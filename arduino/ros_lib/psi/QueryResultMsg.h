#ifndef _ROS_psi_QueryResultMsg_h
#define _ROS_psi_QueryResultMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "psi/BindingSetMsg.h"

namespace psi
{

  class QueryResultMsg : public ros::Msg
  {
    public:
      char * call_id;
      uint8_t binding_sets_length;
      psi::BindingSetMsg st_binding_sets;
      psi::BindingSetMsg * binding_sets;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_call_id = strlen( (const char*) this->call_id);
      memcpy(outbuffer + offset, &length_call_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->call_id, length_call_id);
      offset += length_call_id;
      *(outbuffer + offset++) = binding_sets_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < binding_sets_length; i++){
      offset += this->binding_sets[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_call_id;
      memcpy(&length_call_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_call_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_call_id-1]=0;
      this->call_id = (char *)(inbuffer + offset-1);
      offset += length_call_id;
      uint8_t binding_sets_lengthT = *(inbuffer + offset++);
      if(binding_sets_lengthT > binding_sets_length)
        this->binding_sets = (psi::BindingSetMsg*)realloc(this->binding_sets, binding_sets_lengthT * sizeof(psi::BindingSetMsg));
      offset += 3;
      binding_sets_length = binding_sets_lengthT;
      for( uint8_t i = 0; i < binding_sets_length; i++){
      offset += this->st_binding_sets.deserialize(inbuffer + offset);
        memcpy( &(this->binding_sets[i]), &(this->st_binding_sets), sizeof(psi::BindingSetMsg));
      }
     return offset;
    }

    const char * getType(){ return "psi/QueryResultMsg"; };
    const char * getMD5(){ return "da5e0acf5453dc30547f5d0fb2c8ac31"; };

  };

}
#endif
#ifndef _ROS_psi_BindingSetMsg_h
#define _ROS_psi_BindingSetMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "psi/BindingMsg.h"

namespace psi
{

  class BindingSetMsg : public ros::Msg
  {
    public:
      uint8_t bindings_length;
      psi::BindingMsg st_bindings;
      psi::BindingMsg * bindings;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = bindings_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < bindings_length; i++){
      offset += this->bindings[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t bindings_lengthT = *(inbuffer + offset++);
      if(bindings_lengthT > bindings_length)
        this->bindings = (psi::BindingMsg*)realloc(this->bindings, bindings_lengthT * sizeof(psi::BindingMsg));
      offset += 3;
      bindings_length = bindings_lengthT;
      for( uint8_t i = 0; i < bindings_length; i++){
      offset += this->st_bindings.deserialize(inbuffer + offset);
        memcpy( &(this->bindings[i]), &(this->st_bindings), sizeof(psi::BindingMsg));
      }
     return offset;
    }

    const char * getType(){ return "psi/BindingSetMsg"; };
    const char * getMD5(){ return "d6d0e05423bc0a9423f00edd3216a7e7"; };

  };

}
#endif
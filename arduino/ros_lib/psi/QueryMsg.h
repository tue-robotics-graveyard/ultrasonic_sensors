#ifndef _ROS_psi_QueryMsg_h
#define _ROS_psi_QueryMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "psi/TermMsg.h"

namespace psi
{

  class QueryMsg : public ros::Msg
  {
    public:
      char * call_id;
      char * return_topic;
      psi::TermMsg term;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_call_id = strlen( (const char*) this->call_id);
      memcpy(outbuffer + offset, &length_call_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->call_id, length_call_id);
      offset += length_call_id;
      uint32_t length_return_topic = strlen( (const char*) this->return_topic);
      memcpy(outbuffer + offset, &length_return_topic, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->return_topic, length_return_topic);
      offset += length_return_topic;
      offset += this->term.serialize(outbuffer + offset);
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
      uint32_t length_return_topic;
      memcpy(&length_return_topic, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_return_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_return_topic-1]=0;
      this->return_topic = (char *)(inbuffer + offset-1);
      offset += length_return_topic;
      offset += this->term.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "psi/QueryMsg"; };
    const char * getMD5(){ return "109d935f873a72a125e1fa2f3168d66e"; };

  };

}
#endif
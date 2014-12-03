#ifndef _ROS_psi_BindingMsg_h
#define _ROS_psi_BindingMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "psi/TermMsg.h"

namespace psi
{

  class BindingMsg : public ros::Msg
  {
    public:
      char * variable;
      psi::TermMsg value;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_variable = strlen( (const char*) this->variable);
      memcpy(outbuffer + offset, &length_variable, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->variable, length_variable);
      offset += length_variable;
      offset += this->value.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_variable;
      memcpy(&length_variable, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_variable; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_variable-1]=0;
      this->variable = (char *)(inbuffer + offset-1);
      offset += length_variable;
      offset += this->value.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "psi/BindingMsg"; };
    const char * getMD5(){ return "b179e32c175c7de9d9e579c73ccc1d47"; };

  };

}
#endif
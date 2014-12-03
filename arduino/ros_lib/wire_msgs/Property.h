#ifndef _ROS_wire_msgs_Property_h
#define _ROS_wire_msgs_Property_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "psi/TermMsg.h"

namespace wire_msgs
{

  class Property : public ros::Msg
  {
    public:
      char * attribute;
      psi::TermMsg pdf;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_attribute = strlen( (const char*) this->attribute);
      memcpy(outbuffer + offset, &length_attribute, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->attribute, length_attribute);
      offset += length_attribute;
      offset += this->pdf.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_attribute;
      memcpy(&length_attribute, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_attribute; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_attribute-1]=0;
      this->attribute = (char *)(inbuffer + offset-1);
      offset += length_attribute;
      offset += this->pdf.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "wire_msgs/Property"; };
    const char * getMD5(){ return "34ac3a5568724d7d10ce30a8c6fc6680"; };

  };

}
#endif
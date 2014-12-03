#ifndef _ROS_soem_beckhoff_drivers_EncoderMsg_h
#define _ROS_soem_beckhoff_drivers_EncoderMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace soem_beckhoff_drivers
{

  class EncoderMsg : public ros::Msg
  {
    public:
      uint16_t value;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->value >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value >> (8 * 1)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->value =  ((uint16_t) (*(inbuffer + offset)));
      this->value |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return "soem_beckhoff_drivers/EncoderMsg"; };
    const char * getMD5(){ return "6e68bf91459258a84dab807f5c768df7"; };

  };

}
#endif
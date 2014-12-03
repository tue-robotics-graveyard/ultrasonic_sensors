#ifndef _ROS_soem_beckhoff_drivers_EncoderOutMsg_h
#define _ROS_soem_beckhoff_drivers_EncoderOutMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace soem_beckhoff_drivers
{

  class EncoderOutMsg : public ros::Msg
  {
    public:
      uint8_t control;
      uint16_t outvalue;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->control >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control);
      *(outbuffer + offset + 0) = (this->outvalue >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->outvalue >> (8 * 1)) & 0xFF;
      offset += sizeof(this->outvalue);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->control =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->control);
      this->outvalue =  ((uint16_t) (*(inbuffer + offset)));
      this->outvalue |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->outvalue);
     return offset;
    }

    const char * getType(){ return "soem_beckhoff_drivers/EncoderOutMsg"; };
    const char * getMD5(){ return "297826ed745b96cde20150fa2f0950c2"; };

  };

}
#endif
#ifndef _ROS_soem_beckhoff_drivers_EncoderInMsg_h
#define _ROS_soem_beckhoff_drivers_EncoderInMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace soem_beckhoff_drivers
{

  class EncoderInMsg : public ros::Msg
  {
    public:
      uint8_t status;
      uint16_t value;
      uint16_t latch;
      uint32_t frequency;
      uint16_t period;
      uint16_t window;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->value >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value >> (8 * 1)) & 0xFF;
      offset += sizeof(this->value);
      *(outbuffer + offset + 0) = (this->latch >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->latch >> (8 * 1)) & 0xFF;
      offset += sizeof(this->latch);
      *(outbuffer + offset + 0) = (this->frequency >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->frequency >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->frequency >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->frequency >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frequency);
      *(outbuffer + offset + 0) = (this->period >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->period >> (8 * 1)) & 0xFF;
      offset += sizeof(this->period);
      *(outbuffer + offset + 0) = (this->window >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->window >> (8 * 1)) & 0xFF;
      offset += sizeof(this->window);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      this->value =  ((uint16_t) (*(inbuffer + offset)));
      this->value |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->value);
      this->latch =  ((uint16_t) (*(inbuffer + offset)));
      this->latch |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->latch);
      this->frequency =  ((uint32_t) (*(inbuffer + offset)));
      this->frequency |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->frequency |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->frequency |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->frequency);
      this->period =  ((uint16_t) (*(inbuffer + offset)));
      this->period |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->period);
      this->window =  ((uint16_t) (*(inbuffer + offset)));
      this->window |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->window);
     return offset;
    }

    const char * getType(){ return "soem_beckhoff_drivers/EncoderInMsg"; };
    const char * getMD5(){ return "b22beb20aeb227634f7e90cad065f8e8"; };

  };

}
#endif
#ifndef _ROS_amigo_msgs_AmigoGripperCommand_h
#define _ROS_amigo_msgs_AmigoGripperCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace amigo_msgs
{

  class AmigoGripperCommand : public ros::Msg
  {
    public:
      int8_t direction;
      float max_torque;
      enum { OPEN = -1 };
      enum { CLOSE = 1 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_direction;
      u_direction.real = this->direction;
      *(outbuffer + offset + 0) = (u_direction.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->direction);
      int32_t * val_max_torque = (int32_t *) &(this->max_torque);
      int32_t exp_max_torque = (((*val_max_torque)>>23)&255);
      if(exp_max_torque != 0)
        exp_max_torque += 1023-127;
      int32_t sig_max_torque = *val_max_torque;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_max_torque<<5) & 0xff;
      *(outbuffer + offset++) = (sig_max_torque>>3) & 0xff;
      *(outbuffer + offset++) = (sig_max_torque>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_max_torque<<4) & 0xF0) | ((sig_max_torque>>19)&0x0F);
      *(outbuffer + offset++) = (exp_max_torque>>4) & 0x7F;
      if(this->max_torque < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_direction;
      u_direction.base = 0;
      u_direction.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->direction = u_direction.real;
      offset += sizeof(this->direction);
      uint32_t * val_max_torque = (uint32_t*) &(this->max_torque);
      offset += 3;
      *val_max_torque = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_max_torque |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_max_torque |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_max_torque |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_max_torque = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_max_torque |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_max_torque !=0)
        *val_max_torque |= ((exp_max_torque)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->max_torque = -this->max_torque;
     return offset;
    }

    const char * getType(){ return "amigo_msgs/AmigoGripperCommand"; };
    const char * getMD5(){ return "4b4a2c5c080ad2363e4c7409e2aacece"; };

  };

}
#endif
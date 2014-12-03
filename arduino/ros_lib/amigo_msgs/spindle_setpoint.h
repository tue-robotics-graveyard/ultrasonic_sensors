#ifndef _ROS_amigo_msgs_spindle_setpoint_h
#define _ROS_amigo_msgs_spindle_setpoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace amigo_msgs
{

  class spindle_setpoint : public ros::Msg
  {
    public:
      float pos;
      float vel;
      float acc;
      int8_t stop;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_pos = (int32_t *) &(this->pos);
      int32_t exp_pos = (((*val_pos)>>23)&255);
      if(exp_pos != 0)
        exp_pos += 1023-127;
      int32_t sig_pos = *val_pos;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_pos<<5) & 0xff;
      *(outbuffer + offset++) = (sig_pos>>3) & 0xff;
      *(outbuffer + offset++) = (sig_pos>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_pos<<4) & 0xF0) | ((sig_pos>>19)&0x0F);
      *(outbuffer + offset++) = (exp_pos>>4) & 0x7F;
      if(this->pos < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_vel = (int32_t *) &(this->vel);
      int32_t exp_vel = (((*val_vel)>>23)&255);
      if(exp_vel != 0)
        exp_vel += 1023-127;
      int32_t sig_vel = *val_vel;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_vel<<5) & 0xff;
      *(outbuffer + offset++) = (sig_vel>>3) & 0xff;
      *(outbuffer + offset++) = (sig_vel>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_vel<<4) & 0xF0) | ((sig_vel>>19)&0x0F);
      *(outbuffer + offset++) = (exp_vel>>4) & 0x7F;
      if(this->vel < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_acc = (int32_t *) &(this->acc);
      int32_t exp_acc = (((*val_acc)>>23)&255);
      if(exp_acc != 0)
        exp_acc += 1023-127;
      int32_t sig_acc = *val_acc;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_acc<<5) & 0xff;
      *(outbuffer + offset++) = (sig_acc>>3) & 0xff;
      *(outbuffer + offset++) = (sig_acc>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_acc<<4) & 0xF0) | ((sig_acc>>19)&0x0F);
      *(outbuffer + offset++) = (exp_acc>>4) & 0x7F;
      if(this->acc < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        int8_t real;
        uint8_t base;
      } u_stop;
      u_stop.real = this->stop;
      *(outbuffer + offset + 0) = (u_stop.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stop);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_pos = (uint32_t*) &(this->pos);
      offset += 3;
      *val_pos = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_pos |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_pos |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_pos |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_pos = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_pos |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_pos !=0)
        *val_pos |= ((exp_pos)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->pos = -this->pos;
      uint32_t * val_vel = (uint32_t*) &(this->vel);
      offset += 3;
      *val_vel = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_vel |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_vel |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_vel |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_vel = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_vel |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_vel !=0)
        *val_vel |= ((exp_vel)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->vel = -this->vel;
      uint32_t * val_acc = (uint32_t*) &(this->acc);
      offset += 3;
      *val_acc = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_acc |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_acc |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_acc |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_acc = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_acc |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_acc !=0)
        *val_acc |= ((exp_acc)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->acc = -this->acc;
      union {
        int8_t real;
        uint8_t base;
      } u_stop;
      u_stop.base = 0;
      u_stop.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stop = u_stop.real;
      offset += sizeof(this->stop);
     return offset;
    }

    const char * getType(){ return "amigo_msgs/spindle_setpoint"; };
    const char * getMD5(){ return "427210d08a859ef2eee2f282f3bfceda"; };

  };

}
#endif
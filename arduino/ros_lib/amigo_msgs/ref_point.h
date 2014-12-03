#ifndef _ROS_amigo_msgs_ref_point_h
#define _ROS_amigo_msgs_ref_point_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace amigo_msgs
{

  class ref_point : public ros::Msg
  {
    public:
      float time;
      float dt;
      float pos;
      float vel;
      float acc;
      float pos_d;
      bool ready;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_time = (int32_t *) &(this->time);
      int32_t exp_time = (((*val_time)>>23)&255);
      if(exp_time != 0)
        exp_time += 1023-127;
      int32_t sig_time = *val_time;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_time<<5) & 0xff;
      *(outbuffer + offset++) = (sig_time>>3) & 0xff;
      *(outbuffer + offset++) = (sig_time>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_time<<4) & 0xF0) | ((sig_time>>19)&0x0F);
      *(outbuffer + offset++) = (exp_time>>4) & 0x7F;
      if(this->time < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_dt = (int32_t *) &(this->dt);
      int32_t exp_dt = (((*val_dt)>>23)&255);
      if(exp_dt != 0)
        exp_dt += 1023-127;
      int32_t sig_dt = *val_dt;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_dt<<5) & 0xff;
      *(outbuffer + offset++) = (sig_dt>>3) & 0xff;
      *(outbuffer + offset++) = (sig_dt>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_dt<<4) & 0xF0) | ((sig_dt>>19)&0x0F);
      *(outbuffer + offset++) = (exp_dt>>4) & 0x7F;
      if(this->dt < 0) *(outbuffer + offset -1) |= 0x80;
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
      int32_t * val_pos_d = (int32_t *) &(this->pos_d);
      int32_t exp_pos_d = (((*val_pos_d)>>23)&255);
      if(exp_pos_d != 0)
        exp_pos_d += 1023-127;
      int32_t sig_pos_d = *val_pos_d;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_pos_d<<5) & 0xff;
      *(outbuffer + offset++) = (sig_pos_d>>3) & 0xff;
      *(outbuffer + offset++) = (sig_pos_d>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_pos_d<<4) & 0xF0) | ((sig_pos_d>>19)&0x0F);
      *(outbuffer + offset++) = (exp_pos_d>>4) & 0x7F;
      if(this->pos_d < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        bool real;
        uint8_t base;
      } u_ready;
      u_ready.real = this->ready;
      *(outbuffer + offset + 0) = (u_ready.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ready);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_time = (uint32_t*) &(this->time);
      offset += 3;
      *val_time = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_time |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_time = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_time |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_time !=0)
        *val_time |= ((exp_time)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->time = -this->time;
      uint32_t * val_dt = (uint32_t*) &(this->dt);
      offset += 3;
      *val_dt = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_dt |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_dt |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_dt |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_dt = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_dt |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_dt !=0)
        *val_dt |= ((exp_dt)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->dt = -this->dt;
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
      uint32_t * val_pos_d = (uint32_t*) &(this->pos_d);
      offset += 3;
      *val_pos_d = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_pos_d |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_pos_d |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_pos_d |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_pos_d = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_pos_d |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_pos_d !=0)
        *val_pos_d |= ((exp_pos_d)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->pos_d = -this->pos_d;
      union {
        bool real;
        uint8_t base;
      } u_ready;
      u_ready.base = 0;
      u_ready.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ready = u_ready.real;
      offset += sizeof(this->ready);
     return offset;
    }

    const char * getType(){ return "amigo_msgs/ref_point"; };
    const char * getMD5(){ return "d4eef12602d72d250cf15b4135a6a0f7"; };

  };

}
#endif
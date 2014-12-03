#ifndef _ROS_leap_motion_leap_h
#define _ROS_leap_motion_leap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace leap_motion
{

  class leap : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float hand_direction[3];
      float hand_normal[3];
      float hand_palm_pos[3];
      float hand_pitch;
      float hand_roll;
      float hand_yaw;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      unsigned char * hand_direction_val = (unsigned char *) this->hand_direction;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_hand_directioni = (int32_t *) &(this->hand_direction[i]);
      int32_t exp_hand_directioni = (((*val_hand_directioni)>>23)&255);
      if(exp_hand_directioni != 0)
        exp_hand_directioni += 1023-127;
      int32_t sig_hand_directioni = *val_hand_directioni;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_hand_directioni<<5) & 0xff;
      *(outbuffer + offset++) = (sig_hand_directioni>>3) & 0xff;
      *(outbuffer + offset++) = (sig_hand_directioni>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_hand_directioni<<4) & 0xF0) | ((sig_hand_directioni>>19)&0x0F);
      *(outbuffer + offset++) = (exp_hand_directioni>>4) & 0x7F;
      if(this->hand_direction[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * hand_normal_val = (unsigned char *) this->hand_normal;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_hand_normali = (int32_t *) &(this->hand_normal[i]);
      int32_t exp_hand_normali = (((*val_hand_normali)>>23)&255);
      if(exp_hand_normali != 0)
        exp_hand_normali += 1023-127;
      int32_t sig_hand_normali = *val_hand_normali;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_hand_normali<<5) & 0xff;
      *(outbuffer + offset++) = (sig_hand_normali>>3) & 0xff;
      *(outbuffer + offset++) = (sig_hand_normali>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_hand_normali<<4) & 0xF0) | ((sig_hand_normali>>19)&0x0F);
      *(outbuffer + offset++) = (exp_hand_normali>>4) & 0x7F;
      if(this->hand_normal[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * hand_palm_pos_val = (unsigned char *) this->hand_palm_pos;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_hand_palm_posi = (int32_t *) &(this->hand_palm_pos[i]);
      int32_t exp_hand_palm_posi = (((*val_hand_palm_posi)>>23)&255);
      if(exp_hand_palm_posi != 0)
        exp_hand_palm_posi += 1023-127;
      int32_t sig_hand_palm_posi = *val_hand_palm_posi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_hand_palm_posi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_hand_palm_posi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_hand_palm_posi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_hand_palm_posi<<4) & 0xF0) | ((sig_hand_palm_posi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_hand_palm_posi>>4) & 0x7F;
      if(this->hand_palm_pos[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      int32_t * val_hand_pitch = (int32_t *) &(this->hand_pitch);
      int32_t exp_hand_pitch = (((*val_hand_pitch)>>23)&255);
      if(exp_hand_pitch != 0)
        exp_hand_pitch += 1023-127;
      int32_t sig_hand_pitch = *val_hand_pitch;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_hand_pitch<<5) & 0xff;
      *(outbuffer + offset++) = (sig_hand_pitch>>3) & 0xff;
      *(outbuffer + offset++) = (sig_hand_pitch>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_hand_pitch<<4) & 0xF0) | ((sig_hand_pitch>>19)&0x0F);
      *(outbuffer + offset++) = (exp_hand_pitch>>4) & 0x7F;
      if(this->hand_pitch < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_hand_roll = (int32_t *) &(this->hand_roll);
      int32_t exp_hand_roll = (((*val_hand_roll)>>23)&255);
      if(exp_hand_roll != 0)
        exp_hand_roll += 1023-127;
      int32_t sig_hand_roll = *val_hand_roll;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_hand_roll<<5) & 0xff;
      *(outbuffer + offset++) = (sig_hand_roll>>3) & 0xff;
      *(outbuffer + offset++) = (sig_hand_roll>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_hand_roll<<4) & 0xF0) | ((sig_hand_roll>>19)&0x0F);
      *(outbuffer + offset++) = (exp_hand_roll>>4) & 0x7F;
      if(this->hand_roll < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_hand_yaw = (int32_t *) &(this->hand_yaw);
      int32_t exp_hand_yaw = (((*val_hand_yaw)>>23)&255);
      if(exp_hand_yaw != 0)
        exp_hand_yaw += 1023-127;
      int32_t sig_hand_yaw = *val_hand_yaw;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_hand_yaw<<5) & 0xff;
      *(outbuffer + offset++) = (sig_hand_yaw>>3) & 0xff;
      *(outbuffer + offset++) = (sig_hand_yaw>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_hand_yaw<<4) & 0xF0) | ((sig_hand_yaw>>19)&0x0F);
      *(outbuffer + offset++) = (exp_hand_yaw>>4) & 0x7F;
      if(this->hand_yaw < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t * hand_direction_val = (uint8_t*) this->hand_direction;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_hand_directioni = (uint32_t*) &(this->hand_direction[i]);
      offset += 3;
      *val_hand_directioni = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_hand_directioni |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_hand_directioni |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_hand_directioni |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_hand_directioni = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_hand_directioni |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_hand_directioni !=0)
        *val_hand_directioni |= ((exp_hand_directioni)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->hand_direction[i] = -this->hand_direction[i];
      }
      uint8_t * hand_normal_val = (uint8_t*) this->hand_normal;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_hand_normali = (uint32_t*) &(this->hand_normal[i]);
      offset += 3;
      *val_hand_normali = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_hand_normali |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_hand_normali |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_hand_normali |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_hand_normali = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_hand_normali |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_hand_normali !=0)
        *val_hand_normali |= ((exp_hand_normali)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->hand_normal[i] = -this->hand_normal[i];
      }
      uint8_t * hand_palm_pos_val = (uint8_t*) this->hand_palm_pos;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_hand_palm_posi = (uint32_t*) &(this->hand_palm_pos[i]);
      offset += 3;
      *val_hand_palm_posi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_hand_palm_posi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_hand_palm_posi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_hand_palm_posi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_hand_palm_posi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_hand_palm_posi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_hand_palm_posi !=0)
        *val_hand_palm_posi |= ((exp_hand_palm_posi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->hand_palm_pos[i] = -this->hand_palm_pos[i];
      }
      uint32_t * val_hand_pitch = (uint32_t*) &(this->hand_pitch);
      offset += 3;
      *val_hand_pitch = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_hand_pitch |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_hand_pitch |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_hand_pitch |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_hand_pitch = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_hand_pitch |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_hand_pitch !=0)
        *val_hand_pitch |= ((exp_hand_pitch)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->hand_pitch = -this->hand_pitch;
      uint32_t * val_hand_roll = (uint32_t*) &(this->hand_roll);
      offset += 3;
      *val_hand_roll = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_hand_roll |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_hand_roll |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_hand_roll |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_hand_roll = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_hand_roll |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_hand_roll !=0)
        *val_hand_roll |= ((exp_hand_roll)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->hand_roll = -this->hand_roll;
      uint32_t * val_hand_yaw = (uint32_t*) &(this->hand_yaw);
      offset += 3;
      *val_hand_yaw = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_hand_yaw |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_hand_yaw |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_hand_yaw |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_hand_yaw = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_hand_yaw |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_hand_yaw !=0)
        *val_hand_yaw |= ((exp_hand_yaw)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->hand_yaw = -this->hand_yaw;
     return offset;
    }

    const char * getType(){ return "leap_motion/leap"; };
    const char * getMD5(){ return "3e9a0dc7fd1a98f1d7489e9011c78807"; };

  };

}
#endif
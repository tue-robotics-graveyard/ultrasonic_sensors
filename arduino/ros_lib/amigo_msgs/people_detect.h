#ifndef _ROS_amigo_msgs_people_detect_h
#define _ROS_amigo_msgs_people_detect_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace amigo_msgs
{

  class people_detect : public ros::Msg
  {
    public:
      int8_t num_people;
      float x[20];
      float y[20];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_num_people;
      u_num_people.real = this->num_people;
      *(outbuffer + offset + 0) = (u_num_people.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_people);
      unsigned char * x_val = (unsigned char *) this->x;
      for( uint8_t i = 0; i < 20; i++){
      int32_t * val_xi = (int32_t *) &(this->x[i]);
      int32_t exp_xi = (((*val_xi)>>23)&255);
      if(exp_xi != 0)
        exp_xi += 1023-127;
      int32_t sig_xi = *val_xi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_xi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_xi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_xi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_xi<<4) & 0xF0) | ((sig_xi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_xi>>4) & 0x7F;
      if(this->x[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * y_val = (unsigned char *) this->y;
      for( uint8_t i = 0; i < 20; i++){
      int32_t * val_yi = (int32_t *) &(this->y[i]);
      int32_t exp_yi = (((*val_yi)>>23)&255);
      if(exp_yi != 0)
        exp_yi += 1023-127;
      int32_t sig_yi = *val_yi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_yi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_yi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_yi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_yi<<4) & 0xF0) | ((sig_yi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_yi>>4) & 0x7F;
      if(this->y[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_num_people;
      u_num_people.base = 0;
      u_num_people.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->num_people = u_num_people.real;
      offset += sizeof(this->num_people);
      uint8_t * x_val = (uint8_t*) this->x;
      for( uint8_t i = 0; i < 20; i++){
      uint32_t * val_xi = (uint32_t*) &(this->x[i]);
      offset += 3;
      *val_xi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_xi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_xi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_xi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_xi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_xi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_xi !=0)
        *val_xi |= ((exp_xi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->x[i] = -this->x[i];
      }
      uint8_t * y_val = (uint8_t*) this->y;
      for( uint8_t i = 0; i < 20; i++){
      uint32_t * val_yi = (uint32_t*) &(this->y[i]);
      offset += 3;
      *val_yi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_yi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_yi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_yi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_yi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_yi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_yi !=0)
        *val_yi |= ((exp_yi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->y[i] = -this->y[i];
      }
     return offset;
    }

    const char * getType(){ return "amigo_msgs/people_detect"; };
    const char * getMD5(){ return "a11865839b6724d2f11734bd0221278e"; };

  };

}
#endif
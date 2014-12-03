#ifndef _ROS_hrpsys_ros_bridge_RTC_Size3D_h
#define _ROS_hrpsys_ros_bridge_RTC_Size3D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class RTC_Size3D : public ros::Msg
  {
    public:
      float l;
      float w;
      float h;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_l = (int32_t *) &(this->l);
      int32_t exp_l = (((*val_l)>>23)&255);
      if(exp_l != 0)
        exp_l += 1023-127;
      int32_t sig_l = *val_l;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_l<<5) & 0xff;
      *(outbuffer + offset++) = (sig_l>>3) & 0xff;
      *(outbuffer + offset++) = (sig_l>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_l<<4) & 0xF0) | ((sig_l>>19)&0x0F);
      *(outbuffer + offset++) = (exp_l>>4) & 0x7F;
      if(this->l < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_w = (int32_t *) &(this->w);
      int32_t exp_w = (((*val_w)>>23)&255);
      if(exp_w != 0)
        exp_w += 1023-127;
      int32_t sig_w = *val_w;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_w<<5) & 0xff;
      *(outbuffer + offset++) = (sig_w>>3) & 0xff;
      *(outbuffer + offset++) = (sig_w>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_w<<4) & 0xF0) | ((sig_w>>19)&0x0F);
      *(outbuffer + offset++) = (exp_w>>4) & 0x7F;
      if(this->w < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_h = (int32_t *) &(this->h);
      int32_t exp_h = (((*val_h)>>23)&255);
      if(exp_h != 0)
        exp_h += 1023-127;
      int32_t sig_h = *val_h;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_h<<5) & 0xff;
      *(outbuffer + offset++) = (sig_h>>3) & 0xff;
      *(outbuffer + offset++) = (sig_h>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_h<<4) & 0xF0) | ((sig_h>>19)&0x0F);
      *(outbuffer + offset++) = (exp_h>>4) & 0x7F;
      if(this->h < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_l = (uint32_t*) &(this->l);
      offset += 3;
      *val_l = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_l |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_l |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_l |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_l = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_l |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_l !=0)
        *val_l |= ((exp_l)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->l = -this->l;
      uint32_t * val_w = (uint32_t*) &(this->w);
      offset += 3;
      *val_w = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_w |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_w |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_w |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_w = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_w |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_w !=0)
        *val_w |= ((exp_w)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->w = -this->w;
      uint32_t * val_h = (uint32_t*) &(this->h);
      offset += 3;
      *val_h = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_h |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_h |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_h |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_h = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_h |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_h !=0)
        *val_h |= ((exp_h)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->h = -this->h;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/RTC_Size3D"; };
    const char * getMD5(){ return "09ee73e9959cb322594a7a11cdaf6fce"; };

  };

}
#endif
#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_goVelocity_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_goVelocity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_GOVELOCITY[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_goVelocity";

  class OpenHRP_AutoBalancerService_goVelocityRequest : public ros::Msg
  {
    public:
      float vx;
      float vy;
      float vth;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_vx = (int32_t *) &(this->vx);
      int32_t exp_vx = (((*val_vx)>>23)&255);
      if(exp_vx != 0)
        exp_vx += 1023-127;
      int32_t sig_vx = *val_vx;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_vx<<5) & 0xff;
      *(outbuffer + offset++) = (sig_vx>>3) & 0xff;
      *(outbuffer + offset++) = (sig_vx>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_vx<<4) & 0xF0) | ((sig_vx>>19)&0x0F);
      *(outbuffer + offset++) = (exp_vx>>4) & 0x7F;
      if(this->vx < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_vy = (int32_t *) &(this->vy);
      int32_t exp_vy = (((*val_vy)>>23)&255);
      if(exp_vy != 0)
        exp_vy += 1023-127;
      int32_t sig_vy = *val_vy;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_vy<<5) & 0xff;
      *(outbuffer + offset++) = (sig_vy>>3) & 0xff;
      *(outbuffer + offset++) = (sig_vy>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_vy<<4) & 0xF0) | ((sig_vy>>19)&0x0F);
      *(outbuffer + offset++) = (exp_vy>>4) & 0x7F;
      if(this->vy < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_vth = (int32_t *) &(this->vth);
      int32_t exp_vth = (((*val_vth)>>23)&255);
      if(exp_vth != 0)
        exp_vth += 1023-127;
      int32_t sig_vth = *val_vth;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_vth<<5) & 0xff;
      *(outbuffer + offset++) = (sig_vth>>3) & 0xff;
      *(outbuffer + offset++) = (sig_vth>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_vth<<4) & 0xF0) | ((sig_vth>>19)&0x0F);
      *(outbuffer + offset++) = (exp_vth>>4) & 0x7F;
      if(this->vth < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_vx = (uint32_t*) &(this->vx);
      offset += 3;
      *val_vx = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_vx |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_vx |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_vx |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_vx = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_vx |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_vx !=0)
        *val_vx |= ((exp_vx)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->vx = -this->vx;
      uint32_t * val_vy = (uint32_t*) &(this->vy);
      offset += 3;
      *val_vy = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_vy |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_vy |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_vy |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_vy = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_vy |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_vy !=0)
        *val_vy |= ((exp_vy)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->vy = -this->vy;
      uint32_t * val_vth = (uint32_t*) &(this->vth);
      offset += 3;
      *val_vth = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_vth |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_vth |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_vth |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_vth = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_vth |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_vth !=0)
        *val_vth |= ((exp_vth)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->vth = -this->vth;
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GOVELOCITY; };
    const char * getMD5(){ return "14e82c5776916d6989ea54aa7b04632c"; };

  };

  class OpenHRP_AutoBalancerService_goVelocityResponse : public ros::Msg
  {
    public:
      bool operation_return;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operation_return);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GOVELOCITY; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_AutoBalancerService_goVelocity {
    public:
    typedef OpenHRP_AutoBalancerService_goVelocityRequest Request;
    typedef OpenHRP_AutoBalancerService_goVelocityResponse Response;
  };

}
#endif

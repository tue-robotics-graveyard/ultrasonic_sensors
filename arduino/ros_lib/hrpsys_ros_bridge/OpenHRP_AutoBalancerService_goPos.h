#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_goPos_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_goPos_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_GOPOS[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_goPos";

  class OpenHRP_AutoBalancerService_goPosRequest : public ros::Msg
  {
    public:
      float x;
      float y;
      float th;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_x = (int32_t *) &(this->x);
      int32_t exp_x = (((*val_x)>>23)&255);
      if(exp_x != 0)
        exp_x += 1023-127;
      int32_t sig_x = *val_x;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_x<<5) & 0xff;
      *(outbuffer + offset++) = (sig_x>>3) & 0xff;
      *(outbuffer + offset++) = (sig_x>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_x<<4) & 0xF0) | ((sig_x>>19)&0x0F);
      *(outbuffer + offset++) = (exp_x>>4) & 0x7F;
      if(this->x < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_y = (int32_t *) &(this->y);
      int32_t exp_y = (((*val_y)>>23)&255);
      if(exp_y != 0)
        exp_y += 1023-127;
      int32_t sig_y = *val_y;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_y<<5) & 0xff;
      *(outbuffer + offset++) = (sig_y>>3) & 0xff;
      *(outbuffer + offset++) = (sig_y>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_y<<4) & 0xF0) | ((sig_y>>19)&0x0F);
      *(outbuffer + offset++) = (exp_y>>4) & 0x7F;
      if(this->y < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_th = (int32_t *) &(this->th);
      int32_t exp_th = (((*val_th)>>23)&255);
      if(exp_th != 0)
        exp_th += 1023-127;
      int32_t sig_th = *val_th;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_th<<5) & 0xff;
      *(outbuffer + offset++) = (sig_th>>3) & 0xff;
      *(outbuffer + offset++) = (sig_th>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_th<<4) & 0xF0) | ((sig_th>>19)&0x0F);
      *(outbuffer + offset++) = (exp_th>>4) & 0x7F;
      if(this->th < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_x = (uint32_t*) &(this->x);
      offset += 3;
      *val_x = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_x |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_x = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_x |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_x !=0)
        *val_x |= ((exp_x)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->x = -this->x;
      uint32_t * val_y = (uint32_t*) &(this->y);
      offset += 3;
      *val_y = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_y |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_y = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_y |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_y !=0)
        *val_y |= ((exp_y)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->y = -this->y;
      uint32_t * val_th = (uint32_t*) &(this->th);
      offset += 3;
      *val_th = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_th |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_th |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_th |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_th = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_th |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_th !=0)
        *val_th |= ((exp_th)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->th = -this->th;
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GOPOS; };
    const char * getMD5(){ return "000e435776f4fd6ba555d25d7a61ed8f"; };

  };

  class OpenHRP_AutoBalancerService_goPosResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GOPOS; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_AutoBalancerService_goPos {
    public:
    typedef OpenHRP_AutoBalancerService_goPosRequest Request;
    typedef OpenHRP_AutoBalancerService_goPosResponse Response;
  };

}
#endif

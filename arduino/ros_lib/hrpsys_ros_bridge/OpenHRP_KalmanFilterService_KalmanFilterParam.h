#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_KalmanFilterService_KalmanFilterParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_KalmanFilterService_KalmanFilterParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_KalmanFilterService_KalmanFilterParam : public ros::Msg
  {
    public:
      float Q_angle;
      float Q_rate;
      float R_angle;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_Q_angle = (int32_t *) &(this->Q_angle);
      int32_t exp_Q_angle = (((*val_Q_angle)>>23)&255);
      if(exp_Q_angle != 0)
        exp_Q_angle += 1023-127;
      int32_t sig_Q_angle = *val_Q_angle;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_Q_angle<<5) & 0xff;
      *(outbuffer + offset++) = (sig_Q_angle>>3) & 0xff;
      *(outbuffer + offset++) = (sig_Q_angle>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_Q_angle<<4) & 0xF0) | ((sig_Q_angle>>19)&0x0F);
      *(outbuffer + offset++) = (exp_Q_angle>>4) & 0x7F;
      if(this->Q_angle < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_Q_rate = (int32_t *) &(this->Q_rate);
      int32_t exp_Q_rate = (((*val_Q_rate)>>23)&255);
      if(exp_Q_rate != 0)
        exp_Q_rate += 1023-127;
      int32_t sig_Q_rate = *val_Q_rate;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_Q_rate<<5) & 0xff;
      *(outbuffer + offset++) = (sig_Q_rate>>3) & 0xff;
      *(outbuffer + offset++) = (sig_Q_rate>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_Q_rate<<4) & 0xF0) | ((sig_Q_rate>>19)&0x0F);
      *(outbuffer + offset++) = (exp_Q_rate>>4) & 0x7F;
      if(this->Q_rate < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_R_angle = (int32_t *) &(this->R_angle);
      int32_t exp_R_angle = (((*val_R_angle)>>23)&255);
      if(exp_R_angle != 0)
        exp_R_angle += 1023-127;
      int32_t sig_R_angle = *val_R_angle;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_R_angle<<5) & 0xff;
      *(outbuffer + offset++) = (sig_R_angle>>3) & 0xff;
      *(outbuffer + offset++) = (sig_R_angle>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_R_angle<<4) & 0xF0) | ((sig_R_angle>>19)&0x0F);
      *(outbuffer + offset++) = (exp_R_angle>>4) & 0x7F;
      if(this->R_angle < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_Q_angle = (uint32_t*) &(this->Q_angle);
      offset += 3;
      *val_Q_angle = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_Q_angle |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_Q_angle |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_Q_angle |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_Q_angle = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_Q_angle |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_Q_angle !=0)
        *val_Q_angle |= ((exp_Q_angle)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->Q_angle = -this->Q_angle;
      uint32_t * val_Q_rate = (uint32_t*) &(this->Q_rate);
      offset += 3;
      *val_Q_rate = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_Q_rate |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_Q_rate |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_Q_rate |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_Q_rate = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_Q_rate |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_Q_rate !=0)
        *val_Q_rate |= ((exp_Q_rate)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->Q_rate = -this->Q_rate;
      uint32_t * val_R_angle = (uint32_t*) &(this->R_angle);
      offset += 3;
      *val_R_angle = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_R_angle |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_R_angle |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_R_angle |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_R_angle = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_R_angle |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_R_angle !=0)
        *val_R_angle |= ((exp_R_angle)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->R_angle = -this->R_angle;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_KalmanFilterService_KalmanFilterParam"; };
    const char * getMD5(){ return "99fa7e6dad45fed1dc5ad149496bc96d"; };

  };

}
#endif
#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_GaitGeneratorParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_GaitGeneratorParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_GaitGeneratorParam : public ros::Msg
  {
    public:
      float default_step_time;
      float default_step_height;
      float default_double_support_ratio;
      float stride_parameter[3];
      int64_t default_orbit_type;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_default_step_time = (int32_t *) &(this->default_step_time);
      int32_t exp_default_step_time = (((*val_default_step_time)>>23)&255);
      if(exp_default_step_time != 0)
        exp_default_step_time += 1023-127;
      int32_t sig_default_step_time = *val_default_step_time;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_default_step_time<<5) & 0xff;
      *(outbuffer + offset++) = (sig_default_step_time>>3) & 0xff;
      *(outbuffer + offset++) = (sig_default_step_time>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_default_step_time<<4) & 0xF0) | ((sig_default_step_time>>19)&0x0F);
      *(outbuffer + offset++) = (exp_default_step_time>>4) & 0x7F;
      if(this->default_step_time < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_default_step_height = (int32_t *) &(this->default_step_height);
      int32_t exp_default_step_height = (((*val_default_step_height)>>23)&255);
      if(exp_default_step_height != 0)
        exp_default_step_height += 1023-127;
      int32_t sig_default_step_height = *val_default_step_height;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_default_step_height<<5) & 0xff;
      *(outbuffer + offset++) = (sig_default_step_height>>3) & 0xff;
      *(outbuffer + offset++) = (sig_default_step_height>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_default_step_height<<4) & 0xF0) | ((sig_default_step_height>>19)&0x0F);
      *(outbuffer + offset++) = (exp_default_step_height>>4) & 0x7F;
      if(this->default_step_height < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_default_double_support_ratio = (int32_t *) &(this->default_double_support_ratio);
      int32_t exp_default_double_support_ratio = (((*val_default_double_support_ratio)>>23)&255);
      if(exp_default_double_support_ratio != 0)
        exp_default_double_support_ratio += 1023-127;
      int32_t sig_default_double_support_ratio = *val_default_double_support_ratio;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_default_double_support_ratio<<5) & 0xff;
      *(outbuffer + offset++) = (sig_default_double_support_ratio>>3) & 0xff;
      *(outbuffer + offset++) = (sig_default_double_support_ratio>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_default_double_support_ratio<<4) & 0xF0) | ((sig_default_double_support_ratio>>19)&0x0F);
      *(outbuffer + offset++) = (exp_default_double_support_ratio>>4) & 0x7F;
      if(this->default_double_support_ratio < 0) *(outbuffer + offset -1) |= 0x80;
      unsigned char * stride_parameter_val = (unsigned char *) this->stride_parameter;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_stride_parameteri = (int32_t *) &(this->stride_parameter[i]);
      int32_t exp_stride_parameteri = (((*val_stride_parameteri)>>23)&255);
      if(exp_stride_parameteri != 0)
        exp_stride_parameteri += 1023-127;
      int32_t sig_stride_parameteri = *val_stride_parameteri;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_stride_parameteri<<5) & 0xff;
      *(outbuffer + offset++) = (sig_stride_parameteri>>3) & 0xff;
      *(outbuffer + offset++) = (sig_stride_parameteri>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_stride_parameteri<<4) & 0xF0) | ((sig_stride_parameteri>>19)&0x0F);
      *(outbuffer + offset++) = (exp_stride_parameteri>>4) & 0x7F;
      if(this->stride_parameter[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      union {
        int64_t real;
        uint64_t base;
      } u_default_orbit_type;
      u_default_orbit_type.real = this->default_orbit_type;
      *(outbuffer + offset + 0) = (u_default_orbit_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_orbit_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_orbit_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_orbit_type.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_orbit_type.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_orbit_type.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_orbit_type.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_orbit_type.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_orbit_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_default_step_time = (uint32_t*) &(this->default_step_time);
      offset += 3;
      *val_default_step_time = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_default_step_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_default_step_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_default_step_time |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_default_step_time = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_default_step_time |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_default_step_time !=0)
        *val_default_step_time |= ((exp_default_step_time)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->default_step_time = -this->default_step_time;
      uint32_t * val_default_step_height = (uint32_t*) &(this->default_step_height);
      offset += 3;
      *val_default_step_height = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_default_step_height |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_default_step_height |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_default_step_height |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_default_step_height = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_default_step_height |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_default_step_height !=0)
        *val_default_step_height |= ((exp_default_step_height)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->default_step_height = -this->default_step_height;
      uint32_t * val_default_double_support_ratio = (uint32_t*) &(this->default_double_support_ratio);
      offset += 3;
      *val_default_double_support_ratio = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_default_double_support_ratio |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_default_double_support_ratio |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_default_double_support_ratio |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_default_double_support_ratio = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_default_double_support_ratio |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_default_double_support_ratio !=0)
        *val_default_double_support_ratio |= ((exp_default_double_support_ratio)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->default_double_support_ratio = -this->default_double_support_ratio;
      uint8_t * stride_parameter_val = (uint8_t*) this->stride_parameter;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_stride_parameteri = (uint32_t*) &(this->stride_parameter[i]);
      offset += 3;
      *val_stride_parameteri = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_stride_parameteri |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_stride_parameteri |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_stride_parameteri |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_stride_parameteri = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_stride_parameteri |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_stride_parameteri !=0)
        *val_stride_parameteri |= ((exp_stride_parameteri)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->stride_parameter[i] = -this->stride_parameter[i];
      }
      union {
        int64_t real;
        uint64_t base;
      } u_default_orbit_type;
      u_default_orbit_type.base = 0;
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_orbit_type = u_default_orbit_type.real;
      offset += sizeof(this->default_orbit_type);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_GaitGeneratorParam"; };
    const char * getMD5(){ return "762f8b103379ef6227eae532dfefe71a"; };

  };

}
#endif
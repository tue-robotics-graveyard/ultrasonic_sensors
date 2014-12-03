#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ExecutionProfileService_Profile_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ExecutionProfileService_Profile_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_ComponentProfile.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ExecutionProfileService_Profile : public ros::Msg
  {
    public:
      float max_period;
      float min_period;
      float avg_period;
      float max_process;
      uint8_t profiles_length;
      hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile st_profiles;
      hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile * profiles;
      int32_t count;
      int32_t timeover;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_max_period = (int32_t *) &(this->max_period);
      int32_t exp_max_period = (((*val_max_period)>>23)&255);
      if(exp_max_period != 0)
        exp_max_period += 1023-127;
      int32_t sig_max_period = *val_max_period;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_max_period<<5) & 0xff;
      *(outbuffer + offset++) = (sig_max_period>>3) & 0xff;
      *(outbuffer + offset++) = (sig_max_period>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_max_period<<4) & 0xF0) | ((sig_max_period>>19)&0x0F);
      *(outbuffer + offset++) = (exp_max_period>>4) & 0x7F;
      if(this->max_period < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_min_period = (int32_t *) &(this->min_period);
      int32_t exp_min_period = (((*val_min_period)>>23)&255);
      if(exp_min_period != 0)
        exp_min_period += 1023-127;
      int32_t sig_min_period = *val_min_period;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_min_period<<5) & 0xff;
      *(outbuffer + offset++) = (sig_min_period>>3) & 0xff;
      *(outbuffer + offset++) = (sig_min_period>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_min_period<<4) & 0xF0) | ((sig_min_period>>19)&0x0F);
      *(outbuffer + offset++) = (exp_min_period>>4) & 0x7F;
      if(this->min_period < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_avg_period = (int32_t *) &(this->avg_period);
      int32_t exp_avg_period = (((*val_avg_period)>>23)&255);
      if(exp_avg_period != 0)
        exp_avg_period += 1023-127;
      int32_t sig_avg_period = *val_avg_period;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_avg_period<<5) & 0xff;
      *(outbuffer + offset++) = (sig_avg_period>>3) & 0xff;
      *(outbuffer + offset++) = (sig_avg_period>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_avg_period<<4) & 0xF0) | ((sig_avg_period>>19)&0x0F);
      *(outbuffer + offset++) = (exp_avg_period>>4) & 0x7F;
      if(this->avg_period < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_max_process = (int32_t *) &(this->max_process);
      int32_t exp_max_process = (((*val_max_process)>>23)&255);
      if(exp_max_process != 0)
        exp_max_process += 1023-127;
      int32_t sig_max_process = *val_max_process;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_max_process<<5) & 0xff;
      *(outbuffer + offset++) = (sig_max_process>>3) & 0xff;
      *(outbuffer + offset++) = (sig_max_process>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_max_process<<4) & 0xF0) | ((sig_max_process>>19)&0x0F);
      *(outbuffer + offset++) = (exp_max_process>>4) & 0x7F;
      if(this->max_process < 0) *(outbuffer + offset -1) |= 0x80;
      *(outbuffer + offset++) = profiles_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < profiles_length; i++){
      offset += this->profiles[i].serialize(outbuffer + offset);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_count;
      u_count.real = this->count;
      *(outbuffer + offset + 0) = (u_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_count.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->count);
      union {
        int32_t real;
        uint32_t base;
      } u_timeover;
      u_timeover.real = this->timeover;
      *(outbuffer + offset + 0) = (u_timeover.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timeover.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timeover.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timeover.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeover);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_max_period = (uint32_t*) &(this->max_period);
      offset += 3;
      *val_max_period = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_max_period |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_max_period |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_max_period |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_max_period = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_max_period |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_max_period !=0)
        *val_max_period |= ((exp_max_period)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->max_period = -this->max_period;
      uint32_t * val_min_period = (uint32_t*) &(this->min_period);
      offset += 3;
      *val_min_period = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_min_period |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_min_period |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_min_period |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_min_period = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_min_period |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_min_period !=0)
        *val_min_period |= ((exp_min_period)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->min_period = -this->min_period;
      uint32_t * val_avg_period = (uint32_t*) &(this->avg_period);
      offset += 3;
      *val_avg_period = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_avg_period |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_avg_period |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_avg_period |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_avg_period = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_avg_period |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_avg_period !=0)
        *val_avg_period |= ((exp_avg_period)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->avg_period = -this->avg_period;
      uint32_t * val_max_process = (uint32_t*) &(this->max_process);
      offset += 3;
      *val_max_process = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_max_process |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_max_process |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_max_process |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_max_process = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_max_process |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_max_process !=0)
        *val_max_process |= ((exp_max_process)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->max_process = -this->max_process;
      uint8_t profiles_lengthT = *(inbuffer + offset++);
      if(profiles_lengthT > profiles_length)
        this->profiles = (hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile*)realloc(this->profiles, profiles_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile));
      offset += 3;
      profiles_length = profiles_lengthT;
      for( uint8_t i = 0; i < profiles_length; i++){
      offset += this->st_profiles.deserialize(inbuffer + offset);
        memcpy( &(this->profiles[i]), &(this->st_profiles), sizeof(hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_count;
      u_count.base = 0;
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->count = u_count.real;
      offset += sizeof(this->count);
      union {
        int32_t real;
        uint32_t base;
      } u_timeover;
      u_timeover.base = 0;
      u_timeover.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timeover.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timeover.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timeover.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timeover = u_timeover.real;
      offset += sizeof(this->timeover);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_Profile"; };
    const char * getMD5(){ return "81d6e451dd3c3c507eb655f4a7c6fba2"; };

  };

}
#endif
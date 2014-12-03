#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ExecutionProfileService_ComponentProfile_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ExecutionProfileService_ComponentProfile_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ExecutionProfileService_ComponentProfile : public ros::Msg
  {
    public:
      int32_t count;
      float max_process;
      float avg_process;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      int32_t * val_avg_process = (int32_t *) &(this->avg_process);
      int32_t exp_avg_process = (((*val_avg_process)>>23)&255);
      if(exp_avg_process != 0)
        exp_avg_process += 1023-127;
      int32_t sig_avg_process = *val_avg_process;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_avg_process<<5) & 0xff;
      *(outbuffer + offset++) = (sig_avg_process>>3) & 0xff;
      *(outbuffer + offset++) = (sig_avg_process>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_avg_process<<4) & 0xF0) | ((sig_avg_process>>19)&0x0F);
      *(outbuffer + offset++) = (exp_avg_process>>4) & 0x7F;
      if(this->avg_process < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      uint32_t * val_avg_process = (uint32_t*) &(this->avg_process);
      offset += 3;
      *val_avg_process = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_avg_process |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_avg_process |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_avg_process |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_avg_process = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_avg_process |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_avg_process !=0)
        *val_avg_process |= ((exp_avg_process)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->avg_process = -this->avg_process;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_ComponentProfile"; };
    const char * getMD5(){ return "2756437d1ed9f4a80e8165d05e369c5a"; };

  };

}
#endif
#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_setServoGainPercentage_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_setServoGainPercentage_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_SETSERVOGAINPERCENTAGE[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_setServoGainPercentage";

  class OpenHRP_RobotHardwareService_setServoGainPercentageRequest : public ros::Msg
  {
    public:
      char * name;
      float percentage;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      int32_t * val_percentage = (int32_t *) &(this->percentage);
      int32_t exp_percentage = (((*val_percentage)>>23)&255);
      if(exp_percentage != 0)
        exp_percentage += 1023-127;
      int32_t sig_percentage = *val_percentage;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_percentage<<5) & 0xff;
      *(outbuffer + offset++) = (sig_percentage>>3) & 0xff;
      *(outbuffer + offset++) = (sig_percentage>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_percentage<<4) & 0xF0) | ((sig_percentage>>19)&0x0F);
      *(outbuffer + offset++) = (exp_percentage>>4) & 0x7F;
      if(this->percentage < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t * val_percentage = (uint32_t*) &(this->percentage);
      offset += 3;
      *val_percentage = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_percentage |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_percentage |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_percentage |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_percentage = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_percentage |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_percentage !=0)
        *val_percentage |= ((exp_percentage)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->percentage = -this->percentage;
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_SETSERVOGAINPERCENTAGE; };
    const char * getMD5(){ return "9792b77124fee8e72b69a034d8c9dd49"; };

  };

  class OpenHRP_RobotHardwareService_setServoGainPercentageResponse : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_SETSERVOGAINPERCENTAGE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_RobotHardwareService_setServoGainPercentage {
    public:
    typedef OpenHRP_RobotHardwareService_setServoGainPercentageRequest Request;
    typedef OpenHRP_RobotHardwareService_setServoGainPercentageResponse Response;
  };

}
#endif

#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_setServoErrorLimit_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_setServoErrorLimit_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_SETSERVOERRORLIMIT[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_setServoErrorLimit";

  class OpenHRP_RobotHardwareService_setServoErrorLimitRequest : public ros::Msg
  {
    public:
      char * name;
      float limit;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      int32_t * val_limit = (int32_t *) &(this->limit);
      int32_t exp_limit = (((*val_limit)>>23)&255);
      if(exp_limit != 0)
        exp_limit += 1023-127;
      int32_t sig_limit = *val_limit;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_limit<<5) & 0xff;
      *(outbuffer + offset++) = (sig_limit>>3) & 0xff;
      *(outbuffer + offset++) = (sig_limit>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_limit<<4) & 0xF0) | ((sig_limit>>19)&0x0F);
      *(outbuffer + offset++) = (exp_limit>>4) & 0x7F;
      if(this->limit < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint32_t * val_limit = (uint32_t*) &(this->limit);
      offset += 3;
      *val_limit = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_limit |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_limit |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_limit |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_limit = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_limit |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_limit !=0)
        *val_limit |= ((exp_limit)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->limit = -this->limit;
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_SETSERVOERRORLIMIT; };
    const char * getMD5(){ return "d662ce8bf785722c53b242dac4a01f11"; };

  };

  class OpenHRP_RobotHardwareService_setServoErrorLimitResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_SETSERVOERRORLIMIT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_RobotHardwareService_setServoErrorLimit {
    public:
    typedef OpenHRP_RobotHardwareService_setServoErrorLimitRequest Request;
    typedef OpenHRP_RobotHardwareService_setServoErrorLimitResponse Response;
  };

}
#endif

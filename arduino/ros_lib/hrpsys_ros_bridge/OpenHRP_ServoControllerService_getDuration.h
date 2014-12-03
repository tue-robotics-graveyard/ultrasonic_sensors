#ifndef _ROS_SERVICE_OpenHRP_ServoControllerService_getDuration_h
#define _ROS_SERVICE_OpenHRP_ServoControllerService_getDuration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SERVOCONTROLLERSERVICE_GETDURATION[] = "hrpsys_ros_bridge/OpenHRP_ServoControllerService_getDuration";

  class OpenHRP_ServoControllerService_getDurationRequest : public ros::Msg
  {
    public:
      int16_t id;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id = u_id.real;
      offset += sizeof(this->id);
     return offset;
    }

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_GETDURATION; };
    const char * getMD5(){ return "83303829ff5167a112112db2bf7b7905"; };

  };

  class OpenHRP_ServoControllerService_getDurationResponse : public ros::Msg
  {
    public:
      bool operation_return;
      float duration;

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
      int32_t * val_duration = (int32_t *) &(this->duration);
      int32_t exp_duration = (((*val_duration)>>23)&255);
      if(exp_duration != 0)
        exp_duration += 1023-127;
      int32_t sig_duration = *val_duration;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_duration<<5) & 0xff;
      *(outbuffer + offset++) = (sig_duration>>3) & 0xff;
      *(outbuffer + offset++) = (sig_duration>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_duration<<4) & 0xF0) | ((sig_duration>>19)&0x0F);
      *(outbuffer + offset++) = (exp_duration>>4) & 0x7F;
      if(this->duration < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint32_t * val_duration = (uint32_t*) &(this->duration);
      offset += 3;
      *val_duration = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_duration |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_duration |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_duration |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_duration = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_duration |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_duration !=0)
        *val_duration |= ((exp_duration)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->duration = -this->duration;
     return offset;
    }

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_GETDURATION; };
    const char * getMD5(){ return "c5f41a8084b3515fab9cda5e64452eb1"; };

  };

  class OpenHRP_ServoControllerService_getDuration {
    public:
    typedef OpenHRP_ServoControllerService_getDurationRequest Request;
    typedef OpenHRP_ServoControllerService_getDurationResponse Response;
  };

}
#endif

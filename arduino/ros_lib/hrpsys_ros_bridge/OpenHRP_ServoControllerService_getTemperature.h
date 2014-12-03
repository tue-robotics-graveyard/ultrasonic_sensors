#ifndef _ROS_SERVICE_OpenHRP_ServoControllerService_getTemperature_h
#define _ROS_SERVICE_OpenHRP_ServoControllerService_getTemperature_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SERVOCONTROLLERSERVICE_GETTEMPERATURE[] = "hrpsys_ros_bridge/OpenHRP_ServoControllerService_getTemperature";

  class OpenHRP_ServoControllerService_getTemperatureRequest : public ros::Msg
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

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_GETTEMPERATURE; };
    const char * getMD5(){ return "83303829ff5167a112112db2bf7b7905"; };

  };

  class OpenHRP_ServoControllerService_getTemperatureResponse : public ros::Msg
  {
    public:
      bool operation_return;
      float temperature;

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
      int32_t * val_temperature = (int32_t *) &(this->temperature);
      int32_t exp_temperature = (((*val_temperature)>>23)&255);
      if(exp_temperature != 0)
        exp_temperature += 1023-127;
      int32_t sig_temperature = *val_temperature;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_temperature<<5) & 0xff;
      *(outbuffer + offset++) = (sig_temperature>>3) & 0xff;
      *(outbuffer + offset++) = (sig_temperature>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_temperature<<4) & 0xF0) | ((sig_temperature>>19)&0x0F);
      *(outbuffer + offset++) = (exp_temperature>>4) & 0x7F;
      if(this->temperature < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint32_t * val_temperature = (uint32_t*) &(this->temperature);
      offset += 3;
      *val_temperature = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_temperature |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_temperature |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_temperature |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_temperature = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_temperature |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_temperature !=0)
        *val_temperature |= ((exp_temperature)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->temperature = -this->temperature;
     return offset;
    }

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_GETTEMPERATURE; };
    const char * getMD5(){ return "40dcd8d7d66d9ca9898d0691fb9ec852"; };

  };

  class OpenHRP_ServoControllerService_getTemperature {
    public:
    typedef OpenHRP_ServoControllerService_getTemperatureRequest Request;
    typedef OpenHRP_ServoControllerService_getTemperatureResponse Response;
  };

}
#endif

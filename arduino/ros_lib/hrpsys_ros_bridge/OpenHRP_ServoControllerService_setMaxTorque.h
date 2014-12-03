#ifndef _ROS_SERVICE_OpenHRP_ServoControllerService_setMaxTorque_h
#define _ROS_SERVICE_OpenHRP_ServoControllerService_setMaxTorque_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SERVOCONTROLLERSERVICE_SETMAXTORQUE[] = "hrpsys_ros_bridge/OpenHRP_ServoControllerService_setMaxTorque";

  class OpenHRP_ServoControllerService_setMaxTorqueRequest : public ros::Msg
  {
    public:
      int16_t id;
      int16_t percentage;

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
      union {
        int16_t real;
        uint16_t base;
      } u_percentage;
      u_percentage.real = this->percentage;
      *(outbuffer + offset + 0) = (u_percentage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_percentage.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->percentage);
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
      union {
        int16_t real;
        uint16_t base;
      } u_percentage;
      u_percentage.base = 0;
      u_percentage.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_percentage.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->percentage = u_percentage.real;
      offset += sizeof(this->percentage);
     return offset;
    }

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_SETMAXTORQUE; };
    const char * getMD5(){ return "22efa6302de260a1a29a652caa170664"; };

  };

  class OpenHRP_ServoControllerService_setMaxTorqueResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_SETMAXTORQUE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_ServoControllerService_setMaxTorque {
    public:
    typedef OpenHRP_ServoControllerService_setMaxTorqueRequest Request;
    typedef OpenHRP_ServoControllerService_setMaxTorqueResponse Response;
  };

}
#endif

#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_getGaitGeneratorParam_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_getGaitGeneratorParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_GaitGeneratorParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_GETGAITGENERATORPARAM[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_getGaitGeneratorParam";

  class OpenHRP_AutoBalancerService_getGaitGeneratorParamRequest : public ros::Msg
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GETGAITGENERATORPARAM; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_AutoBalancerService_getGaitGeneratorParamResponse : public ros::Msg
  {
    public:
      bool operation_return;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_GaitGeneratorParam i_param;

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
      offset += this->i_param.serialize(outbuffer + offset);
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
      offset += this->i_param.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GETGAITGENERATORPARAM; };
    const char * getMD5(){ return "26a61fbe867ba18362a21783b96bac92"; };

  };

  class OpenHRP_AutoBalancerService_getGaitGeneratorParam {
    public:
    typedef OpenHRP_AutoBalancerService_getGaitGeneratorParamRequest Request;
    typedef OpenHRP_AutoBalancerService_getGaitGeneratorParamResponse Response;
  };

}
#endif

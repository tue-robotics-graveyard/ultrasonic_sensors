#ifndef _ROS_SERVICE_OpenHRP_ImpedanceControllerService_setImpedanceControllerParam_h
#define _ROS_SERVICE_OpenHRP_ImpedanceControllerService_setImpedanceControllerParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_impedanceParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_IMPEDANCECONTROLLERSERVICE_SETIMPEDANCECONTROLLERPARAM[] = "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_setImpedanceControllerParam";

  class OpenHRP_ImpedanceControllerService_setImpedanceControllerParamRequest : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_ImpedanceControllerService_impedanceParam i_param;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->i_param.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->i_param.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_IMPEDANCECONTROLLERSERVICE_SETIMPEDANCECONTROLLERPARAM; };
    const char * getMD5(){ return "85e6b161c8dce3c506ba0f77208d62c9"; };

  };

  class OpenHRP_ImpedanceControllerService_setImpedanceControllerParamResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_IMPEDANCECONTROLLERSERVICE_SETIMPEDANCECONTROLLERPARAM; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_ImpedanceControllerService_setImpedanceControllerParam {
    public:
    typedef OpenHRP_ImpedanceControllerService_setImpedanceControllerParamRequest Request;
    typedef OpenHRP_ImpedanceControllerService_setImpedanceControllerParamResponse Response;
  };

}
#endif

#ifndef _ROS_SERVICE_OpenHRP_StabilizerService_setParameter_h
#define _ROS_SERVICE_OpenHRP_StabilizerService_setParameter_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_StabilizerService_stParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_STABILIZERSERVICE_SETPARAMETER[] = "hrpsys_ros_bridge/OpenHRP_StabilizerService_setParameter";

  class OpenHRP_StabilizerService_setParameterRequest : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_StabilizerService_stParam i_param;

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

    const char * getType(){ return OPENHRP_STABILIZERSERVICE_SETPARAMETER; };
    const char * getMD5(){ return "4b6654575024573d32022e6cacc6c2c6"; };

  };

  class OpenHRP_StabilizerService_setParameterResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_STABILIZERSERVICE_SETPARAMETER; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_StabilizerService_setParameter {
    public:
    typedef OpenHRP_StabilizerService_setParameterRequest Request;
    typedef OpenHRP_StabilizerService_setParameterResponse Response;
  };

}
#endif

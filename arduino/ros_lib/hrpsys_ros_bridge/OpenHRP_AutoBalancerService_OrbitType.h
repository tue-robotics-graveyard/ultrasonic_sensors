#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_OrbitType_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_OrbitType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_OrbitType : public ros::Msg
  {
    public:
      enum { SHUFFLING = 0 };
      enum { CYCLOID = 1 };
      enum { RECTANGLE = 2 };

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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_OrbitType"; };
    const char * getMD5(){ return "4d2a0133311577e89eab81ac022eb007"; };

  };

}
#endif
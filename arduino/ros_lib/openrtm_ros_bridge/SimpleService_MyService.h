#ifndef _ROS_openrtm_ros_bridge_SimpleService_MyService_h
#define _ROS_openrtm_ros_bridge_SimpleService_MyService_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace openrtm_ros_bridge
{

  class SimpleService_MyService : public ros::Msg
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

    const char * getType(){ return "openrtm_ros_bridge/SimpleService_MyService"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
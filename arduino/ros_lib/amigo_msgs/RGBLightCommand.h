#ifndef _ROS_amigo_msgs_RGBLightCommand_h
#define _ROS_amigo_msgs_RGBLightCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"
#include "std_msgs/Bool.h"

namespace amigo_msgs
{

  class RGBLightCommand : public ros::Msg
  {
    public:
      std_msgs::ColorRGBA color;
      std_msgs::Bool show_color;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->color.serialize(outbuffer + offset);
      offset += this->show_color.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->color.deserialize(inbuffer + offset);
      offset += this->show_color.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "amigo_msgs/RGBLightCommand"; };
    const char * getMD5(){ return "be76ae363ce620617725762b157369a3"; };

  };

}
#endif
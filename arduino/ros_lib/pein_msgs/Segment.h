#ifndef _ROS_pein_msgs_Segment_h
#define _ROS_pein_msgs_Segment_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"
#include "sensor_msgs/Image.h"
#include "geometry_msgs/Pose.h"

namespace pein_msgs
{

  class Segment : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 pcl;
      sensor_msgs::Image rgb_image;
      sensor_msgs::Image depth_image;
      geometry_msgs::Pose pose;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pcl.serialize(outbuffer + offset);
      offset += this->rgb_image.serialize(outbuffer + offset);
      offset += this->depth_image.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pcl.deserialize(inbuffer + offset);
      offset += this->rgb_image.deserialize(inbuffer + offset);
      offset += this->depth_image.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pein_msgs/Segment"; };
    const char * getMD5(){ return "4f7a8c1b77548441a54de51cde08216e"; };

  };

}
#endif
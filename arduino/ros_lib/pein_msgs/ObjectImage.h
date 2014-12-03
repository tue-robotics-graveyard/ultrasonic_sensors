#ifndef _ROS_pein_msgs_ObjectImage_h
#define _ROS_pein_msgs_ObjectImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/PointCloud2.h"
#include "geometry_msgs/Pose.h"
#include "pein_msgs/Hypothesis.h"

namespace pein_msgs
{

  class ObjectImage : public ros::Msg
  {
    public:
      sensor_msgs::Image color_image;
      sensor_msgs::Image depth_image;
      sensor_msgs::Image color_image_mask;
      sensor_msgs::PointCloud2 point_cloud;
      geometry_msgs::Pose pose;
      uint8_t object_evidence_length;
      pein_msgs::Hypothesis st_object_evidence;
      pein_msgs::Hypothesis * object_evidence;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->color_image.serialize(outbuffer + offset);
      offset += this->depth_image.serialize(outbuffer + offset);
      offset += this->color_image_mask.serialize(outbuffer + offset);
      offset += this->point_cloud.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset++) = object_evidence_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < object_evidence_length; i++){
      offset += this->object_evidence[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->color_image.deserialize(inbuffer + offset);
      offset += this->depth_image.deserialize(inbuffer + offset);
      offset += this->color_image_mask.deserialize(inbuffer + offset);
      offset += this->point_cloud.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      uint8_t object_evidence_lengthT = *(inbuffer + offset++);
      if(object_evidence_lengthT > object_evidence_length)
        this->object_evidence = (pein_msgs::Hypothesis*)realloc(this->object_evidence, object_evidence_lengthT * sizeof(pein_msgs::Hypothesis));
      offset += 3;
      object_evidence_length = object_evidence_lengthT;
      for( uint8_t i = 0; i < object_evidence_length; i++){
      offset += this->st_object_evidence.deserialize(inbuffer + offset);
        memcpy( &(this->object_evidence[i]), &(this->st_object_evidence), sizeof(pein_msgs::Hypothesis));
      }
     return offset;
    }

    const char * getType(){ return "pein_msgs/ObjectImage"; };
    const char * getMD5(){ return "1704ca958b4ddd38d6808d09c3c2b970"; };

  };

}
#endif
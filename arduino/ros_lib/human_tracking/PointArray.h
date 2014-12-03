#ifndef _ROS_human_tracking_PointArray_h
#define _ROS_human_tracking_PointArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "human_tracking/Point.h"

namespace human_tracking
{

  class PointArray : public ros::Msg
  {
    public:
      uint8_t points_length;
      human_tracking::Point st_points;
      human_tracking::Point * points;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = points_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t points_lengthT = *(inbuffer + offset++);
      if(points_lengthT > points_length)
        this->points = (human_tracking::Point*)realloc(this->points, points_lengthT * sizeof(human_tracking::Point));
      offset += 3;
      points_length = points_lengthT;
      for( uint8_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(human_tracking::Point));
      }
     return offset;
    }

    const char * getType(){ return "human_tracking/PointArray"; };
    const char * getMD5(){ return "1a62f716996bbc98ca43dac233c98cb8"; };

  };

}
#endif
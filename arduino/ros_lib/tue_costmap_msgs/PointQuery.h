#ifndef _ROS_SERVICE_PointQuery_h
#define _ROS_SERVICE_PointQuery_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"
#include "tue_costmap_msgs/PointInfo.h"

namespace tue_costmap_msgs
{

static const char POINTQUERY[] = "tue_costmap_msgs/PointQuery";

  class PointQueryRequest : public ros::Msg
  {
    public:
      uint8_t points_length;
      geometry_msgs::PointStamped st_points;
      geometry_msgs::PointStamped * points;

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
        this->points = (geometry_msgs::PointStamped*)realloc(this->points, points_lengthT * sizeof(geometry_msgs::PointStamped));
      offset += 3;
      points_length = points_lengthT;
      for( uint8_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(geometry_msgs::PointStamped));
      }
     return offset;
    }

    const char * getType(){ return POINTQUERY; };
    const char * getMD5(){ return "c2297adb08d381758524320d95d45643"; };

  };

  class PointQueryResponse : public ros::Msg
  {
    public:
      uint8_t points_info_length;
      tue_costmap_msgs::PointInfo st_points_info;
      tue_costmap_msgs::PointInfo * points_info;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = points_info_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < points_info_length; i++){
      offset += this->points_info[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t points_info_lengthT = *(inbuffer + offset++);
      if(points_info_lengthT > points_info_length)
        this->points_info = (tue_costmap_msgs::PointInfo*)realloc(this->points_info, points_info_lengthT * sizeof(tue_costmap_msgs::PointInfo));
      offset += 3;
      points_info_length = points_info_lengthT;
      for( uint8_t i = 0; i < points_info_length; i++){
      offset += this->st_points_info.deserialize(inbuffer + offset);
        memcpy( &(this->points_info[i]), &(this->st_points_info), sizeof(tue_costmap_msgs::PointInfo));
      }
     return offset;
    }

    const char * getType(){ return POINTQUERY; };
    const char * getMD5(){ return "eeb2660344f49f2579dc847a0972ea9b"; };

  };

  class PointQuery {
    public:
    typedef PointQueryRequest Request;
    typedef PointQueryResponse Response;
  };

}
#endif

#ifndef _ROS_ed_EntityInfo_h
#define _ROS_ed_EntityInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"

namespace ed
{

  class EntityInfo : public ros::Msg
  {
    public:
      char * id;
      char * type;
      ros::Time last_update_time;
      ros::Time creation_time;
      bool has_shape;
      geometry_msgs::Pose pose;
      uint8_t convex_hull_length;
      geometry_msgs::Point st_convex_hull;
      geometry_msgs::Point * convex_hull;
      geometry_msgs::Point center_point;
      float z_min;
      float z_max;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen( (const char*) this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      uint32_t length_type = strlen( (const char*) this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset + 0) = (this->last_update_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_update_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_update_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_update_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_update_time.sec);
      *(outbuffer + offset + 0) = (this->last_update_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_update_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_update_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_update_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_update_time.nsec);
      *(outbuffer + offset + 0) = (this->creation_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->creation_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->creation_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->creation_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->creation_time.sec);
      *(outbuffer + offset + 0) = (this->creation_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->creation_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->creation_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->creation_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->creation_time.nsec);
      union {
        bool real;
        uint8_t base;
      } u_has_shape;
      u_has_shape.real = this->has_shape;
      *(outbuffer + offset + 0) = (u_has_shape.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_shape);
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset++) = convex_hull_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < convex_hull_length; i++){
      offset += this->convex_hull[i].serialize(outbuffer + offset);
      }
      offset += this->center_point.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_z_min;
      u_z_min.real = this->z_min;
      *(outbuffer + offset + 0) = (u_z_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_min);
      union {
        float real;
        uint32_t base;
      } u_z_max;
      u_z_max.real = this->z_max;
      *(outbuffer + offset + 0) = (u_z_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_max);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      this->last_update_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_update_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_update_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_update_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_update_time.sec);
      this->last_update_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_update_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_update_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_update_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_update_time.nsec);
      this->creation_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->creation_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->creation_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->creation_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->creation_time.sec);
      this->creation_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->creation_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->creation_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->creation_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->creation_time.nsec);
      union {
        bool real;
        uint8_t base;
      } u_has_shape;
      u_has_shape.base = 0;
      u_has_shape.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_shape = u_has_shape.real;
      offset += sizeof(this->has_shape);
      offset += this->pose.deserialize(inbuffer + offset);
      uint8_t convex_hull_lengthT = *(inbuffer + offset++);
      if(convex_hull_lengthT > convex_hull_length)
        this->convex_hull = (geometry_msgs::Point*)realloc(this->convex_hull, convex_hull_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      convex_hull_length = convex_hull_lengthT;
      for( uint8_t i = 0; i < convex_hull_length; i++){
      offset += this->st_convex_hull.deserialize(inbuffer + offset);
        memcpy( &(this->convex_hull[i]), &(this->st_convex_hull), sizeof(geometry_msgs::Point));
      }
      offset += this->center_point.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_z_min;
      u_z_min.base = 0;
      u_z_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z_min = u_z_min.real;
      offset += sizeof(this->z_min);
      union {
        float real;
        uint32_t base;
      } u_z_max;
      u_z_max.base = 0;
      u_z_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z_max = u_z_max.real;
      offset += sizeof(this->z_max);
     return offset;
    }

    const char * getType(){ return "ed/EntityInfo"; };
    const char * getMD5(){ return "61e5b367203751ef091ec2a8a59d3350"; };

  };

}
#endif
#ifndef _ROS_SERVICE_GetPath_h
#define _ROS_SERVICE_GetPath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace tue_move_base_msgs
{

static const char GETPATH[] = "tue_move_base_msgs/GetPath";

  class GetPathRequest : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped target_pose;
      float goal_area_radius;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->target_pose.serialize(outbuffer + offset);
      int32_t * val_goal_area_radius = (int32_t *) &(this->goal_area_radius);
      int32_t exp_goal_area_radius = (((*val_goal_area_radius)>>23)&255);
      if(exp_goal_area_radius != 0)
        exp_goal_area_radius += 1023-127;
      int32_t sig_goal_area_radius = *val_goal_area_radius;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_goal_area_radius<<5) & 0xff;
      *(outbuffer + offset++) = (sig_goal_area_radius>>3) & 0xff;
      *(outbuffer + offset++) = (sig_goal_area_radius>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_goal_area_radius<<4) & 0xF0) | ((sig_goal_area_radius>>19)&0x0F);
      *(outbuffer + offset++) = (exp_goal_area_radius>>4) & 0x7F;
      if(this->goal_area_radius < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->target_pose.deserialize(inbuffer + offset);
      uint32_t * val_goal_area_radius = (uint32_t*) &(this->goal_area_radius);
      offset += 3;
      *val_goal_area_radius = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_goal_area_radius |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_goal_area_radius |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_goal_area_radius |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_goal_area_radius = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_goal_area_radius |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_goal_area_radius !=0)
        *val_goal_area_radius |= ((exp_goal_area_radius)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->goal_area_radius = -this->goal_area_radius;
     return offset;
    }

    const char * getType(){ return GETPATH; };
    const char * getMD5(){ return "bdd3af02db03c222f404523e876a8e89"; };

  };

  class GetPathResponse : public ros::Msg
  {
    public:
      uint8_t path_length;
      geometry_msgs::PoseStamped st_path;
      geometry_msgs::PoseStamped * path;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = path_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < path_length; i++){
      offset += this->path[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t path_lengthT = *(inbuffer + offset++);
      if(path_lengthT > path_length)
        this->path = (geometry_msgs::PoseStamped*)realloc(this->path, path_lengthT * sizeof(geometry_msgs::PoseStamped));
      offset += 3;
      path_length = path_lengthT;
      for( uint8_t i = 0; i < path_length; i++){
      offset += this->st_path.deserialize(inbuffer + offset);
        memcpy( &(this->path[i]), &(this->st_path), sizeof(geometry_msgs::PoseStamped));
      }
     return offset;
    }

    const char * getType(){ return GETPATH; };
    const char * getMD5(){ return "4fde6cfd88a2e9547561cecdb69ccf8c"; };

  };

  class GetPath {
    public:
    typedef GetPathRequest Request;
    typedef GetPathResponse Response;
  };

}
#endif

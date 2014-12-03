#ifndef _ROS_SERVICE_GetBaseGoalPoses_h
#define _ROS_SERVICE_GetBaseGoalPoses_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace amigo_inverse_reachability
{

static const char GETBASEGOALPOSES[] = "amigo_inverse_reachability/GetBaseGoalPoses";

  class GetBaseGoalPosesRequest : public ros::Msg
  {
    public:
      geometry_msgs::Pose robot_pose;
      geometry_msgs::Pose target_pose;
      float x_offset;
      float y_offset;
      float cost_threshold_norm;
      float target_area_radius;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->robot_pose.serialize(outbuffer + offset);
      offset += this->target_pose.serialize(outbuffer + offset);
      int32_t * val_x_offset = (int32_t *) &(this->x_offset);
      int32_t exp_x_offset = (((*val_x_offset)>>23)&255);
      if(exp_x_offset != 0)
        exp_x_offset += 1023-127;
      int32_t sig_x_offset = *val_x_offset;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_x_offset<<5) & 0xff;
      *(outbuffer + offset++) = (sig_x_offset>>3) & 0xff;
      *(outbuffer + offset++) = (sig_x_offset>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_x_offset<<4) & 0xF0) | ((sig_x_offset>>19)&0x0F);
      *(outbuffer + offset++) = (exp_x_offset>>4) & 0x7F;
      if(this->x_offset < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_y_offset = (int32_t *) &(this->y_offset);
      int32_t exp_y_offset = (((*val_y_offset)>>23)&255);
      if(exp_y_offset != 0)
        exp_y_offset += 1023-127;
      int32_t sig_y_offset = *val_y_offset;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_y_offset<<5) & 0xff;
      *(outbuffer + offset++) = (sig_y_offset>>3) & 0xff;
      *(outbuffer + offset++) = (sig_y_offset>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_y_offset<<4) & 0xF0) | ((sig_y_offset>>19)&0x0F);
      *(outbuffer + offset++) = (exp_y_offset>>4) & 0x7F;
      if(this->y_offset < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_cost_threshold_norm = (int32_t *) &(this->cost_threshold_norm);
      int32_t exp_cost_threshold_norm = (((*val_cost_threshold_norm)>>23)&255);
      if(exp_cost_threshold_norm != 0)
        exp_cost_threshold_norm += 1023-127;
      int32_t sig_cost_threshold_norm = *val_cost_threshold_norm;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_cost_threshold_norm<<5) & 0xff;
      *(outbuffer + offset++) = (sig_cost_threshold_norm>>3) & 0xff;
      *(outbuffer + offset++) = (sig_cost_threshold_norm>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_cost_threshold_norm<<4) & 0xF0) | ((sig_cost_threshold_norm>>19)&0x0F);
      *(outbuffer + offset++) = (exp_cost_threshold_norm>>4) & 0x7F;
      if(this->cost_threshold_norm < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_target_area_radius = (int32_t *) &(this->target_area_radius);
      int32_t exp_target_area_radius = (((*val_target_area_radius)>>23)&255);
      if(exp_target_area_radius != 0)
        exp_target_area_radius += 1023-127;
      int32_t sig_target_area_radius = *val_target_area_radius;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_target_area_radius<<5) & 0xff;
      *(outbuffer + offset++) = (sig_target_area_radius>>3) & 0xff;
      *(outbuffer + offset++) = (sig_target_area_radius>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_target_area_radius<<4) & 0xF0) | ((sig_target_area_radius>>19)&0x0F);
      *(outbuffer + offset++) = (exp_target_area_radius>>4) & 0x7F;
      if(this->target_area_radius < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->robot_pose.deserialize(inbuffer + offset);
      offset += this->target_pose.deserialize(inbuffer + offset);
      uint32_t * val_x_offset = (uint32_t*) &(this->x_offset);
      offset += 3;
      *val_x_offset = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_x_offset |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_x_offset |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_x_offset |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_x_offset = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_x_offset |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_x_offset !=0)
        *val_x_offset |= ((exp_x_offset)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->x_offset = -this->x_offset;
      uint32_t * val_y_offset = (uint32_t*) &(this->y_offset);
      offset += 3;
      *val_y_offset = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_y_offset |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_y_offset |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_y_offset |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_y_offset = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_y_offset |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_y_offset !=0)
        *val_y_offset |= ((exp_y_offset)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->y_offset = -this->y_offset;
      uint32_t * val_cost_threshold_norm = (uint32_t*) &(this->cost_threshold_norm);
      offset += 3;
      *val_cost_threshold_norm = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_cost_threshold_norm |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_cost_threshold_norm |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_cost_threshold_norm |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_cost_threshold_norm = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_cost_threshold_norm |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_cost_threshold_norm !=0)
        *val_cost_threshold_norm |= ((exp_cost_threshold_norm)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->cost_threshold_norm = -this->cost_threshold_norm;
      uint32_t * val_target_area_radius = (uint32_t*) &(this->target_area_radius);
      offset += 3;
      *val_target_area_radius = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_target_area_radius |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_target_area_radius |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_target_area_radius |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_target_area_radius = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_target_area_radius |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_target_area_radius !=0)
        *val_target_area_radius |= ((exp_target_area_radius)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->target_area_radius = -this->target_area_radius;
     return offset;
    }

    const char * getType(){ return GETBASEGOALPOSES; };
    const char * getMD5(){ return "762e9214699c5ae6f0489c2cea195218"; };

  };

  class GetBaseGoalPosesResponse : public ros::Msg
  {
    public:
      uint8_t base_goal_poses_length;
      geometry_msgs::Pose st_base_goal_poses;
      geometry_msgs::Pose * base_goal_poses;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = base_goal_poses_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < base_goal_poses_length; i++){
      offset += this->base_goal_poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t base_goal_poses_lengthT = *(inbuffer + offset++);
      if(base_goal_poses_lengthT > base_goal_poses_length)
        this->base_goal_poses = (geometry_msgs::Pose*)realloc(this->base_goal_poses, base_goal_poses_lengthT * sizeof(geometry_msgs::Pose));
      offset += 3;
      base_goal_poses_length = base_goal_poses_lengthT;
      for( uint8_t i = 0; i < base_goal_poses_length; i++){
      offset += this->st_base_goal_poses.deserialize(inbuffer + offset);
        memcpy( &(this->base_goal_poses[i]), &(this->st_base_goal_poses), sizeof(geometry_msgs::Pose));
      }
     return offset;
    }

    const char * getType(){ return GETBASEGOALPOSES; };
    const char * getMD5(){ return "679fe06ffa26e59e95426e0df5775054"; };

  };

  class GetBaseGoalPoses {
    public:
    typedef GetBaseGoalPosesRequest Request;
    typedef GetBaseGoalPosesResponse Response;
  };

}
#endif

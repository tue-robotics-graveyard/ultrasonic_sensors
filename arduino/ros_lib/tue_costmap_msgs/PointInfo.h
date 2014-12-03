#ifndef _ROS_tue_costmap_msgs_PointInfo_h
#define _ROS_tue_costmap_msgs_PointInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"

namespace tue_costmap_msgs
{

  class PointInfo : public ros::Msg
  {
    public:
      geometry_msgs::PointStamped point;
      float distance_to_closest_obstacle;
      float cost;
      float resolution;
      float size_cells_x;
      float size_cells_y;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->point.serialize(outbuffer + offset);
      int32_t * val_distance_to_closest_obstacle = (int32_t *) &(this->distance_to_closest_obstacle);
      int32_t exp_distance_to_closest_obstacle = (((*val_distance_to_closest_obstacle)>>23)&255);
      if(exp_distance_to_closest_obstacle != 0)
        exp_distance_to_closest_obstacle += 1023-127;
      int32_t sig_distance_to_closest_obstacle = *val_distance_to_closest_obstacle;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_distance_to_closest_obstacle<<5) & 0xff;
      *(outbuffer + offset++) = (sig_distance_to_closest_obstacle>>3) & 0xff;
      *(outbuffer + offset++) = (sig_distance_to_closest_obstacle>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_distance_to_closest_obstacle<<4) & 0xF0) | ((sig_distance_to_closest_obstacle>>19)&0x0F);
      *(outbuffer + offset++) = (exp_distance_to_closest_obstacle>>4) & 0x7F;
      if(this->distance_to_closest_obstacle < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_cost = (int32_t *) &(this->cost);
      int32_t exp_cost = (((*val_cost)>>23)&255);
      if(exp_cost != 0)
        exp_cost += 1023-127;
      int32_t sig_cost = *val_cost;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_cost<<5) & 0xff;
      *(outbuffer + offset++) = (sig_cost>>3) & 0xff;
      *(outbuffer + offset++) = (sig_cost>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_cost<<4) & 0xF0) | ((sig_cost>>19)&0x0F);
      *(outbuffer + offset++) = (exp_cost>>4) & 0x7F;
      if(this->cost < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_resolution = (int32_t *) &(this->resolution);
      int32_t exp_resolution = (((*val_resolution)>>23)&255);
      if(exp_resolution != 0)
        exp_resolution += 1023-127;
      int32_t sig_resolution = *val_resolution;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_resolution<<5) & 0xff;
      *(outbuffer + offset++) = (sig_resolution>>3) & 0xff;
      *(outbuffer + offset++) = (sig_resolution>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_resolution<<4) & 0xF0) | ((sig_resolution>>19)&0x0F);
      *(outbuffer + offset++) = (exp_resolution>>4) & 0x7F;
      if(this->resolution < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_size_cells_x = (int32_t *) &(this->size_cells_x);
      int32_t exp_size_cells_x = (((*val_size_cells_x)>>23)&255);
      if(exp_size_cells_x != 0)
        exp_size_cells_x += 1023-127;
      int32_t sig_size_cells_x = *val_size_cells_x;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_size_cells_x<<5) & 0xff;
      *(outbuffer + offset++) = (sig_size_cells_x>>3) & 0xff;
      *(outbuffer + offset++) = (sig_size_cells_x>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_size_cells_x<<4) & 0xF0) | ((sig_size_cells_x>>19)&0x0F);
      *(outbuffer + offset++) = (exp_size_cells_x>>4) & 0x7F;
      if(this->size_cells_x < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_size_cells_y = (int32_t *) &(this->size_cells_y);
      int32_t exp_size_cells_y = (((*val_size_cells_y)>>23)&255);
      if(exp_size_cells_y != 0)
        exp_size_cells_y += 1023-127;
      int32_t sig_size_cells_y = *val_size_cells_y;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_size_cells_y<<5) & 0xff;
      *(outbuffer + offset++) = (sig_size_cells_y>>3) & 0xff;
      *(outbuffer + offset++) = (sig_size_cells_y>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_size_cells_y<<4) & 0xF0) | ((sig_size_cells_y>>19)&0x0F);
      *(outbuffer + offset++) = (exp_size_cells_y>>4) & 0x7F;
      if(this->size_cells_y < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->point.deserialize(inbuffer + offset);
      uint32_t * val_distance_to_closest_obstacle = (uint32_t*) &(this->distance_to_closest_obstacle);
      offset += 3;
      *val_distance_to_closest_obstacle = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_distance_to_closest_obstacle |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_distance_to_closest_obstacle |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_distance_to_closest_obstacle |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_distance_to_closest_obstacle = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_distance_to_closest_obstacle |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_distance_to_closest_obstacle !=0)
        *val_distance_to_closest_obstacle |= ((exp_distance_to_closest_obstacle)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->distance_to_closest_obstacle = -this->distance_to_closest_obstacle;
      uint32_t * val_cost = (uint32_t*) &(this->cost);
      offset += 3;
      *val_cost = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_cost |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_cost |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_cost |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_cost = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_cost |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_cost !=0)
        *val_cost |= ((exp_cost)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->cost = -this->cost;
      uint32_t * val_resolution = (uint32_t*) &(this->resolution);
      offset += 3;
      *val_resolution = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_resolution |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_resolution |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_resolution |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_resolution = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_resolution |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_resolution !=0)
        *val_resolution |= ((exp_resolution)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->resolution = -this->resolution;
      uint32_t * val_size_cells_x = (uint32_t*) &(this->size_cells_x);
      offset += 3;
      *val_size_cells_x = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_size_cells_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_size_cells_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_size_cells_x |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_size_cells_x = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_size_cells_x |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_size_cells_x !=0)
        *val_size_cells_x |= ((exp_size_cells_x)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->size_cells_x = -this->size_cells_x;
      uint32_t * val_size_cells_y = (uint32_t*) &(this->size_cells_y);
      offset += 3;
      *val_size_cells_y = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_size_cells_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_size_cells_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_size_cells_y |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_size_cells_y = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_size_cells_y |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_size_cells_y !=0)
        *val_size_cells_y |= ((exp_size_cells_y)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->size_cells_y = -this->size_cells_y;
     return offset;
    }

    const char * getType(){ return "tue_costmap_msgs/PointInfo"; };
    const char * getMD5(){ return "ed4ab1a2b5f1547169f62b7fdf79258b"; };

  };

}
#endif
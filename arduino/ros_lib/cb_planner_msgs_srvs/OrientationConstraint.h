#ifndef _ROS_cb_planner_msgs_srvs_OrientationConstraint_h
#define _ROS_cb_planner_msgs_srvs_OrientationConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace cb_planner_msgs_srvs
{

  class OrientationConstraint : public ros::Msg
  {
    public:
      char * frame;
      geometry_msgs::Point look_at;
      float angle_offset;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_frame = strlen( (const char*) this->frame);
      memcpy(outbuffer + offset, &length_frame, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->frame, length_frame);
      offset += length_frame;
      offset += this->look_at.serialize(outbuffer + offset);
      int32_t * val_angle_offset = (int32_t *) &(this->angle_offset);
      int32_t exp_angle_offset = (((*val_angle_offset)>>23)&255);
      if(exp_angle_offset != 0)
        exp_angle_offset += 1023-127;
      int32_t sig_angle_offset = *val_angle_offset;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_angle_offset<<5) & 0xff;
      *(outbuffer + offset++) = (sig_angle_offset>>3) & 0xff;
      *(outbuffer + offset++) = (sig_angle_offset>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_angle_offset<<4) & 0xF0) | ((sig_angle_offset>>19)&0x0F);
      *(outbuffer + offset++) = (exp_angle_offset>>4) & 0x7F;
      if(this->angle_offset < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_frame;
      memcpy(&length_frame, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame-1]=0;
      this->frame = (char *)(inbuffer + offset-1);
      offset += length_frame;
      offset += this->look_at.deserialize(inbuffer + offset);
      uint32_t * val_angle_offset = (uint32_t*) &(this->angle_offset);
      offset += 3;
      *val_angle_offset = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_angle_offset |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_angle_offset |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_angle_offset |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_angle_offset = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_angle_offset |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_angle_offset !=0)
        *val_angle_offset |= ((exp_angle_offset)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->angle_offset = -this->angle_offset;
     return offset;
    }

    const char * getType(){ return "cb_planner_msgs_srvs/OrientationConstraint"; };
    const char * getMD5(){ return "99e8d1698957630cc6ca4e72617389d0"; };

  };

}
#endif
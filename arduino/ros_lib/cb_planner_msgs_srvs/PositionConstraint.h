#ifndef _ROS_cb_planner_msgs_srvs_PositionConstraint_h
#define _ROS_cb_planner_msgs_srvs_PositionConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cb_planner_msgs_srvs
{

  class PositionConstraint : public ros::Msg
  {
    public:
      char * frame;
      char * constraint;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_frame = strlen( (const char*) this->frame);
      memcpy(outbuffer + offset, &length_frame, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->frame, length_frame);
      offset += length_frame;
      uint32_t length_constraint = strlen( (const char*) this->constraint);
      memcpy(outbuffer + offset, &length_constraint, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->constraint, length_constraint);
      offset += length_constraint;
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
      uint32_t length_constraint;
      memcpy(&length_constraint, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_constraint; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_constraint-1]=0;
      this->constraint = (char *)(inbuffer + offset-1);
      offset += length_constraint;
     return offset;
    }

    const char * getType(){ return "cb_planner_msgs_srvs/PositionConstraint"; };
    const char * getMD5(){ return "136c52ce3c2804a47d6f930727303f1d"; };

  };

}
#endif
#ifndef _ROS_SERVICE_CheckPlan_h
#define _ROS_SERVICE_CheckPlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace cb_planner_msgs_srvs
{

static const char CHECKPLAN[] = "cb_planner_msgs_srvs/CheckPlan";

  class CheckPlanRequest : public ros::Msg
  {
    public:
      uint8_t plan_length;
      geometry_msgs::PoseStamped st_plan;
      geometry_msgs::PoseStamped * plan;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = plan_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < plan_length; i++){
      offset += this->plan[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t plan_lengthT = *(inbuffer + offset++);
      if(plan_lengthT > plan_length)
        this->plan = (geometry_msgs::PoseStamped*)realloc(this->plan, plan_lengthT * sizeof(geometry_msgs::PoseStamped));
      offset += 3;
      plan_length = plan_lengthT;
      for( uint8_t i = 0; i < plan_length; i++){
      offset += this->st_plan.deserialize(inbuffer + offset);
        memcpy( &(this->plan[i]), &(this->st_plan), sizeof(geometry_msgs::PoseStamped));
      }
     return offset;
    }

    const char * getType(){ return CHECKPLAN; };
    const char * getMD5(){ return "46d17a7e8a557bad200aa6a1e72ab408"; };

  };

  class CheckPlanResponse : public ros::Msg
  {
    public:
      bool valid;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_valid;
      u_valid.real = this->valid;
      *(outbuffer + offset + 0) = (u_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_valid;
      u_valid.base = 0;
      u_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->valid = u_valid.real;
      offset += sizeof(this->valid);
     return offset;
    }

    const char * getType(){ return CHECKPLAN; };
    const char * getMD5(){ return "a04c5033e7efda95fc3786e8d449c6e7"; };

  };

  class CheckPlan {
    public:
    typedef CheckPlanRequest Request;
    typedef CheckPlanResponse Response;
  };

}
#endif

#ifndef _ROS_SERVICE_GetPlan_h
#define _ROS_SERVICE_GetPlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "cb_planner_msgs_srvs/PositionConstraint.h"

namespace cb_planner_msgs_srvs
{

static const char GETPLAN[] = "cb_planner_msgs_srvs/GetPlan";

  class GetPlanRequest : public ros::Msg
  {
    public:
      uint8_t goal_position_constraints_length;
      cb_planner_msgs_srvs::PositionConstraint st_goal_position_constraints;
      cb_planner_msgs_srvs::PositionConstraint * goal_position_constraints;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = goal_position_constraints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < goal_position_constraints_length; i++){
      offset += this->goal_position_constraints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t goal_position_constraints_lengthT = *(inbuffer + offset++);
      if(goal_position_constraints_lengthT > goal_position_constraints_length)
        this->goal_position_constraints = (cb_planner_msgs_srvs::PositionConstraint*)realloc(this->goal_position_constraints, goal_position_constraints_lengthT * sizeof(cb_planner_msgs_srvs::PositionConstraint));
      offset += 3;
      goal_position_constraints_length = goal_position_constraints_lengthT;
      for( uint8_t i = 0; i < goal_position_constraints_length; i++){
      offset += this->st_goal_position_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->goal_position_constraints[i]), &(this->st_goal_position_constraints), sizeof(cb_planner_msgs_srvs::PositionConstraint));
      }
     return offset;
    }

    const char * getType(){ return GETPLAN; };
    const char * getMD5(){ return "c94ca2086fbed67d052cebaf90739c75"; };

  };

  class GetPlanResponse : public ros::Msg
  {
    public:
      uint8_t plan_length;
      geometry_msgs::PoseStamped st_plan;
      geometry_msgs::PoseStamped * plan;
      bool succes;

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
      union {
        bool real;
        uint8_t base;
      } u_succes;
      u_succes.real = this->succes;
      *(outbuffer + offset + 0) = (u_succes.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->succes);
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
      union {
        bool real;
        uint8_t base;
      } u_succes;
      u_succes.base = 0;
      u_succes.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->succes = u_succes.real;
      offset += sizeof(this->succes);
     return offset;
    }

    const char * getType(){ return GETPLAN; };
    const char * getMD5(){ return "8448700c50b6388a44dc177b16b52d00"; };

  };

  class GetPlan {
    public:
    typedef GetPlanRequest Request;
    typedef GetPlanResponse Response;
  };

}
#endif

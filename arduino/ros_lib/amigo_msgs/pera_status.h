#ifndef _ROS_amigo_msgs_pera_status_h
#define _ROS_amigo_msgs_pera_status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Bool.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"

namespace amigo_msgs
{

  class pera_status : public ros::Msg
  {
    public:
      std_msgs::Bool enable;
      std_msgs::Bool error;
      std_msgs::Bool homed;
      std_msgs::Bool ebutton_pressed;
      std_msgs::String gripper;
      std_msgs::Float64 jnt_errors[8];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->enable.serialize(outbuffer + offset);
      offset += this->error.serialize(outbuffer + offset);
      offset += this->homed.serialize(outbuffer + offset);
      offset += this->ebutton_pressed.serialize(outbuffer + offset);
      offset += this->gripper.serialize(outbuffer + offset);
      unsigned char * jnt_errors_val = (unsigned char *) this->jnt_errors;
      for( uint8_t i = 0; i < 8; i++){
      offset += this->jnt_errors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->enable.deserialize(inbuffer + offset);
      offset += this->error.deserialize(inbuffer + offset);
      offset += this->homed.deserialize(inbuffer + offset);
      offset += this->ebutton_pressed.deserialize(inbuffer + offset);
      offset += this->gripper.deserialize(inbuffer + offset);
      uint8_t * jnt_errors_val = (uint8_t*) this->jnt_errors;
      for( uint8_t i = 0; i < 8; i++){
      offset += this->jnt_errors[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "amigo_msgs/pera_status"; };
    const char * getMD5(){ return "95532a8b77ab687cc9f0a954262df803"; };

  };

}
#endif
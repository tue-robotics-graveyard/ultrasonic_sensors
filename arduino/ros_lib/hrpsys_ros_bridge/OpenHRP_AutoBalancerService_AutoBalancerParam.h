#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_AutoBalancerParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_AutoBalancerParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_AutoBalancerParam : public ros::Msg
  {
    public:
      std_msgs::Float64MultiArray default_zmp_offsets;
      float move_base_gain;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->default_zmp_offsets.serialize(outbuffer + offset);
      int32_t * val_move_base_gain = (int32_t *) &(this->move_base_gain);
      int32_t exp_move_base_gain = (((*val_move_base_gain)>>23)&255);
      if(exp_move_base_gain != 0)
        exp_move_base_gain += 1023-127;
      int32_t sig_move_base_gain = *val_move_base_gain;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_move_base_gain<<5) & 0xff;
      *(outbuffer + offset++) = (sig_move_base_gain>>3) & 0xff;
      *(outbuffer + offset++) = (sig_move_base_gain>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_move_base_gain<<4) & 0xF0) | ((sig_move_base_gain>>19)&0x0F);
      *(outbuffer + offset++) = (exp_move_base_gain>>4) & 0x7F;
      if(this->move_base_gain < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->default_zmp_offsets.deserialize(inbuffer + offset);
      uint32_t * val_move_base_gain = (uint32_t*) &(this->move_base_gain);
      offset += 3;
      *val_move_base_gain = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_move_base_gain |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_move_base_gain |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_move_base_gain |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_move_base_gain = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_move_base_gain |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_move_base_gain !=0)
        *val_move_base_gain |= ((exp_move_base_gain)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->move_base_gain = -this->move_base_gain;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_AutoBalancerParam"; };
    const char * getMD5(){ return "bb8273a34fdc60819ba7ee5810d03dc4"; };

  };

}
#endif
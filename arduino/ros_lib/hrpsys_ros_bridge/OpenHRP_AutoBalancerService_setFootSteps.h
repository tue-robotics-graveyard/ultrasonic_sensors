#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_setFootSteps_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_setFootSteps_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footstep.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_SETFOOTSTEPS[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_setFootSteps";

  class OpenHRP_AutoBalancerService_setFootStepsRequest : public ros::Msg
  {
    public:
      uint8_t fs_length;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep st_fs;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep * fs;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = fs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fs_length; i++){
      offset += this->fs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t fs_lengthT = *(inbuffer + offset++);
      if(fs_lengthT > fs_length)
        this->fs = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep*)realloc(this->fs, fs_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep));
      offset += 3;
      fs_length = fs_lengthT;
      for( uint8_t i = 0; i < fs_length; i++){
      offset += this->st_fs.deserialize(inbuffer + offset);
        memcpy( &(this->fs[i]), &(this->st_fs), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_SETFOOTSTEPS; };
    const char * getMD5(){ return "f85957b17cc08a30bbfab3dc61b1d556"; };

  };

  class OpenHRP_AutoBalancerService_setFootStepsResponse : public ros::Msg
  {
    public:
      bool operation_return;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operation_return);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_SETFOOTSTEPS; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_AutoBalancerService_setFootSteps {
    public:
    typedef OpenHRP_AutoBalancerService_setFootStepsRequest Request;
    typedef OpenHRP_AutoBalancerService_setFootStepsResponse Response;
  };

}
#endif

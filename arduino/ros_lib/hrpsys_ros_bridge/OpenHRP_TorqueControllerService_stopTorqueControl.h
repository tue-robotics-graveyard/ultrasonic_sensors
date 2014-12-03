#ifndef _ROS_SERVICE_OpenHRP_TorqueControllerService_stopTorqueControl_h
#define _ROS_SERVICE_OpenHRP_TorqueControllerService_stopTorqueControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_TORQUECONTROLLERSERVICE_STOPTORQUECONTROL[] = "hrpsys_ros_bridge/OpenHRP_TorqueControllerService_stopTorqueControl";

  class OpenHRP_TorqueControllerService_stopTorqueControlRequest : public ros::Msg
  {
    public:
      char * jname;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_jname = strlen( (const char*) this->jname);
      memcpy(outbuffer + offset, &length_jname, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->jname, length_jname);
      offset += length_jname;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_jname;
      memcpy(&length_jname, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_jname; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_jname-1]=0;
      this->jname = (char *)(inbuffer + offset-1);
      offset += length_jname;
     return offset;
    }

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_STOPTORQUECONTROL; };
    const char * getMD5(){ return "d2000700cdaf8cd862b8bf8fe8ba6fda"; };

  };

  class OpenHRP_TorqueControllerService_stopTorqueControlResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_STOPTORQUECONTROL; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_TorqueControllerService_stopTorqueControl {
    public:
    typedef OpenHRP_TorqueControllerService_stopTorqueControlRequest Request;
    typedef OpenHRP_TorqueControllerService_stopTorqueControlResponse Response;
  };

}
#endif

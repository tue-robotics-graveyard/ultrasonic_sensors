#ifndef _ROS_SERVICE_OpenHRP_GraspControllerService_startGrasp_h
#define _ROS_SERVICE_OpenHRP_GraspControllerService_startGrasp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_GRASPCONTROLLERSERVICE_STARTGRASP[] = "hrpsys_ros_bridge/OpenHRP_GraspControllerService_startGrasp";

  class OpenHRP_GraspControllerService_startGraspRequest : public ros::Msg
  {
    public:
      char * name;
      float target_error;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      int32_t * val_target_error = (int32_t *) &(this->target_error);
      int32_t exp_target_error = (((*val_target_error)>>23)&255);
      if(exp_target_error != 0)
        exp_target_error += 1023-127;
      int32_t sig_target_error = *val_target_error;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_target_error<<5) & 0xff;
      *(outbuffer + offset++) = (sig_target_error>>3) & 0xff;
      *(outbuffer + offset++) = (sig_target_error>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_target_error<<4) & 0xF0) | ((sig_target_error>>19)&0x0F);
      *(outbuffer + offset++) = (exp_target_error>>4) & 0x7F;
      if(this->target_error < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t * val_target_error = (uint32_t*) &(this->target_error);
      offset += 3;
      *val_target_error = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_target_error |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_target_error |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_target_error |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_target_error = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_target_error |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_target_error !=0)
        *val_target_error |= ((exp_target_error)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->target_error = -this->target_error;
     return offset;
    }

    const char * getType(){ return OPENHRP_GRASPCONTROLLERSERVICE_STARTGRASP; };
    const char * getMD5(){ return "4b4e4ccae8b8f257602cbe7f48c64b68"; };

  };

  class OpenHRP_GraspControllerService_startGraspResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_GRASPCONTROLLERSERVICE_STARTGRASP; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_GraspControllerService_startGrasp {
    public:
    typedef OpenHRP_GraspControllerService_startGraspRequest Request;
    typedef OpenHRP_GraspControllerService_startGraspResponse Response;
  };

}
#endif

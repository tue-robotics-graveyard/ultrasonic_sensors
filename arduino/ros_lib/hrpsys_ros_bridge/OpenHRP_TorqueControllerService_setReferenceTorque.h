#ifndef _ROS_SERVICE_OpenHRP_TorqueControllerService_setReferenceTorque_h
#define _ROS_SERVICE_OpenHRP_TorqueControllerService_setReferenceTorque_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_TORQUECONTROLLERSERVICE_SETREFERENCETORQUE[] = "hrpsys_ros_bridge/OpenHRP_TorqueControllerService_setReferenceTorque";

  class OpenHRP_TorqueControllerService_setReferenceTorqueRequest : public ros::Msg
  {
    public:
      char * jname;
      float tauRef;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_jname = strlen( (const char*) this->jname);
      memcpy(outbuffer + offset, &length_jname, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->jname, length_jname);
      offset += length_jname;
      int32_t * val_tauRef = (int32_t *) &(this->tauRef);
      int32_t exp_tauRef = (((*val_tauRef)>>23)&255);
      if(exp_tauRef != 0)
        exp_tauRef += 1023-127;
      int32_t sig_tauRef = *val_tauRef;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_tauRef<<5) & 0xff;
      *(outbuffer + offset++) = (sig_tauRef>>3) & 0xff;
      *(outbuffer + offset++) = (sig_tauRef>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_tauRef<<4) & 0xF0) | ((sig_tauRef>>19)&0x0F);
      *(outbuffer + offset++) = (exp_tauRef>>4) & 0x7F;
      if(this->tauRef < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint32_t * val_tauRef = (uint32_t*) &(this->tauRef);
      offset += 3;
      *val_tauRef = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_tauRef |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_tauRef |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_tauRef |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_tauRef = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_tauRef |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_tauRef !=0)
        *val_tauRef |= ((exp_tauRef)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->tauRef = -this->tauRef;
     return offset;
    }

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_SETREFERENCETORQUE; };
    const char * getMD5(){ return "1153c46acb791af55d857dbb85eb7e0a"; };

  };

  class OpenHRP_TorqueControllerService_setReferenceTorqueResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_SETREFERENCETORQUE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_TorqueControllerService_setReferenceTorque {
    public:
    typedef OpenHRP_TorqueControllerService_setReferenceTorqueRequest Request;
    typedef OpenHRP_TorqueControllerService_setReferenceTorqueResponse Response;
  };

}
#endif

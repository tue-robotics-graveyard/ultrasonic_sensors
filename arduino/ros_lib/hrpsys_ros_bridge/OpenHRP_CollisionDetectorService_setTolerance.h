#ifndef _ROS_SERVICE_OpenHRP_CollisionDetectorService_setTolerance_h
#define _ROS_SERVICE_OpenHRP_CollisionDetectorService_setTolerance_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_COLLISIONDETECTORSERVICE_SETTOLERANCE[] = "hrpsys_ros_bridge/OpenHRP_CollisionDetectorService_setTolerance";

  class OpenHRP_CollisionDetectorService_setToleranceRequest : public ros::Msg
  {
    public:
      char * link_pair_name;
      float tolerance;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_link_pair_name = strlen( (const char*) this->link_pair_name);
      memcpy(outbuffer + offset, &length_link_pair_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_pair_name, length_link_pair_name);
      offset += length_link_pair_name;
      int32_t * val_tolerance = (int32_t *) &(this->tolerance);
      int32_t exp_tolerance = (((*val_tolerance)>>23)&255);
      if(exp_tolerance != 0)
        exp_tolerance += 1023-127;
      int32_t sig_tolerance = *val_tolerance;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_tolerance<<5) & 0xff;
      *(outbuffer + offset++) = (sig_tolerance>>3) & 0xff;
      *(outbuffer + offset++) = (sig_tolerance>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_tolerance<<4) & 0xF0) | ((sig_tolerance>>19)&0x0F);
      *(outbuffer + offset++) = (exp_tolerance>>4) & 0x7F;
      if(this->tolerance < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_link_pair_name;
      memcpy(&length_link_pair_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_pair_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_pair_name-1]=0;
      this->link_pair_name = (char *)(inbuffer + offset-1);
      offset += length_link_pair_name;
      uint32_t * val_tolerance = (uint32_t*) &(this->tolerance);
      offset += 3;
      *val_tolerance = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_tolerance |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_tolerance |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_tolerance |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_tolerance = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_tolerance |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_tolerance !=0)
        *val_tolerance |= ((exp_tolerance)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->tolerance = -this->tolerance;
     return offset;
    }

    const char * getType(){ return OPENHRP_COLLISIONDETECTORSERVICE_SETTOLERANCE; };
    const char * getMD5(){ return "454672d6fa714d34c7d2963712d4bbe5"; };

  };

  class OpenHRP_CollisionDetectorService_setToleranceResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_COLLISIONDETECTORSERVICE_SETTOLERANCE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_CollisionDetectorService_setTolerance {
    public:
    typedef OpenHRP_CollisionDetectorService_setToleranceRequest Request;
    typedef OpenHRP_CollisionDetectorService_setToleranceResponse Response;
  };

}
#endif

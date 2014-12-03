#ifndef _ROS_SERVICE_OpenHRP_ForwardKinematicsService_getRelativeCurrentPosition_h
#define _ROS_SERVICE_OpenHRP_ForwardKinematicsService_getRelativeCurrentPosition_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_FORWARDKINEMATICSSERVICE_GETRELATIVECURRENTPOSITION[] = "hrpsys_ros_bridge/OpenHRP_ForwardKinematicsService_getRelativeCurrentPosition";

  class OpenHRP_ForwardKinematicsService_getRelativeCurrentPositionRequest : public ros::Msg
  {
    public:
      char * linknameFrom;
      char * linknameTo;
      float target[3];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_linknameFrom = strlen( (const char*) this->linknameFrom);
      memcpy(outbuffer + offset, &length_linknameFrom, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->linknameFrom, length_linknameFrom);
      offset += length_linknameFrom;
      uint32_t length_linknameTo = strlen( (const char*) this->linknameTo);
      memcpy(outbuffer + offset, &length_linknameTo, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->linknameTo, length_linknameTo);
      offset += length_linknameTo;
      unsigned char * target_val = (unsigned char *) this->target;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_targeti = (int32_t *) &(this->target[i]);
      int32_t exp_targeti = (((*val_targeti)>>23)&255);
      if(exp_targeti != 0)
        exp_targeti += 1023-127;
      int32_t sig_targeti = *val_targeti;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_targeti<<5) & 0xff;
      *(outbuffer + offset++) = (sig_targeti>>3) & 0xff;
      *(outbuffer + offset++) = (sig_targeti>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_targeti<<4) & 0xF0) | ((sig_targeti>>19)&0x0F);
      *(outbuffer + offset++) = (exp_targeti>>4) & 0x7F;
      if(this->target[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_linknameFrom;
      memcpy(&length_linknameFrom, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_linknameFrom; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_linknameFrom-1]=0;
      this->linknameFrom = (char *)(inbuffer + offset-1);
      offset += length_linknameFrom;
      uint32_t length_linknameTo;
      memcpy(&length_linknameTo, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_linknameTo; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_linknameTo-1]=0;
      this->linknameTo = (char *)(inbuffer + offset-1);
      offset += length_linknameTo;
      uint8_t * target_val = (uint8_t*) this->target;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_targeti = (uint32_t*) &(this->target[i]);
      offset += 3;
      *val_targeti = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_targeti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_targeti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_targeti |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_targeti = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_targeti |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_targeti !=0)
        *val_targeti |= ((exp_targeti)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->target[i] = -this->target[i];
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_FORWARDKINEMATICSSERVICE_GETRELATIVECURRENTPOSITION; };
    const char * getMD5(){ return "71ffb77f9db3e6c43c01ee2e02a001f0"; };

  };

  class OpenHRP_ForwardKinematicsService_getRelativeCurrentPositionResponse : public ros::Msg
  {
    public:
      bool operation_return;
      float result[3];

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
      unsigned char * result_val = (unsigned char *) this->result;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_resulti = (int32_t *) &(this->result[i]);
      int32_t exp_resulti = (((*val_resulti)>>23)&255);
      if(exp_resulti != 0)
        exp_resulti += 1023-127;
      int32_t sig_resulti = *val_resulti;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_resulti<<5) & 0xff;
      *(outbuffer + offset++) = (sig_resulti>>3) & 0xff;
      *(outbuffer + offset++) = (sig_resulti>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_resulti<<4) & 0xF0) | ((sig_resulti>>19)&0x0F);
      *(outbuffer + offset++) = (exp_resulti>>4) & 0x7F;
      if(this->result[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
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
      uint8_t * result_val = (uint8_t*) this->result;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_resulti = (uint32_t*) &(this->result[i]);
      offset += 3;
      *val_resulti = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_resulti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_resulti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_resulti |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_resulti = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_resulti |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_resulti !=0)
        *val_resulti |= ((exp_resulti)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->result[i] = -this->result[i];
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_FORWARDKINEMATICSSERVICE_GETRELATIVECURRENTPOSITION; };
    const char * getMD5(){ return "8c1d08e4e27c952291446d526b735f1d"; };

  };

  class OpenHRP_ForwardKinematicsService_getRelativeCurrentPosition {
    public:
    typedef OpenHRP_ForwardKinematicsService_getRelativeCurrentPositionRequest Request;
    typedef OpenHRP_ForwardKinematicsService_getRelativeCurrentPositionResponse Response;
  };

}
#endif

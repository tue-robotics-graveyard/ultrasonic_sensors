#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setWrenches_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setWrenches_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETWRENCHES[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setWrenches";

  class OpenHRP_SequencePlayerService_setWrenchesRequest : public ros::Msg
  {
    public:
      uint8_t wrenches_length;
      float st_wrenches;
      float * wrenches;
      float tm;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = wrenches_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < wrenches_length; i++){
      int32_t * val_wrenchesi = (int32_t *) &(this->wrenches[i]);
      int32_t exp_wrenchesi = (((*val_wrenchesi)>>23)&255);
      if(exp_wrenchesi != 0)
        exp_wrenchesi += 1023-127;
      int32_t sig_wrenchesi = *val_wrenchesi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_wrenchesi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_wrenchesi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_wrenchesi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_wrenchesi<<4) & 0xF0) | ((sig_wrenchesi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_wrenchesi>>4) & 0x7F;
      if(this->wrenches[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      int32_t * val_tm = (int32_t *) &(this->tm);
      int32_t exp_tm = (((*val_tm)>>23)&255);
      if(exp_tm != 0)
        exp_tm += 1023-127;
      int32_t sig_tm = *val_tm;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_tm<<5) & 0xff;
      *(outbuffer + offset++) = (sig_tm>>3) & 0xff;
      *(outbuffer + offset++) = (sig_tm>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_tm<<4) & 0xF0) | ((sig_tm>>19)&0x0F);
      *(outbuffer + offset++) = (exp_tm>>4) & 0x7F;
      if(this->tm < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t wrenches_lengthT = *(inbuffer + offset++);
      if(wrenches_lengthT > wrenches_length)
        this->wrenches = (float*)realloc(this->wrenches, wrenches_lengthT * sizeof(float));
      offset += 3;
      wrenches_length = wrenches_lengthT;
      for( uint8_t i = 0; i < wrenches_length; i++){
      uint32_t * val_st_wrenches = (uint32_t*) &(this->st_wrenches);
      offset += 3;
      *val_st_wrenches = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_wrenches |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_wrenches |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_wrenches |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_wrenches = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_wrenches |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_wrenches !=0)
        *val_st_wrenches |= ((exp_st_wrenches)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_wrenches = -this->st_wrenches;
        memcpy( &(this->wrenches[i]), &(this->st_wrenches), sizeof(float));
      }
      uint32_t * val_tm = (uint32_t*) &(this->tm);
      offset += 3;
      *val_tm = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_tm |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_tm |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_tm |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_tm = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_tm |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_tm !=0)
        *val_tm |= ((exp_tm)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->tm = -this->tm;
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETWRENCHES; };
    const char * getMD5(){ return "8278cb0b6641cad755b5b691fb73ac22"; };

  };

  class OpenHRP_SequencePlayerService_setWrenchesResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETWRENCHES; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setWrenches {
    public:
    typedef OpenHRP_SequencePlayerService_setWrenchesRequest Request;
    typedef OpenHRP_SequencePlayerService_setWrenchesResponse Response;
  };

}
#endif

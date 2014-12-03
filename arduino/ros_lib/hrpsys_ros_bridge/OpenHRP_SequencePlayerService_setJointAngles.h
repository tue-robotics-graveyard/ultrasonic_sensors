#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAngles_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAngles_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLES[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setJointAngles";

  class OpenHRP_SequencePlayerService_setJointAnglesRequest : public ros::Msg
  {
    public:
      uint8_t jvs_length;
      float st_jvs;
      float * jvs;
      float tm;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = jvs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < jvs_length; i++){
      int32_t * val_jvsi = (int32_t *) &(this->jvs[i]);
      int32_t exp_jvsi = (((*val_jvsi)>>23)&255);
      if(exp_jvsi != 0)
        exp_jvsi += 1023-127;
      int32_t sig_jvsi = *val_jvsi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_jvsi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_jvsi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_jvsi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_jvsi<<4) & 0xF0) | ((sig_jvsi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_jvsi>>4) & 0x7F;
      if(this->jvs[i] < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint8_t jvs_lengthT = *(inbuffer + offset++);
      if(jvs_lengthT > jvs_length)
        this->jvs = (float*)realloc(this->jvs, jvs_lengthT * sizeof(float));
      offset += 3;
      jvs_length = jvs_lengthT;
      for( uint8_t i = 0; i < jvs_length; i++){
      uint32_t * val_st_jvs = (uint32_t*) &(this->st_jvs);
      offset += 3;
      *val_st_jvs = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_jvs |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_jvs |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_jvs |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_jvs = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_jvs |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_jvs !=0)
        *val_st_jvs |= ((exp_st_jvs)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_jvs = -this->st_jvs;
        memcpy( &(this->jvs[i]), &(this->st_jvs), sizeof(float));
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLES; };
    const char * getMD5(){ return "5cb366f022500e53b323d89bf91eb900"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLES; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setJointAngles {
    public:
    typedef OpenHRP_SequencePlayerService_setJointAnglesRequest Request;
    typedef OpenHRP_SequencePlayerService_setJointAnglesResponse Response;
  };

}
#endif

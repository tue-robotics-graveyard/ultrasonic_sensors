#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setZmp_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setZmp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETZMP[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setZmp";

  class OpenHRP_SequencePlayerService_setZmpRequest : public ros::Msg
  {
    public:
      uint8_t zmp_length;
      float st_zmp;
      float * zmp;
      float tm;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = zmp_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < zmp_length; i++){
      int32_t * val_zmpi = (int32_t *) &(this->zmp[i]);
      int32_t exp_zmpi = (((*val_zmpi)>>23)&255);
      if(exp_zmpi != 0)
        exp_zmpi += 1023-127;
      int32_t sig_zmpi = *val_zmpi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_zmpi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_zmpi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_zmpi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_zmpi<<4) & 0xF0) | ((sig_zmpi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_zmpi>>4) & 0x7F;
      if(this->zmp[i] < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint8_t zmp_lengthT = *(inbuffer + offset++);
      if(zmp_lengthT > zmp_length)
        this->zmp = (float*)realloc(this->zmp, zmp_lengthT * sizeof(float));
      offset += 3;
      zmp_length = zmp_lengthT;
      for( uint8_t i = 0; i < zmp_length; i++){
      uint32_t * val_st_zmp = (uint32_t*) &(this->st_zmp);
      offset += 3;
      *val_st_zmp = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_zmp |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_zmp |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_zmp |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_zmp = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_zmp |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_zmp !=0)
        *val_st_zmp |= ((exp_st_zmp)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_zmp = -this->st_zmp;
        memcpy( &(this->zmp[i]), &(this->st_zmp), sizeof(float));
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETZMP; };
    const char * getMD5(){ return "ccc8d359d012f5f55e6be510fbec1781"; };

  };

  class OpenHRP_SequencePlayerService_setZmpResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETZMP; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setZmp {
    public:
    typedef OpenHRP_SequencePlayerService_setZmpRequest Request;
    typedef OpenHRP_SequencePlayerService_setZmpResponse Response;
  };

}
#endif

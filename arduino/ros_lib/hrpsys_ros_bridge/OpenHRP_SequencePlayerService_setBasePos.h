#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setBasePos_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setBasePos_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETBASEPOS[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setBasePos";

  class OpenHRP_SequencePlayerService_setBasePosRequest : public ros::Msg
  {
    public:
      uint8_t pos_length;
      float st_pos;
      float * pos;
      float tm;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = pos_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_length; i++){
      int32_t * val_posi = (int32_t *) &(this->pos[i]);
      int32_t exp_posi = (((*val_posi)>>23)&255);
      if(exp_posi != 0)
        exp_posi += 1023-127;
      int32_t sig_posi = *val_posi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_posi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_posi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_posi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_posi<<4) & 0xF0) | ((sig_posi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_posi>>4) & 0x7F;
      if(this->pos[i] < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint8_t pos_lengthT = *(inbuffer + offset++);
      if(pos_lengthT > pos_length)
        this->pos = (float*)realloc(this->pos, pos_lengthT * sizeof(float));
      offset += 3;
      pos_length = pos_lengthT;
      for( uint8_t i = 0; i < pos_length; i++){
      uint32_t * val_st_pos = (uint32_t*) &(this->st_pos);
      offset += 3;
      *val_st_pos = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_pos |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_pos |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_pos |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_pos = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_pos |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_pos !=0)
        *val_st_pos |= ((exp_st_pos)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_pos = -this->st_pos;
        memcpy( &(this->pos[i]), &(this->st_pos), sizeof(float));
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETBASEPOS; };
    const char * getMD5(){ return "4b084539ddcc02779e1dcf3d438cc175"; };

  };

  class OpenHRP_SequencePlayerService_setBasePosResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETBASEPOS; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setBasePos {
    public:
    typedef OpenHRP_SequencePlayerService_setBasePosRequest Request;
    typedef OpenHRP_SequencePlayerService_setBasePosResponse Response;
  };

}
#endif

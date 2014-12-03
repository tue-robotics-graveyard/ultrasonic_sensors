#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAngle_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAngle_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLE[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setJointAngle";

  class OpenHRP_SequencePlayerService_setJointAngleRequest : public ros::Msg
  {
    public:
      char * jname;
      float jv;
      float tm;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_jname = strlen( (const char*) this->jname);
      memcpy(outbuffer + offset, &length_jname, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->jname, length_jname);
      offset += length_jname;
      int32_t * val_jv = (int32_t *) &(this->jv);
      int32_t exp_jv = (((*val_jv)>>23)&255);
      if(exp_jv != 0)
        exp_jv += 1023-127;
      int32_t sig_jv = *val_jv;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_jv<<5) & 0xff;
      *(outbuffer + offset++) = (sig_jv>>3) & 0xff;
      *(outbuffer + offset++) = (sig_jv>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_jv<<4) & 0xF0) | ((sig_jv>>19)&0x0F);
      *(outbuffer + offset++) = (exp_jv>>4) & 0x7F;
      if(this->jv < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint32_t length_jname;
      memcpy(&length_jname, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_jname; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_jname-1]=0;
      this->jname = (char *)(inbuffer + offset-1);
      offset += length_jname;
      uint32_t * val_jv = (uint32_t*) &(this->jv);
      offset += 3;
      *val_jv = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_jv |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_jv |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_jv |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_jv = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_jv |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_jv !=0)
        *val_jv |= ((exp_jv)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->jv = -this->jv;
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLE; };
    const char * getMD5(){ return "0622d9ab6c3a08f749b8789bfad106e3"; };

  };

  class OpenHRP_SequencePlayerService_setJointAngleResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setJointAngle {
    public:
    typedef OpenHRP_SequencePlayerService_setJointAngleRequest Request;
    typedef OpenHRP_SequencePlayerService_setJointAngleResponse Response;
  };

}
#endif

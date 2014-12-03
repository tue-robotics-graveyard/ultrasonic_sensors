#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_playPattern_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_playPattern_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_PLAYPATTERN[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_playPattern";

  class OpenHRP_SequencePlayerService_playPatternRequest : public ros::Msg
  {
    public:
      std_msgs::Float64MultiArray pos;
      std_msgs::Float64MultiArray rpy;
      std_msgs::Float64MultiArray zmp;
      uint8_t tm_length;
      float st_tm;
      float * tm;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pos.serialize(outbuffer + offset);
      offset += this->rpy.serialize(outbuffer + offset);
      offset += this->zmp.serialize(outbuffer + offset);
      *(outbuffer + offset++) = tm_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tm_length; i++){
      int32_t * val_tmi = (int32_t *) &(this->tm[i]);
      int32_t exp_tmi = (((*val_tmi)>>23)&255);
      if(exp_tmi != 0)
        exp_tmi += 1023-127;
      int32_t sig_tmi = *val_tmi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_tmi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_tmi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_tmi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_tmi<<4) & 0xF0) | ((sig_tmi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_tmi>>4) & 0x7F;
      if(this->tm[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pos.deserialize(inbuffer + offset);
      offset += this->rpy.deserialize(inbuffer + offset);
      offset += this->zmp.deserialize(inbuffer + offset);
      uint8_t tm_lengthT = *(inbuffer + offset++);
      if(tm_lengthT > tm_length)
        this->tm = (float*)realloc(this->tm, tm_lengthT * sizeof(float));
      offset += 3;
      tm_length = tm_lengthT;
      for( uint8_t i = 0; i < tm_length; i++){
      uint32_t * val_st_tm = (uint32_t*) &(this->st_tm);
      offset += 3;
      *val_st_tm = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_tm |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_tm |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_tm |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_tm = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_tm |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_tm !=0)
        *val_st_tm |= ((exp_st_tm)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_tm = -this->st_tm;
        memcpy( &(this->tm[i]), &(this->st_tm), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_PLAYPATTERN; };
    const char * getMD5(){ return "337f00a6e3b068d4dfdc1cc7b8dd965c"; };

  };

  class OpenHRP_SequencePlayerService_playPatternResponse : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_PLAYPATTERN; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_playPattern {
    public:
    typedef OpenHRP_SequencePlayerService_playPatternRequest Request;
    typedef OpenHRP_SequencePlayerService_playPatternResponse Response;
  };

}
#endif

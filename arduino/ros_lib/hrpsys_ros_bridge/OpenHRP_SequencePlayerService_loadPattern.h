#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_loadPattern_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_loadPattern_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_LOADPATTERN[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_loadPattern";

  class OpenHRP_SequencePlayerService_loadPatternRequest : public ros::Msg
  {
    public:
      char * basename;
      float tm;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_basename = strlen( (const char*) this->basename);
      memcpy(outbuffer + offset, &length_basename, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->basename, length_basename);
      offset += length_basename;
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
      uint32_t length_basename;
      memcpy(&length_basename, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_basename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_basename-1]=0;
      this->basename = (char *)(inbuffer + offset-1);
      offset += length_basename;
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_LOADPATTERN; };
    const char * getMD5(){ return "5b6071c1a3707612b9adf6c3e53d310c"; };

  };

  class OpenHRP_SequencePlayerService_loadPatternResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_LOADPATTERN; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_loadPattern {
    public:
    typedef OpenHRP_SequencePlayerService_loadPatternRequest Request;
    typedef OpenHRP_SequencePlayerService_loadPatternResponse Response;
  };

}
#endif

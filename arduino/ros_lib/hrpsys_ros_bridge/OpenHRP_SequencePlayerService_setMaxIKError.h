#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setMaxIKError_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setMaxIKError_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETMAXIKERROR[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setMaxIKError";

  class OpenHRP_SequencePlayerService_setMaxIKErrorRequest : public ros::Msg
  {
    public:
      float pos;
      float rot;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_pos = (int32_t *) &(this->pos);
      int32_t exp_pos = (((*val_pos)>>23)&255);
      if(exp_pos != 0)
        exp_pos += 1023-127;
      int32_t sig_pos = *val_pos;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_pos<<5) & 0xff;
      *(outbuffer + offset++) = (sig_pos>>3) & 0xff;
      *(outbuffer + offset++) = (sig_pos>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_pos<<4) & 0xF0) | ((sig_pos>>19)&0x0F);
      *(outbuffer + offset++) = (exp_pos>>4) & 0x7F;
      if(this->pos < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_rot = (int32_t *) &(this->rot);
      int32_t exp_rot = (((*val_rot)>>23)&255);
      if(exp_rot != 0)
        exp_rot += 1023-127;
      int32_t sig_rot = *val_rot;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_rot<<5) & 0xff;
      *(outbuffer + offset++) = (sig_rot>>3) & 0xff;
      *(outbuffer + offset++) = (sig_rot>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_rot<<4) & 0xF0) | ((sig_rot>>19)&0x0F);
      *(outbuffer + offset++) = (exp_rot>>4) & 0x7F;
      if(this->rot < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_pos = (uint32_t*) &(this->pos);
      offset += 3;
      *val_pos = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_pos |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_pos |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_pos |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_pos = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_pos |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_pos !=0)
        *val_pos |= ((exp_pos)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->pos = -this->pos;
      uint32_t * val_rot = (uint32_t*) &(this->rot);
      offset += 3;
      *val_rot = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_rot |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_rot |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_rot |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_rot = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_rot |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_rot !=0)
        *val_rot |= ((exp_rot)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->rot = -this->rot;
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETMAXIKERROR; };
    const char * getMD5(){ return "3c6bfe875826b548627fa31630e69ef4"; };

  };

  class OpenHRP_SequencePlayerService_setMaxIKErrorResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETMAXIKERROR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_setMaxIKError {
    public:
    typedef OpenHRP_SequencePlayerService_setMaxIKErrorRequest Request;
    typedef OpenHRP_SequencePlayerService_setMaxIKErrorResponse Response;
  };

}
#endif

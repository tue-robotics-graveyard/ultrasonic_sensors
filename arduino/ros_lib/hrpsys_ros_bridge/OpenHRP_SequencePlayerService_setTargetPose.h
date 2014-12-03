#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setTargetPose_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setTargetPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETTARGETPOSE[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setTargetPose";

  class OpenHRP_SequencePlayerService_setTargetPoseRequest : public ros::Msg
  {
    public:
      char * name;
      uint8_t xyz_length;
      float st_xyz;
      float * xyz;
      uint8_t rpy_length;
      float st_rpy;
      float * rpy;
      float tm;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset++) = xyz_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < xyz_length; i++){
      int32_t * val_xyzi = (int32_t *) &(this->xyz[i]);
      int32_t exp_xyzi = (((*val_xyzi)>>23)&255);
      if(exp_xyzi != 0)
        exp_xyzi += 1023-127;
      int32_t sig_xyzi = *val_xyzi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_xyzi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_xyzi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_xyzi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_xyzi<<4) & 0xF0) | ((sig_xyzi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_xyzi>>4) & 0x7F;
      if(this->xyz[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = rpy_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < rpy_length; i++){
      int32_t * val_rpyi = (int32_t *) &(this->rpy[i]);
      int32_t exp_rpyi = (((*val_rpyi)>>23)&255);
      if(exp_rpyi != 0)
        exp_rpyi += 1023-127;
      int32_t sig_rpyi = *val_rpyi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_rpyi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_rpyi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_rpyi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_rpyi<<4) & 0xF0) | ((sig_rpyi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_rpyi>>4) & 0x7F;
      if(this->rpy[i] < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint8_t xyz_lengthT = *(inbuffer + offset++);
      if(xyz_lengthT > xyz_length)
        this->xyz = (float*)realloc(this->xyz, xyz_lengthT * sizeof(float));
      offset += 3;
      xyz_length = xyz_lengthT;
      for( uint8_t i = 0; i < xyz_length; i++){
      uint32_t * val_st_xyz = (uint32_t*) &(this->st_xyz);
      offset += 3;
      *val_st_xyz = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_xyz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_xyz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_xyz |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_xyz = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_xyz |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_xyz !=0)
        *val_st_xyz |= ((exp_st_xyz)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_xyz = -this->st_xyz;
        memcpy( &(this->xyz[i]), &(this->st_xyz), sizeof(float));
      }
      uint8_t rpy_lengthT = *(inbuffer + offset++);
      if(rpy_lengthT > rpy_length)
        this->rpy = (float*)realloc(this->rpy, rpy_lengthT * sizeof(float));
      offset += 3;
      rpy_length = rpy_lengthT;
      for( uint8_t i = 0; i < rpy_length; i++){
      uint32_t * val_st_rpy = (uint32_t*) &(this->st_rpy);
      offset += 3;
      *val_st_rpy = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_rpy |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_rpy |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_rpy |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_rpy = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_rpy |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_rpy !=0)
        *val_st_rpy |= ((exp_st_rpy)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_rpy = -this->st_rpy;
        memcpy( &(this->rpy[i]), &(this->st_rpy), sizeof(float));
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETTARGETPOSE; };
    const char * getMD5(){ return "fbd6f07e5a5bde9514a1389b662bf2e1"; };

  };

  class OpenHRP_SequencePlayerService_setTargetPoseResponse : public ros::Msg
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETTARGETPOSE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setTargetPose {
    public:
    typedef OpenHRP_SequencePlayerService_setTargetPoseRequest Request;
    typedef OpenHRP_SequencePlayerService_setTargetPoseResponse Response;
  };

}
#endif

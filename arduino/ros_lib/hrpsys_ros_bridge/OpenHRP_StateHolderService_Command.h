#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StateHolderService_Command_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StateHolderService_Command_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StateHolderService_Command : public ros::Msg
  {
    public:
      uint8_t jointRefs_length;
      float st_jointRefs;
      float * jointRefs;
      uint8_t baseTransform_length;
      float st_baseTransform;
      float * baseTransform;
      uint8_t zmp_length;
      float st_zmp;
      float * zmp;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = jointRefs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < jointRefs_length; i++){
      int32_t * val_jointRefsi = (int32_t *) &(this->jointRefs[i]);
      int32_t exp_jointRefsi = (((*val_jointRefsi)>>23)&255);
      if(exp_jointRefsi != 0)
        exp_jointRefsi += 1023-127;
      int32_t sig_jointRefsi = *val_jointRefsi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_jointRefsi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_jointRefsi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_jointRefsi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_jointRefsi<<4) & 0xF0) | ((sig_jointRefsi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_jointRefsi>>4) & 0x7F;
      if(this->jointRefs[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = baseTransform_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < baseTransform_length; i++){
      int32_t * val_baseTransformi = (int32_t *) &(this->baseTransform[i]);
      int32_t exp_baseTransformi = (((*val_baseTransformi)>>23)&255);
      if(exp_baseTransformi != 0)
        exp_baseTransformi += 1023-127;
      int32_t sig_baseTransformi = *val_baseTransformi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_baseTransformi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_baseTransformi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_baseTransformi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_baseTransformi<<4) & 0xF0) | ((sig_baseTransformi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_baseTransformi>>4) & 0x7F;
      if(this->baseTransform[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t jointRefs_lengthT = *(inbuffer + offset++);
      if(jointRefs_lengthT > jointRefs_length)
        this->jointRefs = (float*)realloc(this->jointRefs, jointRefs_lengthT * sizeof(float));
      offset += 3;
      jointRefs_length = jointRefs_lengthT;
      for( uint8_t i = 0; i < jointRefs_length; i++){
      uint32_t * val_st_jointRefs = (uint32_t*) &(this->st_jointRefs);
      offset += 3;
      *val_st_jointRefs = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_jointRefs |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_jointRefs |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_jointRefs |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_jointRefs = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_jointRefs |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_jointRefs !=0)
        *val_st_jointRefs |= ((exp_st_jointRefs)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_jointRefs = -this->st_jointRefs;
        memcpy( &(this->jointRefs[i]), &(this->st_jointRefs), sizeof(float));
      }
      uint8_t baseTransform_lengthT = *(inbuffer + offset++);
      if(baseTransform_lengthT > baseTransform_length)
        this->baseTransform = (float*)realloc(this->baseTransform, baseTransform_lengthT * sizeof(float));
      offset += 3;
      baseTransform_length = baseTransform_lengthT;
      for( uint8_t i = 0; i < baseTransform_length; i++){
      uint32_t * val_st_baseTransform = (uint32_t*) &(this->st_baseTransform);
      offset += 3;
      *val_st_baseTransform = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_baseTransform |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_baseTransform |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_baseTransform |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_baseTransform = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_baseTransform |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_baseTransform !=0)
        *val_st_baseTransform |= ((exp_st_baseTransform)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_baseTransform = -this->st_baseTransform;
        memcpy( &(this->baseTransform[i]), &(this->st_baseTransform), sizeof(float));
      }
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
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StateHolderService_Command"; };
    const char * getMD5(){ return "c456a517c9c8704b756ab8fb10b08d6d"; };

  };

}
#endif
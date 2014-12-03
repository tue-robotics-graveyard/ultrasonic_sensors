#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_RemoveForceSensorLinkOffsetService_forcemomentOffsetParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_RemoveForceSensorLinkOffsetService_forcemomentOffsetParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_RemoveForceSensorLinkOffsetService_forcemomentOffsetParam : public ros::Msg
  {
    public:
      float force_offset[3];
      float moment_offset[3];
      float link_offset_centroid[3];
      float link_offset_mass;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned char * force_offset_val = (unsigned char *) this->force_offset;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_force_offseti = (int32_t *) &(this->force_offset[i]);
      int32_t exp_force_offseti = (((*val_force_offseti)>>23)&255);
      if(exp_force_offseti != 0)
        exp_force_offseti += 1023-127;
      int32_t sig_force_offseti = *val_force_offseti;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_force_offseti<<5) & 0xff;
      *(outbuffer + offset++) = (sig_force_offseti>>3) & 0xff;
      *(outbuffer + offset++) = (sig_force_offseti>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_force_offseti<<4) & 0xF0) | ((sig_force_offseti>>19)&0x0F);
      *(outbuffer + offset++) = (exp_force_offseti>>4) & 0x7F;
      if(this->force_offset[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * moment_offset_val = (unsigned char *) this->moment_offset;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_moment_offseti = (int32_t *) &(this->moment_offset[i]);
      int32_t exp_moment_offseti = (((*val_moment_offseti)>>23)&255);
      if(exp_moment_offseti != 0)
        exp_moment_offseti += 1023-127;
      int32_t sig_moment_offseti = *val_moment_offseti;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_moment_offseti<<5) & 0xff;
      *(outbuffer + offset++) = (sig_moment_offseti>>3) & 0xff;
      *(outbuffer + offset++) = (sig_moment_offseti>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_moment_offseti<<4) & 0xF0) | ((sig_moment_offseti>>19)&0x0F);
      *(outbuffer + offset++) = (exp_moment_offseti>>4) & 0x7F;
      if(this->moment_offset[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * link_offset_centroid_val = (unsigned char *) this->link_offset_centroid;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_link_offset_centroidi = (int32_t *) &(this->link_offset_centroid[i]);
      int32_t exp_link_offset_centroidi = (((*val_link_offset_centroidi)>>23)&255);
      if(exp_link_offset_centroidi != 0)
        exp_link_offset_centroidi += 1023-127;
      int32_t sig_link_offset_centroidi = *val_link_offset_centroidi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_link_offset_centroidi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_link_offset_centroidi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_link_offset_centroidi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_link_offset_centroidi<<4) & 0xF0) | ((sig_link_offset_centroidi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_link_offset_centroidi>>4) & 0x7F;
      if(this->link_offset_centroid[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      int32_t * val_link_offset_mass = (int32_t *) &(this->link_offset_mass);
      int32_t exp_link_offset_mass = (((*val_link_offset_mass)>>23)&255);
      if(exp_link_offset_mass != 0)
        exp_link_offset_mass += 1023-127;
      int32_t sig_link_offset_mass = *val_link_offset_mass;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_link_offset_mass<<5) & 0xff;
      *(outbuffer + offset++) = (sig_link_offset_mass>>3) & 0xff;
      *(outbuffer + offset++) = (sig_link_offset_mass>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_link_offset_mass<<4) & 0xF0) | ((sig_link_offset_mass>>19)&0x0F);
      *(outbuffer + offset++) = (exp_link_offset_mass>>4) & 0x7F;
      if(this->link_offset_mass < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t * force_offset_val = (uint8_t*) this->force_offset;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_force_offseti = (uint32_t*) &(this->force_offset[i]);
      offset += 3;
      *val_force_offseti = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_force_offseti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_force_offseti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_force_offseti |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_force_offseti = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_force_offseti |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_force_offseti !=0)
        *val_force_offseti |= ((exp_force_offseti)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->force_offset[i] = -this->force_offset[i];
      }
      uint8_t * moment_offset_val = (uint8_t*) this->moment_offset;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_moment_offseti = (uint32_t*) &(this->moment_offset[i]);
      offset += 3;
      *val_moment_offseti = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_moment_offseti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_moment_offseti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_moment_offseti |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_moment_offseti = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_moment_offseti |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_moment_offseti !=0)
        *val_moment_offseti |= ((exp_moment_offseti)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->moment_offset[i] = -this->moment_offset[i];
      }
      uint8_t * link_offset_centroid_val = (uint8_t*) this->link_offset_centroid;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_link_offset_centroidi = (uint32_t*) &(this->link_offset_centroid[i]);
      offset += 3;
      *val_link_offset_centroidi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_link_offset_centroidi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_link_offset_centroidi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_link_offset_centroidi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_link_offset_centroidi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_link_offset_centroidi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_link_offset_centroidi !=0)
        *val_link_offset_centroidi |= ((exp_link_offset_centroidi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->link_offset_centroid[i] = -this->link_offset_centroid[i];
      }
      uint32_t * val_link_offset_mass = (uint32_t*) &(this->link_offset_mass);
      offset += 3;
      *val_link_offset_mass = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_link_offset_mass |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_link_offset_mass |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_link_offset_mass |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_link_offset_mass = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_link_offset_mass |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_link_offset_mass !=0)
        *val_link_offset_mass |= ((exp_link_offset_mass)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->link_offset_mass = -this->link_offset_mass;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_RemoveForceSensorLinkOffsetService_forcemomentOffsetParam"; };
    const char * getMD5(){ return "65a8bdda0c275a081765814539fb2401"; };

  };

}
#endif
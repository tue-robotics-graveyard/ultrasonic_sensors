#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_impedanceParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_impedanceParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ImpedanceControllerService_impedanceParam : public ros::Msg
  {
    public:
      char * name;
      char * base_name;
      char * target_name;
      float M_p;
      float D_p;
      float K_p;
      float M_r;
      float D_r;
      float K_r;
      float ref_force[3];
      float force_gain[3];
      float ref_moment[3];
      float moment_gain[3];
      float sr_gain;
      float avoid_gain;
      float reference_gain;
      float manipulability_limit;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_base_name = strlen( (const char*) this->base_name);
      memcpy(outbuffer + offset, &length_base_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->base_name, length_base_name);
      offset += length_base_name;
      uint32_t length_target_name = strlen( (const char*) this->target_name);
      memcpy(outbuffer + offset, &length_target_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->target_name, length_target_name);
      offset += length_target_name;
      int32_t * val_M_p = (int32_t *) &(this->M_p);
      int32_t exp_M_p = (((*val_M_p)>>23)&255);
      if(exp_M_p != 0)
        exp_M_p += 1023-127;
      int32_t sig_M_p = *val_M_p;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_M_p<<5) & 0xff;
      *(outbuffer + offset++) = (sig_M_p>>3) & 0xff;
      *(outbuffer + offset++) = (sig_M_p>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_M_p<<4) & 0xF0) | ((sig_M_p>>19)&0x0F);
      *(outbuffer + offset++) = (exp_M_p>>4) & 0x7F;
      if(this->M_p < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_D_p = (int32_t *) &(this->D_p);
      int32_t exp_D_p = (((*val_D_p)>>23)&255);
      if(exp_D_p != 0)
        exp_D_p += 1023-127;
      int32_t sig_D_p = *val_D_p;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_D_p<<5) & 0xff;
      *(outbuffer + offset++) = (sig_D_p>>3) & 0xff;
      *(outbuffer + offset++) = (sig_D_p>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_D_p<<4) & 0xF0) | ((sig_D_p>>19)&0x0F);
      *(outbuffer + offset++) = (exp_D_p>>4) & 0x7F;
      if(this->D_p < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_K_p = (int32_t *) &(this->K_p);
      int32_t exp_K_p = (((*val_K_p)>>23)&255);
      if(exp_K_p != 0)
        exp_K_p += 1023-127;
      int32_t sig_K_p = *val_K_p;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_K_p<<5) & 0xff;
      *(outbuffer + offset++) = (sig_K_p>>3) & 0xff;
      *(outbuffer + offset++) = (sig_K_p>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_K_p<<4) & 0xF0) | ((sig_K_p>>19)&0x0F);
      *(outbuffer + offset++) = (exp_K_p>>4) & 0x7F;
      if(this->K_p < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_M_r = (int32_t *) &(this->M_r);
      int32_t exp_M_r = (((*val_M_r)>>23)&255);
      if(exp_M_r != 0)
        exp_M_r += 1023-127;
      int32_t sig_M_r = *val_M_r;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_M_r<<5) & 0xff;
      *(outbuffer + offset++) = (sig_M_r>>3) & 0xff;
      *(outbuffer + offset++) = (sig_M_r>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_M_r<<4) & 0xF0) | ((sig_M_r>>19)&0x0F);
      *(outbuffer + offset++) = (exp_M_r>>4) & 0x7F;
      if(this->M_r < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_D_r = (int32_t *) &(this->D_r);
      int32_t exp_D_r = (((*val_D_r)>>23)&255);
      if(exp_D_r != 0)
        exp_D_r += 1023-127;
      int32_t sig_D_r = *val_D_r;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_D_r<<5) & 0xff;
      *(outbuffer + offset++) = (sig_D_r>>3) & 0xff;
      *(outbuffer + offset++) = (sig_D_r>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_D_r<<4) & 0xF0) | ((sig_D_r>>19)&0x0F);
      *(outbuffer + offset++) = (exp_D_r>>4) & 0x7F;
      if(this->D_r < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_K_r = (int32_t *) &(this->K_r);
      int32_t exp_K_r = (((*val_K_r)>>23)&255);
      if(exp_K_r != 0)
        exp_K_r += 1023-127;
      int32_t sig_K_r = *val_K_r;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_K_r<<5) & 0xff;
      *(outbuffer + offset++) = (sig_K_r>>3) & 0xff;
      *(outbuffer + offset++) = (sig_K_r>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_K_r<<4) & 0xF0) | ((sig_K_r>>19)&0x0F);
      *(outbuffer + offset++) = (exp_K_r>>4) & 0x7F;
      if(this->K_r < 0) *(outbuffer + offset -1) |= 0x80;
      unsigned char * ref_force_val = (unsigned char *) this->ref_force;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_ref_forcei = (int32_t *) &(this->ref_force[i]);
      int32_t exp_ref_forcei = (((*val_ref_forcei)>>23)&255);
      if(exp_ref_forcei != 0)
        exp_ref_forcei += 1023-127;
      int32_t sig_ref_forcei = *val_ref_forcei;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_ref_forcei<<5) & 0xff;
      *(outbuffer + offset++) = (sig_ref_forcei>>3) & 0xff;
      *(outbuffer + offset++) = (sig_ref_forcei>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_ref_forcei<<4) & 0xF0) | ((sig_ref_forcei>>19)&0x0F);
      *(outbuffer + offset++) = (exp_ref_forcei>>4) & 0x7F;
      if(this->ref_force[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * force_gain_val = (unsigned char *) this->force_gain;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_force_gaini = (int32_t *) &(this->force_gain[i]);
      int32_t exp_force_gaini = (((*val_force_gaini)>>23)&255);
      if(exp_force_gaini != 0)
        exp_force_gaini += 1023-127;
      int32_t sig_force_gaini = *val_force_gaini;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_force_gaini<<5) & 0xff;
      *(outbuffer + offset++) = (sig_force_gaini>>3) & 0xff;
      *(outbuffer + offset++) = (sig_force_gaini>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_force_gaini<<4) & 0xF0) | ((sig_force_gaini>>19)&0x0F);
      *(outbuffer + offset++) = (exp_force_gaini>>4) & 0x7F;
      if(this->force_gain[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * ref_moment_val = (unsigned char *) this->ref_moment;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_ref_momenti = (int32_t *) &(this->ref_moment[i]);
      int32_t exp_ref_momenti = (((*val_ref_momenti)>>23)&255);
      if(exp_ref_momenti != 0)
        exp_ref_momenti += 1023-127;
      int32_t sig_ref_momenti = *val_ref_momenti;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_ref_momenti<<5) & 0xff;
      *(outbuffer + offset++) = (sig_ref_momenti>>3) & 0xff;
      *(outbuffer + offset++) = (sig_ref_momenti>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_ref_momenti<<4) & 0xF0) | ((sig_ref_momenti>>19)&0x0F);
      *(outbuffer + offset++) = (exp_ref_momenti>>4) & 0x7F;
      if(this->ref_moment[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * moment_gain_val = (unsigned char *) this->moment_gain;
      for( uint8_t i = 0; i < 3; i++){
      int32_t * val_moment_gaini = (int32_t *) &(this->moment_gain[i]);
      int32_t exp_moment_gaini = (((*val_moment_gaini)>>23)&255);
      if(exp_moment_gaini != 0)
        exp_moment_gaini += 1023-127;
      int32_t sig_moment_gaini = *val_moment_gaini;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_moment_gaini<<5) & 0xff;
      *(outbuffer + offset++) = (sig_moment_gaini>>3) & 0xff;
      *(outbuffer + offset++) = (sig_moment_gaini>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_moment_gaini<<4) & 0xF0) | ((sig_moment_gaini>>19)&0x0F);
      *(outbuffer + offset++) = (exp_moment_gaini>>4) & 0x7F;
      if(this->moment_gain[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      int32_t * val_sr_gain = (int32_t *) &(this->sr_gain);
      int32_t exp_sr_gain = (((*val_sr_gain)>>23)&255);
      if(exp_sr_gain != 0)
        exp_sr_gain += 1023-127;
      int32_t sig_sr_gain = *val_sr_gain;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_sr_gain<<5) & 0xff;
      *(outbuffer + offset++) = (sig_sr_gain>>3) & 0xff;
      *(outbuffer + offset++) = (sig_sr_gain>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_sr_gain<<4) & 0xF0) | ((sig_sr_gain>>19)&0x0F);
      *(outbuffer + offset++) = (exp_sr_gain>>4) & 0x7F;
      if(this->sr_gain < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_avoid_gain = (int32_t *) &(this->avoid_gain);
      int32_t exp_avoid_gain = (((*val_avoid_gain)>>23)&255);
      if(exp_avoid_gain != 0)
        exp_avoid_gain += 1023-127;
      int32_t sig_avoid_gain = *val_avoid_gain;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_avoid_gain<<5) & 0xff;
      *(outbuffer + offset++) = (sig_avoid_gain>>3) & 0xff;
      *(outbuffer + offset++) = (sig_avoid_gain>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_avoid_gain<<4) & 0xF0) | ((sig_avoid_gain>>19)&0x0F);
      *(outbuffer + offset++) = (exp_avoid_gain>>4) & 0x7F;
      if(this->avoid_gain < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_reference_gain = (int32_t *) &(this->reference_gain);
      int32_t exp_reference_gain = (((*val_reference_gain)>>23)&255);
      if(exp_reference_gain != 0)
        exp_reference_gain += 1023-127;
      int32_t sig_reference_gain = *val_reference_gain;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_reference_gain<<5) & 0xff;
      *(outbuffer + offset++) = (sig_reference_gain>>3) & 0xff;
      *(outbuffer + offset++) = (sig_reference_gain>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_reference_gain<<4) & 0xF0) | ((sig_reference_gain>>19)&0x0F);
      *(outbuffer + offset++) = (exp_reference_gain>>4) & 0x7F;
      if(this->reference_gain < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_manipulability_limit = (int32_t *) &(this->manipulability_limit);
      int32_t exp_manipulability_limit = (((*val_manipulability_limit)>>23)&255);
      if(exp_manipulability_limit != 0)
        exp_manipulability_limit += 1023-127;
      int32_t sig_manipulability_limit = *val_manipulability_limit;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_manipulability_limit<<5) & 0xff;
      *(outbuffer + offset++) = (sig_manipulability_limit>>3) & 0xff;
      *(outbuffer + offset++) = (sig_manipulability_limit>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_manipulability_limit<<4) & 0xF0) | ((sig_manipulability_limit>>19)&0x0F);
      *(outbuffer + offset++) = (exp_manipulability_limit>>4) & 0x7F;
      if(this->manipulability_limit < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint32_t length_base_name;
      memcpy(&length_base_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_base_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_base_name-1]=0;
      this->base_name = (char *)(inbuffer + offset-1);
      offset += length_base_name;
      uint32_t length_target_name;
      memcpy(&length_target_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_name-1]=0;
      this->target_name = (char *)(inbuffer + offset-1);
      offset += length_target_name;
      uint32_t * val_M_p = (uint32_t*) &(this->M_p);
      offset += 3;
      *val_M_p = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_M_p |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_M_p |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_M_p |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_M_p = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_M_p |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_M_p !=0)
        *val_M_p |= ((exp_M_p)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->M_p = -this->M_p;
      uint32_t * val_D_p = (uint32_t*) &(this->D_p);
      offset += 3;
      *val_D_p = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_D_p |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_D_p |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_D_p |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_D_p = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_D_p |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_D_p !=0)
        *val_D_p |= ((exp_D_p)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->D_p = -this->D_p;
      uint32_t * val_K_p = (uint32_t*) &(this->K_p);
      offset += 3;
      *val_K_p = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_K_p |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_K_p |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_K_p |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_K_p = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_K_p |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_K_p !=0)
        *val_K_p |= ((exp_K_p)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->K_p = -this->K_p;
      uint32_t * val_M_r = (uint32_t*) &(this->M_r);
      offset += 3;
      *val_M_r = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_M_r |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_M_r |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_M_r |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_M_r = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_M_r |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_M_r !=0)
        *val_M_r |= ((exp_M_r)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->M_r = -this->M_r;
      uint32_t * val_D_r = (uint32_t*) &(this->D_r);
      offset += 3;
      *val_D_r = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_D_r |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_D_r |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_D_r |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_D_r = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_D_r |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_D_r !=0)
        *val_D_r |= ((exp_D_r)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->D_r = -this->D_r;
      uint32_t * val_K_r = (uint32_t*) &(this->K_r);
      offset += 3;
      *val_K_r = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_K_r |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_K_r |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_K_r |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_K_r = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_K_r |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_K_r !=0)
        *val_K_r |= ((exp_K_r)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->K_r = -this->K_r;
      uint8_t * ref_force_val = (uint8_t*) this->ref_force;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_ref_forcei = (uint32_t*) &(this->ref_force[i]);
      offset += 3;
      *val_ref_forcei = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ref_forcei |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ref_forcei |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ref_forcei |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ref_forcei = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ref_forcei |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ref_forcei !=0)
        *val_ref_forcei |= ((exp_ref_forcei)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->ref_force[i] = -this->ref_force[i];
      }
      uint8_t * force_gain_val = (uint8_t*) this->force_gain;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_force_gaini = (uint32_t*) &(this->force_gain[i]);
      offset += 3;
      *val_force_gaini = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_force_gaini |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_force_gaini |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_force_gaini |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_force_gaini = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_force_gaini |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_force_gaini !=0)
        *val_force_gaini |= ((exp_force_gaini)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->force_gain[i] = -this->force_gain[i];
      }
      uint8_t * ref_moment_val = (uint8_t*) this->ref_moment;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_ref_momenti = (uint32_t*) &(this->ref_moment[i]);
      offset += 3;
      *val_ref_momenti = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ref_momenti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ref_momenti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ref_momenti |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ref_momenti = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ref_momenti |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ref_momenti !=0)
        *val_ref_momenti |= ((exp_ref_momenti)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->ref_moment[i] = -this->ref_moment[i];
      }
      uint8_t * moment_gain_val = (uint8_t*) this->moment_gain;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_moment_gaini = (uint32_t*) &(this->moment_gain[i]);
      offset += 3;
      *val_moment_gaini = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_moment_gaini |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_moment_gaini |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_moment_gaini |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_moment_gaini = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_moment_gaini |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_moment_gaini !=0)
        *val_moment_gaini |= ((exp_moment_gaini)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->moment_gain[i] = -this->moment_gain[i];
      }
      uint32_t * val_sr_gain = (uint32_t*) &(this->sr_gain);
      offset += 3;
      *val_sr_gain = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_sr_gain |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_sr_gain |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_sr_gain |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_sr_gain = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_sr_gain |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_sr_gain !=0)
        *val_sr_gain |= ((exp_sr_gain)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->sr_gain = -this->sr_gain;
      uint32_t * val_avoid_gain = (uint32_t*) &(this->avoid_gain);
      offset += 3;
      *val_avoid_gain = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_avoid_gain |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_avoid_gain |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_avoid_gain |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_avoid_gain = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_avoid_gain |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_avoid_gain !=0)
        *val_avoid_gain |= ((exp_avoid_gain)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->avoid_gain = -this->avoid_gain;
      uint32_t * val_reference_gain = (uint32_t*) &(this->reference_gain);
      offset += 3;
      *val_reference_gain = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_reference_gain |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_reference_gain |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_reference_gain |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_reference_gain = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_reference_gain |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_reference_gain !=0)
        *val_reference_gain |= ((exp_reference_gain)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->reference_gain = -this->reference_gain;
      uint32_t * val_manipulability_limit = (uint32_t*) &(this->manipulability_limit);
      offset += 3;
      *val_manipulability_limit = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_manipulability_limit |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_manipulability_limit |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_manipulability_limit |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_manipulability_limit = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_manipulability_limit |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_manipulability_limit !=0)
        *val_manipulability_limit |= ((exp_manipulability_limit)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->manipulability_limit = -this->manipulability_limit;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_impedanceParam"; };
    const char * getMD5(){ return "7dc56fbf308dcfe16e93246b16e80720"; };

  };

}
#endif
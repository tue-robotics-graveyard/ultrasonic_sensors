#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_TorqueControllerService_torqueControllerParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_TorqueControllerService_torqueControllerParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_TorqueControllerService_torqueControllerParam : public ros::Msg
  {
    public:
      char * name;
      float tc;
      float ke;
      float kd;
      float ki;
      float alpha;
      float beta;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      int32_t * val_tc = (int32_t *) &(this->tc);
      int32_t exp_tc = (((*val_tc)>>23)&255);
      if(exp_tc != 0)
        exp_tc += 1023-127;
      int32_t sig_tc = *val_tc;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_tc<<5) & 0xff;
      *(outbuffer + offset++) = (sig_tc>>3) & 0xff;
      *(outbuffer + offset++) = (sig_tc>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_tc<<4) & 0xF0) | ((sig_tc>>19)&0x0F);
      *(outbuffer + offset++) = (exp_tc>>4) & 0x7F;
      if(this->tc < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_ke = (int32_t *) &(this->ke);
      int32_t exp_ke = (((*val_ke)>>23)&255);
      if(exp_ke != 0)
        exp_ke += 1023-127;
      int32_t sig_ke = *val_ke;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_ke<<5) & 0xff;
      *(outbuffer + offset++) = (sig_ke>>3) & 0xff;
      *(outbuffer + offset++) = (sig_ke>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_ke<<4) & 0xF0) | ((sig_ke>>19)&0x0F);
      *(outbuffer + offset++) = (exp_ke>>4) & 0x7F;
      if(this->ke < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_kd = (int32_t *) &(this->kd);
      int32_t exp_kd = (((*val_kd)>>23)&255);
      if(exp_kd != 0)
        exp_kd += 1023-127;
      int32_t sig_kd = *val_kd;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_kd<<5) & 0xff;
      *(outbuffer + offset++) = (sig_kd>>3) & 0xff;
      *(outbuffer + offset++) = (sig_kd>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_kd<<4) & 0xF0) | ((sig_kd>>19)&0x0F);
      *(outbuffer + offset++) = (exp_kd>>4) & 0x7F;
      if(this->kd < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_ki = (int32_t *) &(this->ki);
      int32_t exp_ki = (((*val_ki)>>23)&255);
      if(exp_ki != 0)
        exp_ki += 1023-127;
      int32_t sig_ki = *val_ki;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_ki<<5) & 0xff;
      *(outbuffer + offset++) = (sig_ki>>3) & 0xff;
      *(outbuffer + offset++) = (sig_ki>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_ki<<4) & 0xF0) | ((sig_ki>>19)&0x0F);
      *(outbuffer + offset++) = (exp_ki>>4) & 0x7F;
      if(this->ki < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_alpha = (int32_t *) &(this->alpha);
      int32_t exp_alpha = (((*val_alpha)>>23)&255);
      if(exp_alpha != 0)
        exp_alpha += 1023-127;
      int32_t sig_alpha = *val_alpha;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_alpha<<5) & 0xff;
      *(outbuffer + offset++) = (sig_alpha>>3) & 0xff;
      *(outbuffer + offset++) = (sig_alpha>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_alpha<<4) & 0xF0) | ((sig_alpha>>19)&0x0F);
      *(outbuffer + offset++) = (exp_alpha>>4) & 0x7F;
      if(this->alpha < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_beta = (int32_t *) &(this->beta);
      int32_t exp_beta = (((*val_beta)>>23)&255);
      if(exp_beta != 0)
        exp_beta += 1023-127;
      int32_t sig_beta = *val_beta;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_beta<<5) & 0xff;
      *(outbuffer + offset++) = (sig_beta>>3) & 0xff;
      *(outbuffer + offset++) = (sig_beta>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_beta<<4) & 0xF0) | ((sig_beta>>19)&0x0F);
      *(outbuffer + offset++) = (exp_beta>>4) & 0x7F;
      if(this->beta < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint32_t * val_tc = (uint32_t*) &(this->tc);
      offset += 3;
      *val_tc = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_tc |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_tc |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_tc |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_tc = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_tc |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_tc !=0)
        *val_tc |= ((exp_tc)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->tc = -this->tc;
      uint32_t * val_ke = (uint32_t*) &(this->ke);
      offset += 3;
      *val_ke = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ke |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ke |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ke |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ke = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ke |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ke !=0)
        *val_ke |= ((exp_ke)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->ke = -this->ke;
      uint32_t * val_kd = (uint32_t*) &(this->kd);
      offset += 3;
      *val_kd = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_kd |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_kd |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_kd |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_kd = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_kd |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_kd !=0)
        *val_kd |= ((exp_kd)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->kd = -this->kd;
      uint32_t * val_ki = (uint32_t*) &(this->ki);
      offset += 3;
      *val_ki = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ki |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ki |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ki |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ki = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ki |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ki !=0)
        *val_ki |= ((exp_ki)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->ki = -this->ki;
      uint32_t * val_alpha = (uint32_t*) &(this->alpha);
      offset += 3;
      *val_alpha = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_alpha |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_alpha |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_alpha |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_alpha = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_alpha |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_alpha !=0)
        *val_alpha |= ((exp_alpha)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->alpha = -this->alpha;
      uint32_t * val_beta = (uint32_t*) &(this->beta);
      offset += 3;
      *val_beta = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_beta |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_beta |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_beta |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_beta = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_beta |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_beta !=0)
        *val_beta |= ((exp_beta)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->beta = -this->beta;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_TorqueControllerService_torqueControllerParam"; };
    const char * getMD5(){ return "c2c93ee8385c97a0f222304c89369c30"; };

  };

}
#endif
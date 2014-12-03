#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_Footstep_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_Footstep_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_Footstep : public ros::Msg
  {
    public:
      float pos[3];
      float rot[4];
      char * leg;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned char * pos_val = (unsigned char *) this->pos;
      for( uint8_t i = 0; i < 3; i++){
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
      unsigned char * rot_val = (unsigned char *) this->rot;
      for( uint8_t i = 0; i < 4; i++){
      int32_t * val_roti = (int32_t *) &(this->rot[i]);
      int32_t exp_roti = (((*val_roti)>>23)&255);
      if(exp_roti != 0)
        exp_roti += 1023-127;
      int32_t sig_roti = *val_roti;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_roti<<5) & 0xff;
      *(outbuffer + offset++) = (sig_roti>>3) & 0xff;
      *(outbuffer + offset++) = (sig_roti>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_roti<<4) & 0xF0) | ((sig_roti>>19)&0x0F);
      *(outbuffer + offset++) = (exp_roti>>4) & 0x7F;
      if(this->rot[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      uint32_t length_leg = strlen( (const char*) this->leg);
      memcpy(outbuffer + offset, &length_leg, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->leg, length_leg);
      offset += length_leg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t * pos_val = (uint8_t*) this->pos;
      for( uint8_t i = 0; i < 3; i++){
      uint32_t * val_posi = (uint32_t*) &(this->pos[i]);
      offset += 3;
      *val_posi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_posi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_posi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_posi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_posi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_posi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_posi !=0)
        *val_posi |= ((exp_posi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->pos[i] = -this->pos[i];
      }
      uint8_t * rot_val = (uint8_t*) this->rot;
      for( uint8_t i = 0; i < 4; i++){
      uint32_t * val_roti = (uint32_t*) &(this->rot[i]);
      offset += 3;
      *val_roti = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_roti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_roti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_roti |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_roti = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_roti |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_roti !=0)
        *val_roti |= ((exp_roti)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->rot[i] = -this->rot[i];
      }
      uint32_t length_leg;
      memcpy(&length_leg, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_leg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_leg-1]=0;
      this->leg = (char *)(inbuffer + offset-1);
      offset += length_leg;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footstep"; };
    const char * getMD5(){ return "f65a0e5bbf029cf10add63f7ae123997"; };

  };

}
#endif
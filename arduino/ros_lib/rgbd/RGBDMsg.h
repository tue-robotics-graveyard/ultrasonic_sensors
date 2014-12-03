#ifndef _ROS_rgbd_RGBDMsg_h
#define _ROS_rgbd_RGBDMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rgbd
{

  class RGBDMsg : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t version;
      uint8_t params_length;
      float st_params;
      float * params;
      uint8_t rgb_length;
      uint8_t st_rgb;
      uint8_t * rgb;
      uint8_t depth_length;
      uint8_t st_depth;
      uint8_t * depth;
      uint8_t cam_info_length;
      float st_cam_info;
      float * cam_info;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->version >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->version >> (8 * 1)) & 0xFF;
      offset += sizeof(this->version);
      *(outbuffer + offset++) = params_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < params_length; i++){
      int32_t * val_paramsi = (int32_t *) &(this->params[i]);
      int32_t exp_paramsi = (((*val_paramsi)>>23)&255);
      if(exp_paramsi != 0)
        exp_paramsi += 1023-127;
      int32_t sig_paramsi = *val_paramsi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_paramsi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_paramsi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_paramsi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_paramsi<<4) & 0xF0) | ((sig_paramsi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_paramsi>>4) & 0x7F;
      if(this->params[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = rgb_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < rgb_length; i++){
      *(outbuffer + offset + 0) = (this->rgb[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rgb[i]);
      }
      *(outbuffer + offset++) = depth_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < depth_length; i++){
      *(outbuffer + offset + 0) = (this->depth[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->depth[i]);
      }
      *(outbuffer + offset++) = cam_info_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < cam_info_length; i++){
      int32_t * val_cam_infoi = (int32_t *) &(this->cam_info[i]);
      int32_t exp_cam_infoi = (((*val_cam_infoi)>>23)&255);
      if(exp_cam_infoi != 0)
        exp_cam_infoi += 1023-127;
      int32_t sig_cam_infoi = *val_cam_infoi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_cam_infoi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_cam_infoi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_cam_infoi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_cam_infoi<<4) & 0xF0) | ((sig_cam_infoi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_cam_infoi>>4) & 0x7F;
      if(this->cam_info[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->version =  ((uint16_t) (*(inbuffer + offset)));
      this->version |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->version);
      uint8_t params_lengthT = *(inbuffer + offset++);
      if(params_lengthT > params_length)
        this->params = (float*)realloc(this->params, params_lengthT * sizeof(float));
      offset += 3;
      params_length = params_lengthT;
      for( uint8_t i = 0; i < params_length; i++){
      uint32_t * val_st_params = (uint32_t*) &(this->st_params);
      offset += 3;
      *val_st_params = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_params |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_params |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_params |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_params = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_params |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_params !=0)
        *val_st_params |= ((exp_st_params)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_params = -this->st_params;
        memcpy( &(this->params[i]), &(this->st_params), sizeof(float));
      }
      uint8_t rgb_lengthT = *(inbuffer + offset++);
      if(rgb_lengthT > rgb_length)
        this->rgb = (uint8_t*)realloc(this->rgb, rgb_lengthT * sizeof(uint8_t));
      offset += 3;
      rgb_length = rgb_lengthT;
      for( uint8_t i = 0; i < rgb_length; i++){
      this->st_rgb =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_rgb);
        memcpy( &(this->rgb[i]), &(this->st_rgb), sizeof(uint8_t));
      }
      uint8_t depth_lengthT = *(inbuffer + offset++);
      if(depth_lengthT > depth_length)
        this->depth = (uint8_t*)realloc(this->depth, depth_lengthT * sizeof(uint8_t));
      offset += 3;
      depth_length = depth_lengthT;
      for( uint8_t i = 0; i < depth_length; i++){
      this->st_depth =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_depth);
        memcpy( &(this->depth[i]), &(this->st_depth), sizeof(uint8_t));
      }
      uint8_t cam_info_lengthT = *(inbuffer + offset++);
      if(cam_info_lengthT > cam_info_length)
        this->cam_info = (float*)realloc(this->cam_info, cam_info_lengthT * sizeof(float));
      offset += 3;
      cam_info_length = cam_info_lengthT;
      for( uint8_t i = 0; i < cam_info_length; i++){
      uint32_t * val_st_cam_info = (uint32_t*) &(this->st_cam_info);
      offset += 3;
      *val_st_cam_info = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_cam_info |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_cam_info |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_cam_info |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_cam_info = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_cam_info |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_cam_info !=0)
        *val_st_cam_info |= ((exp_st_cam_info)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_cam_info = -this->st_cam_info;
        memcpy( &(this->cam_info[i]), &(this->st_cam_info), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "rgbd/RGBDMsg"; };
    const char * getMD5(){ return "40795468bdaf3f221e8e7cf1277b000a"; };

  };

}
#endif
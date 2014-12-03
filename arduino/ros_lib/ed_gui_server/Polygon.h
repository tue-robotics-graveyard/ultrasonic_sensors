#ifndef _ROS_ed_gui_server_Polygon_h
#define _ROS_ed_gui_server_Polygon_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ed_gui_server
{

  class Polygon : public ros::Msg
  {
    public:
      float z_min;
      float z_max;
      uint8_t xs_length;
      float st_xs;
      float * xs;
      uint8_t ys_length;
      float st_ys;
      float * ys;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_z_min;
      u_z_min.real = this->z_min;
      *(outbuffer + offset + 0) = (u_z_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_min);
      union {
        float real;
        uint32_t base;
      } u_z_max;
      u_z_max.real = this->z_max;
      *(outbuffer + offset + 0) = (u_z_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_max);
      *(outbuffer + offset++) = xs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < xs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_xsi;
      u_xsi.real = this->xs[i];
      *(outbuffer + offset + 0) = (u_xsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xs[i]);
      }
      *(outbuffer + offset++) = ys_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ys_length; i++){
      union {
        float real;
        uint32_t base;
      } u_ysi;
      u_ysi.real = this->ys[i];
      *(outbuffer + offset + 0) = (u_ysi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ysi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ysi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ysi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ys[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_z_min;
      u_z_min.base = 0;
      u_z_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z_min = u_z_min.real;
      offset += sizeof(this->z_min);
      union {
        float real;
        uint32_t base;
      } u_z_max;
      u_z_max.base = 0;
      u_z_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z_max = u_z_max.real;
      offset += sizeof(this->z_max);
      uint8_t xs_lengthT = *(inbuffer + offset++);
      if(xs_lengthT > xs_length)
        this->xs = (float*)realloc(this->xs, xs_lengthT * sizeof(float));
      offset += 3;
      xs_length = xs_lengthT;
      for( uint8_t i = 0; i < xs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_xs;
      u_st_xs.base = 0;
      u_st_xs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_xs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_xs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_xs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_xs = u_st_xs.real;
      offset += sizeof(this->st_xs);
        memcpy( &(this->xs[i]), &(this->st_xs), sizeof(float));
      }
      uint8_t ys_lengthT = *(inbuffer + offset++);
      if(ys_lengthT > ys_length)
        this->ys = (float*)realloc(this->ys, ys_lengthT * sizeof(float));
      offset += 3;
      ys_length = ys_lengthT;
      for( uint8_t i = 0; i < ys_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_ys;
      u_st_ys.base = 0;
      u_st_ys.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ys.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ys.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ys.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_ys = u_st_ys.real;
      offset += sizeof(this->st_ys);
        memcpy( &(this->ys[i]), &(this->st_ys), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "ed_gui_server/Polygon"; };
    const char * getMD5(){ return "dca8a231720a3f194ef7e286bf1747db"; };

  };

}
#endif
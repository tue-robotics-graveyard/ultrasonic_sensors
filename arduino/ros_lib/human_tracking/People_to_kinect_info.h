#ifndef _ROS_human_tracking_People_to_kinect_info_h
#define _ROS_human_tracking_People_to_kinect_info_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace human_tracking
{

  class People_to_kinect_info : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t counter;
      uint8_t true_detect_length;
      geometry_msgs::Point st_true_detect;
      geometry_msgs::Point * true_detect;
      uint8_t false_detect_length;
      geometry_msgs::Point st_false_detect;
      geometry_msgs::Point * false_detect;
      int32_t real_nb;
      uint8_t x_real_length;
      float st_x_real;
      float * x_real;
      uint8_t y_real_length;
      float st_y_real;
      float * y_real;
      uint8_t z_real_length;
      float st_z_real;
      float * z_real;
      uint8_t theta_real_length;
      float st_theta_real;
      float * theta_real;
      uint8_t theta_coeff_real_length;
      float st_theta_coeff_real;
      float * theta_coeff_real;
      int32_t false_nb;
      uint8_t x_false_length;
      float st_x_false;
      float * x_false;
      uint8_t y_false_length;
      float st_y_false;
      float * y_false;
      uint8_t z_false_length;
      float st_z_false;
      float * z_false;
      uint8_t theta_false_length;
      float st_theta_false;
      float * theta_false;
      uint8_t theta_coeff_false_length;
      float st_theta_coeff_false;
      float * theta_coeff_false;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_counter;
      u_counter.real = this->counter;
      *(outbuffer + offset + 0) = (u_counter.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_counter.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_counter.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_counter.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->counter);
      *(outbuffer + offset++) = true_detect_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < true_detect_length; i++){
      offset += this->true_detect[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = false_detect_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < false_detect_length; i++){
      offset += this->false_detect[i].serialize(outbuffer + offset);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_real_nb;
      u_real_nb.real = this->real_nb;
      *(outbuffer + offset + 0) = (u_real_nb.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_real_nb.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_real_nb.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_real_nb.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->real_nb);
      *(outbuffer + offset++) = x_real_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < x_real_length; i++){
      union {
        float real;
        uint32_t base;
      } u_x_reali;
      u_x_reali.real = this->x_real[i];
      *(outbuffer + offset + 0) = (u_x_reali.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_reali.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_reali.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_reali.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_real[i]);
      }
      *(outbuffer + offset++) = y_real_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < y_real_length; i++){
      union {
        float real;
        uint32_t base;
      } u_y_reali;
      u_y_reali.real = this->y_real[i];
      *(outbuffer + offset + 0) = (u_y_reali.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_reali.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_reali.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_reali.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_real[i]);
      }
      *(outbuffer + offset++) = z_real_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < z_real_length; i++){
      union {
        float real;
        uint32_t base;
      } u_z_reali;
      u_z_reali.real = this->z_real[i];
      *(outbuffer + offset + 0) = (u_z_reali.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_reali.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_reali.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_reali.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_real[i]);
      }
      *(outbuffer + offset++) = theta_real_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < theta_real_length; i++){
      union {
        float real;
        uint32_t base;
      } u_theta_reali;
      u_theta_reali.real = this->theta_real[i];
      *(outbuffer + offset + 0) = (u_theta_reali.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta_reali.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta_reali.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta_reali.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->theta_real[i]);
      }
      *(outbuffer + offset++) = theta_coeff_real_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < theta_coeff_real_length; i++){
      union {
        float real;
        uint32_t base;
      } u_theta_coeff_reali;
      u_theta_coeff_reali.real = this->theta_coeff_real[i];
      *(outbuffer + offset + 0) = (u_theta_coeff_reali.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta_coeff_reali.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta_coeff_reali.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta_coeff_reali.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->theta_coeff_real[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_false_nb;
      u_false_nb.real = this->false_nb;
      *(outbuffer + offset + 0) = (u_false_nb.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_false_nb.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_false_nb.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_false_nb.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->false_nb);
      *(outbuffer + offset++) = x_false_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < x_false_length; i++){
      union {
        float real;
        uint32_t base;
      } u_x_falsei;
      u_x_falsei.real = this->x_false[i];
      *(outbuffer + offset + 0) = (u_x_falsei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_falsei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_falsei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_falsei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_false[i]);
      }
      *(outbuffer + offset++) = y_false_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < y_false_length; i++){
      union {
        float real;
        uint32_t base;
      } u_y_falsei;
      u_y_falsei.real = this->y_false[i];
      *(outbuffer + offset + 0) = (u_y_falsei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_falsei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_falsei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_falsei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_false[i]);
      }
      *(outbuffer + offset++) = z_false_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < z_false_length; i++){
      union {
        float real;
        uint32_t base;
      } u_z_falsei;
      u_z_falsei.real = this->z_false[i];
      *(outbuffer + offset + 0) = (u_z_falsei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_falsei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_falsei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_falsei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_false[i]);
      }
      *(outbuffer + offset++) = theta_false_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < theta_false_length; i++){
      union {
        float real;
        uint32_t base;
      } u_theta_falsei;
      u_theta_falsei.real = this->theta_false[i];
      *(outbuffer + offset + 0) = (u_theta_falsei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta_falsei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta_falsei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta_falsei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->theta_false[i]);
      }
      *(outbuffer + offset++) = theta_coeff_false_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < theta_coeff_false_length; i++){
      union {
        float real;
        uint32_t base;
      } u_theta_coeff_falsei;
      u_theta_coeff_falsei.real = this->theta_coeff_false[i];
      *(outbuffer + offset + 0) = (u_theta_coeff_falsei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta_coeff_falsei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta_coeff_falsei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta_coeff_falsei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->theta_coeff_false[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_counter;
      u_counter.base = 0;
      u_counter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_counter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_counter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_counter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->counter = u_counter.real;
      offset += sizeof(this->counter);
      uint8_t true_detect_lengthT = *(inbuffer + offset++);
      if(true_detect_lengthT > true_detect_length)
        this->true_detect = (geometry_msgs::Point*)realloc(this->true_detect, true_detect_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      true_detect_length = true_detect_lengthT;
      for( uint8_t i = 0; i < true_detect_length; i++){
      offset += this->st_true_detect.deserialize(inbuffer + offset);
        memcpy( &(this->true_detect[i]), &(this->st_true_detect), sizeof(geometry_msgs::Point));
      }
      uint8_t false_detect_lengthT = *(inbuffer + offset++);
      if(false_detect_lengthT > false_detect_length)
        this->false_detect = (geometry_msgs::Point*)realloc(this->false_detect, false_detect_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      false_detect_length = false_detect_lengthT;
      for( uint8_t i = 0; i < false_detect_length; i++){
      offset += this->st_false_detect.deserialize(inbuffer + offset);
        memcpy( &(this->false_detect[i]), &(this->st_false_detect), sizeof(geometry_msgs::Point));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_real_nb;
      u_real_nb.base = 0;
      u_real_nb.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_real_nb.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_real_nb.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_real_nb.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->real_nb = u_real_nb.real;
      offset += sizeof(this->real_nb);
      uint8_t x_real_lengthT = *(inbuffer + offset++);
      if(x_real_lengthT > x_real_length)
        this->x_real = (float*)realloc(this->x_real, x_real_lengthT * sizeof(float));
      offset += 3;
      x_real_length = x_real_lengthT;
      for( uint8_t i = 0; i < x_real_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_x_real;
      u_st_x_real.base = 0;
      u_st_x_real.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_x_real.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_x_real.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_x_real.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_x_real = u_st_x_real.real;
      offset += sizeof(this->st_x_real);
        memcpy( &(this->x_real[i]), &(this->st_x_real), sizeof(float));
      }
      uint8_t y_real_lengthT = *(inbuffer + offset++);
      if(y_real_lengthT > y_real_length)
        this->y_real = (float*)realloc(this->y_real, y_real_lengthT * sizeof(float));
      offset += 3;
      y_real_length = y_real_lengthT;
      for( uint8_t i = 0; i < y_real_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_y_real;
      u_st_y_real.base = 0;
      u_st_y_real.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_y_real.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_y_real.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_y_real.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_y_real = u_st_y_real.real;
      offset += sizeof(this->st_y_real);
        memcpy( &(this->y_real[i]), &(this->st_y_real), sizeof(float));
      }
      uint8_t z_real_lengthT = *(inbuffer + offset++);
      if(z_real_lengthT > z_real_length)
        this->z_real = (float*)realloc(this->z_real, z_real_lengthT * sizeof(float));
      offset += 3;
      z_real_length = z_real_lengthT;
      for( uint8_t i = 0; i < z_real_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_z_real;
      u_st_z_real.base = 0;
      u_st_z_real.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_z_real.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_z_real.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_z_real.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_z_real = u_st_z_real.real;
      offset += sizeof(this->st_z_real);
        memcpy( &(this->z_real[i]), &(this->st_z_real), sizeof(float));
      }
      uint8_t theta_real_lengthT = *(inbuffer + offset++);
      if(theta_real_lengthT > theta_real_length)
        this->theta_real = (float*)realloc(this->theta_real, theta_real_lengthT * sizeof(float));
      offset += 3;
      theta_real_length = theta_real_lengthT;
      for( uint8_t i = 0; i < theta_real_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_theta_real;
      u_st_theta_real.base = 0;
      u_st_theta_real.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_theta_real.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_theta_real.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_theta_real.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_theta_real = u_st_theta_real.real;
      offset += sizeof(this->st_theta_real);
        memcpy( &(this->theta_real[i]), &(this->st_theta_real), sizeof(float));
      }
      uint8_t theta_coeff_real_lengthT = *(inbuffer + offset++);
      if(theta_coeff_real_lengthT > theta_coeff_real_length)
        this->theta_coeff_real = (float*)realloc(this->theta_coeff_real, theta_coeff_real_lengthT * sizeof(float));
      offset += 3;
      theta_coeff_real_length = theta_coeff_real_lengthT;
      for( uint8_t i = 0; i < theta_coeff_real_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_theta_coeff_real;
      u_st_theta_coeff_real.base = 0;
      u_st_theta_coeff_real.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_theta_coeff_real.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_theta_coeff_real.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_theta_coeff_real.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_theta_coeff_real = u_st_theta_coeff_real.real;
      offset += sizeof(this->st_theta_coeff_real);
        memcpy( &(this->theta_coeff_real[i]), &(this->st_theta_coeff_real), sizeof(float));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_false_nb;
      u_false_nb.base = 0;
      u_false_nb.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_false_nb.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_false_nb.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_false_nb.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->false_nb = u_false_nb.real;
      offset += sizeof(this->false_nb);
      uint8_t x_false_lengthT = *(inbuffer + offset++);
      if(x_false_lengthT > x_false_length)
        this->x_false = (float*)realloc(this->x_false, x_false_lengthT * sizeof(float));
      offset += 3;
      x_false_length = x_false_lengthT;
      for( uint8_t i = 0; i < x_false_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_x_false;
      u_st_x_false.base = 0;
      u_st_x_false.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_x_false.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_x_false.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_x_false.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_x_false = u_st_x_false.real;
      offset += sizeof(this->st_x_false);
        memcpy( &(this->x_false[i]), &(this->st_x_false), sizeof(float));
      }
      uint8_t y_false_lengthT = *(inbuffer + offset++);
      if(y_false_lengthT > y_false_length)
        this->y_false = (float*)realloc(this->y_false, y_false_lengthT * sizeof(float));
      offset += 3;
      y_false_length = y_false_lengthT;
      for( uint8_t i = 0; i < y_false_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_y_false;
      u_st_y_false.base = 0;
      u_st_y_false.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_y_false.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_y_false.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_y_false.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_y_false = u_st_y_false.real;
      offset += sizeof(this->st_y_false);
        memcpy( &(this->y_false[i]), &(this->st_y_false), sizeof(float));
      }
      uint8_t z_false_lengthT = *(inbuffer + offset++);
      if(z_false_lengthT > z_false_length)
        this->z_false = (float*)realloc(this->z_false, z_false_lengthT * sizeof(float));
      offset += 3;
      z_false_length = z_false_lengthT;
      for( uint8_t i = 0; i < z_false_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_z_false;
      u_st_z_false.base = 0;
      u_st_z_false.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_z_false.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_z_false.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_z_false.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_z_false = u_st_z_false.real;
      offset += sizeof(this->st_z_false);
        memcpy( &(this->z_false[i]), &(this->st_z_false), sizeof(float));
      }
      uint8_t theta_false_lengthT = *(inbuffer + offset++);
      if(theta_false_lengthT > theta_false_length)
        this->theta_false = (float*)realloc(this->theta_false, theta_false_lengthT * sizeof(float));
      offset += 3;
      theta_false_length = theta_false_lengthT;
      for( uint8_t i = 0; i < theta_false_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_theta_false;
      u_st_theta_false.base = 0;
      u_st_theta_false.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_theta_false.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_theta_false.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_theta_false.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_theta_false = u_st_theta_false.real;
      offset += sizeof(this->st_theta_false);
        memcpy( &(this->theta_false[i]), &(this->st_theta_false), sizeof(float));
      }
      uint8_t theta_coeff_false_lengthT = *(inbuffer + offset++);
      if(theta_coeff_false_lengthT > theta_coeff_false_length)
        this->theta_coeff_false = (float*)realloc(this->theta_coeff_false, theta_coeff_false_lengthT * sizeof(float));
      offset += 3;
      theta_coeff_false_length = theta_coeff_false_lengthT;
      for( uint8_t i = 0; i < theta_coeff_false_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_theta_coeff_false;
      u_st_theta_coeff_false.base = 0;
      u_st_theta_coeff_false.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_theta_coeff_false.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_theta_coeff_false.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_theta_coeff_false.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_theta_coeff_false = u_st_theta_coeff_false.real;
      offset += sizeof(this->st_theta_coeff_false);
        memcpy( &(this->theta_coeff_false[i]), &(this->st_theta_coeff_false), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "human_tracking/People_to_kinect_info"; };
    const char * getMD5(){ return "a2191f0f9ef68ef2d80abf6c519bd83a"; };

  };

}
#endif
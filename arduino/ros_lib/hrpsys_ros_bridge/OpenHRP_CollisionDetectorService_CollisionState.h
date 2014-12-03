#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_CollisionDetectorService_CollisionState_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_CollisionDetectorService_CollisionState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_CollisionDetectorService_CollisionState : public ros::Msg
  {
    public:
      float time;
      float computation_time;
      bool safe_posture;
      float recover_time;
      int16_t loop_for_check;
      uint8_t angle_length;
      float st_angle;
      float * angle;
      uint8_t collide_length;
      bool st_collide;
      bool * collide;
      std_msgs::Float64MultiArray lines;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_time = (int32_t *) &(this->time);
      int32_t exp_time = (((*val_time)>>23)&255);
      if(exp_time != 0)
        exp_time += 1023-127;
      int32_t sig_time = *val_time;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_time<<5) & 0xff;
      *(outbuffer + offset++) = (sig_time>>3) & 0xff;
      *(outbuffer + offset++) = (sig_time>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_time<<4) & 0xF0) | ((sig_time>>19)&0x0F);
      *(outbuffer + offset++) = (exp_time>>4) & 0x7F;
      if(this->time < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_computation_time = (int32_t *) &(this->computation_time);
      int32_t exp_computation_time = (((*val_computation_time)>>23)&255);
      if(exp_computation_time != 0)
        exp_computation_time += 1023-127;
      int32_t sig_computation_time = *val_computation_time;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_computation_time<<5) & 0xff;
      *(outbuffer + offset++) = (sig_computation_time>>3) & 0xff;
      *(outbuffer + offset++) = (sig_computation_time>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_computation_time<<4) & 0xF0) | ((sig_computation_time>>19)&0x0F);
      *(outbuffer + offset++) = (exp_computation_time>>4) & 0x7F;
      if(this->computation_time < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        bool real;
        uint8_t base;
      } u_safe_posture;
      u_safe_posture.real = this->safe_posture;
      *(outbuffer + offset + 0) = (u_safe_posture.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->safe_posture);
      int32_t * val_recover_time = (int32_t *) &(this->recover_time);
      int32_t exp_recover_time = (((*val_recover_time)>>23)&255);
      if(exp_recover_time != 0)
        exp_recover_time += 1023-127;
      int32_t sig_recover_time = *val_recover_time;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_recover_time<<5) & 0xff;
      *(outbuffer + offset++) = (sig_recover_time>>3) & 0xff;
      *(outbuffer + offset++) = (sig_recover_time>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_recover_time<<4) & 0xF0) | ((sig_recover_time>>19)&0x0F);
      *(outbuffer + offset++) = (exp_recover_time>>4) & 0x7F;
      if(this->recover_time < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        int16_t real;
        uint16_t base;
      } u_loop_for_check;
      u_loop_for_check.real = this->loop_for_check;
      *(outbuffer + offset + 0) = (u_loop_for_check.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_loop_for_check.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->loop_for_check);
      *(outbuffer + offset++) = angle_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < angle_length; i++){
      int32_t * val_anglei = (int32_t *) &(this->angle[i]);
      int32_t exp_anglei = (((*val_anglei)>>23)&255);
      if(exp_anglei != 0)
        exp_anglei += 1023-127;
      int32_t sig_anglei = *val_anglei;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_anglei<<5) & 0xff;
      *(outbuffer + offset++) = (sig_anglei>>3) & 0xff;
      *(outbuffer + offset++) = (sig_anglei>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_anglei<<4) & 0xF0) | ((sig_anglei>>19)&0x0F);
      *(outbuffer + offset++) = (exp_anglei>>4) & 0x7F;
      if(this->angle[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = collide_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < collide_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_collidei;
      u_collidei.real = this->collide[i];
      *(outbuffer + offset + 0) = (u_collidei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->collide[i]);
      }
      offset += this->lines.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_time = (uint32_t*) &(this->time);
      offset += 3;
      *val_time = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_time |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_time = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_time |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_time !=0)
        *val_time |= ((exp_time)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->time = -this->time;
      uint32_t * val_computation_time = (uint32_t*) &(this->computation_time);
      offset += 3;
      *val_computation_time = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_computation_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_computation_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_computation_time |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_computation_time = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_computation_time |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_computation_time !=0)
        *val_computation_time |= ((exp_computation_time)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->computation_time = -this->computation_time;
      union {
        bool real;
        uint8_t base;
      } u_safe_posture;
      u_safe_posture.base = 0;
      u_safe_posture.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->safe_posture = u_safe_posture.real;
      offset += sizeof(this->safe_posture);
      uint32_t * val_recover_time = (uint32_t*) &(this->recover_time);
      offset += 3;
      *val_recover_time = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_recover_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_recover_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_recover_time |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_recover_time = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_recover_time |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_recover_time !=0)
        *val_recover_time |= ((exp_recover_time)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->recover_time = -this->recover_time;
      union {
        int16_t real;
        uint16_t base;
      } u_loop_for_check;
      u_loop_for_check.base = 0;
      u_loop_for_check.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_loop_for_check.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->loop_for_check = u_loop_for_check.real;
      offset += sizeof(this->loop_for_check);
      uint8_t angle_lengthT = *(inbuffer + offset++);
      if(angle_lengthT > angle_length)
        this->angle = (float*)realloc(this->angle, angle_lengthT * sizeof(float));
      offset += 3;
      angle_length = angle_lengthT;
      for( uint8_t i = 0; i < angle_length; i++){
      uint32_t * val_st_angle = (uint32_t*) &(this->st_angle);
      offset += 3;
      *val_st_angle = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_angle |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_angle |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_angle |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_angle = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_angle |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_angle !=0)
        *val_st_angle |= ((exp_st_angle)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_angle = -this->st_angle;
        memcpy( &(this->angle[i]), &(this->st_angle), sizeof(float));
      }
      uint8_t collide_lengthT = *(inbuffer + offset++);
      if(collide_lengthT > collide_length)
        this->collide = (bool*)realloc(this->collide, collide_lengthT * sizeof(bool));
      offset += 3;
      collide_length = collide_lengthT;
      for( uint8_t i = 0; i < collide_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_collide;
      u_st_collide.base = 0;
      u_st_collide.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_collide = u_st_collide.real;
      offset += sizeof(this->st_collide);
        memcpy( &(this->collide[i]), &(this->st_collide), sizeof(bool));
      }
      offset += this->lines.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_CollisionDetectorService_CollisionState"; };
    const char * getMD5(){ return "99964cb468a99e4b69081e04306b420c"; };

  };

}
#endif
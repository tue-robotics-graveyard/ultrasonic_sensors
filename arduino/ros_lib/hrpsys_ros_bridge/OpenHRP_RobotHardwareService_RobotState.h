#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_RobotHardwareService_RobotState_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_RobotHardwareService_RobotState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_RobotHardwareService_RobotState : public ros::Msg
  {
    public:
      uint8_t angle_length;
      float st_angle;
      float * angle;
      uint8_t command_length;
      float st_command;
      float * command;
      uint8_t torque_length;
      float st_torque;
      float * torque;
      std_msgs::Int32MultiArray servoState;
      std_msgs::Float64MultiArray force;
      std_msgs::Float64MultiArray rateGyro;
      std_msgs::Float64MultiArray accel;
      float voltage;
      float current;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      *(outbuffer + offset++) = command_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < command_length; i++){
      int32_t * val_commandi = (int32_t *) &(this->command[i]);
      int32_t exp_commandi = (((*val_commandi)>>23)&255);
      if(exp_commandi != 0)
        exp_commandi += 1023-127;
      int32_t sig_commandi = *val_commandi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_commandi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_commandi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_commandi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_commandi<<4) & 0xF0) | ((sig_commandi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_commandi>>4) & 0x7F;
      if(this->command[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      *(outbuffer + offset++) = torque_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < torque_length; i++){
      int32_t * val_torquei = (int32_t *) &(this->torque[i]);
      int32_t exp_torquei = (((*val_torquei)>>23)&255);
      if(exp_torquei != 0)
        exp_torquei += 1023-127;
      int32_t sig_torquei = *val_torquei;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_torquei<<5) & 0xff;
      *(outbuffer + offset++) = (sig_torquei>>3) & 0xff;
      *(outbuffer + offset++) = (sig_torquei>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_torquei<<4) & 0xF0) | ((sig_torquei>>19)&0x0F);
      *(outbuffer + offset++) = (exp_torquei>>4) & 0x7F;
      if(this->torque[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      offset += this->servoState.serialize(outbuffer + offset);
      offset += this->force.serialize(outbuffer + offset);
      offset += this->rateGyro.serialize(outbuffer + offset);
      offset += this->accel.serialize(outbuffer + offset);
      int32_t * val_voltage = (int32_t *) &(this->voltage);
      int32_t exp_voltage = (((*val_voltage)>>23)&255);
      if(exp_voltage != 0)
        exp_voltage += 1023-127;
      int32_t sig_voltage = *val_voltage;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_voltage<<5) & 0xff;
      *(outbuffer + offset++) = (sig_voltage>>3) & 0xff;
      *(outbuffer + offset++) = (sig_voltage>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_voltage<<4) & 0xF0) | ((sig_voltage>>19)&0x0F);
      *(outbuffer + offset++) = (exp_voltage>>4) & 0x7F;
      if(this->voltage < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_current = (int32_t *) &(this->current);
      int32_t exp_current = (((*val_current)>>23)&255);
      if(exp_current != 0)
        exp_current += 1023-127;
      int32_t sig_current = *val_current;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_current<<5) & 0xff;
      *(outbuffer + offset++) = (sig_current>>3) & 0xff;
      *(outbuffer + offset++) = (sig_current>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_current<<4) & 0xF0) | ((sig_current>>19)&0x0F);
      *(outbuffer + offset++) = (exp_current>>4) & 0x7F;
      if(this->current < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      uint8_t command_lengthT = *(inbuffer + offset++);
      if(command_lengthT > command_length)
        this->command = (float*)realloc(this->command, command_lengthT * sizeof(float));
      offset += 3;
      command_length = command_lengthT;
      for( uint8_t i = 0; i < command_length; i++){
      uint32_t * val_st_command = (uint32_t*) &(this->st_command);
      offset += 3;
      *val_st_command = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_command |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_command |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_command |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_command = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_command |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_command !=0)
        *val_st_command |= ((exp_st_command)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_command = -this->st_command;
        memcpy( &(this->command[i]), &(this->st_command), sizeof(float));
      }
      uint8_t torque_lengthT = *(inbuffer + offset++);
      if(torque_lengthT > torque_length)
        this->torque = (float*)realloc(this->torque, torque_lengthT * sizeof(float));
      offset += 3;
      torque_length = torque_lengthT;
      for( uint8_t i = 0; i < torque_length; i++){
      uint32_t * val_st_torque = (uint32_t*) &(this->st_torque);
      offset += 3;
      *val_st_torque = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_torque |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_torque |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_torque |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_torque = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_torque |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_torque !=0)
        *val_st_torque |= ((exp_st_torque)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_torque = -this->st_torque;
        memcpy( &(this->torque[i]), &(this->st_torque), sizeof(float));
      }
      offset += this->servoState.deserialize(inbuffer + offset);
      offset += this->force.deserialize(inbuffer + offset);
      offset += this->rateGyro.deserialize(inbuffer + offset);
      offset += this->accel.deserialize(inbuffer + offset);
      uint32_t * val_voltage = (uint32_t*) &(this->voltage);
      offset += 3;
      *val_voltage = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_voltage |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_voltage |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_voltage |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_voltage = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_voltage |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_voltage !=0)
        *val_voltage |= ((exp_voltage)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->voltage = -this->voltage;
      uint32_t * val_current = (uint32_t*) &(this->current);
      offset += 3;
      *val_current = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_current |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_current |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_current |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_current = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_current |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_current !=0)
        *val_current |= ((exp_current)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->current = -this->current;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_RobotState"; };
    const char * getMD5(){ return "4e74b03cda95d5f0d9622734e0185447"; };

  };

}
#endif
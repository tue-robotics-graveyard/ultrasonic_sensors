#ifndef _ROS_hrpsys_ros_bridge_MotorStates_h
#define _ROS_hrpsys_ros_bridge_MotorStates_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

  class MotorStates : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t name_length;
      char* st_name;
      char* * name;
      uint8_t calib_state_length;
      bool st_calib_state;
      bool * calib_state;
      uint8_t servo_state_length;
      bool st_servo_state;
      bool * servo_state;
      uint8_t power_state_length;
      bool st_power_state;
      bool * power_state;
      uint8_t servo_alarm_length;
      int32_t st_servo_alarm;
      int32_t * servo_alarm;
      uint8_t driver_temp_length;
      int16_t st_driver_temp;
      int16_t * driver_temp;
      uint8_t temperature_length;
      float st_temperature;
      float * temperature;
      std_msgs::Float64MultiArray extra_data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = name_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < name_length; i++){
      uint32_t length_namei = strlen( (const char*) this->name[i]);
      memcpy(outbuffer + offset, &length_namei, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_namei);
      offset += length_namei;
      }
      *(outbuffer + offset++) = calib_state_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < calib_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_calib_statei;
      u_calib_statei.real = this->calib_state[i];
      *(outbuffer + offset + 0) = (u_calib_statei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->calib_state[i]);
      }
      *(outbuffer + offset++) = servo_state_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < servo_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_servo_statei;
      u_servo_statei.real = this->servo_state[i];
      *(outbuffer + offset + 0) = (u_servo_statei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->servo_state[i]);
      }
      *(outbuffer + offset++) = power_state_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < power_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_power_statei;
      u_power_statei.real = this->power_state[i];
      *(outbuffer + offset + 0) = (u_power_statei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->power_state[i]);
      }
      *(outbuffer + offset++) = servo_alarm_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < servo_alarm_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_servo_alarmi;
      u_servo_alarmi.real = this->servo_alarm[i];
      *(outbuffer + offset + 0) = (u_servo_alarmi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_servo_alarmi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_servo_alarmi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_servo_alarmi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->servo_alarm[i]);
      }
      *(outbuffer + offset++) = driver_temp_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < driver_temp_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_driver_tempi;
      u_driver_tempi.real = this->driver_temp[i];
      *(outbuffer + offset + 0) = (u_driver_tempi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_driver_tempi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->driver_temp[i]);
      }
      *(outbuffer + offset++) = temperature_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < temperature_length; i++){
      int32_t * val_temperaturei = (int32_t *) &(this->temperature[i]);
      int32_t exp_temperaturei = (((*val_temperaturei)>>23)&255);
      if(exp_temperaturei != 0)
        exp_temperaturei += 1023-127;
      int32_t sig_temperaturei = *val_temperaturei;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_temperaturei<<5) & 0xff;
      *(outbuffer + offset++) = (sig_temperaturei>>3) & 0xff;
      *(outbuffer + offset++) = (sig_temperaturei>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_temperaturei<<4) & 0xF0) | ((sig_temperaturei>>19)&0x0F);
      *(outbuffer + offset++) = (exp_temperaturei>>4) & 0x7F;
      if(this->temperature[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      offset += this->extra_data.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t name_lengthT = *(inbuffer + offset++);
      if(name_lengthT > name_length)
        this->name = (char**)realloc(this->name, name_lengthT * sizeof(char*));
      offset += 3;
      name_length = name_lengthT;
      for( uint8_t i = 0; i < name_length; i++){
      uint32_t length_st_name;
      memcpy(&length_st_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_name-1]=0;
      this->st_name = (char *)(inbuffer + offset-1);
      offset += length_st_name;
        memcpy( &(this->name[i]), &(this->st_name), sizeof(char*));
      }
      uint8_t calib_state_lengthT = *(inbuffer + offset++);
      if(calib_state_lengthT > calib_state_length)
        this->calib_state = (bool*)realloc(this->calib_state, calib_state_lengthT * sizeof(bool));
      offset += 3;
      calib_state_length = calib_state_lengthT;
      for( uint8_t i = 0; i < calib_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_calib_state;
      u_st_calib_state.base = 0;
      u_st_calib_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_calib_state = u_st_calib_state.real;
      offset += sizeof(this->st_calib_state);
        memcpy( &(this->calib_state[i]), &(this->st_calib_state), sizeof(bool));
      }
      uint8_t servo_state_lengthT = *(inbuffer + offset++);
      if(servo_state_lengthT > servo_state_length)
        this->servo_state = (bool*)realloc(this->servo_state, servo_state_lengthT * sizeof(bool));
      offset += 3;
      servo_state_length = servo_state_lengthT;
      for( uint8_t i = 0; i < servo_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_servo_state;
      u_st_servo_state.base = 0;
      u_st_servo_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_servo_state = u_st_servo_state.real;
      offset += sizeof(this->st_servo_state);
        memcpy( &(this->servo_state[i]), &(this->st_servo_state), sizeof(bool));
      }
      uint8_t power_state_lengthT = *(inbuffer + offset++);
      if(power_state_lengthT > power_state_length)
        this->power_state = (bool*)realloc(this->power_state, power_state_lengthT * sizeof(bool));
      offset += 3;
      power_state_length = power_state_lengthT;
      for( uint8_t i = 0; i < power_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_power_state;
      u_st_power_state.base = 0;
      u_st_power_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_power_state = u_st_power_state.real;
      offset += sizeof(this->st_power_state);
        memcpy( &(this->power_state[i]), &(this->st_power_state), sizeof(bool));
      }
      uint8_t servo_alarm_lengthT = *(inbuffer + offset++);
      if(servo_alarm_lengthT > servo_alarm_length)
        this->servo_alarm = (int32_t*)realloc(this->servo_alarm, servo_alarm_lengthT * sizeof(int32_t));
      offset += 3;
      servo_alarm_length = servo_alarm_lengthT;
      for( uint8_t i = 0; i < servo_alarm_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_servo_alarm;
      u_st_servo_alarm.base = 0;
      u_st_servo_alarm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_servo_alarm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_servo_alarm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_servo_alarm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_servo_alarm = u_st_servo_alarm.real;
      offset += sizeof(this->st_servo_alarm);
        memcpy( &(this->servo_alarm[i]), &(this->st_servo_alarm), sizeof(int32_t));
      }
      uint8_t driver_temp_lengthT = *(inbuffer + offset++);
      if(driver_temp_lengthT > driver_temp_length)
        this->driver_temp = (int16_t*)realloc(this->driver_temp, driver_temp_lengthT * sizeof(int16_t));
      offset += 3;
      driver_temp_length = driver_temp_lengthT;
      for( uint8_t i = 0; i < driver_temp_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_driver_temp;
      u_st_driver_temp.base = 0;
      u_st_driver_temp.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_driver_temp.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_driver_temp = u_st_driver_temp.real;
      offset += sizeof(this->st_driver_temp);
        memcpy( &(this->driver_temp[i]), &(this->st_driver_temp), sizeof(int16_t));
      }
      uint8_t temperature_lengthT = *(inbuffer + offset++);
      if(temperature_lengthT > temperature_length)
        this->temperature = (float*)realloc(this->temperature, temperature_lengthT * sizeof(float));
      offset += 3;
      temperature_length = temperature_lengthT;
      for( uint8_t i = 0; i < temperature_length; i++){
      uint32_t * val_st_temperature = (uint32_t*) &(this->st_temperature);
      offset += 3;
      *val_st_temperature = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_temperature |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_temperature |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_temperature |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_temperature = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_temperature |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_temperature !=0)
        *val_st_temperature |= ((exp_st_temperature)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_temperature = -this->st_temperature;
        memcpy( &(this->temperature[i]), &(this->st_temperature), sizeof(float));
      }
      offset += this->extra_data.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/MotorStates"; };
    const char * getMD5(){ return "75f582b3495b189b341d4111731cd7fc"; };

  };

}
#endif
#ifndef _ROS_amigo_msgs_AmigoGripperMeasurement_h
#define _ROS_amigo_msgs_AmigoGripperMeasurement_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace amigo_msgs
{

  class AmigoGripperMeasurement : public ros::Msg
  {
    public:
      int8_t direction;
      float torque;
      float position;
      bool max_torque_reached;
      bool end_position_reached;
      enum { OPEN = -1 };
      enum { CLOSE = 1 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_direction;
      u_direction.real = this->direction;
      *(outbuffer + offset + 0) = (u_direction.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->direction);
      int32_t * val_torque = (int32_t *) &(this->torque);
      int32_t exp_torque = (((*val_torque)>>23)&255);
      if(exp_torque != 0)
        exp_torque += 1023-127;
      int32_t sig_torque = *val_torque;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_torque<<5) & 0xff;
      *(outbuffer + offset++) = (sig_torque>>3) & 0xff;
      *(outbuffer + offset++) = (sig_torque>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_torque<<4) & 0xF0) | ((sig_torque>>19)&0x0F);
      *(outbuffer + offset++) = (exp_torque>>4) & 0x7F;
      if(this->torque < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_position = (int32_t *) &(this->position);
      int32_t exp_position = (((*val_position)>>23)&255);
      if(exp_position != 0)
        exp_position += 1023-127;
      int32_t sig_position = *val_position;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_position<<5) & 0xff;
      *(outbuffer + offset++) = (sig_position>>3) & 0xff;
      *(outbuffer + offset++) = (sig_position>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_position<<4) & 0xF0) | ((sig_position>>19)&0x0F);
      *(outbuffer + offset++) = (exp_position>>4) & 0x7F;
      if(this->position < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        bool real;
        uint8_t base;
      } u_max_torque_reached;
      u_max_torque_reached.real = this->max_torque_reached;
      *(outbuffer + offset + 0) = (u_max_torque_reached.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->max_torque_reached);
      union {
        bool real;
        uint8_t base;
      } u_end_position_reached;
      u_end_position_reached.real = this->end_position_reached;
      *(outbuffer + offset + 0) = (u_end_position_reached.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->end_position_reached);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_direction;
      u_direction.base = 0;
      u_direction.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->direction = u_direction.real;
      offset += sizeof(this->direction);
      uint32_t * val_torque = (uint32_t*) &(this->torque);
      offset += 3;
      *val_torque = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_torque |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_torque |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_torque |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_torque = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_torque |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_torque !=0)
        *val_torque |= ((exp_torque)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->torque = -this->torque;
      uint32_t * val_position = (uint32_t*) &(this->position);
      offset += 3;
      *val_position = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_position |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_position |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_position |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_position = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_position |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_position !=0)
        *val_position |= ((exp_position)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->position = -this->position;
      union {
        bool real;
        uint8_t base;
      } u_max_torque_reached;
      u_max_torque_reached.base = 0;
      u_max_torque_reached.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->max_torque_reached = u_max_torque_reached.real;
      offset += sizeof(this->max_torque_reached);
      union {
        bool real;
        uint8_t base;
      } u_end_position_reached;
      u_end_position_reached.base = 0;
      u_end_position_reached.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->end_position_reached = u_end_position_reached.real;
      offset += sizeof(this->end_position_reached);
     return offset;
    }

    const char * getType(){ return "amigo_msgs/AmigoGripperMeasurement"; };
    const char * getMD5(){ return "17800da624d2663265740ee3526eee74"; };

  };

}
#endif
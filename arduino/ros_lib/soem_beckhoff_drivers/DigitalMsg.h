#ifndef _ROS_soem_beckhoff_drivers_DigitalMsg_h
#define _ROS_soem_beckhoff_drivers_DigitalMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace soem_beckhoff_drivers
{

  class DigitalMsg : public ros::Msg
  {
    public:
      uint8_t values_length;
      bool st_values;
      bool * values;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < values_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_valuesi;
      u_valuesi.real = this->values[i];
      *(outbuffer + offset + 0) = (u_valuesi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->values[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t values_lengthT = *(inbuffer + offset++);
      if(values_lengthT > values_length)
        this->values = (bool*)realloc(this->values, values_lengthT * sizeof(bool));
      offset += 3;
      values_length = values_lengthT;
      for( uint8_t i = 0; i < values_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_values;
      u_st_values.base = 0;
      u_st_values.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_values = u_st_values.real;
      offset += sizeof(this->st_values);
        memcpy( &(this->values[i]), &(this->st_values), sizeof(bool));
      }
     return offset;
    }

    const char * getType(){ return "soem_beckhoff_drivers/DigitalMsg"; };
    const char * getMD5(){ return "3bf9017546367a617cb0bae8934ef528"; };

  };

}
#endif
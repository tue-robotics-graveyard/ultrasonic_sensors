#ifndef _ROS_soem_beckhoff_drivers_PSUMsg_h
#define _ROS_soem_beckhoff_drivers_PSUMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace soem_beckhoff_drivers
{

  class PSUMsg : public ros::Msg
  {
    public:
      bool power_ok;
      bool overload;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_power_ok;
      u_power_ok.real = this->power_ok;
      *(outbuffer + offset + 0) = (u_power_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->power_ok);
      union {
        bool real;
        uint8_t base;
      } u_overload;
      u_overload.real = this->overload;
      *(outbuffer + offset + 0) = (u_overload.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->overload);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_power_ok;
      u_power_ok.base = 0;
      u_power_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->power_ok = u_power_ok.real;
      offset += sizeof(this->power_ok);
      union {
        bool real;
        uint8_t base;
      } u_overload;
      u_overload.base = 0;
      u_overload.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->overload = u_overload.real;
      offset += sizeof(this->overload);
     return offset;
    }

    const char * getType(){ return "soem_beckhoff_drivers/PSUMsg"; };
    const char * getMD5(){ return "1d640ba06d2b65ae841e25741b04ea2c"; };

  };

}
#endif
#ifndef _ROS_SERVICE_SimpleService_MyService_set_value_h
#define _ROS_SERVICE_SimpleService_MyService_set_value_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace openrtm_ros_bridge
{

static const char SIMPLESERVICE_MYSERVICE_SET_VALUE[] = "openrtm_ros_bridge/SimpleService_MyService_set_value";

  class SimpleService_MyService_set_valueRequest : public ros::Msg
  {
    public:
      float value;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return SIMPLESERVICE_MYSERVICE_SET_VALUE; };
    const char * getMD5(){ return "0aca93dcf6d857f0e5a0dc6be1eaa9fb"; };

  };

  class SimpleService_MyService_set_valueResponse : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SIMPLESERVICE_MYSERVICE_SET_VALUE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SimpleService_MyService_set_value {
    public:
    typedef SimpleService_MyService_set_valueRequest Request;
    typedef SimpleService_MyService_set_valueResponse Response;
  };

}
#endif

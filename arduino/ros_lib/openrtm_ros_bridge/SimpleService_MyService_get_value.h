#ifndef _ROS_SERVICE_SimpleService_MyService_get_value_h
#define _ROS_SERVICE_SimpleService_MyService_get_value_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace openrtm_ros_bridge
{

static const char SIMPLESERVICE_MYSERVICE_GET_VALUE[] = "openrtm_ros_bridge/SimpleService_MyService_get_value";

  class SimpleService_MyService_get_valueRequest : public ros::Msg
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

    const char * getType(){ return SIMPLESERVICE_MYSERVICE_GET_VALUE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SimpleService_MyService_get_valueResponse : public ros::Msg
  {
    public:
      float operation_return;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_operation_return.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_operation_return.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_operation_return.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->operation_return);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_operation_return.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_operation_return.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_operation_return.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
     return offset;
    }

    const char * getType(){ return SIMPLESERVICE_MYSERVICE_GET_VALUE; };
    const char * getMD5(){ return "1af282f87d1e7f3e95e1673ff7b37a25"; };

  };

  class SimpleService_MyService_get_value {
    public:
    typedef SimpleService_MyService_get_valueRequest Request;
    typedef SimpleService_MyService_get_valueResponse Response;
  };

}
#endif

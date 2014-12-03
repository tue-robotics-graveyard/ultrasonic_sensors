#ifndef _ROS_SERVICE_SimpleService_MyService_get_value_history_h
#define _ROS_SERVICE_SimpleService_MyService_get_value_history_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace openrtm_ros_bridge
{

static const char SIMPLESERVICE_MYSERVICE_GET_VALUE_HISTORY[] = "openrtm_ros_bridge/SimpleService_MyService_get_value_history";

  class SimpleService_MyService_get_value_historyRequest : public ros::Msg
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

    const char * getType(){ return SIMPLESERVICE_MYSERVICE_GET_VALUE_HISTORY; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SimpleService_MyService_get_value_historyResponse : public ros::Msg
  {
    public:
      uint8_t operation_return_length;
      float st_operation_return;
      float * operation_return;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = operation_return_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < operation_return_length; i++){
      union {
        float real;
        uint32_t base;
      } u_operation_returni;
      u_operation_returni.real = this->operation_return[i];
      *(outbuffer + offset + 0) = (u_operation_returni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_operation_returni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_operation_returni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_operation_returni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->operation_return[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t operation_return_lengthT = *(inbuffer + offset++);
      if(operation_return_lengthT > operation_return_length)
        this->operation_return = (float*)realloc(this->operation_return, operation_return_lengthT * sizeof(float));
      offset += 3;
      operation_return_length = operation_return_lengthT;
      for( uint8_t i = 0; i < operation_return_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_operation_return;
      u_st_operation_return.base = 0;
      u_st_operation_return.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_operation_return.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_operation_return.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_operation_return.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_operation_return = u_st_operation_return.real;
      offset += sizeof(this->st_operation_return);
        memcpy( &(this->operation_return[i]), &(this->st_operation_return), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return SIMPLESERVICE_MYSERVICE_GET_VALUE_HISTORY; };
    const char * getMD5(){ return "91a243e3b0c6538d73ec05c21a1fb731"; };

  };

  class SimpleService_MyService_get_value_history {
    public:
    typedef SimpleService_MyService_get_value_historyRequest Request;
    typedef SimpleService_MyService_get_value_historyResponse Response;
  };

}
#endif

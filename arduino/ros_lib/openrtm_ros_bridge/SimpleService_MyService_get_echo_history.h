#ifndef _ROS_SERVICE_SimpleService_MyService_get_echo_history_h
#define _ROS_SERVICE_SimpleService_MyService_get_echo_history_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace openrtm_ros_bridge
{

static const char SIMPLESERVICE_MYSERVICE_GET_ECHO_HISTORY[] = "openrtm_ros_bridge/SimpleService_MyService_get_echo_history";

  class SimpleService_MyService_get_echo_historyRequest : public ros::Msg
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

    const char * getType(){ return SIMPLESERVICE_MYSERVICE_GET_ECHO_HISTORY; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SimpleService_MyService_get_echo_historyResponse : public ros::Msg
  {
    public:
      uint8_t operation_return_length;
      char* st_operation_return;
      char* * operation_return;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = operation_return_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < operation_return_length; i++){
      uint32_t length_operation_returni = strlen( (const char*) this->operation_return[i]);
      memcpy(outbuffer + offset, &length_operation_returni, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->operation_return[i], length_operation_returni);
      offset += length_operation_returni;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t operation_return_lengthT = *(inbuffer + offset++);
      if(operation_return_lengthT > operation_return_length)
        this->operation_return = (char**)realloc(this->operation_return, operation_return_lengthT * sizeof(char*));
      offset += 3;
      operation_return_length = operation_return_lengthT;
      for( uint8_t i = 0; i < operation_return_length; i++){
      uint32_t length_st_operation_return;
      memcpy(&length_st_operation_return, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_operation_return; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_operation_return-1]=0;
      this->st_operation_return = (char *)(inbuffer + offset-1);
      offset += length_st_operation_return;
        memcpy( &(this->operation_return[i]), &(this->st_operation_return), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return SIMPLESERVICE_MYSERVICE_GET_ECHO_HISTORY; };
    const char * getMD5(){ return "fc823f84f34ad5a00897d68c51f6631d"; };

  };

  class SimpleService_MyService_get_echo_history {
    public:
    typedef SimpleService_MyService_get_echo_historyRequest Request;
    typedef SimpleService_MyService_get_echo_historyResponse Response;
  };

}
#endif

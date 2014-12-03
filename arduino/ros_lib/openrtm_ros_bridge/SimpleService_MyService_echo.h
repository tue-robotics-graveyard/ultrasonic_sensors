#ifndef _ROS_SERVICE_SimpleService_MyService_echo_h
#define _ROS_SERVICE_SimpleService_MyService_echo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace openrtm_ros_bridge
{

static const char SIMPLESERVICE_MYSERVICE_ECHO[] = "openrtm_ros_bridge/SimpleService_MyService_echo";

  class SimpleService_MyService_echoRequest : public ros::Msg
  {
    public:
      char * msg;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_msg = strlen( (const char*) this->msg);
      memcpy(outbuffer + offset, &length_msg, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_msg;
      memcpy(&length_msg, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
     return offset;
    }

    const char * getType(){ return SIMPLESERVICE_MYSERVICE_ECHO; };
    const char * getMD5(){ return "7d96ed730776804754140b85e64c862e"; };

  };

  class SimpleService_MyService_echoResponse : public ros::Msg
  {
    public:
      char * operation_return;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_operation_return = strlen( (const char*) this->operation_return);
      memcpy(outbuffer + offset, &length_operation_return, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->operation_return, length_operation_return);
      offset += length_operation_return;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_operation_return;
      memcpy(&length_operation_return, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_operation_return; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_operation_return-1]=0;
      this->operation_return = (char *)(inbuffer + offset-1);
      offset += length_operation_return;
     return offset;
    }

    const char * getType(){ return SIMPLESERVICE_MYSERVICE_ECHO; };
    const char * getMD5(){ return "9980e5392bd797d3f020d187344611a8"; };

  };

  class SimpleService_MyService_echo {
    public:
    typedef SimpleService_MyService_echoRequest Request;
    typedef SimpleService_MyService_echoResponse Response;
  };

}
#endif

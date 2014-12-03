#ifndef _ROS_SERVICE_RegisterActionServer_h
#define _ROS_SERVICE_RegisterActionServer_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace action_server
{

static const char REGISTERACTIONSERVER[] = "action_server/RegisterActionServer";

  class RegisterActionServerRequest : public ros::Msg
  {
    public:
      char * add_action_service;
      char * get_action_state_service;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_add_action_service = strlen( (const char*) this->add_action_service);
      memcpy(outbuffer + offset, &length_add_action_service, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->add_action_service, length_add_action_service);
      offset += length_add_action_service;
      uint32_t length_get_action_state_service = strlen( (const char*) this->get_action_state_service);
      memcpy(outbuffer + offset, &length_get_action_state_service, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->get_action_state_service, length_get_action_state_service);
      offset += length_get_action_state_service;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_add_action_service;
      memcpy(&length_add_action_service, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_add_action_service; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_add_action_service-1]=0;
      this->add_action_service = (char *)(inbuffer + offset-1);
      offset += length_add_action_service;
      uint32_t length_get_action_state_service;
      memcpy(&length_get_action_state_service, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_get_action_state_service; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_get_action_state_service-1]=0;
      this->get_action_state_service = (char *)(inbuffer + offset-1);
      offset += length_get_action_state_service;
     return offset;
    }

    const char * getType(){ return REGISTERACTIONSERVER; };
    const char * getMD5(){ return "57a828c120919d3e187a9c63ce95295a"; };

  };

  class RegisterActionServerResponse : public ros::Msg
  {
    public:
      char * error_msg;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_error_msg = strlen( (const char*) this->error_msg);
      memcpy(outbuffer + offset, &length_error_msg, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error_msg, length_error_msg);
      offset += length_error_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_error_msg;
      memcpy(&length_error_msg, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_msg-1]=0;
      this->error_msg = (char *)(inbuffer + offset-1);
      offset += length_error_msg;
     return offset;
    }

    const char * getType(){ return REGISTERACTIONSERVER; };
    const char * getMD5(){ return "dc7944078245572d6aec14dd790dcbca"; };

  };

  class RegisterActionServer {
    public:
    typedef RegisterActionServerRequest Request;
    typedef RegisterActionServerResponse Response;
  };

}
#endif

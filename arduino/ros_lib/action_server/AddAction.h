#ifndef _ROS_SERVICE_AddAction_h
#define _ROS_SERVICE_AddAction_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace action_server
{

static const char ADDACTION[] = "action_server/AddAction";

  class AddActionRequest : public ros::Msg
  {
    public:
      char * action;
      char * parameters;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_action = strlen( (const char*) this->action);
      memcpy(outbuffer + offset, &length_action, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->action, length_action);
      offset += length_action;
      uint32_t length_parameters = strlen( (const char*) this->parameters);
      memcpy(outbuffer + offset, &length_parameters, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->parameters, length_parameters);
      offset += length_parameters;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_action;
      memcpy(&length_action, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_action; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_action-1]=0;
      this->action = (char *)(inbuffer + offset-1);
      offset += length_action;
      uint32_t length_parameters;
      memcpy(&length_parameters, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parameters; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parameters-1]=0;
      this->parameters = (char *)(inbuffer + offset-1);
      offset += length_parameters;
     return offset;
    }

    const char * getType(){ return ADDACTION; };
    const char * getMD5(){ return "fd5ccd5ad7450f157416bc6ed7b43727"; };

  };

  class AddActionResponse : public ros::Msg
  {
    public:
      char * action_uuid;
      char * error_msg;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_action_uuid = strlen( (const char*) this->action_uuid);
      memcpy(outbuffer + offset, &length_action_uuid, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->action_uuid, length_action_uuid);
      offset += length_action_uuid;
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
      uint32_t length_action_uuid;
      memcpy(&length_action_uuid, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_action_uuid; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_action_uuid-1]=0;
      this->action_uuid = (char *)(inbuffer + offset-1);
      offset += length_action_uuid;
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

    const char * getType(){ return ADDACTION; };
    const char * getMD5(){ return "062ab54044e0818da5a625d2f14582eb"; };

  };

  class AddAction {
    public:
    typedef AddActionRequest Request;
    typedef AddActionResponse Response;
  };

}
#endif

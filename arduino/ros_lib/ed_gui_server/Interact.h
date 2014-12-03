#ifndef _ROS_SERVICE_Interact_h
#define _ROS_SERVICE_Interact_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ed_gui_server
{

static const char INTERACT[] = "ed_gui_server/Interact";

  class InteractRequest : public ros::Msg
  {
    public:
      char * command_yaml;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_command_yaml = strlen( (const char*) this->command_yaml);
      memcpy(outbuffer + offset, &length_command_yaml, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->command_yaml, length_command_yaml);
      offset += length_command_yaml;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_command_yaml;
      memcpy(&length_command_yaml, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command_yaml; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command_yaml-1]=0;
      this->command_yaml = (char *)(inbuffer + offset-1);
      offset += length_command_yaml;
     return offset;
    }

    const char * getType(){ return INTERACT; };
    const char * getMD5(){ return "42edac8bcfbcc53f97d46d70547b0088"; };

  };

  class InteractResponse : public ros::Msg
  {
    public:
      char * result_json;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_result_json = strlen( (const char*) this->result_json);
      memcpy(outbuffer + offset, &length_result_json, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->result_json, length_result_json);
      offset += length_result_json;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_result_json;
      memcpy(&length_result_json, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_result_json; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_result_json-1]=0;
      this->result_json = (char *)(inbuffer + offset-1);
      offset += length_result_json;
     return offset;
    }

    const char * getType(){ return INTERACT; };
    const char * getMD5(){ return "5a270255316571644fcef65cddfbac78"; };

  };

  class Interact {
    public:
    typedef InteractRequest Request;
    typedef InteractResponse Response;
  };

}
#endif

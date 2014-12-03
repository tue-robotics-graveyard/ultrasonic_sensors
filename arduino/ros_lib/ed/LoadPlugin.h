#ifndef _ROS_SERVICE_LoadPlugin_h
#define _ROS_SERVICE_LoadPlugin_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ed
{

static const char LOADPLUGIN[] = "ed/LoadPlugin";

  class LoadPluginRequest : public ros::Msg
  {
    public:
      char * plugin_name;
      char * library_path;
      char * configuration;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_plugin_name = strlen( (const char*) this->plugin_name);
      memcpy(outbuffer + offset, &length_plugin_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->plugin_name, length_plugin_name);
      offset += length_plugin_name;
      uint32_t length_library_path = strlen( (const char*) this->library_path);
      memcpy(outbuffer + offset, &length_library_path, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->library_path, length_library_path);
      offset += length_library_path;
      uint32_t length_configuration = strlen( (const char*) this->configuration);
      memcpy(outbuffer + offset, &length_configuration, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->configuration, length_configuration);
      offset += length_configuration;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_plugin_name;
      memcpy(&length_plugin_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_plugin_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_plugin_name-1]=0;
      this->plugin_name = (char *)(inbuffer + offset-1);
      offset += length_plugin_name;
      uint32_t length_library_path;
      memcpy(&length_library_path, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_library_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_library_path-1]=0;
      this->library_path = (char *)(inbuffer + offset-1);
      offset += length_library_path;
      uint32_t length_configuration;
      memcpy(&length_configuration, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_configuration; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_configuration-1]=0;
      this->configuration = (char *)(inbuffer + offset-1);
      offset += length_configuration;
     return offset;
    }

    const char * getType(){ return LOADPLUGIN; };
    const char * getMD5(){ return "4e60f9c47515c75a12ea883132491e2e"; };

  };

  class LoadPluginResponse : public ros::Msg
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

    const char * getType(){ return LOADPLUGIN; };
    const char * getMD5(){ return "dc7944078245572d6aec14dd790dcbca"; };

  };

  class LoadPlugin {
    public:
    typedef LoadPluginRequest Request;
    typedef LoadPluginResponse Response;
  };

}
#endif

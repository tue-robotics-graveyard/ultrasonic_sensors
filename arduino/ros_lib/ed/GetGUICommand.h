#ifndef _ROS_SERVICE_GetGUICommand_h
#define _ROS_SERVICE_GetGUICommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace ed
{

static const char GETGUICOMMAND[] = "ed/GetGUICommand";

  class GetGUICommandRequest : public ros::Msg
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

    const char * getType(){ return GETGUICOMMAND; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetGUICommandResponse : public ros::Msg
  {
    public:
      char * command_id;
      ros::Duration age;
      char * command;
      uint8_t param_names_length;
      char* st_param_names;
      char* * param_names;
      uint8_t param_values_length;
      char* st_param_values;
      char* * param_values;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_command_id = strlen( (const char*) this->command_id);
      memcpy(outbuffer + offset, &length_command_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->command_id, length_command_id);
      offset += length_command_id;
      *(outbuffer + offset + 0) = (this->age.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->age.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->age.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->age.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->age.sec);
      *(outbuffer + offset + 0) = (this->age.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->age.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->age.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->age.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->age.nsec);
      uint32_t length_command = strlen( (const char*) this->command);
      memcpy(outbuffer + offset, &length_command, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->command, length_command);
      offset += length_command;
      *(outbuffer + offset++) = param_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < param_names_length; i++){
      uint32_t length_param_namesi = strlen( (const char*) this->param_names[i]);
      memcpy(outbuffer + offset, &length_param_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->param_names[i], length_param_namesi);
      offset += length_param_namesi;
      }
      *(outbuffer + offset++) = param_values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < param_values_length; i++){
      uint32_t length_param_valuesi = strlen( (const char*) this->param_values[i]);
      memcpy(outbuffer + offset, &length_param_valuesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->param_values[i], length_param_valuesi);
      offset += length_param_valuesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_command_id;
      memcpy(&length_command_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command_id-1]=0;
      this->command_id = (char *)(inbuffer + offset-1);
      offset += length_command_id;
      this->age.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->age.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->age.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->age.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->age.sec);
      this->age.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->age.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->age.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->age.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->age.nsec);
      uint32_t length_command;
      memcpy(&length_command, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command-1]=0;
      this->command = (char *)(inbuffer + offset-1);
      offset += length_command;
      uint8_t param_names_lengthT = *(inbuffer + offset++);
      if(param_names_lengthT > param_names_length)
        this->param_names = (char**)realloc(this->param_names, param_names_lengthT * sizeof(char*));
      offset += 3;
      param_names_length = param_names_lengthT;
      for( uint8_t i = 0; i < param_names_length; i++){
      uint32_t length_st_param_names;
      memcpy(&length_st_param_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_param_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_param_names-1]=0;
      this->st_param_names = (char *)(inbuffer + offset-1);
      offset += length_st_param_names;
        memcpy( &(this->param_names[i]), &(this->st_param_names), sizeof(char*));
      }
      uint8_t param_values_lengthT = *(inbuffer + offset++);
      if(param_values_lengthT > param_values_length)
        this->param_values = (char**)realloc(this->param_values, param_values_lengthT * sizeof(char*));
      offset += 3;
      param_values_length = param_values_lengthT;
      for( uint8_t i = 0; i < param_values_length; i++){
      uint32_t length_st_param_values;
      memcpy(&length_st_param_values, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_param_values; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_param_values-1]=0;
      this->st_param_values = (char *)(inbuffer + offset-1);
      offset += length_st_param_values;
        memcpy( &(this->param_values[i]), &(this->st_param_values), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETGUICOMMAND; };
    const char * getMD5(){ return "df9f6b069d024a65feb2b6ec9923c0d4"; };

  };

  class GetGUICommand {
    public:
    typedef GetGUICommandRequest Request;
    typedef GetGUICommandResponse Response;
  };

}
#endif

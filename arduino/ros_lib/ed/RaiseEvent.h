#ifndef _ROS_SERVICE_RaiseEvent_h
#define _ROS_SERVICE_RaiseEvent_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ed
{

static const char RAISEEVENT[] = "ed/RaiseEvent";

  class RaiseEventRequest : public ros::Msg
  {
    public:
      char * name;
      uint8_t param_names_length;
      char* st_param_names;
      char* * param_names;
      uint8_t param_values_length;
      char* st_param_values;
      char* * param_values;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
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
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
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

    const char * getType(){ return RAISEEVENT; };
    const char * getMD5(){ return "9689a83c89c6b73a47741b6111b99518"; };

  };

  class RaiseEventResponse : public ros::Msg
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

    const char * getType(){ return RAISEEVENT; };
    const char * getMD5(){ return "7d96ed730776804754140b85e64c862e"; };

  };

  class RaiseEvent {
    public:
    typedef RaiseEventRequest Request;
    typedef RaiseEventResponse Response;
  };

}
#endif

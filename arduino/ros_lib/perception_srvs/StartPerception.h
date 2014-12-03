#ifndef _ROS_SERVICE_StartPerception_h
#define _ROS_SERVICE_StartPerception_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace perception_srvs
{

static const char STARTPERCEPTION[] = "perception_srvs/StartPerception";

  class StartPerceptionRequest : public ros::Msg
  {
    public:
      uint8_t modules_length;
      char* st_modules;
      char* * modules;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = modules_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < modules_length; i++){
      uint32_t length_modulesi = strlen( (const char*) this->modules[i]);
      memcpy(outbuffer + offset, &length_modulesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->modules[i], length_modulesi);
      offset += length_modulesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t modules_lengthT = *(inbuffer + offset++);
      if(modules_lengthT > modules_length)
        this->modules = (char**)realloc(this->modules, modules_lengthT * sizeof(char*));
      offset += 3;
      modules_length = modules_lengthT;
      for( uint8_t i = 0; i < modules_length; i++){
      uint32_t length_st_modules;
      memcpy(&length_st_modules, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_modules; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_modules-1]=0;
      this->st_modules = (char *)(inbuffer + offset-1);
      offset += length_st_modules;
        memcpy( &(this->modules[i]), &(this->st_modules), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return STARTPERCEPTION; };
    const char * getMD5(){ return "c553a0d7cb2ac6d8e15855b335552825"; };

  };

  class StartPerceptionResponse : public ros::Msg
  {
    public:
      uint32_t error_code;
      char * error_msg;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->error_code >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->error_code >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->error_code >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->error_code >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_code);
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
      this->error_code =  ((uint32_t) (*(inbuffer + offset)));
      this->error_code |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->error_code |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->error_code |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->error_code);
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

    const char * getType(){ return STARTPERCEPTION; };
    const char * getMD5(){ return "217153dcade9618aa97e37fd1ee0bc01"; };

  };

  class StartPerception {
    public:
    typedef StartPerceptionRequest Request;
    typedef StartPerceptionResponse Response;
  };

}
#endif

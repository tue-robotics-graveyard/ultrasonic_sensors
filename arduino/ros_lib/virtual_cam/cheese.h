#ifndef _ROS_SERVICE_cheese_h
#define _ROS_SERVICE_cheese_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace virtual_cam
{

static const char CHEESE[] = "virtual_cam/cheese";

  class cheeseRequest : public ros::Msg
  {
    public:
      char * fileName;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_fileName = strlen( (const char*) this->fileName);
      memcpy(outbuffer + offset, &length_fileName, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->fileName, length_fileName);
      offset += length_fileName;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_fileName;
      memcpy(&length_fileName, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_fileName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_fileName-1]=0;
      this->fileName = (char *)(inbuffer + offset-1);
      offset += length_fileName;
     return offset;
    }

    const char * getType(){ return CHEESE; };
    const char * getMD5(){ return "0c96d4662a80949a4927729271153923"; };

  };

  class cheeseResponse : public ros::Msg
  {
    public:
      bool success;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return CHEESE; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class cheese {
    public:
    typedef cheeseRequest Request;
    typedef cheeseResponse Response;
  };

}
#endif

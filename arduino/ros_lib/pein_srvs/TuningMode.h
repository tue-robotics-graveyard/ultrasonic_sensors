#ifndef _ROS_SERVICE_TuningMode_h
#define _ROS_SERVICE_TuningMode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pein_srvs
{

static const char TUNINGMODE[] = "pein_srvs/TuningMode";

  class TuningModeRequest : public ros::Msg
  {
    public:
      char * object_class;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_object_class = strlen( (const char*) this->object_class);
      memcpy(outbuffer + offset, &length_object_class, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->object_class, length_object_class);
      offset += length_object_class;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_object_class;
      memcpy(&length_object_class, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_class; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_class-1]=0;
      this->object_class = (char *)(inbuffer + offset-1);
      offset += length_object_class;
     return offset;
    }

    const char * getType(){ return TUNINGMODE; };
    const char * getMD5(){ return "389886f9c8c47a5d896d81d7b7728dc7"; };

  };

  class TuningModeResponse : public ros::Msg
  {
    public:
      bool result;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return TUNINGMODE; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class TuningMode {
    public:
    typedef TuningModeRequest Request;
    typedef TuningModeResponse Response;
  };

}
#endif

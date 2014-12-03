#ifndef _ROS_SERVICE_GetInfo_h
#define _ROS_SERVICE_GetInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace speech_interpreter
{

static const char GETINFO[] = "speech_interpreter/GetInfo";

  class GetInfoRequest : public ros::Msg
  {
    public:
      char * type;
      uint32_t n_tries;
      float time_out;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type = strlen( (const char*) this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset + 0) = (this->n_tries >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->n_tries >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->n_tries >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->n_tries >> (8 * 3)) & 0xFF;
      offset += sizeof(this->n_tries);
      union {
        float real;
        uint32_t base;
      } u_time_out;
      u_time_out.real = this->time_out;
      *(outbuffer + offset + 0) = (u_time_out.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_out.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_out.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_out.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_out);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      this->n_tries =  ((uint32_t) (*(inbuffer + offset)));
      this->n_tries |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->n_tries |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->n_tries |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->n_tries);
      union {
        float real;
        uint32_t base;
      } u_time_out;
      u_time_out.base = 0;
      u_time_out.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_out.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_out.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_out.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time_out = u_time_out.real;
      offset += sizeof(this->time_out);
     return offset;
    }

    const char * getType(){ return GETINFO; };
    const char * getMD5(){ return "26b23336240655cee687344779605b27"; };

  };

  class GetInfoResponse : public ros::Msg
  {
    public:
      char * answer;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_answer = strlen( (const char*) this->answer);
      memcpy(outbuffer + offset, &length_answer, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->answer, length_answer);
      offset += length_answer;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_answer;
      memcpy(&length_answer, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_answer; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_answer-1]=0;
      this->answer = (char *)(inbuffer + offset-1);
      offset += length_answer;
     return offset;
    }

    const char * getType(){ return GETINFO; };
    const char * getMD5(){ return "d7e708f879c94bb931716d8f4f130f30"; };

  };

  class GetInfo {
    public:
    typedef GetInfoRequest Request;
    typedef GetInfoResponse Response;
  };

}
#endif

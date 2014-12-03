#ifndef _ROS_SERVICE_GetStatus_h
#define _ROS_SERVICE_GetStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace text_to_speech
{

static const char GETSTATUS[] = "text_to_speech/GetStatus";

  class GetStatusRequest : public ros::Msg
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

    const char * getType(){ return GETSTATUS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetStatusResponse : public ros::Msg
  {
    public:
      uint8_t sentence_buffer_length;
      char* st_sentence_buffer;
      char* * sentence_buffer;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = sentence_buffer_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sentence_buffer_length; i++){
      uint32_t length_sentence_bufferi = strlen( (const char*) this->sentence_buffer[i]);
      memcpy(outbuffer + offset, &length_sentence_bufferi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->sentence_buffer[i], length_sentence_bufferi);
      offset += length_sentence_bufferi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t sentence_buffer_lengthT = *(inbuffer + offset++);
      if(sentence_buffer_lengthT > sentence_buffer_length)
        this->sentence_buffer = (char**)realloc(this->sentence_buffer, sentence_buffer_lengthT * sizeof(char*));
      offset += 3;
      sentence_buffer_length = sentence_buffer_lengthT;
      for( uint8_t i = 0; i < sentence_buffer_length; i++){
      uint32_t length_st_sentence_buffer;
      memcpy(&length_st_sentence_buffer, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_sentence_buffer; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_sentence_buffer-1]=0;
      this->st_sentence_buffer = (char *)(inbuffer + offset-1);
      offset += length_st_sentence_buffer;
        memcpy( &(this->sentence_buffer[i]), &(this->st_sentence_buffer), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETSTATUS; };
    const char * getMD5(){ return "530ef67b61152300c931c569e4fa1d09"; };

  };

  class GetStatus {
    public:
    typedef GetStatusRequest Request;
    typedef GetStatusResponse Response;
  };

}
#endif

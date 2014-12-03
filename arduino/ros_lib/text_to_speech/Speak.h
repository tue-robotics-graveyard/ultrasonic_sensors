#ifndef _ROS_SERVICE_Speak_h
#define _ROS_SERVICE_Speak_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace text_to_speech
{

static const char SPEAK[] = "text_to_speech/Speak";

  class SpeakRequest : public ros::Msg
  {
    public:
      char * language;
      char * voice;
      char * character;
      char * emotion;
      char * sentence;
      bool blocking_call;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_language = strlen( (const char*) this->language);
      memcpy(outbuffer + offset, &length_language, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->language, length_language);
      offset += length_language;
      uint32_t length_voice = strlen( (const char*) this->voice);
      memcpy(outbuffer + offset, &length_voice, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->voice, length_voice);
      offset += length_voice;
      uint32_t length_character = strlen( (const char*) this->character);
      memcpy(outbuffer + offset, &length_character, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->character, length_character);
      offset += length_character;
      uint32_t length_emotion = strlen( (const char*) this->emotion);
      memcpy(outbuffer + offset, &length_emotion, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->emotion, length_emotion);
      offset += length_emotion;
      uint32_t length_sentence = strlen( (const char*) this->sentence);
      memcpy(outbuffer + offset, &length_sentence, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->sentence, length_sentence);
      offset += length_sentence;
      union {
        bool real;
        uint8_t base;
      } u_blocking_call;
      u_blocking_call.real = this->blocking_call;
      *(outbuffer + offset + 0) = (u_blocking_call.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->blocking_call);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_language;
      memcpy(&length_language, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_language; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_language-1]=0;
      this->language = (char *)(inbuffer + offset-1);
      offset += length_language;
      uint32_t length_voice;
      memcpy(&length_voice, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_voice; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_voice-1]=0;
      this->voice = (char *)(inbuffer + offset-1);
      offset += length_voice;
      uint32_t length_character;
      memcpy(&length_character, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_character; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_character-1]=0;
      this->character = (char *)(inbuffer + offset-1);
      offset += length_character;
      uint32_t length_emotion;
      memcpy(&length_emotion, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_emotion; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_emotion-1]=0;
      this->emotion = (char *)(inbuffer + offset-1);
      offset += length_emotion;
      uint32_t length_sentence;
      memcpy(&length_sentence, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sentence; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sentence-1]=0;
      this->sentence = (char *)(inbuffer + offset-1);
      offset += length_sentence;
      union {
        bool real;
        uint8_t base;
      } u_blocking_call;
      u_blocking_call.base = 0;
      u_blocking_call.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->blocking_call = u_blocking_call.real;
      offset += sizeof(this->blocking_call);
     return offset;
    }

    const char * getType(){ return SPEAK; };
    const char * getMD5(){ return "03a1552599365af1d269cce849321984"; };

  };

  class SpeakResponse : public ros::Msg
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

    const char * getType(){ return SPEAK; };
    const char * getMD5(){ return "dc7944078245572d6aec14dd790dcbca"; };

  };

  class Speak {
    public:
    typedef SpeakRequest Request;
    typedef SpeakResponse Response;
  };

}
#endif

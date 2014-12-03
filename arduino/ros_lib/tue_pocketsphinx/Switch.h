#ifndef _ROS_SERVICE_Switch_h
#define _ROS_SERVICE_Switch_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tue_pocketsphinx
{

static const char SWITCH[] = "tue_pocketsphinx/Switch";

  class SwitchRequest : public ros::Msg
  {
    public:
      uint8_t action;
      char * hidden_markov_model;
      char * language_model;
      char * dictionary;
      char * finite_state_grammer;
      enum { START = 0 };
      enum { STOP = 1 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->action >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      uint32_t length_hidden_markov_model = strlen( (const char*) this->hidden_markov_model);
      memcpy(outbuffer + offset, &length_hidden_markov_model, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->hidden_markov_model, length_hidden_markov_model);
      offset += length_hidden_markov_model;
      uint32_t length_language_model = strlen( (const char*) this->language_model);
      memcpy(outbuffer + offset, &length_language_model, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->language_model, length_language_model);
      offset += length_language_model;
      uint32_t length_dictionary = strlen( (const char*) this->dictionary);
      memcpy(outbuffer + offset, &length_dictionary, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->dictionary, length_dictionary);
      offset += length_dictionary;
      uint32_t length_finite_state_grammer = strlen( (const char*) this->finite_state_grammer);
      memcpy(outbuffer + offset, &length_finite_state_grammer, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->finite_state_grammer, length_finite_state_grammer);
      offset += length_finite_state_grammer;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->action =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->action);
      uint32_t length_hidden_markov_model;
      memcpy(&length_hidden_markov_model, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hidden_markov_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hidden_markov_model-1]=0;
      this->hidden_markov_model = (char *)(inbuffer + offset-1);
      offset += length_hidden_markov_model;
      uint32_t length_language_model;
      memcpy(&length_language_model, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_language_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_language_model-1]=0;
      this->language_model = (char *)(inbuffer + offset-1);
      offset += length_language_model;
      uint32_t length_dictionary;
      memcpy(&length_dictionary, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_dictionary; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_dictionary-1]=0;
      this->dictionary = (char *)(inbuffer + offset-1);
      offset += length_dictionary;
      uint32_t length_finite_state_grammer;
      memcpy(&length_finite_state_grammer, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_finite_state_grammer; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_finite_state_grammer-1]=0;
      this->finite_state_grammer = (char *)(inbuffer + offset-1);
      offset += length_finite_state_grammer;
     return offset;
    }

    const char * getType(){ return SWITCH; };
    const char * getMD5(){ return "9175f1c669cb3312c0a399d961eb367a"; };

  };

  class SwitchResponse : public ros::Msg
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

    const char * getType(){ return SWITCH; };
    const char * getMD5(){ return "dc7944078245572d6aec14dd790dcbca"; };

  };

  class Switch {
    public:
    typedef SwitchRequest Request;
    typedef SwitchResponse Response;
  };

}
#endif

#ifndef _ROS_SERVICE_StartStop_h
#define _ROS_SERVICE_StartStop_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pein_srvs
{

static const char STARTSTOP[] = "pein_srvs/StartStop";

  class StartStopRequest : public ros::Msg
  {
    public:
      uint8_t key_length;
      char* st_key;
      char* * key;
      uint8_t value_length;
      char* st_value;
      char* * value;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = key_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < key_length; i++){
      uint32_t length_keyi = strlen( (const char*) this->key[i]);
      memcpy(outbuffer + offset, &length_keyi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->key[i], length_keyi);
      offset += length_keyi;
      }
      *(outbuffer + offset++) = value_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < value_length; i++){
      uint32_t length_valuei = strlen( (const char*) this->value[i]);
      memcpy(outbuffer + offset, &length_valuei, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->value[i], length_valuei);
      offset += length_valuei;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t key_lengthT = *(inbuffer + offset++);
      if(key_lengthT > key_length)
        this->key = (char**)realloc(this->key, key_lengthT * sizeof(char*));
      offset += 3;
      key_length = key_lengthT;
      for( uint8_t i = 0; i < key_length; i++){
      uint32_t length_st_key;
      memcpy(&length_st_key, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_key; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_key-1]=0;
      this->st_key = (char *)(inbuffer + offset-1);
      offset += length_st_key;
        memcpy( &(this->key[i]), &(this->st_key), sizeof(char*));
      }
      uint8_t value_lengthT = *(inbuffer + offset++);
      if(value_lengthT > value_length)
        this->value = (char**)realloc(this->value, value_lengthT * sizeof(char*));
      offset += 3;
      value_length = value_lengthT;
      for( uint8_t i = 0; i < value_length; i++){
      uint32_t length_st_value;
      memcpy(&length_st_value, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_value-1]=0;
      this->st_value = (char *)(inbuffer + offset-1);
      offset += length_st_value;
        memcpy( &(this->value[i]), &(this->st_value), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return STARTSTOP; };
    const char * getMD5(){ return "a45191f453ccd205b982fe45727b9c67"; };

  };

  class StartStopResponse : public ros::Msg
  {
    public:
      char * message;
      uint16_t error;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_message = strlen( (const char*) this->message);
      memcpy(outbuffer + offset, &length_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      *(outbuffer + offset + 0) = (this->error >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->error >> (8 * 1)) & 0xFF;
      offset += sizeof(this->error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_message;
      memcpy(&length_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      this->error =  ((uint16_t) (*(inbuffer + offset)));
      this->error |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->error);
     return offset;
    }

    const char * getType(){ return STARTSTOP; };
    const char * getMD5(){ return "5f589f325811b16c628c3b6a563ebf9c"; };

  };

  class StartStop {
    public:
    typedef StartStopRequest Request;
    typedef StartStopResponse Response;
  };

}
#endif

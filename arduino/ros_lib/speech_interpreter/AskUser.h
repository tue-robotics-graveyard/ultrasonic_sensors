#ifndef _ROS_SERVICE_AskUser_h
#define _ROS_SERVICE_AskUser_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace speech_interpreter
{

static const char ASKUSER[] = "speech_interpreter/AskUser";

  class AskUserRequest : public ros::Msg
  {
    public:
      char * info_type;
      uint32_t num_tries;
      ros::Duration time_out;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_info_type = strlen( (const char*) this->info_type);
      memcpy(outbuffer + offset, &length_info_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->info_type, length_info_type);
      offset += length_info_type;
      *(outbuffer + offset + 0) = (this->num_tries >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_tries >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_tries >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_tries >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_tries);
      *(outbuffer + offset + 0) = (this->time_out.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_out.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_out.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_out.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_out.sec);
      *(outbuffer + offset + 0) = (this->time_out.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_out.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_out.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_out.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_out.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_info_type;
      memcpy(&length_info_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info_type-1]=0;
      this->info_type = (char *)(inbuffer + offset-1);
      offset += length_info_type;
      this->num_tries =  ((uint32_t) (*(inbuffer + offset)));
      this->num_tries |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_tries |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_tries |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_tries);
      this->time_out.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_out.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_out.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_out.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_out.sec);
      this->time_out.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_out.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_out.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_out.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_out.nsec);
     return offset;
    }

    const char * getType(){ return ASKUSER; };
    const char * getMD5(){ return "19d7337144bc4ee1634421257aaeb002"; };

  };

  class AskUserResponse : public ros::Msg
  {
    public:
      uint8_t keys_length;
      char* st_keys;
      char* * keys;
      uint8_t values_length;
      char* st_values;
      char* * values;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = keys_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < keys_length; i++){
      uint32_t length_keysi = strlen( (const char*) this->keys[i]);
      memcpy(outbuffer + offset, &length_keysi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->keys[i], length_keysi);
      offset += length_keysi;
      }
      *(outbuffer + offset++) = values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < values_length; i++){
      uint32_t length_valuesi = strlen( (const char*) this->values[i]);
      memcpy(outbuffer + offset, &length_valuesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->values[i], length_valuesi);
      offset += length_valuesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t keys_lengthT = *(inbuffer + offset++);
      if(keys_lengthT > keys_length)
        this->keys = (char**)realloc(this->keys, keys_lengthT * sizeof(char*));
      offset += 3;
      keys_length = keys_lengthT;
      for( uint8_t i = 0; i < keys_length; i++){
      uint32_t length_st_keys;
      memcpy(&length_st_keys, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_keys; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_keys-1]=0;
      this->st_keys = (char *)(inbuffer + offset-1);
      offset += length_st_keys;
        memcpy( &(this->keys[i]), &(this->st_keys), sizeof(char*));
      }
      uint8_t values_lengthT = *(inbuffer + offset++);
      if(values_lengthT > values_length)
        this->values = (char**)realloc(this->values, values_lengthT * sizeof(char*));
      offset += 3;
      values_length = values_lengthT;
      for( uint8_t i = 0; i < values_length; i++){
      uint32_t length_st_values;
      memcpy(&length_st_values, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_values; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_values-1]=0;
      this->st_values = (char *)(inbuffer + offset-1);
      offset += length_st_values;
        memcpy( &(this->values[i]), &(this->st_values), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return ASKUSER; };
    const char * getMD5(){ return "8dcfc845da12061fdc33c889527f840c"; };

  };

  class AskUser {
    public:
    typedef AskUserRequest Request;
    typedef AskUserResponse Response;
  };

}
#endif

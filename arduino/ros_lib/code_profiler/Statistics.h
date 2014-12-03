#ifndef _ROS_code_profiler_Statistics_h
#define _ROS_code_profiler_Statistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace code_profiler
{

  class Statistics : public ros::Msg
  {
    public:
      uint8_t labels_length;
      char* st_labels;
      char* * labels;
      uint8_t time_secs_length;
      float st_time_secs;
      float * time_secs;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = labels_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < labels_length; i++){
      uint32_t length_labelsi = strlen( (const char*) this->labels[i]);
      memcpy(outbuffer + offset, &length_labelsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->labels[i], length_labelsi);
      offset += length_labelsi;
      }
      *(outbuffer + offset++) = time_secs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < time_secs_length; i++){
      int32_t * val_time_secsi = (int32_t *) &(this->time_secs[i]);
      int32_t exp_time_secsi = (((*val_time_secsi)>>23)&255);
      if(exp_time_secsi != 0)
        exp_time_secsi += 1023-127;
      int32_t sig_time_secsi = *val_time_secsi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_time_secsi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_time_secsi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_time_secsi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_time_secsi<<4) & 0xF0) | ((sig_time_secsi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_time_secsi>>4) & 0x7F;
      if(this->time_secs[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t labels_lengthT = *(inbuffer + offset++);
      if(labels_lengthT > labels_length)
        this->labels = (char**)realloc(this->labels, labels_lengthT * sizeof(char*));
      offset += 3;
      labels_length = labels_lengthT;
      for( uint8_t i = 0; i < labels_length; i++){
      uint32_t length_st_labels;
      memcpy(&length_st_labels, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_labels; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_labels-1]=0;
      this->st_labels = (char *)(inbuffer + offset-1);
      offset += length_st_labels;
        memcpy( &(this->labels[i]), &(this->st_labels), sizeof(char*));
      }
      uint8_t time_secs_lengthT = *(inbuffer + offset++);
      if(time_secs_lengthT > time_secs_length)
        this->time_secs = (float*)realloc(this->time_secs, time_secs_lengthT * sizeof(float));
      offset += 3;
      time_secs_length = time_secs_lengthT;
      for( uint8_t i = 0; i < time_secs_length; i++){
      uint32_t * val_st_time_secs = (uint32_t*) &(this->st_time_secs);
      offset += 3;
      *val_st_time_secs = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_time_secs |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_time_secs |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_time_secs |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_time_secs = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_time_secs |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_time_secs !=0)
        *val_st_time_secs |= ((exp_st_time_secs)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_time_secs = -this->st_time_secs;
        memcpy( &(this->time_secs[i]), &(this->st_time_secs), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "code_profiler/Statistics"; };
    const char * getMD5(){ return "f82690d7bf363b63d831466f71645dc4"; };

  };

}
#endif
#ifndef _ROS_tue_recorder_Start_h
#define _ROS_tue_recorder_Start_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace tue_recorder
{

  class Start : public ros::Msg
  {
    public:
      char * id;
      char * type;
      char * source;
      char * context;
      ros::Duration max_duration;
      float frequency;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen( (const char*) this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      uint32_t length_type = strlen( (const char*) this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      uint32_t length_source = strlen( (const char*) this->source);
      memcpy(outbuffer + offset, &length_source, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->source, length_source);
      offset += length_source;
      uint32_t length_context = strlen( (const char*) this->context);
      memcpy(outbuffer + offset, &length_context, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->context, length_context);
      offset += length_context;
      *(outbuffer + offset + 0) = (this->max_duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_duration.sec);
      *(outbuffer + offset + 0) = (this->max_duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_duration.nsec);
      int32_t * val_frequency = (int32_t *) &(this->frequency);
      int32_t exp_frequency = (((*val_frequency)>>23)&255);
      if(exp_frequency != 0)
        exp_frequency += 1023-127;
      int32_t sig_frequency = *val_frequency;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_frequency<<5) & 0xff;
      *(outbuffer + offset++) = (sig_frequency>>3) & 0xff;
      *(outbuffer + offset++) = (sig_frequency>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_frequency<<4) & 0xF0) | ((sig_frequency>>19)&0x0F);
      *(outbuffer + offset++) = (exp_frequency>>4) & 0x7F;
      if(this->frequency < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint32_t length_source;
      memcpy(&length_source, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source-1]=0;
      this->source = (char *)(inbuffer + offset-1);
      offset += length_source;
      uint32_t length_context;
      memcpy(&length_context, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_context; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_context-1]=0;
      this->context = (char *)(inbuffer + offset-1);
      offset += length_context;
      this->max_duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->max_duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_duration.sec);
      this->max_duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->max_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_duration.nsec);
      uint32_t * val_frequency = (uint32_t*) &(this->frequency);
      offset += 3;
      *val_frequency = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_frequency |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_frequency |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_frequency |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_frequency = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_frequency |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_frequency !=0)
        *val_frequency |= ((exp_frequency)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->frequency = -this->frequency;
     return offset;
    }

    const char * getType(){ return "tue_recorder/Start"; };
    const char * getMD5(){ return "deebacac301f12f79e38453151355342"; };

  };

}
#endif
#ifndef _ROS_pein_msgs_Hypothesis_h
#define _ROS_pein_msgs_Hypothesis_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pein_msgs
{

  class Hypothesis : public ros::Msg
  {
    public:
      char * object_name;
      char * category;
      float probability;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_object_name = strlen( (const char*) this->object_name);
      memcpy(outbuffer + offset, &length_object_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->object_name, length_object_name);
      offset += length_object_name;
      uint32_t length_category = strlen( (const char*) this->category);
      memcpy(outbuffer + offset, &length_category, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->category, length_category);
      offset += length_category;
      int32_t * val_probability = (int32_t *) &(this->probability);
      int32_t exp_probability = (((*val_probability)>>23)&255);
      if(exp_probability != 0)
        exp_probability += 1023-127;
      int32_t sig_probability = *val_probability;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_probability<<5) & 0xff;
      *(outbuffer + offset++) = (sig_probability>>3) & 0xff;
      *(outbuffer + offset++) = (sig_probability>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_probability<<4) & 0xF0) | ((sig_probability>>19)&0x0F);
      *(outbuffer + offset++) = (exp_probability>>4) & 0x7F;
      if(this->probability < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_object_name;
      memcpy(&length_object_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_name-1]=0;
      this->object_name = (char *)(inbuffer + offset-1);
      offset += length_object_name;
      uint32_t length_category;
      memcpy(&length_category, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_category; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_category-1]=0;
      this->category = (char *)(inbuffer + offset-1);
      offset += length_category;
      uint32_t * val_probability = (uint32_t*) &(this->probability);
      offset += 3;
      *val_probability = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_probability |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_probability |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_probability |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_probability = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_probability |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_probability !=0)
        *val_probability |= ((exp_probability)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->probability = -this->probability;
     return offset;
    }

    const char * getType(){ return "pein_msgs/Hypothesis"; };
    const char * getMD5(){ return "394d0da9ce6f593705e63ee42d1947de"; };

  };

}
#endif
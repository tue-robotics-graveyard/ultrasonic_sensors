#ifndef _ROS_psi_ConstantMsg_h
#define _ROS_psi_ConstantMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace psi
{

  class ConstantMsg : public ros::Msg
  {
    public:
      uint8_t type;
      char * str;
      float num;
      uint8_t num_array_length;
      float st_num_array;
      float * num_array;
      enum { STRING =  0 };
      enum { NUMBER =  1 };
      enum { NUMBER_ARRAY =  2 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_str = strlen( (const char*) this->str);
      memcpy(outbuffer + offset, &length_str, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->str, length_str);
      offset += length_str;
      int32_t * val_num = (int32_t *) &(this->num);
      int32_t exp_num = (((*val_num)>>23)&255);
      if(exp_num != 0)
        exp_num += 1023-127;
      int32_t sig_num = *val_num;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_num<<5) & 0xff;
      *(outbuffer + offset++) = (sig_num>>3) & 0xff;
      *(outbuffer + offset++) = (sig_num>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_num<<4) & 0xF0) | ((sig_num>>19)&0x0F);
      *(outbuffer + offset++) = (exp_num>>4) & 0x7F;
      if(this->num < 0) *(outbuffer + offset -1) |= 0x80;
      *(outbuffer + offset++) = num_array_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < num_array_length; i++){
      int32_t * val_num_arrayi = (int32_t *) &(this->num_array[i]);
      int32_t exp_num_arrayi = (((*val_num_arrayi)>>23)&255);
      if(exp_num_arrayi != 0)
        exp_num_arrayi += 1023-127;
      int32_t sig_num_arrayi = *val_num_arrayi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_num_arrayi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_num_arrayi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_num_arrayi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_num_arrayi<<4) & 0xF0) | ((sig_num_arrayi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_num_arrayi>>4) & 0x7F;
      if(this->num_array[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t length_str;
      memcpy(&length_str, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_str; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_str-1]=0;
      this->str = (char *)(inbuffer + offset-1);
      offset += length_str;
      uint32_t * val_num = (uint32_t*) &(this->num);
      offset += 3;
      *val_num = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_num |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_num |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_num |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_num = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_num |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_num !=0)
        *val_num |= ((exp_num)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->num = -this->num;
      uint8_t num_array_lengthT = *(inbuffer + offset++);
      if(num_array_lengthT > num_array_length)
        this->num_array = (float*)realloc(this->num_array, num_array_lengthT * sizeof(float));
      offset += 3;
      num_array_length = num_array_lengthT;
      for( uint8_t i = 0; i < num_array_length; i++){
      uint32_t * val_st_num_array = (uint32_t*) &(this->st_num_array);
      offset += 3;
      *val_st_num_array = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_num_array |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_num_array |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_num_array |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_num_array = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_num_array |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_num_array !=0)
        *val_st_num_array |= ((exp_st_num_array)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_num_array = -this->st_num_array;
        memcpy( &(this->num_array[i]), &(this->st_num_array), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "psi/ConstantMsg"; };
    const char * getMD5(){ return "9b3b17f8c0d0ae98301df0dd58bf48db"; };

  };

}
#endif
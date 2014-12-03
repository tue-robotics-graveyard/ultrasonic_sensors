#ifndef _ROS_psi_TermImplMsg_h
#define _ROS_psi_TermImplMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "psi/ConstantMsg.h"

namespace psi
{

  class TermImplMsg : public ros::Msg
  {
    public:
      uint8_t type;
      char * variable;
      psi::ConstantMsg constant;
      uint8_t binary_data_length;
      uint8_t st_binary_data;
      uint8_t * binary_data;
      char * functor;
      uint8_t sub_term_ptrs_length;
      uint32_t st_sub_term_ptrs;
      uint32_t * sub_term_ptrs;
      enum { VARIABLE =  1 };
      enum { CONSTANT =  2 };
      enum { COMPOUND =  3 };
      enum { LIST =  4 };
      enum { BINARY =  5 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_variable = strlen( (const char*) this->variable);
      memcpy(outbuffer + offset, &length_variable, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->variable, length_variable);
      offset += length_variable;
      offset += this->constant.serialize(outbuffer + offset);
      *(outbuffer + offset++) = binary_data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < binary_data_length; i++){
      *(outbuffer + offset + 0) = (this->binary_data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->binary_data[i]);
      }
      uint32_t length_functor = strlen( (const char*) this->functor);
      memcpy(outbuffer + offset, &length_functor, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->functor, length_functor);
      offset += length_functor;
      *(outbuffer + offset++) = sub_term_ptrs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sub_term_ptrs_length; i++){
      *(outbuffer + offset + 0) = (this->sub_term_ptrs[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sub_term_ptrs[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sub_term_ptrs[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sub_term_ptrs[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sub_term_ptrs[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t length_variable;
      memcpy(&length_variable, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_variable; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_variable-1]=0;
      this->variable = (char *)(inbuffer + offset-1);
      offset += length_variable;
      offset += this->constant.deserialize(inbuffer + offset);
      uint8_t binary_data_lengthT = *(inbuffer + offset++);
      if(binary_data_lengthT > binary_data_length)
        this->binary_data = (uint8_t*)realloc(this->binary_data, binary_data_lengthT * sizeof(uint8_t));
      offset += 3;
      binary_data_length = binary_data_lengthT;
      for( uint8_t i = 0; i < binary_data_length; i++){
      this->st_binary_data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_binary_data);
        memcpy( &(this->binary_data[i]), &(this->st_binary_data), sizeof(uint8_t));
      }
      uint32_t length_functor;
      memcpy(&length_functor, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_functor; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_functor-1]=0;
      this->functor = (char *)(inbuffer + offset-1);
      offset += length_functor;
      uint8_t sub_term_ptrs_lengthT = *(inbuffer + offset++);
      if(sub_term_ptrs_lengthT > sub_term_ptrs_length)
        this->sub_term_ptrs = (uint32_t*)realloc(this->sub_term_ptrs, sub_term_ptrs_lengthT * sizeof(uint32_t));
      offset += 3;
      sub_term_ptrs_length = sub_term_ptrs_lengthT;
      for( uint8_t i = 0; i < sub_term_ptrs_length; i++){
      this->st_sub_term_ptrs =  ((uint32_t) (*(inbuffer + offset)));
      this->st_sub_term_ptrs |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_sub_term_ptrs |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_sub_term_ptrs |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_sub_term_ptrs);
        memcpy( &(this->sub_term_ptrs[i]), &(this->st_sub_term_ptrs), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return "psi/TermImplMsg"; };
    const char * getMD5(){ return "b4ccf5dd8fce8507075cd19c0be358b2"; };

  };

}
#endif
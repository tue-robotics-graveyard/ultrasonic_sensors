#ifndef _ROS_psi_TermMsg_h
#define _ROS_psi_TermMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "psi/TermImplMsg.h"

namespace psi
{

  class TermMsg : public ros::Msg
  {
    public:
      char * term_string;
      psi::TermImplMsg root;
      uint8_t sub_terms_length;
      psi::TermImplMsg st_sub_terms;
      psi::TermImplMsg * sub_terms;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_term_string = strlen( (const char*) this->term_string);
      memcpy(outbuffer + offset, &length_term_string, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->term_string, length_term_string);
      offset += length_term_string;
      offset += this->root.serialize(outbuffer + offset);
      *(outbuffer + offset++) = sub_terms_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sub_terms_length; i++){
      offset += this->sub_terms[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_term_string;
      memcpy(&length_term_string, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_term_string; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_term_string-1]=0;
      this->term_string = (char *)(inbuffer + offset-1);
      offset += length_term_string;
      offset += this->root.deserialize(inbuffer + offset);
      uint8_t sub_terms_lengthT = *(inbuffer + offset++);
      if(sub_terms_lengthT > sub_terms_length)
        this->sub_terms = (psi::TermImplMsg*)realloc(this->sub_terms, sub_terms_lengthT * sizeof(psi::TermImplMsg));
      offset += 3;
      sub_terms_length = sub_terms_lengthT;
      for( uint8_t i = 0; i < sub_terms_length; i++){
      offset += this->st_sub_terms.deserialize(inbuffer + offset);
        memcpy( &(this->sub_terms[i]), &(this->st_sub_terms), sizeof(psi::TermImplMsg));
      }
     return offset;
    }

    const char * getType(){ return "psi/TermMsg"; };
    const char * getMD5(){ return "bbd78bb52cc3d5b70db991f95738939e"; };

  };

}
#endif
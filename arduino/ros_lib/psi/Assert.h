#ifndef _ROS_SERVICE_Assert_h
#define _ROS_SERVICE_Assert_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "psi/TermMsg.h"

namespace psi
{

static const char ASSERT[] = "psi/Assert";

  class AssertRequest : public ros::Msg
  {
    public:
      uint8_t action;
      uint8_t facts_length;
      psi::TermMsg st_facts;
      psi::TermMsg * facts;
      enum { ASSERT = 0 };
      enum { ASSERTA = 1 };
      enum { ASSERTZ = 2 };
      enum { RETRACT = 3 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->action >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      *(outbuffer + offset++) = facts_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < facts_length; i++){
      offset += this->facts[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->action =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->action);
      uint8_t facts_lengthT = *(inbuffer + offset++);
      if(facts_lengthT > facts_length)
        this->facts = (psi::TermMsg*)realloc(this->facts, facts_lengthT * sizeof(psi::TermMsg));
      offset += 3;
      facts_length = facts_lengthT;
      for( uint8_t i = 0; i < facts_length; i++){
      offset += this->st_facts.deserialize(inbuffer + offset);
        memcpy( &(this->facts[i]), &(this->st_facts), sizeof(psi::TermMsg));
      }
     return offset;
    }

    const char * getType(){ return ASSERT; };
    const char * getMD5(){ return "e0ad3b0d81f37bd1f9e8b262c0be4631"; };

  };

  class AssertResponse : public ros::Msg
  {
    public:
      char * error;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_error = strlen( (const char*) this->error);
      memcpy(outbuffer + offset, &length_error, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error, length_error);
      offset += length_error;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_error;
      memcpy(&length_error, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error-1]=0;
      this->error = (char *)(inbuffer + offset-1);
      offset += length_error;
     return offset;
    }

    const char * getType(){ return ASSERT; };
    const char * getMD5(){ return "eca8b96616c32aacf1be8bbf14c70eba"; };

  };

  class Assert {
    public:
    typedef AssertRequest Request;
    typedef AssertResponse Response;
  };

}
#endif

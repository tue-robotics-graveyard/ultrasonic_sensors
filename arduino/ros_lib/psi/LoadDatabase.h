#ifndef _ROS_SERVICE_LoadDatabase_h
#define _ROS_SERVICE_LoadDatabase_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace psi
{

static const char LOADDATABASE[] = "psi/LoadDatabase";

  class LoadDatabaseRequest : public ros::Msg
  {
    public:
      char * db_filename;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_db_filename = strlen( (const char*) this->db_filename);
      memcpy(outbuffer + offset, &length_db_filename, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->db_filename, length_db_filename);
      offset += length_db_filename;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_db_filename;
      memcpy(&length_db_filename, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_db_filename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_db_filename-1]=0;
      this->db_filename = (char *)(inbuffer + offset-1);
      offset += length_db_filename;
     return offset;
    }

    const char * getType(){ return LOADDATABASE; };
    const char * getMD5(){ return "7283ce5ff5bb561d5c786c08a7e3a293"; };

  };

  class LoadDatabaseResponse : public ros::Msg
  {
    public:
      char * result;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_result = strlen( (const char*) this->result);
      memcpy(outbuffer + offset, &length_result, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->result, length_result);
      offset += length_result;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_result;
      memcpy(&length_result, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_result; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_result-1]=0;
      this->result = (char *)(inbuffer + offset-1);
      offset += length_result;
     return offset;
    }

    const char * getType(){ return LOADDATABASE; };
    const char * getMD5(){ return "c22f2a1ed8654a0b365f1bb3f7ff2c0f"; };

  };

  class LoadDatabase {
    public:
    typedef LoadDatabaseRequest Request;
    typedef LoadDatabaseResponse Response;
  };

}
#endif

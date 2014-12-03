#ifndef _ROS_SERVICE_SetObjects_h
#define _ROS_SERVICE_SetObjects_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pein_srvs
{

static const char SETOBJECTS[] = "pein_srvs/SetObjects";

  class SetObjectsRequest : public ros::Msg
  {
    public:
      uint8_t objects_length;
      char* st_objects;
      char* * objects;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = objects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < objects_length; i++){
      uint32_t length_objectsi = strlen( (const char*) this->objects[i]);
      memcpy(outbuffer + offset, &length_objectsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->objects[i], length_objectsi);
      offset += length_objectsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t objects_lengthT = *(inbuffer + offset++);
      if(objects_lengthT > objects_length)
        this->objects = (char**)realloc(this->objects, objects_lengthT * sizeof(char*));
      offset += 3;
      objects_length = objects_lengthT;
      for( uint8_t i = 0; i < objects_length; i++){
      uint32_t length_st_objects;
      memcpy(&length_st_objects, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_objects; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_objects-1]=0;
      this->st_objects = (char *)(inbuffer + offset-1);
      offset += length_st_objects;
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return SETOBJECTS; };
    const char * getMD5(){ return "39d6292ea712a13252ebdb5470ba0086"; };

  };

  class SetObjectsResponse : public ros::Msg
  {
    public:
      bool suc;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_suc;
      u_suc.real = this->suc;
      *(outbuffer + offset + 0) = (u_suc.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->suc);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_suc;
      u_suc.base = 0;
      u_suc.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->suc = u_suc.real;
      offset += sizeof(this->suc);
     return offset;
    }

    const char * getType(){ return SETOBJECTS; };
    const char * getMD5(){ return "45a5ef5e31fb54647cbd12ed5c0241d7"; };

  };

  class SetObjects {
    public:
    typedef SetObjectsRequest Request;
    typedef SetObjectsResponse Response;
  };

}
#endif

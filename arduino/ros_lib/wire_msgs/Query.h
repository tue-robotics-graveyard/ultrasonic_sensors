#ifndef _ROS_SERVICE_Query_h
#define _ROS_SERVICE_Query_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "wire_msgs/ObjectState.h"
#include "std_msgs/Header.h"

namespace wire_msgs
{

static const char QUERY[] = "wire_msgs/Query";

  class QueryRequest : public ros::Msg
  {
    public:
      char * frame_id;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_frame_id = strlen( (const char*) this->frame_id);
      memcpy(outbuffer + offset, &length_frame_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_frame_id;
      memcpy(&length_frame_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
     return offset;
    }

    const char * getType(){ return QUERY; };
    const char * getMD5(){ return "371cb926969bb965addb80f752c7ca31"; };

  };

  class QueryResponse : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t objects_length;
      wire_msgs::ObjectState st_objects;
      wire_msgs::ObjectState * objects;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = objects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->objects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t objects_lengthT = *(inbuffer + offset++);
      if(objects_lengthT > objects_length)
        this->objects = (wire_msgs::ObjectState*)realloc(this->objects, objects_lengthT * sizeof(wire_msgs::ObjectState));
      offset += 3;
      objects_length = objects_lengthT;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(wire_msgs::ObjectState));
      }
     return offset;
    }

    const char * getType(){ return QUERY; };
    const char * getMD5(){ return "709cf6ed4e0cb48a90805cc932ae8d0e"; };

  };

  class Query {
    public:
    typedef QueryRequest Request;
    typedef QueryResponse Response;
  };

}
#endif

#ifndef _ROS_wire_msgs_WorldState_h
#define _ROS_wire_msgs_WorldState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "wire_msgs/ObjectState.h"

namespace wire_msgs
{

  class WorldState : public ros::Msg
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

    const char * getType(){ return "wire_msgs/WorldState"; };
    const char * getMD5(){ return "709cf6ed4e0cb48a90805cc932ae8d0e"; };

  };

}
#endif
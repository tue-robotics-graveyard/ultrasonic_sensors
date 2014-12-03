#ifndef _ROS_wire_msgs_WorldEvidence_h
#define _ROS_wire_msgs_WorldEvidence_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "wire_msgs/ObjectEvidence.h"

namespace wire_msgs
{

  class WorldEvidence : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t object_evidence_length;
      wire_msgs::ObjectEvidence st_object_evidence;
      wire_msgs::ObjectEvidence * object_evidence;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = object_evidence_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < object_evidence_length; i++){
      offset += this->object_evidence[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t object_evidence_lengthT = *(inbuffer + offset++);
      if(object_evidence_lengthT > object_evidence_length)
        this->object_evidence = (wire_msgs::ObjectEvidence*)realloc(this->object_evidence, object_evidence_lengthT * sizeof(wire_msgs::ObjectEvidence));
      offset += 3;
      object_evidence_length = object_evidence_lengthT;
      for( uint8_t i = 0; i < object_evidence_length; i++){
      offset += this->st_object_evidence.deserialize(inbuffer + offset);
        memcpy( &(this->object_evidence[i]), &(this->st_object_evidence), sizeof(wire_msgs::ObjectEvidence));
      }
     return offset;
    }

    const char * getType(){ return "wire_msgs/WorldEvidence"; };
    const char * getMD5(){ return "b45539c9069bd9814cfced7e3541e65e"; };

  };

}
#endif
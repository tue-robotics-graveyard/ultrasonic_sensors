#ifndef _ROS_pein_msgs_FaceArray_h
#define _ROS_pein_msgs_FaceArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pein_msgs/Face.h"

namespace pein_msgs
{

  class FaceArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t faces_length;
      pein_msgs::Face st_faces;
      pein_msgs::Face * faces;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = faces_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < faces_length; i++){
      offset += this->faces[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t faces_lengthT = *(inbuffer + offset++);
      if(faces_lengthT > faces_length)
        this->faces = (pein_msgs::Face*)realloc(this->faces, faces_lengthT * sizeof(pein_msgs::Face));
      offset += 3;
      faces_length = faces_lengthT;
      for( uint8_t i = 0; i < faces_length; i++){
      offset += this->st_faces.deserialize(inbuffer + offset);
        memcpy( &(this->faces[i]), &(this->st_faces), sizeof(pein_msgs::Face));
      }
     return offset;
    }

    const char * getType(){ return "pein_msgs/FaceArray"; };
    const char * getMD5(){ return "81ce703a41b32b87dc000776c209bd7f"; };

  };

}
#endif
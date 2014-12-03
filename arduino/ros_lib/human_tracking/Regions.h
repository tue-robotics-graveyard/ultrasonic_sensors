#ifndef _ROS_human_tracking_Regions_h
#define _ROS_human_tracking_Regions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "human_tracking/PointArray.h"

namespace human_tracking
{

  class Regions : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t id;
      uint8_t contours_length;
      human_tracking::PointArray st_contours;
      human_tracking::PointArray * contours;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset++) = contours_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < contours_length; i++){
      offset += this->contours[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->id =  ((uint16_t) (*(inbuffer + offset)));
      this->id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->id);
      uint8_t contours_lengthT = *(inbuffer + offset++);
      if(contours_lengthT > contours_length)
        this->contours = (human_tracking::PointArray*)realloc(this->contours, contours_lengthT * sizeof(human_tracking::PointArray));
      offset += 3;
      contours_length = contours_lengthT;
      for( uint8_t i = 0; i < contours_length; i++){
      offset += this->st_contours.deserialize(inbuffer + offset);
        memcpy( &(this->contours[i]), &(this->st_contours), sizeof(human_tracking::PointArray));
      }
     return offset;
    }

    const char * getType(){ return "human_tracking/Regions"; };
    const char * getMD5(){ return "bd2b0b557ddb47f7acc73eb9a9aecd4e"; };

  };

}
#endif
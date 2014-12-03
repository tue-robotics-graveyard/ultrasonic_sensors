#ifndef _ROS_pein_msgs_ODM_h
#define _ROS_pein_msgs_ODM_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/Image.h"
#include "pein_msgs/ObjectImage.h"

namespace pein_msgs
{

  class ODM : public ros::Msg
  {
    public:
      std_msgs::Header header;
      sensor_msgs::Image depth_image;
      sensor_msgs::Image color_image;
      uint8_t object_images_length;
      pein_msgs::ObjectImage st_object_images;
      pein_msgs::ObjectImage * object_images;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->depth_image.serialize(outbuffer + offset);
      offset += this->color_image.serialize(outbuffer + offset);
      *(outbuffer + offset++) = object_images_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < object_images_length; i++){
      offset += this->object_images[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->depth_image.deserialize(inbuffer + offset);
      offset += this->color_image.deserialize(inbuffer + offset);
      uint8_t object_images_lengthT = *(inbuffer + offset++);
      if(object_images_lengthT > object_images_length)
        this->object_images = (pein_msgs::ObjectImage*)realloc(this->object_images, object_images_lengthT * sizeof(pein_msgs::ObjectImage));
      offset += 3;
      object_images_length = object_images_lengthT;
      for( uint8_t i = 0; i < object_images_length; i++){
      offset += this->st_object_images.deserialize(inbuffer + offset);
        memcpy( &(this->object_images[i]), &(this->st_object_images), sizeof(pein_msgs::ObjectImage));
      }
     return offset;
    }

    const char * getType(){ return "pein_msgs/ODM"; };
    const char * getMD5(){ return "30c5b37036e6eabd4227791dd67390d5"; };

  };

}
#endif
#ifndef _ROS_ed_gui_server_Color_h
#define _ROS_ed_gui_server_Color_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ed_gui_server
{

  class Color : public ros::Msg
  {
    public:
      uint8_t r;
      uint8_t g;
      uint8_t b;
      uint8_t a;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->r >> (8 * 0)) & 0xFF;
      offset += sizeof(this->r);
      *(outbuffer + offset + 0) = (this->g >> (8 * 0)) & 0xFF;
      offset += sizeof(this->g);
      *(outbuffer + offset + 0) = (this->b >> (8 * 0)) & 0xFF;
      offset += sizeof(this->b);
      *(outbuffer + offset + 0) = (this->a >> (8 * 0)) & 0xFF;
      offset += sizeof(this->a);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->r =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->r);
      this->g =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->g);
      this->b =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->b);
      this->a =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->a);
     return offset;
    }

    const char * getType(){ return "ed_gui_server/Color"; };
    const char * getMD5(){ return "3a89b17adab5bedef0b554f03235d9b3"; };

  };

}
#endif
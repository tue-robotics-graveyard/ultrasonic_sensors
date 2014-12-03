#ifndef _ROS_SERVICE_UsePhysics_h
#define _ROS_SERVICE_UsePhysics_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tue_gazebo_plugins
{

static const char USEPHYSICS[] = "tue_gazebo_plugins/UsePhysics";

  class UsePhysicsRequest : public ros::Msg
  {
    public:
      bool use_physics;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_use_physics;
      u_use_physics.real = this->use_physics;
      *(outbuffer + offset + 0) = (u_use_physics.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_physics);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_use_physics;
      u_use_physics.base = 0;
      u_use_physics.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_physics = u_use_physics.real;
      offset += sizeof(this->use_physics);
     return offset;
    }

    const char * getType(){ return USEPHYSICS; };
    const char * getMD5(){ return "55daad731bd77344c7fe561e70417666"; };

  };

  class UsePhysicsResponse : public ros::Msg
  {
    public:
      char * success;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_success = strlen( (const char*) this->success);
      memcpy(outbuffer + offset, &length_success, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->success, length_success);
      offset += length_success;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_success;
      memcpy(&length_success, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_success; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_success-1]=0;
      this->success = (char *)(inbuffer + offset-1);
      offset += length_success;
     return offset;
    }

    const char * getType(){ return USEPHYSICS; };
    const char * getMD5(){ return "6563811f75f3715f19a981f2cc0a3560"; };

  };

  class UsePhysics {
    public:
    typedef UsePhysicsRequest Request;
    typedef UsePhysicsResponse Response;
  };

}
#endif

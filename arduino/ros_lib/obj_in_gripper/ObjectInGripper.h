#ifndef _ROS_SERVICE_ObjectInGripper_h
#define _ROS_SERVICE_ObjectInGripper_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace obj_in_gripper
{

static const char OBJECTINGRIPPER[] = "obj_in_gripper/ObjectInGripper";

  class ObjectInGripperRequest : public ros::Msg
  {
    public:
      char * ID;
      char * frame;
      bool grasp;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_ID = strlen( (const char*) this->ID);
      memcpy(outbuffer + offset, &length_ID, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ID, length_ID);
      offset += length_ID;
      uint32_t length_frame = strlen( (const char*) this->frame);
      memcpy(outbuffer + offset, &length_frame, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->frame, length_frame);
      offset += length_frame;
      union {
        bool real;
        uint8_t base;
      } u_grasp;
      u_grasp.real = this->grasp;
      *(outbuffer + offset + 0) = (u_grasp.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->grasp);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_ID;
      memcpy(&length_ID, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ID; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ID-1]=0;
      this->ID = (char *)(inbuffer + offset-1);
      offset += length_ID;
      uint32_t length_frame;
      memcpy(&length_frame, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame-1]=0;
      this->frame = (char *)(inbuffer + offset-1);
      offset += length_frame;
      union {
        bool real;
        uint8_t base;
      } u_grasp;
      u_grasp.base = 0;
      u_grasp.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->grasp = u_grasp.real;
      offset += sizeof(this->grasp);
     return offset;
    }

    const char * getType(){ return OBJECTINGRIPPER; };
    const char * getMD5(){ return "fc749add13b5306d636291ff2a2ace5e"; };

  };

  class ObjectInGripperResponse : public ros::Msg
  {
    public:
      bool success;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return OBJECTINGRIPPER; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ObjectInGripper {
    public:
    typedef ObjectInGripperRequest Request;
    typedef ObjectInGripperResponse Response;
  };

}
#endif

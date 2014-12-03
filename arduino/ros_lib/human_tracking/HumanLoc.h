#ifndef _ROS_human_tracking_HumanLoc_h
#define _ROS_human_tracking_HumanLoc_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace human_tracking
{

  class HumanLoc : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t id;
      float coordX;
      float coordY;
      float coordZ;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      union {
        float real;
        uint32_t base;
      } u_coordX;
      u_coordX.real = this->coordX;
      *(outbuffer + offset + 0) = (u_coordX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_coordX.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_coordX.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_coordX.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coordX);
      union {
        float real;
        uint32_t base;
      } u_coordY;
      u_coordY.real = this->coordY;
      *(outbuffer + offset + 0) = (u_coordY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_coordY.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_coordY.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_coordY.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coordY);
      union {
        float real;
        uint32_t base;
      } u_coordZ;
      u_coordZ.real = this->coordZ;
      *(outbuffer + offset + 0) = (u_coordZ.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_coordZ.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_coordZ.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_coordZ.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coordZ);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        float real;
        uint32_t base;
      } u_coordX;
      u_coordX.base = 0;
      u_coordX.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_coordX.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_coordX.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_coordX.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->coordX = u_coordX.real;
      offset += sizeof(this->coordX);
      union {
        float real;
        uint32_t base;
      } u_coordY;
      u_coordY.base = 0;
      u_coordY.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_coordY.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_coordY.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_coordY.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->coordY = u_coordY.real;
      offset += sizeof(this->coordY);
      union {
        float real;
        uint32_t base;
      } u_coordZ;
      u_coordZ.base = 0;
      u_coordZ.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_coordZ.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_coordZ.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_coordZ.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->coordZ = u_coordZ.real;
      offset += sizeof(this->coordZ);
     return offset;
    }

    const char * getType(){ return "human_tracking/HumanLoc"; };
    const char * getMD5(){ return "cd66590070aca98f7dc469effd7af516"; };

  };

}
#endif
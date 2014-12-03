#ifndef _ROS_SERVICE_FindObjInRoi_h
#define _ROS_SERVICE_FindObjInRoi_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pein_srvs
{

static const char FINDOBJINROI[] = "pein_srvs/FindObjInRoi";

  class FindObjInRoiRequest : public ros::Msg
  {
    public:
      float x;
      float y;
      float z;
      float length_x;
      float length_y;
      float length_z;
      char * frame;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_length_x;
      u_length_x.real = this->length_x;
      *(outbuffer + offset + 0) = (u_length_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_length_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_length_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_length_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->length_x);
      union {
        float real;
        uint32_t base;
      } u_length_y;
      u_length_y.real = this->length_y;
      *(outbuffer + offset + 0) = (u_length_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_length_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_length_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_length_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->length_y);
      union {
        float real;
        uint32_t base;
      } u_length_z;
      u_length_z.real = this->length_z;
      *(outbuffer + offset + 0) = (u_length_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_length_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_length_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_length_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->length_z);
      uint32_t length_frame = strlen( (const char*) this->frame);
      memcpy(outbuffer + offset, &length_frame, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->frame, length_frame);
      offset += length_frame;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_length_x;
      u_length_x.base = 0;
      u_length_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_length_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_length_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_length_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->length_x = u_length_x.real;
      offset += sizeof(this->length_x);
      union {
        float real;
        uint32_t base;
      } u_length_y;
      u_length_y.base = 0;
      u_length_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_length_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_length_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_length_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->length_y = u_length_y.real;
      offset += sizeof(this->length_y);
      union {
        float real;
        uint32_t base;
      } u_length_z;
      u_length_z.base = 0;
      u_length_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_length_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_length_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_length_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->length_z = u_length_z.real;
      offset += sizeof(this->length_z);
      uint32_t length_frame;
      memcpy(&length_frame, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame-1]=0;
      this->frame = (char *)(inbuffer + offset-1);
      offset += length_frame;
     return offset;
    }

    const char * getType(){ return FINDOBJINROI; };
    const char * getMD5(){ return "5aafda2d4a441ce52945eb8b349a7f84"; };

  };

  class FindObjInRoiResponse : public ros::Msg
  {
    public:
      bool suc;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_suc;
      u_suc.real = this->suc;
      *(outbuffer + offset + 0) = (u_suc.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->suc);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_suc;
      u_suc.base = 0;
      u_suc.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->suc = u_suc.real;
      offset += sizeof(this->suc);
     return offset;
    }

    const char * getType(){ return FINDOBJINROI; };
    const char * getMD5(){ return "45a5ef5e31fb54647cbd12ed5c0241d7"; };

  };

  class FindObjInRoi {
    public:
    typedef FindObjInRoiRequest Request;
    typedef FindObjInRoiResponse Response;
  };

}
#endif

#ifndef _ROS_SERVICE_Threshold_h
#define _ROS_SERVICE_Threshold_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pein_srvs
{

static const char THRESHOLD[] = "pein_srvs/Threshold";

  class ThresholdRequest : public ros::Msg
  {
    public:
      float threshold;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_threshold;
      u_threshold.real = this->threshold;
      *(outbuffer + offset + 0) = (u_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->threshold);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_threshold;
      u_threshold.base = 0;
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->threshold = u_threshold.real;
      offset += sizeof(this->threshold);
     return offset;
    }

    const char * getType(){ return THRESHOLD; };
    const char * getMD5(){ return "762b8eff81569601a12f7a5cd61b8c26"; };

  };

  class ThresholdResponse : public ros::Msg
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

    const char * getType(){ return THRESHOLD; };
    const char * getMD5(){ return "45a5ef5e31fb54647cbd12ed5c0241d7"; };

  };

  class Threshold {
    public:
    typedef ThresholdRequest Request;
    typedef ThresholdResponse Response;
  };

}
#endif

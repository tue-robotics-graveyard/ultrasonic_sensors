#ifndef _ROS_SERVICE_StartStopWithROI_h
#define _ROS_SERVICE_StartStopWithROI_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pein_msgs/ROI.h"

namespace pein_srvs
{

static const char STARTSTOPWITHROI[] = "pein_srvs/StartStopWithROI";

  class StartStopWithROIRequest : public ros::Msg
  {
    public:
      bool status;
      pein_msgs::ROI roi;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      offset += this->roi.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
      offset += this->roi.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return STARTSTOPWITHROI; };
    const char * getMD5(){ return "fde97ad5ca4d6bf1c7f419d3537943ef"; };

  };

  class StartStopWithROIResponse : public ros::Msg
  {
    public:
      char * message;
      uint16_t error;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_message = strlen( (const char*) this->message);
      memcpy(outbuffer + offset, &length_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      *(outbuffer + offset + 0) = (this->error >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->error >> (8 * 1)) & 0xFF;
      offset += sizeof(this->error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_message;
      memcpy(&length_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      this->error =  ((uint16_t) (*(inbuffer + offset)));
      this->error |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->error);
     return offset;
    }

    const char * getType(){ return STARTSTOPWITHROI; };
    const char * getMD5(){ return "5f589f325811b16c628c3b6a563ebf9c"; };

  };

  class StartStopWithROI {
    public:
    typedef StartStopWithROIRequest Request;
    typedef StartStopWithROIResponse Response;
  };

}
#endif

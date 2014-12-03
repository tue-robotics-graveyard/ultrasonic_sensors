#ifndef _ROS_SERVICE_TransformPoint_h
#define _ROS_SERVICE_TransformPoint_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"
#include "ros/time.h"

namespace tf_server
{

static const char TRANSFORMPOINT[] = "tf_server/TransformPoint";

  class TransformPointRequest : public ros::Msg
  {
    public:
      geometry_msgs::PointStamped point;
      char * target_frame;
      ros::Time target_time;
      char * fixed_frame;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->point.serialize(outbuffer + offset);
      uint32_t length_target_frame = strlen( (const char*) this->target_frame);
      memcpy(outbuffer + offset, &length_target_frame, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->target_frame, length_target_frame);
      offset += length_target_frame;
      *(outbuffer + offset + 0) = (this->target_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->target_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->target_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->target_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_time.sec);
      *(outbuffer + offset + 0) = (this->target_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->target_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->target_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->target_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_time.nsec);
      uint32_t length_fixed_frame = strlen( (const char*) this->fixed_frame);
      memcpy(outbuffer + offset, &length_fixed_frame, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->fixed_frame, length_fixed_frame);
      offset += length_fixed_frame;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->point.deserialize(inbuffer + offset);
      uint32_t length_target_frame;
      memcpy(&length_target_frame, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_frame-1]=0;
      this->target_frame = (char *)(inbuffer + offset-1);
      offset += length_target_frame;
      this->target_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->target_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->target_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->target_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->target_time.sec);
      this->target_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->target_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->target_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->target_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->target_time.nsec);
      uint32_t length_fixed_frame;
      memcpy(&length_fixed_frame, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_fixed_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_fixed_frame-1]=0;
      this->fixed_frame = (char *)(inbuffer + offset-1);
      offset += length_fixed_frame;
     return offset;
    }

    const char * getType(){ return TRANSFORMPOINT; };
    const char * getMD5(){ return "e3961851904390b7676cfd383c8e9872"; };

  };

  class TransformPointResponse : public ros::Msg
  {
    public:
      geometry_msgs::PointStamped point;
      char * error_msg;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->point.serialize(outbuffer + offset);
      uint32_t length_error_msg = strlen( (const char*) this->error_msg);
      memcpy(outbuffer + offset, &length_error_msg, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error_msg, length_error_msg);
      offset += length_error_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->point.deserialize(inbuffer + offset);
      uint32_t length_error_msg;
      memcpy(&length_error_msg, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_msg-1]=0;
      this->error_msg = (char *)(inbuffer + offset-1);
      offset += length_error_msg;
     return offset;
    }

    const char * getType(){ return TRANSFORMPOINT; };
    const char * getMD5(){ return "02272f7e9965594c183b89fa18b98a41"; };

  };

  class TransformPoint {
    public:
    typedef TransformPointRequest Request;
    typedef TransformPointResponse Response;
  };

}
#endif

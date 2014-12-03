#ifndef _ROS_pein_msgs_Segmentation_h
#define _ROS_pein_msgs_Segmentation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"
#include "pein_msgs/Segment.h"

namespace pein_msgs
{

  class Segmentation : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t plane_parameters_length;
      float st_plane_parameters;
      float * plane_parameters;
      std_msgs::String origin;
      uint8_t segments_length;
      pein_msgs::Segment st_segments;
      pein_msgs::Segment * segments;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = plane_parameters_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < plane_parameters_length; i++){
      union {
        float real;
        uint32_t base;
      } u_plane_parametersi;
      u_plane_parametersi.real = this->plane_parameters[i];
      *(outbuffer + offset + 0) = (u_plane_parametersi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_plane_parametersi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_plane_parametersi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_plane_parametersi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plane_parameters[i]);
      }
      offset += this->origin.serialize(outbuffer + offset);
      *(outbuffer + offset++) = segments_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < segments_length; i++){
      offset += this->segments[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t plane_parameters_lengthT = *(inbuffer + offset++);
      if(plane_parameters_lengthT > plane_parameters_length)
        this->plane_parameters = (float*)realloc(this->plane_parameters, plane_parameters_lengthT * sizeof(float));
      offset += 3;
      plane_parameters_length = plane_parameters_lengthT;
      for( uint8_t i = 0; i < plane_parameters_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_plane_parameters;
      u_st_plane_parameters.base = 0;
      u_st_plane_parameters.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_plane_parameters.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_plane_parameters.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_plane_parameters.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_plane_parameters = u_st_plane_parameters.real;
      offset += sizeof(this->st_plane_parameters);
        memcpy( &(this->plane_parameters[i]), &(this->st_plane_parameters), sizeof(float));
      }
      offset += this->origin.deserialize(inbuffer + offset);
      uint8_t segments_lengthT = *(inbuffer + offset++);
      if(segments_lengthT > segments_length)
        this->segments = (pein_msgs::Segment*)realloc(this->segments, segments_lengthT * sizeof(pein_msgs::Segment));
      offset += 3;
      segments_length = segments_lengthT;
      for( uint8_t i = 0; i < segments_length; i++){
      offset += this->st_segments.deserialize(inbuffer + offset);
        memcpy( &(this->segments[i]), &(this->st_segments), sizeof(pein_msgs::Segment));
      }
     return offset;
    }

    const char * getType(){ return "pein_msgs/Segmentation"; };
    const char * getMD5(){ return "220332fa74695c2fa26a36cc2c9bc516"; };

  };

}
#endif
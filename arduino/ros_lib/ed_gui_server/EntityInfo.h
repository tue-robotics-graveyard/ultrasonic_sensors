#ifndef _ROS_ed_gui_server_EntityInfo_h
#define _ROS_ed_gui_server_EntityInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "ed_gui_server/Color.h"
#include "ed_gui_server/Polygon.h"

namespace ed_gui_server
{

  class EntityInfo : public ros::Msg
  {
    public:
      char * id;
      geometry_msgs::Pose pose;
      uint32_t mesh_revision;
      ed_gui_server::Color color;
      ed_gui_server::Polygon polygon;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen( (const char*) this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->mesh_revision >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mesh_revision >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mesh_revision >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mesh_revision >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mesh_revision);
      offset += this->color.serialize(outbuffer + offset);
      offset += this->polygon.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      offset += this->pose.deserialize(inbuffer + offset);
      this->mesh_revision =  ((uint32_t) (*(inbuffer + offset)));
      this->mesh_revision |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mesh_revision |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->mesh_revision |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->mesh_revision);
      offset += this->color.deserialize(inbuffer + offset);
      offset += this->polygon.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "ed_gui_server/EntityInfo"; };
    const char * getMD5(){ return "73be8abbaf0964f8c2f6db49ee46271b"; };

  };

}
#endif
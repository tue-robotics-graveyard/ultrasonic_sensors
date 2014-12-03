#ifndef _ROS_SERVICE_QueryEntities_h
#define _ROS_SERVICE_QueryEntities_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ed_gui_server/EntityInfo.h"
#include "geometry_msgs/Point32.h"

namespace ed_gui_server
{

static const char QUERYENTITIES[] = "ed_gui_server/QueryEntities";

  class QueryEntitiesRequest : public ros::Msg
  {
    public:
      geometry_msgs::Point32 area_min;
      geometry_msgs::Point32 area_max;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->area_min.serialize(outbuffer + offset);
      offset += this->area_max.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->area_min.deserialize(inbuffer + offset);
      offset += this->area_max.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return QUERYENTITIES; };
    const char * getMD5(){ return "f69750d5b808229c7cf85b1629f71144"; };

  };

  class QueryEntitiesResponse : public ros::Msg
  {
    public:
      uint8_t entities_length;
      ed_gui_server::EntityInfo st_entities;
      ed_gui_server::EntityInfo * entities;
      char * error_msg;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = entities_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < entities_length; i++){
      offset += this->entities[i].serialize(outbuffer + offset);
      }
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
      uint8_t entities_lengthT = *(inbuffer + offset++);
      if(entities_lengthT > entities_length)
        this->entities = (ed_gui_server::EntityInfo*)realloc(this->entities, entities_lengthT * sizeof(ed_gui_server::EntityInfo));
      offset += 3;
      entities_length = entities_lengthT;
      for( uint8_t i = 0; i < entities_length; i++){
      offset += this->st_entities.deserialize(inbuffer + offset);
        memcpy( &(this->entities[i]), &(this->st_entities), sizeof(ed_gui_server::EntityInfo));
      }
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

    const char * getType(){ return QUERYENTITIES; };
    const char * getMD5(){ return "45c2ad4ac939c84cbda75b8a58a03aa8"; };

  };

  class QueryEntities {
    public:
    typedef QueryEntitiesRequest Request;
    typedef QueryEntitiesResponse Response;
  };

}
#endif

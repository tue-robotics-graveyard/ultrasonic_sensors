#ifndef _ROS_ed_gui_server_EntityInfos_h
#define _ROS_ed_gui_server_EntityInfos_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ed_gui_server/EntityInfo.h"

namespace ed_gui_server
{

  class EntityInfos : public ros::Msg
  {
    public:
      uint8_t entities_length;
      ed_gui_server::EntityInfo st_entities;
      ed_gui_server::EntityInfo * entities;

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
     return offset;
    }

    const char * getType(){ return "ed_gui_server/EntityInfos"; };
    const char * getMD5(){ return "99db684f37ecfb66457d5c799db46c1c"; };

  };

}
#endif
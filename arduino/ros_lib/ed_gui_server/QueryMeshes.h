#ifndef _ROS_SERVICE_QueryMeshes_h
#define _ROS_SERVICE_QueryMeshes_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ed_gui_server/Mesh.h"

namespace ed_gui_server
{

static const char QUERYMESHES[] = "ed_gui_server/QueryMeshes";

  class QueryMeshesRequest : public ros::Msg
  {
    public:
      uint8_t entity_ids_length;
      char* st_entity_ids;
      char* * entity_ids;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = entity_ids_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < entity_ids_length; i++){
      uint32_t length_entity_idsi = strlen( (const char*) this->entity_ids[i]);
      memcpy(outbuffer + offset, &length_entity_idsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->entity_ids[i], length_entity_idsi);
      offset += length_entity_idsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t entity_ids_lengthT = *(inbuffer + offset++);
      if(entity_ids_lengthT > entity_ids_length)
        this->entity_ids = (char**)realloc(this->entity_ids, entity_ids_lengthT * sizeof(char*));
      offset += 3;
      entity_ids_length = entity_ids_lengthT;
      for( uint8_t i = 0; i < entity_ids_length; i++){
      uint32_t length_st_entity_ids;
      memcpy(&length_st_entity_ids, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_entity_ids; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_entity_ids-1]=0;
      this->st_entity_ids = (char *)(inbuffer + offset-1);
      offset += length_st_entity_ids;
        memcpy( &(this->entity_ids[i]), &(this->st_entity_ids), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return QUERYMESHES; };
    const char * getMD5(){ return "c3342e15d8974ec05cf94758c3900440"; };

  };

  class QueryMeshesResponse : public ros::Msg
  {
    public:
      uint8_t entity_ids_length;
      char* st_entity_ids;
      char* * entity_ids;
      uint8_t meshes_length;
      ed_gui_server::Mesh st_meshes;
      ed_gui_server::Mesh * meshes;
      char * error_msg;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = entity_ids_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < entity_ids_length; i++){
      uint32_t length_entity_idsi = strlen( (const char*) this->entity_ids[i]);
      memcpy(outbuffer + offset, &length_entity_idsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->entity_ids[i], length_entity_idsi);
      offset += length_entity_idsi;
      }
      *(outbuffer + offset++) = meshes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < meshes_length; i++){
      offset += this->meshes[i].serialize(outbuffer + offset);
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
      uint8_t entity_ids_lengthT = *(inbuffer + offset++);
      if(entity_ids_lengthT > entity_ids_length)
        this->entity_ids = (char**)realloc(this->entity_ids, entity_ids_lengthT * sizeof(char*));
      offset += 3;
      entity_ids_length = entity_ids_lengthT;
      for( uint8_t i = 0; i < entity_ids_length; i++){
      uint32_t length_st_entity_ids;
      memcpy(&length_st_entity_ids, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_entity_ids; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_entity_ids-1]=0;
      this->st_entity_ids = (char *)(inbuffer + offset-1);
      offset += length_st_entity_ids;
        memcpy( &(this->entity_ids[i]), &(this->st_entity_ids), sizeof(char*));
      }
      uint8_t meshes_lengthT = *(inbuffer + offset++);
      if(meshes_lengthT > meshes_length)
        this->meshes = (ed_gui_server::Mesh*)realloc(this->meshes, meshes_lengthT * sizeof(ed_gui_server::Mesh));
      offset += 3;
      meshes_length = meshes_lengthT;
      for( uint8_t i = 0; i < meshes_length; i++){
      offset += this->st_meshes.deserialize(inbuffer + offset);
        memcpy( &(this->meshes[i]), &(this->st_meshes), sizeof(ed_gui_server::Mesh));
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

    const char * getType(){ return QUERYMESHES; };
    const char * getMD5(){ return "b725cf7dd9bc786cecf29c5e86895c29"; };

  };

  class QueryMeshes {
    public:
    typedef QueryMeshesRequest Request;
    typedef QueryMeshesResponse Response;
  };

}
#endif

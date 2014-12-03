#ifndef _ROS_ed_gui_server_Mesh_h
#define _ROS_ed_gui_server_Mesh_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ed_gui_server
{

  class Mesh : public ros::Msg
  {
    public:
      uint32_t revision;
      uint8_t vertices_length;
      float st_vertices;
      float * vertices;
      uint8_t triangles_length;
      uint32_t st_triangles;
      uint32_t * triangles;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->revision >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->revision >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->revision >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->revision >> (8 * 3)) & 0xFF;
      offset += sizeof(this->revision);
      *(outbuffer + offset++) = vertices_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < vertices_length; i++){
      union {
        float real;
        uint32_t base;
      } u_verticesi;
      u_verticesi.real = this->vertices[i];
      *(outbuffer + offset + 0) = (u_verticesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_verticesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_verticesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_verticesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertices[i]);
      }
      *(outbuffer + offset++) = triangles_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < triangles_length; i++){
      *(outbuffer + offset + 0) = (this->triangles[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->triangles[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->triangles[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->triangles[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->triangles[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->revision =  ((uint32_t) (*(inbuffer + offset)));
      this->revision |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->revision |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->revision |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->revision);
      uint8_t vertices_lengthT = *(inbuffer + offset++);
      if(vertices_lengthT > vertices_length)
        this->vertices = (float*)realloc(this->vertices, vertices_lengthT * sizeof(float));
      offset += 3;
      vertices_length = vertices_lengthT;
      for( uint8_t i = 0; i < vertices_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_vertices;
      u_st_vertices.base = 0;
      u_st_vertices.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_vertices.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_vertices.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_vertices.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_vertices = u_st_vertices.real;
      offset += sizeof(this->st_vertices);
        memcpy( &(this->vertices[i]), &(this->st_vertices), sizeof(float));
      }
      uint8_t triangles_lengthT = *(inbuffer + offset++);
      if(triangles_lengthT > triangles_length)
        this->triangles = (uint32_t*)realloc(this->triangles, triangles_lengthT * sizeof(uint32_t));
      offset += 3;
      triangles_length = triangles_lengthT;
      for( uint8_t i = 0; i < triangles_length; i++){
      this->st_triangles =  ((uint32_t) (*(inbuffer + offset)));
      this->st_triangles |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_triangles |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_triangles |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_triangles);
        memcpy( &(this->triangles[i]), &(this->st_triangles), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return "ed_gui_server/Mesh"; };
    const char * getMD5(){ return "47b3b8e1033fe3cd3e2f1aad5f228523"; };

  };

}
#endif
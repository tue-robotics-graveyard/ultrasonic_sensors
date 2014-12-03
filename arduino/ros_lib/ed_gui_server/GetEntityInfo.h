#ifndef _ROS_SERVICE_GetEntityInfo_h
#define _ROS_SERVICE_GetEntityInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ed_gui_server
{

static const char GETENTITYINFO[] = "ed_gui_server/GetEntityInfo";

  class GetEntityInfoRequest : public ros::Msg
  {
    public:
      char * id;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen( (const char*) this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
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
     return offset;
    }

    const char * getType(){ return GETENTITYINFO; };
    const char * getMD5(){ return "bbfcda76036ebbe3d36caf7af80b260c"; };

  };

  class GetEntityInfoResponse : public ros::Msg
  {
    public:
      char * type;
      uint8_t property_names_length;
      char* st_property_names;
      char* * property_names;
      uint8_t property_values_length;
      char* st_property_values;
      char* * property_values;
      uint8_t measurement_image_length;
      uint8_t st_measurement_image;
      uint8_t * measurement_image;
      uint8_t affordances_length;
      char* st_affordances;
      char* * affordances;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type = strlen( (const char*) this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset++) = property_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < property_names_length; i++){
      uint32_t length_property_namesi = strlen( (const char*) this->property_names[i]);
      memcpy(outbuffer + offset, &length_property_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->property_names[i], length_property_namesi);
      offset += length_property_namesi;
      }
      *(outbuffer + offset++) = property_values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < property_values_length; i++){
      uint32_t length_property_valuesi = strlen( (const char*) this->property_values[i]);
      memcpy(outbuffer + offset, &length_property_valuesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->property_values[i], length_property_valuesi);
      offset += length_property_valuesi;
      }
      *(outbuffer + offset++) = measurement_image_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < measurement_image_length; i++){
      *(outbuffer + offset + 0) = (this->measurement_image[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->measurement_image[i]);
      }
      *(outbuffer + offset++) = affordances_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < affordances_length; i++){
      uint32_t length_affordancesi = strlen( (const char*) this->affordances[i]);
      memcpy(outbuffer + offset, &length_affordancesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->affordances[i], length_affordancesi);
      offset += length_affordancesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint8_t property_names_lengthT = *(inbuffer + offset++);
      if(property_names_lengthT > property_names_length)
        this->property_names = (char**)realloc(this->property_names, property_names_lengthT * sizeof(char*));
      offset += 3;
      property_names_length = property_names_lengthT;
      for( uint8_t i = 0; i < property_names_length; i++){
      uint32_t length_st_property_names;
      memcpy(&length_st_property_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_property_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_property_names-1]=0;
      this->st_property_names = (char *)(inbuffer + offset-1);
      offset += length_st_property_names;
        memcpy( &(this->property_names[i]), &(this->st_property_names), sizeof(char*));
      }
      uint8_t property_values_lengthT = *(inbuffer + offset++);
      if(property_values_lengthT > property_values_length)
        this->property_values = (char**)realloc(this->property_values, property_values_lengthT * sizeof(char*));
      offset += 3;
      property_values_length = property_values_lengthT;
      for( uint8_t i = 0; i < property_values_length; i++){
      uint32_t length_st_property_values;
      memcpy(&length_st_property_values, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_property_values; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_property_values-1]=0;
      this->st_property_values = (char *)(inbuffer + offset-1);
      offset += length_st_property_values;
        memcpy( &(this->property_values[i]), &(this->st_property_values), sizeof(char*));
      }
      uint8_t measurement_image_lengthT = *(inbuffer + offset++);
      if(measurement_image_lengthT > measurement_image_length)
        this->measurement_image = (uint8_t*)realloc(this->measurement_image, measurement_image_lengthT * sizeof(uint8_t));
      offset += 3;
      measurement_image_length = measurement_image_lengthT;
      for( uint8_t i = 0; i < measurement_image_length; i++){
      this->st_measurement_image =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_measurement_image);
        memcpy( &(this->measurement_image[i]), &(this->st_measurement_image), sizeof(uint8_t));
      }
      uint8_t affordances_lengthT = *(inbuffer + offset++);
      if(affordances_lengthT > affordances_length)
        this->affordances = (char**)realloc(this->affordances, affordances_lengthT * sizeof(char*));
      offset += 3;
      affordances_length = affordances_lengthT;
      for( uint8_t i = 0; i < affordances_length; i++){
      uint32_t length_st_affordances;
      memcpy(&length_st_affordances, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_affordances; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_affordances-1]=0;
      this->st_affordances = (char *)(inbuffer + offset-1);
      offset += length_st_affordances;
        memcpy( &(this->affordances[i]), &(this->st_affordances), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETENTITYINFO; };
    const char * getMD5(){ return "878f05e3b6d17a50731692b50cebf3fc"; };

  };

  class GetEntityInfo {
    public:
    typedef GetEntityInfoRequest Request;
    typedef GetEntityInfoResponse Response;
  };

}
#endif

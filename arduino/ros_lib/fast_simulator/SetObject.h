#ifndef _ROS_SERVICE_SetObject_h
#define _ROS_SERVICE_SetObject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace fast_simulator
{

static const char SETOBJECT[] = "fast_simulator/SetObject";

  class SetObjectRequest : public ros::Msg
  {
    public:
      uint8_t action;
      char * id;
      char * type;
      geometry_msgs::Pose pose;
      uint8_t path_length;
      geometry_msgs::Pose st_path;
      geometry_msgs::Pose * path;
      uint8_t param_names_length;
      char* st_param_names;
      char* * param_names;
      uint8_t param_values_length;
      char* st_param_values;
      char* * param_values;
      enum { SET_POSE = 0 };
      enum { SET_PATH = 1 };
      enum { SET_PARAMS = 2 };
      enum { DELETE = 3 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->action >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      uint32_t length_id = strlen( (const char*) this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      uint32_t length_type = strlen( (const char*) this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset++) = path_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < path_length; i++){
      offset += this->path[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = param_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < param_names_length; i++){
      uint32_t length_param_namesi = strlen( (const char*) this->param_names[i]);
      memcpy(outbuffer + offset, &length_param_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->param_names[i], length_param_namesi);
      offset += length_param_namesi;
      }
      *(outbuffer + offset++) = param_values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < param_values_length; i++){
      uint32_t length_param_valuesi = strlen( (const char*) this->param_values[i]);
      memcpy(outbuffer + offset, &length_param_valuesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->param_values[i], length_param_valuesi);
      offset += length_param_valuesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->action =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->action);
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      offset += this->pose.deserialize(inbuffer + offset);
      uint8_t path_lengthT = *(inbuffer + offset++);
      if(path_lengthT > path_length)
        this->path = (geometry_msgs::Pose*)realloc(this->path, path_lengthT * sizeof(geometry_msgs::Pose));
      offset += 3;
      path_length = path_lengthT;
      for( uint8_t i = 0; i < path_length; i++){
      offset += this->st_path.deserialize(inbuffer + offset);
        memcpy( &(this->path[i]), &(this->st_path), sizeof(geometry_msgs::Pose));
      }
      uint8_t param_names_lengthT = *(inbuffer + offset++);
      if(param_names_lengthT > param_names_length)
        this->param_names = (char**)realloc(this->param_names, param_names_lengthT * sizeof(char*));
      offset += 3;
      param_names_length = param_names_lengthT;
      for( uint8_t i = 0; i < param_names_length; i++){
      uint32_t length_st_param_names;
      memcpy(&length_st_param_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_param_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_param_names-1]=0;
      this->st_param_names = (char *)(inbuffer + offset-1);
      offset += length_st_param_names;
        memcpy( &(this->param_names[i]), &(this->st_param_names), sizeof(char*));
      }
      uint8_t param_values_lengthT = *(inbuffer + offset++);
      if(param_values_lengthT > param_values_length)
        this->param_values = (char**)realloc(this->param_values, param_values_lengthT * sizeof(char*));
      offset += 3;
      param_values_length = param_values_lengthT;
      for( uint8_t i = 0; i < param_values_length; i++){
      uint32_t length_st_param_values;
      memcpy(&length_st_param_values, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_param_values; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_param_values-1]=0;
      this->st_param_values = (char *)(inbuffer + offset-1);
      offset += length_st_param_values;
        memcpy( &(this->param_values[i]), &(this->st_param_values), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return SETOBJECT; };
    const char * getMD5(){ return "af876b5af2d534acbcf35aab482251f4"; };

  };

  class SetObjectResponse : public ros::Msg
  {
    public:
      char * result_msg;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_result_msg = strlen( (const char*) this->result_msg);
      memcpy(outbuffer + offset, &length_result_msg, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->result_msg, length_result_msg);
      offset += length_result_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_result_msg;
      memcpy(&length_result_msg, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_result_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_result_msg-1]=0;
      this->result_msg = (char *)(inbuffer + offset-1);
      offset += length_result_msg;
     return offset;
    }

    const char * getType(){ return SETOBJECT; };
    const char * getMD5(){ return "703ead7875c7631df330d910113299f9"; };

  };

  class SetObject {
    public:
    typedef SetObjectRequest Request;
    typedef SetObjectResponse Response;
  };

}
#endif

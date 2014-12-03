#ifndef _ROS_SERVICE_StartPerceptionWithROI_h
#define _ROS_SERVICE_StartPerceptionWithROI_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pein_msgs/ModuleStatus.h"

namespace perception_srvs
{

static const char STARTPERCEPTIONWITHROI[] = "perception_srvs/StartPerceptionWithROI";

  class StartPerceptionWithROIRequest : public ros::Msg
  {
    public:
      uint8_t modules_length;
      pein_msgs::ModuleStatus st_modules;
      pein_msgs::ModuleStatus * modules;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = modules_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < modules_length; i++){
      offset += this->modules[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t modules_lengthT = *(inbuffer + offset++);
      if(modules_lengthT > modules_length)
        this->modules = (pein_msgs::ModuleStatus*)realloc(this->modules, modules_lengthT * sizeof(pein_msgs::ModuleStatus));
      offset += 3;
      modules_length = modules_lengthT;
      for( uint8_t i = 0; i < modules_length; i++){
      offset += this->st_modules.deserialize(inbuffer + offset);
        memcpy( &(this->modules[i]), &(this->st_modules), sizeof(pein_msgs::ModuleStatus));
      }
     return offset;
    }

    const char * getType(){ return STARTPERCEPTIONWITHROI; };
    const char * getMD5(){ return "081b500f3629ba2c5097ac8f3122eae0"; };

  };

  class StartPerceptionWithROIResponse : public ros::Msg
  {
    public:
      uint32_t error_code;
      char * error_msg;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->error_code >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->error_code >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->error_code >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->error_code >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_code);
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
      this->error_code =  ((uint32_t) (*(inbuffer + offset)));
      this->error_code |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->error_code |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->error_code |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->error_code);
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

    const char * getType(){ return STARTPERCEPTIONWITHROI; };
    const char * getMD5(){ return "217153dcade9618aa97e37fd1ee0bc01"; };

  };

  class StartPerceptionWithROI {
    public:
    typedef StartPerceptionWithROIRequest Request;
    typedef StartPerceptionWithROIResponse Response;
  };

}
#endif

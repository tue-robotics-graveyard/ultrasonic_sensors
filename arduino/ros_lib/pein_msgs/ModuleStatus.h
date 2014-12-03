#ifndef _ROS_pein_msgs_ModuleStatus_h
#define _ROS_pein_msgs_ModuleStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pein_msgs/ROI.h"

namespace pein_msgs
{

  class ModuleStatus : public ros::Msg
  {
    public:
      char * module;
      bool with_roi;
      pein_msgs::ROI roi;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_module = strlen( (const char*) this->module);
      memcpy(outbuffer + offset, &length_module, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->module, length_module);
      offset += length_module;
      union {
        bool real;
        uint8_t base;
      } u_with_roi;
      u_with_roi.real = this->with_roi;
      *(outbuffer + offset + 0) = (u_with_roi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->with_roi);
      offset += this->roi.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_module;
      memcpy(&length_module, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_module; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_module-1]=0;
      this->module = (char *)(inbuffer + offset-1);
      offset += length_module;
      union {
        bool real;
        uint8_t base;
      } u_with_roi;
      u_with_roi.base = 0;
      u_with_roi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->with_roi = u_with_roi.real;
      offset += sizeof(this->with_roi);
      offset += this->roi.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pein_msgs/ModuleStatus"; };
    const char * getMD5(){ return "ff31a68bd7581f3a61a1ff8850b2ee31"; };

  };

}
#endif
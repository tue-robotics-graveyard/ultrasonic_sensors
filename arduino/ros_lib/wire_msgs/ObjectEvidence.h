#ifndef _ROS_wire_msgs_ObjectEvidence_h
#define _ROS_wire_msgs_ObjectEvidence_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "wire_msgs/Property.h"

namespace wire_msgs
{

  class ObjectEvidence : public ros::Msg
  {
    public:
      float certainty;
      bool negative;
      char * ID;
      uint8_t properties_length;
      wire_msgs::Property st_properties;
      wire_msgs::Property * properties;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_certainty = (int32_t *) &(this->certainty);
      int32_t exp_certainty = (((*val_certainty)>>23)&255);
      if(exp_certainty != 0)
        exp_certainty += 1023-127;
      int32_t sig_certainty = *val_certainty;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_certainty<<5) & 0xff;
      *(outbuffer + offset++) = (sig_certainty>>3) & 0xff;
      *(outbuffer + offset++) = (sig_certainty>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_certainty<<4) & 0xF0) | ((sig_certainty>>19)&0x0F);
      *(outbuffer + offset++) = (exp_certainty>>4) & 0x7F;
      if(this->certainty < 0) *(outbuffer + offset -1) |= 0x80;
      union {
        bool real;
        uint8_t base;
      } u_negative;
      u_negative.real = this->negative;
      *(outbuffer + offset + 0) = (u_negative.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->negative);
      uint32_t length_ID = strlen( (const char*) this->ID);
      memcpy(outbuffer + offset, &length_ID, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ID, length_ID);
      offset += length_ID;
      *(outbuffer + offset++) = properties_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < properties_length; i++){
      offset += this->properties[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_certainty = (uint32_t*) &(this->certainty);
      offset += 3;
      *val_certainty = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_certainty |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_certainty |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_certainty |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_certainty = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_certainty |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_certainty !=0)
        *val_certainty |= ((exp_certainty)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->certainty = -this->certainty;
      union {
        bool real;
        uint8_t base;
      } u_negative;
      u_negative.base = 0;
      u_negative.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->negative = u_negative.real;
      offset += sizeof(this->negative);
      uint32_t length_ID;
      memcpy(&length_ID, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ID; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ID-1]=0;
      this->ID = (char *)(inbuffer + offset-1);
      offset += length_ID;
      uint8_t properties_lengthT = *(inbuffer + offset++);
      if(properties_lengthT > properties_length)
        this->properties = (wire_msgs::Property*)realloc(this->properties, properties_lengthT * sizeof(wire_msgs::Property));
      offset += 3;
      properties_length = properties_lengthT;
      for( uint8_t i = 0; i < properties_length; i++){
      offset += this->st_properties.deserialize(inbuffer + offset);
        memcpy( &(this->properties[i]), &(this->st_properties), sizeof(wire_msgs::Property));
      }
     return offset;
    }

    const char * getType(){ return "wire_msgs/ObjectEvidence"; };
    const char * getMD5(){ return "4671efa73c15b8d8b060828a1e07e1af"; };

  };

}
#endif
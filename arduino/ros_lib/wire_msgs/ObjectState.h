#ifndef _ROS_wire_msgs_ObjectState_h
#define _ROS_wire_msgs_ObjectState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "wire_msgs/Property.h"

namespace wire_msgs
{

  class ObjectState : public ros::Msg
  {
    public:
      char * ID;
      float probability;
      uint8_t properties_length;
      wire_msgs::Property st_properties;
      wire_msgs::Property * properties;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_ID = strlen( (const char*) this->ID);
      memcpy(outbuffer + offset, &length_ID, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ID, length_ID);
      offset += length_ID;
      int32_t * val_probability = (int32_t *) &(this->probability);
      int32_t exp_probability = (((*val_probability)>>23)&255);
      if(exp_probability != 0)
        exp_probability += 1023-127;
      int32_t sig_probability = *val_probability;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_probability<<5) & 0xff;
      *(outbuffer + offset++) = (sig_probability>>3) & 0xff;
      *(outbuffer + offset++) = (sig_probability>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_probability<<4) & 0xF0) | ((sig_probability>>19)&0x0F);
      *(outbuffer + offset++) = (exp_probability>>4) & 0x7F;
      if(this->probability < 0) *(outbuffer + offset -1) |= 0x80;
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
      uint32_t length_ID;
      memcpy(&length_ID, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ID; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ID-1]=0;
      this->ID = (char *)(inbuffer + offset-1);
      offset += length_ID;
      uint32_t * val_probability = (uint32_t*) &(this->probability);
      offset += 3;
      *val_probability = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_probability |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_probability |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_probability |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_probability = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_probability |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_probability !=0)
        *val_probability |= ((exp_probability)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->probability = -this->probability;
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

    const char * getType(){ return "wire_msgs/ObjectState"; };
    const char * getMD5(){ return "91ee83064ce6bebb5909df686db31818"; };

  };

}
#endif
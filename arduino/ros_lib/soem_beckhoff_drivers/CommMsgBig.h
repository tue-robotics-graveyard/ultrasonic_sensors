#ifndef _ROS_soem_beckhoff_drivers_CommMsgBig_h
#define _ROS_soem_beckhoff_drivers_CommMsgBig_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "soem_beckhoff_drivers/CommMsg.h"

namespace soem_beckhoff_drivers
{

  class CommMsgBig : public ros::Msg
  {
    public:
      uint8_t channels_length;
      soem_beckhoff_drivers::CommMsg st_channels;
      soem_beckhoff_drivers::CommMsg * channels;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = channels_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < channels_length; i++){
      offset += this->channels[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t channels_lengthT = *(inbuffer + offset++);
      if(channels_lengthT > channels_length)
        this->channels = (soem_beckhoff_drivers::CommMsg*)realloc(this->channels, channels_lengthT * sizeof(soem_beckhoff_drivers::CommMsg));
      offset += 3;
      channels_length = channels_lengthT;
      for( uint8_t i = 0; i < channels_length; i++){
      offset += this->st_channels.deserialize(inbuffer + offset);
        memcpy( &(this->channels[i]), &(this->st_channels), sizeof(soem_beckhoff_drivers::CommMsg));
      }
     return offset;
    }

    const char * getType(){ return "soem_beckhoff_drivers/CommMsgBig"; };
    const char * getMD5(){ return "9a82f040b0f86ae1565e078936798d4c"; };

  };

}
#endif
#ifndef _ROS_soem_beckhoff_drivers_CommMsg_h
#define _ROS_soem_beckhoff_drivers_CommMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace soem_beckhoff_drivers
{

  class CommMsg : public ros::Msg
  {
    public:
      uint8_t datapacket_length;
      uint8_t st_datapacket;
      uint8_t * datapacket;
      uint8_t datasize;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = datapacket_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < datapacket_length; i++){
      *(outbuffer + offset + 0) = (this->datapacket[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->datapacket[i]);
      }
      *(outbuffer + offset + 0) = (this->datasize >> (8 * 0)) & 0xFF;
      offset += sizeof(this->datasize);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t datapacket_lengthT = *(inbuffer + offset++);
      if(datapacket_lengthT > datapacket_length)
        this->datapacket = (uint8_t*)realloc(this->datapacket, datapacket_lengthT * sizeof(uint8_t));
      offset += 3;
      datapacket_length = datapacket_lengthT;
      for( uint8_t i = 0; i < datapacket_length; i++){
      this->st_datapacket =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_datapacket);
        memcpy( &(this->datapacket[i]), &(this->st_datapacket), sizeof(uint8_t));
      }
      this->datasize =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->datasize);
     return offset;
    }

    const char * getType(){ return "soem_beckhoff_drivers/CommMsg"; };
    const char * getMD5(){ return "8312abb0799e3ce28f5c343af99bc5eb"; };

  };

}
#endif
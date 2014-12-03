#ifndef _ROS_SERVICE_GetMeasurements_h
#define _ROS_SERVICE_GetMeasurements_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tue_serialization/Binary.h"

namespace ed
{

static const char GETMEASUREMENTS[] = "ed/GetMeasurements";

  class GetMeasurementsRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETMEASUREMENTS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetMeasurementsResponse : public ros::Msg
  {
    public:
      uint8_t ids_length;
      char* st_ids;
      char* * ids;
      uint8_t images_length;
      tue_serialization::Binary st_images;
      tue_serialization::Binary * images;
      char * msg;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = ids_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ids_length; i++){
      uint32_t length_idsi = strlen( (const char*) this->ids[i]);
      memcpy(outbuffer + offset, &length_idsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ids[i], length_idsi);
      offset += length_idsi;
      }
      *(outbuffer + offset++) = images_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < images_length; i++){
      offset += this->images[i].serialize(outbuffer + offset);
      }
      uint32_t length_msg = strlen( (const char*) this->msg);
      memcpy(outbuffer + offset, &length_msg, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t ids_lengthT = *(inbuffer + offset++);
      if(ids_lengthT > ids_length)
        this->ids = (char**)realloc(this->ids, ids_lengthT * sizeof(char*));
      offset += 3;
      ids_length = ids_lengthT;
      for( uint8_t i = 0; i < ids_length; i++){
      uint32_t length_st_ids;
      memcpy(&length_st_ids, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_ids; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_ids-1]=0;
      this->st_ids = (char *)(inbuffer + offset-1);
      offset += length_st_ids;
        memcpy( &(this->ids[i]), &(this->st_ids), sizeof(char*));
      }
      uint8_t images_lengthT = *(inbuffer + offset++);
      if(images_lengthT > images_length)
        this->images = (tue_serialization::Binary*)realloc(this->images, images_lengthT * sizeof(tue_serialization::Binary));
      offset += 3;
      images_length = images_lengthT;
      for( uint8_t i = 0; i < images_length; i++){
      offset += this->st_images.deserialize(inbuffer + offset);
        memcpy( &(this->images[i]), &(this->st_images), sizeof(tue_serialization::Binary));
      }
      uint32_t length_msg;
      memcpy(&length_msg, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
     return offset;
    }

    const char * getType(){ return GETMEASUREMENTS; };
    const char * getMD5(){ return "81034b37a28002a441085d4e59f92944"; };

  };

  class GetMeasurements {
    public:
    typedef GetMeasurementsRequest Request;
    typedef GetMeasurementsResponse Response;
  };

}
#endif

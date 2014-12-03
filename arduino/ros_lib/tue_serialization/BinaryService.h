#ifndef _ROS_SERVICE_BinaryService_h
#define _ROS_SERVICE_BinaryService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tue_serialization/Binary.h"

namespace tue_serialization
{

static const char BINARYSERVICE[] = "tue_serialization/BinaryService";

  class BinaryServiceRequest : public ros::Msg
  {
    public:
      tue_serialization::Binary bin;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->bin.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->bin.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return BINARYSERVICE; };
    const char * getMD5(){ return "cc3b9474f6a814dd3397c72deca44c52"; };

  };

  class BinaryServiceResponse : public ros::Msg
  {
    public:
      tue_serialization::Binary bin;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->bin.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->bin.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return BINARYSERVICE; };
    const char * getMD5(){ return "cc3b9474f6a814dd3397c72deca44c52"; };

  };

  class BinaryService {
    public:
    typedef BinaryServiceRequest Request;
    typedef BinaryServiceResponse Response;
  };

}
#endif

#ifndef _ROS_SERVICE_GetActionStatus_h
#define _ROS_SERVICE_GetActionStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace action_server
{

static const char GETACTIONSTATUS[] = "action_server/GetActionStatus";

  class GetActionStatusRequest : public ros::Msg
  {
    public:
      char * action_uuid;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_action_uuid = strlen( (const char*) this->action_uuid);
      memcpy(outbuffer + offset, &length_action_uuid, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->action_uuid, length_action_uuid);
      offset += length_action_uuid;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_action_uuid;
      memcpy(&length_action_uuid, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_action_uuid; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_action_uuid-1]=0;
      this->action_uuid = (char *)(inbuffer + offset-1);
      offset += length_action_uuid;
     return offset;
    }

    const char * getType(){ return GETACTIONSTATUS; };
    const char * getMD5(){ return "16e1c983402e10984cf999bdf38b6b14"; };

  };

  class GetActionStatusResponse : public ros::Msg
  {
    public:
      char * status;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_status = strlen( (const char*) this->status);
      memcpy(outbuffer + offset, &length_status, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_status;
      memcpy(&length_status, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status-1]=0;
      this->status = (char *)(inbuffer + offset-1);
      offset += length_status;
     return offset;
    }

    const char * getType(){ return GETACTIONSTATUS; };
    const char * getMD5(){ return "4fe5af303955c287688e7347e9b00278"; };

  };

  class GetActionStatus {
    public:
    typedef GetActionStatusRequest Request;
    typedef GetActionStatusResponse Response;
  };

}
#endif

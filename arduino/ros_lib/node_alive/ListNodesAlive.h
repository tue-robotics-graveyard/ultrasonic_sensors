#ifndef _ROS_SERVICE_ListNodesAlive_h
#define _ROS_SERVICE_ListNodesAlive_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace node_alive
{

static const char LISTNODESALIVE[] = "node_alive/ListNodesAlive";

  class ListNodesAliveRequest : public ros::Msg
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

    const char * getType(){ return LISTNODESALIVE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListNodesAliveResponse : public ros::Msg
  {
    public:
      uint32_t tracked_nodes;
      uint32_t seen_nodes;
      uint32_t alive_nodes;
      uint32_t listed_nodes;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->tracked_nodes >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tracked_nodes >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tracked_nodes >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tracked_nodes >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tracked_nodes);
      *(outbuffer + offset + 0) = (this->seen_nodes >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->seen_nodes >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->seen_nodes >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->seen_nodes >> (8 * 3)) & 0xFF;
      offset += sizeof(this->seen_nodes);
      *(outbuffer + offset + 0) = (this->alive_nodes >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->alive_nodes >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->alive_nodes >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->alive_nodes >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alive_nodes);
      *(outbuffer + offset + 0) = (this->listed_nodes >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->listed_nodes >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->listed_nodes >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->listed_nodes >> (8 * 3)) & 0xFF;
      offset += sizeof(this->listed_nodes);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->tracked_nodes =  ((uint32_t) (*(inbuffer + offset)));
      this->tracked_nodes |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tracked_nodes |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tracked_nodes |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tracked_nodes);
      this->seen_nodes =  ((uint32_t) (*(inbuffer + offset)));
      this->seen_nodes |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->seen_nodes |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->seen_nodes |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->seen_nodes);
      this->alive_nodes =  ((uint32_t) (*(inbuffer + offset)));
      this->alive_nodes |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->alive_nodes |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->alive_nodes |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->alive_nodes);
      this->listed_nodes =  ((uint32_t) (*(inbuffer + offset)));
      this->listed_nodes |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->listed_nodes |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->listed_nodes |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->listed_nodes);
     return offset;
    }

    const char * getType(){ return LISTNODESALIVE; };
    const char * getMD5(){ return "206cbe3e6af816a2d654986b53d52287"; };

  };

  class ListNodesAlive {
    public:
    typedef ListNodesAliveRequest Request;
    typedef ListNodesAliveResponse Response;
  };

}
#endif

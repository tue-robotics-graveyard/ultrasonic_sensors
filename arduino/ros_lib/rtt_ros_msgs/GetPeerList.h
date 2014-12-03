#ifndef _ROS_SERVICE_GetPeerList_h
#define _ROS_SERVICE_GetPeerList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rtt_ros_msgs
{

static const char GETPEERLIST[] = "rtt_ros_msgs/GetPeerList";

  class GetPeerListRequest : public ros::Msg
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

    const char * getType(){ return GETPEERLIST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetPeerListResponse : public ros::Msg
  {
    public:
      uint8_t peers_length;
      char* st_peers;
      char* * peers;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = peers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < peers_length; i++){
      uint32_t length_peersi = strlen( (const char*) this->peers[i]);
      memcpy(outbuffer + offset, &length_peersi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->peers[i], length_peersi);
      offset += length_peersi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t peers_lengthT = *(inbuffer + offset++);
      if(peers_lengthT > peers_length)
        this->peers = (char**)realloc(this->peers, peers_lengthT * sizeof(char*));
      offset += 3;
      peers_length = peers_lengthT;
      for( uint8_t i = 0; i < peers_length; i++){
      uint32_t length_st_peers;
      memcpy(&length_st_peers, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_peers; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_peers-1]=0;
      this->st_peers = (char *)(inbuffer + offset-1);
      offset += length_st_peers;
        memcpy( &(this->peers[i]), &(this->st_peers), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETPEERLIST; };
    const char * getMD5(){ return "6db093f77b4f8d943666a07989041c39"; };

  };

  class GetPeerList {
    public:
    typedef GetPeerListRequest Request;
    typedef GetPeerListResponse Response;
  };

}
#endif

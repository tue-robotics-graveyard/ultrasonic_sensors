#ifndef _ROS_hrpsys_ros_bridge_RTC_TimedDoubleSeq_h
#define _ROS_hrpsys_ros_bridge_RTC_TimedDoubleSeq_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/RTC_Time.h"

namespace hrpsys_ros_bridge
{

  class RTC_TimedDoubleSeq : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::RTC_Time tm;
      uint8_t data_length;
      float st_data;
      float * data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->tm.serialize(outbuffer + offset);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      int32_t * val_datai = (int32_t *) &(this->data[i]);
      int32_t exp_datai = (((*val_datai)>>23)&255);
      if(exp_datai != 0)
        exp_datai += 1023-127;
      int32_t sig_datai = *val_datai;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_datai<<5) & 0xff;
      *(outbuffer + offset++) = (sig_datai>>3) & 0xff;
      *(outbuffer + offset++) = (sig_datai>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_datai<<4) & 0xF0) | ((sig_datai>>19)&0x0F);
      *(outbuffer + offset++) = (exp_datai>>4) & 0x7F;
      if(this->data[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->tm.deserialize(inbuffer + offset);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (float*)realloc(this->data, data_lengthT * sizeof(float));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      uint32_t * val_st_data = (uint32_t*) &(this->st_data);
      offset += 3;
      *val_st_data = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_st_data |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_st_data |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_st_data |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_st_data = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_st_data |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_st_data !=0)
        *val_st_data |= ((exp_st_data)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->st_data = -this->st_data;
        memcpy( &(this->data[i]), &(this->st_data), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/RTC_TimedDoubleSeq"; };
    const char * getMD5(){ return "d9e01689e17707d99ff596edf800755c"; };

  };

}
#endif
#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_stParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_stParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StabilizerService_stParam : public ros::Msg
  {
    public:
      float k_tpcc_p[2];
      float k_tpcc_x[2];
      float k_brot_p[2];
      float k_brot_tc[2];
      float k_run_b[2];
      float d_run_b[2];
      float tdfke[2];
      float tdftc[2];
      float k_run_x;
      float k_run_y;
      float d_run_x;
      float d_run_y;
      float eefm_k1[2];
      float eefm_k2[2];
      float eefm_k3[2];
      float eefm_zmp_delay_time_const[2];
      float eefm_ref_zmp_aux[2];
      float eefm_rot_damping_gain;
      float eefm_rot_time_const;
      float eefm_pos_damping_gain;
      float eefm_pos_time_const_support;
      float eefm_pos_time_const_swing;
      float eefm_pos_transition_time;
      float eefm_leg_inside_margin;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      unsigned char * k_tpcc_p_val = (unsigned char *) this->k_tpcc_p;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_k_tpcc_pi = (int32_t *) &(this->k_tpcc_p[i]);
      int32_t exp_k_tpcc_pi = (((*val_k_tpcc_pi)>>23)&255);
      if(exp_k_tpcc_pi != 0)
        exp_k_tpcc_pi += 1023-127;
      int32_t sig_k_tpcc_pi = *val_k_tpcc_pi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_k_tpcc_pi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_k_tpcc_pi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_k_tpcc_pi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_k_tpcc_pi<<4) & 0xF0) | ((sig_k_tpcc_pi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_k_tpcc_pi>>4) & 0x7F;
      if(this->k_tpcc_p[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * k_tpcc_x_val = (unsigned char *) this->k_tpcc_x;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_k_tpcc_xi = (int32_t *) &(this->k_tpcc_x[i]);
      int32_t exp_k_tpcc_xi = (((*val_k_tpcc_xi)>>23)&255);
      if(exp_k_tpcc_xi != 0)
        exp_k_tpcc_xi += 1023-127;
      int32_t sig_k_tpcc_xi = *val_k_tpcc_xi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_k_tpcc_xi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_k_tpcc_xi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_k_tpcc_xi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_k_tpcc_xi<<4) & 0xF0) | ((sig_k_tpcc_xi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_k_tpcc_xi>>4) & 0x7F;
      if(this->k_tpcc_x[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * k_brot_p_val = (unsigned char *) this->k_brot_p;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_k_brot_pi = (int32_t *) &(this->k_brot_p[i]);
      int32_t exp_k_brot_pi = (((*val_k_brot_pi)>>23)&255);
      if(exp_k_brot_pi != 0)
        exp_k_brot_pi += 1023-127;
      int32_t sig_k_brot_pi = *val_k_brot_pi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_k_brot_pi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_k_brot_pi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_k_brot_pi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_k_brot_pi<<4) & 0xF0) | ((sig_k_brot_pi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_k_brot_pi>>4) & 0x7F;
      if(this->k_brot_p[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * k_brot_tc_val = (unsigned char *) this->k_brot_tc;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_k_brot_tci = (int32_t *) &(this->k_brot_tc[i]);
      int32_t exp_k_brot_tci = (((*val_k_brot_tci)>>23)&255);
      if(exp_k_brot_tci != 0)
        exp_k_brot_tci += 1023-127;
      int32_t sig_k_brot_tci = *val_k_brot_tci;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_k_brot_tci<<5) & 0xff;
      *(outbuffer + offset++) = (sig_k_brot_tci>>3) & 0xff;
      *(outbuffer + offset++) = (sig_k_brot_tci>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_k_brot_tci<<4) & 0xF0) | ((sig_k_brot_tci>>19)&0x0F);
      *(outbuffer + offset++) = (exp_k_brot_tci>>4) & 0x7F;
      if(this->k_brot_tc[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * k_run_b_val = (unsigned char *) this->k_run_b;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_k_run_bi = (int32_t *) &(this->k_run_b[i]);
      int32_t exp_k_run_bi = (((*val_k_run_bi)>>23)&255);
      if(exp_k_run_bi != 0)
        exp_k_run_bi += 1023-127;
      int32_t sig_k_run_bi = *val_k_run_bi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_k_run_bi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_k_run_bi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_k_run_bi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_k_run_bi<<4) & 0xF0) | ((sig_k_run_bi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_k_run_bi>>4) & 0x7F;
      if(this->k_run_b[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * d_run_b_val = (unsigned char *) this->d_run_b;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_d_run_bi = (int32_t *) &(this->d_run_b[i]);
      int32_t exp_d_run_bi = (((*val_d_run_bi)>>23)&255);
      if(exp_d_run_bi != 0)
        exp_d_run_bi += 1023-127;
      int32_t sig_d_run_bi = *val_d_run_bi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_d_run_bi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_d_run_bi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_d_run_bi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_d_run_bi<<4) & 0xF0) | ((sig_d_run_bi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_d_run_bi>>4) & 0x7F;
      if(this->d_run_b[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * tdfke_val = (unsigned char *) this->tdfke;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_tdfkei = (int32_t *) &(this->tdfke[i]);
      int32_t exp_tdfkei = (((*val_tdfkei)>>23)&255);
      if(exp_tdfkei != 0)
        exp_tdfkei += 1023-127;
      int32_t sig_tdfkei = *val_tdfkei;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_tdfkei<<5) & 0xff;
      *(outbuffer + offset++) = (sig_tdfkei>>3) & 0xff;
      *(outbuffer + offset++) = (sig_tdfkei>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_tdfkei<<4) & 0xF0) | ((sig_tdfkei>>19)&0x0F);
      *(outbuffer + offset++) = (exp_tdfkei>>4) & 0x7F;
      if(this->tdfke[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * tdftc_val = (unsigned char *) this->tdftc;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_tdftci = (int32_t *) &(this->tdftc[i]);
      int32_t exp_tdftci = (((*val_tdftci)>>23)&255);
      if(exp_tdftci != 0)
        exp_tdftci += 1023-127;
      int32_t sig_tdftci = *val_tdftci;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_tdftci<<5) & 0xff;
      *(outbuffer + offset++) = (sig_tdftci>>3) & 0xff;
      *(outbuffer + offset++) = (sig_tdftci>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_tdftci<<4) & 0xF0) | ((sig_tdftci>>19)&0x0F);
      *(outbuffer + offset++) = (exp_tdftci>>4) & 0x7F;
      if(this->tdftc[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      int32_t * val_k_run_x = (int32_t *) &(this->k_run_x);
      int32_t exp_k_run_x = (((*val_k_run_x)>>23)&255);
      if(exp_k_run_x != 0)
        exp_k_run_x += 1023-127;
      int32_t sig_k_run_x = *val_k_run_x;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_k_run_x<<5) & 0xff;
      *(outbuffer + offset++) = (sig_k_run_x>>3) & 0xff;
      *(outbuffer + offset++) = (sig_k_run_x>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_k_run_x<<4) & 0xF0) | ((sig_k_run_x>>19)&0x0F);
      *(outbuffer + offset++) = (exp_k_run_x>>4) & 0x7F;
      if(this->k_run_x < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_k_run_y = (int32_t *) &(this->k_run_y);
      int32_t exp_k_run_y = (((*val_k_run_y)>>23)&255);
      if(exp_k_run_y != 0)
        exp_k_run_y += 1023-127;
      int32_t sig_k_run_y = *val_k_run_y;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_k_run_y<<5) & 0xff;
      *(outbuffer + offset++) = (sig_k_run_y>>3) & 0xff;
      *(outbuffer + offset++) = (sig_k_run_y>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_k_run_y<<4) & 0xF0) | ((sig_k_run_y>>19)&0x0F);
      *(outbuffer + offset++) = (exp_k_run_y>>4) & 0x7F;
      if(this->k_run_y < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_d_run_x = (int32_t *) &(this->d_run_x);
      int32_t exp_d_run_x = (((*val_d_run_x)>>23)&255);
      if(exp_d_run_x != 0)
        exp_d_run_x += 1023-127;
      int32_t sig_d_run_x = *val_d_run_x;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_d_run_x<<5) & 0xff;
      *(outbuffer + offset++) = (sig_d_run_x>>3) & 0xff;
      *(outbuffer + offset++) = (sig_d_run_x>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_d_run_x<<4) & 0xF0) | ((sig_d_run_x>>19)&0x0F);
      *(outbuffer + offset++) = (exp_d_run_x>>4) & 0x7F;
      if(this->d_run_x < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_d_run_y = (int32_t *) &(this->d_run_y);
      int32_t exp_d_run_y = (((*val_d_run_y)>>23)&255);
      if(exp_d_run_y != 0)
        exp_d_run_y += 1023-127;
      int32_t sig_d_run_y = *val_d_run_y;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_d_run_y<<5) & 0xff;
      *(outbuffer + offset++) = (sig_d_run_y>>3) & 0xff;
      *(outbuffer + offset++) = (sig_d_run_y>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_d_run_y<<4) & 0xF0) | ((sig_d_run_y>>19)&0x0F);
      *(outbuffer + offset++) = (exp_d_run_y>>4) & 0x7F;
      if(this->d_run_y < 0) *(outbuffer + offset -1) |= 0x80;
      unsigned char * eefm_k1_val = (unsigned char *) this->eefm_k1;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_eefm_k1i = (int32_t *) &(this->eefm_k1[i]);
      int32_t exp_eefm_k1i = (((*val_eefm_k1i)>>23)&255);
      if(exp_eefm_k1i != 0)
        exp_eefm_k1i += 1023-127;
      int32_t sig_eefm_k1i = *val_eefm_k1i;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_eefm_k1i<<5) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_k1i>>3) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_k1i>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_eefm_k1i<<4) & 0xF0) | ((sig_eefm_k1i>>19)&0x0F);
      *(outbuffer + offset++) = (exp_eefm_k1i>>4) & 0x7F;
      if(this->eefm_k1[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * eefm_k2_val = (unsigned char *) this->eefm_k2;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_eefm_k2i = (int32_t *) &(this->eefm_k2[i]);
      int32_t exp_eefm_k2i = (((*val_eefm_k2i)>>23)&255);
      if(exp_eefm_k2i != 0)
        exp_eefm_k2i += 1023-127;
      int32_t sig_eefm_k2i = *val_eefm_k2i;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_eefm_k2i<<5) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_k2i>>3) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_k2i>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_eefm_k2i<<4) & 0xF0) | ((sig_eefm_k2i>>19)&0x0F);
      *(outbuffer + offset++) = (exp_eefm_k2i>>4) & 0x7F;
      if(this->eefm_k2[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * eefm_k3_val = (unsigned char *) this->eefm_k3;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_eefm_k3i = (int32_t *) &(this->eefm_k3[i]);
      int32_t exp_eefm_k3i = (((*val_eefm_k3i)>>23)&255);
      if(exp_eefm_k3i != 0)
        exp_eefm_k3i += 1023-127;
      int32_t sig_eefm_k3i = *val_eefm_k3i;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_eefm_k3i<<5) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_k3i>>3) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_k3i>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_eefm_k3i<<4) & 0xF0) | ((sig_eefm_k3i>>19)&0x0F);
      *(outbuffer + offset++) = (exp_eefm_k3i>>4) & 0x7F;
      if(this->eefm_k3[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * eefm_zmp_delay_time_const_val = (unsigned char *) this->eefm_zmp_delay_time_const;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_eefm_zmp_delay_time_consti = (int32_t *) &(this->eefm_zmp_delay_time_const[i]);
      int32_t exp_eefm_zmp_delay_time_consti = (((*val_eefm_zmp_delay_time_consti)>>23)&255);
      if(exp_eefm_zmp_delay_time_consti != 0)
        exp_eefm_zmp_delay_time_consti += 1023-127;
      int32_t sig_eefm_zmp_delay_time_consti = *val_eefm_zmp_delay_time_consti;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_eefm_zmp_delay_time_consti<<5) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_zmp_delay_time_consti>>3) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_zmp_delay_time_consti>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_eefm_zmp_delay_time_consti<<4) & 0xF0) | ((sig_eefm_zmp_delay_time_consti>>19)&0x0F);
      *(outbuffer + offset++) = (exp_eefm_zmp_delay_time_consti>>4) & 0x7F;
      if(this->eefm_zmp_delay_time_const[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      unsigned char * eefm_ref_zmp_aux_val = (unsigned char *) this->eefm_ref_zmp_aux;
      for( uint8_t i = 0; i < 2; i++){
      int32_t * val_eefm_ref_zmp_auxi = (int32_t *) &(this->eefm_ref_zmp_aux[i]);
      int32_t exp_eefm_ref_zmp_auxi = (((*val_eefm_ref_zmp_auxi)>>23)&255);
      if(exp_eefm_ref_zmp_auxi != 0)
        exp_eefm_ref_zmp_auxi += 1023-127;
      int32_t sig_eefm_ref_zmp_auxi = *val_eefm_ref_zmp_auxi;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_eefm_ref_zmp_auxi<<5) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_ref_zmp_auxi>>3) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_ref_zmp_auxi>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_eefm_ref_zmp_auxi<<4) & 0xF0) | ((sig_eefm_ref_zmp_auxi>>19)&0x0F);
      *(outbuffer + offset++) = (exp_eefm_ref_zmp_auxi>>4) & 0x7F;
      if(this->eefm_ref_zmp_aux[i] < 0) *(outbuffer + offset -1) |= 0x80;
      }
      int32_t * val_eefm_rot_damping_gain = (int32_t *) &(this->eefm_rot_damping_gain);
      int32_t exp_eefm_rot_damping_gain = (((*val_eefm_rot_damping_gain)>>23)&255);
      if(exp_eefm_rot_damping_gain != 0)
        exp_eefm_rot_damping_gain += 1023-127;
      int32_t sig_eefm_rot_damping_gain = *val_eefm_rot_damping_gain;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_eefm_rot_damping_gain<<5) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_rot_damping_gain>>3) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_rot_damping_gain>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_eefm_rot_damping_gain<<4) & 0xF0) | ((sig_eefm_rot_damping_gain>>19)&0x0F);
      *(outbuffer + offset++) = (exp_eefm_rot_damping_gain>>4) & 0x7F;
      if(this->eefm_rot_damping_gain < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_eefm_rot_time_const = (int32_t *) &(this->eefm_rot_time_const);
      int32_t exp_eefm_rot_time_const = (((*val_eefm_rot_time_const)>>23)&255);
      if(exp_eefm_rot_time_const != 0)
        exp_eefm_rot_time_const += 1023-127;
      int32_t sig_eefm_rot_time_const = *val_eefm_rot_time_const;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_eefm_rot_time_const<<5) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_rot_time_const>>3) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_rot_time_const>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_eefm_rot_time_const<<4) & 0xF0) | ((sig_eefm_rot_time_const>>19)&0x0F);
      *(outbuffer + offset++) = (exp_eefm_rot_time_const>>4) & 0x7F;
      if(this->eefm_rot_time_const < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_eefm_pos_damping_gain = (int32_t *) &(this->eefm_pos_damping_gain);
      int32_t exp_eefm_pos_damping_gain = (((*val_eefm_pos_damping_gain)>>23)&255);
      if(exp_eefm_pos_damping_gain != 0)
        exp_eefm_pos_damping_gain += 1023-127;
      int32_t sig_eefm_pos_damping_gain = *val_eefm_pos_damping_gain;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_eefm_pos_damping_gain<<5) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_pos_damping_gain>>3) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_pos_damping_gain>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_eefm_pos_damping_gain<<4) & 0xF0) | ((sig_eefm_pos_damping_gain>>19)&0x0F);
      *(outbuffer + offset++) = (exp_eefm_pos_damping_gain>>4) & 0x7F;
      if(this->eefm_pos_damping_gain < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_eefm_pos_time_const_support = (int32_t *) &(this->eefm_pos_time_const_support);
      int32_t exp_eefm_pos_time_const_support = (((*val_eefm_pos_time_const_support)>>23)&255);
      if(exp_eefm_pos_time_const_support != 0)
        exp_eefm_pos_time_const_support += 1023-127;
      int32_t sig_eefm_pos_time_const_support = *val_eefm_pos_time_const_support;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_eefm_pos_time_const_support<<5) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_pos_time_const_support>>3) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_pos_time_const_support>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_eefm_pos_time_const_support<<4) & 0xF0) | ((sig_eefm_pos_time_const_support>>19)&0x0F);
      *(outbuffer + offset++) = (exp_eefm_pos_time_const_support>>4) & 0x7F;
      if(this->eefm_pos_time_const_support < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_eefm_pos_time_const_swing = (int32_t *) &(this->eefm_pos_time_const_swing);
      int32_t exp_eefm_pos_time_const_swing = (((*val_eefm_pos_time_const_swing)>>23)&255);
      if(exp_eefm_pos_time_const_swing != 0)
        exp_eefm_pos_time_const_swing += 1023-127;
      int32_t sig_eefm_pos_time_const_swing = *val_eefm_pos_time_const_swing;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_eefm_pos_time_const_swing<<5) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_pos_time_const_swing>>3) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_pos_time_const_swing>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_eefm_pos_time_const_swing<<4) & 0xF0) | ((sig_eefm_pos_time_const_swing>>19)&0x0F);
      *(outbuffer + offset++) = (exp_eefm_pos_time_const_swing>>4) & 0x7F;
      if(this->eefm_pos_time_const_swing < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_eefm_pos_transition_time = (int32_t *) &(this->eefm_pos_transition_time);
      int32_t exp_eefm_pos_transition_time = (((*val_eefm_pos_transition_time)>>23)&255);
      if(exp_eefm_pos_transition_time != 0)
        exp_eefm_pos_transition_time += 1023-127;
      int32_t sig_eefm_pos_transition_time = *val_eefm_pos_transition_time;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_eefm_pos_transition_time<<5) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_pos_transition_time>>3) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_pos_transition_time>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_eefm_pos_transition_time<<4) & 0xF0) | ((sig_eefm_pos_transition_time>>19)&0x0F);
      *(outbuffer + offset++) = (exp_eefm_pos_transition_time>>4) & 0x7F;
      if(this->eefm_pos_transition_time < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_eefm_leg_inside_margin = (int32_t *) &(this->eefm_leg_inside_margin);
      int32_t exp_eefm_leg_inside_margin = (((*val_eefm_leg_inside_margin)>>23)&255);
      if(exp_eefm_leg_inside_margin != 0)
        exp_eefm_leg_inside_margin += 1023-127;
      int32_t sig_eefm_leg_inside_margin = *val_eefm_leg_inside_margin;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_eefm_leg_inside_margin<<5) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_leg_inside_margin>>3) & 0xff;
      *(outbuffer + offset++) = (sig_eefm_leg_inside_margin>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_eefm_leg_inside_margin<<4) & 0xF0) | ((sig_eefm_leg_inside_margin>>19)&0x0F);
      *(outbuffer + offset++) = (exp_eefm_leg_inside_margin>>4) & 0x7F;
      if(this->eefm_leg_inside_margin < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t * k_tpcc_p_val = (uint8_t*) this->k_tpcc_p;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_k_tpcc_pi = (uint32_t*) &(this->k_tpcc_p[i]);
      offset += 3;
      *val_k_tpcc_pi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_k_tpcc_pi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_k_tpcc_pi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_k_tpcc_pi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_k_tpcc_pi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_k_tpcc_pi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_k_tpcc_pi !=0)
        *val_k_tpcc_pi |= ((exp_k_tpcc_pi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->k_tpcc_p[i] = -this->k_tpcc_p[i];
      }
      uint8_t * k_tpcc_x_val = (uint8_t*) this->k_tpcc_x;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_k_tpcc_xi = (uint32_t*) &(this->k_tpcc_x[i]);
      offset += 3;
      *val_k_tpcc_xi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_k_tpcc_xi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_k_tpcc_xi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_k_tpcc_xi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_k_tpcc_xi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_k_tpcc_xi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_k_tpcc_xi !=0)
        *val_k_tpcc_xi |= ((exp_k_tpcc_xi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->k_tpcc_x[i] = -this->k_tpcc_x[i];
      }
      uint8_t * k_brot_p_val = (uint8_t*) this->k_brot_p;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_k_brot_pi = (uint32_t*) &(this->k_brot_p[i]);
      offset += 3;
      *val_k_brot_pi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_k_brot_pi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_k_brot_pi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_k_brot_pi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_k_brot_pi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_k_brot_pi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_k_brot_pi !=0)
        *val_k_brot_pi |= ((exp_k_brot_pi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->k_brot_p[i] = -this->k_brot_p[i];
      }
      uint8_t * k_brot_tc_val = (uint8_t*) this->k_brot_tc;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_k_brot_tci = (uint32_t*) &(this->k_brot_tc[i]);
      offset += 3;
      *val_k_brot_tci = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_k_brot_tci |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_k_brot_tci |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_k_brot_tci |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_k_brot_tci = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_k_brot_tci |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_k_brot_tci !=0)
        *val_k_brot_tci |= ((exp_k_brot_tci)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->k_brot_tc[i] = -this->k_brot_tc[i];
      }
      uint8_t * k_run_b_val = (uint8_t*) this->k_run_b;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_k_run_bi = (uint32_t*) &(this->k_run_b[i]);
      offset += 3;
      *val_k_run_bi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_k_run_bi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_k_run_bi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_k_run_bi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_k_run_bi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_k_run_bi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_k_run_bi !=0)
        *val_k_run_bi |= ((exp_k_run_bi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->k_run_b[i] = -this->k_run_b[i];
      }
      uint8_t * d_run_b_val = (uint8_t*) this->d_run_b;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_d_run_bi = (uint32_t*) &(this->d_run_b[i]);
      offset += 3;
      *val_d_run_bi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_d_run_bi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_d_run_bi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_d_run_bi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_d_run_bi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_d_run_bi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_d_run_bi !=0)
        *val_d_run_bi |= ((exp_d_run_bi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->d_run_b[i] = -this->d_run_b[i];
      }
      uint8_t * tdfke_val = (uint8_t*) this->tdfke;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_tdfkei = (uint32_t*) &(this->tdfke[i]);
      offset += 3;
      *val_tdfkei = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_tdfkei |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_tdfkei |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_tdfkei |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_tdfkei = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_tdfkei |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_tdfkei !=0)
        *val_tdfkei |= ((exp_tdfkei)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->tdfke[i] = -this->tdfke[i];
      }
      uint8_t * tdftc_val = (uint8_t*) this->tdftc;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_tdftci = (uint32_t*) &(this->tdftc[i]);
      offset += 3;
      *val_tdftci = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_tdftci |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_tdftci |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_tdftci |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_tdftci = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_tdftci |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_tdftci !=0)
        *val_tdftci |= ((exp_tdftci)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->tdftc[i] = -this->tdftc[i];
      }
      uint32_t * val_k_run_x = (uint32_t*) &(this->k_run_x);
      offset += 3;
      *val_k_run_x = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_k_run_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_k_run_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_k_run_x |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_k_run_x = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_k_run_x |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_k_run_x !=0)
        *val_k_run_x |= ((exp_k_run_x)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->k_run_x = -this->k_run_x;
      uint32_t * val_k_run_y = (uint32_t*) &(this->k_run_y);
      offset += 3;
      *val_k_run_y = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_k_run_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_k_run_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_k_run_y |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_k_run_y = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_k_run_y |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_k_run_y !=0)
        *val_k_run_y |= ((exp_k_run_y)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->k_run_y = -this->k_run_y;
      uint32_t * val_d_run_x = (uint32_t*) &(this->d_run_x);
      offset += 3;
      *val_d_run_x = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_d_run_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_d_run_x |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_d_run_x |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_d_run_x = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_d_run_x |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_d_run_x !=0)
        *val_d_run_x |= ((exp_d_run_x)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->d_run_x = -this->d_run_x;
      uint32_t * val_d_run_y = (uint32_t*) &(this->d_run_y);
      offset += 3;
      *val_d_run_y = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_d_run_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_d_run_y |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_d_run_y |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_d_run_y = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_d_run_y |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_d_run_y !=0)
        *val_d_run_y |= ((exp_d_run_y)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->d_run_y = -this->d_run_y;
      uint8_t * eefm_k1_val = (uint8_t*) this->eefm_k1;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_eefm_k1i = (uint32_t*) &(this->eefm_k1[i]);
      offset += 3;
      *val_eefm_k1i = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_eefm_k1i |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_eefm_k1i |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_eefm_k1i |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_eefm_k1i = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_eefm_k1i |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_eefm_k1i !=0)
        *val_eefm_k1i |= ((exp_eefm_k1i)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->eefm_k1[i] = -this->eefm_k1[i];
      }
      uint8_t * eefm_k2_val = (uint8_t*) this->eefm_k2;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_eefm_k2i = (uint32_t*) &(this->eefm_k2[i]);
      offset += 3;
      *val_eefm_k2i = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_eefm_k2i |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_eefm_k2i |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_eefm_k2i |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_eefm_k2i = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_eefm_k2i |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_eefm_k2i !=0)
        *val_eefm_k2i |= ((exp_eefm_k2i)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->eefm_k2[i] = -this->eefm_k2[i];
      }
      uint8_t * eefm_k3_val = (uint8_t*) this->eefm_k3;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_eefm_k3i = (uint32_t*) &(this->eefm_k3[i]);
      offset += 3;
      *val_eefm_k3i = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_eefm_k3i |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_eefm_k3i |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_eefm_k3i |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_eefm_k3i = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_eefm_k3i |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_eefm_k3i !=0)
        *val_eefm_k3i |= ((exp_eefm_k3i)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->eefm_k3[i] = -this->eefm_k3[i];
      }
      uint8_t * eefm_zmp_delay_time_const_val = (uint8_t*) this->eefm_zmp_delay_time_const;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_eefm_zmp_delay_time_consti = (uint32_t*) &(this->eefm_zmp_delay_time_const[i]);
      offset += 3;
      *val_eefm_zmp_delay_time_consti = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_eefm_zmp_delay_time_consti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_eefm_zmp_delay_time_consti |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_eefm_zmp_delay_time_consti |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_eefm_zmp_delay_time_consti = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_eefm_zmp_delay_time_consti |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_eefm_zmp_delay_time_consti !=0)
        *val_eefm_zmp_delay_time_consti |= ((exp_eefm_zmp_delay_time_consti)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->eefm_zmp_delay_time_const[i] = -this->eefm_zmp_delay_time_const[i];
      }
      uint8_t * eefm_ref_zmp_aux_val = (uint8_t*) this->eefm_ref_zmp_aux;
      for( uint8_t i = 0; i < 2; i++){
      uint32_t * val_eefm_ref_zmp_auxi = (uint32_t*) &(this->eefm_ref_zmp_aux[i]);
      offset += 3;
      *val_eefm_ref_zmp_auxi = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_eefm_ref_zmp_auxi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_eefm_ref_zmp_auxi |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_eefm_ref_zmp_auxi |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_eefm_ref_zmp_auxi = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_eefm_ref_zmp_auxi |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_eefm_ref_zmp_auxi !=0)
        *val_eefm_ref_zmp_auxi |= ((exp_eefm_ref_zmp_auxi)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->eefm_ref_zmp_aux[i] = -this->eefm_ref_zmp_aux[i];
      }
      uint32_t * val_eefm_rot_damping_gain = (uint32_t*) &(this->eefm_rot_damping_gain);
      offset += 3;
      *val_eefm_rot_damping_gain = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_eefm_rot_damping_gain |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_eefm_rot_damping_gain |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_eefm_rot_damping_gain |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_eefm_rot_damping_gain = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_eefm_rot_damping_gain |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_eefm_rot_damping_gain !=0)
        *val_eefm_rot_damping_gain |= ((exp_eefm_rot_damping_gain)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->eefm_rot_damping_gain = -this->eefm_rot_damping_gain;
      uint32_t * val_eefm_rot_time_const = (uint32_t*) &(this->eefm_rot_time_const);
      offset += 3;
      *val_eefm_rot_time_const = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_eefm_rot_time_const |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_eefm_rot_time_const |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_eefm_rot_time_const |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_eefm_rot_time_const = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_eefm_rot_time_const |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_eefm_rot_time_const !=0)
        *val_eefm_rot_time_const |= ((exp_eefm_rot_time_const)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->eefm_rot_time_const = -this->eefm_rot_time_const;
      uint32_t * val_eefm_pos_damping_gain = (uint32_t*) &(this->eefm_pos_damping_gain);
      offset += 3;
      *val_eefm_pos_damping_gain = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_eefm_pos_damping_gain |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_eefm_pos_damping_gain |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_eefm_pos_damping_gain |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_eefm_pos_damping_gain = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_eefm_pos_damping_gain |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_eefm_pos_damping_gain !=0)
        *val_eefm_pos_damping_gain |= ((exp_eefm_pos_damping_gain)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->eefm_pos_damping_gain = -this->eefm_pos_damping_gain;
      uint32_t * val_eefm_pos_time_const_support = (uint32_t*) &(this->eefm_pos_time_const_support);
      offset += 3;
      *val_eefm_pos_time_const_support = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_eefm_pos_time_const_support |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_eefm_pos_time_const_support |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_eefm_pos_time_const_support |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_eefm_pos_time_const_support = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_eefm_pos_time_const_support |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_eefm_pos_time_const_support !=0)
        *val_eefm_pos_time_const_support |= ((exp_eefm_pos_time_const_support)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->eefm_pos_time_const_support = -this->eefm_pos_time_const_support;
      uint32_t * val_eefm_pos_time_const_swing = (uint32_t*) &(this->eefm_pos_time_const_swing);
      offset += 3;
      *val_eefm_pos_time_const_swing = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_eefm_pos_time_const_swing |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_eefm_pos_time_const_swing |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_eefm_pos_time_const_swing |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_eefm_pos_time_const_swing = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_eefm_pos_time_const_swing |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_eefm_pos_time_const_swing !=0)
        *val_eefm_pos_time_const_swing |= ((exp_eefm_pos_time_const_swing)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->eefm_pos_time_const_swing = -this->eefm_pos_time_const_swing;
      uint32_t * val_eefm_pos_transition_time = (uint32_t*) &(this->eefm_pos_transition_time);
      offset += 3;
      *val_eefm_pos_transition_time = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_eefm_pos_transition_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_eefm_pos_transition_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_eefm_pos_transition_time |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_eefm_pos_transition_time = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_eefm_pos_transition_time |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_eefm_pos_transition_time !=0)
        *val_eefm_pos_transition_time |= ((exp_eefm_pos_transition_time)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->eefm_pos_transition_time = -this->eefm_pos_transition_time;
      uint32_t * val_eefm_leg_inside_margin = (uint32_t*) &(this->eefm_leg_inside_margin);
      offset += 3;
      *val_eefm_leg_inside_margin = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_eefm_leg_inside_margin |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_eefm_leg_inside_margin |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_eefm_leg_inside_margin |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_eefm_leg_inside_margin = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_eefm_leg_inside_margin |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_eefm_leg_inside_margin !=0)
        *val_eefm_leg_inside_margin |= ((exp_eefm_leg_inside_margin)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->eefm_leg_inside_margin = -this->eefm_leg_inside_margin;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StabilizerService_stParam"; };
    const char * getMD5(){ return "bd09d1e261888d76bb995618f0b6fbde"; };

  };

}
#endif
/*
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *	* Redistributions of source code must retain the above copyright
 *	  notice, this list of conditions and the following disclaimer.
 *
 *	* Redistributions in binary form must reproduce the above copyright
 *	  notice, this list of conditions and the following disclaimer in the
 *	  documentation and/or other materials provided with the
 *	  distribution.
 *
 *	* Neither the name of Texas Instruments Incorporated nor the names of
 *	  its contributors may be used to endorse or promote products derived
 *	  from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
#ifndef _ICSSG_IEP_PWM_H_
#define _ICSSG_IEP_PWM_H_ 

/* ICSSG INTC events */
/* Compile-time Host event for IEP0 CMP0 event, pr0_pru_mst_intr[2]_intr_req,
   ideally Host would provide this to FW */
#define TRIGGER_HOST_EVT   ( 18 ) /* 2+16 */

/*
 * Firmware global registers
 */

/* Firmware Information Registers */
#define ICSSG_IEPPWM_FW_MAGIC_NUMBER_ADDR                   ( 0x0000 )
#define ICSSG_IEPPWM_FW_TYPE_ADDR                           ( 0x0004 )
#define ICSSG_IEPPWM_FW_VERSION_ADDR                        ( 0x0008 )
#define ICSSG_IEPPWM_FW_FEATURE_ADDR                        ( 0x000C )
#define ICSSG_IEPPWM_FW_EXT_FEATURE_ADDR                    ( 0x0010 )

/* PWM Control/Status Registers */
#define ICSSG_IEPPWM_PWM_CTRL_ADDR                          ( 0x0014 )
#define ICSSG_IEPPWM_PWM_STAT_ADDR                          ( 0x0018 )

/* 
 * Firmware global register bit fields 
 */
/* Firmware Magic Number */
#define FW_MAGIC_NUM_BYTE0_MASK                             ( 0xF )
#define FW_MAGIC_NUM_BYTE1_MASK                             ( 0xF )
#define FW_MAGIC_NUM_BYTE2_MASK                             ( 0xF )
#define FW_MAGIC_NUM_BYTE3_MASK                             ( 0xF )
#define FW_MAGIC_NUM_MN_BYTE0_SHIFT                         (  0 )
#define FW_MAGIC_NUM_MN_BYTE0_MASK                          ( FW_MAGIC_NUM_BYTE0_MASK << FW_MAGIC_NUM_MN_BYTE0_SHIFT )
#define FW_MAGIC_NUM_MN_BYTE1_SHIFT                         (  8 )
#define FW_MAGIC_NUM_MN_BYTE1_MASK                          ( FW_MAGIC_NUM_BYTE1_MASK << FW_MAGIC_NUM_MN_BYTE1_SHIFT )
#define FW_MAGIC_NUM_MN_BYTE2_SHIFT                         ( 16 )
#define FW_MAGIC_NUM_MN_BYTE2_MASK                          ( FW_MAGIC_NUM_BYTE2_MASK << FW_MAGIC_NUM_MN_BYTE2_SHIFT )
#define FW_MAGIC_NUM_MN_BYTE3_SHIFT                         ( 24 )
#define FW_MAGIC_NUM_MN_BYTE3_MASK                          ( FW_MAGIC_NUM_BYTE3_MASK << FW_MAGIC_NUM_MN_BYTE3_SHIFT )

/* Firmware Type */
#define FW_PROTOCOL_TYPE_VERSION_MASK                       ( 0xF )
#define FW_PROTOCOL_TYPE_MASK                               ( 0xFF )
#define FW_ICSS_VERSION_MASK                                ( 0xF )
#define FW_TYPE_FW_PROTOCOL_TYPE_VERSION_SHIFT              ( 0 )
#define FW_TYPE_FW_PROTOCOL_TYPE_VERSION_MASK               ( FW_PROTOCOL_TYPE_VERSION_MASK << FW_TYPE_FW_PROTOCOL_TYPE_VERSION_SHIFT )
#define FW_TYPE_FW_PROTOCOL_TYPE_SHIFT                      ( 8 )
#define FW_TYPE_FW_PROTOCOL_TYPE_MASK                       ( FW_PROTOCOL_TYPE_MASK << FW_TYPE_FW_PROTOCOL_TYPE_SHIFT )
#define FW_TYPE_FW_ICSS_VERSION_SHIFT                       ( 24 )
#define FW_TYPE_FW_ICSS_VERSION_MASK                        ( FW_ICSS_VERSION_MASK << FW_TYPE_FW_ICSS_VERSION_SHIFT )

/* Firmware Version */
#define FW_VER_BUILD_MASK                                   ( 0xF )
#define FW_VER_MINOR_MASK                                   ( 0xFF )
#define FW_VER_MAJOR_MASK                                   ( 0x7F )
#define FW_REL_OR_INT_VER_MASK                              ( 0x1 )
#define FW_VERSION_FW_VER_BUILD_SHIFT                       (  0 )
#define FW_VERSION_FW_VER_BUILD_MASK                        ( FW_VER_BUILD_MASK << FW_VERSION_FW_VER_BUILD_SHIFT )
#define FW_VERSION_FW_VER_MINOR_SHIFT                       (  8 )
#define FW_VERSION_FW_VER_MINOR_MASK                        ( FW_VER_MINOR_MASK << FW_VERSION_FW_VER_MINOR_SHIFT )
#define FW_VERSION_FW_VER_MAJOR_SHIFT                       ( 24 )
#define FW_VERSION_FW_VER_MAJOR_MASK                        ( FW_VER_MAJOR_MASK << FW_VERSION_FW_VER_MAJOR_SHIFT )
#define FW_VERSION_FW_REL_OR_INT_VER_SHIFT                  ( 31 )
#define FW_VERSION_FW_REL_OR_INT_VER_MASK                   ( FW_REL_OR_INT_VER_MASK << FW_VERSION_FW_REL_OR_INT_VER_SHIFT )

/* Firmware Feature */
#define FW_NUM_PWMS_MASK                                    ( 0x1F )
#define FW_IEP0_NUM_PWMS_MASK                               ( 0xF )
#define FW_IEP1_NUM_PWMS_MASK                               ( 0xF )
#define FW_FEATURE_FW_NUM_PWMS_SHIFT                        (  0 )
#define FW_FEATURE_FW_NUM_PWMS_MASK                         ( FW_NUM_PWMS_MASK << FW_FEATURE_FW_NUM_PWMS_SHIFT )
#define FW_FEATURE_FW_IEP0_NUM_PWMS_SHIFT                   (  5 )
#define FW_FEATURE_FW_IEP0_NUM_PWMS_MASK                    ( FW_IEP0_NUM_PWMS_MASK << FW_FEATURE_FW_IEP0_NUM_PWMS_SHIFT )
#define FW_FEATURE_FW_IEP1_NUM_PWMS_SHIFT                   (  9 )
#define FW_FEATURE_FW_IEP1_NUM_PWMS_MASK                    ( FW_IEP1_NUM_PWMS_MASK << FW_FEATURE_FW_IEP1_NUM_PWMS_SHIFT )

/* PWM_CTRL */
#define BF_PWM_EN_DISABLE                                   ( 0 )   /* PWM Enable bit field disable setting */
#define BF_PWM_EN_ENABLE                                    ( 1 )   /* PWM Enable bit field enable setting */
#define BF_PWM_GBL_EN_DISABLE                               ( 0 )   /* Global Enable bit field disabled setting */
#define BF_PWM_GBL_EN_ENABLE                                ( 1 )   /* Global Enable bit field enabled setting */
#define PWM_EN_MASK                                         ( 0x1 )
#define IEP_PWM_GBL_EN_MASK                                 ( 0x1 )
#define PWM_CTRL_PWM_EN_SHIFT                               (  0 )
#define PWM_CTRL_PWM_EN_MASK                                ( PWM_EN_MASK << PWM_CTRL_PWM_EN_SHIFT )
#define PWM_CTRL_IEP0_PWM_GBL_EN_SHIFT                      (  1 )
#define PWM_CTRL_IEP0_PWM_GBL_EN_MASK                       ( IEP_PWM_GBL_EN_MASK << PWM_CTRL_IEP0_PWM_GBL_EN_SHIFT )
#define PWM_CTRL_IEP1_PWM_GBL_EN_SHIFT                      (  2 )
#define PWM_CTRL_IEP1_PWM_GBL_EN_MASK                       ( IEP_PWM_GBL_EN_MASK << PWM_CTRL_IEP1_PWM_GBL_EN_SHIFT )

/* PWM_STAT */
#define BF_PWM_EN_ACK_DISABLE                               ( 0 )   /* PWM Enable ACK bit field disabled setting */
#define BF_PWM_EN_ACK_ENABLE                                ( 1 )   /* PWM Enable ACK bit field enabled setting */
#define BF_PWM_GBL_EN_ACK_DISABLE                           ( 0 )   /* Global Enable ACK bit field disabled setting */
#define BF_PWM_GBL_EN_ACK_ENABLE                            ( 1 )   /* Global Enable ACK bit field enabled setting */
#define BF_PWM_FW_INIT_UNINIT                               ( 0 )   /* FW initialized bit field uninitialized setting */
#define BF_PWM_FW_INIT_INIT                                 ( 1 )   /* FW initialized bit field initialized setting */
#define PWM_EN_ACK_MASK                                     ( 0x1 )
#define IEP_PWM_GBL_EN_ACK_MASK                             ( 0x1 )
#define FW_INIT_MASK                                        ( 0x1 )
#define PWM_STAT_PWM_EN_ACK_SHIFT                           (  0 )
#define PWM_STAT_PWM_EN_ACK_MASK                            ( PWM_EN_ACK_MASK << PWM_STAT_PWM_EN_ACK_SHIFT )
#define PWM_STAT_IEP0_PWM_GBL_EN_ACK_SHIFT                  (  1 )
#define PWM_STAT_IEP0_PWM_GBL_EN_ACK_MASK                   ( IEP_PWM_GBL_EN_ACK_MASK << PWM_STAT_IEP0_PWM_GBL_EN_ACK_SHIFT )
#define PWM_STAT_IEP1_PWM_GBL_EN_ACK_SHIFT                  (  2 )
#define PWM_STAT_IEP1_PWM_GBL_EN_ACK_MASK                   ( IEP_PWM_GBL_EN_ACK_MASK << PWM_STAT_IEP1_PWM_GBL_EN_ACK_SHIFT )
#define PWM_STAT_FW_INIT_SHIFT                              (  3 )
#define PWM_STAT_FW_INIT_MASK                               ( FW_INIT_MASK << PWM_STAT_FW_INIT_SHIFT )

/*
 * Firmware IEP PWM instance registers
 */

/* IEP PWM register offsets */
#define IEP_PWM_RECFG_OFFSET                                (  0 )
#define IEP_PWM_MODE_OFFSET                                 (  4 )
#define IEP_PWM_EN_OFFSET                                   (  8 )
#define IEP_PWM_PRD_COUNT_OFFSET                            ( 12 )
#define IEP_PWM0_DC_COUNT_OFFSET                            ( 16 )
#define IEP_PWM1_DC_COUNT_OFFSET                            ( 20 )
#define IEP_PWM2_DC_COUNT_OFFSET                            ( 24 )
#define IEP_PWM3_DC_COUNT_OFFSET                            ( 28 )
#define IEP_PWM4_DC_COUNT_OFFSET                            ( 32 )
#define IEP_PWM5_DC_COUNT_OFFSET                            ( 36 )
#define IEP_PWM6_DC_COUNT_OFFSET                            ( 40 )
#define IEP_PWM7_DC_COUNT_OFFSET                            ( 44 )
#define IEP_PWM8_DC_COUNT_OFFSET                            ( 48 )
#define IEP_PWM9_DC_COUNT_OFFSET                            ( 52 )
#define IEP_PWM10_DC_COUNT_OFFSET                           ( 56 )
#define IEP_PWM11_DC_COUNT_OFFSET                           ( 60 )
#define IEP_PWM0_1_DB_COUNT_OFFSET                          ( 62 )
#define IEP_PWM2_3_DB_COUNT_OFFSET                          ( 64 )
#define IEP_PWM4_5_DB_COUNT_OFFSET                          ( 68 )
#define IEP_PWM6_7_DB_COUNT_OFFSET                          ( 70 )
#define IEP_PWM8_9_DB_COUNT_OFFSET                          ( 72 )
#define IEP_PWM10_11_DB_COUNT_OFFSET                        ( 74 )
 
/* IEP0 PWM register addresses */
#define ICSSG_PWM_IEP0_PWM_BASE_ADDR                        ( 0x001C )
#define ICSSG_PWM_IEP0_PWM_RECFG                            ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM_RECFG_OFFSET )
#define ICSSG_PWM_IEP0_PWM_MODE                             ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM_MODE_OFFSET )
#define ICSSG_PWM_IEP0_PWM_EN                               ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM_EN_OFFSET )
#define ICSSG_PWM_IEP0_PWM_PRD_COUNT                        ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM_PRD_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM0_DC_COUNT                        ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM0_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM1_DC_COUNT                        ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM1_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM2_DC_COUNT                        ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM2_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM3_DC_COUNT                        ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM3_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM4_DC_COUNT                        ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM4_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM5_DC_COUNT                        ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM5_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM6_DC_COUNT                        ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM6_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM7_DC_COUNT                        ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM7_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM8_DC_COUNT                        ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM8_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM9_DC_COUNT                        ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM9_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM10_DC_COUNT                       ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM10_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM11_DC_COUNT                       ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM11_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM0_1_DB_COUNT                      ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM0_1_DB_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM2_3_DB_COUNT                      ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM2_3_DB_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM4_5_DB_COUNT                      ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM4_5_DB_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM6_7_DB_COUNT                      ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM6_7_DB_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM8_9_DB_COUNT                      ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM8_9_DB_COUNT_OFFSET )
#define ICSSG_PWM_IEP0_PWM10_11_DB_COUNT                    ( ICSSG_PWM_IEP0_PWM_BASE_ADDR + IEP_PWM10_11_DB_COUNT_OFFSET )

/* IEP1 PWM register addresses */
#define ICSSG_PWM_IEP1_PWM_BASE_ADDR                        ( 0x0068 )
#define ICSSG_PWM_IEP1_PWM_RECFG                            ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM_RECFG_OFFSET )
#define ICSSG_PWM_IEP1_PWM_MODE                             ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM_MODE_OFFSET )
#define ICSSG_PWM_IEP1_PWM_EN                               ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM_EN_OFFSET )
#define ICSSG_PWM_IEP1_PWM_PRD_COUNT                        ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM_PRD_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM0_DC_COUNT                        ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM0_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM1_DC_COUNT                        ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM1_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM2_DC_COUNT                        ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM2_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM3_DC_COUNT                        ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM3_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM4_DC_COUNT                        ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM4_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM5_DC_COUNT                        ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM5_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM6_DC_COUNT                        ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM6_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM7_DC_COUNT                        ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM7_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM8_DC_COUNT                        ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM8_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM9_DC_COUNT                        ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM9_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM10_DC_COUNT                       ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM10_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM11_DC_COUNT                       ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM11_DC_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM0_1_DB_COUNT                      ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM0_1_DB_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM2_3_DB_COUNT                      ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM2_3_DB_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM4_5_DB_COUNT                      ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM4_5_DB_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM6_7_DB_COUNT                      ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM6_7_DB_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM8_9_DB_COUNT                      ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM8_9_DB_COUNT_OFFSET )
#define ICSSG_PWM_IEP1_PWM10_11_DB_COUNT                    ( ICSSG_PWM_IEP1_PWM_BASE_ADDR + IEP_PWM10_11_DB_COUNT_OFFSET )

/*
 * Firmware IEP PWM instance register bit fields
 */

/* IEPx_PWM_RECFG */
#define RECFG_IEP_PWM_EN_MASK                               ( 0x1 )
#define RECFG_IEP_PWM_PRD_COUNT_MASK                        ( 0x1 )
#define RECFG_IEP_PWM_DC_COUNT_MASK                         ( 0xFFF )
#define RECFG_IEP_PWM_DB_COUNT_MASK                         ( 0x3F )
#define IEP_PWM_RECFG_RECFG_IEP_PWM_EN_SHIFT                (  0 )
#define IEP_PWM_RECFG_RECFG_IEP_PWM_EN_MASK                 ( RECFG_IEP_PWM_EN_MASK << IEP_PWM_RECFG_RECFG_IEP_PWM_EN_SHIFT )
#define IEP_PWM_RECFG_RECFG_IEP_PWM_PRD_COUNT_SHIFT         (  1 )
#define IEP_PWM_RECFG_RECFG_IEP_PWM_PRD_COUNT_MASK          ( RECFG_IEP_PWM_PRD_COUNT_MASK << IEP_PWM_RECFG_RECFG_IEP_PWM_PRD_COUNT_SHIFT )
#define IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_SHIFT          (  2 )
#define IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_MASK           ( RECFG_IEP_PWM_DC_COUNT_MASK << IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_SHIFT )
#define IEP_PWM_RECFG_RECFG_IEP_PWM_DB_COUNT_SHIFT          ( 14 )
#define IEP_PWM_RECFG_RECFG_IEP_PWM_DB_COUNT_MASK           ( RECFG_IEP_PWM_DB_COUNT_MASK << IEP_PWM_RECFG_RECFG_IEP_PWM_DB_COUNT_SHIFT )
/* Aggregate Reconfiguration bit field mask */
#define IEP_PWM_RECFG_MASK \
    ( IEP_PWM_RECFG_RECFG_IEP_PWM_EN_MASK | \
      IEP_PWM_RECFG_RECFG_IEP_PWM_PRD_COUNT_MASK | \
      IEP_PWM_RECFG_RECFG_IEP_PWM_DC_COUNT_MASK | \
      IEP_PWM_RECFG_RECFG_IEP_PWM_DB_COUNT_MASK )

/* IEPx_PWM_MODE */
#define BF_PWM_MODE_SNGL                                    ( 0 )   /* PWM mode bit field Single-Ended PWM setting */
#define BF_PWM_MODE_COMP                                    ( 1 )   /* PWM mode bit field Complementary PWM setting */
#define PWM_MODE_MASK                                       ( 0x1 )
#define IEP_PWM_MODE_PWM0_1_MODE_SHIFT                      ( 0 )
#define IEP_PWM_MODE_PWM0_1_MODE_MASK                       ( PWM_MODE_MASK << IEP_PWM_MODE_PWM0_1_MODE_SHIFT )
#define IEP_PWM_MODE_PWM2_3_MODE_SHIFT                      ( 1 )
#define IEP_PWM_MODE_PWM2_3_MODE_MASK                       ( PWM_MODE_MASK << IEP_PWM_MODE_PWM2_3_MODE_SHIFT )
#define IEP_PWM_MODE_PWM4_5_MODE_SHIFT                      ( 2 )
#define IEP_PWM_MODE_PWM4_5_MODE_MASK                       ( PWM_MODE_MASK << IEP_PWM_MODE_PWM4_5_MODE_SHIFT )
#define IEP_PWM_MODE_PWM6_7_MODE_SHIFT                      ( 3 )
#define IEP_PWM_MODE_PWM6_7_MODE_MASK                       ( PWM_MODE_MASK << IEP_PWM_MODE_PWM6_7_MODE_SHIFT )
#define IEP_PWM_MODE_PWM8_9_MODE_SHIFT                      ( 4 )
#define IEP_PWM_MODE_PWM8_9_MODE_MASK                       ( PWM_MODE_MASK << IEP_PWM_MODE_PWM8_9_MODE_SHIFT )
#define IEP_PWM_MODE_PWM10_11_MODE_SHIFT                    ( 5 )
#define IEP_PWM_MODE_PWM10_11_MODE_MASK                     ( PWM_MODE_MASK << IEP_PWM_MODE_PWM10_11_MODE_SHIFT )

/* IEPx_PWM_EN */
#define BF_PWM_EN_DISABLE                                   ( 0 )   /* PWM enable bit field disabled setting */
#define BF_PWM_EN_ENABLE                                    ( 1 )   /* PWM enable bit field enabled setting */
#define PWM_EN_MASK                                         ( 0x1 )
#define IEP_PWM_EN_PWM0_EN_SHIFT                            ( 0 )
#define IEP_PWM_EN_PWM0_EN_MASK                             ( PWM_EN_MASK << IEP_PWM_EN_PWM0_EN_SHIFT )
#define IEP_PWM_EN_PWM1_EN_SHIFT                            ( 1 )
#define IEP_PWM_EN_PWM1_EN_MASK                             ( PWM_EN_MASK << IEP_PWM_EN_PWM1_EN_SHIFT )
#define IEP_PWM_EN_PWM2_EN_SHIFT                            ( 2 )
#define IEP_PWM_EN_PWM2_EN_MASK                             ( PWM_EN_MASK << IEP_PWM_EN_PWM2_EN_SHIFT )
#define IEP_PWM_EN_PWM3_EN_SHIFT                            ( 3 )
#define IEP_PWM_EN_PWM3_EN_MASK                             ( PWM_EN_MASK << IEP_PWM_EN_PWM3_EN_SHIFT )
#define IEP_PWM_EN_PWM4_EN_SHIFT                            ( 4 )
#define IEP_PWM_EN_PWM4_EN_MASK                             ( PWM_EN_MASK << IEP_PWM_EN_PWM4_EN_SHIFT )
#define IEP_PWM_EN_PWM5_EN_SHIFT                            ( 5 )
#define IEP_PWM_EN_PWM5_EN_MASK                             ( PWM_EN_MASK << IEP_PWM_EN_PWM5_EN_SHIFT )
#define IEP_PWM_EN_PWM6_EN_SHIFT                            ( 6 )
#define IEP_PWM_EN_PWM6_EN_MASK                             ( PWM_EN_MASK << IEP_PWM_EN_PWM6_EN_SHIFT )
#define IEP_PWM_EN_PWM7_EN_SHIFT                            ( 7 )
#define IEP_PWM_EN_PWM7_EN_MASK                             ( PWM_EN_MASK << IEP_PWM_EN_PWM7_EN_SHIFT )
#define IEP_PWM_EN_PWM8_EN_SHIFT                            ( 8 )
#define IEP_PWM_EN_PWM8_EN_MASK                             ( PWM_EN_MASK << IEP_PWM_EN_PWM8_EN_SHIFT )
#define IEP_PWM_EN_PWM9_EN_SHIFT                            ( 9 )
#define IEP_PWM_EN_PWM9_EN_MASK                             ( PWM_EN_MASK  << IEP_PWM_EN_PWM9_EN_SHIFT )
#define IEP_PWM_EN_PWM10_EN_SHIFT                           ( 10 )
#define IEP_PWM_EN_PWM10_EN_MASK                            ( PWM_EN_MASK << IEP_PWM_EN_PWM10_EN_SHIFT )
#define IEP_PWM_EN_PWM11_EN_SHIFT                           ( 11 )
#define IEP_PWM_EN_PWM11_EN_MASK                            ( PWM_EN_MASK << IEP_PWM_EN_PWM11_EN_SHIFT )

/* IEPx_PWM_PRD_COUNT */
#define PRD_COUNT_MASK                                      ( 0xFFFFFFFF )
#define IEP_PWM_PRD_COUNT_SHIFT                             (  0 )
#define IEP_PWM_PRD_COUNT_MASK                              ( PRD_COUNT_MASK << IEP_PWM_PRD_COUNT_SHIFT )

/* IEPx_PWMm_DC_COUNT */
#define DC_COUNT_MASK                                       ( 0xFFFFFFFF )
#define IEP_PWM_DC_COUNT_SHIFT                              (  0 )
#define IEP_PWM_DC_COUNT_MASK                               ( DC_COUNT_MASK << IEP_PWM_DC_COUNT_SHIFT )

/* IEPx_PWMn_n+1_DB_COUNT */
#define DB_COUNT_MASK                                       ( 0xFFFF )
#define IEP_PWM_DB_COUNT_SHIFT                              (  0 )
#define IEP_PWM_DB_COUNT_MASK                               ( DB_COUNT_MASK << IEP_PWM_DB_COUNT_SHIFT )

 
#endif /* _ICSSG_IEP_PWM_H_ */

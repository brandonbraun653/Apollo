/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/

/**
 *
 * \file   lcd_touch_test.h
 *
 * \brief  This is the header file for LCD touch detect diagnostic test.
 *
 */
#ifndef _LCD_TOUCH_TEST_H_
#define _LCD_TOUCH_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART_stdio.h>

#include "board.h"
#include "board_cfg.h"

#include <ti/csl/soc.h>
#include <soc.h>

#include "diag_common_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Write only registers */
#define CMD_REG_ADDR                                         (0x8040U)
#define PROXIMITY_EN_REG_ADDR                                (0x8042U)

/* Read/Write Registers */
#define CONFIG_VER_REG_ADDR
#define X_OUTPUT_MAX_LOW_BYTE_REG_ADDR                       (0x8048U)
#define X_OUTPUT_MAX_HIGH_BYTE_REG_ADDR                      (0x8049U)

#define Y_OUTPUT_MAX_LOW_BYTE_REG_ADDR                       (0x804AU)
#define Y_OUTPUT_MAX_HIGH_BYTE_REG_ADDR                      (0x804BU)

#define TOUCH_NUMBER_REG_ADDR                                (0x804CU)

#define MODULE_SWITCH1_REG_ADDR                              (0x804DU)
#define MODULE_SWITCH2_REG_ADDR                              (0x804EU)

#define SHAKE_COUNT_REG_ADDR                                 (0x804FU)
#define FILTER_REG_ADDR                                      (0x8050U)
#define LARGE_TOCUH_REG_ADDR                                 (0x8051U)
#define NOISE_REDUCTION_REG_ADDR                             (0x8052U)

#define SCREEN_TOUCH_LEVEL_REG_ADDR                          (0x8053U)
#define SCREEN_LEAVE_LEVEL_REG_ADDR                          (0x8054U)

#define LOW_POWER_CONTROL_REG_ADDR                           (0x8055U)
#define REFRESH_RATE_REG_ADDR                                (0x8056U)

/* Blank area of boarder-top and boarder-bottom configuration register */
#define BOARDER_SPACING1_REG_ADDR                            (0x805BU)
/* Blank area of boarder-left and boarder-right configuration register */
#define BOARDER_SPACING2_REG_ADDR                            (0x805CU)

#define STRETCH_RATE_REG_ADDR                                (0x805DU)
#define STRETCH_R0_REG_ADDR                                  (0x805EU)
#define STRETCH_R1_REG_ADDR                                  (0x805FU)
#define STRETCH_R2_REG_ADDR                                  (0x8060U)
#define STRETCH_RM_REG_ADDR                                  (0x8061U)

#define DRV_GROUPA_NUM_REG_ADDR                              (0x8062U)
#define DRV_GROUPB_NUM_REG_ADDR                              (0x8063U)

#define SENSOR_NUM_REG_ADDR                                  (0x8064U)

#define FREQA_FACTOR_REG_ADDR                               (0x8065U)
#define FREQB_FACTOR_REG_ADDR                               (0x8066U)

#define PANEL_BITFREQL_REG_ADDR                             (0X8067U)
#define PANEL_BITFREQH_REG_ADDR                             (0x8068U)

#define PANEL_SENSOR_TIMEL_REG_ADDR                         (0x8069U)
#define PANEL_SENSOR_TIMEH_REG_ADDR                         (0x806AU)

#define PANEL_TX_GAIN_REG_ADDR                              (0x806BU)
#define PANEL_RX_GAIN_REG_ADDR                              (0x806CU)

#define PANEL_DUMP_SHIFT_REG_ADDR                           (0x806DU)
#define DRV_FRAME_CONTROL_REG_ADDR                          (0x806EU)

#define STYLUS_TX_GAIN_REG_ADDR                             (0x8072U)
#define STYLUS_RX_GAIN_REG_ADDR                             (0x8073U)
#define STYLUS_DUMP_SHIFT_REG_ADDR                          (0x8074U)
#define STYLUS_DRIVER_TOUCH_LEVEL_REG_ADDR                  (0x8075U)
#define STYLUS_SENSOR_TOUCH_LEVEL_REG_ADDR                  (0x8076U)
#define STYLUS_STYLUS_CONTROL_REG_ADDR                      (0x8077U)
#define BASE_REDUCE_REG_ADDR                                (0x8078U)

#define FREQ_HOPPING_START_REG_ADDR                         (0x807AU)
#define FREQ_HOPPING_END_REG_ADDR                           (0x807BU)

#define NOISE_DETECT_TIMES_REG_ADDR                         (0x807CU)

#define HOPPING_FLAG_REG_ADDR                               (0x807DU)
#define HOPPING_THRESHOLD_REG_ADDR                          (0x807EU)

#define NOISE_THRESHOLD_REG_ADDR                            (0x807FU)

#define HOPPING_SEG1_BITFREQL_REG_ADDR                      (0x8082U)
#define HOPPING_SEG1_BITFREQH_REG_ADDR                      (0x8083U)
#define HOPPING_SEG1_FACTOR_REG_ADDR                        (0x8084U)

#define HOPPING_SEG2_BITFREQL_REG_ADDR                      (0x8085U)
#define HOPPING_SEG2_BITFREQH_REG_ADDR                      (0x8086U)
#define HOPPING_SEG2_FACTOR_REG_ADDR                        (0x8087U)

#define HOPPING_SEG3_BITFREQL_REG_ADDR                      (0x8088U)
#define HOPPING_SEG3_BITFREQH_REG_ADDR                      (0x8089U)
#define HOPPING_SEG3_FACTOR_REG_ADDR                        (0x808AU)

#define HOPPING_SEG4_BITFREQL_REG_ADDR                      (0x808BU)
#define HOPPING_SEG4_BITFREQH_REG_ADDR                      (0x808CU)
#define HOPPING_SEG4_FACTOR_REG_ADDR                        (0x808DU)

#define HOPPING_SEG5_BITFREQL_REG_ADDR                      (0x808EU)
#define HOPPING_SEG5_BITFREQH_REG_ADDR                      (0x808FU)
#define HOPPING_SEG5_FACTOR_REG_ADDR                        (0x8090U)

#define KEY1_REG_ADDR                                       (0x8093U)
#define KEY2_REG_ADDR                                       (0x8094U)
#define KEY3_REG_ADDR                                       (0x8095U)
#define KEY4_REG_ADDR                                       (0x8096U)

#define KEY_AREA_REG_ADDR                                   (0x8097U)

#define KEY_TOUCH_LEVEL_REG_ADDR                            (0x8098U)
#define KEY_LEAVE_LEVEL_REG_ADDR                            (0x8099U)

/* KeySense_1 and KeySense_2 */
#define KEY_SENS12_REG_ADDR                                 (0x809AU)
/* KeySense_3 and KeySense_4 */
#define KEY_SENS34_REG_ADDR                                 (0x809BU)

#define KEY_RESTRAIN_REG_ADDR                               (0x809CU)

#define SCAP_DIFF_UP_LEVEL_SENSE_REG_ADDR                   (0x80B1U)
#define SCAP_MERGE_TOUCH_LEVEL_SENSE_REG_ADDR               (0x80B2U)

#define SENSOR_CH0_CNF_REG_ADDR                             (0x80b7U)
#define SENSOR_CH1_CNF_REG_ADDR                             (0x80b8U)
#define SENSOR_CH2_CNF_REG_ADDR                             (0x80b9U)
#define SENSOR_CH3_CNF_REG_ADDR                             (0x80baU)
#define SENSOR_CH4_CNF_REG_ADDR                             (0x80bbU)
#define SENSOR_CH5_CNF_REG_ADDR                             (0x80bcU)
#define SENSOR_CH6_CNF_REG_ADDR                             (0x80bdU)
#define SENSOR_CH7_CNF_REG_ADDR                             (0x80beU)
#define SENSOR_CH8_CNF_REG_ADDR                             (0x80bfU)
#define SENSOR_CH9_CNF_REG_ADDR                             (0x80c0U)
#define SENSOR_CH10_CNF_REG_ADDR                            (0x80c1U)
#define SENSOR_CH11_CNF_REG_ADDR                            (0x80c2U)
#define SENSOR_CH12_CNF_REG_ADDR                            (0x80c3U)
#define SENSOR_CH13_CNF_REG_ADDR                            (0x80c4U)
#define SENSOR_CH14_CNF_REG_ADDR                            (0x80c5U)
#define SENSOR_CH15_CNF_REG_ADDR                            (0x80c6U)
#define SENSOR_CH16_CNF_REG_ADDR                            (0x80c7U)
#define SENSOR_CH17_CNF_REG_ADDR                            (0x80c8U)
#define SENSOR_CH18_CNF_REG_ADDR                            (0x80c9U)
#define SENSOR_CH19_CNF_REG_ADDR                            (0x80caU)
#define SENSOR_CH20_CNF_REG_ADDR                            (0x80cbU)
#define SENSOR_CH21_CNF_REG_ADDR                            (0x80ccU)
#define SENSOR_CH22_CNF_REG_ADDR                            (0x80cdU)
#define SENSOR_CH23_CNF_REG_ADDR                            (0x80ceU)

#define DRIVER_CH0_CNF_REG_ADDR                             (0x80d5U)
#define DRIVER_CH1_CNF_REG_ADDR                             (0x80d6U)
#define DRIVER_CH2_CNF_REG_ADDR                             (0x80d7U)
#define DRIVER_CH3_CNF_REG_ADDR                             (0x80d8U)
#define DRIVER_CH4_CNF_REG_ADDR                             (0x80d9U)
#define DRIVER_CH5_CNF_REG_ADDR                             (0x80daU)
#define DRIVER_CH6_CNF_REG_ADDR                             (0x80dbU)
#define DRIVER_CH7_CNF_REG_ADDR                             (0x80dcU)
#define DRIVER_CH8_CNF_REG_ADDR                             (0x80ddU)
#define DRIVER_CH9_CNF_REG_ADDR                             (0x80deU)
#define DRIVER_CH10_CNF_REG_ADDR                            (0x80dfU)
#define DRIVER_CH11_CNF_REG_ADDR                            (0x80e0U)
#define DRIVER_CH12_CNF_REG_ADDR                            (0x80e1U)
#define DRIVER_CH13_CNF_REG_ADDR                            (0x80e2U)
#define DRIVER_CH14_CNF_REG_ADDR                            (0x80e3U)
#define DRIVER_CH15_CNF_REG_ADDR                            (0x80e4U)
#define DRIVER_CH16_CNF_REG_ADDR                            (0x80e5U)
#define DRIVER_CH17_CNF_REG_ADDR                            (0x80e6U)
#define DRIVER_CH18_CNF_REG_ADDR                            (0x80e7U)
#define DRIVER_CH19_CNF_REG_ADDR                            (0x80e8U)
#define DRIVER_CH20_CNF_REG_ADDR                            (0x80e9U)
#define DRIVER_CH21_CNF_REG_ADDR                            (0x80eaU)
#define DRIVER_CH22_CNF_REG_ADDR                            (0x80ebU)
#define DRIVER_CH23_CNF_REG_ADDR                            (0x80ecU)
#define DRIVER_CH24_CNF_REG_ADDR                            (0x80edU)
#define DRIVER_CH25_CNF_REG_ADDR                            (0x80ceU)
#define DRIVER_CH26_CNF_REG_ADDR                            (0x80efU)
#define DRIVER_CH27_CNF_REG_ADDR                            (0x80f0U)
#define DRIVER_CH28_CNF_REG_ADDR                            (0x80f1U)
#define DRIVER_CH29_CNF_REG_ADDR                            (0x80f2U)
#define DRIVER_CH30_CNF_REG_ADDR                            (0x80f3U)
#define DRIVER_CH31_CNF_REG_ADDR                            (0x80f4U)

#define CONFIG_CHKSUM_REG_ADDR                              (0x80FFU)
#define CONFIG_FRESH_REG_ADDR                               (0x8100U)

/* Read Only Registers */
#define PRODUCT_ID_FIRST_BYTE_REG_ADDR                      (0x8140U)
#define PRODUCT_ID_SECOND_BYTE_REG_ADDR                     (0x8141U)
#define PRODUCT_ID_THIRD_BYTE_REG_ADDR                      (0x8142U)
#define PRODUCT_ID_FOURTH_BYTE_REG_ADDR                     (0x8143U)

#define FIRMWARE_VERSION_LOW_BYTE_ADDR                      (0x8144U)
#define FIRMWARE_VERSION_HIGH_BYTE_ADDR                     (0x8145U)

#define VENDOR_ID_REG_ADDR                                  (0x0U)

#define BUFFER_STATUS_REG_ADDR                              (0X814EU)

#define POINT1_X_COORDINATE_LOW_BYTE_REG_ADDR               (0x8150U)
#define POINT1_X_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8151U)
#define POINT1_Y_COORDINATE_LOW_BYTE_REG_ADDR               (0x8152U)
#define POINT1_Y_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8153U)

#define POINT2_X_COORDINATE_LOW_BYTE_REG_ADDR               (0x8158U)
#define POINT2_X_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8159U)
#define POINT2_Y_COORDINATE_LOW_BYTE_REG_ADDR               (0x815AU)
#define POINT2_Y_COORDINATE_HIGH_BYTE_REG_ADDR              (0x815BU)

#define POINT3_X_COORDINATE_LOW_BYTE_REG_ADDR               (0x8160U)
#define POINT3_X_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8161U)
#define POINT3_Y_COORDINATE_LOW_BYTE_REG_ADDR               (0x8162U)
#define POINT3_Y_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8163U)

#define POINT4_X_COORDINATE_LOW_BYTE_REG_ADDR               (0x8168U)
#define POINT4_X_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8169U)
#define POINT4_Y_COORDINATE_LOW_BYTE_REG_ADDR               (0x816AU)
#define POINT4_Y_COORDINATE_HIGH_BYTE_REG_ADDR              (0x816BU)

#define POINT5_X_COORDINATE_LOW_BYTE_REG_ADDR               (0x8170U)
#define POINT5_X_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8171U)
#define POINT5_Y_COORDINATE_LOW_BYTE_REG_ADDR               (0x8172U)
#define POINT5_Y_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8173U)

#define POINT6_X_COORDINATE_LOW_BYTE_REG_ADDR               (0x8178U)
#define POINT6_X_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8179U)
#define POINT6_Y_COORDINATE_LOW_BYTE_REG_ADDR               (0x817AU)
#define POINT6_Y_COORDINATE_HIGH_BYTE_REG_ADDR              (0x817BU)

#define POINT7_X_COORDINATE_LOW_BYTE_REG_ADDR               (0x8180U)
#define POINT7_X_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8181U)
#define POINT7_Y_COORDINATE_LOW_BYTE_REG_ADDR               (0x8182U)
#define POINT7_Y_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8183U)

#define POINT8_X_COORDINATE_LOW_BYTE_REG_ADDR               (0x8188U)
#define POINT8_X_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8189U)
#define POINT8_Y_COORDINATE_LOW_BYTE_REG_ADDR               (0x818AU)
#define POINT8_Y_COORDINATE_HIGH_BYTE_REG_ADDR              (0x818BU)

#define POINT9_X_COORDINATE_LOW_BYTE_REG_ADDR               (0x8190U)
#define POINT9_X_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8191U)
#define POINT9_Y_COORDINATE_LOW_BYTE_REG_ADDR               (0x8192U)
#define POINT9_Y_COORDINATE_HIGH_BYTE_REG_ADDR              (0x8193U)

#define POINT10_X_COORDINATE_LOW_BYTE_REG_ADDR              (0x8198U)
#define POINT10_X_COORDINATE_HIGH_BYTE_REG_ADDR             (0x8199U)
#define POINT10_Y_COORDINATE_LOW_BYTE_REG_ADDR              (0x819AU)
#define POINT10_Y_COORDINATE_HIGH_BYTE_REG_ADDR             (0x819BU)

#define PROD_ID_SIZE                                        (4U)
#define VERSION_SIZE                                        (2U)

#define NUM_OF_CONFIGS                                      (134U)

#define NUM_OF_TOUCH_POINTS_MASK                            (0x0FU)

#define NUM_OF_POINT_DATA_SETS                              (10U)
#define NUM_OF_REGS_IN_EACH_SET                             (4U)

#define BUFFER_STATUS_MASK                                  (0x80)

#define TOUCH_LIMIT_CNT                                     (20U)
typedef struct touch_init
{
    uint16_t regAddr;
    uint8_t  regData;
}touch_init_t;

/**
 *  \brief    The function performs the lcd touch test by reading
 *            the touch taps and displaying the position of touch
 *              co-ordinates on to the serial console.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_lcd_touch_detect_test(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LCD_TOUCH_TEST_H_ */

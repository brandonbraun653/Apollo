/******************************************************************************
 * Copyright (c) 2019-2020 Texas Instruments Incorporated - http://www.ti.com
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

/** \file   fpd_tuner_test.h
*
*   \brief  This file contains structure, typedefs, functions and
*           prototypes used for deserializer.
*/

#ifndef _FPD_TUNER_TEST_H_
#define _FPD_TUNER_TEST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "fpd_common.h"

#define BOARD_FPD_UB926_SLAVE_ID1_REG_ADDR              (0x09U)
#define BOARD_FPD_UB926_SLAVE_ID2_REG_ADDR              (0x0AU)
#define BOARD_FPD_UB926_SLAVE_ID3_REG_ADDR              (0x0BU)
#define BOARD_FPD_UB926_SLAVE_ID4_REG_ADDR              (0x0CU)
#define BOARD_FPD_UB926_SLAVE_ID5_REG_ADDR              (0x0DU)
#define BOARD_FPD_UB926_SLAVE_ID6_REG_ADDR              (0x0EU)
#define BOARD_FPD_UB926_SLAVE_ID7_REG_ADDR              (0x0FU)

#define BOARD_FPD_UB926_SLAVE_ALIAS1_REG_ADDR           (0x11U)
#define BOARD_FPD_UB926_SLAVE_ALIAS2_REG_ADDR           (0x12U)
#define BOARD_FPD_UB926_SLAVE_ALIAS3_REG_ADDR           (0x13U)
#define BOARD_FPD_UB926_SLAVE_ALIAS4_REG_ADDR           (0x14U)
#define BOARD_FPD_UB926_SLAVE_ALIAS5_REG_ADDR           (0x15U)
#define BOARD_FPD_UB926_SLAVE_ALIAS6_REG_ADDR           (0x16U)
#define BOARD_FPD_UB926_SLAVE_ALIAS7_REG_ADDR           (0x17U)

#define RESET_REG_MASK                  (uint8_t)(BOARD_FPD_UB926_BC_ENABLE_BIT_MASK | BOARD_FPD_UB926_REMOTE_AUTO_PWR_DWN_BIT_MASK)
#define CONFIGURATION1_REG_MASK         (uint8_t)BOARD_FPD_UB926_I2C_PASS_THROUGH_BIT_MASK
#define I2C_CONTROL1_REG_MASK           (uint8_t)BOARD_FPD_UB926_I2C_PASS_THROUGH_ALL_BIT_MASK
#define DATA_PATH_CONTROL_REG_MASK      (uint8_t)(BOARD_FPD_UB926_OVERRIDE_FC_CONFIG_BIT_MASK | BOARD_FPD_UB926_I2S_CHANNEL_B_OVERRIDE_BIT_MASK | BOARD_FPD_UB926_I2S_CHANNEL_B_ENABLE_BIT_MASK | BOARD_FPD_UB926_PASS_RGB_BIT_MASK | BOARD_FPD_UB926_I2S_GEN_BIT_MASK | BOARD_FPD_UB926_I2S_TRANSPOER_SEL_BIT_MASK | BOARD_FPD_UB926_RGB_18BIT_MODE_BIT_MASK)

#define CONFIGURATION925_REG_MASK       (uint8_t)BOARD_FPD_UB925_RGB_DE_GATE_BIT_MASK
#define DATA_PATH925_CONTROL_REG_MASK   (uint8_t)(BOARD_FPD_UB925_I2S_CHANNEL_B_ENABLE_BIT_MASK | BOARD_FPD_UB925_I2S_TRANSPOER_SEL_BIT_MASK | BOARD_FPD_UB925_RGB_18BIT_MODE_BIT_MASK | BOARD_FPD_UB925_I2S_CHANNEL_B_OVERRIDE_BIT_MASK)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _FPD_TUNER_TEST_H_ */

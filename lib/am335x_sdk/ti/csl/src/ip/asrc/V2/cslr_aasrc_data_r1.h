/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
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
 *  Name        : cslr_aasrc_data_r1.h
*/
#ifndef CSLR_AASRC_DATA_R1_H_
#define CSLR_AASRC_DATA_R1_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : aasrc data region 1 registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t STREAM_INPUT_FIFO_DATA_L0;
    volatile uint8_t  Resv_256[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_R0;
    volatile uint8_t  Resv_512[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_L1;
    volatile uint8_t  Resv_768[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_R1;
    volatile uint8_t  Resv_1024[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_L2;
    volatile uint8_t  Resv_1280[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_R2;
    volatile uint8_t  Resv_1536[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_L3;
    volatile uint8_t  Resv_1792[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_R3;
    volatile uint8_t  Resv_2048[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_L4;
    volatile uint8_t  Resv_2304[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_R4;
    volatile uint8_t  Resv_2560[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_L5;
    volatile uint8_t  Resv_2816[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_R5;
    volatile uint8_t  Resv_3072[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_L6;
    volatile uint8_t  Resv_3328[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_R6;
    volatile uint8_t  Resv_3584[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_L7;
    volatile uint8_t  Resv_3840[252];
    volatile uint32_t STREAM_INPUT_FIFO_DATA_R7;
    volatile uint8_t  Resv_4096[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_L0;
    volatile uint8_t  Resv_4352[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_R0;
    volatile uint8_t  Resv_4608[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_L1;
    volatile uint8_t  Resv_4864[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_R1;
    volatile uint8_t  Resv_5120[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_L2;
    volatile uint8_t  Resv_5376[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_R2;
    volatile uint8_t  Resv_5632[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_L3;
    volatile uint8_t  Resv_5888[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_R3;
    volatile uint8_t  Resv_6144[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_L4;
    volatile uint8_t  Resv_6400[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_R4;
    volatile uint8_t  Resv_6656[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_L5;
    volatile uint8_t  Resv_6912[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_R5;
    volatile uint8_t  Resv_7168[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_L6;
    volatile uint8_t  Resv_7424[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_R6;
    volatile uint8_t  Resv_7680[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_L7;
    volatile uint8_t  Resv_7936[252];
    volatile uint32_t STREAM_OUTPUT_FIFO_DATA_R7;
} CSL_aasrc_data_r1Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L0                            (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R0                            (0x00000100U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L1                            (0x00000200U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R1                            (0x00000300U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L2                            (0x00000400U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R2                            (0x00000500U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L3                            (0x00000600U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R3                            (0x00000700U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L4                            (0x00000800U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R4                            (0x00000900U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L5                            (0x00000A00U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R5                            (0x00000B00U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L6                            (0x00000C00U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R6                            (0x00000D00U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L7                            (0x00000E00U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R7                            (0x00000F00U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L0                           (0x00001000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R0                           (0x00001100U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L1                           (0x00001200U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R1                           (0x00001300U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L2                           (0x00001400U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R2                           (0x00001500U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L3                           (0x00001600U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R3                           (0x00001700U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L4                           (0x00001800U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R4                           (0x00001900U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L5                           (0x00001A00U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R5                           (0x00001B00U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L6                           (0x00001C00U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R6                           (0x00001D00U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L7                           (0x00001E00U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R7                           (0x00001F00U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* STREAM_INPUT_FIFO_DATA_L0 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L0_IN_DATA0_MASK              (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L0_IN_DATA0_SHIFT             (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L0_IN_DATA0_MAX               (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_R0 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R0_IN_DATA1_MASK              (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R0_IN_DATA1_SHIFT             (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R0_IN_DATA1_MAX               (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_L1 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L1_IN_DATA2_MASK              (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L1_IN_DATA2_SHIFT             (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L1_IN_DATA2_MAX               (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_R1 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R1_IN_DATA3_MASK              (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R1_IN_DATA3_SHIFT             (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R1_IN_DATA3_MAX               (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_L2 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L2_IN_DATA4_MASK              (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L2_IN_DATA4_SHIFT             (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L2_IN_DATA4_MAX               (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_R2 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R2_IN_DATA5_MASK              (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R2_IN_DATA5_SHIFT             (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R2_IN_DATA5_MAX               (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_L3 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L3_IN_DATA6_MASK              (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L3_IN_DATA6_SHIFT             (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L3_IN_DATA6_MAX               (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_R3 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R3_IN_DATA7_MASK              (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R3_IN_DATA7_SHIFT             (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R3_IN_DATA7_MAX               (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_L4 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L4_IN_DATA8_MASK              (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L4_IN_DATA8_SHIFT             (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L4_IN_DATA8_MAX               (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_R4 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R4_IN_DATA9_MASK              (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R4_IN_DATA9_SHIFT             (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R4_IN_DATA9_MAX               (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_L5 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L5_IN_DATA10_MASK             (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L5_IN_DATA10_SHIFT            (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L5_IN_DATA10_MAX              (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_R5 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R5_IN_DATA11_MASK             (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R5_IN_DATA11_SHIFT            (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R5_IN_DATA11_MAX              (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_L6 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L6_IN_DATA12_MASK             (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L6_IN_DATA12_SHIFT            (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L6_IN_DATA12_MAX              (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_R6 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R6_IN_DATA13_MASK             (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R6_IN_DATA13_SHIFT            (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R6_IN_DATA13_MAX              (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_L7 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L7_IN_DATA14_MASK             (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L7_IN_DATA14_SHIFT            (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_L7_IN_DATA14_MAX              (0xFFFFFFFFU)

/* STREAM_INPUT_FIFO_DATA_R7 */

#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R7_IN_DATA15_MASK             (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R7_IN_DATA15_SHIFT            (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_INPUT_FIFO_DATA_R7_IN_DATA15_MAX              (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_L0 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L0_OUT_DATA0_MASK            (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L0_OUT_DATA0_SHIFT           (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L0_OUT_DATA0_MAX             (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_R0 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R0_OUT_DATA1_MASK            (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R0_OUT_DATA1_SHIFT           (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R0_OUT_DATA1_MAX             (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_L1 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L1_OUT_DATA2_MASK            (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L1_OUT_DATA2_SHIFT           (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L1_OUT_DATA2_MAX             (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_R1 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R1_OUT_DATA3_MASK            (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R1_OUT_DATA3_SHIFT           (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R1_OUT_DATA3_MAX             (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_L2 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L2_OUT_DATA4_MASK            (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L2_OUT_DATA4_SHIFT           (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L2_OUT_DATA4_MAX             (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_R2 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R2_OUT_DATA5_MASK            (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R2_OUT_DATA5_SHIFT           (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R2_OUT_DATA5_MAX             (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_L3 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L3_OUT_DATA6_MASK            (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L3_OUT_DATA6_SHIFT           (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L3_OUT_DATA6_MAX             (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_R3 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R3_OUT_DATA7_MASK            (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R3_OUT_DATA7_SHIFT           (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R3_OUT_DATA7_MAX             (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_L4 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L4_OUT_DATA8_MASK            (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L4_OUT_DATA8_SHIFT           (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L4_OUT_DATA8_MAX             (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_R4 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R4_OUT_DATA9_MASK            (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R4_OUT_DATA9_SHIFT           (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R4_OUT_DATA9_MAX             (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_L5 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L5_OUT_DATA10_MASK           (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L5_OUT_DATA10_SHIFT          (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L5_OUT_DATA10_MAX            (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_R5 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R5_OUT_DATA11_MASK           (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R5_OUT_DATA11_SHIFT          (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R5_OUT_DATA11_MAX            (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_L6 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L6_OUT_DATA12_MASK           (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L6_OUT_DATA12_SHIFT          (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L6_OUT_DATA12_MAX            (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_R6 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R6_OUT_DATA13_MASK           (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R6_OUT_DATA13_SHIFT          (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R6_OUT_DATA13_MAX            (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_L7 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L7_OUT_DATA14_MASK           (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L7_OUT_DATA14_SHIFT          (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_L7_OUT_DATA14_MAX            (0xFFFFFFFFU)

/* STREAM_OUTPUT_FIFO_DATA_R7 */

#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R7_OUT_DATA15_MASK           (0xFFFFFFFFU)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R7_OUT_DATA15_SHIFT          (0x00000000U)
#define CSL_AASRC_DATA_R1_STREAM_OUTPUT_FIFO_DATA_R7_OUT_DATA15_MAX            (0xFFFFFFFFU)

#ifdef __cplusplus
}
#endif
#endif
/********************************************************************
 * Copyright (C) 2016 Texas Instruments Incorporated.
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
 *  Name        : cslr_proxy.h
*/
#ifndef CSLR_PROXY_H_
#define CSLR_PROXY_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : Proxy Config
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint8_t  Resv_32[28];
    volatile uint32_t EOI;                       /* EOI Register */
    volatile uint8_t  Resv_64[28];
    volatile uint32_t ERR_INTR_RAW_STAT[32];     /* Global Interrupt Raw Status Register */
    volatile uint32_t ERR_INTR_ENABLED_STAT[32];   /* Global Interrupt Enabled Status Register */
    volatile uint32_t ERR_INTR_ENABLE_SET[32];   /* Interrupt Enable Set Register */
    volatile uint32_t ERR_INTR_ENABLE_CLR[32];   /* Interrupt Enable Clear Register */
} CSL_proxyRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_PROXY_PID                                                          (0x00000000U)
#define CSL_PROXY_EOI                                                          (0x00000020U)
#define CSL_PROXY_ERR_INTR_RAW_STAT(ERR_INTR_RAW_STAT)                         ((0x00000040U+(ERR_INTR_RAW_STAT)*0x4U))
#define CSL_PROXY_ERR_INTR_ENABLED_STAT(ERR_INTR_ENABLED_STAT)                 ((0x000000C0U+(ERR_INTR_ENABLED_STAT)*0x4U))
#define CSL_PROXY_ERR_INTR_ENABLE_SET(ERR_INTR_ENABLE_SET)                     ((0x00000140U+(ERR_INTR_ENABLE_SET)*0x4U))
#define CSL_PROXY_ERR_INTR_ENABLE_CLR(ERR_INTR_ENABLE_CLR)                     ((0x000001C0U+(ERR_INTR_ENABLE_CLR)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_PROXY_PID_MINOR_MASK                                               (0x0000003FU)
#define CSL_PROXY_PID_MINOR_SHIFT                                              (0x00000000U)
#define CSL_PROXY_PID_MINOR_RESETVAL                                           (0x00000000U)
#define CSL_PROXY_PID_MINOR_MAX                                                (0x0000003FU)

#define CSL_PROXY_PID_CUSTOM_MASK                                              (0x000000C0U)
#define CSL_PROXY_PID_CUSTOM_SHIFT                                             (0x00000006U)
#define CSL_PROXY_PID_CUSTOM_RESETVAL                                          (0x00000000U)
#define CSL_PROXY_PID_CUSTOM_MAX                                               (0x00000003U)

#define CSL_PROXY_PID_MAJOR_MASK                                               (0x00000700U)
#define CSL_PROXY_PID_MAJOR_SHIFT                                              (0x00000008U)
#define CSL_PROXY_PID_MAJOR_RESETVAL                                           (0x00000001U)
#define CSL_PROXY_PID_MAJOR_MAX                                                (0x00000007U)

#define CSL_PROXY_PID_RTL_MASK                                                 (0x0000F800U)
#define CSL_PROXY_PID_RTL_SHIFT                                                (0x0000000BU)
#define CSL_PROXY_PID_RTL_RESETVAL                                             (0x00000000U)
#define CSL_PROXY_PID_RTL_MAX                                                  (0x0000001FU)

#define CSL_PROXY_PID_FUNC_MASK                                                (0x0FFF0000U)
#define CSL_PROXY_PID_FUNC_SHIFT                                               (0x00000010U)
#define CSL_PROXY_PID_FUNC_RESETVAL                                            (0x00000000U)
#define CSL_PROXY_PID_FUNC_MAX                                                 (0x00000FFFU)

#define CSL_PROXY_PID_BU_MASK                                                  (0x30000000U)
#define CSL_PROXY_PID_BU_SHIFT                                                 (0x0000001CU)
#define CSL_PROXY_PID_BU_RESETVAL                                              (0x00000002U)
#define CSL_PROXY_PID_BU_MAX                                                   (0x00000003U)

#define CSL_PROXY_PID_SCHEME_MASK                                              (0xC0000000U)
#define CSL_PROXY_PID_SCHEME_SHIFT                                             (0x0000001EU)
#define CSL_PROXY_PID_SCHEME_RESETVAL                                          (0x00000001U)
#define CSL_PROXY_PID_SCHEME_MAX                                               (0x00000003U)

#define CSL_PROXY_PID_RESETVAL                                                 (0x60000100U)

/* EOI */

#define CSL_PROXY_EOI_EOI_WR_MASK                                              (0x0000FFFFU)
#define CSL_PROXY_EOI_EOI_WR_SHIFT                                             (0x00000000U)
#define CSL_PROXY_EOI_EOI_WR_RESETVAL                                          (0x00000000U)
#define CSL_PROXY_EOI_EOI_WR_MAX                                               (0x0000FFFFU)

#define CSL_PROXY_EOI_RESETVAL                                                 (0x00000000U)

/* ERR_INTR_RAW_STAT */

#define CSL_PROXY_ERR_INTR_RAW_STAT_VAL_MASK                                   (0xFFFFFFFFU)
#define CSL_PROXY_ERR_INTR_RAW_STAT_VAL_SHIFT                                  (0x00000000U)
#define CSL_PROXY_ERR_INTR_RAW_STAT_VAL_RESETVAL                               (0x00000000U)
#define CSL_PROXY_ERR_INTR_RAW_STAT_VAL_MAX                                    (0xFFFFFFFFU)

#define CSL_PROXY_ERR_INTR_RAW_STAT_RESETVAL                                   (0x00000000U)

/* ERR_INTR_ENABLED_STAT */

#define CSL_PROXY_ERR_INTR_ENABLED_STAT_VAL_MASK                               (0xFFFFFFFFU)
#define CSL_PROXY_ERR_INTR_ENABLED_STAT_VAL_SHIFT                              (0x00000000U)
#define CSL_PROXY_ERR_INTR_ENABLED_STAT_VAL_RESETVAL                           (0x00000000U)
#define CSL_PROXY_ERR_INTR_ENABLED_STAT_VAL_MAX                                (0xFFFFFFFFU)

#define CSL_PROXY_ERR_INTR_ENABLED_STAT_RESETVAL                               (0x00000000U)

/* ERR_INTR_ENABLE_SET */

#define CSL_PROXY_ERR_INTR_ENABLE_SET_VAL_MASK                                 (0xFFFFFFFFU)
#define CSL_PROXY_ERR_INTR_ENABLE_SET_VAL_SHIFT                                (0x00000000U)
#define CSL_PROXY_ERR_INTR_ENABLE_SET_VAL_RESETVAL                             (0x00000000U)
#define CSL_PROXY_ERR_INTR_ENABLE_SET_VAL_MAX                                  (0xFFFFFFFFU)

#define CSL_PROXY_ERR_INTR_ENABLE_SET_RESETVAL                                 (0x00000000U)

/* ERR_INTR_ENABLE_CLR */

#define CSL_PROXY_ERR_INTR_ENABLE_CLR_VAL_MASK                                 (0xFFFFFFFFU)
#define CSL_PROXY_ERR_INTR_ENABLE_CLR_VAL_SHIFT                                (0x00000000U)
#define CSL_PROXY_ERR_INTR_ENABLE_CLR_VAL_RESETVAL                             (0x00000000U)
#define CSL_PROXY_ERR_INTR_ENABLE_CLR_VAL_MAX                                  (0xFFFFFFFFU)

#define CSL_PROXY_ERR_INTR_ENABLE_CLR_RESETVAL                                 (0x00000000U)

/**************************************************************************
* Hardware Region  : Proxy Buffer RAM Debug
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t DATA[32768];               /* Proxy Buffer Register */
} CSL_proxy_bufferRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_PROXY_BUFFER_DATA(DATA)                                            ((0x00000000U+(DATA)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* DATA */

#define CSL_PROXY_BUFFER_DATA_VAL_MASK                                         (0xFFFFFFFFU)
#define CSL_PROXY_BUFFER_DATA_VAL_SHIFT                                        (0x00000000U)
#define CSL_PROXY_BUFFER_DATA_VAL_RESETVAL                                     (0x00000000U)
#define CSL_PROXY_BUFFER_DATA_VAL_MAX                                          (0xFFFFFFFFU)

#define CSL_PROXY_BUFFER_DATA_RESETVAL                                         (0x00000000U)

/**************************************************************************
* Hardware Region  : Proxy Datapath
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t DATA[8];                   /* Proxy Data Register */
} CSL_target0Regs_PROXY_CHANNEL;


typedef struct {
    CSL_target0Regs_PROXY_CHANNEL CHANNEL[512];
    volatile uint8_t  Resv_65536[49152];
} CSL_target0Regs_PROXY;


typedef struct {
    CSL_target0Regs_PROXY PROXY[1024];
} CSL_target0Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_TARGET0_PROXY_CHANNEL_DATA(PROXY, CHANNEL,DATA)                    (0x00000000U+((PROXY)*0x10000U)+((CHANNEL)*0x20U)+((DATA)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* DATA */

#define CSL_TARGET0_PROXY_CHANNEL_DATA_VAL_MASK                                (0xFFFFFFFFU)
#define CSL_TARGET0_PROXY_CHANNEL_DATA_VAL_SHIFT                               (0x00000000U)
#define CSL_TARGET0_PROXY_CHANNEL_DATA_VAL_RESETVAL                            (0x00000000U)
#define CSL_TARGET0_PROXY_CHANNEL_DATA_VAL_MAX                                 (0xFFFFFFFFU)

#define CSL_TARGET0_PROXY_CHANNEL_DATA_RESETVAL                                (0x00000000U)

/**************************************************************************
* Hardware Region  : Proxy Datapath
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t DATA[32];                  /* Proxy Data Register */
} CSL_target1Regs_PROXY_CHANNEL;


typedef struct {
    CSL_target1Regs_PROXY_CHANNEL CHANNEL[128];
    volatile uint8_t  Resv_65536[49152];
} CSL_target1Regs_PROXY;


typedef struct {
    CSL_target1Regs_PROXY PROXY[1024];
} CSL_target1Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_TARGET1_PROXY_CHANNEL_DATA(PROXY, CHANNEL,DATA)                    (0x00000000U+((PROXY)*0x10000U)+((CHANNEL)*0x80U)+((DATA)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* DATA */

#define CSL_TARGET1_PROXY_CHANNEL_DATA_VAL_MASK                                (0xFFFFFFFFU)
#define CSL_TARGET1_PROXY_CHANNEL_DATA_VAL_SHIFT                               (0x00000000U)
#define CSL_TARGET1_PROXY_CHANNEL_DATA_VAL_RESETVAL                            (0x00000000U)
#define CSL_TARGET1_PROXY_CHANNEL_DATA_VAL_MAX                                 (0xFFFFFFFFU)

#define CSL_TARGET1_PROXY_CHANNEL_DATA_RESETVAL                                (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif

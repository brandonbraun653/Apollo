/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
*/
#ifndef CSLR_CP_ACE_H_
#define CSLR_CP_ACE_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifndef CSL_MODIFICATION   
#include <ti/csl/src/ip/sa/V2/cslr_eip_29t2_ram.h>
#endif

/**************************************************************************
* Register Overlay Structure for MMR
**************************************************************************/
typedef struct {
    volatile Uint32 PID;
    volatile Uint32 EFUSE_EN;
    volatile Uint32 CMD_STATUS;
    volatile Uint8  RSVD0[8];
    volatile Uint32 CDMA_FLOWID;
    volatile Uint8  RSVD1[4];
    volatile Uint32 CDMA_ENG_ID;
    volatile Uint8  RSVD2[224];
    volatile Uint32 CTXCACH_CTRL;
    volatile Uint32 CTXCACH_SC_PTR;
    volatile Uint32 CTXCACH_SC_ID;
    volatile Uint32 CTXCACH_MISSCNT;
} CSL_Cp_aceMmrRegs;


/**************************************************************************
* Register Overlay Structure for ECC_AGGR
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint8  RSVD0[4];
    volatile Uint32 VECTOR;
    volatile Uint32 MISC_STATUS;
    volatile Uint32 WRAPPER_REVISION;
    volatile Uint32 CONTROL;
    volatile Uint32 ERROR_CONTROL1;
    volatile Uint32 ERROR_CONTROL2;
    volatile Uint32 ERROR_STATUS1;
    volatile Uint32 ERROR_STATUS2;
    volatile Uint8  RSVD1[20];
    volatile Uint32 EOI;
    volatile Uint32 INT_STATUS[16];
    volatile Uint32 INT_ENABLE[16];
    volatile Uint32 INT_CLEAR[16];
} CSL_Cp_aceEcc_aggrRegs;


/**************************************************************************
* Register Overlay Structure for TRNG
**************************************************************************/
typedef struct {
    volatile Uint32 TRNG_OUTPUT_L;
    volatile Uint32 TRNG_OUTPUT_H;
    volatile Uint32 TRNG_STATUS;
    volatile Uint32 TRNG_INTMASK;
    volatile Uint32 TRNG_INTACK;
    volatile Uint32 TRNG_CONTROL;
    volatile Uint32 TRNG_CONFIG;
    volatile Uint32 TRNG_ALARMCNT;
    volatile Uint32 TRNG_FROENABLE;
    volatile Uint32 TRNG_FRODETUNE;
    volatile Uint32 TRNG_ALARMMASK;
    volatile Uint32 TRNG_ALARMSTOP;
    volatile Uint32 TRNG_LFSR_L;
    volatile Uint32 TRNG_LFSR_M;
    volatile Uint32 TRNG_LFSR_H;
    volatile Uint32 TRNG_COUNT;
    volatile Uint32 TRNG_TEST;
} CSL_Cp_aceTrngRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    CSL_Cp_aceMmrRegs	MMR;
    volatile Uint8  RSVD0[7920];
    CSL_Cp_aceEcc_aggrRegs	ECC_AGGR;
#ifndef CSL_MODIFICATION  
    volatile Uint8 RSVD1[0x1DF00];   /* 155392 */
    CSL_Eip_29t2_ramRegs  PKA;       /* start at offset 0x020000 */
#else
    volatile Uint8  RSVD1[155392];
#endif
    CSL_Cp_aceTrngRegs	TRNG;
} CSL_Cp_aceRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* Peripheral version and ID register */
#define CSL_CP_ACE_PID                                          (0x0U)

/* Efuse enable status register */
#define CSL_CP_ACE_EFUSE_EN                                     (0x4U)

/* Command status register */
#define CSL_CP_ACE_CMD_STATUS                                   (0x8U)

/* CDMA Port default CPPI flow ID register */
#define CSL_CP_ACE_CDMA_FLOWID                                  (0x14U)

/* CDMA Port default Next engine ID register */
#define CSL_CP_ACE_CDMA_ENG_ID                                  (0x1CU)

/* Context Cache module control register */
#define CSL_CP_ACE_CTXCACH_CTRL                                 (0x100U)

/* Context Cache module SC PTR */
#define CSL_CP_ACE_CTXCACH_SC_PTR                               (0x104U)

/* Context Cache module SC PTR */
#define CSL_CP_ACE_CTXCACH_SC_ID                                (0x108U)

/* Context Cache miss count */
#define CSL_CP_ACE_CTXCACH_MISSCNT                              (0x10CU)

/* The Revision Register contains the ID and revision information. */
#define CSL_CP_ACE_REVISION                                     (0x2000U)

/* ECC RAM ID to select the ECC RAM to control or read status. */
#define CSL_CP_ACE_VECTOR                                       (0x2008U)

/* Miscellaneous status register. */
#define CSL_CP_ACE_MISC_STATUS                                  (0x200CU)

/* The Revision Register contains the ID and revision information for the ECC 
 * wrapper. */
#define CSL_CP_ACE_WRAPPER_REVISION                             (0x2010U)

/* The Control Register controls the ECC control bits for the selected ECC 
 * RAM. */
#define CSL_CP_ACE_CONTROL                                      (0x2014U)

/* This register contains ECC error control bits for the selected ECC RAM. */
#define CSL_CP_ACE_ERROR_CONTROL1                               (0x2018U)

/* This register contains ECC error control bits for the selected ECC RAM. */
#define CSL_CP_ACE_ERROR_CONTROL2                               (0x201CU)

/* This register contains ECC status bits for the selected ECC RAM. */
#define CSL_CP_ACE_ERROR_STATUS1                                (0x2020U)

/* This register contains ECC status bits for the selected ECC RAM. */
#define CSL_CP_ACE_ERROR_STATUS2                                (0x2024U)

/* This is the EOI register for the interrupt to the host. */
#define CSL_CP_ACE_EOI                                          (0x203CU)

/* These are the raw level interrupt status bits where each bit corresponds to 
 * the pending status from an ECC RAM. */
#define CSL_CP_ACE_INT_STATUS(i)                                (0x2040U + ((i) * (0x4U)))

/* These are interrupt enables associated with the interrupt from each of the 
 * ECC RAMs. Writing a 1 to a bit position in the register enables the 
 * interrupt from the associated ECC RAM. */
#define CSL_CP_ACE_INT_ENABLE(i)                                (0x2080U + ((i) * (0x4U)))

/* These are interrupt enable clear bits associated with the interrupt from 
 * each of the ECC RAMs. Writing a 1 to a bit position in the register 
 * disables the interrupt from the associated ECC RAM. */
#define CSL_CP_ACE_INT_CLEAR(i)                                 (0x20C0U + ((i) * (0x4U)))

/* Data output LSW register */
#define CSL_CP_ACE_TRNG_OUTPUT_L                                (0x28000U)

/* Data output MSW register */
#define CSL_CP_ACE_TRNG_OUTPUT_H                                (0x28004U)

/* Status register */
#define CSL_CP_ACE_TRNG_STATUS                                  (0x28008U)

/* Interrupt mask register */
#define CSL_CP_ACE_TRNG_INTMASK                                 (0x2800CU)

/* Interrupt acknowledge register */
#define CSL_CP_ACE_TRNG_INTACK                                  (0x28010U)

/* Control register */
#define CSL_CP_ACE_TRNG_CONTROL                                 (0x28014U)

/* Configuration register */
#define CSL_CP_ACE_TRNG_CONFIG                                  (0x28018U)

/* Shutdown interr ctrl register */
#define CSL_CP_ACE_TRNG_ALARMCNT                                (0x2801CU)

/* FRO enables register */
#define CSL_CP_ACE_TRNG_FROENABLE                               (0x28020U)

/* FRO de-tune bits register */
#define CSL_CP_ACE_TRNG_FRODETUNE                               (0x28024U)

/* Alarm event log register */
#define CSL_CP_ACE_TRNG_ALARMMASK                               (0x28028U)

/* Alarm shutdown register */
#define CSL_CP_ACE_TRNG_ALARMSTOP                               (0x2802CU)

/* Main LFSR bits 31:0 */
#define CSL_CP_ACE_TRNG_LFSR_L                                  (0x28030U)

/* Main LFSR bits 63:32 */
#define CSL_CP_ACE_TRNG_LFSR_M                                  (0x28034U)

/* Main LFSR bits 80:64 */
#define CSL_CP_ACE_TRNG_LFSR_H                                  (0x28038U)

/* Main FSM count register */
#define CSL_CP_ACE_TRNG_COUNT                                   (0x2803CU)

/* Test control register */
#define CSL_CP_ACE_TRNG_TEST                                    (0x28040U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PID */

#define CSL_CP_ACE_PID_SCHEME_MASK                              (0xC0000000U)
#define CSL_CP_ACE_PID_SCHEME_SHIFT                             (30U)
#define CSL_CP_ACE_PID_SCHEME_RESETVAL                          (0x00000000U)
#define CSL_CP_ACE_PID_SCHEME_MAX                               (0x00000003U)

#define CSL_CP_ACE_PID_BU_MASK                                  (0x30000000U)
#define CSL_CP_ACE_PID_BU_SHIFT                                 (28U)
#define CSL_CP_ACE_PID_BU_RESETVAL                              (0x00000000U)
#define CSL_CP_ACE_PID_BU_MAX                                   (0x00000003U)

#define CSL_CP_ACE_PID_FUNC_MASK                                (0x0FFF0000U)
#define CSL_CP_ACE_PID_FUNC_SHIFT                               (16U)
#define CSL_CP_ACE_PID_FUNC_RESETVAL                            (0x00000000U)
#define CSL_CP_ACE_PID_FUNC_MAX                                 (0x00000fffU)

#define CSL_CP_ACE_PID_RTL_MASK                                 (0x0000F800U)
#define CSL_CP_ACE_PID_RTL_SHIFT                                (11U)
#define CSL_CP_ACE_PID_RTL_RESETVAL                             (0x00000000U)
#define CSL_CP_ACE_PID_RTL_MAX                                  (0x0000001fU)

#define CSL_CP_ACE_PID_MAJOR_MASK                               (0x00000700U)
#define CSL_CP_ACE_PID_MAJOR_SHIFT                              (8U)
#define CSL_CP_ACE_PID_MAJOR_RESETVAL                           (0x00000000U)
#define CSL_CP_ACE_PID_MAJOR_MAX                                (0x00000007U)

#define CSL_CP_ACE_PID_CUSTOM_MASK                              (0x000000C0U)
#define CSL_CP_ACE_PID_CUSTOM_SHIFT                             (6U)
#define CSL_CP_ACE_PID_CUSTOM_RESETVAL                          (0x00000000U)
#define CSL_CP_ACE_PID_CUSTOM_MAX                               (0x00000003U)

#define CSL_CP_ACE_PID_MINOR_MASK                               (0x0000003FU)
#define CSL_CP_ACE_PID_MINOR_SHIFT                              (0U)
#define CSL_CP_ACE_PID_MINOR_RESETVAL                           (0x00000000U)
#define CSL_CP_ACE_PID_MINOR_MAX                                (0x0000003fU)

#define CSL_CP_ACE_PID_RESETVAL                                 (0x00000000U)

/* EFUSE_EN */

#define CSL_CP_ACE_EFUSE_EN_ENABLE_MASK                         (0x00000001U)
#define CSL_CP_ACE_EFUSE_EN_ENABLE_SHIFT                        (0U)
#define CSL_CP_ACE_EFUSE_EN_ENABLE_RESETVAL                     (0x00000000U)
#define CSL_CP_ACE_EFUSE_EN_ENABLE_MAX                          (0x00000001U)

#define CSL_CP_ACE_EFUSE_EN_RESETVAL                            (0x00000000U)

/* CMD_STATUS */

#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_BUSY_MASK           (0x08000000U)
#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_BUSY_SHIFT          (27U)
#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_BUSY_RESETVAL       (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_BUSY_MAX            (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_BUSY_MASK            (0x02000000U)
#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_BUSY_SHIFT           (25U)
#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_BUSY_RESETVAL        (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_BUSY_MAX             (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_CTXCACH_BUSY_MASK                 (0x00800000U)
#define CSL_CP_ACE_CMD_STATUS_CTXCACH_BUSY_SHIFT                (23U)
#define CSL_CP_ACE_CMD_STATUS_CTXCACH_BUSY_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_CTXCACH_BUSY_MAX                  (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_PKA_BUSY_MASK                     (0x00100000U)
#define CSL_CP_ACE_CMD_STATUS_PKA_BUSY_SHIFT                    (20U)
#define CSL_CP_ACE_CMD_STATUS_PKA_BUSY_RESETVAL                 (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_PKA_BUSY_MAX                      (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_TRNG_BUSY_MASK                    (0x00080000U)
#define CSL_CP_ACE_CMD_STATUS_TRNG_BUSY_SHIFT                   (19U)
#define CSL_CP_ACE_CMD_STATUS_TRNG_BUSY_RESETVAL                (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_TRNG_BUSY_MAX                     (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_AUTHSS_BUSY_MASK                  (0x00020000U)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS_BUSY_SHIFT                 (17U)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS_BUSY_RESETVAL              (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS_BUSY_MAX                   (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_ENCSS_BUSY_MASK                   (0x00010000U)
#define CSL_CP_ACE_CMD_STATUS_ENCSS_BUSY_SHIFT                  (16U)
#define CSL_CP_ACE_CMD_STATUS_ENCSS_BUSY_RESETVAL               (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_ENCSS_BUSY_MAX                    (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_EN_MASK             (0x00000800U)
#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_EN_SHIFT            (11U)
#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_EN_RESETVAL         (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_CDMA_OUT_PORT_EN_MAX              (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_EN_MASK              (0x00000200U)
#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_EN_SHIFT             (9U)
#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_EN_RESETVAL          (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_CDMA_IN_PORT_EN_MAX               (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_CTXCACH_EN_MASK                   (0x00000080U)
#define CSL_CP_ACE_CMD_STATUS_CTXCACH_EN_SHIFT                  (7U)
#define CSL_CP_ACE_CMD_STATUS_CTXCACH_EN_RESETVAL               (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_CTXCACH_EN_MAX                    (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_PKA_EN_MASK                       (0x00000010U)
#define CSL_CP_ACE_CMD_STATUS_PKA_EN_SHIFT                      (4U)
#define CSL_CP_ACE_CMD_STATUS_PKA_EN_RESETVAL                   (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_PKA_EN_MAX                        (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_TRNG_EN_MASK                      (0x00000008U)
#define CSL_CP_ACE_CMD_STATUS_TRNG_EN_SHIFT                     (3U)
#define CSL_CP_ACE_CMD_STATUS_TRNG_EN_RESETVAL                  (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_TRNG_EN_MAX                       (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_AUTHSS_EN_MASK                    (0x00000002U)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS_EN_SHIFT                   (1U)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS_EN_RESETVAL                (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_AUTHSS_EN_MAX                     (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_ENCSS_EN_MASK                     (0x00000001U)
#define CSL_CP_ACE_CMD_STATUS_ENCSS_EN_SHIFT                    (0U)
#define CSL_CP_ACE_CMD_STATUS_ENCSS_EN_RESETVAL                 (0x00000000U)
#define CSL_CP_ACE_CMD_STATUS_ENCSS_EN_MAX                      (0x00000001U)

#define CSL_CP_ACE_CMD_STATUS_RESETVAL                          (0x00000000U)

/* CDMA_FLOWID */

#define CSL_CP_ACE_CDMA_FLOWID_CDMA_FLOWID_MASK                 (0x000000FFU)
#define CSL_CP_ACE_CDMA_FLOWID_CDMA_FLOWID_SHIFT                (0U)
#define CSL_CP_ACE_CDMA_FLOWID_CDMA_FLOWID_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_CDMA_FLOWID_CDMA_FLOWID_MAX                  (0x000000ffU)

#define CSL_CP_ACE_CDMA_FLOWID_RESETVAL                         (0x00000000U)

/* CDMA_ENG_ID */

#define CSL_CP_ACE_CDMA_ENG_ID_CDMA_ENG_ID_MASK                 (0x0000001FU)
#define CSL_CP_ACE_CDMA_ENG_ID_CDMA_ENG_ID_SHIFT                (0U)
#define CSL_CP_ACE_CDMA_ENG_ID_CDMA_ENG_ID_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_CDMA_ENG_ID_CDMA_ENG_ID_MAX                  (0x0000001fU)

#define CSL_CP_ACE_CDMA_ENG_ID_RESETVAL                         (0x00000000U)

/* CTXCACH_CTRL */

#define CSL_CP_ACE_CTXCACH_CTRL_BUSY_MASK                       (0x80000000U)
#define CSL_CP_ACE_CTXCACH_CTRL_BUSY_SHIFT                      (31U)
#define CSL_CP_ACE_CTXCACH_CTRL_BUSY_RESETVAL                   (0x00000000U)
#define CSL_CP_ACE_CTXCACH_CTRL_BUSY_MAX                        (0x00000001U)

#define CSL_CP_ACE_CTXCACH_CTRL_CTX_CNT_MASK                    (0x7F000000U)
#define CSL_CP_ACE_CTXCACH_CTRL_CTX_CNT_SHIFT                   (24U)
#define CSL_CP_ACE_CTXCACH_CTRL_CTX_CNT_RESETVAL                (0x00000000U)
#define CSL_CP_ACE_CTXCACH_CTRL_CTX_CNT_MAX                     (0x0000007fU)

#define CSL_CP_ACE_CTXCACH_CTRL_CLR_STATS_MASK                  (0x00000010U)
#define CSL_CP_ACE_CTXCACH_CTRL_CLR_STATS_SHIFT                 (4U)
#define CSL_CP_ACE_CTXCACH_CTRL_CLR_STATS_RESETVAL              (0x00000000U)
#define CSL_CP_ACE_CTXCACH_CTRL_CLR_STATS_MAX                   (0x00000001U)

#define CSL_CP_ACE_CTXCACH_CTRL_CDMA_PORT_EN_MASK               (0x00000008U)
#define CSL_CP_ACE_CTXCACH_CTRL_CDMA_PORT_EN_SHIFT              (3U)
#define CSL_CP_ACE_CTXCACH_CTRL_CDMA_PORT_EN_RESETVAL           (0x00000000U)
#define CSL_CP_ACE_CTXCACH_CTRL_CDMA_PORT_EN_MAX                (0x00000001U)

#define CSL_CP_ACE_CTXCACH_CTRL_CLR_CACHE_TABLE_MASK            (0x00000002U)
#define CSL_CP_ACE_CTXCACH_CTRL_CLR_CACHE_TABLE_SHIFT           (1U)
#define CSL_CP_ACE_CTXCACH_CTRL_CLR_CACHE_TABLE_RESETVAL        (0x00000000U)
#define CSL_CP_ACE_CTXCACH_CTRL_CLR_CACHE_TABLE_MAX             (0x00000001U)

#define CSL_CP_ACE_CTXCACH_CTRL_AUTO_FETCH_EN_MASK              (0x00000001U)
#define CSL_CP_ACE_CTXCACH_CTRL_AUTO_FETCH_EN_SHIFT             (0U)
#define CSL_CP_ACE_CTXCACH_CTRL_AUTO_FETCH_EN_RESETVAL          (0x00000000U)
#define CSL_CP_ACE_CTXCACH_CTRL_AUTO_FETCH_EN_MAX               (0x00000001U)

#define CSL_CP_ACE_CTXCACH_CTRL_RESETVAL                        (0x00000000U)

/* CTXCACH_SC_PTR */

#define CSL_CP_ACE_CTXCACH_SC_PTR_CTX_SC_PTR_MASK               (0xFFFFFFFFU)
#define CSL_CP_ACE_CTXCACH_SC_PTR_CTX_SC_PTR_SHIFT              (0U)
#define CSL_CP_ACE_CTXCACH_SC_PTR_CTX_SC_PTR_RESETVAL           (0x00000000U)
#define CSL_CP_ACE_CTXCACH_SC_PTR_CTX_SC_PTR_MAX                (0xffffffffU)

#define CSL_CP_ACE_CTXCACH_SC_PTR_RESETVAL                      (0x00000000U)

/* CTXCACH_SC_ID */

#define CSL_CP_ACE_CTXCACH_SC_ID_DONE_MASK                      (0x80000000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_DONE_SHIFT                     (31U)
#define CSL_CP_ACE_CTXCACH_SC_ID_DONE_RESETVAL                  (0x00000000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_DONE_MAX                       (0x00000001U)

#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ERRORCODE_MASK              (0x70000000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ERRORCODE_SHIFT             (28U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ERRORCODE_RESETVAL          (0x00000000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ERRORCODE_MAX               (0x00000007U)

#define CSL_CP_ACE_CTXCACH_SC_ID_SC_RAMIDX_MASK                 (0x0FF00000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_RAMIDX_SHIFT                (20U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_RAMIDX_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_RAMIDX_MAX                  (0x000000ffU)

#define CSL_CP_ACE_CTXCACH_SC_ID_GO_MASK                        (0x00080000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_GO_SHIFT                       (19U)
#define CSL_CP_ACE_CTXCACH_SC_ID_GO_RESETVAL                    (0x00000000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_GO_MAX                         (0x00000001U)

#define CSL_CP_ACE_CTXCACH_SC_ID_SC_TEAR_MASK                   (0x00020000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_TEAR_SHIFT                  (17U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_TEAR_RESETVAL               (0x00000000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_TEAR_MAX                    (0x00000001U)

#define CSL_CP_ACE_CTXCACH_SC_ID_SC_FETCH_EVICT_MASK            (0x00010000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_FETCH_EVICT_SHIFT           (16U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_FETCH_EVICT_RESETVAL        (0x00000000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_FETCH_EVICT_MAX             (0x00000001U)

#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ID_MASK                     (0x0000FFFFU)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ID_SHIFT                    (0U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ID_RESETVAL                 (0x00000000U)
#define CSL_CP_ACE_CTXCACH_SC_ID_SC_ID_MAX                      (0x0000ffffU)

#define CSL_CP_ACE_CTXCACH_SC_ID_RESETVAL                       (0x00000000U)

/* CTXCACH_MISSCNT */

#define CSL_CP_ACE_CTXCACH_MISSCNT_CTX_MISSCNT_MASK             (0xFFFFFFFFU)
#define CSL_CP_ACE_CTXCACH_MISSCNT_CTX_MISSCNT_SHIFT            (0U)
#define CSL_CP_ACE_CTXCACH_MISSCNT_CTX_MISSCNT_RESETVAL         (0x00000000U)
#define CSL_CP_ACE_CTXCACH_MISSCNT_CTX_MISSCNT_MAX              (0xffffffffU)

#define CSL_CP_ACE_CTXCACH_MISSCNT_RESETVAL                     (0x00000000U)

/* REVISION */

#define CSL_CP_ACE_REVISION_SCHEME_MASK                         (0xC0000000U)
#define CSL_CP_ACE_REVISION_SCHEME_SHIFT                        (30U)
#define CSL_CP_ACE_REVISION_SCHEME_RESETVAL                     (0x00000000U)
#define CSL_CP_ACE_REVISION_SCHEME_MAX                          (0x00000003U)

#define CSL_CP_ACE_REVISION_MODID_MASK                          (0x0FFF0000U)
#define CSL_CP_ACE_REVISION_MODID_SHIFT                         (16U)
#define CSL_CP_ACE_REVISION_MODID_RESETVAL                      (0x00000000U)
#define CSL_CP_ACE_REVISION_MODID_MAX                           (0x00000fffU)

#define CSL_CP_ACE_REVISION_REVRTL_MASK                         (0x0000F800U)
#define CSL_CP_ACE_REVISION_REVRTL_SHIFT                        (11U)
#define CSL_CP_ACE_REVISION_REVRTL_RESETVAL                     (0x00000000U)
#define CSL_CP_ACE_REVISION_REVRTL_MAX                          (0x0000001fU)

#define CSL_CP_ACE_REVISION_REVMAJ_MASK                         (0x00000700U)
#define CSL_CP_ACE_REVISION_REVMAJ_SHIFT                        (8U)
#define CSL_CP_ACE_REVISION_REVMAJ_RESETVAL                     (0x00000000U)
#define CSL_CP_ACE_REVISION_REVMAJ_MAX                          (0x00000007U)

#define CSL_CP_ACE_REVISION_REVCUSTOM_MASK                      (0x000000C0U)
#define CSL_CP_ACE_REVISION_REVCUSTOM_SHIFT                     (6U)
#define CSL_CP_ACE_REVISION_REVCUSTOM_RESETVAL                  (0x00000000U)
#define CSL_CP_ACE_REVISION_REVCUSTOM_MAX                       (0x00000003U)

#define CSL_CP_ACE_REVISION_REVMIN_MASK                         (0x0000003FU)
#define CSL_CP_ACE_REVISION_REVMIN_SHIFT                        (0U)
#define CSL_CP_ACE_REVISION_REVMIN_RESETVAL                     (0x00000000U)
#define CSL_CP_ACE_REVISION_REVMIN_MAX                          (0x0000003fU)

#define CSL_CP_ACE_REVISION_RESETVAL                            (0x00000000U)

/* VECTOR */

#define CSL_CP_ACE_VECTOR_READ_DONE_MASK                        (0x01000000U)
#define CSL_CP_ACE_VECTOR_READ_DONE_SHIFT                       (24U)
#define CSL_CP_ACE_VECTOR_READ_DONE_RESETVAL                    (0x00000000U)
#define CSL_CP_ACE_VECTOR_READ_DONE_MAX                         (0x00000001U)

#define CSL_CP_ACE_VECTOR_READ_ADDRESS_MASK                     (0x00FF0000U)
#define CSL_CP_ACE_VECTOR_READ_ADDRESS_SHIFT                    (16U)
#define CSL_CP_ACE_VECTOR_READ_ADDRESS_RESETVAL                 (0x00000000U)
#define CSL_CP_ACE_VECTOR_READ_ADDRESS_MAX                      (0x000000ffU)

#define CSL_CP_ACE_VECTOR_TRIGGER_READ_MASK                     (0x00008000U)
#define CSL_CP_ACE_VECTOR_TRIGGER_READ_SHIFT                    (15U)
#define CSL_CP_ACE_VECTOR_TRIGGER_READ_RESETVAL                 (0x00000000U)
#define CSL_CP_ACE_VECTOR_TRIGGER_READ_MAX                      (0x00000001U)

#define CSL_CP_ACE_VECTOR_ECC_VECTOR_MASK                       (0x000007FFU)
#define CSL_CP_ACE_VECTOR_ECC_VECTOR_SHIFT                      (0U)
#define CSL_CP_ACE_VECTOR_ECC_VECTOR_RESETVAL                   (0x00000000U)
#define CSL_CP_ACE_VECTOR_ECC_VECTOR_MAX                        (0x000007ffU)

#define CSL_CP_ACE_VECTOR_RESETVAL                              (0x00000000U)

/* MISC_STATUS */

#define CSL_CP_ACE_MISC_STATUS_NUM_RAMS_MASK                    (0x000007FFU)
#define CSL_CP_ACE_MISC_STATUS_NUM_RAMS_SHIFT                   (0U)
#define CSL_CP_ACE_MISC_STATUS_NUM_RAMS_RESETVAL                (0x00000000U)
#define CSL_CP_ACE_MISC_STATUS_NUM_RAMS_MAX                     (0x000007ffU)

#define CSL_CP_ACE_MISC_STATUS_RESETVAL                         (0x00000000U)

/* WRAPPER_REVISION */

#define CSL_CP_ACE_WRAPPER_REVISION_SCHEME_MASK                 (0xC0000000U)
#define CSL_CP_ACE_WRAPPER_REVISION_SCHEME_SHIFT                (30U)
#define CSL_CP_ACE_WRAPPER_REVISION_SCHEME_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_WRAPPER_REVISION_SCHEME_MAX                  (0x00000003U)

#define CSL_CP_ACE_WRAPPER_REVISION_MODID_MASK                  (0x0FFF0000U)
#define CSL_CP_ACE_WRAPPER_REVISION_MODID_SHIFT                 (16U)
#define CSL_CP_ACE_WRAPPER_REVISION_MODID_RESETVAL              (0x00000000U)
#define CSL_CP_ACE_WRAPPER_REVISION_MODID_MAX                   (0x00000fffU)

#define CSL_CP_ACE_WRAPPER_REVISION_REVRTL_MASK                 (0x0000F800U)
#define CSL_CP_ACE_WRAPPER_REVISION_REVRTL_SHIFT                (11U)
#define CSL_CP_ACE_WRAPPER_REVISION_REVRTL_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_WRAPPER_REVISION_REVRTL_MAX                  (0x0000001fU)

#define CSL_CP_ACE_WRAPPER_REVISION_REVMAJ_MASK                 (0x00000700U)
#define CSL_CP_ACE_WRAPPER_REVISION_REVMAJ_SHIFT                (8U)
#define CSL_CP_ACE_WRAPPER_REVISION_REVMAJ_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_WRAPPER_REVISION_REVMAJ_MAX                  (0x00000007U)

#define CSL_CP_ACE_WRAPPER_REVISION_REVCUSTOM_MASK              (0x000000C0U)
#define CSL_CP_ACE_WRAPPER_REVISION_REVCUSTOM_SHIFT             (6U)
#define CSL_CP_ACE_WRAPPER_REVISION_REVCUSTOM_RESETVAL          (0x00000000U)
#define CSL_CP_ACE_WRAPPER_REVISION_REVCUSTOM_MAX               (0x00000003U)

#define CSL_CP_ACE_WRAPPER_REVISION_REVMIN_MASK                 (0x0000003FU)
#define CSL_CP_ACE_WRAPPER_REVISION_REVMIN_SHIFT                (0U)
#define CSL_CP_ACE_WRAPPER_REVISION_REVMIN_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_WRAPPER_REVISION_REVMIN_MAX                  (0x0000003fU)

#define CSL_CP_ACE_WRAPPER_REVISION_RESETVAL                    (0x00000000U)

/* CONTROL */

#define CSL_CP_ACE_CONTROL_ERROR_ONCE_MASK                      (0x00000040U)
#define CSL_CP_ACE_CONTROL_ERROR_ONCE_SHIFT                     (6U)
#define CSL_CP_ACE_CONTROL_ERROR_ONCE_RESETVAL                  (0x00000000U)
#define CSL_CP_ACE_CONTROL_ERROR_ONCE_MAX                       (0x00000001U)

#define CSL_CP_ACE_CONTROL_FORCE_N_ROW_MASK                     (0x00000020U)
#define CSL_CP_ACE_CONTROL_FORCE_N_ROW_SHIFT                    (5U)
#define CSL_CP_ACE_CONTROL_FORCE_N_ROW_RESETVAL                 (0x00000000U)
#define CSL_CP_ACE_CONTROL_FORCE_N_ROW_MAX                      (0x00000001U)

#define CSL_CP_ACE_CONTROL_FORCE_DED_MASK                       (0x00000010U)
#define CSL_CP_ACE_CONTROL_FORCE_DED_SHIFT                      (4U)
#define CSL_CP_ACE_CONTROL_FORCE_DED_RESETVAL                   (0x00000000U)
#define CSL_CP_ACE_CONTROL_FORCE_DED_MAX                        (0x00000001U)

#define CSL_CP_ACE_CONTROL_FORCE_SEC_MASK                       (0x00000008U)
#define CSL_CP_ACE_CONTROL_FORCE_SEC_SHIFT                      (3U)
#define CSL_CP_ACE_CONTROL_FORCE_SEC_RESETVAL                   (0x00000000U)
#define CSL_CP_ACE_CONTROL_FORCE_SEC_MAX                        (0x00000001U)

#define CSL_CP_ACE_CONTROL_ENABLE_RMW_MASK                      (0x00000004U)
#define CSL_CP_ACE_CONTROL_ENABLE_RMW_SHIFT                     (2U)
#define CSL_CP_ACE_CONTROL_ENABLE_RMW_RESETVAL                  (0x00000000U)
#define CSL_CP_ACE_CONTROL_ENABLE_RMW_MAX                       (0x00000001U)

#define CSL_CP_ACE_CONTROL_ECC_CHECK_MASK                       (0x00000002U)
#define CSL_CP_ACE_CONTROL_ECC_CHECK_SHIFT                      (1U)
#define CSL_CP_ACE_CONTROL_ECC_CHECK_RESETVAL                   (0x00000000U)
#define CSL_CP_ACE_CONTROL_ECC_CHECK_MAX                        (0x00000001U)

#define CSL_CP_ACE_CONTROL_ECC_ENABLE_MASK                      (0x00000001U)
#define CSL_CP_ACE_CONTROL_ECC_ENABLE_SHIFT                     (0U)
#define CSL_CP_ACE_CONTROL_ECC_ENABLE_RESETVAL                  (0x00000000U)
#define CSL_CP_ACE_CONTROL_ECC_ENABLE_MAX                       (0x00000001U)

#define CSL_CP_ACE_CONTROL_RESETVAL                             (0x00000000U)

/* ERROR_CONTROL1 */

#define CSL_CP_ACE_ERROR_CONTROL1_ECC_BIT1_MASK                 (0xFFFF0000U)
#define CSL_CP_ACE_ERROR_CONTROL1_ECC_BIT1_SHIFT                (16U)
#define CSL_CP_ACE_ERROR_CONTROL1_ECC_BIT1_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_ERROR_CONTROL1_ECC_BIT1_MAX                  (0x0000ffffU)

#define CSL_CP_ACE_ERROR_CONTROL1_ECC_ROW_MASK                  (0x0000FFFFU)
#define CSL_CP_ACE_ERROR_CONTROL1_ECC_ROW_SHIFT                 (0U)
#define CSL_CP_ACE_ERROR_CONTROL1_ECC_ROW_RESETVAL              (0x00000000U)
#define CSL_CP_ACE_ERROR_CONTROL1_ECC_ROW_MAX                   (0x0000ffffU)

#define CSL_CP_ACE_ERROR_CONTROL1_RESETVAL                      (0x00000000U)

/* ERROR_CONTROL2 */

#define CSL_CP_ACE_ERROR_CONTROL2_ECC_BIT2_MASK                 (0x0000FFFFU)
#define CSL_CP_ACE_ERROR_CONTROL2_ECC_BIT2_SHIFT                (0U)
#define CSL_CP_ACE_ERROR_CONTROL2_ECC_BIT2_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_ERROR_CONTROL2_ECC_BIT2_MAX                  (0x0000ffffU)

#define CSL_CP_ACE_ERROR_CONTROL2_RESETVAL                      (0x00000000U)

/* ERROR_STATUS1 */

#define CSL_CP_ACE_ERROR_STATUS1_ECC_ROW_MASK                   (0xFFFF0000U)
#define CSL_CP_ACE_ERROR_STATUS1_ECC_ROW_SHIFT                  (16U)
#define CSL_CP_ACE_ERROR_STATUS1_ECC_ROW_RESETVAL               (0x00000000U)
#define CSL_CP_ACE_ERROR_STATUS1_ECC_ROW_MAX                    (0x0000ffffU)

#define CSL_CP_ACE_ERROR_STATUS1_CLR_ECC_OTHER_MASK             (0x00000400U)
#define CSL_CP_ACE_ERROR_STATUS1_CLR_ECC_OTHER_SHIFT            (10U)
#define CSL_CP_ACE_ERROR_STATUS1_CLR_ECC_OTHER_RESETVAL         (0x00000000U)
#define CSL_CP_ACE_ERROR_STATUS1_CLR_ECC_OTHER_MAX              (0x00000001U)

#define CSL_CP_ACE_ERROR_STATUS1_CLR_ECC_DED_MASK               (0x00000200U)
#define CSL_CP_ACE_ERROR_STATUS1_CLR_ECC_DED_SHIFT              (9U)
#define CSL_CP_ACE_ERROR_STATUS1_CLR_ECC_DED_RESETVAL           (0x00000000U)
#define CSL_CP_ACE_ERROR_STATUS1_CLR_ECC_DED_MAX                (0x00000001U)

#define CSL_CP_ACE_ERROR_STATUS1_CLR_ECC_SEC_MASK               (0x00000100U)
#define CSL_CP_ACE_ERROR_STATUS1_CLR_ECC_SEC_SHIFT              (8U)
#define CSL_CP_ACE_ERROR_STATUS1_CLR_ECC_SEC_RESETVAL           (0x00000000U)
#define CSL_CP_ACE_ERROR_STATUS1_CLR_ECC_SEC_MAX                (0x00000001U)

#define CSL_CP_ACE_ERROR_STATUS1_ECC_OTHER_MASK                 (0x00000004U)
#define CSL_CP_ACE_ERROR_STATUS1_ECC_OTHER_SHIFT                (2U)
#define CSL_CP_ACE_ERROR_STATUS1_ECC_OTHER_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_ERROR_STATUS1_ECC_OTHER_MAX                  (0x00000001U)

#define CSL_CP_ACE_ERROR_STATUS1_ECC_DED_MASK                   (0x00000002U)
#define CSL_CP_ACE_ERROR_STATUS1_ECC_DED_SHIFT                  (1U)
#define CSL_CP_ACE_ERROR_STATUS1_ECC_DED_RESETVAL               (0x00000000U)
#define CSL_CP_ACE_ERROR_STATUS1_ECC_DED_MAX                    (0x00000001U)

#define CSL_CP_ACE_ERROR_STATUS1_ECC_SEC_MASK                   (0x00000001U)
#define CSL_CP_ACE_ERROR_STATUS1_ECC_SEC_SHIFT                  (0U)
#define CSL_CP_ACE_ERROR_STATUS1_ECC_SEC_RESETVAL               (0x00000000U)
#define CSL_CP_ACE_ERROR_STATUS1_ECC_SEC_MAX                    (0x00000001U)

#define CSL_CP_ACE_ERROR_STATUS1_RESETVAL                       (0x00000000U)

/* ERROR_STATUS2 */

#define CSL_CP_ACE_ERROR_STATUS2_ECC_BIT1_MASK                  (0x0000FFFFU)
#define CSL_CP_ACE_ERROR_STATUS2_ECC_BIT1_SHIFT                 (0U)
#define CSL_CP_ACE_ERROR_STATUS2_ECC_BIT1_RESETVAL              (0x00000000U)
#define CSL_CP_ACE_ERROR_STATUS2_ECC_BIT1_MAX                   (0x0000ffffU)

#define CSL_CP_ACE_ERROR_STATUS2_RESETVAL                       (0x00000000U)

/* EOI */

#define CSL_CP_ACE_EOI_EOI_WR_MASK                              (0x00000001U)
#define CSL_CP_ACE_EOI_EOI_WR_SHIFT                             (0U)
#define CSL_CP_ACE_EOI_EOI_WR_RESETVAL                          (0x00000000U)
#define CSL_CP_ACE_EOI_EOI_WR_MAX                               (0x00000001U)

#define CSL_CP_ACE_EOI_RESETVAL                                 (0x00000000U)

/* INT_STATUS */

#define CSL_CP_ACE_INT_STATUS_BITMASK_MASK                      (0xFFFFFFFFU)
#define CSL_CP_ACE_INT_STATUS_BITMASK_SHIFT                     (0U)
#define CSL_CP_ACE_INT_STATUS_BITMASK_RESETVAL                  (0x00000000U)
#define CSL_CP_ACE_INT_STATUS_BITMASK_MAX                       (0xffffffffU)

#define CSL_CP_ACE_INT_STATUS_RESETVAL                          (0x00000000U)

/* INT_ENABLE */

#define CSL_CP_ACE_INT_ENABLE_BITMASK_MASK                      (0xFFFFFFFFU)
#define CSL_CP_ACE_INT_ENABLE_BITMASK_SHIFT                     (0U)
#define CSL_CP_ACE_INT_ENABLE_BITMASK_RESETVAL                  (0x00000000U)
#define CSL_CP_ACE_INT_ENABLE_BITMASK_MAX                       (0xffffffffU)

#define CSL_CP_ACE_INT_ENABLE_RESETVAL                          (0x00000000U)

/* INT_CLEAR */

#define CSL_CP_ACE_INT_CLEAR_BITMASK_MASK                       (0xFFFFFFFFU)
#define CSL_CP_ACE_INT_CLEAR_BITMASK_SHIFT                      (0U)
#define CSL_CP_ACE_INT_CLEAR_BITMASK_RESETVAL                   (0x00000000U)
#define CSL_CP_ACE_INT_CLEAR_BITMASK_MAX                        (0xffffffffU)

#define CSL_CP_ACE_INT_CLEAR_RESETVAL                           (0x00000000U)

/* TRNG_OUTPUT_L */

#define CSL_CP_ACE_TRNG_OUTPUT_L_TRNG_OUTPUT_LOW_MASK           (0xFFFFFFFFU)
#define CSL_CP_ACE_TRNG_OUTPUT_L_TRNG_OUTPUT_LOW_SHIFT          (0U)
#define CSL_CP_ACE_TRNG_OUTPUT_L_TRNG_OUTPUT_LOW_RESETVAL       (0x00000000U)
#define CSL_CP_ACE_TRNG_OUTPUT_L_TRNG_OUTPUT_LOW_MAX            (0xffffffffU)

#define CSL_CP_ACE_TRNG_OUTPUT_L_RESETVAL                       (0x00000000U)

/* TRNG_OUTPUT_H */

#define CSL_CP_ACE_TRNG_OUTPUT_H_TRNG_OUTPUT_HIGH_MASK          (0xFFFFFFFFU)
#define CSL_CP_ACE_TRNG_OUTPUT_H_TRNG_OUTPUT_HIGH_SHIFT         (0U)
#define CSL_CP_ACE_TRNG_OUTPUT_H_TRNG_OUTPUT_HIGH_RESETVAL      (0x00000000U)
#define CSL_CP_ACE_TRNG_OUTPUT_H_TRNG_OUTPUT_HIGH_MAX           (0xffffffffU)

#define CSL_CP_ACE_TRNG_OUTPUT_H_RESETVAL                       (0x00000000U)

/* TRNG_STATUS */

#define CSL_CP_ACE_TRNG_STATUS_NEED_CLOCK_MASK                  (0x80000000U)
#define CSL_CP_ACE_TRNG_STATUS_NEED_CLOCK_SHIFT                 (31U)
#define CSL_CP_ACE_TRNG_STATUS_NEED_CLOCK_RESETVAL              (0x00000000U)
#define CSL_CP_ACE_TRNG_STATUS_NEED_CLOCK_MAX                   (0x00000001U)

#define CSL_CP_ACE_TRNG_STATUS_SHUTDOWN_OFLO_MASK               (0x00000002U)
#define CSL_CP_ACE_TRNG_STATUS_SHUTDOWN_OFLO_SHIFT              (1U)
#define CSL_CP_ACE_TRNG_STATUS_SHUTDOWN_OFLO_RESETVAL           (0x00000000U)
#define CSL_CP_ACE_TRNG_STATUS_SHUTDOWN_OFLO_MAX                (0x00000001U)

#define CSL_CP_ACE_TRNG_STATUS_READY_MASK                       (0x00000001U)
#define CSL_CP_ACE_TRNG_STATUS_READY_SHIFT                      (0U)
#define CSL_CP_ACE_TRNG_STATUS_READY_RESETVAL                   (0x00000000U)
#define CSL_CP_ACE_TRNG_STATUS_READY_MAX                        (0x00000001U)

#define CSL_CP_ACE_TRNG_STATUS_RESETVAL                         (0x00000000U)

/* TRNG_INTMASK */

#define CSL_CP_ACE_TRNG_INTMASK_SHUTDOWN_OFLO_MASK              (0x00000002U)
#define CSL_CP_ACE_TRNG_INTMASK_SHUTDOWN_OFLO_SHIFT             (1U)
#define CSL_CP_ACE_TRNG_INTMASK_SHUTDOWN_OFLO_RESETVAL          (0x00000000U)
#define CSL_CP_ACE_TRNG_INTMASK_SHUTDOWN_OFLO_MAX               (0x00000001U)

#define CSL_CP_ACE_TRNG_INTMASK_READY_MASK                      (0x00000001U)
#define CSL_CP_ACE_TRNG_INTMASK_READY_SHIFT                     (0U)
#define CSL_CP_ACE_TRNG_INTMASK_READY_RESETVAL                  (0x00000000U)
#define CSL_CP_ACE_TRNG_INTMASK_READY_MAX                       (0x00000001U)

#define CSL_CP_ACE_TRNG_INTMASK_RESETVAL                        (0x00000000U)

/* TRNG_INTACK */

#define CSL_CP_ACE_TRNG_INTACK_SHUTDOWN_OFLO_MASK               (0x00000002U)
#define CSL_CP_ACE_TRNG_INTACK_SHUTDOWN_OFLO_SHIFT              (1U)
#define CSL_CP_ACE_TRNG_INTACK_SHUTDOWN_OFLO_RESETVAL           (0x00000000U)
#define CSL_CP_ACE_TRNG_INTACK_SHUTDOWN_OFLO_MAX                (0x00000001U)

#define CSL_CP_ACE_TRNG_INTACK_READY_MASK                       (0x00000001U)
#define CSL_CP_ACE_TRNG_INTACK_READY_SHIFT                      (0U)
#define CSL_CP_ACE_TRNG_INTACK_READY_RESETVAL                   (0x00000000U)
#define CSL_CP_ACE_TRNG_INTACK_READY_MAX                        (0x00000001U)

#define CSL_CP_ACE_TRNG_INTACK_RESETVAL                         (0x00000000U)

/* TRNG_CONTROL */

#define CSL_CP_ACE_TRNG_CONTROL_STARTUP_CYCLES_MASK             (0xFFFF0000U)
#define CSL_CP_ACE_TRNG_CONTROL_STARTUP_CYCLES_SHIFT            (16U)
#define CSL_CP_ACE_TRNG_CONTROL_STARTUP_CYCLES_RESETVAL         (0x00000000U)
#define CSL_CP_ACE_TRNG_CONTROL_STARTUP_CYCLES_MAX              (0x0000ffffU)

#define CSL_CP_ACE_TRNG_CONTROL_ENABLE_TRNG_MASK                (0x00000400U)
#define CSL_CP_ACE_TRNG_CONTROL_ENABLE_TRNG_SHIFT               (10U)
#define CSL_CP_ACE_TRNG_CONTROL_ENABLE_TRNG_RESETVAL            (0x00000000U)
#define CSL_CP_ACE_TRNG_CONTROL_ENABLE_TRNG_MAX                 (0x00000001U)

#define CSL_CP_ACE_TRNG_CONTROL_NO_LFSR_FB_MASK                 (0x00000004U)
#define CSL_CP_ACE_TRNG_CONTROL_NO_LFSR_FB_SHIFT                (2U)
#define CSL_CP_ACE_TRNG_CONTROL_NO_LFSR_FB_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_TRNG_CONTROL_NO_LFSR_FB_MAX                  (0x00000001U)

#define CSL_CP_ACE_TRNG_CONTROL_TEST_MODE_MASK                  (0x00000002U)
#define CSL_CP_ACE_TRNG_CONTROL_TEST_MODE_SHIFT                 (1U)
#define CSL_CP_ACE_TRNG_CONTROL_TEST_MODE_RESETVAL              (0x00000000U)
#define CSL_CP_ACE_TRNG_CONTROL_TEST_MODE_MAX                   (0x00000001U)

#define CSL_CP_ACE_TRNG_CONTROL_RESETVAL                        (0x00000000U)

/* TRNG_CONFIG */

#define CSL_CP_ACE_TRNG_CONFIG_MAX_REFILL_CYCLES_MASK           (0xFFFF0000U)
#define CSL_CP_ACE_TRNG_CONFIG_MAX_REFILL_CYCLES_SHIFT          (16U)
#define CSL_CP_ACE_TRNG_CONFIG_MAX_REFILL_CYCLES_RESETVAL       (0x00000000U)
#define CSL_CP_ACE_TRNG_CONFIG_MAX_REFILL_CYCLES_MAX            (0x0000ffffU)

#define CSL_CP_ACE_TRNG_CONFIG_SAMPLE_DIV_MASK                  (0x00000F00U)
#define CSL_CP_ACE_TRNG_CONFIG_SAMPLE_DIV_SHIFT                 (8U)
#define CSL_CP_ACE_TRNG_CONFIG_SAMPLE_DIV_RESETVAL              (0x00000000U)
#define CSL_CP_ACE_TRNG_CONFIG_SAMPLE_DIV_MAX                   (0x0000000fU)

#define CSL_CP_ACE_TRNG_CONFIG_MIN_REFILL_CYCLES_MASK           (0x000000FFU)
#define CSL_CP_ACE_TRNG_CONFIG_MIN_REFILL_CYCLES_SHIFT          (0U)
#define CSL_CP_ACE_TRNG_CONFIG_MIN_REFILL_CYCLES_RESETVAL       (0x00000000U)
#define CSL_CP_ACE_TRNG_CONFIG_MIN_REFILL_CYCLES_MAX            (0x000000ffU)

#define CSL_CP_ACE_TRNG_CONFIG_RESETVAL                         (0x00000000U)

/* TRNG_ALARMCNT */

#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_COUNT_MASK            (0x3F000000U)
#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_COUNT_SHIFT           (24U)
#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_COUNT_RESETVAL        (0x00000000U)
#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_COUNT_MAX             (0x0000003fU)

#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_MASK        (0x001F0000U)
#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_SHIFT       (16U)
#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_RESETVAL    (0x00000000U)
#define CSL_CP_ACE_TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_MAX         (0x0000001fU)

#define CSL_CP_ACE_TRNG_ALARMCNT_ALARM_THRESHOLD_MASK           (0x000000FFU)
#define CSL_CP_ACE_TRNG_ALARMCNT_ALARM_THRESHOLD_SHIFT          (0U)
#define CSL_CP_ACE_TRNG_ALARMCNT_ALARM_THRESHOLD_RESETVAL       (0x00000000U)
#define CSL_CP_ACE_TRNG_ALARMCNT_ALARM_THRESHOLD_MAX            (0x000000ffU)

#define CSL_CP_ACE_TRNG_ALARMCNT_RESETVAL                       (0x00000000U)

/* TRNG_FROENABLE */

#define CSL_CP_ACE_TRNG_FROENABLE_FRO_ENABLES_MASK              (0x00FFFFFFU)
#define CSL_CP_ACE_TRNG_FROENABLE_FRO_ENABLES_SHIFT             (0U)
#define CSL_CP_ACE_TRNG_FROENABLE_FRO_ENABLES_RESETVAL          (0x00000000U)
#define CSL_CP_ACE_TRNG_FROENABLE_FRO_ENABLES_MAX               (0x00ffffffU)

#define CSL_CP_ACE_TRNG_FROENABLE_RESETVAL                      (0x00000000U)

/* TRNG_FRODETUNE */

#define CSL_CP_ACE_TRNG_FRODETUNE_FRO_DETUNES_MASK              (0x00FFFFFFU)
#define CSL_CP_ACE_TRNG_FRODETUNE_FRO_DETUNES_SHIFT             (0U)
#define CSL_CP_ACE_TRNG_FRODETUNE_FRO_DETUNES_RESETVAL          (0x00000000U)
#define CSL_CP_ACE_TRNG_FRODETUNE_FRO_DETUNES_MAX               (0x00ffffffU)

#define CSL_CP_ACE_TRNG_FRODETUNE_RESETVAL                      (0x00000000U)

/* TRNG_ALARMMASK */

#define CSL_CP_ACE_TRNG_ALARMMASK_FRO_ALARMMASKS_MASK           (0x00FFFFFFU)
#define CSL_CP_ACE_TRNG_ALARMMASK_FRO_ALARMMASKS_SHIFT          (0U)
#define CSL_CP_ACE_TRNG_ALARMMASK_FRO_ALARMMASKS_RESETVAL       (0x00000000U)
#define CSL_CP_ACE_TRNG_ALARMMASK_FRO_ALARMMASKS_MAX            (0x00ffffffU)

#define CSL_CP_ACE_TRNG_ALARMMASK_RESETVAL                      (0x00000000U)

/* TRNG_ALARMSTOP */

#define CSL_CP_ACE_TRNG_ALARMSTOP_FRO_ALARMSTOPS_MASK           (0x00FFFFFFU)
#define CSL_CP_ACE_TRNG_ALARMSTOP_FRO_ALARMSTOPS_SHIFT          (0U)
#define CSL_CP_ACE_TRNG_ALARMSTOP_FRO_ALARMSTOPS_RESETVAL       (0x00000000U)
#define CSL_CP_ACE_TRNG_ALARMSTOP_FRO_ALARMSTOPS_MAX            (0x00ffffffU)

#define CSL_CP_ACE_TRNG_ALARMSTOP_RESETVAL                      (0x00000000U)

/* TRNG_LFSR_L */

#define CSL_CP_ACE_TRNG_LFSR_L_LFSR_LOW_MASK                    (0xFFFFFFFFU)
#define CSL_CP_ACE_TRNG_LFSR_L_LFSR_LOW_SHIFT                   (0U)
#define CSL_CP_ACE_TRNG_LFSR_L_LFSR_LOW_RESETVAL                (0x00000000U)
#define CSL_CP_ACE_TRNG_LFSR_L_LFSR_LOW_MAX                     (0xffffffffU)

#define CSL_CP_ACE_TRNG_LFSR_L_RESETVAL                         (0x00000000U)

/* TRNG_LFSR_M */

#define CSL_CP_ACE_TRNG_LFSR_M_LFSR_MID_MASK                    (0xFFFFFFFFU)
#define CSL_CP_ACE_TRNG_LFSR_M_LFSR_MID_SHIFT                   (0U)
#define CSL_CP_ACE_TRNG_LFSR_M_LFSR_MID_RESETVAL                (0x00000000U)
#define CSL_CP_ACE_TRNG_LFSR_M_LFSR_MID_MAX                     (0xffffffffU)

#define CSL_CP_ACE_TRNG_LFSR_M_RESETVAL                         (0x00000000U)

/* TRNG_LFSR_H */

#define CSL_CP_ACE_TRNG_LFSR_H_LFSR_HIGH_MASK                   (0x0001FFFFU)
#define CSL_CP_ACE_TRNG_LFSR_H_LFSR_HIGH_SHIFT                  (0U)
#define CSL_CP_ACE_TRNG_LFSR_H_LFSR_HIGH_RESETVAL               (0x00000000U)
#define CSL_CP_ACE_TRNG_LFSR_H_LFSR_HIGH_MAX                    (0x0001ffffU)

#define CSL_CP_ACE_TRNG_LFSR_H_RESETVAL                         (0x00000000U)

/* TRNG_COUNT */

#define CSL_CP_ACE_TRNG_COUNT_SAMPLE_COUNTER_MASK               (0x00FFFFFFU)
#define CSL_CP_ACE_TRNG_COUNT_SAMPLE_COUNTER_SHIFT              (0U)
#define CSL_CP_ACE_TRNG_COUNT_SAMPLE_COUNTER_RESETVAL           (0x00000000U)
#define CSL_CP_ACE_TRNG_COUNT_SAMPLE_COUNTER_MAX                (0x00ffffffU)

#define CSL_CP_ACE_TRNG_COUNT_RESETVAL                          (0x00000000U)

/* TRNG_TEST */

#define CSL_CP_ACE_TRNG_TEST_TEST_PATTERN_MASK                  (0x0FFF0000U)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATTERN_SHIFT                 (16U)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATTERN_RESETVAL              (0x00000000U)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATTERN_MAX                   (0x00000fffU)

#define CSL_CP_ACE_TRNG_TEST_TEST_SELECT_MASK                   (0x00001F00U)
#define CSL_CP_ACE_TRNG_TEST_TEST_SELECT_SHIFT                  (8U)
#define CSL_CP_ACE_TRNG_TEST_TEST_SELECT_RESETVAL               (0x00000000U)
#define CSL_CP_ACE_TRNG_TEST_TEST_SELECT_MAX                    (0x0000001fU)

#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_DET_MASK                 (0x00000004U)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_DET_SHIFT                (2U)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_DET_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_DET_MAX                  (0x00000001U)

#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_FRO_MASK                 (0x00000002U)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_FRO_SHIFT                (1U)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_FRO_RESETVAL             (0x00000000U)
#define CSL_CP_ACE_TRNG_TEST_TEST_PATT_FRO_MAX                  (0x00000001U)

#define CSL_CP_ACE_TRNG_TEST_TEST_EN_OUT_MASK                   (0x00000001U)
#define CSL_CP_ACE_TRNG_TEST_TEST_EN_OUT_SHIFT                  (0U)
#define CSL_CP_ACE_TRNG_TEST_TEST_EN_OUT_RESETVAL               (0x00000000U)
#define CSL_CP_ACE_TRNG_TEST_TEST_EN_OUT_MAX                    (0x00000001U)

#define CSL_CP_ACE_TRNG_TEST_RESETVAL                           (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif

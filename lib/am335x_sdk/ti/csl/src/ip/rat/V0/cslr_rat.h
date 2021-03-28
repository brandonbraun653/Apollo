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
 *  Name        : cslr_rat.h
*/
#ifndef CSLR_RAT_H_
#define CSLR_RAT_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : KSBUS Region-Based Address Translation
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t CTRL;                      /* Region Control Register */
    volatile uint32_t BASE;                      /* Region Base Register */
    volatile uint32_t TRANS_L;                   /* Region Translated Lower Address */
    volatile uint32_t TRANS_U;                   /* Region Translated Upper Address */
} CSL_ratRegs_region;


typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint32_t CONFIG;                    /* Config Register */
    volatile uint8_t  Resv_32[24];
    CSL_ratRegs_region REGION[16];
    volatile uint8_t  Resv_2052[1764];
    volatile uint32_t DESTINATION_ID;            /* Destination ID Register */
    volatile uint8_t  Resv_2080[24];
    volatile uint32_t EXCEPTION_LOGGING_CONTROL;   /* Exception Logging Control Register */
    volatile uint32_t EXCEPTION_LOGGING_HEADER0;   /* Exception Logging Header 0 Register */
    volatile uint32_t EXCEPTION_LOGGING_HEADER1;   /* Exception Logging Header 1 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA0;   /* Exception Logging Data 0 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA1;   /* Exception Logging Data 1 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA2;   /* Exception Logging Data 2 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA3;   /* Exception Logging Data 3 Register */
    volatile uint8_t  Resv_2112[4];
    volatile uint32_t EXCEPTION_PEND_SET;        /* Exception Logging Interrupt Pending Set Register */
    volatile uint32_t EXCEPTION_PEND_CLEAR;      /* Exception Logging Interrupt Pending Clear Register */
    volatile uint32_t EXCEPTION_ENABLE_SET;      /* Exception Logging Interrupt Enable Set Register */
    volatile uint32_t EXCEPTION_ENABLE_CLEAR;    /* Exception Logging Interrupt Enable Clear Register */
    volatile uint32_t EOI_REG;                   /* EOI Register */
} CSL_ratRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_RAT_PID                                                            (0x00000000U)
#define CSL_RAT_CONFIG                                                         (0x00000004U)
#define CSL_RAT_REGION_CTRL(REGION)                                            (0x00000020U+((REGION)*0x10U))
#define CSL_RAT_REGION_BASE(REGION)                                            (0x00000024U+((REGION)*0x10U))
#define CSL_RAT_REGION_TRANS_L(REGION)                                         (0x00000028U+((REGION)*0x10U))
#define CSL_RAT_REGION_TRANS_U(REGION)                                         (0x0000002CU+((REGION)*0x10U))
#define CSL_RAT_DESTINATION_ID                                                 (0x00000804U)
#define CSL_RAT_EXCEPTION_LOGGING_CONTROL                                      (0x00000820U)
#define CSL_RAT_EXCEPTION_LOGGING_HEADER0                                      (0x00000824U)
#define CSL_RAT_EXCEPTION_LOGGING_HEADER1                                      (0x00000828U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA0                                        (0x0000082CU)
#define CSL_RAT_EXCEPTION_LOGGING_DATA1                                        (0x00000830U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2                                        (0x00000834U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA3                                        (0x00000838U)
#define CSL_RAT_EXCEPTION_PEND_SET                                             (0x00000840U)
#define CSL_RAT_EXCEPTION_PEND_CLEAR                                           (0x00000844U)
#define CSL_RAT_EXCEPTION_ENABLE_SET                                           (0x00000848U)
#define CSL_RAT_EXCEPTION_ENABLE_CLEAR                                         (0x0000084CU)
#define CSL_RAT_EOI_REG                                                        (0x00000850U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* CTRL */

#define CSL_RAT_REGION_CTRL_EN_MASK                                            (0x80000000U)
#define CSL_RAT_REGION_CTRL_EN_SHIFT                                           (0x0000001FU)
#define CSL_RAT_REGION_CTRL_EN_MAX                                             (0x00000001U)

#define CSL_RAT_REGION_CTRL_SIZE_MASK                                          (0x0000003FU)
#define CSL_RAT_REGION_CTRL_SIZE_SHIFT                                         (0x00000000U)
#define CSL_RAT_REGION_CTRL_SIZE_MAX                                           (0x0000003FU)

/* BASE */

#define CSL_RAT_REGION_BASE_BASE_MASK                                          (0xFFFFFFFFU)
#define CSL_RAT_REGION_BASE_BASE_SHIFT                                         (0x00000000U)
#define CSL_RAT_REGION_BASE_BASE_MAX                                           (0xFFFFFFFFU)

/* TRANS_L */

#define CSL_RAT_REGION_TRANS_L_LOWER_MASK                                      (0xFFFFFFFFU)
#define CSL_RAT_REGION_TRANS_L_LOWER_SHIFT                                     (0x00000000U)
#define CSL_RAT_REGION_TRANS_L_LOWER_MAX                                       (0xFFFFFFFFU)

/* TRANS_U */

#define CSL_RAT_REGION_TRANS_U_UPPER_MASK                                      (0x0000FFFFU)
#define CSL_RAT_REGION_TRANS_U_UPPER_SHIFT                                     (0x00000000U)
#define CSL_RAT_REGION_TRANS_U_UPPER_MAX                                       (0x0000FFFFU)

/* PID */

#define CSL_RAT_PID_MINOR_MASK                                                 (0x0000003FU)
#define CSL_RAT_PID_MINOR_SHIFT                                                (0x00000000U)
#define CSL_RAT_PID_MINOR_MAX                                                  (0x0000003FU)

#define CSL_RAT_PID_CUSTOM_MASK                                                (0x000000C0U)
#define CSL_RAT_PID_CUSTOM_SHIFT                                               (0x00000006U)
#define CSL_RAT_PID_CUSTOM_MAX                                                 (0x00000003U)

#define CSL_RAT_PID_MAJOR_MASK                                                 (0x00000700U)
#define CSL_RAT_PID_MAJOR_SHIFT                                                (0x00000008U)
#define CSL_RAT_PID_MAJOR_MAX                                                  (0x00000007U)

#define CSL_RAT_PID_RTL_MASK                                                   (0x0000F800U)
#define CSL_RAT_PID_RTL_SHIFT                                                  (0x0000000BU)
#define CSL_RAT_PID_RTL_MAX                                                    (0x0000001FU)

#define CSL_RAT_PID_FUNC_MASK                                                  (0x0FFF0000U)
#define CSL_RAT_PID_FUNC_SHIFT                                                 (0x00000010U)
#define CSL_RAT_PID_FUNC_MAX                                                   (0x00000FFFU)

#define CSL_RAT_PID_BU_MASK                                                    (0x30000000U)
#define CSL_RAT_PID_BU_SHIFT                                                   (0x0000001CU)
#define CSL_RAT_PID_BU_MAX                                                     (0x00000003U)

#define CSL_RAT_PID_SCHEME_MASK                                                (0xC0000000U)
#define CSL_RAT_PID_SCHEME_SHIFT                                               (0x0000001EU)
#define CSL_RAT_PID_SCHEME_MAX                                                 (0x00000003U)

/* CONFIG */

#define CSL_RAT_CONFIG_REGIONS_MASK                                            (0x000000FFU)
#define CSL_RAT_CONFIG_REGIONS_SHIFT                                           (0x00000000U)
#define CSL_RAT_CONFIG_REGIONS_MAX                                             (0x000000FFU)

#define CSL_RAT_CONFIG_ADDRS_MASK                                              (0x0000FF00U)
#define CSL_RAT_CONFIG_ADDRS_SHIFT                                             (0x00000008U)
#define CSL_RAT_CONFIG_ADDRS_MAX                                               (0x000000FFU)

#define CSL_RAT_CONFIG_ADDR_WIDTH_MASK                                         (0x00FF0000U)
#define CSL_RAT_CONFIG_ADDR_WIDTH_SHIFT                                        (0x00000010U)
#define CSL_RAT_CONFIG_ADDR_WIDTH_MAX                                          (0x000000FFU)

/* DESTINATION_ID */

#define CSL_RAT_DESTINATION_ID_DEST_ID_MASK                                    (0x000000FFU)
#define CSL_RAT_DESTINATION_ID_DEST_ID_SHIFT                                   (0x00000000U)
#define CSL_RAT_DESTINATION_ID_DEST_ID_MAX                                     (0x000000FFU)

/* EXCEPTION_LOGGING_CONTROL */

#define CSL_RAT_EXCEPTION_LOGGING_CONTROL_DISABLE_F_MASK                       (0x00000001U)
#define CSL_RAT_EXCEPTION_LOGGING_CONTROL_DISABLE_F_SHIFT                      (0x00000000U)
#define CSL_RAT_EXCEPTION_LOGGING_CONTROL_DISABLE_F_MAX                        (0x00000001U)

#define CSL_RAT_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR_MASK                    (0x00000002U)
#define CSL_RAT_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR_SHIFT                   (0x00000001U)
#define CSL_RAT_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR_MAX                     (0x00000001U)

/* EXCEPTION_LOGGING_HEADER0 */

#define CSL_RAT_EXCEPTION_LOGGING_HEADER0_DEST_ID_MASK                         (0x000000FFU)
#define CSL_RAT_EXCEPTION_LOGGING_HEADER0_DEST_ID_SHIFT                        (0x00000000U)
#define CSL_RAT_EXCEPTION_LOGGING_HEADER0_DEST_ID_MAX                          (0x000000FFU)

#define CSL_RAT_EXCEPTION_LOGGING_HEADER0_SRC_ID_MASK                          (0x00FFFF00U)
#define CSL_RAT_EXCEPTION_LOGGING_HEADER0_SRC_ID_SHIFT                         (0x00000008U)
#define CSL_RAT_EXCEPTION_LOGGING_HEADER0_SRC_ID_MAX                           (0x0000FFFFU)

#define CSL_RAT_EXCEPTION_LOGGING_HEADER0_TYPE_F_MASK                          (0xFF000000U)
#define CSL_RAT_EXCEPTION_LOGGING_HEADER0_TYPE_F_SHIFT                         (0x00000018U)
#define CSL_RAT_EXCEPTION_LOGGING_HEADER0_TYPE_F_MAX                           (0x000000FFU)

/* EXCEPTION_LOGGING_HEADER1 */

#define CSL_RAT_EXCEPTION_LOGGING_HEADER1_CODE_MASK                            (0x00FF0000U)
#define CSL_RAT_EXCEPTION_LOGGING_HEADER1_CODE_SHIFT                           (0x00000010U)
#define CSL_RAT_EXCEPTION_LOGGING_HEADER1_CODE_MAX                             (0x000000FFU)

#define CSL_RAT_EXCEPTION_LOGGING_HEADER1_GROUP_MASK                           (0xFF000000U)
#define CSL_RAT_EXCEPTION_LOGGING_HEADER1_GROUP_SHIFT                          (0x00000018U)
#define CSL_RAT_EXCEPTION_LOGGING_HEADER1_GROUP_MAX                            (0x000000FFU)

/* EXCEPTION_LOGGING_DATA0 */

#define CSL_RAT_EXCEPTION_LOGGING_DATA0_ADDR_L_MASK                            (0xFFFFFFFFU)
#define CSL_RAT_EXCEPTION_LOGGING_DATA0_ADDR_L_SHIFT                           (0x00000000U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA0_ADDR_L_MAX                             (0xFFFFFFFFU)

/* EXCEPTION_LOGGING_DATA1 */

#define CSL_RAT_EXCEPTION_LOGGING_DATA1_ADDR_H_MASK                            (0x0000FFFFU)
#define CSL_RAT_EXCEPTION_LOGGING_DATA1_ADDR_H_SHIFT                           (0x00000000U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA1_ADDR_H_MAX                             (0x0000FFFFU)

/* EXCEPTION_LOGGING_DATA2 */

#define CSL_RAT_EXCEPTION_LOGGING_DATA2_PRIV_ID_MASK                           (0x000000FFU)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_PRIV_ID_SHIFT                          (0x00000000U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_PRIV_ID_MAX                            (0x000000FFU)

#define CSL_RAT_EXCEPTION_LOGGING_DATA2_SECURE_MASK                            (0x00000100U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_SECURE_SHIFT                           (0x00000008U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_SECURE_MAX                             (0x00000001U)

#define CSL_RAT_EXCEPTION_LOGGING_DATA2_PRIV_MASK                              (0x00000200U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_PRIV_SHIFT                             (0x00000009U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_PRIV_MAX                               (0x00000001U)

#define CSL_RAT_EXCEPTION_LOGGING_DATA2_CACHEABLE_MASK                         (0x00000400U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_CACHEABLE_SHIFT                        (0x0000000AU)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_CACHEABLE_MAX                          (0x00000001U)

#define CSL_RAT_EXCEPTION_LOGGING_DATA2_DEBUG_MASK                             (0x00000800U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_DEBUG_SHIFT                            (0x0000000BU)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_DEBUG_MAX                              (0x00000001U)

#define CSL_RAT_EXCEPTION_LOGGING_DATA2_READ_MASK                              (0x00001000U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_READ_SHIFT                             (0x0000000CU)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_READ_MAX                               (0x00000001U)

#define CSL_RAT_EXCEPTION_LOGGING_DATA2_WRITE_MASK                             (0x00002000U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_WRITE_SHIFT                            (0x0000000DU)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_WRITE_MAX                              (0x00000001U)

#define CSL_RAT_EXCEPTION_LOGGING_DATA2_ROUTEID_MASK                           (0x0FFF0000U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_ROUTEID_SHIFT                          (0x00000010U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA2_ROUTEID_MAX                            (0x00000FFFU)

/* EXCEPTION_LOGGING_DATA3 */

#define CSL_RAT_EXCEPTION_LOGGING_DATA3_BYTECNT_MASK                           (0x000003FFU)
#define CSL_RAT_EXCEPTION_LOGGING_DATA3_BYTECNT_SHIFT                          (0x00000000U)
#define CSL_RAT_EXCEPTION_LOGGING_DATA3_BYTECNT_MAX                            (0x000003FFU)

/* EXCEPTION_PEND_SET */

#define CSL_RAT_EXCEPTION_PEND_SET_PEND_SET_MASK                               (0x00000001U)
#define CSL_RAT_EXCEPTION_PEND_SET_PEND_SET_SHIFT                              (0x00000000U)
#define CSL_RAT_EXCEPTION_PEND_SET_PEND_SET_MAX                                (0x00000001U)

/* EXCEPTION_PEND_CLEAR */

#define CSL_RAT_EXCEPTION_PEND_CLEAR_PEND_CLR_MASK                             (0x00000001U)
#define CSL_RAT_EXCEPTION_PEND_CLEAR_PEND_CLR_SHIFT                            (0x00000000U)
#define CSL_RAT_EXCEPTION_PEND_CLEAR_PEND_CLR_MAX                              (0x00000001U)

/* EXCEPTION_ENABLE_SET */

#define CSL_RAT_EXCEPTION_ENABLE_SET_ENABLE_SET_MASK                           (0x00000001U)
#define CSL_RAT_EXCEPTION_ENABLE_SET_ENABLE_SET_SHIFT                          (0x00000000U)
#define CSL_RAT_EXCEPTION_ENABLE_SET_ENABLE_SET_MAX                            (0x00000001U)

/* EXCEPTION_ENABLE_CLEAR */

#define CSL_RAT_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR_MASK                         (0x00000001U)
#define CSL_RAT_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR_SHIFT                        (0x00000000U)
#define CSL_RAT_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR_MAX                          (0x00000001U)

/* EOI_REG */

#define CSL_RAT_EOI_REG_EOI_WR_MASK                                            (0x0000FFFFU)
#define CSL_RAT_EOI_REG_EOI_WR_SHIFT                                           (0x00000000U)
#define CSL_RAT_EOI_REG_EOI_WR_MAX                                             (0x0000FFFFU)

#ifdef __cplusplus
}
#endif
#endif

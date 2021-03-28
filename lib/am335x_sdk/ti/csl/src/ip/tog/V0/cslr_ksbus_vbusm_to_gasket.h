/********************************************************************
 * Copyright (C) 2019 Texas Instruments Incorporated.
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
 *  Name        : cslr_ksbus_vbusm_to_gasket.h
*/
#ifndef CSLR_KSBUS_VBUSM_TO_GASKET_H_
#define CSLR_KSBUS_VBUSM_TO_GASKET_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : Timeout Gasket Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint32_t CFG;                       /* Configuration Register */
    volatile uint32_t INFO;                      /* Info Register */
    volatile uint32_t ENABLE;                    /* Enable Register */
    volatile uint32_t FLUSH;                     /* Flush Register */
    volatile uint32_t TIMEOUT;                   /* Timeout Value Register */
    volatile uint32_t TIMER;                     /* Timer Register */
    volatile uint8_t  Resv_32[4];
    volatile uint32_t ERR_RAW;                   /* Error Interrupt Raw Status/Set Register */
    volatile uint32_t ERR;                       /* Error Interrupt Enabled Status/Set Register */
    volatile uint32_t ERR_MSK_SET;               /* Error Interrupt Mask Set Register */
    volatile uint32_t ERR_MSK_CLR;               /* Error Interrupt Mask Set Register */
    volatile uint32_t ERR_TM_INFO;               /* Timeout Error Info Register */
    volatile uint32_t ERR_UN_INFO;               /* Unexpected Error Info Register */
    volatile uint32_t ERR_VAL;                   /* Error Transaction Valid/Dir/RouteID Register */
    volatile uint32_t ERR_TAG;                   /* Error Transaction Tag/CommandID Register */
    volatile uint32_t ERR_BYT;                   /* Error Transaction Bytecnt Register */
    volatile uint32_t ERR_ADDR_U;                /* Error Upper Address Register */
    volatile uint32_t ERR_ADDR_L;                /* Error Upper Address Register */
} CSL_ksbus_vbusm_to_gasketRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_KSBUS_VBUSM_TO_GASKET_PID                                          (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_CFG                                          (0x00000004U)
#define CSL_KSBUS_VBUSM_TO_GASKET_INFO                                         (0x00000008U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ENABLE                                       (0x0000000CU)
#define CSL_KSBUS_VBUSM_TO_GASKET_FLUSH                                        (0x00000010U)
#define CSL_KSBUS_VBUSM_TO_GASKET_TIMEOUT                                      (0x00000014U)
#define CSL_KSBUS_VBUSM_TO_GASKET_TIMER                                        (0x00000018U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_RAW                                      (0x00000020U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR                                          (0x00000024U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_SET                                  (0x00000028U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_CLR                                  (0x0000002CU)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TM_INFO                                  (0x00000030U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_UN_INFO                                  (0x00000034U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL                                      (0x00000038U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TAG                                      (0x0000003CU)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_BYT                                      (0x00000040U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_ADDR_U                                   (0x00000044U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_ADDR_L                                   (0x00000048U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_KSBUS_VBUSM_TO_GASKET_PID_MINOR_MASK                               (0x0000003FU)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_MINOR_SHIFT                              (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_MINOR_MAX                                (0x0000003FU)

#define CSL_KSBUS_VBUSM_TO_GASKET_PID_CUSTOM_MASK                              (0x000000C0U)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_CUSTOM_SHIFT                             (0x00000006U)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_CUSTOM_MAX                               (0x00000003U)

#define CSL_KSBUS_VBUSM_TO_GASKET_PID_MAJOR_MASK                               (0x00000700U)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_MAJOR_SHIFT                              (0x00000008U)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_MAJOR_MAX                                (0x00000007U)

#define CSL_KSBUS_VBUSM_TO_GASKET_PID_RTL_MASK                                 (0x0000F800U)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_RTL_SHIFT                                (0x0000000BU)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_RTL_MAX                                  (0x0000001FU)

#define CSL_KSBUS_VBUSM_TO_GASKET_PID_FUNC_MASK                                (0x0FFF0000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_FUNC_SHIFT                               (0x00000010U)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_FUNC_MAX                                 (0x00000FFFU)

#define CSL_KSBUS_VBUSM_TO_GASKET_PID_BU_MASK                                  (0x30000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_BU_SHIFT                                 (0x0000001CU)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_BU_MAX                                   (0x00000003U)

#define CSL_KSBUS_VBUSM_TO_GASKET_PID_SCHEME_MASK                              (0xC0000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_SCHEME_SHIFT                             (0x0000001EU)
#define CSL_KSBUS_VBUSM_TO_GASKET_PID_SCHEME_MAX                               (0x00000003U)

/* CFG */

#define CSL_KSBUS_VBUSM_TO_GASKET_CFG_NUM_WRITES_MASK                          (0x00FF0000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_CFG_NUM_WRITES_SHIFT                         (0x00000010U)
#define CSL_KSBUS_VBUSM_TO_GASKET_CFG_NUM_WRITES_MAX                           (0x000000FFU)

#define CSL_KSBUS_VBUSM_TO_GASKET_CFG_NUM_READS_MASK                           (0x000000FFU)
#define CSL_KSBUS_VBUSM_TO_GASKET_CFG_NUM_READS_SHIFT                          (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_CFG_NUM_READS_MAX                            (0x000000FFU)

/* INFO */

#define CSL_KSBUS_VBUSM_TO_GASKET_INFO_CUR_WRITES_MASK                         (0x01FF0000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_INFO_CUR_WRITES_SHIFT                        (0x00000010U)
#define CSL_KSBUS_VBUSM_TO_GASKET_INFO_CUR_WRITES_MAX                          (0x000001FFU)

#define CSL_KSBUS_VBUSM_TO_GASKET_INFO_CUR_READS_MASK                          (0x000001FFU)
#define CSL_KSBUS_VBUSM_TO_GASKET_INFO_CUR_READS_SHIFT                         (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_INFO_CUR_READS_MAX                           (0x000001FFU)

/* ENABLE */

#define CSL_KSBUS_VBUSM_TO_GASKET_ENABLE_EN_MASK                               (0x0000000FU)
#define CSL_KSBUS_VBUSM_TO_GASKET_ENABLE_EN_SHIFT                              (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ENABLE_EN_MAX                                (0x0000000FU)

/* FLUSH */

#define CSL_KSBUS_VBUSM_TO_GASKET_FLUSH_EXT_FL_MASK                            (0x80000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_FLUSH_EXT_FL_SHIFT                           (0x0000001FU)
#define CSL_KSBUS_VBUSM_TO_GASKET_FLUSH_EXT_FL_MAX                             (0x00000001U)

#define CSL_KSBUS_VBUSM_TO_GASKET_FLUSH_FL_MASK                                (0x0000000FU)
#define CSL_KSBUS_VBUSM_TO_GASKET_FLUSH_FL_SHIFT                               (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_FLUSH_FL_MAX                                 (0x0000000FU)

/* TIMEOUT */

#define CSL_KSBUS_VBUSM_TO_GASKET_TIMEOUT_TO_MASK                              (0x3FFFFFFFU)
#define CSL_KSBUS_VBUSM_TO_GASKET_TIMEOUT_TO_SHIFT                             (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_TIMEOUT_TO_MAX                               (0x3FFFFFFFU)

/* TIMER */

#define CSL_KSBUS_VBUSM_TO_GASKET_TIMER_EON_MASK                               (0xC0000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_TIMER_EON_SHIFT                              (0x0000001EU)
#define CSL_KSBUS_VBUSM_TO_GASKET_TIMER_EON_MAX                                (0x00000003U)

#define CSL_KSBUS_VBUSM_TO_GASKET_TIMER_CNTR_MASK                              (0x3FFFFFFFU)
#define CSL_KSBUS_VBUSM_TO_GASKET_TIMER_CNTR_SHIFT                             (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_TIMER_CNTR_MAX                               (0x3FFFFFFFU)

/* ERR_RAW */

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_RAW_CMD_MASK                             (0x00000004U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_RAW_CMD_SHIFT                            (0x00000002U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_RAW_CMD_MAX                              (0x00000001U)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_RAW_UNEXP_MASK                           (0x00000002U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_RAW_UNEXP_SHIFT                          (0x00000001U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_RAW_UNEXP_MAX                            (0x00000001U)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_RAW_TIMEOUT_MASK                         (0x00000001U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_RAW_TIMEOUT_SHIFT                        (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_RAW_TIMEOUT_MAX                          (0x00000001U)

/* ERR */

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_CMD_MASK                                 (0x00000004U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_CMD_SHIFT                                (0x00000002U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_CMD_MAX                                  (0x00000001U)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_UNEXP_MASK                               (0x00000002U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_UNEXP_SHIFT                              (0x00000001U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_UNEXP_MAX                                (0x00000001U)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TIMEOUT_MASK                             (0x00000001U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TIMEOUT_SHIFT                            (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TIMEOUT_MAX                              (0x00000001U)

/* ERR_MSK_SET */

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_SET_CMD_MASK                         (0x00000004U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_SET_CMD_SHIFT                        (0x00000002U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_SET_CMD_MAX                          (0x00000001U)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_SET_UNEXP_MASK                       (0x00000002U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_SET_UNEXP_SHIFT                      (0x00000001U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_SET_UNEXP_MAX                        (0x00000001U)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_SET_TIMEOUT_MASK                     (0x00000001U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_SET_TIMEOUT_SHIFT                    (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_SET_TIMEOUT_MAX                      (0x00000001U)

/* ERR_MSK_CLR */

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_CLR_CMD_MASK                         (0x00000004U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_CLR_CMD_SHIFT                        (0x00000002U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_CLR_CMD_MAX                          (0x00000001U)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_CLR_UNEXP_MASK                       (0x00000002U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_CLR_UNEXP_SHIFT                      (0x00000001U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_CLR_UNEXP_MAX                        (0x00000001U)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_CLR_TIMEOUT_MASK                     (0x00000001U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_CLR_TIMEOUT_SHIFT                    (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_MSK_CLR_TIMEOUT_MAX                      (0x00000001U)

/* ERR_TM_INFO */

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TM_INFO_CNT_MASK                         (0x00000003U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TM_INFO_CNT_SHIFT                        (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TM_INFO_CNT_MAX                          (0x00000003U)

/* ERR_UN_INFO */

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_UN_INFO_CNT_MASK                         (0x00000003U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_UN_INFO_CNT_SHIFT                        (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_UN_INFO_CNT_MAX                          (0x00000003U)

/* ERR_VAL */

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_RID_MASK                             (0x0FFF0000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_RID_SHIFT                            (0x00000010U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_RID_MAX                              (0x00000FFFU)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_OID_MASK                             (0x00000F00U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_OID_SHIFT                            (0x00000008U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_OID_MAX                              (0x0000000FU)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_DIR_MASK                             (0x00000004U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_DIR_SHIFT                            (0x00000002U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_DIR_MAX                              (0x00000001U)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_TYP_MASK                             (0x00000002U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_TYP_SHIFT                            (0x00000001U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_TYP_MAX                              (0x00000001U)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_VAL_MASK                             (0x00000001U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_VAL_SHIFT                            (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_VAL_VAL_MAX                              (0x00000001U)

/* ERR_TAG */

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TAG_TAG_MASK                             (0x0FFF0000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TAG_TAG_SHIFT                            (0x00000010U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TAG_TAG_MAX                              (0x00000FFFU)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TAG_CID_MASK                             (0x00000FFFU)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TAG_CID_SHIFT                            (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_TAG_CID_MAX                              (0x00000FFFU)

/* ERR_BYT */

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_BYT_CBYTECNT_MASK                        (0x03FF0000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_BYT_CBYTECNT_SHIFT                       (0x00000010U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_BYT_CBYTECNT_MAX                         (0x000003FFU)

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_BYT_OBYTECNT_MASK                        (0x000003FFU)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_BYT_OBYTECNT_SHIFT                       (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_BYT_OBYTECNT_MAX                         (0x000003FFU)

/* ERR_ADDR_U */

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_ADDR_U_ADDR_MASK                         (0xFFFFFFFFU)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_ADDR_U_ADDR_SHIFT                        (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_ADDR_U_ADDR_MAX                          (0xFFFFFFFFU)

/* ERR_ADDR_L */

#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_ADDR_L_ADDR_MASK                         (0xFFFFFFFFU)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_ADDR_L_ADDR_SHIFT                        (0x00000000U)
#define CSL_KSBUS_VBUSM_TO_GASKET_ERR_ADDR_L_ADDR_MAX                          (0xFFFFFFFFU)

#ifdef __cplusplus
}
#endif
#endif

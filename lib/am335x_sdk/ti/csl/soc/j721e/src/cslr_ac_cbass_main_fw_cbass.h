/********************************************************************
 * Copyright (C) 2018 Texas Instruments Incorporated.
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
 *  Name        : cslr_ac_cbass_main_fw_cbass.h
*/
#ifndef CSLR_AC_CBASS_MAIN_FW_CBASS_H_
#define CSLR_AC_CBASS_MAIN_FW_CBASS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : Error Config port MMR
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint32_t DESTINATION_ID;            /* Destination ID Register */
    volatile uint8_t  Resv_36[28];
    volatile uint32_t EXCEPTION_LOGGING_HEADER0;   /* Exception Logging Header 0 Register */
    volatile uint32_t EXCEPTION_LOGGING_HEADER1;   /* Exception Logging Header 1 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA0;   /* Exception Logging Data 0 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA1;   /* Exception Logging Data 1 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA2;   /* Exception Logging Data 2 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA3;   /* Exception Logging Data 3 Register */
    volatile uint8_t  Resv_80[20];
    volatile uint32_t ERR_INTR_RAW_STAT;         /* Global Interrupt Raw Status Register */
    volatile uint32_t ERR_INTR_ENABLED_STAT;     /* Global Interrupt Enabled Status Register */
    volatile uint32_t ERR_INTR_ENABLE_SET;       /* Interrupt Enable Set Register */
    volatile uint32_t ERR_INTR_ENABLE_CLR;       /* Interrupt Enable Clear Register */
    volatile uint32_t EOI;                       /* EOI Register */
} CSL_ac_cbass_main_fw_cbass_errRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID                                                      (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_DESTINATION_ID                                           (0x00000004U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0                                (0x00000024U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER1                                (0x00000028U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA0                                  (0x0000002CU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA1                                  (0x00000030U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2                                  (0x00000034U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA3                                  (0x00000038U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_RAW_STAT                                        (0x00000050U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLED_STAT                                    (0x00000054U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLE_SET                                      (0x00000058U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLE_CLR                                      (0x0000005CU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EOI                                                      (0x00000060U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_MINOR_MASK                                           (0x0000003FU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_MINOR_SHIFT                                          (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_MINOR_RESETVAL                                       (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_MINOR_MAX                                            (0x0000003FU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_CUSTOM_MASK                                          (0x000000C0U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_CUSTOM_SHIFT                                         (0x00000006U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_CUSTOM_RESETVAL                                      (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_CUSTOM_MAX                                           (0x00000003U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_MAJOR_MASK                                           (0x00000700U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_MAJOR_SHIFT                                          (0x00000008U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_MAJOR_RESETVAL                                       (0x00000001U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_MAJOR_MAX                                            (0x00000007U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_RTL_MASK                                             (0x0000F800U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_RTL_SHIFT                                            (0x0000000BU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_RTL_RESETVAL                                         (0x00000008U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_RTL_MAX                                              (0x0000001FU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_FUNC_MASK                                            (0x0FFF0000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_FUNC_SHIFT                                           (0x00000010U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_FUNC_RESETVAL                                        (0x00000600U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_FUNC_MAX                                             (0x00000FFFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_BU_MASK                                              (0x30000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_BU_SHIFT                                             (0x0000001CU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_BU_RESETVAL                                          (0x00000002U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_BU_MAX                                               (0x00000003U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_SCHEME_MASK                                          (0xC0000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_SCHEME_SHIFT                                         (0x0000001EU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_SCHEME_RESETVAL                                      (0x00000001U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_SCHEME_MAX                                           (0x00000003U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_PID_RESETVAL                                             (0x66004100U)

/* DESTINATION_ID */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_DESTINATION_ID_DEST_ID_MASK                              (0x000000FFU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_DESTINATION_ID_DEST_ID_SHIFT                             (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_DESTINATION_ID_DEST_ID_RESETVAL                          (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_DESTINATION_ID_DEST_ID_MAX                               (0x000000FFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_DESTINATION_ID_RESETVAL                                  (0x00000000U)

/* EXCEPTION_LOGGING_HEADER0 */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_DEST_ID_MASK                   (0x000000FFU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_DEST_ID_SHIFT                  (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_DEST_ID_RESETVAL               (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_DEST_ID_MAX                    (0x000000FFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_SRC_ID_MASK                    (0x00FFFF00U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_SRC_ID_SHIFT                   (0x00000008U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_SRC_ID_RESETVAL                (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_SRC_ID_MAX                     (0x0000FFFFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_TYPE_F_MASK                    (0xFF000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_TYPE_F_SHIFT                   (0x00000018U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_TYPE_F_RESETVAL                (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_TYPE_F_MAX                     (0x000000FFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_RESETVAL                       (0x00000000U)

/* EXCEPTION_LOGGING_HEADER1 */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_CODE_MASK                      (0x00FF0000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_CODE_SHIFT                     (0x00000010U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_CODE_RESETVAL                  (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_CODE_MAX                       (0x000000FFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_GROUP_MASK                     (0xFF000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_GROUP_SHIFT                    (0x00000018U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_GROUP_RESETVAL                 (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_GROUP_MAX                      (0x000000FFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_RESETVAL                       (0x00000000U)

/* EXCEPTION_LOGGING_DATA0 */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA0_ADDR_L_MASK                      (0xFFFFFFFFU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA0_ADDR_L_SHIFT                     (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA0_ADDR_L_RESETVAL                  (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA0_ADDR_L_MAX                       (0xFFFFFFFFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA0_RESETVAL                         (0x00000000U)

/* EXCEPTION_LOGGING_DATA1 */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA1_ADDR_H_MASK                      (0x0000FFFFU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA1_ADDR_H_SHIFT                     (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA1_ADDR_H_RESETVAL                  (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA1_ADDR_H_MAX                       (0x0000FFFFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA1_RESETVAL                         (0x00000000U)

/* EXCEPTION_LOGGING_DATA2 */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_ID_MASK                     (0x000000FFU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_ID_SHIFT                    (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_ID_RESETVAL                 (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_ID_MAX                      (0x000000FFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_SECURE_MASK                      (0x00000100U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_SECURE_SHIFT                     (0x00000008U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_SECURE_RESETVAL                  (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_SECURE_MAX                       (0x00000001U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_MASK                        (0x00000200U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_SHIFT                       (0x00000009U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_RESETVAL                    (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_MAX                         (0x00000001U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_CACHEABLE_MASK                   (0x00000400U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_CACHEABLE_SHIFT                  (0x0000000AU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_CACHEABLE_RESETVAL               (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_CACHEABLE_MAX                    (0x00000001U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_DEBUG_MASK                       (0x00000800U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_DEBUG_SHIFT                      (0x0000000BU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_DEBUG_RESETVAL                   (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_DEBUG_MAX                        (0x00000001U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_READ_MASK                        (0x00001000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_READ_SHIFT                       (0x0000000CU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_READ_RESETVAL                    (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_READ_MAX                         (0x00000001U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_WRITE_MASK                       (0x00002000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_WRITE_SHIFT                      (0x0000000DU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_WRITE_RESETVAL                   (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_WRITE_MAX                        (0x00000001U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_ROUTEID_MASK                     (0x0FFF0000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_ROUTEID_SHIFT                    (0x00000010U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_ROUTEID_RESETVAL                 (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_ROUTEID_MAX                      (0x00000FFFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA2_RESETVAL                         (0x00000000U)

/* EXCEPTION_LOGGING_DATA3 */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA3_BYTECNT_MASK                     (0x000003FFU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA3_BYTECNT_SHIFT                    (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA3_BYTECNT_RESETVAL                 (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA3_BYTECNT_MAX                      (0x000003FFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EXCEPTION_LOGGING_DATA3_RESETVAL                         (0x00000000U)

/* ERR_INTR_RAW_STAT */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MASK                              (0x00000001U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_SHIFT                             (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_RESETVAL                          (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MAX                               (0x00000001U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_RAW_STAT_RESETVAL                               (0x00000000U)

/* ERR_INTR_ENABLED_STAT */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLED_STAT_ENABLED_INTR_MASK                  (0x00000001U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLED_STAT_ENABLED_INTR_SHIFT                 (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLED_STAT_ENABLED_INTR_RESETVAL              (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLED_STAT_ENABLED_INTR_MAX                   (0x00000001U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLED_STAT_RESETVAL                           (0x00000000U)

/* ERR_INTR_ENABLE_SET */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLE_SET_INTR_ENABLE_SET_MASK                 (0x00000001U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLE_SET_INTR_ENABLE_SET_SHIFT                (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLE_SET_INTR_ENABLE_SET_RESETVAL             (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLE_SET_INTR_ENABLE_SET_MAX                  (0x00000001U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLE_SET_RESETVAL                             (0x00000000U)

/* ERR_INTR_ENABLE_CLR */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLE_CLR_INTR_ENABLE_CLR_MASK                 (0x00000001U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLE_CLR_INTR_ENABLE_CLR_SHIFT                (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLE_CLR_INTR_ENABLE_CLR_RESETVAL             (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLE_CLR_INTR_ENABLE_CLR_MAX                  (0x00000001U)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_ERR_INTR_ENABLE_CLR_RESETVAL                             (0x00000000U)

/* EOI */

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EOI_WR_MASK                                              (0x0000FFFFU)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EOI_WR_SHIFT                                             (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EOI_WR_RESETVAL                                          (0x00000000U)
#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EOI_WR_MAX                                               (0x0000FFFFU)

#define CSL_AC_CBASS_MAIN_FW_CBASS_ERR_EOI_RESETVAL                                             (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif

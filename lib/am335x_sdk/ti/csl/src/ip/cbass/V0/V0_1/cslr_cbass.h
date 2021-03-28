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
 *  Name        : cslr_cbass.h
*/
#ifndef CSLR_CBASS_H_
#define CSLR_CBASS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : Global Config port MMR
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint32_t DESTINATION_ID;            /* Destination ID Register */
    volatile uint8_t  Resv_32[24];
    volatile uint32_t EXCEPTION_LOGGING_CONTROL;   /* Exception Logging Control Register */
    volatile uint32_t EXCEPTION_LOGGING_HEADER0;   /* Exception Logging Header 0 Register */
    volatile uint32_t EXCEPTION_LOGGING_HEADER1;   /* Exception Logging Header 1 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA0;   /* Exception Logging Data 0 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA1;   /* Exception Logging Data 1 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA2;   /* Exception Logging Data 2 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA3;   /* Exception Logging Data 3 Register */
    volatile uint8_t  Resv_64[4];
    volatile uint32_t EXCEPTION_PEND_SET;        /* Exception Logging Pending Set Register */
    volatile uint32_t EXCEPTION_PEND_CLEAR;      /* Exception Logging Pending Clear Register */
} CSL_cbass_glbRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_CBASS_GLB_PID                                                      (0x00000000U)
#define CSL_CBASS_GLB_DESTINATION_ID                                           (0x00000004U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_CONTROL                                (0x00000020U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER0                                (0x00000024U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER1                                (0x00000028U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA0                                  (0x0000002CU)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA1                                  (0x00000030U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2                                  (0x00000034U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA3                                  (0x00000038U)
#define CSL_CBASS_GLB_EXCEPTION_PEND_SET                                       (0x00000040U)
#define CSL_CBASS_GLB_EXCEPTION_PEND_CLEAR                                     (0x00000044U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_CBASS_GLB_PID_MINOR_MASK                                           (0x0000003FU)
#define CSL_CBASS_GLB_PID_MINOR_SHIFT                                          (0x00000000U)
#define CSL_CBASS_GLB_PID_MINOR_MAX                                            (0x0000003FU)

#define CSL_CBASS_GLB_PID_CUSTOM_MASK                                          (0x000000C0U)
#define CSL_CBASS_GLB_PID_CUSTOM_SHIFT                                         (0x00000006U)
#define CSL_CBASS_GLB_PID_CUSTOM_MAX                                           (0x00000003U)

#define CSL_CBASS_GLB_PID_MAJOR_MASK                                           (0x00000700U)
#define CSL_CBASS_GLB_PID_MAJOR_SHIFT                                          (0x00000008U)
#define CSL_CBASS_GLB_PID_MAJOR_MAX                                            (0x00000007U)

#define CSL_CBASS_GLB_PID_RTL_MASK                                             (0x0000F800U)
#define CSL_CBASS_GLB_PID_RTL_SHIFT                                            (0x0000000BU)
#define CSL_CBASS_GLB_PID_RTL_MAX                                              (0x0000001FU)

#define CSL_CBASS_GLB_PID_FUNC_MASK                                            (0x0FFF0000U)
#define CSL_CBASS_GLB_PID_FUNC_SHIFT                                           (0x00000010U)
#define CSL_CBASS_GLB_PID_FUNC_MAX                                             (0x00000FFFU)

#define CSL_CBASS_GLB_PID_BU_MASK                                              (0x30000000U)
#define CSL_CBASS_GLB_PID_BU_SHIFT                                             (0x0000001CU)
#define CSL_CBASS_GLB_PID_BU_MAX                                               (0x00000003U)

#define CSL_CBASS_GLB_PID_SCHEME_MASK                                          (0xC0000000U)
#define CSL_CBASS_GLB_PID_SCHEME_SHIFT                                         (0x0000001EU)
#define CSL_CBASS_GLB_PID_SCHEME_MAX                                           (0x00000003U)

/* DESTINATION_ID */

#define CSL_CBASS_GLB_DESTINATION_ID_DEST_ID_MASK                              (0x000000FFU)
#define CSL_CBASS_GLB_DESTINATION_ID_DEST_ID_SHIFT                             (0x00000000U)
#define CSL_CBASS_GLB_DESTINATION_ID_DEST_ID_MAX                               (0x000000FFU)

/* EXCEPTION_LOGGING_CONTROL */

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_CONTROL_DISABLE_F_MASK                 (0x00000001U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_CONTROL_DISABLE_F_SHIFT                (0x00000000U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_CONTROL_DISABLE_F_MAX                  (0x00000001U)

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_CONTROL_DISABLE_PEND_MASK              (0x00000002U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_CONTROL_DISABLE_PEND_SHIFT             (0x00000001U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_CONTROL_DISABLE_PEND_MAX               (0x00000001U)

/* EXCEPTION_LOGGING_HEADER0 */

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER0_DEST_ID_MASK                   (0x000000FFU)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER0_DEST_ID_SHIFT                  (0x00000000U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER0_DEST_ID_MAX                    (0x000000FFU)

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER0_SRC_ID_MASK                    (0x00FFFF00U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER0_SRC_ID_SHIFT                   (0x00000008U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER0_SRC_ID_MAX                     (0x0000FFFFU)

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER0_TYPE_F_MASK                    (0xFF000000U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER0_TYPE_F_SHIFT                   (0x00000018U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER0_TYPE_F_MAX                     (0x000000FFU)

/* EXCEPTION_LOGGING_HEADER1 */

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER1_CODE_MASK                      (0x00FF0000U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER1_CODE_SHIFT                     (0x00000010U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER1_CODE_MAX                       (0x000000FFU)

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER1_GROUP_MASK                     (0xFF000000U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER1_GROUP_SHIFT                    (0x00000018U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_HEADER1_GROUP_MAX                      (0x000000FFU)

/* EXCEPTION_LOGGING_DATA0 */

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA0_ADDR_L_MASK                      (0xFFFFFFFFU)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA0_ADDR_L_SHIFT                     (0x00000000U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA0_ADDR_L_MAX                       (0xFFFFFFFFU)

/* EXCEPTION_LOGGING_DATA1 */

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA1_ADDR_H_MASK                      (0x0000FFFFU)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA1_ADDR_H_SHIFT                     (0x00000000U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA1_ADDR_H_MAX                       (0x0000FFFFU)

/* EXCEPTION_LOGGING_DATA2 */

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_PRIV_ID_MASK                     (0x000000FFU)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_PRIV_ID_SHIFT                    (0x00000000U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_PRIV_ID_MAX                      (0x000000FFU)

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_SECURE_MASK                      (0x00000100U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_SECURE_SHIFT                     (0x00000008U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_SECURE_MAX                       (0x00000001U)

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_PRIV_MASK                        (0x00000200U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_PRIV_SHIFT                       (0x00000009U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_PRIV_MAX                         (0x00000001U)

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_CACHEABLE_MASK                   (0x00000400U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_CACHEABLE_SHIFT                  (0x0000000AU)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_CACHEABLE_MAX                    (0x00000001U)

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_DEBUG_MASK                       (0x00000800U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_DEBUG_SHIFT                      (0x0000000BU)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_DEBUG_MAX                        (0x00000001U)

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_READ_MASK                        (0x00001000U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_READ_SHIFT                       (0x0000000CU)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_READ_MAX                         (0x00000001U)

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_WRITE_MASK                       (0x00002000U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_WRITE_SHIFT                      (0x0000000DU)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_WRITE_MAX                        (0x00000001U)

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_ROUTEID_MASK                     (0x0FFF0000U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_ROUTEID_SHIFT                    (0x00000010U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA2_ROUTEID_MAX                      (0x00000FFFU)

/* EXCEPTION_LOGGING_DATA3 */

#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA3_BYTECNT_MASK                     (0x000003FFU)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA3_BYTECNT_SHIFT                    (0x00000000U)
#define CSL_CBASS_GLB_EXCEPTION_LOGGING_DATA3_BYTECNT_MAX                      (0x000003FFU)

/* EXCEPTION_PEND_SET */

#define CSL_CBASS_GLB_EXCEPTION_PEND_SET_PEND_SET_MASK                         (0x00000001U)
#define CSL_CBASS_GLB_EXCEPTION_PEND_SET_PEND_SET_SHIFT                        (0x00000000U)
#define CSL_CBASS_GLB_EXCEPTION_PEND_SET_PEND_SET_MAX                          (0x00000001U)

/* EXCEPTION_PEND_CLEAR */

#define CSL_CBASS_GLB_EXCEPTION_PEND_CLEAR_PEND_CLR_MASK                       (0x00000001U)
#define CSL_CBASS_GLB_EXCEPTION_PEND_CLEAR_PEND_CLR_SHIFT                      (0x00000000U)
#define CSL_CBASS_GLB_EXCEPTION_PEND_CLEAR_PEND_CLR_MAX                        (0x00000001U)

/**************************************************************************
* Hardware Region  : Config port MMR
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t CONTROL;                   /* Firewall a Region b Control Register */
    volatile uint32_t PERMISSION[3];             /* Firewall a Region b Permission c Register */
    volatile uint32_t START_ADDR_L;              /* Firewall a Region b Start Address Low Register */
    volatile uint32_t START_ADDR_H;              /* Firewall a Region b Start Address High Register */
    volatile uint32_t END_ADDR_L;                /* Firewall a Region b End Address Low Register */
    volatile uint32_t END_ADDR_H;                /* Firewall a Region b End Address High Register */
} CSL_cbass_fwRegs_ep_region;


typedef struct {
    CSL_cbass_fwRegs_ep_region REGION[32];
} CSL_cbass_fwRegs_ep;


typedef struct {
    CSL_cbass_fwRegs_ep EP[8192];
} CSL_cbass_fwRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_CBASS_FW_EP_REGION_CONTROL(EP, REGION)                             (0x00000000U+((EP)*0x400U)+((REGION)*0x20U))
#define CSL_CBASS_FW_EP_REGION_PERMISSION(EP, REGION,PERMISSION)               (0x00000004U+((EP)*0x400U)+((REGION)*0x20U)+((PERMISSION)*0x4U))
#define CSL_CBASS_FW_EP_REGION_START_ADDR_L(EP, REGION)                        (0x00000010U+((EP)*0x400U)+((REGION)*0x20U))
#define CSL_CBASS_FW_EP_REGION_START_ADDR_H(EP, REGION)                        (0x00000014U+((EP)*0x400U)+((REGION)*0x20U))
#define CSL_CBASS_FW_EP_REGION_END_ADDR_L(EP, REGION)                          (0x00000018U+((EP)*0x400U)+((REGION)*0x20U))
#define CSL_CBASS_FW_EP_REGION_END_ADDR_H(EP, REGION)                          (0x0000001CU+((EP)*0x400U)+((REGION)*0x20U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* CONTROL */

#define CSL_CBASS_FW_EP_REGION_CONTROL_ENABLE_MASK                             (0x0000000FU)
#define CSL_CBASS_FW_EP_REGION_CONTROL_ENABLE_SHIFT                            (0x00000000U)
#define CSL_CBASS_FW_EP_REGION_CONTROL_ENABLE_MAX                              (0x0000000FU)

#define CSL_CBASS_FW_EP_REGION_CONTROL_LOCK_MASK                               (0x00000010U)
#define CSL_CBASS_FW_EP_REGION_CONTROL_LOCK_SHIFT                              (0x00000004U)
#define CSL_CBASS_FW_EP_REGION_CONTROL_LOCK_MAX                                (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_CONTROL_BACKGROUND_MASK                         (0x00000100U)
#define CSL_CBASS_FW_EP_REGION_CONTROL_BACKGROUND_SHIFT                        (0x00000008U)
#define CSL_CBASS_FW_EP_REGION_CONTROL_BACKGROUND_MAX                          (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_CONTROL_CACHE_MODE_MASK                         (0x00000200U)
#define CSL_CBASS_FW_EP_REGION_CONTROL_CACHE_MODE_SHIFT                        (0x00000009U)
#define CSL_CBASS_FW_EP_REGION_CONTROL_CACHE_MODE_MAX                          (0x00000001U)

/* PERMISSION */

#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_WRITE_MASK                  (0x00000001U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_WRITE_SHIFT                 (0x00000000U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_WRITE_MAX                   (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_READ_MASK                   (0x00000002U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_READ_SHIFT                  (0x00000001U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_READ_MAX                    (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_CACHEABLE_MASK              (0x00000004U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_CACHEABLE_SHIFT             (0x00000002U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_CACHEABLE_MAX               (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_DEBUG_MASK                  (0x00000008U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_DEBUG_SHIFT                 (0x00000003U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_SUPV_DEBUG_MAX                   (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_WRITE_MASK                  (0x00000010U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_WRITE_SHIFT                 (0x00000004U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_WRITE_MAX                   (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_READ_MASK                   (0x00000020U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_READ_SHIFT                  (0x00000005U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_READ_MAX                    (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_CACHEABLE_MASK              (0x00000040U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_CACHEABLE_SHIFT             (0x00000006U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_CACHEABLE_MAX               (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_DEBUG_MASK                  (0x00000080U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_DEBUG_SHIFT                 (0x00000007U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_SEC_USER_DEBUG_MAX                   (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_WRITE_MASK               (0x00000100U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_WRITE_SHIFT              (0x00000008U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_WRITE_MAX                (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_READ_MASK                (0x00000200U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_READ_SHIFT               (0x00000009U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_READ_MAX                 (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_CACHEABLE_MASK           (0x00000400U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_CACHEABLE_SHIFT          (0x0000000AU)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_CACHEABLE_MAX            (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_DEBUG_MASK               (0x00000800U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_DEBUG_SHIFT              (0x0000000BU)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_SUPV_DEBUG_MAX                (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_WRITE_MASK               (0x00001000U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_WRITE_SHIFT              (0x0000000CU)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_WRITE_MAX                (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_READ_MASK                (0x00002000U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_READ_SHIFT               (0x0000000DU)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_READ_MAX                 (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_CACHEABLE_MASK           (0x00004000U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_CACHEABLE_SHIFT          (0x0000000EU)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_CACHEABLE_MAX            (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_DEBUG_MASK               (0x00008000U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_DEBUG_SHIFT              (0x0000000FU)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_NONSEC_USER_DEBUG_MAX                (0x00000001U)

#define CSL_CBASS_FW_EP_REGION_PERMISSION_PRIV_ID_MASK                         (0x00FF0000U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_PRIV_ID_SHIFT                        (0x00000010U)
#define CSL_CBASS_FW_EP_REGION_PERMISSION_PRIV_ID_MAX                          (0x000000FFU)

/* START_ADDR_L */

#define CSL_CBASS_FW_EP_REGION_START_ADDR_L_ADDR_L_MASK                        (0xFFFFF000U)
#define CSL_CBASS_FW_EP_REGION_START_ADDR_L_ADDR_L_SHIFT                       (0x0000000CU)
#define CSL_CBASS_FW_EP_REGION_START_ADDR_L_ADDR_L_MAX                         (0x000FFFFFU)

#define CSL_CBASS_FW_EP_REGION_START_ADDR_L_ADDR_LSB_MASK                      (0x00000FFFU)
#define CSL_CBASS_FW_EP_REGION_START_ADDR_L_ADDR_LSB_SHIFT                     (0x00000000U)
#define CSL_CBASS_FW_EP_REGION_START_ADDR_L_ADDR_LSB_MAX                       (0x00000FFFU)

/* START_ADDR_H */

#define CSL_CBASS_FW_EP_REGION_START_ADDR_H_ADDR_H_MASK                        (0x0000FFFFU)
#define CSL_CBASS_FW_EP_REGION_START_ADDR_H_ADDR_H_SHIFT                       (0x00000000U)
#define CSL_CBASS_FW_EP_REGION_START_ADDR_H_ADDR_H_MAX                         (0x0000FFFFU)

/* END_ADDR_L */

#define CSL_CBASS_FW_EP_REGION_END_ADDR_L_END_ADDR_L_MASK                      (0xFFFFF000U)
#define CSL_CBASS_FW_EP_REGION_END_ADDR_L_END_ADDR_L_SHIFT                     (0x0000000CU)
#define CSL_CBASS_FW_EP_REGION_END_ADDR_L_END_ADDR_L_MAX                       (0x000FFFFFU)

#define CSL_CBASS_FW_EP_REGION_END_ADDR_L_END_ADDR_LSB_MASK                    (0x00000FFFU)
#define CSL_CBASS_FW_EP_REGION_END_ADDR_L_END_ADDR_LSB_SHIFT                   (0x00000000U)
#define CSL_CBASS_FW_EP_REGION_END_ADDR_L_END_ADDR_LSB_MAX                     (0x00000FFFU)

/* END_ADDR_H */

#define CSL_CBASS_FW_EP_REGION_END_ADDR_H_END_ADDR_H_MASK                      (0x0000FFFFU)
#define CSL_CBASS_FW_EP_REGION_END_ADDR_H_END_ADDR_H_SHIFT                     (0x00000000U)
#define CSL_CBASS_FW_EP_REGION_END_ADDR_H_END_ADDR_H_MAX                       (0x0000FFFFU)

/**************************************************************************
* Hardware Region  : Config port MMR
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t CONTROL;                   /* ISC a Region b Control Register */
    volatile uint8_t  Resv_16[12];
    volatile uint32_t START_ADDR_L;              /* ISC a Region b Start Address Low Register */
    volatile uint32_t START_ADDR_H;              /* ISC a Region b Start Address High Register */
    volatile uint32_t END_ADDR_L;                /* ISC a Region b End Address Low Register */
    volatile uint32_t END_ADDR_H;                /* ISC a Region b End Address High Register */
} CSL_cbass_iscRegs_ep_region;


typedef struct {
    CSL_cbass_iscRegs_ep_region REGION[32];
} CSL_cbass_iscRegs_ep;


typedef struct {
    CSL_cbass_iscRegs_ep EP[1024];
} CSL_cbass_iscRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_CBASS_ISC_EP_REGION_CONTROL(EP, REGION)                            (0x00000000U+((EP)*0x400U)+((REGION)*0x20U))
#define CSL_CBASS_ISC_EP_REGION_START_ADDR_L(EP, REGION)                       (0x00000010U+((EP)*0x400U)+((REGION)*0x20U))
#define CSL_CBASS_ISC_EP_REGION_START_ADDR_H(EP, REGION)                       (0x00000014U+((EP)*0x400U)+((REGION)*0x20U))
#define CSL_CBASS_ISC_EP_REGION_END_ADDR_L(EP, REGION)                         (0x00000018U+((EP)*0x400U)+((REGION)*0x20U))
#define CSL_CBASS_ISC_EP_REGION_END_ADDR_H(EP, REGION)                         (0x0000001CU+((EP)*0x400U)+((REGION)*0x20U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* CONTROL */

#define CSL_CBASS_ISC_EP_REGION_CONTROL_ENABLE_MASK                            (0x0000000FU)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_ENABLE_SHIFT                           (0x00000000U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_ENABLE_MAX                             (0x0000000FU)

#define CSL_CBASS_ISC_EP_REGION_CONTROL_LOCK_MASK                              (0x00000010U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_LOCK_SHIFT                             (0x00000004U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_LOCK_MAX                               (0x00000001U)

#define CSL_CBASS_ISC_EP_REGION_CONTROL_CH_MODE_MASK                           (0x00000020U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_CH_MODE_SHIFT                          (0x00000005U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_CH_MODE_MAX                            (0x00000001U)

#define CSL_CBASS_ISC_EP_REGION_CONTROL_DEF_MASK                               (0x00000040U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_DEF_SHIFT                              (0x00000006U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_DEF_MAX                                (0x00000001U)

#define CSL_CBASS_ISC_EP_REGION_CONTROL_PRIV_ID_MASK                           (0x0000FF00U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_PRIV_ID_SHIFT                          (0x00000008U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_PRIV_ID_MAX                            (0x000000FFU)

#define CSL_CBASS_ISC_EP_REGION_CONTROL_SEC_MASK                               (0x000F0000U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_SEC_SHIFT                              (0x00000010U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_SEC_MAX                                (0x0000000FU)

#define CSL_CBASS_ISC_EP_REGION_CONTROL_NONSEC_MASK                            (0x00100000U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_NONSEC_SHIFT                           (0x00000014U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_NONSEC_MAX                             (0x00000001U)

#define CSL_CBASS_ISC_EP_REGION_CONTROL_PASS_MASK                              (0x00200000U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_PASS_SHIFT                             (0x00000015U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_PASS_MAX                               (0x00000001U)

#define CSL_CBASS_ISC_EP_REGION_CONTROL_PRIV_MASK                              (0x03000000U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_PRIV_SHIFT                             (0x00000018U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_PRIV_MAX                               (0x00000003U)

#define CSL_CBASS_ISC_EP_REGION_CONTROL_NOPRIV_MASK                            (0x0C000000U)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_NOPRIV_SHIFT                           (0x0000001AU)
#define CSL_CBASS_ISC_EP_REGION_CONTROL_NOPRIV_MAX                             (0x00000003U)

/* START_ADDR_L */

#define CSL_CBASS_ISC_EP_REGION_START_ADDR_L_START_ADDR_L_MASK                 (0xFFFFF000U)
#define CSL_CBASS_ISC_EP_REGION_START_ADDR_L_START_ADDR_L_SHIFT                (0x0000000CU)
#define CSL_CBASS_ISC_EP_REGION_START_ADDR_L_START_ADDR_L_MAX                  (0x000FFFFFU)

#define CSL_CBASS_ISC_EP_REGION_START_ADDR_L_START_ADDR_LSB_MASK               (0x00000FFFU)
#define CSL_CBASS_ISC_EP_REGION_START_ADDR_L_START_ADDR_LSB_SHIFT              (0x00000000U)
#define CSL_CBASS_ISC_EP_REGION_START_ADDR_L_START_ADDR_LSB_MAX                (0x00000FFFU)

/* START_ADDR_H */

#define CSL_CBASS_ISC_EP_REGION_START_ADDR_H_START_ADDRESS_H_MASK              (0x0000FFFFU)
#define CSL_CBASS_ISC_EP_REGION_START_ADDR_H_START_ADDRESS_H_SHIFT             (0x00000000U)
#define CSL_CBASS_ISC_EP_REGION_START_ADDR_H_START_ADDRESS_H_MAX               (0x0000FFFFU)

/* END_ADDR_L */

#define CSL_CBASS_ISC_EP_REGION_END_ADDR_L_END_ADDR_L_MASK                     (0xFFFFF000U)
#define CSL_CBASS_ISC_EP_REGION_END_ADDR_L_END_ADDR_L_SHIFT                    (0x0000000CU)
#define CSL_CBASS_ISC_EP_REGION_END_ADDR_L_END_ADDR_L_MAX                      (0x000FFFFFU)

#define CSL_CBASS_ISC_EP_REGION_END_ADDR_L_END_ADDR_LSB_MASK                   (0x00000FFFU)
#define CSL_CBASS_ISC_EP_REGION_END_ADDR_L_END_ADDR_LSB_SHIFT                  (0x00000000U)
#define CSL_CBASS_ISC_EP_REGION_END_ADDR_L_END_ADDR_LSB_MAX                    (0x00000FFFU)

/* END_ADDR_H */

#define CSL_CBASS_ISC_EP_REGION_END_ADDR_H_END_ADDR_H_MASK                     (0x0000FFFFU)
#define CSL_CBASS_ISC_EP_REGION_END_ADDR_H_END_ADDR_H_SHIFT                    (0x00000000U)
#define CSL_CBASS_ISC_EP_REGION_END_ADDR_H_END_ADDR_H_MAX                      (0x0000FFFFU)

/**************************************************************************
* Hardware Region  : Config port MMR
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t MAP1;                      /* Group Map Register 1 */
    volatile uint32_t MAP2;                      /* Group Map Register 2 */
} CSL_cbass_qosRegs_ep_grp;


typedef struct {
    CSL_cbass_qosRegs_ep_grp GRP[32];
    volatile uint32_t MAP[192];                  /* Map Register */
} CSL_cbass_qosRegs_ep;


typedef struct {
    CSL_cbass_qosRegs_ep EP[1024];
} CSL_cbass_qosRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_CBASS_QOS_EP_GRP_MAP1(EP, GRP)                                     (0x00000000U+((EP)*0x400U)+((GRP)*0x8U))
#define CSL_CBASS_QOS_EP_GRP_MAP2(EP, GRP)                                     (0x00000004U+((EP)*0x400U)+((GRP)*0x8U))
#define CSL_CBASS_QOS_EP_MAP(EP,MAP)                                           (0x00000100U+((EP)*0x400U)+((MAP)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* MAP1 */

#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID7_MASK                                (0xF0000000U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID7_SHIFT                               (0x0000001CU)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID7_MAX                                 (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID6_MASK                                (0x0F000000U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID6_SHIFT                               (0x00000018U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID6_MAX                                 (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID5_MASK                                (0x00F00000U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID5_SHIFT                               (0x00000014U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID5_MAX                                 (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID4_MASK                                (0x000F0000U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID4_SHIFT                               (0x00000010U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID4_MAX                                 (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID3_MASK                                (0x0000F000U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID3_SHIFT                               (0x0000000CU)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID3_MAX                                 (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID2_MASK                                (0x00000F00U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID2_SHIFT                               (0x00000008U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID2_MAX                                 (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID1_MASK                                (0x000000F0U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID1_SHIFT                               (0x00000004U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID1_MAX                                 (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID0_MASK                                (0x0000000FU)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID0_SHIFT                               (0x00000000U)
#define CSL_CBASS_QOS_EP_GRP_MAP1_ORDERID0_MAX                                 (0x0000000FU)

/* MAP2 */

#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID15_MASK                               (0xF0000000U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID15_SHIFT                              (0x0000001CU)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID15_MAX                                (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID14_MASK                               (0x0F000000U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID14_SHIFT                              (0x00000018U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID14_MAX                                (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID13_MASK                               (0x00F00000U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID13_SHIFT                              (0x00000014U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID13_MAX                                (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID12_MASK                               (0x000F0000U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID12_SHIFT                              (0x00000010U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID12_MAX                                (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID11_MASK                               (0x0000F000U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID11_SHIFT                              (0x0000000CU)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID11_MAX                                (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID10_MASK                               (0x00000F00U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID10_SHIFT                              (0x00000008U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID10_MAX                                (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID9_MASK                                (0x000000F0U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID9_SHIFT                               (0x00000004U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID9_MAX                                 (0x0000000FU)

#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID8_MASK                                (0x0000000FU)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID8_SHIFT                               (0x00000000U)
#define CSL_CBASS_QOS_EP_GRP_MAP2_ORDERID8_MAX                                 (0x0000000FU)

/* MAP */

#define CSL_CBASS_QOS_EP_MAP_QOS_MASK                                          (0x00000007U)
#define CSL_CBASS_QOS_EP_MAP_QOS_SHIFT                                         (0x00000000U)
#define CSL_CBASS_QOS_EP_MAP_QOS_MAX                                           (0x00000007U)

#define CSL_CBASS_QOS_EP_MAP_ORDERID_MASK                                      (0x000000F0U)
#define CSL_CBASS_QOS_EP_MAP_ORDERID_SHIFT                                     (0x00000004U)
#define CSL_CBASS_QOS_EP_MAP_ORDERID_MAX                                       (0x0000000FU)

#define CSL_CBASS_QOS_EP_MAP_ASEL_MASK                                         (0x00000F00U)
#define CSL_CBASS_QOS_EP_MAP_ASEL_SHIFT                                        (0x00000008U)
#define CSL_CBASS_QOS_EP_MAP_ASEL_MAX                                          (0x0000000FU)

#define CSL_CBASS_QOS_EP_MAP_EPRIORITY_MASK                                    (0x00007000U)
#define CSL_CBASS_QOS_EP_MAP_EPRIORITY_SHIFT                                   (0x0000000CU)
#define CSL_CBASS_QOS_EP_MAP_EPRIORITY_MAX                                     (0x00000007U)

#define CSL_CBASS_QOS_EP_MAP_VIRTID_MASK                                       (0x0FFF0000U)
#define CSL_CBASS_QOS_EP_MAP_VIRTID_SHIFT                                      (0x00000010U)
#define CSL_CBASS_QOS_EP_MAP_VIRTID_MAX                                        (0x00000FFFU)

#define CSL_CBASS_QOS_EP_MAP_ATYPE_MASK                                        (0x30000000U)
#define CSL_CBASS_QOS_EP_MAP_ATYPE_SHIFT                                       (0x0000001CU)
#define CSL_CBASS_QOS_EP_MAP_ATYPE_MAX                                         (0x00000003U)

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
} CSL_cbass_errRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_CBASS_ERR_PID                                                      (0x00000000U)
#define CSL_CBASS_ERR_DESTINATION_ID                                           (0x00000004U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER0                                (0x00000024U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER1                                (0x00000028U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA0                                  (0x0000002CU)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA1                                  (0x00000030U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2                                  (0x00000034U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA3                                  (0x00000038U)
#define CSL_CBASS_ERR_ERR_INTR_RAW_STAT                                        (0x00000050U)
#define CSL_CBASS_ERR_ERR_INTR_ENABLED_STAT                                    (0x00000054U)
#define CSL_CBASS_ERR_ERR_INTR_ENABLE_SET                                      (0x00000058U)
#define CSL_CBASS_ERR_ERR_INTR_ENABLE_CLR                                      (0x0000005CU)
#define CSL_CBASS_ERR_EOI                                                      (0x00000060U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_CBASS_ERR_PID_MINOR_MASK                                           (0x0000003FU)
#define CSL_CBASS_ERR_PID_MINOR_SHIFT                                          (0x00000000U)
#define CSL_CBASS_ERR_PID_MINOR_MAX                                            (0x0000003FU)

#define CSL_CBASS_ERR_PID_CUSTOM_MASK                                          (0x000000C0U)
#define CSL_CBASS_ERR_PID_CUSTOM_SHIFT                                         (0x00000006U)
#define CSL_CBASS_ERR_PID_CUSTOM_MAX                                           (0x00000003U)

#define CSL_CBASS_ERR_PID_MAJOR_MASK                                           (0x00000700U)
#define CSL_CBASS_ERR_PID_MAJOR_SHIFT                                          (0x00000008U)
#define CSL_CBASS_ERR_PID_MAJOR_MAX                                            (0x00000007U)

#define CSL_CBASS_ERR_PID_RTL_MASK                                             (0x0000F800U)
#define CSL_CBASS_ERR_PID_RTL_SHIFT                                            (0x0000000BU)
#define CSL_CBASS_ERR_PID_RTL_MAX                                              (0x0000001FU)

#define CSL_CBASS_ERR_PID_FUNC_MASK                                            (0x0FFF0000U)
#define CSL_CBASS_ERR_PID_FUNC_SHIFT                                           (0x00000010U)
#define CSL_CBASS_ERR_PID_FUNC_MAX                                             (0x00000FFFU)

#define CSL_CBASS_ERR_PID_BU_MASK                                              (0x30000000U)
#define CSL_CBASS_ERR_PID_BU_SHIFT                                             (0x0000001CU)
#define CSL_CBASS_ERR_PID_BU_MAX                                               (0x00000003U)

#define CSL_CBASS_ERR_PID_SCHEME_MASK                                          (0xC0000000U)
#define CSL_CBASS_ERR_PID_SCHEME_SHIFT                                         (0x0000001EU)
#define CSL_CBASS_ERR_PID_SCHEME_MAX                                           (0x00000003U)

/* DESTINATION_ID */

#define CSL_CBASS_ERR_DESTINATION_ID_DEST_ID_MASK                              (0x000000FFU)
#define CSL_CBASS_ERR_DESTINATION_ID_DEST_ID_SHIFT                             (0x00000000U)
#define CSL_CBASS_ERR_DESTINATION_ID_DEST_ID_MAX                               (0x000000FFU)

/* EXCEPTION_LOGGING_HEADER0 */

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_DEST_ID_MASK                   (0x000000FFU)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_DEST_ID_SHIFT                  (0x00000000U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_DEST_ID_MAX                    (0x000000FFU)

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_SRC_ID_MASK                    (0x00FFFF00U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_SRC_ID_SHIFT                   (0x00000008U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_SRC_ID_MAX                     (0x0000FFFFU)

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_TYPE_F_MASK                    (0xFF000000U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_TYPE_F_SHIFT                   (0x00000018U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER0_TYPE_F_MAX                     (0x000000FFU)

/* EXCEPTION_LOGGING_HEADER1 */

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_CODE_MASK                      (0x00FF0000U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_CODE_SHIFT                     (0x00000010U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_CODE_MAX                       (0x000000FFU)

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_GROUP_MASK                     (0xFF000000U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_GROUP_SHIFT                    (0x00000018U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_HEADER1_GROUP_MAX                      (0x000000FFU)

/* EXCEPTION_LOGGING_DATA0 */

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA0_ADDR_L_MASK                      (0xFFFFFFFFU)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA0_ADDR_L_SHIFT                     (0x00000000U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA0_ADDR_L_MAX                       (0xFFFFFFFFU)

/* EXCEPTION_LOGGING_DATA1 */

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA1_ADDR_H_MASK                      (0x0000FFFFU)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA1_ADDR_H_SHIFT                     (0x00000000U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA1_ADDR_H_MAX                       (0x0000FFFFU)

/* EXCEPTION_LOGGING_DATA2 */

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_ID_MASK                     (0x000000FFU)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_ID_SHIFT                    (0x00000000U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_ID_MAX                      (0x000000FFU)

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_SECURE_MASK                      (0x00000100U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_SECURE_SHIFT                     (0x00000008U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_SECURE_MAX                       (0x00000001U)

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_MASK                        (0x00000200U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_SHIFT                       (0x00000009U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_PRIV_MAX                         (0x00000001U)

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_CACHEABLE_MASK                   (0x00000400U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_CACHEABLE_SHIFT                  (0x0000000AU)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_CACHEABLE_MAX                    (0x00000001U)

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_DEBUG_MASK                       (0x00000800U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_DEBUG_SHIFT                      (0x0000000BU)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_DEBUG_MAX                        (0x00000001U)

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_READ_MASK                        (0x00001000U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_READ_SHIFT                       (0x0000000CU)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_READ_MAX                         (0x00000001U)

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_WRITE_MASK                       (0x00002000U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_WRITE_SHIFT                      (0x0000000DU)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_WRITE_MAX                        (0x00000001U)

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_ROUTEID_MASK                     (0x0FFF0000U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_ROUTEID_SHIFT                    (0x00000010U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA2_ROUTEID_MAX                      (0x00000FFFU)

/* EXCEPTION_LOGGING_DATA3 */

#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA3_BYTECNT_MASK                     (0x000003FFU)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA3_BYTECNT_SHIFT                    (0x00000000U)
#define CSL_CBASS_ERR_EXCEPTION_LOGGING_DATA3_BYTECNT_MAX                      (0x000003FFU)

/* ERR_INTR_RAW_STAT */

#define CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MASK                              (0x00000001U)
#define CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_SHIFT                             (0x00000000U)
#define CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MAX                               (0x00000001U)

/* ERR_INTR_ENABLED_STAT */

#define CSL_CBASS_ERR_ERR_INTR_ENABLED_STAT_ENABLED_INTR_MASK                  (0x00000001U)
#define CSL_CBASS_ERR_ERR_INTR_ENABLED_STAT_ENABLED_INTR_SHIFT                 (0x00000000U)
#define CSL_CBASS_ERR_ERR_INTR_ENABLED_STAT_ENABLED_INTR_MAX                   (0x00000001U)

/* ERR_INTR_ENABLE_SET */

#define CSL_CBASS_ERR_ERR_INTR_ENABLE_SET_INTR_ENABLE_SET_MASK                 (0x00000001U)
#define CSL_CBASS_ERR_ERR_INTR_ENABLE_SET_INTR_ENABLE_SET_SHIFT                (0x00000000U)
#define CSL_CBASS_ERR_ERR_INTR_ENABLE_SET_INTR_ENABLE_SET_MAX                  (0x00000001U)

/* ERR_INTR_ENABLE_CLR */

#define CSL_CBASS_ERR_ERR_INTR_ENABLE_CLR_INTR_ENABLE_CLR_MASK                 (0x00000001U)
#define CSL_CBASS_ERR_ERR_INTR_ENABLE_CLR_INTR_ENABLE_CLR_SHIFT                (0x00000000U)
#define CSL_CBASS_ERR_ERR_INTR_ENABLE_CLR_INTR_ENABLE_CLR_MAX                  (0x00000001U)

/* EOI */

#define CSL_CBASS_ERR_EOI_WR_MASK                                              (0x0000FFFFU)
#define CSL_CBASS_ERR_EOI_WR_SHIFT                                             (0x00000000U)
#define CSL_CBASS_ERR_EOI_WR_MAX                                               (0x0000FFFFU)

#ifdef __cplusplus
}
#endif
#endif

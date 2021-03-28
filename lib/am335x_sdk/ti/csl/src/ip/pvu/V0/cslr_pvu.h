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
 *  Name        : cslr_pvu.h
*/
#ifndef CSLR_PVU_H_
#define CSLR_PVU_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : KSDMA Virtual Address Translation Config
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint32_t CONFIG;                    /* Config Register */
    volatile uint8_t  Resv_16[8];
    volatile uint32_t ENABLE;                    /* Enable Register */
    volatile uint32_t VIRTID_MAP1;               /* Map Register 1 */
    volatile uint32_t VIRTID_MAP2;               /* Map Register 2 */
    volatile uint8_t  Resv_48[20];
    volatile uint32_t EXCEPTION_LOGGING_DISABLE;   /* Exception Logging Disable Register */
    volatile uint8_t  Resv_260[208];
    volatile uint32_t DESTINATION_ID;            /* Destination ID Register */
    volatile uint8_t  Resv_288[24];
    volatile uint32_t EXCEPTION_LOGGING_CONTROL;   /* Exception Logging Control Register */
    volatile uint32_t EXCEPTION_LOGGING_HEADER0;   /* Exception Logging Header 0 Register */
    volatile uint32_t EXCEPTION_LOGGING_HEADER1;   /* Exception Logging Header 1 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA0;   /* Exception Logging Data 0 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA1;   /* Exception Logging Data 1 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA2;   /* Exception Logging Data 2 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA3;   /* Exception Logging Data 3 Register */
    volatile uint8_t  Resv_320[4];
    volatile uint32_t EXCEPTION_PEND_SET;        /* Exception Logging Interrupt Pending Set Register */
    volatile uint32_t EXCEPTION_PEND_CLEAR;      /* Exception Logging Interrupt Pending Clear Register */
    volatile uint32_t EXCEPTION_ENABLE_SET;      /* Exception Logging Interrupt Enable Set Register */
    volatile uint32_t EXCEPTION_ENABLE_CLEAR;    /* Exception Logging Interrupt Enable Clear Register */
    volatile uint32_t EOI_REG;                   /* EOI Register */
} CSL_pvuRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_PVU_PID                                                            (0x00000000U)
#define CSL_PVU_CONFIG                                                         (0x00000004U)
#define CSL_PVU_ENABLE                                                         (0x00000010U)
#define CSL_PVU_VIRTID_MAP1                                                    (0x00000014U)
#define CSL_PVU_VIRTID_MAP2                                                    (0x00000018U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE                                      (0x00000030U)
#define CSL_PVU_DESTINATION_ID                                                 (0x00000104U)
#define CSL_PVU_EXCEPTION_LOGGING_CONTROL                                      (0x00000120U)
#define CSL_PVU_EXCEPTION_LOGGING_HEADER0                                      (0x00000124U)
#define CSL_PVU_EXCEPTION_LOGGING_HEADER1                                      (0x00000128U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA0                                        (0x0000012CU)
#define CSL_PVU_EXCEPTION_LOGGING_DATA1                                        (0x00000130U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2                                        (0x00000134U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA3                                        (0x00000138U)
#define CSL_PVU_EXCEPTION_PEND_SET                                             (0x00000140U)
#define CSL_PVU_EXCEPTION_PEND_CLEAR                                           (0x00000144U)
#define CSL_PVU_EXCEPTION_ENABLE_SET                                           (0x00000148U)
#define CSL_PVU_EXCEPTION_ENABLE_CLEAR                                         (0x0000014CU)
#define CSL_PVU_EOI_REG                                                        (0x00000150U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_PVU_PID_MINOR_MASK                                                 (0x0000003FU)
#define CSL_PVU_PID_MINOR_SHIFT                                                (0x00000000U)
#define CSL_PVU_PID_MINOR_MAX                                                  (0x0000003FU)

#define CSL_PVU_PID_CUSTOM_MASK                                                (0x000000C0U)
#define CSL_PVU_PID_CUSTOM_SHIFT                                               (0x00000006U)
#define CSL_PVU_PID_CUSTOM_MAX                                                 (0x00000003U)

#define CSL_PVU_PID_MAJOR_MASK                                                 (0x00000700U)
#define CSL_PVU_PID_MAJOR_SHIFT                                                (0x00000008U)
#define CSL_PVU_PID_MAJOR_MAX                                                  (0x00000007U)

#define CSL_PVU_PID_RTL_MASK                                                   (0x0000F800U)
#define CSL_PVU_PID_RTL_SHIFT                                                  (0x0000000BU)
#define CSL_PVU_PID_RTL_MAX                                                    (0x0000001FU)

#define CSL_PVU_PID_FUNC_MASK                                                  (0x0FFF0000U)
#define CSL_PVU_PID_FUNC_SHIFT                                                 (0x00000010U)
#define CSL_PVU_PID_FUNC_MAX                                                   (0x00000FFFU)

#define CSL_PVU_PID_BU_MASK                                                    (0x30000000U)
#define CSL_PVU_PID_BU_SHIFT                                                   (0x0000001CU)
#define CSL_PVU_PID_BU_MAX                                                     (0x00000003U)

#define CSL_PVU_PID_SCHEME_MASK                                                (0xC0000000U)
#define CSL_PVU_PID_SCHEME_SHIFT                                               (0x0000001EU)
#define CSL_PVU_PID_SCHEME_MAX                                                 (0x00000003U)

/* CONFIG */

#define CSL_PVU_CONFIG_TLBS_MASK                                               (0x0000FFFFU)
#define CSL_PVU_CONFIG_TLBS_SHIFT                                              (0x00000000U)
#define CSL_PVU_CONFIG_TLBS_MAX                                                (0x0000FFFFU)

#define CSL_PVU_CONFIG_TLB_ENTRIES_MASK                                        (0x00FF0000U)
#define CSL_PVU_CONFIG_TLB_ENTRIES_SHIFT                                       (0x00000010U)
#define CSL_PVU_CONFIG_TLB_ENTRIES_MAX                                         (0x000000FFU)

/* ENABLE */

#define CSL_PVU_ENABLE_EN_MASK                                                 (0x00000001U)
#define CSL_PVU_ENABLE_EN_SHIFT                                                (0x00000000U)
#define CSL_PVU_ENABLE_EN_MAX                                                  (0x00000001U)

/* VIRTID_MAP1 */

#define CSL_PVU_VIRTID_MAP1_DMA_CNT_MASK                                       (0x00000FFFU)
#define CSL_PVU_VIRTID_MAP1_DMA_CNT_SHIFT                                      (0x00000000U)
#define CSL_PVU_VIRTID_MAP1_DMA_CNT_MAX                                        (0x00000FFFU)

#define CSL_PVU_VIRTID_MAP1_DMA_CL0_MASK                                       (0x00030000U)
#define CSL_PVU_VIRTID_MAP1_DMA_CL0_SHIFT                                      (0x00000010U)
#define CSL_PVU_VIRTID_MAP1_DMA_CL0_MAX                                        (0x00000003U)

#define CSL_PVU_VIRTID_MAP1_DMA_CL1_MASK                                       (0x000C0000U)
#define CSL_PVU_VIRTID_MAP1_DMA_CL1_SHIFT                                      (0x00000012U)
#define CSL_PVU_VIRTID_MAP1_DMA_CL1_MAX                                        (0x00000003U)

#define CSL_PVU_VIRTID_MAP1_DMA_CL2_MASK                                       (0x00300000U)
#define CSL_PVU_VIRTID_MAP1_DMA_CL2_SHIFT                                      (0x00000014U)
#define CSL_PVU_VIRTID_MAP1_DMA_CL2_MAX                                        (0x00000003U)

#define CSL_PVU_VIRTID_MAP1_DMA_CL3_MASK                                       (0x00C00000U)
#define CSL_PVU_VIRTID_MAP1_DMA_CL3_SHIFT                                      (0x00000016U)
#define CSL_PVU_VIRTID_MAP1_DMA_CL3_MAX                                        (0x00000003U)

/* VIRTID_MAP2 */

#define CSL_PVU_VIRTID_MAP2_MAX_CNT_MASK                                       (0x00000FFFU)
#define CSL_PVU_VIRTID_MAP2_MAX_CNT_SHIFT                                      (0x00000000U)
#define CSL_PVU_VIRTID_MAP2_MAX_CNT_MAX                                        (0x00000FFFU)

/* EXCEPTION_LOGGING_DISABLE */

#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_MISS_DIS_MASK                        (0x00000040U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_MISS_DIS_SHIFT                       (0x00000006U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_MISS_DIS_MAX                         (0x00000001U)

#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_PREF_DIS_MASK                        (0x00000020U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_PREF_DIS_SHIFT                       (0x00000005U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_PREF_DIS_MAX                         (0x00000001U)

#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_EXEC_DIS_MASK                        (0x00000010U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_EXEC_DIS_SHIFT                       (0x00000004U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_EXEC_DIS_MAX                         (0x00000001U)

#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_WRITE_DIS_MASK                       (0x00000008U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_WRITE_DIS_SHIFT                      (0x00000003U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_WRITE_DIS_MAX                        (0x00000001U)

#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_READ_DIS_MASK                        (0x00000004U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_READ_DIS_SHIFT                       (0x00000002U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_READ_DIS_MAX                         (0x00000001U)

#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_VIRTID_DIS_MASK                      (0x00000001U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_VIRTID_DIS_SHIFT                     (0x00000000U)
#define CSL_PVU_EXCEPTION_LOGGING_DISABLE_VIRTID_DIS_MAX                       (0x00000001U)

/* DESTINATION_ID */

#define CSL_PVU_DESTINATION_ID_DEST_ID_MASK                                    (0x000000FFU)
#define CSL_PVU_DESTINATION_ID_DEST_ID_SHIFT                                   (0x00000000U)
#define CSL_PVU_DESTINATION_ID_DEST_ID_MAX                                     (0x000000FFU)

/* EXCEPTION_LOGGING_CONTROL */

#define CSL_PVU_EXCEPTION_LOGGING_CONTROL_DISABLE_F_MASK                       (0x00000001U)
#define CSL_PVU_EXCEPTION_LOGGING_CONTROL_DISABLE_F_SHIFT                      (0x00000000U)
#define CSL_PVU_EXCEPTION_LOGGING_CONTROL_DISABLE_F_MAX                        (0x00000001U)

#define CSL_PVU_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR_MASK                    (0x00000002U)
#define CSL_PVU_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR_SHIFT                   (0x00000001U)
#define CSL_PVU_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR_MAX                     (0x00000001U)

/* EXCEPTION_LOGGING_HEADER0 */

#define CSL_PVU_EXCEPTION_LOGGING_HEADER0_DEST_ID_MASK                         (0x000000FFU)
#define CSL_PVU_EXCEPTION_LOGGING_HEADER0_DEST_ID_SHIFT                        (0x00000000U)
#define CSL_PVU_EXCEPTION_LOGGING_HEADER0_DEST_ID_MAX                          (0x000000FFU)

#define CSL_PVU_EXCEPTION_LOGGING_HEADER0_SRC_ID_MASK                          (0x00FFFF00U)
#define CSL_PVU_EXCEPTION_LOGGING_HEADER0_SRC_ID_SHIFT                         (0x00000008U)
#define CSL_PVU_EXCEPTION_LOGGING_HEADER0_SRC_ID_MAX                           (0x0000FFFFU)

#define CSL_PVU_EXCEPTION_LOGGING_HEADER0_TYPE_F_MASK                          (0xFF000000U)
#define CSL_PVU_EXCEPTION_LOGGING_HEADER0_TYPE_F_SHIFT                         (0x00000018U)
#define CSL_PVU_EXCEPTION_LOGGING_HEADER0_TYPE_F_MAX                           (0x000000FFU)

/* EXCEPTION_LOGGING_HEADER1 */

#define CSL_PVU_EXCEPTION_LOGGING_HEADER1_CODE_MASK                            (0x00FF0000U)
#define CSL_PVU_EXCEPTION_LOGGING_HEADER1_CODE_SHIFT                           (0x00000010U)
#define CSL_PVU_EXCEPTION_LOGGING_HEADER1_CODE_MAX                             (0x000000FFU)

#define CSL_PVU_EXCEPTION_LOGGING_HEADER1_GROUP_MASK                           (0xFF000000U)
#define CSL_PVU_EXCEPTION_LOGGING_HEADER1_GROUP_SHIFT                          (0x00000018U)
#define CSL_PVU_EXCEPTION_LOGGING_HEADER1_GROUP_MAX                            (0x000000FFU)

/* EXCEPTION_LOGGING_DATA0 */

#define CSL_PVU_EXCEPTION_LOGGING_DATA0_ADDR_L_MASK                            (0xFFFFFFFFU)
#define CSL_PVU_EXCEPTION_LOGGING_DATA0_ADDR_L_SHIFT                           (0x00000000U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA0_ADDR_L_MAX                             (0xFFFFFFFFU)

/* EXCEPTION_LOGGING_DATA1 */

#define CSL_PVU_EXCEPTION_LOGGING_DATA1_ADDR_H_MASK                            (0x0000FFFFU)
#define CSL_PVU_EXCEPTION_LOGGING_DATA1_ADDR_H_SHIFT                           (0x00000000U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA1_ADDR_H_MAX                             (0x0000FFFFU)

/* EXCEPTION_LOGGING_DATA2 */

#define CSL_PVU_EXCEPTION_LOGGING_DATA2_PRIV_ID_MASK                           (0x000000FFU)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_PRIV_ID_SHIFT                          (0x00000000U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_PRIV_ID_MAX                            (0x000000FFU)

#define CSL_PVU_EXCEPTION_LOGGING_DATA2_SECURE_MASK                            (0x00000100U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_SECURE_SHIFT                           (0x00000008U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_SECURE_MAX                             (0x00000001U)

#define CSL_PVU_EXCEPTION_LOGGING_DATA2_PRIV_MASK                              (0x00000200U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_PRIV_SHIFT                             (0x00000009U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_PRIV_MAX                               (0x00000001U)

#define CSL_PVU_EXCEPTION_LOGGING_DATA2_CACHEABLE_MASK                         (0x00000400U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_CACHEABLE_SHIFT                        (0x0000000AU)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_CACHEABLE_MAX                          (0x00000001U)

#define CSL_PVU_EXCEPTION_LOGGING_DATA2_DEBUG_MASK                             (0x00000800U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_DEBUG_SHIFT                            (0x0000000BU)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_DEBUG_MAX                              (0x00000001U)

#define CSL_PVU_EXCEPTION_LOGGING_DATA2_READ_MASK                              (0x00001000U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_READ_SHIFT                             (0x0000000CU)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_READ_MAX                               (0x00000001U)

#define CSL_PVU_EXCEPTION_LOGGING_DATA2_WRITE_MASK                             (0x00002000U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_WRITE_SHIFT                            (0x0000000DU)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_WRITE_MAX                              (0x00000001U)

#define CSL_PVU_EXCEPTION_LOGGING_DATA2_ROUTEID_MASK                           (0x0FFF0000U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_ROUTEID_SHIFT                          (0x00000010U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA2_ROUTEID_MAX                            (0x00000FFFU)

/* EXCEPTION_LOGGING_DATA3 */

#define CSL_PVU_EXCEPTION_LOGGING_DATA3_BYTECNT_MASK                           (0x000003FFU)
#define CSL_PVU_EXCEPTION_LOGGING_DATA3_BYTECNT_SHIFT                          (0x00000000U)
#define CSL_PVU_EXCEPTION_LOGGING_DATA3_BYTECNT_MAX                            (0x000003FFU)

/* EXCEPTION_PEND_SET */

#define CSL_PVU_EXCEPTION_PEND_SET_PEND_SET_MASK                               (0x00000001U)
#define CSL_PVU_EXCEPTION_PEND_SET_PEND_SET_SHIFT                              (0x00000000U)
#define CSL_PVU_EXCEPTION_PEND_SET_PEND_SET_MAX                                (0x00000001U)

/* EXCEPTION_PEND_CLEAR */

#define CSL_PVU_EXCEPTION_PEND_CLEAR_PEND_CLR_MASK                             (0x00000001U)
#define CSL_PVU_EXCEPTION_PEND_CLEAR_PEND_CLR_SHIFT                            (0x00000000U)
#define CSL_PVU_EXCEPTION_PEND_CLEAR_PEND_CLR_MAX                              (0x00000001U)

/* EXCEPTION_ENABLE_SET */

#define CSL_PVU_EXCEPTION_ENABLE_SET_ENABLE_SET_MASK                           (0x00000001U)
#define CSL_PVU_EXCEPTION_ENABLE_SET_ENABLE_SET_SHIFT                          (0x00000000U)
#define CSL_PVU_EXCEPTION_ENABLE_SET_ENABLE_SET_MAX                            (0x00000001U)

/* EXCEPTION_ENABLE_CLEAR */

#define CSL_PVU_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR_MASK                         (0x00000001U)
#define CSL_PVU_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR_SHIFT                        (0x00000000U)
#define CSL_PVU_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR_MAX                          (0x00000001U)

/* EOI_REG */

#define CSL_PVU_EOI_REG_EOI_WR_MASK                                            (0x0000FFFFU)
#define CSL_PVU_EOI_REG_EOI_WR_SHIFT                                           (0x00000000U)
#define CSL_PVU_EOI_REG_EOI_WR_MAX                                             (0x0000FFFFU)

/**************************************************************************
* Hardware Region  : KSDMA Virtual Address Translation TLB Config
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t ENTRY0;                    /* TLB Entry Register */
    volatile uint32_t ENTRY1;                    /* TLB Entry Register */
    volatile uint32_t ENTRY2;                    /* TLB Entry Register */
    volatile uint8_t  Resv_16[4];
    volatile uint32_t ENTRY4;                    /* TLB Entry Register */
    volatile uint32_t ENTRY5;                    /* TLB Entry Register */
    volatile uint32_t ENTRY6;                    /* TLB Entry Register */
    volatile uint8_t  Resv_32[4];
} CSL_pvu_tlbRegs_VIRT_TLB;


typedef struct {
    volatile uint32_t CHAIN;                     /* TLB Chain Register */
    volatile uint8_t  Resv_32[28];
    CSL_pvu_tlbRegs_VIRT_TLB TLB[8];
    volatile uint8_t  Resv_4096[3808];
} CSL_pvu_tlbRegs_VIRT;


typedef struct {
    CSL_pvu_tlbRegs_VIRT VIRT[1024];
} CSL_pvu_tlbRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_PVU_TLB_VIRT_CHAIN(VIRT)                                           (0x00000000U+((VIRT)*0x1000U))
#define CSL_PVU_TLB_VIRT_TLB_ENTRY0(VIRT, TLB)                                 (0x00000020U+((VIRT)*0x1000U)+((TLB)*0x20U))
#define CSL_PVU_TLB_VIRT_TLB_ENTRY1(VIRT, TLB)                                 (0x00000024U+((VIRT)*0x1000U)+((TLB)*0x20U))
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2(VIRT, TLB)                                 (0x00000028U+((VIRT)*0x1000U)+((TLB)*0x20U))
#define CSL_PVU_TLB_VIRT_TLB_ENTRY4(VIRT, TLB)                                 (0x00000030U+((VIRT)*0x1000U)+((TLB)*0x20U))
#define CSL_PVU_TLB_VIRT_TLB_ENTRY5(VIRT, TLB)                                 (0x00000034U+((VIRT)*0x1000U)+((TLB)*0x20U))
#define CSL_PVU_TLB_VIRT_TLB_ENTRY6(VIRT, TLB)                                 (0x00000038U+((VIRT)*0x1000U)+((TLB)*0x20U))

/**************************************************************************
* 64K Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t ENTRY0;                    /* TLB Entry Register */
    volatile uint32_t ENTRY1;                    /* TLB Entry Register */
    volatile uint32_t ENTRY2;                    /* TLB Entry Register */
    volatile uint8_t  Resv_16[4];
    volatile uint32_t ENTRY4;                    /* TLB Entry Register */
    volatile uint32_t ENTRY5;                    /* TLB Entry Register */
    volatile uint32_t ENTRY6;                    /* TLB Entry Register */
    volatile uint8_t  Resv_32[4];
} CSL_a64_pvu_tlbRegs_VIRT_TLB;


typedef struct {
    volatile uint32_t CHAIN;                     /* TLB Chain Register */
    volatile uint8_t  Resv_32[28];
    CSL_a64_pvu_tlbRegs_VIRT_TLB TLB[8];
    volatile uint8_t  Resv_65536[65248];
} CSL_a64_pvu_tlbRegs_VIRT;


typedef struct {
    CSL_a64_pvu_tlbRegs_VIRT VIRT[1024];
} CSL_a64_pvu_tlbRegs;


/**************************************************************************
* 64K Register Macros
**************************************************************************/

#define CSL_A64_PVU_TLB_VIRT_CHAIN(VIRT)                                       (0x00000000U+((VIRT)*0x10000U))
#define CSL_A64_PVU_TLB_VIRT_TLB_ENTRY0(VIRT, TLB)                             (0x00000020U+((VIRT)*0x10000U)+((TLB)*0x20U))
#define CSL_A64_PVU_TLB_VIRT_TLB_ENTRY1(VIRT, TLB)                             (0x00000024U+((VIRT)*0x10000U)+((TLB)*0x20U))
#define CSL_A64_PVU_TLB_VIRT_TLB_ENTRY2(VIRT, TLB)                             (0x00000028U+((VIRT)*0x10000U)+((TLB)*0x20U))
#define CSL_A64_PVU_TLB_VIRT_TLB_ENTRY4(VIRT, TLB)                             (0x00000030U+((VIRT)*0x10000U)+((TLB)*0x20U))
#define CSL_A64_PVU_TLB_VIRT_TLB_ENTRY5(VIRT, TLB)                             (0x00000034U+((VIRT)*0x10000U)+((TLB)*0x20U))
#define CSL_A64_PVU_TLB_VIRT_TLB_ENTRY6(VIRT, TLB)                             (0x00000038U+((VIRT)*0x10000U)+((TLB)*0x20U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* ENTRY0 */

#define CSL_PVU_TLB_VIRT_TLB_ENTRY0_VBASE_L_MASK                               (0xFFFFFFFFU)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY0_VBASE_L_SHIFT                              (0x00000000U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY0_VBASE_L_MAX                                (0xFFFFFFFFU)

/* ENTRY1 */

#define CSL_PVU_TLB_VIRT_TLB_ENTRY1_VBASE_H_MASK                               (0x0000FFFFU)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY1_VBASE_H_SHIFT                              (0x00000000U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY1_VBASE_H_MAX                                (0x0000FFFFU)

/* ENTRY2 */

#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_MODE_MASK                                  (0xC0000000U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_MODE_SHIFT                                 (0x0000001EU)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_MODE_MAX                                   (0x00000003U)

#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_SEC_DEM_MASK                               (0x20000000U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_SEC_DEM_SHIFT                              (0x0000001DU)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_SEC_DEM_MAX                                (0x00000001U)

#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PSECURE_MASK                               (0x00200000U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PSECURE_SHIFT                              (0x00000015U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PSECURE_MAX                                (0x00000001U)

#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PSIZE_MASK                                 (0x000F0000U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PSIZE_SHIFT                                (0x00000010U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PSIZE_MAX                                  (0x0000000FU)

#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PPERM_MASK                                 (0x0000FC00U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PPERM_SHIFT                                (0x0000000AU)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PPERM_MAX                                  (0x0000003FU)

#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PMEMTYPE_MASK                              (0x00000300U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PMEMTYPE_SHIFT                             (0x00000008U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PMEMTYPE_MAX                               (0x00000003U)

#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PPREFETCH_MASK                             (0x00000040U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PPREFETCH_SHIFT                            (0x00000006U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PPREFETCH_MAX                              (0x00000001U)

#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PISABLE_MASK                               (0x00000020U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PISABLE_SHIFT                              (0x00000005U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PISABLE_MAX                                (0x00000001U)

#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_POSABLE_MASK                               (0x00000010U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_POSABLE_SHIFT                              (0x00000004U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_POSABLE_MAX                                (0x00000001U)

#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PIALLOCPOL_MASK                            (0x0000000CU)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PIALLOCPOL_SHIFT                           (0x00000002U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_PIALLOCPOL_MAX                             (0x00000003U)

#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_POALLOCPOL_MASK                            (0x00000003U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_POALLOCPOL_SHIFT                           (0x00000000U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY2_POALLOCPOL_MAX                             (0x00000003U)

/* ENTRY4 */

#define CSL_PVU_TLB_VIRT_TLB_ENTRY4_PBASE_L_MASK                               (0xFFFFFFFFU)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY4_PBASE_L_SHIFT                              (0x00000000U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY4_PBASE_L_MAX                                (0xFFFFFFFFU)

/* ENTRY5 */

#define CSL_PVU_TLB_VIRT_TLB_ENTRY5_PBASE_H_MASK                               (0x0000FFFFU)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY5_PBASE_H_SHIFT                              (0x00000000U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY5_PBASE_H_MAX                                (0x0000FFFFU)

/* ENTRY6 */

#define CSL_PVU_TLB_VIRT_TLB_ENTRY6_REPLACE_MASK                               (0x00000010U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY6_REPLACE_SHIFT                              (0x00000004U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY6_REPLACE_MAX                                (0x00000001U)

#define CSL_PVU_TLB_VIRT_TLB_ENTRY6_ORDERID_MASK                               (0x0000000FU)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY6_ORDERID_SHIFT                              (0x00000000U)
#define CSL_PVU_TLB_VIRT_TLB_ENTRY6_ORDERID_MAX                                (0x0000000FU)

/* CHAIN */

#define CSL_PVU_TLB_VIRT_CHAIN_EN_MASK                                         (0x80000000U)
#define CSL_PVU_TLB_VIRT_CHAIN_EN_SHIFT                                        (0x0000001FU)
#define CSL_PVU_TLB_VIRT_CHAIN_EN_MAX                                          (0x00000001U)

#define CSL_PVU_TLB_VIRT_CHAIN_LOG_DIS_MASK                                    (0x40000000U)
#define CSL_PVU_TLB_VIRT_CHAIN_LOG_DIS_SHIFT                                   (0x0000001EU)
#define CSL_PVU_TLB_VIRT_CHAIN_LOG_DIS_MAX                                     (0x00000001U)

#define CSL_PVU_TLB_VIRT_CHAIN_FAULT_MASK                                      (0x20000000U)
#define CSL_PVU_TLB_VIRT_CHAIN_FAULT_SHIFT                                     (0x0000001DU)
#define CSL_PVU_TLB_VIRT_CHAIN_FAULT_MAX                                       (0x00000001U)

#define CSL_PVU_TLB_VIRT_CHAIN_CHAIN_MASK                                      (0x00000FFFU)
#define CSL_PVU_TLB_VIRT_CHAIN_CHAIN_SHIFT                                     (0x00000000U)
#define CSL_PVU_TLB_VIRT_CHAIN_CHAIN_MAX                                       (0x00000FFFU)

#ifdef __cplusplus
}
#endif
#endif

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
 *  Name        : cslr_pat.h
*/
#ifndef CSLR_PAT_H_
#define CSLR_PAT_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : KSBUS Page-Based Address Translation Config
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint32_t CONFIG;                    /* Config Register */
    volatile uint8_t  Resv_16[8];
    volatile uint32_t CONTROL;                   /* Control Register */
    volatile uint8_t  Resv_132[112];
    volatile uint32_t DESTINATION_ID;            /* Destination ID Register */
    volatile uint8_t  Resv_160[24];
    volatile uint32_t EXCEPTION_LOGGING_CONTROL;   /* Exception Logging Control Register */
    volatile uint32_t EXCEPTION_LOGGING_HEADER0;   /* Exception Logging Header 0 Register */
    volatile uint32_t EXCEPTION_LOGGING_HEADER1;   /* Exception Logging Header 1 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA0;   /* Exception Logging Data 0 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA1;   /* Exception Logging Data 1 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA2;   /* Exception Logging Data 2 Register */
    volatile uint32_t EXCEPTION_LOGGING_DATA3;   /* Exception Logging Data 3 Register */
    volatile uint8_t  Resv_192[4];
    volatile uint32_t EXCEPTION_PEND_SET;        /* Exception Logging Interrupt Pending Set Register */
    volatile uint32_t EXCEPTION_PEND_CLEAR;      /* Exception Logging Interrupt Pending Clear Register */
    volatile uint32_t EXCEPTION_ENABLE_SET;      /* Exception Logging Interrupt Enable Set Register */
    volatile uint32_t EXCEPTION_ENABLE_CLEAR;    /* Exception Logging Interrupt Enable Clear Register */
    volatile uint32_t EOI_REG;                   /* EOI Register */
} CSL_patRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_PAT_PID                                                            (0x00000000U)
#define CSL_PAT_CONFIG                                                         (0x00000004U)
#define CSL_PAT_CONTROL                                                        (0x00000010U)
#define CSL_PAT_DESTINATION_ID                                                 (0x00000084U)
#define CSL_PAT_EXCEPTION_LOGGING_CONTROL                                      (0x000000A0U)
#define CSL_PAT_EXCEPTION_LOGGING_HEADER0                                      (0x000000A4U)
#define CSL_PAT_EXCEPTION_LOGGING_HEADER1                                      (0x000000A8U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA0                                        (0x000000ACU)
#define CSL_PAT_EXCEPTION_LOGGING_DATA1                                        (0x000000B0U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2                                        (0x000000B4U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA3                                        (0x000000B8U)
#define CSL_PAT_EXCEPTION_PEND_SET                                             (0x000000C0U)
#define CSL_PAT_EXCEPTION_PEND_CLEAR                                           (0x000000C4U)
#define CSL_PAT_EXCEPTION_ENABLE_SET                                           (0x000000C8U)
#define CSL_PAT_EXCEPTION_ENABLE_CLEAR                                         (0x000000CCU)
#define CSL_PAT_EOI_REG                                                        (0x000000D0U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_PAT_PID_MINOR_MASK                                                 (0x0000003FU)
#define CSL_PAT_PID_MINOR_SHIFT                                                (0x00000000U)
#define CSL_PAT_PID_MINOR_MAX                                                  (0x0000003FU)

#define CSL_PAT_PID_CUSTOM_MASK                                                (0x000000C0U)
#define CSL_PAT_PID_CUSTOM_SHIFT                                               (0x00000006U)
#define CSL_PAT_PID_CUSTOM_MAX                                                 (0x00000003U)

#define CSL_PAT_PID_MAJOR_MASK                                                 (0x00000700U)
#define CSL_PAT_PID_MAJOR_SHIFT                                                (0x00000008U)
#define CSL_PAT_PID_MAJOR_MAX                                                  (0x00000007U)

#define CSL_PAT_PID_RTL_MASK                                                   (0x0000F800U)
#define CSL_PAT_PID_RTL_SHIFT                                                  (0x0000000BU)
#define CSL_PAT_PID_RTL_MAX                                                    (0x0000001FU)

#define CSL_PAT_PID_FUNC_MASK                                                  (0x0FFF0000U)
#define CSL_PAT_PID_FUNC_SHIFT                                                 (0x00000010U)
#define CSL_PAT_PID_FUNC_MAX                                                   (0x00000FFFU)

#define CSL_PAT_PID_BU_MASK                                                    (0x30000000U)
#define CSL_PAT_PID_BU_SHIFT                                                   (0x0000001CU)
#define CSL_PAT_PID_BU_MAX                                                     (0x00000003U)

#define CSL_PAT_PID_SCHEME_MASK                                                (0xC0000000U)
#define CSL_PAT_PID_SCHEME_SHIFT                                               (0x0000001EU)
#define CSL_PAT_PID_SCHEME_MAX                                                 (0x00000003U)

/* CONFIG */

#define CSL_PAT_CONFIG_PAGES_MASK                                              (0xFFFFFFFFU)
#define CSL_PAT_CONFIG_PAGES_SHIFT                                             (0x00000000U)
#define CSL_PAT_CONFIG_PAGES_MAX                                               (0xFFFFFFFFU)

/* CONTROL */

#define CSL_PAT_CONTROL_ENABLE_MASK                                            (0x00000001U)
#define CSL_PAT_CONTROL_ENABLE_SHIFT                                           (0x00000000U)
#define CSL_PAT_CONTROL_ENABLE_MAX                                             (0x00000001U)

#define CSL_PAT_CONTROL_REPLACE_ORDERID_ENABLE_MASK                            (0x00000002U)
#define CSL_PAT_CONTROL_REPLACE_ORDERID_ENABLE_SHIFT                           (0x00000001U)
#define CSL_PAT_CONTROL_REPLACE_ORDERID_ENABLE_MAX                             (0x00000001U)

#define CSL_PAT_CONTROL_PAGE_SIZE_MASK                                         (0x00000030U)
#define CSL_PAT_CONTROL_PAGE_SIZE_SHIFT                                        (0x00000004U)
#define CSL_PAT_CONTROL_PAGE_SIZE_MAX                                          (0x00000003U)

#define CSL_PAT_CONTROL_ARB_MODE_MASK                                          (0x000000C0U)
#define CSL_PAT_CONTROL_ARB_MODE_SHIFT                                         (0x00000006U)
#define CSL_PAT_CONTROL_ARB_MODE_MAX                                           (0x00000003U)

/* DESTINATION_ID */

#define CSL_PAT_DESTINATION_ID_DEST_ID_MASK                                    (0x000000FFU)
#define CSL_PAT_DESTINATION_ID_DEST_ID_SHIFT                                   (0x00000000U)
#define CSL_PAT_DESTINATION_ID_DEST_ID_MAX                                     (0x000000FFU)

/* EXCEPTION_LOGGING_CONTROL */

#define CSL_PAT_EXCEPTION_LOGGING_CONTROL_DISABLE_F_MASK                       (0x00000001U)
#define CSL_PAT_EXCEPTION_LOGGING_CONTROL_DISABLE_F_SHIFT                      (0x00000000U)
#define CSL_PAT_EXCEPTION_LOGGING_CONTROL_DISABLE_F_MAX                        (0x00000001U)

#define CSL_PAT_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR_MASK                    (0x00000002U)
#define CSL_PAT_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR_SHIFT                   (0x00000001U)
#define CSL_PAT_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR_MAX                     (0x00000001U)

/* EXCEPTION_LOGGING_HEADER0 */

#define CSL_PAT_EXCEPTION_LOGGING_HEADER0_DEST_ID_MASK                         (0x000000FFU)
#define CSL_PAT_EXCEPTION_LOGGING_HEADER0_DEST_ID_SHIFT                        (0x00000000U)
#define CSL_PAT_EXCEPTION_LOGGING_HEADER0_DEST_ID_MAX                          (0x000000FFU)

#define CSL_PAT_EXCEPTION_LOGGING_HEADER0_SRC_ID_MASK                          (0x00FFFF00U)
#define CSL_PAT_EXCEPTION_LOGGING_HEADER0_SRC_ID_SHIFT                         (0x00000008U)
#define CSL_PAT_EXCEPTION_LOGGING_HEADER0_SRC_ID_MAX                           (0x0000FFFFU)

#define CSL_PAT_EXCEPTION_LOGGING_HEADER0_TYPE_F_MASK                          (0xFF000000U)
#define CSL_PAT_EXCEPTION_LOGGING_HEADER0_TYPE_F_SHIFT                         (0x00000018U)
#define CSL_PAT_EXCEPTION_LOGGING_HEADER0_TYPE_F_MAX                           (0x000000FFU)

/* EXCEPTION_LOGGING_HEADER1 */

#define CSL_PAT_EXCEPTION_LOGGING_HEADER1_CODE_MASK                            (0x00FF0000U)
#define CSL_PAT_EXCEPTION_LOGGING_HEADER1_CODE_SHIFT                           (0x00000010U)
#define CSL_PAT_EXCEPTION_LOGGING_HEADER1_CODE_MAX                             (0x000000FFU)

#define CSL_PAT_EXCEPTION_LOGGING_HEADER1_GROUP_MASK                           (0xFF000000U)
#define CSL_PAT_EXCEPTION_LOGGING_HEADER1_GROUP_SHIFT                          (0x00000018U)
#define CSL_PAT_EXCEPTION_LOGGING_HEADER1_GROUP_MAX                            (0x000000FFU)

/* EXCEPTION_LOGGING_DATA0 */

#define CSL_PAT_EXCEPTION_LOGGING_DATA0_ADDR_L_MASK                            (0xFFFFFFFFU)
#define CSL_PAT_EXCEPTION_LOGGING_DATA0_ADDR_L_SHIFT                           (0x00000000U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA0_ADDR_L_MAX                             (0xFFFFFFFFU)

/* EXCEPTION_LOGGING_DATA1 */

#define CSL_PAT_EXCEPTION_LOGGING_DATA1_ADDR_H_MASK                            (0x0000FFFFU)
#define CSL_PAT_EXCEPTION_LOGGING_DATA1_ADDR_H_SHIFT                           (0x00000000U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA1_ADDR_H_MAX                             (0x0000FFFFU)

/* EXCEPTION_LOGGING_DATA2 */

#define CSL_PAT_EXCEPTION_LOGGING_DATA2_PRIV_ID_MASK                           (0x000000FFU)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_PRIV_ID_SHIFT                          (0x00000000U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_PRIV_ID_MAX                            (0x000000FFU)

#define CSL_PAT_EXCEPTION_LOGGING_DATA2_SECURE_MASK                            (0x00000100U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_SECURE_SHIFT                           (0x00000008U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_SECURE_MAX                             (0x00000001U)

#define CSL_PAT_EXCEPTION_LOGGING_DATA2_PRIV_MASK                              (0x00000200U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_PRIV_SHIFT                             (0x00000009U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_PRIV_MAX                               (0x00000001U)

#define CSL_PAT_EXCEPTION_LOGGING_DATA2_CACHEABLE_MASK                         (0x00000400U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_CACHEABLE_SHIFT                        (0x0000000AU)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_CACHEABLE_MAX                          (0x00000001U)

#define CSL_PAT_EXCEPTION_LOGGING_DATA2_DEBUG_MASK                             (0x00000800U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_DEBUG_SHIFT                            (0x0000000BU)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_DEBUG_MAX                              (0x00000001U)

#define CSL_PAT_EXCEPTION_LOGGING_DATA2_READ_MASK                              (0x00001000U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_READ_SHIFT                             (0x0000000CU)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_READ_MAX                               (0x00000001U)

#define CSL_PAT_EXCEPTION_LOGGING_DATA2_WRITE_MASK                             (0x00002000U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_WRITE_SHIFT                            (0x0000000DU)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_WRITE_MAX                              (0x00000001U)

#define CSL_PAT_EXCEPTION_LOGGING_DATA2_ROUTEID_MASK                           (0x0FFF0000U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_ROUTEID_SHIFT                          (0x00000010U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA2_ROUTEID_MAX                            (0x00000FFFU)

/* EXCEPTION_LOGGING_DATA3 */

#define CSL_PAT_EXCEPTION_LOGGING_DATA3_BYTECNT_MASK                           (0x000003FFU)
#define CSL_PAT_EXCEPTION_LOGGING_DATA3_BYTECNT_SHIFT                          (0x00000000U)
#define CSL_PAT_EXCEPTION_LOGGING_DATA3_BYTECNT_MAX                            (0x000003FFU)

/* EXCEPTION_PEND_SET */

#define CSL_PAT_EXCEPTION_PEND_SET_PEND_SET_MASK                               (0x00000001U)
#define CSL_PAT_EXCEPTION_PEND_SET_PEND_SET_SHIFT                              (0x00000000U)
#define CSL_PAT_EXCEPTION_PEND_SET_PEND_SET_MAX                                (0x00000001U)

/* EXCEPTION_PEND_CLEAR */

#define CSL_PAT_EXCEPTION_PEND_CLEAR_PEND_CLR_MASK                             (0x00000001U)
#define CSL_PAT_EXCEPTION_PEND_CLEAR_PEND_CLR_SHIFT                            (0x00000000U)
#define CSL_PAT_EXCEPTION_PEND_CLEAR_PEND_CLR_MAX                              (0x00000001U)

/* EXCEPTION_ENABLE_SET */

#define CSL_PAT_EXCEPTION_ENABLE_SET_ENABLE_SET_MASK                           (0x00000001U)
#define CSL_PAT_EXCEPTION_ENABLE_SET_ENABLE_SET_SHIFT                          (0x00000000U)
#define CSL_PAT_EXCEPTION_ENABLE_SET_ENABLE_SET_MAX                            (0x00000001U)

/* EXCEPTION_ENABLE_CLEAR */

#define CSL_PAT_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR_MASK                         (0x00000001U)
#define CSL_PAT_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR_SHIFT                        (0x00000000U)
#define CSL_PAT_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR_MAX                          (0x00000001U)

/* EOI_REG */

#define CSL_PAT_EOI_REG_EOI_WR_MASK                                            (0x0000FFFFU)
#define CSL_PAT_EOI_REG_EOI_WR_SHIFT                                           (0x00000000U)
#define CSL_PAT_EOI_REG_EOI_WR_MAX                                             (0x0000FFFFU)

/**************************************************************************
* Hardware Region  : KSBUS Page-Based Address Translation Table Config
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t BASE_REG_L;                /* Page Base Low Register */
    volatile uint32_t BASE_REG_H;                /* Page Base High Register */
} CSL_pat_tableRegs_BLOCK_PAGE;


typedef struct {
    CSL_pat_tableRegs_BLOCK_PAGE PAGE[256];
    volatile uint8_t  Resv_4096[2048];
} CSL_pat_tableRegs_BLOCK;


typedef struct {
    CSL_pat_tableRegs_BLOCK BLOCK[512];
} CSL_pat_tableRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_L(BLOCK, PAGE)                       (0x00000000U+((BLOCK)*0x1000U)+((PAGE)*0x8U))
#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H(BLOCK, PAGE)                       (0x00000004U+((BLOCK)*0x1000U)+((PAGE)*0x8U))

/**************************************************************************
* 64K Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t BASE_REG_L;                /* Page Base Low Register */
    volatile uint32_t BASE_REG_H;                /* Page Base High Register */
} CSL_a64_pat_tableRegs_BLOCK_PAGE;


typedef struct {
    CSL_a64_pat_tableRegs_BLOCK_PAGE PAGE[256];
    volatile uint8_t  Resv_65536[63488];
} CSL_a64_pat_tableRegs_BLOCK;


typedef struct {
    CSL_a64_pat_tableRegs_BLOCK BLOCK[512];
} CSL_a64_pat_tableRegs;


/**************************************************************************
* 64K Register Macros
**************************************************************************/

#define CSL_A64_PAT_TABLE_BLOCK_PAGE_BASE_REG_L(BLOCK, PAGE)                   (0x00000000U+((BLOCK)*0x10000U)+((PAGE)*0x8U))
#define CSL_A64_PAT_TABLE_BLOCK_PAGE_BASE_REG_H(BLOCK, PAGE)                   (0x00000004U+((BLOCK)*0x10000U)+((PAGE)*0x8U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* BASE_REG_L */

#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_L_BASE_L_MASK                        (0xFFFFFFFFU)
#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_L_BASE_L_SHIFT                       (0x00000000U)
#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_L_BASE_L_MAX                         (0xFFFFFFFFU)

/* BASE_REG_H */

#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H_BASE_H_MASK                        (0x0000000FU)
#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H_BASE_H_SHIFT                       (0x00000000U)
#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H_BASE_H_MAX                         (0x0000000FU)

#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H_ORDERID_MASK                       (0x0F000000U)
#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H_ORDERID_SHIFT                      (0x00000018U)
#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H_ORDERID_MAX                        (0x0000000FU)

#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H_REPLACE_OID_MASK                   (0x40000000U)
#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H_REPLACE_OID_SHIFT                  (0x0000001EU)
#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H_REPLACE_OID_MAX                    (0x00000001U)

#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H_ENABLE_MASK                        (0x80000000U)
#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H_ENABLE_SHIFT                       (0x0000001FU)
#define CSL_PAT_TABLE_BLOCK_PAGE_BASE_REG_H_ENABLE_MAX                         (0x00000001U)

/**************************************************************************
* Hardware Region  : KSBUS Page-Based Address Translation Scratch
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t MEM[131072];               /* Scratch Memory Space */
} CSL_pat_scratchRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_PAT_SCRATCH_MEM(MEM)                                               (0x00000000U+((MEM)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* MEM */

#define CSL_PAT_SCRATCH_MEM_MEM_MASK                                           (0xFFFFFFFFU)
#define CSL_PAT_SCRATCH_MEM_MEM_SHIFT                                          (0x00000000U)
#define CSL_PAT_SCRATCH_MEM_MEM_MAX                                            (0xFFFFFFFFU)

#ifdef __cplusplus
}
#endif
#endif

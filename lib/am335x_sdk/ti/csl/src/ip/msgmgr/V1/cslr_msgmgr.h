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
 *  Name        : cslr_msgmgr.h
*/
#ifndef CSLR_MSGMGR_H_
#define CSLR_MSGMGR_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t CONTROL;                   /* Monitor Control Register */
    volatile uint32_t QUEUE;                     /* Monitor Queue Register */
    volatile uint32_t DATA0;                     /* Monitor Data Register */
    volatile uint32_t DATA1;                     /* Monitor Data Register */
} CSL_msgmgrRegs_mon;


typedef struct {
    volatile uint32_t REVISION;                  /* Msgmgr Revision Register */
    volatile uint8_t  Resv_16[12];
    volatile uint32_t FREE_INTR_RAW_STAT;        /* Global Interrupt Raw Status Register */
    volatile uint32_t FREE_INTR_ENABLED_STAT;    /* Global Interrupt Enabled Status Register */
    volatile uint32_t FREE_INTR_ENABLE_SET;      /* Interrupt Enable Set Register */
    volatile uint32_t FREE_INTR_ENABLE_CLR;      /* Interrupt Enable Clear Register */
    volatile uint32_t EOI;                       /* EOI Register */
    volatile uint8_t  Resv_48[12];
    volatile uint32_t INTR_RAW_STAT0;            /* Global Interrupt Raw Status Register */
    volatile uint32_t INTR_RAW_STAT1;            /* Global Interrupt Raw Status Register */
    volatile uint32_t INTR_ENABLED_STAT0;        /* Global Interrupt Enabled Status Register */
    volatile uint32_t INTR_ENABLED_STAT1;        /* Global Interrupt Enabled Status Register */
    volatile uint32_t INTR_ENABLE_SET0;          /* Interrupt Enable Set Register */
    volatile uint32_t INTR_ENABLE_SET1;          /* Interrupt Enable Set Register */
    volatile uint32_t INTR_ENABLE_CLR0;          /* Interrupt Enable Clear Register */
    volatile uint32_t INTR_ENABLE_CLR1;          /* Interrupt Enable Clear Register */
    volatile uint8_t  Resv_112[32];
    volatile uint32_t TRACE_CTL;                 /* Trace Control Register */
    volatile uint8_t  Resv_256[140];
    CSL_msgmgrRegs_mon MON[64];
} CSL_msgmgrRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MSGMGR_REVISION                                                    (0x00000000U)
#define CSL_MSGMGR_FREE_INTR_RAW_STAT                                          (0x00000010U)
#define CSL_MSGMGR_FREE_INTR_ENABLED_STAT                                      (0x00000014U)
#define CSL_MSGMGR_FREE_INTR_ENABLE_SET                                        (0x00000018U)
#define CSL_MSGMGR_FREE_INTR_ENABLE_CLR                                        (0x0000001CU)
#define CSL_MSGMGR_EOI                                                         (0x00000020U)
#define CSL_MSGMGR_INTR_RAW_STAT0                                              (0x00000030U)
#define CSL_MSGMGR_INTR_RAW_STAT1                                              (0x00000034U)
#define CSL_MSGMGR_INTR_ENABLED_STAT0                                          (0x00000038U)
#define CSL_MSGMGR_INTR_ENABLED_STAT1                                          (0x0000003CU)
#define CSL_MSGMGR_INTR_ENABLE_SET0                                            (0x00000040U)
#define CSL_MSGMGR_INTR_ENABLE_SET1                                            (0x00000044U)
#define CSL_MSGMGR_INTR_ENABLE_CLR0                                            (0x00000048U)
#define CSL_MSGMGR_INTR_ENABLE_CLR1                                            (0x0000004CU)
#define CSL_MSGMGR_TRACE_CTL                                                   (0x00000070U)
#define CSL_MSGMGR_MON_CONTROL(MON)                                            (0x00000100U+((MON)*0x10U))
#define CSL_MSGMGR_MON_QUEUE(MON)                                              (0x00000104U+((MON)*0x10U))
#define CSL_MSGMGR_MON_DATA0(MON)                                              (0x00000108U+((MON)*0x10U))
#define CSL_MSGMGR_MON_DATA1(MON)                                              (0x0000010CU+((MON)*0x10U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* CONTROL */

#define CSL_MSGMGR_MON_CONTROL_INTR_MASK                                       (0xFF000000U)
#define CSL_MSGMGR_MON_CONTROL_INTR_SHIFT                                      (0x00000018U)
#define CSL_MSGMGR_MON_CONTROL_INTR_MAX                                        (0x000000FFU)

#define CSL_MSGMGR_MON_CONTROL_SOURCE_MASK                                     (0x00000F00U)
#define CSL_MSGMGR_MON_CONTROL_SOURCE_SHIFT                                    (0x00000008U)
#define CSL_MSGMGR_MON_CONTROL_SOURCE_MAX                                      (0x0000000FU)

#define CSL_MSGMGR_MON_CONTROL_MODE_MASK                                       (0x00000007U)
#define CSL_MSGMGR_MON_CONTROL_MODE_SHIFT                                      (0x00000000U)
#define CSL_MSGMGR_MON_CONTROL_MODE_MAX                                        (0x00000007U)

/* QUEUE */

#define CSL_MSGMGR_MON_QUEUE_VAL_MASK                                          (0x0000FFFFU)
#define CSL_MSGMGR_MON_QUEUE_VAL_SHIFT                                         (0x00000000U)
#define CSL_MSGMGR_MON_QUEUE_VAL_MAX                                           (0x0000FFFFU)

/* DATA0 */

#define CSL_MSGMGR_MON_DATA0_VAL_MASK                                          (0xFFFFFFFFU)
#define CSL_MSGMGR_MON_DATA0_VAL_SHIFT                                         (0x00000000U)
#define CSL_MSGMGR_MON_DATA0_VAL_MAX                                           (0xFFFFFFFFU)

/* DATA1 */

#define CSL_MSGMGR_MON_DATA1_VAL_MASK                                          (0xFFFFFFFFU)
#define CSL_MSGMGR_MON_DATA1_VAL_SHIFT                                         (0x00000000U)
#define CSL_MSGMGR_MON_DATA1_VAL_MAX                                           (0xFFFFFFFFU)

/* REVISION */

#define CSL_MSGMGR_REVISION_SCHEME_MASK                                        (0xC0000000U)
#define CSL_MSGMGR_REVISION_SCHEME_SHIFT                                       (0x0000001EU)
#define CSL_MSGMGR_REVISION_SCHEME_MAX                                         (0x00000003U)

#define CSL_MSGMGR_REVISION_MODULE_ID_MASK                                     (0x0FFF0000U)
#define CSL_MSGMGR_REVISION_MODULE_ID_SHIFT                                    (0x00000010U)
#define CSL_MSGMGR_REVISION_MODULE_ID_MAX                                      (0x00000FFFU)

#define CSL_MSGMGR_REVISION_REVRTL_MASK                                        (0x0000F800U)
#define CSL_MSGMGR_REVISION_REVRTL_SHIFT                                       (0x0000000BU)
#define CSL_MSGMGR_REVISION_REVRTL_MAX                                         (0x0000001FU)

#define CSL_MSGMGR_REVISION_REVMAJ_MASK                                        (0x00000700U)
#define CSL_MSGMGR_REVISION_REVMAJ_SHIFT                                       (0x00000008U)
#define CSL_MSGMGR_REVISION_REVMAJ_MAX                                         (0x00000007U)

#define CSL_MSGMGR_REVISION_CUSTOM_MASK                                        (0x000000C0U)
#define CSL_MSGMGR_REVISION_CUSTOM_SHIFT                                       (0x00000006U)
#define CSL_MSGMGR_REVISION_CUSTOM_MAX                                         (0x00000003U)

#define CSL_MSGMGR_REVISION_REVMIN_MASK                                        (0x0000003FU)
#define CSL_MSGMGR_REVISION_REVMIN_SHIFT                                       (0x00000000U)
#define CSL_MSGMGR_REVISION_REVMIN_MAX                                         (0x0000003FU)

/* FREE_INTR_RAW_STAT */

#define CSL_MSGMGR_FREE_INTR_RAW_STAT_FREE_INDEX_ERR_MASK                      (0x00000001U)
#define CSL_MSGMGR_FREE_INTR_RAW_STAT_FREE_INDEX_ERR_SHIFT                     (0x00000000U)
#define CSL_MSGMGR_FREE_INTR_RAW_STAT_FREE_INDEX_ERR_MAX                       (0x00000001U)

/* FREE_INTR_ENABLED_STAT */

#define CSL_MSGMGR_FREE_INTR_ENABLED_STAT_ENABLED_FREE_INDEX_ERR_MASK          (0x00000001U)
#define CSL_MSGMGR_FREE_INTR_ENABLED_STAT_ENABLED_FREE_INDEX_ERR_SHIFT         (0x00000000U)
#define CSL_MSGMGR_FREE_INTR_ENABLED_STAT_ENABLED_FREE_INDEX_ERR_MAX           (0x00000001U)

/* FREE_INTR_ENABLE_SET */

#define CSL_MSGMGR_FREE_INTR_ENABLE_SET_INTR_ENABLE_SET_MASK                   (0x00000001U)
#define CSL_MSGMGR_FREE_INTR_ENABLE_SET_INTR_ENABLE_SET_SHIFT                  (0x00000000U)
#define CSL_MSGMGR_FREE_INTR_ENABLE_SET_INTR_ENABLE_SET_MAX                    (0x00000001U)

/* FREE_INTR_ENABLE_CLR */

#define CSL_MSGMGR_FREE_INTR_ENABLE_CLR_INTR_ENABLE_CLR_MASK                   (0x00000001U)
#define CSL_MSGMGR_FREE_INTR_ENABLE_CLR_INTR_ENABLE_CLR_SHIFT                  (0x00000000U)
#define CSL_MSGMGR_FREE_INTR_ENABLE_CLR_INTR_ENABLE_CLR_MAX                    (0x00000001U)

/* EOI */

#define CSL_MSGMGR_EOI_WR_MASK                                                 (0x0000FFFFU)
#define CSL_MSGMGR_EOI_WR_SHIFT                                                (0x00000000U)
#define CSL_MSGMGR_EOI_WR_MAX                                                  (0x0000FFFFU)

/* INTR_RAW_STAT0 */

#define CSL_MSGMGR_INTR_RAW_STAT0_INTR_MASK                                    (0xFFFFFFFFU)
#define CSL_MSGMGR_INTR_RAW_STAT0_INTR_SHIFT                                   (0x00000000U)
#define CSL_MSGMGR_INTR_RAW_STAT0_INTR_MAX                                     (0xFFFFFFFFU)

/* INTR_RAW_STAT1 */

#define CSL_MSGMGR_INTR_RAW_STAT1_INTR_MASK                                    (0xFFFFFFFFU)
#define CSL_MSGMGR_INTR_RAW_STAT1_INTR_SHIFT                                   (0x00000000U)
#define CSL_MSGMGR_INTR_RAW_STAT1_INTR_MAX                                     (0xFFFFFFFFU)

/* INTR_ENABLED_STAT0 */

#define CSL_MSGMGR_INTR_ENABLED_STAT0_ENABLED_INTR_MASK                        (0xFFFFFFFFU)
#define CSL_MSGMGR_INTR_ENABLED_STAT0_ENABLED_INTR_SHIFT                       (0x00000000U)
#define CSL_MSGMGR_INTR_ENABLED_STAT0_ENABLED_INTR_MAX                         (0xFFFFFFFFU)

/* INTR_ENABLED_STAT1 */

#define CSL_MSGMGR_INTR_ENABLED_STAT1_ENABLED_INTR_MASK                        (0xFFFFFFFFU)
#define CSL_MSGMGR_INTR_ENABLED_STAT1_ENABLED_INTR_SHIFT                       (0x00000000U)
#define CSL_MSGMGR_INTR_ENABLED_STAT1_ENABLED_INTR_MAX                         (0xFFFFFFFFU)

/* INTR_ENABLE_SET0 */

#define CSL_MSGMGR_INTR_ENABLE_SET0_INTR_ENABLE_SET_MASK                       (0xFFFFFFFFU)
#define CSL_MSGMGR_INTR_ENABLE_SET0_INTR_ENABLE_SET_SHIFT                      (0x00000000U)
#define CSL_MSGMGR_INTR_ENABLE_SET0_INTR_ENABLE_SET_MAX                        (0xFFFFFFFFU)

/* INTR_ENABLE_SET1 */

#define CSL_MSGMGR_INTR_ENABLE_SET1_INTR_ENABLE_SET_MASK                       (0xFFFFFFFFU)
#define CSL_MSGMGR_INTR_ENABLE_SET1_INTR_ENABLE_SET_SHIFT                      (0x00000000U)
#define CSL_MSGMGR_INTR_ENABLE_SET1_INTR_ENABLE_SET_MAX                        (0xFFFFFFFFU)

/* INTR_ENABLE_CLR0 */

#define CSL_MSGMGR_INTR_ENABLE_CLR0_INTR_ENABLE_CLR_MASK                       (0xFFFFFFFFU)
#define CSL_MSGMGR_INTR_ENABLE_CLR0_INTR_ENABLE_CLR_SHIFT                      (0x00000000U)
#define CSL_MSGMGR_INTR_ENABLE_CLR0_INTR_ENABLE_CLR_MAX                        (0xFFFFFFFFU)

/* INTR_ENABLE_CLR1 */

#define CSL_MSGMGR_INTR_ENABLE_CLR1_INTR_ENABLE_CLR_MASK                       (0xFFFFFFFFU)
#define CSL_MSGMGR_INTR_ENABLE_CLR1_INTR_ENABLE_CLR_SHIFT                      (0x00000000U)
#define CSL_MSGMGR_INTR_ENABLE_CLR1_INTR_ENABLE_CLR_MAX                        (0xFFFFFFFFU)

/* TRACE_CTL */

#define CSL_MSGMGR_TRACE_CTL_EN_MASK                                           (0x80000000U)
#define CSL_MSGMGR_TRACE_CTL_EN_SHIFT                                          (0x0000001FU)
#define CSL_MSGMGR_TRACE_CTL_EN_MAX                                            (0x00000001U)

#define CSL_MSGMGR_TRACE_CTL_ALL_QUEUES_MASK                                   (0x40000000U)
#define CSL_MSGMGR_TRACE_CTL_ALL_QUEUES_SHIFT                                  (0x0000001EU)
#define CSL_MSGMGR_TRACE_CTL_ALL_QUEUES_MAX                                    (0x00000001U)

#define CSL_MSGMGR_TRACE_CTL_MSG_MASK                                          (0x20000000U)
#define CSL_MSGMGR_TRACE_CTL_MSG_SHIFT                                         (0x0000001DU)
#define CSL_MSGMGR_TRACE_CTL_MSG_MAX                                           (0x00000001U)

#define CSL_MSGMGR_TRACE_CTL_QUEUE_MASK                                        (0x0000FFFFU)
#define CSL_MSGMGR_TRACE_CTL_QUEUE_SHIFT                                       (0x00000000U)
#define CSL_MSGMGR_TRACE_CTL_QUEUE_MAX                                         (0x0000FFFFU)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t QUEUE_S;                   /* Secure Queue Start Register */
    volatile uint32_t QUEUE_E;                   /* Secure Queue End Register */
    volatile uint32_t ITEM_POOL;                 /* Secure Pool Register */
} CSL_msgmgr_secRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MSGMGR_SEC_QUEUE_S                                                 (0x00000000U)
#define CSL_MSGMGR_SEC_QUEUE_E                                                 (0x00000004U)
#define CSL_MSGMGR_SEC_ITEM_POOL                                               (0x00000008U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* QUEUE_S */

#define CSL_MSGMGR_SEC_QUEUE_S_VAL_MASK                                        (0x0000FFFFU)
#define CSL_MSGMGR_SEC_QUEUE_S_VAL_SHIFT                                       (0x00000000U)
#define CSL_MSGMGR_SEC_QUEUE_S_VAL_MAX                                         (0x0000FFFFU)

/* QUEUE_E */

#define CSL_MSGMGR_SEC_QUEUE_E_VAL_MASK                                        (0x0000FFFFU)
#define CSL_MSGMGR_SEC_QUEUE_E_VAL_SHIFT                                       (0x00000000U)
#define CSL_MSGMGR_SEC_QUEUE_E_VAL_MAX                                         (0x0000FFFFU)

/* ITEM_POOL */

#define CSL_MSGMGR_SEC_ITEM_POOL_COUNT_MASK                                    (0x000000FFU)
#define CSL_MSGMGR_SEC_ITEM_POOL_COUNT_SHIFT                                   (0x00000000U)
#define CSL_MSGMGR_SEC_ITEM_POOL_COUNT_MAX                                     (0x000000FFU)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t MSG_DATA[2097152];         /* Message Data Register */
} CSL_msgmgr_qmifRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MSGMGR_QMIF_MSG_DATA(MSG_DATA)                                     (0x00000000U+((MSG_DATA)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* MSG_DATA */

#define CSL_MSGMGR_QMIF_MSG_DATA_VAL_MASK                                      (0xFFFFFFFFU)
#define CSL_MSGMGR_QMIF_MSG_DATA_VAL_SHIFT                                     (0x00000000U)
#define CSL_MSGMGR_QMIF_MSG_DATA_VAL_MAX                                       (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint64_t QSTATE[65536];             /* Queue State RAM Register */
} CSL_msgmgr_dispRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MSGMGR_DISP_QSTATE(QSTATE)                                         (0x00000000U+((QSTATE)*0x8U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* QSTATE */

#define CSL_MSGMGR_DISP_QSTATE_HEAD_INDEX_MASK                                 (0x000000000000FFFFU)
#define CSL_MSGMGR_DISP_QSTATE_HEAD_INDEX_SHIFT                                (0x0000000000000000U)
#define CSL_MSGMGR_DISP_QSTATE_HEAD_INDEX_MAX                                  (0x000000000000FFFFU)

#define CSL_MSGMGR_DISP_QSTATE_TAIL_INDEX_MASK                                 (0x00000000FFFF0000U)
#define CSL_MSGMGR_DISP_QSTATE_TAIL_INDEX_SHIFT                                (0x0000000000000010U)
#define CSL_MSGMGR_DISP_QSTATE_TAIL_INDEX_MAX                                  (0x000000000000FFFFU)

#define CSL_MSGMGR_DISP_QSTATE_ECNT_MASK                                       (0x0001FFFF00000000U)
#define CSL_MSGMGR_DISP_QSTATE_ECNT_SHIFT                                      (0x0000000000000020U)
#define CSL_MSGMGR_DISP_QSTATE_ECNT_MAX                                        (0x000000000001FFFFU)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t DATA[65536];               /* Linking RAM Register */
} CSL_msgmgr_lramRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MSGMGR_LRAM_DATA(DATA)                                             (0x00000000U+((DATA)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* DATA */

#define CSL_MSGMGR_LRAM_DATA_NEXT_INDEX_MASK                                   (0x0000FFFFU)
#define CSL_MSGMGR_LRAM_DATA_NEXT_INDEX_SHIFT                                  (0x00000000U)
#define CSL_MSGMGR_LRAM_DATA_NEXT_INDEX_MAX                                    (0x0000FFFFU)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t DATA[2097152];             /* Queue Data Register */
} CSL_msgmgr_queueRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MSGMGR_QUEUE_DATA(DATA)                                            (0x00000000U+((DATA)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* DATA */

#define CSL_MSGMGR_QUEUE_DATA_VAL_MASK                                         (0xFFFFFFFFU)
#define CSL_MSGMGR_QUEUE_DATA_VAL_SHIFT                                        (0x00000000U)
#define CSL_MSGMGR_QUEUE_DATA_VAL_MAX                                          (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t DATA[2097152];             /* Queue Data Register */
} CSL_msgmgr_qpeekRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MSGMGR_QPEEK_DATA(DATA)                                            (0x00000000U+((DATA)*0x4U))

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* DATA */

#define CSL_MSGMGR_QPEEK_DATA_VAL_MASK                                         (0xFFFFFFFFU)
#define CSL_MSGMGR_QPEEK_DATA_VAL_SHIFT                                        (0x00000000U)
#define CSL_MSGMGR_QPEEK_DATA_VAL_MAX                                          (0xFFFFFFFFU)

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t HEAD;                      /* Queue Divert to Head Register */
    volatile uint8_t  Resv_8[4];
    volatile uint32_t TAIL;                      /* Queue Divert to Tail Register */
} CSL_msgmgr_qdivertRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_MSGMGR_QDIVERT_HEAD                                                (0x00000000U)
#define CSL_MSGMGR_QDIVERT_TAIL                                                (0x00000008U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* HEAD */

#define CSL_MSGMGR_QDIVERT_HEAD_SRC_Q_MASK                                     (0x0000FFFFU)
#define CSL_MSGMGR_QDIVERT_HEAD_SRC_Q_SHIFT                                    (0x00000000U)
#define CSL_MSGMGR_QDIVERT_HEAD_SRC_Q_MAX                                      (0x0000FFFFU)

#define CSL_MSGMGR_QDIVERT_HEAD_DST_Q_MASK                                     (0xFFFF0000U)
#define CSL_MSGMGR_QDIVERT_HEAD_DST_Q_SHIFT                                    (0x00000010U)
#define CSL_MSGMGR_QDIVERT_HEAD_DST_Q_MAX                                      (0x0000FFFFU)

/* TAIL */

#define CSL_MSGMGR_QDIVERT_TAIL_SRC_Q_MASK                                     (0x0000FFFFU)
#define CSL_MSGMGR_QDIVERT_TAIL_SRC_Q_SHIFT                                    (0x00000000U)
#define CSL_MSGMGR_QDIVERT_TAIL_SRC_Q_MAX                                      (0x0000FFFFU)

#define CSL_MSGMGR_QDIVERT_TAIL_DST_Q_MASK                                     (0xFFFF0000U)
#define CSL_MSGMGR_QDIVERT_TAIL_DST_Q_SHIFT                                    (0x00000010U)
#define CSL_MSGMGR_QDIVERT_TAIL_DST_Q_MAX                                      (0x0000FFFFU)

#ifdef __cplusplus
}
#endif
#endif

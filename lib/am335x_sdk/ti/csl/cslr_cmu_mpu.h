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
#ifndef CSLR_CMUMPU_H_
#define CSLR_CMUMPU_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for RangeSet
**************************************************************************/
typedef struct {
    volatile Uint32 OPERATION;
    volatile Uint32 STARTPA;
    volatile Uint32 LENGTH;
    volatile Uint32 RANGESTATE;
} CSL_CmumpuRangesetRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 CONFIGREG;
    volatile Uint32 STSREG;
    volatile Uint32 INTRACK_S;
    volatile Uint32 INTRACK_NS;
    volatile Uint32 ALLOCATE;
    volatile Uint32 DEALLOCATE;
    volatile Uint32 NUMSECALLOC;
    volatile Uint32 DBG;
    volatile Uint8  RSVD0[4064];
    CSL_CmumpuRangesetRegs	RANGESET[64];
} CSL_CmuMpuRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* Cache Maintenance Unit Configuration Register */
#define CSL_CMUMPU_CONFIGREG                                    (0x0U)

/* CMU_MPU Status. */
#define CSL_CMUMPU_STSREG                                       (0x4U)

/* Interrupt Acknowledgement Register. Returns the index of the RangeSet that
 * caused the interrupt. An error bit indicates an error completion. Since
 * there is a queue of interrupt acknowledgements, there is also a valid bit
 * that indicates that there were no more interrupts on the queue. */
#define CSL_CMUMPU_INTRACK_S                                    (0x8U)

/* Interrupt Acknowledgement Register - Non-Secure Version. Returns the index
 * of the RangeSet that caused the interrupt. An error bit indicates an error
 * completion. Since there is a queue of interrupt acknowledgements, there is
 * also a valid bit that indicates that there were no more interrupts on the
 * queue. */
#define CSL_CMUMPU_INTRACK_NS                                   (0xCU)

/* Returns the index of a RangeSet in the Free state. */
#define CSL_CMUMPU_ALLOCATE                                     (0x10U)

/* An index stored to this register frees the RangeSet with that index. */
#define CSL_CMUMPU_DEALLOCATE                                   (0x14U)

/* NUMSECALLOC */
#define CSL_CMUMPU_NUMSECALLOC                                  (0x18U)

/* Debug register to configure how MSuspend from the various CPU's need to be
 * looked at by CMU_MPU to either send or not send traffic during debug
 * session. */
#define CSL_CMUMPU_DBG                                          (0x1CU)

/* Controls the operation of one RangeSet of the CMU_MPU. Storing this
 * register enqueues or activates the RangeSet. Note: must not write to any of
 * the rangeset registers if State != 0b00. That indicates that previous
 * values have not yet been transferred to the queue! */
#define CSL_CMUMPU_OPERATION(n)                                 (0x1000U + ((n) * (0x10U)))

/* Starting (lower, inclusive) 32-bit physical address. */
#define CSL_CMUMPU_STARTPA(n)                                   (0x1004U + ((n) * (0x10U)))

/* Length in bytes of the range - 1, giving a representable range of 1 byte to
 * 4k bytes. */
#define CSL_CMUMPU_LENGTH(n)                                    (0x1008U + ((n) * (0x10U)))

/* State of the Range Operation. Used to poll RangeSet for error or
 * completion. */
#define CSL_CMUMPU_RANGESTATE(n)                                (0x100CU + ((n) * (0x10U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CONFIGREG */

#define CSL_CMUMPU_CONFIGREG_LINESTEP_MASK                      (0x00000007U)
#define CSL_CMUMPU_CONFIGREG_LINESTEP_SHIFT                     (0U)
#define CSL_CMUMPU_CONFIGREG_LINESTEP_RESETVAL                  (0x00000004U)
#define CSL_CMUMPU_CONFIGREG_LINESTEP_LS4                       (0x00000000U)
#define CSL_CMUMPU_CONFIGREG_LINESTEP_LS8                       (0x00000001U)
#define CSL_CMUMPU_CONFIGREG_LINESTEP_LS16                      (0x00000002U)
#define CSL_CMUMPU_CONFIGREG_LINESTEP_LS32                      (0x00000003U)
#define CSL_CMUMPU_CONFIGREG_LINESTEP_LS64                      (0x00000004U)
#define CSL_CMUMPU_CONFIGREG_LINESTEP_LS128                     (0x00000005U)
#define CSL_CMUMPU_CONFIGREG_LINESTEP_LS256                     (0x00000006U)
#define CSL_CMUMPU_CONFIGREG_LINESTEP_LS512                     (0x00000007U)

#define CSL_CMUMPU_CONFIGREG_RES1_MASK                          (0x000000F0U)
#define CSL_CMUMPU_CONFIGREG_RES1_SHIFT                         (4U)
#define CSL_CMUMPU_CONFIGREG_RES1_RESETVAL                      (0x00000000U)
#define CSL_CMUMPU_CONFIGREG_RES1_MAX                           (0x0000000fU)

#define CSL_CMUMPU_CONFIGREG_INTEN_MASK                         (0x00000100U)
#define CSL_CMUMPU_CONFIGREG_INTEN_SHIFT                        (8U)
#define CSL_CMUMPU_CONFIGREG_INTEN_RESETVAL                     (0x00000000U)
#define CSL_CMUMPU_CONFIGREG_INTEN_MAX                          (0x00000001U)

#define CSL_CMUMPU_CONFIGREG_RES2_MASK                          (0x0000F800U)
#define CSL_CMUMPU_CONFIGREG_RES2_SHIFT                         (11U)
#define CSL_CMUMPU_CONFIGREG_RES2_RESETVAL                      (0x00000000U)
#define CSL_CMUMPU_CONFIGREG_RES2_MAX                           (0x0000001fU)

#define CSL_CMUMPU_CONFIGREG_QENTRIES_MASK                      (0x0FFF0000U)
#define CSL_CMUMPU_CONFIGREG_QENTRIES_SHIFT                     (16U)
#define CSL_CMUMPU_CONFIGREG_QENTRIES_RESETVAL                  (0x00000040U)
#define CSL_CMUMPU_CONFIGREG_QENTRIES_MAX                       (0x00000fffU)

#define CSL_CMUMPU_CONFIGREG_THREADS_MASK                       (0xF0000000U)
#define CSL_CMUMPU_CONFIGREG_THREADS_SHIFT                      (28U)
#define CSL_CMUMPU_CONFIGREG_THREADS_RESETVAL                   (0x00000001U)
#define CSL_CMUMPU_CONFIGREG_THREADS_MAX                        (0x0000000fU)

#define CSL_CMUMPU_CONFIGREG_DISABLEPARALLEL_MASK               (0x00000200U)
#define CSL_CMUMPU_CONFIGREG_DISABLEPARALLEL_SHIFT              (9U)
#define CSL_CMUMPU_CONFIGREG_DISABLEPARALLEL_RESETVAL           (0x00000001U)
#define CSL_CMUMPU_CONFIGREG_DISABLEPARALLEL_MAX                (0x00000001U)

#define CSL_CMUMPU_CONFIGREG_DISABLEPIPELINING_MASK             (0x00000400U)
#define CSL_CMUMPU_CONFIGREG_DISABLEPIPELINING_SHIFT            (10U)
#define CSL_CMUMPU_CONFIGREG_DISABLEPIPELINING_RESETVAL         (0x00000001U)
#define CSL_CMUMPU_CONFIGREG_DISABLEPIPELINING_MAX              (0x00000001U)

#define CSL_CMUMPU_CONFIGREG_ENNSWR_MASK                        (0x00000008U)
#define CSL_CMUMPU_CONFIGREG_ENNSWR_SHIFT                       (3U)
#define CSL_CMUMPU_CONFIGREG_ENNSWR_RESETVAL                    (0x00000000U)
#define CSL_CMUMPU_CONFIGREG_ENNSWR_MAX                         (0x00000001U)

#define CSL_CMUMPU_CONFIGREG_RESETVAL                           (0x10400604U)

/* STSREG */

#define CSL_CMUMPU_STSREG_BUSY_MASK                             (0x00000001U)
#define CSL_CMUMPU_STSREG_BUSY_SHIFT                            (0U)
#define CSL_CMUMPU_STSREG_BUSY_RESETVAL                         (0x00000000U)
#define CSL_CMUMPU_STSREG_BUSY_MAX                              (0x00000001U)

#define CSL_CMUMPU_STSREG_RES_MASK                              (0xFFFFFFFEU)
#define CSL_CMUMPU_STSREG_RES_SHIFT                             (1U)
#define CSL_CMUMPU_STSREG_RES_RESETVAL                          (0x00000000U)
#define CSL_CMUMPU_STSREG_RES_MAX                               (0x7fffffffU)

#define CSL_CMUMPU_STSREG_RESETVAL                              (0x00000000U)

/* INTRACK_S */

#define CSL_CMUMPU_INTRACK_S_IDX_MASK                           (0x00000FFFU)
#define CSL_CMUMPU_INTRACK_S_IDX_SHIFT                          (0U)
#define CSL_CMUMPU_INTRACK_S_IDX_RESETVAL                       (0x00000000U)
#define CSL_CMUMPU_INTRACK_S_IDX_MAX                            (0x00000fffU)

#define CSL_CMUMPU_INTRACK_S_RES2_MASK                          (0x7FFF0000U)
#define CSL_CMUMPU_INTRACK_S_RES2_SHIFT                         (16U)
#define CSL_CMUMPU_INTRACK_S_RES2_RESETVAL                      (0x00000000U)
#define CSL_CMUMPU_INTRACK_S_RES2_MAX                           (0x00007fffU)

#define CSL_CMUMPU_INTRACK_S_VALID_MASK                         (0x80000000U)
#define CSL_CMUMPU_INTRACK_S_VALID_SHIFT                        (31U)
#define CSL_CMUMPU_INTRACK_S_VALID_RESETVAL                     (0x00000000U)
#define CSL_CMUMPU_INTRACK_S_VALID_MAX                          (0x00000001U)

#define CSL_CMUMPU_INTRACK_S_ERROR_MASK                         (0x00008000U)
#define CSL_CMUMPU_INTRACK_S_ERROR_SHIFT                        (15U)
#define CSL_CMUMPU_INTRACK_S_ERROR_RESETVAL                     (0x00000000U)
#define CSL_CMUMPU_INTRACK_S_ERROR_MAX                          (0x00000001U)

#define CSL_CMUMPU_INTRACK_S_RES1_MASK                          (0x00007000U)
#define CSL_CMUMPU_INTRACK_S_RES1_SHIFT                         (12U)
#define CSL_CMUMPU_INTRACK_S_RES1_RESETVAL                      (0x00000000U)
#define CSL_CMUMPU_INTRACK_S_RES1_MAX                           (0x00000007U)

#define CSL_CMUMPU_INTRACK_S_RESETVAL                           (0x00000000U)

/* INTRACK_NS */

#define CSL_CMUMPU_INTRACK_NS_IDX_MASK                          (0x00000FFFU)
#define CSL_CMUMPU_INTRACK_NS_IDX_SHIFT                         (0U)
#define CSL_CMUMPU_INTRACK_NS_IDX_RESETVAL                      (0x00000000U)
#define CSL_CMUMPU_INTRACK_NS_IDX_MAX                           (0x00000fffU)

#define CSL_CMUMPU_INTRACK_NS_RES1_MASK                         (0x00007000U)
#define CSL_CMUMPU_INTRACK_NS_RES1_SHIFT                        (12U)
#define CSL_CMUMPU_INTRACK_NS_RES1_RESETVAL                     (0x00000000U)
#define CSL_CMUMPU_INTRACK_NS_RES1_MAX                          (0x00000007U)

#define CSL_CMUMPU_INTRACK_NS_ERROR_MASK                        (0x00008000U)
#define CSL_CMUMPU_INTRACK_NS_ERROR_SHIFT                       (15U)
#define CSL_CMUMPU_INTRACK_NS_ERROR_RESETVAL                    (0x00000000U)
#define CSL_CMUMPU_INTRACK_NS_ERROR_MAX                         (0x00000001U)

#define CSL_CMUMPU_INTRACK_NS_RES2_MASK                         (0x7FFF0000U)
#define CSL_CMUMPU_INTRACK_NS_RES2_SHIFT                        (16U)
#define CSL_CMUMPU_INTRACK_NS_RES2_RESETVAL                     (0x00000000U)
#define CSL_CMUMPU_INTRACK_NS_RES2_MAX                          (0x00007fffU)

#define CSL_CMUMPU_INTRACK_NS_VALID_MASK                        (0x80000000U)
#define CSL_CMUMPU_INTRACK_NS_VALID_SHIFT                       (31U)
#define CSL_CMUMPU_INTRACK_NS_VALID_RESETVAL                    (0x00000000U)
#define CSL_CMUMPU_INTRACK_NS_VALID_MAX                         (0x00000001U)

#define CSL_CMUMPU_INTRACK_NS_RESETVAL                          (0x00000000U)

/* ALLOCATE */

#define CSL_CMUMPU_ALLOCATE_IDX_MASK                            (0x000000FFU)
#define CSL_CMUMPU_ALLOCATE_IDX_SHIFT                           (0U)
#define CSL_CMUMPU_ALLOCATE_IDX_RESETVAL                        (0x00000000U)
#define CSL_CMUMPU_ALLOCATE_IDX_MAX                             (0x000000ffU)

#define CSL_CMUMPU_ALLOCATE_RES_MASK                            (0x7FFFFF00U)
#define CSL_CMUMPU_ALLOCATE_RES_SHIFT                           (8U)
#define CSL_CMUMPU_ALLOCATE_RES_RESETVAL                        (0x00000000U)
#define CSL_CMUMPU_ALLOCATE_RES_MAX                             (0x007fffffU)

#define CSL_CMUMPU_ALLOCATE_NONE_MASK                           (0x80000000U)
#define CSL_CMUMPU_ALLOCATE_NONE_SHIFT                          (31U)
#define CSL_CMUMPU_ALLOCATE_NONE_RESETVAL                       (0x00000000U)
#define CSL_CMUMPU_ALLOCATE_NONE_MAX                            (0x00000001U)

#define CSL_CMUMPU_ALLOCATE_RESETVAL                            (0x00000000U)

/* DEALLOCATE */

#define CSL_CMUMPU_DEALLOCATE_IDX_MASK                          (0x000000FFU)
#define CSL_CMUMPU_DEALLOCATE_IDX_SHIFT                         (0U)
#define CSL_CMUMPU_DEALLOCATE_IDX_RESETVAL                      (0x00000000U)
#define CSL_CMUMPU_DEALLOCATE_IDX_MAX                           (0x000000ffU)

#define CSL_CMUMPU_DEALLOCATE_RES_MASK                          (0xFFFFFF00U)
#define CSL_CMUMPU_DEALLOCATE_RES_SHIFT                         (8U)
#define CSL_CMUMPU_DEALLOCATE_RES_RESETVAL                      (0x00000000U)
#define CSL_CMUMPU_DEALLOCATE_RES_MAX                           (0x00ffffffU)

#define CSL_CMUMPU_DEALLOCATE_RESETVAL                          (0x00000000U)

/* NUMSECALLOC */

#define CSL_CMUMPU_NUMSECALLOC_NUMSEC_MASK                      (0x0000000FU)
#define CSL_CMUMPU_NUMSECALLOC_NUMSEC_SHIFT                     (0U)
#define CSL_CMUMPU_NUMSECALLOC_NUMSEC_RESETVAL                  (0x00000008U)
#define CSL_CMUMPU_NUMSECALLOC_NUMSEC_MAX                       (0x0000000fU)

#define CSL_CMUMPU_NUMSECALLOC_RES_MASK                         (0xFFFFFFF0U)
#define CSL_CMUMPU_NUMSECALLOC_RES_SHIFT                        (4U)
#define CSL_CMUMPU_NUMSECALLOC_RES_RESETVAL                     (0x00000000U)
#define CSL_CMUMPU_NUMSECALLOC_RES_MAX                          (0x0fffffffU)

#define CSL_CMUMPU_NUMSECALLOC_RESETVAL                         (0x00000008U)

/* DBG */

#define CSL_CMUMPU_DBG_CPU_MSUSPEND_MASK                        (0x00000003U)
#define CSL_CMUMPU_DBG_CPU_MSUSPEND_SHIFT                       (0U)
#define CSL_CMUMPU_DBG_CPU_MSUSPEND_RESETVAL                    (0x00000000U)
#define CSL_CMUMPU_DBG_CPU_MSUSPEND_MAX                         (0x00000003U)

#define CSL_CMUMPU_DBG_SPEC_MSUSPEND_MASK                       (0x00000004U)
#define CSL_CMUMPU_DBG_SPEC_MSUSPEND_SHIFT                      (2U)
#define CSL_CMUMPU_DBG_SPEC_MSUSPEND_RESETVAL                   (0x00000000U)
#define CSL_CMUMPU_DBG_SPEC_MSUSPEND_MAX                        (0x00000001U)

#define CSL_CMUMPU_DBG_OR_MSUSPEND_MASK                         (0x00000008U)
#define CSL_CMUMPU_DBG_OR_MSUSPEND_SHIFT                        (3U)
#define CSL_CMUMPU_DBG_OR_MSUSPEND_RESETVAL                     (0x00000000U)
#define CSL_CMUMPU_DBG_OR_MSUSPEND_MAX                          (0x00000001U)

#define CSL_CMUMPU_DBG_AND_MSUSPEND_MASK                        (0x00000010U)
#define CSL_CMUMPU_DBG_AND_MSUSPEND_SHIFT                       (4U)
#define CSL_CMUMPU_DBG_AND_MSUSPEND_RESETVAL                    (0x00000000U)
#define CSL_CMUMPU_DBG_AND_MSUSPEND_MAX                         (0x00000001U)

#define CSL_CMUMPU_DBG_RESETVAL                                 (0x00000000U)

/* OPERATION */

#define CSL_CMUMPU_OPERATION_OPNSEL_MASK                        (0x0000000FU)
#define CSL_CMUMPU_OPERATION_OPNSEL_SHIFT                       (0U)
#define CSL_CMUMPU_OPERATION_OPNSEL_RESETVAL                    (0x00000000U)
#define CSL_CMUMPU_OPERATION_OPNSEL_MAX                         (0x0000000fU)

#define CSL_CMUMPU_OPERATION_RES_MASK                           (0x00000070U)
#define CSL_CMUMPU_OPERATION_RES_SHIFT                          (4U)
#define CSL_CMUMPU_OPERATION_RES_RESETVAL                       (0x00000000U)
#define CSL_CMUMPU_OPERATION_RES_MAX                            (0x00000007U)

#define CSL_CMUMPU_OPERATION_WAIT_MASK                          (0x00000100U)
#define CSL_CMUMPU_OPERATION_WAIT_SHIFT                         (8U)
#define CSL_CMUMPU_OPERATION_WAIT_RESETVAL                      (0x00000000U)
#define CSL_CMUMPU_OPERATION_WAIT_MAX                           (0x00000001U)

#define CSL_CMUMPU_OPERATION_COMPLETION_MASK                    (0x00000600U)
#define CSL_CMUMPU_OPERATION_COMPLETION_SHIFT                   (9U)
#define CSL_CMUMPU_OPERATION_COMPLETION_RESETVAL                (0x00000000U)
#define CSL_CMUMPU_OPERATION_COMPLETION_NONE                    (0x00000000U)
#define CSL_CMUMPU_OPERATION_COMPLETION_INTERRUPT               (0x00000001U)
#define CSL_CMUMPU_OPERATION_COMPLETION_ERRORINTR               (0x00000002U)
#define CSL_CMUMPU_OPERATION_COMPLETION_RES3                    (0x00000003U)

#define CSL_CMUMPU_OPERATION_RES1_MASK                          (0x00007800U)
#define CSL_CMUMPU_OPERATION_RES1_SHIFT                         (11U)
#define CSL_CMUMPU_OPERATION_RES1_RESETVAL                      (0x00000000U)
#define CSL_CMUMPU_OPERATION_RES1_MAX                           (0x0000000fU)

#define CSL_CMUMPU_OPERATION_NS_MASK                            (0x80000000U)
#define CSL_CMUMPU_OPERATION_NS_SHIFT                           (31U)
#define CSL_CMUMPU_OPERATION_NS_RESETVAL                        (0x00000000U)
#define CSL_CMUMPU_OPERATION_NS_MAX                             (0x00000001U)

#define CSL_CMUMPU_OPERATION_FORCE_WRNP_MASK                    (0x00000080U)
#define CSL_CMUMPU_OPERATION_FORCE_WRNP_SHIFT                   (7U)
#define CSL_CMUMPU_OPERATION_FORCE_WRNP_RESETVAL                (0x00000000U)
#define CSL_CMUMPU_OPERATION_FORCE_WRNP_MAX                     (0x00000001U)

#define CSL_CMUMPU_OPERATION_HIGHADDREN_MASK                    (0x00008000U)
#define CSL_CMUMPU_OPERATION_HIGHADDREN_SHIFT                   (15U)
#define CSL_CMUMPU_OPERATION_HIGHADDREN_RESETVAL                (0x00000000U)
#define CSL_CMUMPU_OPERATION_HIGHADDREN_MAX                     (0x00000001U)

#define CSL_CMUMPU_OPERATION_HIGHADDR_MASK                      (0x00FF0000U)
#define CSL_CMUMPU_OPERATION_HIGHADDR_SHIFT                     (16U)
#define CSL_CMUMPU_OPERATION_HIGHADDR_RESETVAL                  (0x00000000U)
#define CSL_CMUMPU_OPERATION_HIGHADDR_MAX                       (0x000000ffU)

#define CSL_CMUMPU_OPERATION_RESETVAL                           (0x00000000U)

/* STARTPA */

#define CSL_CMUMPU_STARTPA_STARTPA_MASK                         (0xFFFFFFFFU)
#define CSL_CMUMPU_STARTPA_STARTPA_SHIFT                        (0U)
#define CSL_CMUMPU_STARTPA_STARTPA_RESETVAL                     (0x00000000U)
#define CSL_CMUMPU_STARTPA_STARTPA_MAX                          (0xffffffffU)

#define CSL_CMUMPU_STARTPA_RESETVAL                             (0x00000000U)

/* LENGTH */

#define CSL_CMUMPU_LENGTH_LEN_MASK                              (0x00000FFFU)
#define CSL_CMUMPU_LENGTH_LEN_SHIFT                             (0U)
#define CSL_CMUMPU_LENGTH_LEN_RESETVAL                          (0x00000000U)
#define CSL_CMUMPU_LENGTH_LEN_MAX                               (0x00000fffU)

#define CSL_CMUMPU_LENGTH_RES_MASK                              (0xFFFFF000U)
#define CSL_CMUMPU_LENGTH_RES_SHIFT                             (12U)
#define CSL_CMUMPU_LENGTH_RES_RESETVAL                          (0x00000000U)
#define CSL_CMUMPU_LENGTH_RES_MAX                               (0x000fffffU)

#define CSL_CMUMPU_LENGTH_RESETVAL                              (0x00000000U)

/* RANGESTATE */

#define CSL_CMUMPU_RANGESTATE_STATE_MASK                        (0xE0000000U)
#define CSL_CMUMPU_RANGESTATE_STATE_SHIFT                       (29U)
#define CSL_CMUMPU_RANGESTATE_STATE_RESETVAL                    (0x00000000U)
#define CSL_CMUMPU_RANGESTATE_STATE_ALLOCATED                   (0x00000001U)
#define CSL_CMUMPU_RANGESTATE_STATE_ACTIVE                      (0x00000003U)
#define CSL_CMUMPU_RANGESTATE_STATE_COMPLETE                    (0x00000006U)
#define CSL_CMUMPU_RANGESTATE_STATE_ERROR                       (0x00000007U)
#define CSL_CMUMPU_RANGESTATE_STATE_RES4                        (0x00000004U)
#define CSL_CMUMPU_RANGESTATE_STATE_RES5                        (0x00000005U)
#define CSL_CMUMPU_RANGESTATE_STATE_FREE                        (0x00000000U)

#define CSL_CMUMPU_RANGESTATE_RES_MASK                          (0x1FFFFFFFU)
#define CSL_CMUMPU_RANGESTATE_RES_SHIFT                         (0U)
#define CSL_CMUMPU_RANGESTATE_RES_RESETVAL                      (0x00000000U)
#define CSL_CMUMPU_RANGESTATE_RES_MAX                           (0x1fffffffU)

#define CSL_CMUMPU_RANGESTATE_RESETVAL                          (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif

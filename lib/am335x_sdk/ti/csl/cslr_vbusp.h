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
#ifndef CSLR_VBUSP_H_
#define CSLR_VBUSP_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for registers
**************************************************************************/
typedef struct {
    volatile Uint32 PID;
    volatile Uint8  RSVD0[12];
    volatile Uint32 WFIFOCTL;
    volatile Uint32 WFIFOSTS;
    volatile Uint32 RFIFOCTL;
    volatile Uint32 RFIFOSTS;
} CSL_VbuspRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Peripheral Identification Register */
#define CSL_VBUSP_PID                                           (0x0U)

/* Write FIFO control register */
#define CSL_VBUSP_WFIFOCTL                                      (0x10U)

/* Write FIFO status register */
#define CSL_VBUSP_WFIFOSTS                                      (0x14U)

/* Read FIFO control register */
#define CSL_VBUSP_RFIFOCTL                                      (0x18U)

/* Read FIFO status register */
#define CSL_VBUSP_RFIFOSTS                                      (0x1CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PID */

#define CSL_VBUSP_PID_MINOR_MASK                                (0x0000003FU)
#define CSL_VBUSP_PID_MINOR_SHIFT                               (0U)
#define CSL_VBUSP_PID_MINOR_RESETVAL                            (0x00000000U)
#define CSL_VBUSP_PID_MINOR_MAX                                 (0x0000003fU)

#define CSL_VBUSP_PID_CUSTOM_MASK                               (0x000000C0U)
#define CSL_VBUSP_PID_CUSTOM_SHIFT                              (6U)
#define CSL_VBUSP_PID_CUSTOM_RESETVAL                           (0x00000000U)
#define CSL_VBUSP_PID_CUSTOM_MAX                                (0x00000003U)

#define CSL_VBUSP_PID_MAJOR_MASK                                (0x00000700U)
#define CSL_VBUSP_PID_MAJOR_SHIFT                               (8U)
#define CSL_VBUSP_PID_MAJOR_RESETVAL                            (0x00000000U)
#define CSL_VBUSP_PID_MAJOR_MAX                                 (0x00000007U)

#define CSL_VBUSP_PID_RTL_MASK                                  (0x0000F800U)
#define CSL_VBUSP_PID_RTL_SHIFT                                 (11U)
#define CSL_VBUSP_PID_RTL_RESETVAL                              (0x00000000U)
#define CSL_VBUSP_PID_RTL_MAX                                   (0x0000001fU)

#define CSL_VBUSP_PID_FUNC_MASK                                 (0x0FFF0000U)
#define CSL_VBUSP_PID_FUNC_SHIFT                                (16U)
#define CSL_VBUSP_PID_FUNC_RESETVAL                             (0x00000431U)
#define CSL_VBUSP_PID_FUNC_MAX                                  (0x00000fffU)

#define CSL_VBUSP_PID_SCHEME_MASK                               (0xC0000000U)
#define CSL_VBUSP_PID_SCHEME_SHIFT                              (30U)
#define CSL_VBUSP_PID_SCHEME_RESETVAL                           (0x00000001U)
#define CSL_VBUSP_PID_SCHEME_MAX                                (0x00000003U)

#define CSL_VBUSP_PID_RESETVAL                                  (0x44310000U)

/* WFIFOCTL */

#define CSL_VBUSP_WFIFOCTL_WNUM_DMA_MASK                        (0x000000FFU)
#define CSL_VBUSP_WFIFOCTL_WNUM_DMA_SHIFT                       (0U)
#define CSL_VBUSP_WFIFOCTL_WNUM_DMA_RESETVAL                    (0x00000004U)
#define CSL_VBUSP_WFIFOCTL_WNUM_DMA_MAX                         (0x000000ffU)

#define CSL_VBUSP_WFIFOCTL_WNUM_EVT_MASK                        (0x0000FF00U)
#define CSL_VBUSP_WFIFOCTL_WNUM_EVT_SHIFT                       (8U)
#define CSL_VBUSP_WFIFOCTL_WNUM_EVT_RESETVAL                    (0x00000010U)
#define CSL_VBUSP_WFIFOCTL_WNUM_EVT_MAX                         (0x000000ffU)

#define CSL_VBUSP_WFIFOCTL_WENA_MASK                            (0x00010000U)
#define CSL_VBUSP_WFIFOCTL_WENA_SHIFT                           (16U)
#define CSL_VBUSP_WFIFOCTL_WENA_RESETVAL                        (0x00000000U)
#define CSL_VBUSP_WFIFOCTL_WENA_DISABLE                         (0x00000000U)
#define CSL_VBUSP_WFIFOCTL_WENA_ENABLE                          (0x00000001U)

#define CSL_VBUSP_WFIFOCTL_RESETVAL                             (0x00001004U)

/* WFIFOSTS */

#define CSL_VBUSP_WFIFOSTS_WLVL_MASK                            (0x000000FFU)
#define CSL_VBUSP_WFIFOSTS_WLVL_SHIFT                           (0U)
#define CSL_VBUSP_WFIFOSTS_WLVL_RESETVAL                        (0x00000000U)
#define CSL_VBUSP_WFIFOSTS_WLVL_MAX                             (0x000000ffU)

#define CSL_VBUSP_WFIFOSTS_RESETVAL                             (0x00000000U)

/* RFIFOCTL */

#define CSL_VBUSP_RFIFOCTL_RNUM_DMA_MASK                        (0x000000FFU)
#define CSL_VBUSP_RFIFOCTL_RNUM_DMA_SHIFT                       (0U)
#define CSL_VBUSP_RFIFOCTL_RNUM_DMA_RESETVAL                    (0x00000004U)
#define CSL_VBUSP_RFIFOCTL_RNUM_DMA_MAX                         (0x000000ffU)

#define CSL_VBUSP_RFIFOCTL_RNUM_EVT_MASK                        (0x0000FF00U)
#define CSL_VBUSP_RFIFOCTL_RNUM_EVT_SHIFT                       (8U)
#define CSL_VBUSP_RFIFOCTL_RNUM_EVT_RESETVAL                    (0x00000010U)
#define CSL_VBUSP_RFIFOCTL_RNUM_EVT_MAX                         (0x000000ffU)

#define CSL_VBUSP_RFIFOCTL_RENA_MASK                            (0x00010000U)
#define CSL_VBUSP_RFIFOCTL_RENA_SHIFT                           (16U)
#define CSL_VBUSP_RFIFOCTL_RENA_RESETVAL                        (0x00000000U)
#define CSL_VBUSP_RFIFOCTL_RENA_DISABLE                         (0x00000000U)
#define CSL_VBUSP_RFIFOCTL_RENA_ENABLE                          (0x00000001U)

#define CSL_VBUSP_RFIFOCTL_RESETVAL                             (0x00001004U)

/* RFIFOSTS */

#define CSL_VBUSP_RFIFOSTS_RLVL_MASK                            (0x000000FFU)
#define CSL_VBUSP_RFIFOSTS_RLVL_SHIFT                           (0U)
#define CSL_VBUSP_RFIFOSTS_RLVL_RESETVAL                        (0x00000000U)
#define CSL_VBUSP_RFIFOSTS_RLVL_MAX                             (0x000000ffU)

#define CSL_VBUSP_RFIFOSTS_RESETVAL                             (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif

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
#ifndef CSLR_TETRISVBUSP_H_
#define CSLR_TETRISVBUSP_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for tetris_vbuspaddressBlockTable
**************************************************************************/
typedef struct {
    volatile Uint32 TETRIS_PID;
    volatile Uint32 TETRIS_INTC_PID;
    volatile Uint8  RSVD0[12];
    volatile Uint32 STM_DISABLE;
    volatile Uint8  RSVD1[1000];
    volatile Uint32 PD_CPU0_PTCMD;
    volatile Uint32 PD_CPU0_PDSTAT;
    volatile Uint32 PD_CPU0_PDCTL;
    volatile Uint32 PD_CPU1_PTCMD;
    volatile Uint32 PD_CPU1_PDSTAT;
    volatile Uint32 PD_CPU1_PDCTL;
    volatile Uint32 PD_CPU2_PTCMD;
    volatile Uint32 PD_CPU2_PDSTAT;
    volatile Uint32 PD_CPU2_PDCTL;
    volatile Uint32 PD_CPU3_PTCMD;
    volatile Uint32 PD_CPU3_PDSTAT;
    volatile Uint32 PD_CPU3_PDCTL;
} CSL_TetrisVbuspRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Peripheral Identification Register for Tetris */
#define CSL_TETRISVBUSP_TETRIS_PID                              (0x0U)

/* Peripheral Identification Register for Tetris Intc */
#define CSL_TETRISVBUSP_TETRIS_INTC_PID                         (0x4U)

/* Disable access to STM in Tetris */
#define CSL_TETRISVBUSP_STM_DISABLE                             (0x14U)

/* Power domain transition command for CPU0 */
#define CSL_TETRISVBUSP_PD_CPU0_PTCMD                           (0x400U)

/* Power domain Status for CPU0 */
#define CSL_TETRISVBUSP_PD_CPU0_PDSTAT                          (0x404U)

/* Power domain Control for CPU0 */
#define CSL_TETRISVBUSP_PD_CPU0_PDCTL                           (0x408U)

/* Power domain transition command for CPU1 */
#define CSL_TETRISVBUSP_PD_CPU1_PTCMD                           (0x40CU)

/* Power domain Status for CPU1 */
#define CSL_TETRISVBUSP_PD_CPU1_PDSTAT                          (0x410U)

/* Power domain Control for CPU1 */
#define CSL_TETRISVBUSP_PD_CPU1_PDCTL                           (0x414U)

/* Power domain transition command for CPU2 */
#define CSL_TETRISVBUSP_PD_CPU2_PTCMD                           (0x418U)

/* Power domain Status for CPU2 */
#define CSL_TETRISVBUSP_PD_CPU2_PDSTAT                          (0x41CU)

/* Power domain Control for CPU2 */
#define CSL_TETRISVBUSP_PD_CPU2_PDCTL                           (0x420U)

/* Power domain transition command for CPU3 */
#define CSL_TETRISVBUSP_PD_CPU3_PTCMD                           (0x424U)

/* Power domain Status for CPU3 */
#define CSL_TETRISVBUSP_PD_CPU3_PDSTAT                          (0x428U)

/* Power domain Control for CPU3 */
#define CSL_TETRISVBUSP_PD_CPU3_PDCTL                           (0x42CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* TETRIS_PID */

#define CSL_TETRISVBUSP_TETRIS_PID_PID_MASK                     (0xFFFFFFFFU)
#define CSL_TETRISVBUSP_TETRIS_PID_PID_SHIFT                    (0U)
#define CSL_TETRISVBUSP_TETRIS_PID_PID_RESETVAL                 (0x44900900U)
#define CSL_TETRISVBUSP_TETRIS_PID_PID_MAX                      (0xffffffffU)

#define CSL_TETRISVBUSP_TETRIS_PID_RESETVAL                     (0x44900900U)

/* TETRIS_INTC_PID */

#define CSL_TETRISVBUSP_TETRIS_INTC_PID_PID_MASK                (0xFFFFFFFFU)
#define CSL_TETRISVBUSP_TETRIS_INTC_PID_PID_SHIFT               (0U)
#define CSL_TETRISVBUSP_TETRIS_INTC_PID_PID_RESETVAL            (0x44910900U)
#define CSL_TETRISVBUSP_TETRIS_INTC_PID_PID_MAX                 (0xffffffffU)

#define CSL_TETRISVBUSP_TETRIS_INTC_PID_RESETVAL                (0x44910900U)

/* STM_DISABLE */

#define CSL_TETRISVBUSP_STM_DISABLE_STM_DISABLE_MASK            (0xFFFFFFFFU)
#define CSL_TETRISVBUSP_STM_DISABLE_STM_DISABLE_SHIFT           (0U)
#define CSL_TETRISVBUSP_STM_DISABLE_STM_DISABLE_RESETVAL        (0x00000000U)
#define CSL_TETRISVBUSP_STM_DISABLE_STM_DISABLE_MAX             (0xffffffffU)

#define CSL_TETRISVBUSP_STM_DISABLE_RESETVAL                    (0x00000000U)

/* PD_CPU0_PTCMD */

#define CSL_TETRISVBUSP_PD_CPU0_PTCMD_GO_CPU_MASK               (0x00000001U)
#define CSL_TETRISVBUSP_PD_CPU0_PTCMD_GO_CPU_SHIFT              (0U)
#define CSL_TETRISVBUSP_PD_CPU0_PTCMD_GO_CPU_RESETVAL           (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU0_PTCMD_GO_CPU_MAX                (0x00000001U)

#define CSL_TETRISVBUSP_PD_CPU0_PTCMD_RESETVAL                  (0x00000000U)

/* PD_CPU0_PDSTAT */

#define CSL_TETRISVBUSP_PD_CPU0_PDSTAT_NEXT_CPU_MASK            (0x00000003U)
#define CSL_TETRISVBUSP_PD_CPU0_PDSTAT_NEXT_CPU_SHIFT           (0U)
#define CSL_TETRISVBUSP_PD_CPU0_PDSTAT_NEXT_CPU_RESETVAL        (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU0_PDSTAT_NEXT_CPU_MAX             (0x00000003U)

#define CSL_TETRISVBUSP_PD_CPU0_PDSTAT_DOMAIN_STATE_MASK        (0x00070000U)
#define CSL_TETRISVBUSP_PD_CPU0_PDSTAT_DOMAIN_STATE_SHIFT       (16U)
#define CSL_TETRISVBUSP_PD_CPU0_PDSTAT_DOMAIN_STATE_RESETVAL    (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU0_PDSTAT_DOMAIN_STATE_MAX         (0x00000007U)

#define CSL_TETRISVBUSP_PD_CPU0_PDSTAT_RESETVAL                 (0x00000000U)

/* PD_CPU0_PDCTL */

#define CSL_TETRISVBUSP_PD_CPU0_PDCTL_NEXT_CPU_MASK             (0x00000003U)
#define CSL_TETRISVBUSP_PD_CPU0_PDCTL_NEXT_CPU_SHIFT            (0U)
#define CSL_TETRISVBUSP_PD_CPU0_PDCTL_NEXT_CPU_RESETVAL         (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU0_PDCTL_NEXT_CPU_MAX              (0x00000003U)

#define CSL_TETRISVBUSP_PD_CPU0_PDCTL_RESETVAL                  (0x00000000U)

/* PD_CPU1_PTCMD */

#define CSL_TETRISVBUSP_PD_CPU1_PTCMD_GO_CPU_MASK               (0x00000001U)
#define CSL_TETRISVBUSP_PD_CPU1_PTCMD_GO_CPU_SHIFT              (0U)
#define CSL_TETRISVBUSP_PD_CPU1_PTCMD_GO_CPU_RESETVAL           (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU1_PTCMD_GO_CPU_MAX                (0x00000001U)

#define CSL_TETRISVBUSP_PD_CPU1_PTCMD_RESETVAL                  (0x00000000U)

/* PD_CPU1_PDSTAT */

#define CSL_TETRISVBUSP_PD_CPU1_PDSTAT_NEXT_CPU_MASK            (0x00000003U)
#define CSL_TETRISVBUSP_PD_CPU1_PDSTAT_NEXT_CPU_SHIFT           (0U)
#define CSL_TETRISVBUSP_PD_CPU1_PDSTAT_NEXT_CPU_RESETVAL        (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU1_PDSTAT_NEXT_CPU_MAX             (0x00000003U)

#define CSL_TETRISVBUSP_PD_CPU1_PDSTAT_DOMAIN_STATE_MASK        (0x00070000U)
#define CSL_TETRISVBUSP_PD_CPU1_PDSTAT_DOMAIN_STATE_SHIFT       (16U)
#define CSL_TETRISVBUSP_PD_CPU1_PDSTAT_DOMAIN_STATE_RESETVAL    (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU1_PDSTAT_DOMAIN_STATE_MAX         (0x00000007U)

#define CSL_TETRISVBUSP_PD_CPU1_PDSTAT_RESETVAL                 (0x00000000U)

/* PD_CPU1_PDCTL */

#define CSL_TETRISVBUSP_PD_CPU1_PDCTL_NEXT_CPU_MASK             (0x00000003U)
#define CSL_TETRISVBUSP_PD_CPU1_PDCTL_NEXT_CPU_SHIFT            (0U)
#define CSL_TETRISVBUSP_PD_CPU1_PDCTL_NEXT_CPU_RESETVAL         (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU1_PDCTL_NEXT_CPU_MAX              (0x00000003U)

#define CSL_TETRISVBUSP_PD_CPU1_PDCTL_RESETVAL                  (0x00000000U)

/* PD_CPU2_PTCMD */

#define CSL_TETRISVBUSP_PD_CPU2_PTCMD_GO_CPU_MASK               (0x00000001U)
#define CSL_TETRISVBUSP_PD_CPU2_PTCMD_GO_CPU_SHIFT              (0U)
#define CSL_TETRISVBUSP_PD_CPU2_PTCMD_GO_CPU_RESETVAL           (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU2_PTCMD_GO_CPU_MAX                (0x00000001U)

#define CSL_TETRISVBUSP_PD_CPU2_PTCMD_RESETVAL                  (0x00000000U)

/* PD_CPU2_PDSTAT */

#define CSL_TETRISVBUSP_PD_CPU2_PDSTAT_NEXT_CPU_MASK            (0x00000003U)
#define CSL_TETRISVBUSP_PD_CPU2_PDSTAT_NEXT_CPU_SHIFT           (0U)
#define CSL_TETRISVBUSP_PD_CPU2_PDSTAT_NEXT_CPU_RESETVAL        (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU2_PDSTAT_NEXT_CPU_MAX             (0x00000003U)

#define CSL_TETRISVBUSP_PD_CPU2_PDSTAT_DOMAIN_STATE_MASK        (0x00070000U)
#define CSL_TETRISVBUSP_PD_CPU2_PDSTAT_DOMAIN_STATE_SHIFT       (16U)
#define CSL_TETRISVBUSP_PD_CPU2_PDSTAT_DOMAIN_STATE_RESETVAL    (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU2_PDSTAT_DOMAIN_STATE_MAX         (0x00000007U)

#define CSL_TETRISVBUSP_PD_CPU2_PDSTAT_RESETVAL                 (0x00000000U)

/* PD_CPU2_PDCTL */

#define CSL_TETRISVBUSP_PD_CPU2_PDCTL_NEXT_CPU_MASK             (0x00000003U)
#define CSL_TETRISVBUSP_PD_CPU2_PDCTL_NEXT_CPU_SHIFT            (0U)
#define CSL_TETRISVBUSP_PD_CPU2_PDCTL_NEXT_CPU_RESETVAL         (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU2_PDCTL_NEXT_CPU_MAX              (0x00000003U)

#define CSL_TETRISVBUSP_PD_CPU2_PDCTL_RESETVAL                  (0x00000000U)

/* PD_CPU3_PTCMD */

#define CSL_TETRISVBUSP_PD_CPU3_PTCMD_GO_CPU_MASK               (0x00000001U)
#define CSL_TETRISVBUSP_PD_CPU3_PTCMD_GO_CPU_SHIFT              (0U)
#define CSL_TETRISVBUSP_PD_CPU3_PTCMD_GO_CPU_RESETVAL           (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU3_PTCMD_GO_CPU_MAX                (0x00000001U)

#define CSL_TETRISVBUSP_PD_CPU3_PTCMD_RESETVAL                  (0x00000000U)

/* PD_CPU3_PDSTAT */

#define CSL_TETRISVBUSP_PD_CPU3_PDSTAT_NEXT_CPU_MASK            (0x00000003U)
#define CSL_TETRISVBUSP_PD_CPU3_PDSTAT_NEXT_CPU_SHIFT           (0U)
#define CSL_TETRISVBUSP_PD_CPU3_PDSTAT_NEXT_CPU_RESETVAL        (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU3_PDSTAT_NEXT_CPU_MAX             (0x00000003U)

#define CSL_TETRISVBUSP_PD_CPU3_PDSTAT_DOMAIN_STATE_MASK        (0x00070000U)
#define CSL_TETRISVBUSP_PD_CPU3_PDSTAT_DOMAIN_STATE_SHIFT       (16U)
#define CSL_TETRISVBUSP_PD_CPU3_PDSTAT_DOMAIN_STATE_RESETVAL    (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU3_PDSTAT_DOMAIN_STATE_MAX         (0x00000007U)

#define CSL_TETRISVBUSP_PD_CPU3_PDSTAT_RESETVAL                 (0x00000000U)

/* PD_CPU3_PDCTL */

#define CSL_TETRISVBUSP_PD_CPU3_PDCTL_NEXT_CPU_MASK             (0x00000003U)
#define CSL_TETRISVBUSP_PD_CPU3_PDCTL_NEXT_CPU_SHIFT            (0U)
#define CSL_TETRISVBUSP_PD_CPU3_PDCTL_NEXT_CPU_RESETVAL         (0x00000000U)
#define CSL_TETRISVBUSP_PD_CPU3_PDCTL_NEXT_CPU_MAX              (0x00000003U)

#define CSL_TETRISVBUSP_PD_CPU3_PDCTL_RESETVAL                  (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif

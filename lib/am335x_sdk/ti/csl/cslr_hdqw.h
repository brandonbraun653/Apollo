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
#ifndef CSLR_HDQW_H_
#define CSLR_HDQW_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint32 TX_DATA;
    volatile Uint32 RX_DATA;
    volatile Uint32 CTRL_STS;
    volatile Uint32 INT_STS;
    volatile Uint32 SYSCONFIG;
    volatile Uint32 SYSSTS;
} CSL_HdqwRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register contains the IP revision code */
#define CSL_HDQW_REVISION                                       (0x0U)

/* This register contains the data to be transmitted. */
#define CSL_HDQW_TX_DATA                                        (0x4U)

/* This register contains the data to be received. */
#define CSL_HDQW_RX_DATA                                        (0x8U)

/* This register provides status information about the module. */
#define CSL_HDQW_CTRL_STS                                       (0xCU)

/* This register controls interrupts status */
#define CSL_HDQW_INT_STS                                        (0x10U)

/* This register controls various bits */
#define CSL_HDQW_SYSCONFIG                                      (0x14U)

/* This register monitors the reset sequence. */
#define CSL_HDQW_SYSSTS                                         (0x18U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_HDQW_REVISION_REV_MASK                              (0x000000FFU)
#define CSL_HDQW_REVISION_REV_SHIFT                             (0U)
#define CSL_HDQW_REVISION_REV_RESETVAL                          (0x00000008U)
#define CSL_HDQW_REVISION_REV_MAX                               (0x000000ffU)

#define CSL_HDQW_REVISION_RESETVAL                              (0x00000008U)

/* TX_DATA */

#define CSL_HDQW_TX_DATA_TX_DATA_MASK                           (0x000000FFU)
#define CSL_HDQW_TX_DATA_TX_DATA_SHIFT                          (0U)
#define CSL_HDQW_TX_DATA_TX_DATA_RESETVAL                       (0x00000000U)
#define CSL_HDQW_TX_DATA_TX_DATA_MAX                            (0x000000ffU)

#define CSL_HDQW_TX_DATA_RESETVAL                               (0x00000000U)

/* RX_DATA */

#define CSL_HDQW_RX_DATA_RX_DATA_MASK                           (0x000000FFU)
#define CSL_HDQW_RX_DATA_RX_DATA_SHIFT                          (0U)
#define CSL_HDQW_RX_DATA_RX_DATA_RESETVAL                       (0x00000000U)
#define CSL_HDQW_RX_DATA_RX_DATA_MAX                            (0x000000ffU)

#define CSL_HDQW_RX_DATA_RESETVAL                               (0x00000000U)

/* CTRL_STS */

#define CSL_HDQW_CTRL_STS_INTRMASK_MASK                         (0x00000040U)
#define CSL_HDQW_CTRL_STS_INTRMASK_SHIFT                        (6U)
#define CSL_HDQW_CTRL_STS_INTRMASK_RESETVAL                     (0x00000000U)
#define CSL_HDQW_CTRL_STS_INTRMASK_MAX                          (0x00000001U)

#define CSL_HDQW_CTRL_STS_CLOCKEN_MASK                          (0x00000020U)
#define CSL_HDQW_CTRL_STS_CLOCKEN_SHIFT                         (5U)
#define CSL_HDQW_CTRL_STS_CLOCKEN_RESETVAL                      (0x00000000U)
#define CSL_HDQW_CTRL_STS_CLOCKEN_MAX                           (0x00000001U)

#define CSL_HDQW_CTRL_STS_GO_MASK                               (0x00000010U)
#define CSL_HDQW_CTRL_STS_GO_SHIFT                              (4U)
#define CSL_HDQW_CTRL_STS_GO_RESETVAL                           (0x00000000U)
#define CSL_HDQW_CTRL_STS_GO_MAX                                (0x00000001U)

#define CSL_HDQW_CTRL_STS_PRESENCEDETECT_MASK                   (0x00000008U)
#define CSL_HDQW_CTRL_STS_PRESENCEDETECT_SHIFT                  (3U)
#define CSL_HDQW_CTRL_STS_PRESENCEDETECT_RESETVAL               (0x00000000U)
#define CSL_HDQW_CTRL_STS_PRESENCEDETECT_MAX                    (0x00000001U)

#define CSL_HDQW_CTRL_STS_INITIALIZATION_MASK                   (0x00000004U)
#define CSL_HDQW_CTRL_STS_INITIALIZATION_SHIFT                  (2U)
#define CSL_HDQW_CTRL_STS_INITIALIZATION_RESETVAL               (0x00000000U)
#define CSL_HDQW_CTRL_STS_INITIALIZATION_MAX                    (0x00000001U)

#define CSL_HDQW_CTRL_STS_DIR_MASK                              (0x00000002U)
#define CSL_HDQW_CTRL_STS_DIR_SHIFT                             (1U)
#define CSL_HDQW_CTRL_STS_DIR_RESETVAL                          (0x00000000U)
#define CSL_HDQW_CTRL_STS_DIR_MAX                               (0x00000001U)

#define CSL_HDQW_CTRL_STS_MODE_MASK                             (0x00000001U)
#define CSL_HDQW_CTRL_STS_MODE_SHIFT                            (0U)
#define CSL_HDQW_CTRL_STS_MODE_RESETVAL                         (0x00000000U)
#define CSL_HDQW_CTRL_STS_MODE_MAX                              (0x00000001U)

#define CSL_HDQW_CTRL_STS_ONE_WIRE_SINGLE_BIT_MASK              (0x00000080U)
#define CSL_HDQW_CTRL_STS_ONE_WIRE_SINGLE_BIT_SHIFT             (7U)
#define CSL_HDQW_CTRL_STS_ONE_WIRE_SINGLE_BIT_RESETVAL          (0x00000000U)
#define CSL_HDQW_CTRL_STS_ONE_WIRE_SINGLE_BIT_MAX               (0x00000001U)

#define CSL_HDQW_CTRL_STS_BITFSM_DELAY_MASK                     (0x00000700U)
#define CSL_HDQW_CTRL_STS_BITFSM_DELAY_SHIFT                    (8U)
#define CSL_HDQW_CTRL_STS_BITFSM_DELAY_RESETVAL                 (0x00000000U)
#define CSL_HDQW_CTRL_STS_BITFSM_DELAY_MAX                      (0x00000007U)

#define CSL_HDQW_CTRL_STS_RESETVAL                              (0x00000000U)

/* INT_STS */

#define CSL_HDQW_INT_STS_TXCOMPLETE_MASK                        (0x00000004U)
#define CSL_HDQW_INT_STS_TXCOMPLETE_SHIFT                       (2U)
#define CSL_HDQW_INT_STS_TXCOMPLETE_RESETVAL                    (0x00000000U)
#define CSL_HDQW_INT_STS_TXCOMPLETE_MAX                         (0x00000001U)

#define CSL_HDQW_INT_STS_RXCOMPLETE_MASK                        (0x00000002U)
#define CSL_HDQW_INT_STS_RXCOMPLETE_SHIFT                       (1U)
#define CSL_HDQW_INT_STS_RXCOMPLETE_RESETVAL                    (0x00000000U)
#define CSL_HDQW_INT_STS_RXCOMPLETE_MAX                         (0x00000001U)

#define CSL_HDQW_INT_STS_TIMEOUT_MASK                           (0x00000001U)
#define CSL_HDQW_INT_STS_TIMEOUT_SHIFT                          (0U)
#define CSL_HDQW_INT_STS_TIMEOUT_RESETVAL                       (0x00000000U)
#define CSL_HDQW_INT_STS_TIMEOUT_MAX                            (0x00000001U)

#define CSL_HDQW_INT_STS_RESETVAL                               (0x00000000U)

/* SYSCONFIG */

#define CSL_HDQW_SYSCONFIG_SOFTRESET_MASK                       (0x00000002U)
#define CSL_HDQW_SYSCONFIG_SOFTRESET_SHIFT                      (1U)
#define CSL_HDQW_SYSCONFIG_SOFTRESET_RESETVAL                   (0x00000000U)
#define CSL_HDQW_SYSCONFIG_SOFTRESET_MAX                        (0x00000001U)

#define CSL_HDQW_SYSCONFIG_AUTOIDLE_MASK                        (0x00000001U)
#define CSL_HDQW_SYSCONFIG_AUTOIDLE_SHIFT                       (0U)
#define CSL_HDQW_SYSCONFIG_AUTOIDLE_RESETVAL                    (0x00000000U)
#define CSL_HDQW_SYSCONFIG_AUTOIDLE_MAX                         (0x00000001U)

#define CSL_HDQW_SYSCONFIG_RESETVAL                             (0x00000000U)

/* SYSSTS */

#define CSL_HDQW_SYSSTS_RESETDONE_MASK                          (0x00000001U)
#define CSL_HDQW_SYSSTS_RESETDONE_SHIFT                         (0U)
#define CSL_HDQW_SYSSTS_RESETDONE_RESETVAL                      (0x00000001U)
#define CSL_HDQW_SYSSTS_RESETDONE_MAX                           (0x00000001U)

#define CSL_HDQW_SYSSTS_RESETVAL                                (0x00000001U)

#ifdef __cplusplus
}
#endif
#endif

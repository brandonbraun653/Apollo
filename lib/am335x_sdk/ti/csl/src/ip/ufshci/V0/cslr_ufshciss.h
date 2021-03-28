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
 *  Name        : cslr_ufshciss.h
*/
#ifndef CSLR_UFSHCISS_H_
#define CSLR_UFSHCISS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : UFS Global Control Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PID;                       /* Revision Register */
    volatile uint32_t CTRL;                      /* Control Register */
} CSL_ufshcissRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_UFSHCISS_PID                                                       (0x00000000U)
#define CSL_UFSHCISS_CTRL                                                      (0x00000004U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_UFSHCISS_PID_MINOR_MASK                                            (0x0000003FU)
#define CSL_UFSHCISS_PID_MINOR_SHIFT                                           (0x00000000U)
#define CSL_UFSHCISS_PID_MINOR_MAX                                             (0x0000003FU)

#define CSL_UFSHCISS_PID_CUSTOM_MASK                                           (0x000000C0U)
#define CSL_UFSHCISS_PID_CUSTOM_SHIFT                                          (0x00000006U)
#define CSL_UFSHCISS_PID_CUSTOM_MAX                                            (0x00000003U)

#define CSL_UFSHCISS_PID_MAJOR_MASK                                            (0x00000700U)
#define CSL_UFSHCISS_PID_MAJOR_SHIFT                                           (0x00000008U)
#define CSL_UFSHCISS_PID_MAJOR_MAX                                             (0x00000007U)

#define CSL_UFSHCISS_PID_RTL_MASK                                              (0x0000F800U)
#define CSL_UFSHCISS_PID_RTL_SHIFT                                             (0x0000000BU)
#define CSL_UFSHCISS_PID_RTL_MAX                                               (0x0000001FU)

#define CSL_UFSHCISS_PID_MODULE_ID_MASK                                        (0x0FFF0000U)
#define CSL_UFSHCISS_PID_MODULE_ID_SHIFT                                       (0x00000010U)
#define CSL_UFSHCISS_PID_MODULE_ID_MAX                                         (0x00000FFFU)

#define CSL_UFSHCISS_PID_BU_MASK                                               (0x30000000U)
#define CSL_UFSHCISS_PID_BU_SHIFT                                              (0x0000001CU)
#define CSL_UFSHCISS_PID_BU_MAX                                                (0x00000003U)

#define CSL_UFSHCISS_PID_SCHEME_MASK                                           (0xC0000000U)
#define CSL_UFSHCISS_PID_SCHEME_SHIFT                                          (0x0000001EU)
#define CSL_UFSHCISS_PID_SCHEME_MAX                                            (0x00000003U)

/* CTRL */

#define CSL_UFSHCISS_CTRL_RST_N_PCS_MASK                                       (0x00000001U)
#define CSL_UFSHCISS_CTRL_RST_N_PCS_SHIFT                                      (0x00000000U)
#define CSL_UFSHCISS_CTRL_RST_N_PCS_MAX                                        (0x00000001U)

#define CSL_UFSHCISS_CTRL_MPHY_VCONTROL_LA_SA_SEL_MASK                         (0x00000002U)
#define CSL_UFSHCISS_CTRL_MPHY_VCONTROL_LA_SA_SEL_SHIFT                        (0x00000001U)
#define CSL_UFSHCISS_CTRL_MPHY_VCONTROL_LA_SA_SEL_MAX                          (0x00000001U)

#define CSL_UFSHCISS_CTRL_MPHY_VCONTROL_DEEMP_SEL_MASK                         (0x0000000CU)
#define CSL_UFSHCISS_CTRL_MPHY_VCONTROL_DEEMP_SEL_SHIFT                        (0x00000002U)
#define CSL_UFSHCISS_CTRL_MPHY_VCONTROL_DEEMP_SEL_MAX                          (0x00000003U)

#define CSL_UFSHCISS_CTRL_MPHY_REFCLK_FREQ_SEL_MASK                            (0x00000030U)
#define CSL_UFSHCISS_CTRL_MPHY_REFCLK_FREQ_SEL_SHIFT                           (0x00000004U)
#define CSL_UFSHCISS_CTRL_MPHY_REFCLK_FREQ_SEL_MAX                             (0x00000003U)

#ifdef __cplusplus
}
#endif
#endif

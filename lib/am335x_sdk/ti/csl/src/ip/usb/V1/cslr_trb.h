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
#ifndef CSLR_TRB_H_
#define CSLR_TRB_H_

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
    volatile Uint32 PARAM_LO;
    volatile Uint32 PARAM_HI;
    volatile Uint32 STATUS;
    volatile Uint32 CONTROL;
} CSL_TrbRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* PARAM_LO */
#define CSL_TRB_PARAM_LO                                        (0x0U)

/* PARAM_HI */
#define CSL_TRB_PARAM_HI                                        (0x4U)

/* STATUS */
#define CSL_TRB_STATUS                                          (0x8U)

/* CONTROL */
#define CSL_TRB_CONTROL                                         (0xCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PARAM_LO */

#define CSL_TRB_PARAM_LO_BPTRL_MASK                             (0xFFFFFFFFU)
#define CSL_TRB_PARAM_LO_BPTRL_SHIFT                            (0U)
#define CSL_TRB_PARAM_LO_BPTRL_RESETVAL                         (0x00000000U)
#define CSL_TRB_PARAM_LO_BPTRL_MAX                              (0xffffffffU)

#define CSL_TRB_PARAM_LO_RESETVAL                               (0x00000000U)

/* PARAM_HI */

#define CSL_TRB_PARAM_HI_BPTRH_MASK                             (0xFFFFFFFFU)
#define CSL_TRB_PARAM_HI_BPTRH_SHIFT                            (0U)
#define CSL_TRB_PARAM_HI_BPTRH_RESETVAL                         (0x00000000U)
#define CSL_TRB_PARAM_HI_BPTRH_MAX                              (0xffffffffU)

#define CSL_TRB_PARAM_HI_RESETVAL                               (0x00000000U)

/* STATUS */

#define CSL_TRB_STATUS_BUFSIZ_MASK                              (0x00FFFFFFU)
#define CSL_TRB_STATUS_BUFSIZ_SHIFT                             (0U)
#define CSL_TRB_STATUS_BUFSIZ_RESETVAL                          (0x00000000U)
#define CSL_TRB_STATUS_BUFSIZ_MAX                               (0x00ffffffU)

#define CSL_TRB_STATUS_PCM1_MASK                                (0x03000000U)
#define CSL_TRB_STATUS_PCM1_SHIFT                               (24U)
#define CSL_TRB_STATUS_PCM1_RESETVAL                            (0x00000000U)
#define CSL_TRB_STATUS_PCM1__1                                  (0x00000000U)
#define CSL_TRB_STATUS_PCM1__2                                  (0x00000001U)
#define CSL_TRB_STATUS_PCM1__3                                  (0x00000002U)
#define CSL_TRB_STATUS_PCM1__4                                  (0x00000003U)

#define CSL_TRB_STATUS_TRBSTS_MASK                              (0xF0000000U)
#define CSL_TRB_STATUS_TRBSTS_SHIFT                             (28U)
#define CSL_TRB_STATUS_TRBSTS_RESETVAL                          (0x00000000U)
#define CSL_TRB_STATUS_TRBSTS_MAX                               (0x0000000fU)

#define CSL_TRB_STATUS_RESETVAL                                 (0x00000000U)

/* CONTROL */

#define CSL_TRB_CONTROL_HWO_MASK                                (0x00000001U)
#define CSL_TRB_CONTROL_HWO_SHIFT                               (0U)
#define CSL_TRB_CONTROL_HWO_RESETVAL                            (0x00000000U)
#define CSL_TRB_CONTROL_HWO_SW                                  (0x00000000U)
#define CSL_TRB_CONTROL_HWO_HW                                  (0x00000001U)

#define CSL_TRB_CONTROL_LST_MASK                                (0x00000002U)
#define CSL_TRB_CONTROL_LST_SHIFT                               (1U)
#define CSL_TRB_CONTROL_LST_RESETVAL                            (0x00000000U)
#define CSL_TRB_CONTROL_LST__0                                  (0x00000000U)
#define CSL_TRB_CONTROL_LST__1                                  (0x00000001U)

#define CSL_TRB_CONTROL_CHN_MASK                                (0x00000004U)
#define CSL_TRB_CONTROL_CHN_SHIFT                               (2U)
#define CSL_TRB_CONTROL_CHN_RESETVAL                            (0x00000000U)
#define CSL_TRB_CONTROL_CHN_NEWENUM1                            (0x00000000U)
#define CSL_TRB_CONTROL_CHN_CHAINED                             (0x00000001U)

#define CSL_TRB_CONTROL_CSP_MASK                                (0x00000008U)
#define CSL_TRB_CONTROL_CSP_SHIFT                               (3U)
#define CSL_TRB_CONTROL_CSP_RESETVAL                            (0x00000000U)
#define CSL_TRB_CONTROL_CSP_STOP                                (0x00000000U)
#define CSL_TRB_CONTROL_CSP_CONTINUE                            (0x00000001U)

#define CSL_TRB_CONTROL_TRBCTL_MASK                             (0x000003F0U)
#define CSL_TRB_CONTROL_TRBCTL_SHIFT                            (4U)
#define CSL_TRB_CONTROL_TRBCTL_RESETVAL                         (0x00000000U)
#define CSL_TRB_CONTROL_TRBCTL_MAX                              (0x0000003fU)

#define CSL_TRB_CONTROL_ISP_IMI_MASK                            (0x00000400U)
#define CSL_TRB_CONTROL_ISP_IMI_SHIFT                           (10U)
#define CSL_TRB_CONTROL_ISP_IMI_RESETVAL                        (0x00000000U)
#define CSL_TRB_CONTROL_ISP_IMI_NEWENUM1                        (0x00000000U)
#define CSL_TRB_CONTROL_ISP_IMI_NEWENUM2                        (0x00000001U)

#define CSL_TRB_CONTROL_IOC_MASK                                (0x00000800U)
#define CSL_TRB_CONTROL_IOC_SHIFT                               (11U)
#define CSL_TRB_CONTROL_IOC_RESETVAL                            (0x00000000U)
#define CSL_TRB_CONTROL_IOC_NOACTION                            (0x00000000U)
#define CSL_TRB_CONTROL_IOC_IOC                                 (0x00000001U)

#define CSL_TRB_CONTROL_SID_SOFN_MASK                           (0x3FFFC000U)
#define CSL_TRB_CONTROL_SID_SOFN_SHIFT                          (14U)
#define CSL_TRB_CONTROL_SID_SOFN_RESETVAL                       (0x00000000U)
#define CSL_TRB_CONTROL_SID_SOFN_MAX                            (0x0000ffffU)

#define CSL_TRB_CONTROL_RESETVAL                                (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif

/******************************************************************************
*
* Register header file for TRB
*
******************************************************************************
*/
/**
 *  Copyright (c) Texas Instruments Incorporated 2015-2016
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




#ifndef PDK__HW_TRB_DEVICE_H
#define PDK__HW_TRB_DEVICE_H

#ifdef __cplusplus
extern "C"
{
#endif


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile uint32_t TRB_PARAM_LO; /* Offset: 0x0 */
    volatile uint32_t TRB_PARAM_HI; /* Offset: 0x4 */
    volatile uint32_t TRB_STS;  /* Offset: 0x8 */
    volatile uint32_t TRB_CTRL; /* Offset: 0xc */
} TRBRegs;


/**************************************************************************
* Register Definitions
**************************************************************************/
#define TRB_PARAM_LO                                            (0x0u)
#define TRB_PARAM_HI                                            (0x4u)
#define TRB_STATUS                                              (0x8u)
#define TRB_CONTROL                                             (0xCu)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

#define TRB_PARAM_LO_BPTRL_SHIFT                                (0U)
#define TRB_PARAM_LO_BPTRL_MASK                                 (0xffffffffU)

#define TRB_PARAM_HI_BPTRH_SHIFT                                (0U)
#define TRB_PARAM_HI_BPTRH_MASK                                 (0xffffffffU)

#define TRB_STATUS_BUFSIZ_SHIFT                                 (0U)
#define TRB_STATUS_BUFSIZ_MASK                                  (0x00ffffffU)
#define TRB_STATUS_BUFSIZ_ZERO                                   (0U)
#define TRB_STATUS_BUFSIZ_MAX                                    (16777214U)

#define TRB_STATUS_PCM1_SHIFT                                   (24U)
#define TRB_STATUS_PCM1_MASK                                    (0x03000000U)
#define TRB_STATUS_PCM1_1_PACKET                                 (0U)
#define TRB_STATUS_PCM1_2_PACKETS                                (1U)
#define TRB_STATUS_PCM1_3_PACKETS                                (2U)
#define TRB_STATUS_PCM1_4_PACKETS                                (3U)

#define TRB_STATUS_TRBSTS_SHIFT                                 (28U)
#define TRB_STATUS_TRBSTS_MASK                                  (0xf0000000U)
#define TRB_STATUS_TRBSTS_OK                                     (0U)
#define TRB_STATUS_TRBSTS_MISSEDISOC                             (1U)
#define TRB_STATUS_TRBSTS_SETUPPENDING                           (2U)

#define TRB_CONTROL_HWO_SHIFT                                   (0U)
#define TRB_CONTROL_HWO_MASK                                    (0x00000001U)
#define TRB_CONTROL_HWO_SW                                       (0U)
#define TRB_CONTROL_HWO_HW                                       (1U)

#define TRB_CONTROL_LST_SHIFT                                   (1U)
#define TRB_CONTROL_LST_MASK                                    (0x00000002U)
#define TRB_CONTROL_LST_NOT_COMPLETE                             (0U)
#define TRB_CONTROL_LST_LAST                                     (1U)

#define TRB_CONTROL_CHN_SHIFT                                   (2U)
#define TRB_CONTROL_CHN_MASK                                    (0x00000004U)
#define TRB_CONTROL_CHN_END                                      (0U)
#define TRB_CONTROL_CHN_CHAINED                                  (1U)

#define TRB_CONTROL_CSP_SHIFT                                   (3U)
#define TRB_CONTROL_CSP_MASK                                    (0x00000008U)
#define TRB_CONTROL_CSP_STOP                                     (0U)
#define TRB_CONTROL_CSP_CONTINUE                                 (1U)

#define TRB_CONTROL_TRBCTL_SHIFT                                (4U)
#define TRB_CONTROL_TRBCTL_MASK                                 (0x000003f0U)
#define TRB_CONTROL_TRBCTL_NORMAL                                (1U)
#define TRB_CONTROL_TRBCTL_CSET                                  (2U)
#define TRB_CONTROL_TRBCTL_CSTS2                                 (3U)
#define TRB_CONTROL_TRBCTL_CSTS3                                 (4U)
#define TRB_CONTROL_TRBCTL_CDAT1                                 (5U)
#define TRB_CONTROL_TRBCTL_ISO1                                  (6U)
#define TRB_CONTROL_TRBCTL_ISON                                  (7U)
#define TRB_CONTROL_TRBCTL_LINK                                  (8U)

#define TRB_CONTROL_ISP_IMI_SHIFT                               (10U)
#define TRB_CONTROL_ISP_IMI_MASK                                (0x00000400U)
#define TRB_CONTROL_ISP_IMI_NOACTION                             (0U)
#define TRB_CONTROL_ISP_IMI_XFERINPROG_MISSED_ISOC               (1U)

#define TRB_CONTROL_IOC_SHIFT                                   (11U)
#define TRB_CONTROL_IOC_MASK                                    (0x00000800U)
#define TRB_CONTROL_IOC_NOACTION                                 (0U)
#define TRB_CONTROL_IOC_XFERINPROG                               (1U)

#define TRB_CONTROL_SID_SOFN_SHIFT                              (14U)
#define TRB_CONTROL_SID_SOFN_MASK                               (0x3fffc000U)

#ifdef __cplusplus
}
#endif
#endif /* PDK__HW_TRB_DEVICE_H */

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
#ifndef CSLR_SMSETCONF_H_
#define CSLR_SMSETCONF_H_

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
    volatile Uint32 ID;
    volatile Uint8  RSVD0[12];
    volatile Uint32 SCFG;
    volatile Uint32 SR;
    volatile Uint8  RSVD1[12];
    volatile Uint32 CFG;
    volatile Uint32 SESW;
    volatile Uint8  RSVD2[4];
    volatile Uint32 SEDEN1;
    volatile Uint32 SEDEN2;
    volatile Uint32 SEDEN3;
    volatile Uint32 SEDEN4;
    volatile Uint32 SEDEN5;
    volatile Uint32 SEDEN6;
    volatile Uint32 SEDEN7;
    volatile Uint32 SEDEN8;
} CSL_SmsetConfRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* SMSET identification register */
#define CSL_SMSETCONF_ID                                        (0x0U)

/* SMSET system configuration register */
#define CSL_SMSETCONF_SCFG                                      (0x10U)

/* SMSET Status Register */
#define CSL_SMSETCONF_SR                                        (0x14U)

/* SMSET Configuration register */
#define CSL_SMSETCONF_CFG                                       (0x24U)

/* System Event Sampling Window register */
#define CSL_SMSETCONF_SESW                                      (0x28U)

/* System Event Detection Enable register 1 */
#define CSL_SMSETCONF_SEDEN1                                    (0x30U)

/* System Event Detection Enable register 2 */
#define CSL_SMSETCONF_SEDEN2                                    (0x34U)

/* System Event Detection Enable register 3 */
#define CSL_SMSETCONF_SEDEN3                                    (0x38U)

/* System Event Detection Enable register 4 */
#define CSL_SMSETCONF_SEDEN4                                    (0x3CU)

/* System Event Detection Enable register 5 */
#define CSL_SMSETCONF_SEDEN5                                    (0x40U)

/* System Event Detection Enable register 6 */
#define CSL_SMSETCONF_SEDEN6                                    (0x44U)

/* System Event Detection Enable register 7 */
#define CSL_SMSETCONF_SEDEN7                                    (0x48U)

/* System Event Detection Enable register 8 */
#define CSL_SMSETCONF_SEDEN8                                    (0x4CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* ID */

#define CSL_SMSETCONF_ID_MINORREVISION_MASK                     (0x0000003FU)
#define CSL_SMSETCONF_ID_MINORREVISION_SHIFT                    (0U)
#define CSL_SMSETCONF_ID_MINORREVISION_RESETVAL                 (0x00000000U)
#define CSL_SMSETCONF_ID_MINORREVISION_MAX                      (0x0000003fU)

#define CSL_SMSETCONF_ID_CUSTOM_MASK                            (0x000000C0U)
#define CSL_SMSETCONF_ID_CUSTOM_SHIFT                           (6U)
#define CSL_SMSETCONF_ID_CUSTOM_RESETVAL                        (0x00000000U)
#define CSL_SMSETCONF_ID_CUSTOM_MAX                             (0x00000003U)

#define CSL_SMSETCONF_ID_MAJORREVISION_MASK                     (0x00000700U)
#define CSL_SMSETCONF_ID_MAJORREVISION_SHIFT                    (8U)
#define CSL_SMSETCONF_ID_MAJORREVISION_RESETVAL                 (0x00000000U)
#define CSL_SMSETCONF_ID_MAJORREVISION_MAX                      (0x00000007U)

#define CSL_SMSETCONF_ID_RTLVERSION_MASK                        (0x0000F800U)
#define CSL_SMSETCONF_ID_RTLVERSION_SHIFT                       (11U)
#define CSL_SMSETCONF_ID_RTLVERSION_RESETVAL                    (0x00000000U)
#define CSL_SMSETCONF_ID_RTLVERSION_MAX                         (0x0000001fU)

#define CSL_SMSETCONF_ID_FUNCTION_MASK                          (0x0FFF0000U)
#define CSL_SMSETCONF_ID_FUNCTION_SHIFT                         (16U)
#define CSL_SMSETCONF_ID_FUNCTION_RESETVAL                      (0x00000045U)
#define CSL_SMSETCONF_ID_FUNCTION_MAX                           (0x00000fffU)

#define CSL_SMSETCONF_ID_RESETVAL                               (0x50450000U)

/* SCFG */

#define CSL_SMSETCONF_SCFG_SOFTRESET_MASK                       (0x00000001U)
#define CSL_SMSETCONF_SCFG_SOFTRESET_SHIFT                      (0U)
#define CSL_SMSETCONF_SCFG_SOFTRESET_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SCFG_SOFTRESET_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SCFG_IDLEMODE_MASK                        (0x0000000CU)
#define CSL_SMSETCONF_SCFG_IDLEMODE_SHIFT                       (2U)
#define CSL_SMSETCONF_SCFG_IDLEMODE_RESETVAL                    (0x00000002U)
#define CSL_SMSETCONF_SCFG_IDLEMODE_MAX                         (0x00000003U)

#define CSL_SMSETCONF_SCFG_RESETVAL                             (0x00000008U)

/* SR */

#define CSL_SMSETCONF_SR_RESETDONE_MASK                         (0x00000001U)
#define CSL_SMSETCONF_SR_RESETDONE_SHIFT                        (0U)
#define CSL_SMSETCONF_SR_RESETDONE_RESETVAL                     (0x00000001U)
#define CSL_SMSETCONF_SR_RESETDONE_MAX                          (0x00000001U)

#define CSL_SMSETCONF_SR_HWFIFOEMPTY_MASK                       (0x00000100U)
#define CSL_SMSETCONF_SR_HWFIFOEMPTY_SHIFT                      (8U)
#define CSL_SMSETCONF_SR_HWFIFOEMPTY_RESETVAL                   (0x00000001U)
#define CSL_SMSETCONF_SR_HWFIFOEMPTY_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SR_SWFIFOEMPTY_MASK                       (0x00000200U)
#define CSL_SMSETCONF_SR_SWFIFOEMPTY_SHIFT                      (9U)
#define CSL_SMSETCONF_SR_SWFIFOEMPTY_RESETVAL                   (0x00000001U)
#define CSL_SMSETCONF_SR_SWFIFOEMPTY_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SR_RESETVAL                               (0x00000301U)

/* CFG */

#define CSL_SMSETCONF_CFG_START_MASK                            (0x00000002U)
#define CSL_SMSETCONF_CFG_START_SHIFT                           (1U)
#define CSL_SMSETCONF_CFG_START_RESETVAL                        (0x00000000U)
#define CSL_SMSETCONF_CFG_START_MAX                             (0x00000001U)

#define CSL_SMSETCONF_CFG_STOP_MASK                             (0x00000004U)
#define CSL_SMSETCONF_CFG_STOP_SHIFT                            (2U)
#define CSL_SMSETCONF_CFG_STOP_RESETVAL                         (0x00000000U)
#define CSL_SMSETCONF_CFG_STOP_MAX                              (0x00000001U)

#define CSL_SMSETCONF_CFG_EVTMSG_MASK                           (0x00000008U)
#define CSL_SMSETCONF_CFG_EVTMSG_SHIFT                          (3U)
#define CSL_SMSETCONF_CFG_EVTMSG_RESETVAL                       (0x00000000U)
#define CSL_SMSETCONF_CFG_EVTMSG_MAX                            (0x00000001U)

#define CSL_SMSETCONF_CFG_EVTLEVEL_MASK                         (0x00000010U)
#define CSL_SMSETCONF_CFG_EVTLEVEL_SHIFT                        (4U)
#define CSL_SMSETCONF_CFG_EVTLEVEL_RESETVAL                     (0x00000001U)
#define CSL_SMSETCONF_CFG_EVTLEVEL_MAX                          (0x00000001U)

#define CSL_SMSETCONF_CFG_CURRENTOWNER_MASK                     (0x10000000U)
#define CSL_SMSETCONF_CFG_CURRENTOWNER_SHIFT                    (28U)
#define CSL_SMSETCONF_CFG_CURRENTOWNER_RESETVAL                 (0x00000000U)
#define CSL_SMSETCONF_CFG_CURRENTOWNER_MAX                      (0x00000001U)

#define CSL_SMSETCONF_CFG_CAPTUREEN_MASK                        (0x00000080U)
#define CSL_SMSETCONF_CFG_CAPTUREEN_SHIFT                       (7U)
#define CSL_SMSETCONF_CFG_CAPTUREEN_RESETVAL                    (0x00000000U)
#define CSL_SMSETCONF_CFG_CAPTUREEN_MAX                         (0x00000001U)

#define CSL_SMSETCONF_CFG_DBGGEROVERRIDE_MASK                   (0x20000000U)
#define CSL_SMSETCONF_CFG_DBGGEROVERRIDE_SHIFT                  (29U)
#define CSL_SMSETCONF_CFG_DBGGEROVERRIDE_RESETVAL               (0x00000001U)
#define CSL_SMSETCONF_CFG_DBGGEROVERRIDE_MAX                    (0x00000001U)

#define CSL_SMSETCONF_CFG_OWNERSHIP_MASK                        (0xC0000000U)
#define CSL_SMSETCONF_CFG_OWNERSHIP_SHIFT                       (30U)
#define CSL_SMSETCONF_CFG_OWNERSHIP_RESETVAL                    (0x00000000U)
#define CSL_SMSETCONF_CFG_OWNERSHIP_MAX                         (0x00000003U)

#define CSL_SMSETCONF_CFG_RESETVAL                              (0x20000010U)

/* SESW */

#define CSL_SMSETCONF_SESW_SAMPLINGWINDOWSIZE_MASK              (0x000000FFU)
#define CSL_SMSETCONF_SESW_SAMPLINGWINDOWSIZE_SHIFT             (0U)
#define CSL_SMSETCONF_SESW_SAMPLINGWINDOWSIZE_RESETVAL          (0x00000000U)
#define CSL_SMSETCONF_SESW_SAMPLINGWINDOWSIZE_MAX               (0x000000ffU)

#define CSL_SMSETCONF_SESW_RESETVAL                             (0x00000000U)

/* SEDEN1 */

#define CSL_SMSETCONF_SEDEN1_EVT1EN_MASK                        (0x00000001U)
#define CSL_SMSETCONF_SEDEN1_EVT1EN_SHIFT                       (0U)
#define CSL_SMSETCONF_SEDEN1_EVT1EN_RESETVAL                    (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT1EN_MAX                         (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT2EN_MASK                        (0x00000002U)
#define CSL_SMSETCONF_SEDEN1_EVT2EN_SHIFT                       (1U)
#define CSL_SMSETCONF_SEDEN1_EVT2EN_RESETVAL                    (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT2EN_MAX                         (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT3EN_MASK                        (0x00000004U)
#define CSL_SMSETCONF_SEDEN1_EVT3EN_SHIFT                       (2U)
#define CSL_SMSETCONF_SEDEN1_EVT3EN_RESETVAL                    (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT3EN_MAX                         (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT4EN_MASK                        (0x00000008U)
#define CSL_SMSETCONF_SEDEN1_EVT4EN_SHIFT                       (3U)
#define CSL_SMSETCONF_SEDEN1_EVT4EN_RESETVAL                    (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT4EN_MAX                         (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT5EN_MASK                        (0x00000010U)
#define CSL_SMSETCONF_SEDEN1_EVT5EN_SHIFT                       (4U)
#define CSL_SMSETCONF_SEDEN1_EVT5EN_RESETVAL                    (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT5EN_MAX                         (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT6EN_MASK                        (0x00000020U)
#define CSL_SMSETCONF_SEDEN1_EVT6EN_SHIFT                       (5U)
#define CSL_SMSETCONF_SEDEN1_EVT6EN_RESETVAL                    (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT6EN_MAX                         (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT7EN_MASK                        (0x00000040U)
#define CSL_SMSETCONF_SEDEN1_EVT7EN_SHIFT                       (6U)
#define CSL_SMSETCONF_SEDEN1_EVT7EN_RESETVAL                    (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT7EN_MAX                         (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT8EN_MASK                        (0x00000080U)
#define CSL_SMSETCONF_SEDEN1_EVT8EN_SHIFT                       (7U)
#define CSL_SMSETCONF_SEDEN1_EVT8EN_RESETVAL                    (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT8EN_MAX                         (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT9EN_MASK                        (0x00000100U)
#define CSL_SMSETCONF_SEDEN1_EVT9EN_SHIFT                       (8U)
#define CSL_SMSETCONF_SEDEN1_EVT9EN_RESETVAL                    (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT9EN_MAX                         (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT10EN_MASK                       (0x00000200U)
#define CSL_SMSETCONF_SEDEN1_EVT10EN_SHIFT                      (9U)
#define CSL_SMSETCONF_SEDEN1_EVT10EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT10EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT11EN_MASK                       (0x00000400U)
#define CSL_SMSETCONF_SEDEN1_EVT11EN_SHIFT                      (10U)
#define CSL_SMSETCONF_SEDEN1_EVT11EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT11EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT12EN_MASK                       (0x00000800U)
#define CSL_SMSETCONF_SEDEN1_EVT12EN_SHIFT                      (11U)
#define CSL_SMSETCONF_SEDEN1_EVT12EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT12EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT13EN_MASK                       (0x00001000U)
#define CSL_SMSETCONF_SEDEN1_EVT13EN_SHIFT                      (12U)
#define CSL_SMSETCONF_SEDEN1_EVT13EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT13EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT14EN_MASK                       (0x00002000U)
#define CSL_SMSETCONF_SEDEN1_EVT14EN_SHIFT                      (13U)
#define CSL_SMSETCONF_SEDEN1_EVT14EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT14EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT15EN_MASK                       (0x00004000U)
#define CSL_SMSETCONF_SEDEN1_EVT15EN_SHIFT                      (14U)
#define CSL_SMSETCONF_SEDEN1_EVT15EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT15EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT16EN_MASK                       (0x00008000U)
#define CSL_SMSETCONF_SEDEN1_EVT16EN_SHIFT                      (15U)
#define CSL_SMSETCONF_SEDEN1_EVT16EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT16EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT17EN_MASK                       (0x00010000U)
#define CSL_SMSETCONF_SEDEN1_EVT17EN_SHIFT                      (16U)
#define CSL_SMSETCONF_SEDEN1_EVT17EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT17EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT18EN_MASK                       (0x00020000U)
#define CSL_SMSETCONF_SEDEN1_EVT18EN_SHIFT                      (17U)
#define CSL_SMSETCONF_SEDEN1_EVT18EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT18EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT19EN_MASK                       (0x00040000U)
#define CSL_SMSETCONF_SEDEN1_EVT19EN_SHIFT                      (18U)
#define CSL_SMSETCONF_SEDEN1_EVT19EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT19EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT20EN_MASK                       (0x00080000U)
#define CSL_SMSETCONF_SEDEN1_EVT20EN_SHIFT                      (19U)
#define CSL_SMSETCONF_SEDEN1_EVT20EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT20EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT21EN_MASK                       (0x00100000U)
#define CSL_SMSETCONF_SEDEN1_EVT21EN_SHIFT                      (20U)
#define CSL_SMSETCONF_SEDEN1_EVT21EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT21EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT22EN_MASK                       (0x00200000U)
#define CSL_SMSETCONF_SEDEN1_EVT22EN_SHIFT                      (21U)
#define CSL_SMSETCONF_SEDEN1_EVT22EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT22EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT23EN_MASK                       (0x00400000U)
#define CSL_SMSETCONF_SEDEN1_EVT23EN_SHIFT                      (22U)
#define CSL_SMSETCONF_SEDEN1_EVT23EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT23EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT24EN_MASK                       (0x00800000U)
#define CSL_SMSETCONF_SEDEN1_EVT24EN_SHIFT                      (23U)
#define CSL_SMSETCONF_SEDEN1_EVT24EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT24EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT25EN_MASK                       (0x01000000U)
#define CSL_SMSETCONF_SEDEN1_EVT25EN_SHIFT                      (24U)
#define CSL_SMSETCONF_SEDEN1_EVT25EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT25EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT26EN_MASK                       (0x02000000U)
#define CSL_SMSETCONF_SEDEN1_EVT26EN_SHIFT                      (25U)
#define CSL_SMSETCONF_SEDEN1_EVT26EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT26EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT27EN_MASK                       (0x04000000U)
#define CSL_SMSETCONF_SEDEN1_EVT27EN_SHIFT                      (26U)
#define CSL_SMSETCONF_SEDEN1_EVT27EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT27EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT28EN_MASK                       (0x08000000U)
#define CSL_SMSETCONF_SEDEN1_EVT28EN_SHIFT                      (27U)
#define CSL_SMSETCONF_SEDEN1_EVT28EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT28EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT29EN_MASK                       (0x10000000U)
#define CSL_SMSETCONF_SEDEN1_EVT29EN_SHIFT                      (28U)
#define CSL_SMSETCONF_SEDEN1_EVT29EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT29EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT30EN_MASK                       (0x20000000U)
#define CSL_SMSETCONF_SEDEN1_EVT30EN_SHIFT                      (29U)
#define CSL_SMSETCONF_SEDEN1_EVT30EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT30EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT31EN_MASK                       (0x40000000U)
#define CSL_SMSETCONF_SEDEN1_EVT31EN_SHIFT                      (30U)
#define CSL_SMSETCONF_SEDEN1_EVT31EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT31EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_EVT32EN_MASK                       (0x80000000U)
#define CSL_SMSETCONF_SEDEN1_EVT32EN_SHIFT                      (31U)
#define CSL_SMSETCONF_SEDEN1_EVT32EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN1_EVT32EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN1_RESETVAL                           (0x00000000U)

/* SEDEN2 */

#define CSL_SMSETCONF_SEDEN2_EVT33EN_MASK                       (0x00000001U)
#define CSL_SMSETCONF_SEDEN2_EVT33EN_SHIFT                      (0U)
#define CSL_SMSETCONF_SEDEN2_EVT33EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT33EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT34EN_MASK                       (0x00000002U)
#define CSL_SMSETCONF_SEDEN2_EVT34EN_SHIFT                      (1U)
#define CSL_SMSETCONF_SEDEN2_EVT34EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT34EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT35EN_MASK                       (0x00000004U)
#define CSL_SMSETCONF_SEDEN2_EVT35EN_SHIFT                      (2U)
#define CSL_SMSETCONF_SEDEN2_EVT35EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT35EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT36EN_MASK                       (0x00000008U)
#define CSL_SMSETCONF_SEDEN2_EVT36EN_SHIFT                      (3U)
#define CSL_SMSETCONF_SEDEN2_EVT36EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT36EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT37EN_MASK                       (0x00000010U)
#define CSL_SMSETCONF_SEDEN2_EVT37EN_SHIFT                      (4U)
#define CSL_SMSETCONF_SEDEN2_EVT37EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT37EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT38EN_MASK                       (0x00000020U)
#define CSL_SMSETCONF_SEDEN2_EVT38EN_SHIFT                      (5U)
#define CSL_SMSETCONF_SEDEN2_EVT38EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT38EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT39EN_MASK                       (0x00000040U)
#define CSL_SMSETCONF_SEDEN2_EVT39EN_SHIFT                      (6U)
#define CSL_SMSETCONF_SEDEN2_EVT39EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT39EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT40EN_MASK                       (0x00000080U)
#define CSL_SMSETCONF_SEDEN2_EVT40EN_SHIFT                      (7U)
#define CSL_SMSETCONF_SEDEN2_EVT40EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT40EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT41EN_MASK                       (0x00000100U)
#define CSL_SMSETCONF_SEDEN2_EVT41EN_SHIFT                      (8U)
#define CSL_SMSETCONF_SEDEN2_EVT41EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT41EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT42EN_MASK                       (0x00000200U)
#define CSL_SMSETCONF_SEDEN2_EVT42EN_SHIFT                      (9U)
#define CSL_SMSETCONF_SEDEN2_EVT42EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT42EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT43EN_MASK                       (0x00000400U)
#define CSL_SMSETCONF_SEDEN2_EVT43EN_SHIFT                      (10U)
#define CSL_SMSETCONF_SEDEN2_EVT43EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT43EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT44EN_MASK                       (0x00000800U)
#define CSL_SMSETCONF_SEDEN2_EVT44EN_SHIFT                      (11U)
#define CSL_SMSETCONF_SEDEN2_EVT44EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT44EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT45EN_MASK                       (0x00001000U)
#define CSL_SMSETCONF_SEDEN2_EVT45EN_SHIFT                      (12U)
#define CSL_SMSETCONF_SEDEN2_EVT45EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT45EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT46EN_MASK                       (0x00002000U)
#define CSL_SMSETCONF_SEDEN2_EVT46EN_SHIFT                      (13U)
#define CSL_SMSETCONF_SEDEN2_EVT46EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT46EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT47EN_MASK                       (0x00004000U)
#define CSL_SMSETCONF_SEDEN2_EVT47EN_SHIFT                      (14U)
#define CSL_SMSETCONF_SEDEN2_EVT47EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT47EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT48EN_MASK                       (0x00008000U)
#define CSL_SMSETCONF_SEDEN2_EVT48EN_SHIFT                      (15U)
#define CSL_SMSETCONF_SEDEN2_EVT48EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT48EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT49EN_MASK                       (0x00010000U)
#define CSL_SMSETCONF_SEDEN2_EVT49EN_SHIFT                      (16U)
#define CSL_SMSETCONF_SEDEN2_EVT49EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT49EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT50EN_MASK                       (0x00020000U)
#define CSL_SMSETCONF_SEDEN2_EVT50EN_SHIFT                      (17U)
#define CSL_SMSETCONF_SEDEN2_EVT50EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT50EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT51EN_MASK                       (0x00040000U)
#define CSL_SMSETCONF_SEDEN2_EVT51EN_SHIFT                      (18U)
#define CSL_SMSETCONF_SEDEN2_EVT51EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT51EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT52EN_MASK                       (0x00080000U)
#define CSL_SMSETCONF_SEDEN2_EVT52EN_SHIFT                      (19U)
#define CSL_SMSETCONF_SEDEN2_EVT52EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT52EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT53EN_MASK                       (0x00100000U)
#define CSL_SMSETCONF_SEDEN2_EVT53EN_SHIFT                      (20U)
#define CSL_SMSETCONF_SEDEN2_EVT53EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT53EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT54EN_MASK                       (0x00200000U)
#define CSL_SMSETCONF_SEDEN2_EVT54EN_SHIFT                      (21U)
#define CSL_SMSETCONF_SEDEN2_EVT54EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT54EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT55EN_MASK                       (0x00400000U)
#define CSL_SMSETCONF_SEDEN2_EVT55EN_SHIFT                      (22U)
#define CSL_SMSETCONF_SEDEN2_EVT55EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT55EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT56EN_MASK                       (0x00800000U)
#define CSL_SMSETCONF_SEDEN2_EVT56EN_SHIFT                      (23U)
#define CSL_SMSETCONF_SEDEN2_EVT56EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT56EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT57EN_MASK                       (0x01000000U)
#define CSL_SMSETCONF_SEDEN2_EVT57EN_SHIFT                      (24U)
#define CSL_SMSETCONF_SEDEN2_EVT57EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT57EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT58EN_MASK                       (0x02000000U)
#define CSL_SMSETCONF_SEDEN2_EVT58EN_SHIFT                      (25U)
#define CSL_SMSETCONF_SEDEN2_EVT58EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT58EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT59EN_MASK                       (0x04000000U)
#define CSL_SMSETCONF_SEDEN2_EVT59EN_SHIFT                      (26U)
#define CSL_SMSETCONF_SEDEN2_EVT59EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT59EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT60EN_MASK                       (0x08000000U)
#define CSL_SMSETCONF_SEDEN2_EVT60EN_SHIFT                      (27U)
#define CSL_SMSETCONF_SEDEN2_EVT60EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT60EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT61EN_MASK                       (0x10000000U)
#define CSL_SMSETCONF_SEDEN2_EVT61EN_SHIFT                      (28U)
#define CSL_SMSETCONF_SEDEN2_EVT61EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT61EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT62EN_MASK                       (0x20000000U)
#define CSL_SMSETCONF_SEDEN2_EVT62EN_SHIFT                      (29U)
#define CSL_SMSETCONF_SEDEN2_EVT62EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT62EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT63EN_MASK                       (0x40000000U)
#define CSL_SMSETCONF_SEDEN2_EVT63EN_SHIFT                      (30U)
#define CSL_SMSETCONF_SEDEN2_EVT63EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT63EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_EVT64EN_MASK                       (0x80000000U)
#define CSL_SMSETCONF_SEDEN2_EVT64EN_SHIFT                      (31U)
#define CSL_SMSETCONF_SEDEN2_EVT64EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN2_EVT64EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN2_RESETVAL                           (0x00000000U)

/* SEDEN3 */

#define CSL_SMSETCONF_SEDEN3_EVT65EN_MASK                       (0x00000001U)
#define CSL_SMSETCONF_SEDEN3_EVT65EN_SHIFT                      (0U)
#define CSL_SMSETCONF_SEDEN3_EVT65EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT65EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT66EN_MASK                       (0x00000002U)
#define CSL_SMSETCONF_SEDEN3_EVT66EN_SHIFT                      (1U)
#define CSL_SMSETCONF_SEDEN3_EVT66EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT66EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT67EN_MASK                       (0x00000004U)
#define CSL_SMSETCONF_SEDEN3_EVT67EN_SHIFT                      (2U)
#define CSL_SMSETCONF_SEDEN3_EVT67EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT67EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT68EN_MASK                       (0x00000008U)
#define CSL_SMSETCONF_SEDEN3_EVT68EN_SHIFT                      (3U)
#define CSL_SMSETCONF_SEDEN3_EVT68EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT68EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT69EN_MASK                       (0x00000010U)
#define CSL_SMSETCONF_SEDEN3_EVT69EN_SHIFT                      (4U)
#define CSL_SMSETCONF_SEDEN3_EVT69EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT69EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT70EN_MASK                       (0x00000020U)
#define CSL_SMSETCONF_SEDEN3_EVT70EN_SHIFT                      (5U)
#define CSL_SMSETCONF_SEDEN3_EVT70EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT70EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT71EN_MASK                       (0x00000040U)
#define CSL_SMSETCONF_SEDEN3_EVT71EN_SHIFT                      (6U)
#define CSL_SMSETCONF_SEDEN3_EVT71EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT71EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT72EN_MASK                       (0x00000080U)
#define CSL_SMSETCONF_SEDEN3_EVT72EN_SHIFT                      (7U)
#define CSL_SMSETCONF_SEDEN3_EVT72EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT72EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT73EN_MASK                       (0x00000100U)
#define CSL_SMSETCONF_SEDEN3_EVT73EN_SHIFT                      (8U)
#define CSL_SMSETCONF_SEDEN3_EVT73EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT73EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT74EN_MASK                       (0x00000200U)
#define CSL_SMSETCONF_SEDEN3_EVT74EN_SHIFT                      (9U)
#define CSL_SMSETCONF_SEDEN3_EVT74EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT74EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT75EN_MASK                       (0x00000400U)
#define CSL_SMSETCONF_SEDEN3_EVT75EN_SHIFT                      (10U)
#define CSL_SMSETCONF_SEDEN3_EVT75EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT75EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT76EN_MASK                       (0x00000800U)
#define CSL_SMSETCONF_SEDEN3_EVT76EN_SHIFT                      (11U)
#define CSL_SMSETCONF_SEDEN3_EVT76EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT76EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT77EN_MASK                       (0x00001000U)
#define CSL_SMSETCONF_SEDEN3_EVT77EN_SHIFT                      (12U)
#define CSL_SMSETCONF_SEDEN3_EVT77EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT77EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT78EN_MASK                       (0x00002000U)
#define CSL_SMSETCONF_SEDEN3_EVT78EN_SHIFT                      (13U)
#define CSL_SMSETCONF_SEDEN3_EVT78EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT78EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT79EN_MASK                       (0x00004000U)
#define CSL_SMSETCONF_SEDEN3_EVT79EN_SHIFT                      (14U)
#define CSL_SMSETCONF_SEDEN3_EVT79EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT79EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT80EN_MASK                       (0x00008000U)
#define CSL_SMSETCONF_SEDEN3_EVT80EN_SHIFT                      (15U)
#define CSL_SMSETCONF_SEDEN3_EVT80EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT80EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT81EN_MASK                       (0x00010000U)
#define CSL_SMSETCONF_SEDEN3_EVT81EN_SHIFT                      (16U)
#define CSL_SMSETCONF_SEDEN3_EVT81EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT81EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT82EN_MASK                       (0x00020000U)
#define CSL_SMSETCONF_SEDEN3_EVT82EN_SHIFT                      (17U)
#define CSL_SMSETCONF_SEDEN3_EVT82EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT82EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT83EN_MASK                       (0x00040000U)
#define CSL_SMSETCONF_SEDEN3_EVT83EN_SHIFT                      (18U)
#define CSL_SMSETCONF_SEDEN3_EVT83EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT83EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT84EN_MASK                       (0x00080000U)
#define CSL_SMSETCONF_SEDEN3_EVT84EN_SHIFT                      (19U)
#define CSL_SMSETCONF_SEDEN3_EVT84EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT84EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT85EN_MASK                       (0x00100000U)
#define CSL_SMSETCONF_SEDEN3_EVT85EN_SHIFT                      (20U)
#define CSL_SMSETCONF_SEDEN3_EVT85EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT85EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT86EN_MASK                       (0x00200000U)
#define CSL_SMSETCONF_SEDEN3_EVT86EN_SHIFT                      (21U)
#define CSL_SMSETCONF_SEDEN3_EVT86EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT86EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT87EN_MASK                       (0x00400000U)
#define CSL_SMSETCONF_SEDEN3_EVT87EN_SHIFT                      (22U)
#define CSL_SMSETCONF_SEDEN3_EVT87EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT87EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT88EN_MASK                       (0x00800000U)
#define CSL_SMSETCONF_SEDEN3_EVT88EN_SHIFT                      (23U)
#define CSL_SMSETCONF_SEDEN3_EVT88EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT88EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT89EN_MASK                       (0x01000000U)
#define CSL_SMSETCONF_SEDEN3_EVT89EN_SHIFT                      (24U)
#define CSL_SMSETCONF_SEDEN3_EVT89EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT89EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT90EN_MASK                       (0x02000000U)
#define CSL_SMSETCONF_SEDEN3_EVT90EN_SHIFT                      (25U)
#define CSL_SMSETCONF_SEDEN3_EVT90EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT90EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT91EN_MASK                       (0x04000000U)
#define CSL_SMSETCONF_SEDEN3_EVT91EN_SHIFT                      (26U)
#define CSL_SMSETCONF_SEDEN3_EVT91EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT91EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT92EN_MASK                       (0x08000000U)
#define CSL_SMSETCONF_SEDEN3_EVT92EN_SHIFT                      (27U)
#define CSL_SMSETCONF_SEDEN3_EVT92EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT92EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVEN93EN_MASK                      (0x10000000U)
#define CSL_SMSETCONF_SEDEN3_EVEN93EN_SHIFT                     (28U)
#define CSL_SMSETCONF_SEDEN3_EVEN93EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVEN93EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT94EN_MASK                       (0x20000000U)
#define CSL_SMSETCONF_SEDEN3_EVT94EN_SHIFT                      (29U)
#define CSL_SMSETCONF_SEDEN3_EVT94EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT94EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT95EN_MASK                       (0x40000000U)
#define CSL_SMSETCONF_SEDEN3_EVT95EN_SHIFT                      (30U)
#define CSL_SMSETCONF_SEDEN3_EVT95EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT95EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_EVT96EN_MASK                       (0x80000000U)
#define CSL_SMSETCONF_SEDEN3_EVT96EN_SHIFT                      (31U)
#define CSL_SMSETCONF_SEDEN3_EVT96EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN3_EVT96EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN3_RESETVAL                           (0x00000000U)

/* SEDEN4 */

#define CSL_SMSETCONF_SEDEN4_EVEN97EN_MASK                      (0x00000001U)
#define CSL_SMSETCONF_SEDEN4_EVEN97EN_SHIFT                     (0U)
#define CSL_SMSETCONF_SEDEN4_EVEN97EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVEN97EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT98EN_MASK                       (0x00000002U)
#define CSL_SMSETCONF_SEDEN4_EVT98EN_SHIFT                      (1U)
#define CSL_SMSETCONF_SEDEN4_EVT98EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT98EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT99EN_MASK                       (0x00000004U)
#define CSL_SMSETCONF_SEDEN4_EVT99EN_SHIFT                      (2U)
#define CSL_SMSETCONF_SEDEN4_EVT99EN_RESETVAL                   (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT99EN_MAX                        (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT100EN_MASK                      (0x00000008U)
#define CSL_SMSETCONF_SEDEN4_EVT100EN_SHIFT                     (3U)
#define CSL_SMSETCONF_SEDEN4_EVT100EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT100EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT101EN_MASK                      (0x00000010U)
#define CSL_SMSETCONF_SEDEN4_EVT101EN_SHIFT                     (4U)
#define CSL_SMSETCONF_SEDEN4_EVT101EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT101EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT102EN_MASK                      (0x00000020U)
#define CSL_SMSETCONF_SEDEN4_EVT102EN_SHIFT                     (5U)
#define CSL_SMSETCONF_SEDEN4_EVT102EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT102EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT103EN_MASK                      (0x00000040U)
#define CSL_SMSETCONF_SEDEN4_EVT103EN_SHIFT                     (6U)
#define CSL_SMSETCONF_SEDEN4_EVT103EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT103EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT104EN_MASK                      (0x00000080U)
#define CSL_SMSETCONF_SEDEN4_EVT104EN_SHIFT                     (7U)
#define CSL_SMSETCONF_SEDEN4_EVT104EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT104EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT105EN_MASK                      (0x00000100U)
#define CSL_SMSETCONF_SEDEN4_EVT105EN_SHIFT                     (8U)
#define CSL_SMSETCONF_SEDEN4_EVT105EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT105EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT106EN_MASK                      (0x00000200U)
#define CSL_SMSETCONF_SEDEN4_EVT106EN_SHIFT                     (9U)
#define CSL_SMSETCONF_SEDEN4_EVT106EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT106EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT107EN_MASK                      (0x00000400U)
#define CSL_SMSETCONF_SEDEN4_EVT107EN_SHIFT                     (10U)
#define CSL_SMSETCONF_SEDEN4_EVT107EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT107EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT108EN_MASK                      (0x00000800U)
#define CSL_SMSETCONF_SEDEN4_EVT108EN_SHIFT                     (11U)
#define CSL_SMSETCONF_SEDEN4_EVT108EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT108EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT109EN_MASK                      (0x00001000U)
#define CSL_SMSETCONF_SEDEN4_EVT109EN_SHIFT                     (12U)
#define CSL_SMSETCONF_SEDEN4_EVT109EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT109EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT110EN_MASK                      (0x00002000U)
#define CSL_SMSETCONF_SEDEN4_EVT110EN_SHIFT                     (13U)
#define CSL_SMSETCONF_SEDEN4_EVT110EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT110EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT111EN_MASK                      (0x00004000U)
#define CSL_SMSETCONF_SEDEN4_EVT111EN_SHIFT                     (14U)
#define CSL_SMSETCONF_SEDEN4_EVT111EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT111EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT112EN_MASK                      (0x00008000U)
#define CSL_SMSETCONF_SEDEN4_EVT112EN_SHIFT                     (15U)
#define CSL_SMSETCONF_SEDEN4_EVT112EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT112EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT113EN_MASK                      (0x00010000U)
#define CSL_SMSETCONF_SEDEN4_EVT113EN_SHIFT                     (16U)
#define CSL_SMSETCONF_SEDEN4_EVT113EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT113EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT114EN_MASK                      (0x00020000U)
#define CSL_SMSETCONF_SEDEN4_EVT114EN_SHIFT                     (17U)
#define CSL_SMSETCONF_SEDEN4_EVT114EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT114EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT115EN_MASK                      (0x00040000U)
#define CSL_SMSETCONF_SEDEN4_EVT115EN_SHIFT                     (18U)
#define CSL_SMSETCONF_SEDEN4_EVT115EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT115EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT116EN_MASK                      (0x00080000U)
#define CSL_SMSETCONF_SEDEN4_EVT116EN_SHIFT                     (19U)
#define CSL_SMSETCONF_SEDEN4_EVT116EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT116EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT117EN_MASK                      (0x00100000U)
#define CSL_SMSETCONF_SEDEN4_EVT117EN_SHIFT                     (20U)
#define CSL_SMSETCONF_SEDEN4_EVT117EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT117EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT118EN_MASK                      (0x00200000U)
#define CSL_SMSETCONF_SEDEN4_EVT118EN_SHIFT                     (21U)
#define CSL_SMSETCONF_SEDEN4_EVT118EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT118EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT119EN_MASK                      (0x00400000U)
#define CSL_SMSETCONF_SEDEN4_EVT119EN_SHIFT                     (22U)
#define CSL_SMSETCONF_SEDEN4_EVT119EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT119EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT120EN_MASK                      (0x00800000U)
#define CSL_SMSETCONF_SEDEN4_EVT120EN_SHIFT                     (23U)
#define CSL_SMSETCONF_SEDEN4_EVT120EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT120EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT121EN_MASK                      (0x01000000U)
#define CSL_SMSETCONF_SEDEN4_EVT121EN_SHIFT                     (24U)
#define CSL_SMSETCONF_SEDEN4_EVT121EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT121EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT122EN_MASK                      (0x02000000U)
#define CSL_SMSETCONF_SEDEN4_EVT122EN_SHIFT                     (25U)
#define CSL_SMSETCONF_SEDEN4_EVT122EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT122EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT123EN_MASK                      (0x04000000U)
#define CSL_SMSETCONF_SEDEN4_EVT123EN_SHIFT                     (26U)
#define CSL_SMSETCONF_SEDEN4_EVT123EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT123EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT124EN_MASK                      (0x08000000U)
#define CSL_SMSETCONF_SEDEN4_EVT124EN_SHIFT                     (27U)
#define CSL_SMSETCONF_SEDEN4_EVT124EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT124EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT125EN_MASK                      (0x10000000U)
#define CSL_SMSETCONF_SEDEN4_EVT125EN_SHIFT                     (28U)
#define CSL_SMSETCONF_SEDEN4_EVT125EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT125EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT126EN_MASK                      (0x20000000U)
#define CSL_SMSETCONF_SEDEN4_EVT126EN_SHIFT                     (29U)
#define CSL_SMSETCONF_SEDEN4_EVT126EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT126EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT127EN_MASK                      (0x40000000U)
#define CSL_SMSETCONF_SEDEN4_EVT127EN_SHIFT                     (30U)
#define CSL_SMSETCONF_SEDEN4_EVT127EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT127EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_EVT128EN_MASK                      (0x80000000U)
#define CSL_SMSETCONF_SEDEN4_EVT128EN_SHIFT                     (31U)
#define CSL_SMSETCONF_SEDEN4_EVT128EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN4_EVT128EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN4_RESETVAL                           (0x00000000U)

/* SEDEN5 */

#define CSL_SMSETCONF_SEDEN5_EVT129EN_MASK                      (0x00000001U)
#define CSL_SMSETCONF_SEDEN5_EVT129EN_SHIFT                     (0U)
#define CSL_SMSETCONF_SEDEN5_EVT129EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT129EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT130EN_MASK                      (0x00000002U)
#define CSL_SMSETCONF_SEDEN5_EVT130EN_SHIFT                     (1U)
#define CSL_SMSETCONF_SEDEN5_EVT130EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT130EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT131EN_MASK                      (0x00000004U)
#define CSL_SMSETCONF_SEDEN5_EVT131EN_SHIFT                     (2U)
#define CSL_SMSETCONF_SEDEN5_EVT131EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT131EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT132EN_MASK                      (0x00000008U)
#define CSL_SMSETCONF_SEDEN5_EVT132EN_SHIFT                     (3U)
#define CSL_SMSETCONF_SEDEN5_EVT132EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT132EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT133EN_MASK                      (0x00000010U)
#define CSL_SMSETCONF_SEDEN5_EVT133EN_SHIFT                     (4U)
#define CSL_SMSETCONF_SEDEN5_EVT133EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT133EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT134EN_MASK                      (0x00000020U)
#define CSL_SMSETCONF_SEDEN5_EVT134EN_SHIFT                     (5U)
#define CSL_SMSETCONF_SEDEN5_EVT134EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT134EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT135EN_MASK                      (0x00000040U)
#define CSL_SMSETCONF_SEDEN5_EVT135EN_SHIFT                     (6U)
#define CSL_SMSETCONF_SEDEN5_EVT135EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT135EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT136EN_MASK                      (0x00000080U)
#define CSL_SMSETCONF_SEDEN5_EVT136EN_SHIFT                     (7U)
#define CSL_SMSETCONF_SEDEN5_EVT136EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT136EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT137EN_MASK                      (0x00000100U)
#define CSL_SMSETCONF_SEDEN5_EVT137EN_SHIFT                     (8U)
#define CSL_SMSETCONF_SEDEN5_EVT137EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT137EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT138EN_MASK                      (0x00000200U)
#define CSL_SMSETCONF_SEDEN5_EVT138EN_SHIFT                     (9U)
#define CSL_SMSETCONF_SEDEN5_EVT138EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT138EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT139EN_MASK                      (0x00000400U)
#define CSL_SMSETCONF_SEDEN5_EVT139EN_SHIFT                     (10U)
#define CSL_SMSETCONF_SEDEN5_EVT139EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT139EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT140EN_MASK                      (0x00000800U)
#define CSL_SMSETCONF_SEDEN5_EVT140EN_SHIFT                     (11U)
#define CSL_SMSETCONF_SEDEN5_EVT140EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT140EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT141EN_MASK                      (0x00001000U)
#define CSL_SMSETCONF_SEDEN5_EVT141EN_SHIFT                     (12U)
#define CSL_SMSETCONF_SEDEN5_EVT141EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT141EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT142EN_MASK                      (0x00002000U)
#define CSL_SMSETCONF_SEDEN5_EVT142EN_SHIFT                     (13U)
#define CSL_SMSETCONF_SEDEN5_EVT142EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT142EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT143EN_MASK                      (0x00004000U)
#define CSL_SMSETCONF_SEDEN5_EVT143EN_SHIFT                     (14U)
#define CSL_SMSETCONF_SEDEN5_EVT143EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT143EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT144EN_MASK                      (0x00008000U)
#define CSL_SMSETCONF_SEDEN5_EVT144EN_SHIFT                     (15U)
#define CSL_SMSETCONF_SEDEN5_EVT144EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT144EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT145EN_MASK                      (0x00010000U)
#define CSL_SMSETCONF_SEDEN5_EVT145EN_SHIFT                     (16U)
#define CSL_SMSETCONF_SEDEN5_EVT145EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT145EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT146EN_MASK                      (0x00020000U)
#define CSL_SMSETCONF_SEDEN5_EVT146EN_SHIFT                     (17U)
#define CSL_SMSETCONF_SEDEN5_EVT146EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT146EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT147EN_MASK                      (0x00040000U)
#define CSL_SMSETCONF_SEDEN5_EVT147EN_SHIFT                     (18U)
#define CSL_SMSETCONF_SEDEN5_EVT147EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT147EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT148EN_MASK                      (0x00080000U)
#define CSL_SMSETCONF_SEDEN5_EVT148EN_SHIFT                     (19U)
#define CSL_SMSETCONF_SEDEN5_EVT148EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT148EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT149EN_MASK                      (0x00100000U)
#define CSL_SMSETCONF_SEDEN5_EVT149EN_SHIFT                     (20U)
#define CSL_SMSETCONF_SEDEN5_EVT149EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT149EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT150EN_MASK                      (0x00200000U)
#define CSL_SMSETCONF_SEDEN5_EVT150EN_SHIFT                     (21U)
#define CSL_SMSETCONF_SEDEN5_EVT150EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT150EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT151EN_MASK                      (0x00400000U)
#define CSL_SMSETCONF_SEDEN5_EVT151EN_SHIFT                     (22U)
#define CSL_SMSETCONF_SEDEN5_EVT151EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT151EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT152EN_MASK                      (0x00800000U)
#define CSL_SMSETCONF_SEDEN5_EVT152EN_SHIFT                     (23U)
#define CSL_SMSETCONF_SEDEN5_EVT152EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT152EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT153EN_MASK                      (0x01000000U)
#define CSL_SMSETCONF_SEDEN5_EVT153EN_SHIFT                     (24U)
#define CSL_SMSETCONF_SEDEN5_EVT153EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT153EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT154EN_MASK                      (0x02000000U)
#define CSL_SMSETCONF_SEDEN5_EVT154EN_SHIFT                     (25U)
#define CSL_SMSETCONF_SEDEN5_EVT154EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT154EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT155EN_MASK                      (0x04000000U)
#define CSL_SMSETCONF_SEDEN5_EVT155EN_SHIFT                     (26U)
#define CSL_SMSETCONF_SEDEN5_EVT155EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT155EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT156EN_MASK                      (0x08000000U)
#define CSL_SMSETCONF_SEDEN5_EVT156EN_SHIFT                     (27U)
#define CSL_SMSETCONF_SEDEN5_EVT156EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT156EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT157EN_MASK                      (0x10000000U)
#define CSL_SMSETCONF_SEDEN5_EVT157EN_SHIFT                     (28U)
#define CSL_SMSETCONF_SEDEN5_EVT157EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT157EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT158EN_MASK                      (0x20000000U)
#define CSL_SMSETCONF_SEDEN5_EVT158EN_SHIFT                     (29U)
#define CSL_SMSETCONF_SEDEN5_EVT158EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT158EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT159EN_MASK                      (0x40000000U)
#define CSL_SMSETCONF_SEDEN5_EVT159EN_SHIFT                     (30U)
#define CSL_SMSETCONF_SEDEN5_EVT159EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT159EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_EVT160EN_MASK                      (0x80000000U)
#define CSL_SMSETCONF_SEDEN5_EVT160EN_SHIFT                     (31U)
#define CSL_SMSETCONF_SEDEN5_EVT160EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN5_EVT160EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN5_RESETVAL                           (0x00000000U)

/* SEDEN6 */

#define CSL_SMSETCONF_SEDEN6_EVT161EN_MASK                      (0x00000001U)
#define CSL_SMSETCONF_SEDEN6_EVT161EN_SHIFT                     (0U)
#define CSL_SMSETCONF_SEDEN6_EVT161EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT161EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT162EN_MASK                      (0x00000002U)
#define CSL_SMSETCONF_SEDEN6_EVT162EN_SHIFT                     (1U)
#define CSL_SMSETCONF_SEDEN6_EVT162EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT162EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT163EN_MASK                      (0x00000004U)
#define CSL_SMSETCONF_SEDEN6_EVT163EN_SHIFT                     (2U)
#define CSL_SMSETCONF_SEDEN6_EVT163EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT163EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT164EN_MASK                      (0x00000008U)
#define CSL_SMSETCONF_SEDEN6_EVT164EN_SHIFT                     (3U)
#define CSL_SMSETCONF_SEDEN6_EVT164EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT164EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT165EN_MASK                      (0x00000010U)
#define CSL_SMSETCONF_SEDEN6_EVT165EN_SHIFT                     (4U)
#define CSL_SMSETCONF_SEDEN6_EVT165EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT165EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT166EN_MASK                      (0x00000020U)
#define CSL_SMSETCONF_SEDEN6_EVT166EN_SHIFT                     (5U)
#define CSL_SMSETCONF_SEDEN6_EVT166EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT166EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT167EN_MASK                      (0x00000040U)
#define CSL_SMSETCONF_SEDEN6_EVT167EN_SHIFT                     (6U)
#define CSL_SMSETCONF_SEDEN6_EVT167EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT167EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT168EN_MASK                      (0x00000080U)
#define CSL_SMSETCONF_SEDEN6_EVT168EN_SHIFT                     (7U)
#define CSL_SMSETCONF_SEDEN6_EVT168EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT168EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT169EN_MASK                      (0x00000100U)
#define CSL_SMSETCONF_SEDEN6_EVT169EN_SHIFT                     (8U)
#define CSL_SMSETCONF_SEDEN6_EVT169EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT169EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT170EN_MASK                      (0x00000200U)
#define CSL_SMSETCONF_SEDEN6_EVT170EN_SHIFT                     (9U)
#define CSL_SMSETCONF_SEDEN6_EVT170EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT170EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT171EN_MASK                      (0x00000400U)
#define CSL_SMSETCONF_SEDEN6_EVT171EN_SHIFT                     (10U)
#define CSL_SMSETCONF_SEDEN6_EVT171EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT171EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT172EN_MASK                      (0x00000800U)
#define CSL_SMSETCONF_SEDEN6_EVT172EN_SHIFT                     (11U)
#define CSL_SMSETCONF_SEDEN6_EVT172EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT172EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT173EN_MASK                      (0x00001000U)
#define CSL_SMSETCONF_SEDEN6_EVT173EN_SHIFT                     (12U)
#define CSL_SMSETCONF_SEDEN6_EVT173EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT173EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT174EN_MASK                      (0x00002000U)
#define CSL_SMSETCONF_SEDEN6_EVT174EN_SHIFT                     (13U)
#define CSL_SMSETCONF_SEDEN6_EVT174EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT174EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT175EN_MASK                      (0x00004000U)
#define CSL_SMSETCONF_SEDEN6_EVT175EN_SHIFT                     (14U)
#define CSL_SMSETCONF_SEDEN6_EVT175EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT175EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT176EN_MASK                      (0x00008000U)
#define CSL_SMSETCONF_SEDEN6_EVT176EN_SHIFT                     (15U)
#define CSL_SMSETCONF_SEDEN6_EVT176EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT176EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT177EN_MASK                      (0x00010000U)
#define CSL_SMSETCONF_SEDEN6_EVT177EN_SHIFT                     (16U)
#define CSL_SMSETCONF_SEDEN6_EVT177EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT177EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT178EN_MASK                      (0x00020000U)
#define CSL_SMSETCONF_SEDEN6_EVT178EN_SHIFT                     (17U)
#define CSL_SMSETCONF_SEDEN6_EVT178EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT178EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT179EN_MASK                      (0x00040000U)
#define CSL_SMSETCONF_SEDEN6_EVT179EN_SHIFT                     (18U)
#define CSL_SMSETCONF_SEDEN6_EVT179EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT179EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT180EN_MASK                      (0x00080000U)
#define CSL_SMSETCONF_SEDEN6_EVT180EN_SHIFT                     (19U)
#define CSL_SMSETCONF_SEDEN6_EVT180EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT180EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT181EN_MASK                      (0x00100000U)
#define CSL_SMSETCONF_SEDEN6_EVT181EN_SHIFT                     (20U)
#define CSL_SMSETCONF_SEDEN6_EVT181EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT181EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT182EN_MASK                      (0x00200000U)
#define CSL_SMSETCONF_SEDEN6_EVT182EN_SHIFT                     (21U)
#define CSL_SMSETCONF_SEDEN6_EVT182EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT182EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT183EN_MASK                      (0x00400000U)
#define CSL_SMSETCONF_SEDEN6_EVT183EN_SHIFT                     (22U)
#define CSL_SMSETCONF_SEDEN6_EVT183EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT183EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT184EN_MASK                      (0x00800000U)
#define CSL_SMSETCONF_SEDEN6_EVT184EN_SHIFT                     (23U)
#define CSL_SMSETCONF_SEDEN6_EVT184EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT184EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT185EN_MASK                      (0x01000000U)
#define CSL_SMSETCONF_SEDEN6_EVT185EN_SHIFT                     (24U)
#define CSL_SMSETCONF_SEDEN6_EVT185EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT185EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT186EN_MASK                      (0x02000000U)
#define CSL_SMSETCONF_SEDEN6_EVT186EN_SHIFT                     (25U)
#define CSL_SMSETCONF_SEDEN6_EVT186EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT186EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT187EN_MASK                      (0x04000000U)
#define CSL_SMSETCONF_SEDEN6_EVT187EN_SHIFT                     (26U)
#define CSL_SMSETCONF_SEDEN6_EVT187EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT187EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT188EN_MASK                      (0x08000000U)
#define CSL_SMSETCONF_SEDEN6_EVT188EN_SHIFT                     (27U)
#define CSL_SMSETCONF_SEDEN6_EVT188EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT188EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT189EN_MASK                      (0x10000000U)
#define CSL_SMSETCONF_SEDEN6_EVT189EN_SHIFT                     (28U)
#define CSL_SMSETCONF_SEDEN6_EVT189EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT189EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT190EN_MASK                      (0x20000000U)
#define CSL_SMSETCONF_SEDEN6_EVT190EN_SHIFT                     (29U)
#define CSL_SMSETCONF_SEDEN6_EVT190EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT190EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT191EN_MASK                      (0x40000000U)
#define CSL_SMSETCONF_SEDEN6_EVT191EN_SHIFT                     (30U)
#define CSL_SMSETCONF_SEDEN6_EVT191EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT191EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_EVT192EN_MASK                      (0x80000000U)
#define CSL_SMSETCONF_SEDEN6_EVT192EN_SHIFT                     (31U)
#define CSL_SMSETCONF_SEDEN6_EVT192EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN6_EVT192EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN6_RESETVAL                           (0x00000000U)

/* SEDEN7 */

#define CSL_SMSETCONF_SEDEN7_EVT193EN_MASK                      (0x00000001U)
#define CSL_SMSETCONF_SEDEN7_EVT193EN_SHIFT                     (0U)
#define CSL_SMSETCONF_SEDEN7_EVT193EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT193EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT194EN_MASK                      (0x00000002U)
#define CSL_SMSETCONF_SEDEN7_EVT194EN_SHIFT                     (1U)
#define CSL_SMSETCONF_SEDEN7_EVT194EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT194EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT195EN_MASK                      (0x00000004U)
#define CSL_SMSETCONF_SEDEN7_EVT195EN_SHIFT                     (2U)
#define CSL_SMSETCONF_SEDEN7_EVT195EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT195EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT196EN_MASK                      (0x00000008U)
#define CSL_SMSETCONF_SEDEN7_EVT196EN_SHIFT                     (3U)
#define CSL_SMSETCONF_SEDEN7_EVT196EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT196EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT197EN_MASK                      (0x00000010U)
#define CSL_SMSETCONF_SEDEN7_EVT197EN_SHIFT                     (4U)
#define CSL_SMSETCONF_SEDEN7_EVT197EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT197EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT198EN_MASK                      (0x00000020U)
#define CSL_SMSETCONF_SEDEN7_EVT198EN_SHIFT                     (5U)
#define CSL_SMSETCONF_SEDEN7_EVT198EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT198EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT199EN_MASK                      (0x00000040U)
#define CSL_SMSETCONF_SEDEN7_EVT199EN_SHIFT                     (6U)
#define CSL_SMSETCONF_SEDEN7_EVT199EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT199EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT200EN_MASK                      (0x00000080U)
#define CSL_SMSETCONF_SEDEN7_EVT200EN_SHIFT                     (7U)
#define CSL_SMSETCONF_SEDEN7_EVT200EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT200EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT201EN_MASK                      (0x00000100U)
#define CSL_SMSETCONF_SEDEN7_EVT201EN_SHIFT                     (8U)
#define CSL_SMSETCONF_SEDEN7_EVT201EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT201EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT202EN_MASK                      (0x00000200U)
#define CSL_SMSETCONF_SEDEN7_EVT202EN_SHIFT                     (9U)
#define CSL_SMSETCONF_SEDEN7_EVT202EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT202EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT203EN_MASK                      (0x00000400U)
#define CSL_SMSETCONF_SEDEN7_EVT203EN_SHIFT                     (10U)
#define CSL_SMSETCONF_SEDEN7_EVT203EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT203EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT204EN_MASK                      (0x00000800U)
#define CSL_SMSETCONF_SEDEN7_EVT204EN_SHIFT                     (11U)
#define CSL_SMSETCONF_SEDEN7_EVT204EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT204EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT205EN_MASK                      (0x00001000U)
#define CSL_SMSETCONF_SEDEN7_EVT205EN_SHIFT                     (12U)
#define CSL_SMSETCONF_SEDEN7_EVT205EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT205EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT206EN_MASK                      (0x00002000U)
#define CSL_SMSETCONF_SEDEN7_EVT206EN_SHIFT                     (13U)
#define CSL_SMSETCONF_SEDEN7_EVT206EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT206EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT207EN_MASK                      (0x00004000U)
#define CSL_SMSETCONF_SEDEN7_EVT207EN_SHIFT                     (14U)
#define CSL_SMSETCONF_SEDEN7_EVT207EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT207EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT208EN_MASK                      (0x00008000U)
#define CSL_SMSETCONF_SEDEN7_EVT208EN_SHIFT                     (15U)
#define CSL_SMSETCONF_SEDEN7_EVT208EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT208EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT209EN_MASK                      (0x00010000U)
#define CSL_SMSETCONF_SEDEN7_EVT209EN_SHIFT                     (16U)
#define CSL_SMSETCONF_SEDEN7_EVT209EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT209EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT210EN_MASK                      (0x00020000U)
#define CSL_SMSETCONF_SEDEN7_EVT210EN_SHIFT                     (17U)
#define CSL_SMSETCONF_SEDEN7_EVT210EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT210EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT211EN_MASK                      (0x00040000U)
#define CSL_SMSETCONF_SEDEN7_EVT211EN_SHIFT                     (18U)
#define CSL_SMSETCONF_SEDEN7_EVT211EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT211EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT212EN_MASK                      (0x00080000U)
#define CSL_SMSETCONF_SEDEN7_EVT212EN_SHIFT                     (19U)
#define CSL_SMSETCONF_SEDEN7_EVT212EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT212EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT213EN_MASK                      (0x00100000U)
#define CSL_SMSETCONF_SEDEN7_EVT213EN_SHIFT                     (20U)
#define CSL_SMSETCONF_SEDEN7_EVT213EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT213EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT214EN_MASK                      (0x00200000U)
#define CSL_SMSETCONF_SEDEN7_EVT214EN_SHIFT                     (21U)
#define CSL_SMSETCONF_SEDEN7_EVT214EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT214EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT215EN_MASK                      (0x00400000U)
#define CSL_SMSETCONF_SEDEN7_EVT215EN_SHIFT                     (22U)
#define CSL_SMSETCONF_SEDEN7_EVT215EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT215EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT216EN_MASK                      (0x00800000U)
#define CSL_SMSETCONF_SEDEN7_EVT216EN_SHIFT                     (23U)
#define CSL_SMSETCONF_SEDEN7_EVT216EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT216EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT217EN_MASK                      (0x01000000U)
#define CSL_SMSETCONF_SEDEN7_EVT217EN_SHIFT                     (24U)
#define CSL_SMSETCONF_SEDEN7_EVT217EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT217EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT218EN_MASK                      (0x02000000U)
#define CSL_SMSETCONF_SEDEN7_EVT218EN_SHIFT                     (25U)
#define CSL_SMSETCONF_SEDEN7_EVT218EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT218EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT219EN_MASK                      (0x04000000U)
#define CSL_SMSETCONF_SEDEN7_EVT219EN_SHIFT                     (26U)
#define CSL_SMSETCONF_SEDEN7_EVT219EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT219EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT220EN_MASK                      (0x08000000U)
#define CSL_SMSETCONF_SEDEN7_EVT220EN_SHIFT                     (27U)
#define CSL_SMSETCONF_SEDEN7_EVT220EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT220EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT221EN_MASK                      (0x10000000U)
#define CSL_SMSETCONF_SEDEN7_EVT221EN_SHIFT                     (28U)
#define CSL_SMSETCONF_SEDEN7_EVT221EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT221EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT222EN_MASK                      (0x20000000U)
#define CSL_SMSETCONF_SEDEN7_EVT222EN_SHIFT                     (29U)
#define CSL_SMSETCONF_SEDEN7_EVT222EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT222EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT223EN_MASK                      (0x40000000U)
#define CSL_SMSETCONF_SEDEN7_EVT223EN_SHIFT                     (30U)
#define CSL_SMSETCONF_SEDEN7_EVT223EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT223EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_EVT224EN_MASK                      (0x80000000U)
#define CSL_SMSETCONF_SEDEN7_EVT224EN_SHIFT                     (31U)
#define CSL_SMSETCONF_SEDEN7_EVT224EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN7_EVT224EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN7_RESETVAL                           (0x00000000U)

/* SEDEN8 */

#define CSL_SMSETCONF_SEDEN8_EVT225EN_MASK                      (0x00000001U)
#define CSL_SMSETCONF_SEDEN8_EVT225EN_SHIFT                     (0U)
#define CSL_SMSETCONF_SEDEN8_EVT225EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT225EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT226EN_MASK                      (0x00000002U)
#define CSL_SMSETCONF_SEDEN8_EVT226EN_SHIFT                     (1U)
#define CSL_SMSETCONF_SEDEN8_EVT226EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT226EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT227EN_MASK                      (0x00000004U)
#define CSL_SMSETCONF_SEDEN8_EVT227EN_SHIFT                     (2U)
#define CSL_SMSETCONF_SEDEN8_EVT227EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT227EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT228EN_MASK                      (0x00000008U)
#define CSL_SMSETCONF_SEDEN8_EVT228EN_SHIFT                     (3U)
#define CSL_SMSETCONF_SEDEN8_EVT228EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT228EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT229EN_MASK                      (0x00000010U)
#define CSL_SMSETCONF_SEDEN8_EVT229EN_SHIFT                     (4U)
#define CSL_SMSETCONF_SEDEN8_EVT229EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT229EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT230EN_MASK                      (0x00000020U)
#define CSL_SMSETCONF_SEDEN8_EVT230EN_SHIFT                     (5U)
#define CSL_SMSETCONF_SEDEN8_EVT230EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT230EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT231EN_MASK                      (0x00000040U)
#define CSL_SMSETCONF_SEDEN8_EVT231EN_SHIFT                     (6U)
#define CSL_SMSETCONF_SEDEN8_EVT231EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT231EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT232EN_MASK                      (0x00000080U)
#define CSL_SMSETCONF_SEDEN8_EVT232EN_SHIFT                     (7U)
#define CSL_SMSETCONF_SEDEN8_EVT232EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT232EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT233EN_MASK                      (0x00000100U)
#define CSL_SMSETCONF_SEDEN8_EVT233EN_SHIFT                     (8U)
#define CSL_SMSETCONF_SEDEN8_EVT233EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT233EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT234EN_MASK                      (0x00000200U)
#define CSL_SMSETCONF_SEDEN8_EVT234EN_SHIFT                     (9U)
#define CSL_SMSETCONF_SEDEN8_EVT234EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT234EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT235EN_MASK                      (0x00000400U)
#define CSL_SMSETCONF_SEDEN8_EVT235EN_SHIFT                     (10U)
#define CSL_SMSETCONF_SEDEN8_EVT235EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT235EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT236EN_MASK                      (0x00000800U)
#define CSL_SMSETCONF_SEDEN8_EVT236EN_SHIFT                     (11U)
#define CSL_SMSETCONF_SEDEN8_EVT236EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT236EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT237EN_MASK                      (0x00001000U)
#define CSL_SMSETCONF_SEDEN8_EVT237EN_SHIFT                     (12U)
#define CSL_SMSETCONF_SEDEN8_EVT237EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT237EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT238EN_MASK                      (0x00002000U)
#define CSL_SMSETCONF_SEDEN8_EVT238EN_SHIFT                     (13U)
#define CSL_SMSETCONF_SEDEN8_EVT238EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT238EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT239EN_MASK                      (0x00004000U)
#define CSL_SMSETCONF_SEDEN8_EVT239EN_SHIFT                     (14U)
#define CSL_SMSETCONF_SEDEN8_EVT239EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT239EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT240EN_MASK                      (0x00008000U)
#define CSL_SMSETCONF_SEDEN8_EVT240EN_SHIFT                     (15U)
#define CSL_SMSETCONF_SEDEN8_EVT240EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT240EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT241EN_MASK                      (0x00010000U)
#define CSL_SMSETCONF_SEDEN8_EVT241EN_SHIFT                     (16U)
#define CSL_SMSETCONF_SEDEN8_EVT241EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT241EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT242EN_MASK                      (0x00020000U)
#define CSL_SMSETCONF_SEDEN8_EVT242EN_SHIFT                     (17U)
#define CSL_SMSETCONF_SEDEN8_EVT242EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT242EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT243EN_MASK                      (0x00040000U)
#define CSL_SMSETCONF_SEDEN8_EVT243EN_SHIFT                     (18U)
#define CSL_SMSETCONF_SEDEN8_EVT243EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT243EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT244EN_MASK                      (0x00080000U)
#define CSL_SMSETCONF_SEDEN8_EVT244EN_SHIFT                     (19U)
#define CSL_SMSETCONF_SEDEN8_EVT244EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT244EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT245EN_MASK                      (0x00100000U)
#define CSL_SMSETCONF_SEDEN8_EVT245EN_SHIFT                     (20U)
#define CSL_SMSETCONF_SEDEN8_EVT245EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT245EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT246EN_MASK                      (0x00200000U)
#define CSL_SMSETCONF_SEDEN8_EVT246EN_SHIFT                     (21U)
#define CSL_SMSETCONF_SEDEN8_EVT246EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT246EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT247EN_MASK                      (0x00400000U)
#define CSL_SMSETCONF_SEDEN8_EVT247EN_SHIFT                     (22U)
#define CSL_SMSETCONF_SEDEN8_EVT247EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT247EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT248EN_MASK                      (0x00800000U)
#define CSL_SMSETCONF_SEDEN8_EVT248EN_SHIFT                     (23U)
#define CSL_SMSETCONF_SEDEN8_EVT248EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT248EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT249EN_MASK                      (0x01000000U)
#define CSL_SMSETCONF_SEDEN8_EVT249EN_SHIFT                     (24U)
#define CSL_SMSETCONF_SEDEN8_EVT249EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT249EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT250EN_MASK                      (0x02000000U)
#define CSL_SMSETCONF_SEDEN8_EVT250EN_SHIFT                     (25U)
#define CSL_SMSETCONF_SEDEN8_EVT250EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT250EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT251EN_MASK                      (0x04000000U)
#define CSL_SMSETCONF_SEDEN8_EVT251EN_SHIFT                     (26U)
#define CSL_SMSETCONF_SEDEN8_EVT251EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT251EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT252EN_MASK                      (0x08000000U)
#define CSL_SMSETCONF_SEDEN8_EVT252EN_SHIFT                     (27U)
#define CSL_SMSETCONF_SEDEN8_EVT252EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT252EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT253EN_MASK                      (0x10000000U)
#define CSL_SMSETCONF_SEDEN8_EVT253EN_SHIFT                     (28U)
#define CSL_SMSETCONF_SEDEN8_EVT253EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT253EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT254EN_MASK                      (0x20000000U)
#define CSL_SMSETCONF_SEDEN8_EVT254EN_SHIFT                     (29U)
#define CSL_SMSETCONF_SEDEN8_EVT254EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT254EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_EVT255EN_MASK                      (0x40000000U)
#define CSL_SMSETCONF_SEDEN8_EVT255EN_SHIFT                     (30U)
#define CSL_SMSETCONF_SEDEN8_EVT255EN_RESETVAL                  (0x00000000U)
#define CSL_SMSETCONF_SEDEN8_EVT255EN_MAX                       (0x00000001U)

#define CSL_SMSETCONF_SEDEN8_RESETVAL                           (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif

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
#ifndef CSLR_CSCTI_H_
#define CSLR_CSCTI_H_

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
    volatile Uint32 CTICONTROL;
    volatile Uint8  RSVD0[12];
    volatile Uint32 CTIINTACK;
    volatile Uint32 CTIAPPSET;
    volatile Uint32 CTIAPPCLR;
    volatile Uint32 CTIAPPPULSE;
    volatile Uint32 CTIINEN0;
    volatile Uint32 CTIINEN1;
    volatile Uint32 CTIINEN2;
    volatile Uint32 CTIINEN3;
    volatile Uint32 CTIINEN4;
    volatile Uint32 CTIINEN5;
    volatile Uint32 CTIINEN6;
    volatile Uint32 CTIINEN7;
    volatile Uint8  RSVD1[96];
    volatile Uint32 CTIOUTEN0;
    volatile Uint32 CTIOUTEN1;
    volatile Uint32 CTIOUTEN2;
    volatile Uint32 CTIOUTEN3;
    volatile Uint32 CTIOUTEN4;
    volatile Uint32 CTIOUTEN5;
    volatile Uint32 CTIOUTEN6;
    volatile Uint32 CTIOUTEN7;
    volatile Uint8  RSVD2[112];
    volatile Uint32 CTITRIGINSTATUS;
    volatile Uint32 CTITRIGOUTSTATUS;
    volatile Uint32 CTICHINSTATUS;
    volatile Uint32 CTICHOUTSTATUS;
    volatile Uint32 CTIGATE;
    volatile Uint32 ASICCTL;
    volatile Uint8  RSVD3[3476];
    volatile Uint32 ITCHINACK;
    volatile Uint32 ITTRIGINACK;
    volatile Uint32 ITCHOUT;
    volatile Uint32 ITTRIGOUT;
    volatile Uint32 ITCHOUTACK;
    volatile Uint32 ITTRIGOUTACK;
    volatile Uint32 ITCHIN;
    volatile Uint32 ITTRIGIN;
    volatile Uint8  RSVD4[4];
    volatile Uint32 ITCTRL;
    volatile Uint8  RSVD5[156];
    volatile Uint32 CLAIMSET;
    volatile Uint32 CLAIMCLR;
    volatile Uint8  RSVD6[8];
    volatile Uint32 LOCKACCESS;
    volatile Uint32 LOCKSTATUS;
    volatile Uint32 AUTHSTATUS;
    volatile Uint8  RSVD7[12];
    volatile Uint32 DEVID;
    volatile Uint32 DEVTYPE;
    volatile Uint32 PERIPHID4;
    volatile Uint32 PERIPHID5;
    volatile Uint32 PERIPHID6;
    volatile Uint32 PERIPHID7;
    volatile Uint32 PERIPHID0;
    volatile Uint32 PERIPHID1;
    volatile Uint32 PERIPHID2;
    volatile Uint32 PERIPHID3;
    volatile Uint32 COMPONID0;
    volatile Uint32 COMPONID1;
    volatile Uint32 COMPONID2;
    volatile Uint32 COMPONID3;
} CSL_CsctiRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* GLBEN */
#define CSL_CSCTI_CTICONTROL                                    (0x0U)

/* The CTI Interrupt Acknowledge Register is write-only. Any bits written as a
 * 1 cause the CTITRIGOUT output signal to be acknowledged. The
 * acknowledgement is cleared when MAPTRIGOUT is deactivated. This register is
 * used when the CTITRIGOUT is used as a sticky output, that is, no hardware
 * acknowledge is supplied, and a software acknowledge is required. */
#define CSL_CSCTI_CTIINTACK                                     (0x10U)

/* The CTI Application Trigger Set Register is read/write. A write to this
 * register causes a channel event to be raised, corresponding to the bit
 * written t */
#define CSL_CSCTI_CTIAPPSET                                     (0x14U)

/* CTIAPPCLR */
#define CSL_CSCTI_CTIAPPCLR                                     (0x18U)

/* The CTI Application Pulse Register is write-only. A write to this register
 * causes a channel event pulse, one CTICLK period, to be generated,
 * corresponding to the bit written to. The pulse external to the ECT can be
 * extended to multi-cycle by the handshaking interface circuits. This
 * register clears itself immediately, so it can be repeatedly written to
 * without software having to clear it. */
#define CSL_CSCTI_CTIAPPPULSE                                   (0x1CU)

/* The CTI Trigger to Channel Enable Registers enable the signalling of an
 * event on CTM channels when the core issues a trigger, CTITRIGIN, to the
 * CTI. There is one register for each of the eight CTITRIGIN inputs. Within
 * each register there is one bit for each of the four channels implemented.
 * These registers do not affect the application trigger operations. */
#define CSL_CSCTI_CTIINEN0                                      (0x20U)

/* The CTI Trigger to Channel Enable Registers enable the signalling of an
 * event on CTM channels when the core issues a trigger, CTITRIGIN, to the
 * CTI. There is one register for each of the eight CTITRIGIN inputs. Within
 * each register there is one bit for each of the four channels implemented.
 * These registers do not affect the application trigger operations. */
#define CSL_CSCTI_CTIINEN1                                      (0x24U)

/* The CTI Trigger to Channel Enable Registers enable the signalling of an
 * event on CTM channels when the core issues a trigger, CTITRIGIN, to the
 * CTI. There is one register for each of the eight CTITRIGIN inputs. Within
 * each register there is one bit for each of the four channels implemented.
 * These registers do not affect the application trigger operations. */
#define CSL_CSCTI_CTIINEN2                                      (0x28U)

/* The CTI Trigger to Channel Enable Registers enable the signalling of an
 * event on CTM channels when the core issues a trigger, CTITRIGIN, to the
 * CTI. There is one register for each of the eight CTITRIGIN inputs. Within
 * each register there is one bit for each of the four channels implemented.
 * These registers do not affect the application trigger operations. */
#define CSL_CSCTI_CTIINEN3                                      (0x2CU)

/* The CTI Trigger to Channel Enable Registers enable the signalling of an
 * event on CTM channels when the core issues a trigger, CTITRIGIN, to the
 * CTI. There is one register for each of the eight CTITRIGIN inputs. Within
 * each register there is one bit for each of the four channels implemented.
 * These registers do not affect the application trigger operations. */
#define CSL_CSCTI_CTIINEN4                                      (0x30U)

/* The CTI Trigger to Channel Enable Registers enable the signalling of an
 * event on CTM channels when the core issues a trigger, CTITRIGIN, to the
 * CTI. There is one register for each of the eight CTITRIGIN inputs. Within
 * each register there is one bit for each of the four channels implemented.
 * These registers do not affect the application trigger operations. */
#define CSL_CSCTI_CTIINEN5                                      (0x34U)

/* The CTI Trigger to Channel Enable Registers enable the signalling of an
 * event on CTM channels when the core issues a trigger, CTITRIGIN, to the
 * CTI. There is one register for each of the eight CTITRIGIN inputs. Within
 * each register there is one bit for each of the four channels implemented.
 * These registers do not affect the application trigger operations. */
#define CSL_CSCTI_CTIINEN6                                      (0x38U)

/* The CTI Trigger to Channel Enable Registers enable the signalling of an
 * event on CTM channels when the core issues a trigger, CTITRIGIN, to the
 * CTI. There is one register for each of the eight CTITRIGIN inputs. Within
 * each register there is one bit for each of the four channels implemented.
 * These registers do not affect the application trigger operations. */
#define CSL_CSCTI_CTIINEN7                                      (0x3CU)

/* The CTI Channel to Trigger Enable Registers define which channels can
 * generate a CTITRIGOUT output. There is one register for each of the eight
 * CTITRIGOUT outputs. Within each register there is one bit for each of the
 * four channels implemented. These registers affect the mapping from
 * application trigger to trigger outputs. */
#define CSL_CSCTI_CTIOUTEN0                                     (0xA0U)

/* The CTI Channel to Trigger Enable Registers define which channels can
 * generate a CTITRIGOUT output. There is one register for each of the eight
 * CTITRIGOUT outputs. Within each register there is one bit for each of the
 * four channels implemented. These registers affect the mapping from
 * application trigger to trigger outputs. */
#define CSL_CSCTI_CTIOUTEN1                                     (0xA4U)

/* The CTI Channel to Trigger Enable Registers define which channels can
 * generate a CTITRIGOUT output. There is one register for each of the eight
 * CTITRIGOUT outputs. Within each register there is one bit for each of the
 * four channels implemented. These registers affect the mapping from
 * application trigger to trigger outputs. */
#define CSL_CSCTI_CTIOUTEN2                                     (0xA8U)

/* The CTI Channel to Trigger Enable Registers define which channels can
 * generate a CTITRIGOUT output. There is one register for each of the eight
 * CTITRIGOUT outputs. Within each register there is one bit for each of the
 * four channels implemented. These registers affect the mapping from
 * application trigger to trigger outputs. */
#define CSL_CSCTI_CTIOUTEN3                                     (0xACU)

/* The CTI Channel to Trigger Enable Registers define which channels can
 * generate a CTITRIGOUT output. There is one register for each of the eight
 * CTITRIGOUT outputs. Within each register there is one bit for each of the
 * four channels implemented. These registers affect the mapping from
 * application trigger to trigger outputs. */
#define CSL_CSCTI_CTIOUTEN4                                     (0xB0U)

/* The CTI Channel to Trigger Enable Registers define which channels can
 * generate a CTITRIGOUT output. There is one register for each of the eight
 * CTITRIGOUT outputs. Within each register there is one bit for each of the
 * four channels implemented. These registers affect the mapping from
 * application trigger to trigger outputs. */
#define CSL_CSCTI_CTIOUTEN5                                     (0xB4U)

/* The CTI Channel to Trigger Enable Registers define which channels can
 * generate a CTITRIGOUT output. There is one register for each of the eight
 * CTITRIGOUT outputs. Within each register there is one bit for each of the
 * four channels implemented. These registers affect the mapping from
 * application trigger to trigger outputs. */
#define CSL_CSCTI_CTIOUTEN6                                     (0xB8U)

/* The CTI Channel to Trigger Enable Registers define which channels can
 * generate a CTITRIGOUT output. There is one register for each of the eight
 * CTITRIGOUT outputs. Within each register there is one bit for each of the
 * four channels implemented. These registers affect the mapping from
 * application trigger to trigger outputs. */
#define CSL_CSCTI_CTIOUTEN7                                     (0xBCU)

/* The CTI Trigger In Status Register provides the status of the CTITRIGIN
 * inputs. */
#define CSL_CSCTI_CTITRIGINSTATUS                               (0x130U)

/* The CTI Trigger Out Status Register provides the status of the CTITRIGOUT
 * outputs. */
#define CSL_CSCTI_CTITRIGOUTSTATUS                              (0x134U)

/* The CTI Channel In Status Register provides the status of the CTI CTICHIN
 * inputs. */
#define CSL_CSCTI_CTICHINSTATUS                                 (0x138U)

/* CTICHOUTSTATUS */
#define CSL_CSCTI_CTICHOUTSTATUS                                (0x13CU)

/* The Gate Enable Register prevents the channels from propagating through the
 * CTM to other CTIs. This enables local cross-triggering, for example for
 * causing an interrupt when the ETM trigger occurs. It can be used
 * effectively with CTIAPPSET, CTIAPPCLEAR, and CTIAPPPULSE for asserting
 * trigger outputs by asserting channels, without affecting the rest of the
 * system. On reset, this register is 0xF, and channel propagation is enabled. */
#define CSL_CSCTI_CTIGATE                                       (0x140U)

/* shows the bit assignments for the External Multiplexor Control Register. */
#define CSL_CSCTI_ASICCTL                                       (0x144U)

/* Set the value of the CTCHINACK outputs */
#define CSL_CSCTI_ITCHINACK                                     (0xEDCU)

/* Set the value of the CTTRIGINACK outputs */
#define CSL_CSCTI_ITTRIGINACK                                   (0xEE0U)

/* Set the value of CTCHOUT outputs */
#define CSL_CSCTI_ITCHOUT                                       (0xEE4U)

/* Set the value of CTTRIGOUT outputs */
#define CSL_CSCTI_ITTRIGOUT                                     (0xEE8U)

/* Read the values of the CTCHOUTACK inputs */
#define CSL_CSCTI_ITCHOUTACK                                    (0xEECU)

/* Read the values of the CTTRIGOUTACK inputs */
#define CSL_CSCTI_ITTRIGOUTACK                                  (0xEF0U)

/* Read the values of CTCHIN inputs */
#define CSL_CSCTI_ITCHIN                                        (0xEF4U)

/* Read the values of CTTRIGIN inputs */
#define CSL_CSCTI_ITTRIGIN                                      (0xEF8U)

/* Integration Mode Control Register */
#define CSL_CSCTI_ITCTRL                                        (0xF00U)

/* Claim Tag Set */
#define CSL_CSCTI_CLAIMSET                                      (0xFA0U)

/* Claim Tag Clear */
#define CSL_CSCTI_CLAIMCLR                                      (0xFA4U)

/* Lock Access */
#define CSL_CSCTI_LOCKACCESS                                    (0xFB0U)

/* Lock Status */
#define CSL_CSCTI_LOCKSTATUS                                    (0xFB4U)

/* Authentification status */
#define CSL_CSCTI_AUTHSTATUS                                    (0xFB8U)

/* Device ID */
#define CSL_CSCTI_DEVID                                         (0xFC8U)

/* Device type identifier */
#define CSL_CSCTI_DEVTYPE                                       (0xFCCU)

/* Peripheral ID4 */
#define CSL_CSCTI_PERIPHID4                                     (0xFD0U)

/* Peripheral ID5 */
#define CSL_CSCTI_PERIPHID5                                     (0xFD4U)

/* Peripheral ID6 */
#define CSL_CSCTI_PERIPHID6                                     (0xFD8U)

/* Peripheral ID7 */
#define CSL_CSCTI_PERIPHID7                                     (0xFDCU)

/* Peripheral ID0 */
#define CSL_CSCTI_PERIPHID0                                     (0xFE0U)

/* Peripheral ID1 */
#define CSL_CSCTI_PERIPHID1                                     (0xFE4U)

/* Peripheral ID2 */
#define CSL_CSCTI_PERIPHID2                                     (0xFE8U)

/* Peripheral ID3 */
#define CSL_CSCTI_PERIPHID3                                     (0xFECU)

/* Component ID0 */
#define CSL_CSCTI_COMPONID0                                     (0xFF0U)

/* Component ID1 */
#define CSL_CSCTI_COMPONID1                                     (0xFF4U)

/* Component ID2 */
#define CSL_CSCTI_COMPONID2                                     (0xFF8U)

/* Component ID3 */
#define CSL_CSCTI_COMPONID3                                     (0xFFCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CTICONTROL */

#define CSL_CSCTI_CTICONTROL_GLBEN_MASK                         (0x00000001U)
#define CSL_CSCTI_CTICONTROL_GLBEN_SHIFT                        (0U)
#define CSL_CSCTI_CTICONTROL_GLBEN_RESETVAL                     (0x00000000U)
#define CSL_CSCTI_CTICONTROL_GLBEN_MAX                          (0x00000001U)

#define CSL_CSCTI_CTICONTROL_RESETVAL                           (0x00000000U)

/* CTIINTACK */

#define CSL_CSCTI_CTIINTACK_INTACK_MASK                         (0x000000FFU)
#define CSL_CSCTI_CTIINTACK_INTACK_SHIFT                        (0U)
#define CSL_CSCTI_CTIINTACK_INTACK_RESETVAL                     (0x00000000U)
#define CSL_CSCTI_CTIINTACK_INTACK_MAX                          (0x000000ffU)

#define CSL_CSCTI_CTIINTACK_RESETVAL                            (0x00000000U)

/* CTIAPPSET */

#define CSL_CSCTI_CTIAPPSET_APPSET_MASK                         (0x0000000FU)
#define CSL_CSCTI_CTIAPPSET_APPSET_SHIFT                        (0U)
#define CSL_CSCTI_CTIAPPSET_APPSET_RESETVAL                     (0x00000000U)
#define CSL_CSCTI_CTIAPPSET_APPSET_MAX                          (0x0000000fU)

#define CSL_CSCTI_CTIAPPSET_RESETVAL                            (0x00000000U)

/* CTIAPPCLR */

#define CSL_CSCTI_CTIAPPCLR_APPCLEAR_MASK                       (0x0000000FU)
#define CSL_CSCTI_CTIAPPCLR_APPCLEAR_SHIFT                      (0U)
#define CSL_CSCTI_CTIAPPCLR_APPCLEAR_RESETVAL                   (0x00000000U)
#define CSL_CSCTI_CTIAPPCLR_APPCLEAR_MAX                        (0x0000000fU)

#define CSL_CSCTI_CTIAPPCLR_RESETVAL                            (0x00000000U)

/* CTIAPPPULSE */

#define CSL_CSCTI_CTIAPPPULSE_APPULSE_MASK                      (0x0000000FU)
#define CSL_CSCTI_CTIAPPPULSE_APPULSE_SHIFT                     (0U)
#define CSL_CSCTI_CTIAPPPULSE_APPULSE_RESETVAL                  (0x00000000U)
#define CSL_CSCTI_CTIAPPPULSE_APPULSE_MAX                       (0x0000000fU)

#define CSL_CSCTI_CTIAPPPULSE_RESETVAL                          (0x00000000U)

/* CTIINEN0 */

#define CSL_CSCTI_CTIINEN0_TRIGINEN_MASK                        (0x0000000FU)
#define CSL_CSCTI_CTIINEN0_TRIGINEN_SHIFT                       (0U)
#define CSL_CSCTI_CTIINEN0_TRIGINEN_RESETVAL                    (0x00000000U)
#define CSL_CSCTI_CTIINEN0_TRIGINEN_MAX                         (0x0000000fU)

#define CSL_CSCTI_CTIINEN0_RESETVAL                             (0x00000000U)

/* CTIINEN1 */

#define CSL_CSCTI_CTIINEN1_TRIGINEN_MASK                        (0x0000000FU)
#define CSL_CSCTI_CTIINEN1_TRIGINEN_SHIFT                       (0U)
#define CSL_CSCTI_CTIINEN1_TRIGINEN_RESETVAL                    (0x00000000U)
#define CSL_CSCTI_CTIINEN1_TRIGINEN_MAX                         (0x0000000fU)

#define CSL_CSCTI_CTIINEN1_RESETVAL                             (0x00000000U)

/* CTIINEN2 */

#define CSL_CSCTI_CTIINEN2_TRIGINEN_MASK                        (0x0000000FU)
#define CSL_CSCTI_CTIINEN2_TRIGINEN_SHIFT                       (0U)
#define CSL_CSCTI_CTIINEN2_TRIGINEN_RESETVAL                    (0x00000000U)
#define CSL_CSCTI_CTIINEN2_TRIGINEN_MAX                         (0x0000000fU)

#define CSL_CSCTI_CTIINEN2_RESETVAL                             (0x00000000U)

/* CTIINEN3 */

#define CSL_CSCTI_CTIINEN3_TRIGINEN_MASK                        (0x0000000FU)
#define CSL_CSCTI_CTIINEN3_TRIGINEN_SHIFT                       (0U)
#define CSL_CSCTI_CTIINEN3_TRIGINEN_RESETVAL                    (0x00000000U)
#define CSL_CSCTI_CTIINEN3_TRIGINEN_MAX                         (0x0000000fU)

#define CSL_CSCTI_CTIINEN3_RESETVAL                             (0x00000000U)

/* CTIINEN4 */

#define CSL_CSCTI_CTIINEN4_TRIGINEN_MASK                        (0x0000000FU)
#define CSL_CSCTI_CTIINEN4_TRIGINEN_SHIFT                       (0U)
#define CSL_CSCTI_CTIINEN4_TRIGINEN_RESETVAL                    (0x00000000U)
#define CSL_CSCTI_CTIINEN4_TRIGINEN_MAX                         (0x0000000fU)

#define CSL_CSCTI_CTIINEN4_RESETVAL                             (0x00000000U)

/* CTIINEN5 */

#define CSL_CSCTI_CTIINEN5_TRIGINEN_MASK                        (0x0000000FU)
#define CSL_CSCTI_CTIINEN5_TRIGINEN_SHIFT                       (0U)
#define CSL_CSCTI_CTIINEN5_TRIGINEN_RESETVAL                    (0x00000000U)
#define CSL_CSCTI_CTIINEN5_TRIGINEN_MAX                         (0x0000000fU)

#define CSL_CSCTI_CTIINEN5_RESETVAL                             (0x00000000U)

/* CTIINEN6 */

#define CSL_CSCTI_CTIINEN6_TRIGINEN_MASK                        (0x0000000FU)
#define CSL_CSCTI_CTIINEN6_TRIGINEN_SHIFT                       (0U)
#define CSL_CSCTI_CTIINEN6_TRIGINEN_RESETVAL                    (0x00000000U)
#define CSL_CSCTI_CTIINEN6_TRIGINEN_MAX                         (0x0000000fU)

#define CSL_CSCTI_CTIINEN6_RESETVAL                             (0x00000000U)

/* CTIINEN7 */

#define CSL_CSCTI_CTIINEN7_TRIGINEN_MASK                        (0x0000000FU)
#define CSL_CSCTI_CTIINEN7_TRIGINEN_SHIFT                       (0U)
#define CSL_CSCTI_CTIINEN7_TRIGINEN_RESETVAL                    (0x00000000U)
#define CSL_CSCTI_CTIINEN7_TRIGINEN_MAX                         (0x0000000fU)

#define CSL_CSCTI_CTIINEN7_RESETVAL                             (0x00000000U)

/* CTIOUTEN0 */

#define CSL_CSCTI_CTIOUTEN0_TRIGOUTEN_MASK                      (0x0000000FU)
#define CSL_CSCTI_CTIOUTEN0_TRIGOUTEN_SHIFT                     (0U)
#define CSL_CSCTI_CTIOUTEN0_TRIGOUTEN_RESETVAL                  (0x00000000U)
#define CSL_CSCTI_CTIOUTEN0_TRIGOUTEN_MAX                       (0x0000000fU)

#define CSL_CSCTI_CTIOUTEN0_RESETVAL                            (0x00000000U)

/* CTIOUTEN1 */

#define CSL_CSCTI_CTIOUTEN1_TRIGOUTEN_MASK                      (0x0000000FU)
#define CSL_CSCTI_CTIOUTEN1_TRIGOUTEN_SHIFT                     (0U)
#define CSL_CSCTI_CTIOUTEN1_TRIGOUTEN_RESETVAL                  (0x00000000U)
#define CSL_CSCTI_CTIOUTEN1_TRIGOUTEN_MAX                       (0x0000000fU)

#define CSL_CSCTI_CTIOUTEN1_RESETVAL                            (0x00000000U)

/* CTIOUTEN2 */

#define CSL_CSCTI_CTIOUTEN2_TRIGOUTEN_MASK                      (0x0000000FU)
#define CSL_CSCTI_CTIOUTEN2_TRIGOUTEN_SHIFT                     (0U)
#define CSL_CSCTI_CTIOUTEN2_TRIGOUTEN_RESETVAL                  (0x00000000U)
#define CSL_CSCTI_CTIOUTEN2_TRIGOUTEN_MAX                       (0x0000000fU)

#define CSL_CSCTI_CTIOUTEN2_RESETVAL                            (0x00000000U)

/* CTIOUTEN3 */

#define CSL_CSCTI_CTIOUTEN3_TRIGOUTEN_MASK                      (0x0000000FU)
#define CSL_CSCTI_CTIOUTEN3_TRIGOUTEN_SHIFT                     (0U)
#define CSL_CSCTI_CTIOUTEN3_TRIGOUTEN_RESETVAL                  (0x00000000U)
#define CSL_CSCTI_CTIOUTEN3_TRIGOUTEN_MAX                       (0x0000000fU)

#define CSL_CSCTI_CTIOUTEN3_RESETVAL                            (0x00000000U)

/* CTIOUTEN4 */

#define CSL_CSCTI_CTIOUTEN4_TRIGOUTEN_MASK                      (0x0000000FU)
#define CSL_CSCTI_CTIOUTEN4_TRIGOUTEN_SHIFT                     (0U)
#define CSL_CSCTI_CTIOUTEN4_TRIGOUTEN_RESETVAL                  (0x00000000U)
#define CSL_CSCTI_CTIOUTEN4_TRIGOUTEN_MAX                       (0x0000000fU)

#define CSL_CSCTI_CTIOUTEN4_RESETVAL                            (0x00000000U)

/* CTIOUTEN5 */

#define CSL_CSCTI_CTIOUTEN5_TRIGOUTEN_MASK                      (0x0000000FU)
#define CSL_CSCTI_CTIOUTEN5_TRIGOUTEN_SHIFT                     (0U)
#define CSL_CSCTI_CTIOUTEN5_TRIGOUTEN_RESETVAL                  (0x00000000U)
#define CSL_CSCTI_CTIOUTEN5_TRIGOUTEN_MAX                       (0x0000000fU)

#define CSL_CSCTI_CTIOUTEN5_RESETVAL                            (0x00000000U)

/* CTIOUTEN6 */

#define CSL_CSCTI_CTIOUTEN6_TRIGOUTEN_MASK                      (0x0000000FU)
#define CSL_CSCTI_CTIOUTEN6_TRIGOUTEN_SHIFT                     (0U)
#define CSL_CSCTI_CTIOUTEN6_TRIGOUTEN_RESETVAL                  (0x00000000U)
#define CSL_CSCTI_CTIOUTEN6_TRIGOUTEN_MAX                       (0x0000000fU)

#define CSL_CSCTI_CTIOUTEN6_RESETVAL                            (0x00000000U)

/* CTIOUTEN7 */

#define CSL_CSCTI_CTIOUTEN7_TRIGOUTEN_MASK                      (0x0000000FU)
#define CSL_CSCTI_CTIOUTEN7_TRIGOUTEN_SHIFT                     (0U)
#define CSL_CSCTI_CTIOUTEN7_TRIGOUTEN_RESETVAL                  (0x00000000U)
#define CSL_CSCTI_CTIOUTEN7_TRIGOUTEN_MAX                       (0x0000000fU)

#define CSL_CSCTI_CTIOUTEN7_RESETVAL                            (0x00000000U)

/* CTITRIGINSTATUS */

#define CSL_CSCTI_CTITRIGINSTATUS_TRIGINSTATUS_MASK             (0x000000FFU)
#define CSL_CSCTI_CTITRIGINSTATUS_TRIGINSTATUS_SHIFT            (0U)
#define CSL_CSCTI_CTITRIGINSTATUS_TRIGINSTATUS_RESETVAL         (0x00000000U)
#define CSL_CSCTI_CTITRIGINSTATUS_TRIGINSTATUS_MAX              (0x000000ffU)

#define CSL_CSCTI_CTITRIGINSTATUS_RESETVAL                      (0x00000000U)

/* CTITRIGOUTSTATUS */

#define CSL_CSCTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_MASK           (0x000000FFU)
#define CSL_CSCTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_SHIFT          (0U)
#define CSL_CSCTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_RESETVAL       (0x00000000U)
#define CSL_CSCTI_CTITRIGOUTSTATUS_TRIGOUTSTATUS_MAX            (0x000000ffU)

#define CSL_CSCTI_CTITRIGOUTSTATUS_RESETVAL                     (0x00000000U)

/* CTICHINSTATUS */

#define CSL_CSCTI_CTICHINSTATUS_CTICHOUTSTATUS_MASK             (0x0000000FU)
#define CSL_CSCTI_CTICHINSTATUS_CTICHOUTSTATUS_SHIFT            (0U)
#define CSL_CSCTI_CTICHINSTATUS_CTICHOUTSTATUS_RESETVAL         (0x00000000U)
#define CSL_CSCTI_CTICHINSTATUS_CTICHOUTSTATUS_MAX              (0x0000000fU)

#define CSL_CSCTI_CTICHINSTATUS_RESETVAL                        (0x00000000U)

/* CTICHOUTSTATUS */

#define CSL_CSCTI_CTICHOUTSTATUS_CTICHOUTSTATUS_MASK            (0x0000000FU)
#define CSL_CSCTI_CTICHOUTSTATUS_CTICHOUTSTATUS_SHIFT           (0U)
#define CSL_CSCTI_CTICHOUTSTATUS_CTICHOUTSTATUS_RESETVAL        (0x00000000U)
#define CSL_CSCTI_CTICHOUTSTATUS_CTICHOUTSTATUS_MAX             (0x0000000fU)

#define CSL_CSCTI_CTICHOUTSTATUS_RESETVAL                       (0x00000000U)

/* CTIGATE */

#define CSL_CSCTI_CTIGATE_CTIGATEEN0_MASK                       (0x00000001U)
#define CSL_CSCTI_CTIGATE_CTIGATEEN0_SHIFT                      (0U)
#define CSL_CSCTI_CTIGATE_CTIGATEEN0_RESETVAL                   (0x00000001U)
#define CSL_CSCTI_CTIGATE_CTIGATEEN0_MAX                        (0x00000001U)

#define CSL_CSCTI_CTIGATE_CTIGATEEN1_MASK                       (0x00000002U)
#define CSL_CSCTI_CTIGATE_CTIGATEEN1_SHIFT                      (1U)
#define CSL_CSCTI_CTIGATE_CTIGATEEN1_RESETVAL                   (0x00000001U)
#define CSL_CSCTI_CTIGATE_CTIGATEEN1_MAX                        (0x00000001U)

#define CSL_CSCTI_CTIGATE_CTIGATEEN2_MASK                       (0x00000004U)
#define CSL_CSCTI_CTIGATE_CTIGATEEN2_SHIFT                      (2U)
#define CSL_CSCTI_CTIGATE_CTIGATEEN2_RESETVAL                   (0x00000001U)
#define CSL_CSCTI_CTIGATE_CTIGATEEN2_MAX                        (0x00000001U)

#define CSL_CSCTI_CTIGATE_CTIGATEEN3_MASK                       (0x00000008U)
#define CSL_CSCTI_CTIGATE_CTIGATEEN3_SHIFT                      (3U)
#define CSL_CSCTI_CTIGATE_CTIGATEEN3_RESETVAL                   (0x00000001U)
#define CSL_CSCTI_CTIGATE_CTIGATEEN3_MAX                        (0x00000001U)

#define CSL_CSCTI_CTIGATE_RESETVAL                              (0x0000000fU)

/* ASICCTL */

#define CSL_CSCTI_ASICCTL_ASICCTL_MASK                          (0x000000FFU)
#define CSL_CSCTI_ASICCTL_ASICCTL_SHIFT                         (0U)
#define CSL_CSCTI_ASICCTL_ASICCTL_RESETVAL                      (0x00000000U)
#define CSL_CSCTI_ASICCTL_ASICCTL_MAX                           (0x000000ffU)

#define CSL_CSCTI_ASICCTL_RESETVAL                              (0x00000000U)

/* ITCHINACK */

#define CSL_CSCTI_ITCHINACK_CTCHINACK_MASK                      (0x0000000FU)
#define CSL_CSCTI_ITCHINACK_CTCHINACK_SHIFT                     (0U)
#define CSL_CSCTI_ITCHINACK_CTCHINACK_RESETVAL                  (0x00000000U)
#define CSL_CSCTI_ITCHINACK_CTCHINACK_MAX                       (0x0000000fU)

#define CSL_CSCTI_ITCHINACK_RESETVAL                            (0x00000000U)

/* ITTRIGINACK */

#define CSL_CSCTI_ITTRIGINACK_CTTRIGINACK_MASK                  (0x000000FFU)
#define CSL_CSCTI_ITTRIGINACK_CTTRIGINACK_SHIFT                 (0U)
#define CSL_CSCTI_ITTRIGINACK_CTTRIGINACK_RESETVAL              (0x00000000U)
#define CSL_CSCTI_ITTRIGINACK_CTTRIGINACK_MAX                   (0x000000ffU)

#define CSL_CSCTI_ITTRIGINACK_RESETVAL                          (0x00000000U)

/* ITCHOUT */

#define CSL_CSCTI_ITCHOUT_CTCHOUT_MASK                          (0x0000000FU)
#define CSL_CSCTI_ITCHOUT_CTCHOUT_SHIFT                         (0U)
#define CSL_CSCTI_ITCHOUT_CTCHOUT_RESETVAL                      (0x00000000U)
#define CSL_CSCTI_ITCHOUT_CTCHOUT_MAX                           (0x0000000fU)

#define CSL_CSCTI_ITCHOUT_RESETVAL                              (0x00000000U)

/* ITTRIGOUT */

#define CSL_CSCTI_ITTRIGOUT_CTTRIGOUT_MASK                      (0x000000FFU)
#define CSL_CSCTI_ITTRIGOUT_CTTRIGOUT_SHIFT                     (0U)
#define CSL_CSCTI_ITTRIGOUT_CTTRIGOUT_RESETVAL                  (0x00000000U)
#define CSL_CSCTI_ITTRIGOUT_CTTRIGOUT_MAX                       (0x000000ffU)

#define CSL_CSCTI_ITTRIGOUT_RESETVAL                            (0x00000000U)

/* ITCHOUTACK */

#define CSL_CSCTI_ITCHOUTACK_CTCHOUTACK_MASK                    (0x0000000FU)
#define CSL_CSCTI_ITCHOUTACK_CTCHOUTACK_SHIFT                   (0U)
#define CSL_CSCTI_ITCHOUTACK_CTCHOUTACK_RESETVAL                (0x00000000U)
#define CSL_CSCTI_ITCHOUTACK_CTCHOUTACK_MAX                     (0x0000000fU)

#define CSL_CSCTI_ITCHOUTACK_RESETVAL                           (0x00000000U)

/* ITTRIGOUTACK */

#define CSL_CSCTI_ITTRIGOUTACK_CTTRIGOUTACK_MASK                (0x000000FFU)
#define CSL_CSCTI_ITTRIGOUTACK_CTTRIGOUTACK_SHIFT               (0U)
#define CSL_CSCTI_ITTRIGOUTACK_CTTRIGOUTACK_RESETVAL            (0x00000000U)
#define CSL_CSCTI_ITTRIGOUTACK_CTTRIGOUTACK_MAX                 (0x000000ffU)

#define CSL_CSCTI_ITTRIGOUTACK_RESETVAL                         (0x00000000U)

/* ITCHIN */

#define CSL_CSCTI_ITCHIN_CTCHIN_MASK                            (0x0000000FU)
#define CSL_CSCTI_ITCHIN_CTCHIN_SHIFT                           (0U)
#define CSL_CSCTI_ITCHIN_CTCHIN_RESETVAL                        (0x00000000U)
#define CSL_CSCTI_ITCHIN_CTCHIN_MAX                             (0x0000000fU)

#define CSL_CSCTI_ITCHIN_RESETVAL                               (0x00000000U)

/* ITTRIGIN */

#define CSL_CSCTI_ITTRIGIN_CTITRIGIN_MASK                       (0x0000000FU)
#define CSL_CSCTI_ITTRIGIN_CTITRIGIN_SHIFT                      (0U)
#define CSL_CSCTI_ITTRIGIN_CTITRIGIN_RESETVAL                   (0x00000000U)
#define CSL_CSCTI_ITTRIGIN_CTITRIGIN_MAX                        (0x0000000fU)

#define CSL_CSCTI_ITTRIGIN_RESETVAL                             (0x00000000U)

/* ITCTRL */

#define CSL_CSCTI_ITCTRL_ITCTRL_MASK                            (0x00000001U)
#define CSL_CSCTI_ITCTRL_ITCTRL_SHIFT                           (0U)
#define CSL_CSCTI_ITCTRL_ITCTRL_RESETVAL                        (0x00000000U)
#define CSL_CSCTI_ITCTRL_ITCTRL_MAX                             (0x00000001U)

#define CSL_CSCTI_ITCTRL_RESETVAL                               (0x00000000U)

/* CLAIMSET */

#define CSL_CSCTI_CLAIMSET_CLAIMTAGSET_MASK                     (0x0000000FU)
#define CSL_CSCTI_CLAIMSET_CLAIMTAGSET_SHIFT                    (0U)
#define CSL_CSCTI_CLAIMSET_CLAIMTAGSET_RESETVAL                 (0x0000000fU)
#define CSL_CSCTI_CLAIMSET_CLAIMTAGSET_MAX                      (0x0000000fU)

#define CSL_CSCTI_CLAIMSET_RESETVAL                             (0x0000000fU)

/* CLAIMCLR */

#define CSL_CSCTI_CLAIMCLR_CLAIMTAGCLEAR_MASK                   (0x0000000FU)
#define CSL_CSCTI_CLAIMCLR_CLAIMTAGCLEAR_SHIFT                  (0U)
#define CSL_CSCTI_CLAIMCLR_CLAIMTAGCLEAR_RESETVAL               (0x00000000U)
#define CSL_CSCTI_CLAIMCLR_CLAIMTAGCLEAR_MAX                    (0x0000000fU)

#define CSL_CSCTI_CLAIMCLR_RESETVAL                             (0x00000000U)

/* LOCKACCESS */

#define CSL_CSCTI_LOCKACCESS_WRITEACCESSCODE_MASK               (0xFFFFFFFFU)
#define CSL_CSCTI_LOCKACCESS_WRITEACCESSCODE_SHIFT              (0U)
#define CSL_CSCTI_LOCKACCESS_WRITEACCESSCODE_RESETVAL           (0x00000000U)
#define CSL_CSCTI_LOCKACCESS_WRITEACCESSCODE_MAX                (0xffffffffU)

#define CSL_CSCTI_LOCKACCESS_RESETVAL                           (0x00000000U)

/* LOCKSTATUS */

#define CSL_CSCTI_LOCKSTATUS_IMP_MASK                           (0x00000001U)
#define CSL_CSCTI_LOCKSTATUS_IMP_SHIFT                          (0U)
#define CSL_CSCTI_LOCKSTATUS_IMP_RESETVAL                       (0x00000000U)
#define CSL_CSCTI_LOCKSTATUS_IMP_MAX                            (0x00000001U)

#define CSL_CSCTI_LOCKSTATUS_STATUS_MASK                        (0x00000002U)
#define CSL_CSCTI_LOCKSTATUS_STATUS_SHIFT                       (1U)
#define CSL_CSCTI_LOCKSTATUS_STATUS_RESETVAL                    (0x00000000U)
#define CSL_CSCTI_LOCKSTATUS_STATUS_MAX                         (0x00000001U)

#define CSL_CSCTI_LOCKSTATUS_EIGHT_BIT_MASK                     (0x00000004U)
#define CSL_CSCTI_LOCKSTATUS_EIGHT_BIT_SHIFT                    (2U)
#define CSL_CSCTI_LOCKSTATUS_EIGHT_BIT_RESETVAL                 (0x00000000U)
#define CSL_CSCTI_LOCKSTATUS_EIGHT_BIT_MAX                      (0x00000001U)

#define CSL_CSCTI_LOCKSTATUS_RESETVAL                           (0x00000000U)

/* AUTHSTATUS */

#define CSL_CSCTI_AUTHSTATUS_NONSECURE_INVASIVE_DEBUG_MASK      (0x00000003U)
#define CSL_CSCTI_AUTHSTATUS_NONSECURE_INVASIVE_DEBUG_SHIFT     (0U)
#define CSL_CSCTI_AUTHSTATUS_NONSECURE_INVASIVE_DEBUG_RESETVAL  (0x00000001U)
#define CSL_CSCTI_AUTHSTATUS_NONSECURE_INVASIVE_DEBUG_MAX       (0x00000003U)

#define CSL_CSCTI_AUTHSTATUS_NONSECURE_NONINVASIVE_DEBUG_MASK   (0x0000000CU)
#define CSL_CSCTI_AUTHSTATUS_NONSECURE_NONINVASIVE_DEBUG_SHIFT  (2U)
#define CSL_CSCTI_AUTHSTATUS_NONSECURE_NONINVASIVE_DEBUG_RESETVAL  (0x00000001U)
#define CSL_CSCTI_AUTHSTATUS_NONSECURE_NONINVASIVE_DEBUG_MAX    (0x00000003U)

#define CSL_CSCTI_AUTHSTATUS_SECURE_INVASIVE_DEBUG_MASK         (0x00000030U)
#define CSL_CSCTI_AUTHSTATUS_SECURE_INVASIVE_DEBUG_SHIFT        (4U)
#define CSL_CSCTI_AUTHSTATUS_SECURE_INVASIVE_DEBUG_RESETVAL     (0x00000000U)
#define CSL_CSCTI_AUTHSTATUS_SECURE_INVASIVE_DEBUG_MAX          (0x00000003U)

#define CSL_CSCTI_AUTHSTATUS_SECURE_NONINVASIVE_DEBUG_MASK      (0x000000C0U)
#define CSL_CSCTI_AUTHSTATUS_SECURE_NONINVASIVE_DEBUG_SHIFT     (6U)
#define CSL_CSCTI_AUTHSTATUS_SECURE_NONINVASIVE_DEBUG_RESETVAL  (0x00000000U)
#define CSL_CSCTI_AUTHSTATUS_SECURE_NONINVASIVE_DEBUG_MAX       (0x00000003U)

#define CSL_CSCTI_AUTHSTATUS_RESETVAL                           (0x00000005U)

/* DEVID */

#define CSL_CSCTI_DEVID_DEVICEID_MASK                           (0xFFFFFFFFU)
#define CSL_CSCTI_DEVID_DEVICEID_SHIFT                          (0U)
#define CSL_CSCTI_DEVID_DEVICEID_RESETVAL                       (0x00040800U)
#define CSL_CSCTI_DEVID_DEVICEID_MAX                            (0xffffffffU)

#define CSL_CSCTI_DEVID_RESETVAL                                (0x00040800U)

/* DEVTYPE */

#define CSL_CSCTI_DEVTYPE_MAIN_TYPE_CLASS_MASK                  (0x0000000FU)
#define CSL_CSCTI_DEVTYPE_MAIN_TYPE_CLASS_SHIFT                 (0U)
#define CSL_CSCTI_DEVTYPE_MAIN_TYPE_CLASS_RESETVAL              (0x00000004U)
#define CSL_CSCTI_DEVTYPE_MAIN_TYPE_CLASS_MAX                   (0x0000000fU)

#define CSL_CSCTI_DEVTYPE_SUB_TYPE_MASK                         (0x000000F0U)
#define CSL_CSCTI_DEVTYPE_SUB_TYPE_SHIFT                        (4U)
#define CSL_CSCTI_DEVTYPE_SUB_TYPE_RESETVAL                     (0x00000001U)
#define CSL_CSCTI_DEVTYPE_SUB_TYPE_MAX                          (0x0000000fU)

#define CSL_CSCTI_DEVTYPE_RESETVAL                              (0x00000014U)

/* PERIPHID4 */

#define CSL_CSCTI_PERIPHID4_JEP106_CONTINUATION_CODE_MASK       (0x0000000FU)
#define CSL_CSCTI_PERIPHID4_JEP106_CONTINUATION_CODE_SHIFT      (0U)
#define CSL_CSCTI_PERIPHID4_JEP106_CONTINUATION_CODE_RESETVAL   (0x00000004U)
#define CSL_CSCTI_PERIPHID4_JEP106_CONTINUATION_CODE_MAX        (0x0000000fU)

#define CSL_CSCTI_PERIPHID4_FOURKB_COUNT_MASK                   (0x000000F0U)
#define CSL_CSCTI_PERIPHID4_FOURKB_COUNT_SHIFT                  (4U)
#define CSL_CSCTI_PERIPHID4_FOURKB_COUNT_RESETVAL               (0x00000000U)
#define CSL_CSCTI_PERIPHID4_FOURKB_COUNT_MAX                    (0x0000000fU)

#define CSL_CSCTI_PERIPHID4_RESETVAL                            (0x00000004U)

/* PERIPHID5 */

#define CSL_CSCTI_PERIPHID5_RESETVAL                            (0x00000000U)

/* PERIPHID6 */

#define CSL_CSCTI_PERIPHID6_RESETVAL                            (0x00000000U)

/* PERIPHID7 */

#define CSL_CSCTI_PERIPHID7_RESETVAL                            (0x00000000U)

/* PERIPHID0 */

#define CSL_CSCTI_PERIPHID0_PART_NUMBER_0_MASK                  (0x000000FFU)
#define CSL_CSCTI_PERIPHID0_PART_NUMBER_0_SHIFT                 (0U)
#define CSL_CSCTI_PERIPHID0_PART_NUMBER_0_RESETVAL              (0x00000006U)
#define CSL_CSCTI_PERIPHID0_PART_NUMBER_0_MAX                   (0x000000ffU)

#define CSL_CSCTI_PERIPHID0_RESETVAL                            (0x00000006U)

/* PERIPHID1 */

#define CSL_CSCTI_PERIPHID1_PART_NUMBER_1_MASK                  (0x0000000FU)
#define CSL_CSCTI_PERIPHID1_PART_NUMBER_1_SHIFT                 (0U)
#define CSL_CSCTI_PERIPHID1_PART_NUMBER_1_RESETVAL              (0x00000009U)
#define CSL_CSCTI_PERIPHID1_PART_NUMBER_1_MAX                   (0x0000000fU)

#define CSL_CSCTI_PERIPHID1_JEP106_IDENTITY_CODE_MASK           (0x000000F0U)
#define CSL_CSCTI_PERIPHID1_JEP106_IDENTITY_CODE_SHIFT          (4U)
#define CSL_CSCTI_PERIPHID1_JEP106_IDENTITY_CODE_RESETVAL       (0x0000000bU)
#define CSL_CSCTI_PERIPHID1_JEP106_IDENTITY_CODE_MAX            (0x0000000fU)

#define CSL_CSCTI_PERIPHID1_RESETVAL                            (0x000000b9U)

/* PERIPHID2 */

#define CSL_CSCTI_PERIPHID2_JEP106_IDENTITY_MASK                (0x00000007U)
#define CSL_CSCTI_PERIPHID2_JEP106_IDENTITY_SHIFT               (0U)
#define CSL_CSCTI_PERIPHID2_JEP106_IDENTITY_RESETVAL            (0x00000003U)
#define CSL_CSCTI_PERIPHID2_JEP106_IDENTITY_MAX                 (0x00000007U)

#define CSL_CSCTI_PERIPHID2_JEP106_ENABLE_MASK                  (0x00000008U)
#define CSL_CSCTI_PERIPHID2_JEP106_ENABLE_SHIFT                 (3U)
#define CSL_CSCTI_PERIPHID2_JEP106_ENABLE_RESETVAL              (0x00000001U)
#define CSL_CSCTI_PERIPHID2_JEP106_ENABLE_MAX                   (0x00000001U)

#define CSL_CSCTI_PERIPHID2_REVISION_MASK                       (0x000000F0U)
#define CSL_CSCTI_PERIPHID2_REVISION_SHIFT                      (4U)
#define CSL_CSCTI_PERIPHID2_REVISION_RESETVAL                   (0x00000003U)
#define CSL_CSCTI_PERIPHID2_REVISION_MAX                        (0x0000000fU)

#define CSL_CSCTI_PERIPHID2_RESETVAL                            (0x0000003bU)

/* PERIPHID3 */

#define CSL_CSCTI_PERIPHID3_CUSTOMER_MODIFIED_MASK              (0x0000000FU)
#define CSL_CSCTI_PERIPHID3_CUSTOMER_MODIFIED_SHIFT             (0U)
#define CSL_CSCTI_PERIPHID3_CUSTOMER_MODIFIED_RESETVAL          (0x00000000U)
#define CSL_CSCTI_PERIPHID3_CUSTOMER_MODIFIED_MAX               (0x0000000fU)

#define CSL_CSCTI_PERIPHID3_REVAND_MASK                         (0x000000F0U)
#define CSL_CSCTI_PERIPHID3_REVAND_SHIFT                        (4U)
#define CSL_CSCTI_PERIPHID3_REVAND_RESETVAL                     (0x00000000U)
#define CSL_CSCTI_PERIPHID3_REVAND_MAX                          (0x0000000fU)

#define CSL_CSCTI_PERIPHID3_RESETVAL                            (0x00000000U)

/* COMPONID0 */

#define CSL_CSCTI_COMPONID0_PREAMBLE_MASK                       (0x000000FFU)
#define CSL_CSCTI_COMPONID0_PREAMBLE_SHIFT                      (0U)
#define CSL_CSCTI_COMPONID0_PREAMBLE_RESETVAL                   (0x0000000dU)
#define CSL_CSCTI_COMPONID0_PREAMBLE_MAX                        (0x000000ffU)

#define CSL_CSCTI_COMPONID0_RESETVAL                            (0x0000000dU)

/* COMPONID1 */

#define CSL_CSCTI_COMPONID1_PREAMBLE_MASK                       (0x0000000FU)
#define CSL_CSCTI_COMPONID1_PREAMBLE_SHIFT                      (0U)
#define CSL_CSCTI_COMPONID1_PREAMBLE_RESETVAL                   (0x00000000U)
#define CSL_CSCTI_COMPONID1_PREAMBLE_MAX                        (0x0000000fU)

#define CSL_CSCTI_COMPONID1_COMPONENT_CLASS_MASK                (0x000000F0U)
#define CSL_CSCTI_COMPONID1_COMPONENT_CLASS_SHIFT               (4U)
#define CSL_CSCTI_COMPONID1_COMPONENT_CLASS_RESETVAL            (0x00000009U)
#define CSL_CSCTI_COMPONID1_COMPONENT_CLASS_MAX                 (0x0000000fU)

#define CSL_CSCTI_COMPONID1_RESETVAL                            (0x00000090U)

/* COMPONID2 */

#define CSL_CSCTI_COMPONID2_PREAMBLE_MASK                       (0x000000FFU)
#define CSL_CSCTI_COMPONID2_PREAMBLE_SHIFT                      (0U)
#define CSL_CSCTI_COMPONID2_PREAMBLE_RESETVAL                   (0x00000005U)
#define CSL_CSCTI_COMPONID2_PREAMBLE_MAX                        (0x000000ffU)

#define CSL_CSCTI_COMPONID2_RESETVAL                            (0x00000005U)

/* COMPONID3 */

#define CSL_CSCTI_COMPONID3_PREAMBLE_MASK                       (0x000000FFU)
#define CSL_CSCTI_COMPONID3_PREAMBLE_SHIFT                      (0U)
#define CSL_CSCTI_COMPONID3_PREAMBLE_RESETVAL                   (0x000000b1U)
#define CSL_CSCTI_COMPONID3_PREAMBLE_MAX                        (0x000000ffU)

#define CSL_CSCTI_COMPONID3_RESETVAL                            (0x000000b1U)

#ifdef __cplusplus
}
#endif
#endif

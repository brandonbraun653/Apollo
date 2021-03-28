/********************************************************************
 * Copyright (C) 2013-2016 Texas Instruments Incorporated.
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
#ifndef CSLR_CGEM_H
#define CSLR_CGEM_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for CGEMaddressBlockTable
**************************************************************************/
typedef struct {
    volatile Uint32 EVTFLAG[4];
    volatile Uint8  RSVD0[16];
    volatile Uint32 EVTSET[4];
    volatile Uint8  RSVD1[16];
    volatile Uint32 EVTCLR[4];
    volatile Uint8  RSVD2[48];
    volatile Uint32 EVTMASK[4];
    volatile Uint8  RSVD3[16];
    volatile Uint32 MEVTFLAG[4];
    volatile Uint8  RSVD4[16];
    volatile Uint32 EXPMASK[4];
    volatile Uint8  RSVD5[16];
    volatile Uint32 MEXPFLAG[4];
    volatile Uint8  RSVD6[20];
    volatile Uint32 INTMUX1;
    volatile Uint32 INTMUX2;
    volatile Uint32 INTMUX3;
    volatile Uint8  RSVD7[48];
    volatile Uint32 AEGMUX0;
    volatile Uint32 AEGMUX1;
    volatile Uint8  RSVD8[56];
    volatile Uint32 INTXSTAT;
    volatile Uint32 INTXCLR;
    volatile Uint32 INTDMASK;
    volatile Uint8  RSVD9[52];
    volatile Uint32 EVTASRT;
    volatile Uint8  RSVD10[65084];
    volatile Uint32 PDCCMD;
    volatile Uint8  RSVD11[8188];
    volatile Uint32 MM_REVID;
    volatile Uint8  RSVD12[57340];
    volatile Uint32 IDMA0_STAT;
    volatile Uint32 IDMA0_MASK;
    volatile Uint32 IDMA0_SOURCE;
    volatile Uint32 IDMA0_DEST;
    volatile Uint32 IDMA0_COUNT;
    volatile Uint8  RSVD13[236];
    volatile Uint32 IDMA1_STAT;
    volatile Uint8  RSVD14[4];
    volatile Uint32 IDMA1_SOURCE;
    volatile Uint32 IDMA1_DEST;
    volatile Uint32 IDMA1_COUNT;
    volatile Uint8  RSVD15[236];
    volatile Uint32 CPUARBE;
    volatile Uint32 IDMAARBE;
    volatile Uint32 SDMAARBE;
    volatile Uint8  RSVD16[4];
    volatile Uint32 ECFGARBE;
    volatile Uint8  RSVD17[236];
    volatile Uint32 ICFGMPFAR;
    volatile Uint32 ICFGMPFSR;
    volatile Uint32 ICFGMPFCR;
    volatile Uint8  RSVD18[252];
    volatile Uint32 ECFGERR;
    volatile Uint32 ECFGERRCLR;
    volatile Uint8  RSVD19[240];
    volatile Uint32 PAMAP0;
    volatile Uint32 PAMAP1;
    volatile Uint32 PAMAP2;
    volatile Uint32 PAMAP3;
    volatile Uint32 PAMAP4;
    volatile Uint32 PAMAP5;
    volatile Uint32 PAMAP6;
    volatile Uint32 PAMAP7;
    volatile Uint32 PAMAP8;
    volatile Uint32 PAMAP9;
    volatile Uint32 PAMAP10;
    volatile Uint32 PAMAP11;
    volatile Uint32 PAMAP12;
    volatile Uint32 PAMAP13;
    volatile Uint32 PAMAP14;
    volatile Uint32 PAMAP15;
    volatile Uint8  RSVD20[129728];
    volatile Uint32 L2CFG;
    volatile Uint8  RSVD21[28];
    volatile Uint32 L1PCFG;
    volatile Uint32 L1PCC;
    volatile Uint8  RSVD22[24];
    volatile Uint32 L1DCFG;
    volatile Uint32 L1DCC;
    volatile Uint8  RSVD23[4024];
    volatile Uint32 CPUARBU;
    volatile Uint32 IDMAARBU;
    volatile Uint32 SDMAARBU;
    volatile Uint32 UCARBU;
    volatile Uint32 MDMAARBU;
    volatile Uint8  RSVD24[44];
    volatile Uint32 CPUARBD;
    volatile Uint32 IDMAARBD;
    volatile Uint32 SDMAARBD;
    volatile Uint32 UCARBD;
    volatile Uint8  RSVD25[12208];
    volatile Uint32 L2WBAR;
    volatile Uint32 L2WWC;
    volatile Uint8  RSVD26[8];
    volatile Uint32 L2WIBAR;
    volatile Uint32 L2WIWC;
    volatile Uint32 L2IBAR;
    volatile Uint32 L2IWC;
    volatile Uint32 L1PIBAR;
    volatile Uint32 L1PIWC;
    volatile Uint8  RSVD27[8];
    volatile Uint32 L1DWIBAR;
    volatile Uint32 L1DWIWC;
    volatile Uint8  RSVD28[8];
    volatile Uint32 L1DWBAR;
    volatile Uint32 L1DWWC;
    volatile Uint32 L1DIBAR;
    volatile Uint32 L1DIWC;
    volatile Uint8  RSVD29[4016];
    volatile Uint32 L2WB;
    volatile Uint32 L2WBINV;
    volatile Uint32 L2INV;
    volatile Uint8  RSVD30[28];
    volatile Uint32 L1PINV;
    volatile Uint8  RSVD31[20];
    volatile Uint32 L1DWB;
    volatile Uint32 L1DWBINV;
    volatile Uint32 L1DINV;
    volatile Uint8  RSVD32[4024];
    volatile Uint32 L2EDSTAT;
    volatile Uint32 L2EDCMD;
    volatile Uint32 L2EDADDR;
    volatile Uint8  RSVD33[8];
    volatile Uint32 L2EDCPEC;
    volatile Uint32 L2EDCNEC;
    volatile Uint32 MDMAERR;
    volatile Uint32 MDMAERRCLR;
    volatile Uint8  RSVD34[8];
    volatile Uint32 L2EDCEN;
    volatile Uint8  RSVD35[976];
    volatile Uint32 L1PEDSTAT;
    volatile Uint32 L1PEDCMD;
    volatile Uint32 L1PEDADDR;
    volatile Uint8  RSVD36[7152];
    volatile Uint32 MAR[256];
    volatile Uint8  RSVD37[7168];
    volatile Uint32 L2MPFAR;
    volatile Uint32 L2MPFSR;
    volatile Uint32 L2MPFCR;
    volatile Uint8  RSVD38[500];
    volatile Uint32 L2MPPA[32];
    volatile Uint8  RSVD39[384];
    volatile Uint32 L1PMPFAR;
    volatile Uint32 L1PMPFSR;
    volatile Uint32 L1PMPFCR;
    volatile Uint8  RSVD40[564];
    volatile Uint32 L1PMPPA[16];
    volatile Uint8  RSVD41[1408];
    volatile Uint32 L1DMPFAR;
    volatile Uint32 L1DMPFSR;
    volatile Uint32 L1DMPFCR;
    volatile Uint8  RSVD42[244];
    volatile Uint32 MPLK[4];
    volatile Uint32 MPLKCMD;
    volatile Uint32 MPLKSTAT;
    volatile Uint8  RSVD43[296];
    volatile Uint32 L1DMPPA[16];
    volatile Uint8  RSVD44[2147231];
} CSL_CgemRegs;


/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_CGEM_EVTFLAG(i)                                     ((uint32_t)0x1800000u + ((i) * ((uint32_t)4u)))
#define CSL_CGEM_EVTSET(i)                                      ((uint32_t)0x1800020u + ((i) * ((uint32_t)4u)))
#define CSL_CGEM_EVTCLR(i)                                      ((uint32_t)0x1800040u + ((i) * ((uint32_t)4u)))
#define CSL_CGEM_EVTMASK(i)                                     ((uint32_t)0x1800080u + ((i) * ((uint32_t)4u)))
#define CSL_CGEM_MEVTFLAG(i)                                    ((uint32_t)0x18000A0u + ((i) * ((uint32_t)4u)))
#define CSL_CGEM_EXPMASK(i)                                     ((uint32_t)0x18000C0u + ((i) * ((uint32_t)4u)))
#define CSL_CGEM_MEXPFLAG(i)                                    ((uint32_t)0x18000E0u + ((i) * ((uint32_t)4u)))
#define CSL_CGEM_INTMUX1                                        ((uint32_t)0x1800104u)
#define CSL_CGEM_INTMUX2                                        ((uint32_t)0x1800108u)
#define CSL_CGEM_INTMUX3                                        ((uint32_t)0x180010Cu)
#define CSL_CGEM_AEGMUX0                                        ((uint32_t)0x1800140u)
#define CSL_CGEM_AEGMUX1                                        ((uint32_t)0x1800144u)
#define CSL_CGEM_INTXSTAT                                       ((uint32_t)0x1800180u)
#define CSL_CGEM_INTXCLR                                        ((uint32_t)0x1800184u)
#define CSL_CGEM_INTDMASK                                       ((uint32_t)0x1800188u)
#define CSL_CGEM_EVTASRT                                        ((uint32_t)0x18001C0u)
#define CSL_CGEM_PDCCMD                                         ((uint32_t)0x1810000u)
#define CSL_CGEM_EDCINTMASK                                     ((uint32_t)0x1811100u)
#define CSL_CGEM_MM_REVID                                       ((uint32_t)0x1812000u)
#define CSL_CGEM_IDMA0_STAT                                     ((uint32_t)0x1820000u)
#define CSL_CGEM_IDMA0_MASK                                     ((uint32_t)0x1820004u)
#define CSL_CGEM_IDMA0_SOURCE                                   ((uint32_t)0x1820008u)
#define CSL_CGEM_IDMA0_DEST                                     ((uint32_t)0x182000Cu)
#define CSL_CGEM_IDMA0_COUNT                                    ((uint32_t)0x1820010u)
#define CSL_CGEM_IDMA1_STAT                                     ((uint32_t)0x1820100u)
#define CSL_CGEM_IDMA1_SOURCE                                   ((uint32_t)0x1820108u)
#define CSL_CGEM_IDMA1_DEST                                     ((uint32_t)0x182010Cu)
#define CSL_CGEM_IDMA1_COUNT                                    ((uint32_t)0x1820110u)
#define CSL_CGEM_CPUARBE                                        ((uint32_t)0x1820200u)
#define CSL_CGEM_IDMAARBE                                       ((uint32_t)0x1820204u)
#define CSL_CGEM_SDMAARBE                                       ((uint32_t)0x1820208u)
#define CSL_CGEM_ECFGARBE                                       ((uint32_t)0x1820210u)
#define CSL_CGEM_ICFGMPFAR                                      ((uint32_t)0x1820300u)
#define CSL_CGEM_ICFGMPFSR                                      ((uint32_t)0x1820304u)
#define CSL_CGEM_ICFGMPFCR                                      ((uint32_t)0x1820308u)
#define CSL_CGEM_ECFGERR                                        ((uint32_t)0x1820408u)
#define CSL_CGEM_ECFGERRCLR                                     ((uint32_t)0x182040Cu)
#define CSL_CGEM_PAMAP0                                         ((uint32_t)0x1820500u)
#define CSL_CGEM_PAMAP1                                         ((uint32_t)0x1820504u)
#define CSL_CGEM_PAMAP2                                         ((uint32_t)0x1820508u)
#define CSL_CGEM_PAMAP3                                         ((uint32_t)0x182050Cu)
#define CSL_CGEM_PAMAP4                                         ((uint32_t)0x1820510u)
#define CSL_CGEM_PAMAP5                                         ((uint32_t)0x1820514u)
#define CSL_CGEM_PAMAP6                                         ((uint32_t)0x1820518u)
#define CSL_CGEM_PAMAP7                                         ((uint32_t)0x182051Cu)
#define CSL_CGEM_PAMAP8                                         ((uint32_t)0x1820520u)
#define CSL_CGEM_PAMAP9                                         ((uint32_t)0x1820524u)
#define CSL_CGEM_PAMAP10                                        ((uint32_t)0x1820528u)
#define CSL_CGEM_PAMAP11                                        ((uint32_t)0x182052Cu)
#define CSL_CGEM_PAMAP12                                        ((uint32_t)0x1820530u)
#define CSL_CGEM_PAMAP13                                        ((uint32_t)0x1820534u)
#define CSL_CGEM_PAMAP14                                        ((uint32_t)0x1820538u)
#define CSL_CGEM_PAMAP15                                        ((uint32_t)0x182053Cu)
#define CSL_CGEM_EDCINTFLG                                      ((uint32_t)0x1821104u)
#define CSL_CGEM_L1DEDCMD                                       ((uint32_t)0x1821108u)
#define CSL_CGEM_L1DDCSTAT                                      ((uint32_t)0x182110Cu)
#define CSL_CGEM_L1DDNCSTAT                                     ((uint32_t)0x1821110u)
#define CSL_CGEM_L1DTCSTAT                                      ((uint32_t)0x1821114u)
#define CSL_CGEM_L1DTNCSTAT                                     ((uint32_t)0x1821118u)
#define CSL_CGEM_L1DDEDADDR                                     ((uint32_t)0x182111Cu)
#define CSL_CGEM_L1DTEDADDR                                     ((uint32_t)0x1821120u)
#define CSL_CGEM_L1DEDCNT                                       ((uint32_t)0x1821124u)
#define CSL_CGEM_L2TEDCMD                                       ((uint32_t)0x1821128u)
#define CSL_CGEM_L2TCSTAT                                       ((uint32_t)0x182112Cu)
#define CSL_CGEM_L2TNCSTAT                                      ((uint32_t)0x1821130u)
#define CSL_CGEM_L2TEDADDR                                      ((uint32_t)0x1821134u)
#define CSL_CGEM_L2MCSTAT                                       ((uint32_t)0x1821138u)
#define CSL_CGEM_L2MNCSTAT                                      ((uint32_t)0x182113Cu)
#define CSL_CGEM_L2MEDADDR                                      ((uint32_t)0x1821140u)
#define CSL_CGEM_L2SCSTAT                                       ((uint32_t)0x1821144u)
#define CSL_CGEM_L2SNCSTAT                                      ((uint32_t)0x1821148u)
#define CSL_CGEM_L2SEDADDR                                      ((uint32_t)0x182114Cu)
#define CSL_CGEM_L2LCSTAT                                       ((uint32_t)0x1821150u)
#define CSL_CGEM_L2LNCSTAT                                      ((uint32_t)0x1821154u)
#define CSL_CGEM_L2LEDADDR                                      ((uint32_t)0x1821158u)
#define CSL_CGEM_L2TEDCNT                                       ((uint32_t)0x182115Cu)
#define CSL_CGEM_L1PTEDCMD                                      ((uint32_t)0x1821160u)
#define CSL_CGEM_L1PTEDSTAT                                     ((uint32_t)0x1821164u)
#define CSL_CGEM_L1PTEDADDR                                     ((uint32_t)0x1821168u)
#define CSL_CGEM_L1DTEDCNT                                      ((uint32_t)0x182116Cu)
#define CSL_CGEM_L2CFG                                          ((uint32_t)0x1840000u)
#define CSL_CGEM_L1PCFG                                         ((uint32_t)0x1840020u)
#define CSL_CGEM_L1PCC                                          ((uint32_t)0x1840024u)
#define CSL_CGEM_L1DCFG                                         ((uint32_t)0x1840040u)
#define CSL_CGEM_L1DCC                                          ((uint32_t)0x1840044u)
#define CSL_CGEM_CPUARBU                                        ((uint32_t)0x1841000u)
#define CSL_CGEM_IDMAARBU                                       ((uint32_t)0x1841004u)
#define CSL_CGEM_SDMAARBU                                       ((uint32_t)0x1841008u)
#define CSL_CGEM_UCARBU                                         ((uint32_t)0x184100Cu)
#define CSL_CGEM_MDMAARBU                                       ((uint32_t)0x1841010u)
#define CSL_CGEM_CPUARBD                                        ((uint32_t)0x1841040u)
#define CSL_CGEM_IDMAARBD                                       ((uint32_t)0x1841044u)
#define CSL_CGEM_SDMAARBD                                       ((uint32_t)0x1841048u)
#define CSL_CGEM_UCARBD                                         ((uint32_t)0x184104Cu)
#define CSL_CGEM_L2WBAR                                         ((uint32_t)0x1844000u)
#define CSL_CGEM_L2WWC                                          ((uint32_t)0x1844004u)
#define CSL_CGEM_L2WIBAR                                        ((uint32_t)0x1844010u)
#define CSL_CGEM_L2WIWC                                         ((uint32_t)0x1844014u)
#define CSL_CGEM_L2IBAR                                         ((uint32_t)0x1844018u)
#define CSL_CGEM_L2IWC                                          ((uint32_t)0x184401Cu)
#define CSL_CGEM_L1PIBAR                                        ((uint32_t)0x1844020u)
#define CSL_CGEM_L1PIWC                                         ((uint32_t)0x1844024u)
#define CSL_CGEM_L1DWIBAR                                       ((uint32_t)0x1844030u)
#define CSL_CGEM_L1DWIWC                                        ((uint32_t)0x1844034u)
#define CSL_CGEM_L1DWBAR                                        ((uint32_t)0x1844040u)
#define CSL_CGEM_L1DWWC                                         ((uint32_t)0x1844044u)
#define CSL_CGEM_L1DIBAR                                        ((uint32_t)0x1844048u)
#define CSL_CGEM_L1DIWC                                         ((uint32_t)0x184404Cu)
#define CSL_CGEM_L2WB                                           ((uint32_t)0x1845000u)
#define CSL_CGEM_L2WBINV                                        ((uint32_t)0x1845004u)
#define CSL_CGEM_L2INV                                          ((uint32_t)0x1845008u)
#define CSL_CGEM_L1PINV                                         ((uint32_t)0x1845028u)
#define CSL_CGEM_L1DWB                                          ((uint32_t)0x1845040u)
#define CSL_CGEM_L1DWBINV                                       ((uint32_t)0x1845044u)
#define CSL_CGEM_L1DINV                                         ((uint32_t)0x1845048u)
#define CSL_CGEM_L2EDSTAT                                       ((uint32_t)0x1846004u)
#define CSL_CGEM_L2EDCMD                                        ((uint32_t)0x1846008u)
#define CSL_CGEM_L2EDADDR                                       ((uint32_t)0x184600Cu)
#define CSL_CGEM_L2EDCPEC                                       ((uint32_t)0x1846018u)
#define CSL_CGEM_L2EDCNEC                                       ((uint32_t)0x184601Cu)
#define CSL_CGEM_MDMAERR                                        ((uint32_t)0x1846020u)
#define CSL_CGEM_MDMAERRCLR                                     ((uint32_t)0x1846024u)
#define CSL_CGEM_L2EDCEN                                        ((uint32_t)0x1846030u)
#define CSL_CGEM_L1PEDSTAT                                      ((uint32_t)0x1846404u)
#define CSL_CGEM_L1PEDCMD                                       ((uint32_t)0x1846408u)
#define CSL_CGEM_L1PEDADDR                                      ((uint32_t)0x184640Cu)
#define CSL_CGEM_MAR(i)                                         ((uint32_t)0x1848000u + ((i) * ((uint32_t)4u)))
#define CSL_CGEM_L2MPFAR                                        ((uint32_t)0x184A000u)
#define CSL_CGEM_L2MPFSR                                        ((uint32_t)0x184A004u)
#define CSL_CGEM_L2MPFCR                                        ((uint32_t)0x184A008u)
#define CSL_CGEM_L2MPPA(i)                                      ((uint32_t)0x184A200u + ((i) * ((uint32_t)4u)))
#define CSL_CGEM_L1PMPFAR                                       ((uint32_t)0x184A400u)
#define CSL_CGEM_L1PMPFSR                                       ((uint32_t)0x184A404u)
#define CSL_CGEM_L1PMPFCR                                       ((uint32_t)0x184A408u)
#define CSL_CGEM_L1PMPPA(i)                                     ((uint32_t)0x184A640u + ((i) * ((uint32_t)4u)))
#define CSL_CGEM_L1DMPFAR                                       ((uint32_t)0x184AC00u)
#define CSL_CGEM_L1DMPFSR                                       ((uint32_t)0x184AC04u)
#define CSL_CGEM_L1DMPFCR                                       ((uint32_t)0x184AC08u)
#define CSL_CGEM_MPLK(i)                                        ((uint32_t)0x184AD00u + ((i) * ((uint32_t)4u)))
#define CSL_CGEM_MPLKCMD                                        ((uint32_t)0x184AD10u)
#define CSL_CGEM_MPLKSTAT                                       ((uint32_t)0x184AD14u)
#define CSL_CGEM_L1DMPPA(i)                                     ((uint32_t)0x184AE40u + ((i) * ((uint32_t)4u)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* EVTFLAG */

#define CSL_CGEM_EVTFLAG_EF_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_EVTFLAG_EF_MASK                                ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_EVTFLAG_EF_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_EVTFLAG_EF_MAX                                 ((uint32_t)0xffffffffu)

#define CSL_CGEM_EVTFLAG_RESETVAL                               ((uint32_t)0x00000000u)

/* EVTSET */

#define CSL_CGEM_EVTSET_ES_SHIFT                                ((uint32_t)0u)
#define CSL_CGEM_EVTSET_ES_MASK                                 ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_EVTSET_ES_RESETVAL                             ((uint32_t)0x00000000u)
#define CSL_CGEM_EVTSET_ES_MAX                                  ((uint32_t)0xffffffffu)

#define CSL_CGEM_EVTSET_RESETVAL                                ((uint32_t)0x00000000u)

/* EVTCLR */

#define CSL_CGEM_EVTCLR_EC_SHIFT                                ((uint32_t)0u)
#define CSL_CGEM_EVTCLR_EC_MASK                                 ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_EVTCLR_EC_RESETVAL                             ((uint32_t)0x00000000u)
#define CSL_CGEM_EVTCLR_EC_MAX                                  ((uint32_t)0xffffffffu)

#define CSL_CGEM_EVTCLR_RESETVAL                                ((uint32_t)0x00000000u)

/* EVTMASK */

#define CSL_CGEM_EVTMASK_EM_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_EVTMASK_EM_MASK                                ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_EVTMASK_EM_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_EVTMASK_EM_MAX                                 ((uint32_t)0xffffffffu)

#define CSL_CGEM_EVTMASK_RESETVAL                               ((uint32_t)0x00000000u)

/* MEVTFLAG */

#define CSL_CGEM_MEVTFLAG_MEVTFLAG_SHIFT                        ((uint32_t)0u)
#define CSL_CGEM_MEVTFLAG_MEVTFLAG_MASK                         ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_MEVTFLAG_MEVTFLAG_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_MEVTFLAG_MEVTFLAG_MAX                          ((uint32_t)0xffffffffu)

#define CSL_CGEM_MEVTFLAG_RESETVAL                              ((uint32_t)0x00000000u)

/* EXPMASK */

#define CSL_CGEM_EXPMASK_XM_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_EXPMASK_XM_MASK                                ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_EXPMASK_XM_RESETVAL                            ((uint32_t)0xffffffffu)
#define CSL_CGEM_EXPMASK_XM_MAX                                 ((uint32_t)0xffffffffu)

#define CSL_CGEM_EXPMASK_RESETVAL                               ((uint32_t)0xffffffffu)

/* MEXPFLAG */

#define CSL_CGEM_MEXPFLAG_MEXPFLAG_SHIFT                        ((uint32_t)0u)
#define CSL_CGEM_MEXPFLAG_MEXPFLAG_MASK                         ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_MEXPFLAG_MEXPFLAG_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_MEXPFLAG_MEXPFLAG_MAX                          ((uint32_t)0xffffffffu)

#define CSL_CGEM_MEXPFLAG_RESETVAL                              ((uint32_t)0x00000000u)

/* INTMUX1 */

#define CSL_CGEM_INTMUX1__RESV3_SHIFT                           ((uint32_t)31u)
#define CSL_CGEM_INTMUX1__RESV3_MASK                            ((uint32_t)0x80000000u)
#define CSL_CGEM_INTMUX1__RESV3_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTMUX1__RESV3_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_INTMUX1__RESV2_SHIFT                           ((uint32_t)23u)
#define CSL_CGEM_INTMUX1__RESV2_MASK                            ((uint32_t)0x00800000u)
#define CSL_CGEM_INTMUX1__RESV2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTMUX1__RESV2_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_INTMUX1__RESV1_SHIFT                           ((uint32_t)15u)
#define CSL_CGEM_INTMUX1__RESV1_MASK                            ((uint32_t)0x00008000u)
#define CSL_CGEM_INTMUX1__RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTMUX1__RESV1_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_INTMUX1__RESV0_SHIFT                           ((uint32_t)7u)
#define CSL_CGEM_INTMUX1__RESV0_MASK                            ((uint32_t)0x00000080u)
#define CSL_CGEM_INTMUX1__RESV0_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTMUX1__RESV0_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_INTMUX1_INTSEL7_SHIFT                          ((uint32_t)24u)
#define CSL_CGEM_INTMUX1_INTSEL7_MASK                           ((uint32_t)0x7F000000u)
#define CSL_CGEM_INTMUX1_INTSEL7_RESETVAL                       ((uint32_t)0x00000007u)
#define CSL_CGEM_INTMUX1_INTSEL7_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_INTMUX1_INTSEL6_SHIFT                          ((uint32_t)16u)
#define CSL_CGEM_INTMUX1_INTSEL6_MASK                           ((uint32_t)0x007F0000u)
#define CSL_CGEM_INTMUX1_INTSEL6_RESETVAL                       ((uint32_t)0x00000006u)
#define CSL_CGEM_INTMUX1_INTSEL6_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_INTMUX1_INTSEL5_SHIFT                          ((uint32_t)8u)
#define CSL_CGEM_INTMUX1_INTSEL5_MASK                           ((uint32_t)0x00007F00u)
#define CSL_CGEM_INTMUX1_INTSEL5_RESETVAL                       ((uint32_t)0x00000005u)
#define CSL_CGEM_INTMUX1_INTSEL5_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_INTMUX1_INTSEL4_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_INTMUX1_INTSEL4_MASK                           ((uint32_t)0x0000007Fu)
#define CSL_CGEM_INTMUX1_INTSEL4_RESETVAL                       ((uint32_t)0x00000004u)
#define CSL_CGEM_INTMUX1_INTSEL4_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_INTMUX1_RESETVAL                               ((uint32_t)0x07060504u)

/* INTMUX2 */

#define CSL_CGEM_INTMUX2__RESV3_SHIFT                           ((uint32_t)31u)
#define CSL_CGEM_INTMUX2__RESV3_MASK                            ((uint32_t)0x80000000u)
#define CSL_CGEM_INTMUX2__RESV3_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTMUX2__RESV3_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_INTMUX2__RESV2_SHIFT                           ((uint32_t)23u)
#define CSL_CGEM_INTMUX2__RESV2_MASK                            ((uint32_t)0x00800000u)
#define CSL_CGEM_INTMUX2__RESV2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTMUX2__RESV2_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_INTMUX2__RESV1_SHIFT                           ((uint32_t)15u)
#define CSL_CGEM_INTMUX2__RESV1_MASK                            ((uint32_t)0x00008000u)
#define CSL_CGEM_INTMUX2__RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTMUX2__RESV1_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_INTMUX2__RESV0_SHIFT                           ((uint32_t)7u)
#define CSL_CGEM_INTMUX2__RESV0_MASK                            ((uint32_t)0x00000080u)
#define CSL_CGEM_INTMUX2__RESV0_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTMUX2__RESV0_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_INTMUX2_INTSEL11_SHIFT                         ((uint32_t)24u)
#define CSL_CGEM_INTMUX2_INTSEL11_MASK                          ((uint32_t)0x7F000000u)
#define CSL_CGEM_INTMUX2_INTSEL11_RESETVAL                      ((uint32_t)0x0000000bu)
#define CSL_CGEM_INTMUX2_INTSEL11_MAX                           ((uint32_t)0x0000007fu)

#define CSL_CGEM_INTMUX2_INTSEL10_SHIFT                         ((uint32_t)16u)
#define CSL_CGEM_INTMUX2_INTSEL10_MASK                          ((uint32_t)0x007F0000u)
#define CSL_CGEM_INTMUX2_INTSEL10_RESETVAL                      ((uint32_t)0x0000000au)
#define CSL_CGEM_INTMUX2_INTSEL10_MAX                           ((uint32_t)0x0000007fu)

#define CSL_CGEM_INTMUX2_INTSEL9_SHIFT                          ((uint32_t)8u)
#define CSL_CGEM_INTMUX2_INTSEL9_MASK                           ((uint32_t)0x00007F00u)
#define CSL_CGEM_INTMUX2_INTSEL9_RESETVAL                       ((uint32_t)0x00000009u)
#define CSL_CGEM_INTMUX2_INTSEL9_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_INTMUX2_INTSEL8_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_INTMUX2_INTSEL8_MASK                           ((uint32_t)0x0000007Fu)
#define CSL_CGEM_INTMUX2_INTSEL8_RESETVAL                       ((uint32_t)0x00000008u)
#define CSL_CGEM_INTMUX2_INTSEL8_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_INTMUX2_RESETVAL                               ((uint32_t)0x0b0a0908u)

/* INTMUX3 */

#define CSL_CGEM_INTMUX3__RESV3_SHIFT                           ((uint32_t)31u)
#define CSL_CGEM_INTMUX3__RESV3_MASK                            ((uint32_t)0x80000000u)
#define CSL_CGEM_INTMUX3__RESV3_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTMUX3__RESV3_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_INTMUX3__RESV2_SHIFT                           ((uint32_t)23u)
#define CSL_CGEM_INTMUX3__RESV2_MASK                            ((uint32_t)0x00800000u)
#define CSL_CGEM_INTMUX3__RESV2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTMUX3__RESV2_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_INTMUX3__RESV1_SHIFT                           ((uint32_t)15u)
#define CSL_CGEM_INTMUX3__RESV1_MASK                            ((uint32_t)0x00008000u)
#define CSL_CGEM_INTMUX3__RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTMUX3__RESV1_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_INTMUX3__RESV0_SHIFT                           ((uint32_t)7u)
#define CSL_CGEM_INTMUX3__RESV0_MASK                            ((uint32_t)0x00000080u)
#define CSL_CGEM_INTMUX3__RESV0_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTMUX3__RESV0_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_INTMUX3_INTSEL15_SHIFT                         ((uint32_t)24u)
#define CSL_CGEM_INTMUX3_INTSEL15_MASK                          ((uint32_t)0x7F000000u)
#define CSL_CGEM_INTMUX3_INTSEL15_RESETVAL                      ((uint32_t)0x0000000fu)
#define CSL_CGEM_INTMUX3_INTSEL15_MAX                           ((uint32_t)0x0000007fu)

#define CSL_CGEM_INTMUX3_INTSEL14_SHIFT                         ((uint32_t)16u)
#define CSL_CGEM_INTMUX3_INTSEL14_MASK                          ((uint32_t)0x007F0000u)
#define CSL_CGEM_INTMUX3_INTSEL14_RESETVAL                      ((uint32_t)0x0000000eu)
#define CSL_CGEM_INTMUX3_INTSEL14_MAX                           ((uint32_t)0x0000007fu)

#define CSL_CGEM_INTMUX3_INTSEL13_SHIFT                         ((uint32_t)8u)
#define CSL_CGEM_INTMUX3_INTSEL13_MASK                          ((uint32_t)0x00007F00u)
#define CSL_CGEM_INTMUX3_INTSEL13_RESETVAL                      ((uint32_t)0x0000000du)
#define CSL_CGEM_INTMUX3_INTSEL13_MAX                           ((uint32_t)0x0000007fu)

#define CSL_CGEM_INTMUX3_INTSEL12_SHIFT                         ((uint32_t)0u)
#define CSL_CGEM_INTMUX3_INTSEL12_MASK                          ((uint32_t)0x0000007Fu)
#define CSL_CGEM_INTMUX3_INTSEL12_RESETVAL                      ((uint32_t)0x0000000cu)
#define CSL_CGEM_INTMUX3_INTSEL12_MAX                           ((uint32_t)0x0000007fu)

#define CSL_CGEM_INTMUX3_RESETVAL                               ((uint32_t)0x0f0e0d0cu)

/* AEGMUX0 */

#define CSL_CGEM_AEGMUX0_AEGSEL3_SHIFT                          ((uint32_t)24u)
#define CSL_CGEM_AEGMUX0_AEGSEL3_MASK                           ((uint32_t)0x7F000000u)
#define CSL_CGEM_AEGMUX0_AEGSEL3_RESETVAL                       ((uint32_t)0x00000003u)
#define CSL_CGEM_AEGMUX0_AEGSEL3_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_AEGMUX0_AEGSEL2_SHIFT                          ((uint32_t)16u)
#define CSL_CGEM_AEGMUX0_AEGSEL2_MASK                           ((uint32_t)0x007F0000u)
#define CSL_CGEM_AEGMUX0_AEGSEL2_RESETVAL                       ((uint32_t)0x00000002u)
#define CSL_CGEM_AEGMUX0_AEGSEL2_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_AEGMUX0_AEGSEL1_SHIFT                          ((uint32_t)8u)
#define CSL_CGEM_AEGMUX0_AEGSEL1_MASK                           ((uint32_t)0x00007F00u)
#define CSL_CGEM_AEGMUX0_AEGSEL1_RESETVAL                       ((uint32_t)0x00000001u)
#define CSL_CGEM_AEGMUX0_AEGSEL1_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_AEGMUX0_AEGSEL0_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_AEGMUX0_AEGSEL0_MASK                           ((uint32_t)0x0000007Fu)
#define CSL_CGEM_AEGMUX0_AEGSEL0_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_AEGMUX0_AEGSEL0_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_AEGMUX0_RESETVAL                               ((uint32_t)0x03020100u)

/* AEGMUX1 */

#define CSL_CGEM_AEGMUX1_AEGSEL7_SHIFT                          ((uint32_t)24u)
#define CSL_CGEM_AEGMUX1_AEGSEL7_MASK                           ((uint32_t)0x7F000000u)
#define CSL_CGEM_AEGMUX1_AEGSEL7_RESETVAL                       ((uint32_t)0x00000007u)
#define CSL_CGEM_AEGMUX1_AEGSEL7_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_AEGMUX1_AEGSEL6_SHIFT                          ((uint32_t)16u)
#define CSL_CGEM_AEGMUX1_AEGSEL6_MASK                           ((uint32_t)0x007F0000u)
#define CSL_CGEM_AEGMUX1_AEGSEL6_RESETVAL                       ((uint32_t)0x00000006u)
#define CSL_CGEM_AEGMUX1_AEGSEL6_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_AEGMUX1_AEGSEL5_SHIFT                          ((uint32_t)8u)
#define CSL_CGEM_AEGMUX1_AEGSEL5_MASK                           ((uint32_t)0x00007F00u)
#define CSL_CGEM_AEGMUX1_AEGSEL5_RESETVAL                       ((uint32_t)0x00000005u)
#define CSL_CGEM_AEGMUX1_AEGSEL5_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_AEGMUX1_AEGSEL4_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_AEGMUX1_AEGSEL4_MASK                           ((uint32_t)0x0000007Fu)
#define CSL_CGEM_AEGMUX1_AEGSEL4_RESETVAL                       ((uint32_t)0x00000004u)
#define CSL_CGEM_AEGMUX1_AEGSEL4_MAX                            ((uint32_t)0x0000007fu)

#define CSL_CGEM_AEGMUX1_RESETVAL                               ((uint32_t)0x07060504u)

/* INTXSTAT */

#define CSL_CGEM_INTXSTAT_SYSINT_SHIFT                          ((uint32_t)24u)
#define CSL_CGEM_INTXSTAT_SYSINT_MASK                           ((uint32_t)0xFF000000u)
#define CSL_CGEM_INTXSTAT_SYSINT_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_INTXSTAT_SYSINT_MAX                            ((uint32_t)0x000000ffu)

#define CSL_CGEM_INTXSTAT_CPUINT_SHIFT                          ((uint32_t)16u)
#define CSL_CGEM_INTXSTAT_CPUINT_MASK                           ((uint32_t)0x00FF0000u)
#define CSL_CGEM_INTXSTAT_CPUINT_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_INTXSTAT_CPUINT_MAX                            ((uint32_t)0x000000ffu)

#define CSL_CGEM_INTXSTAT__RESV3_SHIFT                          ((uint32_t)1u)
#define CSL_CGEM_INTXSTAT__RESV3_MASK                           ((uint32_t)0x0000FFFEu)
#define CSL_CGEM_INTXSTAT__RESV3_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_INTXSTAT__RESV3_MAX                            ((uint32_t)0x00007fffu)

#define CSL_CGEM_INTXSTAT_DROP_SHIFT                            ((uint32_t)0u)
#define CSL_CGEM_INTXSTAT_DROP_MASK                             ((uint32_t)0x00000001u)
#define CSL_CGEM_INTXSTAT_DROP_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_INTXSTAT_DROP_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_INTXSTAT_RESETVAL                              ((uint32_t)0x00000000u)

/* INTXCLR */

#define CSL_CGEM_INTXCLR__RESV3_SHIFT                           ((uint32_t)1u)
#define CSL_CGEM_INTXCLR__RESV3_MASK                            ((uint32_t)0xFFFFFFFEu)
#define CSL_CGEM_INTXCLR__RESV3_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_INTXCLR__RESV3_MAX                             ((uint32_t)0x7fffffffu)

#define CSL_CGEM_INTXCLR_CLEAR_SHIFT                            ((uint32_t)0u)
#define CSL_CGEM_INTXCLR_CLEAR_MASK                             ((uint32_t)0x00000001u)
#define CSL_CGEM_INTXCLR_CLEAR_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_INTXCLR_CLEAR_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_INTXCLR_RESETVAL                               ((uint32_t)0x00000000u)

/* INTDMASK */

#define CSL_CGEM_INTDMASK__RESV1_SHIFT                          ((uint32_t)16u)
#define CSL_CGEM_INTDMASK__RESV1_MASK                           ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_INTDMASK__RESV1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_INTDMASK__RESV1_MAX                            ((uint32_t)0x0000ffffu)

#define CSL_CGEM_INTDMASK_IDM_SHIFT                             ((uint32_t)4u)
#define CSL_CGEM_INTDMASK_IDM_MASK                              ((uint32_t)0x0000FFF0u)
#define CSL_CGEM_INTDMASK_IDM_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_INTDMASK_IDM_MAX                               ((uint32_t)0x00000fffu)

#define CSL_CGEM_INTDMASK__RESV0_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_INTDMASK__RESV0_MASK                           ((uint32_t)0x0000000Fu)
#define CSL_CGEM_INTDMASK__RESV0_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_INTDMASK__RESV0_MAX                            ((uint32_t)0x0000000fu)

#define CSL_CGEM_INTDMASK_RESETVAL                              ((uint32_t)0x00000000u)

/* EVTASRT */

#define CSL_CGEM_EVTASRT_MRA_SHIFT                              ((uint32_t)31u)
#define CSL_CGEM_EVTASRT_MRA_MASK                               ((uint32_t)0x80000000u)
#define CSL_CGEM_EVTASRT_MRA_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_EVTASRT_MRA_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_EVTASRT_SRA_SHIFT                              ((uint32_t)30u)
#define CSL_CGEM_EVTASRT_SRA_MASK                               ((uint32_t)0x40000000u)
#define CSL_CGEM_EVTASRT_SRA_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_EVTASRT_SRA_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_EVTASRT_CRA_SHIFT                              ((uint32_t)29u)
#define CSL_CGEM_EVTASRT_CRA_MASK                               ((uint32_t)0x20000000u)
#define CSL_CGEM_EVTASRT_CRA_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_EVTASRT_CRA_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_EVTASRT_LRA_SHIFT                              ((uint32_t)28u)
#define CSL_CGEM_EVTASRT_LRA_MASK                               ((uint32_t)0x10000000u)
#define CSL_CGEM_EVTASRT_LRA_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_EVTASRT_LRA_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_EVTASRT__RESV0_SHIFT                           ((uint32_t)8u)
#define CSL_CGEM_EVTASRT__RESV0_MASK                            ((uint32_t)0x0FFFFF00u)
#define CSL_CGEM_EVTASRT__RESV0_RESETVAL                        ((uint32_t)0x00030201u)
#define CSL_CGEM_EVTASRT__RESV0_MAX                             ((uint32_t)0x000fffffu)

#define CSL_CGEM_EVTASRT_EA_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_EVTASRT_EA_MASK                                ((uint32_t)0x000000FFu)
#define CSL_CGEM_EVTASRT_EA_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_EVTASRT_EA_MAX                                 ((uint32_t)0x000000ffu)

#define CSL_CGEM_EVTASRT_RESETVAL                               ((uint32_t)0x03020100u)

/* PDCCMD */

#define CSL_CGEM_PDCCMD_RESV_1_SHIFT                            ((uint32_t)17u)
#define CSL_CGEM_PDCCMD_RESV_1_MASK                             ((uint32_t)0xFFFE0000u)
#define CSL_CGEM_PDCCMD_RESV_1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PDCCMD_RESV_1_MAX                              ((uint32_t)0x00007fffu)

#define CSL_CGEM_PDCCMD_GEMPD_SHIFT                             ((uint32_t)16u)
#define CSL_CGEM_PDCCMD_GEMPD_MASK                              ((uint32_t)0x00010000u)
#define CSL_CGEM_PDCCMD_GEMPD_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_PDCCMD_GEMPD_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_PDCCMD_RESV_2_SHIFT                            ((uint32_t)14u)
#define CSL_CGEM_PDCCMD_RESV_2_MASK                             ((uint32_t)0x0000C000u)
#define CSL_CGEM_PDCCMD_RESV_2_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PDCCMD_RESV_2_MAX                              ((uint32_t)0x00000003u)

#define CSL_CGEM_PDCCMD_EMCLOG_SHIFT                            ((uint32_t)12u)
#define CSL_CGEM_PDCCMD_EMCLOG_MASK                             ((uint32_t)0x00003000u)
#define CSL_CGEM_PDCCMD_EMCLOG_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PDCCMD_EMCLOG_MAX                              ((uint32_t)0x00000003u)

#define CSL_CGEM_PDCCMD_RESV_3_SHIFT                            ((uint32_t)10u)
#define CSL_CGEM_PDCCMD_RESV_3_MASK                             ((uint32_t)0x00000C00u)
#define CSL_CGEM_PDCCMD_RESV_3_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PDCCMD_RESV_3_MAX                              ((uint32_t)0x00000003u)

#define CSL_CGEM_PDCCMD_UMCLOG_SHIFT                            ((uint32_t)8u)
#define CSL_CGEM_PDCCMD_UMCLOG_MASK                             ((uint32_t)0x00000300u)
#define CSL_CGEM_PDCCMD_UMCLOG_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PDCCMD_UMCLOG_MAX                              ((uint32_t)0x00000003u)

#define CSL_CGEM_PDCCMD_DMCMEM_SHIFT                            ((uint32_t)6u)
#define CSL_CGEM_PDCCMD_DMCMEM_MASK                             ((uint32_t)0x000000C0u)
#define CSL_CGEM_PDCCMD_DMCMEM_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PDCCMD_DMCMEM_MAX                              ((uint32_t)0x00000003u)

#define CSL_CGEM_PDCCMD_DMCLOG_SHIFT                            ((uint32_t)4u)
#define CSL_CGEM_PDCCMD_DMCLOG_MASK                             ((uint32_t)0x00000030u)
#define CSL_CGEM_PDCCMD_DMCLOG_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PDCCMD_DMCLOG_MAX                              ((uint32_t)0x00000003u)

#define CSL_CGEM_PDCCMD_PMCMEM_SHIFT                            ((uint32_t)2u)
#define CSL_CGEM_PDCCMD_PMCMEM_MASK                             ((uint32_t)0x0000000Cu)
#define CSL_CGEM_PDCCMD_PMCMEM_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PDCCMD_PMCMEM_MAX                              ((uint32_t)0x00000003u)

#define CSL_CGEM_PDCCMD_PMCLOG_SHIFT                            ((uint32_t)0u)
#define CSL_CGEM_PDCCMD_PMCLOG_MASK                             ((uint32_t)0x00000003u)
#define CSL_CGEM_PDCCMD_PMCLOG_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PDCCMD_PMCLOG_MAX                              ((uint32_t)0x00000003u)

#define CSL_CGEM_PDCCMD_RESETVAL                                ((uint32_t)0x00000000u)

/* EDCINTMASK */

#define CSL_CGEM_EDCINTMASK_L1DDATA_SHIFT                       ((uint32_t)0u)
#define CSL_CGEM_EDCINTMASK_L1DDATA_MASK                        ((uint32_t)0x00000001u)
#define CSL_CGEM_EDCINTMASK_L1DDATA_RESETVAL                    ((uint32_t)0x00000001u)
#define CSL_CGEM_EDCINTMASK_L1DDATA_MAX                         ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTMASK_L1DTAG_SHIFT                        ((uint32_t)1u)
#define CSL_CGEM_EDCINTMASK_L1DTAG_MASK                         ((uint32_t)0x00000002u)
#define CSL_CGEM_EDCINTMASK_L1DTAG_RESETVAL                     ((uint32_t)0x00000001u)
#define CSL_CGEM_EDCINTMASK_L1DTAG_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTMASK_L2MPPA_SHIFT                        ((uint32_t)2u)
#define CSL_CGEM_EDCINTMASK_L2MPPA_MASK                         ((uint32_t)0x00000004u)
#define CSL_CGEM_EDCINTMASK_L2MPPA_RESETVAL                     ((uint32_t)0x00000001u)
#define CSL_CGEM_EDCINTMASK_L2MPPA_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTMASK_L2TAG_SHIFT                         ((uint32_t)3u)
#define CSL_CGEM_EDCINTMASK_L2TAG_MASK                          ((uint32_t)0x00000008u)
#define CSL_CGEM_EDCINTMASK_L2TAG_RESETVAL                      ((uint32_t)0x00000001u)
#define CSL_CGEM_EDCINTMASK_L2TAG_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTMASK_L2SNOP_SHIFT                        ((uint32_t)4u)
#define CSL_CGEM_EDCINTMASK_L2SNOP_MASK                         ((uint32_t)0x00000010u)
#define CSL_CGEM_EDCINTMASK_L2SNOP_RESETVAL                     ((uint32_t)0x00000001u)
#define CSL_CGEM_EDCINTMASK_L2SNOP_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTMASK_L2LRU_SHIFT                         ((uint32_t)5u)
#define CSL_CGEM_EDCINTMASK_L2LRU_MASK                          ((uint32_t)0x00000020u)
#define CSL_CGEM_EDCINTMASK_L2LRU_RESETVAL                      ((uint32_t)0x00000001u)
#define CSL_CGEM_EDCINTMASK_L2LRU_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTMASK_L1PTAG_SHIFT                        ((uint32_t)6u)
#define CSL_CGEM_EDCINTMASK_L1PTAG_MASK                         ((uint32_t)0x00000040u)
#define CSL_CGEM_EDCINTMASK_L1PTAG_RESETVAL                     ((uint32_t)0x00000001u)
#define CSL_CGEM_EDCINTMASK_L1PTAG_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTMASK_RESETVAL                            ((uint32_t)0x0000007fu)

/* MM_REVID */

#define CSL_CGEM_MM_REVID_MM_REVID_SHIFT                        ((uint32_t)0u)
#define CSL_CGEM_MM_REVID_MM_REVID_MASK                         ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_MM_REVID_MM_REVID_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_MM_REVID_MM_REVID_MAX                          ((uint32_t)0xffffffffu)

#define CSL_CGEM_MM_REVID_RESETVAL                              ((uint32_t)0x00000000u)

/* IDMA0_STAT */

#define CSL_CGEM_IDMA0_STAT__RESV1_SHIFT                        ((uint32_t)2u)
#define CSL_CGEM_IDMA0_STAT__RESV1_MASK                         ((uint32_t)0xFFFFFFFCu)
#define CSL_CGEM_IDMA0_STAT__RESV1_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA0_STAT__RESV1_MAX                          ((uint32_t)0x3fffffffu)

#define CSL_CGEM_IDMA0_STAT_PEND_SHIFT                          ((uint32_t)1u)
#define CSL_CGEM_IDMA0_STAT_PEND_MASK                           ((uint32_t)0x00000002u)
#define CSL_CGEM_IDMA0_STAT_PEND_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA0_STAT_PEND_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_IDMA0_STAT_ACTV_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_IDMA0_STAT_ACTV_MASK                           ((uint32_t)0x00000001u)
#define CSL_CGEM_IDMA0_STAT_ACTV_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA0_STAT_ACTV_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_IDMA0_STAT_RESETVAL                            ((uint32_t)0x00000000u)

/* IDMA0_MASK */

#define CSL_CGEM_IDMA0_MASK_MASK_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_IDMA0_MASK_MASK_MASK                           ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_IDMA0_MASK_MASK_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA0_MASK_MASK_MAX                            ((uint32_t)0xffffffffu)

#define CSL_CGEM_IDMA0_MASK_RESETVAL                            ((uint32_t)0x00000000u)

/* IDMA0_SOURCE */

#define CSL_CGEM_IDMA0_SOURCE_SOURCEADDR_SHIFT                  ((uint32_t)5u)
#define CSL_CGEM_IDMA0_SOURCE_SOURCEADDR_MASK                   ((uint32_t)0xFFFFFFE0u)
#define CSL_CGEM_IDMA0_SOURCE_SOURCEADDR_RESETVAL               ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA0_SOURCE_SOURCEADDR_MAX                    ((uint32_t)0x07ffffffu)

#define CSL_CGEM_IDMA0_SOURCE__RESV1_SHIFT                      ((uint32_t)0u)
#define CSL_CGEM_IDMA0_SOURCE__RESV1_MASK                       ((uint32_t)0x0000001Fu)
#define CSL_CGEM_IDMA0_SOURCE__RESV1_RESETVAL                   ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA0_SOURCE__RESV1_MAX                        ((uint32_t)0x0000001fu)

#define CSL_CGEM_IDMA0_SOURCE_RESETVAL                          ((uint32_t)0x00000000u)

/* IDMA0_DEST */

#define CSL_CGEM_IDMA0_DEST_DESTADDR_SHIFT                      ((uint32_t)5u)
#define CSL_CGEM_IDMA0_DEST_DESTADDR_MASK                       ((uint32_t)0xFFFFFFE0u)
#define CSL_CGEM_IDMA0_DEST_DESTADDR_RESETVAL                   ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA0_DEST_DESTADDR_MAX                        ((uint32_t)0x07ffffffu)

#define CSL_CGEM_IDMA0_DEST__RESV1_SHIFT                        ((uint32_t)0u)
#define CSL_CGEM_IDMA0_DEST__RESV1_MASK                         ((uint32_t)0x0000001Fu)
#define CSL_CGEM_IDMA0_DEST__RESV1_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA0_DEST__RESV1_MAX                          ((uint32_t)0x0000001fu)

#define CSL_CGEM_IDMA0_DEST_RESETVAL                            ((uint32_t)0x00000000u)

/* IDMA0_COUNT */

#define CSL_CGEM_IDMA0_COUNT__RESV1_SHIFT                       ((uint32_t)29u)
#define CSL_CGEM_IDMA0_COUNT__RESV1_MASK                        ((uint32_t)0xE0000000u)
#define CSL_CGEM_IDMA0_COUNT__RESV1_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA0_COUNT__RESV1_MAX                         ((uint32_t)0x00000007u)

#define CSL_CGEM_IDMA0_COUNT_INT_SHIFT                          ((uint32_t)28u)
#define CSL_CGEM_IDMA0_COUNT_INT_MASK                           ((uint32_t)0x10000000u)
#define CSL_CGEM_IDMA0_COUNT_INT_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA0_COUNT_INT_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_IDMA0_COUNT__RESV2_SHIFT                       ((uint32_t)4u)
#define CSL_CGEM_IDMA0_COUNT__RESV2_MASK                        ((uint32_t)0x0FFFFFF0u)
#define CSL_CGEM_IDMA0_COUNT__RESV2_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA0_COUNT__RESV2_MAX                         ((uint32_t)0x00ffffffu)

#define CSL_CGEM_IDMA0_COUNT_COUNT_SHIFT                        ((uint32_t)0u)
#define CSL_CGEM_IDMA0_COUNT_COUNT_MASK                         ((uint32_t)0x0000000Fu)
#define CSL_CGEM_IDMA0_COUNT_COUNT_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA0_COUNT_COUNT_MAX                          ((uint32_t)0x0000000fu)

#define CSL_CGEM_IDMA0_COUNT_RESETVAL                           ((uint32_t)0x00000000u)

/* IDMA1_STAT */

#define CSL_CGEM_IDMA1_STAT__RESV1_SHIFT                        ((uint32_t)2u)
#define CSL_CGEM_IDMA1_STAT__RESV1_MASK                         ((uint32_t)0xFFFFFFFCu)
#define CSL_CGEM_IDMA1_STAT__RESV1_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_STAT__RESV1_MAX                          ((uint32_t)0x3fffffffu)

#define CSL_CGEM_IDMA1_STAT_PEND_SHIFT                          ((uint32_t)1u)
#define CSL_CGEM_IDMA1_STAT_PEND_MASK                           ((uint32_t)0x00000002u)
#define CSL_CGEM_IDMA1_STAT_PEND_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_STAT_PEND_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_IDMA1_STAT_ACTV_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_IDMA1_STAT_ACTV_MASK                           ((uint32_t)0x00000001u)
#define CSL_CGEM_IDMA1_STAT_ACTV_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_STAT_ACTV_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_IDMA1_STAT_RESETVAL                            ((uint32_t)0x00000000u)

/* IDMA1_SOURCE */

#define CSL_CGEM_IDMA1_SOURCE_SOURCEADDR_SHIFT                  ((uint32_t)2u)
#define CSL_CGEM_IDMA1_SOURCE_SOURCEADDR_MASK                   ((uint32_t)0xFFFFFFFCu)
#define CSL_CGEM_IDMA1_SOURCE_SOURCEADDR_RESETVAL               ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_SOURCE_SOURCEADDR_MAX                    ((uint32_t)0x3fffffffu)

#define CSL_CGEM_IDMA1_SOURCE__RESV1_SHIFT                      ((uint32_t)0u)
#define CSL_CGEM_IDMA1_SOURCE__RESV1_MASK                       ((uint32_t)0x00000003u)
#define CSL_CGEM_IDMA1_SOURCE__RESV1_RESETVAL                   ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_SOURCE__RESV1_MAX                        ((uint32_t)0x00000003u)

#define CSL_CGEM_IDMA1_SOURCE_RESETVAL                          ((uint32_t)0x00000000u)

/* IDMA1_DEST */

#define CSL_CGEM_IDMA1_DEST_DESTADDR_SHIFT                      ((uint32_t)2u)
#define CSL_CGEM_IDMA1_DEST_DESTADDR_MASK                       ((uint32_t)0xFFFFFFFCu)
#define CSL_CGEM_IDMA1_DEST_DESTADDR_RESETVAL                   ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_DEST_DESTADDR_MAX                        ((uint32_t)0x3fffffffu)

#define CSL_CGEM_IDMA1_DEST__RESV1_SHIFT                        ((uint32_t)0u)
#define CSL_CGEM_IDMA1_DEST__RESV1_MASK                         ((uint32_t)0x00000003u)
#define CSL_CGEM_IDMA1_DEST__RESV1_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_DEST__RESV1_MAX                          ((uint32_t)0x00000003u)

#define CSL_CGEM_IDMA1_DEST_RESETVAL                            ((uint32_t)0x00000000u)

/* IDMA1_COUNT */

#define CSL_CGEM_IDMA1_COUNT_PRI_SHIFT                          ((uint32_t)29u)
#define CSL_CGEM_IDMA1_COUNT_PRI_MASK                           ((uint32_t)0xE0000000u)
#define CSL_CGEM_IDMA1_COUNT_PRI_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_COUNT_PRI_MAX                            ((uint32_t)0x00000007u)

#define CSL_CGEM_IDMA1_COUNT_INT_SHIFT                          ((uint32_t)28u)
#define CSL_CGEM_IDMA1_COUNT_INT_MASK                           ((uint32_t)0x10000000u)
#define CSL_CGEM_IDMA1_COUNT_INT_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_COUNT_INT_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_IDMA1_COUNT__RESV1_SHIFT                       ((uint32_t)17u)
#define CSL_CGEM_IDMA1_COUNT__RESV1_MASK                        ((uint32_t)0x0FFE0000u)
#define CSL_CGEM_IDMA1_COUNT__RESV1_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_COUNT__RESV1_MAX                         ((uint32_t)0x000007ffu)

#define CSL_CGEM_IDMA1_COUNT_FILL_SHIFT                         ((uint32_t)16u)
#define CSL_CGEM_IDMA1_COUNT_FILL_MASK                          ((uint32_t)0x00010000u)
#define CSL_CGEM_IDMA1_COUNT_FILL_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_COUNT_FILL_MAX                           ((uint32_t)0x00000001u)

/* CSL_MODIFICATION: Update from Autogen output */
#define CSL_CGEM_IDMA1_COUNT_COUNT_SHIFT                        ((uint32_t)0u)
#define CSL_CGEM_IDMA1_COUNT_COUNT_MASK                         ((uint32_t)0x0000FFFFu)

#define CSL_CGEM_IDMA1_COUNT_COUNT_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_COUNT_COUNT_MAX                          ((uint32_t)0x00003fffu)

#define CSL_CGEM_IDMA1_COUNT__RESV2_SHIFT                       ((uint32_t)0u)
#define CSL_CGEM_IDMA1_COUNT__RESV2_MASK                        ((uint32_t)0x00000003u)
#define CSL_CGEM_IDMA1_COUNT__RESV2_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMA1_COUNT__RESV2_MAX                         ((uint32_t)0x00000003u)

#define CSL_CGEM_IDMA1_COUNT_RESETVAL                           ((uint32_t)0x00000000u)

/* CPUARBE */

#define CSL_CGEM_CPUARBE_RESV_1_SHIFT                           ((uint32_t)19u)
#define CSL_CGEM_CPUARBE_RESV_1_MASK                            ((uint32_t)0xFFF80000u)
#define CSL_CGEM_CPUARBE_RESV_1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_CPUARBE_RESV_1_MAX                             ((uint32_t)0x00001fffu)

#define CSL_CGEM_CPUARBE_PRI_SHIFT                              ((uint32_t)16u)
#define CSL_CGEM_CPUARBE_PRI_MASK                               ((uint32_t)0x00070000u)
#define CSL_CGEM_CPUARBE_PRI_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_CPUARBE_PRI_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_CPUARBE_RESV_2_SHIFT                           ((uint32_t)6u)
#define CSL_CGEM_CPUARBE_RESV_2_MASK                            ((uint32_t)0x0000FFC0u)
#define CSL_CGEM_CPUARBE_RESV_2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_CPUARBE_RESV_2_MAX                             ((uint32_t)0x000003ffu)

#define CSL_CGEM_CPUARBE_MAXWAIT_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_CPUARBE_MAXWAIT_MASK                           ((uint32_t)0x0000003Fu)
#define CSL_CGEM_CPUARBE_MAXWAIT_RESETVAL                       ((uint32_t)0x00000010u)
#define CSL_CGEM_CPUARBE_MAXWAIT_MAX                            ((uint32_t)0x0000003fu)

#define CSL_CGEM_CPUARBE_RESETVAL                               ((uint32_t)0x00010010u)

/* IDMAARBE */

#define CSL_CGEM_IDMAARBE_RESV_1_SHIFT                          ((uint32_t)6u)
#define CSL_CGEM_IDMAARBE_RESV_1_MASK                           ((uint32_t)0xFFFFFFC0u)
#define CSL_CGEM_IDMAARBE_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMAARBE_RESV_1_MAX                            ((uint32_t)0x03ffffffu)

#define CSL_CGEM_IDMAARBE_MAXWAIT_SHIFT                         ((uint32_t)0u)
#define CSL_CGEM_IDMAARBE_MAXWAIT_MASK                          ((uint32_t)0x0000003Fu)
#define CSL_CGEM_IDMAARBE_MAXWAIT_RESETVAL                      ((uint32_t)0x00000010u)
#define CSL_CGEM_IDMAARBE_MAXWAIT_MAX                           ((uint32_t)0x0000003fu)

#define CSL_CGEM_IDMAARBE_RESETVAL                              ((uint32_t)0x00000010u)

/* SDMAARBE */

#define CSL_CGEM_SDMAARBE_RESV_1_SHIFT                          ((uint32_t)6u)
#define CSL_CGEM_SDMAARBE_RESV_1_MASK                           ((uint32_t)0xFFFFFFC0u)
#define CSL_CGEM_SDMAARBE_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_SDMAARBE_RESV_1_MAX                            ((uint32_t)0x03ffffffu)

#define CSL_CGEM_SDMAARBE_MAXWAIT_SHIFT                         ((uint32_t)0u)
#define CSL_CGEM_SDMAARBE_MAXWAIT_MASK                          ((uint32_t)0x0000003Fu)
#define CSL_CGEM_SDMAARBE_MAXWAIT_RESETVAL                      ((uint32_t)0x00000001u)
#define CSL_CGEM_SDMAARBE_MAXWAIT_MAX                           ((uint32_t)0x0000003fu)

#define CSL_CGEM_SDMAARBE_RESETVAL                              ((uint32_t)0x00000001u)

/* ECFGARBE */

#define CSL_CGEM_ECFGARBE_RESV_2_SHIFT                          ((uint32_t)19u)
#define CSL_CGEM_ECFGARBE_RESV_2_MASK                           ((uint32_t)0xFFF80000u)
#define CSL_CGEM_ECFGARBE_RESV_2_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_ECFGARBE_RESV_2_MAX                            ((uint32_t)0x00001fffu)

#define CSL_CGEM_ECFGARBE_PRI_SHIFT                             ((uint32_t)16u)
#define CSL_CGEM_ECFGARBE_PRI_MASK                              ((uint32_t)0x00070000u)
#define CSL_CGEM_ECFGARBE_PRI_RESETVAL                          ((uint32_t)0x00000007u)
#define CSL_CGEM_ECFGARBE_PRI_MAX                               ((uint32_t)0x00000007u)

#define CSL_CGEM_ECFGARBE_RESV_1_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_ECFGARBE_RESV_1_MASK                           ((uint32_t)0x0000FFFFu)
#define CSL_CGEM_ECFGARBE_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_ECFGARBE_RESV_1_MAX                            ((uint32_t)0x0000ffffu)

#define CSL_CGEM_ECFGARBE_RESETVAL                              ((uint32_t)0x00070000u)

/* ICFGMPFAR */

#define CSL_CGEM_ICFGMPFAR_ADDR_SHIFT                           ((uint32_t)0u)
#define CSL_CGEM_ICFGMPFAR_ADDR_MASK                            ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_ICFGMPFAR_ADDR_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFAR_ADDR_MAX                             ((uint32_t)0xffffffffu)

#define CSL_CGEM_ICFGMPFAR_RESETVAL                             ((uint32_t)0x00000000u)

/* ICFGMPFSR */

#define CSL_CGEM_ICFGMPFSR_RESV_1_SHIFT                         ((uint32_t)16u)
#define CSL_CGEM_ICFGMPFSR_RESV_1_MASK                          ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_ICFGMPFSR_RESV_1_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFSR_RESV_1_MAX                           ((uint32_t)0x0000ffffu)

#define CSL_CGEM_ICFGMPFSR_FID_SHIFT                            ((uint32_t)8u)
#define CSL_CGEM_ICFGMPFSR_FID_MASK                             ((uint32_t)0x0000FF00u)
#define CSL_CGEM_ICFGMPFSR_FID_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFSR_FID_MAX                              ((uint32_t)0x000000ffu)

#define CSL_CGEM_ICFGMPFSR_SECE_SHIFT                           ((uint32_t)7u)
#define CSL_CGEM_ICFGMPFSR_SECE_MASK                            ((uint32_t)0x00000080u)
#define CSL_CGEM_ICFGMPFSR_SECE_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFSR_SECE_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_ICFGMPFSR_RESV_2_SHIFT                         ((uint32_t)6u)
#define CSL_CGEM_ICFGMPFSR_RESV_2_MASK                          ((uint32_t)0x00000040u)
#define CSL_CGEM_ICFGMPFSR_RESV_2_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFSR_RESV_2_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_ICFGMPFSR_SR_SHIFT                             ((uint32_t)5u)
#define CSL_CGEM_ICFGMPFSR_SR_MASK                              ((uint32_t)0x00000020u)
#define CSL_CGEM_ICFGMPFSR_SR_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFSR_SR_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_ICFGMPFSR_SW_SHIFT                             ((uint32_t)4u)
#define CSL_CGEM_ICFGMPFSR_SW_MASK                              ((uint32_t)0x00000010u)
#define CSL_CGEM_ICFGMPFSR_SW_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFSR_SW_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_ICFGMPFSR_SX_SHIFT                             ((uint32_t)3u)
#define CSL_CGEM_ICFGMPFSR_SX_MASK                              ((uint32_t)0x00000008u)
#define CSL_CGEM_ICFGMPFSR_SX_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFSR_SX_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_ICFGMPFSR_UR_SHIFT                             ((uint32_t)2u)
#define CSL_CGEM_ICFGMPFSR_UR_MASK                              ((uint32_t)0x00000004u)
#define CSL_CGEM_ICFGMPFSR_UR_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFSR_UR_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_ICFGMPFSR_UW_SHIFT                             ((uint32_t)1u)
#define CSL_CGEM_ICFGMPFSR_UW_MASK                              ((uint32_t)0x00000002u)
#define CSL_CGEM_ICFGMPFSR_UW_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFSR_UW_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_ICFGMPFSR_UX_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_ICFGMPFSR_UX_MASK                              ((uint32_t)0x00000001u)
#define CSL_CGEM_ICFGMPFSR_UX_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFSR_UX_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_ICFGMPFSR_RESETVAL                             ((uint32_t)0x00000000u)

/* ICFGMPFCR */

#define CSL_CGEM_ICFGMPFCR_RESV_1_SHIFT                         ((uint32_t)1u)
#define CSL_CGEM_ICFGMPFCR_RESV_1_MASK                          ((uint32_t)0xFFFFFFFEu)
#define CSL_CGEM_ICFGMPFCR_RESV_1_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFCR_RESV_1_MAX                           ((uint32_t)0x7fffffffu)

#define CSL_CGEM_ICFGMPFCR_MPFCLR_SHIFT                         ((uint32_t)0u)
#define CSL_CGEM_ICFGMPFCR_MPFCLR_MASK                          ((uint32_t)0x00000001u)
#define CSL_CGEM_ICFGMPFCR_MPFCLR_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_ICFGMPFCR_MPFCLR_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_ICFGMPFCR_RESETVAL                             ((uint32_t)0x00000000u)

/* ECFGERR */

#define CSL_CGEM_ECFGERR_ERR_SHIFT                              ((uint32_t)29u)
#define CSL_CGEM_ECFGERR_ERR_MASK                               ((uint32_t)0xE0000000u)
#define CSL_CGEM_ECFGERR_ERR_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_ECFGERR_ERR_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_ECFGERR_RESV_2_SHIFT                           ((uint32_t)12u)
#define CSL_CGEM_ECFGERR_RESV_2_MASK                            ((uint32_t)0x1FFFF000u)
#define CSL_CGEM_ECFGERR_RESV_2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_ECFGERR_RESV_2_MAX                             ((uint32_t)0x0001ffffu)

#define CSL_CGEM_ECFGERR_XID_SHIFT                              ((uint32_t)8u)
#define CSL_CGEM_ECFGERR_XID_MASK                               ((uint32_t)0x00000F00u)
#define CSL_CGEM_ECFGERR_XID_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_ECFGERR_XID_MAX                                ((uint32_t)0x0000000fu)

#define CSL_CGEM_ECFGERR_RESV_1_SHIFT                           ((uint32_t)3u)
#define CSL_CGEM_ECFGERR_RESV_1_MASK                            ((uint32_t)0x000000F8u)
#define CSL_CGEM_ECFGERR_RESV_1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_ECFGERR_RESV_1_MAX                             ((uint32_t)0x0000001fu)

#define CSL_CGEM_ECFGERR_STAT_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_ECFGERR_STAT_MASK                              ((uint32_t)0x00000007u)
#define CSL_CGEM_ECFGERR_STAT_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_ECFGERR_STAT_MAX                               ((uint32_t)0x00000007u)

#define CSL_CGEM_ECFGERR_RESETVAL                               ((uint32_t)0x00000000u)

/* ECFGERRCLR */

#define CSL_CGEM_ECFGERRCLR_RESV_1_SHIFT                        ((uint32_t)1u)
#define CSL_CGEM_ECFGERRCLR_RESV_1_MASK                         ((uint32_t)0xFFFFFFFEu)
#define CSL_CGEM_ECFGERRCLR_RESV_1_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_ECFGERRCLR_RESV_1_MAX                          ((uint32_t)0x7fffffffu)

#define CSL_CGEM_ECFGERRCLR_CLR_SHIFT                           ((uint32_t)0u)
#define CSL_CGEM_ECFGERRCLR_CLR_MASK                            ((uint32_t)0x00000001u)
#define CSL_CGEM_ECFGERRCLR_CLR_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_ECFGERRCLR_CLR_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_ECFGERRCLR_RESETVAL                            ((uint32_t)0x00000000u)

/* PAMAP0 */

#define CSL_CGEM_PAMAP0__RESV1_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_PAMAP0__RESV1_MASK                             ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP0__RESV1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP0__RESV1_MAX                              ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP0_AID_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_PAMAP0_AID_MASK                                ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP0_AID_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP0_AID_MAX                                 ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP0_RESETVAL                                ((uint32_t)0x00000000u)

/* PAMAP1 */

#define CSL_CGEM_PAMAP1__RESV1_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_PAMAP1__RESV1_MASK                             ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP1__RESV1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP1__RESV1_MAX                              ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP1_AID_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_PAMAP1_AID_MASK                                ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP1_AID_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_PAMAP1_AID_MAX                                 ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP1_RESETVAL                                ((uint32_t)0x00000001u)

/* PAMAP2 */

#define CSL_CGEM_PAMAP2__RESV1_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_PAMAP2__RESV1_MASK                             ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP2__RESV1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP2__RESV1_MAX                              ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP2_AID_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_PAMAP2_AID_MASK                                ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP2_AID_RESETVAL                            ((uint32_t)0x00000002u)
#define CSL_CGEM_PAMAP2_AID_MAX                                 ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP2_RESETVAL                                ((uint32_t)0x00000002u)

/* PAMAP3 */

#define CSL_CGEM_PAMAP3__RESV1_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_PAMAP3__RESV1_MASK                             ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP3__RESV1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP3__RESV1_MAX                              ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP3_AID_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_PAMAP3_AID_MASK                                ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP3_AID_RESETVAL                            ((uint32_t)0x00000003u)
#define CSL_CGEM_PAMAP3_AID_MAX                                 ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP3_RESETVAL                                ((uint32_t)0x00000003u)

/* PAMAP4 */

#define CSL_CGEM_PAMAP4__RESV1_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_PAMAP4__RESV1_MASK                             ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP4__RESV1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP4__RESV1_MAX                              ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP4_AID_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_PAMAP4_AID_MASK                                ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP4_AID_RESETVAL                            ((uint32_t)0x00000004u)
#define CSL_CGEM_PAMAP4_AID_MAX                                 ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP4_RESETVAL                                ((uint32_t)0x00000004u)

/* PAMAP5 */

#define CSL_CGEM_PAMAP5__RESV1_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_PAMAP5__RESV1_MASK                             ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP5__RESV1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP5__RESV1_MAX                              ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP5_AID_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_PAMAP5_AID_MASK                                ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP5_AID_RESETVAL                            ((uint32_t)0x00000005u)
#define CSL_CGEM_PAMAP5_AID_MAX                                 ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP5_RESETVAL                                ((uint32_t)0x00000005u)

/* PAMAP6 */

#define CSL_CGEM_PAMAP6__RESV1_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_PAMAP6__RESV1_MASK                             ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP6__RESV1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP6__RESV1_MAX                              ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP6_AID_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_PAMAP6_AID_MASK                                ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP6_AID_RESETVAL                            ((uint32_t)0x00000006u)
#define CSL_CGEM_PAMAP6_AID_MAX                                 ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP6_RESETVAL                                ((uint32_t)0x00000006u)

/* PAMAP7 */

#define CSL_CGEM_PAMAP7__RESV1_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_PAMAP7__RESV1_MASK                             ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP7__RESV1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP7__RESV1_MAX                              ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP7_AID_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_PAMAP7_AID_MASK                                ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP7_AID_RESETVAL                            ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP7_AID_MAX                                 ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP7_RESETVAL                                ((uint32_t)0x00000007u)

/* PAMAP8 */

#define CSL_CGEM_PAMAP8__RESV1_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_PAMAP8__RESV1_MASK                             ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP8__RESV1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP8__RESV1_MAX                              ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP8_AID_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_PAMAP8_AID_MASK                                ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP8_AID_RESETVAL                            ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP8_AID_MAX                                 ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP8_RESETVAL                                ((uint32_t)0x00000007u)

/* PAMAP9 */

#define CSL_CGEM_PAMAP9__RESV1_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_PAMAP9__RESV1_MASK                             ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP9__RESV1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP9__RESV1_MAX                              ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP9_AID_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_PAMAP9_AID_MASK                                ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP9_AID_RESETVAL                            ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP9_AID_MAX                                 ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP9_RESETVAL                                ((uint32_t)0x00000007u)

/* PAMAP10 */

#define CSL_CGEM_PAMAP10__RESV1_SHIFT                           ((uint32_t)3u)
#define CSL_CGEM_PAMAP10__RESV1_MASK                            ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP10__RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP10__RESV1_MAX                             ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP10_AID_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_PAMAP10_AID_MASK                               ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP10_AID_RESETVAL                           ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP10_AID_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP10_RESETVAL                               ((uint32_t)0x00000007u)

/* PAMAP11 */

#define CSL_CGEM_PAMAP11__RESV1_SHIFT                           ((uint32_t)3u)
#define CSL_CGEM_PAMAP11__RESV1_MASK                            ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP11__RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP11__RESV1_MAX                             ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP11_AID_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_PAMAP11_AID_MASK                               ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP11_AID_RESETVAL                           ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP11_AID_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP11_RESETVAL                               ((uint32_t)0x00000007u)

/* PAMAP12 */

#define CSL_CGEM_PAMAP12__RESV1_SHIFT                           ((uint32_t)3u)
#define CSL_CGEM_PAMAP12__RESV1_MASK                            ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP12__RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP12__RESV1_MAX                             ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP12_AID_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_PAMAP12_AID_MASK                               ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP12_AID_RESETVAL                           ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP12_AID_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP12_RESETVAL                               ((uint32_t)0x00000007u)

/* PAMAP13 */

#define CSL_CGEM_PAMAP13__RESV1_SHIFT                           ((uint32_t)3u)
#define CSL_CGEM_PAMAP13__RESV1_MASK                            ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP13__RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP13__RESV1_MAX                             ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP13_AID_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_PAMAP13_AID_MASK                               ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP13_AID_RESETVAL                           ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP13_AID_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP13_RESETVAL                               ((uint32_t)0x00000007u)

/* PAMAP14 */

#define CSL_CGEM_PAMAP14__RESV1_SHIFT                           ((uint32_t)3u)
#define CSL_CGEM_PAMAP14__RESV1_MASK                            ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP14__RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP14__RESV1_MAX                             ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP14_AID_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_PAMAP14_AID_MASK                               ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP14_AID_RESETVAL                           ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP14_AID_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP14_RESETVAL                               ((uint32_t)0x00000007u)

/* PAMAP15 */

#define CSL_CGEM_PAMAP15__RESV1_SHIFT                           ((uint32_t)3u)
#define CSL_CGEM_PAMAP15__RESV1_MASK                            ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_PAMAP15__RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_PAMAP15__RESV1_MAX                             ((uint32_t)0x1fffffffu)

#define CSL_CGEM_PAMAP15_AID_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_PAMAP15_AID_MASK                               ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP15_AID_RESETVAL                           ((uint32_t)0x00000007u)
#define CSL_CGEM_PAMAP15_AID_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_PAMAP15_RESETVAL                               ((uint32_t)0x00000007u)

/* EDCINTFLG */

#define CSL_CGEM_EDCINTFLG_L1DDATA_SHIFT                        ((uint32_t)0u)
#define CSL_CGEM_EDCINTFLG_L1DDATA_MASK                         ((uint32_t)0x00000001u)
#define CSL_CGEM_EDCINTFLG_L1DDATA_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_EDCINTFLG_L1DDATA_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTFLG_L1DTAG_SHIFT                         ((uint32_t)1u)
#define CSL_CGEM_EDCINTFLG_L1DTAG_MASK                          ((uint32_t)0x00000002u)
#define CSL_CGEM_EDCINTFLG_L1DTAG_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_EDCINTFLG_L1DTAG_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTFLG_L2MPPA_SHIFT                         ((uint32_t)4u)
#define CSL_CGEM_EDCINTFLG_L2MPPA_MASK                          ((uint32_t)0x00000010u)
#define CSL_CGEM_EDCINTFLG_L2MPPA_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_EDCINTFLG_L2MPPA_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTFLG_L2TAG_SHIFT                          ((uint32_t)2u)
#define CSL_CGEM_EDCINTFLG_L2TAG_MASK                           ((uint32_t)0x00000004u)
#define CSL_CGEM_EDCINTFLG_L2TAG_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_EDCINTFLG_L2TAG_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTFLG_L2SNOP_SHIFT                         ((uint32_t)3u)
#define CSL_CGEM_EDCINTFLG_L2SNOP_MASK                          ((uint32_t)0x00000008u)
#define CSL_CGEM_EDCINTFLG_L2SNOP_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_EDCINTFLG_L2SNOP_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTFLG_L2LRU_SHIFT                          ((uint32_t)5u)
#define CSL_CGEM_EDCINTFLG_L2LRU_MASK                           ((uint32_t)0x00000020u)
#define CSL_CGEM_EDCINTFLG_L2LRU_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_EDCINTFLG_L2LRU_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTFLG_L1PTAG_SHIFT                         ((uint32_t)6u)
#define CSL_CGEM_EDCINTFLG_L1PTAG_MASK                          ((uint32_t)0x00000040u)
#define CSL_CGEM_EDCINTFLG_L1PTAG_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_EDCINTFLG_L1PTAG_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_EDCINTFLG_RESETVAL                             ((uint32_t)0x00000000u)

/* L1DEDCMD */

#define CSL_CGEM_L1DEDCMD_ENDATA_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_L1DEDCMD_ENDATA_MASK                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DEDCMD_ENDATA_RESETVAL                       ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DEDCMD_ENDATA_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DEDCMD_ENTAG_SHIFT                           ((uint32_t)1u)
#define CSL_CGEM_L1DEDCMD_ENTAG_MASK                            ((uint32_t)0x00000002u)
#define CSL_CGEM_L1DEDCMD_ENTAG_RESETVAL                        ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DEDCMD_ENTAG_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DEDCMD_SUSPDATA_SHIFT                        ((uint32_t)8u)
#define CSL_CGEM_L1DEDCMD_SUSPDATA_MASK                         ((uint32_t)0x00000100u)
#define CSL_CGEM_L1DEDCMD_SUSPDATA_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DEDCMD_SUSPDATA_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DEDCMD_NCCLRDATA_SHIFT                       ((uint32_t)16u)
#define CSL_CGEM_L1DEDCMD_NCCLRDATA_MASK                        ((uint32_t)0x00010000u)
#define CSL_CGEM_L1DEDCMD_NCCLRDATA_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DEDCMD_NCCLRDATA_MAX                         ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DEDCMD_NCCLTAG_SHIFT                         ((uint32_t)17u)
#define CSL_CGEM_L1DEDCMD_NCCLTAG_MASK                          ((uint32_t)0x00020000u)
#define CSL_CGEM_L1DEDCMD_NCCLTAG_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DEDCMD_NCCLTAG_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DEDCMD_CCLRDATA_SHIFT                        ((uint32_t)24u)
#define CSL_CGEM_L1DEDCMD_CCLRDATA_MASK                         ((uint32_t)0x01000000u)
#define CSL_CGEM_L1DEDCMD_CCLRDATA_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DEDCMD_CCLRDATA_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DEDCMD_CCLRTAG_SHIFT                         ((uint32_t)25u)
#define CSL_CGEM_L1DEDCMD_CCLRTAG_MASK                          ((uint32_t)0x02000000u)
#define CSL_CGEM_L1DEDCMD_CCLRTAG_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DEDCMD_CCLRTAG_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DEDCMD_RESETVAL                              ((uint32_t)0x00000003u)

/* L1DDCSTAT */

#define CSL_CGEM_L1DDCSTAT_EN_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L1DDCSTAT_EN_MASK                              ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DDCSTAT_EN_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DDCSTAT_EN_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DDCSTAT_SUSP_SHIFT                           ((uint32_t)1u)
#define CSL_CGEM_L1DDCSTAT_SUSP_MASK                            ((uint32_t)0x00000002u)
#define CSL_CGEM_L1DDCSTAT_SUSP_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDCSTAT_SUSP_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DDCSTAT_BITPOS_SHIFT                         ((uint32_t)2u)
#define CSL_CGEM_L1DDCSTAT_BITPOS_MASK                          ((uint32_t)0x0000001Cu)
#define CSL_CGEM_L1DDCSTAT_BITPOS_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDCSTAT_BITPOS_MAX                           ((uint32_t)0x00000007u)

#define CSL_CGEM_L1DDCSTAT_BYTE_SHIFT                           ((uint32_t)5u)
#define CSL_CGEM_L1DDCSTAT_BYTE_MASK                            ((uint32_t)0x00000060u)
#define CSL_CGEM_L1DDCSTAT_BYTE_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDCSTAT_BYTE_MAX                             ((uint32_t)0x00000003u)

#define CSL_CGEM_L1DDCSTAT_BANK_SHIFT                           ((uint32_t)7u)
#define CSL_CGEM_L1DDCSTAT_BANK_MASK                            ((uint32_t)0x00000380u)
#define CSL_CGEM_L1DDCSTAT_BANK_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDCSTAT_BANK_MAX                             ((uint32_t)0x00000007u)

#define CSL_CGEM_L1DDCSTAT_CERR2_SHIFT                          ((uint32_t)30u)
#define CSL_CGEM_L1DDCSTAT_CERR2_MASK                           ((uint32_t)0x40000000u)
#define CSL_CGEM_L1DDCSTAT_CERR2_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDCSTAT_CERR2_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DDCSTAT_CERR1_SHIFT                          ((uint32_t)31u)
#define CSL_CGEM_L1DDCSTAT_CERR1_MASK                           ((uint32_t)0x80000000u)
#define CSL_CGEM_L1DDCSTAT_CERR1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDCSTAT_CERR1_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DDCSTAT_RESETVAL                             ((uint32_t)0x00000001u)

/* L1DDNCSTAT */

#define CSL_CGEM_L1DDNCSTAT_EN_SHIFT                            ((uint32_t)0u)
#define CSL_CGEM_L1DDNCSTAT_EN_MASK                             ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DDNCSTAT_EN_RESETVAL                         ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DDNCSTAT_EN_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DDNCSTAT_SUSP_SHIFT                          ((uint32_t)1u)
#define CSL_CGEM_L1DDNCSTAT_SUSP_MASK                           ((uint32_t)0x00000002u)
#define CSL_CGEM_L1DDNCSTAT_SUSP_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDNCSTAT_SUSP_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DDNCSTAT_BYTE_SHIFT                          ((uint32_t)5u)
#define CSL_CGEM_L1DDNCSTAT_BYTE_MASK                           ((uint32_t)0x00000060u)
#define CSL_CGEM_L1DDNCSTAT_BYTE_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDNCSTAT_BYTE_MAX                            ((uint32_t)0x00000003u)

#define CSL_CGEM_L1DDNCSTAT_BANK_SHIFT                          ((uint32_t)7u)
#define CSL_CGEM_L1DDNCSTAT_BANK_MASK                           ((uint32_t)0x00000380u)
#define CSL_CGEM_L1DDNCSTAT_BANK_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDNCSTAT_BANK_MAX                            ((uint32_t)0x00000007u)

#define CSL_CGEM_L1DDNCSTAT_NCERR2_SHIFT                        ((uint32_t)30u)
#define CSL_CGEM_L1DDNCSTAT_NCERR2_MASK                         ((uint32_t)0x40000000u)
#define CSL_CGEM_L1DDNCSTAT_NCERR2_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDNCSTAT_NCERR2_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DDNCSTAT_NCERR1_SHIFT                        ((uint32_t)31u)
#define CSL_CGEM_L1DDNCSTAT_NCERR1_MASK                         ((uint32_t)0x80000000u)
#define CSL_CGEM_L1DDNCSTAT_NCERR1_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDNCSTAT_NCERR1_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DDNCSTAT_RESETVAL                            ((uint32_t)0x00000001u)

/* L1DTCSTAT */

#define CSL_CGEM_L1DTCSTAT_EN_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L1DTCSTAT_EN_MASK                              ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DTCSTAT_EN_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DTCSTAT_EN_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DTCSTAT_SUSP_SHIFT                           ((uint32_t)1u)
#define CSL_CGEM_L1DTCSTAT_SUSP_MASK                            ((uint32_t)0x00000002u)
#define CSL_CGEM_L1DTCSTAT_SUSP_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTCSTAT_SUSP_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DTCSTAT_CHANNEL_SHIFT                        ((uint32_t)7u)
#define CSL_CGEM_L1DTCSTAT_CHANNEL_MASK                         ((uint32_t)0x00000080u)
#define CSL_CGEM_L1DTCSTAT_CHANNEL_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTCSTAT_CHANNEL_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DTCSTAT_CERR2_SHIFT                          ((uint32_t)30u)
#define CSL_CGEM_L1DTCSTAT_CERR2_MASK                           ((uint32_t)0x40000000u)
#define CSL_CGEM_L1DTCSTAT_CERR2_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTCSTAT_CERR2_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DTCSTAT_CERR1_SHIFT                          ((uint32_t)31u)
#define CSL_CGEM_L1DTCSTAT_CERR1_MASK                           ((uint32_t)0x80000000u)
#define CSL_CGEM_L1DTCSTAT_CERR1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTCSTAT_CERR1_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DTCSTAT_BITPOS_SHIFT                         ((uint32_t)2u)
#define CSL_CGEM_L1DTCSTAT_BITPOS_MASK                          ((uint32_t)0x0000007Cu)
#define CSL_CGEM_L1DTCSTAT_BITPOS_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTCSTAT_BITPOS_MAX                           ((uint32_t)0x0000001fu)

#define CSL_CGEM_L1DTCSTAT_BANK_SHIFT                           ((uint32_t)8u)
#define CSL_CGEM_L1DTCSTAT_BANK_MASK                            ((uint32_t)0x00000100u)
#define CSL_CGEM_L1DTCSTAT_BANK_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTCSTAT_BANK_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DTCSTAT_RESETVAL                             ((uint32_t)0x00000001u)

/* L1DTNCSTAT */

#define CSL_CGEM_L1DTNCSTAT_EN_SHIFT                            ((uint32_t)0u)
#define CSL_CGEM_L1DTNCSTAT_EN_MASK                             ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DTNCSTAT_EN_RESETVAL                         ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DTNCSTAT_EN_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DTNCSTAT_SUSP_SHIFT                          ((uint32_t)1u)
#define CSL_CGEM_L1DTNCSTAT_SUSP_MASK                           ((uint32_t)0x00000002u)
#define CSL_CGEM_L1DTNCSTAT_SUSP_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTNCSTAT_SUSP_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DTNCSTAT_BANK_SHIFT                          ((uint32_t)7u)
#define CSL_CGEM_L1DTNCSTAT_BANK_MASK                           ((uint32_t)0x00000080u)
#define CSL_CGEM_L1DTNCSTAT_BANK_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTNCSTAT_BANK_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DTNCSTAT_NCERR2_SHIFT                        ((uint32_t)30u)
#define CSL_CGEM_L1DTNCSTAT_NCERR2_MASK                         ((uint32_t)0x40000000u)
#define CSL_CGEM_L1DTNCSTAT_NCERR2_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTNCSTAT_NCERR2_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DTNCSTAT_NCERR1_SHIFT                        ((uint32_t)31u)
#define CSL_CGEM_L1DTNCSTAT_NCERR1_MASK                         ((uint32_t)0x80000000u)
#define CSL_CGEM_L1DTNCSTAT_NCERR1_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTNCSTAT_NCERR1_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DTNCSTAT_RESETVAL                            ((uint32_t)0x00000001u)

/* L1DDEDADDR */

#define CSL_CGEM_L1DDEDADDR_CADDR_SHIFT                         ((uint32_t)0u)
#define CSL_CGEM_L1DDEDADDR_CADDR_MASK                          ((uint32_t)0x000007FFu)
#define CSL_CGEM_L1DDEDADDR_CADDR_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDEDADDR_CADDR_MAX                           ((uint32_t)0x000007ffu)

#define CSL_CGEM_L1DDEDADDR_NCADDR_SHIFT                        ((uint32_t)16u)
#define CSL_CGEM_L1DDEDADDR_NCADDR_MASK                         ((uint32_t)0x07FF0000u)
#define CSL_CGEM_L1DDEDADDR_NCADDR_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DDEDADDR_NCADDR_MAX                          ((uint32_t)0x000007ffu)

#define CSL_CGEM_L1DDEDADDR_RESETVAL                            ((uint32_t)0x00000000u)

/* L1DTEDADDR */

#define CSL_CGEM_L1DTEDADDR_CADDR_SHIFT                         ((uint32_t)0u)
#define CSL_CGEM_L1DTEDADDR_CADDR_MASK                          ((uint32_t)0x000007FFu)
#define CSL_CGEM_L1DTEDADDR_CADDR_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTEDADDR_CADDR_MAX                           ((uint32_t)0x000007ffu)

#define CSL_CGEM_L1DTEDADDR_NCADDR_SHIFT                        ((uint32_t)16u)
#define CSL_CGEM_L1DTEDADDR_NCADDR_MASK                         ((uint32_t)0x07FF0000u)
#define CSL_CGEM_L1DTEDADDR_NCADDR_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTEDADDR_NCADDR_MAX                          ((uint32_t)0x000007ffu)

#define CSL_CGEM_L1DTEDADDR_RESETVAL                            ((uint32_t)0x00000000u)

/* L1DEDCNT */

#define CSL_CGEM_L1DEDCNT_CPECNT_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_L1DEDCNT_CPECNT_MASK                           ((uint32_t)0x0000FFFFu)
#define CSL_CGEM_L1DEDCNT_CPECNT_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DEDCNT_CPECNT_MAX                            ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1DEDCNT_NCPECNT_SHIFT                         ((uint32_t)16u)
#define CSL_CGEM_L1DEDCNT_NCPECNT_MASK                          ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L1DEDCNT_NCPECNT_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DEDCNT_NCPECNT_MAX                           ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1DEDCNT_RESETVAL                              ((uint32_t)0x00000000u)

/* L2TEDCMD */

#define CSL_CGEM_L2TEDCMD_TAGEDCEN_SHIFT                        ((uint32_t)0u)
#define CSL_CGEM_L2TEDCMD_TAGEDCEN_MASK                         ((uint32_t)0x00000001u)
#define CSL_CGEM_L2TEDCMD_TAGEDCEN_RESETVAL                     ((uint32_t)0x00000001u)
#define CSL_CGEM_L2TEDCMD_TAGEDCEN_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TEDCMD_MPPAEDCEN_SHIFT                       ((uint32_t)1u)
#define CSL_CGEM_L2TEDCMD_MPPAEDCEN_MASK                        ((uint32_t)0x00000002u)
#define CSL_CGEM_L2TEDCMD_MPPAEDCEN_RESETVAL                    ((uint32_t)0x00000001u)
#define CSL_CGEM_L2TEDCMD_MPPAEDCEN_MAX                         ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TEDCMD_LRUEDCEN_SHIFT                        ((uint32_t)2u)
#define CSL_CGEM_L2TEDCMD_LRUEDCEN_MASK                         ((uint32_t)0x00000004u)
#define CSL_CGEM_L2TEDCMD_LRUEDCEN_RESETVAL                     ((uint32_t)0x00000001u)
#define CSL_CGEM_L2TEDCMD_LRUEDCEN_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TEDCMD_SNPEDCEN_SHIFT                        ((uint32_t)3u)
#define CSL_CGEM_L2TEDCMD_SNPEDCEN_MASK                         ((uint32_t)0x00000008u)
#define CSL_CGEM_L2TEDCMD_SNPEDCEN_RESETVAL                     ((uint32_t)0x00000001u)
#define CSL_CGEM_L2TEDCMD_SNPEDCEN_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TEDCMD_NCCLRTAG_SHIFT                        ((uint32_t)8u)
#define CSL_CGEM_L2TEDCMD_NCCLRTAG_MASK                         ((uint32_t)0x00000100u)
#define CSL_CGEM_L2TEDCMD_NCCLRTAG_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TEDCMD_NCCLRTAG_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TEDCMD_NCCLRMPPA_SHIFT                       ((uint32_t)9u)
#define CSL_CGEM_L2TEDCMD_NCCLRMPPA_MASK                        ((uint32_t)0x00000200u)
#define CSL_CGEM_L2TEDCMD_NCCLRMPPA_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TEDCMD_NCCLRMPPA_MAX                         ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TEDCMD_NCCLRLRU_SHIFT                        ((uint32_t)10u)
#define CSL_CGEM_L2TEDCMD_NCCLRLRU_MASK                         ((uint32_t)0x00000400u)
#define CSL_CGEM_L2TEDCMD_NCCLRLRU_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TEDCMD_NCCLRLRU_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TEDCMD_NCCLRSNOP_SHIFT                       ((uint32_t)11u)
#define CSL_CGEM_L2TEDCMD_NCCLRSNOP_MASK                        ((uint32_t)0x00000800u)
#define CSL_CGEM_L2TEDCMD_NCCLRSNOP_RESETVAL                    ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TEDCMD_NCCLRSNOP_MAX                         ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TEDCMD_CCLRTAG_SHIFT                         ((uint32_t)16u)
#define CSL_CGEM_L2TEDCMD_CCLRTAG_MASK                          ((uint32_t)0x00010000u)
#define CSL_CGEM_L2TEDCMD_CCLRTAG_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TEDCMD_CCLRTAG_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TEDCMD_CCLRMPPA_SHIFT                        ((uint32_t)17u)
#define CSL_CGEM_L2TEDCMD_CCLRMPPA_MASK                         ((uint32_t)0x00020000u)
#define CSL_CGEM_L2TEDCMD_CCLRMPPA_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TEDCMD_CCLRMPPA_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TEDCMD_CCLRLRU_SHIFT                         ((uint32_t)18u)
#define CSL_CGEM_L2TEDCMD_CCLRLRU_MASK                          ((uint32_t)0x00040000u)
#define CSL_CGEM_L2TEDCMD_CCLRLRU_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TEDCMD_CCLRLRU_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TEDCMD_CCLRSNOP_SHIFT                        ((uint32_t)19u)
#define CSL_CGEM_L2TEDCMD_CCLRSNOP_MASK                         ((uint32_t)0x00080000u)
#define CSL_CGEM_L2TEDCMD_CCLRSNOP_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TEDCMD_CCLRSNOP_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TEDCMD_RESETVAL                              ((uint32_t)0x0000000fu)

/* L2TCSTAT */

#define CSL_CGEM_L2TCSTAT_EN_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_L2TCSTAT_EN_MASK                               ((uint32_t)0x00000001u)
#define CSL_CGEM_L2TCSTAT_EN_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L2TCSTAT_EN_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TCSTAT_BITPOS_SHIFT                          ((uint32_t)2u)
#define CSL_CGEM_L2TCSTAT_BITPOS_MASK                           ((uint32_t)0x0000007Cu)
#define CSL_CGEM_L2TCSTAT_BITPOS_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TCSTAT_BITPOS_MAX                            ((uint32_t)0x0000001fu)

#define CSL_CGEM_L2TCSTAT_CHANNEL_SHIFT                         ((uint32_t)7u)
#define CSL_CGEM_L2TCSTAT_CHANNEL_MASK                          ((uint32_t)0x00000080u)
#define CSL_CGEM_L2TCSTAT_CHANNEL_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TCSTAT_CHANNEL_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TCSTAT_BANK_SHIFT                            ((uint32_t)8u)
#define CSL_CGEM_L2TCSTAT_BANK_MASK                             ((uint32_t)0x00000100u)
#define CSL_CGEM_L2TCSTAT_BANK_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TCSTAT_BANK_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TCSTAT_CERR2_SHIFT                           ((uint32_t)30u)
#define CSL_CGEM_L2TCSTAT_CERR2_MASK                            ((uint32_t)0x40000000u)
#define CSL_CGEM_L2TCSTAT_CERR2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TCSTAT_CERR2_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TCSTAT_CERR1_SHIFT                           ((uint32_t)31u)
#define CSL_CGEM_L2TCSTAT_CERR1_MASK                            ((uint32_t)0x80000000u)
#define CSL_CGEM_L2TCSTAT_CERR1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TCSTAT_CERR1_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TCSTAT_RESETVAL                              ((uint32_t)0x00000001u)

/* L2TNCSTAT */

#define CSL_CGEM_L2TNCSTAT_EN_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L2TNCSTAT_EN_MASK                              ((uint32_t)0x00000001u)
#define CSL_CGEM_L2TNCSTAT_EN_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L2TNCSTAT_EN_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TNCSTAT_BANK_SHIFT                           ((uint32_t)8u)
#define CSL_CGEM_L2TNCSTAT_BANK_MASK                            ((uint32_t)0x00000100u)
#define CSL_CGEM_L2TNCSTAT_BANK_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TNCSTAT_BANK_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TNCSTAT_NCERR2_SHIFT                         ((uint32_t)30u)
#define CSL_CGEM_L2TNCSTAT_NCERR2_MASK                          ((uint32_t)0x40000000u)
#define CSL_CGEM_L2TNCSTAT_NCERR2_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TNCSTAT_NCERR2_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TNCSTAT_NCERR1_SHIFT                         ((uint32_t)31u)
#define CSL_CGEM_L2TNCSTAT_NCERR1_MASK                          ((uint32_t)0x80000000u)
#define CSL_CGEM_L2TNCSTAT_NCERR1_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TNCSTAT_NCERR1_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L2TNCSTAT_RESETVAL                             ((uint32_t)0x00000001u)

/* L2TEDADDR */

#define CSL_CGEM_L2TEDADDR_CADDR_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_L2TEDADDR_CADDR_MASK                           ((uint32_t)0x000007FFu)
#define CSL_CGEM_L2TEDADDR_CADDR_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TEDADDR_CADDR_MAX                            ((uint32_t)0x000007ffu)

#define CSL_CGEM_L2TEDADDR_NCADDR_SHIFT                         ((uint32_t)16u)
#define CSL_CGEM_L2TEDADDR_NCADDR_MASK                          ((uint32_t)0x07FF0000u)
#define CSL_CGEM_L2TEDADDR_NCADDR_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TEDADDR_NCADDR_MAX                           ((uint32_t)0x000007ffu)

#define CSL_CGEM_L2TEDADDR_RESETVAL                             ((uint32_t)0x00000000u)

/* L2MCSTAT */

#define CSL_CGEM_L2MCSTAT_RESETVAL                              ((uint32_t)0x00000000u)

/* L2MNCSTAT */

#define CSL_CGEM_L2MNCSTAT_EN_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L2MNCSTAT_EN_MASK                              ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MNCSTAT_EN_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MNCSTAT_EN_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MNCSTAT_NCERR2_SHIFT                         ((uint32_t)30u)
#define CSL_CGEM_L2MNCSTAT_NCERR2_MASK                          ((uint32_t)0x40000000u)
#define CSL_CGEM_L2MNCSTAT_NCERR2_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MNCSTAT_NCERR2_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MNCSTAT_NCERR1_SHIFT                         ((uint32_t)31u)
#define CSL_CGEM_L2MNCSTAT_NCERR1_MASK                          ((uint32_t)0x80000000u)
#define CSL_CGEM_L2MNCSTAT_NCERR1_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MNCSTAT_NCERR1_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MNCSTAT_RESETVAL                             ((uint32_t)0x00000001u)

/* L2MEDADDR */

#define CSL_CGEM_L2MEDADDR_NCADDR_SHIFT                         ((uint32_t)16u)
#define CSL_CGEM_L2MEDADDR_NCADDR_MASK                          ((uint32_t)0x07FF0000u)
#define CSL_CGEM_L2MEDADDR_NCADDR_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MEDADDR_NCADDR_MAX                           ((uint32_t)0x000007ffu)

#define CSL_CGEM_L2MEDADDR_RESETVAL                             ((uint32_t)0x00000000u)

/* L2SCSTAT */

#define CSL_CGEM_L2SCSTAT_EN_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_L2SCSTAT_EN_MASK                               ((uint32_t)0x00000001u)
#define CSL_CGEM_L2SCSTAT_EN_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L2SCSTAT_EN_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L2SCSTAT_BITPOS_SHIFT                          ((uint32_t)2u)
#define CSL_CGEM_L2SCSTAT_BITPOS_MASK                           ((uint32_t)0x0000007Cu)
#define CSL_CGEM_L2SCSTAT_BITPOS_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L2SCSTAT_BITPOS_MAX                            ((uint32_t)0x0000001fu)

#define CSL_CGEM_L2SCSTAT_CERR2_SHIFT                           ((uint32_t)30u)
#define CSL_CGEM_L2SCSTAT_CERR2_MASK                            ((uint32_t)0x40000000u)
#define CSL_CGEM_L2SCSTAT_CERR2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2SCSTAT_CERR2_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2SCSTAT_CERR1_SHIFT                           ((uint32_t)31u)
#define CSL_CGEM_L2SCSTAT_CERR1_MASK                            ((uint32_t)0x80000000u)
#define CSL_CGEM_L2SCSTAT_CERR1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2SCSTAT_CERR1_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2SCSTAT_RESETVAL                              ((uint32_t)0x00000001u)

/* L2SNCSTAT */

#define CSL_CGEM_L2SNCSTAT_EN_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L2SNCSTAT_EN_MASK                              ((uint32_t)0x00000001u)
#define CSL_CGEM_L2SNCSTAT_EN_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L2SNCSTAT_EN_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L2SNCSTAT_NCERR2_SHIFT                         ((uint32_t)30u)
#define CSL_CGEM_L2SNCSTAT_NCERR2_MASK                          ((uint32_t)0x40000000u)
#define CSL_CGEM_L2SNCSTAT_NCERR2_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2SNCSTAT_NCERR2_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L2SNCSTAT_NCERR1_SHIFT                         ((uint32_t)31u)
#define CSL_CGEM_L2SNCSTAT_NCERR1_MASK                          ((uint32_t)0x80000000u)
#define CSL_CGEM_L2SNCSTAT_NCERR1_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2SNCSTAT_NCERR1_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L2SNCSTAT_RESETVAL                             ((uint32_t)0x00000001u)

/* L2SEDADDR */

#define CSL_CGEM_L2SEDADDR_CADDR_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_L2SEDADDR_CADDR_MASK                           ((uint32_t)0x000003FFu)
#define CSL_CGEM_L2SEDADDR_CADDR_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L2SEDADDR_CADDR_MAX                            ((uint32_t)0x000003ffu)

#define CSL_CGEM_L2SEDADDR_NCADDR_SHIFT                         ((uint32_t)16u)
#define CSL_CGEM_L2SEDADDR_NCADDR_MASK                          ((uint32_t)0x03FF0000u)
#define CSL_CGEM_L2SEDADDR_NCADDR_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2SEDADDR_NCADDR_MAX                           ((uint32_t)0x000003ffu)

#define CSL_CGEM_L2SEDADDR_RESETVAL                             ((uint32_t)0x00000000u)

/* L2LCSTAT */

#define CSL_CGEM_L2LCSTAT_EN_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_L2LCSTAT_EN_MASK                               ((uint32_t)0x00000001u)
#define CSL_CGEM_L2LCSTAT_EN_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L2LCSTAT_EN_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L2LCSTAT_BITPOS_SHIFT                          ((uint32_t)2u)
#define CSL_CGEM_L2LCSTAT_BITPOS_MASK                           ((uint32_t)0x0000007Cu)
#define CSL_CGEM_L2LCSTAT_BITPOS_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L2LCSTAT_BITPOS_MAX                            ((uint32_t)0x0000001fu)

#define CSL_CGEM_L2LCSTAT_CERR2_SHIFT                           ((uint32_t)30u)
#define CSL_CGEM_L2LCSTAT_CERR2_MASK                            ((uint32_t)0x40000000u)
#define CSL_CGEM_L2LCSTAT_CERR2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2LCSTAT_CERR2_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2LCSTAT_CERR1_SHIFT                           ((uint32_t)31u)
#define CSL_CGEM_L2LCSTAT_CERR1_MASK                            ((uint32_t)0x80000000u)
#define CSL_CGEM_L2LCSTAT_CERR1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2LCSTAT_CERR1_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2LCSTAT_RESETVAL                              ((uint32_t)0x00000001u)

/* L2LNCSTAT */

#define CSL_CGEM_L2LNCSTAT_EN_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L2LNCSTAT_EN_MASK                              ((uint32_t)0x00000001u)
#define CSL_CGEM_L2LNCSTAT_EN_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L2LNCSTAT_EN_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L2LNCSTAT_NCERR2_SHIFT                         ((uint32_t)30u)
#define CSL_CGEM_L2LNCSTAT_NCERR2_MASK                          ((uint32_t)0x40000000u)
#define CSL_CGEM_L2LNCSTAT_NCERR2_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2LNCSTAT_NCERR2_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L2LNCSTAT_NCERR1_SHIFT                         ((uint32_t)31u)
#define CSL_CGEM_L2LNCSTAT_NCERR1_MASK                          ((uint32_t)0x80000000u)
#define CSL_CGEM_L2LNCSTAT_NCERR1_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2LNCSTAT_NCERR1_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L2LNCSTAT_RESETVAL                             ((uint32_t)0x00000001u)

/* L2LEDADDR */

#define CSL_CGEM_L2LEDADDR_CADDR_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_L2LEDADDR_CADDR_MASK                           ((uint32_t)0x000003FFu)
#define CSL_CGEM_L2LEDADDR_CADDR_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L2LEDADDR_CADDR_MAX                            ((uint32_t)0x000003ffu)

#define CSL_CGEM_L2LEDADDR_NCADDR_SHIFT                         ((uint32_t)16u)
#define CSL_CGEM_L2LEDADDR_NCADDR_MASK                          ((uint32_t)0x03FF0000u)
#define CSL_CGEM_L2LEDADDR_NCADDR_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2LEDADDR_NCADDR_MAX                           ((uint32_t)0x000003ffu)

#define CSL_CGEM_L2LEDADDR_RESETVAL                             ((uint32_t)0x00000000u)

/* L2TEDCNT */

#define CSL_CGEM_L2TEDCNT_CPECNT_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_L2TEDCNT_CPECNT_MASK                           ((uint32_t)0x0000FFFFu)
#define CSL_CGEM_L2TEDCNT_CPECNT_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TEDCNT_CPECNT_MAX                            ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L2TEDCNT_NCPECNT_SHIFT                         ((uint32_t)16u)
#define CSL_CGEM_L2TEDCNT_NCPECNT_MASK                          ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L2TEDCNT_NCPECNT_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L2TEDCNT_NCPECNT_MAX                           ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L2TEDCNT_RESETVAL                              ((uint32_t)0x00000000u)

/* L1PTEDCMD */

#define CSL_CGEM_L1PTEDCMD_EN_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L1PTEDCMD_EN_MASK                              ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PTEDCMD_EN_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PTEDCMD_EN_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PTEDCMD_NCCLR_SHIFT                          ((uint32_t)5u)
#define CSL_CGEM_L1PTEDCMD_NCCLR_MASK                           ((uint32_t)0x00000020u)
#define CSL_CGEM_L1PTEDCMD_NCCLR_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PTEDCMD_NCCLR_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PTEDCMD_RESETVAL                             ((uint32_t)0x00000001u)

/* L1PTEDSTAT */

#define CSL_CGEM_L1PTEDSTAT_EN_SHIFT                            ((uint32_t)0u)
#define CSL_CGEM_L1PTEDSTAT_EN_MASK                             ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PTEDSTAT_EN_RESETVAL                         ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PTEDSTAT_EN_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PTEDSTAT_NCERR1_SHIFT                        ((uint32_t)30u)
#define CSL_CGEM_L1PTEDSTAT_NCERR1_MASK                         ((uint32_t)0x40000000u)
#define CSL_CGEM_L1PTEDSTAT_NCERR1_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PTEDSTAT_NCERR1_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PTEDSTAT_NCERR2_SHIFT                        ((uint32_t)31u)
#define CSL_CGEM_L1PTEDSTAT_NCERR2_MASK                         ((uint32_t)0x80000000u)
#define CSL_CGEM_L1PTEDSTAT_NCERR2_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PTEDSTAT_NCERR2_MAX                          ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PTEDSTAT_RESETVAL                            ((uint32_t)0x00000001u)

/* L1PTEDADDR */

#define CSL_CGEM_L1PTEDADDR_NCADDR_SHIFT                        ((uint32_t)16u)
#define CSL_CGEM_L1PTEDADDR_NCADDR_MASK                         ((uint32_t)0x07FF0000u)
#define CSL_CGEM_L1PTEDADDR_NCADDR_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PTEDADDR_NCADDR_MAX                          ((uint32_t)0x000007ffu)

#define CSL_CGEM_L1PTEDADDR_RESETVAL                            ((uint32_t)0x00000000u)

/* L1DTEDCNT */

#define CSL_CGEM_L1DTEDCNT_NCPECNT_SHIFT                        ((uint32_t)16u)
#define CSL_CGEM_L1DTEDCNT_NCPECNT_MASK                         ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L1DTEDCNT_NCPECNT_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DTEDCNT_NCPECNT_MAX                          ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1DTEDCNT_RESETVAL                             ((uint32_t)0x00000000u)

/* L2CFG */

#define CSL_CGEM_L2CFG_RESV_1_SHIFT                             ((uint32_t)28u)
#define CSL_CGEM_L2CFG_RESV_1_MASK                              ((uint32_t)0xF0000000u)
#define CSL_CGEM_L2CFG_RESV_1_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2CFG_RESV_1_MAX                               ((uint32_t)0x0000000fu)

#define CSL_CGEM_L2CFG_NUM_MM_SHIFT                             ((uint32_t)24u)
#define CSL_CGEM_L2CFG_NUM_MM_MASK                              ((uint32_t)0x0F000000u)
#define CSL_CGEM_L2CFG_NUM_MM_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L2CFG_NUM_MM_MAX                               ((uint32_t)0x0000000fu)

#define CSL_CGEM_L2CFG_RESV_2_SHIFT                             ((uint32_t)20u)
#define CSL_CGEM_L2CFG_RESV_2_MASK                              ((uint32_t)0x00F00000u)
#define CSL_CGEM_L2CFG_RESV_2_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2CFG_RESV_2_MAX                               ((uint32_t)0x0000000fu)

#define CSL_CGEM_L2CFG_MMID_SHIFT                               ((uint32_t)16u)
#define CSL_CGEM_L2CFG_MMID_MASK                                ((uint32_t)0x000F0000u)
#define CSL_CGEM_L2CFG_MMID_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L2CFG_MMID_MAX                                 ((uint32_t)0x0000000fu)

#define CSL_CGEM_L2CFG_RESV_3_SHIFT                             ((uint32_t)10u)
#define CSL_CGEM_L2CFG_RESV_3_MASK                              ((uint32_t)0x0000FC00u)
#define CSL_CGEM_L2CFG_RESV_3_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2CFG_RESV_3_MAX                               ((uint32_t)0x0000003fu)

#define CSL_CGEM_L2CFG_IP_SHIFT                                 ((uint32_t)9u)
#define CSL_CGEM_L2CFG_IP_MASK                                  ((uint32_t)0x00000200u)
#define CSL_CGEM_L2CFG_IP_RESETVAL                              ((uint32_t)0x00000000u)
#define CSL_CGEM_L2CFG_IP_MAX                                   ((uint32_t)0x00000001u)

#define CSL_CGEM_L2CFG_ID_SHIFT                                 ((uint32_t)8u)
#define CSL_CGEM_L2CFG_ID_MASK                                  ((uint32_t)0x00000100u)
#define CSL_CGEM_L2CFG_ID_RESETVAL                              ((uint32_t)0x00000000u)
#define CSL_CGEM_L2CFG_ID_MAX                                   ((uint32_t)0x00000001u)

#define CSL_CGEM_L2CFG_RESV_4_SHIFT                             ((uint32_t)5u)
#define CSL_CGEM_L2CFG_RESV_4_MASK                              ((uint32_t)0x000000E0u)
#define CSL_CGEM_L2CFG_RESV_4_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2CFG_RESV_4_MAX                               ((uint32_t)0x00000007u)

#define CSL_CGEM_L2CFG_L2CC_SHIFT                               ((uint32_t)3u)
#define CSL_CGEM_L2CFG_L2CC_MASK                                ((uint32_t)0x00000018u)
#define CSL_CGEM_L2CFG_L2CC_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L2CFG_L2CC_MAX                                 ((uint32_t)0x00000003u)

#define CSL_CGEM_L2CFG_L2MODE_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L2CFG_L2MODE_MASK                              ((uint32_t)0x00000007u)
#define CSL_CGEM_L2CFG_L2MODE_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2CFG_L2MODE_MAX                               ((uint32_t)0x00000007u)

#define CSL_CGEM_L2CFG_RESETVAL                                 ((uint32_t)0x01000000u)

/* L1PCFG */

#define CSL_CGEM_L1PCFG_RESV_1_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_L1PCFG_RESV_1_MASK                             ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_L1PCFG_RESV_1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PCFG_RESV_1_MAX                              ((uint32_t)0x1fffffffu)

#define CSL_CGEM_L1PCFG_L1PMODE_SHIFT                           ((uint32_t)0u)
#define CSL_CGEM_L1PCFG_L1PMODE_MASK                            ((uint32_t)0x00000007u)
#define CSL_CGEM_L1PCFG_L1PMODE_RESETVAL                        ((uint32_t)0x00000007u)
#define CSL_CGEM_L1PCFG_L1PMODE_MAX                             ((uint32_t)0x00000007u)

#define CSL_CGEM_L1PCFG_RESETVAL                                ((uint32_t)0x00000007u)

/* L1PCC */

#define CSL_CGEM_L1PCC_RESV_1_SHIFT                             ((uint32_t)19u)
#define CSL_CGEM_L1PCC_RESV_1_MASK                              ((uint32_t)0xFFF80000u)
#define CSL_CGEM_L1PCC_RESV_1_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PCC_RESV_1_MAX                               ((uint32_t)0x00001fffu)

#define CSL_CGEM_L1PCC_POPER_SHIFT                              ((uint32_t)16u)
#define CSL_CGEM_L1PCC_POPER_MASK                               ((uint32_t)0x00070000u)
#define CSL_CGEM_L1PCC_POPER_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PCC_POPER_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_L1PCC_RESV_2_SHIFT                             ((uint32_t)3u)
#define CSL_CGEM_L1PCC_RESV_2_MASK                              ((uint32_t)0x0000FFF8u)
#define CSL_CGEM_L1PCC_RESV_2_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PCC_RESV_2_MAX                               ((uint32_t)0x00001fffu)

#define CSL_CGEM_L1PCC_OPER_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_L1PCC_OPER_MASK                                ((uint32_t)0x00000007u)
#define CSL_CGEM_L1PCC_OPER_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PCC_OPER_MAX                                 ((uint32_t)0x00000007u)

#define CSL_CGEM_L1PCC_RESETVAL                                 ((uint32_t)0x00000000u)

/* L1DCFG */

#define CSL_CGEM_L1DCFG_RESV_1_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_L1DCFG_RESV_1_MASK                             ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_L1DCFG_RESV_1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DCFG_RESV_1_MAX                              ((uint32_t)0x1fffffffu)

#define CSL_CGEM_L1DCFG_L1DMODE_SHIFT                           ((uint32_t)0u)
#define CSL_CGEM_L1DCFG_L1DMODE_MASK                            ((uint32_t)0x00000007u)
#define CSL_CGEM_L1DCFG_L1DMODE_RESETVAL                        ((uint32_t)0x00000007u)
#define CSL_CGEM_L1DCFG_L1DMODE_MAX                             ((uint32_t)0x00000007u)

#define CSL_CGEM_L1DCFG_RESETVAL                                ((uint32_t)0x00000007u)

/* L1DCC */

#define CSL_CGEM_L1DCC_RESV_1_SHIFT                             ((uint32_t)19u)
#define CSL_CGEM_L1DCC_RESV_1_MASK                              ((uint32_t)0xFFF80000u)
#define CSL_CGEM_L1DCC_RESV_1_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DCC_RESV_1_MAX                               ((uint32_t)0x00001fffu)

#define CSL_CGEM_L1DCC_POPER_SHIFT                              ((uint32_t)16u)
#define CSL_CGEM_L1DCC_POPER_MASK                               ((uint32_t)0x00070000u)
#define CSL_CGEM_L1DCC_POPER_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DCC_POPER_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_L1DCC_RESV_2_SHIFT                             ((uint32_t)3u)
#define CSL_CGEM_L1DCC_RESV_2_MASK                              ((uint32_t)0x0000FFF8u)
#define CSL_CGEM_L1DCC_RESV_2_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DCC_RESV_2_MAX                               ((uint32_t)0x00001fffu)

#define CSL_CGEM_L1DCC_OPER_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_L1DCC_OPER_MASK                                ((uint32_t)0x00000007u)
#define CSL_CGEM_L1DCC_OPER_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DCC_OPER_MAX                                 ((uint32_t)0x00000007u)

#define CSL_CGEM_L1DCC_RESETVAL                                 ((uint32_t)0x00000000u)

/* CPUARBU */

#define CSL_CGEM_CPUARBU_RESV_1_SHIFT                           ((uint32_t)19u)
#define CSL_CGEM_CPUARBU_RESV_1_MASK                            ((uint32_t)0xFFF80000u)
#define CSL_CGEM_CPUARBU_RESV_1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_CPUARBU_RESV_1_MAX                             ((uint32_t)0x00001fffu)

#define CSL_CGEM_CPUARBU_PRI_SHIFT                              ((uint32_t)16u)
#define CSL_CGEM_CPUARBU_PRI_MASK                               ((uint32_t)0x00070000u)
#define CSL_CGEM_CPUARBU_PRI_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_CPUARBU_PRI_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_CPUARBU_RESV_2_SHIFT                           ((uint32_t)6u)
#define CSL_CGEM_CPUARBU_RESV_2_MASK                            ((uint32_t)0x0000FFC0u)
#define CSL_CGEM_CPUARBU_RESV_2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_CPUARBU_RESV_2_MAX                             ((uint32_t)0x000003ffu)

#define CSL_CGEM_CPUARBU_MAXWAIT_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_CPUARBU_MAXWAIT_MASK                           ((uint32_t)0x0000003Fu)
#define CSL_CGEM_CPUARBU_MAXWAIT_RESETVAL                       ((uint32_t)0x00000010u)
#define CSL_CGEM_CPUARBU_MAXWAIT_MAX                            ((uint32_t)0x0000003fu)

#define CSL_CGEM_CPUARBU_RESETVAL                               ((uint32_t)0x00010010u)

/* IDMAARBU */

#define CSL_CGEM_IDMAARBU_RESV_1_SHIFT                          ((uint32_t)6u)
#define CSL_CGEM_IDMAARBU_RESV_1_MASK                           ((uint32_t)0xFFFFFFC0u)
#define CSL_CGEM_IDMAARBU_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMAARBU_RESV_1_MAX                            ((uint32_t)0x03ffffffu)

#define CSL_CGEM_IDMAARBU_MAXWAIT_SHIFT                         ((uint32_t)0u)
#define CSL_CGEM_IDMAARBU_MAXWAIT_MASK                          ((uint32_t)0x0000003Fu)
#define CSL_CGEM_IDMAARBU_MAXWAIT_RESETVAL                      ((uint32_t)0x00000010u)
#define CSL_CGEM_IDMAARBU_MAXWAIT_MAX                           ((uint32_t)0x0000003fu)

#define CSL_CGEM_IDMAARBU_RESETVAL                              ((uint32_t)0x00000010u)

/* SDMAARBU */

#define CSL_CGEM_SDMAARBU_RESV_1_SHIFT                          ((uint32_t)6u)
#define CSL_CGEM_SDMAARBU_RESV_1_MASK                           ((uint32_t)0xFFFFFFC0u)
#define CSL_CGEM_SDMAARBU_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_SDMAARBU_RESV_1_MAX                            ((uint32_t)0x03ffffffu)

#define CSL_CGEM_SDMAARBU_MAXWAIT_SHIFT                         ((uint32_t)0u)
#define CSL_CGEM_SDMAARBU_MAXWAIT_MASK                          ((uint32_t)0x0000003Fu)
#define CSL_CGEM_SDMAARBU_MAXWAIT_RESETVAL                      ((uint32_t)0x00000001u)
#define CSL_CGEM_SDMAARBU_MAXWAIT_MAX                           ((uint32_t)0x0000003fu)

#define CSL_CGEM_SDMAARBU_RESETVAL                              ((uint32_t)0x00000001u)

/* UCARBU */

#define CSL_CGEM_UCARBU_RESV_1_SHIFT                            ((uint32_t)6u)
#define CSL_CGEM_UCARBU_RESV_1_MASK                             ((uint32_t)0xFFFFFFC0u)
#define CSL_CGEM_UCARBU_RESV_1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_UCARBU_RESV_1_MAX                              ((uint32_t)0x03ffffffu)

#define CSL_CGEM_UCARBU_MAXWAIT_SHIFT                           ((uint32_t)0u)
#define CSL_CGEM_UCARBU_MAXWAIT_MASK                            ((uint32_t)0x0000003Fu)
#define CSL_CGEM_UCARBU_MAXWAIT_RESETVAL                        ((uint32_t)0x00000020u)
#define CSL_CGEM_UCARBU_MAXWAIT_MAX                             ((uint32_t)0x0000003fu)

#define CSL_CGEM_UCARBU_RESETVAL                                ((uint32_t)0x00000020u)

/* MDMAARBU */

#define CSL_CGEM_MDMAARBU_RESV_1_SHIFT                          ((uint32_t)27u)
#define CSL_CGEM_MDMAARBU_RESV_1_MASK                           ((uint32_t)0xF8000000u)
#define CSL_CGEM_MDMAARBU_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_MDMAARBU_RESV_1_MAX                            ((uint32_t)0x0000001fu)

#define CSL_CGEM_MDMAARBU_UPRI_SHIFT                            ((uint32_t)24u)
#define CSL_CGEM_MDMAARBU_UPRI_MASK                             ((uint32_t)0x07000000u)
#define CSL_CGEM_MDMAARBU_UPRI_RESETVAL                         ((uint32_t)0x00000006u)
#define CSL_CGEM_MDMAARBU_UPRI_MAX                              ((uint32_t)0x00000007u)

#define CSL_CGEM_MDMAARBU_RESV_2_SHIFT                          ((uint32_t)19u)
#define CSL_CGEM_MDMAARBU_RESV_2_MASK                           ((uint32_t)0x00F80000u)
#define CSL_CGEM_MDMAARBU_RESV_2_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_MDMAARBU_RESV_2_MAX                            ((uint32_t)0x0000001fu)

#define CSL_CGEM_MDMAARBU_PRI_SHIFT                             ((uint32_t)16u)
#define CSL_CGEM_MDMAARBU_PRI_MASK                              ((uint32_t)0x00070000u)
#define CSL_CGEM_MDMAARBU_PRI_RESETVAL                          ((uint32_t)0x00000007u)
#define CSL_CGEM_MDMAARBU_PRI_MAX                               ((uint32_t)0x00000007u)

#define CSL_CGEM_MDMAARBU_RESV_3_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_MDMAARBU_RESV_3_MASK                           ((uint32_t)0x0000FFFFu)
#define CSL_CGEM_MDMAARBU_RESV_3_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_MDMAARBU_RESV_3_MAX                            ((uint32_t)0x0000ffffu)

#define CSL_CGEM_MDMAARBU_RESETVAL                              ((uint32_t)0x06070000u)

/* CPUARBD */

#define CSL_CGEM_CPUARBD_RESV_1_SHIFT                           ((uint32_t)19u)
#define CSL_CGEM_CPUARBD_RESV_1_MASK                            ((uint32_t)0xFFF80000u)
#define CSL_CGEM_CPUARBD_RESV_1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_CPUARBD_RESV_1_MAX                             ((uint32_t)0x00001fffu)

#define CSL_CGEM_CPUARBD_PRI_SHIFT                              ((uint32_t)16u)
#define CSL_CGEM_CPUARBD_PRI_MASK                               ((uint32_t)0x00070000u)
#define CSL_CGEM_CPUARBD_PRI_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_CPUARBD_PRI_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_CPUARBD_RESV_2_SHIFT                           ((uint32_t)6u)
#define CSL_CGEM_CPUARBD_RESV_2_MASK                            ((uint32_t)0x0000FFC0u)
#define CSL_CGEM_CPUARBD_RESV_2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_CPUARBD_RESV_2_MAX                             ((uint32_t)0x000003ffu)

#define CSL_CGEM_CPUARBD_MAXWAIT_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_CPUARBD_MAXWAIT_MASK                           ((uint32_t)0x0000003Fu)
#define CSL_CGEM_CPUARBD_MAXWAIT_RESETVAL                       ((uint32_t)0x00000010u)
#define CSL_CGEM_CPUARBD_MAXWAIT_MAX                            ((uint32_t)0x0000003fu)

#define CSL_CGEM_CPUARBD_RESETVAL                               ((uint32_t)0x00010010u)

/* IDMAARBD */

#define CSL_CGEM_IDMAARBD_RESV_1_SHIFT                          ((uint32_t)6u)
#define CSL_CGEM_IDMAARBD_RESV_1_MASK                           ((uint32_t)0xFFFFFFC0u)
#define CSL_CGEM_IDMAARBD_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_IDMAARBD_RESV_1_MAX                            ((uint32_t)0x03ffffffu)

#define CSL_CGEM_IDMAARBD_MAXWAIT_SHIFT                         ((uint32_t)0u)
#define CSL_CGEM_IDMAARBD_MAXWAIT_MASK                          ((uint32_t)0x0000003Fu)
#define CSL_CGEM_IDMAARBD_MAXWAIT_RESETVAL                      ((uint32_t)0x00000010u)
#define CSL_CGEM_IDMAARBD_MAXWAIT_MAX                           ((uint32_t)0x0000003fu)

#define CSL_CGEM_IDMAARBD_RESETVAL                              ((uint32_t)0x00000010u)

/* SDMAARBD */

#define CSL_CGEM_SDMAARBD_RESV_1_SHIFT                          ((uint32_t)6u)
#define CSL_CGEM_SDMAARBD_RESV_1_MASK                           ((uint32_t)0xFFFFFFC0u)
#define CSL_CGEM_SDMAARBD_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_SDMAARBD_RESV_1_MAX                            ((uint32_t)0x03ffffffu)

#define CSL_CGEM_SDMAARBD_MAXWAIT_SHIFT                         ((uint32_t)0u)
#define CSL_CGEM_SDMAARBD_MAXWAIT_MASK                          ((uint32_t)0x0000003Fu)
#define CSL_CGEM_SDMAARBD_MAXWAIT_RESETVAL                      ((uint32_t)0x00000001u)
#define CSL_CGEM_SDMAARBD_MAXWAIT_MAX                           ((uint32_t)0x0000003fu)

#define CSL_CGEM_SDMAARBD_RESETVAL                              ((uint32_t)0x00000001u)

/* UCARBD */

#define CSL_CGEM_UCARBD_RESV_1_SHIFT                            ((uint32_t)6u)
#define CSL_CGEM_UCARBD_RESV_1_MASK                             ((uint32_t)0xFFFFFFC0u)
#define CSL_CGEM_UCARBD_RESV_1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_UCARBD_RESV_1_MAX                              ((uint32_t)0x03ffffffu)

#define CSL_CGEM_UCARBD_MAXWAIT_SHIFT                           ((uint32_t)0u)
#define CSL_CGEM_UCARBD_MAXWAIT_MASK                            ((uint32_t)0x0000003Fu)
#define CSL_CGEM_UCARBD_MAXWAIT_RESETVAL                        ((uint32_t)0x00000020u)
#define CSL_CGEM_UCARBD_MAXWAIT_MAX                             ((uint32_t)0x0000003fu)

#define CSL_CGEM_UCARBD_RESETVAL                                ((uint32_t)0x00000020u)

/* L2WBAR */

#define CSL_CGEM_L2WBAR_ADDR_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_L2WBAR_ADDR_MASK                               ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L2WBAR_ADDR_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L2WBAR_ADDR_MAX                                ((uint32_t)0xffffffffu)

#define CSL_CGEM_L2WBAR_RESETVAL                                ((uint32_t)0x00000000u)

/* L2WWC */

#define CSL_CGEM_L2WWC_RESV_1_SHIFT                             ((uint32_t)16u)
#define CSL_CGEM_L2WWC_RESV_1_MASK                              ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L2WWC_RESV_1_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2WWC_RESV_1_MAX                               ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L2WWC_WC_SHIFT                                 ((uint32_t)0u)
#define CSL_CGEM_L2WWC_WC_MASK                                  ((uint32_t)0x0000FFFFu)
#define CSL_CGEM_L2WWC_WC_RESETVAL                              ((uint32_t)0x00000000u)
#define CSL_CGEM_L2WWC_WC_MAX                                   ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L2WWC_RESETVAL                                 ((uint32_t)0x00000000u)

/* L2WIBAR */

#define CSL_CGEM_L2WIBAR_ADDR_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L2WIBAR_ADDR_MASK                              ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L2WIBAR_ADDR_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2WIBAR_ADDR_MAX                               ((uint32_t)0xffffffffu)

#define CSL_CGEM_L2WIBAR_RESETVAL                               ((uint32_t)0x00000000u)

/* L2WIWC */

#define CSL_CGEM_L2WIWC_RESV_1_SHIFT                            ((uint32_t)16u)
#define CSL_CGEM_L2WIWC_RESV_1_MASK                             ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L2WIWC_RESV_1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2WIWC_RESV_1_MAX                              ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L2WIWC_WC_SHIFT                                ((uint32_t)0u)
#define CSL_CGEM_L2WIWC_WC_MASK                                 ((uint32_t)0x0000FFFFu)
#define CSL_CGEM_L2WIWC_WC_RESETVAL                             ((uint32_t)0x00000000u)
#define CSL_CGEM_L2WIWC_WC_MAX                                  ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L2WIWC_RESETVAL                                ((uint32_t)0x00000000u)

/* L2IBAR */

#define CSL_CGEM_L2IBAR_ADDR_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_L2IBAR_ADDR_MASK                               ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L2IBAR_ADDR_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L2IBAR_ADDR_MAX                                ((uint32_t)0xffffffffu)

#define CSL_CGEM_L2IBAR_RESETVAL                                ((uint32_t)0x00000000u)

/* L2IWC */

#define CSL_CGEM_L2IWC_RESV_1_SHIFT                             ((uint32_t)16u)
#define CSL_CGEM_L2IWC_RESV_1_MASK                              ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L2IWC_RESV_1_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2IWC_RESV_1_MAX                               ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L2IWC_WC_SHIFT                                 ((uint32_t)0u)
#define CSL_CGEM_L2IWC_WC_MASK                                  ((uint32_t)0x0000FFFFu)
#define CSL_CGEM_L2IWC_WC_RESETVAL                              ((uint32_t)0x00000000u)
#define CSL_CGEM_L2IWC_WC_MAX                                   ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L2IWC_RESETVAL                                 ((uint32_t)0x00000000u)

/* L1PIBAR */

#define CSL_CGEM_L1PIBAR_ADDR_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L1PIBAR_ADDR_MASK                              ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L1PIBAR_ADDR_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PIBAR_ADDR_MAX                               ((uint32_t)0xffffffffu)

#define CSL_CGEM_L1PIBAR_RESETVAL                               ((uint32_t)0x00000000u)

/* L1PIWC */

#define CSL_CGEM_L1PIWC_RESV_1_SHIFT                            ((uint32_t)16u)
#define CSL_CGEM_L1PIWC_RESV_1_MASK                             ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L1PIWC_RESV_1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PIWC_RESV_1_MAX                              ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1PIWC_WC_SHIFT                                ((uint32_t)0u)
#define CSL_CGEM_L1PIWC_WC_MASK                                 ((uint32_t)0x0000FFFFu)
#define CSL_CGEM_L1PIWC_WC_RESETVAL                             ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PIWC_WC_MAX                                  ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1PIWC_RESETVAL                                ((uint32_t)0x00000000u)

/* L1DWIBAR */

#define CSL_CGEM_L1DWIBAR_ADDR_SHIFT                            ((uint32_t)0u)
#define CSL_CGEM_L1DWIBAR_ADDR_MASK                             ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L1DWIBAR_ADDR_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DWIBAR_ADDR_MAX                              ((uint32_t)0xffffffffu)

#define CSL_CGEM_L1DWIBAR_RESETVAL                              ((uint32_t)0x00000000u)

/* L1DWIWC */

#define CSL_CGEM_L1DWIWC_RESV_1_SHIFT                           ((uint32_t)16u)
#define CSL_CGEM_L1DWIWC_RESV_1_MASK                            ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L1DWIWC_RESV_1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DWIWC_RESV_1_MAX                             ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1DWIWC_WC_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_L1DWIWC_WC_MASK                                ((uint32_t)0x0000FFFFu)
#define CSL_CGEM_L1DWIWC_WC_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DWIWC_WC_MAX                                 ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1DWIWC_RESETVAL                               ((uint32_t)0x00000000u)

/* L1DWBAR */

#define CSL_CGEM_L1DWBAR_ADDR_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L1DWBAR_ADDR_MASK                              ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L1DWBAR_ADDR_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DWBAR_ADDR_MAX                               ((uint32_t)0xffffffffu)

#define CSL_CGEM_L1DWBAR_RESETVAL                               ((uint32_t)0x00000000u)

/* L1DWWC */

#define CSL_CGEM_L1DWWC_RESV_1_SHIFT                            ((uint32_t)16u)
#define CSL_CGEM_L1DWWC_RESV_1_MASK                             ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L1DWWC_RESV_1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DWWC_RESV_1_MAX                              ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1DWWC_WC_SHIFT                                ((uint32_t)0u)
#define CSL_CGEM_L1DWWC_WC_MASK                                 ((uint32_t)0x0000FFFFu)
#define CSL_CGEM_L1DWWC_WC_RESETVAL                             ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DWWC_WC_MAX                                  ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1DWWC_RESETVAL                                ((uint32_t)0x00000000u)

/* L1DIBAR */

#define CSL_CGEM_L1DIBAR_ADDR_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L1DIBAR_ADDR_MASK                              ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L1DIBAR_ADDR_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DIBAR_ADDR_MAX                               ((uint32_t)0xffffffffu)

#define CSL_CGEM_L1DIBAR_RESETVAL                               ((uint32_t)0x00000000u)

/* L1DIWC */

#define CSL_CGEM_L1DIWC_RESV_1_SHIFT                            ((uint32_t)16u)
#define CSL_CGEM_L1DIWC_RESV_1_MASK                             ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L1DIWC_RESV_1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DIWC_RESV_1_MAX                              ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1DIWC_WC_SHIFT                                ((uint32_t)0u)
#define CSL_CGEM_L1DIWC_WC_MASK                                 ((uint32_t)0x0000FFFFu)
#define CSL_CGEM_L1DIWC_WC_RESETVAL                             ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DIWC_WC_MAX                                  ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1DIWC_RESETVAL                                ((uint32_t)0x00000000u)

/* L2WB */

#define CSL_CGEM_L2WB_C_SHIFT                                   ((uint32_t)0u)
#define CSL_CGEM_L2WB_C_MASK                                    ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L2WB_C_RESETVAL                                ((uint32_t)0x00000000u)
#define CSL_CGEM_L2WB_C_MAX                                     ((uint32_t)0xffffffffu)

#define CSL_CGEM_L2WB_RESETVAL                                  ((uint32_t)0x00000000u)

/* L2WBINV */

#define CSL_CGEM_L2WBINV_C_SHIFT                                ((uint32_t)0u)
#define CSL_CGEM_L2WBINV_C_MASK                                 ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L2WBINV_C_RESETVAL                             ((uint32_t)0x00000000u)
#define CSL_CGEM_L2WBINV_C_MAX                                  ((uint32_t)0xffffffffu)

#define CSL_CGEM_L2WBINV_RESETVAL                               ((uint32_t)0x00000000u)

/* L2INV */

#define CSL_CGEM_L2INV_I_SHIFT                                  ((uint32_t)0u)
#define CSL_CGEM_L2INV_I_MASK                                   ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L2INV_I_RESETVAL                               ((uint32_t)0x00000000u)
#define CSL_CGEM_L2INV_I_MAX                                    ((uint32_t)0xffffffffu)

#define CSL_CGEM_L2INV_RESETVAL                                 ((uint32_t)0x00000000u)

/* L1PINV */

#define CSL_CGEM_L1PINV_I_SHIFT                                 ((uint32_t)0u)
#define CSL_CGEM_L1PINV_I_MASK                                  ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L1PINV_I_RESETVAL                              ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PINV_I_MAX                                   ((uint32_t)0xffffffffu)

#define CSL_CGEM_L1PINV_RESETVAL                                ((uint32_t)0x00000000u)

/* L1DWB */

#define CSL_CGEM_L1DWB_C_SHIFT                                  ((uint32_t)0u)
#define CSL_CGEM_L1DWB_C_MASK                                   ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L1DWB_C_RESETVAL                               ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DWB_C_MAX                                    ((uint32_t)0xffffffffu)

#define CSL_CGEM_L1DWB_RESETVAL                                 ((uint32_t)0x00000000u)

/* L1DWBINV */

#define CSL_CGEM_L1DWBINV_C_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_L1DWBINV_C_MASK                                ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L1DWBINV_C_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DWBINV_C_MAX                                 ((uint32_t)0xffffffffu)

#define CSL_CGEM_L1DWBINV_RESETVAL                              ((uint32_t)0x00000000u)

/* L1DINV */

#define CSL_CGEM_L1DINV_I_SHIFT                                 ((uint32_t)0u)
#define CSL_CGEM_L1DINV_I_MASK                                  ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L1DINV_I_RESETVAL                              ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DINV_I_MAX                                   ((uint32_t)0xffffffffu)

#define CSL_CGEM_L1DINV_RESETVAL                                ((uint32_t)0x00000000u)

/* L2EDSTAT */

#define CSL_CGEM_L2EDSTAT_RESV1_SHIFT                           ((uint32_t)24u)
#define CSL_CGEM_L2EDSTAT_RESV1_MASK                            ((uint32_t)0xFF000000u)
#define CSL_CGEM_L2EDSTAT_RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDSTAT_RESV1_MAX                             ((uint32_t)0x000000ffu)

#define CSL_CGEM_L2EDSTAT_BITPOS_SHIFT                          ((uint32_t)16u)
#define CSL_CGEM_L2EDSTAT_BITPOS_MASK                           ((uint32_t)0x00FF0000u)
#define CSL_CGEM_L2EDSTAT_BITPOS_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDSTAT_BITPOS_MAX                            ((uint32_t)0x000000ffu)

#define CSL_CGEM_L2EDSTAT_RESV2_SHIFT                           ((uint32_t)10u)
#define CSL_CGEM_L2EDSTAT_RESV2_MASK                            ((uint32_t)0x0000FC00u)
#define CSL_CGEM_L2EDSTAT_RESV2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDSTAT_RESV2_MAX                             ((uint32_t)0x0000003fu)

#define CSL_CGEM_L2EDSTAT_NERR_SHIFT                            ((uint32_t)8u)
#define CSL_CGEM_L2EDSTAT_NERR_MASK                             ((uint32_t)0x00000300u)
#define CSL_CGEM_L2EDSTAT_NERR_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDSTAT_NERR_MAX                              ((uint32_t)0x00000003u)

#define CSL_CGEM_L2EDSTAT_VERR_SHIFT                            ((uint32_t)7u)
#define CSL_CGEM_L2EDSTAT_VERR_MASK                             ((uint32_t)0x00000080u)
#define CSL_CGEM_L2EDSTAT_VERR_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDSTAT_VERR_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDSTAT_DMAERR_SHIFT                          ((uint32_t)6u)
#define CSL_CGEM_L2EDSTAT_DMAERR_MASK                           ((uint32_t)0x00000040u)
#define CSL_CGEM_L2EDSTAT_DMAERR_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDSTAT_DMAERR_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDSTAT_PERR_SHIFT                            ((uint32_t)5u)
#define CSL_CGEM_L2EDSTAT_PERR_MASK                             ((uint32_t)0x00000020u)
#define CSL_CGEM_L2EDSTAT_PERR_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDSTAT_PERR_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDSTAT_DERR_SHIFT                            ((uint32_t)4u)
#define CSL_CGEM_L2EDSTAT_DERR_MASK                             ((uint32_t)0x00000010u)
#define CSL_CGEM_L2EDSTAT_DERR_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDSTAT_DERR_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDSTAT_SUSP_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_L2EDSTAT_SUSP_MASK                             ((uint32_t)0x00000008u)
#define CSL_CGEM_L2EDSTAT_SUSP_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDSTAT_SUSP_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDSTAT_DIS_SHIFT                             ((uint32_t)2u)
#define CSL_CGEM_L2EDSTAT_DIS_MASK                              ((uint32_t)0x00000004u)
#define CSL_CGEM_L2EDSTAT_DIS_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDSTAT_DIS_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDSTAT_RESV3_SHIFT                           ((uint32_t)1u)
#define CSL_CGEM_L2EDSTAT_RESV3_MASK                            ((uint32_t)0x00000002u)
#define CSL_CGEM_L2EDSTAT_RESV3_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDSTAT_RESV3_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDSTAT_EN_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_L2EDSTAT_EN_MASK                               ((uint32_t)0x00000001u)
#define CSL_CGEM_L2EDSTAT_EN_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L2EDSTAT_EN_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDSTAT_RESETVAL                              ((uint32_t)0x00000001u)

/* L2EDCMD */

#define CSL_CGEM_L2EDCMD_RESV1_SHIFT                            ((uint32_t)8u)
#define CSL_CGEM_L2EDCMD_RESV1_MASK                             ((uint32_t)0xFFFFFF00u)
#define CSL_CGEM_L2EDCMD_RESV1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCMD_RESV1_MAX                              ((uint32_t)0x00ffffffu)

#define CSL_CGEM_L2EDCMD_VCLR_SHIFT                             ((uint32_t)7u)
#define CSL_CGEM_L2EDCMD_VCLR_MASK                              ((uint32_t)0x00000080u)
#define CSL_CGEM_L2EDCMD_VCLR_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCMD_VCLR_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCMD_DMACLR_SHIFT                           ((uint32_t)6u)
#define CSL_CGEM_L2EDCMD_DMACLR_MASK                            ((uint32_t)0x00000040u)
#define CSL_CGEM_L2EDCMD_DMACLR_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCMD_DMACLR_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCMD_PCLR_SHIFT                             ((uint32_t)5u)
#define CSL_CGEM_L2EDCMD_PCLR_MASK                              ((uint32_t)0x00000020u)
#define CSL_CGEM_L2EDCMD_PCLR_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCMD_PCLR_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCMD_DCLR_SHIFT                             ((uint32_t)4u)
#define CSL_CGEM_L2EDCMD_DCLR_MASK                              ((uint32_t)0x00000010u)
#define CSL_CGEM_L2EDCMD_DCLR_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCMD_DCLR_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCMD_SUSP_SHIFT                             ((uint32_t)3u)
#define CSL_CGEM_L2EDCMD_SUSP_MASK                              ((uint32_t)0x00000008u)
#define CSL_CGEM_L2EDCMD_SUSP_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCMD_SUSP_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCMD_DIS_SHIFT                              ((uint32_t)2u)
#define CSL_CGEM_L2EDCMD_DIS_MASK                               ((uint32_t)0x00000004u)
#define CSL_CGEM_L2EDCMD_DIS_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCMD_DIS_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCMD_RESV3_SHIFT                            ((uint32_t)1u)
#define CSL_CGEM_L2EDCMD_RESV3_MASK                             ((uint32_t)0x00000002u)
#define CSL_CGEM_L2EDCMD_RESV3_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCMD_RESV3_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCMD_EN_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_L2EDCMD_EN_MASK                                ((uint32_t)0x00000001u)
#define CSL_CGEM_L2EDCMD_EN_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L2EDCMD_EN_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCMD_RESETVAL                               ((uint32_t)0x00000001u)

/* L2EDADDR */

#define CSL_CGEM_L2EDADDR_ADDR_SHIFT                            ((uint32_t)5u)
#define CSL_CGEM_L2EDADDR_ADDR_MASK                             ((uint32_t)0xFFFFFFE0u)
#define CSL_CGEM_L2EDADDR_ADDR_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDADDR_ADDR_MAX                              ((uint32_t)0x07ffffffu)

#define CSL_CGEM_L2EDADDR_WAY_SHIFT                             ((uint32_t)3u)
#define CSL_CGEM_L2EDADDR_WAY_MASK                              ((uint32_t)0x00000018u)
#define CSL_CGEM_L2EDADDR_WAY_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDADDR_WAY_MAX                               ((uint32_t)0x00000003u)

#define CSL_CGEM_L2EDADDR_RESV1_SHIFT                           ((uint32_t)1u)
#define CSL_CGEM_L2EDADDR_RESV1_MASK                            ((uint32_t)0x00000006u)
#define CSL_CGEM_L2EDADDR_RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDADDR_RESV1_MAX                             ((uint32_t)0x00000003u)

#define CSL_CGEM_L2EDADDR_RAM_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L2EDADDR_RAM_MASK                              ((uint32_t)0x00000001u)
#define CSL_CGEM_L2EDADDR_RAM_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDADDR_RAM_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDADDR_RESETVAL                              ((uint32_t)0x00000000u)

/* L2EDCPEC */

#define CSL_CGEM_L2EDCPEC_RESV1_SHIFT                           ((uint32_t)8u)
#define CSL_CGEM_L2EDCPEC_RESV1_MASK                            ((uint32_t)0xFFFFFF00u)
#define CSL_CGEM_L2EDCPEC_RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCPEC_RESV1_MAX                             ((uint32_t)0x00ffffffu)

#define CSL_CGEM_L2EDCPEC_CNT_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L2EDCPEC_CNT_MASK                              ((uint32_t)0x000000FFu)
#define CSL_CGEM_L2EDCPEC_CNT_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCPEC_CNT_MAX                               ((uint32_t)0x000000ffu)

#define CSL_CGEM_L2EDCPEC_RESETVAL                              ((uint32_t)0x00000000u)

/* L2EDCNEC */

#define CSL_CGEM_L2EDCNEC_RESV1_SHIFT                           ((uint32_t)8u)
#define CSL_CGEM_L2EDCNEC_RESV1_MASK                            ((uint32_t)0xFFFFFF00u)
#define CSL_CGEM_L2EDCNEC_RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCNEC_RESV1_MAX                             ((uint32_t)0x00ffffffu)

#define CSL_CGEM_L2EDCNEC_CNT_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L2EDCNEC_CNT_MASK                              ((uint32_t)0x000000FFu)
#define CSL_CGEM_L2EDCNEC_CNT_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCNEC_CNT_MAX                               ((uint32_t)0x000000ffu)

#define CSL_CGEM_L2EDCNEC_RESETVAL                              ((uint32_t)0x00000000u)

/* MDMAERR */

#define CSL_CGEM_MDMAERR_ERR_SHIFT                              ((uint32_t)29u)
#define CSL_CGEM_MDMAERR_ERR_MASK                               ((uint32_t)0xE0000000u)
#define CSL_CGEM_MDMAERR_ERR_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_MDMAERR_ERR_MAX                                ((uint32_t)0x00000007u)

#define CSL_CGEM_MDMAERR_RESV_2_SHIFT                           ((uint32_t)12u)
#define CSL_CGEM_MDMAERR_RESV_2_MASK                            ((uint32_t)0x1FFFF000u)
#define CSL_CGEM_MDMAERR_RESV_2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_MDMAERR_RESV_2_MAX                             ((uint32_t)0x0001ffffu)

#define CSL_CGEM_MDMAERR_XID_SHIFT                              ((uint32_t)8u)
#define CSL_CGEM_MDMAERR_XID_MASK                               ((uint32_t)0x00000F00u)
#define CSL_CGEM_MDMAERR_XID_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_MDMAERR_XID_MAX                                ((uint32_t)0x0000000fu)

#define CSL_CGEM_MDMAERR_RESV_1_SHIFT                           ((uint32_t)3u)
#define CSL_CGEM_MDMAERR_RESV_1_MASK                            ((uint32_t)0x000000F8u)
#define CSL_CGEM_MDMAERR_RESV_1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_MDMAERR_RESV_1_MAX                             ((uint32_t)0x0000001fu)

#define CSL_CGEM_MDMAERR_STAT_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_MDMAERR_STAT_MASK                              ((uint32_t)0x00000007u)
#define CSL_CGEM_MDMAERR_STAT_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_MDMAERR_STAT_MAX                               ((uint32_t)0x00000007u)

#define CSL_CGEM_MDMAERR_RESETVAL                               ((uint32_t)0x00000000u)

/* MDMAERRCLR */

#define CSL_CGEM_MDMAERRCLR_RESV_1_SHIFT                        ((uint32_t)1u)
#define CSL_CGEM_MDMAERRCLR_RESV_1_MASK                         ((uint32_t)0xFFFFFFFEu)
#define CSL_CGEM_MDMAERRCLR_RESV_1_RESETVAL                     ((uint32_t)0x00000000u)
#define CSL_CGEM_MDMAERRCLR_RESV_1_MAX                          ((uint32_t)0x7fffffffu)

#define CSL_CGEM_MDMAERRCLR_CLR_SHIFT                           ((uint32_t)0u)
#define CSL_CGEM_MDMAERRCLR_CLR_MASK                            ((uint32_t)0x00000001u)
#define CSL_CGEM_MDMAERRCLR_CLR_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_MDMAERRCLR_CLR_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_MDMAERRCLR_RESETVAL                            ((uint32_t)0x00000000u)

/* L2EDCEN */

#define CSL_CGEM_L2EDCEN_RESV1_SHIFT                            ((uint32_t)5u)
#define CSL_CGEM_L2EDCEN_RESV1_MASK                             ((uint32_t)0xFFFFFFE0u)
#define CSL_CGEM_L2EDCEN_RESV1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2EDCEN_RESV1_MAX                              ((uint32_t)0x07ffffffu)

#define CSL_CGEM_L2EDCEN_SDMAEN_SHIFT                           ((uint32_t)4u)
#define CSL_CGEM_L2EDCEN_SDMAEN_MASK                            ((uint32_t)0x00000010u)
#define CSL_CGEM_L2EDCEN_SDMAEN_RESETVAL                        ((uint32_t)0x00000001u)
#define CSL_CGEM_L2EDCEN_SDMAEN_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCEN_PL2SEN_SHIFT                           ((uint32_t)3u)
#define CSL_CGEM_L2EDCEN_PL2SEN_MASK                            ((uint32_t)0x00000008u)
#define CSL_CGEM_L2EDCEN_PL2SEN_RESETVAL                        ((uint32_t)0x00000001u)
#define CSL_CGEM_L2EDCEN_PL2SEN_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCEN_DL2SEN_SHIFT                           ((uint32_t)2u)
#define CSL_CGEM_L2EDCEN_DL2SEN_MASK                            ((uint32_t)0x00000004u)
#define CSL_CGEM_L2EDCEN_DL2SEN_RESETVAL                        ((uint32_t)0x00000001u)
#define CSL_CGEM_L2EDCEN_DL2SEN_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCEN_PL2CEN_SHIFT                           ((uint32_t)1u)
#define CSL_CGEM_L2EDCEN_PL2CEN_MASK                            ((uint32_t)0x00000002u)
#define CSL_CGEM_L2EDCEN_PL2CEN_RESETVAL                        ((uint32_t)0x00000001u)
#define CSL_CGEM_L2EDCEN_PL2CEN_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCEN_DL2CEN_SHIFT                           ((uint32_t)0u)
#define CSL_CGEM_L2EDCEN_DL2CEN_MASK                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L2EDCEN_DL2CEN_RESETVAL                        ((uint32_t)0x00000001u)
#define CSL_CGEM_L2EDCEN_DL2CEN_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2EDCEN_RESETVAL                               ((uint32_t)0x0000001fu)

/* L1PEDSTAT */

#define CSL_CGEM_L1PEDSTAT_RESV1_SHIFT                          ((uint32_t)7u)
#define CSL_CGEM_L1PEDSTAT_RESV1_MASK                           ((uint32_t)0xFFFFFF80u)
#define CSL_CGEM_L1PEDSTAT_RESV1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDSTAT_RESV1_MAX                            ((uint32_t)0x01ffffffu)

#define CSL_CGEM_L1PEDSTAT_DMAERR_SHIFT                         ((uint32_t)6u)
#define CSL_CGEM_L1PEDSTAT_DMAERR_MASK                          ((uint32_t)0x00000040u)
#define CSL_CGEM_L1PEDSTAT_DMAERR_RESETVAL                      ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDSTAT_DMAERR_MAX                           ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDSTAT_PERR_SHIFT                           ((uint32_t)5u)
#define CSL_CGEM_L1PEDSTAT_PERR_MASK                            ((uint32_t)0x00000020u)
#define CSL_CGEM_L1PEDSTAT_PERR_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDSTAT_PERR_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDSTAT_RESV2_SHIFT                          ((uint32_t)4u)
#define CSL_CGEM_L1PEDSTAT_RESV2_MASK                           ((uint32_t)0x00000010u)
#define CSL_CGEM_L1PEDSTAT_RESV2_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDSTAT_RESV2_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDSTAT_SUSP_SHIFT                           ((uint32_t)3u)
#define CSL_CGEM_L1PEDSTAT_SUSP_MASK                            ((uint32_t)0x00000008u)
#define CSL_CGEM_L1PEDSTAT_SUSP_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDSTAT_SUSP_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDSTAT_DIS_SHIFT                            ((uint32_t)2u)
#define CSL_CGEM_L1PEDSTAT_DIS_MASK                             ((uint32_t)0x00000004u)
#define CSL_CGEM_L1PEDSTAT_DIS_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDSTAT_DIS_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDSTAT_RESV3_SHIFT                          ((uint32_t)1u)
#define CSL_CGEM_L1PEDSTAT_RESV3_MASK                           ((uint32_t)0x00000002u)
#define CSL_CGEM_L1PEDSTAT_RESV3_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDSTAT_RESV3_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDSTAT_EN_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L1PEDSTAT_EN_MASK                              ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PEDSTAT_EN_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDSTAT_EN_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDSTAT_RESETVAL                             ((uint32_t)0x00000000u)

/* L1PEDCMD */

#define CSL_CGEM_L1PEDCMD_RESV1_SHIFT                           ((uint32_t)7u)
#define CSL_CGEM_L1PEDCMD_RESV1_MASK                            ((uint32_t)0xFFFFFF80u)
#define CSL_CGEM_L1PEDCMD_RESV1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDCMD_RESV1_MAX                             ((uint32_t)0x01ffffffu)

#define CSL_CGEM_L1PEDCMD_DMACLR_SHIFT                          ((uint32_t)6u)
#define CSL_CGEM_L1PEDCMD_DMACLR_MASK                           ((uint32_t)0x00000040u)
#define CSL_CGEM_L1PEDCMD_DMACLR_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDCMD_DMACLR_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDCMD_PCLR_SHIFT                            ((uint32_t)5u)
#define CSL_CGEM_L1PEDCMD_PCLR_MASK                             ((uint32_t)0x00000020u)
#define CSL_CGEM_L1PEDCMD_PCLR_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDCMD_PCLR_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDCMD_RESV2_SHIFT                           ((uint32_t)4u)
#define CSL_CGEM_L1PEDCMD_RESV2_MASK                            ((uint32_t)0x00000010u)
#define CSL_CGEM_L1PEDCMD_RESV2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDCMD_RESV2_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDCMD_SUSP_SHIFT                            ((uint32_t)3u)
#define CSL_CGEM_L1PEDCMD_SUSP_MASK                             ((uint32_t)0x00000008u)
#define CSL_CGEM_L1PEDCMD_SUSP_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDCMD_SUSP_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDCMD_DIS_SHIFT                             ((uint32_t)2u)
#define CSL_CGEM_L1PEDCMD_DIS_MASK                              ((uint32_t)0x00000004u)
#define CSL_CGEM_L1PEDCMD_DIS_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDCMD_DIS_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDCMD_RESV3_SHIFT                           ((uint32_t)1u)
#define CSL_CGEM_L1PEDCMD_RESV3_MASK                            ((uint32_t)0x00000002u)
#define CSL_CGEM_L1PEDCMD_RESV3_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDCMD_RESV3_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDCMD_EN_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_L1PEDCMD_EN_MASK                               ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PEDCMD_EN_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDCMD_EN_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDCMD_RESETVAL                              ((uint32_t)0x00000000u)

/* L1PEDADDR */

#define CSL_CGEM_L1PEDADDR_ADDR_SHIFT                           ((uint32_t)5u)
#define CSL_CGEM_L1PEDADDR_ADDR_MASK                            ((uint32_t)0xFFFFFFE0u)
#define CSL_CGEM_L1PEDADDR_ADDR_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDADDR_ADDR_MAX                             ((uint32_t)0x07ffffffu)

#define CSL_CGEM_L1PEDADDR_RESV1_SHIFT                          ((uint32_t)1u)
#define CSL_CGEM_L1PEDADDR_RESV1_MASK                           ((uint32_t)0x0000001Eu)
#define CSL_CGEM_L1PEDADDR_RESV1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDADDR_RESV1_MAX                            ((uint32_t)0x0000000fu)

#define CSL_CGEM_L1PEDADDR_RAM_SHIFT                            ((uint32_t)0u)
#define CSL_CGEM_L1PEDADDR_RAM_MASK                             ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PEDADDR_RAM_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PEDADDR_RAM_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PEDADDR_RESETVAL                             ((uint32_t)0x00000000u)
#ifndef CSL_MODIFICATION    

/* MAR0 */


#define CSL_CGEM_MAR0_PFX_MASK           ((uint32_t)0x00000008u)
#define CSL_CGEM_MAR0_PFX_SHIFT          ((uint32_t)0x00000003u)
#define CSL_CGEM_MAR0_PFX_RESETVAL       ((uint32_t)0x00000000u)

#define CSL_CGEM_MAR0_PCX_MASK           ((uint32_t)0x00000004u)
#define CSL_CGEM_MAR0_PCX_SHIFT          ((uint32_t)0x00000002u)
#define CSL_CGEM_MAR0_PCX_RESETVAL       ((uint32_t)0x00000000u)

#define CSL_CGEM_MAR0_WTE_MASK           ((uint32_t)0x00000002u)
#define CSL_CGEM_MAR0_WTE_SHIFT          ((uint32_t)0x00000001u)
#define CSL_CGEM_MAR0_WTE_RESETVAL       ((uint32_t)0x00000000u)

#define CSL_CGEM_MAR0_PC_MASK            ((uint32_t)0x00000001u)
#define CSL_CGEM_MAR0_PC_SHIFT           ((uint32_t)0x00000000u)
#define CSL_CGEM_MAR0_PC_RESETVAL        ((uint32_t)0x00000000u)

#define CSL_CGEM_MAR0_RESETVAL           ((uint32_t)0x00000000u)
#endif
/* MAR */

#define CSL_CGEM_MAR_RESV_1_SHIFT                               ((uint32_t)4u)
#define CSL_CGEM_MAR_RESV_1_MASK                                ((uint32_t)0xFFFFFFF0u)
#define CSL_CGEM_MAR_RESV_1_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_MAR_RESV_1_MAX                                 ((uint32_t)0x0fffffffu)

#define CSL_CGEM_MAR_PFX_SHIFT                                  ((uint32_t)3u)
#define CSL_CGEM_MAR_PFX_MASK                                   ((uint32_t)0x00000008u)
#define CSL_CGEM_MAR_PFX_RESETVAL                               ((uint32_t)0x00000000u)
#define CSL_CGEM_MAR_PFX_MAX                                    ((uint32_t)0x00000001u)

#define CSL_CGEM_MAR_PCX_SHIFT                                  ((uint32_t)2u)
#define CSL_CGEM_MAR_PCX_MASK                                   ((uint32_t)0x00000004u)
#define CSL_CGEM_MAR_PCX_RESETVAL                               ((uint32_t)0x00000000u)
#define CSL_CGEM_MAR_PCX_MAX                                    ((uint32_t)0x00000001u)

#define CSL_CGEM_MAR_WTE_SHIFT                                  ((uint32_t)1u)
#define CSL_CGEM_MAR_WTE_MASK                                   ((uint32_t)0x00000002u)
#define CSL_CGEM_MAR_WTE_RESETVAL                               ((uint32_t)0x00000000u)
#define CSL_CGEM_MAR_WTE_MAX                                    ((uint32_t)0x00000001u)

#define CSL_CGEM_MAR_PC_SHIFT                                   ((uint32_t)0u)
#define CSL_CGEM_MAR_PC_MASK                                    ((uint32_t)0x00000001u)
#define CSL_CGEM_MAR_PC_RESETVAL                                ((uint32_t)0x00000001u)
#define CSL_CGEM_MAR_PC_MAX                                     ((uint32_t)0x00000001u)

#define CSL_CGEM_MAR_RESETVAL                                   ((uint32_t)0x00000001u)

/* L2MPFAR */

#define CSL_CGEM_L2MPFAR_ADDR_SHIFT                             ((uint32_t)0u)
#define CSL_CGEM_L2MPFAR_ADDR_MASK                              ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L2MPFAR_ADDR_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFAR_ADDR_MAX                               ((uint32_t)0xffffffffu)

#define CSL_CGEM_L2MPFAR_RESETVAL                               ((uint32_t)0x00000000u)

/* L2MPFSR */

#define CSL_CGEM_L2MPFSR_RESV_1_SHIFT                           ((uint32_t)16u)
#define CSL_CGEM_L2MPFSR_RESV_1_MASK                            ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L2MPFSR_RESV_1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFSR_RESV_1_MAX                             ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L2MPFSR_FID_SHIFT                              ((uint32_t)9u)
#define CSL_CGEM_L2MPFSR_FID_MASK                               ((uint32_t)0x0000FE00u)
#define CSL_CGEM_L2MPFSR_FID_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFSR_FID_MAX                                ((uint32_t)0x0000007fu)

#define CSL_CGEM_L2MPFSR_LOCAL_SHIFT                            ((uint32_t)8u)
#define CSL_CGEM_L2MPFSR_LOCAL_MASK                             ((uint32_t)0x00000100u)
#define CSL_CGEM_L2MPFSR_LOCAL_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFSR_LOCAL_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPFSR_NS_SHIFT                               ((uint32_t)7u)
#define CSL_CGEM_L2MPFSR_NS_MASK                                ((uint32_t)0x00000080u)
#define CSL_CGEM_L2MPFSR_NS_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFSR_NS_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPFSR_RESV_2_SHIFT                           ((uint32_t)6u)
#define CSL_CGEM_L2MPFSR_RESV_2_MASK                            ((uint32_t)0x00000040u)
#define CSL_CGEM_L2MPFSR_RESV_2_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFSR_RESV_2_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPFSR_SR_SHIFT                               ((uint32_t)5u)
#define CSL_CGEM_L2MPFSR_SR_MASK                                ((uint32_t)0x00000020u)
#define CSL_CGEM_L2MPFSR_SR_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFSR_SR_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPFSR_SW_SHIFT                               ((uint32_t)4u)
#define CSL_CGEM_L2MPFSR_SW_MASK                                ((uint32_t)0x00000010u)
#define CSL_CGEM_L2MPFSR_SW_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFSR_SW_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPFSR_SX_SHIFT                               ((uint32_t)3u)
#define CSL_CGEM_L2MPFSR_SX_MASK                                ((uint32_t)0x00000008u)
#define CSL_CGEM_L2MPFSR_SX_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFSR_SX_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPFSR_UR_SHIFT                               ((uint32_t)2u)
#define CSL_CGEM_L2MPFSR_UR_MASK                                ((uint32_t)0x00000004u)
#define CSL_CGEM_L2MPFSR_UR_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFSR_UR_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPFSR_UW_SHIFT                               ((uint32_t)1u)
#define CSL_CGEM_L2MPFSR_UW_MASK                                ((uint32_t)0x00000002u)
#define CSL_CGEM_L2MPFSR_UW_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFSR_UW_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPFSR_UX_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_L2MPFSR_UX_MASK                                ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPFSR_UX_RESETVAL                            ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFSR_UX_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPFSR_RESETVAL                               ((uint32_t)0x00000000u)

/* L2MPFCR */

#define CSL_CGEM_L2MPFCR_RESV_1_SHIFT                           ((uint32_t)1u)
#define CSL_CGEM_L2MPFCR_RESV_1_MASK                            ((uint32_t)0xFFFFFFFEu)
#define CSL_CGEM_L2MPFCR_RESV_1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFCR_RESV_1_MAX                             ((uint32_t)0x7fffffffu)

#define CSL_CGEM_L2MPFCR_MPFCLR_SHIFT                           ((uint32_t)0u)
#define CSL_CGEM_L2MPFCR_MPFCLR_MASK                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPFCR_MPFCLR_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPFCR_MPFCLR_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPFCR_RESETVAL                               ((uint32_t)0x00000000u)

/* L2MPPA */

#define CSL_CGEM_L2MPPA_RESV_1_SHIFT                            ((uint32_t)16u)
#define CSL_CGEM_L2MPPA_RESV_1_MASK                             ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L2MPPA_RESV_1_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L2MPPA_RESV_1_MAX                              ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L2MPPA_AID5_SHIFT                              ((uint32_t)15u)
#define CSL_CGEM_L2MPPA_AID5_MASK                               ((uint32_t)0x00008000u)
#define CSL_CGEM_L2MPPA_AID5_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_AID5_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_AID4_SHIFT                              ((uint32_t)14u)
#define CSL_CGEM_L2MPPA_AID4_MASK                               ((uint32_t)0x00004000u)
#define CSL_CGEM_L2MPPA_AID4_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_AID4_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_AID3_SHIFT                              ((uint32_t)13u)
#define CSL_CGEM_L2MPPA_AID3_MASK                               ((uint32_t)0x00002000u)
#define CSL_CGEM_L2MPPA_AID3_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_AID3_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_AID2_SHIFT                              ((uint32_t)12u)
#define CSL_CGEM_L2MPPA_AID2_MASK                               ((uint32_t)0x00001000u)
#define CSL_CGEM_L2MPPA_AID2_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_AID2_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_AID1_SHIFT                              ((uint32_t)11u)
#define CSL_CGEM_L2MPPA_AID1_MASK                               ((uint32_t)0x00000800u)
#define CSL_CGEM_L2MPPA_AID1_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_AID1_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_AID0_SHIFT                              ((uint32_t)10u)
#define CSL_CGEM_L2MPPA_AID0_MASK                               ((uint32_t)0x00000400u)
#define CSL_CGEM_L2MPPA_AID0_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_AID0_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_AIDX_SHIFT                              ((uint32_t)9u)
#define CSL_CGEM_L2MPPA_AIDX_MASK                               ((uint32_t)0x00000200u)
#define CSL_CGEM_L2MPPA_AIDX_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_AIDX_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_LOCAL_SHIFT                             ((uint32_t)8u)
#define CSL_CGEM_L2MPPA_LOCAL_MASK                              ((uint32_t)0x00000100u)
#define CSL_CGEM_L2MPPA_LOCAL_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_LOCAL_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_NS_SHIFT                                ((uint32_t)7u)
#define CSL_CGEM_L2MPPA_NS_MASK                                 ((uint32_t)0x00000080u)
#define CSL_CGEM_L2MPPA_NS_RESETVAL                             ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_NS_MAX                                  ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_EMU_SHIFT                               ((uint32_t)6u)
#define CSL_CGEM_L2MPPA_EMU_MASK                                ((uint32_t)0x00000040u)
#define CSL_CGEM_L2MPPA_EMU_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_EMU_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_SR_SHIFT                                ((uint32_t)5u)
#define CSL_CGEM_L2MPPA_SR_MASK                                 ((uint32_t)0x00000020u)
#define CSL_CGEM_L2MPPA_SR_RESETVAL                             ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_SR_MAX                                  ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_SW_SHIFT                                ((uint32_t)4u)
#define CSL_CGEM_L2MPPA_SW_MASK                                 ((uint32_t)0x00000010u)
#define CSL_CGEM_L2MPPA_SW_RESETVAL                             ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_SW_MAX                                  ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_SX_SHIFT                                ((uint32_t)3u)
#define CSL_CGEM_L2MPPA_SX_MASK                                 ((uint32_t)0x00000008u)
#define CSL_CGEM_L2MPPA_SX_RESETVAL                             ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_SX_MAX                                  ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_UR_SHIFT                                ((uint32_t)2u)
#define CSL_CGEM_L2MPPA_UR_MASK                                 ((uint32_t)0x00000004u)
#define CSL_CGEM_L2MPPA_UR_RESETVAL                             ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_UR_MAX                                  ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_UW_SHIFT                                ((uint32_t)1u)
#define CSL_CGEM_L2MPPA_UW_MASK                                 ((uint32_t)0x00000002u)
#define CSL_CGEM_L2MPPA_UW_RESETVAL                             ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_UW_MAX                                  ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_UX_SHIFT                                ((uint32_t)0u)
#define CSL_CGEM_L2MPPA_UX_MASK                                 ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_UX_RESETVAL                             ((uint32_t)0x00000001u)
#define CSL_CGEM_L2MPPA_UX_MAX                                  ((uint32_t)0x00000001u)

#define CSL_CGEM_L2MPPA_RESETVAL                                ((uint32_t)0x0000ffffu)

/* L1PMPFAR */

#define CSL_CGEM_L1PMPFAR_ADDR_SHIFT                            ((uint32_t)0u)
#define CSL_CGEM_L1PMPFAR_ADDR_MASK                             ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L1PMPFAR_ADDR_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFAR_ADDR_MAX                              ((uint32_t)0xffffffffu)

#define CSL_CGEM_L1PMPFAR_RESETVAL                              ((uint32_t)0x00000000u)

/* L1PMPFSR */

#define CSL_CGEM_L1PMPFSR_RESV_1_SHIFT                          ((uint32_t)16u)
#define CSL_CGEM_L1PMPFSR_RESV_1_MASK                           ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L1PMPFSR_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFSR_RESV_1_MAX                            ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1PMPFSR_FID_SHIFT                             ((uint32_t)9u)
#define CSL_CGEM_L1PMPFSR_FID_MASK                              ((uint32_t)0x0000FE00u)
#define CSL_CGEM_L1PMPFSR_FID_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFSR_FID_MAX                               ((uint32_t)0x0000007fu)

#define CSL_CGEM_L1PMPFSR_LOCAL_SHIFT                           ((uint32_t)8u)
#define CSL_CGEM_L1PMPFSR_LOCAL_MASK                            ((uint32_t)0x00000100u)
#define CSL_CGEM_L1PMPFSR_LOCAL_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFSR_LOCAL_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPFSR_NS_SHIFT                              ((uint32_t)7u)
#define CSL_CGEM_L1PMPFSR_NS_MASK                               ((uint32_t)0x00000080u)
#define CSL_CGEM_L1PMPFSR_NS_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFSR_NS_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPFSR_RESV_2_SHIFT                          ((uint32_t)6u)
#define CSL_CGEM_L1PMPFSR_RESV_2_MASK                           ((uint32_t)0x00000040u)
#define CSL_CGEM_L1PMPFSR_RESV_2_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFSR_RESV_2_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPFSR_SR_SHIFT                              ((uint32_t)5u)
#define CSL_CGEM_L1PMPFSR_SR_MASK                               ((uint32_t)0x00000020u)
#define CSL_CGEM_L1PMPFSR_SR_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFSR_SR_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPFSR_SW_SHIFT                              ((uint32_t)4u)
#define CSL_CGEM_L1PMPFSR_SW_MASK                               ((uint32_t)0x00000010u)
#define CSL_CGEM_L1PMPFSR_SW_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFSR_SW_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPFSR_SX_SHIFT                              ((uint32_t)3u)
#define CSL_CGEM_L1PMPFSR_SX_MASK                               ((uint32_t)0x00000008u)
#define CSL_CGEM_L1PMPFSR_SX_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFSR_SX_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPFSR_UR_SHIFT                              ((uint32_t)2u)
#define CSL_CGEM_L1PMPFSR_UR_MASK                               ((uint32_t)0x00000004u)
#define CSL_CGEM_L1PMPFSR_UR_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFSR_UR_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPFSR_UW_SHIFT                              ((uint32_t)1u)
#define CSL_CGEM_L1PMPFSR_UW_MASK                               ((uint32_t)0x00000002u)
#define CSL_CGEM_L1PMPFSR_UW_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFSR_UW_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPFSR_UX_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_L1PMPFSR_UX_MASK                               ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPFSR_UX_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFSR_UX_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPFSR_RESETVAL                              ((uint32_t)0x00000000u)

/* L1PMPFCR */

#define CSL_CGEM_L1PMPFCR_RESV_1_SHIFT                          ((uint32_t)1u)
#define CSL_CGEM_L1PMPFCR_RESV_1_MASK                           ((uint32_t)0xFFFFFFFEu)
#define CSL_CGEM_L1PMPFCR_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFCR_RESV_1_MAX                            ((uint32_t)0x7fffffffu)

#define CSL_CGEM_L1PMPFCR_MPFCLR_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_L1PMPFCR_MPFCLR_MASK                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPFCR_MPFCLR_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPFCR_MPFCLR_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPFCR_RESETVAL                              ((uint32_t)0x00000000u)

/* L1PMPPA */

#define CSL_CGEM_L1PMPPA_RESV_1_SHIFT                           ((uint32_t)16u)
#define CSL_CGEM_L1PMPPA_RESV_1_MASK                            ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L1PMPPA_RESV_1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1PMPPA_RESV_1_MAX                             ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1PMPPA_AID5_SHIFT                             ((uint32_t)15u)
#define CSL_CGEM_L1PMPPA_AID5_MASK                              ((uint32_t)0x00008000u)
#define CSL_CGEM_L1PMPPA_AID5_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_AID5_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_AID4_SHIFT                             ((uint32_t)14u)
#define CSL_CGEM_L1PMPPA_AID4_MASK                              ((uint32_t)0x00004000u)
#define CSL_CGEM_L1PMPPA_AID4_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_AID4_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_AID3_SHIFT                             ((uint32_t)13u)
#define CSL_CGEM_L1PMPPA_AID3_MASK                              ((uint32_t)0x00002000u)
#define CSL_CGEM_L1PMPPA_AID3_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_AID3_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_AID2_SHIFT                             ((uint32_t)12u)
#define CSL_CGEM_L1PMPPA_AID2_MASK                              ((uint32_t)0x00001000u)
#define CSL_CGEM_L1PMPPA_AID2_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_AID2_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_AID1_SHIFT                             ((uint32_t)11u)
#define CSL_CGEM_L1PMPPA_AID1_MASK                              ((uint32_t)0x00000800u)
#define CSL_CGEM_L1PMPPA_AID1_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_AID1_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_AID0_SHIFT                             ((uint32_t)10u)
#define CSL_CGEM_L1PMPPA_AID0_MASK                              ((uint32_t)0x00000400u)
#define CSL_CGEM_L1PMPPA_AID0_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_AID0_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_AIDX_SHIFT                             ((uint32_t)9u)
#define CSL_CGEM_L1PMPPA_AIDX_MASK                              ((uint32_t)0x00000200u)
#define CSL_CGEM_L1PMPPA_AIDX_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_AIDX_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_LOCAL_SHIFT                            ((uint32_t)8u)
#define CSL_CGEM_L1PMPPA_LOCAL_MASK                             ((uint32_t)0x00000100u)
#define CSL_CGEM_L1PMPPA_LOCAL_RESETVAL                         ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_LOCAL_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_NS_SHIFT                               ((uint32_t)7u)
#define CSL_CGEM_L1PMPPA_NS_MASK                                ((uint32_t)0x00000080u)
#define CSL_CGEM_L1PMPPA_NS_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_NS_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_EMU_SHIFT                              ((uint32_t)6u)
#define CSL_CGEM_L1PMPPA_EMU_MASK                               ((uint32_t)0x00000040u)
#define CSL_CGEM_L1PMPPA_EMU_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_EMU_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_SR_SHIFT                               ((uint32_t)5u)
#define CSL_CGEM_L1PMPPA_SR_MASK                                ((uint32_t)0x00000020u)
#define CSL_CGEM_L1PMPPA_SR_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_SR_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_SW_SHIFT                               ((uint32_t)4u)
#define CSL_CGEM_L1PMPPA_SW_MASK                                ((uint32_t)0x00000010u)
#define CSL_CGEM_L1PMPPA_SW_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_SW_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_SX_SHIFT                               ((uint32_t)3u)
#define CSL_CGEM_L1PMPPA_SX_MASK                                ((uint32_t)0x00000008u)
#define CSL_CGEM_L1PMPPA_SX_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_SX_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_UR_SHIFT                               ((uint32_t)2u)
#define CSL_CGEM_L1PMPPA_UR_MASK                                ((uint32_t)0x00000004u)
#define CSL_CGEM_L1PMPPA_UR_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_UR_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_UW_SHIFT                               ((uint32_t)1u)
#define CSL_CGEM_L1PMPPA_UW_MASK                                ((uint32_t)0x00000002u)
#define CSL_CGEM_L1PMPPA_UW_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_UW_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_UX_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_L1PMPPA_UX_MASK                                ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_UX_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1PMPPA_UX_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1PMPPA_RESETVAL                               ((uint32_t)0x0000ffffu)

/* L1DMPFAR */

#define CSL_CGEM_L1DMPFAR_ADDR_SHIFT                            ((uint32_t)0u)
#define CSL_CGEM_L1DMPFAR_ADDR_MASK                             ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_L1DMPFAR_ADDR_RESETVAL                         ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFAR_ADDR_MAX                              ((uint32_t)0xffffffffu)

#define CSL_CGEM_L1DMPFAR_RESETVAL                              ((uint32_t)0x00000000u)

/* L1DMPFSR */

#define CSL_CGEM_L1DMPFSR_RESV_1_SHIFT                          ((uint32_t)16u)
#define CSL_CGEM_L1DMPFSR_RESV_1_MASK                           ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L1DMPFSR_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFSR_RESV_1_MAX                            ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1DMPFSR_FID_SHIFT                             ((uint32_t)9u)
#define CSL_CGEM_L1DMPFSR_FID_MASK                              ((uint32_t)0x0000FE00u)
#define CSL_CGEM_L1DMPFSR_FID_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFSR_FID_MAX                               ((uint32_t)0x0000007fu)

#define CSL_CGEM_L1DMPFSR_LOCAL_SHIFT                           ((uint32_t)8u)
#define CSL_CGEM_L1DMPFSR_LOCAL_MASK                            ((uint32_t)0x00000100u)
#define CSL_CGEM_L1DMPFSR_LOCAL_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFSR_LOCAL_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPFSR_NS_SHIFT                              ((uint32_t)7u)
#define CSL_CGEM_L1DMPFSR_NS_MASK                               ((uint32_t)0x00000080u)
#define CSL_CGEM_L1DMPFSR_NS_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFSR_NS_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPFSR_RESV_2_SHIFT                          ((uint32_t)6u)
#define CSL_CGEM_L1DMPFSR_RESV_2_MASK                           ((uint32_t)0x00000040u)
#define CSL_CGEM_L1DMPFSR_RESV_2_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFSR_RESV_2_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPFSR_SR_SHIFT                              ((uint32_t)5u)
#define CSL_CGEM_L1DMPFSR_SR_MASK                               ((uint32_t)0x00000020u)
#define CSL_CGEM_L1DMPFSR_SR_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFSR_SR_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPFSR_SW_SHIFT                              ((uint32_t)4u)
#define CSL_CGEM_L1DMPFSR_SW_MASK                               ((uint32_t)0x00000010u)
#define CSL_CGEM_L1DMPFSR_SW_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFSR_SW_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPFSR_SX_SHIFT                              ((uint32_t)3u)
#define CSL_CGEM_L1DMPFSR_SX_MASK                               ((uint32_t)0x00000008u)
#define CSL_CGEM_L1DMPFSR_SX_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFSR_SX_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPFSR_UR_SHIFT                              ((uint32_t)2u)
#define CSL_CGEM_L1DMPFSR_UR_MASK                               ((uint32_t)0x00000004u)
#define CSL_CGEM_L1DMPFSR_UR_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFSR_UR_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPFSR_UW_SHIFT                              ((uint32_t)1u)
#define CSL_CGEM_L1DMPFSR_UW_MASK                               ((uint32_t)0x00000002u)
#define CSL_CGEM_L1DMPFSR_UW_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFSR_UW_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPFSR_UX_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_L1DMPFSR_UX_MASK                               ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPFSR_UX_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFSR_UX_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPFSR_RESETVAL                              ((uint32_t)0x00000000u)

/* L1DMPFCR */

#define CSL_CGEM_L1DMPFCR_RESV_1_SHIFT                          ((uint32_t)1u)
#define CSL_CGEM_L1DMPFCR_RESV_1_MASK                           ((uint32_t)0xFFFFFFFEu)
#define CSL_CGEM_L1DMPFCR_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFCR_RESV_1_MAX                            ((uint32_t)0x7fffffffu)

#define CSL_CGEM_L1DMPFCR_MPFCLR_SHIFT                          ((uint32_t)0u)
#define CSL_CGEM_L1DMPFCR_MPFCLR_MASK                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPFCR_MPFCLR_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPFCR_MPFCLR_MAX                            ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPFCR_RESETVAL                              ((uint32_t)0x00000000u)

/* MPLK */

#define CSL_CGEM_MPLK_MPLK_SHIFT                                ((uint32_t)0u)
#define CSL_CGEM_MPLK_MPLK_MASK                                 ((uint32_t)0xFFFFFFFFu)
#define CSL_CGEM_MPLK_MPLK_RESETVAL                             ((uint32_t)0x00000000u)
#define CSL_CGEM_MPLK_MPLK_MAX                                  ((uint32_t)0xffffffffu)

#define CSL_CGEM_MPLK_RESETVAL                                  ((uint32_t)0x00000000u)

/* MPLKCMD */

#define CSL_CGEM_MPLKCMD_RESV_1_SHIFT                           ((uint32_t)3u)
#define CSL_CGEM_MPLKCMD_RESV_1_MASK                            ((uint32_t)0xFFFFFFF8u)
#define CSL_CGEM_MPLKCMD_RESV_1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_MPLKCMD_RESV_1_MAX                             ((uint32_t)0x1fffffffu)

#define CSL_CGEM_MPLKCMD_KEYR_SHIFT                             ((uint32_t)2u)
#define CSL_CGEM_MPLKCMD_KEYR_MASK                              ((uint32_t)0x00000004u)
#define CSL_CGEM_MPLKCMD_KEYR_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_MPLKCMD_KEYR_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_MPLKCMD_LOCK_SHIFT                             ((uint32_t)1u)
#define CSL_CGEM_MPLKCMD_LOCK_MASK                              ((uint32_t)0x00000002u)
#define CSL_CGEM_MPLKCMD_LOCK_RESETVAL                          ((uint32_t)0x00000000u)
#define CSL_CGEM_MPLKCMD_LOCK_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_MPLKCMD_UNLOCK_SHIFT                           ((uint32_t)0u)
#define CSL_CGEM_MPLKCMD_UNLOCK_MASK                            ((uint32_t)0x00000001u)
#define CSL_CGEM_MPLKCMD_UNLOCK_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_MPLKCMD_UNLOCK_MAX                             ((uint32_t)0x00000001u)

#define CSL_CGEM_MPLKCMD_RESETVAL                               ((uint32_t)0x00000000u)

/* MPLKSTAT */

#define CSL_CGEM_MPLKSTAT_RESV_1_SHIFT                          ((uint32_t)2u)
#define CSL_CGEM_MPLKSTAT_RESV_1_MASK                           ((uint32_t)0xFFFFFFFCu)
#define CSL_CGEM_MPLKSTAT_RESV_1_RESETVAL                       ((uint32_t)0x00000000u)
#define CSL_CGEM_MPLKSTAT_RESV_1_MAX                            ((uint32_t)0x3fffffffu)

#define CSL_CGEM_MPLKSTAT_NSL_SHIFT                             ((uint32_t)1u)
#define CSL_CGEM_MPLKSTAT_NSL_MASK                              ((uint32_t)0x00000002u)
#define CSL_CGEM_MPLKSTAT_NSL_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_MPLKSTAT_NSL_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_MPLKSTAT_LK_SHIFT                              ((uint32_t)0u)
#define CSL_CGEM_MPLKSTAT_LK_MASK                               ((uint32_t)0x00000001u)
#define CSL_CGEM_MPLKSTAT_LK_RESETVAL                           ((uint32_t)0x00000000u)
#define CSL_CGEM_MPLKSTAT_LK_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_MPLKSTAT_RESETVAL                              ((uint32_t)0x00000002u)

/* L1DMPPA */

#define CSL_CGEM_L1DMPPA_RESV_1_SHIFT                           ((uint32_t)16u)
#define CSL_CGEM_L1DMPPA_RESV_1_MASK                            ((uint32_t)0xFFFF0000u)
#define CSL_CGEM_L1DMPPA_RESV_1_RESETVAL                        ((uint32_t)0x00000000u)
#define CSL_CGEM_L1DMPPA_RESV_1_MAX                             ((uint32_t)0x0000ffffu)

#define CSL_CGEM_L1DMPPA_AID5_SHIFT                             ((uint32_t)15u)
#define CSL_CGEM_L1DMPPA_AID5_MASK                              ((uint32_t)0x00008000u)
#define CSL_CGEM_L1DMPPA_AID5_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_AID5_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_AID4_SHIFT                             ((uint32_t)14u)
#define CSL_CGEM_L1DMPPA_AID4_MASK                              ((uint32_t)0x00004000u)
#define CSL_CGEM_L1DMPPA_AID4_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_AID4_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_AID3_SHIFT                             ((uint32_t)13u)
#define CSL_CGEM_L1DMPPA_AID3_MASK                              ((uint32_t)0x00002000u)
#define CSL_CGEM_L1DMPPA_AID3_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_AID3_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_AID2_SHIFT                             ((uint32_t)12u)
#define CSL_CGEM_L1DMPPA_AID2_MASK                              ((uint32_t)0x00001000u)
#define CSL_CGEM_L1DMPPA_AID2_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_AID2_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_AID1_SHIFT                             ((uint32_t)11u)
#define CSL_CGEM_L1DMPPA_AID1_MASK                              ((uint32_t)0x00000800u)
#define CSL_CGEM_L1DMPPA_AID1_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_AID1_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_AID0_SHIFT                             ((uint32_t)10u)
#define CSL_CGEM_L1DMPPA_AID0_MASK                              ((uint32_t)0x00000400u)
#define CSL_CGEM_L1DMPPA_AID0_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_AID0_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_AIDX_SHIFT                             ((uint32_t)9u)
#define CSL_CGEM_L1DMPPA_AIDX_MASK                              ((uint32_t)0x00000200u)
#define CSL_CGEM_L1DMPPA_AIDX_RESETVAL                          ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_AIDX_MAX                               ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_LOCAL_SHIFT                            ((uint32_t)8u)
#define CSL_CGEM_L1DMPPA_LOCAL_MASK                             ((uint32_t)0x00000100u)
#define CSL_CGEM_L1DMPPA_LOCAL_RESETVAL                         ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_LOCAL_MAX                              ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_NS_SHIFT                               ((uint32_t)7u)
#define CSL_CGEM_L1DMPPA_NS_MASK                                ((uint32_t)0x00000080u)
#define CSL_CGEM_L1DMPPA_NS_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_NS_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_EMU_SHIFT                              ((uint32_t)6u)
#define CSL_CGEM_L1DMPPA_EMU_MASK                               ((uint32_t)0x00000040u)
#define CSL_CGEM_L1DMPPA_EMU_RESETVAL                           ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_EMU_MAX                                ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_SR_SHIFT                               ((uint32_t)5u)
#define CSL_CGEM_L1DMPPA_SR_MASK                                ((uint32_t)0x00000020u)
#define CSL_CGEM_L1DMPPA_SR_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_SR_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_SW_SHIFT                               ((uint32_t)4u)
#define CSL_CGEM_L1DMPPA_SW_MASK                                ((uint32_t)0x00000010u)
#define CSL_CGEM_L1DMPPA_SW_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_SW_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_SX_SHIFT                               ((uint32_t)3u)
#define CSL_CGEM_L1DMPPA_SX_MASK                                ((uint32_t)0x00000008u)
#define CSL_CGEM_L1DMPPA_SX_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_SX_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_UR_SHIFT                               ((uint32_t)2u)
#define CSL_CGEM_L1DMPPA_UR_MASK                                ((uint32_t)0x00000004u)
#define CSL_CGEM_L1DMPPA_UR_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_UR_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_UW_SHIFT                               ((uint32_t)1u)
#define CSL_CGEM_L1DMPPA_UW_MASK                                ((uint32_t)0x00000002u)
#define CSL_CGEM_L1DMPPA_UW_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_UW_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_UX_SHIFT                               ((uint32_t)0u)
#define CSL_CGEM_L1DMPPA_UX_MASK                                ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_UX_RESETVAL                            ((uint32_t)0x00000001u)
#define CSL_CGEM_L1DMPPA_UX_MAX                                 ((uint32_t)0x00000001u)

#define CSL_CGEM_L1DMPPA_RESETVAL                               ((uint32_t)0x0000ffffu)

#ifdef __cplusplus
}
#endif
#endif

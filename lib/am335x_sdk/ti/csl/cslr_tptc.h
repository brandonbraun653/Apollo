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
#ifndef CSLR_TPTC_H_
#define CSLR_TPTC_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for DstFifo
**************************************************************************/
typedef struct {
    volatile Uint32 TPTC_DFOPT;
    volatile Uint8  RSVD0[4];
    volatile Uint32 TPTC_DFCNT;
    volatile Uint32 TPTC_DFDST;
    volatile Uint32 TPTC_DFBIDX;
    volatile Uint32 TPTC_DFMPPRXY;
    volatile Uint8  RSVD1[40];
} CSL_TptcDstfifoRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 TPCC_PID;
    volatile Uint32 TPTC_TCCFG;
    volatile Uint8  RSVD0[244];
    volatile Uint32 TPTC_CLKGDIS;
    volatile Uint32 TPTC_STAT;
    volatile Uint32 TPTC_INTSTAT;
    volatile Uint32 TPTC_INTEN;
    volatile Uint32 TPTC_INTCLR;
    volatile Uint32 TPTC_INTCMD;
    volatile Uint8  RSVD1[12];
    volatile Uint32 TPTC_ERRSTAT;
    volatile Uint32 TPTC_ERREN;
    volatile Uint32 TPTC_ERRCLR;
    volatile Uint32 TPTC_ERRDET;
    volatile Uint32 TPTC_ERRCMD;
    volatile Uint8  RSVD2[12];
    volatile Uint32 TPTC_RDRATE;
    volatile Uint8  RSVD3[188];
    volatile Uint32 TPTC_POPT;
    volatile Uint32 TPTC_PSRC;
    volatile Uint32 TPTC_PCNT;
    volatile Uint32 TPTC_PDST;
    volatile Uint32 TPTC_PBIDX;
    volatile Uint32 TPTC_PMPPRXY;
    volatile Uint8  RSVD4[40];
    volatile Uint32 TPTC_SAOPT;
    volatile Uint32 TPTC_SASRC;
    volatile Uint32 TPTC_SACNT;
    volatile Uint8  RSVD5[4];
    volatile Uint32 TPTC_SABIDX;
    volatile Uint32 TPTC_SAMPPRXY;
    volatile Uint32 TPTC_SACNTRLD;
    volatile Uint32 TPTC_SASRCBREF;
    volatile Uint8  RSVD6[32];
    volatile Uint32 TPTC_DFCNTRLD;
    volatile Uint32 TPTC_DFSRCBREF;
    volatile Uint32 TPTC_DFDSTBREF;
    volatile Uint8  RSVD7[116];
    CSL_TptcDstfifoRegs	DSTFIFO[4];
} CSL_TptcRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* TPTC_DFOPT */
#define CSL_TPTC_TPTC_DFOPT(n)                                  (0x300U + ((n) * (0x40U)))

/* TPTC_DFCNT */
#define CSL_TPTC_TPTC_DFCNT(n)                                  (0x308U + ((n) * (0x40U)))

/* TPTC_DFDST */
#define CSL_TPTC_TPTC_DFDST(n)                                  (0x30CU + ((n) * (0x40U)))

/* TPTC_DFBIDX */
#define CSL_TPTC_TPTC_DFBIDX(n)                                 (0x310U + ((n) * (0x40U)))

/* TPTC_DFMPPRXY */
#define CSL_TPTC_TPTC_DFMPPRXY(n)                               (0x314U + ((n) * (0x40U)))

/* TPCC_PID */
#define CSL_TPTC_TPCC_PID                                       (0x0U)

/* TPTC_TCCFG */
#define CSL_TPTC_TPTC_TCCFG                                     (0x4U)

/* TPTC_CLKGDIS */
#define CSL_TPTC_TPTC_CLKGDIS                                   (0xFCU)

/* TPTC_STAT */
#define CSL_TPTC_TPTC_STAT                                      (0x100U)

/* TPTC_INTSTAT */
#define CSL_TPTC_TPTC_INTSTAT                                   (0x104U)

/* TPTC_INTEN */
#define CSL_TPTC_TPTC_INTEN                                     (0x108U)

/* TPTC_INTCLR */
#define CSL_TPTC_TPTC_INTCLR                                    (0x10CU)

/* TPTC_INTCMD */
#define CSL_TPTC_TPTC_INTCMD                                    (0x110U)

/* TPTC_ERRSTAT */
#define CSL_TPTC_TPTC_ERRSTAT                                   (0x120U)

/* TPTC_ERREN */
#define CSL_TPTC_TPTC_ERREN                                     (0x124U)

/* TPTC_ERRCLR */
#define CSL_TPTC_TPTC_ERRCLR                                    (0x128U)

/* TPTC_ERRDET */
#define CSL_TPTC_TPTC_ERRDET                                    (0x12CU)

/* TPTC_ERRCMD */
#define CSL_TPTC_TPTC_ERRCMD                                    (0x130U)

/* TPTC_RDRATE */
#define CSL_TPTC_TPTC_RDRATE                                    (0x140U)

/* TPTC_POPT */
#define CSL_TPTC_TPTC_POPT                                      (0x200U)

/* TPTC_PSRC */
#define CSL_TPTC_TPTC_PSRC                                      (0x204U)

/* TPTC_PCNT */
#define CSL_TPTC_TPTC_PCNT                                      (0x208U)

/* TPTC_PDST */
#define CSL_TPTC_TPTC_PDST                                      (0x20CU)

/* TPTC_PBIDX */
#define CSL_TPTC_TPTC_PBIDX                                     (0x210U)

/* TPTC_PMPPRXY */
#define CSL_TPTC_TPTC_PMPPRXY                                   (0x214U)

/* TPTC_SAOPT */
#define CSL_TPTC_TPTC_SAOPT                                     (0x240U)

/* TPTC_SASRC */
#define CSL_TPTC_TPTC_SASRC                                     (0x244U)

/* TPTC_SACNT */
#define CSL_TPTC_TPTC_SACNT                                     (0x248U)

/* TPTC_SABIDX */
#define CSL_TPTC_TPTC_SABIDX                                    (0x250U)

/* TPTC_SAMPPRXY */
#define CSL_TPTC_TPTC_SAMPPRXY                                  (0x254U)

/* TPTC_SACNTRLD */
#define CSL_TPTC_TPTC_SACNTRLD                                  (0x258U)

/* TPTC_SASRCBREF */
#define CSL_TPTC_TPTC_SASRCBREF                                 (0x25CU)

/* TPTC_DFCNTRLD */
#define CSL_TPTC_TPTC_DFCNTRLD                                  (0x280U)

/* TPTC_DFSRCBREF */
#define CSL_TPTC_TPTC_DFSRCBREF                                 (0x284U)

/* TPTC_DFDSTBREF */
#define CSL_TPTC_TPTC_DFDSTBREF                                 (0x288U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* TPTC_DFOPT */

#define CSL_TPTC_TPTC_DFOPT_SAM_MASK                            (0x00000001U)
#define CSL_TPTC_TPTC_DFOPT_SAM_SHIFT                           (0U)
#define CSL_TPTC_TPTC_DFOPT_SAM_RESETVAL                        (0x00000000U)
#define CSL_TPTC_TPTC_DFOPT_SAM_MAX                             (0x00000001U)

#define CSL_TPTC_TPTC_DFOPT_DAM_MASK                            (0x00000002U)
#define CSL_TPTC_TPTC_DFOPT_DAM_SHIFT                           (1U)
#define CSL_TPTC_TPTC_DFOPT_DAM_RESETVAL                        (0x00000000U)
#define CSL_TPTC_TPTC_DFOPT_DAM_MAX                             (0x00000001U)

#define CSL_TPTC_TPTC_DFOPT_PRIORITY_MASK                       (0x00000070U)
#define CSL_TPTC_TPTC_DFOPT_PRIORITY_SHIFT                      (4U)
#define CSL_TPTC_TPTC_DFOPT_PRIORITY_RESETVAL                   (0x00000000U)
#define CSL_TPTC_TPTC_DFOPT_PRIORITY_MAX                        (0x00000007U)

#define CSL_TPTC_TPTC_DFOPT_FWID_MASK                           (0x00000700U)
#define CSL_TPTC_TPTC_DFOPT_FWID_SHIFT                          (8U)
#define CSL_TPTC_TPTC_DFOPT_FWID_RESETVAL                       (0x00000000U)
#define CSL_TPTC_TPTC_DFOPT_FWID_MAX                            (0x00000007U)

#define CSL_TPTC_TPTC_DFOPT_TCC_MASK                            (0x0003F000U)
#define CSL_TPTC_TPTC_DFOPT_TCC_SHIFT                           (12U)
#define CSL_TPTC_TPTC_DFOPT_TCC_RESETVAL                        (0x00000000U)
#define CSL_TPTC_TPTC_DFOPT_TCC_MAX                             (0x0000003fU)

#define CSL_TPTC_TPTC_DFOPT_TCINTEN_MASK                        (0x00100000U)
#define CSL_TPTC_TPTC_DFOPT_TCINTEN_SHIFT                       (20U)
#define CSL_TPTC_TPTC_DFOPT_TCINTEN_RESETVAL                    (0x00000000U)
#define CSL_TPTC_TPTC_DFOPT_TCINTEN_MAX                         (0x00000001U)

#define CSL_TPTC_TPTC_DFOPT_TCCHEN_MASK                         (0x00400000U)
#define CSL_TPTC_TPTC_DFOPT_TCCHEN_SHIFT                        (22U)
#define CSL_TPTC_TPTC_DFOPT_TCCHEN_RESETVAL                     (0x00000000U)
#define CSL_TPTC_TPTC_DFOPT_TCCHEN_MAX                          (0x00000001U)

#define CSL_TPTC_TPTC_DFOPT_RESETVAL                            (0x00000000U)

/* TPTC_DFCNT */

#define CSL_TPTC_TPTC_DFCNT_ACNT_MASK                           (0x0000FFFFU)
#define CSL_TPTC_TPTC_DFCNT_ACNT_SHIFT                          (0U)
#define CSL_TPTC_TPTC_DFCNT_ACNT_RESETVAL                       (0x00000000U)
#define CSL_TPTC_TPTC_DFCNT_ACNT_MAX                            (0x0000ffffU)

#define CSL_TPTC_TPTC_DFCNT_BCNT_MASK                           (0xFFFF0000U)
#define CSL_TPTC_TPTC_DFCNT_BCNT_SHIFT                          (16U)
#define CSL_TPTC_TPTC_DFCNT_BCNT_RESETVAL                       (0x00000000U)
#define CSL_TPTC_TPTC_DFCNT_BCNT_MAX                            (0x0000ffffU)

#define CSL_TPTC_TPTC_DFCNT_RESETVAL                            (0x00000000U)

/* TPTC_DFDST */

#define CSL_TPTC_TPTC_DFDST_DADDR_MASK                          (0xFFFFFFFFU)
#define CSL_TPTC_TPTC_DFDST_DADDR_SHIFT                         (0U)
#define CSL_TPTC_TPTC_DFDST_DADDR_RESETVAL                      (0x00000000U)
#define CSL_TPTC_TPTC_DFDST_DADDR_MAX                           (0xffffffffU)

#define CSL_TPTC_TPTC_DFDST_RESETVAL                            (0x00000000U)

/* TPTC_DFBIDX */

#define CSL_TPTC_TPTC_DFBIDX_SBIDX_MASK                         (0x0000FFFFU)
#define CSL_TPTC_TPTC_DFBIDX_SBIDX_SHIFT                        (0U)
#define CSL_TPTC_TPTC_DFBIDX_SBIDX_RESETVAL                     (0x00000000U)
#define CSL_TPTC_TPTC_DFBIDX_SBIDX_MAX                          (0x0000ffffU)

#define CSL_TPTC_TPTC_DFBIDX_DBIDX_MASK                         (0xFFFF0000U)
#define CSL_TPTC_TPTC_DFBIDX_DBIDX_SHIFT                        (16U)
#define CSL_TPTC_TPTC_DFBIDX_DBIDX_RESETVAL                     (0x00000000U)
#define CSL_TPTC_TPTC_DFBIDX_DBIDX_MAX                          (0x0000ffffU)

#define CSL_TPTC_TPTC_DFBIDX_RESETVAL                           (0x00000000U)

/* TPTC_DFMPPRXY */

#define CSL_TPTC_TPTC_DFMPPRXY_PRIVID_MASK                      (0x0000000FU)
#define CSL_TPTC_TPTC_DFMPPRXY_PRIVID_SHIFT                     (0U)
#define CSL_TPTC_TPTC_DFMPPRXY_PRIVID_RESETVAL                  (0x00000000U)
#define CSL_TPTC_TPTC_DFMPPRXY_PRIVID_MAX                       (0x0000000fU)

#define CSL_TPTC_TPTC_DFMPPRXY_PRIV_MASK                        (0x00000100U)
#define CSL_TPTC_TPTC_DFMPPRXY_PRIV_SHIFT                       (8U)
#define CSL_TPTC_TPTC_DFMPPRXY_PRIV_RESETVAL                    (0x00000000U)
#define CSL_TPTC_TPTC_DFMPPRXY_PRIV_MAX                         (0x00000001U)

#define CSL_TPTC_TPTC_DFMPPRXY_SECURE_MASK                      (0x00000200U)
#define CSL_TPTC_TPTC_DFMPPRXY_SECURE_SHIFT                     (9U)
#define CSL_TPTC_TPTC_DFMPPRXY_SECURE_RESETVAL                  (0x00000000U)
#define CSL_TPTC_TPTC_DFMPPRXY_SECURE_MAX                       (0x00000001U)

#define CSL_TPTC_TPTC_DFMPPRXY_RESETVAL                         (0x00000000U)

/* TPCC_PID */

#define CSL_TPTC_TPCC_PID_SCHEME_MASK                           (0xC0000000U)
#define CSL_TPTC_TPCC_PID_SCHEME_SHIFT                          (30U)
#define CSL_TPTC_TPCC_PID_SCHEME_RESETVAL                       (0x00000001U)
#define CSL_TPTC_TPCC_PID_SCHEME_MAX                            (0x00000003U)

#define CSL_TPTC_TPCC_PID_FUNC_MASK                             (0x0FFF0000U)
#define CSL_TPTC_TPCC_PID_FUNC_SHIFT                            (16U)
#define CSL_TPTC_TPCC_PID_FUNC_RESETVAL                         (0x00000000U)
#define CSL_TPTC_TPCC_PID_FUNC_MAX                              (0x00000fffU)

#define CSL_TPTC_TPCC_PID_RESETVAL                              (0x40000000U)

/* TPTC_TCCFG */

#define CSL_TPTC_TPTC_TCCFG_FIFOSIZE_MASK                       (0x00000007U)
#define CSL_TPTC_TPTC_TCCFG_FIFOSIZE_SHIFT                      (0U)
#define CSL_TPTC_TPTC_TCCFG_FIFOSIZE_RESETVAL                   (0x00000005U)
#define CSL_TPTC_TPTC_TCCFG_FIFOSIZE_MAX                        (0x00000007U)

#define CSL_TPTC_TPTC_TCCFG_BUS_WIDTH_MASK                      (0x00000030U)
#define CSL_TPTC_TPTC_TCCFG_BUS_WIDTH_SHIFT                     (4U)
#define CSL_TPTC_TPTC_TCCFG_BUS_WIDTH_RESETVAL                  (0x00000003U)
#define CSL_TPTC_TPTC_TCCFG_BUS_WIDTH_MAX                       (0x00000003U)

#define CSL_TPTC_TPTC_TCCFG_DREGDEPTH_MASK                      (0x00000300U)
#define CSL_TPTC_TPTC_TCCFG_DREGDEPTH_SHIFT                     (8U)
#define CSL_TPTC_TPTC_TCCFG_DREGDEPTH_RESETVAL                  (0x00000002U)
#define CSL_TPTC_TPTC_TCCFG_DREGDEPTH_MAX                       (0x00000003U)

#define CSL_TPTC_TPTC_TCCFG_RESETVAL                            (0x00000235U)

/* TPTC_CLKGDIS */

#define CSL_TPTC_TPTC_CLKGDIS_CLKGDIS_MASK                      (0x00000001U)
#define CSL_TPTC_TPTC_CLKGDIS_CLKGDIS_SHIFT                     (0U)
#define CSL_TPTC_TPTC_CLKGDIS_CLKGDIS_RESETVAL                  (0x00000000U)
#define CSL_TPTC_TPTC_CLKGDIS_CLKGDIS_MAX                       (0x00000001U)

#define CSL_TPTC_TPTC_CLKGDIS_RESETVAL                          (0x00000000U)

/* TPTC_STAT */

#define CSL_TPTC_TPTC_STAT_PROGBUSY_MASK                        (0x00000001U)
#define CSL_TPTC_TPTC_STAT_PROGBUSY_SHIFT                       (0U)
#define CSL_TPTC_TPTC_STAT_PROGBUSY_RESETVAL                    (0x00000000U)
#define CSL_TPTC_TPTC_STAT_PROGBUSY_MAX                         (0x00000001U)

#define CSL_TPTC_TPTC_STAT_SRCACT_MASK                          (0x00000002U)
#define CSL_TPTC_TPTC_STAT_SRCACT_SHIFT                         (1U)
#define CSL_TPTC_TPTC_STAT_SRCACT_RESETVAL                      (0x00000000U)
#define CSL_TPTC_TPTC_STAT_SRCACT_MAX                           (0x00000001U)

#define CSL_TPTC_TPTC_STAT_WSACT_MASK                           (0x00000004U)
#define CSL_TPTC_TPTC_STAT_WSACT_SHIFT                          (2U)
#define CSL_TPTC_TPTC_STAT_WSACT_RESETVAL                       (0x00000000U)
#define CSL_TPTC_TPTC_STAT_WSACT_MAX                            (0x00000001U)

#define CSL_TPTC_TPTC_STAT_DSTACT_MASK                          (0x00000070U)
#define CSL_TPTC_TPTC_STAT_DSTACT_SHIFT                         (4U)
#define CSL_TPTC_TPTC_STAT_DSTACT_RESETVAL                      (0x00000000U)
#define CSL_TPTC_TPTC_STAT_DSTACT_MAX                           (0x00000007U)

#define CSL_TPTC_TPTC_STAT_ACT_MASK                             (0x00000100U)
#define CSL_TPTC_TPTC_STAT_ACT_SHIFT                            (8U)
#define CSL_TPTC_TPTC_STAT_ACT_RESETVAL                         (0x00000000U)
#define CSL_TPTC_TPTC_STAT_ACT_MAX                              (0x00000001U)

#define CSL_TPTC_TPTC_STAT_DFSTRTPTR_MASK                       (0x00003000U)
#define CSL_TPTC_TPTC_STAT_DFSTRTPTR_SHIFT                      (12U)
#define CSL_TPTC_TPTC_STAT_DFSTRTPTR_RESETVAL                   (0x00000000U)
#define CSL_TPTC_TPTC_STAT_DFSTRTPTR_MAX                        (0x00000003U)

#define CSL_TPTC_TPTC_STAT_RESETVAL                             (0x00000000U)

/* TPTC_INTSTAT */

#define CSL_TPTC_TPTC_INTSTAT_PROGEMPTY_MASK                    (0x00000001U)
#define CSL_TPTC_TPTC_INTSTAT_PROGEMPTY_SHIFT                   (0U)
#define CSL_TPTC_TPTC_INTSTAT_PROGEMPTY_RESETVAL                (0x00000000U)
#define CSL_TPTC_TPTC_INTSTAT_PROGEMPTY_MAX                     (0x00000001U)

#define CSL_TPTC_TPTC_INTSTAT_TRDONE_MASK                       (0x00000002U)
#define CSL_TPTC_TPTC_INTSTAT_TRDONE_SHIFT                      (1U)
#define CSL_TPTC_TPTC_INTSTAT_TRDONE_RESETVAL                   (0x00000000U)
#define CSL_TPTC_TPTC_INTSTAT_TRDONE_MAX                        (0x00000001U)

#define CSL_TPTC_TPTC_INTSTAT_RESETVAL                          (0x00000000U)

/* TPTC_INTEN */

#define CSL_TPTC_TPTC_INTEN_PROGEMPTY_MASK                      (0x00000001U)
#define CSL_TPTC_TPTC_INTEN_PROGEMPTY_SHIFT                     (0U)
#define CSL_TPTC_TPTC_INTEN_PROGEMPTY_RESETVAL                  (0x00000000U)
#define CSL_TPTC_TPTC_INTEN_PROGEMPTY_MAX                       (0x00000001U)

#define CSL_TPTC_TPTC_INTEN_TRDONE_MASK                         (0x00000002U)
#define CSL_TPTC_TPTC_INTEN_TRDONE_SHIFT                        (1U)
#define CSL_TPTC_TPTC_INTEN_TRDONE_RESETVAL                     (0x00000000U)
#define CSL_TPTC_TPTC_INTEN_TRDONE_MAX                          (0x00000001U)

#define CSL_TPTC_TPTC_INTEN_RESETVAL                            (0x00000000U)

/* TPTC_INTCLR */

#define CSL_TPTC_TPTC_INTCLR_PROGEMPTY_MASK                     (0x00000001U)
#define CSL_TPTC_TPTC_INTCLR_PROGEMPTY_SHIFT                    (0U)
#define CSL_TPTC_TPTC_INTCLR_PROGEMPTY_RESETVAL                 (0x00000000U)
#define CSL_TPTC_TPTC_INTCLR_PROGEMPTY_MAX                      (0x00000001U)

#define CSL_TPTC_TPTC_INTCLR_TRDONE_MASK                        (0x00000002U)
#define CSL_TPTC_TPTC_INTCLR_TRDONE_SHIFT                       (1U)
#define CSL_TPTC_TPTC_INTCLR_TRDONE_RESETVAL                    (0x00000000U)
#define CSL_TPTC_TPTC_INTCLR_TRDONE_MAX                         (0x00000001U)

#define CSL_TPTC_TPTC_INTCLR_RESETVAL                           (0x00000000U)

/* TPTC_INTCMD */

#define CSL_TPTC_TPTC_INTCMD_EVAL_MASK                          (0x00000001U)
#define CSL_TPTC_TPTC_INTCMD_EVAL_SHIFT                         (0U)
#define CSL_TPTC_TPTC_INTCMD_EVAL_RESETVAL                      (0x00000000U)
#define CSL_TPTC_TPTC_INTCMD_EVAL_MAX                           (0x00000001U)

#define CSL_TPTC_TPTC_INTCMD_SET_MASK                           (0x00000002U)
#define CSL_TPTC_TPTC_INTCMD_SET_SHIFT                          (1U)
#define CSL_TPTC_TPTC_INTCMD_SET_RESETVAL                       (0x00000000U)
#define CSL_TPTC_TPTC_INTCMD_SET_MAX                            (0x00000001U)

#define CSL_TPTC_TPTC_INTCMD_RESETVAL                           (0x00000000U)

/* TPTC_ERRSTAT */

#define CSL_TPTC_TPTC_ERRSTAT_BUSERR_MASK                       (0x00000001U)
#define CSL_TPTC_TPTC_ERRSTAT_BUSERR_SHIFT                      (0U)
#define CSL_TPTC_TPTC_ERRSTAT_BUSERR_RESETVAL                   (0x00000000U)
#define CSL_TPTC_TPTC_ERRSTAT_BUSERR_MAX                        (0x00000001U)

#define CSL_TPTC_TPTC_ERRSTAT_TRERR_MASK                        (0x00000002U)
#define CSL_TPTC_TPTC_ERRSTAT_TRERR_SHIFT                       (1U)
#define CSL_TPTC_TPTC_ERRSTAT_TRERR_RESETVAL                    (0x00000000U)
#define CSL_TPTC_TPTC_ERRSTAT_TRERR_MAX                         (0x00000001U)

#define CSL_TPTC_TPTC_ERRSTAT_MMRAERR_MASK                      (0x00000008U)
#define CSL_TPTC_TPTC_ERRSTAT_MMRAERR_SHIFT                     (3U)
#define CSL_TPTC_TPTC_ERRSTAT_MMRAERR_RESETVAL                  (0x00000000U)
#define CSL_TPTC_TPTC_ERRSTAT_MMRAERR_MAX                       (0x00000001U)

#define CSL_TPTC_TPTC_ERRSTAT_RESETVAL                          (0x00000000U)

/* TPTC_ERREN */

#define CSL_TPTC_TPTC_ERREN_BUSERR_MASK                         (0x00000001U)
#define CSL_TPTC_TPTC_ERREN_BUSERR_SHIFT                        (0U)
#define CSL_TPTC_TPTC_ERREN_BUSERR_RESETVAL                     (0x00000000U)
#define CSL_TPTC_TPTC_ERREN_BUSERR_MAX                          (0x00000001U)

#define CSL_TPTC_TPTC_ERREN_TRERR_MASK                          (0x00000002U)
#define CSL_TPTC_TPTC_ERREN_TRERR_SHIFT                         (1U)
#define CSL_TPTC_TPTC_ERREN_TRERR_RESETVAL                      (0x00000000U)
#define CSL_TPTC_TPTC_ERREN_TRERR_MAX                           (0x00000001U)

#define CSL_TPTC_TPTC_ERREN_MMRAERR_MASK                        (0x00000008U)
#define CSL_TPTC_TPTC_ERREN_MMRAERR_SHIFT                       (3U)
#define CSL_TPTC_TPTC_ERREN_MMRAERR_RESETVAL                    (0x00000000U)
#define CSL_TPTC_TPTC_ERREN_MMRAERR_MAX                         (0x00000001U)

#define CSL_TPTC_TPTC_ERREN_RESETVAL                            (0x00000000U)

/* TPTC_ERRCLR */

#define CSL_TPTC_TPTC_ERRCLR_BUSERR_MASK                        (0x00000001U)
#define CSL_TPTC_TPTC_ERRCLR_BUSERR_SHIFT                       (0U)
#define CSL_TPTC_TPTC_ERRCLR_BUSERR_RESETVAL                    (0x00000000U)
#define CSL_TPTC_TPTC_ERRCLR_BUSERR_MAX                         (0x00000001U)

#define CSL_TPTC_TPTC_ERRCLR_TRERR_MASK                         (0x00000002U)
#define CSL_TPTC_TPTC_ERRCLR_TRERR_SHIFT                        (1U)
#define CSL_TPTC_TPTC_ERRCLR_TRERR_RESETVAL                     (0x00000000U)
#define CSL_TPTC_TPTC_ERRCLR_TRERR_MAX                          (0x00000001U)

#define CSL_TPTC_TPTC_ERRCLR_MMRAERR_MASK                       (0x00000008U)
#define CSL_TPTC_TPTC_ERRCLR_MMRAERR_SHIFT                      (3U)
#define CSL_TPTC_TPTC_ERRCLR_MMRAERR_RESETVAL                   (0x00000000U)
#define CSL_TPTC_TPTC_ERRCLR_MMRAERR_MAX                        (0x00000001U)

#define CSL_TPTC_TPTC_ERRCLR_RESETVAL                           (0x00000000U)

/* TPTC_ERRDET */

#define CSL_TPTC_TPTC_ERRDET_STAT_MASK                          (0x0000000FU)
#define CSL_TPTC_TPTC_ERRDET_STAT_SHIFT                         (0U)
#define CSL_TPTC_TPTC_ERRDET_STAT_RESETVAL                      (0x00000000U)
#define CSL_TPTC_TPTC_ERRDET_STAT_MAX                           (0x0000000fU)

#define CSL_TPTC_TPTC_ERRDET_TCC_MASK                           (0x00003F00U)
#define CSL_TPTC_TPTC_ERRDET_TCC_SHIFT                          (8U)
#define CSL_TPTC_TPTC_ERRDET_TCC_RESETVAL                       (0x00000000U)
#define CSL_TPTC_TPTC_ERRDET_TCC_MAX                            (0x0000003fU)

#define CSL_TPTC_TPTC_ERRDET_TCINTEN_MASK                       (0x00010000U)
#define CSL_TPTC_TPTC_ERRDET_TCINTEN_SHIFT                      (16U)
#define CSL_TPTC_TPTC_ERRDET_TCINTEN_RESETVAL                   (0x00000000U)
#define CSL_TPTC_TPTC_ERRDET_TCINTEN_MAX                        (0x00000001U)

#define CSL_TPTC_TPTC_ERRDET_TCCHEN_MASK                        (0x00020000U)
#define CSL_TPTC_TPTC_ERRDET_TCCHEN_SHIFT                       (17U)
#define CSL_TPTC_TPTC_ERRDET_TCCHEN_RESETVAL                    (0x00000000U)
#define CSL_TPTC_TPTC_ERRDET_TCCHEN_MAX                         (0x00000001U)

#define CSL_TPTC_TPTC_ERRDET_RESETVAL                           (0x00000000U)

/* TPTC_ERRCMD */

#define CSL_TPTC_TPTC_ERRCMD_EVAL_MASK                          (0x00000001U)
#define CSL_TPTC_TPTC_ERRCMD_EVAL_SHIFT                         (0U)
#define CSL_TPTC_TPTC_ERRCMD_EVAL_RESETVAL                      (0x00000000U)
#define CSL_TPTC_TPTC_ERRCMD_EVAL_MAX                           (0x00000001U)

#define CSL_TPTC_TPTC_ERRCMD_SET_MASK                           (0x00000002U)
#define CSL_TPTC_TPTC_ERRCMD_SET_SHIFT                          (1U)
#define CSL_TPTC_TPTC_ERRCMD_SET_RESETVAL                       (0x00000000U)
#define CSL_TPTC_TPTC_ERRCMD_SET_MAX                            (0x00000001U)

#define CSL_TPTC_TPTC_ERRCMD_RESETVAL                           (0x00000000U)

/* TPTC_RDRATE */

#define CSL_TPTC_TPTC_RDRATE_RDRATE_MASK                        (0x00000003U)
#define CSL_TPTC_TPTC_RDRATE_RDRATE_SHIFT                       (0U)
#define CSL_TPTC_TPTC_RDRATE_RDRATE_RESETVAL                    (0x00000000U)
#define CSL_TPTC_TPTC_RDRATE_RDRATE_MAX                         (0x00000003U)

#define CSL_TPTC_TPTC_RDRATE_RESETVAL                           (0x00000000U)

/* TPTC_POPT */

#define CSL_TPTC_TPTC_POPT_SAM_MASK                             (0x00000001U)
#define CSL_TPTC_TPTC_POPT_SAM_SHIFT                            (0U)
#define CSL_TPTC_TPTC_POPT_SAM_RESETVAL                         (0x00000000U)
#define CSL_TPTC_TPTC_POPT_SAM_MAX                              (0x00000001U)

#define CSL_TPTC_TPTC_POPT_DAM_MASK                             (0x00000002U)
#define CSL_TPTC_TPTC_POPT_DAM_SHIFT                            (1U)
#define CSL_TPTC_TPTC_POPT_DAM_RESETVAL                         (0x00000000U)
#define CSL_TPTC_TPTC_POPT_DAM_MAX                              (0x00000001U)

#define CSL_TPTC_TPTC_POPT_PRIORITY_MASK                        (0x00000070U)
#define CSL_TPTC_TPTC_POPT_PRIORITY_SHIFT                       (4U)
#define CSL_TPTC_TPTC_POPT_PRIORITY_RESETVAL                    (0x00000000U)
#define CSL_TPTC_TPTC_POPT_PRIORITY_MAX                         (0x00000007U)

#define CSL_TPTC_TPTC_POPT_FWID_MASK                            (0x00000700U)
#define CSL_TPTC_TPTC_POPT_FWID_SHIFT                           (8U)
#define CSL_TPTC_TPTC_POPT_FWID_RESETVAL                        (0x00000000U)
#define CSL_TPTC_TPTC_POPT_FWID_MAX                             (0x00000007U)

#define CSL_TPTC_TPTC_POPT_TCC_MASK                             (0x0003F000U)
#define CSL_TPTC_TPTC_POPT_TCC_SHIFT                            (12U)
#define CSL_TPTC_TPTC_POPT_TCC_RESETVAL                         (0x00000000U)
#define CSL_TPTC_TPTC_POPT_TCC_MAX                              (0x0000003fU)

#define CSL_TPTC_TPTC_POPT_TCINTEN_MASK                         (0x00100000U)
#define CSL_TPTC_TPTC_POPT_TCINTEN_SHIFT                        (20U)
#define CSL_TPTC_TPTC_POPT_TCINTEN_RESETVAL                     (0x00000000U)
#define CSL_TPTC_TPTC_POPT_TCINTEN_MAX                          (0x00000001U)

#define CSL_TPTC_TPTC_POPT_TCCHEN_MASK                          (0x00400000U)
#define CSL_TPTC_TPTC_POPT_TCCHEN_SHIFT                         (22U)
#define CSL_TPTC_TPTC_POPT_TCCHEN_RESETVAL                      (0x00000000U)
#define CSL_TPTC_TPTC_POPT_TCCHEN_MAX                           (0x00000001U)

#define CSL_TPTC_TPTC_POPT_RESETVAL                             (0x00000000U)

/* TPTC_PSRC */

#define CSL_TPTC_TPTC_PSRC_SADDR_MASK                           (0xFFFFFFFFU)
#define CSL_TPTC_TPTC_PSRC_SADDR_SHIFT                          (0U)
#define CSL_TPTC_TPTC_PSRC_SADDR_RESETVAL                       (0x00000000U)
#define CSL_TPTC_TPTC_PSRC_SADDR_MAX                            (0xffffffffU)

#define CSL_TPTC_TPTC_PSRC_RESETVAL                             (0x00000000U)

/* TPTC_PCNT */

#define CSL_TPTC_TPTC_PCNT_ACNT_MASK                            (0x0000FFFFU)
#define CSL_TPTC_TPTC_PCNT_ACNT_SHIFT                           (0U)
#define CSL_TPTC_TPTC_PCNT_ACNT_RESETVAL                        (0x00000000U)
#define CSL_TPTC_TPTC_PCNT_ACNT_MAX                             (0x0000ffffU)

#define CSL_TPTC_TPTC_PCNT_BCNT_MASK                            (0xFFFF0000U)
#define CSL_TPTC_TPTC_PCNT_BCNT_SHIFT                           (16U)
#define CSL_TPTC_TPTC_PCNT_BCNT_RESETVAL                        (0x00000000U)
#define CSL_TPTC_TPTC_PCNT_BCNT_MAX                             (0x0000ffffU)

#define CSL_TPTC_TPTC_PCNT_RESETVAL                             (0x00000000U)

/* TPTC_PDST */

#define CSL_TPTC_TPTC_PDST_DADDR_MASK                           (0xFFFFFFFFU)
#define CSL_TPTC_TPTC_PDST_DADDR_SHIFT                          (0U)
#define CSL_TPTC_TPTC_PDST_DADDR_RESETVAL                       (0x00000000U)
#define CSL_TPTC_TPTC_PDST_DADDR_MAX                            (0xffffffffU)

#define CSL_TPTC_TPTC_PDST_RESETVAL                             (0x00000000U)

/* TPTC_PBIDX */

#define CSL_TPTC_TPTC_PBIDX_SBIDX_MASK                          (0x0000FFFFU)
#define CSL_TPTC_TPTC_PBIDX_SBIDX_SHIFT                         (0U)
#define CSL_TPTC_TPTC_PBIDX_SBIDX_RESETVAL                      (0x00000000U)
#define CSL_TPTC_TPTC_PBIDX_SBIDX_MAX                           (0x0000ffffU)

#define CSL_TPTC_TPTC_PBIDX_DBIDX_MASK                          (0xFFFF0000U)
#define CSL_TPTC_TPTC_PBIDX_DBIDX_SHIFT                         (16U)
#define CSL_TPTC_TPTC_PBIDX_DBIDX_RESETVAL                      (0x00000000U)
#define CSL_TPTC_TPTC_PBIDX_DBIDX_MAX                           (0x0000ffffU)

#define CSL_TPTC_TPTC_PBIDX_RESETVAL                            (0x00000000U)

/* TPTC_PMPPRXY */

#define CSL_TPTC_TPTC_PMPPRXY_PRIVID_MASK                       (0x0000000FU)
#define CSL_TPTC_TPTC_PMPPRXY_PRIVID_SHIFT                      (0U)
#define CSL_TPTC_TPTC_PMPPRXY_PRIVID_RESETVAL                   (0x00000000U)
#define CSL_TPTC_TPTC_PMPPRXY_PRIVID_MAX                        (0x0000000fU)

#define CSL_TPTC_TPTC_PMPPRXY_PRIV_MASK                         (0x00000100U)
#define CSL_TPTC_TPTC_PMPPRXY_PRIV_SHIFT                        (8U)
#define CSL_TPTC_TPTC_PMPPRXY_PRIV_RESETVAL                     (0x00000000U)
#define CSL_TPTC_TPTC_PMPPRXY_PRIV_MAX                          (0x00000001U)

#define CSL_TPTC_TPTC_PMPPRXY_SECURE_MASK                       (0x00000200U)
#define CSL_TPTC_TPTC_PMPPRXY_SECURE_SHIFT                      (9U)
#define CSL_TPTC_TPTC_PMPPRXY_SECURE_RESETVAL                   (0x00000000U)
#define CSL_TPTC_TPTC_PMPPRXY_SECURE_MAX                        (0x00000001U)

#define CSL_TPTC_TPTC_PMPPRXY_RESETVAL                          (0x00000000U)

/* TPTC_SAOPT */

#define CSL_TPTC_TPTC_SAOPT_SAM_MASK                            (0x00000001U)
#define CSL_TPTC_TPTC_SAOPT_SAM_SHIFT                           (0U)
#define CSL_TPTC_TPTC_SAOPT_SAM_RESETVAL                        (0x00000000U)
#define CSL_TPTC_TPTC_SAOPT_SAM_MAX                             (0x00000001U)

#define CSL_TPTC_TPTC_SAOPT_DAM_MASK                            (0x00000002U)
#define CSL_TPTC_TPTC_SAOPT_DAM_SHIFT                           (1U)
#define CSL_TPTC_TPTC_SAOPT_DAM_RESETVAL                        (0x00000000U)
#define CSL_TPTC_TPTC_SAOPT_DAM_MAX                             (0x00000001U)

#define CSL_TPTC_TPTC_SAOPT_PRIORITY_MASK                       (0x00000070U)
#define CSL_TPTC_TPTC_SAOPT_PRIORITY_SHIFT                      (4U)
#define CSL_TPTC_TPTC_SAOPT_PRIORITY_RESETVAL                   (0x00000000U)
#define CSL_TPTC_TPTC_SAOPT_PRIORITY_MAX                        (0x00000007U)

#define CSL_TPTC_TPTC_SAOPT_FWID_MASK                           (0x00000700U)
#define CSL_TPTC_TPTC_SAOPT_FWID_SHIFT                          (8U)
#define CSL_TPTC_TPTC_SAOPT_FWID_RESETVAL                       (0x00000000U)
#define CSL_TPTC_TPTC_SAOPT_FWID_MAX                            (0x00000007U)

#define CSL_TPTC_TPTC_SAOPT_TCC_MASK                            (0x0003F000U)
#define CSL_TPTC_TPTC_SAOPT_TCC_SHIFT                           (12U)
#define CSL_TPTC_TPTC_SAOPT_TCC_RESETVAL                        (0x00000000U)
#define CSL_TPTC_TPTC_SAOPT_TCC_MAX                             (0x0000003fU)

#define CSL_TPTC_TPTC_SAOPT_TCINTEN_MASK                        (0x00100000U)
#define CSL_TPTC_TPTC_SAOPT_TCINTEN_SHIFT                       (20U)
#define CSL_TPTC_TPTC_SAOPT_TCINTEN_RESETVAL                    (0x00000000U)
#define CSL_TPTC_TPTC_SAOPT_TCINTEN_MAX                         (0x00000001U)

#define CSL_TPTC_TPTC_SAOPT_TCCHEN_MASK                         (0x00400000U)
#define CSL_TPTC_TPTC_SAOPT_TCCHEN_SHIFT                        (22U)
#define CSL_TPTC_TPTC_SAOPT_TCCHEN_RESETVAL                     (0x00000000U)
#define CSL_TPTC_TPTC_SAOPT_TCCHEN_MAX                          (0x00000001U)

#define CSL_TPTC_TPTC_SAOPT_RESETVAL                            (0x00000000U)

/* TPTC_SASRC */

#define CSL_TPTC_TPTC_SASRC_SADDR_MASK                          (0xFFFFFFFFU)
#define CSL_TPTC_TPTC_SASRC_SADDR_SHIFT                         (0U)
#define CSL_TPTC_TPTC_SASRC_SADDR_RESETVAL                      (0x00000000U)
#define CSL_TPTC_TPTC_SASRC_SADDR_MAX                           (0xffffffffU)

#define CSL_TPTC_TPTC_SASRC_RESETVAL                            (0x00000000U)

/* TPTC_SACNT */

#define CSL_TPTC_TPTC_SACNT_ACNT_MASK                           (0x0000FFFFU)
#define CSL_TPTC_TPTC_SACNT_ACNT_SHIFT                          (0U)
#define CSL_TPTC_TPTC_SACNT_ACNT_RESETVAL                       (0x00000000U)
#define CSL_TPTC_TPTC_SACNT_ACNT_MAX                            (0x0000ffffU)

#define CSL_TPTC_TPTC_SACNT_BCNT_MASK                           (0xFFFF0000U)
#define CSL_TPTC_TPTC_SACNT_BCNT_SHIFT                          (16U)
#define CSL_TPTC_TPTC_SACNT_BCNT_RESETVAL                       (0x00000000U)
#define CSL_TPTC_TPTC_SACNT_BCNT_MAX                            (0x0000ffffU)

#define CSL_TPTC_TPTC_SACNT_RESETVAL                            (0x00000000U)

/* TPTC_SABIDX */

#define CSL_TPTC_TPTC_SABIDX_SBIDX_MASK                         (0x0000FFFFU)
#define CSL_TPTC_TPTC_SABIDX_SBIDX_SHIFT                        (0U)
#define CSL_TPTC_TPTC_SABIDX_SBIDX_RESETVAL                     (0x00000000U)
#define CSL_TPTC_TPTC_SABIDX_SBIDX_MAX                          (0x0000ffffU)

#define CSL_TPTC_TPTC_SABIDX_DBIDX_MASK                         (0xFFFF0000U)
#define CSL_TPTC_TPTC_SABIDX_DBIDX_SHIFT                        (16U)
#define CSL_TPTC_TPTC_SABIDX_DBIDX_RESETVAL                     (0x00000000U)
#define CSL_TPTC_TPTC_SABIDX_DBIDX_MAX                          (0x0000ffffU)

#define CSL_TPTC_TPTC_SABIDX_RESETVAL                           (0x00000000U)

/* TPTC_SAMPPRXY */

#define CSL_TPTC_TPTC_SAMPPRXY_PRIVID_MASK                      (0x0000000FU)
#define CSL_TPTC_TPTC_SAMPPRXY_PRIVID_SHIFT                     (0U)
#define CSL_TPTC_TPTC_SAMPPRXY_PRIVID_RESETVAL                  (0x00000000U)
#define CSL_TPTC_TPTC_SAMPPRXY_PRIVID_MAX                       (0x0000000fU)

#define CSL_TPTC_TPTC_SAMPPRXY_PRIV_MASK                        (0x00000100U)
#define CSL_TPTC_TPTC_SAMPPRXY_PRIV_SHIFT                       (8U)
#define CSL_TPTC_TPTC_SAMPPRXY_PRIV_RESETVAL                    (0x00000000U)
#define CSL_TPTC_TPTC_SAMPPRXY_PRIV_MAX                         (0x00000001U)

#define CSL_TPTC_TPTC_SAMPPRXY_SECURE_MASK                      (0x00000200U)
#define CSL_TPTC_TPTC_SAMPPRXY_SECURE_SHIFT                     (9U)
#define CSL_TPTC_TPTC_SAMPPRXY_SECURE_RESETVAL                  (0x00000000U)
#define CSL_TPTC_TPTC_SAMPPRXY_SECURE_MAX                       (0x00000001U)

#define CSL_TPTC_TPTC_SAMPPRXY_RESETVAL                         (0x00000000U)

/* TPTC_SACNTRLD */

#define CSL_TPTC_TPTC_SACNTRLD_ACNTRLD_MASK                     (0x0000FFFFU)
#define CSL_TPTC_TPTC_SACNTRLD_ACNTRLD_SHIFT                    (0U)
#define CSL_TPTC_TPTC_SACNTRLD_ACNTRLD_RESETVAL                 (0x00000000U)
#define CSL_TPTC_TPTC_SACNTRLD_ACNTRLD_MAX                      (0x0000ffffU)

#define CSL_TPTC_TPTC_SACNTRLD_RESETVAL                         (0x00000000U)

/* TPTC_SASRCBREF */

#define CSL_TPTC_TPTC_SASRCBREF_SADDRBREF_MASK                  (0xFFFFFFFFU)
#define CSL_TPTC_TPTC_SASRCBREF_SADDRBREF_SHIFT                 (0U)
#define CSL_TPTC_TPTC_SASRCBREF_SADDRBREF_RESETVAL              (0x00000000U)
#define CSL_TPTC_TPTC_SASRCBREF_SADDRBREF_MAX                   (0xffffffffU)

#define CSL_TPTC_TPTC_SASRCBREF_RESETVAL                        (0x00000000U)

/* TPTC_DFCNTRLD */

#define CSL_TPTC_TPTC_DFCNTRLD_ACNTRLD_MASK                     (0x0000FFFFU)
#define CSL_TPTC_TPTC_DFCNTRLD_ACNTRLD_SHIFT                    (0U)
#define CSL_TPTC_TPTC_DFCNTRLD_ACNTRLD_RESETVAL                 (0x00000000U)
#define CSL_TPTC_TPTC_DFCNTRLD_ACNTRLD_MAX                      (0x0000ffffU)

#define CSL_TPTC_TPTC_DFCNTRLD_RESETVAL                         (0x00000000U)

/* TPTC_DFSRCBREF */

#define CSL_TPTC_TPTC_DFSRCBREF_SADDRBREF_MASK                  (0xFFFFFFFFU)
#define CSL_TPTC_TPTC_DFSRCBREF_SADDRBREF_SHIFT                 (0U)
#define CSL_TPTC_TPTC_DFSRCBREF_SADDRBREF_RESETVAL              (0x00000000U)
#define CSL_TPTC_TPTC_DFSRCBREF_SADDRBREF_MAX                   (0xffffffffU)

#define CSL_TPTC_TPTC_DFSRCBREF_RESETVAL                        (0x00000000U)

/* TPTC_DFDSTBREF */

#define CSL_TPTC_TPTC_DFDSTBREF_DADDRBREF_MASK                  (0xFFFFFFFFU)
#define CSL_TPTC_TPTC_DFDSTBREF_DADDRBREF_SHIFT                 (0U)
#define CSL_TPTC_TPTC_DFDSTBREF_DADDRBREF_RESETVAL              (0x00000000U)
#define CSL_TPTC_TPTC_DFDSTBREF_DADDRBREF_MAX                   (0xffffffffU)

#define CSL_TPTC_TPTC_DFDSTBREF_RESETVAL                        (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif

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
#ifndef CSLR_SRSS_H_
#define CSLR_SRSS_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for TOP_LEVEL
**************************************************************************/
typedef struct {
    volatile Uint32 PID_REG;
    volatile Uint32 INTR_EN_SET_REG;
    volatile Uint32 EVT_FLAG_REG;
    volatile Uint32 EVT_CLR_REG;
    volatile Uint32 TIMER_CTL_REG;
    volatile Uint32 TIMER_LD_REG;
    volatile Uint32 TIMER_VAL_REG;
    volatile Uint32 TEMP_CTL0_REG;
    volatile Uint32 TEMP_CTL1_REG;
    volatile Uint32 TEMP_CTL2_REG;
    volatile Uint32 TEMP_STAT0_REG;
    volatile Uint32 TEMP_STAT1_REG;
    volatile Uint32 SRSEN_CTL0_REG;
    volatile Uint32 SRSEN_CTL1_REG;
    volatile Uint32 SRSEN_CTL2_REG;
    volatile Uint32 SRSEN_STAT0_REG;
    volatile Uint32 MISC_CTL0_REG;
    volatile Uint32 MISC_CTL1_REG;
    volatile Uint32 MISC_STAT0_REG;
    volatile Uint8  RSVD0[52];
    volatile Uint32 VPRM_CTRL0_REG;
    volatile Uint32 VPRM_CTRL1_REG;
    volatile Uint32 VPRM_STS0_REG;
    volatile Uint32 VPRM_STS1_REG;
    volatile Uint8  RSVD1[112];
    volatile Uint32 SRCTL0_SRCONFIG;
    volatile Uint32 SRCTL0_SRSTS;
    volatile Uint32 SRCTL0_SENVAL;
    volatile Uint32 SRCTL0_SENMIN;
    volatile Uint32 SRCTL0_SENMAX;
    volatile Uint32 SRCTL0_SENAVG;
    volatile Uint32 SRCTL0_AVGWEIGHT;
    volatile Uint32 SRCTL0_NVALUERECIPROCAL;
    volatile Uint32 SRCTL0_IRQ_EOI;
    volatile Uint32 SRCTL0_IRQSTS_RAW;
    volatile Uint32 SRCTL0_IRQSTS;
    volatile Uint32 SRCTL0_IRQEN_SET;
    volatile Uint32 SRCTL0_IRQEN_CLR;
    volatile Uint32 SRCTL0_SENERROR;
    volatile Uint32 SRCTL0_ERRCONFIG;
    volatile Uint8  RSVD2[196];
    volatile Uint32 SRCTL2_SRCONFIG;
    volatile Uint32 SRCTL2_SRSTS;
    volatile Uint32 SRCTL2_SENVAL;
    volatile Uint32 SRCTL2_SENMIN;
    volatile Uint32 SRCTL2_SENMAX;
    volatile Uint32 SRCTL2_SENAVG;
    volatile Uint32 SRCTL2_AVGWEIGHT;
    volatile Uint32 SRCTL2_NVALUERECIPROCAL;
    volatile Uint32 SRCTL2_IRQ_EOI;
    volatile Uint32 SRCTL2_IRQSTS_RAW;
    volatile Uint32 SRCTL2_IRQSTS;
    volatile Uint32 SRCTL2_IRQEN_SET;
    volatile Uint32 SRCTL2_IRQEN_CLR;
    volatile Uint32 SRCTL2_SENERROR;
    volatile Uint32 SRCTL2_ERRCONFIG;
    volatile Uint8  RSVD3[68];
    volatile Uint32 SRCTL1_SRCONFIG;
    volatile Uint32 SRCTL1_SRSTS;
    volatile Uint32 SRCTL1_SENVAL;
    volatile Uint32 SRCTL1_SENMIN;
    volatile Uint32 SRCTL1_SENMAX;
    volatile Uint32 SRCTL1_SENAVG;
    volatile Uint32 SRCTL1_AVGWEIGHT;
    volatile Uint32 SRCTL1_NVALUERECIPROCAL;
    volatile Uint32 SRCTL1_IRQ_EOI;
    volatile Uint32 SRCTL1_IRQSTS_RAW;
    volatile Uint32 SRCTL1_IRQSTS;
    volatile Uint32 SRCTL1_IRQEN_SET;
    volatile Uint32 SRCTL1_IRQEN_CLR;
    volatile Uint32 SRCTL1_SENERROR;
    volatile Uint32 SRCTL1_ERRCONFIG;
    volatile Uint8  RSVD4[68];
    volatile Uint32 VP_VPCONFIG_REG;
    volatile Uint32 VP_VSTEPMIN_REG;
    volatile Uint32 VP_VSTEPMAX_REG;
    volatile Uint32 VP_VLIMITTO_REG;
    volatile Uint32 VP_VPSTS_REG;
    volatile Uint32 VP_VPVOLTAGE_REG;
    volatile Uint32 VP_SMPSREQ_STS_REG;
    volatile Uint8  RSVD5[100];
    volatile Uint32 SR_SS_VC_SMPS_I2C_SA0_REG;
    volatile Uint32 SR_SS_VC_SMPS_I2C_RA0_REG;
    volatile Uint32 SR_SS_VC_SMPS_I2C_SA1_REG;
    volatile Uint32 SR_SS_VC_SMPS_I2C_RA1_REG;
    volatile Uint32 SR_SS_VC_VAL_BYPASS_REG;
    volatile Uint8  RSVD6[8];
    volatile Uint32 SR_SS_VC_CFG_I2C_MODE_REG;
    volatile Uint32 SR_SS_VC_CFG_I2C_CLK_REG;
    volatile Uint32 SR_SS_VC_MISC_CTRL_REG;
    volatile Uint32 SR_SS_VC_MISC_STS_REG;
    volatile Uint8  RSVD7[4];
    volatile Uint32 SR_SS_VC_LINEAR_CTRL0_REG;
    volatile Uint32 SR_SS_VC_LINEAR_CTRL1_REG;
    volatile Uint32 SR_SS_VC_LINEAR_CTRL2_REG;
    volatile Uint32 SR_SS_VC_LINEAR_CTRL3_REG;
    volatile Uint32 SR_SS_VC_LINEAR_CTRL4_REG;
    volatile Uint32 SR_SS_VC_LINEAR_CTRL5_REG;
    volatile Uint32 SR_SS_VC_LINEAR_CTRL6_REG;
    volatile Uint32 SR_SS_VC_LINEAR_CTRL7_REG;
    volatile Uint32 SR_SS_VC_BYPASS_WDATA0_REG;
    volatile Uint32 SR_SS_VC_BYPASS_WDATA1_REG;
    volatile Uint32 SR_SS_VC_BYPASS_WDATA2_REG;
    volatile Uint32 SR_SS_VC_BYPASS_WDATA3_REG;
    volatile Uint32 SR_SS_VC_BYPASS_WDATA4_REG;
    volatile Uint32 SR_SS_VC_BYPASS_WDATA5_REG;
    volatile Uint32 SR_SS_VC_BYPASS_RDATA0_REG;
    volatile Uint32 SR_SS_VC_BYPASS_RDATA1_REG;
    volatile Uint32 SR_SS_VC_BYPASS_RDATA2_REG;
    volatile Uint32 SR_SS_VC_BYPASS_RDATA3_REG;
    volatile Uint32 SR_SS_VC_BYPASS_RDATA4_REG;
    volatile Uint32 SR_SS_VC_BYPASS_RDATA5_REG;
    volatile Uint32 SR_SS_I2C_ICOAR;
    volatile Uint32 SR_SS_I2C_ICIMR;
    volatile Uint32 SR_SS_I2C_ICSTR;
    volatile Uint32 SR_SS_I2C_ICCLKL;
    volatile Uint32 SR_SS_I2C_ICCLKH;
    volatile Uint32 SR_SS_I2C_ICCNT;
    volatile Uint32 SR_SS_I2C_ICDRR;
    volatile Uint32 SR_SS_I2C_ICSAR;
    volatile Uint32 SR_SS_I2C_ICDXR;
    volatile Uint32 SR_SS_I2C_ICMDR;
    volatile Uint32 SR_SS_I2C_ICIVR;
    volatile Uint32 SR_SS_I2C_ICEMDR;
    volatile Uint32 SR_SS_I2C_ICPSC;
    volatile Uint32 SR_SS_I2C_ICPID1;
    volatile Uint32 SR_SS_I2C_ICPID2;
} CSL_SrssRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* EVT_CLR_REG */
#define CSL_SRSS_EVT_CLR_REG                                    (0x18U)

/* EVT_FLAG_REG */
#define CSL_SRSS_EVT_FLAG_REG                                   (0x14U)

/* INTR_EN_SET_REG */
#define CSL_SRSS_INTR_EN_SET_REG                                (0x10U)

/* MISC_CTL0_REG */
#define CSL_SRSS_MISC_CTL0_REG                                  (0x4CU)

/* MISC_CTL1_REG */
#define CSL_SRSS_MISC_CTL1_REG                                  (0x50U)

/* MISC_STAT0_REG */
#define CSL_SRSS_MISC_STAT0_REG                                 (0x54U)

/* PID_REG */
#define CSL_SRSS_PID_REG                                        (0xCU)

/* SRCTL0_AVGWEIGHT */
#define CSL_SRSS_SRCTL0_AVGWEIGHT                               (0x124U)

/* SRCTL0_ERRCONFIG */
#define CSL_SRSS_SRCTL0_ERRCONFIG                               (0x144U)

/* SRCTL0_IRQ_EOI */
#define CSL_SRSS_SRCTL0_IRQ_EOI                                 (0x12CU)

/* SRCTL0_IRQEN_CLR */
#define CSL_SRSS_SRCTL0_IRQEN_CLR                               (0x13CU)

/* SRCTL0_IRQEN_SET */
#define CSL_SRSS_SRCTL0_IRQEN_SET                               (0x138U)

/* SRCTL0_IRQSTS */
#define CSL_SRSS_SRCTL0_IRQSTS                                  (0x134U)

/* SRCTL0_IRQSTS_RAW */
#define CSL_SRSS_SRCTL0_IRQSTS_RAW                              (0x130U)

/* SRCTL0_NVALUERECIPROCAL */
#define CSL_SRSS_SRCTL0_NVALUERECIPROCAL                        (0x128U)

/* SRCTL0_SRCONFIG */
#define CSL_SRSS_SRCTL0_SRCONFIG                                (0x10CU)

/* SRCTL0_SRSTS */
#define CSL_SRSS_SRCTL0_SRSTS                                   (0x110U)

/* SRCTL0_SENAVG */
#define CSL_SRSS_SRCTL0_SENAVG                                  (0x120U)

/* SRCTL0_SENERROR */
#define CSL_SRSS_SRCTL0_SENERROR                                (0x140U)

/* SRCTL0_SENMAX */
#define CSL_SRSS_SRCTL0_SENMAX                                  (0x11CU)

/* SRCTL0_SENMIN */
#define CSL_SRSS_SRCTL0_SENMIN                                  (0x118U)

/* SRCTL0_SENVAL */
#define CSL_SRSS_SRCTL0_SENVAL                                  (0x114U)

/* SRCTL1_AVGWEIGHT */
#define CSL_SRSS_SRCTL1_AVGWEIGHT                               (0x2A4U)

/* SRCTL1_ERRCONFIG */
#define CSL_SRSS_SRCTL1_ERRCONFIG                               (0x2C4U)

/* SRCTL1_IRQ_EOI */
#define CSL_SRSS_SRCTL1_IRQ_EOI                                 (0x2ACU)

/* SRCTL1_IRQEN_CLR */
#define CSL_SRSS_SRCTL1_IRQEN_CLR                               (0x2BCU)

/* SRCTL1_IRQEN_SET */
#define CSL_SRSS_SRCTL1_IRQEN_SET                               (0x2B8U)

/* SRCTL1_IRQSTS */
#define CSL_SRSS_SRCTL1_IRQSTS                                  (0x2B4U)

/* SRCTL1_IRQSTS_RAW */
#define CSL_SRSS_SRCTL1_IRQSTS_RAW                              (0x2B0U)

/* SRCTL1_NVALUERECIPROCAL */
#define CSL_SRSS_SRCTL1_NVALUERECIPROCAL                        (0x2A8U)

/* SRCTL1_SRCONFIG */
#define CSL_SRSS_SRCTL1_SRCONFIG                                (0x28CU)

/* SRCTL1_SRSTS */
#define CSL_SRSS_SRCTL1_SRSTS                                   (0x290U)

/* SRCTL1_SENAVG */
#define CSL_SRSS_SRCTL1_SENAVG                                  (0x2A0U)

/* SRCTL1_SENERROR */
#define CSL_SRSS_SRCTL1_SENERROR                                (0x2C0U)

/* SRCTL1_SENMAX */
#define CSL_SRSS_SRCTL1_SENMAX                                  (0x29CU)

/* SRCTL1_SENMIN */
#define CSL_SRSS_SRCTL1_SENMIN                                  (0x298U)

/* SRCTL1_SENVAL */
#define CSL_SRSS_SRCTL1_SENVAL                                  (0x294U)

/* SRCTL2_AVGWEIGHT */
#define CSL_SRSS_SRCTL2_AVGWEIGHT                               (0x224U)

/* SRCTL2_ERRCONFIG */
#define CSL_SRSS_SRCTL2_ERRCONFIG                               (0x244U)

/* SRCTL2_IRQ_EOI */
#define CSL_SRSS_SRCTL2_IRQ_EOI                                 (0x22CU)

/* SRCTL2_IRQEN_CLR */
#define CSL_SRSS_SRCTL2_IRQEN_CLR                               (0x23CU)

/* SRCTL2_IRQEN_SET */
#define CSL_SRSS_SRCTL2_IRQEN_SET                               (0x238U)

/* SRCTL2_IRQSTS */
#define CSL_SRSS_SRCTL2_IRQSTS                                  (0x234U)

/* SRCTL2_IRQSTS_RAW */
#define CSL_SRSS_SRCTL2_IRQSTS_RAW                              (0x230U)

/* SRCTL2_NVALUERECIPROCAL */
#define CSL_SRSS_SRCTL2_NVALUERECIPROCAL                        (0x228U)

/* SRCTL2_SRCONFIG */
#define CSL_SRSS_SRCTL2_SRCONFIG                                (0x20CU)

/* SRCTL2_SRSTS */
#define CSL_SRSS_SRCTL2_SRSTS                                   (0x210U)

/* SRCTL2_SENAVG */
#define CSL_SRSS_SRCTL2_SENAVG                                  (0x220U)

/* SRCTL2_SENERROR */
#define CSL_SRSS_SRCTL2_SENERROR                                (0x240U)

/* SRCTL2_SENMAX */
#define CSL_SRSS_SRCTL2_SENMAX                                  (0x21CU)

/* SRCTL2_SENMIN */
#define CSL_SRSS_SRCTL2_SENMIN                                  (0x218U)

/* SRCTL2_SENVAL */
#define CSL_SRSS_SRCTL2_SENVAL                                  (0x214U)

/* SRSEN_CTL0_REG */
#define CSL_SRSS_SRSEN_CTL0_REG                                 (0x3CU)

/* SRSEN_CTL1_REG */
#define CSL_SRSS_SRSEN_CTL1_REG                                 (0x40U)

/* SRSEN_CTL2_REG */
#define CSL_SRSS_SRSEN_CTL2_REG                                 (0x44U)

/* SRSEN_STAT0_REG */
#define CSL_SRSS_SRSEN_STAT0_REG                                (0x48U)

/* TEMP_CTL0_REG */
#define CSL_SRSS_TEMP_CTL0_REG                                  (0x28U)

/* TEMP_CTL1_REG */
#define CSL_SRSS_TEMP_CTL1_REG                                  (0x2CU)

/* TEMP_CTL2_REG */
#define CSL_SRSS_TEMP_CTL2_REG                                  (0x30U)

/* TEMP_STAT0_REG */
#define CSL_SRSS_TEMP_STAT0_REG                                 (0x34U)

/* TEMP_STAT1_REG */
#define CSL_SRSS_TEMP_STAT1_REG                                 (0x38U)

/* TIMER_CTL_REG */
#define CSL_SRSS_TIMER_CTL_REG                                  (0x1CU)

/* TIMER_LD_REG */
#define CSL_SRSS_TIMER_LD_REG                                   (0x20U)

/* TIMER_VAL_REG */
#define CSL_SRSS_TIMER_VAL_REG                                  (0x24U)

/* VPRM_CTRL0_REG */
#define CSL_SRSS_VPRM_CTRL0_REG                                 (0x8CU)

/* VPRM_CTRL1_REG */
#define CSL_SRSS_VPRM_CTRL1_REG                                 (0x90U)

/* VPRM_STS0_REG */
#define CSL_SRSS_VPRM_STS0_REG                                  (0x94U)

/* VPRM_STS1_REG */
#define CSL_SRSS_VPRM_STS1_REG                                  (0x98U)

/* VP_SMPSREQ_STS_REG */
#define CSL_SRSS_VP_SMPSREQ_STS_REG                             (0x324U)

/* VP_VLIMITTO_REG */
#define CSL_SRSS_VP_VLIMITTO_REG                                (0x318U)

/* VP_VPCONFIG_REG */
#define CSL_SRSS_VP_VPCONFIG_REG                                (0x30CU)

/* VP_VPSTS_REG */
#define CSL_SRSS_VP_VPSTS_REG                                   (0x31CU)

/* VP_VPVOLTAGE_REG */
#define CSL_SRSS_VP_VPVOLTAGE_REG                               (0x320U)

/* VP_VSTEPMAX_REG */
#define CSL_SRSS_VP_VSTEPMAX_REG                                (0x314U)

/* VP_VSTEPMIN_REG */
#define CSL_SRSS_VP_VSTEPMIN_REG                                (0x310U)

/* SR_SS_I2C_ICCLKH */
#define CSL_SRSS_SR_SS_I2C_ICCLKH                               (0x41CU)

/* SR_SS_I2C_ICCLKL */
#define CSL_SRSS_SR_SS_I2C_ICCLKL                               (0x418U)

/* SR_SS_I2C_ICCNT */
#define CSL_SRSS_SR_SS_I2C_ICCNT                                (0x420U)

/* SR_SS_I2C_ICDRR */
#define CSL_SRSS_SR_SS_I2C_ICDRR                                (0x424U)

/* SR_SS_I2C_ICDXR */
#define CSL_SRSS_SR_SS_I2C_ICDXR                                (0x42CU)

/* SR_SS_I2C_ICEMDR */
#define CSL_SRSS_SR_SS_I2C_ICEMDR                               (0x438U)

/* SR_SS_I2C_ICIMR */
#define CSL_SRSS_SR_SS_I2C_ICIMR                                (0x410U)

/* SR_SS_I2C_ICIVR */
#define CSL_SRSS_SR_SS_I2C_ICIVR                                (0x434U)

/* SR_SS_I2C_ICMDR */
#define CSL_SRSS_SR_SS_I2C_ICMDR                                (0x430U)

/* SR_SS_I2C_ICOAR */
#define CSL_SRSS_SR_SS_I2C_ICOAR                                (0x40CU)

/* SR_SS_I2C_ICPID1 */
#define CSL_SRSS_SR_SS_I2C_ICPID1                               (0x440U)

/* SR_SS_I2C_ICPID2 */
#define CSL_SRSS_SR_SS_I2C_ICPID2                               (0x444U)

/* SR_SS_I2C_ICPSC */
#define CSL_SRSS_SR_SS_I2C_ICPSC                                (0x43CU)

/* SR_SS_I2C_ICSAR */
#define CSL_SRSS_SR_SS_I2C_ICSAR                                (0x428U)

/* SR_SS_I2C_ICSTR */
#define CSL_SRSS_SR_SS_I2C_ICSTR                                (0x414U)

/* SR_SS_VC_BYPASS_RDATA0_REG */
#define CSL_SRSS_SR_SS_VC_BYPASS_RDATA0_REG                     (0x3F4U)

/* SR_SS_VC_BYPASS_RDATA1_REG */
#define CSL_SRSS_SR_SS_VC_BYPASS_RDATA1_REG                     (0x3F8U)

/* SR_SS_VC_BYPASS_RDATA2_REG */
#define CSL_SRSS_SR_SS_VC_BYPASS_RDATA2_REG                     (0x3FCU)

/* SR_SS_VC_BYPASS_RDATA3_REG */
#define CSL_SRSS_SR_SS_VC_BYPASS_RDATA3_REG                     (0x400U)

/* SR_SS_VC_BYPASS_RDATA4_REG */
#define CSL_SRSS_SR_SS_VC_BYPASS_RDATA4_REG                     (0x404U)

/* SR_SS_VC_BYPASS_RDATA5_REG */
#define CSL_SRSS_SR_SS_VC_BYPASS_RDATA5_REG                     (0x408U)

/* SR_SS_VC_BYPASS_WDATA0_REG */
#define CSL_SRSS_SR_SS_VC_BYPASS_WDATA0_REG                     (0x3DCU)

/* SR_SS_VC_BYPASS_WDATA1_REG */
#define CSL_SRSS_SR_SS_VC_BYPASS_WDATA1_REG                     (0x3E0U)

/* SR_SS_VC_BYPASS_WDATA2_REG */
#define CSL_SRSS_SR_SS_VC_BYPASS_WDATA2_REG                     (0x3E4U)

/* SR_SS_VC_BYPASS_WDATA3_REG */
#define CSL_SRSS_SR_SS_VC_BYPASS_WDATA3_REG                     (0x3E8U)

/* SR_SS_VC_BYPASS_WDATA4_REG */
#define CSL_SRSS_SR_SS_VC_BYPASS_WDATA4_REG                     (0x3ECU)

/* SR_SS_VC_BYPASS_WDATA5_REG */
#define CSL_SRSS_SR_SS_VC_BYPASS_WDATA5_REG                     (0x3F0U)

/* SR_SS_VC_CFG_I2C_CLK_REG */
#define CSL_SRSS_SR_SS_VC_CFG_I2C_CLK_REG                       (0x3ACU)

/* SR_SS_VC_CFG_I2C_MODE_REG */
#define CSL_SRSS_SR_SS_VC_CFG_I2C_MODE_REG                      (0x3A8U)

/* SR_SS_VC_LINEAR_CTRL0_REG */
#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL0_REG                      (0x3BCU)

/* SR_SS_VC_LINEAR_CTRL1_REG */
#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL1_REG                      (0x3C0U)

/* SR_SS_VC_LINEAR_CTRL2_REG */
#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL2_REG                      (0x3C4U)

/* SR_SS_VC_LINEAR_CTRL3_REG */
#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL3_REG                      (0x3C8U)

/* SR_SS_VC_LINEAR_CTRL4_REG */
#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL4_REG                      (0x3CCU)

/* SR_SS_VC_LINEAR_CTRL5_REG */
#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL5_REG                      (0x3D0U)

/* SR_SS_VC_LINEAR_CTRL6_REG */
#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL6_REG                      (0x3D4U)

/* SR_SS_VC_LINEAR_CTRL7_REG */
#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL7_REG                      (0x3D8U)

/* SR_SS_VC_MISC_CTRL_REG */
#define CSL_SRSS_SR_SS_VC_MISC_CTRL_REG                         (0x3B0U)

/* SR_SS_VC_MISC_STS_REG */
#define CSL_SRSS_SR_SS_VC_MISC_STS_REG                          (0x3B4U)

/* SR_SS_VC_SMPS_I2C_RA0_REG */
#define CSL_SRSS_SR_SS_VC_SMPS_I2C_RA0_REG                      (0x390U)

/* SR_SS_VC_SMPS_I2C_RA1_REG */
#define CSL_SRSS_SR_SS_VC_SMPS_I2C_RA1_REG                      (0x398U)

/* SR_SS_VC_SMPS_I2C_SA0_REG */
#define CSL_SRSS_SR_SS_VC_SMPS_I2C_SA0_REG                      (0x38CU)

/* SR_SS_VC_SMPS_I2C_SA1_REG */
#define CSL_SRSS_SR_SS_VC_SMPS_I2C_SA1_REG                      (0x394U)

/* SR_SS_VC_VAL_BYPASS_REG */
#define CSL_SRSS_SR_SS_VC_VAL_BYPASS_REG                        (0x39CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* EVT_CLR_REG */

#define CSL_SRSS_EVT_CLR_REG_RESETVAL                           (0x00000000U)

/* EVT_FLAG_REG */

#define CSL_SRSS_EVT_FLAG_REG_RESETVAL                          (0x00000000U)

/* INTR_EN_SET_REG */

#define CSL_SRSS_INTR_EN_SET_REG_RESETVAL                       (0x00000000U)

/* MISC_CTL0_REG */

#define CSL_SRSS_MISC_CTL0_REG_RESETVAL                         (0x00000000U)

/* MISC_CTL1_REG */

#define CSL_SRSS_MISC_CTL1_REG_RESETVAL                         (0x00000000U)

/* MISC_STAT0_REG */

#define CSL_SRSS_MISC_STAT0_REG_RESETVAL                        (0x00000000U)

/* PID_REG */

#define CSL_SRSS_PID_REG_RESETVAL                               (0x00000000U)

/* SRCTL0_AVGWEIGHT */

#define CSL_SRSS_SRCTL0_AVGWEIGHT_RESETVAL                      (0x00000000U)

/* SRCTL0_ERRCONFIG */

#define CSL_SRSS_SRCTL0_ERRCONFIG_RESETVAL                      (0x00000000U)

/* SRCTL0_IRQ_EOI */

#define CSL_SRSS_SRCTL0_IRQ_EOI_RESETVAL                        (0x00000000U)

/* SRCTL0_IRQEN_CLR */

#define CSL_SRSS_SRCTL0_IRQEN_CLR_RESETVAL                      (0x00000000U)

/* SRCTL0_IRQEN_SET */

#define CSL_SRSS_SRCTL0_IRQEN_SET_RESETVAL                      (0x00000000U)

/* SRCTL0_IRQSTS */

#define CSL_SRSS_SRCTL0_IRQSTS_RESETVAL                         (0x00000000U)

/* SRCTL0_IRQSTS_RAW */

#define CSL_SRSS_SRCTL0_IRQSTS_RAW_RESETVAL                     (0x00000000U)

/* SRCTL0_NVALUERECIPROCAL */

#define CSL_SRSS_SRCTL0_NVALUERECIPROCAL_RESETVAL               (0x00000000U)

/* SRCTL0_SRCONFIG */

#define CSL_SRSS_SRCTL0_SRCONFIG_RESETVAL                       (0x00000000U)

/* SRCTL0_SRSTS */

#define CSL_SRSS_SRCTL0_SRSTS_RESETVAL                          (0x00000000U)

/* SRCTL0_SENAVG */

#define CSL_SRSS_SRCTL0_SENAVG_RESETVAL                         (0x00000000U)

/* SRCTL0_SENERROR */

#define CSL_SRSS_SRCTL0_SENERROR_RESETVAL                       (0x00000000U)

/* SRCTL0_SENMAX */

#define CSL_SRSS_SRCTL0_SENMAX_RESETVAL                         (0x00000000U)

/* SRCTL0_SENMIN */

#define CSL_SRSS_SRCTL0_SENMIN_RESETVAL                         (0x00000000U)

/* SRCTL0_SENVAL */

#define CSL_SRSS_SRCTL0_SENVAL_RESETVAL                         (0x00000000U)

/* SRCTL1_AVGWEIGHT */

#define CSL_SRSS_SRCTL1_AVGWEIGHT_RESETVAL                      (0x00000000U)

/* SRCTL1_ERRCONFIG */

#define CSL_SRSS_SRCTL1_ERRCONFIG_RESETVAL                      (0x00000000U)

/* SRCTL1_IRQ_EOI */

#define CSL_SRSS_SRCTL1_IRQ_EOI_RESETVAL                        (0x00000000U)

/* SRCTL1_IRQEN_CLR */

#define CSL_SRSS_SRCTL1_IRQEN_CLR_RESETVAL                      (0x00000000U)

/* SRCTL1_IRQEN_SET */

#define CSL_SRSS_SRCTL1_IRQEN_SET_RESETVAL                      (0x00000000U)

/* SRCTL1_IRQSTS */

#define CSL_SRSS_SRCTL1_IRQSTS_RESETVAL                         (0x00000000U)

/* SRCTL1_IRQSTS_RAW */

#define CSL_SRSS_SRCTL1_IRQSTS_RAW_RESETVAL                     (0x00000000U)

/* SRCTL1_NVALUERECIPROCAL */

#define CSL_SRSS_SRCTL1_NVALUERECIPROCAL_RESETVAL               (0x00000000U)

/* SRCTL1_SRCONFIG */

#define CSL_SRSS_SRCTL1_SRCONFIG_RESETVAL                       (0x00000000U)

/* SRCTL1_SRSTS */

#define CSL_SRSS_SRCTL1_SRSTS_RESETVAL                          (0x00000000U)

/* SRCTL1_SENAVG */

#define CSL_SRSS_SRCTL1_SENAVG_RESETVAL                         (0x00000000U)

/* SRCTL1_SENERROR */

#define CSL_SRSS_SRCTL1_SENERROR_RESETVAL                       (0x00000000U)

/* SRCTL1_SENMAX */

#define CSL_SRSS_SRCTL1_SENMAX_RESETVAL                         (0x00000000U)

/* SRCTL1_SENMIN */

#define CSL_SRSS_SRCTL1_SENMIN_RESETVAL                         (0x00000000U)

/* SRCTL1_SENVAL */

#define CSL_SRSS_SRCTL1_SENVAL_RESETVAL                         (0x00000000U)

/* SRCTL2_AVGWEIGHT */

#define CSL_SRSS_SRCTL2_AVGWEIGHT_RESETVAL                      (0x00000000U)

/* SRCTL2_ERRCONFIG */

#define CSL_SRSS_SRCTL2_ERRCONFIG_RESETVAL                      (0x00000000U)

/* SRCTL2_IRQ_EOI */

#define CSL_SRSS_SRCTL2_IRQ_EOI_RESETVAL                        (0x00000000U)

/* SRCTL2_IRQEN_CLR */

#define CSL_SRSS_SRCTL2_IRQEN_CLR_RESETVAL                      (0x00000000U)

/* SRCTL2_IRQEN_SET */

#define CSL_SRSS_SRCTL2_IRQEN_SET_RESETVAL                      (0x00000000U)

/* SRCTL2_IRQSTS */

#define CSL_SRSS_SRCTL2_IRQSTS_RESETVAL                         (0x00000000U)

/* SRCTL2_IRQSTS_RAW */

#define CSL_SRSS_SRCTL2_IRQSTS_RAW_RESETVAL                     (0x00000000U)

/* SRCTL2_NVALUERECIPROCAL */

#define CSL_SRSS_SRCTL2_NVALUERECIPROCAL_RESETVAL               (0x00000000U)

/* SRCTL2_SRCONFIG */

#define CSL_SRSS_SRCTL2_SRCONFIG_RESETVAL                       (0x00000000U)

/* SRCTL2_SRSTS */

#define CSL_SRSS_SRCTL2_SRSTS_RESETVAL                          (0x00000000U)

/* SRCTL2_SENAVG */

#define CSL_SRSS_SRCTL2_SENAVG_RESETVAL                         (0x00000000U)

/* SRCTL2_SENERROR */

#define CSL_SRSS_SRCTL2_SENERROR_RESETVAL                       (0x00000000U)

/* SRCTL2_SENMAX */

#define CSL_SRSS_SRCTL2_SENMAX_RESETVAL                         (0x00000000U)

/* SRCTL2_SENMIN */

#define CSL_SRSS_SRCTL2_SENMIN_RESETVAL                         (0x00000000U)

/* SRCTL2_SENVAL */

#define CSL_SRSS_SRCTL2_SENVAL_RESETVAL                         (0x00000000U)

/* SRSEN_CTL0_REG */

#define CSL_SRSS_SRSEN_CTL0_REG_RESETVAL                        (0x00000000U)

/* SRSEN_CTL1_REG */

#define CSL_SRSS_SRSEN_CTL1_REG_RESETVAL                        (0x00000000U)

/* SRSEN_CTL2_REG */

#define CSL_SRSS_SRSEN_CTL2_REG_RESETVAL                        (0x00000000U)

/* SRSEN_STAT0_REG */

#define CSL_SRSS_SRSEN_STAT0_REG_RESETVAL                       (0x00000000U)

/* TEMP_CTL0_REG */

#define CSL_SRSS_TEMP_CTL0_REG_RESETVAL                         (0x00000000U)

/* TEMP_CTL1_REG */

#define CSL_SRSS_TEMP_CTL1_REG_RESETVAL                         (0x00000000U)

/* TEMP_CTL2_REG */

#define CSL_SRSS_TEMP_CTL2_REG_RESETVAL                         (0x00000000U)

/* TEMP_STAT0_REG */

#define CSL_SRSS_TEMP_STAT0_REG_RESETVAL                        (0x00000000U)

/* TEMP_STAT1_REG */

#define CSL_SRSS_TEMP_STAT1_REG_RESETVAL                        (0x00000000U)

/* TIMER_CTL_REG */

#define CSL_SRSS_TIMER_CTL_REG_RESETVAL                         (0x00000000U)

/* TIMER_LD_REG */

#define CSL_SRSS_TIMER_LD_REG_RESETVAL                          (0x00000000U)

/* TIMER_VAL_REG */

#define CSL_SRSS_TIMER_VAL_REG_RESETVAL                         (0x00000000U)

/* VPRM_CTRL0_REG */

#define CSL_SRSS_VPRM_CTRL0_REG_RESETVAL                        (0x00000000U)

/* VPRM_CTRL1_REG */

#define CSL_SRSS_VPRM_CTRL1_REG_RESETVAL                        (0x00000000U)

/* VPRM_STS0_REG */

#define CSL_SRSS_VPRM_STS0_REG_RESETVAL                         (0x00000000U)

/* VPRM_STS1_REG */

#define CSL_SRSS_VPRM_STS1_REG_RESETVAL                         (0x00000000U)

/* VP_SMPSREQ_STS_REG */

#define CSL_SRSS_VP_SMPSREQ_STS_REG_RESETVAL                    (0x00000000U)

/* VP_VLIMITTO_REG */

#define CSL_SRSS_VP_VLIMITTO_REG_RESETVAL                       (0x00000000U)

/* VP_VPCONFIG_REG */

#define CSL_SRSS_VP_VPCONFIG_REG_RESETVAL                       (0x00000000U)

/* VP_VPSTS_REG */

#define CSL_SRSS_VP_VPSTS_REG_RESETVAL                          (0x00000000U)

/* VP_VPVOLTAGE_REG */

#define CSL_SRSS_VP_VPVOLTAGE_REG_RESETVAL                      (0x00000000U)

/* VP_VSTEPMAX_REG */

#define CSL_SRSS_VP_VSTEPMAX_REG_RESETVAL                       (0x00000000U)

/* VP_VSTEPMIN_REG */

#define CSL_SRSS_VP_VSTEPMIN_REG_RESETVAL                       (0x00000000U)

/* SR_SS_I2C_ICCLKH */

#define CSL_SRSS_SR_SS_I2C_ICCLKH_RESETVAL                      (0x00000000U)

/* SR_SS_I2C_ICCLKL */

#define CSL_SRSS_SR_SS_I2C_ICCLKL_RESETVAL                      (0x00000000U)

/* SR_SS_I2C_ICCNT */

#define CSL_SRSS_SR_SS_I2C_ICCNT_RESETVAL                       (0x00000000U)

/* SR_SS_I2C_ICDRR */

#define CSL_SRSS_SR_SS_I2C_ICDRR_RESETVAL                       (0x00000000U)

/* SR_SS_I2C_ICDXR */

#define CSL_SRSS_SR_SS_I2C_ICDXR_RESETVAL                       (0x00000000U)

/* SR_SS_I2C_ICEMDR */

#define CSL_SRSS_SR_SS_I2C_ICEMDR_RESETVAL                      (0x00000000U)

/* SR_SS_I2C_ICIMR */

#define CSL_SRSS_SR_SS_I2C_ICIMR_RESETVAL                       (0x00000000U)

/* SR_SS_I2C_ICIVR */

#define CSL_SRSS_SR_SS_I2C_ICIVR_RESETVAL                       (0x00000000U)

/* SR_SS_I2C_ICMDR */

#define CSL_SRSS_SR_SS_I2C_ICMDR_RESETVAL                       (0x00000000U)

/* SR_SS_I2C_ICOAR */

#define CSL_SRSS_SR_SS_I2C_ICOAR_RESETVAL                       (0x00000000U)

/* SR_SS_I2C_ICPID1 */

#define CSL_SRSS_SR_SS_I2C_ICPID1_RESETVAL                      (0x00000000U)

/* SR_SS_I2C_ICPID2 */

#define CSL_SRSS_SR_SS_I2C_ICPID2_RESETVAL                      (0x00000000U)

/* SR_SS_I2C_ICPSC */

#define CSL_SRSS_SR_SS_I2C_ICPSC_RESETVAL                       (0x00000000U)

/* SR_SS_I2C_ICSAR */

#define CSL_SRSS_SR_SS_I2C_ICSAR_RESETVAL                       (0x00000000U)

/* SR_SS_I2C_ICSTR */

#define CSL_SRSS_SR_SS_I2C_ICSTR_RESETVAL                       (0x00000000U)

/* SR_SS_VC_BYPASS_RDATA0_REG */

#define CSL_SRSS_SR_SS_VC_BYPASS_RDATA0_REG_RESETVAL            (0x00000000U)

/* SR_SS_VC_BYPASS_RDATA1_REG */

#define CSL_SRSS_SR_SS_VC_BYPASS_RDATA1_REG_RESETVAL            (0x00000000U)

/* SR_SS_VC_BYPASS_RDATA2_REG */

#define CSL_SRSS_SR_SS_VC_BYPASS_RDATA2_REG_RESETVAL            (0x00000000U)

/* SR_SS_VC_BYPASS_RDATA3_REG */

#define CSL_SRSS_SR_SS_VC_BYPASS_RDATA3_REG_RESETVAL            (0x00000000U)

/* SR_SS_VC_BYPASS_RDATA4_REG */

#define CSL_SRSS_SR_SS_VC_BYPASS_RDATA4_REG_RESETVAL            (0x00000000U)

/* SR_SS_VC_BYPASS_RDATA5_REG */

#define CSL_SRSS_SR_SS_VC_BYPASS_RDATA5_REG_RESETVAL            (0x00000000U)

/* SR_SS_VC_BYPASS_WDATA0_REG */

#define CSL_SRSS_SR_SS_VC_BYPASS_WDATA0_REG_RESETVAL            (0x00000000U)

/* SR_SS_VC_BYPASS_WDATA1_REG */

#define CSL_SRSS_SR_SS_VC_BYPASS_WDATA1_REG_RESETVAL            (0x00000000U)

/* SR_SS_VC_BYPASS_WDATA2_REG */

#define CSL_SRSS_SR_SS_VC_BYPASS_WDATA2_REG_RESETVAL            (0x00000000U)

/* SR_SS_VC_BYPASS_WDATA3_REG */

#define CSL_SRSS_SR_SS_VC_BYPASS_WDATA3_REG_RESETVAL            (0x00000000U)

/* SR_SS_VC_BYPASS_WDATA4_REG */

#define CSL_SRSS_SR_SS_VC_BYPASS_WDATA4_REG_RESETVAL            (0x00000000U)

/* SR_SS_VC_BYPASS_WDATA5_REG */

#define CSL_SRSS_SR_SS_VC_BYPASS_WDATA5_REG_RESETVAL            (0x00000000U)

/* SR_SS_VC_CFG_I2C_CLK_REG */

#define CSL_SRSS_SR_SS_VC_CFG_I2C_CLK_REG_RESETVAL              (0x00000000U)

/* SR_SS_VC_CFG_I2C_MODE_REG */

#define CSL_SRSS_SR_SS_VC_CFG_I2C_MODE_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_LINEAR_CTRL0_REG */

#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL0_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_LINEAR_CTRL1_REG */

#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL1_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_LINEAR_CTRL2_REG */

#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL2_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_LINEAR_CTRL3_REG */

#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL3_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_LINEAR_CTRL4_REG */

#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL4_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_LINEAR_CTRL5_REG */

#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL5_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_LINEAR_CTRL6_REG */

#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL6_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_LINEAR_CTRL7_REG */

#define CSL_SRSS_SR_SS_VC_LINEAR_CTRL7_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_MISC_CTRL_REG */

#define CSL_SRSS_SR_SS_VC_MISC_CTRL_REG_RESETVAL                (0x00000000U)

/* SR_SS_VC_MISC_STS_REG */

#define CSL_SRSS_SR_SS_VC_MISC_STS_REG_RESETVAL                 (0x00000000U)

/* SR_SS_VC_SMPS_I2C_RA0_REG */

#define CSL_SRSS_SR_SS_VC_SMPS_I2C_RA0_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_SMPS_I2C_RA1_REG */

#define CSL_SRSS_SR_SS_VC_SMPS_I2C_RA1_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_SMPS_I2C_SA0_REG */

#define CSL_SRSS_SR_SS_VC_SMPS_I2C_SA0_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_SMPS_I2C_SA1_REG */

#define CSL_SRSS_SR_SS_VC_SMPS_I2C_SA1_REG_RESETVAL             (0x00000000U)

/* SR_SS_VC_VAL_BYPASS_REG */

#define CSL_SRSS_SR_SS_VC_VAL_BYPASS_REG_RESETVAL               (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif

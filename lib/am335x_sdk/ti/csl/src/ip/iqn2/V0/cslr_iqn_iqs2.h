/*
 *
 * Copyright (C) 2012-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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

/********************************************************************
*********************************************************************
* file: cslr_iqn_iqs2.h
*
* Brief: This file contains the Register Description for iqn_iqs2
*
*********************************************************************/
#ifndef CSLR_IQN_IQS2_H_
#define CSLR_IQN_IQS2_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for IQS_INGRESS_CONFIG
\**************************************************************************/
typedef struct  {
    volatile Uint32 IQS_ING_PKTDMA_CFG; /* Ingress PKTDMA pushback control. */
    volatile Uint8 RSVD0[4];
    volatile Uint32 IQS_ING_AID2_AXC_CFG; /* Ingress AID2 AXC priority and pushback control */
    volatile Uint32 IQS_ING_AID2_CTL_CFG; /* Ingress AID2 CTL priority and pushback control */
    volatile Uint32 IQS_ING_AIL0_AXC_CFG; /* Ingress AIL0 and pushback AXC priority control */
    volatile Uint32 IQS_ING_AIL0_CTL_CFG; /* Ingress AIL0 CTL priority and pushback control */
    volatile Uint32 IQS_ING_AIL1_AXC_CFG; /* Ingress AIL1 AXC priority and pushback control */
    volatile Uint32 IQS_ING_AIL1_CTL_CFG; /* Ingress AIL1 CTL priority and pushback control */
    volatile Uint32 IQS_ING_AIL2_AXC_CFG; /* Ingress AIL2 AXC priority and pushback control. NOTE: AIL 2 and 3 not currently supported. These are to be treated as reserved locations. */
    volatile Uint32 IQS_ING_AIL2_CTL_CFG; /* Ingress AIL2 CTL priority and pushback control. NOTE: AIL 2 and 3 not currently supported. These are to be treated as reserved locations. */
    volatile Uint32 IQS_ING_AIL3_AXC_CFG; /* Ingress AIL3 AXC priority and pushback control. NOTE: AIL 2 and 3 not currently supported. These are to be treated as reserved locations. */
    volatile Uint32 IQS_ING_AIL3_CTL_CFG; /* Ingress AIL3 CTL priority and pushback control. NOTE: AIL 2 and 3 not currently supported. These are to be treated as reserved locations. */
} CSL_Iqn_iqs2Iqs_ingress_configRegs; /* Ingress Configuration MMRs */

/**************************************************************************\
* Register Overlay Structure for IQS_INGRESS_CHAN_CONFIG
\**************************************************************************/
typedef struct  {
    volatile Uint32 IQS_ING_DIO2_PSI_CFG[16]; /* Sets the priority of the ingress DIO2 PSI channel. */
    volatile Uint8 RSVD0[448];
    volatile Uint32 IQS_ING_AID2_AXC_LUT_CFG[32]; /* Sets ingress AID2 AxC LUT for destination port and channel */
    volatile Uint8 RSVD1[384];
    volatile Uint32 IQS_ING_AID2_CTL_LUT_CFG[16]; /* Sets ingress AID2 CTL LUT for destination port and channel */
    volatile Uint8 RSVD2[448];
    volatile Uint32 IQS_ING_AIL0_AXC_LUT_CFG[64]; /* Sets ingress AIL0 AxC LUT for destination port and channel */
    volatile Uint8 RSVD3[256];
    volatile Uint32 IQS_ING_AIL0_CTL_LUT_CFG[4]; /* Sets ingress AIL0 CTL LUT for destination port and channel */
    volatile Uint8 RSVD4[496];
    volatile Uint32 IQS_ING_AIL1_AXC_LUT_CFG[64]; /* Sets ingress AIL1 AxC LUT for destination port and channel */
    volatile Uint8 RSVD5[256];
    volatile Uint32 IQS_ING_AIL1_CTL_LUT_CFG[4]; /* Sets ingress AIL1 CTL LUT for destination port and channel */
    volatile Uint8 RSVD6[496];
    volatile Uint32 IQS_ING_AIL2_AXC_LUT_CFG[64]; /* Sets ingress AIL2 AxC LUT for destination port and channel. NOTE: AIL 2 and 3 not currently supported. These are to be treated as reserved locations. */
    volatile Uint8 RSVD7[256];
    volatile Uint32 IQS_ING_AIL2_CTL_LUT_CFG[4]; /* Sets ingress AIL2 CTL LUT for destination port and channel. NOTE: AIL 2 and 3 not currently supported. These are to be treated as reserved locations. */
    volatile Uint8 RSVD8[496];
    volatile Uint32 IQS_ING_AIL3_AXC_LUT_CFG[64]; /* Sets ingress AIL3 AxC LUT for destination port and channel. NOTE: AIL 2 and 3 not currently supported. These are to be treated as reserved locations. */
    volatile Uint8 RSVD9[256];
    volatile Uint32 IQS_ING_AIL3_CTL_LUT_CFG[4]; /* Sets ingress AIL3 CTL LUT for destination port and channel. NOTE: AIL 2 and 3 not currently supported. These are to be treated as reserved locations. */
} CSL_Iqn_iqs2Iqs_ingress_chan_configRegs; /* Ingress Channel Configuration MMRs */

/**************************************************************************\
* Register Overlay Structure for IQS_EGRESS_CHAN_CONFIG
\**************************************************************************/
typedef struct  {
    volatile Uint32 IQS_EGR_PKTDMA_CFG[48]; /* Sets egress PKTDMA destination port and channel. Also sets internal arbitration and port PSI priority */
    volatile Uint8 RSVD0[320];
    volatile Uint32 IQS_EGR_DIO2_CFG[16]; /* Sets egress DIO2 destination port and channel. Also sets internal arbitration and port PSI priority. A 0 is highest priority. */
} CSL_Iqn_iqs2Iqs_egress_chan_configRegs; /* IQS Egress Channel Configuration MMRs */

/**************************************************************************\
* Register Overlay Structure for IQS_EE
\**************************************************************************/
typedef struct  {
    volatile Uint32 IQS_EE_CHAN_ERR_RAW_STS; /* Channel error register. When set indicates a transfer occurred for a non-existent destination port or channel. */
    volatile Uint32 IQS_EE_CHAN_ERR_RAW_SET; /* Allows software to force any bit in the correesponding raw status register high. */
    volatile Uint32 IQS_EE_CHAN_ERR_RAW_CLR; /* Allows software to clear any bit in the corresponding raw status register. */
    volatile Uint32 IQS_EE_CHAN_ERR_EV0_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 IQS_EE_CHAN_ERR_EV0_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 IQS_EE_CHAN_ERR_EV0_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 IQS_EE_CHAN_ERR_EV1_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 IQS_EE_CHAN_ERR_EV1_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 IQS_EE_CHAN_ERR_EV1_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 IQS_EE_CHAN_ERR_EV0_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint32 IQS_EE_CHAN_ERR_EV1_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint32 IQS_EE_ING_FLUSH_ERR_RAW_STS; /* Ingress Flush error register. When set indicates the DIO detected the need to flush or the transfer was to an IQS DIO channel that was full. */
    volatile Uint32 IQS_EE_ING_FLUSH_ERR_RAW_SET; /* Allows software to force any bit in the correesponding raw status register high. */
    volatile Uint32 IQS_EE_ING_FLUSH_ERR_RAW_CLR; /* Allows software to clear any bit in the corresponding raw status register. */
    volatile Uint32 IQS_EE_ING_FLUSH_ERR_EV0_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 IQS_EE_ING_FLUSH_ERR_EV0_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 IQS_EE_ING_FLUSH_ERR_EV0_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 IQS_EE_ING_FLUSH_ERR_EV1_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 IQS_EE_ING_FLUSH_ERR_EV1_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 IQS_EE_ING_FLUSH_ERR_EV1_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 IQS_EE_ING_FLUSH_ERR_EV0_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint32 IQS_EE_ING_FLUSH_ERR_EV1_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint32 IQS_EE_EGR_FLUSH_ERR_RAW_STS; /* Egress Flush error register. When set indicates that the destination module for the channel had requesed a flush. */
    volatile Uint32 IQS_EE_EGR_FLUSH_ERR_RAW_SET; /* Allows software to force any bit in the correesponding raw status register high. */
    volatile Uint32 IQS_EE_EGR_FLUSH_ERR_RAW_CLR; /* Allows software to clear any bit in the corresponding raw status register. */
    volatile Uint32 IQS_EE_EGR_FLUSH_ERR_EV0_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 IQS_EE_EGR_FLUSH_ERR_EV0_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 IQS_EE_EGR_FLUSH_ERR_EV0_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 IQS_EE_EGR_FLUSH_ERR_EV1_EN_STS; /* This is the enable mask used to select which raw status bits generate an interrupt when both register bits are set. */
    volatile Uint32 IQS_EE_EGR_FLUSH_ERR_EV1_EN_SET; /* Allows software to force any bit in the correesponding enable register high. */
    volatile Uint32 IQS_EE_EGR_FLUSH_ERR_EV1_EN_CLR; /* Allows software to clear any bit in the correesponding enable register. */
    volatile Uint32 IQS_EE_EGR_FLUSH_ERR_EV0_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint32 IQS_EE_EGR_FLUSH_ERR_EV1_ENABLED_STS; /* This is the result of masking the corresponding raw status register with the enable status register. */
    volatile Uint32 IQS_ORIG_REG; /* This is the origination register indicating which interrupt register group caused the interrupt. */
} CSL_Iqn_iqs2Iqs_eeRegs; /* IQN_IQS2_EE EE register group */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    CSL_Iqn_iqs2Iqs_ingress_configRegs IQS_INGRESS_CONFIG;
    volatile Uint8 RSVD0[464];
    CSL_Iqn_iqs2Iqs_ingress_chan_configRegs IQS_INGRESS_CHAN_CONFIG;
    volatile Uint8 RSVD1[2544];
    CSL_Iqn_iqs2Iqs_egress_chan_configRegs IQS_EGRESS_CHAN_CONFIG;
    volatile Uint8 RSVD2[7616];
    CSL_Iqn_iqs2Iqs_eeRegs IQS_EE;
/******************************************/
/*  TEMPORARY FIX: Manual addition till   */
/*  autogenerated file becomes available. */
    volatile Uint8 RSVD3[114552];
/******************************************/
} CSL_Iqn_iqs2Regs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* iqs_ing_pktdma_cfg */

#define CSL_IQN_IQS2_IQS_ING_PKTDMA_CFG_PB_SEL_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_ING_PKTDMA_CFG_PB_SEL_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_PKTDMA_CFG_PB_SEL_RESETVAL (0x00000001u)
/*----pb_sel Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_PKTDMA_CFG_PB_SEL_PB_AT_HALF_FULL (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_PKTDMA_CFG_PB_SEL_PB_AT_3QTR_FULL (0x00000001u)


#define CSL_IQN_IQS2_IQS_ING_PKTDMA_CFG_RESETVAL (0x00000001u)

/* iqs_ing_aid2_axc_cfg */

#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_CFG_PRI_MASK (0x00000003u)
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_CFG_PRI_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_CFG_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_CFG_ALLOW_PUSHBACK_MASK (0x00000100u)
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_CFG_ALLOW_PUSHBACK_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_CFG_ALLOW_PUSHBACK_RESETVAL (0x00000000u)
/*----allow_pushback Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_CFG_ALLOW_PUSHBACK_NO_PUSHBACK (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_CFG_ALLOW_PUSHBACK_EN_PUSHBACK (0x00000001u)


#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_CFG_RESETVAL (0x00000000u)

/* iqs_ing_aid2_ctl_cfg */

#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_CFG_PRI_MASK (0x00000003u)
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_CFG_PRI_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_CFG_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_CFG_ALLOW_PUSHBACK_MASK (0x00000100u)
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_CFG_ALLOW_PUSHBACK_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_CFG_ALLOW_PUSHBACK_RESETVAL (0x00000000u)
/*----allow_pushback Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_CFG_ALLOW_PUSHBACK_NO_PUSHBACK (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_CFG_ALLOW_PUSHBACK_EN_PUSHBACK (0x00000001u)


#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail0_axc_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_CFG_PRI_MASK (0x00000003u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_CFG_PRI_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_CFG_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_CFG_ALLOW_PUSHBACK_MASK (0x00000100u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_CFG_ALLOW_PUSHBACK_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_CFG_ALLOW_PUSHBACK_RESETVAL (0x00000000u)
/*----allow_pushback Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_CFG_ALLOW_PUSHBACK_NO_PUSHBACK (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_CFG_ALLOW_PUSHBACK_EN_PUSHBACK (0x00000001u)


#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail0_ctl_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_CFG_PRI_MASK (0x00000003u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_CFG_PRI_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_CFG_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_CFG_ALLOW_PUSHBACK_MASK (0x00000100u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_CFG_ALLOW_PUSHBACK_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_CFG_ALLOW_PUSHBACK_RESETVAL (0x00000000u)
/*----allow_pushback Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_CFG_ALLOW_PUSHBACK_NO_PUSHBACK (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_CFG_ALLOW_PUSHBACK_EN_PUSHBACK (0x00000001u)


#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail1_axc_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_CFG_PRI_MASK (0x00000003u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_CFG_PRI_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_CFG_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_CFG_ALLOW_PUSHBACK_MASK (0x00000100u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_CFG_ALLOW_PUSHBACK_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_CFG_ALLOW_PUSHBACK_RESETVAL (0x00000000u)
/*----allow_pushback Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_CFG_ALLOW_PUSHBACK_NO_PUSHBACK (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_CFG_ALLOW_PUSHBACK_EN_PUSHBACK (0x00000001u)


#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail1_ctl_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_CFG_PRI_MASK (0x00000003u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_CFG_PRI_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_CFG_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_CFG_ALLOW_PUSHBACK_MASK (0x00000100u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_CFG_ALLOW_PUSHBACK_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_CFG_ALLOW_PUSHBACK_RESETVAL (0x00000000u)
/*----allow_pushback Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_CFG_ALLOW_PUSHBACK_NO_PUSHBACK (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_CFG_ALLOW_PUSHBACK_EN_PUSHBACK (0x00000001u)


#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail2_axc_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_CFG_PRI_MASK (0x00000003u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_CFG_PRI_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_CFG_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_CFG_ALLOW_PUSHBACK_MASK (0x00000100u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_CFG_ALLOW_PUSHBACK_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_CFG_ALLOW_PUSHBACK_RESETVAL (0x00000000u)
/*----allow_pushback Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_CFG_ALLOW_PUSHBACK_NO_PUSHBACK (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_CFG_ALLOW_PUSHBACK_EN_PUSHBACK (0x00000001u)


#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail2_ctl_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_CFG_PRI_MASK (0x00000003u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_CFG_PRI_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_CFG_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_CFG_ALLOW_PUSHBACK_MASK (0x00000100u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_CFG_ALLOW_PUSHBACK_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_CFG_ALLOW_PUSHBACK_RESETVAL (0x00000000u)
/*----allow_pushback Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_CFG_ALLOW_PUSHBACK_NO_PUSHBACK (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_CFG_ALLOW_PUSHBACK_EN_PUSHBACK (0x00000001u)


#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail3_axc_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_CFG_PRI_MASK (0x00000003u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_CFG_PRI_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_CFG_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_CFG_ALLOW_PUSHBACK_MASK (0x00000100u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_CFG_ALLOW_PUSHBACK_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_CFG_ALLOW_PUSHBACK_RESETVAL (0x00000000u)
/*----allow_pushback Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_CFG_ALLOW_PUSHBACK_NO_PUSHBACK (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_CFG_ALLOW_PUSHBACK_EN_PUSHBACK (0x00000001u)


#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail3_ctl_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_CFG_PRI_MASK (0x00000003u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_CFG_PRI_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_CFG_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_CFG_ALLOW_PUSHBACK_MASK (0x00000100u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_CFG_ALLOW_PUSHBACK_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_CFG_ALLOW_PUSHBACK_RESETVAL (0x00000000u)
/*----allow_pushback Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_CFG_ALLOW_PUSHBACK_NO_PUSHBACK (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_CFG_ALLOW_PUSHBACK_EN_PUSHBACK (0x00000001u)


#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_CFG_RESETVAL (0x00000000u)

/* iqs_ing_dio2_psi_cfg */

#define CSL_IQN_IQS2_IQS_ING_DIO2_PSI_CFG_PRI_MASK (0x00000003u)
#define CSL_IQN_IQS2_IQS_ING_DIO2_PSI_CFG_PRI_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_DIO2_PSI_CFG_PRI_RESETVAL (0x00000000u)



#define CSL_IQN_IQS2_IQS_ING_DIO2_PSI_CFG_RESETVAL (0x00000000u)

/* iqs_ing_aid2_axc_lut_cfg */

#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_LUT_CFG_CHAN_MASK (0x0000007Fu)
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_LUT_CFG_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_LUT_CFG_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_LUT_CFG_DEST_MASK (0x00000300u)
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_LUT_CFG_DEST_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_LUT_CFG_DEST_RESETVAL (0x00000000u)
/*----dest Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_LUT_CFG_DEST_PKTDMA (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_LUT_CFG_DEST_DIO2 (0x00000001u)
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_LUT_CFG_DEST_RESERVED_2 (0x00000002u)
#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_LUT_CFG_DEST_RESERVED_3 (0x00000003u)


#define CSL_IQN_IQS2_IQS_ING_AID2_AXC_LUT_CFG_RESETVAL (0x00000000u)

/* iqs_ing_aid2_ctl_lut_cfg */

#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_LUT_CFG_CHAN_MASK (0x0000007Fu)
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_LUT_CFG_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_LUT_CFG_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_LUT_CFG_DEST_MASK (0x00000300u)
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_LUT_CFG_DEST_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_LUT_CFG_DEST_RESETVAL (0x00000000u)
/*----dest Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_LUT_CFG_DEST_PKTDMA (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_LUT_CFG_DEST_DIO2 (0x00000001u)
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_LUT_CFG_DEST_RESERVED_2 (0x00000002u)
#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_LUT_CFG_DEST_RESERVED_3 (0x00000003u)


#define CSL_IQN_IQS2_IQS_ING_AID2_CTL_LUT_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail0_axc_lut_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_LUT_CFG_CHAN_MASK (0x0000007Fu)
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_LUT_CFG_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_LUT_CFG_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_LUT_CFG_DEST_MASK (0x00000300u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_LUT_CFG_DEST_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_LUT_CFG_DEST_RESETVAL (0x00000000u)
/*----dest Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_LUT_CFG_DEST_PKTDMA (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_LUT_CFG_DEST_DIO2 (0x00000001u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_LUT_CFG_DEST_RESERVED_2 (0x00000002u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_LUT_CFG_DEST_RESERVED_3 (0x00000003u)


#define CSL_IQN_IQS2_IQS_ING_AIL0_AXC_LUT_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail0_ctl_lut_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_LUT_CFG_CHAN_MASK (0x0000007Fu)
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_LUT_CFG_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_LUT_CFG_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_LUT_CFG_DEST_MASK (0x00000300u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_LUT_CFG_DEST_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_LUT_CFG_DEST_RESETVAL (0x00000000u)
/*----dest Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_LUT_CFG_DEST_PKTDMA (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_LUT_CFG_DEST_DIO2 (0x00000001u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_LUT_CFG_DEST_RESERVED_2 (0x00000002u)
#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_LUT_CFG_DEST_RESERVED_3 (0x00000003u)


#define CSL_IQN_IQS2_IQS_ING_AIL0_CTL_LUT_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail1_axc_lut_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_LUT_CFG_CHAN_MASK (0x0000007Fu)
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_LUT_CFG_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_LUT_CFG_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_LUT_CFG_DEST_MASK (0x00000300u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_LUT_CFG_DEST_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_LUT_CFG_DEST_RESETVAL (0x00000000u)
/*----dest Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_LUT_CFG_DEST_PKTDMA (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_LUT_CFG_DEST_DIO2 (0x00000001u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_LUT_CFG_DEST_RESERVED_2 (0x00000002u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_LUT_CFG_DEST_RESERVED_3 (0x00000003u)


#define CSL_IQN_IQS2_IQS_ING_AIL1_AXC_LUT_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail1_ctl_lut_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_LUT_CFG_CHAN_MASK (0x0000007Fu)
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_LUT_CFG_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_LUT_CFG_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_LUT_CFG_DEST_MASK (0x00000300u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_LUT_CFG_DEST_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_LUT_CFG_DEST_RESETVAL (0x00000000u)
/*----dest Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_LUT_CFG_DEST_PKTDMA (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_LUT_CFG_DEST_DIO2 (0x00000001u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_LUT_CFG_DEST_RESERVED_2 (0x00000002u)
#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_LUT_CFG_DEST_RESERVED_3 (0x00000003u)


#define CSL_IQN_IQS2_IQS_ING_AIL1_CTL_LUT_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail2_axc_lut_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_LUT_CFG_CHAN_MASK (0x0000007Fu)
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_LUT_CFG_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_LUT_CFG_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_LUT_CFG_DEST_MASK (0x00000300u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_LUT_CFG_DEST_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_LUT_CFG_DEST_RESETVAL (0x00000000u)
/*----dest Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_LUT_CFG_DEST_PKTDMA (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_LUT_CFG_DEST_DIO2 (0x00000001u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_LUT_CFG_DEST_RESERVED_2 (0x00000002u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_LUT_CFG_DEST_RESERVED_3 (0x00000003u)


#define CSL_IQN_IQS2_IQS_ING_AIL2_AXC_LUT_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail2_ctl_lut_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_LUT_CFG_CHAN_MASK (0x0000007Fu)
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_LUT_CFG_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_LUT_CFG_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_LUT_CFG_DEST_MASK (0x00000300u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_LUT_CFG_DEST_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_LUT_CFG_DEST_RESETVAL (0x00000000u)
/*----dest Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_LUT_CFG_DEST_PKTDMA (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_LUT_CFG_DEST_DIO2 (0x00000001u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_LUT_CFG_DEST_RESERVED_2 (0x00000002u)
#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_LUT_CFG_DEST_RESERVED_3 (0x00000003u)


#define CSL_IQN_IQS2_IQS_ING_AIL2_CTL_LUT_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail3_axc_lut_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_LUT_CFG_CHAN_MASK (0x0000007Fu)
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_LUT_CFG_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_LUT_CFG_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_LUT_CFG_DEST_MASK (0x00000300u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_LUT_CFG_DEST_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_LUT_CFG_DEST_RESETVAL (0x00000000u)
/*----dest Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_LUT_CFG_DEST_PKTDMA (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_LUT_CFG_DEST_DIO2 (0x00000001u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_LUT_CFG_DEST_RESERVED_2 (0x00000002u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_LUT_CFG_DEST_RESERVED_3 (0x00000003u)


#define CSL_IQN_IQS2_IQS_ING_AIL3_AXC_LUT_CFG_RESETVAL (0x00000000u)

/* iqs_ing_ail3_ctl_lut_cfg */

#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_LUT_CFG_CHAN_MASK (0x0000007Fu)
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_LUT_CFG_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_LUT_CFG_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_LUT_CFG_DEST_MASK (0x00000300u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_LUT_CFG_DEST_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_LUT_CFG_DEST_RESETVAL (0x00000000u)
/*----dest Tokens----*/
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_LUT_CFG_DEST_PKTDMA (0x00000000u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_LUT_CFG_DEST_DIO2 (0x00000001u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_LUT_CFG_DEST_RESERVED_2 (0x00000002u)
#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_LUT_CFG_DEST_RESERVED_3 (0x00000003u)


#define CSL_IQN_IQS2_IQS_ING_AIL3_CTL_LUT_CFG_RESETVAL (0x00000000u)

/* iqs_egr_pktdma_cfg */

#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_CHAN_MASK (0x0000007Fu)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_MASK (0x00000F00u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_RESETVAL (0x00000000u)
/*----dest Tokens----*/
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_AID2_AXC (0x00000000u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_AID2_CTL (0x00000001u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_AIL0_AXC (0x00000002u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_AIL0_CTL (0x00000003u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_AIL1_AXC (0x00000004u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_AIL1_CTL (0x00000005u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_AIL2_AXC (0x00000006u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_AIL2_CTL (0x00000007u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_AIL3_AXC (0x00000008u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_DEST_AIL3_CTL (0x00000009u)

#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_ARB_PRI_MASK (0x00007000u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_ARB_PRI_SHIFT (0x0000000Cu)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_ARB_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_PSI_PRI_MASK (0x00070000u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_PSI_PRI_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_PSI_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EGR_PKTDMA_CFG_RESETVAL (0x00000000u)

/* iqs_egr_dio2_cfg */

#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_CHAN_MASK (0x0000007Fu)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_CHAN_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_CHAN_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_MASK (0x00000F00u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_SHIFT (0x00000008u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_RESETVAL (0x00000000u)
/*----dest Tokens----*/
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_AID2_AXC (0x00000000u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_AID2_CTL (0x00000001u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_AIL0_AXC (0x00000002u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_AIL0_CTL (0x00000003u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_AIL1_AXC (0x00000004u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_AIL1_CTL (0x00000005u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_AIL2_AXC (0x00000006u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_AIL2_CTL (0x00000007u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_AIL3_AXC (0x00000008u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_DEST_AIL3_CTL (0x00000009u)

#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_ARB_PRI_MASK (0x00007000u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_ARB_PRI_SHIFT (0x0000000Cu)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_ARB_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_PSI_PRI_MASK (0x00070000u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_PSI_PRI_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_PSI_PRI_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EGR_DIO2_CFG_RESETVAL (0x00000000u)

/* iqs_ee_chan_err_raw_sts */

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_STS_ING_PKTDMA_ERR_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_STS_ING_PKTDMA_ERR_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_STS_ING_PKTDMA_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_STS_ING_DIO2_ERR_MASK (0x00000002u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_STS_ING_DIO2_ERR_SHIFT (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_STS_ING_DIO2_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_STS_EGR_MUX_ERR_MASK (0x00010000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_STS_EGR_MUX_ERR_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_STS_EGR_MUX_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_STS_RESETVAL (0x00000000u)

/* iqs_ee_chan_err_raw_set */

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_SET_ING_PKTDMA_ERR_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_SET_ING_PKTDMA_ERR_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_SET_ING_PKTDMA_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_SET_ING_DIO2_ERR_MASK (0x00000002u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_SET_ING_DIO2_ERR_SHIFT (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_SET_ING_DIO2_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_SET_EGR_MUX_ERR_MASK (0x00010000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_SET_EGR_MUX_ERR_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_SET_EGR_MUX_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_SET_RESETVAL (0x00000000u)

/* iqs_ee_chan_err_raw_clr */

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_CLR_ING_PKTDMA_ERR_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_CLR_ING_PKTDMA_ERR_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_CLR_ING_PKTDMA_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_CLR_ING_DIO2_ERR_MASK (0x00000002u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_CLR_ING_DIO2_ERR_SHIFT (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_CLR_ING_DIO2_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_CLR_EGR_MUX_ERR_MASK (0x00010000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_CLR_EGR_MUX_ERR_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_CLR_EGR_MUX_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_RAW_CLR_RESETVAL (0x00000000u)

/* iqs_ee_chan_err_ev0_en_sts */

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_STS_ING_PKTDMA_ERR_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_STS_ING_PKTDMA_ERR_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_STS_ING_PKTDMA_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_STS_ING_DIO2_ERR_MASK (0x00000002u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_STS_ING_DIO2_ERR_SHIFT (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_STS_ING_DIO2_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_STS_EGR_MUX_ERR_MASK (0x00010000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_STS_EGR_MUX_ERR_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_STS_EGR_MUX_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_STS_RESETVAL (0x00000000u)

/* iqs_ee_chan_err_ev0_en_set */

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_SET_ING_PKTDMA_ERR_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_SET_ING_PKTDMA_ERR_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_SET_ING_PKTDMA_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_SET_ING_DIO2_ERR_MASK (0x00000002u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_SET_ING_DIO2_ERR_SHIFT (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_SET_ING_DIO2_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_SET_EGR_MUX_ERR_MASK (0x00010000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_SET_EGR_MUX_ERR_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_SET_EGR_MUX_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_SET_RESETVAL (0x00000000u)

/* iqs_ee_chan_err_ev0_en_clr */

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_CLR_ING_PKTDMA_ERR_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_CLR_ING_PKTDMA_ERR_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_CLR_ING_PKTDMA_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_CLR_ING_DIO2_ERR_MASK (0x00000002u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_CLR_ING_DIO2_ERR_SHIFT (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_CLR_ING_DIO2_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_CLR_EGR_MUX_ERR_MASK (0x00010000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_CLR_EGR_MUX_ERR_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_CLR_EGR_MUX_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_EN_CLR_RESETVAL (0x00000000u)

/* iqs_ee_chan_err_ev1_en_sts */

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_STS_ING_PKTDMA_ERR_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_STS_ING_PKTDMA_ERR_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_STS_ING_PKTDMA_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_STS_ING_DIO2_ERR_MASK (0x00000002u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_STS_ING_DIO2_ERR_SHIFT (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_STS_ING_DIO2_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_STS_EGR_MUX_ERR_MASK (0x00010000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_STS_EGR_MUX_ERR_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_STS_EGR_MUX_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_STS_RESETVAL (0x00000000u)

/* iqs_ee_chan_err_ev1_en_set */

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_SET_ING_PKTDMA_ERR_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_SET_ING_PKTDMA_ERR_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_SET_ING_PKTDMA_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_SET_ING_DIO2_ERR_MASK (0x00000002u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_SET_ING_DIO2_ERR_SHIFT (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_SET_ING_DIO2_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_SET_EGR_MUX_ERR_MASK (0x00010000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_SET_EGR_MUX_ERR_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_SET_EGR_MUX_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_SET_RESETVAL (0x00000000u)

/* iqs_ee_chan_err_ev1_en_clr */

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_CLR_ING_PKTDMA_ERR_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_CLR_ING_PKTDMA_ERR_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_CLR_ING_PKTDMA_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_CLR_ING_DIO2_ERR_MASK (0x00000002u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_CLR_ING_DIO2_ERR_SHIFT (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_CLR_ING_DIO2_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_CLR_EGR_MUX_ERR_MASK (0x00010000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_CLR_EGR_MUX_ERR_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_CLR_EGR_MUX_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_EN_CLR_RESETVAL (0x00000000u)

/* iqs_ee_chan_err_ev0_enabled_sts */

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_ENABLED_STS_ING_PKTDMA_ERR_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_ENABLED_STS_ING_PKTDMA_ERR_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_ENABLED_STS_ING_PKTDMA_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_ENABLED_STS_ING_DIO2_ERR_MASK (0x00000002u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_ENABLED_STS_ING_DIO2_ERR_SHIFT (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_ENABLED_STS_ING_DIO2_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_ENABLED_STS_EGR_MUX_ERR_MASK (0x00010000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_ENABLED_STS_EGR_MUX_ERR_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_ENABLED_STS_EGR_MUX_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* iqs_ee_chan_err_ev1_enabled_sts */

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_ENABLED_STS_ING_PKTDMA_ERR_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_ENABLED_STS_ING_PKTDMA_ERR_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_ENABLED_STS_ING_PKTDMA_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_ENABLED_STS_ING_DIO2_ERR_MASK (0x00000002u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_ENABLED_STS_ING_DIO2_ERR_SHIFT (0x00000001u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_ENABLED_STS_ING_DIO2_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_ENABLED_STS_EGR_MUX_ERR_MASK (0x00010000u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_ENABLED_STS_EGR_MUX_ERR_SHIFT (0x00000010u)
#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_ENABLED_STS_EGR_MUX_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_CHAN_ERR_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* iqs_ee_ing_flush_err_raw_sts */

#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_RAW_STS_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_RAW_STS_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_RAW_STS_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_RAW_STS_RESETVAL (0x00000000u)

/* iqs_ee_ing_flush_err_raw_set */

#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_RAW_SET_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_RAW_SET_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_RAW_SET_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_RAW_SET_RESETVAL (0x00000000u)

/* iqs_ee_ing_flush_err_raw_clr */

#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_RAW_CLR_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_RAW_CLR_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_RAW_CLR_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_RAW_CLR_RESETVAL (0x00000000u)

/* iqs_ee_ing_flush_err_ev0_en_sts */

#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_EN_STS_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_EN_STS_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_EN_STS_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_EN_STS_RESETVAL (0x00000000u)

/* iqs_ee_ing_flush_err_ev0_en_set */

#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_EN_SET_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_EN_SET_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_EN_SET_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_EN_SET_RESETVAL (0x00000000u)

/* iqs_ee_ing_flush_err_ev0_en_clr */

#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_EN_CLR_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_EN_CLR_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_EN_CLR_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_EN_CLR_RESETVAL (0x00000000u)

/* iqs_ee_ing_flush_err_ev1_en_sts */

#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_EN_STS_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_EN_STS_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_EN_STS_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_EN_STS_RESETVAL (0x00000000u)

/* iqs_ee_ing_flush_err_ev1_en_set */

#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_EN_SET_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_EN_SET_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_EN_SET_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_EN_SET_RESETVAL (0x00000000u)

/* iqs_ee_ing_flush_err_ev1_en_clr */

#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_EN_CLR_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_EN_CLR_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_EN_CLR_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_EN_CLR_RESETVAL (0x00000000u)

/* iqs_ee_ing_flush_err_ev0_enabled_sts */

#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_ENABLED_STS_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_ENABLED_STS_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_ENABLED_STS_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* iqs_ee_ing_flush_err_ev1_enabled_sts */

#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_ENABLED_STS_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_ENABLED_STS_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_ENABLED_STS_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_ING_FLUSH_ERR_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* iqs_ee_egr_flush_err_raw_sts */

#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_RAW_STS_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_RAW_STS_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_RAW_STS_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_RAW_STS_RESETVAL (0x00000000u)

/* iqs_ee_egr_flush_err_raw_set */

#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_RAW_SET_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_RAW_SET_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_RAW_SET_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_RAW_SET_RESETVAL (0x00000000u)

/* iqs_ee_egr_flush_err_raw_clr */

#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_RAW_CLR_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_RAW_CLR_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_RAW_CLR_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_RAW_CLR_RESETVAL (0x00000000u)

/* iqs_ee_egr_flush_err_ev0_en_sts */

#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_EN_STS_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_EN_STS_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_EN_STS_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_EN_STS_RESETVAL (0x00000000u)

/* iqs_ee_egr_flush_err_ev0_en_set */

#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_EN_SET_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_EN_SET_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_EN_SET_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_EN_SET_RESETVAL (0x00000000u)

/* iqs_ee_egr_flush_err_ev0_en_clr */

#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_EN_CLR_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_EN_CLR_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_EN_CLR_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_EN_CLR_RESETVAL (0x00000000u)

/* iqs_ee_egr_flush_err_ev1_en_sts */

#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_EN_STS_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_EN_STS_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_EN_STS_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_EN_STS_RESETVAL (0x00000000u)

/* iqs_ee_egr_flush_err_ev1_en_set */

#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_EN_SET_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_EN_SET_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_EN_SET_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_EN_SET_RESETVAL (0x00000000u)

/* iqs_ee_egr_flush_err_ev1_en_clr */

#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_EN_CLR_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_EN_CLR_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_EN_CLR_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_EN_CLR_RESETVAL (0x00000000u)

/* iqs_ee_egr_flush_err_ev0_enabled_sts */

#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_ENABLED_STS_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_ENABLED_STS_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_ENABLED_STS_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* iqs_ee_egr_flush_err_ev1_enabled_sts */

#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_ENABLED_STS_FLUSH_MASK (0x0000FFFFu)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_ENABLED_STS_FLUSH_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_ENABLED_STS_FLUSH_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_EE_EGR_FLUSH_ERR_EV1_ENABLED_STS_RESETVAL (0x00000000u)

/* iqs_orig_reg */

#define CSL_IQN_IQS2_IQS_ORIG_REG_EE_CHAN_ERR_MASK (0x00000001u)
#define CSL_IQN_IQS2_IQS_ORIG_REG_EE_CHAN_ERR_SHIFT (0x00000000u)
#define CSL_IQN_IQS2_IQS_ORIG_REG_EE_CHAN_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_ORIG_REG_EE_ING_FLUSH_ERR_MASK (0x00000002u)
#define CSL_IQN_IQS2_IQS_ORIG_REG_EE_ING_FLUSH_ERR_SHIFT (0x00000001u)
#define CSL_IQN_IQS2_IQS_ORIG_REG_EE_ING_FLUSH_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_IQS2_IQS_ORIG_REG_EE_EGR_FLUSH_ERR_MASK (0x00000004u)
#define CSL_IQN_IQS2_IQS_ORIG_REG_EE_EGR_FLUSH_ERR_SHIFT (0x00000002u)
#define CSL_IQN_IQS2_IQS_ORIG_REG_EE_EGR_FLUSH_ERR_RESETVAL (0x00000000u)


#define CSL_IQN_IQS2_IQS_ORIG_REG_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif

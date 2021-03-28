/********************************************************************
 * Copyright (C) 2003-2018 Texas Instruments Incorporated.
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
#ifndef CSLR_TAC2_DATA_V0_H
#define CSLR_TAC2_DATA_V0_H

/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Modified the header file includes to be RTSC compliant
 */

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 4 bytes */

/**************************************************************************\
* Register Overlay Structure for SG0_SIG_GAIN
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG0_SIG_GAIN_W0;
    volatile Uint32 SG0_SIG_GAIN_W1;
    volatile Uint32 SG0_SIG_GAIN_W2;
    volatile Uint32 RSVD0;
    volatile Uint32 SG0_SIG_GAIN_W4;
    volatile Uint32 SG0_SIG_GAIN_W5;
    volatile Uint32 SG0_SIG_GAIN_W6;
    volatile Uint32 RSVD1;
    volatile Uint32 SG0_SIG_GAIN_W8;
    volatile Uint32 SG0_SIG_GAIN_W9;
    volatile Uint32 SG0_SIG_GAIN_W10;
    volatile Uint32 RSVD2;
    volatile Uint32 SG0_SIG_GAIN_W12;
    volatile Uint32 SG0_SIG_GAIN_W13;
    volatile Uint32 SG0_SIG_GAIN_W14;
    volatile Uint32 RSVD3;
} CSL_Tac_dataSg0_sig_gainRegs;

/**************************************************************************\
* Register Overlay Structure for SG0_FT_QUEUE
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG0_FTQ_W0;
    volatile Uint32 SG0_FTQ_W1;
    volatile Uint32 SG0_FTQ_W2;
    volatile Uint32 RSVD4;
} CSL_Tac_dataSg0_ft_queueRegs;

/**************************************************************************\
* Register Overlay Structure for SG0_WT_QUEUE
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG0_WTQ_W0;
    volatile Uint32 SG0_WTQ_W1;
} CSL_Tac_dataSg0_wt_queueRegs;

/**************************************************************************\
* Register Overlay Structure for SG1_SIG_GAIN
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG1_SIG_GAIN_W0;
    volatile Uint32 SG1_SIG_GAIN_W1;
    volatile Uint32 SG1_SIG_GAIN_W2;
    volatile Uint32 RSVD0;
    volatile Uint32 SG1_SIG_GAIN_W4;
    volatile Uint32 SG1_SIG_GAIN_W5;
    volatile Uint32 SG1_SIG_GAIN_W6;
    volatile Uint32 RSVD1;
    volatile Uint32 SG1_SIG_GAIN_W7;
    volatile Uint32 SG1_SIG_GAIN_W8;
    volatile Uint32 SG1_SIG_GAIN_W10;
    volatile Uint32 RSVD2;
    volatile Uint32 SG1_SIG_GAIN_W12;
    volatile Uint32 SG1_SIG_GAIN_W13;
    volatile Uint32 SG1_SIG_GAIN_W14;
    volatile Uint32 RSVD3;
} CSL_Tac_dataSg1_sig_gainRegs;

/**************************************************************************\
* Register Overlay Structure for SG1_FT_QUEUE
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG1_FTQ_W0;
    volatile Uint32 SG1_FTQ_W1;
    volatile Uint32 SG1_FTQ_W2;
    volatile Uint32 RSVD8;
} CSL_Tac_dataSg1_ft_queueRegs;

/**************************************************************************\
* Register Overlay Structure for SG1_WT_QUEUE
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG1_WTQ_W0;
    volatile Uint32 SG1_WTQ_W1;
} CSL_Tac_dataSg1_wt_queueRegs;

/**************************************************************************\
* Register Overlay Structure for SG2_SIG_GAIN
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG2_SIG_GAIN_W0;
    volatile Uint32 SG2_SIG_GAIN_W1;
    volatile Uint32 SG2_SIG_GAIN_W2;
    volatile Uint32 RSVD0;
    volatile Uint32 SG2_SIG_GAIN_W4;
    volatile Uint32 SG2_SIG_GAIN_W5;
    volatile Uint32 SG2_SIG_GAIN_W6;
    volatile Uint32 RSVD1;
    volatile Uint32 SG2_SIG_GAIN_W8;
    volatile Uint32 SG2_SIG_GAIN_W9;
    volatile Uint32 SG2_SIG_GAIN_W10;
    volatile Uint32 RSVD2;
    volatile Uint32 SG2_SIG_GAIN_W12;
    volatile Uint32 SG2_SIG_GAIN_W13;
    volatile Uint32 SG2_SIG_GAIN_W14;
    volatile Uint32 RSVD3;
} CSL_Tac_dataSg2_sig_gainRegs;

/**************************************************************************\
* Register Overlay Structure for SG2_FT_QUEUE
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG2_FTQ_W0;
    volatile Uint32 SG2_FTQ_W1;
    volatile Uint32 SG2_FTQ_W2;
    volatile Uint32 RSVD4;
} CSL_Tac_dataSg2_ft_queueRegs;

/**************************************************************************\
* Register Overlay Structure for SG2_WT_QUEUE
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG2_WTQ_W0;
    volatile Uint32 SG2_WTQ_W1;
} CSL_Tac_dataSg2_wt_queueRegs;

/**************************************************************************\
* Register Overlay Structure for SG3_SIG_GAIN
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG3_SIG_GAIN_W0;
    volatile Uint32 SG3_SIG_GAIN_W1;
    volatile Uint32 SG3_SIG_GAIN_W2;
    volatile Uint32 RSVD0;
    volatile Uint32 SG3_SIG_GAIN_W4;
    volatile Uint32 SG3_SIG_GAIN_W5;
    volatile Uint32 SG3_SIG_GAIN_W6;
    volatile Uint32 RSVD1;
    volatile Uint32 SG3_SIG_GAIN_W8;
    volatile Uint32 SG3_SIG_GAIN_W9;
    volatile Uint32 SG3_SIG_GAIN_W10;
    volatile Uint32 RSVD2;
    volatile Uint32 SG3_SIG_GAIN_W12;
    volatile Uint32 SG3_SIG_GAIN_W13;
    volatile Uint32 SG3_SIG_GAIN_W14;
    volatile Uint32 RSVD3;
} CSL_Tac_dataSg3_sig_gainRegs;

/**************************************************************************\
* Register Overlay Structure for SG3_FT_QUEUE
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG3_FTQ_W0;
    volatile Uint32 SG3_FTQ_W1;
    volatile Uint32 SG3_FTQ_W2;
    volatile Uint32 RSVD4;
} CSL_Tac_dataSg3_ft_queueRegs;

/**************************************************************************\
* Register Overlay Structure for SG3_WT_QUEUE
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG3_WTQ_W0;
    volatile Uint32 SG3_WTQ_W1;
} CSL_Tac_dataSg3_wt_queueRegs;

/**************************************************************************\
* Register Overlay Structure for SG4_SIG_GAIN
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG4_SIG_GAIN_W0;
    volatile Uint32 SG4_SIG_GAIN_W1;
    volatile Uint32 SG4_SIG_GAIN_W2;
    volatile Uint32 RSVD0;
    volatile Uint32 SG4_SIG_GAIN_W4;
    volatile Uint32 SG4_SIG_GAIN_W5;
    volatile Uint32 SG4_SIG_GAIN_W6;
    volatile Uint32 RSVD1;
    volatile Uint32 SG4_SIG_GAIN_W8;
    volatile Uint32 SG4_SIG_GAIN_W9;
    volatile Uint32 SG4_SIG_GAIN_W10;
    volatile Uint32 RSVD2;
    volatile Uint32 SG4_SIG_GAIN_W12;
    volatile Uint32 SG4_SIG_GAIN_W13;
    volatile Uint32 SG4_SIG_GAIN_W14;
    volatile Uint32 RSVD3;
} CSL_Tac_dataSg4_sig_gainRegs;

/**************************************************************************\
* Register Overlay Structure for SG4_FT_QUEUE
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG4_FTQ_W0;
    volatile Uint32 SG4_FTQ_W1;
    volatile Uint32 SG4_FTQ_W2;
    volatile Uint32 RSVD4;
} CSL_Tac_dataSg4_ft_queueRegs;

/**************************************************************************\
* Register Overlay Structure for SG4_WT_QUEUE
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG4_WTQ_W0;
    volatile Uint32 SG4_WTQ_W1;
} CSL_Tac_dataSg4_wt_queueRegs;

/**************************************************************************\
* Register Overlay Structure for SG5_SIG_GAIN
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG5_SIG_GAIN_W0;
    volatile Uint32 SG5_SIG_GAIN_W1;
    volatile Uint32 SG5_SIG_GAIN_W2;
    volatile Uint32 RSVD0;
    volatile Uint32 SG5_SIG_GAIN_W4;
    volatile Uint32 SG5_SIG_GAIN_W5;
    volatile Uint32 SG5_SIG_GAIN_W6;
    volatile Uint32 RSVD1;
    volatile Uint32 SG5_SIG_GAIN_W8;
    volatile Uint32 SG5_SIG_GAIN_W9;
    volatile Uint32 SG5_SIG_GAIN_W10;
    volatile Uint32 RSVD2;
    volatile Uint32 SG5_SIG_GAIN_W12;
    volatile Uint32 SG5_SIG_GAIN_W13;
    volatile Uint32 SG5_SIG_GAIN_W14;
    volatile Uint32 RSVD3;
} CSL_Tac_dataSg5_sig_gainRegs;

/**************************************************************************\
* Register Overlay Structure for SG5_FT_QUEUE
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG5_FTQ_W0;
    volatile Uint32 SG5_FTQ_W1;
    volatile Uint32 SG5_FTQ_W2;
    volatile Uint32 RSVD4;
} CSL_Tac_dataSg5_ft_queueRegs;

/**************************************************************************\
* Register Overlay Structure for SG5_WT_QUEUE
\**************************************************************************/
typedef struct  {
    volatile Uint32 SG5_WTQ_W0;
    volatile Uint32 SG5_WTQ_W1;
} CSL_Tac_dataSg5_wt_queueRegs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile CSL_Uint64 BE_ACT_OUT[128];
    volatile Uint32 BE_TIME;
    volatile Uint32 RSVD0[255];
    volatile CSL_Uint64 SPMR_SIDE0[128];
    volatile CSL_Uint64 SPMR_SIDE1[128];
    volatile CSL_Uint64 SPMR_INACT_SIDE[128];
    volatile Uint32 RSVD1[2816];
    volatile Uint32 EAB_WR[1536];
    volatile Uint32 EAB_RD[768];
    volatile Uint32 RSVD2[9984];

    CSL_Tac_dataSg0_sig_gainRegs SG0_SIG_GAIN[384];
    volatile Uint32 SG0_SIG_OUT[2048];
    CSL_Tac_dataSg0_ft_queueRegs SG0_FT_QUEUE[512];
    volatile Uint32 SG0_IB[2048];
    volatile Uint32 SG0_OB0[1024];
    volatile Uint32 SG0_OB1[1024];
    volatile Uint32 RSVD3[512];
    CSL_Tac_dataSg0_wt_queueRegs SG0_WT_QUEUE[128];
    volatile CSL_Uint64 SG0_CPMQ[128];
    volatile Uint32 SG0_SIG_INPUT[768];
    volatile Uint32 RSVD4[256];

    CSL_Tac_dataSg1_sig_gainRegs SG1_SIG_GAIN[384];
    volatile Uint32 SG1_SIG_OUT[2048];
    CSL_Tac_dataSg1_ft_queueRegs SG1_FT_QUEUE[512];
    volatile Uint32 SG1_IB[2048];
    volatile Uint32 SG1_OB0[1024];
    volatile Uint32 SG1_OB1[1024];
    volatile Uint32 RSVD5[512];
    CSL_Tac_dataSg1_wt_queueRegs SG1_WT_QUEUE[128];
    volatile CSL_Uint64 SG1_CPMQ[128];
    volatile Uint32 SG1_SIG_INPUT[768];
    volatile Uint32 RSVD6[256];

    CSL_Tac_dataSg2_sig_gainRegs SG2_SIG_GAIN[384];
    volatile Uint32 SG2_SIG_OUT[2048];
    CSL_Tac_dataSg2_ft_queueRegs SG2_FT_QUEUE[512];
    volatile Uint32 SG2_IB[2048];
    volatile Uint32 SG2_OB0[1024];
    volatile Uint32 SG2_OB1[1024];
    volatile Uint32 RSVD7[512];
    CSL_Tac_dataSg2_wt_queueRegs SG2_WT_QUEUE[128];
    volatile CSL_Uint64 SG2_CPMQ[128];
    volatile Uint32 SG2_SIG_INPUT[768];
    volatile Uint32 RSVD8[256];

    CSL_Tac_dataSg3_sig_gainRegs SG3_SIG_GAIN[384];
    volatile Uint32 SG3_SIG_OUT[2048];
    CSL_Tac_dataSg3_ft_queueRegs SG3_FT_QUEUE[512];
    volatile Uint32 SG3_IB[2048];
    volatile Uint32 SG3_OB0[1024];
    volatile Uint32 SG3_OB1[1024];
    volatile Uint32 RSVD9[512];
    CSL_Tac_dataSg3_wt_queueRegs SG3_WT_QUEUE[128];
    volatile CSL_Uint64 SG3_CPMQ[128];
    volatile Uint32 SG3_SIG_INPUT[768];
    volatile Uint32 RSVD10[256];

    CSL_Tac_dataSg4_sig_gainRegs SG4_SIG_GAIN[384];
    volatile Uint32 SG4_SIG_OUT[2048];
    CSL_Tac_dataSg4_ft_queueRegs SG4_FT_QUEUE[512];
    volatile Uint32 SG4_IB[2048];
    volatile Uint32 SG4_OB0[1024];
    volatile Uint32 SG4_OB1[1024];
    volatile Uint32 RSVD11[512];
    CSL_Tac_dataSg4_wt_queueRegs SG4_WT_QUEUE[128];
    volatile CSL_Uint64 SG4_CPMQ[128];
    volatile Uint32 SG4_SIG_INPUT[768];
    volatile Uint32 RSVD12[256];

    CSL_Tac_dataSg5_sig_gainRegs SG5_SIG_GAIN[384];
    volatile Uint32 SG5_SIG_OUT[2048];
    CSL_Tac_dataSg5_ft_queueRegs SG5_FT_QUEUE[512];
    volatile Uint32 SG5_IB[2048];
    volatile Uint32 SG5_OB0[1024];
    volatile Uint32 SG5_OB1[1024];
    volatile Uint32 RSVD13[512];
    CSL_Tac_dataSg5_wt_queueRegs SG5_WT_QUEUE[128];
    volatile CSL_Uint64 SG5_CPMQ[128];
    volatile Uint32 SG5_SIG_INPUT[768];
    volatile Uint32 RSVD14[256];

} CSL_Tac_dataRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* SG0_SIG_GAIN_W0 */

#define CSL_TAC_DATA_SG0_SIG_GAIN_W0_INIT_GAIN_SIG4KPLUS0_MASK (0x000003FFu)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W0_INIT_GAIN_SIG4KPLUS0_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W0_INIT_GAIN_SIG4KPLUS0_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_GAIN_W0_RESETVAL (0x00000000u)

/* SG0_SIG_GAIN_W1 */

#define CSL_TAC_DATA_SG0_SIG_GAIN_W1_DELTA_GAIN1_SIG4KPLUS0_MASK (0x000000FFu)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W1_DELTA_GAIN1_SIG4KPLUS0_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W1_DELTA_GAIN1_SIG4KPLUS0_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_GAIN_W1_RESETVAL (0x00000000u)

/* SG0_SIG_GAIN_W2 */

#define CSL_TAC_DATA_SG0_SIG_GAIN_W2_DELTA_GAIN2_SIG4KPLUS0_MASK (0x000000FFu)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W2_DELTA_GAIN2_SIG4KPLUS0_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W2_DELTA_GAIN2_SIG4KPLUS0_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_GAIN_W2_RESETVAL (0x00000000u)

/* SG0_SIG_GAIN_W4 */

#define CSL_TAC_DATA_SG0_SIG_GAIN_W4_INIT_GAIN_SIG4KPLUS1_MASK (0x000003FFu)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W4_INIT_GAIN_SIG4KPLUS1_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W4_INIT_GAIN_SIG4KPLUS1_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_GAIN_W4_RESETVAL (0x00000000u)

/* SG0_SIG_GAIN_W5 */

#define CSL_TAC_DATA_SG0_SIG_GAIN_W5_DELTA_GAIN1_SIG4KPLUS1_MASK (0x000000FFu)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W5_DELTA_GAIN1_SIG4KPLUS1_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W5_DELTA_GAIN1_SIG4KPLUS1_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_GAIN_W5_RESETVAL (0x00000000u)

/* SG0_SIG_GAIN_W6 */

#define CSL_TAC_DATA_SG0_SIG_GAIN_W6_DELTA_GAIN2_SIG4KPLUS1_MASK (0x000000FFu)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W6_DELTA_GAIN2_SIG4KPLUS1_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W6_DELTA_GAIN2_SIG4KPLUS1_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_GAIN_W6_RESETVAL (0x00000000u)

/* SG0_SIG_GAIN_W8 */

#define CSL_TAC_DATA_SG0_SIG_GAIN_W8_INIT_GAIN_SIG4KPLUS2_MASK (0x000003FFu)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W8_INIT_GAIN_SIG4KPLUS2_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W8_INIT_GAIN_SIG4KPLUS2_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_GAIN_W8_RESETVAL (0x00000000u)

/* SG0_SIG_GAIN_W9 */

#define CSL_TAC_DATA_SG0_SIG_GAIN_W9_DELTA_GAIN1_SIG4KPLUS2_MASK (0x000000FFu)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W9_DELTA_GAIN1_SIG4KPLUS2_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W9_DELTA_GAIN1_SIG4KPLUS2_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_GAIN_W9_RESETVAL (0x00000000u)

/* SG0_SIG_GAIN_W10 */

#define CSL_TAC_DATA_SG0_SIG_GAIN_W10_DELTA_GAIN2_SIG4KPLUS2_MASK (0x000000FFu)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W10_DELTA_GAIN2_SIG4KPLUS2_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W10_DELTA_GAIN2_SIG4KPLUS2_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_GAIN_W10_RESETVAL (0x00000000u)

/* SG0_SIG_GAIN_W12 */

#define CSL_TAC_DATA_SG0_SIG_GAIN_W12_INIT_GAIN_SIG4KPLUS3_MASK (0x000003FFu)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W12_INIT_GAIN_SIG4KPLUS3_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W12_INIT_GAIN_SIG4KPLUS3_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_GAIN_W12_RESETVAL (0x00000000u)

/* SG0_SIG_GAIN_W13 */

#define CSL_TAC_DATA_SG0_SIG_GAIN_W13_DELTA_GAIN1_SIG4KPLUS3_MASK (0x000000FFu)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W13_DELTA_GAIN1_SIG4KPLUS3_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W13_DELTA_GAIN1_SIG4KPLUS3_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_GAIN_W13_RESETVAL (0x00000000u)

/* SG0_SIG_GAIN_W14 */

#define CSL_TAC_DATA_SG0_SIG_GAIN_W14_DELTA_GAIN2_SIG4KPLUS3_MASK (0x000000FFu)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W14_DELTA_GAIN2_SIG4KPLUS3_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_GAIN_W14_DELTA_GAIN2_SIG4KPLUS3_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_GAIN_W14_RESETVAL (0x00000000u)

/* SG0_FTQ_W0 */

#define CSL_TAC_DATA_SG0_FTQ_W0_START_ADDR_MASK (0xFFFFFFFFu)
#define CSL_TAC_DATA_SG0_FTQ_W0_START_ADDR_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_FTQ_W0_START_ADDR_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_FTQ_W0_RESETVAL (0x00000000u)

/* SG0_FTQ_W1 */

#define CSL_TAC_DATA_SG0_FTQ_W1_FRAME_ID_MASK (0x1FFE0000u)
#define CSL_TAC_DATA_SG0_FTQ_W1_FRAME_ID_SHIFT (0x00000011u)
#define CSL_TAC_DATA_SG0_FTQ_W1_FRAME_ID_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_FTQ_W1_SPR_IDX_MASK (0x0001FF00u)
#define CSL_TAC_DATA_SG0_FTQ_W1_SPR_IDX_SHIFT (0x00000008u)
#define CSL_TAC_DATA_SG0_FTQ_W1_SPR_IDX_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_FTQ_W1_NB_BYTES_MASK (0x000000FFu)
#define CSL_TAC_DATA_SG0_FTQ_W1_NB_BYTES_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_FTQ_W1_NB_BYTES_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_FTQ_W1_RESETVAL (0x00000000u)

/* SG0_FTQ_W2 */

#define CSL_TAC_DATA_SG0_FTQ_W2_SIG_TASK_ID_MASK (0x0003FE00u)
#define CSL_TAC_DATA_SG0_FTQ_W2_SIG_TASK_ID_SHIFT (0x00000009u)
#define CSL_TAC_DATA_SG0_FTQ_W2_SIG_TASK_ID_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_FTQ_W2_HEADER_FLG_MASK (0x00000100u)
#define CSL_TAC_DATA_SG0_FTQ_W2_HEADER_FLG_SHIFT (0x00000008u)
#define CSL_TAC_DATA_SG0_FTQ_W2_HEADER_FLG_RESETVAL (0x00000000u)
/*----HEADER_FLG Tokens----*/
#define CSL_TAC_DATA_SG0_FTQ_W2_HEADER_FLG_DATA (0x00000000u)
#define CSL_TAC_DATA_SG0_FTQ_W2_HEADER_FLG_HEADER (0x00000001u)

#define CSL_TAC_DATA_SG0_FTQ_W2_CHANNEL_KIND_MASK (0x000000F0u)
#define CSL_TAC_DATA_SG0_FTQ_W2_CHANNEL_KIND_SHIFT (0x00000004u)
#define CSL_TAC_DATA_SG0_FTQ_W2_CHANNEL_KIND_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_FTQ_W2_OPTION_MASK (0x0000000Fu)
#define CSL_TAC_DATA_SG0_FTQ_W2_OPTION_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_FTQ_W2_OPTION_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_FTQ_W2_RESETVAL (0x00000000u)

/* SG0_WTQ_W0 */

#define CSL_TAC_DATA_SG0_WTQ_W0_OPTION_MASK (0xF0000000u)
#define CSL_TAC_DATA_SG0_WTQ_W0_OPTION_SHIFT (0x0000001Cu)
#define CSL_TAC_DATA_SG0_WTQ_W0_OPTION_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_WTQ_W0_FRAME_ID_MASK (0x0FFF0000u)
#define CSL_TAC_DATA_SG0_WTQ_W0_FRAME_ID_SHIFT (0x00000010u)
#define CSL_TAC_DATA_SG0_WTQ_W0_FRAME_ID_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_WTQ_W0_SGCP_ID_MASK (0x0000E000u)
#define CSL_TAC_DATA_SG0_WTQ_W0_SGCP_ID_SHIFT (0x0000000Du)
#define CSL_TAC_DATA_SG0_WTQ_W0_SGCP_ID_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_WTQ_W0_SPR_IDX_MASK (0x00001FF0u)
#define CSL_TAC_DATA_SG0_WTQ_W0_SPR_IDX_SHIFT (0x00000004u)
#define CSL_TAC_DATA_SG0_WTQ_W0_SPR_IDX_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_WTQ_W0_CHANNEL_KIND_MASK (0x0000000Fu)
#define CSL_TAC_DATA_SG0_WTQ_W0_CHANNEL_KIND_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_WTQ_W0_CHANNEL_KIND_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_WTQ_W0_RESETVAL (0x00000000u)

/* SG0_WTQ_W1 */

#define CSL_TAC_DATA_SG0_WTQ_W1_WARNING_FLAG_MASK (0x0000F000u)
#define CSL_TAC_DATA_SG0_WTQ_W1_WARNING_FLAG_SHIFT (0x0000000Cu)
#define CSL_TAC_DATA_SG0_WTQ_W1_WARNING_FLAG_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_WTQ_W1_CHANNEL_IDX_MASK (0x00000FFFu)
#define CSL_TAC_DATA_SG0_WTQ_W1_CHANNEL_IDX_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_WTQ_W1_CHANNEL_IDX_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_WTQ_W1_RESETVAL (0x00000000u)

/* SG0_CPMQ */

#define CSL_TAC_DATA_SG0_CPMQ_SLOT_ID_MASK (0x0000F00000000000u)
#define CSL_TAC_DATA_SG0_CPMQ_SLOT_ID_SHIFT (0x000000000000002Cu)
#define CSL_TAC_DATA_SG0_CPMQ_SLOT_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SG0_CPMQ_FRAME_ID_MASK (0x00000FFF00000000u)
#define CSL_TAC_DATA_SG0_CPMQ_FRAME_ID_SHIFT (0x0000000000000020u)
#define CSL_TAC_DATA_SG0_CPMQ_FRAME_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SG0_CPMQ_SGCP_ID_MASK (0x0000000003800000u)
#define CSL_TAC_DATA_SG0_CPMQ_SGCP_ID_SHIFT (0x0000000000000017u)
#define CSL_TAC_DATA_SG0_CPMQ_SGCP_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SG0_CPMQ_RLS_ID_MASK (0x00000000007F0000u)
#define CSL_TAC_DATA_SG0_CPMQ_RLS_ID_SHIFT (0x0000000000000010u)
#define CSL_TAC_DATA_SG0_CPMQ_RLS_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SG0_CPMQ_ACC_GAIN_MASK (0x000000000000FFFFu)
#define CSL_TAC_DATA_SG0_CPMQ_ACC_GAIN_SHIFT (0x0000000000000000u)
#define CSL_TAC_DATA_SG0_CPMQ_ACC_GAIN_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SG0_CPMQ_RESETVAL (0x0000000000000000u)

/* BE_ACT_OUT */

#define CSL_TAC_DATA_BE_ACT_OUT_C1_Q_MASK (0xFFFF000000000000u)
#define CSL_TAC_DATA_BE_ACT_OUT_C1_Q_SHIFT (0x0000000000000030u)
#define CSL_TAC_DATA_BE_ACT_OUT_C1_Q_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_BE_ACT_OUT_C1_I_MASK (0x0000FFFF00000000u)
#define CSL_TAC_DATA_BE_ACT_OUT_C1_I_SHIFT (0x0000000000000020u)
#define CSL_TAC_DATA_BE_ACT_OUT_C1_I_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_BE_ACT_OUT_C0_Q_MASK (0x00000000FFFF0000u)
#define CSL_TAC_DATA_BE_ACT_OUT_C0_Q_SHIFT (0x0000000000000010u)
#define CSL_TAC_DATA_BE_ACT_OUT_C0_Q_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_BE_ACT_OUT_C0_I_MASK (0x000000000000FFFFu)
#define CSL_TAC_DATA_BE_ACT_OUT_C0_I_SHIFT (0x0000000000000000u)
#define CSL_TAC_DATA_BE_ACT_OUT_C0_I_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_BE_ACT_OUT_RESETVAL (0x0000000000000000u)

/* BE_TIME */

#define CSL_TAC_DATA_BE_TIME_FRAME_MASK  (0x0FFF0000u)
#define CSL_TAC_DATA_BE_TIME_FRAME_SHIFT (0x00000010u)
#define CSL_TAC_DATA_BE_TIME_FRAME_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_BE_TIME_SLOT_MASK   (0x0000F000u)
#define CSL_TAC_DATA_BE_TIME_SLOT_SHIFT  (0x0000000Cu)
#define CSL_TAC_DATA_BE_TIME_SLOT_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_BE_TIME_CHIP_MASK   (0x00000FFFu)
#define CSL_TAC_DATA_BE_TIME_CHIP_SHIFT  (0x00000000u)
#define CSL_TAC_DATA_BE_TIME_CHIP_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_BE_TIME_RESETVAL    (0x00000000u)

/* SPMR_SIDE0 */

#define CSL_TAC_DATA_SPMR_SIDE0_TRUNC_FRAME_ID_MASK (0xFF00000000000000u)
#define CSL_TAC_DATA_SPMR_SIDE0_TRUNC_FRAME_ID_SHIFT (0x0000000000000038u)
#define CSL_TAC_DATA_SPMR_SIDE0_TRUNC_FRAME_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SPMR_SIDE0_SLOT_ID_MASK (0x00F0000000000000u)
#define CSL_TAC_DATA_SPMR_SIDE0_SLOT_ID_SHIFT (0x0000000000000034u)
#define CSL_TAC_DATA_SPMR_SIDE0_SLOT_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SPMR_SIDE0_SYMBOL_ID_MASK (0x000F000000000000u)
#define CSL_TAC_DATA_SPMR_SIDE0_SYMBOL_ID_SHIFT (0x0000000000000030u)
#define CSL_TAC_DATA_SPMR_SIDE0_SYMBOL_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SPMR_SIDE0_ACCUMULATOR_MASK (0x0000FFFFFFFFFFFFu)
#define CSL_TAC_DATA_SPMR_SIDE0_ACCUMULATOR_SHIFT (0x0000000000000000u)
#define CSL_TAC_DATA_SPMR_SIDE0_ACCUMULATOR_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SPMR_SIDE0_RESETVAL (0x0000000000000000u)

/* SPMR_SIDE1 */

#define CSL_TAC_DATA_SPMR_SIDE1_TRUNC_FRAME_ID_MASK (0xFF00000000000000u)
#define CSL_TAC_DATA_SPMR_SIDE1_TRUNC_FRAME_ID_SHIFT (0x0000000000000038u)
#define CSL_TAC_DATA_SPMR_SIDE1_TRUNC_FRAME_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SPMR_SIDE1_SLOT_ID_MASK (0x00F0000000000000u)
#define CSL_TAC_DATA_SPMR_SIDE1_SLOT_ID_SHIFT (0x0000000000000034u)
#define CSL_TAC_DATA_SPMR_SIDE1_SLOT_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SPMR_SIDE1_SYMBOL_ID_MASK (0x000F000000000000u)
#define CSL_TAC_DATA_SPMR_SIDE1_SYMBOL_ID_SHIFT (0x0000000000000030u)
#define CSL_TAC_DATA_SPMR_SIDE1_SYMBOL_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SPMR_SIDE1_ACCUMULATOR_MASK (0x0000FFFFFFFFFFFFu)
#define CSL_TAC_DATA_SPMR_SIDE1_ACCUMULATOR_SHIFT (0x0000000000000000u)
#define CSL_TAC_DATA_SPMR_SIDE1_ACCUMULATOR_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SPMR_SIDE1_RESETVAL (0x0000000000000000u)

/* SPMR_INACT_SIDE */

#define CSL_TAC_DATA_SPMR_INACT_SIDE_TRUNC_FRAME_ID_MASK (0xFF00000000000000u)
#define CSL_TAC_DATA_SPMR_INACT_SIDE_TRUNC_FRAME_ID_SHIFT (0x0000000000000038u)
#define CSL_TAC_DATA_SPMR_INACT_SIDE_TRUNC_FRAME_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SPMR_INACT_SIDE_SLOT_ID_MASK (0x00F0000000000000u)
#define CSL_TAC_DATA_SPMR_INACT_SIDE_SLOT_ID_SHIFT (0x0000000000000034u)
#define CSL_TAC_DATA_SPMR_INACT_SIDE_SLOT_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SPMR_INACT_SIDE_SYMBOL_ID_MASK (0x000F000000000000u)
#define CSL_TAC_DATA_SPMR_INACT_SIDE_SYMBOL_ID_SHIFT (0x0000000000000030u)
#define CSL_TAC_DATA_SPMR_INACT_SIDE_SYMBOL_ID_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SPMR_INACT_SIDE_ACCUMULATOR_MASK (0x0000FFFFFFFFFFFFu)
#define CSL_TAC_DATA_SPMR_INACT_SIDE_ACCUMULATOR_SHIFT (0x0000000000000000u)
#define CSL_TAC_DATA_SPMR_INACT_SIDE_ACCUMULATOR_RESETVAL (0x0000000000000000u)

#define CSL_TAC_DATA_SPMR_INACT_SIDE_RESETVAL (0x0000000000000000u)

/* EAB_WR */

#define CSL_TAC_DATA_EAB_WR_WORD_MASK    (0xFFFFFFFFu)
#define CSL_TAC_DATA_EAB_WR_WORD_SHIFT   (0x00000000u)
#define CSL_TAC_DATA_EAB_WR_WORD_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_EAB_WR_RESETVAL     (0x00000000u)

/* EAB_RD */

#define CSL_TAC_DATA_EAB_RD_WORD_MASK    (0xFFFFFFFFu)
#define CSL_TAC_DATA_EAB_RD_WORD_SHIFT   (0x00000000u)
#define CSL_TAC_DATA_EAB_RD_WORD_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_EAB_RD_RESETVAL     (0x00000000u)

/* SG0_IB */

#define CSL_TAC_DATA_SG0_IB_WORD_MASK    (0xFFFFFFFFu)
#define CSL_TAC_DATA_SG0_IB_WORD_SHIFT   (0x00000000u)
#define CSL_TAC_DATA_SG0_IB_WORD_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_IB_RESETVAL     (0x00000000u)

/* SG0_OB0 */

#define CSL_TAC_DATA_SG0_OB0_WORD_MASK   (0xFFFFFFFFu)
#define CSL_TAC_DATA_SG0_OB0_WORD_SHIFT  (0x00000000u)
#define CSL_TAC_DATA_SG0_OB0_WORD_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_OB0_RESETVAL    (0x00000000u)

/* SG0_OB1 */

#define CSL_TAC_DATA_SG0_OB1_WORD_MASK   (0xFFFFFFFFu)
#define CSL_TAC_DATA_SG0_OB1_WORD_SHIFT  (0x00000000u)
#define CSL_TAC_DATA_SG0_OB1_WORD_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_OB1_RESETVAL    (0x00000000u)

/* SG0_SIG_OUT */

#define CSL_TAC_DATA_SG0_SIG_OUT_WORD_MASK (0xFFFFFFFFu)
#define CSL_TAC_DATA_SG0_SIG_OUT_WORD_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_OUT_WORD_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_OUT_RESETVAL (0x00000000u)




/* SG0_SIG_INPUT */


#define CSL_TAC_DATA_SG0_SIG_INPUT_SIG_DATA_MASK (0x000FFFFFu)
#define CSL_TAC_DATA_SG0_SIG_INPUT_SIG_DATA_SHIFT (0x00000000u)
#define CSL_TAC_DATA_SG0_SIG_INPUT_SIG_DATA_RESETVAL (0x00000000u)

#define CSL_TAC_DATA_SG0_SIG_INPUT_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif

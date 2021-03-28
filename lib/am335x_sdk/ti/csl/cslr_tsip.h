/********************************************************************
* Copyright (C) 2003-2008 Texas Instruments Incorporated.
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
#ifndef CSLR_TSIP_H
#define CSLR_TSIP_H

#include <ti/csl/cslr.h>

#include <ti/csl/tistdtypes.h>

/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Modified CH0ERRS - CH7ERRS to an array of 8 
 *      b) Modified XMTCHNEN_0 - XMTCHNEN_7 to an array of 8
 *      c) Modified RCVCHNEN_0 - RCVCHNEN_7 to an array of 8
 *      d) Modified XMTCHNCON_0_ABA-XMTCHNCON_7_BFC and made it an array.
 *      e) Modified RCVCHNCON_0_ABA-RCVCHNCON_7_BFC and made it an array.
 */

/* Minimum unit = 1 byte */

/**************************************************************************\
 * Register Overlay Structure for Error.
\**************************************************************************/
typedef struct  
{
    volatile Uint32 ERRCTL;
    volatile Uint32 ERRCNT;
    volatile Uint32 ERRQ;
    volatile Uint8  RSVD[4];
}CSL_TsipErrRegs;

/**************************************************************************\
* Register Overlay Structure for XCHEN
\**************************************************************************/
typedef struct  
{
    volatile Uint32 XCHEN;
    volatile Uint8  RSVD[28];
} CSL_TsipXchenRegs;

/**************************************************************************\
* Register Overlay Structure for RCHEN
\**************************************************************************/
typedef struct  
{
    volatile Uint32 RCHEN;
    volatile Uint8  RSVD[28];
} CSL_TsipRchenRegs;

/**************************************************************************\
* Register Overlay Structure for DXCH
\**************************************************************************/
typedef struct  
{
    volatile Uint32 ABASE;
    volatile Uint32 AFALLOC;
    volatile Uint32 AFSIZE;
    volatile Uint32 AFCNT;
    volatile Uint8  RSVD0[16];
    volatile Uint32 BBASE;
    volatile Uint32 BFALLOC;
    volatile Uint32 BFSIZE;
    volatile Uint32 BFCNT;
    volatile Uint8  RSVD1[16];
} CSL_TsipDxchRegs;

/**************************************************************************\
* Register Overlay Structure for DRCH
\**************************************************************************/
typedef struct  
{
    volatile Uint32 ABASE;
    volatile Uint32 AFALLOC;
    volatile Uint32 AFSIZE;
    volatile Uint32 AFCNT;
    volatile Uint8  RSVD[16];
    volatile Uint32 BBASE;
    volatile Uint32 BFALLOC;
    volatile Uint32 BFSIZE;
    volatile Uint32 BFCNT;
    volatile Uint8  RSVD1[16];
} CSL_TsipDrchRegs;

/**************************************************************************\
* Register Overlay Structure for XBM
\**************************************************************************/
typedef struct  {
    volatile Uint32 XBMA[64];
    volatile Uint32 XBMB[64];
} CSL_TsipXbmRegs;

/**************************************************************************\
* Register Overlay Structure for RBM
\**************************************************************************/
typedef struct  {
    volatile Uint32 RBMA[64];
    volatile Uint32 RBMB[64];
} CSL_TsipRbmRegs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 MOD_VER;
    volatile Uint32 EMU_TST;
    volatile Uint32 RESET;
    volatile Uint8 RSVD0[116];
    volatile Uint32 SIU_GCTL;
    volatile Uint8 RSVD1[28];
    volatile Uint32 SIU_XMTSEL;
    volatile Uint32 SIU_XMTCTL;
    volatile Uint32 SIU_XMTSIZ;
    volatile Uint8 RSVD2[20];
    volatile Uint32 SIU_RCVSEL;
    volatile Uint32 SIU_RCVCTL;
    volatile Uint32 SIU_RCVSIZ;
    volatile Uint8 RSVD3[52];
    volatile Uint32 TDMU_GCTL;
    volatile Uint32 XMTFRFC;
    volatile Uint32 RCVFRFC;
    volatile Uint32 TDMU_GECTL;
    volatile Uint32 XMTCBAS;
    volatile Uint32 RCVCBAS;
    volatile Uint8 RSVD4[104];
    volatile Uint32 DMATCU_GCTL;
    volatile Uint32 XMTTDR;
    volatile Uint32 RCVTDR;
    volatile Uint8 RSVD5[4];
    volatile Uint32 XMTCCAS;
    volatile Uint32 RCVCCAS;
    volatile Uint8 RSVD6[104];
#ifdef CSL_MODIFICATION    
    volatile Uint32 CH0ECR;
    volatile Uint32 CH0ERRS;
    volatile Uint32 CH0EQR;
    volatile Uint8 RSVD7[4];
    volatile Uint32 CH1ECR;
    volatile Uint32 CH1ERRS;
    volatile Uint32 CH1EQR;
    volatile Uint8 RSVD8[4];
    volatile Uint32 CH2ECR;
    volatile Uint32 CH2ERRS;
    volatile Uint32 CH2EQR;
    volatile Uint8 RSVD9[4];
    volatile Uint32 CH3ECR;
    volatile Uint32 CH3ERRS;
    volatile Uint32 CH3EQR;
    volatile Uint8 RSVD10[4];
    volatile Uint32 CH4ECR;
    volatile Uint32 CH4ERRS;
    volatile Uint32 CH4EQR;
    volatile Uint8 RSVD11[4];
    volatile Uint32 CH5ECR;
    volatile Uint32 CH5ERRS;
    volatile Uint32 CH5EQR;
    volatile Uint8 RSVD12[4];
    volatile Uint32 CH6ECR;
    volatile Uint32 CH6ERRS;
    volatile Uint32 CH6EQR;
    volatile Uint8 RSVD13[4];
    volatile Uint32 CH7ECR;
    volatile Uint32 CH7ERRS;
    volatile Uint32 CH7EQR;
    volatile Uint8 RSVD14[1412];
#else
    CSL_TsipErrRegs ERR[8];
    volatile Uint8 RSVD14[1408];
#endif
#ifdef CSL_MODIFCATION     
    volatile Uint32 XMTCHNEN_0;
    volatile Uint8 RSVD15[28];
    volatile Uint32 XMTCHNEN_1;
    volatile Uint8 RSVD16[28];
    volatile Uint32 XMTCHNEN_2;
    volatile Uint8 RSVD17[28];
    volatile Uint32 XMTCHNEN_3;
    volatile Uint8 RSVD18[28];
    volatile Uint32 XMTCHNEN_4;
    volatile Uint8 RSVD19[28];
    volatile Uint32 XMTCHNEN_5;
    volatile Uint8 RSVD20[28];
    volatile Uint32 XMTCHNEN_6;
    volatile Uint8 RSVD21[28];
    volatile Uint32 XMTCHNEN_7;
    volatile Uint8 RSVD22[796];
#else
    CSL_TsipXchenRegs  XCHEN[8]; 
    volatile Uint8     RSVD22[768];
#endif
#ifdef CSL_MODIFCATION
    volatile Uint32 RCVCHNEN_0;
    volatile Uint8 RSVD23[28];
    volatile Uint32 RCVCHNEN_1;
    volatile Uint8 RSVD24[28];
    volatile Uint32 RCVCHNEN_2;
    volatile Uint8 RSVD25[28];
    volatile Uint32 RCVCHNEN_3;
    volatile Uint8 RSVD26[28];
    volatile Uint32 RCVCHNEN_4;
    volatile Uint8 RSVD27[28];
    volatile Uint32 RCVCHNEN_5;
    volatile Uint8 RSVD28[28];
    volatile Uint32 RCVCHNEN_6;
    volatile Uint8 RSVD29[28];
    volatile Uint32 RCVCHNEN_7;
    volatile Uint8 RSVD30[796];
#else
    CSL_TsipRchenRegs RCHEN[8];
    volatile Uint8    RSVD30[768];
#endif
#ifdef CSL_MODIFCATION    
    volatile Uint32 XMTCHNCON_0_ABA;
    volatile Uint32 XMTCHNCON_0_AFA;
    volatile Uint32 XMTCHNCON_0_AFS;
    volatile Uint32 XMTCHNCON_0_AFC;
    volatile Uint8 RSVD31[16];
    volatile Uint32 XMTCHNCON_0_BBA;
    volatile Uint32 XMTCHNCON_0_BFA;
    volatile Uint32 XMTCHNCON_0_BFS;
    volatile Uint32 XMTCHNCON_0_BFC;
    volatile Uint8 RSVD32[16];
    volatile Uint32 XMTCHNCON_1_ABA;
    volatile Uint32 XMTCHNCON_1_AFA;
    volatile Uint32 XMTCHNCON_1_AFS;
    volatile Uint32 XMTCHNCON_1_AFC;
    volatile Uint8 RSVD33[16];
    volatile Uint32 XMTCHNCON_1_BBA;
    volatile Uint32 XMTCHNCON_1_BFA;
    volatile Uint32 XMTCHNCON_1_BFS;
    volatile Uint32 XMTCHNCON_1_BFC;
    volatile Uint8 RSVD34[16];
    volatile Uint32 XMTCHNCON_2_ABA;
    volatile Uint32 XMTCHNCON_2_AFA;
    volatile Uint32 XMTCHNCON_2_AFS;
    volatile Uint32 XMTCHNCON_2_AFC;
    volatile Uint8 RSVD35[16];
    volatile Uint32 XMTCHNCON_2_BBA;
    volatile Uint32 XMTCHNCON_2_BFA;
    volatile Uint32 XMTCHNCON_2_BFS;
    volatile Uint32 XMTCHNCON_2_BFC;
    volatile Uint8 RSVD36[16];
    volatile Uint32 XMTCHNCON_3_ABA;
    volatile Uint32 XMTCHNCON_3_AFA;
    volatile Uint32 XMTCHNCON_3_AFS;
    volatile Uint32 XMTCHNCON_3_AFC;
    volatile Uint8 RSVD37[16];
    volatile Uint32 XMTCHNCON_3_BBA;
    volatile Uint32 XMTCHNCON_3_BFA;
    volatile Uint32 XMTCHNCON_3_BFS;
    volatile Uint32 XMTCHNCON_3_BFC;
    volatile Uint8 RSVD38[16];
    volatile Uint32 XMTCHNCON_4_ABA;
    volatile Uint32 XMTCHNCON_4_AFA;
    volatile Uint32 XMTCHNCON_4_AFS;
    volatile Uint32 XMTCHNCON_4_AFC;
    volatile Uint8 RSVD39[16];
    volatile Uint32 XMTCHNCON_4_BBA;
    volatile Uint32 XMTCHNCON_4_BFA;
    volatile Uint32 XMTCHNCON_4_BFS;
    volatile Uint32 XMTCHNCON_4_BFC;
    volatile Uint8 RSVD40[16];
    volatile Uint32 XMTCHNCON_5_ABA;
    volatile Uint32 XMTCHNCON_5_AFA;
    volatile Uint32 XMTCHNCON_5_AFS;
    volatile Uint32 XMTCHNCON_5_AFC;
    volatile Uint8 RSVD41[16];
    volatile Uint32 XMTCHNCON_5_BBA;
    volatile Uint32 XMTCHNCON_5_BFA;
    volatile Uint32 XMTCHNCON_5_BFS;
    volatile Uint32 XMTCHNCON_5_BFC;
    volatile Uint8 RSVD42[16];
    volatile Uint32 XMTCHNCON_6_ABA;
    volatile Uint32 XMTCHNCON_6_AFA;
    volatile Uint32 XMTCHNCON_6_AFS;
    volatile Uint32 XMTCHNCON_6_AFC;
    volatile Uint8 RSVD43[16];
    volatile Uint32 XMTCHNCON_6_BBA;
    volatile Uint32 XMTCHNCON_6_BFA;
    volatile Uint32 XMTCHNCON_6_BFS;
    volatile Uint32 XMTCHNCON_6_BFC;
    volatile Uint8 RSVD44[16];
    volatile Uint32 XMTCHNCON_7_ABA;
    volatile Uint32 XMTCHNCON_7_AFA;
    volatile Uint32 XMTCHNCON_7_AFS;
    volatile Uint32 XMTCHNCON_7_AFC;
    volatile Uint8 RSVD45[16];
    volatile Uint32 XMTCHNCON_7_BBA;
    volatile Uint32 XMTCHNCON_7_BFA;
    volatile Uint32 XMTCHNCON_7_BFS;
    volatile Uint32 XMTCHNCON_7_BFC;
    volatile Uint8 RSVD46[1552];
#else
    CSL_TsipDxchRegs DXCH[8];
    volatile Uint8   RSVD46[1536];
#endif
#ifdef CSL_MODIFCATION    
    volatile Uint32 RCVCHNCON_0_ABA;
    volatile Uint32 RCVCHNCON_0_AFA;
    volatile Uint32 RCVCHNCON_0_AFS;
    volatile Uint32 RCVCHNCON_0_AFC;
    volatile Uint8 RSVD47[16];
    volatile Uint32 RCVCHNCON_0_BBA;
    volatile Uint32 RCVCHNCON_0_BFA;
    volatile Uint32 RCVCHNCON_0_BFS;
    volatile Uint32 RCVCHNCON_0_BFC;
    volatile Uint8 RSVD48[16];
    volatile Uint32 RCVCHNCON_1_ABA;
    volatile Uint32 RCVCHNCON_1_AFA;
    volatile Uint32 RCVCHNCON_1_AFS;
    volatile Uint32 RCVCHNCON_1_AFC;
    volatile Uint8 RSVD49[16];
    volatile Uint32 RCVCHNCON_1_BBA;
    volatile Uint32 RCVCHNCON_1_BFA;
    volatile Uint32 RCVCHNCON_1_BFS;
    volatile Uint32 RCVCHNCON_1_BFC;
    volatile Uint8 RSVD50[16];
    volatile Uint32 RCVCHNCON_2_ABA;
    volatile Uint32 RCVCHNCON_2_AFA;
    volatile Uint32 RCVCHNCON_2_AFS;
    volatile Uint32 RCVCHNCON_2_AFC;
    volatile Uint8 RSVD51[16];
    volatile Uint32 RCVCHNCON_2_BBA;
    volatile Uint32 RCVCHNCON_2_BFA;
    volatile Uint32 RCVCHNCON_2_BFS;
    volatile Uint32 RCVCHNCON_2_BFC;
    volatile Uint8 RSVD52[16];
    volatile Uint32 RCVCHNCON_3_ABA;
    volatile Uint32 RCVCHNCON_3_AFA;
    volatile Uint32 RCVCHNCON_3_AFS;
    volatile Uint32 RCVCHNCON_3_AFC;
    volatile Uint8 RSVD53[16];
    volatile Uint32 RCVCHNCON_3_BBA;
    volatile Uint32 RCVCHNCON_3_BFA;
    volatile Uint32 RCVCHNCON_3_BFS;
    volatile Uint32 RCVCHNCON_3_BFC;
    volatile Uint8 RSVD54[16];
    volatile Uint32 RCVCHNCON_4_ABA;
    volatile Uint32 RCVCHNCON_4_AFA;
    volatile Uint32 RCVCHNCON_4_AFS;
    volatile Uint32 RCVCHNCON_4_AFC;
    volatile Uint8 RSVD55[16];
    volatile Uint32 RCVCHNCON_4_BBA;
    volatile Uint32 RCVCHNCON_4_BFA;
    volatile Uint32 RCVCHNCON_4_BFS;
    volatile Uint32 RCVCHNCON_4_BFC;
    volatile Uint8 RSVD56[16];
    volatile Uint32 RCVCHNCON_5_ABA;
    volatile Uint32 RCVCHNCON_5_AFA;
    volatile Uint32 RCVCHNCON_5_AFS;
    volatile Uint32 RCVCHNCON_5_AFC;
    volatile Uint8 RSVD57[16];
    volatile Uint32 RCVCHNCON_5_BBA;
    volatile Uint32 RCVCHNCON_5_BFA;
    volatile Uint32 RCVCHNCON_5_BFS;
    volatile Uint32 RCVCHNCON_5_BFC;
    volatile Uint8 RSVD58[16];
    volatile Uint32 RCVCHNCON_6_ABA;
    volatile Uint32 RCVCHNCON_6_AFA;
    volatile Uint32 RCVCHNCON_6_AFS;
    volatile Uint32 RCVCHNCON_6_AFC;
    volatile Uint8 RSVD59[16];
    volatile Uint32 RCVCHNCON_6_BBA;
    volatile Uint32 RCVCHNCON_6_BFA;
    volatile Uint32 RCVCHNCON_6_BFS;
    volatile Uint32 RCVCHNCON_6_BFC;
    volatile Uint8 RSVD60[16];
    volatile Uint32 RCVCHNCON_7_ABA;
    volatile Uint32 RCVCHNCON_7_AFA;
    volatile Uint32 RCVCHNCON_7_AFS;
    volatile Uint32 RCVCHNCON_7_AFC;
    volatile Uint8 RSVD61[16];
    volatile Uint32 RCVCHNCON_7_BBA;
    volatile Uint32 RCVCHNCON_7_BFA;
    volatile Uint32 RCVCHNCON_7_BFS;
    volatile Uint32 RCVCHNCON_7_BFC;
#else
    CSL_TsipDrchRegs DRCH[8];
#endif
    volatile Uint8 RSVD62[26112];
#ifdef CSL_MODIFCATION
    volatile Uint32 XCH0BMA[64];
    volatile Uint32 XCH0BMB[64];
    volatile Uint32 XCH1BMA[64];
    volatile Uint32 XCH1BMB[64];
    volatile Uint32 XCH2BMA[64];
    volatile Uint32 XCH2BMB[64];
    volatile Uint32 XCH3BMA[64];
    volatile Uint32 XCH3BMB[64];
    volatile Uint32 XCH4BMA[64];
    volatile Uint32 XCH4BMB[64];
    volatile Uint32 XCH5BMA[64];
    volatile Uint32 XCH5BMB[64];
    volatile Uint32 XCH6BMA[64];
    volatile Uint32 XCH6BMB[64];
    volatile Uint32 XCH7BMA[64];
    volatile Uint32 XCH7BMB[64];
#else
    CSL_TsipXbmRegs XBM[8];
#endif
    volatile Uint8 RSVD63[12288];
#ifdef CSL_MODIFCATION
    volatile Uint32 RCH0BMA[64];
    volatile Uint32 RCH0BMB[64];
    volatile Uint32 RCH1BMA[64];
    volatile Uint32 RCH1BMB[64];
    volatile Uint32 RCH2BMA[64];
    volatile Uint32 RCH2BMB[64];
    volatile Uint32 RCH3BMA[64];
    volatile Uint32 RCH3BMB[64];
    volatile Uint32 RCH4BMA[64];
    volatile Uint32 RCH4BMB[64];
    volatile Uint32 RCH5BMA[64];
    volatile Uint32 RCH5BMB[64];
    volatile Uint32 RCH6BMA[64];
    volatile Uint32 RCH6BMB[64];
    volatile Uint32 RCH7BMA[64];
    volatile Uint32 RCH7BMB[64];
#else
    CSL_TsipRbmRegs RBM[8];
#endif
    volatile Uint8 RSVD64[12288];
    volatile Uint32 XCH0BPI[64];
    volatile Uint8 RSVD65[768];
    volatile Uint32 XCH0BPO[64];
    volatile Uint8 RSVD66[768];
    volatile Uint32 XCH1BPI[64];
    volatile Uint8 RSVD67[768];
    volatile Uint32 XCH1BPO[64];
    volatile Uint8 RSVD68[768];
    volatile Uint32 XCH2BPI[64];
    volatile Uint8 RSVD69[768];
    volatile Uint32 XCH2BPO[64];
    volatile Uint8 RSVD70[768];
    volatile Uint32 XCH3BPI[64];
    volatile Uint8 RSVD71[768];
    volatile Uint32 XCH3BPO[64];
    volatile Uint8 RSVD72[768];
    volatile Uint32 XCH4BPI[64];
    volatile Uint8 RSVD73[768];
    volatile Uint32 XCH4BPO[64];
    volatile Uint8 RSVD74[768];
    volatile Uint32 XCH5BPI[64];
    volatile Uint8 RSVD75[768];
    volatile Uint32 XCH5BPO[64];
    volatile Uint8 RSVD76[768];
    volatile Uint32 XCH6BPI[64];
    volatile Uint8 RSVD77[768];
    volatile Uint32 XCH6BPO[64];
    volatile Uint8 RSVD78[768];
    volatile Uint32 XCH7BPI[64];
    volatile Uint8 RSVD79[768];
    volatile Uint32 XCH7BPO[64];
    volatile Uint8 RSVD80[17152];
    volatile Uint32 RCH0BPI[64];
    volatile Uint8 RSVD81[768];
    volatile Uint32 RCH0BPO[64];
    volatile Uint8 RSVD82[768];
    volatile Uint32 RCH1BPI[64];
    volatile Uint8 RSVD83[768];
    volatile Uint32 RCH1BPO[64];
    volatile Uint8 RSVD84[768];
    volatile Uint32 RCH2BPI[64];
    volatile Uint8 RSVD85[768];
    volatile Uint32 RCH2BPO[64];
    volatile Uint8 RSVD86[768];
    volatile Uint32 RCH3BPI[64];
    volatile Uint8 RSVD87[768];
    volatile Uint32 RCH3BPO[64];
    volatile Uint8 RSVD88[768];
    volatile Uint32 RCH4BPI[64];
    volatile Uint8 RSVD89[768];
    volatile Uint32 RCH4BPO[64];
    volatile Uint8 RSVD90[768];
    volatile Uint32 RCH5BPI[64];
    volatile Uint8 RSVD91[768];
    volatile Uint32 RCH5BPO[64];
    volatile Uint8 RSVD92[768];
    volatile Uint32 RCH6BPI[64];
    volatile Uint8 RSVD93[768];
    volatile Uint32 RCH6BPO[64];
    volatile Uint8 RSVD94[768];
    volatile Uint32 RCH7BPI[64];
    volatile Uint8 RSVD95[768];
    volatile Uint32 RCH7BPO[64];
} CSL_TsipRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* MOD_VER */

#define CSL_TSIP_MOD_VER_REVISION_MASK   (0xFFFFFFFFu)
#define CSL_TSIP_MOD_VER_REVISION_SHIFT  (0x00000000u)
#define CSL_TSIP_MOD_VER_REVISION_RESETVAL (0x00000000u)

#define CSL_TSIP_MOD_VER_RESETVAL        (0x00000000u)

/* EMU_TST */

#define CSL_TSIP_EMU_TST_TSTDIV_MASK     (0x01F00000u)
#define CSL_TSIP_EMU_TST_TSTDIV_SHIFT    (0x00000014u)
#define CSL_TSIP_EMU_TST_TSTDIV_RESETVAL (0x00000000u)

#define CSL_TSIP_EMU_TST_TSTCLK_MASK     (0x00080000u)
#define CSL_TSIP_EMU_TST_TSTCLK_SHIFT    (0x00000013u)
#define CSL_TSIP_EMU_TST_TSTCLK_RESETVAL (0x00000000u)

#define CSL_TSIP_EMU_TST_IOLB_MASK       (0x00040000u)
#define CSL_TSIP_EMU_TST_IOLB_SHIFT      (0x00000012u)
#define CSL_TSIP_EMU_TST_IOLB_RESETVAL   (0x00000000u)

#define CSL_TSIP_EMU_TST_LBS_MASK        (0x00020000u)
#define CSL_TSIP_EMU_TST_LBS_SHIFT       (0x00000011u)
#define CSL_TSIP_EMU_TST_LBS_RESETVAL    (0x00000000u)

#define CSL_TSIP_EMU_TST_SIUTST_MASK     (0x00010000u)
#define CSL_TSIP_EMU_TST_SIUTST_SHIFT    (0x00000010u)
#define CSL_TSIP_EMU_TST_SIUTST_RESETVAL (0x00000000u)

#define CSL_TSIP_EMU_TST_SOFT_MASK       (0x00000002u)
#define CSL_TSIP_EMU_TST_SOFT_SHIFT      (0x00000001u)
#define CSL_TSIP_EMU_TST_SOFT_RESETVAL   (0x00000000u)

#define CSL_TSIP_EMU_TST_FREE_MASK       (0x00000001u)
#define CSL_TSIP_EMU_TST_FREE_SHIFT      (0x00000000u)
#define CSL_TSIP_EMU_TST_FREE_RESETVAL   (0x00000001u)

#define CSL_TSIP_EMU_TST_RESETVAL        (0x00000001u)

/* RESET */

#define CSL_TSIP_RESET_DMARST_MASK       (0x00000002u)
#define CSL_TSIP_RESET_DMARST_SHIFT      (0x00000001u)
#define CSL_TSIP_RESET_DMARST_RESETVAL   (0x00000000u)

#define CSL_TSIP_RESET_SIURST_MASK       (0x00000001u)
#define CSL_TSIP_RESET_SIURST_SHIFT      (0x00000000u)
#define CSL_TSIP_RESET_SIURST_RESETVAL   (0x00000000u)

#define CSL_TSIP_RESET_RESETVAL          (0x00000000u)

/* SIU_GCTL */

#define CSL_TSIP_SIU_GCTL_CLKD_MASK      (0x00000010u)
#define CSL_TSIP_SIU_GCTL_CLKD_SHIFT     (0x00000004u)
#define CSL_TSIP_SIU_GCTL_CLKD_RESETVAL  (0x00000000u)

#define CSL_TSIP_SIU_GCTL_RCVENB_MASK    (0x00000002u)
#define CSL_TSIP_SIU_GCTL_RCVENB_SHIFT   (0x00000001u)
#define CSL_TSIP_SIU_GCTL_RCVENB_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_GCTL_XMTENB_MASK    (0x00000001u)
#define CSL_TSIP_SIU_GCTL_XMTENB_SHIFT   (0x00000000u)
#define CSL_TSIP_SIU_GCTL_XMTENB_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_GCTL_RESETVAL       (0x00000000u)

/* SIU_XMTSEL */

#define CSL_TSIP_SIU_XMTSEL_XMTSRC_MASK  (0x00000001u)
#define CSL_TSIP_SIU_XMTSEL_XMTSRC_SHIFT (0x00000000u)
#define CSL_TSIP_SIU_XMTSEL_XMTSRC_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_XMTSEL_RESETVAL     (0x00000000u)

/* SIU_XMTCTL */

#define CSL_TSIP_SIU_XMTCTL_XMTDATD_MASK (0x3FFF0000u)
#define CSL_TSIP_SIU_XMTCTL_XMTDATD_SHIFT (0x00000010u)
#define CSL_TSIP_SIU_XMTCTL_XMTDATD_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_XMTCTL_XMTDLY_MASK  (0x00000400u)
#define CSL_TSIP_SIU_XMTCTL_XMTDLY_SHIFT (0x0000000Au)
#define CSL_TSIP_SIU_XMTCTL_XMTDLY_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_XMTCTL_XMTDIS_MASK  (0x00000300u)
#define CSL_TSIP_SIU_XMTCTL_XMTDIS_SHIFT (0x00000008u)
#define CSL_TSIP_SIU_XMTCTL_XMTDIS_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_XMTCTL_XMTFSYNCP_MASK (0x00000080u)
#define CSL_TSIP_SIU_XMTCTL_XMTFSYNCP_SHIFT (0x00000007u)
#define CSL_TSIP_SIU_XMTCTL_XMTFSYNCP_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_XMTCTL_XMTFCLKP_MASK (0x00000040u)
#define CSL_TSIP_SIU_XMTCTL_XMTFCLKP_SHIFT (0x00000006u)
#define CSL_TSIP_SIU_XMTCTL_XMTFCLKP_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_XMTCTL_XMTDCLKP_MASK (0x00000020u)
#define CSL_TSIP_SIU_XMTCTL_XMTDCLKP_SHIFT (0x00000005u)
#define CSL_TSIP_SIU_XMTCTL_XMTDCLKP_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_XMTCTL_XMTDATR_MASK (0x00000006u)
#define CSL_TSIP_SIU_XMTCTL_XMTDATR_SHIFT (0x00000001u)
#define CSL_TSIP_SIU_XMTCTL_XMTDATR_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_XMTCTL_XMTCLKM_MASK (0x00000001u)
#define CSL_TSIP_SIU_XMTCTL_XMTCLKM_SHIFT (0x00000000u)
#define CSL_TSIP_SIU_XMTCTL_XMTCLKM_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_XMTCTL_RESETVAL     (0x00000000u)

/* SIU_XMTSIZ */

#define CSL_TSIP_SIU_XMTSIZ_XMTFCNT_MASK (0x00FF0000u)
#define CSL_TSIP_SIU_XMTSIZ_XMTFCNT_SHIFT (0x00000010u)
#define CSL_TSIP_SIU_XMTSIZ_XMTFCNT_RESETVAL (0x00000003u)

#define CSL_TSIP_SIU_XMTSIZ_XMTFSIZ_MASK (0x0000007Fu)
#define CSL_TSIP_SIU_XMTSIZ_XMTFSIZ_SHIFT (0x00000000u)
#define CSL_TSIP_SIU_XMTSIZ_XMTFSIZ_RESETVAL (0x0000007Fu)

#define CSL_TSIP_SIU_XMTSIZ_RESETVAL     (0x0003007Fu)

/* SIU_RCVSEL */

#define CSL_TSIP_SIU_RCVSEL_RCVSRC_MASK  (0x00000001u)
#define CSL_TSIP_SIU_RCVSEL_RCVSRC_SHIFT (0x00000000u)
#define CSL_TSIP_SIU_RCVSEL_RCVSRC_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_RCVSEL_RESETVAL     (0x00000000u)

/* SIU_RCVCTL */

#define CSL_TSIP_SIU_RCVCTL_RCVDATD_MASK (0x3FFF0000u)
#define CSL_TSIP_SIU_RCVCTL_RCVDATD_SHIFT (0x00000010u)
#define CSL_TSIP_SIU_RCVCTL_RCVDATD_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_RCVCTL_RCVFSYNCP_MASK (0x00000080u)
#define CSL_TSIP_SIU_RCVCTL_RCVFSYNCP_SHIFT (0x00000007u)
#define CSL_TSIP_SIU_RCVCTL_RCVFSYNCP_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_RCVCTL_RCVFCLKP_MASK (0x00000040u)
#define CSL_TSIP_SIU_RCVCTL_RCVFCLKP_SHIFT (0x00000006u)
#define CSL_TSIP_SIU_RCVCTL_RCVFCLKP_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_RCVCTL_RCVDCLKP_MASK (0x00000020u)
#define CSL_TSIP_SIU_RCVCTL_RCVDCLKP_SHIFT (0x00000005u)
#define CSL_TSIP_SIU_RCVCTL_RCVDCLKP_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_RCVCTL_RCVDATR_MASK (0x00000006u)
#define CSL_TSIP_SIU_RCVCTL_RCVDATR_SHIFT (0x00000001u)
#define CSL_TSIP_SIU_RCVCTL_RCVDATR_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_RCVCTL_RCVCLKM_MASK (0x00000001u)
#define CSL_TSIP_SIU_RCVCTL_RCVCLKM_SHIFT (0x00000000u)
#define CSL_TSIP_SIU_RCVCTL_RCVCLKM_RESETVAL (0x00000000u)

#define CSL_TSIP_SIU_RCVCTL_RESETVAL     (0x00000000u)

/* SIU_RCVSIZ */

#define CSL_TSIP_SIU_RCVSIZ_RCVFCNT_MASK (0x00FF0000u)
#define CSL_TSIP_SIU_RCVSIZ_RCVFCNT_SHIFT (0x00000010u)
#define CSL_TSIP_SIU_RCVSIZ_RCVFCNT_RESETVAL (0x00000003u)

#define CSL_TSIP_SIU_RCVSIZ_RCVFSIZ_MASK (0x0000007Fu)
#define CSL_TSIP_SIU_RCVSIZ_RCVFSIZ_SHIFT (0x00000000u)
#define CSL_TSIP_SIU_RCVSIZ_RCVFSIZ_RESETVAL (0x0000007Fu)

#define CSL_TSIP_SIU_RCVSIZ_RESETVAL     (0x0003007Fu)

/* TDMU_GCTL */

#define CSL_TSIP_TDMU_GCTL_DMAENB_MASK   (0x00000001u)
#define CSL_TSIP_TDMU_GCTL_DMAENB_SHIFT  (0x00000000u)
#define CSL_TSIP_TDMU_GCTL_DMAENB_RESETVAL (0x00000000u)

#define CSL_TSIP_TDMU_GCTL_RESETVAL      (0x00000000u)

/* XMTFRFC */

#define CSL_TSIP_XMTFRFC_TXFRFC_MASK     (0x00FFFFFFu)
#define CSL_TSIP_XMTFRFC_TXFRFC_SHIFT    (0x00000000u)
#define CSL_TSIP_XMTFRFC_TXFRFC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTFRFC_RESETVAL        (0x00000000u)

/* RCVFRFC */

#define CSL_TSIP_RCVFRFC_RXFRFC_MASK     (0x00FFFFFFu)
#define CSL_TSIP_RCVFRFC_RXFRFC_SHIFT    (0x00000000u)
#define CSL_TSIP_RCVFRFC_RXFRFC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVFRFC_RESETVAL        (0x00000000u)

/* TDMU_GECTL */

#define CSL_TSIP_TDMU_GECTL_BEND_MASK    (0x00000001u)
#define CSL_TSIP_TDMU_GECTL_BEND_SHIFT   (0x00000000u)
#define CSL_TSIP_TDMU_GECTL_BEND_RESETVAL (0x00000000u)

#define CSL_TSIP_TDMU_GECTL_RESETVAL     (0x00000000u)

/* XMTCBAS */

#define CSL_TSIP_XMTCBAS_TXTDMAACTSTS_MASK (0x0000FFFFu)
#define CSL_TSIP_XMTCBAS_TXTDMAACTSTS_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCBAS_TXTDMAACTSTS_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCBAS_RESETVAL        (0x00000000u)

/* RCVCBAS */

#define CSL_TSIP_RCVCBAS_RXTDMAACTSTS_MASK (0x0000FFFFu)
#define CSL_TSIP_RCVCBAS_RXTDMAACTSTS_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCBAS_RXTDMAACTSTS_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCBAS_RESETVAL        (0x00000000u)

/* DMATCU_GCTL */

#define CSL_TSIP_DMATCU_GCTL_MAXPRI_MASK (0x00000070u)
#define CSL_TSIP_DMATCU_GCTL_MAXPRI_SHIFT (0x00000004u)
#define CSL_TSIP_DMATCU_GCTL_MAXPRI_RESETVAL (0x00000007u)

#define CSL_TSIP_DMATCU_GCTL_BASEPRI_MASK (0x00000007u)
#define CSL_TSIP_DMATCU_GCTL_BASEPRI_SHIFT (0x00000000u)
#define CSL_TSIP_DMATCU_GCTL_BASEPRI_RESETVAL (0x00000007u)

#define CSL_TSIP_DMATCU_GCTL_RESETVAL    (0x00000077u)

/* XMTTDR */

#define CSL_TSIP_XMTTDR_XMTFSINT_MASK    (0x0000C000u)
#define CSL_TSIP_XMTTDR_XMTFSINT_SHIFT   (0x0000000Eu)
#define CSL_TSIP_XMTTDR_XMTFSINT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTTDR_XMTFRINT_MASK    (0x00003000u)
#define CSL_TSIP_XMTTDR_XMTFRINT_SHIFT   (0x0000000Cu)
#define CSL_TSIP_XMTTDR_XMTFRINT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTTDR_XMTFDLY_MASK     (0x0000007Fu)
#define CSL_TSIP_XMTTDR_XMTFDLY_SHIFT    (0x00000000u)
#define CSL_TSIP_XMTTDR_XMTFDLY_RESETVAL (0x0000007Fu)

#define CSL_TSIP_XMTTDR_RESETVAL         (0x0000007Fu)

/* RCVTDR */

#define CSL_TSIP_RCVTDR_RCVFSINT_MASK    (0x0000C000u)
#define CSL_TSIP_RCVTDR_RCVFSINT_SHIFT   (0x0000000Eu)
#define CSL_TSIP_RCVTDR_RCVFSINT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVTDR_RCVFRINT_MASK    (0x00003000u)
#define CSL_TSIP_RCVTDR_RCVFRINT_SHIFT   (0x0000000Cu)
#define CSL_TSIP_RCVTDR_RCVFRINT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVTDR_RCVFDLY_MASK     (0x0000007Fu)
#define CSL_TSIP_RCVTDR_RCVFDLY_SHIFT    (0x00000000u)
#define CSL_TSIP_RCVTDR_RCVFDLY_RESETVAL (0x0000007Fu)

#define CSL_TSIP_RCVTDR_RESETVAL         (0x0000007Fu)

/* XMTCCAS */

#define CSL_TSIP_XMTCCAS_TXTCUACTSTS_MASK (0x0000FFFFu)
#define CSL_TSIP_XMTCCAS_TXTCUACTSTS_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCCAS_TXTCUACTSTS_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCCAS_RESETVAL        (0x00000000u)

/* RCVCCAS */

#define CSL_TSIP_RCVCCAS_RXTCUACTSTS_MASK (0x0000FFFFu)
#define CSL_TSIP_RCVCCAS_RXTCUACTSTS_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCCAS_RXTCUACTSTS_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCCAS_RESETVAL        (0x00000000u)

/* CH0ECR */

#define CSL_TSIP_CH0ECR_CH0CEQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH0ECR_CH0CEQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH0ECR_CH0CEQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH0ECR_CH0CLRQ_MASK     (0x00000002u)
#define CSL_TSIP_CH0ECR_CH0CLRQ_SHIFT    (0x00000001u)
#define CSL_TSIP_CH0ECR_CH0CLRQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH0ECR_CH0POPQ_MASK     (0x00000001u)
#define CSL_TSIP_CH0ECR_CH0POPQ_SHIFT    (0x00000000u)
#define CSL_TSIP_CH0ECR_CH0POPQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH0ECR_RESETVAL         (0x00000000u)

/* CH0ERRS */

#define CSL_TSIP_CH0ERRS_CH0EQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH0ERRS_CH0EQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH0ERRS_CH0EQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH0ERRS_CH0ECNT_MASK    (0x0000000Fu)
#define CSL_TSIP_CH0ERRS_CH0ECNT_SHIFT   (0x00000000u)
#define CSL_TSIP_CH0ERRS_CH0ECNT_RESETVAL (0x00000000u)

#define CSL_TSIP_CH0ERRS_RESETVAL        (0x00000000u)

/* CH0EQR */

#define CSL_TSIP_CH0EQR_CH0ERRC_MASK     (0xFF000000u)
#define CSL_TSIP_CH0EQR_CH0ERRC_SHIFT    (0x00000018u)
#define CSL_TSIP_CH0EQR_CH0ERRC_RESETVAL (0x00000000u)

#define CSL_TSIP_CH0EQR_CH0INFO_MASK     (0x00FFFFFFu)
#define CSL_TSIP_CH0EQR_CH0INFO_SHIFT    (0x00000000u)
#define CSL_TSIP_CH0EQR_CH0INFO_RESETVAL (0x00000000u)

#define CSL_TSIP_CH0EQR_RESETVAL         (0x00000000u)

/* CH1ECR */

#define CSL_TSIP_CH1ECR_CH1CEQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH1ECR_CH1CEQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH1ECR_CH1CEQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH1ECR_CH1CLRQ_MASK     (0x00000002u)
#define CSL_TSIP_CH1ECR_CH1CLRQ_SHIFT    (0x00000001u)
#define CSL_TSIP_CH1ECR_CH1CLRQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH1ECR_CH1POPQ_MASK     (0x00000001u)
#define CSL_TSIP_CH1ECR_CH1POPQ_SHIFT    (0x00000000u)
#define CSL_TSIP_CH1ECR_CH1POPQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH1ECR_RESETVAL         (0x00000000u)

/* CH1ERRS */

#define CSL_TSIP_CH1ERRS_CH1EQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH1ERRS_CH1EQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH1ERRS_CH1EQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH1ERRS_CH1ECNT_MASK    (0x0000000Fu)
#define CSL_TSIP_CH1ERRS_CH1ECNT_SHIFT   (0x00000000u)
#define CSL_TSIP_CH1ERRS_CH1ECNT_RESETVAL (0x00000000u)

#define CSL_TSIP_CH1ERRS_RESETVAL        (0x00000000u)

/* CH1EQR */

#define CSL_TSIP_CH1EQR_CH1ERRC_MASK     (0xFF000000u)
#define CSL_TSIP_CH1EQR_CH1ERRC_SHIFT    (0x00000018u)
#define CSL_TSIP_CH1EQR_CH1ERRC_RESETVAL (0x00000000u)

#define CSL_TSIP_CH1EQR_CH1INFO_MASK     (0x00FFFFFFu)
#define CSL_TSIP_CH1EQR_CH1INFO_SHIFT    (0x00000000u)
#define CSL_TSIP_CH1EQR_CH1INFO_RESETVAL (0x00000000u)

#define CSL_TSIP_CH1EQR_RESETVAL         (0x00000000u)

/* CH2ECR */

#define CSL_TSIP_CH2ECR_CH2CEQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH2ECR_CH2CEQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH2ECR_CH2CEQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH2ECR_CH2CLRQ_MASK     (0x00000002u)
#define CSL_TSIP_CH2ECR_CH2CLRQ_SHIFT    (0x00000001u)
#define CSL_TSIP_CH2ECR_CH2CLRQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH2ECR_CH2POPQ_MASK     (0x00000001u)
#define CSL_TSIP_CH2ECR_CH2POPQ_SHIFT    (0x00000000u)
#define CSL_TSIP_CH2ECR_CH2POPQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH2ECR_RESETVAL         (0x00000000u)

/* CH2ERRS */

#define CSL_TSIP_CH2ERRS_CH2EQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH2ERRS_CH2EQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH2ERRS_CH2EQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH2ERRS_CH2ECNT_MASK    (0x0000000Fu)
#define CSL_TSIP_CH2ERRS_CH2ECNT_SHIFT   (0x00000000u)
#define CSL_TSIP_CH2ERRS_CH2ECNT_RESETVAL (0x00000000u)

#define CSL_TSIP_CH2ERRS_RESETVAL        (0x00000000u)

/* CH2EQR */

#define CSL_TSIP_CH2EQR_CH2ERRC_MASK     (0xFF000000u)
#define CSL_TSIP_CH2EQR_CH2ERRC_SHIFT    (0x00000018u)
#define CSL_TSIP_CH2EQR_CH2ERRC_RESETVAL (0x00000000u)

#define CSL_TSIP_CH2EQR_CH2INFO_MASK     (0x00FFFFFFu)
#define CSL_TSIP_CH2EQR_CH2INFO_SHIFT    (0x00000000u)
#define CSL_TSIP_CH2EQR_CH2INFO_RESETVAL (0x00000000u)

#define CSL_TSIP_CH2EQR_RESETVAL         (0x00000000u)

/* CH3ECR */

#define CSL_TSIP_CH3ECR_CH3CEQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH3ECR_CH3CEQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH3ECR_CH3CEQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH3ECR_CH3CLRQ_MASK     (0x00000002u)
#define CSL_TSIP_CH3ECR_CH3CLRQ_SHIFT    (0x00000001u)
#define CSL_TSIP_CH3ECR_CH3CLRQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH3ECR_CH3POPQ_MASK     (0x00000001u)
#define CSL_TSIP_CH3ECR_CH3POPQ_SHIFT    (0x00000000u)
#define CSL_TSIP_CH3ECR_CH3POPQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH3ECR_RESETVAL         (0x00000000u)

/* CH3ERRS */

#define CSL_TSIP_CH3ERRS_CH3EQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH3ERRS_CH3EQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH3ERRS_CH3EQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH3ERRS_CH3ECNT_MASK    (0x0000000Fu)
#define CSL_TSIP_CH3ERRS_CH3ECNT_SHIFT   (0x00000000u)
#define CSL_TSIP_CH3ERRS_CH3ECNT_RESETVAL (0x00000000u)

#define CSL_TSIP_CH3ERRS_RESETVAL        (0x00000000u)

/* CH3EQR */

#define CSL_TSIP_CH3EQR_CH3ERRC_MASK     (0xFF000000u)
#define CSL_TSIP_CH3EQR_CH3ERRC_SHIFT    (0x00000018u)
#define CSL_TSIP_CH3EQR_CH3ERRC_RESETVAL (0x00000000u)

#define CSL_TSIP_CH3EQR_CH3INFO_MASK     (0x00FFFFFFu)
#define CSL_TSIP_CH3EQR_CH3INFO_SHIFT    (0x00000000u)
#define CSL_TSIP_CH3EQR_CH3INFO_RESETVAL (0x00000000u)

#define CSL_TSIP_CH3EQR_RESETVAL         (0x00000000u)

/* CH4ECR */

#define CSL_TSIP_CH4ECR_CH4CEQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH4ECR_CH4CEQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH4ECR_CH4CEQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH4ECR_CH4CLRQ_MASK     (0x00000002u)
#define CSL_TSIP_CH4ECR_CH4CLRQ_SHIFT    (0x00000001u)
#define CSL_TSIP_CH4ECR_CH4CLRQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH4ECR_CH4POPQ_MASK     (0x00000001u)
#define CSL_TSIP_CH4ECR_CH4POPQ_SHIFT    (0x00000000u)
#define CSL_TSIP_CH4ECR_CH4POPQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH4ECR_RESETVAL         (0x00000000u)

/* CH4ERRS */

#define CSL_TSIP_CH4ERRS_CH4EQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH4ERRS_CH4EQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH4ERRS_CH4EQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH4ERRS_CH4ECNT_MASK    (0x0000000Fu)
#define CSL_TSIP_CH4ERRS_CH4ECNT_SHIFT   (0x00000000u)
#define CSL_TSIP_CH4ERRS_CH4ECNT_RESETVAL (0x00000000u)

#define CSL_TSIP_CH4ERRS_RESETVAL        (0x00000000u)

/* CH4EQR */

#define CSL_TSIP_CH4EQR_CH4ERRC_MASK     (0xFF000000u)
#define CSL_TSIP_CH4EQR_CH4ERRC_SHIFT    (0x00000018u)
#define CSL_TSIP_CH4EQR_CH4ERRC_RESETVAL (0x00000000u)

#define CSL_TSIP_CH4EQR_CH4INFO_MASK     (0x00FFFFFFu)
#define CSL_TSIP_CH4EQR_CH4INFO_SHIFT    (0x00000000u)
#define CSL_TSIP_CH4EQR_CH4INFO_RESETVAL (0x00000000u)

#define CSL_TSIP_CH4EQR_RESETVAL         (0x00000000u)

/* CH5ECR */

#define CSL_TSIP_CH5ECR_CH5CEQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH5ECR_CH5CEQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH5ECR_CH5CEQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH5ECR_CH5CLRQ_MASK     (0x00000002u)
#define CSL_TSIP_CH5ECR_CH5CLRQ_SHIFT    (0x00000001u)
#define CSL_TSIP_CH5ECR_CH5CLRQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH5ECR_CH5POPQ_MASK     (0x00000001u)
#define CSL_TSIP_CH5ECR_CH5POPQ_SHIFT    (0x00000000u)
#define CSL_TSIP_CH5ECR_CH5POPQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH5ECR_RESETVAL         (0x00000000u)

/* CH5ERRS */

#define CSL_TSIP_CH5ERRS_CH5EQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH5ERRS_CH5EQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH5ERRS_CH5EQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH5ERRS_CH5ECNT_MASK    (0x0000000Fu)
#define CSL_TSIP_CH5ERRS_CH5ECNT_SHIFT   (0x00000000u)
#define CSL_TSIP_CH5ERRS_CH5ECNT_RESETVAL (0x00000000u)

#define CSL_TSIP_CH5ERRS_RESETVAL        (0x00000000u)

/* CH5EQR */

#define CSL_TSIP_CH5EQR_CH5ERRC_MASK     (0xFF000000u)
#define CSL_TSIP_CH5EQR_CH5ERRC_SHIFT    (0x00000018u)
#define CSL_TSIP_CH5EQR_CH5ERRC_RESETVAL (0x00000000u)

#define CSL_TSIP_CH5EQR_CH5INFO_MASK     (0x00FFFFFFu)
#define CSL_TSIP_CH5EQR_CH5INFO_SHIFT    (0x00000000u)
#define CSL_TSIP_CH5EQR_CH5INFO_RESETVAL (0x00000000u)

#define CSL_TSIP_CH5EQR_RESETVAL         (0x00000000u)

/* CH6ECR */

#define CSL_TSIP_CH6ECR_CH6CEQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH6ECR_CH6CEQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH6ECR_CH6CEQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH6ECR_CH6CLRQ_MASK     (0x00000002u)
#define CSL_TSIP_CH6ECR_CH6CLRQ_SHIFT    (0x00000001u)
#define CSL_TSIP_CH6ECR_CH6CLRQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH6ECR_CH6POPQ_MASK     (0x00000001u)
#define CSL_TSIP_CH6ECR_CH6POPQ_SHIFT    (0x00000000u)
#define CSL_TSIP_CH6ECR_CH6POPQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH6ECR_RESETVAL         (0x00000000u)

/* CH6ERRS */

#define CSL_TSIP_CH6ERRS_CH6EQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH6ERRS_CH6EQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH6ERRS_CH6EQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH6ERRS_CH6ECNT_MASK    (0x0000000Fu)
#define CSL_TSIP_CH6ERRS_CH6ECNT_SHIFT   (0x00000000u)
#define CSL_TSIP_CH6ERRS_CH6ECNT_RESETVAL (0x00000000u)

#define CSL_TSIP_CH6ERRS_RESETVAL        (0x00000000u)

/* CH6EQR */

#define CSL_TSIP_CH6EQR_CH6ERRC_MASK     (0xFF000000u)
#define CSL_TSIP_CH6EQR_CH6ERRC_SHIFT    (0x00000018u)
#define CSL_TSIP_CH6EQR_CH6ERRC_RESETVAL (0x00000000u)

#define CSL_TSIP_CH6EQR_CH6INFO_MASK     (0x00FFFFFFu)
#define CSL_TSIP_CH6EQR_CH6INFO_SHIFT    (0x00000000u)
#define CSL_TSIP_CH6EQR_CH6INFO_RESETVAL (0x00000000u)

#define CSL_TSIP_CH6EQR_RESETVAL         (0x00000000u)

/* CH7ECR */

#define CSL_TSIP_CH7ECR_CH7CEQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH7ECR_CH7CEQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH7ECR_CH7CEQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH7ECR_CH7CLRQ_MASK     (0x00000002u)
#define CSL_TSIP_CH7ECR_CH7CLRQ_SHIFT    (0x00000001u)
#define CSL_TSIP_CH7ECR_CH7CLRQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH7ECR_CH7POPQ_MASK     (0x00000001u)
#define CSL_TSIP_CH7ECR_CH7POPQ_SHIFT    (0x00000000u)
#define CSL_TSIP_CH7ECR_CH7POPQ_RESETVAL (0x00000000u)

#define CSL_TSIP_CH7ECR_RESETVAL         (0x00000000u)

/* CH7ERRS */

#define CSL_TSIP_CH7ERRS_CH7EQOV_MASK    (0x00000100u)
#define CSL_TSIP_CH7ERRS_CH7EQOV_SHIFT   (0x00000008u)
#define CSL_TSIP_CH7ERRS_CH7EQOV_RESETVAL (0x00000000u)

#define CSL_TSIP_CH7ERRS_CH7ECNT_MASK    (0x0000000Fu)
#define CSL_TSIP_CH7ERRS_CH7ECNT_SHIFT   (0x00000000u)
#define CSL_TSIP_CH7ERRS_CH7ECNT_RESETVAL (0x00000000u)

#define CSL_TSIP_CH7ERRS_RESETVAL        (0x00000000u)

/* CH7EQR */

#define CSL_TSIP_CH7EQR_CH7ERRC_MASK     (0xFF000000u)
#define CSL_TSIP_CH7EQR_CH7ERRC_SHIFT    (0x00000018u)
#define CSL_TSIP_CH7EQR_CH7ERRC_RESETVAL (0x00000000u)

#define CSL_TSIP_CH7EQR_CH7INFO_MASK     (0x00FFFFFFu)
#define CSL_TSIP_CH7EQR_CH7INFO_SHIFT    (0x00000000u)
#define CSL_TSIP_CH7EQR_CH7INFO_RESETVAL (0x00000000u)

#define CSL_TSIP_CH7EQR_RESETVAL         (0x00000000u)

/* XMTCHNEN_0 */

#define CSL_TSIP_XMTCHNEN_0_TXC0ID_MASK  (0x0000FF00u)
#define CSL_TSIP_XMTCHNEN_0_TXC0ID_SHIFT (0x00000008u)
#define CSL_TSIP_XMTCHNEN_0_TXC0ID_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_0_TXCH0ENB_MASK (0x00000001u)
#define CSL_TSIP_XMTCHNEN_0_TXCH0ENB_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNEN_0_TXCH0ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_0_RESETVAL     (0x00000000u)

/* XMTCHNEN_1 */

#define CSL_TSIP_XMTCHNEN_1_TXC1ID_MASK  (0x0000FF00u)
#define CSL_TSIP_XMTCHNEN_1_TXC1ID_SHIFT (0x00000008u)
#define CSL_TSIP_XMTCHNEN_1_TXC1ID_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_1_TXCH1ENB_MASK (0x00000001u)
#define CSL_TSIP_XMTCHNEN_1_TXCH1ENB_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNEN_1_TXCH1ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_1_RESETVAL     (0x00000000u)

/* XMTCHNEN_2 */

#define CSL_TSIP_XMTCHNEN_2_TXC2ID_MASK  (0x0000FF00u)
#define CSL_TSIP_XMTCHNEN_2_TXC2ID_SHIFT (0x00000008u)
#define CSL_TSIP_XMTCHNEN_2_TXC2ID_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_2_TXCH2ENB_MASK (0x00000001u)
#define CSL_TSIP_XMTCHNEN_2_TXCH2ENB_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNEN_2_TXCH2ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_2_RESETVAL     (0x00000000u)

/* XMTCHNEN_3 */

#define CSL_TSIP_XMTCHNEN_3_TXC3ID_MASK  (0x0000FF00u)
#define CSL_TSIP_XMTCHNEN_3_TXC3ID_SHIFT (0x00000008u)
#define CSL_TSIP_XMTCHNEN_3_TXC3ID_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_3_TXCH3ENB_MASK (0x00000001u)
#define CSL_TSIP_XMTCHNEN_3_TXCH3ENB_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNEN_3_TXCH3ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_3_RESETVAL     (0x00000000u)

/* XMTCHNEN_4 */

#define CSL_TSIP_XMTCHNEN_4_TXC4ID_MASK  (0x0000FF00u)
#define CSL_TSIP_XMTCHNEN_4_TXC4ID_SHIFT (0x00000008u)
#define CSL_TSIP_XMTCHNEN_4_TXC4ID_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_4_TXCH4ENB_MASK (0x00000001u)
#define CSL_TSIP_XMTCHNEN_4_TXCH4ENB_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNEN_4_TXCH4ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_4_RESETVAL     (0x00000000u)

/* XMTCHNEN_5 */

#define CSL_TSIP_XMTCHNEN_5_TXC5ID_MASK  (0x0000FF00u)
#define CSL_TSIP_XMTCHNEN_5_TXC5ID_SHIFT (0x00000008u)
#define CSL_TSIP_XMTCHNEN_5_TXC5ID_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_5_TXCH5ENB_MASK (0x00000001u)
#define CSL_TSIP_XMTCHNEN_5_TXCH5ENB_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNEN_5_TXCH5ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_5_RESETVAL     (0x00000000u)

/* XMTCHNEN_6 */

#define CSL_TSIP_XMTCHNEN_6_TXC6ID_MASK  (0x0000FF00u)
#define CSL_TSIP_XMTCHNEN_6_TXC6ID_SHIFT (0x00000008u)
#define CSL_TSIP_XMTCHNEN_6_TXC6ID_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_6_TXCH6ENB_MASK (0x00000001u)
#define CSL_TSIP_XMTCHNEN_6_TXCH6ENB_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNEN_6_TXCH6ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_6_RESETVAL     (0x00000000u)

/* XMTCHNEN_7 */

#define CSL_TSIP_XMTCHNEN_7_TXC7ID_MASK  (0x0000FF00u)
#define CSL_TSIP_XMTCHNEN_7_TXC7ID_SHIFT (0x00000008u)
#define CSL_TSIP_XMTCHNEN_7_TXC7ID_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_7_TXCH7ENB_MASK (0x00000001u)
#define CSL_TSIP_XMTCHNEN_7_TXCH7ENB_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNEN_7_TXCH7ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNEN_7_RESETVAL     (0x00000000u)

/* RCVCHNEN_0 */

#define CSL_TSIP_RCVCHNEN_0_RXC0ID_MASK  (0x0000FF00u)
#define CSL_TSIP_RCVCHNEN_0_RXC0ID_SHIFT (0x00000008u)
#define CSL_TSIP_RCVCHNEN_0_RXC0ID_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_0_RXCH0ENB_MASK (0x00000001u)
#define CSL_TSIP_RCVCHNEN_0_RXCH0ENB_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNEN_0_RXCH0ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_0_RESETVAL     (0x00000000u)

/* RCVCHNEN_1 */

#define CSL_TSIP_RCVCHNEN_1_RXC1ID_MASK  (0x0000FF00u)
#define CSL_TSIP_RCVCHNEN_1_RXC1ID_SHIFT (0x00000008u)
#define CSL_TSIP_RCVCHNEN_1_RXC1ID_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_1_RXCH1ENB_MASK (0x00000001u)
#define CSL_TSIP_RCVCHNEN_1_RXCH1ENB_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNEN_1_RXCH1ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_1_RESETVAL     (0x00000000u)

/* RCVCHNEN_2 */

#define CSL_TSIP_RCVCHNEN_2_RXC2ID_MASK  (0x0000FF00u)
#define CSL_TSIP_RCVCHNEN_2_RXC2ID_SHIFT (0x00000008u)
#define CSL_TSIP_RCVCHNEN_2_RXC2ID_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_2_RXCH2ENB_MASK (0x00000001u)
#define CSL_TSIP_RCVCHNEN_2_RXCH2ENB_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNEN_2_RXCH2ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_2_RESETVAL     (0x00000000u)

/* RCVCHNEN_3 */

#define CSL_TSIP_RCVCHNEN_3_RXC3ID_MASK  (0x0000FF00u)
#define CSL_TSIP_RCVCHNEN_3_RXC3ID_SHIFT (0x00000008u)
#define CSL_TSIP_RCVCHNEN_3_RXC3ID_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_3_RXCH3ENB_MASK (0x00000001u)
#define CSL_TSIP_RCVCHNEN_3_RXCH3ENB_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNEN_3_RXCH3ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_3_RESETVAL     (0x00000000u)

/* RCVCHNEN_4 */

#define CSL_TSIP_RCVCHNEN_4_RXC4ID_MASK  (0x0000FF00u)
#define CSL_TSIP_RCVCHNEN_4_RXC4ID_SHIFT (0x00000008u)
#define CSL_TSIP_RCVCHNEN_4_RXC4ID_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_4_RXCH4ENB_MASK (0x00000001u)
#define CSL_TSIP_RCVCHNEN_4_RXCH4ENB_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNEN_4_RXCH4ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_4_RESETVAL     (0x00000000u)

/* RCVCHNEN_5 */

#define CSL_TSIP_RCVCHNEN_5_RXC5ID_MASK  (0x0000FF00u)
#define CSL_TSIP_RCVCHNEN_5_RXC5ID_SHIFT (0x00000008u)
#define CSL_TSIP_RCVCHNEN_5_RXC5ID_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_5_RXCH5ENB_MASK (0x00000001u)
#define CSL_TSIP_RCVCHNEN_5_RXCH5ENB_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNEN_5_RXCH5ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_5_RESETVAL     (0x00000000u)

/* RCVCHNEN_6 */

#define CSL_TSIP_RCVCHNEN_6_RXC6ID_MASK  (0x0000FF00u)
#define CSL_TSIP_RCVCHNEN_6_RXC6ID_SHIFT (0x00000008u)
#define CSL_TSIP_RCVCHNEN_6_RXC6ID_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_6_RXCH6ENB_MASK (0x00000001u)
#define CSL_TSIP_RCVCHNEN_6_RXCH6ENB_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNEN_6_RXCH6ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_6_RESETVAL     (0x00000000u)

/* RCVCHNEN_7 */

#define CSL_TSIP_RCVCHNEN_7_RXC7ID_MASK  (0x0000FF00u)
#define CSL_TSIP_RCVCHNEN_7_RXC7ID_SHIFT (0x00000008u)
#define CSL_TSIP_RCVCHNEN_7_RXC7ID_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_7_RXCH7ENB_MASK (0x00000001u)
#define CSL_TSIP_RCVCHNEN_7_RXCH7ENB_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNEN_7_RXCH7ENB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNEN_7_RESETVAL     (0x00000000u)

/* XMTCHNCON_ABA_0 */

#define CSL_TSIP_XMTCHNCON_ABA_0_TXC0AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_ABA_0_TXC0AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_ABA_0_TXC0AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_ABA_0_RESETVAL (0x00000000u)

/* XMTCHNCON_AFA_0 */

#define CSL_TSIP_XMTCHNCON_AFA_0_TXC0AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFA_0_TXC0AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFA_0_TXC0AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFA_0_RESETVAL (0x00000000u)

/* XMTCHNCON_AFS_0 */

#define CSL_TSIP_XMTCHNCON_AFS_0_TXC0AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFS_0_TXC0AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFS_0_TXC0AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFS_0_RESETVAL (0x00000000u)

/* XMTCHNCON_AFC_0 */

#define CSL_TSIP_XMTCHNCON_AFC_0_TXC0AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_AFC_0_TXC0AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFC_0_TXC0AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFC_0_RESETVAL (0x00000000u)

/* XMTCHNCON_BBA_0 */

#define CSL_TSIP_XMTCHNCON_BBA_0_TXC0BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_BBA_0_TXC0BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BBA_0_TXC0BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BBA_0_RESETVAL (0x00000000u)

/* XMTCHNCON_BFA_0 */

#define CSL_TSIP_XMTCHNCON_BFA_0_TXC0BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFA_0_TXC0BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFA_0_TXC0BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFA_0_RESETVAL (0x00000000u)

/* XMTCHNCON_BFS_0 */

#define CSL_TSIP_XMTCHNCON_BFS_0_TXC0BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFS_0_TXC0BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFS_0_TXC0BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFS_0_RESETVAL (0x00000000u)

/* XMTCHNCON_BFC_0 */

#define CSL_TSIP_XMTCHNCON_BFC_0_TXC0BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_BFC_0_TXC0BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFC_0_TXC0BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFC_0_RESETVAL (0x00000000u)

/* XMTCHNCON_ABA_1 */

#define CSL_TSIP_XMTCHNCON_ABA_1_TXC1AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_ABA_1_TXC1AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_ABA_1_TXC1AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_ABA_1_RESETVAL (0x00000000u)

/* XMTCHNCON_AFA_1 */

#define CSL_TSIP_XMTCHNCON_AFA_1_TXC1AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFA_1_TXC1AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFA_1_TXC1AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFA_1_RESETVAL (0x00000000u)

/* XMTCHNCON_AFS_1 */

#define CSL_TSIP_XMTCHNCON_AFS_1_TXC1AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFS_1_TXC1AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFS_1_TXC1AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFS_1_RESETVAL (0x00000000u)

/* XMTCHNCON_AFC_1 */

#define CSL_TSIP_XMTCHNCON_AFC_1_TXC1AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_AFC_1_TXC1AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFC_1_TXC1AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFC_1_RESETVAL (0x00000000u)

/* XMTCHNCON_BBA_1 */

#define CSL_TSIP_XMTCHNCON_BBA_1_TXC1BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_BBA_1_TXC1BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BBA_1_TXC1BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BBA_1_RESETVAL (0x00000000u)

/* XMTCHNCON_BFA_1 */

#define CSL_TSIP_XMTCHNCON_BFA_1_TXC1BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFA_1_TXC1BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFA_1_TXC1BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFA_1_RESETVAL (0x00000000u)

/* XMTCHNCON_BFS_1 */

#define CSL_TSIP_XMTCHNCON_BFS_1_TXC1BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFS_1_TXC1BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFS_1_TXC1BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFS_1_RESETVAL (0x00000000u)

/* XMTCHNCON_BFC_1 */

#define CSL_TSIP_XMTCHNCON_BFC_1_TXC1BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_BFC_1_TXC1BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFC_1_TXC1BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFC_1_RESETVAL (0x00000000u)

/* XMTCHNCON_ABA_2 */

#define CSL_TSIP_XMTCHNCON_ABA_2_TXC2AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_ABA_2_TXC2AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_ABA_2_TXC2AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_ABA_2_RESETVAL (0x00000000u)

/* XMTCHNCON_AFA_2 */

#define CSL_TSIP_XMTCHNCON_AFA_2_TXC2AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFA_2_TXC2AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFA_2_TXC2AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFA_2_RESETVAL (0x00000000u)

/* XMTCHNCON_AFS_2 */

#define CSL_TSIP_XMTCHNCON_AFS_2_TXC2AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFS_2_TXC2AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFS_2_TXC2AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFS_2_RESETVAL (0x00000000u)

/* XMTCHNCON_AFC_2 */

#define CSL_TSIP_XMTCHNCON_AFC_2_TXC2AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_AFC_2_TXC2AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFC_2_TXC2AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFC_2_RESETVAL (0x00000000u)

/* XMTCHNCON_BBA_2 */

#define CSL_TSIP_XMTCHNCON_BBA_2_TXC2BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_BBA_2_TXC2BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BBA_2_TXC2BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BBA_2_RESETVAL (0x00000000u)

/* XMTCHNCON_BFA_2 */

#define CSL_TSIP_XMTCHNCON_BFA_2_TXC2BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFA_2_TXC2BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFA_2_TXC2BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFA_2_RESETVAL (0x00000000u)

/* XMTCHNCON_BFS_2 */

#define CSL_TSIP_XMTCHNCON_BFS_2_TXC2BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFS_2_TXC2BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFS_2_TXC2BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFS_2_RESETVAL (0x00000000u)

/* XMTCHNCON_BFC_2 */

#define CSL_TSIP_XMTCHNCON_BFC_2_TXC2BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_BFC_2_TXC2BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFC_2_TXC2BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFC_2_RESETVAL (0x00000000u)

/* XMTCHNCON_ABA_3 */

#define CSL_TSIP_XMTCHNCON_ABA_3_TXC3AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_ABA_3_TXC3AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_ABA_3_TXC3AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_ABA_3_RESETVAL (0x00000000u)

/* XMTCHNCON_AFA_3 */

#define CSL_TSIP_XMTCHNCON_AFA_3_TXC3AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFA_3_TXC3AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFA_3_TXC3AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFA_3_RESETVAL (0x00000000u)

/* XMTCHNCON_AFS_3 */

#define CSL_TSIP_XMTCHNCON_AFS_3_TXC3AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFS_3_TXC3AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFS_3_TXC3AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFS_3_RESETVAL (0x00000000u)

/* XMTCHNCON_AFC_3 */

#define CSL_TSIP_XMTCHNCON_AFC_3_TXC3AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_AFC_3_TXC3AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFC_3_TXC3AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFC_3_RESETVAL (0x00000000u)

/* XMTCHNCON_BBA_3 */

#define CSL_TSIP_XMTCHNCON_BBA_3_TXC3BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_BBA_3_TXC3BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BBA_3_TXC3BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BBA_3_RESETVAL (0x00000000u)

/* XMTCHNCON_BFA_3 */

#define CSL_TSIP_XMTCHNCON_BFA_3_TXC3BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFA_3_TXC3BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFA_3_TXC3BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFA_3_RESETVAL (0x00000000u)

/* XMTCHNCON_BFS_3 */

#define CSL_TSIP_XMTCHNCON_BFS_3_TXC3BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFS_3_TXC3BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFS_3_TXC3BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFS_3_RESETVAL (0x00000000u)

/* XMTCHNCON_BFC_3 */

#define CSL_TSIP_XMTCHNCON_BFC_3_TXC3BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_BFC_3_TXC3BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFC_3_TXC3BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFC_3_RESETVAL (0x00000000u)

/* XMTCHNCON_ABA_4 */

#define CSL_TSIP_XMTCHNCON_ABA_4_TXC4AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_ABA_4_TXC4AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_ABA_4_TXC4AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_ABA_4_RESETVAL (0x00000000u)

/* XMTCHNCON_AFA_4 */

#define CSL_TSIP_XMTCHNCON_AFA_4_TXC4AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFA_4_TXC4AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFA_4_TXC4AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFA_4_RESETVAL (0x00000000u)

/* XMTCHNCON_AFS_4 */

#define CSL_TSIP_XMTCHNCON_AFS_4_TXC4AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFS_4_TXC4AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFS_4_TXC4AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFS_4_RESETVAL (0x00000000u)

/* XMTCHNCON_AFC_4 */

#define CSL_TSIP_XMTCHNCON_AFC_4_TXC4AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_AFC_4_TXC4AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFC_4_TXC4AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFC_4_RESETVAL (0x00000000u)

/* XMTCHNCON_BBA_4 */

#define CSL_TSIP_XMTCHNCON_BBA_4_TXC4BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_BBA_4_TXC4BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BBA_4_TXC4BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BBA_4_RESETVAL (0x00000000u)

/* XMTCHNCON_BFA_4 */

#define CSL_TSIP_XMTCHNCON_BFA_4_TXC4BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFA_4_TXC4BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFA_4_TXC4BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFA_4_RESETVAL (0x00000000u)

/* XMTCHNCON_BFS_4 */

#define CSL_TSIP_XMTCHNCON_BFS_4_TXC4BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFS_4_TXC4BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFS_4_TXC4BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFS_4_RESETVAL (0x00000000u)

/* XMTCHNCON_BFC_4 */

#define CSL_TSIP_XMTCHNCON_BFC_4_TXC4BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_BFC_4_TXC4BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFC_4_TXC4BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFC_4_RESETVAL (0x00000000u)

/* XMTCHNCON_ABA_5 */

#define CSL_TSIP_XMTCHNCON_ABA_5_TXC5AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_ABA_5_TXC5AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_ABA_5_TXC5AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_ABA_5_RESETVAL (0x00000000u)

/* XMTCHNCON_AFA_5 */

#define CSL_TSIP_XMTCHNCON_AFA_5_TXC5AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFA_5_TXC5AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFA_5_TXC5AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFA_5_RESETVAL (0x00000000u)

/* XMTCHNCON_AFS_5 */

#define CSL_TSIP_XMTCHNCON_AFS_5_TXC5AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFS_5_TXC5AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFS_5_TXC5AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFS_5_RESETVAL (0x00000000u)

/* XMTCHNCON_AFC_5 */

#define CSL_TSIP_XMTCHNCON_AFC_5_TXC5AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_AFC_5_TXC5AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFC_5_TXC5AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFC_5_RESETVAL (0x00000000u)

/* XMTCHNCON_BBA_5 */

#define CSL_TSIP_XMTCHNCON_BBA_5_TXC5BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_BBA_5_TXC5BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BBA_5_TXC5BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BBA_5_RESETVAL (0x00000000u)

/* XMTCHNCON_BFA_5 */

#define CSL_TSIP_XMTCHNCON_BFA_5_TXC5BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFA_5_TXC5BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFA_5_TXC5BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFA_5_RESETVAL (0x00000000u)

/* XMTCHNCON_BFS_5 */

#define CSL_TSIP_XMTCHNCON_BFS_5_TXC5BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFS_5_TXC5BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFS_5_TXC5BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFS_5_RESETVAL (0x00000000u)

/* XMTCHNCON_BFC_5 */

#define CSL_TSIP_XMTCHNCON_BFC_5_TXC5BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_BFC_5_TXC5BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFC_5_TXC5BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFC_5_RESETVAL (0x00000000u)

/* XMTCHNCON_ABA_6 */

#define CSL_TSIP_XMTCHNCON_ABA_6_TXC6AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_ABA_6_TXC6AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_ABA_6_TXC6AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_ABA_6_RESETVAL (0x00000000u)

/* XMTCHNCON_AFA_6 */

#define CSL_TSIP_XMTCHNCON_AFA_6_TXC6AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFA_6_TXC6AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFA_6_TXC6AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFA_6_RESETVAL (0x00000000u)

/* XMTCHNCON_AFS_6 */

#define CSL_TSIP_XMTCHNCON_AFS_6_TXC6AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFS_6_TXC6AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFS_6_TXC6AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFS_6_RESETVAL (0x00000000u)

/* XMTCHNCON_AFC_6 */

#define CSL_TSIP_XMTCHNCON_AFC_6_TXC6AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_AFC_6_TXC6AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFC_6_TXC6AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFC_6_RESETVAL (0x00000000u)

/* XMTCHNCON_BBA_6 */

#define CSL_TSIP_XMTCHNCON_BBA_6_TXC6BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_BBA_6_TXC6BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BBA_6_TXC6BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BBA_6_RESETVAL (0x00000000u)

/* XMTCHNCON_BFA_6 */

#define CSL_TSIP_XMTCHNCON_BFA_6_TXC6BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFA_6_TXC6BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFA_6_TXC6BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFA_6_RESETVAL (0x00000000u)

/* XMTCHNCON_BFS_6 */

#define CSL_TSIP_XMTCHNCON_BFS_6_TXC6BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFS_6_TXC6BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFS_6_TXC6BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFS_6_RESETVAL (0x00000000u)

/* XMTCHNCON_BFC_6 */

#define CSL_TSIP_XMTCHNCON_BFC_6_TXC6BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_BFC_6_TXC6BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFC_6_TXC6BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFC_6_RESETVAL (0x00000000u)

/* XMTCHNCON_ABA_7 */

#define CSL_TSIP_XMTCHNCON_ABA_7_TXC7AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_ABA_7_TXC7AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_ABA_7_TXC7AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_ABA_7_RESETVAL (0x00000000u)

/* XMTCHNCON_AFA_7 */

#define CSL_TSIP_XMTCHNCON_AFA_7_TXC7AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFA_7_TXC7AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFA_7_TXC7AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFA_7_RESETVAL (0x00000000u)

/* XMTCHNCON_AFS_7 */

#define CSL_TSIP_XMTCHNCON_AFS_7_TXC7AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_AFS_7_TXC7AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFS_7_TXC7AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFS_7_RESETVAL (0x00000000u)

/* XMTCHNCON_AFC_7 */

#define CSL_TSIP_XMTCHNCON_AFC_7_TXC7AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_AFC_7_TXC7AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_AFC_7_TXC7AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_AFC_7_RESETVAL (0x00000000u)

/* XMTCHNCON_BBA_7 */

#define CSL_TSIP_XMTCHNCON_BBA_7_TXC7BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_XMTCHNCON_BBA_7_TXC7BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BBA_7_TXC7BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BBA_7_RESETVAL (0x00000000u)

/* XMTCHNCON_BFA_7 */

#define CSL_TSIP_XMTCHNCON_BFA_7_TXC7BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFA_7_TXC7BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFA_7_TXC7BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFA_7_RESETVAL (0x00000000u)

/* XMTCHNCON_BFS_7 */

#define CSL_TSIP_XMTCHNCON_BFS_7_TXC7BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_XMTCHNCON_BFS_7_TXC7BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFS_7_TXC7BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFS_7_RESETVAL (0x00000000u)

/* XMTCHNCON_BFC_7 */

#define CSL_TSIP_XMTCHNCON_BFC_7_TXC7BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_XMTCHNCON_BFC_7_TXC7BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_XMTCHNCON_BFC_7_TXC7BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_XMTCHNCON_BFC_7_RESETVAL (0x00000000u)

/* RCVCHNCON_ABA_0 */

#define CSL_TSIP_RCVCHNCON_ABA_0_RXC0AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_ABA_0_RXC0AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_ABA_0_RXC0AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_ABA_0_RESETVAL (0x00000000u)

/* RCVCHNCON_AFA_0 */

#define CSL_TSIP_RCVCHNCON_AFA_0_RXC0AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFA_0_RXC0AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFA_0_RXC0AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFA_0_RESETVAL (0x00000000u)

/* RCVCHNCON_AFS_0 */

#define CSL_TSIP_RCVCHNCON_AFS_0_RXC0AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFS_0_RXC0AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFS_0_RXC0AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFS_0_RESETVAL (0x00000000u)

/* RCVCHNCON_AFC_0 */

#define CSL_TSIP_RCVCHNCON_AFC_0_RXC0AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_AFC_0_RXC0AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFC_0_RXC0AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFC_0_RESETVAL (0x00000000u)

/* RCVCHNCON_BBA_0 */

#define CSL_TSIP_RCVCHNCON_BBA_0_RXC0BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_BBA_0_RXC0BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BBA_0_RXC0BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BBA_0_RESETVAL (0x00000000u)

/* RCVCHNCON_BFA_0 */

#define CSL_TSIP_RCVCHNCON_BFA_0_RXC0BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFA_0_RXC0BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFA_0_RXC0BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFA_0_RESETVAL (0x00000000u)

/* RCVCHNCON_BFS_0 */

#define CSL_TSIP_RCVCHNCON_BFS_0_RXC0BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFS_0_RXC0BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFS_0_RXC0BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFS_0_RESETVAL (0x00000000u)

/* RCVCHNCON_BFC_0 */

#define CSL_TSIP_RCVCHNCON_BFC_0_RXC0BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_BFC_0_RXC0BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFC_0_RXC0BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFC_0_RESETVAL (0x00000000u)

/* RCVCHNCON_ABA_1 */

#define CSL_TSIP_RCVCHNCON_ABA_1_RXC1AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_ABA_1_RXC1AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_ABA_1_RXC1AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_ABA_1_RESETVAL (0x00000000u)

/* RCVCHNCON_AFA_1 */

#define CSL_TSIP_RCVCHNCON_AFA_1_RXC1AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFA_1_RXC1AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFA_1_RXC1AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFA_1_RESETVAL (0x00000000u)

/* RCVCHNCON_AFS_1 */

#define CSL_TSIP_RCVCHNCON_AFS_1_RXC1AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFS_1_RXC1AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFS_1_RXC1AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFS_1_RESETVAL (0x00000000u)

/* RCVCHNCON_AFC_1 */

#define CSL_TSIP_RCVCHNCON_AFC_1_RXC1AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_AFC_1_RXC1AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFC_1_RXC1AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFC_1_RESETVAL (0x00000000u)

/* RCVCHNCON_BBA_1 */

#define CSL_TSIP_RCVCHNCON_BBA_1_RXC1BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_BBA_1_RXC1BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BBA_1_RXC1BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BBA_1_RESETVAL (0x00000000u)

/* RCVCHNCON_BFA_1 */

#define CSL_TSIP_RCVCHNCON_BFA_1_RXC1BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFA_1_RXC1BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFA_1_RXC1BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFA_1_RESETVAL (0x00000000u)

/* RCVCHNCON_BFS_1 */

#define CSL_TSIP_RCVCHNCON_BFS_1_RXC1BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFS_1_RXC1BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFS_1_RXC1BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFS_1_RESETVAL (0x00000000u)

/* RCVCHNCON_BFC_1 */

#define CSL_TSIP_RCVCHNCON_BFC_1_RXC1BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_BFC_1_RXC1BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFC_1_RXC1BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFC_1_RESETVAL (0x00000000u)

/* RCVCHNCON_ABA_2 */

#define CSL_TSIP_RCVCHNCON_ABA_2_RXC2AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_ABA_2_RXC2AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_ABA_2_RXC2AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_ABA_2_RESETVAL (0x00000000u)

/* RCVCHNCON_AFA_2 */

#define CSL_TSIP_RCVCHNCON_AFA_2_RXC2AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFA_2_RXC2AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFA_2_RXC2AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFA_2_RESETVAL (0x00000000u)

/* RCVCHNCON_AFS_2 */

#define CSL_TSIP_RCVCHNCON_AFS_2_RXC2AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFS_2_RXC2AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFS_2_RXC2AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFS_2_RESETVAL (0x00000000u)

/* RCVCHNCON_AFC_2 */

#define CSL_TSIP_RCVCHNCON_AFC_2_RXC2AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_AFC_2_RXC2AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFC_2_RXC2AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFC_2_RESETVAL (0x00000000u)

/* RCVCHNCON_BBA_2 */

#define CSL_TSIP_RCVCHNCON_BBA_2_RXC2BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_BBA_2_RXC2BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BBA_2_RXC2BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BBA_2_RESETVAL (0x00000000u)

/* RCVCHNCON_BFA_2 */

#define CSL_TSIP_RCVCHNCON_BFA_2_RXC2BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFA_2_RXC2BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFA_2_RXC2BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFA_2_RESETVAL (0x00000000u)

/* RCVCHNCON_BFS_2 */

#define CSL_TSIP_RCVCHNCON_BFS_2_RXC2BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFS_2_RXC2BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFS_2_RXC2BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFS_2_RESETVAL (0x00000000u)

/* RCVCHNCON_BFC_2 */

#define CSL_TSIP_RCVCHNCON_BFC_2_RXC2BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_BFC_2_RXC2BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFC_2_RXC2BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFC_2_RESETVAL (0x00000000u)

/* RCVCHNCON_ABA_3 */

#define CSL_TSIP_RCVCHNCON_ABA_3_RXC3AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_ABA_3_RXC3AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_ABA_3_RXC3AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_ABA_3_RESETVAL (0x00000000u)

/* RCVCHNCON_AFA_3 */

#define CSL_TSIP_RCVCHNCON_AFA_3_RXC3AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFA_3_RXC3AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFA_3_RXC3AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFA_3_RESETVAL (0x00000000u)

/* RCVCHNCON_AFS_3 */

#define CSL_TSIP_RCVCHNCON_AFS_3_RXC3AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFS_3_RXC3AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFS_3_RXC3AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFS_3_RESETVAL (0x00000000u)

/* RCVCHNCON_AFC_3 */

#define CSL_TSIP_RCVCHNCON_AFC_3_RXC3AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_AFC_3_RXC3AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFC_3_RXC3AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFC_3_RESETVAL (0x00000000u)

/* RCVCHNCON_BBA_3 */

#define CSL_TSIP_RCVCHNCON_BBA_3_RXC3BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_BBA_3_RXC3BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BBA_3_RXC3BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BBA_3_RESETVAL (0x00000000u)

/* RCVCHNCON_BFA_3 */

#define CSL_TSIP_RCVCHNCON_BFA_3_RXC3BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFA_3_RXC3BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFA_3_RXC3BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFA_3_RESETVAL (0x00000000u)

/* RCVCHNCON_BFS_3 */

#define CSL_TSIP_RCVCHNCON_BFS_3_RXC3BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFS_3_RXC3BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFS_3_RXC3BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFS_3_RESETVAL (0x00000000u)

/* RCVCHNCON_BFC_3 */

#define CSL_TSIP_RCVCHNCON_BFC_3_RXC3BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_BFC_3_RXC3BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFC_3_RXC3BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFC_3_RESETVAL (0x00000000u)

/* RCVCHNCON_ABA_4 */

#define CSL_TSIP_RCVCHNCON_ABA_4_RXC4AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_ABA_4_RXC4AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_ABA_4_RXC4AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_ABA_4_RESETVAL (0x00000000u)

/* RCVCHNCON_AFA_4 */

#define CSL_TSIP_RCVCHNCON_AFA_4_RXC4AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFA_4_RXC4AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFA_4_RXC4AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFA_4_RESETVAL (0x00000000u)

/* RCVCHNCON_AFS_4 */

#define CSL_TSIP_RCVCHNCON_AFS_4_RXC4AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFS_4_RXC4AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFS_4_RXC4AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFS_4_RESETVAL (0x00000000u)

/* RCVCHNCON_AFC_4 */

#define CSL_TSIP_RCVCHNCON_AFC_4_RXC4AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_AFC_4_RXC4AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFC_4_RXC4AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFC_4_RESETVAL (0x00000000u)

/* RCVCHNCON_BBA_4 */

#define CSL_TSIP_RCVCHNCON_BBA_4_RXC4BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_BBA_4_RXC4BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BBA_4_RXC4BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BBA_4_RESETVAL (0x00000000u)

/* RCVCHNCON_BFA_4 */

#define CSL_TSIP_RCVCHNCON_BFA_4_RXC4BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFA_4_RXC4BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFA_4_RXC4BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFA_4_RESETVAL (0x00000000u)

/* RCVCHNCON_BFS_4 */

#define CSL_TSIP_RCVCHNCON_BFS_4_RXC4BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFS_4_RXC4BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFS_4_RXC4BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFS_4_RESETVAL (0x00000000u)

/* RCVCHNCON_BFC_4 */

#define CSL_TSIP_RCVCHNCON_BFC_4_RXC4BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_BFC_4_RXC4BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFC_4_RXC4BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFC_4_RESETVAL (0x00000000u)

/* RCVCHNCON_ABA_5 */

#define CSL_TSIP_RCVCHNCON_ABA_5_RXC5AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_ABA_5_RXC5AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_ABA_5_RXC5AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_ABA_5_RESETVAL (0x00000000u)

/* RCVCHNCON_AFA_5 */

#define CSL_TSIP_RCVCHNCON_AFA_5_RXC5AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFA_5_RXC5AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFA_5_RXC5AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFA_5_RESETVAL (0x00000000u)

/* RCVCHNCON_AFS_5 */

#define CSL_TSIP_RCVCHNCON_AFS_5_RXC5AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFS_5_RXC5AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFS_5_RXC5AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFS_5_RESETVAL (0x00000000u)

/* RCVCHNCON_AFC_5 */

#define CSL_TSIP_RCVCHNCON_AFC_5_RXC5AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_AFC_5_RXC5AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFC_5_RXC5AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFC_5_RESETVAL (0x00000000u)

/* RCVCHNCON_BBA_5 */

#define CSL_TSIP_RCVCHNCON_BBA_5_RXC5BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_BBA_5_RXC5BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BBA_5_RXC5BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BBA_5_RESETVAL (0x00000000u)

/* RCVCHNCON_BFA_5 */

#define CSL_TSIP_RCVCHNCON_BFA_5_RXC5BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFA_5_RXC5BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFA_5_RXC5BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFA_5_RESETVAL (0x00000000u)

/* RCVCHNCON_BFS_5 */

#define CSL_TSIP_RCVCHNCON_BFS_5_RXC5BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFS_5_RXC5BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFS_5_RXC5BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFS_5_RESETVAL (0x00000000u)

/* RCVCHNCON_BFC_5 */

#define CSL_TSIP_RCVCHNCON_BFC_5_RXC5BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_BFC_5_RXC5BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFC_5_RXC5BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFC_5_RESETVAL (0x00000000u)

/* RCVCHNCON_ABA_6 */

#define CSL_TSIP_RCVCHNCON_ABA_6_RXC6AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_ABA_6_RXC6AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_ABA_6_RXC6AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_ABA_6_RESETVAL (0x00000000u)

/* RCVCHNCON_AFA_6 */

#define CSL_TSIP_RCVCHNCON_AFA_6_RXC6AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFA_6_RXC6AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFA_6_RXC6AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFA_6_RESETVAL (0x00000000u)

/* RCVCHNCON_AFS_6 */

#define CSL_TSIP_RCVCHNCON_AFS_6_RXC6AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFS_6_RXC6AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFS_6_RXC6AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFS_6_RESETVAL (0x00000000u)

/* RCVCHNCON_AFC_6 */

#define CSL_TSIP_RCVCHNCON_AFC_6_RXC6AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_AFC_6_RXC6AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFC_6_RXC6AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFC_6_RESETVAL (0x00000000u)

/* RCVCHNCON_BBA_6 */

#define CSL_TSIP_RCVCHNCON_BBA_6_RXC6BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_BBA_6_RXC6BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BBA_6_RXC6BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BBA_6_RESETVAL (0x00000000u)

/* RCVCHNCON_BFA_6 */

#define CSL_TSIP_RCVCHNCON_BFA_6_RXC6BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFA_6_RXC6BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFA_6_RXC6BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFA_6_RESETVAL (0x00000000u)

/* RCVCHNCON_BFS_6 */

#define CSL_TSIP_RCVCHNCON_BFS_6_RXC6BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFS_6_RXC6BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFS_6_RXC6BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFS_6_RESETVAL (0x00000000u)

/* RCVCHNCON_BFC_6 */

#define CSL_TSIP_RCVCHNCON_BFC_6_RXC6BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_BFC_6_RXC6BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFC_6_RXC6BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFC_6_RESETVAL (0x00000000u)

/* RCVCHNCON_ABA_7 */

#define CSL_TSIP_RCVCHNCON_ABA_7_RXC7AMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_ABA_7_RXC7AMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_ABA_7_RXC7AMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_ABA_7_RESETVAL (0x00000000u)

/* RCVCHNCON_AFA_7 */

#define CSL_TSIP_RCVCHNCON_AFA_7_RXC7AFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFA_7_RXC7AFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFA_7_RXC7AFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFA_7_RESETVAL (0x00000000u)

/* RCVCHNCON_AFS_7 */

#define CSL_TSIP_RCVCHNCON_AFS_7_RXC7AFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_AFS_7_RXC7AFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFS_7_RXC7AFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFS_7_RESETVAL (0x00000000u)

/* RCVCHNCON_AFC_7 */

#define CSL_TSIP_RCVCHNCON_AFC_7_RXC7AFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_AFC_7_RXC7AFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_AFC_7_RXC7AFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_AFC_7_RESETVAL (0x00000000u)

/* RCVCHNCON_BBA_7 */

#define CSL_TSIP_RCVCHNCON_BBA_7_RXC7BMEMBASEADR_MASK (0xFFFFFFFFu)
#define CSL_TSIP_RCVCHNCON_BBA_7_RXC7BMEMBASEADR_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BBA_7_RXC7BMEMBASEADR_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BBA_7_RESETVAL (0x00000000u)

/* RCVCHNCON_BFA_7 */

#define CSL_TSIP_RCVCHNCON_BFA_7_RXC7BFRAMEALLOC_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFA_7_RXC7BFRAMEALLOC_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFA_7_RXC7BFRAMEALLOC_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFA_7_RESETVAL (0x00000000u)

/* RCVCHNCON_BFS_7 */

#define CSL_TSIP_RCVCHNCON_BFS_7_RXC7BFSIZE_MASK (0x00000FFFu)
#define CSL_TSIP_RCVCHNCON_BFS_7_RXC7BFSIZE_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFS_7_RXC7BFSIZE_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFS_7_RESETVAL (0x00000000u)

/* RCVCHNCON_BFC_7 */

#define CSL_TSIP_RCVCHNCON_BFC_7_RXC7BFCOUNT_MASK (0x000000FFu)
#define CSL_TSIP_RCVCHNCON_BFC_7_RXC7BFCOUNT_SHIFT (0x00000000u)
#define CSL_TSIP_RCVCHNCON_BFC_7_RXC7BFCOUNT_RESETVAL (0x00000000u)

#define CSL_TSIP_RCVCHNCON_BFC_7_RESETVAL (0x00000000u)

/* XCH0BMA */

#define CSL_TSIP_XCH0BMA_XCH0BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH0BMA_XCH0BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH0BMA_XCH0BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH0BMA_RESETVAL        (0x00000000u)

/* XCH0BMB */

#define CSL_TSIP_XCH0BMB_XCH0BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH0BMB_XCH0BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH0BMB_XCH0BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH0BMB_RESETVAL        (0x00000000u)

/* XCH1BMA */

#define CSL_TSIP_XCH1BMA_XCH1BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH1BMA_XCH1BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH1BMA_XCH1BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH1BMA_RESETVAL        (0x00000000u)

/* XCH1BMB */

#define CSL_TSIP_XCH1BMB_XCH1BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH1BMB_XCH1BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH1BMB_XCH1BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH1BMB_RESETVAL        (0x00000000u)

/* XCH2BMA */

#define CSL_TSIP_XCH2BMA_XCH2BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH2BMA_XCH2BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH2BMA_XCH2BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH2BMA_RESETVAL        (0x00000000u)

/* XCH2BMB */

#define CSL_TSIP_XCH2BMB_XCH2BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH2BMB_XCH2BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH2BMB_XCH2BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH2BMB_RESETVAL        (0x00000000u)

/* XCH3BMA */

#define CSL_TSIP_XCH3BMA_XCH3BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH3BMA_XCH3BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH3BMA_XCH3BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH3BMA_RESETVAL        (0x00000000u)

/* XCH3BMB */

#define CSL_TSIP_XCH3BMB_XCH3BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH3BMB_XCH3BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH3BMB_XCH3BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH3BMB_RESETVAL        (0x00000000u)

/* XCH4BMA */

#define CSL_TSIP_XCH4BMA_XCH4BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH4BMA_XCH4BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH4BMA_XCH4BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH4BMA_RESETVAL        (0x00000000u)

/* XCH4BMB */

#define CSL_TSIP_XCH4BMB_XCH4BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH4BMB_XCH4BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH4BMB_XCH4BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH4BMB_RESETVAL        (0x00000000u)

/* XCH5BMA */

#define CSL_TSIP_XCH5BMA_XCH5BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH5BMA_XCH5BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH5BMA_XCH5BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH5BMA_RESETVAL        (0x00000000u)

/* XCH5BMB */

#define CSL_TSIP_XCH5BMB_XCH5BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH5BMB_XCH5BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH5BMB_XCH5BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH5BMB_RESETVAL        (0x00000000u)

/* XCH6BMA */

#define CSL_TSIP_XCH6BMA_XCH6BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH6BMA_XCH6BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH6BMA_XCH6BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH6BMA_RESETVAL        (0x00000000u)

/* XCH6BMB */

#define CSL_TSIP_XCH6BMB_XCH6BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH6BMB_XCH6BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH6BMB_XCH6BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH6BMB_RESETVAL        (0x00000000u)

/* XCH7BMA */

#define CSL_TSIP_XCH7BMA_XCH7BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH7BMA_XCH7BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH7BMA_XCH7BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH7BMA_RESETVAL        (0x00000000u)

/* XCH7BMB */

#define CSL_TSIP_XCH7BMB_XCH7BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH7BMB_XCH7BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH7BMB_XCH7BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH7BMB_RESETVAL        (0x00000000u)

/* RCH0BMA */

#define CSL_TSIP_RCH0BMA_RCH0BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH0BMA_RCH0BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH0BMA_RCH0BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH0BMA_RESETVAL        (0x00000000u)

/* RCH0BMB */

#define CSL_TSIP_RCH0BMB_RCH0BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH0BMB_RCH0BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH0BMB_RCH0BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH0BMB_RESETVAL        (0x00000000u)

/* RCH1BMA */

#define CSL_TSIP_RCH1BMA_RCH1BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH1BMA_RCH1BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH1BMA_RCH1BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH1BMA_RESETVAL        (0x00000000u)

/* RCH1BMB */

#define CSL_TSIP_RCH1BMB_RCH1BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH1BMB_RCH1BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH1BMB_RCH1BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH1BMB_RESETVAL        (0x00000000u)

/* RCH2BMA */

#define CSL_TSIP_RCH2BMA_RCH2BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH2BMA_RCH2BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH2BMA_RCH2BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH2BMA_RESETVAL        (0x00000000u)

/* RCH2BMB */

#define CSL_TSIP_RCH2BMB_RCH2BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH2BMB_RCH2BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH2BMB_RCH2BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH2BMB_RESETVAL        (0x00000000u)

/* RCH3BMA */

#define CSL_TSIP_RCH3BMA_RCH3BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH3BMA_RCH3BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH3BMA_RCH3BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH3BMA_RESETVAL        (0x00000000u)

/* RCH3BMB */

#define CSL_TSIP_RCH3BMB_RCH3BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH3BMB_RCH3BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH3BMB_RCH3BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH3BMB_RESETVAL        (0x00000000u)

/* RCH4BMA */

#define CSL_TSIP_RCH4BMA_RCH4BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH4BMA_RCH4BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH4BMA_RCH4BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH4BMA_RESETVAL        (0x00000000u)

/* RCH4BMB */

#define CSL_TSIP_RCH4BMB_RCH4BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH4BMB_RCH4BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH4BMB_RCH4BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH4BMB_RESETVAL        (0x00000000u)

/* RCH5BMA */

#define CSL_TSIP_RCH5BMA_RCH5BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH5BMA_RCH5BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH5BMA_RCH5BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH5BMA_RESETVAL        (0x00000000u)

/* RCH5BMB */

#define CSL_TSIP_RCH5BMB_RCH5BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH5BMB_RCH5BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH5BMB_RCH5BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH5BMB_RESETVAL        (0x00000000u)

/* RCH6BMA */

#define CSL_TSIP_RCH6BMA_RCH6BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH6BMA_RCH6BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH6BMA_RCH6BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH6BMA_RESETVAL        (0x00000000u)

/* RCH6BMB */

#define CSL_TSIP_RCH6BMB_RCH6BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH6BMB_RCH6BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH6BMB_RCH6BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH6BMB_RESETVAL        (0x00000000u)

/* RCH7BMA */

#define CSL_TSIP_RCH7BMA_RCH7BMA_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH7BMA_RCH7BMA_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH7BMA_RCH7BMA_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH7BMA_RESETVAL        (0x00000000u)

/* RCH7BMB */

#define CSL_TSIP_RCH7BMB_RCH7BMB_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH7BMB_RCH7BMB_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH7BMB_RCH7BMB_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH7BMB_RESETVAL        (0x00000000u)

/* XCH0BPI */

#define CSL_TSIP_XCH0BPI_XCH0BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH0BPI_XCH0BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH0BPI_XCH0BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH0BPI_RESETVAL        (0x00000000u)

/* XCH0BPO */

#define CSL_TSIP_XCH0BPO_XCH0BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH0BPO_XCH0BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH0BPO_XCH0BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH0BPO_RESETVAL        (0x00000000u)

/* XCH1BPI */

#define CSL_TSIP_XCH1BPI_XCH1BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH1BPI_XCH1BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH1BPI_XCH1BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH1BPI_RESETVAL        (0x00000000u)

/* XCH1BPO */

#define CSL_TSIP_XCH1BPO_XCH1BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH1BPO_XCH1BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH1BPO_XCH1BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH1BPO_RESETVAL        (0x00000000u)

/* XCH2BPI */

#define CSL_TSIP_XCH2BPI_XCH2BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH2BPI_XCH2BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH2BPI_XCH2BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH2BPI_RESETVAL        (0x00000000u)

/* XCH2BPO */

#define CSL_TSIP_XCH2BPO_XCH2BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH2BPO_XCH2BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH2BPO_XCH2BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH2BPO_RESETVAL        (0x00000000u)

/* XCH3BPI */

#define CSL_TSIP_XCH3BPI_XCH3BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH3BPI_XCH3BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH3BPI_XCH3BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH3BPI_RESETVAL        (0x00000000u)

/* XCH3BPO */

#define CSL_TSIP_XCH3BPO_XCH3BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH3BPO_XCH3BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH3BPO_XCH3BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH3BPO_RESETVAL        (0x00000000u)

/* XCH4BPI */

#define CSL_TSIP_XCH4BPI_XCH4BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH4BPI_XCH4BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH4BPI_XCH4BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH4BPI_RESETVAL        (0x00000000u)

/* XCH4BPO */

#define CSL_TSIP_XCH4BPO_XCH4BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH4BPO_XCH4BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH4BPO_XCH4BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH4BPO_RESETVAL        (0x00000000u)

/* XCH5BPI */

#define CSL_TSIP_XCH5BPI_XCH5BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH5BPI_XCH5BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH5BPI_XCH5BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH5BPI_RESETVAL        (0x00000000u)

/* XCH5BPO */

#define CSL_TSIP_XCH5BPO_XCH5BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH5BPO_XCH5BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH5BPO_XCH5BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH5BPO_RESETVAL        (0x00000000u)

/* XCH6BPI */

#define CSL_TSIP_XCH6BPI_XCH6BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH6BPI_XCH6BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH6BPI_XCH6BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH6BPI_RESETVAL        (0x00000000u)

/* XCH6BPO */

#define CSL_TSIP_XCH6BPO_XCH6BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH6BPO_XCH6BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH6BPO_XCH6BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH6BPO_RESETVAL        (0x00000000u)

/* XCH7BPI */

#define CSL_TSIP_XCH7BPI_XCH7BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH7BPI_XCH7BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH7BPI_XCH7BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH7BPI_RESETVAL        (0x00000000u)

/* XCH7BPO */

#define CSL_TSIP_XCH7BPO_XCH7BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_XCH7BPO_XCH7BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_XCH7BPO_XCH7BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_XCH7BPO_RESETVAL        (0x00000000u)

/* RCH0BPI */

#define CSL_TSIP_RCH0BPI_RCH0BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH0BPI_RCH0BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH0BPI_RCH0BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH0BPI_RESETVAL        (0x00000000u)

/* RCH0BPO */

#define CSL_TSIP_RCH0BPO_RCH0BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH0BPO_RCH0BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH0BPO_RCH0BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH0BPO_RESETVAL        (0x00000000u)

/* RCH1BPI */

#define CSL_TSIP_RCH1BPI_RCH1BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH1BPI_RCH1BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH1BPI_RCH1BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH1BPI_RESETVAL        (0x00000000u)

/* RCH1BPO */

#define CSL_TSIP_RCH1BPO_RCH1BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH1BPO_RCH1BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH1BPO_RCH1BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH1BPO_RESETVAL        (0x00000000u)

/* RCH2BPI */

#define CSL_TSIP_RCH2BPI_RCH2BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH2BPI_RCH2BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH2BPI_RCH2BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH2BPI_RESETVAL        (0x00000000u)

/* RCH2BPO */

#define CSL_TSIP_RCH2BPO_RCH2BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH2BPO_RCH2BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH2BPO_RCH2BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH2BPO_RESETVAL        (0x00000000u)

/* RCH3BPI */

#define CSL_TSIP_RCH3BPI_RCH3BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH3BPI_RCH3BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH3BPI_RCH3BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH3BPI_RESETVAL        (0x00000000u)

/* RCH3BPO */

#define CSL_TSIP_RCH3BPO_RCH3BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH3BPO_RCH3BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH3BPO_RCH3BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH3BPO_RESETVAL        (0x00000000u)

/* RCH4BPI */

#define CSL_TSIP_RCH4BPI_RCH4BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH4BPI_RCH4BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH4BPI_RCH4BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH4BPI_RESETVAL        (0x00000000u)

/* RCH4BPO */

#define CSL_TSIP_RCH4BPO_RCH4BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH4BPO_RCH4BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH4BPO_RCH4BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH4BPO_RESETVAL        (0x00000000u)

/* RCH5BPI */

#define CSL_TSIP_RCH5BPI_RCH5BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH5BPI_RCH5BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH5BPI_RCH5BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH5BPI_RESETVAL        (0x00000000u)

/* RCH5BPO */

#define CSL_TSIP_RCH5BPO_RCH5BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH5BPO_RCH5BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH5BPO_RCH5BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH5BPO_RESETVAL        (0x00000000u)

/* RCH6BPI */

#define CSL_TSIP_RCH6BPI_RCH6BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH6BPI_RCH6BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH6BPI_RCH6BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH6BPI_RESETVAL        (0x00000000u)

/* RCH6BPO */

#define CSL_TSIP_RCH6BPO_RCH6BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH6BPO_RCH6BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH6BPO_RCH6BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH6BPO_RESETVAL        (0x00000000u)

/* RCH7BPI */

#define CSL_TSIP_RCH7BPI_RCH7BPI_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH7BPI_RCH7BPI_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH7BPI_RCH7BPI_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH7BPI_RESETVAL        (0x00000000u)

/* RCH7BPO */

#define CSL_TSIP_RCH7BPO_RCH7BPO_MASK    (0xFFFFFFFFu)
#define CSL_TSIP_RCH7BPO_RCH7BPO_SHIFT   (0x00000000u)
#define CSL_TSIP_RCH7BPO_RCH7BPO_RESETVAL (0x00000000u)

#define CSL_TSIP_RCH7BPO_RESETVAL        (0x00000000u)

#endif

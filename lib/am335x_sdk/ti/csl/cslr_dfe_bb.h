/*
 * cslr_dfe_bb.h
 *
 * This file contains the macros for Register Chip Support Library (CSL) which 
 * can be used for operations on the respective underlying hardware/peripheral
 *
 * Copyright (C) 2009-2012 Texas Instruments Incorporated - http://www.ti.com/
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
 *  AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
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

/* The file is auto generated at 09:57:24 02/28/13 (Rev 1.68)*/

#ifndef CSLR_DFE_BB_H__
#define CSLR_DFE_BB_H__

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/

typedef struct
{
    volatile Uint32 pn_init;
    volatile Uint32 pn_tapconfig;
    volatile Uint32 tx_noise;
    volatile Uint32 rx;
} CSL_DFE_BB_ANTCAL_REGS;

typedef struct
{
    volatile Uint32 time_step_lo;
    volatile Uint32 time_step_hi;
    volatile Uint32 reset_int_lo;
    volatile Uint32 reset_int_hi;
    volatile Uint32 tdd_period_lo;
    volatile Uint32 tdd_period_hi;
    volatile Uint32 on_0_lo;
    volatile Uint32 on_0_hi;
    volatile Uint32 off_0_lo;
    volatile Uint32 off_0_hi;
    volatile Uint32 on_1_lo;
    volatile Uint32 on_1_hi;
    volatile Uint32 off_1_lo;
    volatile Uint32 off_1_hi;
    volatile Uint32 rsvd0[18];
} CSL_DFE_BB_CLKGATE_REGS;

typedef struct
{
    volatile Uint32 config0;
    volatile Uint32 config1;
    volatile Uint32 config2;
    volatile Uint32 rsvd0[1];
} CSL_DFE_BB_BBTXIF_AXC_REGS;

typedef struct
{
    volatile Uint32 config0;
    volatile Uint32 config1;
    volatile Uint32 config2;
    volatile Uint32 rsvd0[1];
    volatile Uint32 config4;
    volatile Uint32 config5;
    volatile Uint32 config6;
    volatile Uint32 config7;
} CSL_DFE_BB_BBRXIF_AXC_REGS;

typedef struct
{
    volatile Uint32 integer;
    volatile Uint32 fraction;
} CSL_DFE_BB_BBRXGAIN_REGS;

typedef struct
{
    volatile Uint32 i;
    volatile Uint32 q;
} CSL_DFE_BB_BBTXGAIN_REGS;

typedef struct
{
    volatile Uint32 lut0;
    volatile Uint32 lut1;
} CSL_DFE_BB_BBTXIF_REGS;

typedef struct
{
    volatile Uint32 config1;
    volatile Uint32 config2;
} CSL_DFE_BB_RXNOTCH_REGS;

typedef struct
{
    volatile Uint32 config0;
    volatile Uint32 config1;
    volatile Uint32 config2;
    volatile Uint32 config3;
} CSL_DFE_BB_RXNOTCHTAP0_REGS;

typedef struct
{
    volatile Uint32 config0;
    volatile Uint32 config1;
    volatile Uint32 config2;
    volatile Uint32 config3;
} CSL_DFE_BB_RXNOTCHTAP1_REGS;

typedef struct
{
    volatile Uint32 r0;
    volatile Uint32 r1;
    volatile Uint32 r2;
    volatile Uint32 r3;
} CSL_DFE_BB_BBTXPWRMETER_REGS;

typedef struct
{
    volatile Uint32 r0;
    volatile Uint32 r1;
    volatile Uint32 r2;
    volatile Uint32 r3;
} CSL_DFE_BB_BBRXPWRMETER_REGS;

typedef struct
{
    volatile Uint32 cfg0;
    volatile Uint32 cfg1;
    volatile Uint32 cfg2;
    volatile Uint32 cfg3;
    volatile Uint32 cfg4;
    volatile Uint32 cfg5;
    volatile Uint32 rsvd0[2];
} CSL_DFE_BB_BEAGC_REGS;

typedef struct
{
    volatile Uint32 r0;
    volatile Uint32 r1;
    volatile Uint32 r2;
    volatile Uint32 rsvd0[1];
    volatile Uint32 r3;
    volatile Uint32 r4;
    volatile Uint32 r5;
    volatile Uint32 rsvd1[1];
} CSL_DFE_BB_ANTCALCORR_REGS;

typedef struct 
{
    /* Addr: h(0), d(0) */
    volatile Uint32 rsvd0[65664];
    /* Addr: h(40200), d(262656) */
    volatile Uint32 cfg0;
    /* Addr: h(40204), d(262660) */
    volatile Uint32 cfg1;
    /* Addr: h(40208), d(262664) */
    volatile Uint32 cfg2;
    /* Addr: h(4020C), d(262668) */
    volatile Uint32 cfg3;
    /* Addr: h(40210), d(262672) */
    volatile Uint32 cfg4;
    /* Addr: h(40214), d(262676) */
    volatile Uint32 cfg5;
    /* Addr: h(40218), d(262680) */
    volatile Uint32 cfg6;
    /* Addr: h(4021C), d(262684) */
    volatile Uint32 cfg7;
    /* Addr: h(40220), d(262688) */
    volatile Uint32 cfg8;
    /* Addr: h(40224), d(262692) */
    volatile Uint32 cfg9;
    /* Addr: h(40228), d(262696) */
    volatile Uint32 cfg10;
    /* Addr: h(4022C), d(262700) */
    volatile Uint32 cfg11;
    /* Addr: h(40230), d(262704) */
    volatile Uint32 cfg12;
    /* Addr: h(40234), d(262708) */
    volatile Uint32 cfg13;
    /* Addr: h(40238), d(262712) */
    volatile Uint32 rsvd1[2];
    /* Addr: h(40240), d(262720) */
    volatile Uint32 cfg16;
    /* Addr: h(40244), d(262724) */
    volatile Uint32 cfg17;
    /* Addr: h(40248), d(262728) */
    volatile Uint32 cfg18;
    /* Addr: h(4024C), d(262732) */
    volatile Uint32 rsvd2[1];
    /* Addr: h(40250), d(262736) */
    volatile Uint32 cfg20;
    /* Addr: h(40254), d(262740) */
    volatile Uint32 cfg21;
    /* Addr: h(40258), d(262744) */
    volatile Uint32 rsvd3[1];
    /* Addr: h(4025C), d(262748) */
    volatile Uint32 cfg23;
    /* Addr: h(40260), d(262752) */
    volatile Uint32 rsvd4[1];
    /* Addr: h(40264), d(262756) */
    volatile Uint32 cfg25;
    /* Addr: h(40268), d(262760) */
    volatile Uint32 cfg26;
    /* Addr: h(4026C), d(262764) */
    volatile Uint32 cfg27;
    /* Addr: h(40270), d(262768) */
    volatile Uint32 cfg28;
    /* Addr: h(40274), d(262772) */
    volatile Uint32 rsvd5[2];
    /* Addr: h(4027C), d(262780) */
    volatile Uint32 cfg31;
    /* Addr: h(40280), d(262784) */
    volatile Uint32 cfg32;
    /* Addr: h(40284), d(262788) */
    volatile Uint32 cfg33;
    /* Addr: h(40288), d(262792) */
    volatile Uint32 cfg34;
    /* Addr: h(4028C), d(262796) */
    volatile Uint32 rsvd6[1];
    /* Addr: h(40290), d(262800) */
    volatile Uint32 cfg36;
    /* Addr: h(40294), d(262804) */
    volatile Uint32 cfg37;
    /* Addr: h(40298), d(262808) */
    volatile Uint32 cfg38;
    /* Addr: h(4029C), d(262812) */
    volatile Uint32 cfg39;
    /* Addr: h(402A0), d(262816) */
    volatile Uint32 cfg40;
    /* Addr: h(402A4), d(262820) */
    volatile Uint32 cfg41;
    /* Addr: h(402A8), d(262824) */
    volatile Uint32 cfg42;
    /* Addr: h(402AC), d(262828) */
    volatile Uint32 cfg43;
    /* Addr: h(402B0), d(262832) */
    volatile Uint32 cfg44;
    /* Addr: h(402B4), d(262836) */
    volatile Uint32 cfg45;
    /* Addr: h(402B8), d(262840) */
    volatile Uint32 cfg46;
    /* Addr: h(402BC), d(262844) */
    volatile Uint32 cfg47;
    /* Addr: h(402C0), d(262848) */
    volatile Uint32 cfg48;
    /* Addr: h(402C4), d(262852) */
    volatile Uint32 cfg49;
    /* Addr: h(402C8), d(262856) */
    volatile Uint32 cfg50;
    /* Addr: h(402CC), d(262860) */
    volatile Uint32 cfg51;
    /* Addr: h(402D0), d(262864) */
    volatile Uint32 cfg52;
    /* Addr: h(402D4), d(262868) */
    volatile Uint32 cfg53;
    /* Addr: h(402D8), d(262872) */
    volatile Uint32 cfg54;
    /* Addr: h(402DC), d(262876) */
    volatile Uint32 cfg55;
    /* Addr: h(402E0), d(262880) */
    volatile Uint32 cfg56;
    /* Addr: h(402E4), d(262884) */
    volatile Uint32 cfg57;
    /* Addr: h(402E8), d(262888) */
    volatile Uint32 cfg58;
    /* Addr: h(402EC), d(262892) */
    volatile Uint32 cfg59;
    /* Addr: h(402F0), d(262896) */
    volatile Uint32 cfg60;
    /* Addr: h(402F4), d(262900) */
    volatile Uint32 cfg61;
    /* Addr: h(402F8), d(262904) */
    volatile Uint32 cfg62;
    /* Addr: h(402FC), d(262908) */
    volatile Uint32 cfg63;
    /* Addr: h(40300), d(262912) */
    volatile Uint32 cfg64;
    /* Addr: h(40304), d(262916) */
    volatile Uint32 cfg65;
    /* Addr: h(40308), d(262920) */
    volatile Uint32 cfg66;
    /* Addr: h(4030C), d(262924) */
    volatile Uint32 cfg67;
    /* Addr: h(40310), d(262928) */
    volatile Uint32 cfg68;
    /* Addr: h(40314), d(262932) */
    volatile Uint32 cfg69;
    /* Addr: h(40318), d(262936) */
    volatile Uint32 cfg70;
    /* Addr: h(4031C), d(262940) */
    volatile Uint32 cfg71;
    /* Addr: h(40320), d(262944) */
    volatile Uint32 cfg72;
    /* Addr: h(40324), d(262948) */
    volatile Uint32 cfg73;
    /* Addr: h(40328), d(262952) */
    volatile Uint32 cfg74;
    /* Addr: h(4032C), d(262956) */
    volatile Uint32 cfg75;
    /* Addr: h(40330), d(262960) */
    volatile Uint32 cfg76;
    /* Addr: h(40334), d(262964) */
    volatile Uint32 cfg77;
    /* Addr: h(40338), d(262968) */
    volatile Uint32 cfg78;
    /* Addr: h(4033C), d(262972) */
    volatile Uint32 cfg79;
    /* Addr: h(40340), d(262976) */
    volatile Uint32 rsvd7[1];
    /* Addr: h(40344), d(262980) */
    volatile Uint32 cfg81;
    /* Addr: h(40348), d(262984) */
    volatile Uint32 cfg82;
    /* Addr: h(4034C), d(262988) */
    volatile Uint32 cfg83;
    /* Addr: h(40350), d(262992) */
    volatile Uint32 cfg84;
    /* Addr: h(40354), d(262996) */
    volatile Uint32 cfg85;
    /* Addr: h(40358), d(263000) */
    volatile Uint32 rsvd8[2];
    /* Addr: h(40360), d(263008) */
    volatile Uint32 cfg88;
    /* Addr: h(40364), d(263012) */
    volatile Uint32 cfg89;
    /* Addr: h(40368), d(263016) */
    volatile Uint32 rsvd9[1];
    /* Addr: h(4036C), d(263020) */
    volatile Uint32 cfg91;
    /* Addr: h(40370), d(263024) */
    volatile Uint32 cfg92;
    /* Addr: h(40374), d(263028) */
    volatile Uint32 cfg93;
    /* Addr: h(40378), d(263032) */
    volatile Uint32 cfg94;
    /* Addr: h(4037C), d(263036) */
    volatile Uint32 cfg95;
    /* Addr: h(40380), d(263040) */
    volatile Uint32 cfg96;
    /* Addr: h(40384), d(263044) */
    volatile Uint32 cfg97;
    /* Addr: h(40388), d(263048) */
    volatile Uint32 cfg98;
    /* Addr: h(4038C), d(263052) */
    volatile Uint32 cfg99;
    /* Addr: h(40390), d(263056) */
    volatile Uint32 cfg100;
    /* Addr: h(40394), d(263060) */
    volatile Uint32 cfg101;
    /* Addr: h(40398), d(263064) */
    volatile Uint32 cfg102;
    /* Addr: h(4039C), d(263068) */
    volatile Uint32 cfg103;
    /* Addr: h(403A0), d(263072) */
    volatile Uint32 cfg104;
    /* Addr: h(403A4), d(263076) */
    volatile Uint32 cfg105;
    /* Addr: h(403A8), d(263080) */
    volatile Uint32 cfg106;
    /* Addr: h(403AC), d(263084) */
    volatile Uint32 cfg107;
    /* Addr: h(403B0), d(263088) */
    volatile Uint32 cfg108;
    /* Addr: h(403B4), d(263092) */
    volatile Uint32 cfg109;
    /* Addr: h(403B8), d(263096) */
    volatile Uint32 cfg110;
    /* Addr: h(403BC), d(263100) */
    volatile Uint32 cfg111;
    /* Addr: h(403C0), d(263104) */
    volatile Uint32 cfg112;
    /* Addr: h(403C4), d(263108) */
    volatile Uint32 rsvd10[6];
    /* Addr: h(403DC), d(263132) */
    volatile Uint32 cfg119;
    /* Addr: h(403E0), d(263136) */
    volatile Uint32 cfg120;
    /* Addr: h(403E4), d(263140) */
    volatile Uint32 cfg121;
    /* Addr: h(403E8), d(263144) */
    volatile Uint32 cfg122;
    /* Addr: h(403EC), d(263148) */
    volatile Uint32 cfg123;
    /* Addr: h(403F0), d(263152) */
    volatile Uint32 cfg124;
    /* Addr: h(403F4), d(263156) */
    volatile Uint32 cfg125;
    /* Addr: h(403F8), d(263160) */
    volatile Uint32 cfg126;
    /* Addr: h(403FC), d(263164) */
    volatile Uint32 cfg127;
    /* Addr: h(40400), d(263168) */
    volatile Uint32 cfg_txpm0;
    /* Addr: h(40404), d(263172) */
    volatile Uint32 syncdly_txpm0;
    /* Addr: h(40408), d(263176) */
    volatile Uint32 interval_lo_txpm0;
    /* Addr: h(4040C), d(263180) */
    volatile Uint32 pdinterval_hi_txpm0;
    /* Addr: h(40410), d(263184) */
    volatile Uint32 pd_lo_txpm0;
    /* Addr: h(40414), d(263188) */
    volatile Uint32 sync_pwr_txpm0;
    /* Addr: h(40418), d(263192) */
    volatile Uint32 rsvd11[2];
    /* Addr: h(40420), d(263200) */
    volatile Uint32 cfg_txpm1;
    /* Addr: h(40424), d(263204) */
    volatile Uint32 syncdly_txpm1;
    /* Addr: h(40428), d(263208) */
    volatile Uint32 interval_lo_txpm1;
    /* Addr: h(4042C), d(263212) */
    volatile Uint32 pdinterval_hi_txpm1;
    /* Addr: h(40430), d(263216) */
    volatile Uint32 pd_lo_txpm1;
    /* Addr: h(40434), d(263220) */
    volatile Uint32 sync_pwr_txpm1;
    /* Addr: h(40438), d(263224) */
    volatile Uint32 rsvd12[2];
    /* Addr: h(40440), d(263232) */
    volatile Uint32 cfg_txpm2;
    /* Addr: h(40444), d(263236) */
    volatile Uint32 syncdly_txpm2;
    /* Addr: h(40448), d(263240) */
    volatile Uint32 interval_lo_txpm2;
    /* Addr: h(4044C), d(263244) */
    volatile Uint32 pdinterval_hi_txpm2;
    /* Addr: h(40450), d(263248) */
    volatile Uint32 pd_lo_txpm2;
    /* Addr: h(40454), d(263252) */
    volatile Uint32 sync_pwr_txpm2;
    /* Addr: h(40458), d(263256) */
    volatile Uint32 rsvd13[2];
    /* Addr: h(40460), d(263264) */
    volatile Uint32 cfg_txpm3;
    /* Addr: h(40464), d(263268) */
    volatile Uint32 syncdly_txpm3;
    /* Addr: h(40468), d(263272) */
    volatile Uint32 interval_lo_txpm3;
    /* Addr: h(4046C), d(263276) */
    volatile Uint32 pdinterval_hi_txpm3;
    /* Addr: h(40470), d(263280) */
    volatile Uint32 pd_lo_txpm3;
    /* Addr: h(40474), d(263284) */
    volatile Uint32 sync_pwr_txpm3;
    /* Addr: h(40478), d(263288) */
    volatile Uint32 rsvd14[2];
    /* Addr: h(40480), d(263296) */
    volatile Uint32 cfg_txpm4;
    /* Addr: h(40484), d(263300) */
    volatile Uint32 syncdly_txpm4;
    /* Addr: h(40488), d(263304) */
    volatile Uint32 interval_lo_txpm4;
    /* Addr: h(4048C), d(263308) */
    volatile Uint32 pdinterval_hi_txpm4;
    /* Addr: h(40490), d(263312) */
    volatile Uint32 pd_lo_txpm4;
    /* Addr: h(40494), d(263316) */
    volatile Uint32 sync_pwr_txpm4;
    /* Addr: h(40498), d(263320) */
    volatile Uint32 rsvd15[2];
    /* Addr: h(404A0), d(263328) */
    volatile Uint32 cfg_txpm5;
    /* Addr: h(404A4), d(263332) */
    volatile Uint32 syncdly_txpm5;
    /* Addr: h(404A8), d(263336) */
    volatile Uint32 interval_lo_txpm5;
    /* Addr: h(404AC), d(263340) */
    volatile Uint32 pdinterval_hi_txpm5;
    /* Addr: h(404B0), d(263344) */
    volatile Uint32 pd_lo_txpm5;
    /* Addr: h(404B4), d(263348) */
    volatile Uint32 sync_pwr_txpm5;
    /* Addr: h(404B8), d(263352) */
    volatile Uint32 rsvd16[2];
    /* Addr: h(404C0), d(263360) */
    volatile Uint32 cfg_txpm6;
    /* Addr: h(404C4), d(263364) */
    volatile Uint32 syncdly_txpm6;
    /* Addr: h(404C8), d(263368) */
    volatile Uint32 interval_lo_txpm6;
    /* Addr: h(404CC), d(263372) */
    volatile Uint32 pdinterval_hi_txpm6;
    /* Addr: h(404D0), d(263376) */
    volatile Uint32 pd_lo_txpm6;
    /* Addr: h(404D4), d(263380) */
    volatile Uint32 sync_pwr_txpm6;
    /* Addr: h(404D8), d(263384) */
    volatile Uint32 rsvd17[2];
    /* Addr: h(404E0), d(263392) */
    volatile Uint32 cfg_txpm7;
    /* Addr: h(404E4), d(263396) */
    volatile Uint32 syncdly_txpm7;
    /* Addr: h(404E8), d(263400) */
    volatile Uint32 interval_lo_txpm7;
    /* Addr: h(404EC), d(263404) */
    volatile Uint32 pdinterval_hi_txpm7;
    /* Addr: h(404F0), d(263408) */
    volatile Uint32 pd_lo_txpm7;
    /* Addr: h(404F4), d(263412) */
    volatile Uint32 sync_pwr_txpm7;
    /* Addr: h(404F8), d(263416) */
    volatile Uint32 rsvd18[2];
    /* Addr: h(40500), d(263424) */
    volatile Uint32 cfg_txpm8;
    /* Addr: h(40504), d(263428) */
    volatile Uint32 syncdly_txpm8;
    /* Addr: h(40508), d(263432) */
    volatile Uint32 interval_lo_txpm8;
    /* Addr: h(4050C), d(263436) */
    volatile Uint32 pdinterval_hi_txpm8;
    /* Addr: h(40510), d(263440) */
    volatile Uint32 pd_lo_txpm8;
    /* Addr: h(40514), d(263444) */
    volatile Uint32 sync_pwr_txpm8;
    /* Addr: h(40518), d(263448) */
    volatile Uint32 rsvd19[2];
    /* Addr: h(40520), d(263456) */
    volatile Uint32 cfg_txpm9;
    /* Addr: h(40524), d(263460) */
    volatile Uint32 syncdly_txpm9;
    /* Addr: h(40528), d(263464) */
    volatile Uint32 interval_lo_txpm9;
    /* Addr: h(4052C), d(263468) */
    volatile Uint32 pdinterval_hi_txpm9;
    /* Addr: h(40530), d(263472) */
    volatile Uint32 pd_lo_txpm9;
    /* Addr: h(40534), d(263476) */
    volatile Uint32 sync_pwr_txpm9;
    /* Addr: h(40538), d(263480) */
    volatile Uint32 rsvd20[2];
    /* Addr: h(40540), d(263488) */
    volatile Uint32 cfg_txpm10;
    /* Addr: h(40544), d(263492) */
    volatile Uint32 syncdly_txpm10;
    /* Addr: h(40548), d(263496) */
    volatile Uint32 interval_lo_txpm10;
    /* Addr: h(4054C), d(263500) */
    volatile Uint32 pdinterval_hi_txpm10;
    /* Addr: h(40550), d(263504) */
    volatile Uint32 pd_lo_txpm10;
    /* Addr: h(40554), d(263508) */
    volatile Uint32 sync_pwr_txpm10;
    /* Addr: h(40558), d(263512) */
    volatile Uint32 rsvd21[2];
    /* Addr: h(40560), d(263520) */
    volatile Uint32 cfg_txpm11;
    /* Addr: h(40564), d(263524) */
    volatile Uint32 syncdly_txpm11;
    /* Addr: h(40568), d(263528) */
    volatile Uint32 interval_lo_txpm11;
    /* Addr: h(4056C), d(263532) */
    volatile Uint32 pdinterval_hi_txpm11;
    /* Addr: h(40570), d(263536) */
    volatile Uint32 pd_lo_txpm11;
    /* Addr: h(40574), d(263540) */
    volatile Uint32 sync_pwr_txpm11;
    /* Addr: h(40578), d(263544) */
    volatile Uint32 rsvd22[2];
    /* Addr: h(40580), d(263552) */
    volatile Uint32 cfg_txpm12;
    /* Addr: h(40584), d(263556) */
    volatile Uint32 syncdly_txpm12;
    /* Addr: h(40588), d(263560) */
    volatile Uint32 interval_lo_txpm12;
    /* Addr: h(4058C), d(263564) */
    volatile Uint32 pdinterval_hi_txpm12;
    /* Addr: h(40590), d(263568) */
    volatile Uint32 pd_lo_txpm12;
    /* Addr: h(40594), d(263572) */
    volatile Uint32 sync_pwr_txpm12;
    /* Addr: h(40598), d(263576) */
    volatile Uint32 rsvd23[2];
    /* Addr: h(405A0), d(263584) */
    volatile Uint32 cfg_txpm13;
    /* Addr: h(405A4), d(263588) */
    volatile Uint32 syncdly_txpm13;
    /* Addr: h(405A8), d(263592) */
    volatile Uint32 interval_lo_txpm13;
    /* Addr: h(405AC), d(263596) */
    volatile Uint32 pdinterval_hi_txpm13;
    /* Addr: h(405B0), d(263600) */
    volatile Uint32 pd_lo_txpm13;
    /* Addr: h(405B4), d(263604) */
    volatile Uint32 sync_pwr_txpm13;
    /* Addr: h(405B8), d(263608) */
    volatile Uint32 rsvd24[2];
    /* Addr: h(405C0), d(263616) */
    volatile Uint32 cfg_txpm14;
    /* Addr: h(405C4), d(263620) */
    volatile Uint32 syncdly_txpm14;
    /* Addr: h(405C8), d(263624) */
    volatile Uint32 interval_lo_txpm14;
    /* Addr: h(405CC), d(263628) */
    volatile Uint32 pdinterval_hi_txpm14;
    /* Addr: h(405D0), d(263632) */
    volatile Uint32 pd_lo_txpm14;
    /* Addr: h(405D4), d(263636) */
    volatile Uint32 sync_pwr_txpm14;
    /* Addr: h(405D8), d(263640) */
    volatile Uint32 rsvd25[2];
    /* Addr: h(405E0), d(263648) */
    volatile Uint32 cfg_txpm15;
    /* Addr: h(405E4), d(263652) */
    volatile Uint32 syncdly_txpm15;
    /* Addr: h(405E8), d(263656) */
    volatile Uint32 interval_lo_txpm15;
    /* Addr: h(405EC), d(263660) */
    volatile Uint32 pdinterval_hi_txpm15;
    /* Addr: h(405F0), d(263664) */
    volatile Uint32 pd_lo_txpm15;
    /* Addr: h(405F4), d(263668) */
    volatile Uint32 sync_pwr_txpm15;
    /* Addr: h(405F8), d(263672) */
    volatile Uint32 rsvd26[1];
    /* Addr: h(405FC), d(263676) */
    volatile Uint32 txpm_update_disable;
    /* Addr: h(40600), d(263680) */
    volatile Uint32 txpm_auxint_mask;
    /* Addr: h(40604), d(263684) */
    volatile Uint32 rsvd27[127];
    /* Addr: h(40800), d(264192) */
    volatile Uint32 cfg_rxpm0;
    /* Addr: h(40804), d(264196) */
    volatile Uint32 syncdly_rxpm0;
    /* Addr: h(40808), d(264200) */
    volatile Uint32 interval_lo_rxpm0;
    /* Addr: h(4080C), d(264204) */
    volatile Uint32 pdinterval_hi_rxpm0;
    /* Addr: h(40810), d(264208) */
    volatile Uint32 pd_lo_rxpm0;
    /* Addr: h(40814), d(264212) */
    volatile Uint32 sync_pwr_rxpm0;
    /* Addr: h(40818), d(264216) */
    volatile Uint32 rxpm_max_db0;
    /* Addr: h(4081C), d(264220) */
    volatile Uint32 rsvd28[1];
    /* Addr: h(40820), d(264224) */
    volatile Uint32 cfg_rxpm1;
    /* Addr: h(40824), d(264228) */
    volatile Uint32 syncdly_rxpm1;
    /* Addr: h(40828), d(264232) */
    volatile Uint32 interval_lo_rxpm1;
    /* Addr: h(4082C), d(264236) */
    volatile Uint32 pdinterval_hi_rxpm1;
    /* Addr: h(40830), d(264240) */
    volatile Uint32 pd_lo_rxpm1;
    /* Addr: h(40834), d(264244) */
    volatile Uint32 sync_pwr_rxpm1;
    /* Addr: h(40838), d(264248) */
    volatile Uint32 rxpm_max_db1;
    /* Addr: h(4083C), d(264252) */
    volatile Uint32 rsvd29[1];
    /* Addr: h(40840), d(264256) */
    volatile Uint32 cfg_rxpm2;
    /* Addr: h(40844), d(264260) */
    volatile Uint32 syncdly_rxpm2;
    /* Addr: h(40848), d(264264) */
    volatile Uint32 interval_lo_rxpm2;
    /* Addr: h(4084C), d(264268) */
    volatile Uint32 pdinterval_hi_rxpm2;
    /* Addr: h(40850), d(264272) */
    volatile Uint32 pd_lo_rxpm2;
    /* Addr: h(40854), d(264276) */
    volatile Uint32 sync_pwr_rxpm2;
    /* Addr: h(40858), d(264280) */
    volatile Uint32 rxpm_max_db2;
    /* Addr: h(4085C), d(264284) */
    volatile Uint32 rsvd30[1];
    /* Addr: h(40860), d(264288) */
    volatile Uint32 cfg_rxpm3;
    /* Addr: h(40864), d(264292) */
    volatile Uint32 syncdly_rxpm3;
    /* Addr: h(40868), d(264296) */
    volatile Uint32 interval_lo_rxpm3;
    /* Addr: h(4086C), d(264300) */
    volatile Uint32 pdinterval_hi_rxpm3;
    /* Addr: h(40870), d(264304) */
    volatile Uint32 pd_lo_rxpm3;
    /* Addr: h(40874), d(264308) */
    volatile Uint32 sync_pwr_rxpm3;
    /* Addr: h(40878), d(264312) */
    volatile Uint32 rxpm_max_db3;
    /* Addr: h(4087C), d(264316) */
    volatile Uint32 rsvd31[1];
    /* Addr: h(40880), d(264320) */
    volatile Uint32 cfg_rxpm4;
    /* Addr: h(40884), d(264324) */
    volatile Uint32 syncdly_rxpm4;
    /* Addr: h(40888), d(264328) */
    volatile Uint32 interval_lo_rxpm4;
    /* Addr: h(4088C), d(264332) */
    volatile Uint32 pdinterval_hi_rxpm4;
    /* Addr: h(40890), d(264336) */
    volatile Uint32 pd_lo_rxpm4;
    /* Addr: h(40894), d(264340) */
    volatile Uint32 sync_pwr_rxpm4;
    /* Addr: h(40898), d(264344) */
    volatile Uint32 rxpm_max_db4;
    /* Addr: h(4089C), d(264348) */
    volatile Uint32 rsvd32[1];
    /* Addr: h(408A0), d(264352) */
    volatile Uint32 cfg_rxpm5;
    /* Addr: h(408A4), d(264356) */
    volatile Uint32 syncdly_rxpm5;
    /* Addr: h(408A8), d(264360) */
    volatile Uint32 interval_lo_rxpm5;
    /* Addr: h(408AC), d(264364) */
    volatile Uint32 pdinterval_hi_rxpm5;
    /* Addr: h(408B0), d(264368) */
    volatile Uint32 pd_lo_rxpm5;
    /* Addr: h(408B4), d(264372) */
    volatile Uint32 sync_pwr_rxpm5;
    /* Addr: h(408B8), d(264376) */
    volatile Uint32 rxpm_max_db5;
    /* Addr: h(408BC), d(264380) */
    volatile Uint32 rsvd33[1];
    /* Addr: h(408C0), d(264384) */
    volatile Uint32 cfg_rxpm6;
    /* Addr: h(408C4), d(264388) */
    volatile Uint32 syncdly_rxpm6;
    /* Addr: h(408C8), d(264392) */
    volatile Uint32 interval_lo_rxpm6;
    /* Addr: h(408CC), d(264396) */
    volatile Uint32 pdinterval_hi_rxpm6;
    /* Addr: h(408D0), d(264400) */
    volatile Uint32 pd_lo_rxpm6;
    /* Addr: h(408D4), d(264404) */
    volatile Uint32 sync_pwr_rxpm6;
    /* Addr: h(408D8), d(264408) */
    volatile Uint32 rxpm_max_db6;
    /* Addr: h(408DC), d(264412) */
    volatile Uint32 rsvd34[1];
    /* Addr: h(408E0), d(264416) */
    volatile Uint32 cfg_rxpm7;
    /* Addr: h(408E4), d(264420) */
    volatile Uint32 syncdly_rxpm7;
    /* Addr: h(408E8), d(264424) */
    volatile Uint32 interval_lo_rxpm7;
    /* Addr: h(408EC), d(264428) */
    volatile Uint32 pdinterval_hi_rxpm7;
    /* Addr: h(408F0), d(264432) */
    volatile Uint32 pd_lo_rxpm7;
    /* Addr: h(408F4), d(264436) */
    volatile Uint32 sync_pwr_rxpm7;
    /* Addr: h(408F8), d(264440) */
    volatile Uint32 rxpm_max_db7;
    /* Addr: h(408FC), d(264444) */
    volatile Uint32 rsvd35[1];
    /* Addr: h(40900), d(264448) */
    volatile Uint32 cfg_rxpm8;
    /* Addr: h(40904), d(264452) */
    volatile Uint32 syncdly_rxpm8;
    /* Addr: h(40908), d(264456) */
    volatile Uint32 interval_lo_rxpm8;
    /* Addr: h(4090C), d(264460) */
    volatile Uint32 pdinterval_hi_rxpm8;
    /* Addr: h(40910), d(264464) */
    volatile Uint32 pd_lo_rxpm8;
    /* Addr: h(40914), d(264468) */
    volatile Uint32 sync_pwr_rxpm8;
    /* Addr: h(40918), d(264472) */
    volatile Uint32 rxpm_max_db8;
    /* Addr: h(4091C), d(264476) */
    volatile Uint32 rsvd36[1];
    /* Addr: h(40920), d(264480) */
    volatile Uint32 cfg_rxpm9;
    /* Addr: h(40924), d(264484) */
    volatile Uint32 syncdly_rxpm9;
    /* Addr: h(40928), d(264488) */
    volatile Uint32 interval_lo_rxpm9;
    /* Addr: h(4092C), d(264492) */
    volatile Uint32 pdinterval_hi_rxpm9;
    /* Addr: h(40930), d(264496) */
    volatile Uint32 pd_lo_rxpm9;
    /* Addr: h(40934), d(264500) */
    volatile Uint32 sync_pwr_rxpm9;
    /* Addr: h(40938), d(264504) */
    volatile Uint32 rxpm_max_db9;
    /* Addr: h(4093C), d(264508) */
    volatile Uint32 rsvd37[1];
    /* Addr: h(40940), d(264512) */
    volatile Uint32 cfg_rxpm10;
    /* Addr: h(40944), d(264516) */
    volatile Uint32 syncdly_rxpm10;
    /* Addr: h(40948), d(264520) */
    volatile Uint32 interval_lo_rxpm10;
    /* Addr: h(4094C), d(264524) */
    volatile Uint32 pdinterval_hi_rxpm10;
    /* Addr: h(40950), d(264528) */
    volatile Uint32 pd_lo_rxpm10;
    /* Addr: h(40954), d(264532) */
    volatile Uint32 sync_pwr_rxpm10;
    /* Addr: h(40958), d(264536) */
    volatile Uint32 rxpm_max_db10;
    /* Addr: h(4095C), d(264540) */
    volatile Uint32 rsvd38[1];
    /* Addr: h(40960), d(264544) */
    volatile Uint32 cfg_rxpm11;
    /* Addr: h(40964), d(264548) */
    volatile Uint32 syncdly_rxpm11;
    /* Addr: h(40968), d(264552) */
    volatile Uint32 interval_lo_rxpm11;
    /* Addr: h(4096C), d(264556) */
    volatile Uint32 pdinterval_hi_rxpm11;
    /* Addr: h(40970), d(264560) */
    volatile Uint32 pd_lo_rxpm11;
    /* Addr: h(40974), d(264564) */
    volatile Uint32 sync_pwr_rxpm11;
    /* Addr: h(40978), d(264568) */
    volatile Uint32 rxpm_max_db11;
    /* Addr: h(4097C), d(264572) */
    volatile Uint32 rsvd39[1];
    /* Addr: h(40980), d(264576) */
    volatile Uint32 cfg_rxpm12;
    /* Addr: h(40984), d(264580) */
    volatile Uint32 syncdly_rxpm12;
    /* Addr: h(40988), d(264584) */
    volatile Uint32 interval_lo_rxpm12;
    /* Addr: h(4098C), d(264588) */
    volatile Uint32 pdinterval_hi_rxpm12;
    /* Addr: h(40990), d(264592) */
    volatile Uint32 pd_lo_rxpm12;
    /* Addr: h(40994), d(264596) */
    volatile Uint32 sync_pwr_rxpm12;
    /* Addr: h(40998), d(264600) */
    volatile Uint32 rxpm_max_db12;
    /* Addr: h(4099C), d(264604) */
    volatile Uint32 rsvd40[1];
    /* Addr: h(409A0), d(264608) */
    volatile Uint32 cfg_rxpm13;
    /* Addr: h(409A4), d(264612) */
    volatile Uint32 syncdly_rxpm13;
    /* Addr: h(409A8), d(264616) */
    volatile Uint32 interval_lo_rxpm13;
    /* Addr: h(409AC), d(264620) */
    volatile Uint32 pdinterval_hi_rxpm13;
    /* Addr: h(409B0), d(264624) */
    volatile Uint32 pd_lo_rxpm13;
    /* Addr: h(409B4), d(264628) */
    volatile Uint32 sync_pwr_rxpm13;
    /* Addr: h(409B8), d(264632) */
    volatile Uint32 rxpm_max_db13;
    /* Addr: h(409BC), d(264636) */
    volatile Uint32 rsvd41[1];
    /* Addr: h(409C0), d(264640) */
    volatile Uint32 cfg_rxpm14;
    /* Addr: h(409C4), d(264644) */
    volatile Uint32 syncdly_rxpm14;
    /* Addr: h(409C8), d(264648) */
    volatile Uint32 interval_lo_rxpm14;
    /* Addr: h(409CC), d(264652) */
    volatile Uint32 pdinterval_hi_rxpm14;
    /* Addr: h(409D0), d(264656) */
    volatile Uint32 pd_lo_rxpm14;
    /* Addr: h(409D4), d(264660) */
    volatile Uint32 sync_pwr_rxpm14;
    /* Addr: h(409D8), d(264664) */
    volatile Uint32 rxpm_max_db14;
    /* Addr: h(409DC), d(264668) */
    volatile Uint32 rsvd42[1];
    /* Addr: h(409E0), d(264672) */
    volatile Uint32 cfg_rxpm15;
    /* Addr: h(409E4), d(264676) */
    volatile Uint32 syncdly_rxpm15;
    /* Addr: h(409E8), d(264680) */
    volatile Uint32 interval_lo_rxpm15;
    /* Addr: h(409EC), d(264684) */
    volatile Uint32 pdinterval_hi_rxpm15;
    /* Addr: h(409F0), d(264688) */
    volatile Uint32 pd_lo_rxpm15;
    /* Addr: h(409F4), d(264692) */
    volatile Uint32 sync_pwr_rxpm15;
    /* Addr: h(409F8), d(264696) */
    volatile Uint32 rxpm_max_db15;
    /* Addr: h(409FC), d(264700) */
    volatile Uint32 rxpm_update_disable;
    /* Addr: h(40A00), d(264704) */
    volatile Uint32 rxpm_auxint_mask;
    /* Addr: h(40A04), d(264708) */
    volatile Uint32 rsvd43[127];
    /* Addr: h(40C00), d(265216) */
    volatile Uint32 signal_gen0_ctrl0;
    /* Addr: h(40C04), d(265220) */
    volatile Uint32 ck_dduc0_signal_len;
    /* Addr: h(40C08), d(265224) */
    volatile Uint32 ck_dduc0_chan_sel;
    /* Addr: h(40C0C), d(265228) */
    volatile Uint32 ck_dduc0_result_lo;
    /* Addr: h(40C10), d(265232) */
    volatile Uint32 ck_dduc0_result_hi;
    /* Addr: h(40C14), d(265236) */
    volatile Uint32 ck_dduc0_dduc0_ssel;
    /* Addr: h(40C18), d(265240) */
    volatile Uint32 gcck_dduc0_general;
    /* Addr: h(40C1C), d(265244) */
    volatile Uint32 signal_gen0_ramp_start_lo;
    /* Addr: h(40C20), d(265248) */
    volatile Uint32 signal_gen0_ramp_start_hi;
    /* Addr: h(40C24), d(265252) */
    volatile Uint32 signal_gen0_ramp_stop_lo;
    /* Addr: h(40C28), d(265256) */
    volatile Uint32 signal_gen0_ramp_stop_hi;
    /* Addr: h(40C2C), d(265260) */
    volatile Uint32 signal_gen0_ramp_slope_lo;
    /* Addr: h(40C30), d(265264) */
    volatile Uint32 signal_gen0_ramp_slope_hi;
    /* Addr: h(40C34), d(265268) */
    volatile Uint32 signal_gen0_gen_timer;
    /* Addr: h(40C38), d(265272) */
    volatile Uint32 rsvd44[2];
    /* Addr: h(40C40), d(265280) */
    volatile Uint32 signal_gen1_ctrl0;
    /* Addr: h(40C44), d(265284) */
    volatile Uint32 ck_dduc1_signal_len;
    /* Addr: h(40C48), d(265288) */
    volatile Uint32 ck_dduc1_chan_sel;
    /* Addr: h(40C4C), d(265292) */
    volatile Uint32 ck_dduc1_result_lo;
    /* Addr: h(40C50), d(265296) */
    volatile Uint32 ck_dduc1_result_hi;
    /* Addr: h(40C54), d(265300) */
    volatile Uint32 ck_dduc1_dduc1_ssel;
    /* Addr: h(40C58), d(265304) */
    volatile Uint32 gcck_dduc1_general;
    /* Addr: h(40C5C), d(265308) */
    volatile Uint32 signal_gen1_ramp_start_lo;
    /* Addr: h(40C60), d(265312) */
    volatile Uint32 signal_gen1_ramp_start_hi;
    /* Addr: h(40C64), d(265316) */
    volatile Uint32 signal_gen1_ramp_stop_lo;
    /* Addr: h(40C68), d(265320) */
    volatile Uint32 signal_gen1_ramp_stop_hi;
    /* Addr: h(40C6C), d(265324) */
    volatile Uint32 signal_gen1_ramp_slope_lo;
    /* Addr: h(40C70), d(265328) */
    volatile Uint32 signal_gen1_ramp_slope_hi;
    /* Addr: h(40C74), d(265332) */
    volatile Uint32 signal_gen1_gen_timer;
    /* Addr: h(40C78), d(265336) */
    volatile Uint32 rsvd45[2];
    /* Addr: h(40C80), d(265344) */
    volatile Uint32 signal_gen2_ctrl0;
    /* Addr: h(40C84), d(265348) */
    volatile Uint32 ck_dduc2_signal_len;
    /* Addr: h(40C88), d(265352) */
    volatile Uint32 ck_dduc2_chan_sel;
    /* Addr: h(40C8C), d(265356) */
    volatile Uint32 ck_dduc2_result_lo;
    /* Addr: h(40C90), d(265360) */
    volatile Uint32 ck_dduc2_result_hi;
    /* Addr: h(40C94), d(265364) */
    volatile Uint32 ck_dduc2_dduc0_ssel;
    /* Addr: h(40C98), d(265368) */
    volatile Uint32 gcck_dduc2_general;
    /* Addr: h(40C9C), d(265372) */
    volatile Uint32 signal_gen2_ramp_start_lo;
    /* Addr: h(40CA0), d(265376) */
    volatile Uint32 signal_gen2_ramp_start_hi;
    /* Addr: h(40CA4), d(265380) */
    volatile Uint32 signal_gen2_ramp_stop_lo;
    /* Addr: h(40CA8), d(265384) */
    volatile Uint32 signal_gen2_ramp_stop_hi;
    /* Addr: h(40CAC), d(265388) */
    volatile Uint32 signal_gen2_ramp_slope_lo;
    /* Addr: h(40CB0), d(265392) */
    volatile Uint32 signal_gen2_ramp_slope_hi;
    /* Addr: h(40CB4), d(265396) */
    volatile Uint32 signal_gen2_gen_timer;
    /* Addr: h(40CB8), d(265400) */
    volatile Uint32 rsvd46[2];
    /* Addr: h(40CC0), d(265408) */
    volatile Uint32 signal_gen3_ctrl0;
    /* Addr: h(40CC4), d(265412) */
    volatile Uint32 ck_dduc3_signal_len;
    /* Addr: h(40CC8), d(265416) */
    volatile Uint32 ck_dduc3_chan_sel;
    /* Addr: h(40CCC), d(265420) */
    volatile Uint32 ck_dduc3_result_lo;
    /* Addr: h(40CD0), d(265424) */
    volatile Uint32 ck_dduc3_result_hi;
    /* Addr: h(40CD4), d(265428) */
    volatile Uint32 ck_dduc3_dduc1_ssel;
    /* Addr: h(40CD8), d(265432) */
    volatile Uint32 gcck_dduc3_general;
    /* Addr: h(40CDC), d(265436) */
    volatile Uint32 signal_gen3_ramp_start_lo;
    /* Addr: h(40CE0), d(265440) */
    volatile Uint32 signal_gen3_ramp_start_hi;
    /* Addr: h(40CE4), d(265444) */
    volatile Uint32 signal_gen3_ramp_stop_lo;
    /* Addr: h(40CE8), d(265448) */
    volatile Uint32 signal_gen3_ramp_stop_hi;
    /* Addr: h(40CEC), d(265452) */
    volatile Uint32 signal_gen3_ramp_slope_lo;
    /* Addr: h(40CF0), d(265456) */
    volatile Uint32 signal_gen3_ramp_slope_hi;
    /* Addr: h(40CF4), d(265460) */
    volatile Uint32 signal_gen3_gen_timer;
    /* Addr: h(40CF8), d(265464) */
    volatile Uint32 rsvd47[2];
    /* Addr: h(40D00), d(265472) */
    volatile Uint32 signal_gen4_ctrl0;
    /* Addr: h(40D04), d(265476) */
    volatile Uint32 ck_dduc4_signal_len;
    /* Addr: h(40D08), d(265480) */
    volatile Uint32 ck_dduc4_chan_sel;
    /* Addr: h(40D0C), d(265484) */
    volatile Uint32 ck_dduc4_result_lo;
    /* Addr: h(40D10), d(265488) */
    volatile Uint32 ck_dduc4_result_hi;
    /* Addr: h(40D14), d(265492) */
    volatile Uint32 ck_dduc4_dduc0_ssel;
    /* Addr: h(40D18), d(265496) */
    volatile Uint32 gcck_dduc4_general;
    /* Addr: h(40D1C), d(265500) */
    volatile Uint32 signal_gen4_ramp_start_lo;
    /* Addr: h(40D20), d(265504) */
    volatile Uint32 signal_gen4_ramp_start_hi;
    /* Addr: h(40D24), d(265508) */
    volatile Uint32 signal_gen4_ramp_stop_lo;
    /* Addr: h(40D28), d(265512) */
    volatile Uint32 signal_gen4_ramp_stop_hi;
    /* Addr: h(40D2C), d(265516) */
    volatile Uint32 signal_gen4_ramp_slope_lo;
    /* Addr: h(40D30), d(265520) */
    volatile Uint32 signal_gen4_ramp_slope_hi;
    /* Addr: h(40D34), d(265524) */
    volatile Uint32 signal_gen4_gen_timer;
    /* Addr: h(40D38), d(265528) */
    volatile Uint32 rsvd48[2];
    /* Addr: h(40D40), d(265536) */
    volatile Uint32 signal_gen5_ctrl0;
    /* Addr: h(40D44), d(265540) */
    volatile Uint32 ck_dduc5_signal_len;
    /* Addr: h(40D48), d(265544) */
    volatile Uint32 ck_dduc5_chan_sel;
    /* Addr: h(40D4C), d(265548) */
    volatile Uint32 ck_dduc5_result_lo;
    /* Addr: h(40D50), d(265552) */
    volatile Uint32 ck_dduc5_result_hi;
    /* Addr: h(40D54), d(265556) */
    volatile Uint32 ck_dduc5_dduc1_ssel;
    /* Addr: h(40D58), d(265560) */
    volatile Uint32 gcck_dduc5_general;
    /* Addr: h(40D5C), d(265564) */
    volatile Uint32 signal_gen5_ramp_start_lo;
    /* Addr: h(40D60), d(265568) */
    volatile Uint32 signal_gen5_ramp_start_hi;
    /* Addr: h(40D64), d(265572) */
    volatile Uint32 signal_gen5_ramp_stop_lo;
    /* Addr: h(40D68), d(265576) */
    volatile Uint32 signal_gen5_ramp_stop_hi;
    /* Addr: h(40D6C), d(265580) */
    volatile Uint32 signal_gen5_ramp_slope_lo;
    /* Addr: h(40D70), d(265584) */
    volatile Uint32 signal_gen5_ramp_slope_hi;
    /* Addr: h(40D74), d(265588) */
    volatile Uint32 signal_gen5_gen_timer;
    /* Addr: h(40D78), d(265592) */
    volatile Uint32 rsvd49[2];
    /* Addr: h(40D80), d(265600) */
    volatile Uint32 signal_gen6_ctrl0;
    /* Addr: h(40D84), d(265604) */
    volatile Uint32 ck_dduc6_signal_len;
    /* Addr: h(40D88), d(265608) */
    volatile Uint32 ck_dduc6_chan_sel;
    /* Addr: h(40D8C), d(265612) */
    volatile Uint32 ck_dduc6_result_lo;
    /* Addr: h(40D90), d(265616) */
    volatile Uint32 ck_dduc6_result_hi;
    /* Addr: h(40D94), d(265620) */
    volatile Uint32 ck_dduc6_dduc0_ssel;
    /* Addr: h(40D98), d(265624) */
    volatile Uint32 gcck_dduc6_general;
    /* Addr: h(40D9C), d(265628) */
    volatile Uint32 signal_gen6_ramp_start_lo;
    /* Addr: h(40DA0), d(265632) */
    volatile Uint32 signal_gen6_ramp_start_hi;
    /* Addr: h(40DA4), d(265636) */
    volatile Uint32 signal_gen6_ramp_stop_lo;
    /* Addr: h(40DA8), d(265640) */
    volatile Uint32 signal_gen6_ramp_stop_hi;
    /* Addr: h(40DAC), d(265644) */
    volatile Uint32 signal_gen6_ramp_slope_lo;
    /* Addr: h(40DB0), d(265648) */
    volatile Uint32 signal_gen6_ramp_slope_hi;
    /* Addr: h(40DB4), d(265652) */
    volatile Uint32 signal_gen6_gen_timer;
    /* Addr: h(40DB8), d(265656) */
    volatile Uint32 rsvd50[2];
    /* Addr: h(40DC0), d(265664) */
    volatile Uint32 signal_gen7_ctrl0;
    /* Addr: h(40DC4), d(265668) */
    volatile Uint32 ck_dduc7_signal_len;
    /* Addr: h(40DC8), d(265672) */
    volatile Uint32 ck_dduc7_chan_sel;
    /* Addr: h(40DCC), d(265676) */
    volatile Uint32 ck_dduc7_result_lo;
    /* Addr: h(40DD0), d(265680) */
    volatile Uint32 ck_dduc7_result_hi;
    /* Addr: h(40DD4), d(265684) */
    volatile Uint32 ck_dduc7_dduc1_ssel;
    /* Addr: h(40DD8), d(265688) */
    volatile Uint32 gcck_dduc7_general;
    /* Addr: h(40DDC), d(265692) */
    volatile Uint32 signal_gen7_ramp_start_lo;
    /* Addr: h(40DE0), d(265696) */
    volatile Uint32 signal_gen7_ramp_start_hi;
    /* Addr: h(40DE4), d(265700) */
    volatile Uint32 signal_gen7_ramp_stop_lo;
    /* Addr: h(40DE8), d(265704) */
    volatile Uint32 signal_gen7_ramp_stop_hi;
    /* Addr: h(40DEC), d(265708) */
    volatile Uint32 signal_gen7_ramp_slope_lo;
    /* Addr: h(40DF0), d(265712) */
    volatile Uint32 signal_gen7_ramp_slope_hi;
    /* Addr: h(40DF4), d(265716) */
    volatile Uint32 signal_gen7_gen_timer;
    /* Addr: h(40DF8), d(265720) */
    volatile Uint32 rsvd51[2];
    /* Addr: h(40E00), d(265728) */
    volatile Uint32 ck_suma_ctrl0;
    /* Addr: h(40E04), d(265732) */
    volatile Uint32 ck_suma_signal_len;
    /* Addr: h(40E08), d(265736) */
    volatile Uint32 ck_suma_chan_sel;
    /* Addr: h(40E0C), d(265740) */
    volatile Uint32 ck_suma_result_lo;
    /* Addr: h(40E10), d(265744) */
    volatile Uint32 ck_suma_result_hi;
    /* Addr: h(40E14), d(265748) */
    volatile Uint32 ck_suma_ctrl1;
    /* Addr: h(40E18), d(265752) */
    volatile Uint32 gcck_aida_general;
    /* Addr: h(40E1C), d(265756) */
    volatile Uint32 signal_gena_ramp_start_lo;
    /* Addr: h(40E20), d(265760) */
    volatile Uint32 signal_gena_ramp_start_hi;
    /* Addr: h(40E24), d(265764) */
    volatile Uint32 signal_gena_ramp_stop_lo;
    /* Addr: h(40E28), d(265768) */
    volatile Uint32 signal_gena_ramp_stop_hi;
    /* Addr: h(40E2C), d(265772) */
    volatile Uint32 signal_gena_ramp_slope_lo;
    /* Addr: h(40E30), d(265776) */
    volatile Uint32 signal_gena_ramp_slope_hi;
    /* Addr: h(40E34), d(265780) */
    volatile Uint32 signal_gena_gen_timer;
    /* Addr: h(40E38), d(265784) */
    volatile Uint32 rsvd52[2];
    /* Addr: h(40E40), d(265792) */
    volatile Uint32 ck_sumb_ctrl0;
    /* Addr: h(40E44), d(265796) */
    volatile Uint32 ck_sumb_signal_len;
    /* Addr: h(40E48), d(265800) */
    volatile Uint32 ck_sumb_chan_sel;
    /* Addr: h(40E4C), d(265804) */
    volatile Uint32 ck_sumb_result_lo;
    /* Addr: h(40E50), d(265808) */
    volatile Uint32 ck_sumb_result_hi;
    /* Addr: h(40E54), d(265812) */
    volatile Uint32 ck_sumb_ctrl1;
    /* Addr: h(40E58), d(265816) */
    volatile Uint32 gcck_aidb_general;
    /* Addr: h(40E5C), d(265820) */
    volatile Uint32 signal_genb_ramp_start_lo;
    /* Addr: h(40E60), d(265824) */
    volatile Uint32 signal_genb_ramp_start_hi;
    /* Addr: h(40E64), d(265828) */
    volatile Uint32 signal_genb_ramp_stop_lo;
    /* Addr: h(40E68), d(265832) */
    volatile Uint32 signal_genb_ramp_stop_hi;
    /* Addr: h(40E6C), d(265836) */
    volatile Uint32 signal_genb_ramp_slope_lo;
    /* Addr: h(40E70), d(265840) */
    volatile Uint32 signal_genb_ramp_slope_hi;
    /* Addr: h(40E74), d(265844) */
    volatile Uint32 signal_genb_gen_timer;
    /* Addr: h(40E78), d(265848) */
    volatile Uint32 rsvd53[98];
    /* Addr: h(41000), d(266240) */
    volatile CSL_DFE_BB_ANTCAL_REGS antcal[8];
    /* Addr: h(41080), d(266368) */
    volatile Uint32 rsvd54[32];
    /* Addr: h(41100), d(266496) */
    volatile Uint32 cfg1088;
    /* Addr: h(41104), d(266500) */
    volatile Uint32 cfg1089;
    /* Addr: h(41108), d(266504) */
    volatile Uint32 cfg1090;
    /* Addr: h(4110C), d(266508) */
    volatile Uint32 cfg1091;
    /* Addr: h(41110), d(266512) */
    volatile Uint32 cfg1092;
    /* Addr: h(41114), d(266516) */
    volatile Uint32 cfg1093;
    /* Addr: h(41118), d(266520) */
    volatile Uint32 cfg1094;
    /* Addr: h(4111C), d(266524) */
    volatile Uint32 rsvd55[57];
    /* Addr: h(41200), d(266752) */
    volatile Uint32 cfg1152;
    /* Addr: h(41204), d(266756) */
    volatile Uint32 cfg1153;
    /* Addr: h(41208), d(266760) */
    volatile Uint32 cfg1154;
    /* Addr: h(4120C), d(266764) */
    volatile Uint32 cfg1155;
    /* Addr: h(41210), d(266768) */
    volatile Uint32 cfg1156;
    /* Addr: h(41214), d(266772) */
    volatile Uint32 rsvd56[3];
    /* Addr: h(41220), d(266784) */
    volatile Uint32 cfg1160;
    /* Addr: h(41224), d(266788) */
    volatile Uint32 cfg1161;
    /* Addr: h(41228), d(266792) */
    volatile Uint32 cfg1162;
    /* Addr: h(4122C), d(266796) */
    volatile Uint32 cfg1163;
    /* Addr: h(41230), d(266800) */
    volatile Uint32 cfg1164;
    /* Addr: h(41234), d(266804) */
    volatile Uint32 rsvd57[3];
    /* Addr: h(41240), d(266816) */
    volatile Uint32 cfg1168;
    /* Addr: h(41244), d(266820) */
    volatile Uint32 cfg1169;
    /* Addr: h(41248), d(266824) */
    volatile Uint32 cfg1170;
    /* Addr: h(4124C), d(266828) */
    volatile Uint32 cfg1171;
    /* Addr: h(41250), d(266832) */
    volatile Uint32 cfg1172;
    /* Addr: h(41254), d(266836) */
    volatile Uint32 cfg1173;
    /* Addr: h(41258), d(266840) */
    volatile Uint32 cfg1174;
    /* Addr: h(4125C), d(266844) */
    volatile Uint32 cfg1175;
    /* Addr: h(41260), d(266848) */
    volatile Uint32 cfg1176;
    /* Addr: h(41264), d(266852) */
    volatile Uint32 cfg1177;
    /* Addr: h(41268), d(266856) */
    volatile Uint32 rsvd58[6];
    /* Addr: h(41280), d(266880) */
    volatile Uint32 cfg1184;
    /* Addr: h(41284), d(266884) */
    volatile Uint32 cfg1185;
    /* Addr: h(41288), d(266888) */
    volatile Uint32 cfg1186;
    /* Addr: h(4128C), d(266892) */
    volatile Uint32 cfg1187;
    /* Addr: h(41290), d(266896) */
    volatile Uint32 cfg1188;
    /* Addr: h(41294), d(266900) */
    volatile Uint32 cfg1189;
    /* Addr: h(41298), d(266904) */
    volatile Uint32 cfg1190;
    /* Addr: h(4129C), d(266908) */
    volatile Uint32 cfg1191;
    /* Addr: h(412A0), d(266912) */
    volatile Uint32 cfg1192;
    /* Addr: h(412A4), d(266916) */
    volatile Uint32 cfg1193;
    /* Addr: h(412A8), d(266920) */
    volatile Uint32 rsvd59[86];
    /* Addr: h(41400), d(267264) */
    volatile CSL_DFE_BB_CLKGATE_REGS clkgate[8];
    /* Addr: h(41800), d(268288) */
    volatile Uint32 intmask0;
    /* Addr: h(41804), d(268292) */
    volatile Uint32 intstatus0;
    /* Addr: h(41808), d(268296) */
    volatile Uint32 intforce0;
    /* Addr: h(4180C), d(268300) */
    volatile Uint32 rsvd60[13];
    /* Addr: h(41840), d(268352) */
    volatile Uint32 intmask1;
    /* Addr: h(41844), d(268356) */
    volatile Uint32 intstatus1;
    /* Addr: h(41848), d(268360) */
    volatile Uint32 intforce1;
    /* Addr: h(4184C), d(268364) */
    volatile Uint32 rsvd61[13];
    /* Addr: h(41880), d(268416) */
    volatile Uint32 intmask2;
    /* Addr: h(41884), d(268420) */
    volatile Uint32 intstatus2;
    /* Addr: h(41888), d(268424) */
    volatile Uint32 intforce2;
    /* Addr: h(4188C), d(268428) */
    volatile Uint32 rsvd62[13];
    /* Addr: h(418C0), d(268480) */
    volatile Uint32 intmask3;
    /* Addr: h(418C4), d(268484) */
    volatile Uint32 intstatus3;
    /* Addr: h(418C8), d(268488) */
    volatile Uint32 intforce3;
    /* Addr: h(418CC), d(268492) */
    volatile Uint32 rsvd63[13];
    /* Addr: h(41900), d(268544) */
    volatile Uint32 intmask4;
    /* Addr: h(41904), d(268548) */
    volatile Uint32 intmask4a;
    /* Addr: h(41908), d(268552) */
    volatile Uint32 intstatus4;
    /* Addr: h(4190C), d(268556) */
    volatile Uint32 intstatus4a;
    /* Addr: h(41910), d(268560) */
    volatile Uint32 intforce4;
    /* Addr: h(41914), d(268564) */
    volatile Uint32 intforce4a;
    /* Addr: h(41918), d(268568) */
    volatile Uint32 rsvd64[31162];
    /* Addr: h(60000), d(393216) */
    volatile CSL_DFE_BB_BBTXIF_AXC_REGS bbtxif_axc[72];
    /* Addr: h(60480), d(394368) */
    volatile Uint32 rsvd65[224];
    /* Addr: h(60800), d(395264) */
    volatile CSL_DFE_BB_BBRXIF_AXC_REGS bbrxif_axc[48];
    /* Addr: h(60E00), d(396800) */
    volatile Uint32 rsvd66[128];
    /* Addr: h(61000), d(397312) */
    volatile Uint32 bbrxif_slot[256];
    /* Addr: h(61400), d(398336) */
    volatile CSL_DFE_BB_BBRXGAIN_REGS bbrxgain[48];
    /* Addr: h(61580), d(398720) */
    volatile Uint32 rsvd67[160];
    /* Addr: h(61800), d(399360) */
    volatile CSL_DFE_BB_BBTXGAIN_REGS bbtxgain[72];
    /* Addr: h(61A40), d(399936) */
    volatile Uint32 rsvd68[112];
    /* Addr: h(61C00), d(400384) */
    volatile Uint32 aid_dl_xlate[256];
    /* Addr: h(62000), d(401408) */
    volatile Uint32 aid_ul_xlate[48];
    /* Addr: h(620C0), d(401600) */
    volatile Uint32 rsvd69[208];
    /* Addr: h(62400), d(402432) */
    volatile Uint32 bbtxif_slot[256];
    /* Addr: h(62800), d(403456) */
    volatile Uint32 jesd_dl_xlate[256];
    /* Addr: h(62C00), d(404480) */
    volatile Uint32 jesd_ul_xlate[48];
    /* Addr: h(62CC0), d(404672) */
    volatile Uint32 rsvd70[208];
    /* Addr: h(63000), d(405504) */
    volatile Uint32 jesd_txif_slot[256];
    /* Addr: h(63400), d(406528) */
    volatile Uint32 jesd_rxif_slot[256];
    /* Addr: h(63800), d(407552) */
    volatile Uint32 rsvd71[512];
    /* Addr: h(64000), d(409600) */
    volatile CSL_DFE_BB_BBTXIF_REGS bbtxif[128];
    /* Addr: h(64400), d(410624) */
    volatile Uint32 rsvd72[768];
    /* Addr: h(65000), d(413696) */
    volatile CSL_DFE_BB_RXNOTCH_REGS rxnotch[48];
    /* Addr: h(65180), d(414080) */
    volatile Uint32 rsvd73[160];
    /* Addr: h(65400), d(414720) */
    volatile CSL_DFE_BB_RXNOTCHTAP0_REGS rxnotchtap0[48];
    /* Addr: h(65700), d(415488) */
    volatile Uint32 rsvd74[64];
    /* Addr: h(65800), d(415744) */
    volatile CSL_DFE_BB_RXNOTCHTAP1_REGS rxnotchtap1[48];
    /* Addr: h(65B00), d(416512) */
    volatile Uint32 rsvd75[2368];
    /* Addr: h(68000), d(425984) */
    volatile CSL_DFE_BB_BBTXPWRMETER_REGS bbtxpwrmeter[72];
    /* Addr: h(68480), d(427136) */
    volatile Uint32 rsvd76[736];
    /* Addr: h(69000), d(430080) */
    volatile CSL_DFE_BB_BBRXPWRMETER_REGS bbrxpwrmeter[48];
    /* Addr: h(69300), d(430848) */
    volatile Uint32 rsvd77[2880];
    /* Addr: h(6C000), d(442368) */
    volatile CSL_DFE_BB_BEAGC_REGS beagc[8];
    /* Addr: h(6C100), d(442624) */
    volatile Uint32 rsvd78[4032];
    /* Addr: h(70000), d(458752) */
    volatile CSL_DFE_BB_ANTCALCORR_REGS antcalcorr[64];
} CSL_DFE_BB_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* CFG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 21;
    Uint32 bbif_repeater_mode : 1;
    Uint32 bbif_rx_mode_en : 1;
    Uint32 bbif_tx_mode_en : 1;
    Uint32 bbif_size : 8;
#else 
    Uint32 bbif_size : 8;
    Uint32 bbif_tx_mode_en : 1;
    Uint32 bbif_rx_mode_en : 1;
    Uint32 bbif_repeater_mode : 1;
    Uint32 rsvd0 : 21;
#endif 
} CSL_DFE_BB_CFG0_REG;

/* Number of cycles in BBIF frame  (set to zero for bbif_size=256) */
#define CSL_DFE_BB_CFG0_REG_BBIF_SIZE_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG0_REG_BBIF_SIZE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG0_REG_BBIF_SIZE_RESETVAL (0x000000C0u)

/* Master clock enable for bbtxif.  This shall be disabled for the mpu to be able to read back some memories.  */
#define CSL_DFE_BB_CFG0_REG_BBIF_TX_MODE_EN_MASK (0x00000100u)
#define CSL_DFE_BB_CFG0_REG_BBIF_TX_MODE_EN_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG0_REG_BBIF_TX_MODE_EN_RESETVAL (0x00000000u)

/* Master clock enable for bbrxif.   This shall be disabled for the mpu to be able to read back some memories. */
#define CSL_DFE_BB_CFG0_REG_BBIF_RX_MODE_EN_MASK (0x00000200u)
#define CSL_DFE_BB_CFG0_REG_BBIF_RX_MODE_EN_SHIFT (0x00000009u)
#define CSL_DFE_BB_CFG0_REG_BBIF_RX_MODE_EN_RESETVAL (0x00000000u)

/* Places Base Band processor into repeater mode.  BBRXIF interface is muxed onto BBTXIF interface.  External BBTXIF pins have no effect in this mode. */
#define CSL_DFE_BB_CFG0_REG_BBIF_REPEATER_MODE_MASK (0x00000400u)
#define CSL_DFE_BB_CFG0_REG_BBIF_REPEATER_MODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG0_REG_BBIF_REPEATER_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG0_REG_ADDR (0x00040200u)
#define CSL_DFE_BB_CFG0_REG_RESETVAL (0x000000C0u)

/* CFG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 test_cb_axc : 8;
    Uint32 rsvd0 : 2;
    Uint32 test_cb_control : 6;
#else 
    Uint32 test_cb_control : 6;
    Uint32 rsvd0 : 2;
    Uint32 test_cb_axc : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_CFG1_REG;

/* Capture buffer interface mode.   bit 0= enabled/disabled;  bit 1= single AxC / All carriers;  bit 5:2=source  0=tx aid, 1=tx dducif before buf mem, 2=tx dducif, 3=JESD TX(master dl, slave ul), 8=rx aid, 9=rx dducif after buf mem, 10=rx dducif 11=JESD RX(master ul, slave dl).     Note: TX/RX JESD single carrier # is relative to the eng_jesd # and not the carrier# it points to. */
#define CSL_DFE_BB_CFG1_REG_TEST_CB_CONTROL_MASK (0x0000003Fu)
#define CSL_DFE_BB_CFG1_REG_TEST_CB_CONTROL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1_REG_TEST_CB_CONTROL_RESETVAL (0x00000000u)

/* Test_cb_axc[15:12] is used to indicate a single DDUC port to monitor when test_cb_control[5:0] = 0x5, 0x9, 0x25, 0x29.  Test_cb_axc[11:8] indicate the DDUC slot when in single DDUC mode. */
#define CSL_DFE_BB_CFG1_REG_TEST_CB_AXC_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG1_REG_TEST_CB_AXC_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1_REG_TEST_CB_AXC_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1_REG_ADDR (0x00040204u)
#define CSL_DFE_BB_CFG1_REG_RESETVAL (0x00000000u)

/* CFG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 test_loopback : 8;
#else 
    Uint32 test_loopback : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CFG2_REG;

/* loopback control.  Loopback is a test mode to route an output to an input.  It is limited to 4 paths since the buffer memory is shared between tx and rx.   Routes data from the BB DUC interface to the BB DDC interface.  Bit 1 set assigns DUC0 to DDC1.  Bit 2 set assigns DUC1 to DDC2, Bit 3 assigns DUC0 to DDC3., Bit4 assigns DUC3 to DDC4, Bit5 assigns DUC2 to DDC5, Bit6 assigns DUC1 to DDC6, Bit7 assigns DUC0 to DDC7 */
#define CSL_DFE_BB_CFG2_REG_TEST_LOOPBACK_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG2_REG_TEST_LOOPBACK_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG2_REG_TEST_LOOPBACK_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG2_REG_ADDR (0x00040208u)
#define CSL_DFE_BB_CFG2_REG_RESETVAL (0x00000000u)

/* CFG3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbif_ct1_interval : 8;
    Uint32 bbif_ct0_interval : 8;
#else 
    Uint32 bbif_ct0_interval : 8;
    Uint32 bbif_ct1_interval : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG3_REG;

/* Carrier type 0 sample interval.  Sub frame interval within the BBIF frame interval that this carrier shall repeat by.  Value must be an integer division of bbif_size.  This is the reservation slot interval so variable (gapped) carriers hold the reservation interval not the actual AxC data interval.  Default is LTE1.4 */
#define CSL_DFE_BB_CFG3_REG_BBIF_CT0_INTERVAL_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG3_REG_BBIF_CT0_INTERVAL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG3_REG_BBIF_CT0_INTERVAL_RESETVAL (0x000000C0u)

/* see bbif_ct0_interval description.   */
#define CSL_DFE_BB_CFG3_REG_BBIF_CT1_INTERVAL_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG3_REG_BBIF_CT1_INTERVAL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG3_REG_BBIF_CT1_INTERVAL_RESETVAL (0x00000060u)

#define CSL_DFE_BB_CFG3_REG_ADDR (0x0004020Cu)
#define CSL_DFE_BB_CFG3_REG_RESETVAL (0x000060C0u)

/* CFG4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbif_ct3_interval : 8;
    Uint32 bbif_ct2_interval : 8;
#else 
    Uint32 bbif_ct2_interval : 8;
    Uint32 bbif_ct3_interval : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG4_REG;

/* see bbif_ct0_interval description.   */
#define CSL_DFE_BB_CFG4_REG_BBIF_CT2_INTERVAL_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG4_REG_BBIF_CT2_INTERVAL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG4_REG_BBIF_CT2_INTERVAL_RESETVAL (0x00000030u)

/* see bbif_ct0_interval description.  */
#define CSL_DFE_BB_CFG4_REG_BBIF_CT3_INTERVAL_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG4_REG_BBIF_CT3_INTERVAL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG4_REG_BBIF_CT3_INTERVAL_RESETVAL (0x00000018u)

#define CSL_DFE_BB_CFG4_REG_ADDR (0x00040210u)
#define CSL_DFE_BB_CFG4_REG_RESETVAL (0x00001830u)

/* CFG5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbif_ct5_interval : 8;
    Uint32 bbif_ct4_interval : 8;
#else 
    Uint32 bbif_ct4_interval : 8;
    Uint32 bbif_ct5_interval : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG5_REG;

/* see bbif_ct0_interval description.   */
#define CSL_DFE_BB_CFG5_REG_BBIF_CT4_INTERVAL_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG5_REG_BBIF_CT4_INTERVAL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG5_REG_BBIF_CT4_INTERVAL_RESETVAL (0x0000000Cu)

/* see bbif_ct0_interval description.     */
#define CSL_DFE_BB_CFG5_REG_BBIF_CT5_INTERVAL_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG5_REG_BBIF_CT5_INTERVAL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG5_REG_BBIF_CT5_INTERVAL_RESETVAL (0x00000006u)

#define CSL_DFE_BB_CFG5_REG_ADDR (0x00040214u)
#define CSL_DFE_BB_CFG5_REG_RESETVAL (0x0000060Cu)

/* CFG6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbif_ct7_interval : 8;
    Uint32 bbif_ct6_interval : 8;
#else 
    Uint32 bbif_ct6_interval : 8;
    Uint32 bbif_ct7_interval : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG6_REG;

/* see bbif_ct0_interval description.    */
#define CSL_DFE_BB_CFG6_REG_BBIF_CT6_INTERVAL_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG6_REG_BBIF_CT6_INTERVAL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG6_REG_BBIF_CT6_INTERVAL_RESETVAL (0x00000002u)

/* see bbif_ct0_interval description.   */
#define CSL_DFE_BB_CFG6_REG_BBIF_CT7_INTERVAL_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG6_REG_BBIF_CT7_INTERVAL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG6_REG_BBIF_CT7_INTERVAL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG6_REG_ADDR (0x00040218u)
#define CSL_DFE_BB_CFG6_REG_RESETVAL (0x00000002u)

/* CFG7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbif_ct9_interval : 8;
    Uint32 bbif_ct8_interval : 8;
#else 
    Uint32 bbif_ct8_interval : 8;
    Uint32 bbif_ct9_interval : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG7_REG;

/* see bbif_ct0_interval description.    */
#define CSL_DFE_BB_CFG7_REG_BBIF_CT8_INTERVAL_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG7_REG_BBIF_CT8_INTERVAL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG7_REG_BBIF_CT8_INTERVAL_RESETVAL (0x00000000u)

/* see bbif_ct0_interval description.    */
#define CSL_DFE_BB_CFG7_REG_BBIF_CT9_INTERVAL_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG7_REG_BBIF_CT9_INTERVAL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG7_REG_BBIF_CT9_INTERVAL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG7_REG_ADDR (0x0004021Cu)
#define CSL_DFE_BB_CFG7_REG_RESETVAL (0x00000000u)

/* CFG8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbif_ct11_interval : 8;
    Uint32 bbif_ct10_interval : 8;
#else 
    Uint32 bbif_ct10_interval : 8;
    Uint32 bbif_ct11_interval : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG8_REG;

/* see bbif_ct0_interval description.    */
#define CSL_DFE_BB_CFG8_REG_BBIF_CT10_INTERVAL_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG8_REG_BBIF_CT10_INTERVAL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG8_REG_BBIF_CT10_INTERVAL_RESETVAL (0x00000000u)

/* see bbif_ct0_interval description.     */
#define CSL_DFE_BB_CFG8_REG_BBIF_CT11_INTERVAL_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG8_REG_BBIF_CT11_INTERVAL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG8_REG_BBIF_CT11_INTERVAL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG8_REG_ADDR (0x00040220u)
#define CSL_DFE_BB_CFG8_REG_RESETVAL (0x00000000u)

/* CFG9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbif_ct13_interval : 8;
    Uint32 bbif_ct12_interval : 8;
#else 
    Uint32 bbif_ct12_interval : 8;
    Uint32 bbif_ct13_interval : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG9_REG;

/* see bbif_ct0_interval description.   */
#define CSL_DFE_BB_CFG9_REG_BBIF_CT12_INTERVAL_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG9_REG_BBIF_CT12_INTERVAL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG9_REG_BBIF_CT12_INTERVAL_RESETVAL (0x00000000u)

/* see bbif_ct0_interval description.   */
#define CSL_DFE_BB_CFG9_REG_BBIF_CT13_INTERVAL_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG9_REG_BBIF_CT13_INTERVAL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG9_REG_BBIF_CT13_INTERVAL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG9_REG_ADDR (0x00040224u)
#define CSL_DFE_BB_CFG9_REG_RESETVAL (0x00000000u)

/* CFG10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbif_ct15_interval : 8;
    Uint32 bbif_ct14_interval : 8;
#else 
    Uint32 bbif_ct14_interval : 8;
    Uint32 bbif_ct15_interval : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG10_REG;

/* see bbif_ct0_interval description.   */
#define CSL_DFE_BB_CFG10_REG_BBIF_CT14_INTERVAL_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG10_REG_BBIF_CT14_INTERVAL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG10_REG_BBIF_CT14_INTERVAL_RESETVAL (0x00000000u)

/*  Special 3 of 4 frame sync generation for LTE15. */
#define CSL_DFE_BB_CFG10_REG_BBIF_CT15_INTERVAL_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG10_REG_BBIF_CT15_INTERVAL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG10_REG_BBIF_CT15_INTERVAL_RESETVAL (0x0000000Cu)

#define CSL_DFE_BB_CFG10_REG_ADDR (0x00040228u)
#define CSL_DFE_BB_CFG10_REG_RESETVAL (0x00000C00u)

/* CFG11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 17;
    Uint32 ct_variable_mode : 15;
#else 
    Uint32 ct_variable_mode : 15;
    Uint32 rsvd0 : 17;
#endif 
} CSL_DFE_BB_CFG11_REG;

/* One bit per carrier type to indicate if TX carrier is a variable type carrier.  One where there will be empty slots (such as GSM).   0=fixed, 1= variable  */
#define CSL_DFE_BB_CFG11_REG_CT_VARIABLE_MODE_MASK (0x00007FFFu)
#define CSL_DFE_BB_CFG11_REG_CT_VARIABLE_MODE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG11_REG_CT_VARIABLE_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG11_REG_ADDR (0x0004022Cu)
#define CSL_DFE_BB_CFG11_REG_RESETVAL (0x00000000u)

/* CFG12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 21;
    Uint32 dsp_in_the_loop_config : 11;
#else 
    Uint32 dsp_in_the_loop_config : 11;
    Uint32 rsvd0 : 21;
#endif 
} CSL_DFE_BB_CFG12_REG;

/* DSP in the loop configuration register.  1:0 TX OUT CFG where 0=off, 1=aid monitor, 2=output of txgain block, 3=end of tx chain;  3:2 TX IN CFG where 0=off, 1=aid monitor, 2=output of txgain block, 3=end of tx chain;  6:4 RX OUT CFG where 0=off, 1=dducif side, 2= out of notch filter, 3=beagc output, 4=aid interface; 10:8 RX IN CFG where 0=off, 1=dducif side, 2= out of notch filter, 3=beagc output, 4=aid interface; */
#define CSL_DFE_BB_CFG12_REG_DSP_IN_THE_LOOP_CONFIG_MASK (0x000007FFu)
#define CSL_DFE_BB_CFG12_REG_DSP_IN_THE_LOOP_CONFIG_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG12_REG_DSP_IN_THE_LOOP_CONFIG_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG12_REG_ADDR (0x00040230u)
#define CSL_DFE_BB_CFG12_REG_RESETVAL (0x00000000u)

/* CFG13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 25;
    Uint32 clear_data : 1;
    Uint32 inits_state : 1;
    Uint32 inits_clk_gate : 1;
    Uint32 inits_ssel : 4;
#else 
    Uint32 inits_ssel : 4;
    Uint32 inits_clk_gate : 1;
    Uint32 inits_state : 1;
    Uint32 clear_data : 1;
    Uint32 rsvd0 : 25;
#endif 
} CSL_DFE_BB_CFG13_REG;

/* Sync select for init_clk_gate, init_state and clear_data */
#define CSL_DFE_BB_CFG13_REG_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG13_REG_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG13_REG_INITS_SSEL_RESETVAL (0x00000000u)

/* Value of init_clk_gate. Updates when gsync[bb.inits_ssel] is true */
#define CSL_DFE_BB_CFG13_REG_INITS_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_BB_CFG13_REG_INITS_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG13_REG_INITS_CLK_GATE_RESETVAL (0x00000001u)

/* Value of init_state. Updates when gsync[bb.inits_ssel] is true */
#define CSL_DFE_BB_CFG13_REG_INITS_STATE_MASK (0x00000020u)
#define CSL_DFE_BB_CFG13_REG_INITS_STATE_SHIFT (0x00000005u)
#define CSL_DFE_BB_CFG13_REG_INITS_STATE_RESETVAL (0x00000001u)

/* Value of clear. Updates when gsync[bb.inits_ssel] is true */
#define CSL_DFE_BB_CFG13_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_BB_CFG13_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG13_REG_CLEAR_DATA_RESETVAL (0x00000001u)

#define CSL_DFE_BB_CFG13_REG_ADDR (0x00040234u)
#define CSL_DFE_BB_CFG13_REG_RESETVAL (0x00000070u)

/* CFG16 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 buf_rxtx_config : 8;
#else 
    Uint32 buf_rxtx_config : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CFG16_REG;

/* Config to set Buffers to RX or TX mode.  0=TX, 1=RX Bit 0 corresponds to buffer0 …. Bit 1 corresponds to buffer1 */
#define CSL_DFE_BB_CFG16_REG_BUF_RXTX_CONFIG_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG16_REG_BUF_RXTX_CONFIG_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG16_REG_BUF_RXTX_CONFIG_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG16_REG_ADDR (0x00040240u)
#define CSL_DFE_BB_CFG16_REG_RESETVAL (0x00000000u)

/* CFG17 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 buf3size : 4;
    Uint32 buf2size : 4;
    Uint32 buf1size : 4;
    Uint32 buf0size : 4;
#else 
    Uint32 buf0size : 4;
    Uint32 buf1size : 4;
    Uint32 buf2size : 4;
    Uint32 buf3size : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG17_REG;

/* TX/RX Buffer 0 word size.  Number of samples to be held in buffer  (range 0-12)   Used by DDUC interface for number to load.  Clock of buffer is disabled when bufsize=0 */
#define CSL_DFE_BB_CFG17_REG_BUF0SIZE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG17_REG_BUF0SIZE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG17_REG_BUF0SIZE_RESETVAL (0x00000000u)

/* TX/RX Buffer 1 word size.  Number of samples to be held in buffer  (range 0-12)  */
#define CSL_DFE_BB_CFG17_REG_BUF1SIZE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG17_REG_BUF1SIZE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG17_REG_BUF1SIZE_RESETVAL (0x00000000u)

/* TX/RX Buffer 1 word size.  Number of samples to be held in buffer  (range 0-12)  */
#define CSL_DFE_BB_CFG17_REG_BUF2SIZE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG17_REG_BUF2SIZE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG17_REG_BUF2SIZE_RESETVAL (0x00000000u)

/* TX/RX Buffer 2 word size.  Number of samples to be held in buffer  (range 0-12)  */
#define CSL_DFE_BB_CFG17_REG_BUF3SIZE_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG17_REG_BUF3SIZE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG17_REG_BUF3SIZE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG17_REG_ADDR (0x00040244u)
#define CSL_DFE_BB_CFG17_REG_RESETVAL (0x00000000u)

/* CFG18 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 buf7size : 4;
    Uint32 buf6size : 4;
    Uint32 buf5size : 4;
    Uint32 buf4size : 4;
#else 
    Uint32 buf4size : 4;
    Uint32 buf5size : 4;
    Uint32 buf6size : 4;
    Uint32 buf7size : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG18_REG;

/* TX/RX Buffer 3 word size.  Number of samples to be held in buffer  (range 0-12)  */
#define CSL_DFE_BB_CFG18_REG_BUF4SIZE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG18_REG_BUF4SIZE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG18_REG_BUF4SIZE_RESETVAL (0x00000000u)

/* TX/RX Buffer 4 word size.  Number of samples to be held in buffer  (range 0-12)  */
#define CSL_DFE_BB_CFG18_REG_BUF5SIZE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG18_REG_BUF5SIZE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG18_REG_BUF5SIZE_RESETVAL (0x00000000u)

/* TX/RX Buffer 5 word size.  Number of samples to be held in buffer  (range 0-12)  */
#define CSL_DFE_BB_CFG18_REG_BUF6SIZE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG18_REG_BUF6SIZE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG18_REG_BUF6SIZE_RESETVAL (0x00000000u)

/* TX/RX Buffer 6 word size.  Number of samples to be held in buffer  (range 0-12)  */
#define CSL_DFE_BB_CFG18_REG_BUF7SIZE_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG18_REG_BUF7SIZE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG18_REG_BUF7SIZE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG18_REG_ADDR (0x00040248u)
#define CSL_DFE_BB_CFG18_REG_RESETVAL (0x00000000u)

/* CFG20 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 buf3_sync_ct : 4;
    Uint32 buf2_sync_ct : 4;
    Uint32 buf1_sync_ct : 4;
    Uint32 buf0_sync_ct : 4;
#else 
    Uint32 buf0_sync_ct : 4;
    Uint32 buf1_sync_ct : 4;
    Uint32 buf2_sync_ct : 4;
    Uint32 buf3_sync_ct : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG20_REG;

/* Used to determine the carrier interval to generate frame sync to the dduc buffer .  Set to the highest data rate carrier associated with the dduc. */
#define CSL_DFE_BB_CFG20_REG_BUF0_SYNC_CT_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG20_REG_BUF0_SYNC_CT_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG20_REG_BUF0_SYNC_CT_RESETVAL (0x00000000u)

/* for dduc1.  see above */
#define CSL_DFE_BB_CFG20_REG_BUF1_SYNC_CT_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG20_REG_BUF1_SYNC_CT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG20_REG_BUF1_SYNC_CT_RESETVAL (0x00000000u)

/* for dduc2.  see above */
#define CSL_DFE_BB_CFG20_REG_BUF2_SYNC_CT_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG20_REG_BUF2_SYNC_CT_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG20_REG_BUF2_SYNC_CT_RESETVAL (0x00000000u)

/* for dduc3.  see above */
#define CSL_DFE_BB_CFG20_REG_BUF3_SYNC_CT_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG20_REG_BUF3_SYNC_CT_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG20_REG_BUF3_SYNC_CT_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG20_REG_ADDR (0x00040250u)
#define CSL_DFE_BB_CFG20_REG_RESETVAL (0x00000000u)

/* CFG21 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 buf7_sync_ct : 4;
    Uint32 buf6_sync_ct : 4;
    Uint32 buf5_sync_ct : 4;
    Uint32 buf4_sync_ct : 4;
#else 
    Uint32 buf4_sync_ct : 4;
    Uint32 buf5_sync_ct : 4;
    Uint32 buf6_sync_ct : 4;
    Uint32 buf7_sync_ct : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG21_REG;

/* for dduc4.  see above */
#define CSL_DFE_BB_CFG21_REG_BUF4_SYNC_CT_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG21_REG_BUF4_SYNC_CT_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG21_REG_BUF4_SYNC_CT_RESETVAL (0x00000000u)

/* for dduc5.  see above */
#define CSL_DFE_BB_CFG21_REG_BUF5_SYNC_CT_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG21_REG_BUF5_SYNC_CT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG21_REG_BUF5_SYNC_CT_RESETVAL (0x00000000u)

/* for dduc6.  see above */
#define CSL_DFE_BB_CFG21_REG_BUF6_SYNC_CT_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG21_REG_BUF6_SYNC_CT_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG21_REG_BUF6_SYNC_CT_RESETVAL (0x00000000u)

/* for dduc7.  see above */
#define CSL_DFE_BB_CFG21_REG_BUF7_SYNC_CT_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG21_REG_BUF7_SYNC_CT_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG21_REG_BUF7_SYNC_CT_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG21_REG_ADDR (0x00040254u)
#define CSL_DFE_BB_CFG21_REG_RESETVAL (0x00000000u)

/* CFG23 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 buf_autozero_disable : 8;
#else 
    Uint32 buf_autozero_disable : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CFG23_REG;

/* Config to disable autozero insertion of write ports.  0=autozero enabled, 1=autozero disabled Bit 0 corresponds to buffer0 …. Bit 1 corresponds to buffer1.   */
#define CSL_DFE_BB_CFG23_REG_BUF_AUTOZERO_DISABLE_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG23_REG_BUF_AUTOZERO_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG23_REG_BUF_AUTOZERO_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG23_REG_ADDR (0x0004025Cu)
#define CSL_DFE_BB_CFG23_REG_RESETVAL (0x00000000u)

/* CFG25 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 ddc1_dchsupa : 6;
    Uint32 rsvd0 : 2;
    Uint32 ddc0_dchsupa : 6;
#else 
    Uint32 ddc0_dchsupa : 6;
    Uint32 rsvd0 : 2;
    Uint32 ddc1_dchsupa : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_BB_CFG25_REG;

/* Enable of Dual Cell HSUPA adders on the even and adjacent carrier (+1).  Two carriers are added together and put into a single location.  Note bufsize reflects the size after DC-HSPCA combination.  Bit 0 for carriers 0 and 1, Bit 1 for carriers 2 and 3, …. Bit 5 for carriers 10 and 11 */
#define CSL_DFE_BB_CFG25_REG_DDC0_DCHSUPA_MASK (0x0000003Fu)
#define CSL_DFE_BB_CFG25_REG_DDC0_DCHSUPA_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG25_REG_DDC0_DCHSUPA_RESETVAL (0x00000000u)

/* see ddc0_dchsupa description */
#define CSL_DFE_BB_CFG25_REG_DDC1_DCHSUPA_MASK (0x00003F00u)
#define CSL_DFE_BB_CFG25_REG_DDC1_DCHSUPA_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG25_REG_DDC1_DCHSUPA_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG25_REG_ADDR (0x00040264u)
#define CSL_DFE_BB_CFG25_REG_RESETVAL (0x00000000u)

/* CFG26 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 ddc3_dchsupa : 6;
    Uint32 rsvd0 : 2;
    Uint32 ddc2_dchsupa : 6;
#else 
    Uint32 ddc2_dchsupa : 6;
    Uint32 rsvd0 : 2;
    Uint32 ddc3_dchsupa : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_BB_CFG26_REG;

/* see ddc0_dchsupa description */
#define CSL_DFE_BB_CFG26_REG_DDC2_DCHSUPA_MASK (0x0000003Fu)
#define CSL_DFE_BB_CFG26_REG_DDC2_DCHSUPA_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG26_REG_DDC2_DCHSUPA_RESETVAL (0x00000000u)

/* see ddc0_dchsupa description */
#define CSL_DFE_BB_CFG26_REG_DDC3_DCHSUPA_MASK (0x00003F00u)
#define CSL_DFE_BB_CFG26_REG_DDC3_DCHSUPA_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG26_REG_DDC3_DCHSUPA_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG26_REG_ADDR (0x00040268u)
#define CSL_DFE_BB_CFG26_REG_RESETVAL (0x00000000u)

/* CFG27 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 ddc5_dchsupa : 6;
    Uint32 rsvd0 : 2;
    Uint32 ddc4_dchsupa : 6;
#else 
    Uint32 ddc4_dchsupa : 6;
    Uint32 rsvd0 : 2;
    Uint32 ddc5_dchsupa : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_BB_CFG27_REG;

/* see ddc0_dchsupa description */
#define CSL_DFE_BB_CFG27_REG_DDC4_DCHSUPA_MASK (0x0000003Fu)
#define CSL_DFE_BB_CFG27_REG_DDC4_DCHSUPA_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG27_REG_DDC4_DCHSUPA_RESETVAL (0x00000000u)

/* see ddc0_dchsupa description */
#define CSL_DFE_BB_CFG27_REG_DDC5_DCHSUPA_MASK (0x00003F00u)
#define CSL_DFE_BB_CFG27_REG_DDC5_DCHSUPA_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG27_REG_DDC5_DCHSUPA_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG27_REG_ADDR (0x0004026Cu)
#define CSL_DFE_BB_CFG27_REG_RESETVAL (0x00000000u)

/* CFG28 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 ddc7_dchsupa : 6;
    Uint32 rsvd0 : 2;
    Uint32 ddc6_dchsupa : 6;
#else 
    Uint32 ddc6_dchsupa : 6;
    Uint32 rsvd0 : 2;
    Uint32 ddc7_dchsupa : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_BB_CFG28_REG;

/* see ddc0_dchsupa description */
#define CSL_DFE_BB_CFG28_REG_DDC6_DCHSUPA_MASK (0x0000003Fu)
#define CSL_DFE_BB_CFG28_REG_DDC6_DCHSUPA_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG28_REG_DDC6_DCHSUPA_RESETVAL (0x00000000u)

/* see ddc0_dchsupa description */
#define CSL_DFE_BB_CFG28_REG_DDC7_DCHSUPA_MASK (0x00003F00u)
#define CSL_DFE_BB_CFG28_REG_DDC7_DCHSUPA_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG28_REG_DDC7_DCHSUPA_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG28_REG_ADDR (0x00040270u)
#define CSL_DFE_BB_CFG28_REG_RESETVAL (0x00000000u)

/* CFG31 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 duc1_framesize : 8;
    Uint32 duc0_framesize : 8;
#else 
    Uint32 duc0_framesize : 8;
    Uint32 duc1_framesize : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG31_REG;

/* DDUC 0 number of gated dduc_clks per frame. */
#define CSL_DFE_BB_CFG31_REG_DUC0_FRAMESIZE_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG31_REG_DUC0_FRAMESIZE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG31_REG_DUC0_FRAMESIZE_RESETVAL (0x00000000u)

/* DDUC 1 number of gated dduc_clks per frame.  */
#define CSL_DFE_BB_CFG31_REG_DUC1_FRAMESIZE_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG31_REG_DUC1_FRAMESIZE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG31_REG_DUC1_FRAMESIZE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG31_REG_ADDR (0x0004027Cu)
#define CSL_DFE_BB_CFG31_REG_RESETVAL (0x00000000u)

/* CFG32 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 duc3_framesize : 8;
    Uint32 duc2_framesize : 8;
#else 
    Uint32 duc2_framesize : 8;
    Uint32 duc3_framesize : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG32_REG;

/* DDUC 2 number of gated dduc_clks per frame. */
#define CSL_DFE_BB_CFG32_REG_DUC2_FRAMESIZE_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG32_REG_DUC2_FRAMESIZE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG32_REG_DUC2_FRAMESIZE_RESETVAL (0x00000000u)

/* DDUC 3 number of gated dduc_clks per frame.  */
#define CSL_DFE_BB_CFG32_REG_DUC3_FRAMESIZE_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG32_REG_DUC3_FRAMESIZE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG32_REG_DUC3_FRAMESIZE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG32_REG_ADDR (0x00040280u)
#define CSL_DFE_BB_CFG32_REG_RESETVAL (0x00000000u)

/* CFG33 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 duc5_framesize : 8;
    Uint32 duc4_framesize : 8;
#else 
    Uint32 duc4_framesize : 8;
    Uint32 duc5_framesize : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG33_REG;

/* DDUC 4 number of gated dduc_clks per frame. */
#define CSL_DFE_BB_CFG33_REG_DUC4_FRAMESIZE_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG33_REG_DUC4_FRAMESIZE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG33_REG_DUC4_FRAMESIZE_RESETVAL (0x00000000u)

/* DDUC 5 number of gated dduc_clks per frame.  */
#define CSL_DFE_BB_CFG33_REG_DUC5_FRAMESIZE_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG33_REG_DUC5_FRAMESIZE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG33_REG_DUC5_FRAMESIZE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG33_REG_ADDR (0x00040284u)
#define CSL_DFE_BB_CFG33_REG_RESETVAL (0x00000000u)

/* CFG34 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 duc7_framesize : 8;
    Uint32 duc6_framesize : 8;
#else 
    Uint32 duc6_framesize : 8;
    Uint32 duc7_framesize : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG34_REG;

/* DDUC 6 number of gated dduc_clks per frame. */
#define CSL_DFE_BB_CFG34_REG_DUC6_FRAMESIZE_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG34_REG_DUC6_FRAMESIZE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG34_REG_DUC6_FRAMESIZE_RESETVAL (0x00000000u)

/* DDUC 7 number of gated dduc_clks per frame.  */
#define CSL_DFE_BB_CFG34_REG_DUC7_FRAMESIZE_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG34_REG_DUC7_FRAMESIZE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG34_REG_DUC7_FRAMESIZE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG34_REG_ADDR (0x00040288u)
#define CSL_DFE_BB_CFG34_REG_RESETVAL (0x00000000u)

/* CFG36 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 31;
    Uint32 beagc_loop_config_sat : 1;
#else 
    Uint32 beagc_loop_config_sat : 1;
    Uint32 rsvd0 : 31;
#endif 
} CSL_DFE_BB_CFG36_REG;

/* When set beagc gain loop emphasizes saturation by incrementing sat counter by 1 when I or Q is sat.  Otherwise both I and Q must be set for the counter to increment.  When bit 1 is cleared the zero and sat counters run continuously (after init reset), otherwise counters only run when unfrozen. */
#define CSL_DFE_BB_CFG36_REG_BEAGC_LOOP_CONFIG_SAT_MASK (0x00000001u)
#define CSL_DFE_BB_CFG36_REG_BEAGC_LOOP_CONFIG_SAT_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG36_REG_BEAGC_LOOP_CONFIG_SAT_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG36_REG_ADDR (0x00040290u)
#define CSL_DFE_BB_CFG36_REG_RESETVAL (0x00000000u)

/* CFG37 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_intervalsource3 : 4;
    Uint32 beagc_intervalsource2 : 4;
    Uint32 beagc_intervalsource1 : 4;
    Uint32 beagc_intervalsource0 : 4;
#else 
    Uint32 beagc_intervalsource0 : 4;
    Uint32 beagc_intervalsource1 : 4;
    Uint32 beagc_intervalsource2 : 4;
    Uint32 beagc_intervalsource3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG37_REG;

/* Select which buffer sync is the source of the interval counter for configuration 0 in closed loop mode.   */
#define CSL_DFE_BB_CFG37_REG_BEAGC_INTERVALSOURCE0_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG37_REG_BEAGC_INTERVALSOURCE0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG37_REG_BEAGC_INTERVALSOURCE0_RESETVAL (0x00000000u)

/* Select which buffer sync is the source of the interval counter for configuration 1 in closed loop mode.   */
#define CSL_DFE_BB_CFG37_REG_BEAGC_INTERVALSOURCE1_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG37_REG_BEAGC_INTERVALSOURCE1_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG37_REG_BEAGC_INTERVALSOURCE1_RESETVAL (0x00000000u)

/* Select which buffer sync is the source of the interval counter for configuration 2 in closed loop mode.   */
#define CSL_DFE_BB_CFG37_REG_BEAGC_INTERVALSOURCE2_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG37_REG_BEAGC_INTERVALSOURCE2_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG37_REG_BEAGC_INTERVALSOURCE2_RESETVAL (0x00000000u)

/* Select which buffer sync is the source of the interval counter for configuration 3 in closed loop mode.   */
#define CSL_DFE_BB_CFG37_REG_BEAGC_INTERVALSOURCE3_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG37_REG_BEAGC_INTERVALSOURCE3_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG37_REG_BEAGC_INTERVALSOURCE3_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG37_REG_ADDR (0x00040294u)
#define CSL_DFE_BB_CFG37_REG_RESETVAL (0x00000000u)

/* CFG38 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_intervalsource7 : 4;
    Uint32 beagc_intervalsource6 : 4;
    Uint32 beagc_intervalsource5 : 4;
    Uint32 beagc_intervalsource4 : 4;
#else 
    Uint32 beagc_intervalsource4 : 4;
    Uint32 beagc_intervalsource5 : 4;
    Uint32 beagc_intervalsource6 : 4;
    Uint32 beagc_intervalsource7 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG38_REG;

/* Select which buffer sync is the source of the interval counter for configuration 4 in closed loop mode.   */
#define CSL_DFE_BB_CFG38_REG_BEAGC_INTERVALSOURCE4_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG38_REG_BEAGC_INTERVALSOURCE4_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG38_REG_BEAGC_INTERVALSOURCE4_RESETVAL (0x00000000u)

/* Select which buffer sync is the source of the interval counter for configuration 5 in closed loop mode.   */
#define CSL_DFE_BB_CFG38_REG_BEAGC_INTERVALSOURCE5_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG38_REG_BEAGC_INTERVALSOURCE5_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG38_REG_BEAGC_INTERVALSOURCE5_RESETVAL (0x00000000u)

/* Select which buffer sync is the source of the interval counter for configuration 6 in closed loop mode.   */
#define CSL_DFE_BB_CFG38_REG_BEAGC_INTERVALSOURCE6_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG38_REG_BEAGC_INTERVALSOURCE6_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG38_REG_BEAGC_INTERVALSOURCE6_RESETVAL (0x00000000u)

/* Select which buffer sync is the source of the interval counter for configuration 7 in closed loop mode.   */
#define CSL_DFE_BB_CFG38_REG_BEAGC_INTERVALSOURCE7_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG38_REG_BEAGC_INTERVALSOURCE7_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG38_REG_BEAGC_INTERVALSOURCE7_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG38_REG_ADDR (0x00040298u)
#define CSL_DFE_BB_CFG38_REG_RESETVAL (0x00000000u)

/* CFG39 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t3interval0_15_0 : 16;
#else 
    Uint32 beagc_t3interval0_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG39_REG;

/* AGC master interval for  config 0.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval.  See address 0x403f0 for upper 8 bits of 24 bit field. */
#define CSL_DFE_BB_CFG39_REG_BEAGC_T3INTERVAL0_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG39_REG_BEAGC_T3INTERVAL0_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG39_REG_BEAGC_T3INTERVAL0_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG39_REG_ADDR (0x0004029Cu)
#define CSL_DFE_BB_CFG39_REG_RESETVAL (0x00000000u)

/* CFG40 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t3interval1_15_0 : 16;
#else 
    Uint32 beagc_t3interval1_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG40_REG;

/* AGC master interval for  config 1.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval. See address 0x403f0 for upper 8 bits of 24 bit field. */
#define CSL_DFE_BB_CFG40_REG_BEAGC_T3INTERVAL1_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG40_REG_BEAGC_T3INTERVAL1_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG40_REG_BEAGC_T3INTERVAL1_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG40_REG_ADDR (0x000402A0u)
#define CSL_DFE_BB_CFG40_REG_RESETVAL (0x00000000u)

/* CFG41 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t3interval2_15_0 : 16;
#else 
    Uint32 beagc_t3interval2_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG41_REG;

/* AGC master interval for  config 2.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval.  See address 0x403f4 for upper 8 bits of 24 bit field. */
#define CSL_DFE_BB_CFG41_REG_BEAGC_T3INTERVAL2_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG41_REG_BEAGC_T3INTERVAL2_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG41_REG_BEAGC_T3INTERVAL2_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG41_REG_ADDR (0x000402A4u)
#define CSL_DFE_BB_CFG41_REG_RESETVAL (0x00000000u)

/* CFG42 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t3interval3_15_0 : 16;
#else 
    Uint32 beagc_t3interval3_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG42_REG;

/* AGC master interval for  config 3.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval.  See address 0x403f4 for upper 8 bits of 24 bit field. */
#define CSL_DFE_BB_CFG42_REG_BEAGC_T3INTERVAL3_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG42_REG_BEAGC_T3INTERVAL3_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG42_REG_BEAGC_T3INTERVAL3_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG42_REG_ADDR (0x000402A8u)
#define CSL_DFE_BB_CFG42_REG_RESETVAL (0x00000000u)

/* CFG43 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t3interval4_15_0 : 16;
#else 
    Uint32 beagc_t3interval4_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG43_REG;

/* AGC master interval for  config 4.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval.  See address 0x403f8 for upper 8 bits of 24 bit field. */
#define CSL_DFE_BB_CFG43_REG_BEAGC_T3INTERVAL4_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG43_REG_BEAGC_T3INTERVAL4_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG43_REG_BEAGC_T3INTERVAL4_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG43_REG_ADDR (0x000402ACu)
#define CSL_DFE_BB_CFG43_REG_RESETVAL (0x00000000u)

/* CFG44 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t3interval5_15_0 : 16;
#else 
    Uint32 beagc_t3interval5_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG44_REG;

/* AGC master interval for  config 5.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval.  See address 0x403f8 for upper 8 bits of 24 bit field. */
#define CSL_DFE_BB_CFG44_REG_BEAGC_T3INTERVAL5_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG44_REG_BEAGC_T3INTERVAL5_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG44_REG_BEAGC_T3INTERVAL5_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG44_REG_ADDR (0x000402B0u)
#define CSL_DFE_BB_CFG44_REG_RESETVAL (0x00000000u)

/* CFG45 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t3interval6_15_0 : 16;
#else 
    Uint32 beagc_t3interval6_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG45_REG;

/* AGC master interval for  config 6.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval.  See address 0x403fc for upper 8 bits of 24 bit field. */
#define CSL_DFE_BB_CFG45_REG_BEAGC_T3INTERVAL6_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG45_REG_BEAGC_T3INTERVAL6_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG45_REG_BEAGC_T3INTERVAL6_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG45_REG_ADDR (0x000402B4u)
#define CSL_DFE_BB_CFG45_REG_RESETVAL (0x00000000u)

/* CFG46 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t3interval7_15_0 : 16;
#else 
    Uint32 beagc_t3interval7_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG46_REG;

/* AGC master interval for  config 7.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval.  See address 0x403fc for upper 8 bits of 24 bit field. */
#define CSL_DFE_BB_CFG46_REG_BEAGC_T3INTERVAL7_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG46_REG_BEAGC_T3INTERVAL7_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG46_REG_BEAGC_T3INTERVAL7_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG46_REG_ADDR (0x000402B8u)
#define CSL_DFE_BB_CFG46_REG_RESETVAL (0x00000000u)

/* CFG47 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 beagc_tdd_config : 1;
    Uint32 beagc_tdd_en : 8;
#else 
    Uint32 beagc_tdd_en : 8;
    Uint32 beagc_tdd_config : 1;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_BB_CFG47_REG;

/* TDD timer mode enable for beAGC.  One bit per beAGC config.  Bit0->beAGC0...Bit7->beAGC7 */
#define CSL_DFE_BB_CFG47_REG_BEAGC_TDD_EN_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG47_REG_BEAGC_TDD_EN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG47_REG_BEAGC_TDD_EN_RESETVAL (0x00000000u)

/* TDD timer configuration for beAGC.  0:tdd halt on DL, 1: tdd reset on DL */
#define CSL_DFE_BB_CFG47_REG_BEAGC_TDD_CONFIG_MASK (0x00000100u)
#define CSL_DFE_BB_CFG47_REG_BEAGC_TDD_CONFIG_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG47_REG_BEAGC_TDD_CONFIG_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG47_REG_ADDR (0x000402BCu)
#define CSL_DFE_BB_CFG47_REG_RESETVAL (0x00000000u)

/* CFG48 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_txpm3 : 4;
    Uint32 ssel_txpm2 : 4;
    Uint32 ssel_txpm1 : 4;
    Uint32 ssel_txpm0 : 4;
#else 
    Uint32 ssel_txpm0 : 4;
    Uint32 ssel_txpm1 : 4;
    Uint32 ssel_txpm2 : 4;
    Uint32 ssel_txpm3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG48_REG;

/* TX power meter 0 sync */
#define CSL_DFE_BB_CFG48_REG_SSEL_TXPM0_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG48_REG_SSEL_TXPM0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG48_REG_SSEL_TXPM0_RESETVAL (0x00000000u)

/* TX power meter 1 sync */
#define CSL_DFE_BB_CFG48_REG_SSEL_TXPM1_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG48_REG_SSEL_TXPM1_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG48_REG_SSEL_TXPM1_RESETVAL (0x00000000u)

/* TX power meter 2 sync */
#define CSL_DFE_BB_CFG48_REG_SSEL_TXPM2_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG48_REG_SSEL_TXPM2_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG48_REG_SSEL_TXPM2_RESETVAL (0x00000000u)

/* TX power meter 3 sync */
#define CSL_DFE_BB_CFG48_REG_SSEL_TXPM3_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG48_REG_SSEL_TXPM3_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG48_REG_SSEL_TXPM3_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG48_REG_ADDR (0x000402C0u)
#define CSL_DFE_BB_CFG48_REG_RESETVAL (0x00000000u)

/* CFG49 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_txpm7 : 4;
    Uint32 ssel_txpm6 : 4;
    Uint32 ssel_txpm5 : 4;
    Uint32 ssel_txpm4 : 4;
#else 
    Uint32 ssel_txpm4 : 4;
    Uint32 ssel_txpm5 : 4;
    Uint32 ssel_txpm6 : 4;
    Uint32 ssel_txpm7 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG49_REG;

/* TX power meter 4 sync */
#define CSL_DFE_BB_CFG49_REG_SSEL_TXPM4_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG49_REG_SSEL_TXPM4_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG49_REG_SSEL_TXPM4_RESETVAL (0x00000000u)

/* TX power meter 5 sync */
#define CSL_DFE_BB_CFG49_REG_SSEL_TXPM5_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG49_REG_SSEL_TXPM5_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG49_REG_SSEL_TXPM5_RESETVAL (0x00000000u)

/* TX power meter 6 sync */
#define CSL_DFE_BB_CFG49_REG_SSEL_TXPM6_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG49_REG_SSEL_TXPM6_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG49_REG_SSEL_TXPM6_RESETVAL (0x00000000u)

/* TX power meter 7 sync */
#define CSL_DFE_BB_CFG49_REG_SSEL_TXPM7_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG49_REG_SSEL_TXPM7_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG49_REG_SSEL_TXPM7_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG49_REG_ADDR (0x000402C4u)
#define CSL_DFE_BB_CFG49_REG_RESETVAL (0x00000000u)

/* CFG50 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_txpm11 : 4;
    Uint32 ssel_txpm10 : 4;
    Uint32 ssel_txpm9 : 4;
    Uint32 ssel_txpm8 : 4;
#else 
    Uint32 ssel_txpm8 : 4;
    Uint32 ssel_txpm9 : 4;
    Uint32 ssel_txpm10 : 4;
    Uint32 ssel_txpm11 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG50_REG;

/* TX power meter 8 sync */
#define CSL_DFE_BB_CFG50_REG_SSEL_TXPM8_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG50_REG_SSEL_TXPM8_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG50_REG_SSEL_TXPM8_RESETVAL (0x00000000u)

/* TX power meter 9 sync */
#define CSL_DFE_BB_CFG50_REG_SSEL_TXPM9_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG50_REG_SSEL_TXPM9_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG50_REG_SSEL_TXPM9_RESETVAL (0x00000000u)

/* TX power meter 10 sync */
#define CSL_DFE_BB_CFG50_REG_SSEL_TXPM10_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG50_REG_SSEL_TXPM10_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG50_REG_SSEL_TXPM10_RESETVAL (0x00000000u)

/* TX power meter 11 sync */
#define CSL_DFE_BB_CFG50_REG_SSEL_TXPM11_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG50_REG_SSEL_TXPM11_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG50_REG_SSEL_TXPM11_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG50_REG_ADDR (0x000402C8u)
#define CSL_DFE_BB_CFG50_REG_RESETVAL (0x00000000u)

/* CFG51 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_txpm15 : 4;
    Uint32 ssel_txpm14 : 4;
    Uint32 ssel_txpm13 : 4;
    Uint32 ssel_txpm12 : 4;
#else 
    Uint32 ssel_txpm12 : 4;
    Uint32 ssel_txpm13 : 4;
    Uint32 ssel_txpm14 : 4;
    Uint32 ssel_txpm15 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG51_REG;

/* TX power meter 12 sync */
#define CSL_DFE_BB_CFG51_REG_SSEL_TXPM12_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG51_REG_SSEL_TXPM12_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG51_REG_SSEL_TXPM12_RESETVAL (0x00000000u)

/* TX power meter 13 sync */
#define CSL_DFE_BB_CFG51_REG_SSEL_TXPM13_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG51_REG_SSEL_TXPM13_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG51_REG_SSEL_TXPM13_RESETVAL (0x00000000u)

/* TX power meter 14 sync */
#define CSL_DFE_BB_CFG51_REG_SSEL_TXPM14_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG51_REG_SSEL_TXPM14_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG51_REG_SSEL_TXPM14_RESETVAL (0x00000000u)

/* TX power meter 15 sync */
#define CSL_DFE_BB_CFG51_REG_SSEL_TXPM15_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG51_REG_SSEL_TXPM15_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG51_REG_SSEL_TXPM15_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG51_REG_ADDR (0x000402CCu)
#define CSL_DFE_BB_CFG51_REG_RESETVAL (0x00000000u)

/* CFG52 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_rxpm3 : 4;
    Uint32 ssel_rxpm2 : 4;
    Uint32 ssel_rxpm1 : 4;
    Uint32 ssel_rxpm0 : 4;
#else 
    Uint32 ssel_rxpm0 : 4;
    Uint32 ssel_rxpm1 : 4;
    Uint32 ssel_rxpm2 : 4;
    Uint32 ssel_rxpm3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG52_REG;

/* RX power meter 0 sync */
#define CSL_DFE_BB_CFG52_REG_SSEL_RXPM0_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG52_REG_SSEL_RXPM0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG52_REG_SSEL_RXPM0_RESETVAL (0x00000000u)

/* RX power meter 1 sync */
#define CSL_DFE_BB_CFG52_REG_SSEL_RXPM1_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG52_REG_SSEL_RXPM1_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG52_REG_SSEL_RXPM1_RESETVAL (0x00000000u)

/* RX power meter 2 sync */
#define CSL_DFE_BB_CFG52_REG_SSEL_RXPM2_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG52_REG_SSEL_RXPM2_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG52_REG_SSEL_RXPM2_RESETVAL (0x00000000u)

/* RX power meter 3 sync */
#define CSL_DFE_BB_CFG52_REG_SSEL_RXPM3_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG52_REG_SSEL_RXPM3_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG52_REG_SSEL_RXPM3_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG52_REG_ADDR (0x000402D0u)
#define CSL_DFE_BB_CFG52_REG_RESETVAL (0x00000000u)

/* CFG53 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_rxpm7 : 4;
    Uint32 ssel_rxpm6 : 4;
    Uint32 ssel_rxpm5 : 4;
    Uint32 ssel_rxpm4 : 4;
#else 
    Uint32 ssel_rxpm4 : 4;
    Uint32 ssel_rxpm5 : 4;
    Uint32 ssel_rxpm6 : 4;
    Uint32 ssel_rxpm7 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG53_REG;

/* RX power meter 4 sync */
#define CSL_DFE_BB_CFG53_REG_SSEL_RXPM4_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG53_REG_SSEL_RXPM4_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG53_REG_SSEL_RXPM4_RESETVAL (0x00000000u)

/* RX power meter 5 sync */
#define CSL_DFE_BB_CFG53_REG_SSEL_RXPM5_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG53_REG_SSEL_RXPM5_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG53_REG_SSEL_RXPM5_RESETVAL (0x00000000u)

/* RX power meter 6 sync */
#define CSL_DFE_BB_CFG53_REG_SSEL_RXPM6_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG53_REG_SSEL_RXPM6_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG53_REG_SSEL_RXPM6_RESETVAL (0x00000000u)

/* RX power meter 7 sync */
#define CSL_DFE_BB_CFG53_REG_SSEL_RXPM7_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG53_REG_SSEL_RXPM7_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG53_REG_SSEL_RXPM7_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG53_REG_ADDR (0x000402D4u)
#define CSL_DFE_BB_CFG53_REG_RESETVAL (0x00000000u)

/* CFG54 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_rxpm11 : 4;
    Uint32 ssel_rxpm10 : 4;
    Uint32 ssel_rxpm9 : 4;
    Uint32 ssel_rxpm8 : 4;
#else 
    Uint32 ssel_rxpm8 : 4;
    Uint32 ssel_rxpm9 : 4;
    Uint32 ssel_rxpm10 : 4;
    Uint32 ssel_rxpm11 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG54_REG;

/* RX power meter 8 sync */
#define CSL_DFE_BB_CFG54_REG_SSEL_RXPM8_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG54_REG_SSEL_RXPM8_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG54_REG_SSEL_RXPM8_RESETVAL (0x00000000u)

/* RX power meter 9 sync */
#define CSL_DFE_BB_CFG54_REG_SSEL_RXPM9_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG54_REG_SSEL_RXPM9_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG54_REG_SSEL_RXPM9_RESETVAL (0x00000000u)

/* RX power meter 10 sync */
#define CSL_DFE_BB_CFG54_REG_SSEL_RXPM10_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG54_REG_SSEL_RXPM10_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG54_REG_SSEL_RXPM10_RESETVAL (0x00000000u)

/* RX power meter 11 sync */
#define CSL_DFE_BB_CFG54_REG_SSEL_RXPM11_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG54_REG_SSEL_RXPM11_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG54_REG_SSEL_RXPM11_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG54_REG_ADDR (0x000402D8u)
#define CSL_DFE_BB_CFG54_REG_RESETVAL (0x00000000u)

/* CFG55 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_rxpm15 : 4;
    Uint32 ssel_rxpm14 : 4;
    Uint32 ssel_rxpm13 : 4;
    Uint32 ssel_rxpm12 : 4;
#else 
    Uint32 ssel_rxpm12 : 4;
    Uint32 ssel_rxpm13 : 4;
    Uint32 ssel_rxpm14 : 4;
    Uint32 ssel_rxpm15 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG55_REG;

/* RX power meter 12 sync */
#define CSL_DFE_BB_CFG55_REG_SSEL_RXPM12_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG55_REG_SSEL_RXPM12_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG55_REG_SSEL_RXPM12_RESETVAL (0x00000000u)

/* RX power meter 13 sync */
#define CSL_DFE_BB_CFG55_REG_SSEL_RXPM13_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG55_REG_SSEL_RXPM13_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG55_REG_SSEL_RXPM13_RESETVAL (0x00000000u)

/* RX power meter 14 sync */
#define CSL_DFE_BB_CFG55_REG_SSEL_RXPM14_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG55_REG_SSEL_RXPM14_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG55_REG_SSEL_RXPM14_RESETVAL (0x00000000u)

/* RX power meter 15 sync */
#define CSL_DFE_BB_CFG55_REG_SSEL_RXPM15_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG55_REG_SSEL_RXPM15_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG55_REG_SSEL_RXPM15_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG55_REG_ADDR (0x000402DCu)
#define CSL_DFE_BB_CFG55_REG_RESETVAL (0x00000000u)

/* CFG56 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_rxgain_ct3 : 4;
    Uint32 ssel_rxgain_ct2 : 4;
    Uint32 ssel_rxgain_ct1 : 4;
    Uint32 ssel_rxgain_ct0 : 4;
#else 
    Uint32 ssel_rxgain_ct0 : 4;
    Uint32 ssel_rxgain_ct1 : 4;
    Uint32 ssel_rxgain_ct2 : 4;
    Uint32 ssel_rxgain_ct3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG56_REG;

/* Update of Rxgain of carrier type 0 to active buffer */
#define CSL_DFE_BB_CFG56_REG_SSEL_RXGAIN_CT0_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG56_REG_SSEL_RXGAIN_CT0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG56_REG_SSEL_RXGAIN_CT0_RESETVAL (0x00000000u)

/* Update of Rxgain of carrier type 1 to active buffer */
#define CSL_DFE_BB_CFG56_REG_SSEL_RXGAIN_CT1_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG56_REG_SSEL_RXGAIN_CT1_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG56_REG_SSEL_RXGAIN_CT1_RESETVAL (0x00000000u)

/* Update of Rxgain of carrier type 2 to active buffer */
#define CSL_DFE_BB_CFG56_REG_SSEL_RXGAIN_CT2_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG56_REG_SSEL_RXGAIN_CT2_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG56_REG_SSEL_RXGAIN_CT2_RESETVAL (0x00000000u)

/* Update of Rxgain of carrier type 3 to active buffer */
#define CSL_DFE_BB_CFG56_REG_SSEL_RXGAIN_CT3_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG56_REG_SSEL_RXGAIN_CT3_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG56_REG_SSEL_RXGAIN_CT3_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG56_REG_ADDR (0x000402E0u)
#define CSL_DFE_BB_CFG56_REG_RESETVAL (0x00000000u)

/* CFG57 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_rxgain_ct7 : 4;
    Uint32 ssel_rxgain_ct6 : 4;
    Uint32 ssel_rxgain_ct5 : 4;
    Uint32 ssel_rxgain_ct4 : 4;
#else 
    Uint32 ssel_rxgain_ct4 : 4;
    Uint32 ssel_rxgain_ct5 : 4;
    Uint32 ssel_rxgain_ct6 : 4;
    Uint32 ssel_rxgain_ct7 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG57_REG;

/* Update of Rxgain of carrier type 4 to active buffer */
#define CSL_DFE_BB_CFG57_REG_SSEL_RXGAIN_CT4_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG57_REG_SSEL_RXGAIN_CT4_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG57_REG_SSEL_RXGAIN_CT4_RESETVAL (0x00000000u)

/* Update of Rxgain of carrier type 5 to active buffer */
#define CSL_DFE_BB_CFG57_REG_SSEL_RXGAIN_CT5_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG57_REG_SSEL_RXGAIN_CT5_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG57_REG_SSEL_RXGAIN_CT5_RESETVAL (0x00000000u)

/* Update of Rxgain of carrier type 6 to active buffer */
#define CSL_DFE_BB_CFG57_REG_SSEL_RXGAIN_CT6_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG57_REG_SSEL_RXGAIN_CT6_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG57_REG_SSEL_RXGAIN_CT6_RESETVAL (0x00000000u)

/* Update of Rxgain of carrier type 7 to active buffer */
#define CSL_DFE_BB_CFG57_REG_SSEL_RXGAIN_CT7_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG57_REG_SSEL_RXGAIN_CT7_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG57_REG_SSEL_RXGAIN_CT7_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG57_REG_ADDR (0x000402E4u)
#define CSL_DFE_BB_CFG57_REG_RESETVAL (0x00000000u)

/* CFG58 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_rxgain_ct11 : 4;
    Uint32 ssel_rxgain_ct10 : 4;
    Uint32 ssel_rxgain_ct9 : 4;
    Uint32 ssel_rxgain_ct8 : 4;
#else 
    Uint32 ssel_rxgain_ct8 : 4;
    Uint32 ssel_rxgain_ct9 : 4;
    Uint32 ssel_rxgain_ct10 : 4;
    Uint32 ssel_rxgain_ct11 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG58_REG;

/* Update of Rxgain of carrier type 8 to active buffer */
#define CSL_DFE_BB_CFG58_REG_SSEL_RXGAIN_CT8_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG58_REG_SSEL_RXGAIN_CT8_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG58_REG_SSEL_RXGAIN_CT8_RESETVAL (0x00000000u)

/* Update of Rxgain of carrier type 9 to active buffer */
#define CSL_DFE_BB_CFG58_REG_SSEL_RXGAIN_CT9_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG58_REG_SSEL_RXGAIN_CT9_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG58_REG_SSEL_RXGAIN_CT9_RESETVAL (0x00000000u)

/* Update of Rxgain of carrier type 10 to active buffer */
#define CSL_DFE_BB_CFG58_REG_SSEL_RXGAIN_CT10_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG58_REG_SSEL_RXGAIN_CT10_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG58_REG_SSEL_RXGAIN_CT10_RESETVAL (0x00000000u)

/* Update of Rxgain of carrier type 11 to active buffer */
#define CSL_DFE_BB_CFG58_REG_SSEL_RXGAIN_CT11_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG58_REG_SSEL_RXGAIN_CT11_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG58_REG_SSEL_RXGAIN_CT11_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG58_REG_ADDR (0x000402E8u)
#define CSL_DFE_BB_CFG58_REG_RESETVAL (0x00000000u)

/* CFG59 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_rxgain_ct15 : 4;
    Uint32 ssel_rxgain_ct14 : 4;
    Uint32 ssel_rxgain_ct13 : 4;
    Uint32 ssel_rxgain_ct12 : 4;
#else 
    Uint32 ssel_rxgain_ct12 : 4;
    Uint32 ssel_rxgain_ct13 : 4;
    Uint32 ssel_rxgain_ct14 : 4;
    Uint32 ssel_rxgain_ct15 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG59_REG;

/* Update of Rxgain of carrier type 12 to active buffer */
#define CSL_DFE_BB_CFG59_REG_SSEL_RXGAIN_CT12_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG59_REG_SSEL_RXGAIN_CT12_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG59_REG_SSEL_RXGAIN_CT12_RESETVAL (0x00000000u)

/* Update of Rxgain of carrier type 13 to active buffer */
#define CSL_DFE_BB_CFG59_REG_SSEL_RXGAIN_CT13_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG59_REG_SSEL_RXGAIN_CT13_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG59_REG_SSEL_RXGAIN_CT13_RESETVAL (0x00000000u)

/* Update of Rxgain of carrier type 14 to active buffer */
#define CSL_DFE_BB_CFG59_REG_SSEL_RXGAIN_CT14_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG59_REG_SSEL_RXGAIN_CT14_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG59_REG_SSEL_RXGAIN_CT14_RESETVAL (0x00000000u)

/* Update of Rxgain of carrier type 15 to active buffer */
#define CSL_DFE_BB_CFG59_REG_SSEL_RXGAIN_CT15_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG59_REG_SSEL_RXGAIN_CT15_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG59_REG_SSEL_RXGAIN_CT15_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG59_REG_ADDR (0x000402ECu)
#define CSL_DFE_BB_CFG59_REG_RESETVAL (0x00000000u)

/* CFG60 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_txgain_ct3 : 4;
    Uint32 ssel_txgain_ct2 : 4;
    Uint32 ssel_txgain_ct1 : 4;
    Uint32 ssel_txgain_ct0 : 4;
#else 
    Uint32 ssel_txgain_ct0 : 4;
    Uint32 ssel_txgain_ct1 : 4;
    Uint32 ssel_txgain_ct2 : 4;
    Uint32 ssel_txgain_ct3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG60_REG;

/* Update of Txgain of carrier type 0 to active buffer */
#define CSL_DFE_BB_CFG60_REG_SSEL_TXGAIN_CT0_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG60_REG_SSEL_TXGAIN_CT0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG60_REG_SSEL_TXGAIN_CT0_RESETVAL (0x00000000u)

/* Update of Txgain of carrier type 1 to active buffer */
#define CSL_DFE_BB_CFG60_REG_SSEL_TXGAIN_CT1_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG60_REG_SSEL_TXGAIN_CT1_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG60_REG_SSEL_TXGAIN_CT1_RESETVAL (0x00000000u)

/* Update of Txgain of carrier type 2 to active buffer */
#define CSL_DFE_BB_CFG60_REG_SSEL_TXGAIN_CT2_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG60_REG_SSEL_TXGAIN_CT2_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG60_REG_SSEL_TXGAIN_CT2_RESETVAL (0x00000000u)

/* Update of Txgain of carrier type 3 to active buffer */
#define CSL_DFE_BB_CFG60_REG_SSEL_TXGAIN_CT3_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG60_REG_SSEL_TXGAIN_CT3_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG60_REG_SSEL_TXGAIN_CT3_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG60_REG_ADDR (0x000402F0u)
#define CSL_DFE_BB_CFG60_REG_RESETVAL (0x00000000u)

/* CFG61 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_txgain_ct7 : 4;
    Uint32 ssel_txgain_ct6 : 4;
    Uint32 ssel_txgain_ct5 : 4;
    Uint32 ssel_txgain_ct4 : 4;
#else 
    Uint32 ssel_txgain_ct4 : 4;
    Uint32 ssel_txgain_ct5 : 4;
    Uint32 ssel_txgain_ct6 : 4;
    Uint32 ssel_txgain_ct7 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG61_REG;

/* Update of Txgain of carrier type 4 to active buffer */
#define CSL_DFE_BB_CFG61_REG_SSEL_TXGAIN_CT4_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG61_REG_SSEL_TXGAIN_CT4_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG61_REG_SSEL_TXGAIN_CT4_RESETVAL (0x00000000u)

/* Update of Txgain of carrier type 5 to active buffer */
#define CSL_DFE_BB_CFG61_REG_SSEL_TXGAIN_CT5_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG61_REG_SSEL_TXGAIN_CT5_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG61_REG_SSEL_TXGAIN_CT5_RESETVAL (0x00000000u)

/* Update of Txgain of carrier type 6 to active buffer */
#define CSL_DFE_BB_CFG61_REG_SSEL_TXGAIN_CT6_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG61_REG_SSEL_TXGAIN_CT6_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG61_REG_SSEL_TXGAIN_CT6_RESETVAL (0x00000000u)

/* Update of Txgain of carrier type 7 to active buffer */
#define CSL_DFE_BB_CFG61_REG_SSEL_TXGAIN_CT7_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG61_REG_SSEL_TXGAIN_CT7_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG61_REG_SSEL_TXGAIN_CT7_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG61_REG_ADDR (0x000402F4u)
#define CSL_DFE_BB_CFG61_REG_RESETVAL (0x00000000u)

/* CFG62 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_txgain_ct11 : 4;
    Uint32 ssel_txgain_ct10 : 4;
    Uint32 ssel_txgain_ct9 : 4;
    Uint32 ssel_txgain_ct8 : 4;
#else 
    Uint32 ssel_txgain_ct8 : 4;
    Uint32 ssel_txgain_ct9 : 4;
    Uint32 ssel_txgain_ct10 : 4;
    Uint32 ssel_txgain_ct11 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG62_REG;

/* Update of Txgain of carrier type 8 to active buffer */
#define CSL_DFE_BB_CFG62_REG_SSEL_TXGAIN_CT8_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG62_REG_SSEL_TXGAIN_CT8_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG62_REG_SSEL_TXGAIN_CT8_RESETVAL (0x00000000u)

/* Update of Txgain of carrier type 9 to active buffer */
#define CSL_DFE_BB_CFG62_REG_SSEL_TXGAIN_CT9_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG62_REG_SSEL_TXGAIN_CT9_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG62_REG_SSEL_TXGAIN_CT9_RESETVAL (0x00000000u)

/* Update of Txgain of carrier type 10 to active buffer */
#define CSL_DFE_BB_CFG62_REG_SSEL_TXGAIN_CT10_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG62_REG_SSEL_TXGAIN_CT10_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG62_REG_SSEL_TXGAIN_CT10_RESETVAL (0x00000000u)

/* Update of Txgain of carrier type 11 to active buffer */
#define CSL_DFE_BB_CFG62_REG_SSEL_TXGAIN_CT11_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG62_REG_SSEL_TXGAIN_CT11_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG62_REG_SSEL_TXGAIN_CT11_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG62_REG_ADDR (0x000402F8u)
#define CSL_DFE_BB_CFG62_REG_RESETVAL (0x00000000u)

/* CFG63 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_txgain_ct15 : 4;
    Uint32 ssel_txgain_ct14 : 4;
    Uint32 ssel_txgain_ct13 : 4;
    Uint32 ssel_txgain_ct12 : 4;
#else 
    Uint32 ssel_txgain_ct12 : 4;
    Uint32 ssel_txgain_ct13 : 4;
    Uint32 ssel_txgain_ct14 : 4;
    Uint32 ssel_txgain_ct15 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG63_REG;

/* Update of Txgain of carrier type 12 to active buffer */
#define CSL_DFE_BB_CFG63_REG_SSEL_TXGAIN_CT12_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG63_REG_SSEL_TXGAIN_CT12_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG63_REG_SSEL_TXGAIN_CT12_RESETVAL (0x00000000u)

/* Update of Txgain of carrier type 13 to active buffer */
#define CSL_DFE_BB_CFG63_REG_SSEL_TXGAIN_CT13_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG63_REG_SSEL_TXGAIN_CT13_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG63_REG_SSEL_TXGAIN_CT13_RESETVAL (0x00000000u)

/* Update of Txgain of carrier type 14 to active buffer */
#define CSL_DFE_BB_CFG63_REG_SSEL_TXGAIN_CT14_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG63_REG_SSEL_TXGAIN_CT14_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG63_REG_SSEL_TXGAIN_CT14_RESETVAL (0x00000000u)

/* Update of Txgain of carrier type 15 to active buffer */
#define CSL_DFE_BB_CFG63_REG_SSEL_TXGAIN_CT15_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG63_REG_SSEL_TXGAIN_CT15_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG63_REG_SSEL_TXGAIN_CT15_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG63_REG_ADDR (0x000402FCu)
#define CSL_DFE_BB_CFG63_REG_RESETVAL (0x00000000u)

/* CFG64 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbtxif_ct3_varisource : 4;
    Uint32 bbtxif_ct2_varisource : 4;
    Uint32 bbtxif_ct1_varisource : 4;
    Uint32 bbtxif_ct0_varisource : 4;
#else 
    Uint32 bbtxif_ct0_varisource : 4;
    Uint32 bbtxif_ct1_varisource : 4;
    Uint32 bbtxif_ct2_varisource : 4;
    Uint32 bbtxif_ct3_varisource : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG64_REG;

/* dduc frame sync that is to be used by TX if  CT0 is a variable type.  This is because only the DDUC has the control to know when the variable data sync is valid.   */
#define CSL_DFE_BB_CFG64_REG_BBTXIF_CT0_VARISOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG64_REG_BBTXIF_CT0_VARISOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG64_REG_BBTXIF_CT0_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by TX if  CT1 is a variable type.   */
#define CSL_DFE_BB_CFG64_REG_BBTXIF_CT1_VARISOURCE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG64_REG_BBTXIF_CT1_VARISOURCE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG64_REG_BBTXIF_CT1_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by TX if  CT2 is a variable type.   */
#define CSL_DFE_BB_CFG64_REG_BBTXIF_CT2_VARISOURCE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG64_REG_BBTXIF_CT2_VARISOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG64_REG_BBTXIF_CT2_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by TX if  CT3 is a variable type.   */
#define CSL_DFE_BB_CFG64_REG_BBTXIF_CT3_VARISOURCE_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG64_REG_BBTXIF_CT3_VARISOURCE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG64_REG_BBTXIF_CT3_VARISOURCE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG64_REG_ADDR (0x00040300u)
#define CSL_DFE_BB_CFG64_REG_RESETVAL (0x00000000u)

/* CFG65 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbtxif_ct7_varisource : 4;
    Uint32 bbtxif_ct6_varisource : 4;
    Uint32 bbtxif_ct5_varisource : 4;
    Uint32 bbtxif_ct4_varisource : 4;
#else 
    Uint32 bbtxif_ct4_varisource : 4;
    Uint32 bbtxif_ct5_varisource : 4;
    Uint32 bbtxif_ct6_varisource : 4;
    Uint32 bbtxif_ct7_varisource : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG65_REG;

/* dduc frame sync that is to be used by TX if  CT4 is a variable type.   */
#define CSL_DFE_BB_CFG65_REG_BBTXIF_CT4_VARISOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG65_REG_BBTXIF_CT4_VARISOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG65_REG_BBTXIF_CT4_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by TX if  CT5 is a variable type.   */
#define CSL_DFE_BB_CFG65_REG_BBTXIF_CT5_VARISOURCE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG65_REG_BBTXIF_CT5_VARISOURCE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG65_REG_BBTXIF_CT5_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by TX if  CT6 is a variable type.   */
#define CSL_DFE_BB_CFG65_REG_BBTXIF_CT6_VARISOURCE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG65_REG_BBTXIF_CT6_VARISOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG65_REG_BBTXIF_CT6_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by TX if  CT7 is a variable type.   */
#define CSL_DFE_BB_CFG65_REG_BBTXIF_CT7_VARISOURCE_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG65_REG_BBTXIF_CT7_VARISOURCE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG65_REG_BBTXIF_CT7_VARISOURCE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG65_REG_ADDR (0x00040304u)
#define CSL_DFE_BB_CFG65_REG_RESETVAL (0x00000000u)

/* CFG66 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbtxif_ct11_varisource : 4;
    Uint32 bbtxif_ct10_varisource : 4;
    Uint32 bbtxif_ct9_varisource : 4;
    Uint32 bbtxif_ct8_varisource : 4;
#else 
    Uint32 bbtxif_ct8_varisource : 4;
    Uint32 bbtxif_ct9_varisource : 4;
    Uint32 bbtxif_ct10_varisource : 4;
    Uint32 bbtxif_ct11_varisource : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG66_REG;

/* dduc frame sync that is to be used by TX if  CT8 is a variable type.   */
#define CSL_DFE_BB_CFG66_REG_BBTXIF_CT8_VARISOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG66_REG_BBTXIF_CT8_VARISOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG66_REG_BBTXIF_CT8_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by TX if  CT9 is a variable type.   */
#define CSL_DFE_BB_CFG66_REG_BBTXIF_CT9_VARISOURCE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG66_REG_BBTXIF_CT9_VARISOURCE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG66_REG_BBTXIF_CT9_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by TX if  CT10 is a variable type.   */
#define CSL_DFE_BB_CFG66_REG_BBTXIF_CT10_VARISOURCE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG66_REG_BBTXIF_CT10_VARISOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG66_REG_BBTXIF_CT10_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by TX if  CT11 is a variable type.   */
#define CSL_DFE_BB_CFG66_REG_BBTXIF_CT11_VARISOURCE_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG66_REG_BBTXIF_CT11_VARISOURCE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG66_REG_BBTXIF_CT11_VARISOURCE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG66_REG_ADDR (0x00040308u)
#define CSL_DFE_BB_CFG66_REG_RESETVAL (0x00000000u)

/* CFG67 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 bbtxif_ct14_varisource : 4;
    Uint32 bbtxif_ct13_varisource : 4;
    Uint32 bbtxif_ct12_varisource : 4;
#else 
    Uint32 bbtxif_ct12_varisource : 4;
    Uint32 bbtxif_ct13_varisource : 4;
    Uint32 bbtxif_ct14_varisource : 4;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG67_REG;

/* dduc frame sync that is to be used by TX if  CT12 is a variable type.   */
#define CSL_DFE_BB_CFG67_REG_BBTXIF_CT12_VARISOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG67_REG_BBTXIF_CT12_VARISOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG67_REG_BBTXIF_CT12_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by TX if  CT13 is a variable type.   */
#define CSL_DFE_BB_CFG67_REG_BBTXIF_CT13_VARISOURCE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG67_REG_BBTXIF_CT13_VARISOURCE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG67_REG_BBTXIF_CT13_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by TX if  CT14 is a variable type.   */
#define CSL_DFE_BB_CFG67_REG_BBTXIF_CT14_VARISOURCE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG67_REG_BBTXIF_CT14_VARISOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG67_REG_BBTXIF_CT14_VARISOURCE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG67_REG_ADDR (0x0004030Cu)
#define CSL_DFE_BB_CFG67_REG_RESETVAL (0x00000000u)

/* CFG68 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbrxif_ct3_varisource : 4;
    Uint32 bbrxif_ct2_varisource : 4;
    Uint32 bbrxif_ct1_varisource : 4;
    Uint32 bbrxif_ct0_varisource : 4;
#else 
    Uint32 bbrxif_ct0_varisource : 4;
    Uint32 bbrxif_ct1_varisource : 4;
    Uint32 bbrxif_ct2_varisource : 4;
    Uint32 bbrxif_ct3_varisource : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG68_REG;

/* dduc frame sync that is to be used by RX if CT0 is a variable type.  This is because only the DDUC has the control to know when the variable data sync is valid.   */
#define CSL_DFE_BB_CFG68_REG_BBRXIF_CT0_VARISOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG68_REG_BBRXIF_CT0_VARISOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG68_REG_BBRXIF_CT0_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by RX if CT1 is a variable type */
#define CSL_DFE_BB_CFG68_REG_BBRXIF_CT1_VARISOURCE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG68_REG_BBRXIF_CT1_VARISOURCE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG68_REG_BBRXIF_CT1_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by RX if CT2 is a variable type */
#define CSL_DFE_BB_CFG68_REG_BBRXIF_CT2_VARISOURCE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG68_REG_BBRXIF_CT2_VARISOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG68_REG_BBRXIF_CT2_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by RX if CT3 is a variable type */
#define CSL_DFE_BB_CFG68_REG_BBRXIF_CT3_VARISOURCE_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG68_REG_BBRXIF_CT3_VARISOURCE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG68_REG_BBRXIF_CT3_VARISOURCE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG68_REG_ADDR (0x00040310u)
#define CSL_DFE_BB_CFG68_REG_RESETVAL (0x00000000u)

/* CFG69 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbrxif_ct7_varisource : 4;
    Uint32 bbrxif_ct6_varisource : 4;
    Uint32 bbrxif_ct5_varisource : 4;
    Uint32 bbrxif_ct4_varisource : 4;
#else 
    Uint32 bbrxif_ct4_varisource : 4;
    Uint32 bbrxif_ct5_varisource : 4;
    Uint32 bbrxif_ct6_varisource : 4;
    Uint32 bbrxif_ct7_varisource : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG69_REG;

/* dduc frame sync that is to be used by RX if CT4 is a variable type */
#define CSL_DFE_BB_CFG69_REG_BBRXIF_CT4_VARISOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG69_REG_BBRXIF_CT4_VARISOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG69_REG_BBRXIF_CT4_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by RX if CT5 is a variable type */
#define CSL_DFE_BB_CFG69_REG_BBRXIF_CT5_VARISOURCE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG69_REG_BBRXIF_CT5_VARISOURCE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG69_REG_BBRXIF_CT5_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by RX if CT6 is a variable type */
#define CSL_DFE_BB_CFG69_REG_BBRXIF_CT6_VARISOURCE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG69_REG_BBRXIF_CT6_VARISOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG69_REG_BBRXIF_CT6_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by RX if CT7 is a variable type */
#define CSL_DFE_BB_CFG69_REG_BBRXIF_CT7_VARISOURCE_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG69_REG_BBRXIF_CT7_VARISOURCE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG69_REG_BBRXIF_CT7_VARISOURCE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG69_REG_ADDR (0x00040314u)
#define CSL_DFE_BB_CFG69_REG_RESETVAL (0x00000000u)

/* CFG70 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bbrxif_ct11_varisource : 4;
    Uint32 bbrxif_ct10_varisource : 4;
    Uint32 bbrxif_ct9_varisource : 4;
    Uint32 bbrxif_ct8_varisource : 4;
#else 
    Uint32 bbrxif_ct8_varisource : 4;
    Uint32 bbrxif_ct9_varisource : 4;
    Uint32 bbrxif_ct10_varisource : 4;
    Uint32 bbrxif_ct11_varisource : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG70_REG;

/* dduc frame sync that is to be used by RX if CT8 is a variable type */
#define CSL_DFE_BB_CFG70_REG_BBRXIF_CT8_VARISOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG70_REG_BBRXIF_CT8_VARISOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG70_REG_BBRXIF_CT8_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by RX if CT9 is a variable type */
#define CSL_DFE_BB_CFG70_REG_BBRXIF_CT9_VARISOURCE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG70_REG_BBRXIF_CT9_VARISOURCE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG70_REG_BBRXIF_CT9_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by RX if CT10 is a variable type */
#define CSL_DFE_BB_CFG70_REG_BBRXIF_CT10_VARISOURCE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG70_REG_BBRXIF_CT10_VARISOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG70_REG_BBRXIF_CT10_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by RX if CT11 is a variable type */
#define CSL_DFE_BB_CFG70_REG_BBRXIF_CT11_VARISOURCE_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG70_REG_BBRXIF_CT11_VARISOURCE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG70_REG_BBRXIF_CT11_VARISOURCE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG70_REG_ADDR (0x00040318u)
#define CSL_DFE_BB_CFG70_REG_RESETVAL (0x00000000u)

/* CFG71 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 bbrxif_ct14_varisource : 4;
    Uint32 bbrxif_ct13_varisource : 4;
    Uint32 bbrxif_ct12_varisource : 4;
#else 
    Uint32 bbrxif_ct12_varisource : 4;
    Uint32 bbrxif_ct13_varisource : 4;
    Uint32 bbrxif_ct14_varisource : 4;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG71_REG;

/* dduc frame sync that is to be used by RX if CT12 is a variable type */
#define CSL_DFE_BB_CFG71_REG_BBRXIF_CT12_VARISOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG71_REG_BBRXIF_CT12_VARISOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG71_REG_BBRXIF_CT12_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by RX if CT13 is a variable type */
#define CSL_DFE_BB_CFG71_REG_BBRXIF_CT13_VARISOURCE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG71_REG_BBRXIF_CT13_VARISOURCE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG71_REG_BBRXIF_CT13_VARISOURCE_RESETVAL (0x00000000u)

/* dduc frame sync that is to be used by RX if CT14 is a variable type */
#define CSL_DFE_BB_CFG71_REG_BBRXIF_CT14_VARISOURCE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG71_REG_BBRXIF_CT14_VARISOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG71_REG_BBRXIF_CT14_VARISOURCE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG71_REG_ADDR (0x0004031Cu)
#define CSL_DFE_BB_CFG71_REG_RESETVAL (0x00000000u)

/* CFG72 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 buf0_carrier_disable : 12;
#else 
    Uint32 buf0_carrier_disable : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG72_REG;

/* This will force data of this carrier to be zero.  In variable mode it also prevents a buffer over/underflow from being generated */
#define CSL_DFE_BB_CFG72_REG_BUF0_CARRIER_DISABLE_MASK (0x00000FFFu)
#define CSL_DFE_BB_CFG72_REG_BUF0_CARRIER_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG72_REG_BUF0_CARRIER_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG72_REG_ADDR (0x00040320u)
#define CSL_DFE_BB_CFG72_REG_RESETVAL (0x00000000u)

/* CFG73 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 buf1_carrier_disable : 12;
#else 
    Uint32 buf1_carrier_disable : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG73_REG;

/* see above */
#define CSL_DFE_BB_CFG73_REG_BUF1_CARRIER_DISABLE_MASK (0x00000FFFu)
#define CSL_DFE_BB_CFG73_REG_BUF1_CARRIER_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG73_REG_BUF1_CARRIER_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG73_REG_ADDR (0x00040324u)
#define CSL_DFE_BB_CFG73_REG_RESETVAL (0x00000000u)

/* CFG74 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 buf2_carrier_disable : 12;
#else 
    Uint32 buf2_carrier_disable : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG74_REG;

/* see above */
#define CSL_DFE_BB_CFG74_REG_BUF2_CARRIER_DISABLE_MASK (0x00000FFFu)
#define CSL_DFE_BB_CFG74_REG_BUF2_CARRIER_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG74_REG_BUF2_CARRIER_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG74_REG_ADDR (0x00040328u)
#define CSL_DFE_BB_CFG74_REG_RESETVAL (0x00000000u)

/* CFG75 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 buf3_carrier_disable : 12;
#else 
    Uint32 buf3_carrier_disable : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG75_REG;

/* see above */
#define CSL_DFE_BB_CFG75_REG_BUF3_CARRIER_DISABLE_MASK (0x00000FFFu)
#define CSL_DFE_BB_CFG75_REG_BUF3_CARRIER_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG75_REG_BUF3_CARRIER_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG75_REG_ADDR (0x0004032Cu)
#define CSL_DFE_BB_CFG75_REG_RESETVAL (0x00000000u)

/* CFG76 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 buf4_carrier_disable : 12;
#else 
    Uint32 buf4_carrier_disable : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG76_REG;

/* see above */
#define CSL_DFE_BB_CFG76_REG_BUF4_CARRIER_DISABLE_MASK (0x00000FFFu)
#define CSL_DFE_BB_CFG76_REG_BUF4_CARRIER_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG76_REG_BUF4_CARRIER_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG76_REG_ADDR (0x00040330u)
#define CSL_DFE_BB_CFG76_REG_RESETVAL (0x00000000u)

/* CFG77 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 buf5_carrier_disable : 12;
#else 
    Uint32 buf5_carrier_disable : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG77_REG;

/* see above */
#define CSL_DFE_BB_CFG77_REG_BUF5_CARRIER_DISABLE_MASK (0x00000FFFu)
#define CSL_DFE_BB_CFG77_REG_BUF5_CARRIER_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG77_REG_BUF5_CARRIER_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG77_REG_ADDR (0x00040334u)
#define CSL_DFE_BB_CFG77_REG_RESETVAL (0x00000000u)

/* CFG78 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 buf6_carrier_disable : 12;
#else 
    Uint32 buf6_carrier_disable : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG78_REG;

/* see above */
#define CSL_DFE_BB_CFG78_REG_BUF6_CARRIER_DISABLE_MASK (0x00000FFFu)
#define CSL_DFE_BB_CFG78_REG_BUF6_CARRIER_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG78_REG_BUF6_CARRIER_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG78_REG_ADDR (0x00040338u)
#define CSL_DFE_BB_CFG78_REG_RESETVAL (0x00000000u)

/* CFG79 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 buf7_carrier_disable : 12;
#else 
    Uint32 buf7_carrier_disable : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG79_REG;

/* see above */
#define CSL_DFE_BB_CFG79_REG_BUF7_CARRIER_DISABLE_MASK (0x00000FFFu)
#define CSL_DFE_BB_CFG79_REG_BUF7_CARRIER_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG79_REG_BUF7_CARRIER_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG79_REG_ADDR (0x0004033Cu)
#define CSL_DFE_BB_CFG79_REG_RESETVAL (0x00000000u)

/* CFG81 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 buf_delay_15_0 : 16;
#else 
    Uint32 buf_delay_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG81_REG;

/* initialization delay for dduc buffers.  2 bits per dduc [1:0] is for buffer 0, [3:2] is for buffer1.    Delay of zero is minimum value but does not guarantee auto zero functionality.  1 guarantees auto zero function.  2 and 3 give more sample delay. */
#define CSL_DFE_BB_CFG81_REG_BUF_DELAY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG81_REG_BUF_DELAY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG81_REG_BUF_DELAY_15_0_RESETVAL (0x00005555u)

#define CSL_DFE_BB_CFG81_REG_ADDR (0x00040344u)
#define CSL_DFE_BB_CFG81_REG_RESETVAL (0x00005555u)

/* CFG82 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_rxbeagc3 : 4;
    Uint32 ssel_rxbeagc2 : 4;
    Uint32 ssel_rxbeagc1 : 4;
    Uint32 ssel_rxbeagc0 : 4;
#else 
    Uint32 ssel_rxbeagc0 : 4;
    Uint32 ssel_rxbeagc1 : 4;
    Uint32 ssel_rxbeagc2 : 4;
    Uint32 ssel_rxbeagc3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG82_REG;

/* RX beAGC 0 sync */
#define CSL_DFE_BB_CFG82_REG_SSEL_RXBEAGC0_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG82_REG_SSEL_RXBEAGC0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG82_REG_SSEL_RXBEAGC0_RESETVAL (0x00000000u)

/* RX beAGC 1 sync */
#define CSL_DFE_BB_CFG82_REG_SSEL_RXBEAGC1_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG82_REG_SSEL_RXBEAGC1_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG82_REG_SSEL_RXBEAGC1_RESETVAL (0x00000000u)

/* RX beAGC 2 sync */
#define CSL_DFE_BB_CFG82_REG_SSEL_RXBEAGC2_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG82_REG_SSEL_RXBEAGC2_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG82_REG_SSEL_RXBEAGC2_RESETVAL (0x00000000u)

/* RX beAGC 3 sync */
#define CSL_DFE_BB_CFG82_REG_SSEL_RXBEAGC3_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG82_REG_SSEL_RXBEAGC3_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG82_REG_SSEL_RXBEAGC3_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG82_REG_ADDR (0x00040348u)
#define CSL_DFE_BB_CFG82_REG_RESETVAL (0x00000000u)

/* CFG83 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel_rxbeagc7 : 4;
    Uint32 ssel_rxbeagc6 : 4;
    Uint32 ssel_rxbeagc5 : 4;
    Uint32 ssel_rxbeagc4 : 4;
#else 
    Uint32 ssel_rxbeagc4 : 4;
    Uint32 ssel_rxbeagc5 : 4;
    Uint32 ssel_rxbeagc6 : 4;
    Uint32 ssel_rxbeagc7 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG83_REG;

/* RX beAGC 4 sync */
#define CSL_DFE_BB_CFG83_REG_SSEL_RXBEAGC4_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG83_REG_SSEL_RXBEAGC4_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG83_REG_SSEL_RXBEAGC4_RESETVAL (0x00000000u)

/* RX beAGC 5 sync */
#define CSL_DFE_BB_CFG83_REG_SSEL_RXBEAGC5_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG83_REG_SSEL_RXBEAGC5_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG83_REG_SSEL_RXBEAGC5_RESETVAL (0x00000000u)

/* RX beAGC 6 sync */
#define CSL_DFE_BB_CFG83_REG_SSEL_RXBEAGC6_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG83_REG_SSEL_RXBEAGC6_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG83_REG_SSEL_RXBEAGC6_RESETVAL (0x00000000u)

/* RX beAGC 7 sync */
#define CSL_DFE_BB_CFG83_REG_SSEL_RXBEAGC7_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG83_REG_SSEL_RXBEAGC7_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG83_REG_SSEL_RXBEAGC7_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG83_REG_ADDR (0x0004034Cu)
#define CSL_DFE_BB_CFG83_REG_RESETVAL (0x00000000u)

/* CFG84 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxgain_update_status : 16;
#else 
    Uint32 rxgain_update_status : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG84_REG;

/* One bit per carrier type indicating a gain update is pending.  Bit should not be set for more than 2 carrier intervals.  Gain update memory is readable when all bits are cleared.   */
#define CSL_DFE_BB_CFG84_REG_RXGAIN_UPDATE_STATUS_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG84_REG_RXGAIN_UPDATE_STATUS_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG84_REG_RXGAIN_UPDATE_STATUS_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG84_REG_ADDR (0x00040350u)
#define CSL_DFE_BB_CFG84_REG_RESETVAL (0x00000000u)

/* CFG85 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txgain_update_status : 16;
#else 
    Uint32 txgain_update_status : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG85_REG;

/* One bit per carrier type indicating a gain update is pending.  Bit should not be set for more than 2 carrier intervals.  Gain update memory is readable when all bits are cleared.   */
#define CSL_DFE_BB_CFG85_REG_TXGAIN_UPDATE_STATUS_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG85_REG_TXGAIN_UPDATE_STATUS_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG85_REG_TXGAIN_UPDATE_STATUS_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG85_REG_ADDR (0x00040354u)
#define CSL_DFE_BB_CFG85_REG_RESETVAL (0x00000000u)

/* CFG88 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_if_config : 16;
#else 
    Uint32 aid_if_config : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG88_REG;

/* Configuration word for AID interface.  bits 1:0 DL initialization mode 0= always active;  1= start AxC on strobe;  2= start on frame_start;        bit 1 Slave/Master 0=master of UL bus arbitration       bit 2  DL sync mode  0:=ct sync on strobe, 1= ct sync on frame_start;       bit 3 DL stream translation enable   0=bypass (note when bypassed only strobe0 is used);           bit 4 DL AxC sequencer initial sync mode, 0=free running, 1= sync on strobe;    bits 7:6 DL data width,  0= four 32 bit samples, 1=single 32 bit sample, 2=single 16 bit half sample;        bit 8  UL stream translation enable,  0=bypass;       bit 9  UL data width   0= four 32 bit I/Q samples, 1=single 32 bit sample (note may also have 16 bit samples packed for either mode);        bit 11 loopback mode DL-UL;      bits 14:12  strobe to initialize TX AxC sequencer;            bit 15 TX AxC sequencer initialize on rise or fall of strobe_valid  0=rise 1= fall  where length is set by ct interval and strobe_width; */
#define CSL_DFE_BB_CFG88_REG_AID_IF_CONFIG_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG88_REG_AID_IF_CONFIG_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG88_REG_AID_IF_CONFIG_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG88_REG_ADDR (0x00040360u)
#define CSL_DFE_BB_CFG88_REG_RESETVAL (0x00000000u)

/* CFG89 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_strobe3_ct : 4;
    Uint32 aid_strobe2_ct : 4;
    Uint32 aid_strobe1_ct : 4;
    Uint32 aid_strobe0_ct : 4;
#else 
    Uint32 aid_strobe0_ct : 4;
    Uint32 aid_strobe1_ct : 4;
    Uint32 aid_strobe2_ct : 4;
    Uint32 aid_strobe3_ct : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG89_REG;

/* AID interface input strobe 0 carrier type.  Used to define the period after strobe that AxCs become active for DL initialization mode 1.  value selects a ct interval (see 0x83 -0x8a) */
#define CSL_DFE_BB_CFG89_REG_AID_STROBE0_CT_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG89_REG_AID_STROBE0_CT_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG89_REG_AID_STROBE0_CT_RESETVAL (0x00000000u)

/* AID interface input strobe 1 carrier type. */
#define CSL_DFE_BB_CFG89_REG_AID_STROBE1_CT_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG89_REG_AID_STROBE1_CT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG89_REG_AID_STROBE1_CT_RESETVAL (0x00000000u)

/* AID interface input strobe 2 carrier type. */
#define CSL_DFE_BB_CFG89_REG_AID_STROBE2_CT_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG89_REG_AID_STROBE2_CT_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG89_REG_AID_STROBE2_CT_RESETVAL (0x00000000u)

/* AID interface input strobe 3 carrier type. */
#define CSL_DFE_BB_CFG89_REG_AID_STROBE3_CT_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG89_REG_AID_STROBE3_CT_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG89_REG_AID_STROBE3_CT_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG89_REG_ADDR (0x00040364u)
#define CSL_DFE_BB_CFG89_REG_RESETVAL (0x00000000u)

/* CFG91 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_strobe7_width : 2;
    Uint32 aid_strobe6_width : 2;
    Uint32 aid_strobe5_width : 2;
    Uint32 aid_strobe4_width : 2;
    Uint32 aid_strobe3_width : 2;
    Uint32 aid_strobe2_width : 2;
    Uint32 aid_strobe1_width : 2;
    Uint32 aid_strobe0_width : 2;
#else 
    Uint32 aid_strobe0_width : 2;
    Uint32 aid_strobe1_width : 2;
    Uint32 aid_strobe2_width : 2;
    Uint32 aid_strobe3_width : 2;
    Uint32 aid_strobe4_width : 2;
    Uint32 aid_strobe5_width : 2;
    Uint32 aid_strobe6_width : 2;
    Uint32 aid_strobe7_width : 2;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG91_REG;

/* This sets the number of ct intervals strobe0_valid signal is set.  0=one ct length, 1=two ct lengths, etc.  Should be set to minimum value possible because it sets the sample latency of the interface */
#define CSL_DFE_BB_CFG91_REG_AID_STROBE0_WIDTH_MASK (0x00000003u)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE0_WIDTH_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE0_WIDTH_RESETVAL (0x00000000u)

/* Sets the number of ct intervals strobe1_valid signal is set.  */
#define CSL_DFE_BB_CFG91_REG_AID_STROBE1_WIDTH_MASK (0x0000000Cu)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE1_WIDTH_SHIFT (0x00000002u)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE1_WIDTH_RESETVAL (0x00000000u)

/* Sets the number of ct intervals strobe2_valid signal is set.  */
#define CSL_DFE_BB_CFG91_REG_AID_STROBE2_WIDTH_MASK (0x00000030u)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE2_WIDTH_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE2_WIDTH_RESETVAL (0x00000000u)

/* Sets the number of ct intervals strobe3_valid signal is set.  */
#define CSL_DFE_BB_CFG91_REG_AID_STROBE3_WIDTH_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE3_WIDTH_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE3_WIDTH_RESETVAL (0x00000000u)

/* Sets the number of ct intervals strobe4_valid signal is set.  */
#define CSL_DFE_BB_CFG91_REG_AID_STROBE4_WIDTH_MASK (0x00000300u)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE4_WIDTH_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE4_WIDTH_RESETVAL (0x00000000u)

/* Sets the number of ct intervals strobe5_valid signal is set.  */
#define CSL_DFE_BB_CFG91_REG_AID_STROBE5_WIDTH_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE5_WIDTH_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE5_WIDTH_RESETVAL (0x00000000u)

/* Sets the number of ct intervals strobe6_valid signal is set.  */
#define CSL_DFE_BB_CFG91_REG_AID_STROBE6_WIDTH_MASK (0x00003000u)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE6_WIDTH_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE6_WIDTH_RESETVAL (0x00000000u)

/* Sets the number of ct intervals strobe7_valid signal is set.  */
#define CSL_DFE_BB_CFG91_REG_AID_STROBE7_WIDTH_MASK (0x0000C000u)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE7_WIDTH_SHIFT (0x0000000Eu)
#define CSL_DFE_BB_CFG91_REG_AID_STROBE7_WIDTH_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG91_REG_ADDR (0x0004036Cu)
#define CSL_DFE_BB_CFG91_REG_RESETVAL (0x00000000u)

/* CFG92 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ct3_ul_sync_strobe : 4;
    Uint32 ct2_ul_sync_strobe : 4;
    Uint32 ct1_ul_sync_strobe : 4;
    Uint32 ct0_ul_sync_strobe : 4;
#else 
    Uint32 ct0_ul_sync_strobe : 4;
    Uint32 ct1_ul_sync_strobe : 4;
    Uint32 ct2_ul_sync_strobe : 4;
    Uint32 ct3_ul_sync_strobe : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG92_REG;

/* Determines which input strobe is the sync for the carrier type 0 sync. */
#define CSL_DFE_BB_CFG92_REG_CT0_UL_SYNC_STROBE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG92_REG_CT0_UL_SYNC_STROBE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG92_REG_CT0_UL_SYNC_STROBE_RESETVAL (0x00000000u)

/* Determines which input strobe is the sync for the carrier type 1 sync. */
#define CSL_DFE_BB_CFG92_REG_CT1_UL_SYNC_STROBE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG92_REG_CT1_UL_SYNC_STROBE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG92_REG_CT1_UL_SYNC_STROBE_RESETVAL (0x00000000u)

/* Determines which input strobe is the sync for the carrier type 2 sync. */
#define CSL_DFE_BB_CFG92_REG_CT2_UL_SYNC_STROBE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG92_REG_CT2_UL_SYNC_STROBE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG92_REG_CT2_UL_SYNC_STROBE_RESETVAL (0x00000000u)

/* Determines which input strobe is the sync for the carrier type 3 sync. */
#define CSL_DFE_BB_CFG92_REG_CT3_UL_SYNC_STROBE_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG92_REG_CT3_UL_SYNC_STROBE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG92_REG_CT3_UL_SYNC_STROBE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG92_REG_ADDR (0x00040370u)
#define CSL_DFE_BB_CFG92_REG_RESETVAL (0x00000000u)

/* CFG93 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ct7_ul_sync_strobe : 4;
    Uint32 ct6_ul_sync_strobe : 4;
    Uint32 ct5_ul_sync_strobe : 4;
    Uint32 ct4_ul_sync_strobe : 4;
#else 
    Uint32 ct4_ul_sync_strobe : 4;
    Uint32 ct5_ul_sync_strobe : 4;
    Uint32 ct6_ul_sync_strobe : 4;
    Uint32 ct7_ul_sync_strobe : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG93_REG;

/* Determines which input strobe is the sync for the carrier type 4 sync. */
#define CSL_DFE_BB_CFG93_REG_CT4_UL_SYNC_STROBE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG93_REG_CT4_UL_SYNC_STROBE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG93_REG_CT4_UL_SYNC_STROBE_RESETVAL (0x00000000u)

/* Determines which input strobe is the sync for the carrier type 5 sync. */
#define CSL_DFE_BB_CFG93_REG_CT5_UL_SYNC_STROBE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG93_REG_CT5_UL_SYNC_STROBE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG93_REG_CT5_UL_SYNC_STROBE_RESETVAL (0x00000000u)

/* Determines which input strobe is the sync for the carrier type 6 sync. */
#define CSL_DFE_BB_CFG93_REG_CT6_UL_SYNC_STROBE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG93_REG_CT6_UL_SYNC_STROBE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG93_REG_CT6_UL_SYNC_STROBE_RESETVAL (0x00000000u)

/* Determines which input strobe is the sync for the carrier type 7 sync. */
#define CSL_DFE_BB_CFG93_REG_CT7_UL_SYNC_STROBE_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG93_REG_CT7_UL_SYNC_STROBE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG93_REG_CT7_UL_SYNC_STROBE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG93_REG_ADDR (0x00040374u)
#define CSL_DFE_BB_CFG93_REG_RESETVAL (0x00000000u)

/* CFG94 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ct11_ul_sync_strobe : 4;
    Uint32 ct10_ul_sync_strobe : 4;
    Uint32 ct9_ul_sync_strobe : 4;
    Uint32 ct8_ul_sync_strobe : 4;
#else 
    Uint32 ct8_ul_sync_strobe : 4;
    Uint32 ct9_ul_sync_strobe : 4;
    Uint32 ct10_ul_sync_strobe : 4;
    Uint32 ct11_ul_sync_strobe : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG94_REG;

/* Determines which input strobe is the sync for the carrier type 8 sync. */
#define CSL_DFE_BB_CFG94_REG_CT8_UL_SYNC_STROBE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG94_REG_CT8_UL_SYNC_STROBE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG94_REG_CT8_UL_SYNC_STROBE_RESETVAL (0x00000000u)

/* Determines which input strobe is the sync for the carrier type 9 sync. */
#define CSL_DFE_BB_CFG94_REG_CT9_UL_SYNC_STROBE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG94_REG_CT9_UL_SYNC_STROBE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG94_REG_CT9_UL_SYNC_STROBE_RESETVAL (0x00000000u)

/* Determines which input strobe is the sync for the carrier type 10 sync. */
#define CSL_DFE_BB_CFG94_REG_CT10_UL_SYNC_STROBE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG94_REG_CT10_UL_SYNC_STROBE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG94_REG_CT10_UL_SYNC_STROBE_RESETVAL (0x00000000u)

/* Determines which input strobe is the sync for the carrier type 11 sync. */
#define CSL_DFE_BB_CFG94_REG_CT11_UL_SYNC_STROBE_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG94_REG_CT11_UL_SYNC_STROBE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG94_REG_CT11_UL_SYNC_STROBE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG94_REG_ADDR (0x00040378u)
#define CSL_DFE_BB_CFG94_REG_RESETVAL (0x00000000u)

/* CFG95 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ct15_ul_sync_strobe : 4;
    Uint32 ct14_ul_sync_strobe : 4;
    Uint32 ct13_ul_sync_strobe : 4;
    Uint32 ct12_ul_sync_strobe : 4;
#else 
    Uint32 ct12_ul_sync_strobe : 4;
    Uint32 ct13_ul_sync_strobe : 4;
    Uint32 ct14_ul_sync_strobe : 4;
    Uint32 ct15_ul_sync_strobe : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG95_REG;

/* Determines which input strobe is the sync for the carrier type 12 sync. */
#define CSL_DFE_BB_CFG95_REG_CT12_UL_SYNC_STROBE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG95_REG_CT12_UL_SYNC_STROBE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG95_REG_CT12_UL_SYNC_STROBE_RESETVAL (0x00000000u)

/* Determines which input strobe is the sync for the carrier type 13 sync. */
#define CSL_DFE_BB_CFG95_REG_CT13_UL_SYNC_STROBE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG95_REG_CT13_UL_SYNC_STROBE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG95_REG_CT13_UL_SYNC_STROBE_RESETVAL (0x00000000u)

/* Determines which input strobe is the sync for the carrier type 14 sync. */
#define CSL_DFE_BB_CFG95_REG_CT14_UL_SYNC_STROBE_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG95_REG_CT14_UL_SYNC_STROBE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG95_REG_CT14_UL_SYNC_STROBE_RESETVAL (0x00000000u)

/* Determines which input strobe is the sync for the carrier type 15 sync. */
#define CSL_DFE_BB_CFG95_REG_CT15_UL_SYNC_STROBE_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG95_REG_CT15_UL_SYNC_STROBE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG95_REG_CT15_UL_SYNC_STROBE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG95_REG_ADDR (0x0004037Cu)
#define CSL_DFE_BB_CFG95_REG_RESETVAL (0x00000000u)

/* CFG96 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct0 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG96_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG96_REG_AID_ULSTROBE_DLY_CT0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG96_REG_AID_ULSTROBE_DLY_CT0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG96_REG_AID_ULSTROBE_DLY_CT0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG96_REG_ADDR (0x00040380u)
#define CSL_DFE_BB_CFG96_REG_RESETVAL (0x00000000u)

/* CFG97 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct1 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG97_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG97_REG_AID_ULSTROBE_DLY_CT1_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG97_REG_AID_ULSTROBE_DLY_CT1_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG97_REG_AID_ULSTROBE_DLY_CT1_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG97_REG_ADDR (0x00040384u)
#define CSL_DFE_BB_CFG97_REG_RESETVAL (0x00000000u)

/* CFG98 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct2 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG98_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG98_REG_AID_ULSTROBE_DLY_CT2_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG98_REG_AID_ULSTROBE_DLY_CT2_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG98_REG_AID_ULSTROBE_DLY_CT2_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG98_REG_ADDR (0x00040388u)
#define CSL_DFE_BB_CFG98_REG_RESETVAL (0x00000000u)

/* CFG99 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct3 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG99_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG99_REG_AID_ULSTROBE_DLY_CT3_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG99_REG_AID_ULSTROBE_DLY_CT3_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG99_REG_AID_ULSTROBE_DLY_CT3_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG99_REG_ADDR (0x0004038Cu)
#define CSL_DFE_BB_CFG99_REG_RESETVAL (0x00000000u)

/* CFG100 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct4 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct4 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG100_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG100_REG_AID_ULSTROBE_DLY_CT4_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG100_REG_AID_ULSTROBE_DLY_CT4_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG100_REG_AID_ULSTROBE_DLY_CT4_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG100_REG_ADDR (0x00040390u)
#define CSL_DFE_BB_CFG100_REG_RESETVAL (0x00000000u)

/* CFG101 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct5 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct5 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG101_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG101_REG_AID_ULSTROBE_DLY_CT5_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG101_REG_AID_ULSTROBE_DLY_CT5_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG101_REG_AID_ULSTROBE_DLY_CT5_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG101_REG_ADDR (0x00040394u)
#define CSL_DFE_BB_CFG101_REG_RESETVAL (0x00000000u)

/* CFG102 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct6 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct6 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG102_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG102_REG_AID_ULSTROBE_DLY_CT6_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG102_REG_AID_ULSTROBE_DLY_CT6_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG102_REG_AID_ULSTROBE_DLY_CT6_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG102_REG_ADDR (0x00040398u)
#define CSL_DFE_BB_CFG102_REG_RESETVAL (0x00000000u)

/* CFG103 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct7 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct7 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG103_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG103_REG_AID_ULSTROBE_DLY_CT7_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG103_REG_AID_ULSTROBE_DLY_CT7_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG103_REG_AID_ULSTROBE_DLY_CT7_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG103_REG_ADDR (0x0004039Cu)
#define CSL_DFE_BB_CFG103_REG_RESETVAL (0x00000000u)

/* CFG104 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct8 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct8 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG104_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG104_REG_AID_ULSTROBE_DLY_CT8_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG104_REG_AID_ULSTROBE_DLY_CT8_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG104_REG_AID_ULSTROBE_DLY_CT8_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG104_REG_ADDR (0x000403A0u)
#define CSL_DFE_BB_CFG104_REG_RESETVAL (0x00000000u)

/* CFG105 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct9 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct9 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG105_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG105_REG_AID_ULSTROBE_DLY_CT9_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG105_REG_AID_ULSTROBE_DLY_CT9_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG105_REG_AID_ULSTROBE_DLY_CT9_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG105_REG_ADDR (0x000403A4u)
#define CSL_DFE_BB_CFG105_REG_RESETVAL (0x00000000u)

/* CFG106 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct10 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct10 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG106_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG106_REG_AID_ULSTROBE_DLY_CT10_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG106_REG_AID_ULSTROBE_DLY_CT10_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG106_REG_AID_ULSTROBE_DLY_CT10_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG106_REG_ADDR (0x000403A8u)
#define CSL_DFE_BB_CFG106_REG_RESETVAL (0x00000000u)

/* CFG107 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct11 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct11 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG107_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG107_REG_AID_ULSTROBE_DLY_CT11_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG107_REG_AID_ULSTROBE_DLY_CT11_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG107_REG_AID_ULSTROBE_DLY_CT11_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG107_REG_ADDR (0x000403ACu)
#define CSL_DFE_BB_CFG107_REG_RESETVAL (0x00000000u)

/* CFG108 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct12 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct12 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG108_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG108_REG_AID_ULSTROBE_DLY_CT12_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG108_REG_AID_ULSTROBE_DLY_CT12_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG108_REG_AID_ULSTROBE_DLY_CT12_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG108_REG_ADDR (0x000403B0u)
#define CSL_DFE_BB_CFG108_REG_RESETVAL (0x00000000u)

/* CFG109 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct13 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct13 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG109_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG109_REG_AID_ULSTROBE_DLY_CT13_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG109_REG_AID_ULSTROBE_DLY_CT13_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG109_REG_AID_ULSTROBE_DLY_CT13_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG109_REG_ADDR (0x000403B4u)
#define CSL_DFE_BB_CFG109_REG_RESETVAL (0x00000000u)

/* CFG110 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct14 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct14 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG110_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG110_REG_AID_ULSTROBE_DLY_CT14_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG110_REG_AID_ULSTROBE_DLY_CT14_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG110_REG_AID_ULSTROBE_DLY_CT14_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG110_REG_ADDR (0x000403B8u)
#define CSL_DFE_BB_CFG110_REG_RESETVAL (0x00000000u)

/* CFG111 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 aid_ulstrobe_dly_ct15 : 16;
#else 
    Uint32 aid_ulstrobe_dly_ct15 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG111_REG;

/* Delay in carrier type samples from the UL_STROBE that UL FRAME_START shall be enabled on AID output. */
#define CSL_DFE_BB_CFG111_REG_AID_ULSTROBE_DLY_CT15_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG111_REG_AID_ULSTROBE_DLY_CT15_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG111_REG_AID_ULSTROBE_DLY_CT15_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG111_REG_ADDR (0x000403BCu)
#define CSL_DFE_BB_CFG111_REG_RESETVAL (0x00000000u)

/* CFG112 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 25;
    Uint32 aid_ul_axc_disable : 7;
#else 
    Uint32 aid_ul_axc_disable : 7;
    Uint32 rsvd0 : 25;
#endif 
} CSL_DFE_BB_CFG112_REG;

/* Mechanism to disable an AxC in the AID interface.   Bit 6 when high indicates an AxC is to be disabled;   Bit 5:0 indicates the AxC to be disabled. */
#define CSL_DFE_BB_CFG112_REG_AID_UL_AXC_DISABLE_MASK (0x0000007Fu)
#define CSL_DFE_BB_CFG112_REG_AID_UL_AXC_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG112_REG_AID_UL_AXC_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG112_REG_ADDR (0x000403C0u)
#define CSL_DFE_BB_CFG112_REG_RESETVAL (0x00000000u)

/* CFG119 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 rxnotch_tddmode : 1;
    Uint32 rxnotch_ct : 4;
    Uint32 rxnotch_ssel : 4;
#else 
    Uint32 rxnotch_ssel : 4;
    Uint32 rxnotch_ct : 4;
    Uint32 rxnotch_tddmode : 1;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_BB_CFG119_REG;

/* Update of rx notch filter configuration to active buffers.  Zero affected state memories */
#define CSL_DFE_BB_CFG119_REG_RXNOTCH_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG119_REG_RXNOTCH_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG119_REG_RXNOTCH_SSEL_RESETVAL (0x00000000u)

/* Carrier type to use as sync boundary for update of rx notch filter configuration to active buffers */
#define CSL_DFE_BB_CFG119_REG_RXNOTCH_CT_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG119_REG_RXNOTCH_CT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG119_REG_RXNOTCH_CT_RESETVAL (0x00000000u)

/* Tdd timer configuration used by rx notch filters.  0:disabled, 1: tdd enabled and freeze on DL */
#define CSL_DFE_BB_CFG119_REG_RXNOTCH_TDDMODE_MASK (0x00000100u)
#define CSL_DFE_BB_CFG119_REG_RXNOTCH_TDDMODE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG119_REG_RXNOTCH_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG119_REG_ADDR (0x000403DCu)
#define CSL_DFE_BB_CFG119_REG_RESETVAL (0x00000000u)

/* CFG120 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 antcal_interval_15_0 : 16;
#else 
    Uint32 antcal_interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG120_REG;

/* Number of samples to collect noise correlation values */
#define CSL_DFE_BB_CFG120_REG_ANTCAL_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG120_REG_ANTCAL_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG120_REG_ANTCAL_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG120_REG_ADDR (0x000403E0u)
#define CSL_DFE_BB_CFG120_REG_RESETVAL (0x00000000u)

/* CFG121 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 antcal_interval_31_16 : 8;
#else 
    Uint32 antcal_interval_31_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CFG121_REG;

/*  */
#define CSL_DFE_BB_CFG121_REG_ANTCAL_INTERVAL_31_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG121_REG_ANTCAL_INTERVAL_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG121_REG_ANTCAL_INTERVAL_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG121_REG_ADDR (0x000403E4u)
#define CSL_DFE_BB_CFG121_REG_RESETVAL (0x00000000u)

/* CFG122 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 antcal_rx_ssel : 4;
    Uint32 antcal_tx_ssel : 4;
    Uint32 antcal_rx_ct_sel : 4;
    Uint32 antcal_tx_ct_sel : 4;
#else 
    Uint32 antcal_tx_ct_sel : 4;
    Uint32 antcal_rx_ct_sel : 4;
    Uint32 antcal_tx_ssel : 4;
    Uint32 antcal_rx_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG122_REG;

/* Carrier type to use to start antcal noise.  Should be ct with maximum interval of active carriers being calibrated. */
#define CSL_DFE_BB_CFG122_REG_ANTCAL_TX_CT_SEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG122_REG_ANTCAL_TX_CT_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG122_REG_ANTCAL_TX_CT_SEL_RESETVAL (0x00000000u)

/* Carrier type to use to start antcal_interval.  Should be ct with maximum interval of active carriers being calibrated to minimize measurement error. */
#define CSL_DFE_BB_CFG122_REG_ANTCAL_RX_CT_SEL_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG122_REG_ANTCAL_RX_CT_SEL_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG122_REG_ANTCAL_RX_CT_SEL_RESETVAL (0x00000000u)

/* Sync select to start antenna calibration noise generation */
#define CSL_DFE_BB_CFG122_REG_ANTCAL_TX_SSEL_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG122_REG_ANTCAL_TX_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG122_REG_ANTCAL_TX_SSEL_RESETVAL (0x00000000u)

/* Sync select to start antenna calibration correlation.  Separate from tx so delay can be adjusted >255 samples. */
#define CSL_DFE_BB_CFG122_REG_ANTCAL_RX_SSEL_MASK (0x0000F000u)
#define CSL_DFE_BB_CFG122_REG_ANTCAL_RX_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_CFG122_REG_ANTCAL_RX_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG122_REG_ADDR (0x000403E8u)
#define CSL_DFE_BB_CFG122_REG_RESETVAL (0x00000000u)

/* CFG123 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 31;
    Uint32 antcal_en : 1;
#else 
    Uint32 antcal_en : 1;
    Uint32 rsvd0 : 31;
#endif 
} CSL_DFE_BB_CFG123_REG;

/* Enable of antenna calibration function.  Overrides individual AxC enables when disabled. */
#define CSL_DFE_BB_CFG123_REG_ANTCAL_EN_MASK (0x00000001u)
#define CSL_DFE_BB_CFG123_REG_ANTCAL_EN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG123_REG_ANTCAL_EN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG123_REG_ADDR (0x000403ECu)
#define CSL_DFE_BB_CFG123_REG_RESETVAL (0x00000000u)

/* CFG124 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t3interval1_23_16 : 8;
    Uint32 beagc_t3interval0_23_16 : 8;
#else 
    Uint32 beagc_t3interval0_23_16 : 8;
    Uint32 beagc_t3interval1_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG124_REG;

/* AGC master interval for  config 0.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval */
#define CSL_DFE_BB_CFG124_REG_BEAGC_T3INTERVAL0_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG124_REG_BEAGC_T3INTERVAL0_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG124_REG_BEAGC_T3INTERVAL0_23_16_RESETVAL (0x00000000u)

/* AGC master interval for  config 1.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval */
#define CSL_DFE_BB_CFG124_REG_BEAGC_T3INTERVAL1_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG124_REG_BEAGC_T3INTERVAL1_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG124_REG_BEAGC_T3INTERVAL1_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG124_REG_ADDR (0x000403F0u)
#define CSL_DFE_BB_CFG124_REG_RESETVAL (0x00000000u)

/* CFG125 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t3interval3_23_16 : 8;
    Uint32 beagc_t3interval2_23_16 : 8;
#else 
    Uint32 beagc_t3interval2_23_16 : 8;
    Uint32 beagc_t3interval3_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG125_REG;

/* AGC master interval for  config 2.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval */
#define CSL_DFE_BB_CFG125_REG_BEAGC_T3INTERVAL2_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG125_REG_BEAGC_T3INTERVAL2_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG125_REG_BEAGC_T3INTERVAL2_23_16_RESETVAL (0x00000000u)

/* AGC master interval for  config 3.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval */
#define CSL_DFE_BB_CFG125_REG_BEAGC_T3INTERVAL3_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG125_REG_BEAGC_T3INTERVAL3_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG125_REG_BEAGC_T3INTERVAL3_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG125_REG_ADDR (0x000403F4u)
#define CSL_DFE_BB_CFG125_REG_RESETVAL (0x00000000u)

/* CFG126 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t3interval5_23_16 : 8;
    Uint32 beagc_t3interval4_23_16 : 8;
#else 
    Uint32 beagc_t3interval4_23_16 : 8;
    Uint32 beagc_t3interval5_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG126_REG;

/* AGC master interval for  config 4.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval */
#define CSL_DFE_BB_CFG126_REG_BEAGC_T3INTERVAL4_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG126_REG_BEAGC_T3INTERVAL4_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG126_REG_BEAGC_T3INTERVAL4_23_16_RESETVAL (0x00000000u)

/* AGC master interval for  config 5.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval */
#define CSL_DFE_BB_CFG126_REG_BEAGC_T3INTERVAL5_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG126_REG_BEAGC_T3INTERVAL5_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG126_REG_BEAGC_T3INTERVAL5_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG126_REG_ADDR (0x000403F8u)
#define CSL_DFE_BB_CFG126_REG_RESETVAL (0x00000000u)

/* CFG127 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t3interval7_23_16 : 8;
    Uint32 beagc_t3interval6_23_16 : 8;
#else 
    Uint32 beagc_t3interval6_23_16 : 8;
    Uint32 beagc_t3interval7_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG127_REG;

/* AGC master interval for  config 6.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval */
#define CSL_DFE_BB_CFG127_REG_BEAGC_T3INTERVAL6_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG127_REG_BEAGC_T3INTERVAL6_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG127_REG_BEAGC_T3INTERVAL6_23_16_RESETVAL (0x00000000u)

/* AGC master interval for  config 7.  Each AxC attached to this interval has separate t1, t2 values within the t3 interval */
#define CSL_DFE_BB_CFG127_REG_BEAGC_T3INTERVAL7_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG127_REG_BEAGC_T3INTERVAL7_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG127_REG_BEAGC_T3INTERVAL7_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG127_REG_ADDR (0x000403FCu)
#define CSL_DFE_BB_CFG127_REG_RESETVAL (0x00000000u)

/* CFG_TXPM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM0_REG;

/* TX power meter 0 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM0_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM0_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM0_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 0 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM0_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM0_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM0_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 0 enable.  0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM0_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM0_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM0_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 0 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM0_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM0_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM0_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 0 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM0_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM0_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM0_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM0_REG_ADDR (0x00040400u)
#define CSL_DFE_BB_CFG_TXPM0_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM0_REG;

/* TX power meter 0 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM0_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM0_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM0_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM0_REG_ADDR (0x00040404u)
#define CSL_DFE_BB_SYNCDLY_TXPM0_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM0_REG;

/* TX power meter 0 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM0_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM0_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM0_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM0_REG_ADDR (0x00040408u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM0_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM0_REG;

/* TX power meter 0 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM0_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM0_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM0_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 0 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM0_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM0_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM0_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM0_REG_ADDR (0x0004040Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM0_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM0_REG;

/* TX power meter 0 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM0_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM0_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM0_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM0_REG_ADDR (0x00040410u)
#define CSL_DFE_BB_PD_LO_TXPM0_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM0_REG;

/* TX power meter 0 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM0_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM0_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM0_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 0 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM0_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM0_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM0_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM0_REG_ADDR (0x00040414u)
#define CSL_DFE_BB_SYNC_PWR_TXPM0_REG_RESETVAL (0x00000000u)

/* CFG_TXPM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM1_REG;

/* TX power meter 1 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM1_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM1_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM1_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 1 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM1_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM1_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM1_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 1 enable. 0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM1_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM1_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM1_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 1 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM1_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM1_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM1_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 1 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM1_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM1_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM1_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM1_REG_ADDR (0x00040420u)
#define CSL_DFE_BB_CFG_TXPM1_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM1_REG;

/* TX power meter 1 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM1_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM1_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM1_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM1_REG_ADDR (0x00040424u)
#define CSL_DFE_BB_SYNCDLY_TXPM1_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM1_REG;

/* TX power meter 1 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM1_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM1_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM1_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM1_REG_ADDR (0x00040428u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM1_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM1_REG;

/* TX power meter 1 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM1_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM1_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM1_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 1 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM1_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM1_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM1_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM1_REG_ADDR (0x0004042Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM1_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM1_REG;

/* TX power meter 1 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM1_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM1_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM1_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM1_REG_ADDR (0x00040430u)
#define CSL_DFE_BB_PD_LO_TXPM1_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM1_REG;

/* TX power meter 1 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM1_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM1_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM1_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 1 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM1_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM1_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM1_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM1_REG_ADDR (0x00040434u)
#define CSL_DFE_BB_SYNC_PWR_TXPM1_REG_RESETVAL (0x00000000u)

/* CFG_TXPM2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM2_REG;

/* TX power meter 2 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM2_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM2_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM2_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 2 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM2_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM2_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM2_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 2 enable.  0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM2_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM2_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM2_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 2 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM2_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM2_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM2_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 2 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM2_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM2_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM2_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM2_REG_ADDR (0x00040440u)
#define CSL_DFE_BB_CFG_TXPM2_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM2_REG;

/* TX power meter 2 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM2_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM2_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM2_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM2_REG_ADDR (0x00040444u)
#define CSL_DFE_BB_SYNCDLY_TXPM2_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM2_REG;

/* TX power meter 2 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM2_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM2_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM2_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM2_REG_ADDR (0x00040448u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM2_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM2_REG;

/* TX power meter 2 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM2_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM2_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM2_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 2 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM2_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM2_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM2_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM2_REG_ADDR (0x0004044Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM2_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM2_REG;

/* TX power meter 2 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM2_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM2_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM2_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM2_REG_ADDR (0x00040450u)
#define CSL_DFE_BB_PD_LO_TXPM2_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM2_REG;

/* TX power meter 2 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM2_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM2_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM2_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 2 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM2_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM2_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM2_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM2_REG_ADDR (0x00040454u)
#define CSL_DFE_BB_SYNC_PWR_TXPM2_REG_RESETVAL (0x00000000u)

/* CFG_TXPM3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM3_REG;

/* TX power meter 3 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM3_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM3_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM3_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 3 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM3_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM3_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM3_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 3 enable. 0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM3_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM3_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM3_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 3 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM3_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM3_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM3_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 3 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM3_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM3_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM3_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM3_REG_ADDR (0x00040460u)
#define CSL_DFE_BB_CFG_TXPM3_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM3_REG;

/* TX power meter 3 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM3_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM3_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM3_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM3_REG_ADDR (0x00040464u)
#define CSL_DFE_BB_SYNCDLY_TXPM3_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM3_REG;

/* TX power meter 3 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM3_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM3_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM3_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM3_REG_ADDR (0x00040468u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM3_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM3_REG;

/* TX power meter 3 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM3_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM3_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM3_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 3 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM3_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM3_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM3_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM3_REG_ADDR (0x0004046Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM3_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM3_REG;

/* TX power meter 3 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM3_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM3_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM3_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM3_REG_ADDR (0x00040470u)
#define CSL_DFE_BB_PD_LO_TXPM3_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM3_REG;

/* TX power meter 3 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM3_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM3_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM3_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 3 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM3_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM3_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM3_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM3_REG_ADDR (0x00040474u)
#define CSL_DFE_BB_SYNC_PWR_TXPM3_REG_RESETVAL (0x00000000u)

/* CFG_TXPM4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM4_REG;

/* TX power meter 4 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM4_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM4_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM4_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 4 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM4_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM4_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM4_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 4 enable. 0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM4_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM4_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM4_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 4 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM4_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM4_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM4_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 4 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM4_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM4_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM4_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM4_REG_ADDR (0x00040480u)
#define CSL_DFE_BB_CFG_TXPM4_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM4_REG;

/* TX power meter 4 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM4_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM4_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM4_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM4_REG_ADDR (0x00040484u)
#define CSL_DFE_BB_SYNCDLY_TXPM4_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM4_REG;

/* TX power meter 4 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM4_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM4_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM4_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM4_REG_ADDR (0x00040488u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM4_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM4_REG;

/* TX power meter 4 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM4_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM4_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM4_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 4 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM4_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM4_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM4_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM4_REG_ADDR (0x0004048Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM4_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM4_REG;

/* TX power meter 4 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM4_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM4_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM4_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM4_REG_ADDR (0x00040490u)
#define CSL_DFE_BB_PD_LO_TXPM4_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM4_REG;

/* TX power meter 4 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM4_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM4_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM4_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 4 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM4_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM4_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM4_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM4_REG_ADDR (0x00040494u)
#define CSL_DFE_BB_SYNC_PWR_TXPM4_REG_RESETVAL (0x00000000u)

/* CFG_TXPM5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM5_REG;

/* TX power meter 5 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM5_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM5_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM5_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 5 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM5_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM5_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM5_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 5 enable. 0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM5_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM5_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM5_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 5 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM5_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM5_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM5_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 5 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM5_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM5_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM5_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM5_REG_ADDR (0x000404A0u)
#define CSL_DFE_BB_CFG_TXPM5_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM5_REG;

/* TX power meter 5 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM5_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM5_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM5_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM5_REG_ADDR (0x000404A4u)
#define CSL_DFE_BB_SYNCDLY_TXPM5_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM5_REG;

/* TX power meter 5 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM5_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM5_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM5_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM5_REG_ADDR (0x000404A8u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM5_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM5_REG;

/* TX power meter 5 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM5_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM5_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM5_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 5 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM5_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM5_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM5_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM5_REG_ADDR (0x000404ACu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM5_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM5_REG;

/* TX power meter 5 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM5_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM5_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM5_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM5_REG_ADDR (0x000404B0u)
#define CSL_DFE_BB_PD_LO_TXPM5_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM5_REG;

/* TX power meter 5 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM5_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM5_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM5_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 5 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM5_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM5_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM5_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM5_REG_ADDR (0x000404B4u)
#define CSL_DFE_BB_SYNC_PWR_TXPM5_REG_RESETVAL (0x00000000u)

/* CFG_TXPM6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM6_REG;

/* TX power meter 6 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM6_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM6_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM6_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 6 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM6_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM6_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM6_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 6 enable. 0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM6_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM6_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM6_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 6 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM6_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM6_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM6_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 6 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM6_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM6_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM6_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM6_REG_ADDR (0x000404C0u)
#define CSL_DFE_BB_CFG_TXPM6_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM6_REG;

/* TX power meter 6 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM6_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM6_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM6_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM6_REG_ADDR (0x000404C4u)
#define CSL_DFE_BB_SYNCDLY_TXPM6_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM6_REG;

/* TX power meter 6 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM6_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM6_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM6_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM6_REG_ADDR (0x000404C8u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM6_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM6_REG;

/* TX power meter 6 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM6_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM6_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM6_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 6 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM6_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM6_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM6_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM6_REG_ADDR (0x000404CCu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM6_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM6_REG;

/* TX power meter 6 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM6_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM6_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM6_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM6_REG_ADDR (0x000404D0u)
#define CSL_DFE_BB_PD_LO_TXPM6_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM6_REG;

/* TX power meter 6 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM6_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM6_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM6_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 6 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM6_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM6_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM6_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM6_REG_ADDR (0x000404D4u)
#define CSL_DFE_BB_SYNC_PWR_TXPM6_REG_RESETVAL (0x00000000u)

/* CFG_TXPM7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM7_REG;

/* TX power meter 7 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM7_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM7_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM7_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 7 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM7_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM7_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM7_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 7 enable.  0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM7_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM7_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM7_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 7 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM7_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM7_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM7_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 7 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM7_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM7_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM7_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM7_REG_ADDR (0x000404E0u)
#define CSL_DFE_BB_CFG_TXPM7_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM7_REG;

/* TX power meter 7 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM7_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM7_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM7_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM7_REG_ADDR (0x000404E4u)
#define CSL_DFE_BB_SYNCDLY_TXPM7_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM7_REG;

/* TX power meter 7 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM7_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM7_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM7_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM7_REG_ADDR (0x000404E8u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM7_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM7_REG;

/* TX power meter 7 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM7_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM7_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM7_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 7 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM7_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM7_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM7_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM7_REG_ADDR (0x000404ECu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM7_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM7_REG;

/* TX power meter 7 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM7_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM7_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM7_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM7_REG_ADDR (0x000404F0u)
#define CSL_DFE_BB_PD_LO_TXPM7_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM7_REG;

/* TX power meter 7 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM7_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM7_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM7_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 7 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM7_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM7_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM7_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM7_REG_ADDR (0x000404F4u)
#define CSL_DFE_BB_SYNC_PWR_TXPM7_REG_RESETVAL (0x00000000u)

/* CFG_TXPM8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM8_REG;

/* TX power meter 8 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM8_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM8_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM8_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 8 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM8_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM8_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM8_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 8 enable.  0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM8_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM8_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM8_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 8 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM8_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM8_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM8_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 8 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM8_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM8_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM8_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM8_REG_ADDR (0x00040500u)
#define CSL_DFE_BB_CFG_TXPM8_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM8_REG;

/* TX power meter 8 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM8_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM8_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM8_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM8_REG_ADDR (0x00040504u)
#define CSL_DFE_BB_SYNCDLY_TXPM8_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM8_REG;

/* TX power meter 8 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM8_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM8_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM8_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM8_REG_ADDR (0x00040508u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM8_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM8_REG;

/* TX power meter 8 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM8_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM8_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM8_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 8 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM8_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM8_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM8_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM8_REG_ADDR (0x0004050Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM8_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM8_REG;

/* TX power meter 8 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM8_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM8_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM8_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM8_REG_ADDR (0x00040510u)
#define CSL_DFE_BB_PD_LO_TXPM8_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM8_REG;

/* TX power meter 8 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM8_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM8_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM8_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 8 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM8_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM8_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM8_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM8_REG_ADDR (0x00040514u)
#define CSL_DFE_BB_SYNC_PWR_TXPM8_REG_RESETVAL (0x00000000u)

/* CFG_TXPM9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM9_REG;

/* TX power meter 9 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM9_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM9_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM9_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 9 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM9_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM9_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM9_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 9 enable. 0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM9_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM9_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM9_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 9 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM9_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM9_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM9_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 9 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM9_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM9_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM9_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM9_REG_ADDR (0x00040520u)
#define CSL_DFE_BB_CFG_TXPM9_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM9_REG;

/* TX power meter 9 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM9_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM9_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM9_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM9_REG_ADDR (0x00040524u)
#define CSL_DFE_BB_SYNCDLY_TXPM9_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM9_REG;

/* TX power meter 9 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM9_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM9_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM9_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM9_REG_ADDR (0x00040528u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM9_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM9_REG;

/* TX power meter 9 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM9_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM9_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM9_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 9 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM9_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM9_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM9_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM9_REG_ADDR (0x0004052Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM9_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM9_REG;

/* TX power meter 9 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM9_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM9_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM9_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM9_REG_ADDR (0x00040530u)
#define CSL_DFE_BB_PD_LO_TXPM9_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM9_REG;

/* TX power meter 9 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM9_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM9_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM9_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 9 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM9_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM9_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM9_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM9_REG_ADDR (0x00040534u)
#define CSL_DFE_BB_SYNC_PWR_TXPM9_REG_RESETVAL (0x00000000u)

/* CFG_TXPM10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM10_REG;

/* TX power meter 10 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM10_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM10_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM10_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 10output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM10_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM10_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM10_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 10 enable.  0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM10_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM10_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM10_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 10 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM10_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM10_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM10_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 10 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM10_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM10_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM10_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM10_REG_ADDR (0x00040540u)
#define CSL_DFE_BB_CFG_TXPM10_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM10_REG;

/* TX power meter 10 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM10_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM10_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM10_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM10_REG_ADDR (0x00040544u)
#define CSL_DFE_BB_SYNCDLY_TXPM10_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM10_REG;

/* TX power meter 10 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM10_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM10_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM10_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM10_REG_ADDR (0x00040548u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM10_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM10_REG;

/* TX power meter 10 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM10_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM10_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM10_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 10 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM10_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM10_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM10_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM10_REG_ADDR (0x0004054Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM10_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM10_REG;

/* TX power meter 10 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM10_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM10_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM10_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM10_REG_ADDR (0x00040550u)
#define CSL_DFE_BB_PD_LO_TXPM10_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM10_REG;

/* TX power meter 10 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM10_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM10_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM10_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 10 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM10_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM10_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM10_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM10_REG_ADDR (0x00040554u)
#define CSL_DFE_BB_SYNC_PWR_TXPM10_REG_RESETVAL (0x00000000u)

/* CFG_TXPM11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM11_REG;

/* TX power meter 11 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM11_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM11_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM11_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 11 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM11_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM11_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM11_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 11 enable. 0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM11_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM11_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM11_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 11 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM11_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM11_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM11_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 11 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM11_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM11_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM11_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM11_REG_ADDR (0x00040560u)
#define CSL_DFE_BB_CFG_TXPM11_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM11_REG;

/* TX power meter 11 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM11_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM11_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM11_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM11_REG_ADDR (0x00040564u)
#define CSL_DFE_BB_SYNCDLY_TXPM11_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM11_REG;

/* TX power meter 11 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM11_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM11_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM11_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM11_REG_ADDR (0x00040568u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM11_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM11_REG;

/* TX power meter 11 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM11_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM11_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM11_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 11 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM11_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM11_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM11_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM11_REG_ADDR (0x0004056Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM11_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM11_REG;

/* TX power meter 11 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM11_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM11_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM11_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM11_REG_ADDR (0x00040570u)
#define CSL_DFE_BB_PD_LO_TXPM11_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM11_REG;

/* TX power meter 11 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM11_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM11_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM11_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 11 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM11_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM11_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM11_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM11_REG_ADDR (0x00040574u)
#define CSL_DFE_BB_SYNC_PWR_TXPM11_REG_RESETVAL (0x00000000u)

/* CFG_TXPM12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM12_REG;

/* TX power meter 12 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM12_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM12_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM12_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 12 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM12_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM12_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM12_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 12 enable.  0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM12_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM12_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM12_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 12 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM12_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM12_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM12_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 12 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM12_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM12_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM12_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM12_REG_ADDR (0x00040580u)
#define CSL_DFE_BB_CFG_TXPM12_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM12_REG;

/* TX power meter 12 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM12_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM12_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM12_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM12_REG_ADDR (0x00040584u)
#define CSL_DFE_BB_SYNCDLY_TXPM12_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM12_REG;

/* TX power meter 12 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM12_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM12_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM12_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM12_REG_ADDR (0x00040588u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM12_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM12_REG;

/* TX power meter 12 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM12_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM12_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM12_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 12 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM12_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM12_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM12_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM12_REG_ADDR (0x0004058Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM12_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM12_REG;

/* TX power meter 12 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM12_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM12_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM12_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM12_REG_ADDR (0x00040590u)
#define CSL_DFE_BB_PD_LO_TXPM12_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM12_REG;

/* TX power meter 12 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM12_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM12_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM12_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 12 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM12_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM12_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM12_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM12_REG_ADDR (0x00040594u)
#define CSL_DFE_BB_SYNC_PWR_TXPM12_REG_RESETVAL (0x00000000u)

/* CFG_TXPM13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM13_REG;

/* TX power meter 13 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM13_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM13_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM13_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 13 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM13_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM13_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM13_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 13 enable. 0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM13_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM13_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM13_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 13 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM13_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM13_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM13_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 13 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM13_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM13_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM13_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM13_REG_ADDR (0x000405A0u)
#define CSL_DFE_BB_CFG_TXPM13_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM13_REG;

/* TX power meter 13 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM13_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM13_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM13_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM13_REG_ADDR (0x000405A4u)
#define CSL_DFE_BB_SYNCDLY_TXPM13_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM13_REG;

/* TX power meter 13 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM13_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM13_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM13_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM13_REG_ADDR (0x000405A8u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM13_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM13_REG;

/* TX power meter 13 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM13_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM13_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM13_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 13 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM13_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM13_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM13_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM13_REG_ADDR (0x000405ACu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM13_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM13_REG;

/* TX power meter 13 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM13_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM13_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM13_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM13_REG_ADDR (0x000405B0u)
#define CSL_DFE_BB_PD_LO_TXPM13_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM13_REG;

/* TX power meter 13 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM13_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM13_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM13_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 13 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM13_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM13_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM13_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM13_REG_ADDR (0x000405B4u)
#define CSL_DFE_BB_SYNC_PWR_TXPM13_REG_RESETVAL (0x00000000u)

/* CFG_TXPM14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM14_REG;

/* TX power meter 14 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM14_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM14_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM14_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 14 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM14_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM14_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM14_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 14 enable.  0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM14_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM14_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM14_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 14 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM14_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM14_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM14_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 14 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM14_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM14_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM14_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM14_REG_ADDR (0x000405C0u)
#define CSL_DFE_BB_CFG_TXPM14_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM14_REG;

/* TX power meter 14 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM14_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM14_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM14_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM14_REG_ADDR (0x000405C4u)
#define CSL_DFE_BB_SYNCDLY_TXPM14_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM14_REG;

/* TX power meter 14 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM14_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM14_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM14_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM14_REG_ADDR (0x000405C8u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM14_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM14_REG;

/* TX power meter 14 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM14_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM14_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM14_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 14 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM14_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM14_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM14_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM14_REG_ADDR (0x000405CCu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM14_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM14_REG;

/* TX power meter 14 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM14_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM14_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM14_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM14_REG_ADDR (0x000405D0u)
#define CSL_DFE_BB_PD_LO_TXPM14_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM14_REG;

/* TX power meter 14 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM14_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM14_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM14_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 14 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM14_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM14_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM14_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM14_REG_ADDR (0x000405D4u)
#define CSL_DFE_BB_SYNC_PWR_TXPM14_REG_RESETVAL (0x00000000u)

/* CFG_TXPM15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_TXPM15_REG;

/* TX power meter 15 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_TXPM15_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_TXPM15_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_TXPM15_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 15 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_TXPM15_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_TXPM15_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_TXPM15_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* TX power meter 15 enable.  0=0ff, 1=single power measurement, 2=single power update interval, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_TXPM15_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_TXPM15_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_TXPM15_REG_ENABLE_RESETVAL (0x00000000u)

/* TX power meter 15 input source. 0=input, 1=output, 2=gain output */
#define CSL_DFE_BB_CFG_TXPM15_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_TXPM15_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_TXPM15_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* TX power meter 15 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_TXPM15_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_TXPM15_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_TXPM15_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_TXPM15_REG_ADDR (0x000405E0u)
#define CSL_DFE_BB_CFG_TXPM15_REG_RESETVAL (0x00000000u)

/* SYNCDLY_TXPM15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_TXPM15_REG;

/* TX power meter 15 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_TXPM15_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_TXPM15_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_TXPM15_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_TXPM15_REG_ADDR (0x000405E4u)
#define CSL_DFE_BB_SYNCDLY_TXPM15_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_TXPM15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_TXPM15_REG;

/* TX power meter 15 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_TXPM15_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_TXPM15_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM15_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_TXPM15_REG_ADDR (0x000405E8u)
#define CSL_DFE_BB_INTERVAL_LO_TXPM15_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_TXPM15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_TXPM15_REG;

/* TX power meter 15 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM15_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM15_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM15_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* TX power meter 15 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM15_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM15_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM15_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_TXPM15_REG_ADDR (0x000405ECu)
#define CSL_DFE_BB_PDINTERVAL_HI_TXPM15_REG_RESETVAL (0x00000000u)

/* PD_LO_TXPM15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_TXPM15_REG;

/* TX power meter 15 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_TXPM15_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_TXPM15_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_TXPM15_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_TXPM15_REG_ADDR (0x000405F0u)
#define CSL_DFE_BB_PD_LO_TXPM15_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_TXPM15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_TXPM15_REG;

/* TX power meter 15 measurement count */
#define CSL_DFE_BB_SYNC_PWR_TXPM15_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_TXPM15_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_TXPM15_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* TX power meter 15 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_TXPM15_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_TXPM15_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_TXPM15_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_TXPM15_REG_ADDR (0x000405F4u)
#define CSL_DFE_BB_SYNC_PWR_TXPM15_REG_RESETVAL (0x00000000u)

/* TXPM_UPDATE_DISABLE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 update_disable : 16;
#else 
    Uint32 update_disable : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_TXPM_UPDATE_DISABLE_REG;

/* One bit per interval timer, when set, disables the corresponding TX power meter from being able to write to the TX power meter results register.  MPU can only write to results register when update_disable is asserted for all bits. */
#define CSL_DFE_BB_TXPM_UPDATE_DISABLE_REG_UPDATE_DISABLE_MASK (0x0000FFFFu)
#define CSL_DFE_BB_TXPM_UPDATE_DISABLE_REG_UPDATE_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_TXPM_UPDATE_DISABLE_REG_UPDATE_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_TXPM_UPDATE_DISABLE_REG_ADDR (0x000405FCu)
#define CSL_DFE_BB_TXPM_UPDATE_DISABLE_REG_RESETVAL (0x00000000u)

/* TXPM_AUXINT_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 auxint_mask : 16;
#else 
    Uint32 auxint_mask : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_TXPM_AUXINT_MASK_REG;

/* One bit per power meter, when set, enables the corresponding TX power meter to generate an interrupt to the CPP state machines */
#define CSL_DFE_BB_TXPM_AUXINT_MASK_REG_AUXINT_MASK_MASK (0x0000FFFFu)
#define CSL_DFE_BB_TXPM_AUXINT_MASK_REG_AUXINT_MASK_SHIFT (0x00000000u)
#define CSL_DFE_BB_TXPM_AUXINT_MASK_REG_AUXINT_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_BB_TXPM_AUXINT_MASK_REG_ADDR (0x00040600u)
#define CSL_DFE_BB_TXPM_AUXINT_MASK_REG_RESETVAL (0x00000000u)

/* CFG_RXPM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM0_REG;

/* RX power meter 0 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM0_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM0_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM0_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 0 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM0_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM0_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM0_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 0 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM0_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM0_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM0_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 0 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM0_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM0_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM0_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 0 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM0_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM0_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM0_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM0_REG_ADDR (0x00040800u)
#define CSL_DFE_BB_CFG_RXPM0_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM0_REG;

/* RX power meter 0 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM0_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM0_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM0_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM0_REG_ADDR (0x00040804u)
#define CSL_DFE_BB_SYNCDLY_RXPM0_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM0_REG;

/* RX power meter 0 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM0_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM0_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM0_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM0_REG_ADDR (0x00040808u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM0_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM0_REG;

/* RX power meter 0 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM0_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM0_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM0_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 0 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM0_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM0_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM0_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM0_REG_ADDR (0x0004080Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM0_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM0_REG;

/* RX power meter 0 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM0_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM0_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM0_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM0_REG_ADDR (0x00040810u)
#define CSL_DFE_BB_PD_LO_RXPM0_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM0_REG;

/* RX power meter 0 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM0_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM0_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM0_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 0 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM0_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM0_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM0_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM0_REG_ADDR (0x00040814u)
#define CSL_DFE_BB_SYNC_PWR_RXPM0_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB0_REG;

/* RX power meter 0 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB0_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB0_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB0_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB0_REG_ADDR (0x00040818u)
#define CSL_DFE_BB_RXPM_MAX_DB0_REG_RESETVAL (0x00000000u)

/* CFG_RXPM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM1_REG;

/* RX power meter 1 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM1_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM1_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM1_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 1 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM1_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM1_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM1_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 1 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM1_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM1_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM1_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 1 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM1_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM1_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM1_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 1 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM1_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM1_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM1_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM1_REG_ADDR (0x00040820u)
#define CSL_DFE_BB_CFG_RXPM1_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM1_REG;

/* RX power meter 1 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM1_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM1_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM1_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM1_REG_ADDR (0x00040824u)
#define CSL_DFE_BB_SYNCDLY_RXPM1_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM1_REG;

/* RX power meter 1 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM1_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM1_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM1_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM1_REG_ADDR (0x00040828u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM1_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM1_REG;

/* RX power meter 1 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM1_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM1_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM1_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 1 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM1_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM1_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM1_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM1_REG_ADDR (0x0004082Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM1_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM1_REG;

/* RX power meter 1 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM1_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM1_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM1_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM1_REG_ADDR (0x00040830u)
#define CSL_DFE_BB_PD_LO_RXPM1_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM1_REG;

/* RX power meter 1 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM1_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM1_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM1_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 1 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM1_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM1_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM1_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM1_REG_ADDR (0x00040834u)
#define CSL_DFE_BB_SYNC_PWR_RXPM1_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB1_REG;

/* RX power meter 1 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB1_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB1_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB1_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB1_REG_ADDR (0x00040838u)
#define CSL_DFE_BB_RXPM_MAX_DB1_REG_RESETVAL (0x00000000u)

/* CFG_RXPM2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM2_REG;

/* RX power meter 2 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM2_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM2_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM2_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 2 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM2_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM2_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM2_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 2 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM2_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM2_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM2_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 2 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM2_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM2_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM2_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 2 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM2_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM2_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM2_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM2_REG_ADDR (0x00040840u)
#define CSL_DFE_BB_CFG_RXPM2_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM2_REG;

/* RX power meter 2 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM2_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM2_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM2_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM2_REG_ADDR (0x00040844u)
#define CSL_DFE_BB_SYNCDLY_RXPM2_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM2_REG;

/* RX power meter 2 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM2_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM2_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM2_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM2_REG_ADDR (0x00040848u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM2_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM2_REG;

/* RX power meter 2 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM2_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM2_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM2_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 2 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM2_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM2_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM2_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM2_REG_ADDR (0x0004084Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM2_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM2_REG;

/* RX power meter 2 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM2_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM2_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM2_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM2_REG_ADDR (0x00040850u)
#define CSL_DFE_BB_PD_LO_RXPM2_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM2_REG;

/* RX power meter 2 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM2_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM2_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM2_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 2 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM2_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM2_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM2_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM2_REG_ADDR (0x00040854u)
#define CSL_DFE_BB_SYNC_PWR_RXPM2_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB2_REG;

/* RX power meter 2 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB2_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB2_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB2_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB2_REG_ADDR (0x00040858u)
#define CSL_DFE_BB_RXPM_MAX_DB2_REG_RESETVAL (0x00000000u)

/* CFG_RXPM3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM3_REG;

/* RX power meter 3 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM3_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM3_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM3_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 3 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM3_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM3_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM3_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 3 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM3_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM3_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM3_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 3 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM3_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM3_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM3_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 3 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM3_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM3_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM3_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM3_REG_ADDR (0x00040860u)
#define CSL_DFE_BB_CFG_RXPM3_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM3_REG;

/* RX power meter 3 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM3_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM3_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM3_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM3_REG_ADDR (0x00040864u)
#define CSL_DFE_BB_SYNCDLY_RXPM3_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM3_REG;

/* RX power meter 3 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM3_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM3_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM3_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM3_REG_ADDR (0x00040868u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM3_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM3_REG;

/* RX power meter 3 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM3_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM3_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM3_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 3 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM3_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM3_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM3_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM3_REG_ADDR (0x0004086Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM3_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM3_REG;

/* RX power meter 3 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM3_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM3_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM3_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM3_REG_ADDR (0x00040870u)
#define CSL_DFE_BB_PD_LO_RXPM3_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM3_REG;

/* RX power meter 3 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM3_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM3_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM3_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 3 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM3_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM3_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM3_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM3_REG_ADDR (0x00040874u)
#define CSL_DFE_BB_SYNC_PWR_RXPM3_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB3_REG;

/* RX power meter 3 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB3_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB3_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB3_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB3_REG_ADDR (0x00040878u)
#define CSL_DFE_BB_RXPM_MAX_DB3_REG_RESETVAL (0x00000000u)

/* CFG_RXPM4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM4_REG;

/* RX power meter 4 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM4_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM4_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM4_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 4 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM4_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM4_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM4_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 4 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM4_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM4_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM4_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 4 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM4_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM4_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM4_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 4 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM4_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM4_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM4_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM4_REG_ADDR (0x00040880u)
#define CSL_DFE_BB_CFG_RXPM4_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM4_REG;

/* RX power meter 4 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM4_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM4_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM4_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM4_REG_ADDR (0x00040884u)
#define CSL_DFE_BB_SYNCDLY_RXPM4_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM4_REG;

/* RX power meter 4 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM4_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM4_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM4_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM4_REG_ADDR (0x00040888u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM4_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM4_REG;

/* RX power meter 4 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM4_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM4_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM4_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 4 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM4_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM4_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM4_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM4_REG_ADDR (0x0004088Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM4_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM4_REG;

/* RX power meter 4 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM4_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM4_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM4_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM4_REG_ADDR (0x00040890u)
#define CSL_DFE_BB_PD_LO_RXPM4_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM4_REG;

/* RX power meter 4 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM4_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM4_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM4_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 4 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM4_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM4_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM4_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM4_REG_ADDR (0x00040894u)
#define CSL_DFE_BB_SYNC_PWR_RXPM4_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB4_REG;

/* RX power meter 4 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB4_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB4_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB4_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB4_REG_ADDR (0x00040898u)
#define CSL_DFE_BB_RXPM_MAX_DB4_REG_RESETVAL (0x00000000u)

/* CFG_RXPM5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM5_REG;

/* RX power meter 5 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM5_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM5_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM5_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 5 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM5_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM5_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM5_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 5 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM5_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM5_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM5_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 5 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM5_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM5_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM5_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 5 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM5_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM5_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM5_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM5_REG_ADDR (0x000408A0u)
#define CSL_DFE_BB_CFG_RXPM5_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM5_REG;

/* RX power meter 5 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM5_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM5_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM5_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM5_REG_ADDR (0x000408A4u)
#define CSL_DFE_BB_SYNCDLY_RXPM5_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM5_REG;

/* RX power meter 5 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM5_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM5_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM5_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM5_REG_ADDR (0x000408A8u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM5_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM5_REG;

/* RX power meter 5 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM5_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM5_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM5_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 5 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM5_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM5_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM5_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM5_REG_ADDR (0x000408ACu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM5_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM5_REG;

/* RX power meter 5 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM5_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM5_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM5_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM5_REG_ADDR (0x000408B0u)
#define CSL_DFE_BB_PD_LO_RXPM5_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM5_REG;

/* RX power meter 5 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM5_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM5_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM5_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 5 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM5_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM5_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM5_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM5_REG_ADDR (0x000408B4u)
#define CSL_DFE_BB_SYNC_PWR_RXPM5_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB5_REG;

/* RX power meter 5 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB5_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB5_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB5_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB5_REG_ADDR (0x000408B8u)
#define CSL_DFE_BB_RXPM_MAX_DB5_REG_RESETVAL (0x00000000u)

/* CFG_RXPM6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM6_REG;

/* RX power meter 6 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM6_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM6_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM6_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 6 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM6_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM6_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM6_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 6 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM6_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM6_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM6_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 6 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM6_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM6_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM6_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 6 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM6_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM6_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM6_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM6_REG_ADDR (0x000408C0u)
#define CSL_DFE_BB_CFG_RXPM6_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM6_REG;

/* RX power meter 6 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM6_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM6_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM6_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM6_REG_ADDR (0x000408C4u)
#define CSL_DFE_BB_SYNCDLY_RXPM6_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM6_REG;

/* RX power meter 6 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM6_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM6_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM6_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM6_REG_ADDR (0x000408C8u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM6_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM6_REG;

/* RX power meter 6 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM6_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM6_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM6_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 6 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM6_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM6_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM6_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM6_REG_ADDR (0x000408CCu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM6_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM6_REG;

/* RX power meter 6 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM6_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM6_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM6_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM6_REG_ADDR (0x000408D0u)
#define CSL_DFE_BB_PD_LO_RXPM6_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM6_REG;

/* RX power meter 6 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM6_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM6_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM6_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 6 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM6_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM6_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM6_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM6_REG_ADDR (0x000408D4u)
#define CSL_DFE_BB_SYNC_PWR_RXPM6_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB6_REG;

/* RX power meter 6 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB6_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB6_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB6_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB6_REG_ADDR (0x000408D8u)
#define CSL_DFE_BB_RXPM_MAX_DB6_REG_RESETVAL (0x00000000u)

/* CFG_RXPM7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM7_REG;

/* RX power meter 7 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM7_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM7_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM7_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 7 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM7_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM7_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM7_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 7 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM7_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM7_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM7_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 7 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM7_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM7_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM7_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 7 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM7_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM7_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM7_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM7_REG_ADDR (0x000408E0u)
#define CSL_DFE_BB_CFG_RXPM7_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM7_REG;

/* RX power meter 7 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM7_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM7_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM7_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM7_REG_ADDR (0x000408E4u)
#define CSL_DFE_BB_SYNCDLY_RXPM7_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM7_REG;

/* RX power meter 7 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM7_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM7_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM7_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM7_REG_ADDR (0x000408E8u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM7_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM7_REG;

/* RX power meter 7 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM7_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM7_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM7_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 7 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM7_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM7_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM7_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM7_REG_ADDR (0x000408ECu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM7_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM7_REG;

/* RX power meter 7 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM7_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM7_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM7_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM7_REG_ADDR (0x000408F0u)
#define CSL_DFE_BB_PD_LO_RXPM7_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM7_REG;

/* RX power meter 7 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM7_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM7_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM7_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 7 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM7_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM7_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM7_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM7_REG_ADDR (0x000408F4u)
#define CSL_DFE_BB_SYNC_PWR_RXPM7_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB7_REG;

/* RX power meter 7 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB7_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB7_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB7_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB7_REG_ADDR (0x000408F8u)
#define CSL_DFE_BB_RXPM_MAX_DB7_REG_RESETVAL (0x00000000u)

/* CFG_RXPM8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM8_REG;

/* RX power meter 8 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM8_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM8_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM8_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 8 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM8_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM8_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM8_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 8 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM8_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM8_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM8_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 8 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM8_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM8_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM8_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 8 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM8_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM8_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM8_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM8_REG_ADDR (0x00040900u)
#define CSL_DFE_BB_CFG_RXPM8_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM8_REG;

/* RX power meter 8 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM8_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM8_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM8_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM8_REG_ADDR (0x00040904u)
#define CSL_DFE_BB_SYNCDLY_RXPM8_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM8_REG;

/* RX power meter 8 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM8_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM8_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM8_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM8_REG_ADDR (0x00040908u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM8_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM8_REG;

/* RX power meter 8 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM8_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM8_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM8_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 8 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM8_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM8_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM8_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM8_REG_ADDR (0x0004090Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM8_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM8_REG;

/* RX power meter 8 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM8_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM8_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM8_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM8_REG_ADDR (0x00040910u)
#define CSL_DFE_BB_PD_LO_RXPM8_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM8_REG;

/* RX power meter 8 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM8_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM8_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM8_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 8 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM8_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM8_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM8_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM8_REG_ADDR (0x00040914u)
#define CSL_DFE_BB_SYNC_PWR_RXPM8_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB8_REG;

/* RX power meter 8 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB8_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB8_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB8_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB8_REG_ADDR (0x00040918u)
#define CSL_DFE_BB_RXPM_MAX_DB8_REG_RESETVAL (0x00000000u)

/* CFG_RXPM9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM9_REG;

/* RX power meter 9 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM9_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM9_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM9_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 9 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM9_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM9_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM9_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 9 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM9_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM9_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM9_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 9 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM9_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM9_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM9_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 9 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM9_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM9_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM9_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM9_REG_ADDR (0x00040920u)
#define CSL_DFE_BB_CFG_RXPM9_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM9_REG;

/* RX power meter 9 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM9_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM9_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM9_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM9_REG_ADDR (0x00040924u)
#define CSL_DFE_BB_SYNCDLY_RXPM9_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM9_REG;

/* RX power meter 9 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM9_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM9_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM9_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM9_REG_ADDR (0x00040928u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM9_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM9_REG;

/* RX power meter 9 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM9_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM9_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM9_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 9 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM9_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM9_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM9_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM9_REG_ADDR (0x0004092Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM9_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM9_REG;

/* RX power meter 9 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM9_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM9_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM9_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM9_REG_ADDR (0x00040930u)
#define CSL_DFE_BB_PD_LO_RXPM9_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM9_REG;

/* RX power meter 9 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM9_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM9_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM9_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 9 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM9_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM9_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM9_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM9_REG_ADDR (0x00040934u)
#define CSL_DFE_BB_SYNC_PWR_RXPM9_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB9_REG;

/* RX power meter 9 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB9_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB9_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB9_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB9_REG_ADDR (0x00040938u)
#define CSL_DFE_BB_RXPM_MAX_DB9_REG_RESETVAL (0x00000000u)

/* CFG_RXPM10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM10_REG;

/* RX power meter 10 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM10_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM10_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM10_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 10output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM10_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM10_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM10_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 10 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM10_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM10_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM10_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 10 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM10_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM10_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM10_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 10 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM10_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM10_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM10_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM10_REG_ADDR (0x00040940u)
#define CSL_DFE_BB_CFG_RXPM10_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM10_REG;

/* RX power meter 10 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM10_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM10_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM10_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM10_REG_ADDR (0x00040944u)
#define CSL_DFE_BB_SYNCDLY_RXPM10_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM10_REG;

/* RX power meter 10 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM10_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM10_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM10_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM10_REG_ADDR (0x00040948u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM10_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM10_REG;

/* RX power meter 10 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM10_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM10_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM10_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 10 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM10_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM10_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM10_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM10_REG_ADDR (0x0004094Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM10_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM10_REG;

/* RX power meter 10 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM10_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM10_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM10_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM10_REG_ADDR (0x00040950u)
#define CSL_DFE_BB_PD_LO_RXPM10_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM10_REG;

/* RX power meter 10 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM10_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM10_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM10_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 10 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM10_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM10_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM10_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM10_REG_ADDR (0x00040954u)
#define CSL_DFE_BB_SYNC_PWR_RXPM10_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB10_REG;

/* RX power meter 10 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB10_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB10_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB10_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB10_REG_ADDR (0x00040958u)
#define CSL_DFE_BB_RXPM_MAX_DB10_REG_RESETVAL (0x00000000u)

/* CFG_RXPM11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM11_REG;

/* RX power meter 11 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM11_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM11_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM11_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 11 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM11_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM11_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM11_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 11 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM11_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM11_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM11_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 11 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM11_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM11_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM11_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 11 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM11_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM11_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM11_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM11_REG_ADDR (0x00040960u)
#define CSL_DFE_BB_CFG_RXPM11_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM11_REG;

/* RX power meter 11 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM11_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM11_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM11_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM11_REG_ADDR (0x00040964u)
#define CSL_DFE_BB_SYNCDLY_RXPM11_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM11_REG;

/* RX power meter 11 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM11_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM11_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM11_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM11_REG_ADDR (0x00040968u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM11_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM11_REG;

/* RX power meter 11 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM11_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM11_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM11_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 11 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM11_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM11_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM11_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM11_REG_ADDR (0x0004096Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM11_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM11_REG;

/* RX power meter 11 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM11_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM11_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM11_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM11_REG_ADDR (0x00040970u)
#define CSL_DFE_BB_PD_LO_RXPM11_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM11_REG;

/* RX power meter 11 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM11_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM11_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM11_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 11 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM11_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM11_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM11_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM11_REG_ADDR (0x00040974u)
#define CSL_DFE_BB_SYNC_PWR_RXPM11_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB11_REG;

/* RX power meter 11 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB11_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB11_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB11_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB11_REG_ADDR (0x00040978u)
#define CSL_DFE_BB_RXPM_MAX_DB11_REG_RESETVAL (0x00000000u)

/* CFG_RXPM12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM12_REG;

/* RX power meter 12 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM12_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM12_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM12_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 12 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM12_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM12_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM12_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 12 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM12_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM12_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM12_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 12 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM12_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM12_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM12_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 12 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM12_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM12_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM12_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM12_REG_ADDR (0x00040980u)
#define CSL_DFE_BB_CFG_RXPM12_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM12_REG;

/* RX power meter 12 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM12_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM12_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM12_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM12_REG_ADDR (0x00040984u)
#define CSL_DFE_BB_SYNCDLY_RXPM12_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM12_REG;

/* RX power meter 12 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM12_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM12_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM12_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM12_REG_ADDR (0x00040988u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM12_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM12_REG;

/* RX power meter 12 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM12_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM12_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM12_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 12 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM12_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM12_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM12_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM12_REG_ADDR (0x0004098Cu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM12_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM12_REG;

/* RX power meter 12 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM12_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM12_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM12_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM12_REG_ADDR (0x00040990u)
#define CSL_DFE_BB_PD_LO_RXPM12_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM12_REG;

/* RX power meter 12 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM12_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM12_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM12_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 12 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM12_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM12_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM12_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM12_REG_ADDR (0x00040994u)
#define CSL_DFE_BB_SYNC_PWR_RXPM12_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB12_REG;

/* RX power meter 12 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB12_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB12_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB12_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB12_REG_ADDR (0x00040998u)
#define CSL_DFE_BB_RXPM_MAX_DB12_REG_RESETVAL (0x00000000u)

/* CFG_RXPM13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM13_REG;

/* RX power meter 13 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM13_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM13_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM13_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 13 output format.  0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM13_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM13_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM13_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 13 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM13_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM13_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM13_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 13 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM13_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM13_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM13_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 13 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM13_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM13_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM13_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM13_REG_ADDR (0x000409A0u)
#define CSL_DFE_BB_CFG_RXPM13_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM13_REG;

/* RX power meter 13 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM13_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM13_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM13_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM13_REG_ADDR (0x000409A4u)
#define CSL_DFE_BB_SYNCDLY_RXPM13_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM13_REG;

/* RX power meter 13 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM13_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM13_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM13_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM13_REG_ADDR (0x000409A8u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM13_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM13_REG;

/* RX power meter 13 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM13_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM13_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM13_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 13 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM13_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM13_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM13_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM13_REG_ADDR (0x000409ACu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM13_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM13_REG;

/* RX power meter 13 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM13_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM13_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM13_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM13_REG_ADDR (0x000409B0u)
#define CSL_DFE_BB_PD_LO_RXPM13_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM13_REG;

/* RX power meter 13 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM13_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM13_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM13_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 13 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM13_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM13_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM13_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM13_REG_ADDR (0x000409B4u)
#define CSL_DFE_BB_SYNC_PWR_RXPM13_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB13_REG;

/* RX power meter 13 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB13_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB13_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB13_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB13_REG_ADDR (0x000409B8u)
#define CSL_DFE_BB_RXPM_MAX_DB13_REG_RESETVAL (0x00000000u)

/* CFG_RXPM14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM14_REG;

/* RX power meter 14 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM14_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM14_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM14_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 14 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM14_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM14_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM14_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 14 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM14_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM14_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM14_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 14 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM14_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM14_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM14_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 14 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM14_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM14_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM14_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM14_REG_ADDR (0x000409C0u)
#define CSL_DFE_BB_CFG_RXPM14_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM14_REG;

/* RX power meter 14 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM14_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM14_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM14_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM14_REG_ADDR (0x000409C4u)
#define CSL_DFE_BB_SYNCDLY_RXPM14_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM14_REG;

/* RX power meter 14 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM14_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM14_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM14_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM14_REG_ADDR (0x000409C8u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM14_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM14_REG;

/* RX power meter 14 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM14_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM14_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM14_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 14 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM14_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM14_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM14_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM14_REG_ADDR (0x000409CCu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM14_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM14_REG;

/* RX power meter 14 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM14_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM14_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM14_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM14_REG_ADDR (0x000409D0u)
#define CSL_DFE_BB_PD_LO_RXPM14_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM14_REG;

/* RX power meter 14 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM14_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM14_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM14_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 14 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM14_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM14_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM14_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM14_REG_ADDR (0x000409D4u)
#define CSL_DFE_BB_SYNC_PWR_RXPM14_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB14_REG;

/* RX power meter 14 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB14_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB14_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB14_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB14_REG_ADDR (0x000409D8u)
#define CSL_DFE_BB_RXPM_MAX_DB14_REG_RESETVAL (0x00000000u)

/* CFG_RXPM15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 tddmode : 2;
    Uint32 in_source : 2;
    Uint32 enable : 2;
    Uint32 out_format : 2;
    Uint32 count_source : 4;
#else 
    Uint32 count_source : 4;
    Uint32 out_format : 2;
    Uint32 enable : 2;
    Uint32 in_source : 2;
    Uint32 tddmode : 2;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG_RXPM15_REG;

/* RX power meter 15 carrier type count.  Selects which carrier type interval counter is the basic incrementer for the measurement counter. */
#define CSL_DFE_BB_CFG_RXPM15_REG_COUNT_SOURCE_MASK (0x0000000Fu)
#define CSL_DFE_BB_CFG_RXPM15_REG_COUNT_SOURCE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG_RXPM15_REG_COUNT_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 15 output format.   0, 1=floating point 10.16bit mantissa, 6bit exponent, 2=dB from 0 in 0.1dB units, 3=unused */
#define CSL_DFE_BB_CFG_RXPM15_REG_OUT_FORMAT_MASK (0x00000030u)
#define CSL_DFE_BB_CFG_RXPM15_REG_OUT_FORMAT_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG_RXPM15_REG_OUT_FORMAT_RESETVAL (0x00000000u)

/* RX power meter 15 enable.  0=0ff, 1=single power measurement, 2=reserved, 3=continuous power measurement operation */
#define CSL_DFE_BB_CFG_RXPM15_REG_ENABLE_MASK (0x000000C0u)
#define CSL_DFE_BB_CFG_RXPM15_REG_ENABLE_SHIFT (0x00000006u)
#define CSL_DFE_BB_CFG_RXPM15_REG_ENABLE_RESETVAL (0x00000000u)

/* RX power meter 15 input source. 0=input, 1=output, 2=rx filter output */
#define CSL_DFE_BB_CFG_RXPM15_REG_IN_SOURCE_MASK (0x00000300u)
#define CSL_DFE_BB_CFG_RXPM15_REG_IN_SOURCE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG_RXPM15_REG_IN_SOURCE_RESETVAL (0x00000000u)

/* RX power meter 15 tdd timer config 0=disabled, 2=tdd halt on UL, 3= tdd reset on UL */
#define CSL_DFE_BB_CFG_RXPM15_REG_TDDMODE_MASK (0x00000C00u)
#define CSL_DFE_BB_CFG_RXPM15_REG_TDDMODE_SHIFT (0x0000000Au)
#define CSL_DFE_BB_CFG_RXPM15_REG_TDDMODE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG_RXPM15_REG_ADDR (0x000409E0u)
#define CSL_DFE_BB_CFG_RXPM15_REG_RESETVAL (0x00000000u)

/* SYNCDLY_RXPM15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_dly_15_0 : 16;
#else 
    Uint32 sync_dly_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SYNCDLY_RXPM15_REG;

/* RX power meter 15 delay after sync event */
#define CSL_DFE_BB_SYNCDLY_RXPM15_REG_SYNC_DLY_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SYNCDLY_RXPM15_REG_SYNC_DLY_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNCDLY_RXPM15_REG_SYNC_DLY_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNCDLY_RXPM15_REG_ADDR (0x000409E4u)
#define CSL_DFE_BB_SYNCDLY_RXPM15_REG_RESETVAL (0x00000000u)

/* INTERVAL_LO_RXPM15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTERVAL_LO_RXPM15_REG;

/* RX power meter 15 interval time LSBs, in frame rate */
#define CSL_DFE_BB_INTERVAL_LO_RXPM15_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTERVAL_LO_RXPM15_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM15_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTERVAL_LO_RXPM15_REG_ADDR (0x000409E8u)
#define CSL_DFE_BB_INTERVAL_LO_RXPM15_REG_RESETVAL (0x00000000u)

/* PDINTERVAL_HI_RXPM15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_23_16 : 8;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 intg_pd_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PDINTERVAL_HI_RXPM15_REG;

/* RX power meter 15 interval time MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM15_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM15_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM15_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

/* RX power meter 15 integration period MSBs, in frame rate */
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM15_REG_INTG_PD_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM15_REG_INTG_PD_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM15_REG_INTG_PD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PDINTERVAL_HI_RXPM15_REG_ADDR (0x000409ECu)
#define CSL_DFE_BB_PDINTERVAL_HI_RXPM15_REG_RESETVAL (0x00000000u)

/* PD_LO_RXPM15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 intg_pd_15_0 : 16;
#else 
    Uint32 intg_pd_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_PD_LO_RXPM15_REG;

/* RX power meter 15 integration period LSBs, in frame rate */
#define CSL_DFE_BB_PD_LO_RXPM15_REG_INTG_PD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_PD_LO_RXPM15_REG_INTG_PD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_PD_LO_RXPM15_REG_INTG_PD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_PD_LO_RXPM15_REG_ADDR (0x000409F0u)
#define CSL_DFE_BB_PD_LO_RXPM15_REG_RESETVAL (0x00000000u)

/* SYNC_PWR_RXPM15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd0 : 1;
    Uint32 pwr_update : 7;
#else 
    Uint32 pwr_update : 7;
    Uint32 rsvd0 : 1;
    Uint32 sync_dly_23_16 : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_BB_SYNC_PWR_RXPM15_REG;

/* RX power meter 15 measurement count */
#define CSL_DFE_BB_SYNC_PWR_RXPM15_REG_PWR_UPDATE_MASK (0x0000007Fu)
#define CSL_DFE_BB_SYNC_PWR_RXPM15_REG_PWR_UPDATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SYNC_PWR_RXPM15_REG_PWR_UPDATE_RESETVAL (0x00000000u)

/* RX power meter 15 delay after sync event */
#define CSL_DFE_BB_SYNC_PWR_RXPM15_REG_SYNC_DLY_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_SYNC_PWR_RXPM15_REG_SYNC_DLY_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_SYNC_PWR_RXPM15_REG_SYNC_DLY_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SYNC_PWR_RXPM15_REG_ADDR (0x000409F4u)
#define CSL_DFE_BB_SYNC_PWR_RXPM15_REG_RESETVAL (0x00000000u)

/* RXPM_MAX_DB15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 max_db : 12;
#else 
    Uint32 max_db : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXPM_MAX_DB15_REG;

/* RX power meter 15 maximum dB value assuming full power of power interval */
#define CSL_DFE_BB_RXPM_MAX_DB15_REG_MAX_DB_MASK (0x00000FFFu)
#define CSL_DFE_BB_RXPM_MAX_DB15_REG_MAX_DB_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_MAX_DB15_REG_MAX_DB_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_MAX_DB15_REG_ADDR (0x000409F8u)
#define CSL_DFE_BB_RXPM_MAX_DB15_REG_RESETVAL (0x00000000u)

/* RXPM_UPDATE_DISABLE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 update_disable : 16;
#else 
    Uint32 update_disable : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_RXPM_UPDATE_DISABLE_REG;

/* One bit per interval timer, when set, disables the corresponding RX power meter from being able to write to the RX power meter results register.  MPU can only write to results register when update_disable is asserted for all bits. */
#define CSL_DFE_BB_RXPM_UPDATE_DISABLE_REG_UPDATE_DISABLE_MASK (0x0000FFFFu)
#define CSL_DFE_BB_RXPM_UPDATE_DISABLE_REG_UPDATE_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_UPDATE_DISABLE_REG_UPDATE_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_UPDATE_DISABLE_REG_ADDR (0x000409FCu)
#define CSL_DFE_BB_RXPM_UPDATE_DISABLE_REG_RESETVAL (0x00000000u)

/* RXPM_AUXINT_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 auxint_mask : 16;
#else 
    Uint32 auxint_mask : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_RXPM_AUXINT_MASK_REG;

/* One bit per power meter, when set, enables the corresponding RX power meter to generate an interrupt to the CPP state machines */
#define CSL_DFE_BB_RXPM_AUXINT_MASK_REG_AUXINT_MASK_MASK (0x0000FFFFu)
#define CSL_DFE_BB_RXPM_AUXINT_MASK_REG_AUXINT_MASK_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXPM_AUXINT_MASK_REG_AUXINT_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXPM_AUXINT_MASK_REG_ADDR (0x00040A00u)
#define CSL_DFE_BB_RXPM_AUXINT_MASK_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN0_CTRL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 stable_len : 12;
    Uint32 dduc_spare0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 dduc_spare0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN0_CTRL0_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_BB_SIGNAL_GEN0_CTRL0_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN0_CTRL0_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN0_CTRL0_REG_MODE_RESETVAL (0x00000000u)

/* spare pins */
#define CSL_DFE_BB_SIGNAL_GEN0_CTRL0_REG_DDUC_SPARE0_MASK (0x0000000Eu)
#define CSL_DFE_BB_SIGNAL_GEN0_CTRL0_REG_DDUC_SPARE0_SHIFT (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN0_CTRL0_REG_DDUC_SPARE0_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_BB_SIGNAL_GEN0_CTRL0_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_BB_SIGNAL_GEN0_CTRL0_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_BB_SIGNAL_GEN0_CTRL0_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN0_CTRL0_REG_ADDR (0x00040C00u)
#define CSL_DFE_BB_SIGNAL_GEN0_CTRL0_REG_RESETVAL (0x00000000u)

/* CK_DDUC0_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC0_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_BB_CK_DDUC0_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC0_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC0_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC0_SIGNAL_LEN_REG_ADDR (0x00040C04u)
#define CSL_DFE_BB_CK_DDUC0_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CK_DDUC0_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 chan_sel : 12;
#else 
    Uint32 chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CK_DDUC0_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_BB_CK_DDUC0_CHAN_SEL_REG_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_BB_CK_DDUC0_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC0_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC0_CHAN_SEL_REG_ADDR (0x00040C08u)
#define CSL_DFE_BB_CK_DDUC0_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CK_DDUC0_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC0_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC0_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC0_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC0_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC0_RESULT_LO_REG_ADDR (0x00040C0Cu)
#define CSL_DFE_BB_CK_DDUC0_RESULT_LO_REG_RESETVAL (0x00000000u)

/* CK_DDUC0_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC0_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC0_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC0_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC0_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC0_RESULT_HI_REG_ADDR (0x00040C10u)
#define CSL_DFE_BB_CK_DDUC0_RESULT_HI_REG_RESETVAL (0x00000000u)

/* CK_DDUC0_DDUC0_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 sig_gen_ssel : 4;
    Uint32 chksum_ssel : 4;
#else 
    Uint32 chksum_ssel : 4;
    Uint32 sig_gen_ssel : 4;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CK_DDUC0_DDUC0_SSEL_REG;

/* sync select for check sum module */
#define CSL_DFE_BB_CK_DDUC0_DDUC0_SSEL_REG_CHKSUM_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CK_DDUC0_DDUC0_SSEL_REG_CHKSUM_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC0_DDUC0_SSEL_REG_CHKSUM_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator module */
#define CSL_DFE_BB_CK_DDUC0_DDUC0_SSEL_REG_SIG_GEN_SSEL_MASK (0x000000F0u)
#define CSL_DFE_BB_CK_DDUC0_DDUC0_SSEL_REG_SIG_GEN_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_BB_CK_DDUC0_DDUC0_SSEL_REG_SIG_GEN_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC0_DDUC0_SSEL_REG_ADDR (0x00040C14u)
#define CSL_DFE_BB_CK_DDUC0_DDUC0_SSEL_REG_RESETVAL (0x00000000u)

/* GCCK_DDUC0_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_ADDR (0x00040C18u)
#define CSL_DFE_BB_GCCK_DDUC0_GENERAL_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN0_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN0_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_START_LO_REG_ADDR (0x00040C1Cu)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN0_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN0_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_START_HI_REG_ADDR (0x00040C20u)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN0_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN0_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_STOP_LO_REG_ADDR (0x00040C24u)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN0_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN0_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_STOP_HI_REG_ADDR (0x00040C28u)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN0_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN0_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_SLOPE_LO_REG_ADDR (0x00040C2Cu)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN0_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN0_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_SLOPE_HI_REG_ADDR (0x00040C30u)
#define CSL_DFE_BB_SIGNAL_GEN0_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN0_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN0_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_BB_SIGNAL_GEN0_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN0_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN0_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN0_GEN_TIMER_REG_ADDR (0x00040C34u)
#define CSL_DFE_BB_SIGNAL_GEN0_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN1_CTRL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 stable_len : 12;
    Uint32 dduc_spare0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 dduc_spare0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN1_CTRL0_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_BB_SIGNAL_GEN1_CTRL0_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN1_CTRL0_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN1_CTRL0_REG_MODE_RESETVAL (0x00000000u)

/* spare pins */
#define CSL_DFE_BB_SIGNAL_GEN1_CTRL0_REG_DDUC_SPARE0_MASK (0x0000000Eu)
#define CSL_DFE_BB_SIGNAL_GEN1_CTRL0_REG_DDUC_SPARE0_SHIFT (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN1_CTRL0_REG_DDUC_SPARE0_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_BB_SIGNAL_GEN1_CTRL0_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_BB_SIGNAL_GEN1_CTRL0_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_BB_SIGNAL_GEN1_CTRL0_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN1_CTRL0_REG_ADDR (0x00040C40u)
#define CSL_DFE_BB_SIGNAL_GEN1_CTRL0_REG_RESETVAL (0x00000000u)

/* CK_DDUC1_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC1_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_BB_CK_DDUC1_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC1_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC1_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC1_SIGNAL_LEN_REG_ADDR (0x00040C44u)
#define CSL_DFE_BB_CK_DDUC1_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CK_DDUC1_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 chan_sel : 12;
#else 
    Uint32 chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CK_DDUC1_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_BB_CK_DDUC1_CHAN_SEL_REG_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_BB_CK_DDUC1_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC1_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC1_CHAN_SEL_REG_ADDR (0x00040C48u)
#define CSL_DFE_BB_CK_DDUC1_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CK_DDUC1_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC1_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC1_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC1_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC1_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC1_RESULT_LO_REG_ADDR (0x00040C4Cu)
#define CSL_DFE_BB_CK_DDUC1_RESULT_LO_REG_RESETVAL (0x00000000u)

/* CK_DDUC1_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC1_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC1_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC1_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC1_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC1_RESULT_HI_REG_ADDR (0x00040C50u)
#define CSL_DFE_BB_CK_DDUC1_RESULT_HI_REG_RESETVAL (0x00000000u)

/* CK_DDUC1_DDUC1_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 sig_gen_ssel : 4;
    Uint32 chksum_ssel : 4;
#else 
    Uint32 chksum_ssel : 4;
    Uint32 sig_gen_ssel : 4;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CK_DDUC1_DDUC1_SSEL_REG;

/* sync select for check sum module */
#define CSL_DFE_BB_CK_DDUC1_DDUC1_SSEL_REG_CHKSUM_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CK_DDUC1_DDUC1_SSEL_REG_CHKSUM_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC1_DDUC1_SSEL_REG_CHKSUM_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator module */
#define CSL_DFE_BB_CK_DDUC1_DDUC1_SSEL_REG_SIG_GEN_SSEL_MASK (0x000000F0u)
#define CSL_DFE_BB_CK_DDUC1_DDUC1_SSEL_REG_SIG_GEN_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_BB_CK_DDUC1_DDUC1_SSEL_REG_SIG_GEN_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC1_DDUC1_SSEL_REG_ADDR (0x00040C54u)
#define CSL_DFE_BB_CK_DDUC1_DDUC1_SSEL_REG_RESETVAL (0x00000000u)

/* GCCK_DDUC1_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_ADDR (0x00040C58u)
#define CSL_DFE_BB_GCCK_DDUC1_GENERAL_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN1_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN1_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_START_LO_REG_ADDR (0x00040C5Cu)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN1_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN1_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_START_HI_REG_ADDR (0x00040C60u)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN1_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN1_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_STOP_LO_REG_ADDR (0x00040C64u)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN1_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN1_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_STOP_HI_REG_ADDR (0x00040C68u)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN1_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN1_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_SLOPE_LO_REG_ADDR (0x00040C6Cu)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN1_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN1_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_SLOPE_HI_REG_ADDR (0x00040C70u)
#define CSL_DFE_BB_SIGNAL_GEN1_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN1_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN1_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_BB_SIGNAL_GEN1_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN1_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN1_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN1_GEN_TIMER_REG_ADDR (0x00040C74u)
#define CSL_DFE_BB_SIGNAL_GEN1_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN2_CTRL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 stable_len : 12;
    Uint32 dduc_spare0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 dduc_spare0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN2_CTRL0_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_BB_SIGNAL_GEN2_CTRL0_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN2_CTRL0_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN2_CTRL0_REG_MODE_RESETVAL (0x00000000u)

/* spare pins */
#define CSL_DFE_BB_SIGNAL_GEN2_CTRL0_REG_DDUC_SPARE0_MASK (0x0000000Eu)
#define CSL_DFE_BB_SIGNAL_GEN2_CTRL0_REG_DDUC_SPARE0_SHIFT (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN2_CTRL0_REG_DDUC_SPARE0_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_BB_SIGNAL_GEN2_CTRL0_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_BB_SIGNAL_GEN2_CTRL0_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_BB_SIGNAL_GEN2_CTRL0_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN2_CTRL0_REG_ADDR (0x00040C80u)
#define CSL_DFE_BB_SIGNAL_GEN2_CTRL0_REG_RESETVAL (0x00000000u)

/* CK_DDUC2_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC2_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_BB_CK_DDUC2_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC2_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC2_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC2_SIGNAL_LEN_REG_ADDR (0x00040C84u)
#define CSL_DFE_BB_CK_DDUC2_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CK_DDUC2_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 chan_sel : 12;
#else 
    Uint32 chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CK_DDUC2_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_BB_CK_DDUC2_CHAN_SEL_REG_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_BB_CK_DDUC2_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC2_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC2_CHAN_SEL_REG_ADDR (0x00040C88u)
#define CSL_DFE_BB_CK_DDUC2_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CK_DDUC2_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC2_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC2_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC2_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC2_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC2_RESULT_LO_REG_ADDR (0x00040C8Cu)
#define CSL_DFE_BB_CK_DDUC2_RESULT_LO_REG_RESETVAL (0x00000000u)

/* CK_DDUC2_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC2_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC2_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC2_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC2_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC2_RESULT_HI_REG_ADDR (0x00040C90u)
#define CSL_DFE_BB_CK_DDUC2_RESULT_HI_REG_RESETVAL (0x00000000u)

/* CK_DDUC2_DDUC0_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 sig_gen_ssel : 4;
    Uint32 chksum_ssel : 4;
#else 
    Uint32 chksum_ssel : 4;
    Uint32 sig_gen_ssel : 4;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CK_DDUC2_DDUC0_SSEL_REG;

/* sync select for check sum module */
#define CSL_DFE_BB_CK_DDUC2_DDUC0_SSEL_REG_CHKSUM_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CK_DDUC2_DDUC0_SSEL_REG_CHKSUM_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC2_DDUC0_SSEL_REG_CHKSUM_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator module */
#define CSL_DFE_BB_CK_DDUC2_DDUC0_SSEL_REG_SIG_GEN_SSEL_MASK (0x000000F0u)
#define CSL_DFE_BB_CK_DDUC2_DDUC0_SSEL_REG_SIG_GEN_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_BB_CK_DDUC2_DDUC0_SSEL_REG_SIG_GEN_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC2_DDUC0_SSEL_REG_ADDR (0x00040C94u)
#define CSL_DFE_BB_CK_DDUC2_DDUC0_SSEL_REG_RESETVAL (0x00000000u)

/* GCCK_DDUC2_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_ADDR (0x00040C98u)
#define CSL_DFE_BB_GCCK_DDUC2_GENERAL_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN2_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN2_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_START_LO_REG_ADDR (0x00040C9Cu)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN2_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN2_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_START_HI_REG_ADDR (0x00040CA0u)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN2_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN2_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_STOP_LO_REG_ADDR (0x00040CA4u)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN2_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN2_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_STOP_HI_REG_ADDR (0x00040CA8u)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN2_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN2_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_SLOPE_LO_REG_ADDR (0x00040CACu)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN2_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN2_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_SLOPE_HI_REG_ADDR (0x00040CB0u)
#define CSL_DFE_BB_SIGNAL_GEN2_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN2_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN2_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_BB_SIGNAL_GEN2_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN2_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN2_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN2_GEN_TIMER_REG_ADDR (0x00040CB4u)
#define CSL_DFE_BB_SIGNAL_GEN2_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN3_CTRL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 stable_len : 12;
    Uint32 dduc_spare0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 dduc_spare0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN3_CTRL0_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_BB_SIGNAL_GEN3_CTRL0_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN3_CTRL0_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN3_CTRL0_REG_MODE_RESETVAL (0x00000000u)

/* spare pins */
#define CSL_DFE_BB_SIGNAL_GEN3_CTRL0_REG_DDUC_SPARE0_MASK (0x0000000Eu)
#define CSL_DFE_BB_SIGNAL_GEN3_CTRL0_REG_DDUC_SPARE0_SHIFT (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN3_CTRL0_REG_DDUC_SPARE0_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_BB_SIGNAL_GEN3_CTRL0_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_BB_SIGNAL_GEN3_CTRL0_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_BB_SIGNAL_GEN3_CTRL0_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN3_CTRL0_REG_ADDR (0x00040CC0u)
#define CSL_DFE_BB_SIGNAL_GEN3_CTRL0_REG_RESETVAL (0x00000000u)

/* CK_DDUC3_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC3_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_BB_CK_DDUC3_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC3_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC3_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC3_SIGNAL_LEN_REG_ADDR (0x00040CC4u)
#define CSL_DFE_BB_CK_DDUC3_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CK_DDUC3_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 chan_sel : 12;
#else 
    Uint32 chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CK_DDUC3_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_BB_CK_DDUC3_CHAN_SEL_REG_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_BB_CK_DDUC3_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC3_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC3_CHAN_SEL_REG_ADDR (0x00040CC8u)
#define CSL_DFE_BB_CK_DDUC3_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CK_DDUC3_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC3_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC3_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC3_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC3_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC3_RESULT_LO_REG_ADDR (0x00040CCCu)
#define CSL_DFE_BB_CK_DDUC3_RESULT_LO_REG_RESETVAL (0x00000000u)

/* CK_DDUC3_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC3_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC3_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC3_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC3_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC3_RESULT_HI_REG_ADDR (0x00040CD0u)
#define CSL_DFE_BB_CK_DDUC3_RESULT_HI_REG_RESETVAL (0x00000000u)

/* CK_DDUC3_DDUC1_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 sig_gen_ssel : 4;
    Uint32 chksum_ssel : 4;
#else 
    Uint32 chksum_ssel : 4;
    Uint32 sig_gen_ssel : 4;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CK_DDUC3_DDUC1_SSEL_REG;

/* sync select for check sum module */
#define CSL_DFE_BB_CK_DDUC3_DDUC1_SSEL_REG_CHKSUM_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CK_DDUC3_DDUC1_SSEL_REG_CHKSUM_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC3_DDUC1_SSEL_REG_CHKSUM_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator module */
#define CSL_DFE_BB_CK_DDUC3_DDUC1_SSEL_REG_SIG_GEN_SSEL_MASK (0x000000F0u)
#define CSL_DFE_BB_CK_DDUC3_DDUC1_SSEL_REG_SIG_GEN_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_BB_CK_DDUC3_DDUC1_SSEL_REG_SIG_GEN_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC3_DDUC1_SSEL_REG_ADDR (0x00040CD4u)
#define CSL_DFE_BB_CK_DDUC3_DDUC1_SSEL_REG_RESETVAL (0x00000000u)

/* GCCK_DDUC3_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_ADDR (0x00040CD8u)
#define CSL_DFE_BB_GCCK_DDUC3_GENERAL_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN3_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN3_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_START_LO_REG_ADDR (0x00040CDCu)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN3_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN3_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_START_HI_REG_ADDR (0x00040CE0u)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN3_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN3_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_STOP_LO_REG_ADDR (0x00040CE4u)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN3_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN3_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_STOP_HI_REG_ADDR (0x00040CE8u)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN3_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN3_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_SLOPE_LO_REG_ADDR (0x00040CECu)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN3_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN3_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_SLOPE_HI_REG_ADDR (0x00040CF0u)
#define CSL_DFE_BB_SIGNAL_GEN3_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN3_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN3_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_BB_SIGNAL_GEN3_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN3_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN3_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN3_GEN_TIMER_REG_ADDR (0x00040CF4u)
#define CSL_DFE_BB_SIGNAL_GEN3_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN4_CTRL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 stable_len : 12;
    Uint32 dduc_spare0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 dduc_spare0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN4_CTRL0_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_BB_SIGNAL_GEN4_CTRL0_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN4_CTRL0_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN4_CTRL0_REG_MODE_RESETVAL (0x00000000u)

/* spare pins */
#define CSL_DFE_BB_SIGNAL_GEN4_CTRL0_REG_DDUC_SPARE0_MASK (0x0000000Eu)
#define CSL_DFE_BB_SIGNAL_GEN4_CTRL0_REG_DDUC_SPARE0_SHIFT (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN4_CTRL0_REG_DDUC_SPARE0_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_BB_SIGNAL_GEN4_CTRL0_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_BB_SIGNAL_GEN4_CTRL0_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_BB_SIGNAL_GEN4_CTRL0_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN4_CTRL0_REG_ADDR (0x00040D00u)
#define CSL_DFE_BB_SIGNAL_GEN4_CTRL0_REG_RESETVAL (0x00000000u)

/* CK_DDUC4_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC4_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_BB_CK_DDUC4_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC4_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC4_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC4_SIGNAL_LEN_REG_ADDR (0x00040D04u)
#define CSL_DFE_BB_CK_DDUC4_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CK_DDUC4_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 chan_sel : 12;
#else 
    Uint32 chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CK_DDUC4_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_BB_CK_DDUC4_CHAN_SEL_REG_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_BB_CK_DDUC4_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC4_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC4_CHAN_SEL_REG_ADDR (0x00040D08u)
#define CSL_DFE_BB_CK_DDUC4_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CK_DDUC4_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC4_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC4_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC4_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC4_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC4_RESULT_LO_REG_ADDR (0x00040D0Cu)
#define CSL_DFE_BB_CK_DDUC4_RESULT_LO_REG_RESETVAL (0x00000000u)

/* CK_DDUC4_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC4_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC4_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC4_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC4_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC4_RESULT_HI_REG_ADDR (0x00040D10u)
#define CSL_DFE_BB_CK_DDUC4_RESULT_HI_REG_RESETVAL (0x00000000u)

/* CK_DDUC4_DDUC0_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 sig_gen_ssel : 4;
    Uint32 chksum_ssel : 4;
#else 
    Uint32 chksum_ssel : 4;
    Uint32 sig_gen_ssel : 4;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CK_DDUC4_DDUC0_SSEL_REG;

/* sync select for check sum module */
#define CSL_DFE_BB_CK_DDUC4_DDUC0_SSEL_REG_CHKSUM_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CK_DDUC4_DDUC0_SSEL_REG_CHKSUM_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC4_DDUC0_SSEL_REG_CHKSUM_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator module */
#define CSL_DFE_BB_CK_DDUC4_DDUC0_SSEL_REG_SIG_GEN_SSEL_MASK (0x000000F0u)
#define CSL_DFE_BB_CK_DDUC4_DDUC0_SSEL_REG_SIG_GEN_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_BB_CK_DDUC4_DDUC0_SSEL_REG_SIG_GEN_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC4_DDUC0_SSEL_REG_ADDR (0x00040D14u)
#define CSL_DFE_BB_CK_DDUC4_DDUC0_SSEL_REG_RESETVAL (0x00000000u)

/* GCCK_DDUC4_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_ADDR (0x00040D18u)
#define CSL_DFE_BB_GCCK_DDUC4_GENERAL_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN4_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN4_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_START_LO_REG_ADDR (0x00040D1Cu)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN4_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN4_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_START_HI_REG_ADDR (0x00040D20u)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN4_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN4_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_STOP_LO_REG_ADDR (0x00040D24u)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN4_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN4_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_STOP_HI_REG_ADDR (0x00040D28u)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN4_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN4_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_SLOPE_LO_REG_ADDR (0x00040D2Cu)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN4_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN4_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_SLOPE_HI_REG_ADDR (0x00040D30u)
#define CSL_DFE_BB_SIGNAL_GEN4_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN4_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN4_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_BB_SIGNAL_GEN4_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN4_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN4_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN4_GEN_TIMER_REG_ADDR (0x00040D34u)
#define CSL_DFE_BB_SIGNAL_GEN4_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN5_CTRL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 stable_len : 12;
    Uint32 dduc_spare0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 dduc_spare0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN5_CTRL0_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_BB_SIGNAL_GEN5_CTRL0_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN5_CTRL0_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN5_CTRL0_REG_MODE_RESETVAL (0x00000000u)

/* spare pins */
#define CSL_DFE_BB_SIGNAL_GEN5_CTRL0_REG_DDUC_SPARE0_MASK (0x0000000Eu)
#define CSL_DFE_BB_SIGNAL_GEN5_CTRL0_REG_DDUC_SPARE0_SHIFT (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN5_CTRL0_REG_DDUC_SPARE0_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_BB_SIGNAL_GEN5_CTRL0_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_BB_SIGNAL_GEN5_CTRL0_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_BB_SIGNAL_GEN5_CTRL0_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN5_CTRL0_REG_ADDR (0x00040D40u)
#define CSL_DFE_BB_SIGNAL_GEN5_CTRL0_REG_RESETVAL (0x00000000u)

/* CK_DDUC5_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC5_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_BB_CK_DDUC5_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC5_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC5_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC5_SIGNAL_LEN_REG_ADDR (0x00040D44u)
#define CSL_DFE_BB_CK_DDUC5_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CK_DDUC5_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 chan_sel : 12;
#else 
    Uint32 chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CK_DDUC5_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_BB_CK_DDUC5_CHAN_SEL_REG_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_BB_CK_DDUC5_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC5_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC5_CHAN_SEL_REG_ADDR (0x00040D48u)
#define CSL_DFE_BB_CK_DDUC5_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CK_DDUC5_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC5_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC5_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC5_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC5_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC5_RESULT_LO_REG_ADDR (0x00040D4Cu)
#define CSL_DFE_BB_CK_DDUC5_RESULT_LO_REG_RESETVAL (0x00000000u)

/* CK_DDUC5_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC5_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC5_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC5_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC5_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC5_RESULT_HI_REG_ADDR (0x00040D50u)
#define CSL_DFE_BB_CK_DDUC5_RESULT_HI_REG_RESETVAL (0x00000000u)

/* CK_DDUC5_DDUC1_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 sig_gen_ssel : 4;
    Uint32 chksum_ssel : 4;
#else 
    Uint32 chksum_ssel : 4;
    Uint32 sig_gen_ssel : 4;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CK_DDUC5_DDUC1_SSEL_REG;

/* sync select for check sum module */
#define CSL_DFE_BB_CK_DDUC5_DDUC1_SSEL_REG_CHKSUM_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CK_DDUC5_DDUC1_SSEL_REG_CHKSUM_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC5_DDUC1_SSEL_REG_CHKSUM_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator module */
#define CSL_DFE_BB_CK_DDUC5_DDUC1_SSEL_REG_SIG_GEN_SSEL_MASK (0x000000F0u)
#define CSL_DFE_BB_CK_DDUC5_DDUC1_SSEL_REG_SIG_GEN_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_BB_CK_DDUC5_DDUC1_SSEL_REG_SIG_GEN_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC5_DDUC1_SSEL_REG_ADDR (0x00040D54u)
#define CSL_DFE_BB_CK_DDUC5_DDUC1_SSEL_REG_RESETVAL (0x00000000u)

/* GCCK_DDUC5_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_ADDR (0x00040D58u)
#define CSL_DFE_BB_GCCK_DDUC5_GENERAL_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN5_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN5_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_START_LO_REG_ADDR (0x00040D5Cu)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN5_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN5_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_START_HI_REG_ADDR (0x00040D60u)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN5_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN5_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_STOP_LO_REG_ADDR (0x00040D64u)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN5_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN5_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_STOP_HI_REG_ADDR (0x00040D68u)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN5_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN5_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_SLOPE_LO_REG_ADDR (0x00040D6Cu)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN5_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN5_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_SLOPE_HI_REG_ADDR (0x00040D70u)
#define CSL_DFE_BB_SIGNAL_GEN5_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN5_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN5_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_BB_SIGNAL_GEN5_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN5_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN5_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN5_GEN_TIMER_REG_ADDR (0x00040D74u)
#define CSL_DFE_BB_SIGNAL_GEN5_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN6_CTRL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 stable_len : 12;
    Uint32 dduc_spare0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 dduc_spare0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN6_CTRL0_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_BB_SIGNAL_GEN6_CTRL0_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN6_CTRL0_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN6_CTRL0_REG_MODE_RESETVAL (0x00000000u)

/* spare pins */
#define CSL_DFE_BB_SIGNAL_GEN6_CTRL0_REG_DDUC_SPARE0_MASK (0x0000000Eu)
#define CSL_DFE_BB_SIGNAL_GEN6_CTRL0_REG_DDUC_SPARE0_SHIFT (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN6_CTRL0_REG_DDUC_SPARE0_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_BB_SIGNAL_GEN6_CTRL0_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_BB_SIGNAL_GEN6_CTRL0_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_BB_SIGNAL_GEN6_CTRL0_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN6_CTRL0_REG_ADDR (0x00040D80u)
#define CSL_DFE_BB_SIGNAL_GEN6_CTRL0_REG_RESETVAL (0x00000000u)

/* CK_DDUC6_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC6_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_BB_CK_DDUC6_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC6_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC6_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC6_SIGNAL_LEN_REG_ADDR (0x00040D84u)
#define CSL_DFE_BB_CK_DDUC6_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CK_DDUC6_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 chan_sel : 12;
#else 
    Uint32 chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CK_DDUC6_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_BB_CK_DDUC6_CHAN_SEL_REG_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_BB_CK_DDUC6_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC6_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC6_CHAN_SEL_REG_ADDR (0x00040D88u)
#define CSL_DFE_BB_CK_DDUC6_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CK_DDUC6_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC6_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC6_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC6_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC6_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC6_RESULT_LO_REG_ADDR (0x00040D8Cu)
#define CSL_DFE_BB_CK_DDUC6_RESULT_LO_REG_RESETVAL (0x00000000u)

/* CK_DDUC6_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC6_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC6_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC6_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC6_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC6_RESULT_HI_REG_ADDR (0x00040D90u)
#define CSL_DFE_BB_CK_DDUC6_RESULT_HI_REG_RESETVAL (0x00000000u)

/* CK_DDUC6_DDUC0_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 sig_gen_ssel : 4;
    Uint32 chksum_ssel : 4;
#else 
    Uint32 chksum_ssel : 4;
    Uint32 sig_gen_ssel : 4;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CK_DDUC6_DDUC0_SSEL_REG;

/* sync select for check sum module */
#define CSL_DFE_BB_CK_DDUC6_DDUC0_SSEL_REG_CHKSUM_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CK_DDUC6_DDUC0_SSEL_REG_CHKSUM_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC6_DDUC0_SSEL_REG_CHKSUM_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator module */
#define CSL_DFE_BB_CK_DDUC6_DDUC0_SSEL_REG_SIG_GEN_SSEL_MASK (0x000000F0u)
#define CSL_DFE_BB_CK_DDUC6_DDUC0_SSEL_REG_SIG_GEN_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_BB_CK_DDUC6_DDUC0_SSEL_REG_SIG_GEN_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC6_DDUC0_SSEL_REG_ADDR (0x00040D94u)
#define CSL_DFE_BB_CK_DDUC6_DDUC0_SSEL_REG_RESETVAL (0x00000000u)

/* GCCK_DDUC6_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_ADDR (0x00040D98u)
#define CSL_DFE_BB_GCCK_DDUC6_GENERAL_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN6_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN6_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_START_LO_REG_ADDR (0x00040D9Cu)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN6_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN6_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_START_HI_REG_ADDR (0x00040DA0u)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN6_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN6_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_STOP_LO_REG_ADDR (0x00040DA4u)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN6_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN6_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_STOP_HI_REG_ADDR (0x00040DA8u)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN6_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN6_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_SLOPE_LO_REG_ADDR (0x00040DACu)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN6_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN6_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_SLOPE_HI_REG_ADDR (0x00040DB0u)
#define CSL_DFE_BB_SIGNAL_GEN6_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN6_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN6_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_BB_SIGNAL_GEN6_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN6_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN6_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN6_GEN_TIMER_REG_ADDR (0x00040DB4u)
#define CSL_DFE_BB_SIGNAL_GEN6_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN7_CTRL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 stable_len : 12;
    Uint32 dduc_spare0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 dduc_spare0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN7_CTRL0_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_BB_SIGNAL_GEN7_CTRL0_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN7_CTRL0_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN7_CTRL0_REG_MODE_RESETVAL (0x00000000u)

/* spare pins */
#define CSL_DFE_BB_SIGNAL_GEN7_CTRL0_REG_DDUC_SPARE0_MASK (0x0000000Eu)
#define CSL_DFE_BB_SIGNAL_GEN7_CTRL0_REG_DDUC_SPARE0_SHIFT (0x00000001u)
#define CSL_DFE_BB_SIGNAL_GEN7_CTRL0_REG_DDUC_SPARE0_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_BB_SIGNAL_GEN7_CTRL0_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_BB_SIGNAL_GEN7_CTRL0_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_BB_SIGNAL_GEN7_CTRL0_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN7_CTRL0_REG_ADDR (0x00040DC0u)
#define CSL_DFE_BB_SIGNAL_GEN7_CTRL0_REG_RESETVAL (0x00000000u)

/* CK_DDUC7_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC7_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_BB_CK_DDUC7_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC7_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC7_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC7_SIGNAL_LEN_REG_ADDR (0x00040DC4u)
#define CSL_DFE_BB_CK_DDUC7_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CK_DDUC7_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 chan_sel : 12;
#else 
    Uint32 chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CK_DDUC7_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_BB_CK_DDUC7_CHAN_SEL_REG_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_BB_CK_DDUC7_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC7_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC7_CHAN_SEL_REG_ADDR (0x00040DC8u)
#define CSL_DFE_BB_CK_DDUC7_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CK_DDUC7_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC7_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC7_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC7_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC7_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC7_RESULT_LO_REG_ADDR (0x00040DCCu)
#define CSL_DFE_BB_CK_DDUC7_RESULT_LO_REG_RESETVAL (0x00000000u)

/* CK_DDUC7_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_DDUC7_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_DDUC7_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_DDUC7_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC7_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC7_RESULT_HI_REG_ADDR (0x00040DD0u)
#define CSL_DFE_BB_CK_DDUC7_RESULT_HI_REG_RESETVAL (0x00000000u)

/* CK_DDUC7_DDUC1_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 sig_gen_ssel : 4;
    Uint32 chksum_ssel : 4;
#else 
    Uint32 chksum_ssel : 4;
    Uint32 sig_gen_ssel : 4;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CK_DDUC7_DDUC1_SSEL_REG;

/* sync select for check sum module */
#define CSL_DFE_BB_CK_DDUC7_DDUC1_SSEL_REG_CHKSUM_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CK_DDUC7_DDUC1_SSEL_REG_CHKSUM_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_DDUC7_DDUC1_SSEL_REG_CHKSUM_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator module */
#define CSL_DFE_BB_CK_DDUC7_DDUC1_SSEL_REG_SIG_GEN_SSEL_MASK (0x000000F0u)
#define CSL_DFE_BB_CK_DDUC7_DDUC1_SSEL_REG_SIG_GEN_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_BB_CK_DDUC7_DDUC1_SSEL_REG_SIG_GEN_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_DDUC7_DDUC1_SSEL_REG_ADDR (0x00040DD4u)
#define CSL_DFE_BB_CK_DDUC7_DDUC1_SSEL_REG_RESETVAL (0x00000000u)

/* GCCK_DDUC7_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_ADDR (0x00040DD8u)
#define CSL_DFE_BB_GCCK_DDUC7_GENERAL_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN7_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN7_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_START_LO_REG_ADDR (0x00040DDCu)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN7_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN7_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_START_HI_REG_ADDR (0x00040DE0u)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN7_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN7_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_STOP_LO_REG_ADDR (0x00040DE4u)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN7_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN7_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_STOP_HI_REG_ADDR (0x00040DE8u)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN7_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN7_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_SLOPE_LO_REG_ADDR (0x00040DECu)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN7_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN7_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_SLOPE_HI_REG_ADDR (0x00040DF0u)
#define CSL_DFE_BB_SIGNAL_GEN7_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GEN7_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GEN7_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_BB_SIGNAL_GEN7_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GEN7_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GEN7_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GEN7_GEN_TIMER_REG_ADDR (0x00040DF4u)
#define CSL_DFE_BB_SIGNAL_GEN7_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* CK_SUMA_CTRL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 stable_len : 12;
    Uint32 dduc_spare0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 dduc_spare0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_SUMA_CTRL0_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_BB_CK_SUMA_CTRL0_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_BB_CK_SUMA_CTRL0_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_SUMA_CTRL0_REG_MODE_RESETVAL (0x00000000u)

/* spare pins */
#define CSL_DFE_BB_CK_SUMA_CTRL0_REG_DDUC_SPARE0_MASK (0x0000000Eu)
#define CSL_DFE_BB_CK_SUMA_CTRL0_REG_DDUC_SPARE0_SHIFT (0x00000001u)
#define CSL_DFE_BB_CK_SUMA_CTRL0_REG_DDUC_SPARE0_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_BB_CK_SUMA_CTRL0_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_BB_CK_SUMA_CTRL0_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_BB_CK_SUMA_CTRL0_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_SUMA_CTRL0_REG_ADDR (0x00040E00u)
#define CSL_DFE_BB_CK_SUMA_CTRL0_REG_RESETVAL (0x00000000u)

/* CK_SUMA_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_SUMA_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_BB_CK_SUMA_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_SUMA_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_SUMA_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_SUMA_SIGNAL_LEN_REG_ADDR (0x00040E04u)
#define CSL_DFE_BB_CK_SUMA_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CK_SUMA_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 chan_sel : 12;
#else 
    Uint32 chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CK_SUMA_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_BB_CK_SUMA_CHAN_SEL_REG_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_BB_CK_SUMA_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_SUMA_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_SUMA_CHAN_SEL_REG_ADDR (0x00040E08u)
#define CSL_DFE_BB_CK_SUMA_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CK_SUMA_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_SUMA_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_SUMA_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_SUMA_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_SUMA_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_SUMA_RESULT_LO_REG_ADDR (0x00040E0Cu)
#define CSL_DFE_BB_CK_SUMA_RESULT_LO_REG_RESETVAL (0x00000000u)

/* CK_SUMA_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_SUMA_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_SUMA_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_SUMA_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_SUMA_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_SUMA_RESULT_HI_REG_ADDR (0x00040E10u)
#define CSL_DFE_BB_CK_SUMA_RESULT_HI_REG_RESETVAL (0x00000000u)

/* CK_SUMA_CTRL1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 aid_sig_gen_test_enable : 1;
    Uint32 sig_gen_ssel : 4;
    Uint32 chksum_ssel : 4;
#else 
    Uint32 chksum_ssel : 4;
    Uint32 sig_gen_ssel : 4;
    Uint32 aid_sig_gen_test_enable : 1;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_BB_CK_SUMA_CTRL1_REG;

/* sync select for check sum module */
#define CSL_DFE_BB_CK_SUMA_CTRL1_REG_CHKSUM_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CK_SUMA_CTRL1_REG_CHKSUM_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_SUMA_CTRL1_REG_CHKSUM_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator module */
#define CSL_DFE_BB_CK_SUMA_CTRL1_REG_SIG_GEN_SSEL_MASK (0x000000F0u)
#define CSL_DFE_BB_CK_SUMA_CTRL1_REG_SIG_GEN_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_BB_CK_SUMA_CTRL1_REG_SIG_GEN_SSEL_RESETVAL (0x00000000u)

/* Signal Generator Test Mode Enable.  When this bit is set the AID downlink interface is disconnected and the Signal Generator generates data instead */
#define CSL_DFE_BB_CK_SUMA_CTRL1_REG_AID_SIG_GEN_TEST_ENABLE_MASK (0x00000100u)
#define CSL_DFE_BB_CK_SUMA_CTRL1_REG_AID_SIG_GEN_TEST_ENABLE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CK_SUMA_CTRL1_REG_AID_SIG_GEN_TEST_ENABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_SUMA_CTRL1_REG_ADDR (0x00040E14u)
#define CSL_DFE_BB_CK_SUMA_CTRL1_REG_RESETVAL (0x00000000u)

/* GCCK_AIDA_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_GCCK_AIDA_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_ADDR (0x00040E18u)
#define CSL_DFE_BB_GCCK_AIDA_GENERAL_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENA_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENA_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENA_RAMP_START_LO_REG_ADDR (0x00040E1Cu)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENA_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENA_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENA_RAMP_START_HI_REG_ADDR (0x00040E20u)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENA_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENA_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENA_RAMP_STOP_LO_REG_ADDR (0x00040E24u)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENA_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENA_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENA_RAMP_STOP_HI_REG_ADDR (0x00040E28u)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENA_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENA_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENA_RAMP_SLOPE_LO_REG_ADDR (0x00040E2Cu)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENA_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENA_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENA_RAMP_SLOPE_HI_REG_ADDR (0x00040E30u)
#define CSL_DFE_BB_SIGNAL_GENA_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENA_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENA_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_BB_SIGNAL_GENA_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENA_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENA_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENA_GEN_TIMER_REG_ADDR (0x00040E34u)
#define CSL_DFE_BB_SIGNAL_GENA_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* CK_SUMB_CTRL0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 stable_len : 12;
    Uint32 dduc_spare0 : 3;
    Uint32 mode : 1;
#else 
    Uint32 mode : 1;
    Uint32 dduc_spare0 : 3;
    Uint32 stable_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_SUMB_CTRL0_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_BB_CK_SUMB_CTRL0_REG_MODE_MASK (0x00000001u)
#define CSL_DFE_BB_CK_SUMB_CTRL0_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_SUMB_CTRL0_REG_MODE_RESETVAL (0x00000000u)

/* spare pins */
#define CSL_DFE_BB_CK_SUMB_CTRL0_REG_DDUC_SPARE0_MASK (0x0000000Eu)
#define CSL_DFE_BB_CK_SUMB_CTRL0_REG_DDUC_SPARE0_SHIFT (0x00000001u)
#define CSL_DFE_BB_CK_SUMB_CTRL0_REG_DDUC_SPARE0_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_BB_CK_SUMB_CTRL0_REG_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_BB_CK_SUMB_CTRL0_REG_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_BB_CK_SUMB_CTRL0_REG_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_SUMB_CTRL0_REG_ADDR (0x00040E40u)
#define CSL_DFE_BB_CK_SUMB_CTRL0_REG_RESETVAL (0x00000000u)

/* CK_SUMB_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_len : 16;
#else 
    Uint32 signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_SUMB_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_BB_CK_SUMB_SIGNAL_LEN_REG_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_SUMB_SIGNAL_LEN_REG_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_SUMB_SIGNAL_LEN_REG_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_SUMB_SIGNAL_LEN_REG_ADDR (0x00040E44u)
#define CSL_DFE_BB_CK_SUMB_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CK_SUMB_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 chan_sel : 12;
#else 
    Uint32 chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CK_SUMB_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_BB_CK_SUMB_CHAN_SEL_REG_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_BB_CK_SUMB_CHAN_SEL_REG_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_SUMB_CHAN_SEL_REG_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_SUMB_CHAN_SEL_REG_ADDR (0x00040E48u)
#define CSL_DFE_BB_CK_SUMB_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CK_SUMB_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_SUMB_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_SUMB_RESULT_LO_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_SUMB_RESULT_LO_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_SUMB_RESULT_LO_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_SUMB_RESULT_LO_REG_ADDR (0x00040E4Cu)
#define CSL_DFE_BB_CK_SUMB_RESULT_LO_REG_RESETVAL (0x00000000u)

/* CK_SUMB_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CK_SUMB_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_BB_CK_SUMB_RESULT_HI_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CK_SUMB_RESULT_HI_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_SUMB_RESULT_HI_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_SUMB_RESULT_HI_REG_ADDR (0x00040E50u)
#define CSL_DFE_BB_CK_SUMB_RESULT_HI_REG_RESETVAL (0x00000000u)

/* CK_SUMB_CTRL1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 aid_sig_gen_test_enable : 1;
    Uint32 sig_gen_ssel : 4;
    Uint32 chksum_ssel : 4;
#else 
    Uint32 chksum_ssel : 4;
    Uint32 sig_gen_ssel : 4;
    Uint32 aid_sig_gen_test_enable : 1;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_BB_CK_SUMB_CTRL1_REG;

/* sync select for check sum module */
#define CSL_DFE_BB_CK_SUMB_CTRL1_REG_CHKSUM_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_CK_SUMB_CTRL1_REG_CHKSUM_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_CK_SUMB_CTRL1_REG_CHKSUM_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator module */
#define CSL_DFE_BB_CK_SUMB_CTRL1_REG_SIG_GEN_SSEL_MASK (0x000000F0u)
#define CSL_DFE_BB_CK_SUMB_CTRL1_REG_SIG_GEN_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_BB_CK_SUMB_CTRL1_REG_SIG_GEN_SSEL_RESETVAL (0x00000000u)

/* Signal Generator Test Mode Enable.  When this bit is set the AID downlink interface is disconnected and the Signal Generator generates data instead */
#define CSL_DFE_BB_CK_SUMB_CTRL1_REG_AID_SIG_GEN_TEST_ENABLE_MASK (0x00000100u)
#define CSL_DFE_BB_CK_SUMB_CTRL1_REG_AID_SIG_GEN_TEST_ENABLE_SHIFT (0x00000008u)
#define CSL_DFE_BB_CK_SUMB_CTRL1_REG_AID_SIG_GEN_TEST_ENABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CK_SUMB_CTRL1_REG_ADDR (0x00040E54u)
#define CSL_DFE_BB_CK_SUMB_CTRL1_REG_RESETVAL (0x00000000u)

/* GCCK_AIDB_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 frame_len_m1 : 12;
    Uint32 seed : 1;
    Uint32 ramp_mode : 1;
    Uint32 gen_frame : 1;
    Uint32 gen_data : 1;
#else 
    Uint32 gen_data : 1;
    Uint32 gen_frame : 1;
    Uint32 ramp_mode : 1;
    Uint32 seed : 1;
    Uint32 frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_GCCK_AIDB_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_SEED_MASK (0x00000008u)
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_SEED_SHIFT (0x00000003u)
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_ADDR (0x00040E58u)
#define CSL_DFE_BB_GCCK_AIDB_GENERAL_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENB_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_15_0 : 16;
#else 
    Uint32 ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENB_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_START_LO_REG_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_START_LO_REG_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_START_LO_REG_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENB_RAMP_START_LO_REG_ADDR (0x00040E5Cu)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENB_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_start_31_16 : 16;
#else 
    Uint32 ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENB_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_START_HI_REG_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_START_HI_REG_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_START_HI_REG_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENB_RAMP_START_HI_REG_ADDR (0x00040E60u)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENB_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_15_0 : 16;
#else 
    Uint32 ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENB_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_STOP_LO_REG_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_STOP_LO_REG_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_STOP_LO_REG_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENB_RAMP_STOP_LO_REG_ADDR (0x00040E64u)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENB_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_stop_31_16 : 16;
#else 
    Uint32 ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENB_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_STOP_HI_REG_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_STOP_HI_REG_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_STOP_HI_REG_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENB_RAMP_STOP_HI_REG_ADDR (0x00040E68u)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENB_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_15_0 : 16;
#else 
    Uint32 ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENB_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_SLOPE_LO_REG_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENB_RAMP_SLOPE_LO_REG_ADDR (0x00040E6Cu)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENB_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ramp_slope_31_16 : 16;
#else 
    Uint32 ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENB_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_SLOPE_HI_REG_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENB_RAMP_SLOPE_HI_REG_ADDR (0x00040E70u)
#define CSL_DFE_BB_SIGNAL_GENB_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* SIGNAL_GENB_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gen_timer : 16;
#else 
    Uint32 gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_SIGNAL_GENB_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_BB_SIGNAL_GENB_GEN_TIMER_REG_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_BB_SIGNAL_GENB_GEN_TIMER_REG_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_BB_SIGNAL_GENB_GEN_TIMER_REG_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_BB_SIGNAL_GENB_GEN_TIMER_REG_ADDR (0x00040E74u)
#define CSL_DFE_BB_SIGNAL_GENB_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* ANTCAL_PN_INIT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 antcal_pn_init : 16;
#else 
    Uint32 antcal_pn_init : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_ANTCAL_PN_INIT_REG;

/* Antenna Calibration PN sequencer Initial value */
#define CSL_DFE_BB_ANTCAL_PN_INIT_REG_ANTCAL_PN_INIT_MASK (0x0000FFFFu)
#define CSL_DFE_BB_ANTCAL_PN_INIT_REG_ANTCAL_PN_INIT_SHIFT (0x00000000u)
#define CSL_DFE_BB_ANTCAL_PN_INIT_REG_ANTCAL_PN_INIT_RESETVAL (0x00000000u)

#define CSL_DFE_BB_ANTCAL_PN_INIT_REG_ADDR (0x00041000u)
#define CSL_DFE_BB_ANTCAL_PN_INIT_REG_RESETVAL (0x00000000u)

/* ANTCAL_PN_TAPCONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 antcal_pn_tapconfig : 16;
#else 
    Uint32 antcal_pn_tapconfig : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_ANTCAL_PN_TAPCONFIG_REG;

/* Antenna Calibration PN sequencer tap configuration */
#define CSL_DFE_BB_ANTCAL_PN_TAPCONFIG_REG_ANTCAL_PN_TAPCONFIG_MASK (0x0000FFFFu)
#define CSL_DFE_BB_ANTCAL_PN_TAPCONFIG_REG_ANTCAL_PN_TAPCONFIG_SHIFT (0x00000000u)
#define CSL_DFE_BB_ANTCAL_PN_TAPCONFIG_REG_ANTCAL_PN_TAPCONFIG_RESETVAL (0x00000000u)

#define CSL_DFE_BB_ANTCAL_PN_TAPCONFIG_REG_ADDR (0x00041004u)
#define CSL_DFE_BB_ANTCAL_PN_TAPCONFIG_REG_RESETVAL (0x00000000u)

/* ANTCAL_TX_NOISE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 17;
    Uint32 antcal_tx_noise : 15;
#else 
    Uint32 antcal_tx_noise : 15;
    Uint32 rsvd0 : 17;
#endif 
} CSL_DFE_BB_ANTCAL_TX_NOISE_REG;

/* Antenna Calibration TX noise level */
#define CSL_DFE_BB_ANTCAL_TX_NOISE_REG_ANTCAL_TX_NOISE_MASK (0x00007FFFu)
#define CSL_DFE_BB_ANTCAL_TX_NOISE_REG_ANTCAL_TX_NOISE_SHIFT (0x00000000u)
#define CSL_DFE_BB_ANTCAL_TX_NOISE_REG_ANTCAL_TX_NOISE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_ANTCAL_TX_NOISE_REG_ADDR (0x00041008u)
#define CSL_DFE_BB_ANTCAL_TX_NOISE_REG_RESETVAL (0x00000000u)

/* ANTCAL_RX */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 antcal_rx_oversample : 1;
    Uint32 antcal_rx_corr_delay : 8;
#else 
    Uint32 antcal_rx_corr_delay : 8;
    Uint32 antcal_rx_oversample : 1;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_BB_ANTCAL_RX_REG;

/* Antenna Calibration RX correlation delay in samples */
#define CSL_DFE_BB_ANTCAL_RX_REG_ANTCAL_RX_CORR_DELAY_MASK (0x000000FFu)
#define CSL_DFE_BB_ANTCAL_RX_REG_ANTCAL_RX_CORR_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_BB_ANTCAL_RX_REG_ANTCAL_RX_CORR_DELAY_RESETVAL (0x00000000u)

/* Antenna Calibration RX oversampled.  When 1 AxC is 2x oversampled */
#define CSL_DFE_BB_ANTCAL_RX_REG_ANTCAL_RX_OVERSAMPLE_MASK (0x00000100u)
#define CSL_DFE_BB_ANTCAL_RX_REG_ANTCAL_RX_OVERSAMPLE_SHIFT (0x00000008u)
#define CSL_DFE_BB_ANTCAL_RX_REG_ANTCAL_RX_OVERSAMPLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_ANTCAL_RX_REG_ADDR (0x0004100Cu)
#define CSL_DFE_BB_ANTCAL_RX_REG_RESETVAL (0x00000000u)

/* CFG1088 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 21;
    Uint32 jesd_en : 3;
    Uint32 rsvd1 : 2;
    Uint32 jesd_spacing : 2;
    Uint32 rsvd0 : 1;
    Uint32 jesd_if_config : 3;
#else 
    Uint32 jesd_if_config : 3;
    Uint32 rsvd0 : 1;
    Uint32 jesd_spacing : 2;
    Uint32 rsvd1 : 2;
    Uint32 jesd_en : 3;
    Uint32 rsvd2 : 21;
#endif 
} CSL_DFE_BB_CFG1088_REG;

/* Jesd interface config 1:0=DL init mode ; 2=Master Jesd only, asserted if IQN uplink interface is only JESD (no BB UL) */
#define CSL_DFE_BB_CFG1088_REG_JESD_IF_CONFIG_MASK (0x00000007u)
#define CSL_DFE_BB_CFG1088_REG_JESD_IF_CONFIG_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1088_REG_JESD_IF_CONFIG_RESETVAL (0x00000000u)

/* Jesd valid data spacing used to match JESD module interface speed.  0=valid every cycle.  1=valid every other sample, 2= valid every fourth sample. */
#define CSL_DFE_BB_CFG1088_REG_JESD_SPACING_MASK (0x00000030u)
#define CSL_DFE_BB_CFG1088_REG_JESD_SPACING_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG1088_REG_JESD_SPACING_RESETVAL (0x00000000u)

/* Jesd interface mode.  0=disabled, 1=master mode, 2=slave mode, 5=master loopback mode, 6=slave loopback mode */
#define CSL_DFE_BB_CFG1088_REG_JESD_EN_MASK (0x00000700u)
#define CSL_DFE_BB_CFG1088_REG_JESD_EN_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1088_REG_JESD_EN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1088_REG_ADDR (0x00041100u)
#define CSL_DFE_BB_CFG1088_REG_RESETVAL (0x00000000u)

/* CFG1089 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 jesd_ulstrobe_dly : 16;
#else 
    Uint32 jesd_ulstrobe_dly : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1089_REG;

/* Delay in ulstrobe_ct carrier type samples from UL_STROBE to frame start (slave only) */
#define CSL_DFE_BB_CFG1089_REG_JESD_ULSTROBE_DLY_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1089_REG_JESD_ULSTROBE_DLY_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1089_REG_JESD_ULSTROBE_DLY_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1089_REG_ADDR (0x00041104u)
#define CSL_DFE_BB_CFG1089_REG_RESETVAL (0x00000000u)

/* CFG1090 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 25;
    Uint32 jesd_ul_axc_disable : 7;
#else 
    Uint32 jesd_ul_axc_disable : 7;
    Uint32 rsvd0 : 25;
#endif 
} CSL_DFE_BB_CFG1090_REG;

/* Mechanism to disable an AxC in the JESD interface. Bit 6 set indicates AxC [5:0] is to be disabled */
#define CSL_DFE_BB_CFG1090_REG_JESD_UL_AXC_DISABLE_MASK (0x0000007Fu)
#define CSL_DFE_BB_CFG1090_REG_JESD_UL_AXC_DISABLE_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1090_REG_JESD_UL_AXC_DISABLE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1090_REG_ADDR (0x00041108u)
#define CSL_DFE_BB_CFG1090_REG_RESETVAL (0x00000000u)

/* CFG1091 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 jesd_dl_sync_delay : 8;
#else 
    Uint32 jesd_dl_sync_delay : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CFG1091_REG;

/* Delay of bb_jesd_if_sync signal enabling TX AxC sequencer. */
#define CSL_DFE_BB_CFG1091_REG_JESD_DL_SYNC_DELAY_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG1091_REG_JESD_DL_SYNC_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1091_REG_JESD_DL_SYNC_DELAY_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1091_REG_ADDR (0x0004110Cu)
#define CSL_DFE_BB_CFG1091_REG_RESETVAL (0x00000000u)

/* CFG1092 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 jesd_ul_pack_15_0 : 16;
#else 
    Uint32 jesd_ul_pack_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1092_REG;

/* Per AxC set master ul to aid data as packed into 16 bits.  Must match slave setting.  AxC numbering is according to JESD slot#  (eng_jesd_ul_axc#) not translated AxC value. */
#define CSL_DFE_BB_CFG1092_REG_JESD_UL_PACK_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1092_REG_JESD_UL_PACK_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1092_REG_JESD_UL_PACK_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1092_REG_ADDR (0x00041110u)
#define CSL_DFE_BB_CFG1092_REG_RESETVAL (0x00000000u)

/* CFG1093 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 jesd_ul_pack_31_16 : 16;
#else 
    Uint32 jesd_ul_pack_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1093_REG;

/* Per AxC set master ul to aid data as packed into 16 bits.  Must match slave setting. */
#define CSL_DFE_BB_CFG1093_REG_JESD_UL_PACK_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1093_REG_JESD_UL_PACK_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1093_REG_JESD_UL_PACK_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1093_REG_ADDR (0x00041114u)
#define CSL_DFE_BB_CFG1093_REG_RESETVAL (0x00000000u)

/* CFG1094 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 jesd_ul_pack_47_32 : 16;
#else 
    Uint32 jesd_ul_pack_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1094_REG;

/* Per AxC set master ul to aid data as packed into 16 bits.  Must match slave setting. */
#define CSL_DFE_BB_CFG1094_REG_JESD_UL_PACK_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1094_REG_JESD_UL_PACK_47_32_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1094_REG_JESD_UL_PACK_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1094_REG_ADDR (0x00041118u)
#define CSL_DFE_BB_CFG1094_REG_RESETVAL (0x00000000u)

/* CFG1152 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 autocp0_ssel : 4;
    Uint32 autocp0_ct_type : 4;
    Uint32 autocp_slave : 1;
    Uint32 autocp0_tddmode : 2;
    Uint32 autocp0_en : 1;
#else 
    Uint32 autocp0_en : 1;
    Uint32 autocp0_tddmode : 2;
    Uint32 autocp_slave : 1;
    Uint32 autocp0_ct_type : 4;
    Uint32 autocp0_ssel : 4;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_CFG1152_REG;

/* AutoCP timer0 operation enable 0=off */
#define CSL_DFE_BB_CFG1152_REG_AUTOCP0_EN_MASK (0x00000001u)
#define CSL_DFE_BB_CFG1152_REG_AUTOCP0_EN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1152_REG_AUTOCP0_EN_RESETVAL (0x00000000u)

/* TDD timer configuration used by autoCP0.  0:disabled, 2:tdd halt on UL, 3:tdd reset on UL */
#define CSL_DFE_BB_CFG1152_REG_AUTOCP0_TDDMODE_MASK (0x00000006u)
#define CSL_DFE_BB_CFG1152_REG_AUTOCP0_TDDMODE_SHIFT (0x00000001u)
#define CSL_DFE_BB_CFG1152_REG_AUTOCP0_TDDMODE_RESETVAL (0x00000000u)

/* When high this module uses the other BB module for arbitration onto the shared autoCP interface bus.  When low it is the arbitration master. */
#define CSL_DFE_BB_CFG1152_REG_AUTOCP_SLAVE_MASK (0x00000008u)
#define CSL_DFE_BB_CFG1152_REG_AUTOCP_SLAVE_SHIFT (0x00000003u)
#define CSL_DFE_BB_CFG1152_REG_AUTOCP_SLAVE_RESETVAL (0x00000000u)

/* AutoCP0 carrier type used to count timing interval.  Should be set to largest interval of selected active carriers. */
#define CSL_DFE_BB_CFG1152_REG_AUTOCP0_CT_TYPE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG1152_REG_AUTOCP0_CT_TYPE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG1152_REG_AUTOCP0_CT_TYPE_RESETVAL (0x00000000u)

/* AutoCP0 sync select to start operation (non-TDD mode) */
#define CSL_DFE_BB_CFG1152_REG_AUTOCP0_SSEL_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG1152_REG_AUTOCP0_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1152_REG_AUTOCP0_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1152_REG_ADDR (0x00041200u)
#define CSL_DFE_BB_CFG1152_REG_RESETVAL (0x00000000u)

/* CFG1153 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 autocp0_delayfromsync_15_0 : 16;
#else 
    Uint32 autocp0_delayfromsync_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1153_REG;

/* AutoCP0 interval in samples from sync to start of accumulation.  Not used in tdd mode. */
#define CSL_DFE_BB_CFG1153_REG_AUTOCP0_DELAYFROMSYNC_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1153_REG_AUTOCP0_DELAYFROMSYNC_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1153_REG_AUTOCP0_DELAYFROMSYNC_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1153_REG_ADDR (0x00041204u)
#define CSL_DFE_BB_CFG1153_REG_RESETVAL (0x00000000u)

/* CFG1154 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 autocp0_interval_acc_23_16 : 8;
    Uint32 autocp0_delayfromsync_23_16 : 8;
#else 
    Uint32 autocp0_delayfromsync_23_16 : 8;
    Uint32 autocp0_interval_acc_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1154_REG;

/*  */
#define CSL_DFE_BB_CFG1154_REG_AUTOCP0_DELAYFROMSYNC_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG1154_REG_AUTOCP0_DELAYFROMSYNC_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1154_REG_AUTOCP0_DELAYFROMSYNC_23_16_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_BB_CFG1154_REG_AUTOCP0_INTERVAL_ACC_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG1154_REG_AUTOCP0_INTERVAL_ACC_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1154_REG_AUTOCP0_INTERVAL_ACC_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1154_REG_ADDR (0x00041208u)
#define CSL_DFE_BB_CFG1154_REG_RESETVAL (0x00000000u)

/* CFG1155 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 autocp0_interval_acc_15_0 : 16;
#else 
    Uint32 autocp0_interval_acc_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1155_REG;

/* AutoCP0 inverval in samples that power accumulators operate */
#define CSL_DFE_BB_CFG1155_REG_AUTOCP0_INTERVAL_ACC_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1155_REG_AUTOCP0_INTERVAL_ACC_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1155_REG_AUTOCP0_INTERVAL_ACC_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1155_REG_ADDR (0x0004120Cu)
#define CSL_DFE_BB_CFG1155_REG_RESETVAL (0x00000000u)

/* CFG1156 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 autocp0_interval_off_15_0 : 16;
#else 
    Uint32 autocp0_interval_off_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1156_REG;

/* AutoCP0 inverval in samples that power accumulators delay between measurements.  Actual delay is longer if dump requires more cycles than defined in this field.  Note a delay of less than 144 clock cycles  or 2 samples may not be a precise delay depending on configuration.  */
#define CSL_DFE_BB_CFG1156_REG_AUTOCP0_INTERVAL_OFF_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1156_REG_AUTOCP0_INTERVAL_OFF_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1156_REG_AUTOCP0_INTERVAL_OFF_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1156_REG_ADDR (0x00041210u)
#define CSL_DFE_BB_CFG1156_REG_RESETVAL (0x00000000u)

/* CFG1160 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 autocp1_ssel : 4;
    Uint32 autocp1_ct_type : 4;
    Uint32 rsvd0 : 1;
    Uint32 autocp1_tddmode : 2;
    Uint32 autocp1_en : 1;
#else 
    Uint32 autocp1_en : 1;
    Uint32 autocp1_tddmode : 2;
    Uint32 rsvd0 : 1;
    Uint32 autocp1_ct_type : 4;
    Uint32 autocp1_ssel : 4;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_BB_CFG1160_REG;

/* AutoCP timer1 operation enable 0=off */
#define CSL_DFE_BB_CFG1160_REG_AUTOCP1_EN_MASK (0x00000001u)
#define CSL_DFE_BB_CFG1160_REG_AUTOCP1_EN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1160_REG_AUTOCP1_EN_RESETVAL (0x00000000u)

/* TDD timer configuration used by autoCP1.  0:disabled, 2:tdd halt on UL, 3:tdd reset on UL */
#define CSL_DFE_BB_CFG1160_REG_AUTOCP1_TDDMODE_MASK (0x00000006u)
#define CSL_DFE_BB_CFG1160_REG_AUTOCP1_TDDMODE_SHIFT (0x00000001u)
#define CSL_DFE_BB_CFG1160_REG_AUTOCP1_TDDMODE_RESETVAL (0x00000000u)

/* AutoCP1 carrier type used to count timing interval.  Should be set to largest interval of selected active carriers. */
#define CSL_DFE_BB_CFG1160_REG_AUTOCP1_CT_TYPE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG1160_REG_AUTOCP1_CT_TYPE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG1160_REG_AUTOCP1_CT_TYPE_RESETVAL (0x00000000u)

/* AutoCP1 sync select to start operation (non-TDD mode) */
#define CSL_DFE_BB_CFG1160_REG_AUTOCP1_SSEL_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG1160_REG_AUTOCP1_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1160_REG_AUTOCP1_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1160_REG_ADDR (0x00041220u)
#define CSL_DFE_BB_CFG1160_REG_RESETVAL (0x00000000u)

/* CFG1161 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 autocp1_delayfromsync_15_0 : 16;
#else 
    Uint32 autocp1_delayfromsync_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1161_REG;

/* AutoCP1 interval in samples from sync to start of accumulation.  Not used in tdd mode. */
#define CSL_DFE_BB_CFG1161_REG_AUTOCP1_DELAYFROMSYNC_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1161_REG_AUTOCP1_DELAYFROMSYNC_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1161_REG_AUTOCP1_DELAYFROMSYNC_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1161_REG_ADDR (0x00041224u)
#define CSL_DFE_BB_CFG1161_REG_RESETVAL (0x00000000u)

/* CFG1162 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 autocp1_interval_acc_23_16 : 8;
    Uint32 autocp1_delayfromsync_23_16 : 8;
#else 
    Uint32 autocp1_delayfromsync_23_16 : 8;
    Uint32 autocp1_interval_acc_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1162_REG;

/*  */
#define CSL_DFE_BB_CFG1162_REG_AUTOCP1_DELAYFROMSYNC_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG1162_REG_AUTOCP1_DELAYFROMSYNC_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1162_REG_AUTOCP1_DELAYFROMSYNC_23_16_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_BB_CFG1162_REG_AUTOCP1_INTERVAL_ACC_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG1162_REG_AUTOCP1_INTERVAL_ACC_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1162_REG_AUTOCP1_INTERVAL_ACC_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1162_REG_ADDR (0x00041228u)
#define CSL_DFE_BB_CFG1162_REG_RESETVAL (0x00000000u)

/* CFG1163 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 autocp1_interval_acc_15_0 : 16;
#else 
    Uint32 autocp1_interval_acc_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1163_REG;

/* AutoCP1 inverval in samples that power accumulators operate */
#define CSL_DFE_BB_CFG1163_REG_AUTOCP1_INTERVAL_ACC_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1163_REG_AUTOCP1_INTERVAL_ACC_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1163_REG_AUTOCP1_INTERVAL_ACC_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1163_REG_ADDR (0x0004122Cu)
#define CSL_DFE_BB_CFG1163_REG_RESETVAL (0x00000000u)

/* CFG1164 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 autocp1_interval_off_15_0 : 16;
#else 
    Uint32 autocp1_interval_off_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1164_REG;

/* AutoCP1 inverval in samples that power accumulators delay between measurements.  Actual delay is longer if dump requires more cycles than defined in this field.  Note a delay of less than 144 clock cycles  or 2 samples may not be a precise delay depending on configuration.  */
#define CSL_DFE_BB_CFG1164_REG_AUTOCP1_INTERVAL_OFF_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1164_REG_AUTOCP1_INTERVAL_OFF_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1164_REG_AUTOCP1_INTERVAL_OFF_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1164_REG_ADDR (0x00041230u)
#define CSL_DFE_BB_CFG1164_REG_RESETVAL (0x00000000u)

/* CFG1168 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 txtdd_ssel : 4;
    Uint32 txtdd_ct_type : 4;
    Uint32 rsvd0 : 1;
    Uint32 txtdd_datamode : 2;
    Uint32 txtdd_en : 1;
#else 
    Uint32 txtdd_en : 1;
    Uint32 txtdd_datamode : 2;
    Uint32 rsvd0 : 1;
    Uint32 txtdd_ct_type : 4;
    Uint32 txtdd_ssel : 4;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_BB_CFG1168_REG;

/* TX tdd timer operation enable 0=off */
#define CSL_DFE_BB_CFG1168_REG_TXTDD_EN_MASK (0x00000001u)
#define CSL_DFE_BB_CFG1168_REG_TXTDD_EN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1168_REG_TXTDD_EN_RESETVAL (0x00000000u)

/* In TX tdd mode data.  When 0 data is passed unchanged through BB;  When 2 the data is zeroed and the buffer memory is stalled */
#define CSL_DFE_BB_CFG1168_REG_TXTDD_DATAMODE_MASK (0x00000006u)
#define CSL_DFE_BB_CFG1168_REG_TXTDD_DATAMODE_SHIFT (0x00000001u)
#define CSL_DFE_BB_CFG1168_REG_TXTDD_DATAMODE_RESETVAL (0x00000000u)

/* TX tdd carrier type used to count timing interval.   */
#define CSL_DFE_BB_CFG1168_REG_TXTDD_CT_TYPE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG1168_REG_TXTDD_CT_TYPE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG1168_REG_TXTDD_CT_TYPE_RESETVAL (0x00000000u)

/* TX tdd sync select to start operation  */
#define CSL_DFE_BB_CFG1168_REG_TXTDD_SSEL_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG1168_REG_TXTDD_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1168_REG_TXTDD_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1168_REG_ADDR (0x00041240u)
#define CSL_DFE_BB_CFG1168_REG_RESETVAL (0x00000000u)

/* CFG1169 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txtdd_delayfromsync_15_0 : 16;
#else 
    Uint32 txtdd_delayfromsync_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1169_REG;

/* TX tdd interval in samples from sync to start of interval timer minus 1 sample. */
#define CSL_DFE_BB_CFG1169_REG_TXTDD_DELAYFROMSYNC_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1169_REG_TXTDD_DELAYFROMSYNC_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1169_REG_TXTDD_DELAYFROMSYNC_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1169_REG_ADDR (0x00041244u)
#define CSL_DFE_BB_CFG1169_REG_RESETVAL (0x00000000u)

/* CFG1170 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txtdd_timer_dl1_23_16 : 8;
    Uint32 txtdd_delayfromsync_23_16 : 8;
#else 
    Uint32 txtdd_delayfromsync_23_16 : 8;
    Uint32 txtdd_timer_dl1_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1170_REG;

/*  */
#define CSL_DFE_BB_CFG1170_REG_TXTDD_DELAYFROMSYNC_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG1170_REG_TXTDD_DELAYFROMSYNC_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1170_REG_TXTDD_DELAYFROMSYNC_23_16_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_BB_CFG1170_REG_TXTDD_TIMER_DL1_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG1170_REG_TXTDD_TIMER_DL1_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1170_REG_TXTDD_TIMER_DL1_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1170_REG_ADDR (0x00041248u)
#define CSL_DFE_BB_CFG1170_REG_RESETVAL (0x00000000u)

/* CFG1171 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txtdd_timer_dl1_15_0 : 16;
#else 
    Uint32 txtdd_timer_dl1_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1171_REG;

/* TX tdd initial downlink interval */
#define CSL_DFE_BB_CFG1171_REG_TXTDD_TIMER_DL1_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1171_REG_TXTDD_TIMER_DL1_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1171_REG_TXTDD_TIMER_DL1_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1171_REG_ADDR (0x0004124Cu)
#define CSL_DFE_BB_CFG1171_REG_RESETVAL (0x00000000u)

/* CFG1172 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txtdd_timer_ul1_15_0 : 16;
#else 
    Uint32 txtdd_timer_ul1_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1172_REG;

/* TX tdd initial upllink interval following dl1 */
#define CSL_DFE_BB_CFG1172_REG_TXTDD_TIMER_UL1_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1172_REG_TXTDD_TIMER_UL1_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1172_REG_TXTDD_TIMER_UL1_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1172_REG_ADDR (0x00041250u)
#define CSL_DFE_BB_CFG1172_REG_RESETVAL (0x00000000u)

/* CFG1173 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txtdd_timer_dl2_23_16 : 8;
    Uint32 txtdd_timer_ul1_23_16 : 8;
#else 
    Uint32 txtdd_timer_ul1_23_16 : 8;
    Uint32 txtdd_timer_dl2_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1173_REG;

/*  */
#define CSL_DFE_BB_CFG1173_REG_TXTDD_TIMER_UL1_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG1173_REG_TXTDD_TIMER_UL1_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1173_REG_TXTDD_TIMER_UL1_23_16_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_BB_CFG1173_REG_TXTDD_TIMER_DL2_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG1173_REG_TXTDD_TIMER_DL2_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1173_REG_TXTDD_TIMER_DL2_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1173_REG_ADDR (0x00041254u)
#define CSL_DFE_BB_CFG1173_REG_RESETVAL (0x00000000u)

/* CFG1174 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txtdd_timer_dl2_15_0 : 16;
#else 
    Uint32 txtdd_timer_dl2_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1174_REG;

/* TX tdd optional second downlink interval following ul1 */
#define CSL_DFE_BB_CFG1174_REG_TXTDD_TIMER_DL2_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1174_REG_TXTDD_TIMER_DL2_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1174_REG_TXTDD_TIMER_DL2_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1174_REG_ADDR (0x00041258u)
#define CSL_DFE_BB_CFG1174_REG_RESETVAL (0x00000000u)

/* CFG1175 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txtdd_timer_ul2_15_0 : 16;
#else 
    Uint32 txtdd_timer_ul2_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1175_REG;

/* TX tdd optional second upllink interval following dl2 */
#define CSL_DFE_BB_CFG1175_REG_TXTDD_TIMER_UL2_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1175_REG_TXTDD_TIMER_UL2_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1175_REG_TXTDD_TIMER_UL2_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1175_REG_ADDR (0x0004125Cu)
#define CSL_DFE_BB_CFG1175_REG_RESETVAL (0x00000000u)

/* CFG1176 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txtdd_timer_dl3_23_16 : 8;
    Uint32 txtdd_timer_ul2_23_16 : 8;
#else 
    Uint32 txtdd_timer_ul2_23_16 : 8;
    Uint32 txtdd_timer_dl3_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1176_REG;

/*  */
#define CSL_DFE_BB_CFG1176_REG_TXTDD_TIMER_UL2_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG1176_REG_TXTDD_TIMER_UL2_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1176_REG_TXTDD_TIMER_UL2_23_16_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_BB_CFG1176_REG_TXTDD_TIMER_DL3_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG1176_REG_TXTDD_TIMER_DL3_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1176_REG_TXTDD_TIMER_DL3_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1176_REG_ADDR (0x00041260u)
#define CSL_DFE_BB_CFG1176_REG_RESETVAL (0x00000000u)

/* CFG1177 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txtdd_timer_dl3_15_0 : 16;
#else 
    Uint32 txtdd_timer_dl3_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1177_REG;

/* TX tdd optional third downlink interval following ul2 */
#define CSL_DFE_BB_CFG1177_REG_TXTDD_TIMER_DL3_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1177_REG_TXTDD_TIMER_DL3_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1177_REG_TXTDD_TIMER_DL3_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1177_REG_ADDR (0x00041264u)
#define CSL_DFE_BB_CFG1177_REG_RESETVAL (0x00000000u)

/* CFG1184 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 20;
    Uint32 rxtdd_ssel : 4;
    Uint32 rxtdd_ct_type : 4;
    Uint32 rsvd0 : 1;
    Uint32 rxtdd_datamode : 2;
    Uint32 rxtdd_en : 1;
#else 
    Uint32 rxtdd_en : 1;
    Uint32 rxtdd_datamode : 2;
    Uint32 rsvd0 : 1;
    Uint32 rxtdd_ct_type : 4;
    Uint32 rxtdd_ssel : 4;
    Uint32 rsvd1 : 20;
#endif 
} CSL_DFE_BB_CFG1184_REG;

/* RX tdd timer operation enable 0=off */
#define CSL_DFE_BB_CFG1184_REG_RXTDD_EN_MASK (0x00000001u)
#define CSL_DFE_BB_CFG1184_REG_RXTDD_EN_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1184_REG_RXTDD_EN_RESETVAL (0x00000000u)

/* In RX tdd mode data is zeroed at (notch filter) input when not uplink when bit is 0; formatter data zeroed when 1; When 2 the data is zeroed at the input of the BB and the buffer memory is stalled */
#define CSL_DFE_BB_CFG1184_REG_RXTDD_DATAMODE_MASK (0x00000006u)
#define CSL_DFE_BB_CFG1184_REG_RXTDD_DATAMODE_SHIFT (0x00000001u)
#define CSL_DFE_BB_CFG1184_REG_RXTDD_DATAMODE_RESETVAL (0x00000000u)

/* RX tdd carrier type used to count timing interval.   */
#define CSL_DFE_BB_CFG1184_REG_RXTDD_CT_TYPE_MASK (0x000000F0u)
#define CSL_DFE_BB_CFG1184_REG_RXTDD_CT_TYPE_SHIFT (0x00000004u)
#define CSL_DFE_BB_CFG1184_REG_RXTDD_CT_TYPE_RESETVAL (0x00000000u)

/* RX tdd sync select to start operation  */
#define CSL_DFE_BB_CFG1184_REG_RXTDD_SSEL_MASK (0x00000F00u)
#define CSL_DFE_BB_CFG1184_REG_RXTDD_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1184_REG_RXTDD_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1184_REG_ADDR (0x00041280u)
#define CSL_DFE_BB_CFG1184_REG_RESETVAL (0x00000000u)

/* CFG1185 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxtdd_delayfromsync_15_0 : 16;
#else 
    Uint32 rxtdd_delayfromsync_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1185_REG;

/* RX tdd interval in samples from sync to start of interval timer minus 1 sample. */
#define CSL_DFE_BB_CFG1185_REG_RXTDD_DELAYFROMSYNC_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1185_REG_RXTDD_DELAYFROMSYNC_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1185_REG_RXTDD_DELAYFROMSYNC_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1185_REG_ADDR (0x00041284u)
#define CSL_DFE_BB_CFG1185_REG_RESETVAL (0x00000000u)

/* CFG1186 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxtdd_timer_dl1_23_16 : 8;
    Uint32 rxtdd_delayfromsync_23_16 : 8;
#else 
    Uint32 rxtdd_delayfromsync_23_16 : 8;
    Uint32 rxtdd_timer_dl1_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1186_REG;

/*  */
#define CSL_DFE_BB_CFG1186_REG_RXTDD_DELAYFROMSYNC_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG1186_REG_RXTDD_DELAYFROMSYNC_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1186_REG_RXTDD_DELAYFROMSYNC_23_16_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_BB_CFG1186_REG_RXTDD_TIMER_DL1_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG1186_REG_RXTDD_TIMER_DL1_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1186_REG_RXTDD_TIMER_DL1_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1186_REG_ADDR (0x00041288u)
#define CSL_DFE_BB_CFG1186_REG_RESETVAL (0x00000000u)

/* CFG1187 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxtdd_timer_dl1_15_0 : 16;
#else 
    Uint32 rxtdd_timer_dl1_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1187_REG;

/* RX tdd initial downlink interval */
#define CSL_DFE_BB_CFG1187_REG_RXTDD_TIMER_DL1_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1187_REG_RXTDD_TIMER_DL1_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1187_REG_RXTDD_TIMER_DL1_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1187_REG_ADDR (0x0004128Cu)
#define CSL_DFE_BB_CFG1187_REG_RESETVAL (0x00000000u)

/* CFG1188 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxtdd_timer_ul1_15_0 : 16;
#else 
    Uint32 rxtdd_timer_ul1_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1188_REG;

/* RX tdd initial upllink interval following dl1 */
#define CSL_DFE_BB_CFG1188_REG_RXTDD_TIMER_UL1_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1188_REG_RXTDD_TIMER_UL1_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1188_REG_RXTDD_TIMER_UL1_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1188_REG_ADDR (0x00041290u)
#define CSL_DFE_BB_CFG1188_REG_RESETVAL (0x00000000u)

/* CFG1189 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxtdd_timer_dl2_23_16 : 8;
    Uint32 rxtdd_timer_ul1_23_16 : 8;
#else 
    Uint32 rxtdd_timer_ul1_23_16 : 8;
    Uint32 rxtdd_timer_dl2_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1189_REG;

/*  */
#define CSL_DFE_BB_CFG1189_REG_RXTDD_TIMER_UL1_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG1189_REG_RXTDD_TIMER_UL1_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1189_REG_RXTDD_TIMER_UL1_23_16_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_BB_CFG1189_REG_RXTDD_TIMER_DL2_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG1189_REG_RXTDD_TIMER_DL2_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1189_REG_RXTDD_TIMER_DL2_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1189_REG_ADDR (0x00041294u)
#define CSL_DFE_BB_CFG1189_REG_RESETVAL (0x00000000u)

/* CFG1190 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxtdd_timer_dl2_15_0 : 16;
#else 
    Uint32 rxtdd_timer_dl2_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1190_REG;

/* RX tdd optional second downlink interval following ul1 */
#define CSL_DFE_BB_CFG1190_REG_RXTDD_TIMER_DL2_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1190_REG_RXTDD_TIMER_DL2_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1190_REG_RXTDD_TIMER_DL2_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1190_REG_ADDR (0x00041298u)
#define CSL_DFE_BB_CFG1190_REG_RESETVAL (0x00000000u)

/* CFG1191 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxtdd_timer_ul2_15_0 : 16;
#else 
    Uint32 rxtdd_timer_ul2_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1191_REG;

/* RX tdd optional second upllink interval following dl2 */
#define CSL_DFE_BB_CFG1191_REG_RXTDD_TIMER_UL2_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1191_REG_RXTDD_TIMER_UL2_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1191_REG_RXTDD_TIMER_UL2_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1191_REG_ADDR (0x0004129Cu)
#define CSL_DFE_BB_CFG1191_REG_RESETVAL (0x00000000u)

/* CFG1192 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxtdd_timer_dl3_23_16 : 8;
    Uint32 rxtdd_timer_ul2_23_16 : 8;
#else 
    Uint32 rxtdd_timer_ul2_23_16 : 8;
    Uint32 rxtdd_timer_dl3_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1192_REG;

/*  */
#define CSL_DFE_BB_CFG1192_REG_RXTDD_TIMER_UL2_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CFG1192_REG_RXTDD_TIMER_UL2_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1192_REG_RXTDD_TIMER_UL2_23_16_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_BB_CFG1192_REG_RXTDD_TIMER_DL3_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_CFG1192_REG_RXTDD_TIMER_DL3_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_CFG1192_REG_RXTDD_TIMER_DL3_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1192_REG_ADDR (0x000412A0u)
#define CSL_DFE_BB_CFG1192_REG_RESETVAL (0x00000000u)

/* CFG1193 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxtdd_timer_dl3_15_0 : 16;
#else 
    Uint32 rxtdd_timer_dl3_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CFG1193_REG;

/* RX tdd optional third downlink interval following ul2 */
#define CSL_DFE_BB_CFG1193_REG_RXTDD_TIMER_DL3_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CFG1193_REG_RXTDD_TIMER_DL3_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CFG1193_REG_RXTDD_TIMER_DL3_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CFG1193_REG_ADDR (0x000412A4u)
#define CSL_DFE_BB_CFG1193_REG_RESETVAL (0x00000000u)

/* CLKGATE_TIME_STEP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step_15_0 : 16;
#else 
    Uint32 time_step_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CLKGATE_TIME_STEP_LO_REG;

/* DUC N domain Farrow-style time accumulation word. Gates off a clock when it overflows. This removes one clock out of every (2^31)/time_step clocks. Put another way: multiplies the clock rate by ((2^31)-time_step)/(2^31). */
#define CSL_DFE_BB_CLKGATE_TIME_STEP_LO_REG_TIME_STEP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CLKGATE_TIME_STEP_LO_REG_TIME_STEP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_TIME_STEP_LO_REG_TIME_STEP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_TIME_STEP_LO_REG_ADDR (0x00041400u)
#define CSL_DFE_BB_CLKGATE_TIME_STEP_LO_REG_RESETVAL (0x00000000u)

/* CLKGATE_TIME_STEP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 time_step_31_16 : 16;
#else 
    Uint32 time_step_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CLKGATE_TIME_STEP_HI_REG;

/*  */
#define CSL_DFE_BB_CLKGATE_TIME_STEP_HI_REG_TIME_STEP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CLKGATE_TIME_STEP_HI_REG_TIME_STEP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_TIME_STEP_HI_REG_TIME_STEP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_TIME_STEP_HI_REG_ADDR (0x00041404u)
#define CSL_DFE_BB_CLKGATE_TIME_STEP_HI_REG_RESETVAL (0x00000000u)

/* CLKGATE_RESET_INT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 reset_int_15_0 : 16;
#else 
    Uint32 reset_int_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CLKGATE_RESET_INT_LO_REG;

/* DUC N domain Farrow-style reset interval. Resets the time accumulator every reset_int plus 1 clocks (resetting also counts as an overflow, so it gates a clock). If 0, then reset is disabled. If the output clock is N/D the rate of the ungated clock, then this should be set to D-1. */
#define CSL_DFE_BB_CLKGATE_RESET_INT_LO_REG_RESET_INT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CLKGATE_RESET_INT_LO_REG_RESET_INT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_RESET_INT_LO_REG_RESET_INT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_RESET_INT_LO_REG_ADDR (0x00041408u)
#define CSL_DFE_BB_CLKGATE_RESET_INT_LO_REG_RESETVAL (0x00000000u)

/* CLKGATE_RESET_INT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 resetl_int_31_16 : 16;
#else 
    Uint32 resetl_int_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CLKGATE_RESET_INT_HI_REG;

/*  */
#define CSL_DFE_BB_CLKGATE_RESET_INT_HI_REG_RESETL_INT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CLKGATE_RESET_INT_HI_REG_RESETL_INT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_RESET_INT_HI_REG_RESETL_INT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_RESET_INT_HI_REG_ADDR (0x0004140Cu)
#define CSL_DFE_BB_CLKGATE_RESET_INT_HI_REG_RESETVAL (0x00000000u)

/* CLKGATE_TDD_PERIOD_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_period_15_0 : 16;
#else 
    Uint32 tdd_period_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CLKGATE_TDD_PERIOD_LO_REG;

/* DUC N domain TDD count period. Counts from 0 to programmed value and repeats. */
#define CSL_DFE_BB_CLKGATE_TDD_PERIOD_LO_REG_TDD_PERIOD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CLKGATE_TDD_PERIOD_LO_REG_TDD_PERIOD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_TDD_PERIOD_LO_REG_TDD_PERIOD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_TDD_PERIOD_LO_REG_ADDR (0x00041410u)
#define CSL_DFE_BB_CLKGATE_TDD_PERIOD_LO_REG_RESETVAL (0x00000000u)

/* CLKGATE_TDD_PERIOD_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_period_23_16 : 8;
#else 
    Uint32 tdd_period_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CLKGATE_TDD_PERIOD_HI_REG;

/*  */
#define CSL_DFE_BB_CLKGATE_TDD_PERIOD_HI_REG_TDD_PERIOD_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CLKGATE_TDD_PERIOD_HI_REG_TDD_PERIOD_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_TDD_PERIOD_HI_REG_TDD_PERIOD_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_TDD_PERIOD_HI_REG_ADDR (0x00041414u)
#define CSL_DFE_BB_CLKGATE_TDD_PERIOD_HI_REG_RESETVAL (0x00000000u)

/* CLKGATE_ON_0_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_0_15_0 : 16;
#else 
    Uint32 tdd_on_0_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CLKGATE_ON_0_LO_REG;

/* DUC N domain TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_BB_CLKGATE_ON_0_LO_REG_TDD_ON_0_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CLKGATE_ON_0_LO_REG_TDD_ON_0_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_ON_0_LO_REG_TDD_ON_0_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_ON_0_LO_REG_ADDR (0x00041418u)
#define CSL_DFE_BB_CLKGATE_ON_0_LO_REG_RESETVAL (0x00000000u)

/* CLKGATE_ON_0_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_0_23_16 : 8;
#else 
    Uint32 tdd_on_0_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CLKGATE_ON_0_HI_REG;

/*  */
#define CSL_DFE_BB_CLKGATE_ON_0_HI_REG_TDD_ON_0_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CLKGATE_ON_0_HI_REG_TDD_ON_0_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_ON_0_HI_REG_TDD_ON_0_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_ON_0_HI_REG_ADDR (0x0004141Cu)
#define CSL_DFE_BB_CLKGATE_ON_0_HI_REG_RESETVAL (0x00000000u)

/* CLKGATE_OFF_0_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_0_15_0 : 16;
#else 
    Uint32 tdd_off_0_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CLKGATE_OFF_0_LO_REG;

/* DUC N domain TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_BB_CLKGATE_OFF_0_LO_REG_TDD_OFF_0_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CLKGATE_OFF_0_LO_REG_TDD_OFF_0_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_OFF_0_LO_REG_TDD_OFF_0_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_OFF_0_LO_REG_ADDR (0x00041420u)
#define CSL_DFE_BB_CLKGATE_OFF_0_LO_REG_RESETVAL (0x00000000u)

/* CLKGATE_OFF_0_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_0_23_16 : 8;
#else 
    Uint32 tdd_off_0_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CLKGATE_OFF_0_HI_REG;

/*  */
#define CSL_DFE_BB_CLKGATE_OFF_0_HI_REG_TDD_OFF_0_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CLKGATE_OFF_0_HI_REG_TDD_OFF_0_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_OFF_0_HI_REG_TDD_OFF_0_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_OFF_0_HI_REG_ADDR (0x00041424u)
#define CSL_DFE_BB_CLKGATE_OFF_0_HI_REG_RESETVAL (0x00000000u)

/* CLKGATE_ON_1_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_on_1_15_0 : 16;
#else 
    Uint32 tdd_on_1_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CLKGATE_ON_1_LO_REG;

/* DUC N domain TDD on time. Turns on clocks when counter hits this value. Remains on until it his an off time. */
#define CSL_DFE_BB_CLKGATE_ON_1_LO_REG_TDD_ON_1_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CLKGATE_ON_1_LO_REG_TDD_ON_1_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_ON_1_LO_REG_TDD_ON_1_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_ON_1_LO_REG_ADDR (0x00041428u)
#define CSL_DFE_BB_CLKGATE_ON_1_LO_REG_RESETVAL (0x00000000u)

/* CLKGATE_ON_1_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_on_1_23_16 : 8;
#else 
    Uint32 tdd_on_1_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CLKGATE_ON_1_HI_REG;

/*  */
#define CSL_DFE_BB_CLKGATE_ON_1_HI_REG_TDD_ON_1_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CLKGATE_ON_1_HI_REG_TDD_ON_1_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_ON_1_HI_REG_TDD_ON_1_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_ON_1_HI_REG_ADDR (0x0004142Cu)
#define CSL_DFE_BB_CLKGATE_ON_1_HI_REG_RESETVAL (0x00000000u)

/* CLKGATE_OFF_1_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd_off_1_15_0 : 16;
#else 
    Uint32 tdd_off_1_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_CLKGATE_OFF_1_LO_REG;

/* DUC N domain TDD off time. Turns off clocks when counter hits this value. Remains off until it his an on time. */
#define CSL_DFE_BB_CLKGATE_OFF_1_LO_REG_TDD_OFF_1_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_CLKGATE_OFF_1_LO_REG_TDD_OFF_1_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_OFF_1_LO_REG_TDD_OFF_1_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_OFF_1_LO_REG_ADDR (0x00041430u)
#define CSL_DFE_BB_CLKGATE_OFF_1_LO_REG_RESETVAL (0x00000000u)

/* CLKGATE_OFF_1_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tdd_off_1_23_16 : 8;
#else 
    Uint32 tdd_off_1_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_CLKGATE_OFF_1_HI_REG;

/*  */
#define CSL_DFE_BB_CLKGATE_OFF_1_HI_REG_TDD_OFF_1_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_CLKGATE_OFF_1_HI_REG_TDD_OFF_1_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_CLKGATE_OFF_1_HI_REG_TDD_OFF_1_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_CLKGATE_OFF_1_HI_REG_ADDR (0x00041434u)
#define CSL_DFE_BB_CLKGATE_OFF_1_HI_REG_RESETVAL (0x00000000u)

/* INTMASK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txpwr : 16;
#else 
    Uint32 txpwr : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTMASK0_REG;

/* TX power meter Interrupt Mask */
#define CSL_DFE_BB_INTMASK0_REG_TXPWR_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTMASK0_REG_TXPWR_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTMASK0_REG_TXPWR_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTMASK0_REG_ADDR (0x00041800u)
#define CSL_DFE_BB_INTMASK0_REG_RESETVAL (0x00000000u)

/* INTSTATUS0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txpwr : 16;
#else 
    Uint32 txpwr : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTSTATUS0_REG;

/* TX power meter Interrupt Status Word */
#define CSL_DFE_BB_INTSTATUS0_REG_TXPWR_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTSTATUS0_REG_TXPWR_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTSTATUS0_REG_TXPWR_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTSTATUS0_REG_ADDR (0x00041804u)
#define CSL_DFE_BB_INTSTATUS0_REG_RESETVAL (0x00000000u)

/* INTFORCE0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txpwr : 16;
#else 
    Uint32 txpwr : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTFORCE0_REG;

/* TX power meter Interrupt Force Word */
#define CSL_DFE_BB_INTFORCE0_REG_TXPWR_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTFORCE0_REG_TXPWR_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTFORCE0_REG_TXPWR_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTFORCE0_REG_ADDR (0x00041808u)
#define CSL_DFE_BB_INTFORCE0_REG_RESETVAL (0x00000000u)

/* INTMASK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxpwr : 16;
#else 
    Uint32 rxpwr : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTMASK1_REG;

/* RX power meter Interrupt Mask */
#define CSL_DFE_BB_INTMASK1_REG_RXPWR_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTMASK1_REG_RXPWR_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTMASK1_REG_RXPWR_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTMASK1_REG_ADDR (0x00041840u)
#define CSL_DFE_BB_INTMASK1_REG_RESETVAL (0x00000000u)

/* INTSTATUS1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxpwr : 16;
#else 
    Uint32 rxpwr : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTSTATUS1_REG;

/* RX power meter Interrupt Status Word */
#define CSL_DFE_BB_INTSTATUS1_REG_RXPWR_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTSTATUS1_REG_RXPWR_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTSTATUS1_REG_RXPWR_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTSTATUS1_REG_ADDR (0x00041844u)
#define CSL_DFE_BB_INTSTATUS1_REG_RESETVAL (0x00000000u)

/* INTFORCE1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxpwr : 16;
#else 
    Uint32 rxpwr : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTFORCE1_REG;

/* RX power meter Interrupt Force Word */
#define CSL_DFE_BB_INTFORCE1_REG_RXPWR_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTFORCE1_REG_RXPWR_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTFORCE1_REG_RXPWR_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTFORCE1_REG_ADDR (0x00041848u)
#define CSL_DFE_BB_INTFORCE1_REG_RESETVAL (0x00000000u)

/* INTMASK2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txgain : 16;
#else 
    Uint32 txgain : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTMASK2_REG;

/* TX Gain Update Complete Interrupt Mask */
#define CSL_DFE_BB_INTMASK2_REG_TXGAIN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTMASK2_REG_TXGAIN_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTMASK2_REG_TXGAIN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTMASK2_REG_ADDR (0x00041880u)
#define CSL_DFE_BB_INTMASK2_REG_RESETVAL (0x00000000u)

/* INTSTATUS2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txgain : 16;
#else 
    Uint32 txgain : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTSTATUS2_REG;

/* TX Gain Update Complete Interrupt Status Word */
#define CSL_DFE_BB_INTSTATUS2_REG_TXGAIN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTSTATUS2_REG_TXGAIN_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTSTATUS2_REG_TXGAIN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTSTATUS2_REG_ADDR (0x00041884u)
#define CSL_DFE_BB_INTSTATUS2_REG_RESETVAL (0x00000000u)

/* INTFORCE2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 txgain : 16;
#else 
    Uint32 txgain : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTFORCE2_REG;

/* TX Gain Update Complete Interrupt Force Word */
#define CSL_DFE_BB_INTFORCE2_REG_TXGAIN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTFORCE2_REG_TXGAIN_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTFORCE2_REG_TXGAIN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTFORCE2_REG_ADDR (0x00041888u)
#define CSL_DFE_BB_INTFORCE2_REG_RESETVAL (0x00000000u)

/* INTMASK3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxgain : 16;
#else 
    Uint32 rxgain : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTMASK3_REG;

/* RX Gain Update Complete Interrupt Mask */
#define CSL_DFE_BB_INTMASK3_REG_RXGAIN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTMASK3_REG_RXGAIN_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTMASK3_REG_RXGAIN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTMASK3_REG_ADDR (0x000418C0u)
#define CSL_DFE_BB_INTMASK3_REG_RESETVAL (0x00000000u)

/* INTSTATUS3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxgain : 16;
#else 
    Uint32 rxgain : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTSTATUS3_REG;

/* RX Gain Update Complete Interrupt Status Word */
#define CSL_DFE_BB_INTSTATUS3_REG_RXGAIN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTSTATUS3_REG_RXGAIN_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTSTATUS3_REG_RXGAIN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTSTATUS3_REG_ADDR (0x000418C4u)
#define CSL_DFE_BB_INTSTATUS3_REG_RESETVAL (0x00000000u)

/* INTFORCE3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 rxgain : 16;
#else 
    Uint32 rxgain : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTFORCE3_REG;

/* RX Gain Update Complete Interrupt Force Word */
#define CSL_DFE_BB_INTFORCE3_REG_RXGAIN_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTFORCE3_REG_RXGAIN_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTFORCE3_REG_RXGAIN_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTFORCE3_REG_ADDR (0x000418C8u)
#define CSL_DFE_BB_INTFORCE3_REG_RESETVAL (0x00000000u)

/* INTMASK4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bb_15_0 : 16;
#else 
    Uint32 bb_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTMASK4_REG;

/* BB General Interrupt Mask;   0=TX pwr meter lderr int, 1=RX pwr meter lderr int, 2=Antenna Cal complete int, 3=RX notch filter update complete int, 4=RX notch filter err (resource conflict), 7:5=0, 15:8= buffer memory[7:0] overflow/underflow, 16=rxaid sync err int, 17= txaid buffer underflow int, 18= txaid buffer overflow int, 19= jesd rx sync err int, 20= jesd tx buffer underflow, 21=jesd tx buffer overflow int */
#define CSL_DFE_BB_INTMASK4_REG_BB_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTMASK4_REG_BB_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTMASK4_REG_BB_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTMASK4_REG_ADDR (0x00041900u)
#define CSL_DFE_BB_INTMASK4_REG_RESETVAL (0x00000000u)

/* INTMASK4A */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bb_31_16 : 16;
#else 
    Uint32 bb_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTMASK4A_REG;

/* BB General Interrupt Mask.  See above */
#define CSL_DFE_BB_INTMASK4A_REG_BB_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTMASK4A_REG_BB_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTMASK4A_REG_BB_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTMASK4A_REG_ADDR (0x00041904u)
#define CSL_DFE_BB_INTMASK4A_REG_RESETVAL (0x00000000u)

/* INTSTATUS4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bb_15_0 : 16;
#else 
    Uint32 bb_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTSTATUS4_REG;

/* BB General Interrupt status word.  See above for pin definitions */
#define CSL_DFE_BB_INTSTATUS4_REG_BB_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTSTATUS4_REG_BB_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTSTATUS4_REG_BB_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTSTATUS4_REG_ADDR (0x00041908u)
#define CSL_DFE_BB_INTSTATUS4_REG_RESETVAL (0x00000000u)

/* INTSTATUS4A */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bb_31_16 : 16;
#else 
    Uint32 bb_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTSTATUS4A_REG;

/* BB General Interrupt status word.  See above for pin definitions */
#define CSL_DFE_BB_INTSTATUS4A_REG_BB_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTSTATUS4A_REG_BB_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTSTATUS4A_REG_BB_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTSTATUS4A_REG_ADDR (0x0004190Cu)
#define CSL_DFE_BB_INTSTATUS4A_REG_RESETVAL (0x00000000u)

/* INTFORCE4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bb_15_0 : 16;
#else 
    Uint32 bb_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTFORCE4_REG;

/* BB General Interrupt force word.  See above for pin definitions */
#define CSL_DFE_BB_INTFORCE4_REG_BB_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTFORCE4_REG_BB_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTFORCE4_REG_BB_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTFORCE4_REG_ADDR (0x00041910u)
#define CSL_DFE_BB_INTFORCE4_REG_RESETVAL (0x00000000u)

/* INTFORCE4A */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 bb_31_16 : 16;
#else 
    Uint32 bb_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_INTFORCE4A_REG;

/* BB General Interrupt force word.  See above for pin definitions */
#define CSL_DFE_BB_INTFORCE4A_REG_BB_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_INTFORCE4A_REG_BB_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_INTFORCE4A_REG_BB_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_INTFORCE4A_REG_ADDR (0x00041914u)
#define CSL_DFE_BB_INTFORCE4A_REG_RESETVAL (0x00000000u)

/* BBTXIF_AXC_CONFIG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 axc_valid : 1;
    Uint32 gain_en : 1;
    Uint32 cl_en : 1;
    Uint32 pm_en : 1;
    Uint32 pm_config_sel : 4;
    Uint32 buffer_num : 4;
    Uint32 buffer_index : 4;
#else 
    Uint32 buffer_index : 4;
    Uint32 buffer_num : 4;
    Uint32 pm_config_sel : 4;
    Uint32 pm_en : 1;
    Uint32 cl_en : 1;
    Uint32 gain_en : 1;
    Uint32 axc_valid : 1;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG;

/* Per antenna carrier (0:71) index into buffer memory the carrier is assigned to */
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_BUFFER_INDEX_MASK (0x0000000Fu)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_BUFFER_INDEX_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_BUFFER_INDEX_RESETVAL (0x00000000u)

/* Per antenna carrier buffer the carrier is assigned to */
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_BUFFER_NUM_MASK (0x000000F0u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_BUFFER_NUM_SHIFT (0x00000004u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_BUFFER_NUM_RESETVAL (0x00000000u)

/* Per antenna carrier selection of 1 of 16 power meter configurations the carrier is assigned to. */
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_PM_CONFIG_SEL_MASK (0x00000F00u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_PM_CONFIG_SEL_SHIFT (0x00000008u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_PM_CONFIG_SEL_RESETVAL (0x00000000u)

/* Per antenna carrier enable of power meter function */
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_PM_EN_MASK (0x00001000u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_PM_EN_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_PM_EN_RESETVAL (0x00000000u)

/* Per antenna carrier enable of the circular clipper function */
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_CL_EN_MASK (0x00002000u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_CL_EN_SHIFT (0x0000000Du)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_CL_EN_RESETVAL (0x00000000u)

/* Per antenna carrier enable of the gain function (otherwise unity gain) */
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_GAIN_EN_MASK (0x00004000u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_GAIN_EN_SHIFT (0x0000000Eu)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_GAIN_EN_RESETVAL (0x00000000u)

/* Per antenna carrier enable.  When disabled carrier is ignored */
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_AXC_VALID_MASK (0x00008000u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_AXC_VALID_SHIFT (0x0000000Fu)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_AXC_VALID_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_ADDR (0x00060000u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG0_REG_RESETVAL (0x00000000u)

/* BBTXIF_AXC_CONFIG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cl_1overt : 16;
#else 
    Uint32 cl_1overt : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBTXIF_AXC_CONFIG1_REG;

/* Per antenna carrier 1/T value to be used when circular clipper is enabled. */
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG1_REG_CL_1OVERT_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG1_REG_CL_1OVERT_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG1_REG_CL_1OVERT_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBTXIF_AXC_CONFIG1_REG_ADDR (0x00060004u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG1_REG_RESETVAL (0x00000000u)

/* BBTXIF_AXC_CONFIG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 25;
    Uint32 autocp_sel : 1;
    Uint32 autocp_en : 1;
    Uint32 antcal_en : 1;
    Uint32 antcal_sel : 4;
#else 
    Uint32 antcal_sel : 4;
    Uint32 antcal_en : 1;
    Uint32 autocp_en : 1;
    Uint32 autocp_sel : 1;
    Uint32 rsvd0 : 25;
#endif 
} CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG;

/* Per antenna carrier antenna calibration select. */
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_ANTCAL_SEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_ANTCAL_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_ANTCAL_SEL_RESETVAL (0x00000000u)

/* Per antenna carrier antenna calibration enable. */
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_ANTCAL_EN_MASK (0x00000010u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_ANTCAL_EN_SHIFT (0x00000004u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_ANTCAL_EN_RESETVAL (0x00000000u)

/* Per antenna carrier enable of autoCP mode. */
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_AUTOCP_EN_MASK (0x00000020u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_AUTOCP_EN_SHIFT (0x00000005u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_AUTOCP_EN_RESETVAL (0x00000000u)

/* Per antenna carrier selection of autoCP timer (one of two choices). */
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_AUTOCP_SEL_MASK (0x00000040u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_AUTOCP_SEL_SHIFT (0x00000006u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_AUTOCP_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_ADDR (0x00060008u)
#define CSL_DFE_BB_BBTXIF_AXC_CONFIG2_REG_RESETVAL (0x00000000u)

/* BBRXIF_AXC_CONFIG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 axc_valid : 1;
    Uint32 beagc_mode : 3;
    Uint32 carrier_type : 4;
    Uint32 buffer_num : 4;
    Uint32 buffer_index : 4;
#else 
    Uint32 buffer_index : 4;
    Uint32 buffer_num : 4;
    Uint32 carrier_type : 4;
    Uint32 beagc_mode : 3;
    Uint32 axc_valid : 1;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG;

/* Per antenna carrier (0:47) index into buffer memory the carrier is assigned to */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_BUFFER_INDEX_MASK (0x0000000Fu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_BUFFER_INDEX_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_BUFFER_INDEX_RESETVAL (0x00000000u)

/* Per antenna carrier buffer the carrier is assigned to */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_BUFFER_NUM_MASK (0x000000F0u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_BUFFER_NUM_SHIFT (0x00000004u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_BUFFER_NUM_RESETVAL (0x00000000u)

/* Per antenna carrier assignment of the carrier type. */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_CARRIER_TYPE_MASK (0x00000F00u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_CARRIER_TYPE_SHIFT (0x00000008u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_CARRIER_TYPE_RESETVAL (0x00000000u)

/* Per antenna carrier selection of AGC mode.  */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_BEAGC_MODE_MASK (0x00007000u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_BEAGC_MODE_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_BEAGC_MODE_RESETVAL (0x00000000u)

/* Per antenna carrier enable.  When disabled carrier is ignored even if there is a slot assigned to it. */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_AXC_VALID_MASK (0x00008000u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_AXC_VALID_SHIFT (0x0000000Fu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_AXC_VALID_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_ADDR (0x00060800u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG0_REG_RESETVAL (0x00000000u)

/* BBRXIF_AXC_CONFIG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 out_num_bits : 4;
    Uint32 fixedorfloat : 1;
    Uint32 out_float_mode : 2;
    Uint32 out_packed : 1;
    Uint32 notch_en : 3;
    Uint32 pm_en : 1;
    Uint32 pm_config_sel : 4;
#else 
    Uint32 pm_config_sel : 4;
    Uint32 pm_en : 1;
    Uint32 notch_en : 3;
    Uint32 out_packed : 1;
    Uint32 out_float_mode : 2;
    Uint32 fixedorfloat : 1;
    Uint32 out_num_bits : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG;

/* Per antenna carrier selection of 1 of 16 power meter configurations the carrier is assigned to. */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_PM_CONFIG_SEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_PM_CONFIG_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_PM_CONFIG_SEL_RESETVAL (0x00000000u)

/* Per antenna carrier enable of power meter function */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_PM_EN_MASK (0x00000010u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_PM_EN_SHIFT (0x00000004u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_PM_EN_RESETVAL (0x00000000u)

/* Per antenna carrier selection of input notch filter configuration */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_NOTCH_EN_MASK (0x000000E0u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_NOTCH_EN_SHIFT (0x00000005u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_NOTCH_EN_RESETVAL (0x00000000u)

/* Per antenna carrier selection of 16 bit output packing (instead of 32 bit format) */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_OUT_PACKED_MASK (0x00000100u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_OUT_PACKED_SHIFT (0x00000008u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_OUT_PACKED_RESETVAL (0x00000000u)

/* Per antenna carrier selection of number of floating point bits when in float mode (set by fixedorfloat) */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_OUT_FLOAT_MODE_MASK (0x00000600u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_OUT_FLOAT_MODE_SHIFT (0x00000009u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_OUT_FLOAT_MODE_RESETVAL (0x00000000u)

/* Per antenna carrier selection of floating point mode for output */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_FIXEDORFLOAT_MASK (0x00000800u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_FIXEDORFLOAT_SHIFT (0x0000000Bu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_FIXEDORFLOAT_RESETVAL (0x00000000u)

/* Per antenna carrier selection of number of mantissa bits +1 the output will be rounded to. */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_OUT_NUM_BITS_MASK (0x0000F000u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_OUT_NUM_BITS_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_OUT_NUM_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_ADDR (0x00060804u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG1_REG_RESETVAL (0x00000000u)

/* BBRXIF_AXC_CONFIG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tdd0 : 1;
    Uint32 beagc_power_backoff : 10;
    Uint32 ant_cal_en : 1;
    Uint32 ant_cal_sel : 4;
#else 
    Uint32 ant_cal_sel : 4;
    Uint32 ant_cal_en : 1;
    Uint32 beagc_power_backoff : 10;
    Uint32 tdd0 : 1;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG;

/* Selects which of 16 antenna calibration configurations to use for the carrier */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_ANT_CAL_SEL_MASK (0x0000000Fu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_ANT_CAL_SEL_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_ANT_CAL_SEL_RESETVAL (0x00000000u)

/* Per antenna carrier enable of antenna calibration noise enable */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_ANT_CAL_EN_MASK (0x00000010u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_ANT_CAL_EN_SHIFT (0x00000004u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_ANT_CAL_EN_RESETVAL (0x00000000u)

/* Per antenna carrier power backoff value used when in power managed gain control mode */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_BEAGC_POWER_BACKOFF_MASK (0x00007FE0u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_BEAGC_POWER_BACKOFF_SHIFT (0x00000005u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_BEAGC_POWER_BACKOFF_RESETVAL (0x00000000u)

/* Per antenna carrier force output to zero when tdd is in DL */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_TDD0_MASK (0x00008000u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_TDD0_SHIFT (0x0000000Fu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_TDD0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_ADDR (0x00060808u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG2_REG_RESETVAL (0x00000000u)

/* BBRXIF_AXC_CONFIG4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t1_interval_7_0 : 8;
    Uint32 bbrxif_axc_config_spare : 1;
    Uint32 beagc_config_sel : 3;
    Uint32 beagc_t3_actv_cnt : 4;
#else 
    Uint32 beagc_t3_actv_cnt : 4;
    Uint32 beagc_config_sel : 3;
    Uint32 bbrxif_axc_config_spare : 1;
    Uint32 beagc_t1_interval_7_0 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG;

/* Per antenna carrier number of t3 intervals to run gain loop.  0=forever */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_BEAGC_T3_ACTV_CNT_MASK (0x0000000Fu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_BEAGC_T3_ACTV_CNT_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_BEAGC_T3_ACTV_CNT_RESETVAL (0x00000000u)

/* Per antenna carrier selection of 1 of 8 beagc loop configurations to be used when in beagc mode */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_BEAGC_CONFIG_SEL_MASK (0x00000070u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_BEAGC_CONFIG_SEL_SHIFT (0x00000004u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_BEAGC_CONFIG_SEL_RESETVAL (0x00000000u)

/* spare config memory  */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_BBRXIF_AXC_CONFIG_SPARE_MASK (0x00000080u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_BBRXIF_AXC_CONFIG_SPARE_SHIFT (0x00000007u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_BBRXIF_AXC_CONFIG_SPARE_RESETVAL (0x00000000u)

/* Per antenna carrier t1 interval when in beagc closed loop gain mode */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_BEAGC_T1_INTERVAL_7_0_MASK (0x0000FF00u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_BEAGC_T1_INTERVAL_7_0_SHIFT (0x00000008u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_BEAGC_T1_INTERVAL_7_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_ADDR (0x00060810u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG4_REG_RESETVAL (0x00000000u)

/* BBRXIF_AXC_CONFIG5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t1_interval_23_8 : 16;
#else 
    Uint32 beagc_t1_interval_23_8 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBRXIF_AXC_CONFIG5_REG;

/* Per antenna carrier t1 interval when in beagc closed loop gain mode */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG5_REG_BEAGC_T1_INTERVAL_23_8_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG5_REG_BEAGC_T1_INTERVAL_23_8_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG5_REG_BEAGC_T1_INTERVAL_23_8_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXIF_AXC_CONFIG5_REG_ADDR (0x00060814u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG5_REG_RESETVAL (0x00000000u)

/* BBRXIF_AXC_CONFIG6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 beagc_t2_interval_15_0 : 16;
#else 
    Uint32 beagc_t2_interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBRXIF_AXC_CONFIG6_REG;

/* Per antenna carrier t2 interval when in beagc closed loop gain mode */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG6_REG_BEAGC_T2_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG6_REG_BEAGC_T2_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG6_REG_BEAGC_T2_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXIF_AXC_CONFIG6_REG_ADDR (0x00060818u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG6_REG_RESETVAL (0x00000000u)

/* BBRXIF_AXC_CONFIG7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 beagc_t2_interval_23_16 : 8;
#else 
    Uint32 beagc_t2_interval_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_BBRXIF_AXC_CONFIG7_REG;

/* Per antenna carrier t2 interval when in beagc closed loop gain mode */
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG7_REG_BEAGC_T2_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG7_REG_BEAGC_T2_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG7_REG_BEAGC_T2_INTERVAL_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXIF_AXC_CONFIG7_REG_ADDR (0x0006081Cu)
#define CSL_DFE_BB_BBRXIF_AXC_CONFIG7_REG_RESETVAL (0x00000000u)

/* BBRXIF_SLOT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 25;
    Uint32 bbrxif_slot : 7;
#else 
    Uint32 bbrxif_slot : 7;
    Uint32 rsvd0 : 25;
#endif 
} CSL_DFE_BB_BBRXIF_SLOT_REG;

/* BBRXIF Slot Mapping Table.  One entry per BBIF cycle.  Holds AxC assignment.  Bit6 is set for unassigned slot */
#define CSL_DFE_BB_BBRXIF_SLOT_REG_BBRXIF_SLOT_MASK (0x0000007Fu)
#define CSL_DFE_BB_BBRXIF_SLOT_REG_BBRXIF_SLOT_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXIF_SLOT_REG_BBRXIF_SLOT_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXIF_SLOT_REG_ADDR (0x00061000u)
#define CSL_DFE_BB_BBRXIF_SLOT_REG_RESETVAL (0x00000000u)

/* BBRXGAIN_INTEGER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 integer : 16;
#else 
    Uint32 integer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBRXGAIN_INTEGER_REG;

/* Per antenna carrier setting of unsigned integer portion of fixed gain */
#define CSL_DFE_BB_BBRXGAIN_INTEGER_REG_INTEGER_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBRXGAIN_INTEGER_REG_INTEGER_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXGAIN_INTEGER_REG_INTEGER_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXGAIN_INTEGER_REG_ADDR (0x00061400u)
#define CSL_DFE_BB_BBRXGAIN_INTEGER_REG_RESETVAL (0x00000000u)

/* BBRXGAIN_FRACTION */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 fraction : 8;
#else 
    Uint32 fraction : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_BBRXGAIN_FRACTION_REG;

/* Per antenna carrier setting of 8 bit fractional portion of fixed gain */
#define CSL_DFE_BB_BBRXGAIN_FRACTION_REG_FRACTION_MASK (0x000000FFu)
#define CSL_DFE_BB_BBRXGAIN_FRACTION_REG_FRACTION_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXGAIN_FRACTION_REG_FRACTION_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXGAIN_FRACTION_REG_ADDR (0x00061404u)
#define CSL_DFE_BB_BBRXGAIN_FRACTION_REG_RESETVAL (0x00000000u)

/* BBTXGAIN_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 inphase : 16;
#else 
    Uint32 inphase : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBTXGAIN_I_REG;

/* Per antenna carrier setting of in-phase portion of signed complex fixed gain */
#define CSL_DFE_BB_BBTXGAIN_I_REG_INPHASE_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBTXGAIN_I_REG_INPHASE_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBTXGAIN_I_REG_INPHASE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBTXGAIN_I_REG_ADDR (0x00061800u)
#define CSL_DFE_BB_BBTXGAIN_I_REG_RESETVAL (0x00000000u)

/* BBTXGAIN_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 quadrature : 16;
#else 
    Uint32 quadrature : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBTXGAIN_Q_REG;

/* Per antenna carrier setting of quadrature portion of signed complex fixed gain */
#define CSL_DFE_BB_BBTXGAIN_Q_REG_QUADRATURE_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBTXGAIN_Q_REG_QUADRATURE_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBTXGAIN_Q_REG_QUADRATURE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBTXGAIN_Q_REG_ADDR (0x00061804u)
#define CSL_DFE_BB_BBTXGAIN_Q_REG_RESETVAL (0x00000000u)

/* AID_DL_XLATE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 dl_translate : 10;
#else 
    Uint32 dl_translate : 10;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_BB_AID_DL_XLATE_REG;

/* Down Link Stream ID translation table. Translates 256 AID stream ID to 72 internal AxC.  Bit[9:7] is strobe_type.  Bit[6:0] is remapped AxC number.  An AxC value of 0x3F invalidates input carrier (default). */
#define CSL_DFE_BB_AID_DL_XLATE_REG_DL_TRANSLATE_MASK (0x000003FFu)
#define CSL_DFE_BB_AID_DL_XLATE_REG_DL_TRANSLATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_AID_DL_XLATE_REG_DL_TRANSLATE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_AID_DL_XLATE_REG_ADDR (0x00061C00u)
#define CSL_DFE_BB_AID_DL_XLATE_REG_RESETVAL (0x00000000u)

/* AID_UL_XLATE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 ul_translate : 12;
#else 
    Uint32 ul_translate : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_AID_UL_XLATE_REG;

/* Up Link Stream ID translation table. Translates 48 internal AxCs to one of 256 AID streams.  Bits [11:8] map to carrier type of the AID stream. */
#define CSL_DFE_BB_AID_UL_XLATE_REG_UL_TRANSLATE_MASK (0x00000FFFu)
#define CSL_DFE_BB_AID_UL_XLATE_REG_UL_TRANSLATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_AID_UL_XLATE_REG_UL_TRANSLATE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_AID_UL_XLATE_REG_ADDR (0x00062000u)
#define CSL_DFE_BB_AID_UL_XLATE_REG_RESETVAL (0x00000000u)

/* BBTXIF_SLOT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 slot : 12;
#else 
    Uint32 slot : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_BBTXIF_SLOT_REG;

/* BBTXIF Slot Mapping Table.  One entry per BBTXIF sample.  Holds internal AxC assignment and carrier type for that AxC.  AxC assignment is in bits 6:0;  Bit7 is slot unassigned bit.  Carrier_type in 11:8 */
#define CSL_DFE_BB_BBTXIF_SLOT_REG_SLOT_MASK (0x00000FFFu)
#define CSL_DFE_BB_BBTXIF_SLOT_REG_SLOT_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBTXIF_SLOT_REG_SLOT_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBTXIF_SLOT_REG_ADDR (0x00062400u)
#define CSL_DFE_BB_BBTXIF_SLOT_REG_RESETVAL (0x00000000u)

/* JESD_DL_XLATE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 dl_translate : 10;
#else 
    Uint32 dl_translate : 10;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_BB_JESD_DL_XLATE_REG;

/* JESD Down Link Stream ID translation table. Translates 256 AID stream ID to 72 internal AxC.  Bit[9:7] is strobe_type.  Bit[6:0] is remapped AxC number.  An AxC value of 0x3F invalidates input carrier (default). */
#define CSL_DFE_BB_JESD_DL_XLATE_REG_DL_TRANSLATE_MASK (0x000003FFu)
#define CSL_DFE_BB_JESD_DL_XLATE_REG_DL_TRANSLATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_JESD_DL_XLATE_REG_DL_TRANSLATE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_JESD_DL_XLATE_REG_ADDR (0x00062800u)
#define CSL_DFE_BB_JESD_DL_XLATE_REG_RESETVAL (0x00000000u)

/* JESD_UL_XLATE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 ul_translate : 12;
#else 
    Uint32 ul_translate : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_JESD_UL_XLATE_REG;

/* JESD Up Link Stream ID translation table. Translates 48 internal AxCs to one of 256 AID streams.  Bit[7:0] is remapped AxC, Bit[11:8]= ct of carrier.  */
#define CSL_DFE_BB_JESD_UL_XLATE_REG_UL_TRANSLATE_MASK (0x00000FFFu)
#define CSL_DFE_BB_JESD_UL_XLATE_REG_UL_TRANSLATE_SHIFT (0x00000000u)
#define CSL_DFE_BB_JESD_UL_XLATE_REG_UL_TRANSLATE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_JESD_UL_XLATE_REG_ADDR (0x00062C00u)
#define CSL_DFE_BB_JESD_UL_XLATE_REG_RESETVAL (0x00000000u)

/* JESD_TXIF_SLOT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 slot : 12;
#else 
    Uint32 slot : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_JESD_TXIF_SLOT_REG;

/* JESD TXIF Slot Mapping Table.  One entry per BBTXIF sample.  Holds internal AxC assignment and carrier type for that AxC.  AxC assignment is in bits 6:0;  Bit7 is slot unassigned bit.  Carrier_type in bit8 where 0=normal ct, 1=variable slot type. */
#define CSL_DFE_BB_JESD_TXIF_SLOT_REG_SLOT_MASK (0x00000FFFu)
#define CSL_DFE_BB_JESD_TXIF_SLOT_REG_SLOT_SHIFT (0x00000000u)
#define CSL_DFE_BB_JESD_TXIF_SLOT_REG_SLOT_RESETVAL (0x00000000u)

#define CSL_DFE_BB_JESD_TXIF_SLOT_REG_ADDR (0x00063000u)
#define CSL_DFE_BB_JESD_TXIF_SLOT_REG_RESETVAL (0x00000000u)

/* JESD_RXIF_SLOT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 slot : 12;
#else 
    Uint32 slot : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_JESD_RXIF_SLOT_REG;

/* JESD RXIF Slot Mapping Table.  One entry per BBRXIF sample.  Holds internal AxC assignment and carrier type for that AxC.  AxC assignment is in bits 5:0;  Bit6 is slot unassigned bit.  Carrier_type in bit11:8; Bit 7=variable mode where 0=normal ct, 1=variable slot type. */
#define CSL_DFE_BB_JESD_RXIF_SLOT_REG_SLOT_MASK (0x00000FFFu)
#define CSL_DFE_BB_JESD_RXIF_SLOT_REG_SLOT_SHIFT (0x00000000u)
#define CSL_DFE_BB_JESD_RXIF_SLOT_REG_SLOT_RESETVAL (0x00000000u)

#define CSL_DFE_BB_JESD_RXIF_SLOT_REG_ADDR (0x00063400u)
#define CSL_DFE_BB_JESD_RXIF_SLOT_REG_RESETVAL (0x00000000u)

/* BBTXIF_LUT0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cl_lut_dc : 16;
#else 
    Uint32 cl_lut_dc : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBTXIF_LUT0_REG;

/* Circular clipper LUT value.  Even addresses are the direct lookup value */
#define CSL_DFE_BB_BBTXIF_LUT0_REG_CL_LUT_DC_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBTXIF_LUT0_REG_CL_LUT_DC_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBTXIF_LUT0_REG_CL_LUT_DC_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBTXIF_LUT0_REG_ADDR (0x00064000u)
#define CSL_DFE_BB_BBTXIF_LUT0_REG_RESETVAL (0x00000000u)

/* BBTXIF_LUT1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 cl_lut_slope : 10;
#else 
    Uint32 cl_lut_slope : 10;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_BB_BBTXIF_LUT1_REG;

/* Circular clipper LUT value.  Odd addresses are the slope of the curve for interpolation */
#define CSL_DFE_BB_BBTXIF_LUT1_REG_CL_LUT_SLOPE_MASK (0x000003FFu)
#define CSL_DFE_BB_BBTXIF_LUT1_REG_CL_LUT_SLOPE_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBTXIF_LUT1_REG_CL_LUT_SLOPE_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBTXIF_LUT1_REG_ADDR (0x00064004u)
#define CSL_DFE_BB_BBTXIF_LUT1_REG_RESETVAL (0x00000000u)

/* RXNOTCH_CONFIG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 filter2 : 6;
    Uint32 filter1 : 6;
    Uint32 axc_mode : 4;
#else 
    Uint32 axc_mode : 4;
    Uint32 filter1 : 6;
    Uint32 filter2 : 6;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_RXNOTCH_CONFIG1_REG;

/* Per AxC notch filter configuration */
#define CSL_DFE_BB_RXNOTCH_CONFIG1_REG_AXC_MODE_MASK (0x0000000Fu)
#define CSL_DFE_BB_RXNOTCH_CONFIG1_REG_AXC_MODE_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXNOTCH_CONFIG1_REG_AXC_MODE_RESETVAL (0x00000000u)

/* Per AxC notch filter1 tap select */
#define CSL_DFE_BB_RXNOTCH_CONFIG1_REG_FILTER1_MASK (0x000003F0u)
#define CSL_DFE_BB_RXNOTCH_CONFIG1_REG_FILTER1_SHIFT (0x00000004u)
#define CSL_DFE_BB_RXNOTCH_CONFIG1_REG_FILTER1_RESETVAL (0x00000000u)

/* Per AxC notch filter2 tap select */
#define CSL_DFE_BB_RXNOTCH_CONFIG1_REG_FILTER2_MASK (0x0000FC00u)
#define CSL_DFE_BB_RXNOTCH_CONFIG1_REG_FILTER2_SHIFT (0x0000000Au)
#define CSL_DFE_BB_RXNOTCH_CONFIG1_REG_FILTER2_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXNOTCH_CONFIG1_REG_ADDR (0x00065000u)
#define CSL_DFE_BB_RXNOTCH_CONFIG1_REG_RESETVAL (0x00000000u)

/* RXNOTCH_CONFIG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 filter4 : 6;
    Uint32 filter3 : 6;
#else 
    Uint32 filter3 : 6;
    Uint32 filter4 : 6;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_BB_RXNOTCH_CONFIG2_REG;

/* Per AxC notch filter3 tap select */
#define CSL_DFE_BB_RXNOTCH_CONFIG2_REG_FILTER3_MASK (0x0000003Fu)
#define CSL_DFE_BB_RXNOTCH_CONFIG2_REG_FILTER3_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXNOTCH_CONFIG2_REG_FILTER3_RESETVAL (0x00000000u)

/* Per AxC notch filter4 tap select */
#define CSL_DFE_BB_RXNOTCH_CONFIG2_REG_FILTER4_MASK (0x00000FC0u)
#define CSL_DFE_BB_RXNOTCH_CONFIG2_REG_FILTER4_SHIFT (0x00000006u)
#define CSL_DFE_BB_RXNOTCH_CONFIG2_REG_FILTER4_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXNOTCH_CONFIG2_REG_ADDR (0x00065004u)
#define CSL_DFE_BB_RXNOTCH_CONFIG2_REG_RESETVAL (0x00000000u)

/* RXNOTCHTAP0_CONFIG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tap0_i_15_0 : 16;
#else 
    Uint32 tap0_i_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_RXNOTCHTAP0_CONFIG0_REG;

/* Notch Filter0 I tap */
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG0_REG_TAP0_I_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG0_REG_TAP0_I_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG0_REG_TAP0_I_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG0_REG_ADDR (0x00065400u)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG0_REG_RESETVAL (0x00000000u)

/* RXNOTCHTAP0_CONFIG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tap0_i_23_16 : 8;
#else 
    Uint32 tap0_i_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_RXNOTCHTAP0_CONFIG1_REG;

/* Notch Filter0 I tap */
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG1_REG_TAP0_I_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG1_REG_TAP0_I_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG1_REG_TAP0_I_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG1_REG_ADDR (0x00065404u)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG1_REG_RESETVAL (0x00000000u)

/* RXNOTCHTAP0_CONFIG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tap0_q_15_0 : 16;
#else 
    Uint32 tap0_q_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_RXNOTCHTAP0_CONFIG2_REG;

/* Notch Filter0 Q tap */
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG2_REG_TAP0_Q_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG2_REG_TAP0_Q_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG2_REG_TAP0_Q_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG2_REG_ADDR (0x00065408u)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG2_REG_RESETVAL (0x00000000u)

/* RXNOTCHTAP0_CONFIG3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 18;
    Uint32 tap0_width : 6;
    Uint32 tap0_q_23_16 : 8;
#else 
    Uint32 tap0_q_23_16 : 8;
    Uint32 tap0_width : 6;
    Uint32 rsvd0 : 18;
#endif 
} CSL_DFE_BB_RXNOTCHTAP0_CONFIG3_REG;

/* Notch Filter0 Q tap */
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG3_REG_TAP0_Q_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG3_REG_TAP0_Q_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG3_REG_TAP0_Q_23_16_RESETVAL (0x00000000u)

/* Notch Filter0 notch width control */
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG3_REG_TAP0_WIDTH_MASK (0x00003F00u)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG3_REG_TAP0_WIDTH_SHIFT (0x00000008u)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG3_REG_TAP0_WIDTH_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG3_REG_ADDR (0x0006540Cu)
#define CSL_DFE_BB_RXNOTCHTAP0_CONFIG3_REG_RESETVAL (0x00000000u)

/* RXNOTCHTAP1_CONFIG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tap1_i_15_0 : 16;
#else 
    Uint32 tap1_i_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_RXNOTCHTAP1_CONFIG0_REG;

/* Notch Filter1 I tap */
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG0_REG_TAP1_I_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG0_REG_TAP1_I_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG0_REG_TAP1_I_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG0_REG_ADDR (0x00065800u)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG0_REG_RESETVAL (0x00000000u)

/* RXNOTCHTAP1_CONFIG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 tap1_i_23_16 : 8;
#else 
    Uint32 tap1_i_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_BB_RXNOTCHTAP1_CONFIG1_REG;

/* Notch Filter1 I tap */
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG1_REG_TAP1_I_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG1_REG_TAP1_I_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG1_REG_TAP1_I_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG1_REG_ADDR (0x00065804u)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG1_REG_RESETVAL (0x00000000u)

/* RXNOTCHTAP1_CONFIG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tap1_q_15_0 : 16;
#else 
    Uint32 tap1_q_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_RXNOTCHTAP1_CONFIG2_REG;

/* Notch Filter1 Q tap */
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG2_REG_TAP1_Q_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG2_REG_TAP1_Q_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG2_REG_TAP1_Q_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG2_REG_ADDR (0x00065808u)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG2_REG_RESETVAL (0x00000000u)

/* RXNOTCHTAP1_CONFIG3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 18;
    Uint32 tap1_width : 6;
    Uint32 tap1_q_23_16 : 8;
#else 
    Uint32 tap1_q_23_16 : 8;
    Uint32 tap1_width : 6;
    Uint32 rsvd0 : 18;
#endif 
} CSL_DFE_BB_RXNOTCHTAP1_CONFIG3_REG;

/* Notch Filter1 Q tap */
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG3_REG_TAP1_Q_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG3_REG_TAP1_Q_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG3_REG_TAP1_Q_23_16_RESETVAL (0x00000000u)

/* Notch Filter1 notch width control */
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG3_REG_TAP1_WIDTH_MASK (0x00003F00u)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG3_REG_TAP1_WIDTH_SHIFT (0x00000008u)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG3_REG_TAP1_WIDTH_RESETVAL (0x00000000u)

#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG3_REG_ADDR (0x0006580Cu)
#define CSL_DFE_BB_RXNOTCHTAP1_CONFIG3_REG_RESETVAL (0x00000000u)

/* BBTXPWRMETER_R0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBTXPWRMETER_R0_REG;

/* Peak power of Tx AxC y  (float value (10+6exponent), or dB value (compared to 1 with.1db resolution)), or dB value (compared to peak db) */
#define CSL_DFE_BB_BBTXPWRMETER_R0_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBTXPWRMETER_R0_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBTXPWRMETER_R0_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBTXPWRMETER_R0_REG_ADDR (0x00068000u)
#define CSL_DFE_BB_BBTXPWRMETER_R0_REG_RESETVAL (0x00000000u)

/* BBTXPWRMETER_R1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBTXPWRMETER_R1_REG;

/* Peak power of  of AxC y (extended float value (16 bit fractional portion of float value) */
#define CSL_DFE_BB_BBTXPWRMETER_R1_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBTXPWRMETER_R1_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBTXPWRMETER_R1_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBTXPWRMETER_R1_REG_ADDR (0x00068004u)
#define CSL_DFE_BB_BBTXPWRMETER_R1_REG_RESETVAL (0x00000000u)

/* BBTXPWRMETER_R2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_47_32 : 16;
#else 
    Uint32 result_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBTXPWRMETER_R2_REG;

/* RMS power of Tx AxC y.  (float value (10+6exponent), or dB value (compared to 1 with.1db resolution)), or dB value (compared to peak db) */
#define CSL_DFE_BB_BBTXPWRMETER_R2_REG_RESULT_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBTXPWRMETER_R2_REG_RESULT_47_32_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBTXPWRMETER_R2_REG_RESULT_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBTXPWRMETER_R2_REG_ADDR (0x00068008u)
#define CSL_DFE_BB_BBTXPWRMETER_R2_REG_RESETVAL (0x00000000u)

/* BBTXPWRMETER_R3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_63_0 : 16;
#else 
    Uint32 result_63_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBTXPWRMETER_R3_REG;

/* RMS power of  TX AxC y (extended float value (16 bit fractional portion of float value) */
#define CSL_DFE_BB_BBTXPWRMETER_R3_REG_RESULT_63_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBTXPWRMETER_R3_REG_RESULT_63_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBTXPWRMETER_R3_REG_RESULT_63_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBTXPWRMETER_R3_REG_ADDR (0x0006800Cu)
#define CSL_DFE_BB_BBTXPWRMETER_R3_REG_RESETVAL (0x00000000u)

/* BBRXPWRMETER_R0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_15_0 : 16;
#else 
    Uint32 result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBRXPWRMETER_R0_REG;

/* Peak power of Rx AxC y  (float value (10+6exponent), or dB value (compared to 1 with.1db resolution)), or dB value (compared to peak db) */
#define CSL_DFE_BB_BBRXPWRMETER_R0_REG_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBRXPWRMETER_R0_REG_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXPWRMETER_R0_REG_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXPWRMETER_R0_REG_ADDR (0x00069000u)
#define CSL_DFE_BB_BBRXPWRMETER_R0_REG_RESETVAL (0x00000000u)

/* BBRXPWRMETER_R1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_31_16 : 16;
#else 
    Uint32 result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBRXPWRMETER_R1_REG;

/* Peak power of  RX AxC y (extended float value (16 bit fractional portion of float value) */
#define CSL_DFE_BB_BBRXPWRMETER_R1_REG_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBRXPWRMETER_R1_REG_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXPWRMETER_R1_REG_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXPWRMETER_R1_REG_ADDR (0x00069004u)
#define CSL_DFE_BB_BBRXPWRMETER_R1_REG_RESETVAL (0x00000000u)

/* BBRXPWRMETER_R2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_47_32 : 16;
#else 
    Uint32 result_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBRXPWRMETER_R2_REG;

/* RMS power of Rx AxC y.  (float value (10+6exponent), or dB value (compared to 1 with.1db resolution)), or dB value (compared to peak db) */
#define CSL_DFE_BB_BBRXPWRMETER_R2_REG_RESULT_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBRXPWRMETER_R2_REG_RESULT_47_32_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXPWRMETER_R2_REG_RESULT_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXPWRMETER_R2_REG_ADDR (0x00069008u)
#define CSL_DFE_BB_BBRXPWRMETER_R2_REG_RESETVAL (0x00000000u)

/* BBRXPWRMETER_R3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 result_63_48 : 16;
#else 
    Uint32 result_63_48 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BBRXPWRMETER_R3_REG;

/* RMS power of  Rx AxC y (extended float value (16 bit fractional portion of float value) */
#define CSL_DFE_BB_BBRXPWRMETER_R3_REG_RESULT_63_48_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BBRXPWRMETER_R3_REG_RESULT_63_48_SHIFT (0x00000000u)
#define CSL_DFE_BB_BBRXPWRMETER_R3_REG_RESULT_63_48_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BBRXPWRMETER_R3_REG_ADDR (0x0006900Cu)
#define CSL_DFE_BB_BBRXPWRMETER_R3_REG_RESETVAL (0x00000000u)

/* BEAGC_CFG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 spare0 : 8;
    Uint32 thres : 8;
#else 
    Uint32 thres : 8;
    Uint32 spare0 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BEAGC_CFG0_REG;

/* beagc control loop configuration threshold value of AGC unsigned */
#define CSL_DFE_BB_BEAGC_CFG0_REG_THRES_MASK (0x000000FFu)
#define CSL_DFE_BB_BEAGC_CFG0_REG_THRES_SHIFT (0x00000000u)
#define CSL_DFE_BB_BEAGC_CFG0_REG_THRES_RESETVAL (0x00000000u)

/* beagc control loop configuration spare memory bits  */
#define CSL_DFE_BB_BEAGC_CFG0_REG_SPARE0_MASK (0x0000FF00u)
#define CSL_DFE_BB_BEAGC_CFG0_REG_SPARE0_SHIFT (0x00000008u)
#define CSL_DFE_BB_BEAGC_CFG0_REG_SPARE0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BEAGC_CFG0_REG_ADDR (0x0006C000u)
#define CSL_DFE_BB_BEAGC_CFG0_REG_RESETVAL (0x00000000u)

/* BEAGC_CFG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 spare1 : 4;
    Uint32 sat_thres : 4;
    Uint32 zero_thres : 4;
    Uint32 zero_mask : 4;
#else 
    Uint32 zero_mask : 4;
    Uint32 zero_thres : 4;
    Uint32 sat_thres : 4;
    Uint32 spare1 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BEAGC_CFG1_REG;

/* beagc control loop configuration zero_mask masks lower 4 bits for zero count, a 0 will mask off zero calculation */
#define CSL_DFE_BB_BEAGC_CFG1_REG_ZERO_MASK_MASK (0x0000000Fu)
#define CSL_DFE_BB_BEAGC_CFG1_REG_ZERO_MASK_SHIFT (0x00000000u)
#define CSL_DFE_BB_BEAGC_CFG1_REG_ZERO_MASK_RESETVAL (0x00000000u)

/* beagc control loop configuration  zero count threshold */
#define CSL_DFE_BB_BEAGC_CFG1_REG_ZERO_THRES_MASK (0x000000F0u)
#define CSL_DFE_BB_BEAGC_CFG1_REG_ZERO_THRES_SHIFT (0x00000004u)
#define CSL_DFE_BB_BEAGC_CFG1_REG_ZERO_THRES_RESETVAL (0x00000000u)

/* beagc control loop configuration saturation count threshold;  */
#define CSL_DFE_BB_BEAGC_CFG1_REG_SAT_THRES_MASK (0x00000F00u)
#define CSL_DFE_BB_BEAGC_CFG1_REG_SAT_THRES_SHIFT (0x00000008u)
#define CSL_DFE_BB_BEAGC_CFG1_REG_SAT_THRES_RESETVAL (0x00000000u)

/* beagc control loop configuration spare memory bits  */
#define CSL_DFE_BB_BEAGC_CFG1_REG_SPARE1_MASK (0x0000F000u)
#define CSL_DFE_BB_BEAGC_CFG1_REG_SPARE1_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_BEAGC_CFG1_REG_SPARE1_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BEAGC_CFG1_REG_ADDR (0x0006C004u)
#define CSL_DFE_BB_BEAGC_CFG1_REG_RESETVAL (0x00000000u)

/* BEAGC_CFG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dzri : 4;
    Uint32 dsat : 4;
    Uint32 dabv : 4;
    Uint32 dblw : 4;
#else 
    Uint32 dblw : 4;
    Uint32 dabv : 4;
    Uint32 dsat : 4;
    Uint32 dzri : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BEAGC_CFG2_REG;

/* beagc control loop configuration shift value for below threshold.  0=shift of 2 ... 15=shift of 17 */
#define CSL_DFE_BB_BEAGC_CFG2_REG_DBLW_MASK (0x0000000Fu)
#define CSL_DFE_BB_BEAGC_CFG2_REG_DBLW_SHIFT (0x00000000u)
#define CSL_DFE_BB_BEAGC_CFG2_REG_DBLW_RESETVAL (0x00000000u)

/* beagc control loop configuration shift value for above theshold.   0=shift of 2 ... 15=shift of 17 */
#define CSL_DFE_BB_BEAGC_CFG2_REG_DABV_MASK (0x000000F0u)
#define CSL_DFE_BB_BEAGC_CFG2_REG_DABV_SHIFT (0x00000004u)
#define CSL_DFE_BB_BEAGC_CFG2_REG_DABV_RESETVAL (0x00000000u)

/* beagc control loop configuration shift value for saturation.  0=shift of 2 ... 15=shift of 17 */
#define CSL_DFE_BB_BEAGC_CFG2_REG_DSAT_MASK (0x00000F00u)
#define CSL_DFE_BB_BEAGC_CFG2_REG_DSAT_SHIFT (0x00000008u)
#define CSL_DFE_BB_BEAGC_CFG2_REG_DSAT_RESETVAL (0x00000000u)

/* beagc control loop configuration shift value for zero case.  0=shift of 2 ... 15=shift of 17 */
#define CSL_DFE_BB_BEAGC_CFG2_REG_DZRI_MASK (0x0000F000u)
#define CSL_DFE_BB_BEAGC_CFG2_REG_DZRI_SHIFT (0x0000000Cu)
#define CSL_DFE_BB_BEAGC_CFG2_REG_DZRI_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BEAGC_CFG2_REG_ADDR (0x0006C008u)
#define CSL_DFE_BB_BEAGC_CFG2_REG_RESETVAL (0x00000000u)

/* BEAGC_CFG3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 amax_15_0 : 16;
#else 
    Uint32 amax_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BEAGC_CFG3_REG;

/* beagc control loop configuration maximum allowed gain adjustment value.  Adjustment stops at g(k)=G + amax Amax format is signed (1,16,7) */
#define CSL_DFE_BB_BEAGC_CFG3_REG_AMAX_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BEAGC_CFG3_REG_AMAX_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_BEAGC_CFG3_REG_AMAX_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BEAGC_CFG3_REG_ADDR (0x0006C00Cu)
#define CSL_DFE_BB_BEAGC_CFG3_REG_RESETVAL (0x00000000u)

/* BEAGC_CFG4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 amin_23_16 : 8;
    Uint32 amax_23_16 : 8;
#else 
    Uint32 amax_23_16 : 8;
    Uint32 amin_23_16 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BEAGC_CFG4_REG;

/* beagc control loop configurationamax[23:16] */
#define CSL_DFE_BB_BEAGC_CFG4_REG_AMAX_23_16_MASK (0x000000FFu)
#define CSL_DFE_BB_BEAGC_CFG4_REG_AMAX_23_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_BEAGC_CFG4_REG_AMAX_23_16_RESETVAL (0x00000000u)

/* beagc control loop configuration amin[23:16] */
#define CSL_DFE_BB_BEAGC_CFG4_REG_AMIN_23_16_MASK (0x0000FF00u)
#define CSL_DFE_BB_BEAGC_CFG4_REG_AMIN_23_16_SHIFT (0x00000008u)
#define CSL_DFE_BB_BEAGC_CFG4_REG_AMIN_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BEAGC_CFG4_REG_ADDR (0x0006C010u)
#define CSL_DFE_BB_BEAGC_CFG4_REG_RESETVAL (0x00000000u)

/* BEAGC_CFG5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 amin_15_0 : 16;
#else 
    Uint32 amin_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_BEAGC_CFG5_REG;

/* beagc control loop configuration minimum allowed gain adjustment value.   Adjustment stops at g(k)=G +  amin. Amin format is signed (1,16,7) */
#define CSL_DFE_BB_BEAGC_CFG5_REG_AMIN_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_BEAGC_CFG5_REG_AMIN_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_BEAGC_CFG5_REG_AMIN_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_BEAGC_CFG5_REG_ADDR (0x0006C014u)
#define CSL_DFE_BB_BEAGC_CFG5_REG_RESETVAL (0x00000000u)

/* ANTCALCORR_R0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 antcal_corr_i_15_0 : 16;
#else 
    Uint32 antcal_corr_i_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_ANTCALCORR_R0_REG;

/* Antenna Calibration RX correlation result.  64bits per correlation result.  16 results per antenna calibration unit.  Each correlation unit is offset by 64 addresses.  The correlation results are actually only 48 bits but they are aligned by 64 to aid in easy reading. */
#define CSL_DFE_BB_ANTCALCORR_R0_REG_ANTCAL_CORR_I_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_ANTCALCORR_R0_REG_ANTCAL_CORR_I_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_ANTCALCORR_R0_REG_ANTCAL_CORR_I_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_ANTCALCORR_R0_REG_ADDR (0x00070000u)
#define CSL_DFE_BB_ANTCALCORR_R0_REG_RESETVAL (0x00000000u)

/* ANTCALCORR_R1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 antcal_corr_i_31_16 : 16;
#else 
    Uint32 antcal_corr_i_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_ANTCALCORR_R1_REG;

/*  */
#define CSL_DFE_BB_ANTCALCORR_R1_REG_ANTCAL_CORR_I_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_ANTCALCORR_R1_REG_ANTCAL_CORR_I_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_ANTCALCORR_R1_REG_ANTCAL_CORR_I_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_ANTCALCORR_R1_REG_ADDR (0x00070004u)
#define CSL_DFE_BB_ANTCALCORR_R1_REG_RESETVAL (0x00000000u)

/* ANTCALCORR_R2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 antcal_corr_i_47_32 : 16;
#else 
    Uint32 antcal_corr_i_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_ANTCALCORR_R2_REG;

/*  */
#define CSL_DFE_BB_ANTCALCORR_R2_REG_ANTCAL_CORR_I_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_BB_ANTCALCORR_R2_REG_ANTCAL_CORR_I_47_32_SHIFT (0x00000000u)
#define CSL_DFE_BB_ANTCALCORR_R2_REG_ANTCAL_CORR_I_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_BB_ANTCALCORR_R2_REG_ADDR (0x00070008u)
#define CSL_DFE_BB_ANTCALCORR_R2_REG_RESETVAL (0x00000000u)

/* ANTCALCORR_R3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 antcal_corr_q_15_0 : 16;
#else 
    Uint32 antcal_corr_q_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_ANTCALCORR_R3_REG;

/*  */
#define CSL_DFE_BB_ANTCALCORR_R3_REG_ANTCAL_CORR_Q_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_BB_ANTCALCORR_R3_REG_ANTCAL_CORR_Q_15_0_SHIFT (0x00000000u)
#define CSL_DFE_BB_ANTCALCORR_R3_REG_ANTCAL_CORR_Q_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_BB_ANTCALCORR_R3_REG_ADDR (0x00070010u)
#define CSL_DFE_BB_ANTCALCORR_R3_REG_RESETVAL (0x00000000u)

/* ANTCALCORR_R4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 antcal_corr_q_31_16 : 16;
#else 
    Uint32 antcal_corr_q_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_ANTCALCORR_R4_REG;

/*  */
#define CSL_DFE_BB_ANTCALCORR_R4_REG_ANTCAL_CORR_Q_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_BB_ANTCALCORR_R4_REG_ANTCAL_CORR_Q_31_16_SHIFT (0x00000000u)
#define CSL_DFE_BB_ANTCALCORR_R4_REG_ANTCAL_CORR_Q_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_BB_ANTCALCORR_R4_REG_ADDR (0x00070014u)
#define CSL_DFE_BB_ANTCALCORR_R4_REG_RESETVAL (0x00000000u)

/* ANTCALCORR_R5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 antcal_corr_q_47_32 : 16;
#else 
    Uint32 antcal_corr_q_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_BB_ANTCALCORR_R5_REG;

/*  */
#define CSL_DFE_BB_ANTCALCORR_R5_REG_ANTCAL_CORR_Q_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_BB_ANTCALCORR_R5_REG_ANTCAL_CORR_Q_47_32_SHIFT (0x00000000u)
#define CSL_DFE_BB_ANTCALCORR_R5_REG_ANTCAL_CORR_Q_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_BB_ANTCALCORR_R5_REG_ADDR (0x00070018u)
#define CSL_DFE_BB_ANTCALCORR_R5_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_BB_H__ */

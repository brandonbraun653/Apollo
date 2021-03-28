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
#ifndef CSLR_SMSETSW_H_
#define CSLR_SMSETSW_H_

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
    volatile Uint32 SWCHANNELID0;
    volatile Uint32 SWCHANNELID0TS;
    volatile Uint32 SWCHANNELID1;
    volatile Uint32 SWCHANNELID1TS;
    volatile Uint32 SWCHANNELID2;
    volatile Uint32 SWCHANNELID2TS;
    volatile Uint32 SWCHANNELID3;
    volatile Uint32 SWCHANNELID3TS;
    volatile Uint32 SWCHANNELID4;
    volatile Uint32 SWCHANNELID4TS;
    volatile Uint32 SWCHANNELID5;
    volatile Uint32 SWCHANNELID5TS;
    volatile Uint32 SWCHANNELID6;
    volatile Uint32 SWCHANNELID6TS;
    volatile Uint32 SWCHANNELID7;
    volatile Uint32 SWCHANNELID7TS;
    volatile Uint32 SWCHANNELID8;
    volatile Uint32 SWCHANNELID8TS;
    volatile Uint32 SWCHANNELID9;
    volatile Uint32 SWCHANNELID9TS;
    volatile Uint32 SWCHANNELID10;
    volatile Uint32 SWCHANNELID10TS;
    volatile Uint32 SWCHANNELID11;
    volatile Uint32 SWCHANNELID11TS;
    volatile Uint32 SWCHANNELID12;
    volatile Uint32 SWCHANNELID12TS;
    volatile Uint32 SWCHANNELID13;
    volatile Uint32 SWCHANNELID13TS;
    volatile Uint32 SWCHANNELID14;
    volatile Uint32 SWCHANNELID14TS;
    volatile Uint32 SWCHANNELID15;
    volatile Uint32 SWCHANNELID15TS;
    volatile Uint32 SWCHANNELID16;
    volatile Uint32 SWCHANNELID16TS;
    volatile Uint32 SWCHANNELID17;
    volatile Uint32 SWCHANNELID17TS;
    volatile Uint32 SWCHANNELID18;
    volatile Uint32 SWCHANNELID18TS;
    volatile Uint32 SWCHANNELID19;
    volatile Uint32 SWCHANNELID19TS;
    volatile Uint32 SWCHANNELID20;
    volatile Uint32 SWCHANNELID20TS;
    volatile Uint32 SWCHANNELID21;
    volatile Uint32 SWCHANNELID21TS;
    volatile Uint32 SWCHANNELID22;
    volatile Uint32 SWCHANNELID22TS;
    volatile Uint32 SWCHANNELID23;
    volatile Uint32 SWCHANNELID23TS;
    volatile Uint32 SWCHANNELID24;
    volatile Uint32 SWCHANNELID24TS;
    volatile Uint32 SWCHANNELID25;
    volatile Uint32 SWCHANNELID25TS;
    volatile Uint32 SWCHANNELID26;
    volatile Uint32 SWCHANNELID26TS;
    volatile Uint32 SWCHANNELID27;
    volatile Uint32 SWCHANNELID27TS;
    volatile Uint32 SWCHANNELID28;
    volatile Uint32 SWCHANNELID28TS;
    volatile Uint32 SWCHANNELID29;
    volatile Uint32 SWCHANNELID29TS;
    volatile Uint32 SWCHANNELID30;
    volatile Uint32 SWCHANNELID30TS;
    volatile Uint32 SWCHANNELID31;
    volatile Uint32 SWCHANNELID31TS;
    volatile Uint32 SWCHANNELID32;
    volatile Uint32 SWCHANNELID32TS;
    volatile Uint32 SWCHANNELID33;
    volatile Uint32 SWCHANNELID33TS;
    volatile Uint32 SWCHANNELID34;
    volatile Uint32 SWCHANNELID34TS;
    volatile Uint32 SWCHANNELID35;
    volatile Uint32 SWCHANNELID35TS;
    volatile Uint32 SWCHANNELID36;
    volatile Uint32 SWCHANNELID36TS;
    volatile Uint32 SWCHANNELID37;
    volatile Uint32 SWCHANNELID37TS;
    volatile Uint32 SWCHANNELID38;
    volatile Uint32 SWCHANNELID38TS;
    volatile Uint32 SWCHANNELID39;
    volatile Uint32 SWCHANNELID39TS;
    volatile Uint32 SWCHANNELID40;
    volatile Uint32 SWCHANNELID40TS;
    volatile Uint32 SWCHANNELID41;
    volatile Uint32 SWCHANNELID41TS;
    volatile Uint32 SWCHANNELID42;
    volatile Uint32 SWCHANNELID42TS;
    volatile Uint32 SWCHANNELID43;
    volatile Uint32 SWCHANNELID43TS;
    volatile Uint32 SWCHANNELID44;
    volatile Uint32 SWCHANNELID44TS;
    volatile Uint32 SWCHANNELID45;
    volatile Uint32 SWCHANNELID45TS;
    volatile Uint32 SWCHANNELID46;
    volatile Uint32 SWCHANNELID46TS;
    volatile Uint32 SWCHANNELID47;
    volatile Uint32 SWCHANNELID47TS;
    volatile Uint32 SWCHANNELID48;
    volatile Uint32 SWCHANNELID48TS;
    volatile Uint32 SWCHANNELID49;
    volatile Uint32 SWCHANNELID49TS;
    volatile Uint32 SWCHANNELID50;
    volatile Uint32 SWCHANNELID50TS;
    volatile Uint32 SWCHANNELID51;
    volatile Uint32 SWCHANNELID51TS;
    volatile Uint32 SWCHANNELID52;
    volatile Uint32 SWCHANNELID52TS;
    volatile Uint32 SWCHANNELID53;
    volatile Uint32 SWCHANNELID53TS;
    volatile Uint32 SWCHANNELID54;
    volatile Uint32 SWCHANNELID54TS;
    volatile Uint32 SWCHANNELID55;
    volatile Uint32 SWCHANNELID55TS;
    volatile Uint32 SWCHANNELID56;
    volatile Uint32 SWCHANNELID56TS;
    volatile Uint32 SWCHANNELID57;
    volatile Uint32 SWCHANNELID57TS;
    volatile Uint32 SWCHANNELID58;
    volatile Uint32 SWCHANNELID58TS;
    volatile Uint32 SWCHANNELID59;
    volatile Uint32 SWCHANNELID59TS;
    volatile Uint32 SWCHANNELID60;
    volatile Uint32 SWCHANNELID60TS;
    volatile Uint32 SWCHANNELID61;
    volatile Uint32 SWCHANNELID61TS;
    volatile Uint32 SWCHANNELID62;
    volatile Uint32 SWCHANNELID62TS;
    volatile Uint32 SWCHANNELID63;
    volatile Uint32 SWCHANNELID63TS;
    volatile Uint32 SWCHANNELID64;
    volatile Uint32 SWCHANNELID64TS;
    volatile Uint32 SWCHANNELID65;
    volatile Uint32 SWCHANNELID65TS;
    volatile Uint32 SWCHANNELID66;
    volatile Uint32 SWCHANNELID66TS;
    volatile Uint32 SWCHANNELID67;
    volatile Uint32 SWCHANNELID67TS;
    volatile Uint32 SWCHANNELID68;
    volatile Uint32 SWCHANNELID68TS;
    volatile Uint32 SWCHANNELID69;
    volatile Uint32 SWCHANNELID69TS;
    volatile Uint32 SWCHANNELID70;
    volatile Uint32 SWCHANNELID70TS;
    volatile Uint32 SWCHANNELID71;
    volatile Uint32 SWCHANNELID71TS;
    volatile Uint32 SWCHANNELID72;
    volatile Uint32 SWCHANNELID72TS;
    volatile Uint32 SWCHANNELID73;
    volatile Uint32 SWCHANNELID73TS;
    volatile Uint32 SWCHANNELID74;
    volatile Uint32 SWCHANNELID74TS;
    volatile Uint32 SWCHANNELID75;
    volatile Uint32 SWCHANNELID75TS;
    volatile Uint32 SWCHANNELID76;
    volatile Uint32 SWCHANNELID76TS;
    volatile Uint32 SWCHANNELID77;
    volatile Uint32 SWCHANNELID77TS;
    volatile Uint32 SWCHANNELID78;
    volatile Uint32 SWCHANNELID78TS;
    volatile Uint32 SWCHANNELID79;
    volatile Uint32 SWCHANNELID79TS;
    volatile Uint32 SWCHANNELID80;
    volatile Uint32 SWCHANNELID80TS;
    volatile Uint32 SWCHANNELID81;
    volatile Uint32 SWCHANNELID81TS;
    volatile Uint32 SWCHANNELID82;
    volatile Uint32 SWCHANNELID82TS;
    volatile Uint32 SWCHANNELID83;
    volatile Uint32 SWCHANNELID83TS;
    volatile Uint32 SWCHANNELID84;
    volatile Uint32 SWCHANNELID84TS;
    volatile Uint32 SWCHANNELID85;
    volatile Uint32 SWCHANNELID85TS;
    volatile Uint32 SWCHANNELID86;
    volatile Uint32 SWCHANNELID86TS;
    volatile Uint32 SWCHANNELID87;
    volatile Uint32 SWCHANNELID87TS;
    volatile Uint32 SWCHANNELID88;
    volatile Uint32 SWCHANNELID88TS;
    volatile Uint32 SWCHANNELID89;
    volatile Uint32 SWCHANNELID89TS;
    volatile Uint32 SWCHANNELID90;
    volatile Uint32 SWCHANNELID90TS;
    volatile Uint32 SWCHANNELID91;
    volatile Uint32 SWCHANNELID91TS;
    volatile Uint32 SWCHANNELID92;
    volatile Uint32 SWCHANNELID92TS;
    volatile Uint32 SWCHANNELID93;
    volatile Uint32 SWCHANNELID93TS;
    volatile Uint32 SWCHANNELID94;
    volatile Uint32 SWCHANNELID94TS;
    volatile Uint32 SWCHANNELID95;
    volatile Uint32 SWCHANNELID95TS;
    volatile Uint32 SWCHANNELID96;
    volatile Uint32 SWCHANNELID96TS;
    volatile Uint32 SWCHANNELID97;
    volatile Uint32 SWCHANNELID97TS;
    volatile Uint32 SWCHANNELID98;
    volatile Uint32 SWCHANNELID98TS;
    volatile Uint32 SWCHANNELID99;
    volatile Uint32 SWCHANNELID99TS;
    volatile Uint32 SWCHANNELID100;
    volatile Uint32 SWCHANNELID100TS;
    volatile Uint32 SWCHANNELID101;
    volatile Uint32 SWCHANNELID101TS;
    volatile Uint32 SWCHANNELID102;
    volatile Uint32 SWCHANNELID102TS;
    volatile Uint32 SWCHANNELID103;
    volatile Uint32 SWCHANNELID103TS;
    volatile Uint32 SWCHANNELID104;
    volatile Uint32 SWCHANNELID104TS;
    volatile Uint32 SWCHANNELID105;
    volatile Uint32 SWCHANNELID105TS;
    volatile Uint32 SWCHANNELID106;
    volatile Uint32 SWCHANNELID106TS;
    volatile Uint32 SWCHANNELID107;
    volatile Uint32 SWCHANNELID107TS;
    volatile Uint32 SWCHANNELID108;
    volatile Uint32 SWCHANNELID108TS;
    volatile Uint32 SWCHANNELID109;
    volatile Uint32 SWCHANNELID109TS;
    volatile Uint32 SWCHANNELID110;
    volatile Uint32 SWCHANNELID110TS;
    volatile Uint32 SWCHANNELID111;
    volatile Uint32 SWCHANNELID111TS;
    volatile Uint32 SWCHANNELID112;
    volatile Uint32 SWCHANNELID112TS;
    volatile Uint32 SWCHANNELID113;
    volatile Uint32 SWCHANNELID113TS;
    volatile Uint32 SWCHANNELID114;
    volatile Uint32 SWCHANNELID114TS;
    volatile Uint32 SWCHANNELID115;
    volatile Uint32 SWCHANNELID115TS;
    volatile Uint32 SWCHANNELID116;
    volatile Uint32 SWCHANNELID116TS;
    volatile Uint32 SWCHANNELID117;
    volatile Uint32 SWCHANNELID117TS;
    volatile Uint32 SWCHANNELID118;
    volatile Uint32 SWCHANNELID118TS;
    volatile Uint32 SWCHANNELID119;
    volatile Uint32 SWCHANNELID119TS;
    volatile Uint32 SWCHANNELID120;
    volatile Uint32 SWCHANNELID120TS;
    volatile Uint32 SWCHANNELID121;
    volatile Uint32 SWCHANNELID121TS;
    volatile Uint32 SWCHANNELID122;
    volatile Uint32 SWCHANNELID122TS;
    volatile Uint32 SWCHANNELID123;
    volatile Uint32 SWCHANNELID123TS;
    volatile Uint32 SWCHANNELID124;
    volatile Uint32 SWCHANNELID124TS;
    volatile Uint32 SWCHANNELID125;
    volatile Uint32 SWCHANNELID125TS;
    volatile Uint32 SWCHANNELID126;
    volatile Uint32 SWCHANNELID126TS;
    volatile Uint32 SWCHANNELID127;
    volatile Uint32 SWCHANNELID127TS;
    volatile Uint32 SWCHANNELID128;
    volatile Uint32 SWCHANNELID128TS;
    volatile Uint32 SWCHANNELID129;
    volatile Uint32 SWCHANNELID129TS;
    volatile Uint32 SWCHANNELID130;
    volatile Uint32 SWCHANNELID130TS;
    volatile Uint32 SWCHANNELID131;
    volatile Uint32 SWCHANNELID131TS;
    volatile Uint32 SWCHANNELID132;
    volatile Uint32 SWCHANNELID132TS;
    volatile Uint32 SWCHANNELID133;
    volatile Uint32 SWCHANNELID133TS;
    volatile Uint32 SWCHANNELID134;
    volatile Uint32 SWCHANNELID134TS;
    volatile Uint32 SWCHANNELID135;
    volatile Uint32 SWCHANNELID135TS;
    volatile Uint32 SWCHANNELID136;
    volatile Uint32 SWCHANNELID136TS;
    volatile Uint32 SWCHANNELID137;
    volatile Uint32 SWCHANNELID137TS;
    volatile Uint32 SWCHANNELID138;
    volatile Uint32 SWCHANNELID138TS;
    volatile Uint32 SWCHANNELID139;
    volatile Uint32 SWCHANNELID139TS;
    volatile Uint32 SWCHANNELID140;
    volatile Uint32 SWCHANNELID140TS;
    volatile Uint32 SWCHANNELID141;
    volatile Uint32 SWCHANNELID141TS;
    volatile Uint32 SWCHANNELID142;
    volatile Uint32 SWCHANNELID142TS;
    volatile Uint32 SWCHANNELID143;
    volatile Uint32 SWCHANNELID143TS;
    volatile Uint32 SWCHANNELID144;
    volatile Uint32 SWCHANNELID144TS;
    volatile Uint32 SWCHANNELID145;
    volatile Uint32 SWCHANNELID145TS;
    volatile Uint32 SWCHANNELID146;
    volatile Uint32 SWCHANNELID146TS;
    volatile Uint32 SWCHANNELID147;
    volatile Uint32 SWCHANNELID147TS;
    volatile Uint32 SWCHANNELID148;
    volatile Uint32 SWCHANNELID148TS;
    volatile Uint32 SWCHANNELID149;
    volatile Uint32 SWCHANNELID149TS;
    volatile Uint32 SWCHANNELID150;
    volatile Uint32 SWCHANNELID150TS;
    volatile Uint32 SWCHANNELID151;
    volatile Uint32 SWCHANNELID151TS;
    volatile Uint32 SWCHANNELID152;
    volatile Uint32 SWCHANNELID152TS;
    volatile Uint32 SWCHANNELID153;
    volatile Uint32 SWCHANNELID153TS;
    volatile Uint32 SWCHANNELID154;
    volatile Uint32 SWCHANNELID154TS;
    volatile Uint32 SWCHANNELID155;
    volatile Uint32 SWCHANNELID155TS;
    volatile Uint32 SWCHANNELID156;
    volatile Uint32 SWCHANNELID156TS;
    volatile Uint32 SWCHANNELID157;
    volatile Uint32 SWCHANNELID157TS;
    volatile Uint32 SWCHANNELID158;
    volatile Uint32 SWCHANNELID158TS;
    volatile Uint32 SWCHANNELID159;
    volatile Uint32 SWCHANNELID159TS;
    volatile Uint32 SWCHANNELID160;
    volatile Uint32 SWCHANNELID160TS;
    volatile Uint32 SWCHANNELID161;
    volatile Uint32 SWCHANNELID161TS;
    volatile Uint32 SWCHANNELID162;
    volatile Uint32 SWCHANNELID162TS;
    volatile Uint32 SWCHANNELID163;
    volatile Uint32 SWCHANNELID163TS;
    volatile Uint32 SWCHANNELID164;
    volatile Uint32 SWCHANNELID164TS;
    volatile Uint32 SWCHANNELID165;
    volatile Uint32 SWCHANNELID165TS;
    volatile Uint32 SWCHANNELID166;
    volatile Uint32 SWCHANNELID166TS;
    volatile Uint32 SWCHANNELID167;
    volatile Uint32 SWCHANNELID167TS;
    volatile Uint32 SWCHANNELID168;
    volatile Uint32 SWCHANNELID168TS;
    volatile Uint32 SWCHANNELID169;
    volatile Uint32 SWCHANNELID169TS;
    volatile Uint32 SWCHANNELID170;
    volatile Uint32 SWCHANNELID170TS;
    volatile Uint32 SWCHANNELID171;
    volatile Uint32 SWCHANNELID171TS;
    volatile Uint32 SWCHANNELID172;
    volatile Uint32 SWCHANNELID172TS;
    volatile Uint32 SWCHANNELID173;
    volatile Uint32 SWCHANNELID173TS;
    volatile Uint32 SWCHANNELID174;
    volatile Uint32 SWCHANNELID174TS;
    volatile Uint32 SWCHANNELID175;
    volatile Uint32 SWCHANNELID175TS;
    volatile Uint32 SWCHANNELID176;
    volatile Uint32 SWCHANNELID176TS;
    volatile Uint32 SWCHANNELID177;
    volatile Uint32 SWCHANNELID177TS;
    volatile Uint32 SWCHANNELID178;
    volatile Uint32 SWCHANNELID178TS;
    volatile Uint32 SWCHANNELID179;
    volatile Uint32 SWCHANNELID179TS;
    volatile Uint32 SWCHANNELID180;
    volatile Uint32 SWCHANNELID180TS;
    volatile Uint32 SWCHANNELID181;
    volatile Uint32 SWCHANNELID181TS;
    volatile Uint32 SWCHANNELID182;
    volatile Uint32 SWCHANNELID182TS;
    volatile Uint32 SWCHANNELID183;
    volatile Uint32 SWCHANNELID183TS;
    volatile Uint32 SWCHANNELID184;
    volatile Uint32 SWCHANNELID184TS;
    volatile Uint32 SWCHANNELID185;
    volatile Uint32 SWCHANNELID185TS;
    volatile Uint32 SWCHANNELID186;
    volatile Uint32 SWCHANNELID186TS;
    volatile Uint32 SWCHANNELID187;
    volatile Uint32 SWCHANNELID187TS;
    volatile Uint32 SWCHANNELID188;
    volatile Uint32 SWCHANNELID188TS;
    volatile Uint32 SWCHANNELID189;
    volatile Uint32 SWCHANNELID189TS;
    volatile Uint32 SWCHANNELID190;
    volatile Uint32 SWCHANNELID190TS;
    volatile Uint32 SWCHANNELID191;
    volatile Uint32 SWCHANNELID191TS;
    volatile Uint32 SWCHANNELID192;
    volatile Uint32 SWCHANNELID192TS;
    volatile Uint32 SWCHANNELID193;
    volatile Uint32 SWCHANNELID193TS;
    volatile Uint32 SWCHANNELID194;
    volatile Uint32 SWCHANNELID194TS;
    volatile Uint32 SWCHANNELID195;
    volatile Uint32 SWCHANNELID195TS;
    volatile Uint32 SWCHANNELID196;
    volatile Uint32 SWCHANNELID196TS;
    volatile Uint32 SWCHANNELID197;
    volatile Uint32 SWCHANNELID197TS;
    volatile Uint32 SWCHANNELID198;
    volatile Uint32 SWCHANNELID198TS;
    volatile Uint32 SWCHANNELID199;
    volatile Uint32 SWCHANNELID199TS;
    volatile Uint32 SWCHANNELID200;
    volatile Uint32 SWCHANNELID200TS;
    volatile Uint32 SWCHANNELID201;
    volatile Uint32 SWCHANNELID201TS;
    volatile Uint32 SWCHANNELID202;
    volatile Uint32 SWCHANNELID202TS;
    volatile Uint32 SWCHANNELID203;
    volatile Uint32 SWCHANNELID203TS;
    volatile Uint32 SWCHANNELID204;
    volatile Uint32 SWCHANNELID204TS;
    volatile Uint32 SWCHANNELID205;
    volatile Uint32 SWCHANNELID205TS;
    volatile Uint32 SWCHANNELID206;
    volatile Uint32 SWCHANNELID206TS;
    volatile Uint32 SWCHANNELID207;
    volatile Uint32 SWCHANNELID207TS;
    volatile Uint32 SWCHANNELID208;
    volatile Uint32 SWCHANNELID208TS;
    volatile Uint32 SWCHANNELID209;
    volatile Uint32 SWCHANNELID209TS;
    volatile Uint32 SWCHANNELID210;
    volatile Uint32 SWCHANNELID210TS;
    volatile Uint32 SWCHANNELID211;
    volatile Uint32 SWCHANNELID211TS;
    volatile Uint32 SWCHANNELID212;
    volatile Uint32 SWCHANNELID212TS;
    volatile Uint32 SWCHANNELID213;
    volatile Uint32 SWCHANNELID213TS;
    volatile Uint32 SWCHANNELID214;
    volatile Uint32 SWCHANNELID214TS;
    volatile Uint32 SWCHANNELID215;
    volatile Uint32 SWCHANNELID215TS;
    volatile Uint32 SWCHANNELID216;
    volatile Uint32 SWCHANNELID216TS;
    volatile Uint32 SWCHANNELID217;
    volatile Uint32 SWCHANNELID217TS;
    volatile Uint32 SWCHANNELID218;
    volatile Uint32 SWCHANNELID218TS;
    volatile Uint32 SWCHANNELID219;
    volatile Uint32 SWCHANNELID219TS;
    volatile Uint32 SWCHANNELID220;
    volatile Uint32 SWCHANNELID220TS;
    volatile Uint32 SWCHANNELID221;
    volatile Uint32 SWCHANNELID221TS;
    volatile Uint32 SWCHANNELID222;
    volatile Uint32 SWCHANNELID222TS;
    volatile Uint32 SWCHANNELID223;
    volatile Uint32 SWCHANNELID223TS;
    volatile Uint32 SWCHANNELID224;
    volatile Uint32 SWCHANNELID224TS;
    volatile Uint32 SWCHANNELID225;
    volatile Uint32 SWCHANNELID225TS;
    volatile Uint32 SWCHANNELID226;
    volatile Uint32 SWCHANNELID226TS;
    volatile Uint32 SWCHANNELID227;
    volatile Uint32 SWCHANNELID227TS;
    volatile Uint32 SWCHANNELID228;
    volatile Uint32 SWCHANNELID228TS;
    volatile Uint32 SWCHANNELID229;
    volatile Uint32 SWCHANNELID229TS;
    volatile Uint32 SWCHANNELID230;
    volatile Uint32 SWCHANNELID230TS;
    volatile Uint32 SWCHANNELID231;
    volatile Uint32 SWCHANNELID231TS;
    volatile Uint32 SWCHANNELID232;
    volatile Uint32 SWCHANNELID232TS;
    volatile Uint32 SWCHANNELID233;
    volatile Uint32 SWCHANNELID233TS;
    volatile Uint32 SWCHANNELID234;
    volatile Uint32 SWCHANNELID234TS;
    volatile Uint32 SWCHANNELID235;
    volatile Uint32 SWCHANNELID235TS;
    volatile Uint32 SWCHANNELID236;
    volatile Uint32 SWCHANNELID236TS;
    volatile Uint32 SWCHANNELID237;
    volatile Uint32 SWCHANNELID237TS;
    volatile Uint32 SWCHANNELID238;
    volatile Uint32 SWCHANNELID238TS;
    volatile Uint32 SWCHANNELID239;
    volatile Uint32 SWCHANNELID239TS;
    volatile Uint32 SWCHANNELID240;
    volatile Uint32 SWCHANNELID240TS;
    volatile Uint32 SWCHANNELID241;
    volatile Uint32 SWCHANNELID241TS;
    volatile Uint32 SWCHANNELID242;
    volatile Uint32 SWCHANNELID242TS;
    volatile Uint32 SWCHANNELID243;
    volatile Uint32 SWCHANNELID243TS;
    volatile Uint32 SWCHANNELID244;
    volatile Uint32 SWCHANNELID244TS;
    volatile Uint32 SWCHANNELID245;
    volatile Uint32 SWCHANNELID245TS;
    volatile Uint32 SWCHANNELID246;
    volatile Uint32 SWCHANNELID246TS;
    volatile Uint32 SWCHANNELID247;
    volatile Uint32 SWCHANNELID247TS;
    volatile Uint32 SWCHANNELID248;
    volatile Uint32 SWCHANNELID248TS;
    volatile Uint32 SWCHANNELID249;
    volatile Uint32 SWCHANNELID249TS;
    volatile Uint32 SWCHANNELID250;
    volatile Uint32 SWCHANNELID250TS;
    volatile Uint32 SWCHANNELID251;
    volatile Uint32 SWCHANNELID251TS;
    volatile Uint32 SWCHANNELID252;
    volatile Uint32 SWCHANNELID252TS;
    volatile Uint32 SWCHANNELID253;
    volatile Uint32 SWCHANNELID253TS;
    volatile Uint32 SWCHANNELID254;
    volatile Uint32 SWCHANNELID254TS;
    volatile Uint32 SWCHANNELID255;
    volatile Uint32 SWCHANNELID255TS;
} CSL_SmsetSwRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* SW message write on ChannelID0 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID0                                (0x0U)

/* SW message write on ChannelID0 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID0TS                              (0x4U)

/* SW message write on ChannelID1 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID1                                (0x8U)

/* SW message write on ChannelID1 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID1TS                              (0xCU)

/* SW message write on ChannelID2 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID2                                (0x10U)

/* SW message write on ChannelID2 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID2TS                              (0x14U)

/* SW message write on ChannelID3 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID3                                (0x18U)

/* SW message write on ChannelID3 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID3TS                              (0x1CU)

/* SW message write on ChannelID4 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID4                                (0x20U)

/* SW message write on ChannelID4 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID4TS                              (0x24U)

/* SW message write on ChannelID5 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID5                                (0x28U)

/* SW message write on ChannelID5 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID5TS                              (0x2CU)

/* SW message write on ChannelID6 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID6                                (0x30U)

/* SW message write on ChannelID6 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID6TS                              (0x34U)

/* SW message write on ChannelID7 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID7                                (0x38U)

/* SW message write on ChannelID7 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID7TS                              (0x3CU)

/* SW message write on ChannelID8 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID8                                (0x40U)

/* SW message write on ChannelID8 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID8TS                              (0x44U)

/* SW message write on ChannelID9 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID9                                (0x48U)

/* SW message write on ChannelID9 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID9TS                              (0x4CU)

/* SW message write on ChannelID10 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID10                               (0x50U)

/* SW message write on ChannelID10 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID10TS                             (0x54U)

/* SW message write on ChannelID11 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID11                               (0x58U)

/* SW message write on ChannelID11 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID11TS                             (0x5CU)

/* SW message write on ChannelID12 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID12                               (0x60U)

/* SW message write on ChannelID12 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID12TS                             (0x64U)

/* SW message write on ChannelID13 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID13                               (0x68U)

/* SW message write on ChannelID13 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID13TS                             (0x6CU)

/* SW message write on ChannelID14 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID14                               (0x70U)

/* SW message write on ChannelID14 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID14TS                             (0x74U)

/* SW message write on ChannelID15 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID15                               (0x78U)

/* SW message write on ChannelID15 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID15TS                             (0x7CU)

/* SW message write on ChannelID16 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID16                               (0x80U)

/* SW message write on ChannelID16 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID16TS                             (0x84U)

/* SW message write on ChannelID17 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID17                               (0x88U)

/* SW message write on ChannelID17 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID17TS                             (0x8CU)

/* SW message write on ChannelID18 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID18                               (0x90U)

/* SW message write on ChannelID18 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID18TS                             (0x94U)

/* SW message write on ChannelID19 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID19                               (0x98U)

/* SW message write on ChannelID19 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID19TS                             (0x9CU)

/* SW message write on ChannelID20 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID20                               (0xA0U)

/* SW message write on ChannelID20 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID20TS                             (0xA4U)

/* SW message write on ChannelID21 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID21                               (0xA8U)

/* SW message write on ChannelID21 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID21TS                             (0xACU)

/* SW message write on ChannelID22 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID22                               (0xB0U)

/* SW message write on ChannelID22 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID22TS                             (0xB4U)

/* SW message write on ChannelID23 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID23                               (0xB8U)

/* SW message write on ChannelID23 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID23TS                             (0xBCU)

/* SW message write on ChannelID24 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID24                               (0xC0U)

/* SW message write on ChannelID24 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID24TS                             (0xC4U)

/* SW message write on ChannelID25 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID25                               (0xC8U)

/* SW message write on ChannelID25 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID25TS                             (0xCCU)

/* SW message write on ChannelID26 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID26                               (0xD0U)

/* SW message write on ChannelID26 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID26TS                             (0xD4U)

/* SW message write on ChannelID27 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID27                               (0xD8U)

/* SW message write on ChannelID27 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID27TS                             (0xDCU)

/* SW message write on ChannelID28 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID28                               (0xE0U)

/* SW message write on ChannelID28 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID28TS                             (0xE4U)

/* SW message write on ChannelID29 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID29                               (0xE8U)

/* SW message write on ChannelID29 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID29TS                             (0xECU)

/* SW message write on ChannelID30 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID30                               (0xF0U)

/* SW message write on ChannelID30 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID30TS                             (0xF4U)

/* SW message write on ChannelID31 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID31                               (0xF8U)

/* SW message write on ChannelID31 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID31TS                             (0xFCU)

/* SW message write on ChannelID32 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID32                               (0x100U)

/* SW message write on ChannelID32 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID32TS                             (0x104U)

/* SW message write on ChannelID33 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID33                               (0x108U)

/* SW message write on ChannelID33 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID33TS                             (0x10CU)

/* SW message write on ChannelID34 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID34                               (0x110U)

/* SW message write on ChannelID34 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID34TS                             (0x114U)

/* SW message write on ChannelID35 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID35                               (0x118U)

/* SW message write on ChannelID35 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID35TS                             (0x11CU)

/* SW message write on ChannelID36 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID36                               (0x120U)

/* SW message write on ChannelID36 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID36TS                             (0x124U)

/* SW message write on ChannelID37 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID37                               (0x128U)

/* SW message write on ChannelID37 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID37TS                             (0x12CU)

/* SW message write on ChannelID38 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID38                               (0x130U)

/* SW message write on ChannelID38 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID38TS                             (0x134U)

/* SW message write on ChannelID39 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID39                               (0x138U)

/* SW message write on ChannelID39 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID39TS                             (0x13CU)

/* SW message write on ChannelID40 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID40                               (0x140U)

/* SW message write on ChannelID40 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID40TS                             (0x144U)

/* SW message write on ChannelID41 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID41                               (0x148U)

/* SW message write on ChannelID41 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID41TS                             (0x14CU)

/* SW message write on ChannelID42 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID42                               (0x150U)

/* SW message write on ChannelID42 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID42TS                             (0x154U)

/* SW message write on ChannelID43 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID43                               (0x158U)

/* SW message write on ChannelID43 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID43TS                             (0x15CU)

/* SW message write on ChannelID44 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID44                               (0x160U)

/* SW message write on ChannelID44 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID44TS                             (0x164U)

/* SW message write on ChannelID45 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID45                               (0x168U)

/* SW message write on ChannelID45 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID45TS                             (0x16CU)

/* SW message write on ChannelID46 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID46                               (0x170U)

/* SW message write on ChannelID46 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID46TS                             (0x174U)

/* SW message write on ChannelID47 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID47                               (0x178U)

/* SW message write on ChannelID47 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID47TS                             (0x17CU)

/* SW message write on ChannelID48 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID48                               (0x180U)

/* SW message write on ChannelID48 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID48TS                             (0x184U)

/* SW message write on ChannelID49 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID49                               (0x188U)

/* SW message write on ChannelID49 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID49TS                             (0x18CU)

/* SW message write on ChannelID50 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID50                               (0x190U)

/* SW message write on ChannelID50 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID50TS                             (0x194U)

/* SW message write on ChannelID51 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID51                               (0x198U)

/* SW message write on ChannelID51 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID51TS                             (0x19CU)

/* SW message write on ChannelID52 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID52                               (0x1A0U)

/* SW message write on ChannelID52 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID52TS                             (0x1A4U)

/* SW message write on ChannelID53 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID53                               (0x1A8U)

/* SW message write on ChannelID53 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID53TS                             (0x1ACU)

/* SW message write on ChannelID54 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID54                               (0x1B0U)

/* SW message write on ChannelID54 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID54TS                             (0x1B4U)

/* SW message write on ChannelID55 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID55                               (0x1B8U)

/* SW message write on ChannelID55 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID55TS                             (0x1BCU)

/* SW message write on ChannelID56 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID56                               (0x1C0U)

/* SW message write on ChannelID56 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID56TS                             (0x1C4U)

/* SW message write on ChannelID57 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID57                               (0x1C8U)

/* SW message write on ChannelID57 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID57TS                             (0x1CCU)

/* SW message write on ChannelID58 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID58                               (0x1D0U)

/* SW message write on ChannelID58 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID58TS                             (0x1D4U)

/* SW message write on ChannelID59 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID59                               (0x1D8U)

/* SW message write on ChannelID59 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID59TS                             (0x1DCU)

/* SW message write on ChannelID60 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID60                               (0x1E0U)

/* SW message write on ChannelID60 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID60TS                             (0x1E4U)

/* SW message write on ChannelID61 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID61                               (0x1E8U)

/* SW message write on ChannelID61 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID61TS                             (0x1ECU)

/* SW message write on ChannelID62 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID62                               (0x1F0U)

/* SW message write on ChannelID62 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID62TS                             (0x1F4U)

/* SW message write on ChannelID63 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID63                               (0x1F8U)

/* SW message write on ChannelID63 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID63TS                             (0x1FCU)

/* SW message write on ChannelID64 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID64                               (0x200U)

/* SW message write on ChannelID64 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID64TS                             (0x204U)

/* SW message write on ChannelID65 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID65                               (0x208U)

/* SW message write on ChannelID65 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID65TS                             (0x20CU)

/* SW message write on ChannelID66 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID66                               (0x210U)

/* SW message write on ChannelID66 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID66TS                             (0x214U)

/* SW message write on ChannelID67 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID67                               (0x218U)

/* SW message write on ChannelID67 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID67TS                             (0x21CU)

/* SW message write on ChannelID68 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID68                               (0x220U)

/* SW message write on ChannelID68 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID68TS                             (0x224U)

/* SW message write on ChannelID69 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID69                               (0x228U)

/* SW message write on ChannelID69 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID69TS                             (0x22CU)

/* SW message write on ChannelID70 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID70                               (0x230U)

/* SW message write on ChannelID70 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID70TS                             (0x234U)

/* SW message write on ChannelID71 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID71                               (0x238U)

/* SW message write on ChannelID71 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID71TS                             (0x23CU)

/* SW message write on ChannelID72 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID72                               (0x240U)

/* SW message write on ChannelID72 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID72TS                             (0x244U)

/* SW message write on ChannelID73 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID73                               (0x248U)

/* SW message write on ChannelID73 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID73TS                             (0x24CU)

/* SW message write on ChannelID74 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID74                               (0x250U)

/* SW message write on ChannelID74 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID74TS                             (0x254U)

/* SW message write on ChannelID75 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID75                               (0x258U)

/* SW message write on ChannelID75 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID75TS                             (0x25CU)

/* SW message write on ChannelID76 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID76                               (0x260U)

/* SW message write on ChannelID76 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID76TS                             (0x264U)

/* SW message write on ChannelID77 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID77                               (0x268U)

/* SW message write on ChannelID77 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID77TS                             (0x26CU)

/* SW message write on ChannelID78 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID78                               (0x270U)

/* SW message write on ChannelID78 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID78TS                             (0x274U)

/* SW message write on ChannelID79 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID79                               (0x278U)

/* SW message write on ChannelID79 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID79TS                             (0x27CU)

/* SW message write on ChannelID80 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID80                               (0x280U)

/* SW message write on ChannelID80 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID80TS                             (0x284U)

/* SW message write on ChannelID81 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID81                               (0x288U)

/* SW message write on ChannelID81 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID81TS                             (0x28CU)

/* SW message write on ChannelID82 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID82                               (0x290U)

/* SW message write on ChannelID82 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID82TS                             (0x294U)

/* SW message write on ChannelID83 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID83                               (0x298U)

/* SW message write on ChannelID83 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID83TS                             (0x29CU)

/* SW message write on ChannelID84 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID84                               (0x2A0U)

/* SW message write on ChannelID84 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID84TS                             (0x2A4U)

/* SW message write on ChannelID85 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID85                               (0x2A8U)

/* SW message write on ChannelID85 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID85TS                             (0x2ACU)

/* SW message write on ChannelID86 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID86                               (0x2B0U)

/* SW message write on ChannelID86 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID86TS                             (0x2B4U)

/* SW message write on ChannelID87 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID87                               (0x2B8U)

/* SW message write on ChannelID87 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID87TS                             (0x2BCU)

/* SW message write on ChannelID88 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID88                               (0x2C0U)

/* SW message write on ChannelID88 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID88TS                             (0x2C4U)

/* SW message write on ChannelID89 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID89                               (0x2C8U)

/* SW message write on ChannelID89 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID89TS                             (0x2CCU)

/* SW message write on ChannelID90 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID90                               (0x2D0U)

/* SW message write on ChannelID90 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID90TS                             (0x2D4U)

/* SW message write on ChannelID91 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID91                               (0x2D8U)

/* SW message write on ChannelID91 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID91TS                             (0x2DCU)

/* SW message write on ChannelID92 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID92                               (0x2E0U)

/* SW message write on ChannelID92 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID92TS                             (0x2E4U)

/* SW message write on ChannelID93 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID93                               (0x2E8U)

/* SW message write on ChannelID93 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID93TS                             (0x2ECU)

/* SW message write on ChannelID94 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID94                               (0x2F0U)

/* SW message write on ChannelID94 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID94TS                             (0x2F4U)

/* SW message write on ChannelID95 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID95                               (0x2F8U)

/* SW message write on ChannelID95 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID95TS                             (0x2FCU)

/* SW message write on ChannelID96 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID96                               (0x300U)

/* SW message write on ChannelID96 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID96TS                             (0x304U)

/* SW message write on ChannelID97 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID97                               (0x308U)

/* SW message write on ChannelID97 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID97TS                             (0x30CU)

/* SW message write on ChannelID98 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID98                               (0x310U)

/* SW message write on ChannelID98 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID98TS                             (0x314U)

/* SW message write on ChannelID99 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID99                               (0x318U)

/* SW message write on ChannelID99 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID99TS                             (0x31CU)

/* SW message write on ChannelID100 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID100                              (0x320U)

/* SW message write on ChannelID100 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID100TS                            (0x324U)

/* SW message write on ChannelID101 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID101                              (0x328U)

/* SW message write on ChannelID101 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID101TS                            (0x32CU)

/* SW message write on ChannelID102 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID102                              (0x330U)

/* SW message write on ChannelID102 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID102TS                            (0x334U)

/* SW message write on ChannelID103 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID103                              (0x338U)

/* SW message write on ChannelID103 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID103TS                            (0x33CU)

/* SW message write on ChannelID104 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID104                              (0x340U)

/* SW message write on ChannelID104 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID104TS                            (0x344U)

/* SW message write on ChannelID105 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID105                              (0x348U)

/* SW message write on ChannelID105 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID105TS                            (0x34CU)

/* SW message write on ChannelID106 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID106                              (0x350U)

/* SW message write on ChannelID106 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID106TS                            (0x354U)

/* SW message write on ChannelID107 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID107                              (0x358U)

/* SW message write on ChannelID107 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID107TS                            (0x35CU)

/* SW message write on ChannelID108 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID108                              (0x360U)

/* SW message write on ChannelID108 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID108TS                            (0x364U)

/* SW message write on ChannelID109 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID109                              (0x368U)

/* SW message write on ChannelID109 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID109TS                            (0x36CU)

/* SW message write on ChannelID110 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID110                              (0x370U)

/* SW message write on ChannelID110 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID110TS                            (0x374U)

/* SW message write on ChannelID111 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID111                              (0x378U)

/* SW message write on ChannelID111 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID111TS                            (0x37CU)

/* SW message write on ChannelID112 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID112                              (0x380U)

/* SW message write on ChannelID112 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID112TS                            (0x384U)

/* SW message write on ChannelID113 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID113                              (0x388U)

/* SW message write on ChannelID113 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID113TS                            (0x38CU)

/* SW message write on ChannelID114 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID114                              (0x390U)

/* SW message write on ChannelID114 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID114TS                            (0x394U)

/* SW message write on ChannelID115 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID115                              (0x398U)

/* SW message write on ChannelID115 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID115TS                            (0x39CU)

/* SW message write on ChannelID116 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID116                              (0x3A0U)

/* SW message write on ChannelID116 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID116TS                            (0x3A4U)

/* SW message write on ChannelID117 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID117                              (0x3A8U)

/* SW message write on ChannelID117 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID117TS                            (0x3ACU)

/* SW message write on ChannelID118 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID118                              (0x3B0U)

/* SW message write on ChannelID118 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID118TS                            (0x3B4U)

/* SW message write on ChannelID119 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID119                              (0x3B8U)

/* SW message write on ChannelID119 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID119TS                            (0x3BCU)

/* SW message write on ChannelID120 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID120                              (0x3C0U)

/* SW message write on ChannelID120 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID120TS                            (0x3C4U)

/* SW message write on ChannelID121 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID121                              (0x3C8U)

/* SW message write on ChannelID121 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID121TS                            (0x3CCU)

/* SW message write on ChannelID122 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID122                              (0x3D0U)

/* SW message write on ChannelID122 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID122TS                            (0x3D4U)

/* SW message write on ChannelID123 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID123                              (0x3D8U)

/* SW message write on ChannelID123 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID123TS                            (0x3DCU)

/* SW message write on ChannelID124 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID124                              (0x3E0U)

/* SW message write on ChannelID124 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID124TS                            (0x3E4U)

/* SW message write on ChannelID125 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID125                              (0x3E8U)

/* SW message write on ChannelID125 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID125TS                            (0x3ECU)

/* SW message write on ChannelID126 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID126                              (0x3F0U)

/* SW message write on ChannelID126 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID126TS                            (0x3F4U)

/* SW message write on ChannelID127 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID127                              (0x3F8U)

/* SW message write on ChannelID127 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID127TS                            (0x3FCU)

/* SW message write on ChannelID128 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID128                              (0x400U)

/* SW message write on ChannelID128 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID128TS                            (0x404U)

/* SW message write on ChannelID129 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID129                              (0x408U)

/* SW message write on ChannelID129 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID129TS                            (0x40CU)

/* SW message write on ChannelID130 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID130                              (0x410U)

/* SW message write on ChannelID130 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID130TS                            (0x414U)

/* SW message write on ChannelID131 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID131                              (0x418U)

/* SW message write on ChannelID131 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID131TS                            (0x41CU)

/* SW message write on ChannelID132 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID132                              (0x420U)

/* SW message write on ChannelID132 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID132TS                            (0x424U)

/* SW message write on ChannelID133 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID133                              (0x428U)

/* SW message write on ChannelID133 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID133TS                            (0x42CU)

/* SW message write on ChannelID134 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID134                              (0x430U)

/* SW message write on ChannelID134 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID134TS                            (0x434U)

/* SW message write on ChannelID135 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID135                              (0x438U)

/* SW message write on ChannelID135 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID135TS                            (0x43CU)

/* SW message write on ChannelID136 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID136                              (0x440U)

/* SW message write on ChannelID136 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID136TS                            (0x444U)

/* SW message write on ChannelID137 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID137                              (0x448U)

/* SW message write on ChannelID137 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID137TS                            (0x44CU)

/* SW message write on ChannelID138 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID138                              (0x450U)

/* SW message write on ChannelID138 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID138TS                            (0x454U)

/* SW message write on ChannelID139 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID139                              (0x458U)

/* SW message write on ChannelID139 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID139TS                            (0x45CU)

/* SW message write on ChannelID140 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID140                              (0x460U)

/* SW message write on ChannelID140 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID140TS                            (0x464U)

/* SW message write on ChannelID141 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID141                              (0x468U)

/* SW message write on ChannelID141 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID141TS                            (0x46CU)

/* SW message write on ChannelID142 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID142                              (0x470U)

/* SW message write on ChannelID142 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID142TS                            (0x474U)

/* SW message write on ChannelID143 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID143                              (0x478U)

/* SW message write on ChannelID143 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID143TS                            (0x47CU)

/* SW message write on ChannelID144 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID144                              (0x480U)

/* SW message write on ChannelID144 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID144TS                            (0x484U)

/* SW message write on ChannelID145 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID145                              (0x488U)

/* SW message write on ChannelID145 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID145TS                            (0x48CU)

/* SW message write on ChannelID146 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID146                              (0x490U)

/* SW message write on ChannelID146 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID146TS                            (0x494U)

/* SW message write on ChannelID147 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID147                              (0x498U)

/* SW message write on ChannelID147 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID147TS                            (0x49CU)

/* SW message write on ChannelID148 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID148                              (0x4A0U)

/* SW message write on ChannelID148 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID148TS                            (0x4A4U)

/* SW message write on ChannelID149 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID149                              (0x4A8U)

/* SW message write on ChannelID149 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID149TS                            (0x4ACU)

/* SW message write on ChannelID150 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID150                              (0x4B0U)

/* SW message write on ChannelID150 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID150TS                            (0x4B4U)

/* SW message write on ChannelID151 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID151                              (0x4B8U)

/* SW message write on ChannelID151 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID151TS                            (0x4BCU)

/* SW message write on ChannelID152 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID152                              (0x4C0U)

/* SW message write on ChannelID152 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID152TS                            (0x4C4U)

/* SW message write on ChannelID153 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID153                              (0x4C8U)

/* SW message write on ChannelID153 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID153TS                            (0x4CCU)

/* SW message write on ChannelID154 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID154                              (0x4D0U)

/* SW message write on ChannelID154 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID154TS                            (0x4D4U)

/* SW message write on ChannelID155 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID155                              (0x4D8U)

/* SW message write on ChannelID155 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID155TS                            (0x4DCU)

/* SW message write on ChannelID156 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID156                              (0x4E0U)

/* SW message write on ChannelID156 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID156TS                            (0x4E4U)

/* SW message write on ChannelID157 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID157                              (0x4E8U)

/* SW message write on ChannelID157 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID157TS                            (0x4ECU)

/* SW message write on ChannelID158 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID158                              (0x4F0U)

/* SW message write on ChannelID158 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID158TS                            (0x4F4U)

/* SW message write on ChannelID159 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID159                              (0x4F8U)

/* SW message write on ChannelID159 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID159TS                            (0x4FCU)

/* SW message write on ChannelID160 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID160                              (0x500U)

/* SW message write on ChannelID160 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID160TS                            (0x504U)

/* SW message write on ChannelID161 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID161                              (0x508U)

/* SW message write on ChannelID161 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID161TS                            (0x50CU)

/* SW message write on ChannelID162 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID162                              (0x510U)

/* SW message write on ChannelID162 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID162TS                            (0x514U)

/* SW message write on ChannelID163 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID163                              (0x518U)

/* SW message write on ChannelID163 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID163TS                            (0x51CU)

/* SW message write on ChannelID164 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID164                              (0x520U)

/* SW message write on ChannelID164 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID164TS                            (0x524U)

/* SW message write on ChannelID165 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID165                              (0x528U)

/* SW message write on ChannelID165 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID165TS                            (0x52CU)

/* SW message write on ChannelID166 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID166                              (0x530U)

/* SW message write on ChannelID166 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID166TS                            (0x534U)

/* SW message write on ChannelID167 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID167                              (0x538U)

/* SW message write on ChannelID167 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID167TS                            (0x53CU)

/* SW message write on ChannelID168 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID168                              (0x540U)

/* SW message write on ChannelID168 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID168TS                            (0x544U)

/* SW message write on ChannelID169 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID169                              (0x548U)

/* SW message write on ChannelID169 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID169TS                            (0x54CU)

/* SW message write on ChannelID170 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID170                              (0x550U)

/* SW message write on ChannelID170 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID170TS                            (0x554U)

/* SW message write on ChannelID171 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID171                              (0x558U)

/* SW message write on ChannelID171 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID171TS                            (0x55CU)

/* SW message write on ChannelID172 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID172                              (0x560U)

/* SW message write on ChannelID172 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID172TS                            (0x564U)

/* SW message write on ChannelID173 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID173                              (0x568U)

/* SW message write on ChannelID173 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID173TS                            (0x56CU)

/* SW message write on ChannelID174 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID174                              (0x570U)

/* SW message write on ChannelID174 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID174TS                            (0x574U)

/* SW message write on ChannelID175 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID175                              (0x578U)

/* SW message write on ChannelID175 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID175TS                            (0x57CU)

/* SW message write on ChannelID176 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID176                              (0x580U)

/* SW message write on ChannelID176 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID176TS                            (0x584U)

/* SW message write on ChannelID177 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID177                              (0x588U)

/* SW message write on ChannelID177 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID177TS                            (0x58CU)

/* SW message write on ChannelID178 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID178                              (0x590U)

/* SW message write on ChannelID178 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID178TS                            (0x594U)

/* SW message write on ChannelID179 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID179                              (0x598U)

/* SW message write on ChannelID179 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID179TS                            (0x59CU)

/* SW message write on ChannelID180 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID180                              (0x5A0U)

/* SW message write on ChannelID180 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID180TS                            (0x5A4U)

/* SW message write on ChannelID181 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID181                              (0x5A8U)

/* SW message write on ChannelID181 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID181TS                            (0x5ACU)

/* SW message write on ChannelID182 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID182                              (0x5B0U)

/* SW message write on ChannelID182 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID182TS                            (0x5B4U)

/* SW message write on ChannelID183 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID183                              (0x5B8U)

/* SW message write on ChannelID183 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID183TS                            (0x5BCU)

/* SW message write on ChannelID184 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID184                              (0x5C0U)

/* SW message write on ChannelID184 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID184TS                            (0x5C4U)

/* SW message write on ChannelID185 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID185                              (0x5C8U)

/* SW message write on ChannelID185 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID185TS                            (0x5CCU)

/* SW message write on ChannelID186 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID186                              (0x5D0U)

/* SW message write on ChannelID186 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID186TS                            (0x5D4U)

/* SW message write on ChannelID187 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID187                              (0x5D8U)

/* SW message write on ChannelID187 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID187TS                            (0x5DCU)

/* SW message write on ChannelID188 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID188                              (0x5E0U)

/* SW message write on ChannelID188 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID188TS                            (0x5E4U)

/* SW message write on ChannelID189 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID189                              (0x5E8U)

/* SW message write on ChannelID189 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID189TS                            (0x5ECU)

/* SW message write on ChannelID190 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID190                              (0x5F0U)

/* SW message write on ChannelID190 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID190TS                            (0x5F4U)

/* SW message write on ChannelID191 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID191                              (0x5F8U)

/* SW message write on ChannelID191 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID191TS                            (0x5FCU)

/* SW message write on ChannelID192 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID192                              (0x600U)

/* SW message write on ChannelID192 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID192TS                            (0x604U)

/* SW message write on ChannelID193 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID193                              (0x608U)

/* SW message write on ChannelID193 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID193TS                            (0x60CU)

/* SW message write on ChannelID194 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID194                              (0x610U)

/* SW message write on ChannelID194 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID194TS                            (0x614U)

/* SW message write on ChannelID195 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID195                              (0x618U)

/* SW message write on ChannelID195 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID195TS                            (0x61CU)

/* SW message write on ChannelID196 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID196                              (0x620U)

/* SW message write on ChannelID196 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID196TS                            (0x624U)

/* SW message write on ChannelID197 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID197                              (0x628U)

/* SW message write on ChannelID197 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID197TS                            (0x62CU)

/* SW message write on ChannelID198 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID198                              (0x630U)

/* SW message write on ChannelID198 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID198TS                            (0x634U)

/* SW message write on ChannelID199 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID199                              (0x638U)

/* SW message write on ChannelID199 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID199TS                            (0x63CU)

/* SW message write on ChannelID200 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID200                              (0x640U)

/* SW message write on ChannelID200 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID200TS                            (0x644U)

/* SW message write on ChannelID201 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID201                              (0x648U)

/* SW message write on ChannelID201 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID201TS                            (0x64CU)

/* SW message write on ChannelID202 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID202                              (0x650U)

/* SW message write on ChannelID202 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID202TS                            (0x654U)

/* SW message write on ChannelID203 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID203                              (0x658U)

/* SW message write on ChannelID203 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID203TS                            (0x65CU)

/* SW message write on ChannelID204 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID204                              (0x660U)

/* SW message write on ChannelID204 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID204TS                            (0x664U)

/* SW message write on ChannelID205 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID205                              (0x668U)

/* SW message write on ChannelID205 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID205TS                            (0x66CU)

/* SW message write on ChannelID206 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID206                              (0x670U)

/* SW message write on ChannelID206 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID206TS                            (0x674U)

/* SW message write on ChannelID207 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID207                              (0x678U)

/* SW message write on ChannelID207 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID207TS                            (0x67CU)

/* SW message write on ChannelID208 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID208                              (0x680U)

/* SW message write on ChannelID208 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID208TS                            (0x684U)

/* SW message write on ChannelID209 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID209                              (0x688U)

/* SW message write on ChannelID209 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID209TS                            (0x68CU)

/* SW message write on ChannelID210 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID210                              (0x690U)

/* SW message write on ChannelID210 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID210TS                            (0x694U)

/* SW message write on ChannelID211 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID211                              (0x698U)

/* SW message write on ChannelID211 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID211TS                            (0x69CU)

/* SW message write on ChannelID212 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID212                              (0x6A0U)

/* SW message write on ChannelID212 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID212TS                            (0x6A4U)

/* SW message write on ChannelID213 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID213                              (0x6A8U)

/* SW message write on ChannelID213 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID213TS                            (0x6ACU)

/* SW message write on ChannelID214 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID214                              (0x6B0U)

/* SW message write on ChannelID214 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID214TS                            (0x6B4U)

/* SW message write on ChannelID215 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID215                              (0x6B8U)

/* SW message write on ChannelID215 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID215TS                            (0x6BCU)

/* SW message write on ChannelID216 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID216                              (0x6C0U)

/* SW message write on ChannelID216 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID216TS                            (0x6C4U)

/* SW message write on ChannelID217 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID217                              (0x6C8U)

/* SW message write on ChannelID217 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID217TS                            (0x6CCU)

/* SW message write on ChannelID218 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID218                              (0x6D0U)

/* SW message write on ChannelID218 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID218TS                            (0x6D4U)

/* SW message write on ChannelID219 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID219                              (0x6D8U)

/* SW message write on ChannelID219 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID219TS                            (0x6DCU)

/* SW message write on ChannelID220 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID220                              (0x6E0U)

/* SW message write on ChannelID220 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID220TS                            (0x6E4U)

/* SW message write on ChannelID221 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID221                              (0x6E8U)

/* SW message write on ChannelID221 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID221TS                            (0x6ECU)

/* SW message write on ChannelID222 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID222                              (0x6F0U)

/* SW message write on ChannelID222 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID222TS                            (0x6F4U)

/* SW message write on ChannelID223 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID223                              (0x6F8U)

/* SW message write on ChannelID223 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID223TS                            (0x6FCU)

/* SW message write on ChannelID224 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID224                              (0x700U)

/* SW message write on ChannelID224 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID224TS                            (0x704U)

/* SW message write on ChannelID225 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID225                              (0x708U)

/* SW message write on ChannelID225 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID225TS                            (0x70CU)

/* SW message write on ChannelID226 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID226                              (0x710U)

/* SW message write on ChannelID226 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID226TS                            (0x714U)

/* SW message write on ChannelID227 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID227                              (0x718U)

/* SW message write on ChannelID227 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID227TS                            (0x71CU)

/* SW message write on ChannelID228 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID228                              (0x720U)

/* SW message write on ChannelID228 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID228TS                            (0x724U)

/* SW message write on ChannelID229 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID229                              (0x728U)

/* SW message write on ChannelID229 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID229TS                            (0x72CU)

/* SW message write on ChannelID230 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID230                              (0x730U)

/* SW message write on ChannelID230 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID230TS                            (0x734U)

/* SW message write on ChannelID231 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID231                              (0x738U)

/* SW message write on ChannelID231 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID231TS                            (0x73CU)

/* SW message write on ChannelID232 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID232                              (0x740U)

/* SW message write on ChannelID232 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID232TS                            (0x744U)

/* SW message write on ChannelID233 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID233                              (0x748U)

/* SW message write on ChannelID233 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID233TS                            (0x74CU)

/* SW message write on ChannelID234 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID234                              (0x750U)

/* SW message write on ChannelID234 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID234TS                            (0x754U)

/* SW message write on ChannelID235 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID235                              (0x758U)

/* SW message write on ChannelID235 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID235TS                            (0x75CU)

/* SW message write on ChannelID236 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID236                              (0x760U)

/* SW message write on ChannelID236 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID236TS                            (0x764U)

/* SW message write on ChannelID237 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID237                              (0x768U)

/* SW message write on ChannelID237 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID237TS                            (0x76CU)

/* SW message write on ChannelID238 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID238                              (0x770U)

/* SW message write on ChannelID238 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID238TS                            (0x774U)

/* SW message write on ChannelID239 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID239                              (0x778U)

/* SW message write on ChannelID239 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID239TS                            (0x77CU)

/* SW message write on ChannelID240 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID240                              (0x780U)

/* SW message write on ChannelID240 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID240TS                            (0x784U)

/* SW message write on ChannelID241 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID241                              (0x788U)

/* SW message write on ChannelID241 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID241TS                            (0x78CU)

/* SW message write on ChannelID242 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID242                              (0x790U)

/* SW message write on ChannelID242 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID242TS                            (0x794U)

/* SW message write on ChannelID243 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID243                              (0x798U)

/* SW message write on ChannelID243 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID243TS                            (0x79CU)

/* SW message write on ChannelID244 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID244                              (0x7A0U)

/* SW message write on ChannelID244 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID244TS                            (0x7A4U)

/* SW message write on ChannelID245 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID245                              (0x7A8U)

/* SW message write on ChannelID245 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID245TS                            (0x7ACU)

/* SW message write on ChannelID246 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID246                              (0x7B0U)

/* SW message write on ChannelID246 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID246TS                            (0x7B4U)

/* SW message write on ChannelID247 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID247                              (0x7B8U)

/* SW message write on ChannelID247 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID247TS                            (0x7BCU)

/* SW message write on ChannelID248 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID248                              (0x7C0U)

/* SW message write on ChannelID248 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID248TS                            (0x7C4U)

/* SW message write on ChannelID249 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID249                              (0x7C8U)

/* SW message write on ChannelID249 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID249TS                            (0x7CCU)

/* SW message write on ChannelID250 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID250                              (0x7D0U)

/* SW message write on ChannelID250 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID250TS                            (0x7D4U)

/* SW message write on ChannelID251 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID251                              (0x7D8U)

/* SW message write on ChannelID251 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID251TS                            (0x7DCU)

/* SW message write on ChannelID252 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID252                              (0x7E0U)

/* SW message write on ChannelID252 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID252TS                            (0x7E4U)

/* SW message write on ChannelID253 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID253                              (0x7E8U)

/* SW message write on ChannelID253 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID253TS                            (0x7ECU)

/* SW message write on ChannelID254 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID254                              (0x7F0U)

/* SW message write on ChannelID254 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID254TS                            (0x7F4U)

/* SW message write on ChannelID255 without Time Stamp */
#define CSL_SMSETSW_SWCHANNELID255                              (0x7F8U)

/* SW message write on ChannelID255 with Time Stamp */
#define CSL_SMSETSW_SWCHANNELID255TS                            (0x7FCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* SWCHANNELID0 */

#define CSL_SMSETSW_SWCHANNELID0_SWCHANNELID0_MASK              (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID0_SWCHANNELID0_SHIFT             (0U)
#define CSL_SMSETSW_SWCHANNELID0_SWCHANNELID0_RESETVAL          (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID0_SWCHANNELID0_MAX               (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID0_RESETVAL                       (0x00000000U)

/* SWCHANNELID0TS */

#define CSL_SMSETSW_SWCHANNELID0TS_SWCHANNELID0TS_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID0TS_SWCHANNELID0TS_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID0TS_SWCHANNELID0TS_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID0TS_SWCHANNELID0TS_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID0TS_RESETVAL                     (0x00000000U)

/* SWCHANNELID1 */

#define CSL_SMSETSW_SWCHANNELID1_SWCHANNELID1_MASK              (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID1_SWCHANNELID1_SHIFT             (0U)
#define CSL_SMSETSW_SWCHANNELID1_SWCHANNELID1_RESETVAL          (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID1_SWCHANNELID1_MAX               (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID1_RESETVAL                       (0x00000000U)

/* SWCHANNELID1TS */

#define CSL_SMSETSW_SWCHANNELID1TS_SWCHANNELID1TS_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID1TS_SWCHANNELID1TS_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID1TS_SWCHANNELID1TS_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID1TS_SWCHANNELID1TS_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID1TS_RESETVAL                     (0x00000000U)

/* SWCHANNELID2 */

#define CSL_SMSETSW_SWCHANNELID2_SWCHANNELID2_MASK              (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID2_SWCHANNELID2_SHIFT             (0U)
#define CSL_SMSETSW_SWCHANNELID2_SWCHANNELID2_RESETVAL          (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID2_SWCHANNELID2_MAX               (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID2_RESETVAL                       (0x00000000U)

/* SWCHANNELID2TS */

#define CSL_SMSETSW_SWCHANNELID2TS_SWCHANNELID2TS_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID2TS_SWCHANNELID2TS_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID2TS_SWCHANNELID2TS_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID2TS_SWCHANNELID2TS_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID2TS_RESETVAL                     (0x00000000U)

/* SWCHANNELID3 */

#define CSL_SMSETSW_SWCHANNELID3_SWCHANNELID3_MASK              (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID3_SWCHANNELID3_SHIFT             (0U)
#define CSL_SMSETSW_SWCHANNELID3_SWCHANNELID3_RESETVAL          (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID3_SWCHANNELID3_MAX               (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID3_RESETVAL                       (0x00000000U)

/* SWCHANNELID3TS */

#define CSL_SMSETSW_SWCHANNELID3TS_SWCHANNELID3TS_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID3TS_SWCHANNELID3TS_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID3TS_SWCHANNELID3TS_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID3TS_SWCHANNELID3TS_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID3TS_RESETVAL                     (0x00000000U)

/* SWCHANNELID4 */

#define CSL_SMSETSW_SWCHANNELID4_SWCHANNELID4_MASK              (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID4_SWCHANNELID4_SHIFT             (0U)
#define CSL_SMSETSW_SWCHANNELID4_SWCHANNELID4_RESETVAL          (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID4_SWCHANNELID4_MAX               (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID4_RESETVAL                       (0x00000000U)

/* SWCHANNELID4TS */

#define CSL_SMSETSW_SWCHANNELID4TS_SWCHANNELID4TS_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID4TS_SWCHANNELID4TS_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID4TS_SWCHANNELID4TS_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID4TS_SWCHANNELID4TS_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID4TS_RESETVAL                     (0x00000000U)

/* SWCHANNELID5 */

#define CSL_SMSETSW_SWCHANNELID5_SWCHANNELID5_MASK              (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID5_SWCHANNELID5_SHIFT             (0U)
#define CSL_SMSETSW_SWCHANNELID5_SWCHANNELID5_RESETVAL          (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID5_SWCHANNELID5_MAX               (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID5_RESETVAL                       (0x00000000U)

/* SWCHANNELID5TS */

#define CSL_SMSETSW_SWCHANNELID5TS_SWCHANNELID5TS_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID5TS_SWCHANNELID5TS_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID5TS_SWCHANNELID5TS_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID5TS_SWCHANNELID5TS_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID5TS_RESETVAL                     (0x00000000U)

/* SWCHANNELID6 */

#define CSL_SMSETSW_SWCHANNELID6_SWCHANNELID6_MASK              (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID6_SWCHANNELID6_SHIFT             (0U)
#define CSL_SMSETSW_SWCHANNELID6_SWCHANNELID6_RESETVAL          (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID6_SWCHANNELID6_MAX               (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID6_RESETVAL                       (0x00000000U)

/* SWCHANNELID6TS */

#define CSL_SMSETSW_SWCHANNELID6TS_SWCHANNELID6TS_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID6TS_SWCHANNELID6TS_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID6TS_SWCHANNELID6TS_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID6TS_SWCHANNELID6TS_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID6TS_RESETVAL                     (0x00000000U)

/* SWCHANNELID7 */

#define CSL_SMSETSW_SWCHANNELID7_SWCHANNELID7_MASK              (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID7_SWCHANNELID7_SHIFT             (0U)
#define CSL_SMSETSW_SWCHANNELID7_SWCHANNELID7_RESETVAL          (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID7_SWCHANNELID7_MAX               (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID7_RESETVAL                       (0x00000000U)

/* SWCHANNELID7TS */

#define CSL_SMSETSW_SWCHANNELID7TS_SWCHANNELID7TS_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID7TS_SWCHANNELID7TS_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID7TS_SWCHANNELID7TS_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID7TS_SWCHANNELID7TS_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID7TS_RESETVAL                     (0x00000000U)

/* SWCHANNELID8 */

#define CSL_SMSETSW_SWCHANNELID8_SWCHANNELID8_MASK              (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID8_SWCHANNELID8_SHIFT             (0U)
#define CSL_SMSETSW_SWCHANNELID8_SWCHANNELID8_RESETVAL          (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID8_SWCHANNELID8_MAX               (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID8_RESETVAL                       (0x00000000U)

/* SWCHANNELID8TS */

#define CSL_SMSETSW_SWCHANNELID8TS_SWCHANNELID8TS_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID8TS_SWCHANNELID8TS_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID8TS_SWCHANNELID8TS_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID8TS_SWCHANNELID8TS_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID8TS_RESETVAL                     (0x00000000U)

/* SWCHANNELID9 */

#define CSL_SMSETSW_SWCHANNELID9_SWCHANNELID9_MASK              (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID9_SWCHANNELID9_SHIFT             (0U)
#define CSL_SMSETSW_SWCHANNELID9_SWCHANNELID9_RESETVAL          (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID9_SWCHANNELID9_MAX               (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID9_RESETVAL                       (0x00000000U)

/* SWCHANNELID9TS */

#define CSL_SMSETSW_SWCHANNELID9TS_SWCHANNELID9TS_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID9TS_SWCHANNELID9TS_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID9TS_SWCHANNELID9TS_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID9TS_SWCHANNELID9TS_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID9TS_RESETVAL                     (0x00000000U)

/* SWCHANNELID10 */

#define CSL_SMSETSW_SWCHANNELID10_SWCHANNELID10_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID10_SWCHANNELID10_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID10_SWCHANNELID10_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID10_SWCHANNELID10_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID10_RESETVAL                      (0x00000000U)

/* SWCHANNELID10TS */

#define CSL_SMSETSW_SWCHANNELID10TS_SWCHANNELID10TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID10TS_SWCHANNELID10TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID10TS_SWCHANNELID10TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID10TS_SWCHANNELID10TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID10TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID11 */

#define CSL_SMSETSW_SWCHANNELID11_SWCHANNELID11_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID11_SWCHANNELID11_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID11_SWCHANNELID11_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID11_SWCHANNELID11_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID11_RESETVAL                      (0x00000000U)

/* SWCHANNELID11TS */

#define CSL_SMSETSW_SWCHANNELID11TS_SWCHANNELID11TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID11TS_SWCHANNELID11TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID11TS_SWCHANNELID11TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID11TS_SWCHANNELID11TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID11TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID12 */

#define CSL_SMSETSW_SWCHANNELID12_SWCHANNELID12_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID12_SWCHANNELID12_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID12_SWCHANNELID12_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID12_SWCHANNELID12_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID12_RESETVAL                      (0x00000000U)

/* SWCHANNELID12TS */

#define CSL_SMSETSW_SWCHANNELID12TS_SWCHANNELID12TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID12TS_SWCHANNELID12TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID12TS_SWCHANNELID12TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID12TS_SWCHANNELID12TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID12TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID13 */

#define CSL_SMSETSW_SWCHANNELID13_SWCHANNELID13_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID13_SWCHANNELID13_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID13_SWCHANNELID13_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID13_SWCHANNELID13_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID13_RESETVAL                      (0x00000000U)

/* SWCHANNELID13TS */

#define CSL_SMSETSW_SWCHANNELID13TS_SWCHANNELID13TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID13TS_SWCHANNELID13TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID13TS_SWCHANNELID13TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID13TS_SWCHANNELID13TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID13TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID14 */

#define CSL_SMSETSW_SWCHANNELID14_SWCHANNELID14_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID14_SWCHANNELID14_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID14_SWCHANNELID14_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID14_SWCHANNELID14_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID14_RESETVAL                      (0x00000000U)

/* SWCHANNELID14TS */

#define CSL_SMSETSW_SWCHANNELID14TS_SWCHANNELID14TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID14TS_SWCHANNELID14TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID14TS_SWCHANNELID14TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID14TS_SWCHANNELID14TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID14TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID15 */

#define CSL_SMSETSW_SWCHANNELID15_SWCHANNELID15_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID15_SWCHANNELID15_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID15_SWCHANNELID15_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID15_SWCHANNELID15_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID15_RESETVAL                      (0x00000000U)

/* SWCHANNELID15TS */

#define CSL_SMSETSW_SWCHANNELID15TS_SWCHANNELID15TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID15TS_SWCHANNELID15TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID15TS_SWCHANNELID15TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID15TS_SWCHANNELID15TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID15TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID16 */

#define CSL_SMSETSW_SWCHANNELID16_SWCHANNELID16_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID16_SWCHANNELID16_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID16_SWCHANNELID16_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID16_SWCHANNELID16_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID16_RESETVAL                      (0x00000000U)

/* SWCHANNELID16TS */

#define CSL_SMSETSW_SWCHANNELID16TS_SWCHANNELID16TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID16TS_SWCHANNELID16TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID16TS_SWCHANNELID16TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID16TS_SWCHANNELID16TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID16TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID17 */

#define CSL_SMSETSW_SWCHANNELID17_SWCHANNELID17_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID17_SWCHANNELID17_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID17_SWCHANNELID17_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID17_SWCHANNELID17_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID17_RESETVAL                      (0x00000000U)

/* SWCHANNELID17TS */

#define CSL_SMSETSW_SWCHANNELID17TS_SWCHANNELID17TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID17TS_SWCHANNELID17TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID17TS_SWCHANNELID17TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID17TS_SWCHANNELID17TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID17TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID18 */

#define CSL_SMSETSW_SWCHANNELID18_SWCHANNELID18_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID18_SWCHANNELID18_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID18_SWCHANNELID18_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID18_SWCHANNELID18_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID18_RESETVAL                      (0x00000000U)

/* SWCHANNELID18TS */

#define CSL_SMSETSW_SWCHANNELID18TS_SWCHANNELID18TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID18TS_SWCHANNELID18TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID18TS_SWCHANNELID18TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID18TS_SWCHANNELID18TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID18TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID19 */

#define CSL_SMSETSW_SWCHANNELID19_SWCHANNELID19_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID19_SWCHANNELID19_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID19_SWCHANNELID19_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID19_SWCHANNELID19_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID19_RESETVAL                      (0x00000000U)

/* SWCHANNELID19TS */

#define CSL_SMSETSW_SWCHANNELID19TS_SWCHANNELID19TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID19TS_SWCHANNELID19TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID19TS_SWCHANNELID19TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID19TS_SWCHANNELID19TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID19TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID20 */

#define CSL_SMSETSW_SWCHANNELID20_SWCHANNELID20_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID20_SWCHANNELID20_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID20_SWCHANNELID20_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID20_SWCHANNELID20_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID20_RESETVAL                      (0x00000000U)

/* SWCHANNELID20TS */

#define CSL_SMSETSW_SWCHANNELID20TS_SWCHANNELID20TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID20TS_SWCHANNELID20TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID20TS_SWCHANNELID20TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID20TS_SWCHANNELID20TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID20TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID21 */

#define CSL_SMSETSW_SWCHANNELID21_SWCHANNELID21_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID21_SWCHANNELID21_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID21_SWCHANNELID21_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID21_SWCHANNELID21_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID21_RESETVAL                      (0x00000000U)

/* SWCHANNELID21TS */

#define CSL_SMSETSW_SWCHANNELID21TS_SWCHANNELID21TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID21TS_SWCHANNELID21TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID21TS_SWCHANNELID21TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID21TS_SWCHANNELID21TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID21TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID22 */

#define CSL_SMSETSW_SWCHANNELID22_SWCHANNELID22_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID22_SWCHANNELID22_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID22_SWCHANNELID22_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID22_SWCHANNELID22_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID22_RESETVAL                      (0x00000000U)

/* SWCHANNELID22TS */

#define CSL_SMSETSW_SWCHANNELID22TS_SWCHANNELID22TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID22TS_SWCHANNELID22TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID22TS_SWCHANNELID22TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID22TS_SWCHANNELID22TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID22TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID23 */

#define CSL_SMSETSW_SWCHANNELID23_SWCHANNELID23_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID23_SWCHANNELID23_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID23_SWCHANNELID23_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID23_SWCHANNELID23_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID23_RESETVAL                      (0x00000000U)

/* SWCHANNELID23TS */

#define CSL_SMSETSW_SWCHANNELID23TS_SWCHANNELID23TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID23TS_SWCHANNELID23TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID23TS_SWCHANNELID23TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID23TS_SWCHANNELID23TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID23TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID24 */

#define CSL_SMSETSW_SWCHANNELID24_SWCHANNELID24_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID24_SWCHANNELID24_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID24_SWCHANNELID24_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID24_SWCHANNELID24_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID24_RESETVAL                      (0x00000000U)

/* SWCHANNELID24TS */

#define CSL_SMSETSW_SWCHANNELID24TS_SWCHANNELID24TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID24TS_SWCHANNELID24TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID24TS_SWCHANNELID24TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID24TS_SWCHANNELID24TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID24TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID25 */

#define CSL_SMSETSW_SWCHANNELID25_SWCHANNELID25_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID25_SWCHANNELID25_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID25_SWCHANNELID25_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID25_SWCHANNELID25_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID25_RESETVAL                      (0x00000000U)

/* SWCHANNELID25TS */

#define CSL_SMSETSW_SWCHANNELID25TS_SWCHANNELID25TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID25TS_SWCHANNELID25TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID25TS_SWCHANNELID25TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID25TS_SWCHANNELID25TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID25TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID26 */

#define CSL_SMSETSW_SWCHANNELID26_SWCHANNELID26_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID26_SWCHANNELID26_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID26_SWCHANNELID26_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID26_SWCHANNELID26_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID26_RESETVAL                      (0x00000000U)

/* SWCHANNELID26TS */

#define CSL_SMSETSW_SWCHANNELID26TS_SWCHANNELID26TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID26TS_SWCHANNELID26TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID26TS_SWCHANNELID26TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID26TS_SWCHANNELID26TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID26TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID27 */

#define CSL_SMSETSW_SWCHANNELID27_SWCHANNELID27_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID27_SWCHANNELID27_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID27_SWCHANNELID27_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID27_SWCHANNELID27_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID27_RESETVAL                      (0x00000000U)

/* SWCHANNELID27TS */

#define CSL_SMSETSW_SWCHANNELID27TS_SWCHANNELID27TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID27TS_SWCHANNELID27TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID27TS_SWCHANNELID27TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID27TS_SWCHANNELID27TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID27TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID28 */

#define CSL_SMSETSW_SWCHANNELID28_SWCHANNELID28_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID28_SWCHANNELID28_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID28_SWCHANNELID28_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID28_SWCHANNELID28_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID28_RESETVAL                      (0x00000000U)

/* SWCHANNELID28TS */

#define CSL_SMSETSW_SWCHANNELID28TS_SWCHANNELID28TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID28TS_SWCHANNELID28TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID28TS_SWCHANNELID28TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID28TS_SWCHANNELID28TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID28TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID29 */

#define CSL_SMSETSW_SWCHANNELID29_SWCHANNELID29_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID29_SWCHANNELID29_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID29_SWCHANNELID29_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID29_SWCHANNELID29_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID29_RESETVAL                      (0x00000000U)

/* SWCHANNELID29TS */

#define CSL_SMSETSW_SWCHANNELID29TS_SWCHANNELID29TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID29TS_SWCHANNELID29TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID29TS_SWCHANNELID29TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID29TS_SWCHANNELID29TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID29TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID30 */

#define CSL_SMSETSW_SWCHANNELID30_SWCHANNELID30_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID30_SWCHANNELID30_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID30_SWCHANNELID30_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID30_SWCHANNELID30_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID30_RESETVAL                      (0x00000000U)

/* SWCHANNELID30TS */

#define CSL_SMSETSW_SWCHANNELID30TS_SWCHANNELID30TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID30TS_SWCHANNELID30TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID30TS_SWCHANNELID30TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID30TS_SWCHANNELID30TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID30TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID31 */

#define CSL_SMSETSW_SWCHANNELID31_SWCHANNELID31_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID31_SWCHANNELID31_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID31_SWCHANNELID31_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID31_SWCHANNELID31_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID31_RESETVAL                      (0x00000000U)

/* SWCHANNELID31TS */

#define CSL_SMSETSW_SWCHANNELID31TS_SWCHANNELID31TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID31TS_SWCHANNELID31TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID31TS_SWCHANNELID31TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID31TS_SWCHANNELID31TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID31TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID32 */

#define CSL_SMSETSW_SWCHANNELID32_SWCHANNELID32_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID32_SWCHANNELID32_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID32_SWCHANNELID32_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID32_SWCHANNELID32_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID32_RESETVAL                      (0x00000000U)

/* SWCHANNELID32TS */

#define CSL_SMSETSW_SWCHANNELID32TS_SWCHANNELID32TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID32TS_SWCHANNELID32TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID32TS_SWCHANNELID32TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID32TS_SWCHANNELID32TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID32TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID33 */

#define CSL_SMSETSW_SWCHANNELID33_SWCHANNELID33_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID33_SWCHANNELID33_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID33_SWCHANNELID33_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID33_SWCHANNELID33_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID33_RESETVAL                      (0x00000000U)

/* SWCHANNELID33TS */

#define CSL_SMSETSW_SWCHANNELID33TS_SWCHANNELID33TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID33TS_SWCHANNELID33TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID33TS_SWCHANNELID33TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID33TS_SWCHANNELID33TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID33TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID34 */

#define CSL_SMSETSW_SWCHANNELID34_SWCHANNELID34_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID34_SWCHANNELID34_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID34_SWCHANNELID34_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID34_SWCHANNELID34_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID34_RESETVAL                      (0x00000000U)

/* SWCHANNELID34TS */

#define CSL_SMSETSW_SWCHANNELID34TS_SWCHANNELID34TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID34TS_SWCHANNELID34TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID34TS_SWCHANNELID34TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID34TS_SWCHANNELID34TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID34TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID35 */

#define CSL_SMSETSW_SWCHANNELID35_SWCHANNELID35_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID35_SWCHANNELID35_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID35_SWCHANNELID35_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID35_SWCHANNELID35_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID35_RESETVAL                      (0x00000000U)

/* SWCHANNELID35TS */

#define CSL_SMSETSW_SWCHANNELID35TS_SWCHANNELID35TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID35TS_SWCHANNELID35TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID35TS_SWCHANNELID35TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID35TS_SWCHANNELID35TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID35TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID36 */

#define CSL_SMSETSW_SWCHANNELID36_SWCHANNELID36_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID36_SWCHANNELID36_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID36_SWCHANNELID36_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID36_SWCHANNELID36_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID36_RESETVAL                      (0x00000000U)

/* SWCHANNELID36TS */

#define CSL_SMSETSW_SWCHANNELID36TS_SWCHANNELID36TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID36TS_SWCHANNELID36TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID36TS_SWCHANNELID36TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID36TS_SWCHANNELID36TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID36TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID37 */

#define CSL_SMSETSW_SWCHANNELID37_SWCHANNELID37_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID37_SWCHANNELID37_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID37_SWCHANNELID37_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID37_SWCHANNELID37_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID37_RESETVAL                      (0x00000000U)

/* SWCHANNELID37TS */

#define CSL_SMSETSW_SWCHANNELID37TS_SWCHANNELID37TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID37TS_SWCHANNELID37TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID37TS_SWCHANNELID37TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID37TS_SWCHANNELID37TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID37TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID38 */

#define CSL_SMSETSW_SWCHANNELID38_SWCHANNELID38_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID38_SWCHANNELID38_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID38_SWCHANNELID38_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID38_SWCHANNELID38_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID38_RESETVAL                      (0x00000000U)

/* SWCHANNELID38TS */

#define CSL_SMSETSW_SWCHANNELID38TS_SWCHANNELID38TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID38TS_SWCHANNELID38TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID38TS_SWCHANNELID38TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID38TS_SWCHANNELID38TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID38TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID39 */

#define CSL_SMSETSW_SWCHANNELID39_SWCHANNELID39_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID39_SWCHANNELID39_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID39_SWCHANNELID39_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID39_SWCHANNELID39_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID39_RESETVAL                      (0x00000000U)

/* SWCHANNELID39TS */

#define CSL_SMSETSW_SWCHANNELID39TS_SWCHANNELID39TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID39TS_SWCHANNELID39TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID39TS_SWCHANNELID39TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID39TS_SWCHANNELID39TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID39TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID40 */

#define CSL_SMSETSW_SWCHANNELID40_SWCHANNELID40_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID40_SWCHANNELID40_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID40_SWCHANNELID40_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID40_SWCHANNELID40_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID40_RESETVAL                      (0x00000000U)

/* SWCHANNELID40TS */

#define CSL_SMSETSW_SWCHANNELID40TS_SWCHANNELID40TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID40TS_SWCHANNELID40TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID40TS_SWCHANNELID40TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID40TS_SWCHANNELID40TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID40TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID41 */

#define CSL_SMSETSW_SWCHANNELID41_SWCHANNELID41_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID41_SWCHANNELID41_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID41_SWCHANNELID41_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID41_SWCHANNELID41_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID41_RESETVAL                      (0x00000000U)

/* SWCHANNELID41TS */

#define CSL_SMSETSW_SWCHANNELID41TS_SWCHANNELID41TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID41TS_SWCHANNELID41TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID41TS_SWCHANNELID41TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID41TS_SWCHANNELID41TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID41TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID42 */

#define CSL_SMSETSW_SWCHANNELID42_SWCHANNELID42_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID42_SWCHANNELID42_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID42_SWCHANNELID42_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID42_SWCHANNELID42_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID42_RESETVAL                      (0x00000000U)

/* SWCHANNELID42TS */

#define CSL_SMSETSW_SWCHANNELID42TS_SWCHANNELID42TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID42TS_SWCHANNELID42TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID42TS_SWCHANNELID42TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID42TS_SWCHANNELID42TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID42TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID43 */

#define CSL_SMSETSW_SWCHANNELID43_SWCHANNELID43_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID43_SWCHANNELID43_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID43_SWCHANNELID43_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID43_SWCHANNELID43_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID43_RESETVAL                      (0x00000000U)

/* SWCHANNELID43TS */

#define CSL_SMSETSW_SWCHANNELID43TS_SWCHANNELID43TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID43TS_SWCHANNELID43TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID43TS_SWCHANNELID43TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID43TS_SWCHANNELID43TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID43TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID44 */

#define CSL_SMSETSW_SWCHANNELID44_SWCHANNELID44_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID44_SWCHANNELID44_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID44_SWCHANNELID44_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID44_SWCHANNELID44_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID44_RESETVAL                      (0x00000000U)

/* SWCHANNELID44TS */

#define CSL_SMSETSW_SWCHANNELID44TS_SWCHANNELID44TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID44TS_SWCHANNELID44TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID44TS_SWCHANNELID44TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID44TS_SWCHANNELID44TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID44TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID45 */

#define CSL_SMSETSW_SWCHANNELID45_SWCHANNELID45_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID45_SWCHANNELID45_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID45_SWCHANNELID45_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID45_SWCHANNELID45_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID45_RESETVAL                      (0x00000000U)

/* SWCHANNELID45TS */

#define CSL_SMSETSW_SWCHANNELID45TS_SWCHANNELID45TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID45TS_SWCHANNELID45TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID45TS_SWCHANNELID45TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID45TS_SWCHANNELID45TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID45TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID46 */

#define CSL_SMSETSW_SWCHANNELID46_SWCHANNELID46_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID46_SWCHANNELID46_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID46_SWCHANNELID46_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID46_SWCHANNELID46_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID46_RESETVAL                      (0x00000000U)

/* SWCHANNELID46TS */

#define CSL_SMSETSW_SWCHANNELID46TS_SWCHANNELID46TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID46TS_SWCHANNELID46TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID46TS_SWCHANNELID46TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID46TS_SWCHANNELID46TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID46TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID47 */

#define CSL_SMSETSW_SWCHANNELID47_SWCHANNELID47_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID47_SWCHANNELID47_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID47_SWCHANNELID47_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID47_SWCHANNELID47_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID47_RESETVAL                      (0x00000000U)

/* SWCHANNELID47TS */

#define CSL_SMSETSW_SWCHANNELID47TS_SWCHANNELID47TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID47TS_SWCHANNELID47TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID47TS_SWCHANNELID47TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID47TS_SWCHANNELID47TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID47TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID48 */

#define CSL_SMSETSW_SWCHANNELID48_SWCHANNELID48_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID48_SWCHANNELID48_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID48_SWCHANNELID48_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID48_SWCHANNELID48_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID48_RESETVAL                      (0x00000000U)

/* SWCHANNELID48TS */

#define CSL_SMSETSW_SWCHANNELID48TS_SWCHANNELID48TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID48TS_SWCHANNELID48TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID48TS_SWCHANNELID48TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID48TS_SWCHANNELID48TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID48TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID49 */

#define CSL_SMSETSW_SWCHANNELID49_SWCHANNELID49_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID49_SWCHANNELID49_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID49_SWCHANNELID49_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID49_SWCHANNELID49_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID49_RESETVAL                      (0x00000000U)

/* SWCHANNELID49TS */

#define CSL_SMSETSW_SWCHANNELID49TS_SWCHANNELID49TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID49TS_SWCHANNELID49TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID49TS_SWCHANNELID49TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID49TS_SWCHANNELID49TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID49TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID50 */

#define CSL_SMSETSW_SWCHANNELID50_SWCHANNELID50_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID50_SWCHANNELID50_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID50_SWCHANNELID50_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID50_SWCHANNELID50_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID50_RESETVAL                      (0x00000000U)

/* SWCHANNELID50TS */

#define CSL_SMSETSW_SWCHANNELID50TS_SWCHANNELID50TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID50TS_SWCHANNELID50TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID50TS_SWCHANNELID50TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID50TS_SWCHANNELID50TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID50TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID51 */

#define CSL_SMSETSW_SWCHANNELID51_SWCHANNELID51_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID51_SWCHANNELID51_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID51_SWCHANNELID51_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID51_SWCHANNELID51_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID51_RESETVAL                      (0x00000000U)

/* SWCHANNELID51TS */

#define CSL_SMSETSW_SWCHANNELID51TS_SWCHANNELID51TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID51TS_SWCHANNELID51TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID51TS_SWCHANNELID51TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID51TS_SWCHANNELID51TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID51TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID52 */

#define CSL_SMSETSW_SWCHANNELID52_SWCHANNELID52_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID52_SWCHANNELID52_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID52_SWCHANNELID52_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID52_SWCHANNELID52_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID52_RESETVAL                      (0x00000000U)

/* SWCHANNELID52TS */

#define CSL_SMSETSW_SWCHANNELID52TS_SWCHANNELID52TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID52TS_SWCHANNELID52TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID52TS_SWCHANNELID52TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID52TS_SWCHANNELID52TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID52TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID53 */

#define CSL_SMSETSW_SWCHANNELID53_SWCHANNELID53_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID53_SWCHANNELID53_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID53_SWCHANNELID53_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID53_SWCHANNELID53_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID53_RESETVAL                      (0x00000000U)

/* SWCHANNELID53TS */

#define CSL_SMSETSW_SWCHANNELID53TS_SWCHANNELID53TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID53TS_SWCHANNELID53TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID53TS_SWCHANNELID53TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID53TS_SWCHANNELID53TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID53TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID54 */

#define CSL_SMSETSW_SWCHANNELID54_SWCHANNELID54_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID54_SWCHANNELID54_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID54_SWCHANNELID54_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID54_SWCHANNELID54_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID54_RESETVAL                      (0x00000000U)

/* SWCHANNELID54TS */

#define CSL_SMSETSW_SWCHANNELID54TS_SWCHANNELID54TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID54TS_SWCHANNELID54TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID54TS_SWCHANNELID54TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID54TS_SWCHANNELID54TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID54TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID55 */

#define CSL_SMSETSW_SWCHANNELID55_SWCHANNELID55_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID55_SWCHANNELID55_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID55_SWCHANNELID55_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID55_SWCHANNELID55_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID55_RESETVAL                      (0x00000000U)

/* SWCHANNELID55TS */

#define CSL_SMSETSW_SWCHANNELID55TS_SWCHANNELID55TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID55TS_SWCHANNELID55TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID55TS_SWCHANNELID55TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID55TS_SWCHANNELID55TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID55TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID56 */

#define CSL_SMSETSW_SWCHANNELID56_SWCHANNELID56_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID56_SWCHANNELID56_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID56_SWCHANNELID56_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID56_SWCHANNELID56_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID56_RESETVAL                      (0x00000000U)

/* SWCHANNELID56TS */

#define CSL_SMSETSW_SWCHANNELID56TS_SWCHANNELID56TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID56TS_SWCHANNELID56TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID56TS_SWCHANNELID56TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID56TS_SWCHANNELID56TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID56TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID57 */

#define CSL_SMSETSW_SWCHANNELID57_SWCHANNELID57_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID57_SWCHANNELID57_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID57_SWCHANNELID57_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID57_SWCHANNELID57_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID57_RESETVAL                      (0x00000000U)

/* SWCHANNELID57TS */

#define CSL_SMSETSW_SWCHANNELID57TS_SWCHANNELID57TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID57TS_SWCHANNELID57TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID57TS_SWCHANNELID57TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID57TS_SWCHANNELID57TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID57TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID58 */

#define CSL_SMSETSW_SWCHANNELID58_SWCHANNELID58_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID58_SWCHANNELID58_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID58_SWCHANNELID58_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID58_SWCHANNELID58_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID58_RESETVAL                      (0x00000000U)

/* SWCHANNELID58TS */

#define CSL_SMSETSW_SWCHANNELID58TS_SWCHANNELID58TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID58TS_SWCHANNELID58TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID58TS_SWCHANNELID58TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID58TS_SWCHANNELID58TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID58TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID59 */

#define CSL_SMSETSW_SWCHANNELID59_SWCHANNELID59_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID59_SWCHANNELID59_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID59_SWCHANNELID59_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID59_SWCHANNELID59_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID59_RESETVAL                      (0x00000000U)

/* SWCHANNELID59TS */

#define CSL_SMSETSW_SWCHANNELID59TS_SWCHANNELID59TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID59TS_SWCHANNELID59TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID59TS_SWCHANNELID59TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID59TS_SWCHANNELID59TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID59TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID60 */

#define CSL_SMSETSW_SWCHANNELID60_SWCHANNELID60_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID60_SWCHANNELID60_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID60_SWCHANNELID60_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID60_SWCHANNELID60_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID60_RESETVAL                      (0x00000000U)

/* SWCHANNELID60TS */

#define CSL_SMSETSW_SWCHANNELID60TS_SWCHANNELID60TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID60TS_SWCHANNELID60TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID60TS_SWCHANNELID60TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID60TS_SWCHANNELID60TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID60TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID61 */

#define CSL_SMSETSW_SWCHANNELID61_SWCHANNELID61_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID61_SWCHANNELID61_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID61_SWCHANNELID61_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID61_SWCHANNELID61_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID61_RESETVAL                      (0x00000000U)

/* SWCHANNELID61TS */

#define CSL_SMSETSW_SWCHANNELID61TS_SWCHANNELID61TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID61TS_SWCHANNELID61TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID61TS_SWCHANNELID61TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID61TS_SWCHANNELID61TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID61TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID62 */

#define CSL_SMSETSW_SWCHANNELID62_SWCHANNELID62_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID62_SWCHANNELID62_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID62_SWCHANNELID62_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID62_SWCHANNELID62_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID62_RESETVAL                      (0x00000000U)

/* SWCHANNELID62TS */

#define CSL_SMSETSW_SWCHANNELID62TS_SWCHANNELID62TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID62TS_SWCHANNELID62TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID62TS_SWCHANNELID62TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID62TS_SWCHANNELID62TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID62TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID63 */

#define CSL_SMSETSW_SWCHANNELID63_SWCHANNELID63_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID63_SWCHANNELID63_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID63_SWCHANNELID63_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID63_SWCHANNELID63_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID63_RESETVAL                      (0x00000000U)

/* SWCHANNELID63TS */

#define CSL_SMSETSW_SWCHANNELID63TS_SWCHANNELID63TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID63TS_SWCHANNELID63TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID63TS_SWCHANNELID63TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID63TS_SWCHANNELID63TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID63TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID64 */

#define CSL_SMSETSW_SWCHANNELID64_SWCHANNELID64_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID64_SWCHANNELID64_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID64_SWCHANNELID64_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID64_SWCHANNELID64_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID64_RESETVAL                      (0x00000000U)

/* SWCHANNELID64TS */

#define CSL_SMSETSW_SWCHANNELID64TS_SWCHANNELID64TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID64TS_SWCHANNELID64TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID64TS_SWCHANNELID64TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID64TS_SWCHANNELID64TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID64TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID65 */

#define CSL_SMSETSW_SWCHANNELID65_SWCHANNELID65_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID65_SWCHANNELID65_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID65_SWCHANNELID65_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID65_SWCHANNELID65_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID65_RESETVAL                      (0x00000000U)

/* SWCHANNELID65TS */

#define CSL_SMSETSW_SWCHANNELID65TS_SWCHANNELID65TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID65TS_SWCHANNELID65TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID65TS_SWCHANNELID65TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID65TS_SWCHANNELID65TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID65TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID66 */

#define CSL_SMSETSW_SWCHANNELID66_SWCHANNELID66_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID66_SWCHANNELID66_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID66_SWCHANNELID66_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID66_SWCHANNELID66_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID66_RESETVAL                      (0x00000000U)

/* SWCHANNELID66TS */

#define CSL_SMSETSW_SWCHANNELID66TS_SWCHANNELID66TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID66TS_SWCHANNELID66TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID66TS_SWCHANNELID66TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID66TS_SWCHANNELID66TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID66TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID67 */

#define CSL_SMSETSW_SWCHANNELID67_SWCHANNELID67_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID67_SWCHANNELID67_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID67_SWCHANNELID67_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID67_SWCHANNELID67_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID67_RESETVAL                      (0x00000000U)

/* SWCHANNELID67TS */

#define CSL_SMSETSW_SWCHANNELID67TS_SWCHANNELID67TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID67TS_SWCHANNELID67TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID67TS_SWCHANNELID67TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID67TS_SWCHANNELID67TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID67TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID68 */

#define CSL_SMSETSW_SWCHANNELID68_SWCHANNELID68_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID68_SWCHANNELID68_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID68_SWCHANNELID68_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID68_SWCHANNELID68_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID68_RESETVAL                      (0x00000000U)

/* SWCHANNELID68TS */

#define CSL_SMSETSW_SWCHANNELID68TS_SWCHANNELID68TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID68TS_SWCHANNELID68TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID68TS_SWCHANNELID68TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID68TS_SWCHANNELID68TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID68TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID69 */

#define CSL_SMSETSW_SWCHANNELID69_SWCHANNELID69_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID69_SWCHANNELID69_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID69_SWCHANNELID69_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID69_SWCHANNELID69_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID69_RESETVAL                      (0x00000000U)

/* SWCHANNELID69TS */

#define CSL_SMSETSW_SWCHANNELID69TS_SWCHANNELID69TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID69TS_SWCHANNELID69TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID69TS_SWCHANNELID69TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID69TS_SWCHANNELID69TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID69TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID70 */

#define CSL_SMSETSW_SWCHANNELID70_SWCHANNELID70_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID70_SWCHANNELID70_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID70_SWCHANNELID70_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID70_SWCHANNELID70_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID70_RESETVAL                      (0x00000000U)

/* SWCHANNELID70TS */

#define CSL_SMSETSW_SWCHANNELID70TS_SWCHANNELID70TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID70TS_SWCHANNELID70TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID70TS_SWCHANNELID70TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID70TS_SWCHANNELID70TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID70TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID71 */

#define CSL_SMSETSW_SWCHANNELID71_SWCHANNELID71_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID71_SWCHANNELID71_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID71_SWCHANNELID71_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID71_SWCHANNELID71_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID71_RESETVAL                      (0x00000000U)

/* SWCHANNELID71TS */

#define CSL_SMSETSW_SWCHANNELID71TS_SWCHANNELID71TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID71TS_SWCHANNELID71TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID71TS_SWCHANNELID71TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID71TS_SWCHANNELID71TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID71TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID72 */

#define CSL_SMSETSW_SWCHANNELID72_SWCHANNELID72_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID72_SWCHANNELID72_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID72_SWCHANNELID72_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID72_SWCHANNELID72_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID72_RESETVAL                      (0x00000000U)

/* SWCHANNELID72TS */

#define CSL_SMSETSW_SWCHANNELID72TS_SWCHANNELID72TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID72TS_SWCHANNELID72TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID72TS_SWCHANNELID72TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID72TS_SWCHANNELID72TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID72TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID73 */

#define CSL_SMSETSW_SWCHANNELID73_SWCHANNELID73_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID73_SWCHANNELID73_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID73_SWCHANNELID73_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID73_SWCHANNELID73_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID73_RESETVAL                      (0x00000000U)

/* SWCHANNELID73TS */

#define CSL_SMSETSW_SWCHANNELID73TS_SWCHANNELID73TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID73TS_SWCHANNELID73TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID73TS_SWCHANNELID73TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID73TS_SWCHANNELID73TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID73TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID74 */

#define CSL_SMSETSW_SWCHANNELID74_SWCHANNELID74_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID74_SWCHANNELID74_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID74_SWCHANNELID74_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID74_SWCHANNELID74_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID74_RESETVAL                      (0x00000000U)

/* SWCHANNELID74TS */

#define CSL_SMSETSW_SWCHANNELID74TS_SWCHANNELID74TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID74TS_SWCHANNELID74TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID74TS_SWCHANNELID74TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID74TS_SWCHANNELID74TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID74TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID75 */

#define CSL_SMSETSW_SWCHANNELID75_SWCHANNELID75_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID75_SWCHANNELID75_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID75_SWCHANNELID75_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID75_SWCHANNELID75_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID75_RESETVAL                      (0x00000000U)

/* SWCHANNELID75TS */

#define CSL_SMSETSW_SWCHANNELID75TS_SWCHANNELID75TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID75TS_SWCHANNELID75TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID75TS_SWCHANNELID75TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID75TS_SWCHANNELID75TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID75TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID76 */

#define CSL_SMSETSW_SWCHANNELID76_SWCHANNELID76_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID76_SWCHANNELID76_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID76_SWCHANNELID76_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID76_SWCHANNELID76_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID76_RESETVAL                      (0x00000000U)

/* SWCHANNELID76TS */

#define CSL_SMSETSW_SWCHANNELID76TS_SWCHANNELID76TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID76TS_SWCHANNELID76TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID76TS_SWCHANNELID76TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID76TS_SWCHANNELID76TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID76TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID77 */

#define CSL_SMSETSW_SWCHANNELID77_SWCHANNELID77_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID77_SWCHANNELID77_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID77_SWCHANNELID77_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID77_SWCHANNELID77_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID77_RESETVAL                      (0x00000000U)

/* SWCHANNELID77TS */

#define CSL_SMSETSW_SWCHANNELID77TS_SWCHANNELID77TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID77TS_SWCHANNELID77TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID77TS_SWCHANNELID77TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID77TS_SWCHANNELID77TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID77TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID78 */

#define CSL_SMSETSW_SWCHANNELID78_SWCHANNELID78_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID78_SWCHANNELID78_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID78_SWCHANNELID78_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID78_SWCHANNELID78_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID78_RESETVAL                      (0x00000000U)

/* SWCHANNELID78TS */

#define CSL_SMSETSW_SWCHANNELID78TS_SWCHANNELID78TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID78TS_SWCHANNELID78TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID78TS_SWCHANNELID78TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID78TS_SWCHANNELID78TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID78TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID79 */

#define CSL_SMSETSW_SWCHANNELID79_SWCHANNELID79_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID79_SWCHANNELID79_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID79_SWCHANNELID79_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID79_SWCHANNELID79_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID79_RESETVAL                      (0x00000000U)

/* SWCHANNELID79TS */

#define CSL_SMSETSW_SWCHANNELID79TS_SWCHANNELID79TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID79TS_SWCHANNELID79TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID79TS_SWCHANNELID79TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID79TS_SWCHANNELID79TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID79TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID80 */

#define CSL_SMSETSW_SWCHANNELID80_SWCHANNELID80_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID80_SWCHANNELID80_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID80_SWCHANNELID80_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID80_SWCHANNELID80_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID80_RESETVAL                      (0x00000000U)

/* SWCHANNELID80TS */

#define CSL_SMSETSW_SWCHANNELID80TS_SWCHANNELID80TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID80TS_SWCHANNELID80TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID80TS_SWCHANNELID80TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID80TS_SWCHANNELID80TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID80TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID81 */

#define CSL_SMSETSW_SWCHANNELID81_SWCHANNELID81_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID81_SWCHANNELID81_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID81_SWCHANNELID81_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID81_SWCHANNELID81_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID81_RESETVAL                      (0x00000000U)

/* SWCHANNELID81TS */

#define CSL_SMSETSW_SWCHANNELID81TS_SWCHANNELID81TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID81TS_SWCHANNELID81TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID81TS_SWCHANNELID81TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID81TS_SWCHANNELID81TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID81TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID82 */

#define CSL_SMSETSW_SWCHANNELID82_SWCHANNELID82_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID82_SWCHANNELID82_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID82_SWCHANNELID82_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID82_SWCHANNELID82_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID82_RESETVAL                      (0x00000000U)

/* SWCHANNELID82TS */

#define CSL_SMSETSW_SWCHANNELID82TS_SWCHANNELID82TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID82TS_SWCHANNELID82TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID82TS_SWCHANNELID82TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID82TS_SWCHANNELID82TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID82TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID83 */

#define CSL_SMSETSW_SWCHANNELID83_SWCHANNELID83_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID83_SWCHANNELID83_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID83_SWCHANNELID83_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID83_SWCHANNELID83_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID83_RESETVAL                      (0x00000000U)

/* SWCHANNELID83TS */

#define CSL_SMSETSW_SWCHANNELID83TS_SWCHANNELID83TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID83TS_SWCHANNELID83TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID83TS_SWCHANNELID83TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID83TS_SWCHANNELID83TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID83TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID84 */

#define CSL_SMSETSW_SWCHANNELID84_SWCHANNELID84_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID84_SWCHANNELID84_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID84_SWCHANNELID84_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID84_SWCHANNELID84_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID84_RESETVAL                      (0x00000000U)

/* SWCHANNELID84TS */

#define CSL_SMSETSW_SWCHANNELID84TS_SWCHANNELID84TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID84TS_SWCHANNELID84TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID84TS_SWCHANNELID84TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID84TS_SWCHANNELID84TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID84TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID85 */

#define CSL_SMSETSW_SWCHANNELID85_SWCHANNELID85_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID85_SWCHANNELID85_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID85_SWCHANNELID85_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID85_SWCHANNELID85_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID85_RESETVAL                      (0x00000000U)

/* SWCHANNELID85TS */

#define CSL_SMSETSW_SWCHANNELID85TS_SWCHANNELID85TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID85TS_SWCHANNELID85TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID85TS_SWCHANNELID85TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID85TS_SWCHANNELID85TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID85TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID86 */

#define CSL_SMSETSW_SWCHANNELID86_SWCHANNELID86_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID86_SWCHANNELID86_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID86_SWCHANNELID86_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID86_SWCHANNELID86_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID86_RESETVAL                      (0x00000000U)

/* SWCHANNELID86TS */

#define CSL_SMSETSW_SWCHANNELID86TS_SWCHANNELID86TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID86TS_SWCHANNELID86TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID86TS_SWCHANNELID86TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID86TS_SWCHANNELID86TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID86TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID87 */

#define CSL_SMSETSW_SWCHANNELID87_SWCHANNELID87_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID87_SWCHANNELID87_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID87_SWCHANNELID87_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID87_SWCHANNELID87_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID87_RESETVAL                      (0x00000000U)

/* SWCHANNELID87TS */

#define CSL_SMSETSW_SWCHANNELID87TS_SWCHANNELID87TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID87TS_SWCHANNELID87TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID87TS_SWCHANNELID87TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID87TS_SWCHANNELID87TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID87TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID88 */

#define CSL_SMSETSW_SWCHANNELID88_SWCHANNELID88_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID88_SWCHANNELID88_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID88_SWCHANNELID88_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID88_SWCHANNELID88_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID88_RESETVAL                      (0x00000000U)

/* SWCHANNELID88TS */

#define CSL_SMSETSW_SWCHANNELID88TS_SWCHANNELID88TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID88TS_SWCHANNELID88TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID88TS_SWCHANNELID88TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID88TS_SWCHANNELID88TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID88TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID89 */

#define CSL_SMSETSW_SWCHANNELID89_SWCHANNELID89_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID89_SWCHANNELID89_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID89_SWCHANNELID89_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID89_SWCHANNELID89_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID89_RESETVAL                      (0x00000000U)

/* SWCHANNELID89TS */

#define CSL_SMSETSW_SWCHANNELID89TS_SWCHANNELID89TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID89TS_SWCHANNELID89TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID89TS_SWCHANNELID89TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID89TS_SWCHANNELID89TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID89TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID90 */

#define CSL_SMSETSW_SWCHANNELID90_SWCHANNELID90_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID90_SWCHANNELID90_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID90_SWCHANNELID90_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID90_SWCHANNELID90_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID90_RESETVAL                      (0x00000000U)

/* SWCHANNELID90TS */

#define CSL_SMSETSW_SWCHANNELID90TS_SWCHANNELID90TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID90TS_SWCHANNELID90TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID90TS_SWCHANNELID90TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID90TS_SWCHANNELID90TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID90TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID91 */

#define CSL_SMSETSW_SWCHANNELID91_SWCHANNELID91_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID91_SWCHANNELID91_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID91_SWCHANNELID91_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID91_SWCHANNELID91_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID91_RESETVAL                      (0x00000000U)

/* SWCHANNELID91TS */

#define CSL_SMSETSW_SWCHANNELID91TS_SWCHANNELID91TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID91TS_SWCHANNELID91TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID91TS_SWCHANNELID91TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID91TS_SWCHANNELID91TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID91TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID92 */

#define CSL_SMSETSW_SWCHANNELID92_SWCHANNELID92_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID92_SWCHANNELID92_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID92_SWCHANNELID92_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID92_SWCHANNELID92_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID92_RESETVAL                      (0x00000000U)

/* SWCHANNELID92TS */

#define CSL_SMSETSW_SWCHANNELID92TS_SWCHANNELID92TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID92TS_SWCHANNELID92TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID92TS_SWCHANNELID92TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID92TS_SWCHANNELID92TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID92TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID93 */

#define CSL_SMSETSW_SWCHANNELID93_SWCHANNELID93_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID93_SWCHANNELID93_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID93_SWCHANNELID93_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID93_SWCHANNELID93_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID93_RESETVAL                      (0x00000000U)

/* SWCHANNELID93TS */

#define CSL_SMSETSW_SWCHANNELID93TS_SWCHANNELID93TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID93TS_SWCHANNELID93TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID93TS_SWCHANNELID93TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID93TS_SWCHANNELID93TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID93TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID94 */

#define CSL_SMSETSW_SWCHANNELID94_SWCHANNELID94_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID94_SWCHANNELID94_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID94_SWCHANNELID94_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID94_SWCHANNELID94_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID94_RESETVAL                      (0x00000000U)

/* SWCHANNELID94TS */

#define CSL_SMSETSW_SWCHANNELID94TS_SWCHANNELID94TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID94TS_SWCHANNELID94TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID94TS_SWCHANNELID94TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID94TS_SWCHANNELID94TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID94TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID95 */

#define CSL_SMSETSW_SWCHANNELID95_SWCHANNELID95_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID95_SWCHANNELID95_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID95_SWCHANNELID95_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID95_SWCHANNELID95_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID95_RESETVAL                      (0x00000000U)

/* SWCHANNELID95TS */

#define CSL_SMSETSW_SWCHANNELID95TS_SWCHANNELID95TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID95TS_SWCHANNELID95TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID95TS_SWCHANNELID95TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID95TS_SWCHANNELID95TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID95TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID96 */

#define CSL_SMSETSW_SWCHANNELID96_SWCHANNELID96_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID96_SWCHANNELID96_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID96_SWCHANNELID96_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID96_SWCHANNELID96_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID96_RESETVAL                      (0x00000000U)

/* SWCHANNELID96TS */

#define CSL_SMSETSW_SWCHANNELID96TS_SWCHANNELID96TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID96TS_SWCHANNELID96TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID96TS_SWCHANNELID96TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID96TS_SWCHANNELID96TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID96TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID97 */

#define CSL_SMSETSW_SWCHANNELID97_SWCHANNELID97_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID97_SWCHANNELID97_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID97_SWCHANNELID97_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID97_SWCHANNELID97_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID97_RESETVAL                      (0x00000000U)

/* SWCHANNELID97TS */

#define CSL_SMSETSW_SWCHANNELID97TS_SWCHANNELID97TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID97TS_SWCHANNELID97TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID97TS_SWCHANNELID97TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID97TS_SWCHANNELID97TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID97TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID98 */

#define CSL_SMSETSW_SWCHANNELID98_SWCHANNELID98_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID98_SWCHANNELID98_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID98_SWCHANNELID98_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID98_SWCHANNELID98_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID98_RESETVAL                      (0x00000000U)

/* SWCHANNELID98TS */

#define CSL_SMSETSW_SWCHANNELID98TS_SWCHANNELID98TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID98TS_SWCHANNELID98TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID98TS_SWCHANNELID98TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID98TS_SWCHANNELID98TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID98TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID99 */

#define CSL_SMSETSW_SWCHANNELID99_SWCHANNELID99_MASK            (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID99_SWCHANNELID99_SHIFT           (0U)
#define CSL_SMSETSW_SWCHANNELID99_SWCHANNELID99_RESETVAL        (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID99_SWCHANNELID99_MAX             (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID99_RESETVAL                      (0x00000000U)

/* SWCHANNELID99TS */

#define CSL_SMSETSW_SWCHANNELID99TS_SWCHANNELID99TS_MASK        (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID99TS_SWCHANNELID99TS_SHIFT       (0U)
#define CSL_SMSETSW_SWCHANNELID99TS_SWCHANNELID99TS_RESETVAL    (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID99TS_SWCHANNELID99TS_MAX         (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID99TS_RESETVAL                    (0x00000000U)

/* SWCHANNELID100 */

#define CSL_SMSETSW_SWCHANNELID100_SWCHANNELID100_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID100_SWCHANNELID100_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID100_SWCHANNELID100_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID100_SWCHANNELID100_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID100_RESETVAL                     (0x00000000U)

/* SWCHANNELID100TS */

#define CSL_SMSETSW_SWCHANNELID100TS_SWCHANNELID100TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID100TS_SWCHANNELID100TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID100TS_SWCHANNELID100TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID100TS_SWCHANNELID100TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID100TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID101 */

#define CSL_SMSETSW_SWCHANNELID101_SWCHANNELID101_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID101_SWCHANNELID101_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID101_SWCHANNELID101_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID101_SWCHANNELID101_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID101_RESETVAL                     (0x00000000U)

/* SWCHANNELID101TS */

#define CSL_SMSETSW_SWCHANNELID101TS_SWCHANNELID101TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID101TS_SWCHANNELID101TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID101TS_SWCHANNELID101TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID101TS_SWCHANNELID101TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID101TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID102 */

#define CSL_SMSETSW_SWCHANNELID102_SWCHANNELID102_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID102_SWCHANNELID102_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID102_SWCHANNELID102_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID102_SWCHANNELID102_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID102_RESETVAL                     (0x00000000U)

/* SWCHANNELID102TS */

#define CSL_SMSETSW_SWCHANNELID102TS_SWCHANNELID102TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID102TS_SWCHANNELID102TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID102TS_SWCHANNELID102TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID102TS_SWCHANNELID102TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID102TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID103 */

#define CSL_SMSETSW_SWCHANNELID103_SWCHANNELID103_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID103_SWCHANNELID103_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID103_SWCHANNELID103_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID103_SWCHANNELID103_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID103_RESETVAL                     (0x00000000U)

/* SWCHANNELID103TS */

#define CSL_SMSETSW_SWCHANNELID103TS_SWCHANNELID103TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID103TS_SWCHANNELID103TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID103TS_SWCHANNELID103TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID103TS_SWCHANNELID103TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID103TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID104 */

#define CSL_SMSETSW_SWCHANNELID104_SWCHANNELID104_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID104_SWCHANNELID104_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID104_SWCHANNELID104_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID104_SWCHANNELID104_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID104_RESETVAL                     (0x00000000U)

/* SWCHANNELID104TS */

#define CSL_SMSETSW_SWCHANNELID104TS_SWCHANNELID104TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID104TS_SWCHANNELID104TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID104TS_SWCHANNELID104TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID104TS_SWCHANNELID104TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID104TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID105 */

#define CSL_SMSETSW_SWCHANNELID105_SWCHANNELID105_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID105_SWCHANNELID105_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID105_SWCHANNELID105_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID105_SWCHANNELID105_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID105_RESETVAL                     (0x00000000U)

/* SWCHANNELID105TS */

#define CSL_SMSETSW_SWCHANNELID105TS_SWCHANNELID105TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID105TS_SWCHANNELID105TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID105TS_SWCHANNELID105TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID105TS_SWCHANNELID105TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID105TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID106 */

#define CSL_SMSETSW_SWCHANNELID106_SWCHANNELID106_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID106_SWCHANNELID106_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID106_SWCHANNELID106_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID106_SWCHANNELID106_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID106_RESETVAL                     (0x00000000U)

/* SWCHANNELID106TS */

#define CSL_SMSETSW_SWCHANNELID106TS_SWCHANNELID106TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID106TS_SWCHANNELID106TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID106TS_SWCHANNELID106TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID106TS_SWCHANNELID106TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID106TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID107 */

#define CSL_SMSETSW_SWCHANNELID107_SWCHANNELID107_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID107_SWCHANNELID107_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID107_SWCHANNELID107_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID107_SWCHANNELID107_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID107_RESETVAL                     (0x00000000U)

/* SWCHANNELID107TS */

#define CSL_SMSETSW_SWCHANNELID107TS_SWCHANNELID107TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID107TS_SWCHANNELID107TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID107TS_SWCHANNELID107TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID107TS_SWCHANNELID107TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID107TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID108 */

#define CSL_SMSETSW_SWCHANNELID108_SWCHANNELID108_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID108_SWCHANNELID108_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID108_SWCHANNELID108_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID108_SWCHANNELID108_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID108_RESETVAL                     (0x00000000U)

/* SWCHANNELID108TS */

#define CSL_SMSETSW_SWCHANNELID108TS_SWCHANNELID108TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID108TS_SWCHANNELID108TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID108TS_SWCHANNELID108TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID108TS_SWCHANNELID108TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID108TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID109 */

#define CSL_SMSETSW_SWCHANNELID109_SWCHANNELID109_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID109_SWCHANNELID109_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID109_SWCHANNELID109_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID109_SWCHANNELID109_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID109_RESETVAL                     (0x00000000U)

/* SWCHANNELID109TS */

#define CSL_SMSETSW_SWCHANNELID109TS_SWCHANNELID109TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID109TS_SWCHANNELID109TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID109TS_SWCHANNELID109TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID109TS_SWCHANNELID109TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID109TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID110 */

#define CSL_SMSETSW_SWCHANNELID110_SWCHANNELID110_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID110_SWCHANNELID110_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID110_SWCHANNELID110_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID110_SWCHANNELID110_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID110_RESETVAL                     (0x00000000U)

/* SWCHANNELID110TS */

#define CSL_SMSETSW_SWCHANNELID110TS_SWCHANNELID110TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID110TS_SWCHANNELID110TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID110TS_SWCHANNELID110TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID110TS_SWCHANNELID110TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID110TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID111 */

#define CSL_SMSETSW_SWCHANNELID111_SWCHANNELID111_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID111_SWCHANNELID111_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID111_SWCHANNELID111_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID111_SWCHANNELID111_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID111_RESETVAL                     (0x00000000U)

/* SWCHANNELID111TS */

#define CSL_SMSETSW_SWCHANNELID111TS_SWCHANNELID111TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID111TS_SWCHANNELID111TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID111TS_SWCHANNELID111TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID111TS_SWCHANNELID111TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID111TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID112 */

#define CSL_SMSETSW_SWCHANNELID112_SWCHANNELID112_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID112_SWCHANNELID112_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID112_SWCHANNELID112_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID112_SWCHANNELID112_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID112_RESETVAL                     (0x00000000U)

/* SWCHANNELID112TS */

#define CSL_SMSETSW_SWCHANNELID112TS_SWCHANNELID112TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID112TS_SWCHANNELID112TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID112TS_SWCHANNELID112TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID112TS_SWCHANNELID112TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID112TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID113 */

#define CSL_SMSETSW_SWCHANNELID113_SWCHANNELID113_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID113_SWCHANNELID113_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID113_SWCHANNELID113_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID113_SWCHANNELID113_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID113_RESETVAL                     (0x00000000U)

/* SWCHANNELID113TS */

#define CSL_SMSETSW_SWCHANNELID113TS_SWCHANNELID113TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID113TS_SWCHANNELID113TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID113TS_SWCHANNELID113TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID113TS_SWCHANNELID113TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID113TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID114 */

#define CSL_SMSETSW_SWCHANNELID114_SWCHANNELID114_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID114_SWCHANNELID114_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID114_SWCHANNELID114_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID114_SWCHANNELID114_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID114_RESETVAL                     (0x00000000U)

/* SWCHANNELID114TS */

#define CSL_SMSETSW_SWCHANNELID114TS_SWCHANNELID114TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID114TS_SWCHANNELID114TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID114TS_SWCHANNELID114TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID114TS_SWCHANNELID114TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID114TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID115 */

#define CSL_SMSETSW_SWCHANNELID115_SWCHANNELID115_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID115_SWCHANNELID115_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID115_SWCHANNELID115_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID115_SWCHANNELID115_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID115_RESETVAL                     (0x00000000U)

/* SWCHANNELID115TS */

#define CSL_SMSETSW_SWCHANNELID115TS_SWCHANNELID115TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID115TS_SWCHANNELID115TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID115TS_SWCHANNELID115TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID115TS_SWCHANNELID115TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID115TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID116 */

#define CSL_SMSETSW_SWCHANNELID116_SWCHANNELID116_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID116_SWCHANNELID116_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID116_SWCHANNELID116_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID116_SWCHANNELID116_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID116_RESETVAL                     (0x00000000U)

/* SWCHANNELID116TS */

#define CSL_SMSETSW_SWCHANNELID116TS_SWCHANNELID116TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID116TS_SWCHANNELID116TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID116TS_SWCHANNELID116TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID116TS_SWCHANNELID116TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID116TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID117 */

#define CSL_SMSETSW_SWCHANNELID117_SWCHANNELID117_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID117_SWCHANNELID117_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID117_SWCHANNELID117_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID117_SWCHANNELID117_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID117_RESETVAL                     (0x00000000U)

/* SWCHANNELID117TS */

#define CSL_SMSETSW_SWCHANNELID117TS_SWCHANNELID117TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID117TS_SWCHANNELID117TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID117TS_SWCHANNELID117TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID117TS_SWCHANNELID117TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID117TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID118 */

#define CSL_SMSETSW_SWCHANNELID118_SWCHANNELID118_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID118_SWCHANNELID118_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID118_SWCHANNELID118_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID118_SWCHANNELID118_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID118_RESETVAL                     (0x00000000U)

/* SWCHANNELID118TS */

#define CSL_SMSETSW_SWCHANNELID118TS_SWCHANNELID118TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID118TS_SWCHANNELID118TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID118TS_SWCHANNELID118TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID118TS_SWCHANNELID118TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID118TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID119 */

#define CSL_SMSETSW_SWCHANNELID119_SWCHANNELID119_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID119_SWCHANNELID119_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID119_SWCHANNELID119_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID119_SWCHANNELID119_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID119_RESETVAL                     (0x00000000U)

/* SWCHANNELID119TS */

#define CSL_SMSETSW_SWCHANNELID119TS_SWCHANNELID119TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID119TS_SWCHANNELID119TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID119TS_SWCHANNELID119TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID119TS_SWCHANNELID119TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID119TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID120 */

#define CSL_SMSETSW_SWCHANNELID120_SWCHANNELID120_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID120_SWCHANNELID120_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID120_SWCHANNELID120_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID120_SWCHANNELID120_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID120_RESETVAL                     (0x00000000U)

/* SWCHANNELID120TS */

#define CSL_SMSETSW_SWCHANNELID120TS_SWCHANNELID120TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID120TS_SWCHANNELID120TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID120TS_SWCHANNELID120TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID120TS_SWCHANNELID120TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID120TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID121 */

#define CSL_SMSETSW_SWCHANNELID121_SWCHANNELID121_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID121_SWCHANNELID121_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID121_SWCHANNELID121_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID121_SWCHANNELID121_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID121_RESETVAL                     (0x00000000U)

/* SWCHANNELID121TS */

#define CSL_SMSETSW_SWCHANNELID121TS_SWCHANNELID121TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID121TS_SWCHANNELID121TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID121TS_SWCHANNELID121TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID121TS_SWCHANNELID121TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID121TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID122 */

#define CSL_SMSETSW_SWCHANNELID122_SWCHANNELID122_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID122_SWCHANNELID122_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID122_SWCHANNELID122_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID122_SWCHANNELID122_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID122_RESETVAL                     (0x00000000U)

/* SWCHANNELID122TS */

#define CSL_SMSETSW_SWCHANNELID122TS_SWCHANNELID122TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID122TS_SWCHANNELID122TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID122TS_SWCHANNELID122TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID122TS_SWCHANNELID122TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID122TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID123 */

#define CSL_SMSETSW_SWCHANNELID123_SWCHANNELID123_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID123_SWCHANNELID123_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID123_SWCHANNELID123_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID123_SWCHANNELID123_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID123_RESETVAL                     (0x00000000U)

/* SWCHANNELID123TS */

#define CSL_SMSETSW_SWCHANNELID123TS_SWCHANNELID123TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID123TS_SWCHANNELID123TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID123TS_SWCHANNELID123TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID123TS_SWCHANNELID123TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID123TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID124 */

#define CSL_SMSETSW_SWCHANNELID124_SWCHANNELID124_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID124_SWCHANNELID124_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID124_SWCHANNELID124_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID124_SWCHANNELID124_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID124_RESETVAL                     (0x00000000U)

/* SWCHANNELID124TS */

#define CSL_SMSETSW_SWCHANNELID124TS_SWCHANNELID124TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID124TS_SWCHANNELID124TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID124TS_SWCHANNELID124TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID124TS_SWCHANNELID124TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID124TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID125 */

#define CSL_SMSETSW_SWCHANNELID125_SWCHANNELID125_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID125_SWCHANNELID125_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID125_SWCHANNELID125_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID125_SWCHANNELID125_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID125_RESETVAL                     (0x00000000U)

/* SWCHANNELID125TS */

#define CSL_SMSETSW_SWCHANNELID125TS_SWCHANNELID125TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID125TS_SWCHANNELID125TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID125TS_SWCHANNELID125TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID125TS_SWCHANNELID125TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID125TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID126 */

#define CSL_SMSETSW_SWCHANNELID126_SWCHANNELID126_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID126_SWCHANNELID126_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID126_SWCHANNELID126_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID126_SWCHANNELID126_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID126_RESETVAL                     (0x00000000U)

/* SWCHANNELID126TS */

#define CSL_SMSETSW_SWCHANNELID126TS_SWCHANNELID126TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID126TS_SWCHANNELID126TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID126TS_SWCHANNELID126TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID126TS_SWCHANNELID126TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID126TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID127 */

#define CSL_SMSETSW_SWCHANNELID127_SWCHANNELID127_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID127_SWCHANNELID127_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID127_SWCHANNELID127_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID127_SWCHANNELID127_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID127_RESETVAL                     (0x00000000U)

/* SWCHANNELID127TS */

#define CSL_SMSETSW_SWCHANNELID127TS_SWCHANNELID127TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID127TS_SWCHANNELID127TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID127TS_SWCHANNELID127TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID127TS_SWCHANNELID127TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID127TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID128 */

#define CSL_SMSETSW_SWCHANNELID128_SWCHANNELID128_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID128_SWCHANNELID128_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID128_SWCHANNELID128_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID128_SWCHANNELID128_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID128_RESETVAL                     (0x00000000U)

/* SWCHANNELID128TS */

#define CSL_SMSETSW_SWCHANNELID128TS_SWCHANNELID128TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID128TS_SWCHANNELID128TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID128TS_SWCHANNELID128TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID128TS_SWCHANNELID128TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID128TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID129 */

#define CSL_SMSETSW_SWCHANNELID129_SWCHANNELID129_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID129_SWCHANNELID129_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID129_SWCHANNELID129_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID129_SWCHANNELID129_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID129_RESETVAL                     (0x00000000U)

/* SWCHANNELID129TS */

#define CSL_SMSETSW_SWCHANNELID129TS_SWCHANNELID129TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID129TS_SWCHANNELID129TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID129TS_SWCHANNELID129TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID129TS_SWCHANNELID129TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID129TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID130 */

#define CSL_SMSETSW_SWCHANNELID130_SWCHANNELID130_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID130_SWCHANNELID130_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID130_SWCHANNELID130_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID130_SWCHANNELID130_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID130_RESETVAL                     (0x00000000U)

/* SWCHANNELID130TS */

#define CSL_SMSETSW_SWCHANNELID130TS_SWCHANNELID130TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID130TS_SWCHANNELID130TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID130TS_SWCHANNELID130TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID130TS_SWCHANNELID130TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID130TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID131 */

#define CSL_SMSETSW_SWCHANNELID131_SWCHANNELID131_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID131_SWCHANNELID131_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID131_SWCHANNELID131_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID131_SWCHANNELID131_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID131_RESETVAL                     (0x00000000U)

/* SWCHANNELID131TS */

#define CSL_SMSETSW_SWCHANNELID131TS_SWCHANNELID131TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID131TS_SWCHANNELID131TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID131TS_SWCHANNELID131TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID131TS_SWCHANNELID131TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID131TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID132 */

#define CSL_SMSETSW_SWCHANNELID132_SWCHANNELID132_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID132_SWCHANNELID132_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID132_SWCHANNELID132_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID132_SWCHANNELID132_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID132_RESETVAL                     (0x00000000U)

/* SWCHANNELID132TS */

#define CSL_SMSETSW_SWCHANNELID132TS_SWCHANNELID132TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID132TS_SWCHANNELID132TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID132TS_SWCHANNELID132TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID132TS_SWCHANNELID132TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID132TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID133 */

#define CSL_SMSETSW_SWCHANNELID133_SWCHANNELID133_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID133_SWCHANNELID133_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID133_SWCHANNELID133_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID133_SWCHANNELID133_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID133_RESETVAL                     (0x00000000U)

/* SWCHANNELID133TS */

#define CSL_SMSETSW_SWCHANNELID133TS_SWCHANNELID133TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID133TS_SWCHANNELID133TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID133TS_SWCHANNELID133TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID133TS_SWCHANNELID133TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID133TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID134 */

#define CSL_SMSETSW_SWCHANNELID134_SWCHANNELID134_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID134_SWCHANNELID134_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID134_SWCHANNELID134_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID134_SWCHANNELID134_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID134_RESETVAL                     (0x00000000U)

/* SWCHANNELID134TS */

#define CSL_SMSETSW_SWCHANNELID134TS_SWCHANNELID134TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID134TS_SWCHANNELID134TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID134TS_SWCHANNELID134TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID134TS_SWCHANNELID134TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID134TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID135 */

#define CSL_SMSETSW_SWCHANNELID135_SWCHANNELID135_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID135_SWCHANNELID135_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID135_SWCHANNELID135_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID135_SWCHANNELID135_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID135_RESETVAL                     (0x00000000U)

/* SWCHANNELID135TS */

#define CSL_SMSETSW_SWCHANNELID135TS_SWCHANNELID135TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID135TS_SWCHANNELID135TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID135TS_SWCHANNELID135TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID135TS_SWCHANNELID135TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID135TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID136 */

#define CSL_SMSETSW_SWCHANNELID136_SWCHANNELID136_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID136_SWCHANNELID136_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID136_SWCHANNELID136_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID136_SWCHANNELID136_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID136_RESETVAL                     (0x00000000U)

/* SWCHANNELID136TS */

#define CSL_SMSETSW_SWCHANNELID136TS_SWCHANNELID136TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID136TS_SWCHANNELID136TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID136TS_SWCHANNELID136TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID136TS_SWCHANNELID136TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID136TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID137 */

#define CSL_SMSETSW_SWCHANNELID137_SWCHANNELID137_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID137_SWCHANNELID137_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID137_SWCHANNELID137_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID137_SWCHANNELID137_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID137_RESETVAL                     (0x00000000U)

/* SWCHANNELID137TS */

#define CSL_SMSETSW_SWCHANNELID137TS_SWCHANNELID137TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID137TS_SWCHANNELID137TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID137TS_SWCHANNELID137TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID137TS_SWCHANNELID137TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID137TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID138 */

#define CSL_SMSETSW_SWCHANNELID138_SWCHANNELID138_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID138_SWCHANNELID138_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID138_SWCHANNELID138_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID138_SWCHANNELID138_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID138_RESETVAL                     (0x00000000U)

/* SWCHANNELID138TS */

#define CSL_SMSETSW_SWCHANNELID138TS_SWCHANNELID138TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID138TS_SWCHANNELID138TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID138TS_SWCHANNELID138TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID138TS_SWCHANNELID138TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID138TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID139 */

#define CSL_SMSETSW_SWCHANNELID139_SWCHANNELID139_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID139_SWCHANNELID139_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID139_SWCHANNELID139_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID139_SWCHANNELID139_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID139_RESETVAL                     (0x00000000U)

/* SWCHANNELID139TS */

#define CSL_SMSETSW_SWCHANNELID139TS_SWCHANNELID139TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID139TS_SWCHANNELID139TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID139TS_SWCHANNELID139TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID139TS_SWCHANNELID139TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID139TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID140 */

#define CSL_SMSETSW_SWCHANNELID140_SWCHANNELID140_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID140_SWCHANNELID140_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID140_SWCHANNELID140_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID140_SWCHANNELID140_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID140_RESETVAL                     (0x00000000U)

/* SWCHANNELID140TS */

#define CSL_SMSETSW_SWCHANNELID140TS_SWCHANNELID140TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID140TS_SWCHANNELID140TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID140TS_SWCHANNELID140TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID140TS_SWCHANNELID140TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID140TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID141 */

#define CSL_SMSETSW_SWCHANNELID141_SWCHANNELID141_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID141_SWCHANNELID141_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID141_SWCHANNELID141_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID141_SWCHANNELID141_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID141_RESETVAL                     (0x00000000U)

/* SWCHANNELID141TS */

#define CSL_SMSETSW_SWCHANNELID141TS_SWCHANNELID141TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID141TS_SWCHANNELID141TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID141TS_SWCHANNELID141TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID141TS_SWCHANNELID141TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID141TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID142 */

#define CSL_SMSETSW_SWCHANNELID142_SWCHANNELID142_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID142_SWCHANNELID142_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID142_SWCHANNELID142_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID142_SWCHANNELID142_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID142_RESETVAL                     (0x00000000U)

/* SWCHANNELID142TS */

#define CSL_SMSETSW_SWCHANNELID142TS_SWCHANNELID142TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID142TS_SWCHANNELID142TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID142TS_SWCHANNELID142TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID142TS_SWCHANNELID142TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID142TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID143 */

#define CSL_SMSETSW_SWCHANNELID143_SWCHANNELID143_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID143_SWCHANNELID143_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID143_SWCHANNELID143_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID143_SWCHANNELID143_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID143_RESETVAL                     (0x00000000U)

/* SWCHANNELID143TS */

#define CSL_SMSETSW_SWCHANNELID143TS_SWCHANNELID143TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID143TS_SWCHANNELID143TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID143TS_SWCHANNELID143TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID143TS_SWCHANNELID143TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID143TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID144 */

#define CSL_SMSETSW_SWCHANNELID144_SWCHANNELID144_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID144_SWCHANNELID144_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID144_SWCHANNELID144_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID144_SWCHANNELID144_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID144_RESETVAL                     (0x00000000U)

/* SWCHANNELID144TS */

#define CSL_SMSETSW_SWCHANNELID144TS_SWCHANNELID144TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID144TS_SWCHANNELID144TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID144TS_SWCHANNELID144TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID144TS_SWCHANNELID144TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID144TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID145 */

#define CSL_SMSETSW_SWCHANNELID145_SWCHANNELID145_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID145_SWCHANNELID145_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID145_SWCHANNELID145_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID145_SWCHANNELID145_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID145_RESETVAL                     (0x00000000U)

/* SWCHANNELID145TS */

#define CSL_SMSETSW_SWCHANNELID145TS_SWCHANNELID145TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID145TS_SWCHANNELID145TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID145TS_SWCHANNELID145TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID145TS_SWCHANNELID145TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID145TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID146 */

#define CSL_SMSETSW_SWCHANNELID146_SWCHANNELID146_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID146_SWCHANNELID146_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID146_SWCHANNELID146_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID146_SWCHANNELID146_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID146_RESETVAL                     (0x00000000U)

/* SWCHANNELID146TS */

#define CSL_SMSETSW_SWCHANNELID146TS_SWCHANNELID146TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID146TS_SWCHANNELID146TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID146TS_SWCHANNELID146TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID146TS_SWCHANNELID146TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID146TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID147 */

#define CSL_SMSETSW_SWCHANNELID147_SWCHANNELID147_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID147_SWCHANNELID147_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID147_SWCHANNELID147_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID147_SWCHANNELID147_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID147_RESETVAL                     (0x00000000U)

/* SWCHANNELID147TS */

#define CSL_SMSETSW_SWCHANNELID147TS_SWCHANNELID147TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID147TS_SWCHANNELID147TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID147TS_SWCHANNELID147TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID147TS_SWCHANNELID147TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID147TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID148 */

#define CSL_SMSETSW_SWCHANNELID148_SWCHANNELID148_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID148_SWCHANNELID148_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID148_SWCHANNELID148_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID148_SWCHANNELID148_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID148_RESETVAL                     (0x00000000U)

/* SWCHANNELID148TS */

#define CSL_SMSETSW_SWCHANNELID148TS_SWCHANNELID148TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID148TS_SWCHANNELID148TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID148TS_SWCHANNELID148TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID148TS_SWCHANNELID148TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID148TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID149 */

#define CSL_SMSETSW_SWCHANNELID149_SWCHANNELID149_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID149_SWCHANNELID149_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID149_SWCHANNELID149_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID149_SWCHANNELID149_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID149_RESETVAL                     (0x00000000U)

/* SWCHANNELID149TS */

#define CSL_SMSETSW_SWCHANNELID149TS_SWCHANNELID149TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID149TS_SWCHANNELID149TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID149TS_SWCHANNELID149TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID149TS_SWCHANNELID149TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID149TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID150 */

#define CSL_SMSETSW_SWCHANNELID150_SWCHANNELID150_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID150_SWCHANNELID150_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID150_SWCHANNELID150_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID150_SWCHANNELID150_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID150_RESETVAL                     (0x00000000U)

/* SWCHANNELID150TS */

#define CSL_SMSETSW_SWCHANNELID150TS_SWCHANNELID150TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID150TS_SWCHANNELID150TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID150TS_SWCHANNELID150TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID150TS_SWCHANNELID150TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID150TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID151 */

#define CSL_SMSETSW_SWCHANNELID151_SWCHANNELID151_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID151_SWCHANNELID151_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID151_SWCHANNELID151_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID151_SWCHANNELID151_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID151_RESETVAL                     (0x00000000U)

/* SWCHANNELID151TS */

#define CSL_SMSETSW_SWCHANNELID151TS_SWCHANNELID151TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID151TS_SWCHANNELID151TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID151TS_SWCHANNELID151TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID151TS_SWCHANNELID151TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID151TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID152 */

#define CSL_SMSETSW_SWCHANNELID152_SWCHANNELID152_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID152_SWCHANNELID152_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID152_SWCHANNELID152_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID152_SWCHANNELID152_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID152_RESETVAL                     (0x00000000U)

/* SWCHANNELID152TS */

#define CSL_SMSETSW_SWCHANNELID152TS_SWCHANNELID152TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID152TS_SWCHANNELID152TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID152TS_SWCHANNELID152TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID152TS_SWCHANNELID152TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID152TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID153 */

#define CSL_SMSETSW_SWCHANNELID153_SWCHANNELID153_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID153_SWCHANNELID153_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID153_SWCHANNELID153_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID153_SWCHANNELID153_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID153_RESETVAL                     (0x00000000U)

/* SWCHANNELID153TS */

#define CSL_SMSETSW_SWCHANNELID153TS_SWCHANNELID153TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID153TS_SWCHANNELID153TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID153TS_SWCHANNELID153TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID153TS_SWCHANNELID153TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID153TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID154 */

#define CSL_SMSETSW_SWCHANNELID154_SWCHANNELID154_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID154_SWCHANNELID154_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID154_SWCHANNELID154_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID154_SWCHANNELID154_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID154_RESETVAL                     (0x00000000U)

/* SWCHANNELID154TS */

#define CSL_SMSETSW_SWCHANNELID154TS_SWCHANNELID154TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID154TS_SWCHANNELID154TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID154TS_SWCHANNELID154TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID154TS_SWCHANNELID154TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID154TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID155 */

#define CSL_SMSETSW_SWCHANNELID155_SWCHANNELID155_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID155_SWCHANNELID155_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID155_SWCHANNELID155_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID155_SWCHANNELID155_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID155_RESETVAL                     (0x00000000U)

/* SWCHANNELID155TS */

#define CSL_SMSETSW_SWCHANNELID155TS_SWCHANNELID155TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID155TS_SWCHANNELID155TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID155TS_SWCHANNELID155TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID155TS_SWCHANNELID155TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID155TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID156 */

#define CSL_SMSETSW_SWCHANNELID156_SWCHANNELID156_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID156_SWCHANNELID156_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID156_SWCHANNELID156_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID156_SWCHANNELID156_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID156_RESETVAL                     (0x00000000U)

/* SWCHANNELID156TS */

#define CSL_SMSETSW_SWCHANNELID156TS_SWCHANNELID156TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID156TS_SWCHANNELID156TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID156TS_SWCHANNELID156TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID156TS_SWCHANNELID156TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID156TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID157 */

#define CSL_SMSETSW_SWCHANNELID157_SWCHANNELID157_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID157_SWCHANNELID157_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID157_SWCHANNELID157_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID157_SWCHANNELID157_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID157_RESETVAL                     (0x00000000U)

/* SWCHANNELID157TS */

#define CSL_SMSETSW_SWCHANNELID157TS_SWCHANNELID157TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID157TS_SWCHANNELID157TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID157TS_SWCHANNELID157TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID157TS_SWCHANNELID157TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID157TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID158 */

#define CSL_SMSETSW_SWCHANNELID158_SWCHANNELID158_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID158_SWCHANNELID158_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID158_SWCHANNELID158_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID158_SWCHANNELID158_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID158_RESETVAL                     (0x00000000U)

/* SWCHANNELID158TS */

#define CSL_SMSETSW_SWCHANNELID158TS_SWCHANNELID158TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID158TS_SWCHANNELID158TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID158TS_SWCHANNELID158TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID158TS_SWCHANNELID158TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID158TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID159 */

#define CSL_SMSETSW_SWCHANNELID159_SWCHANNELID159_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID159_SWCHANNELID159_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID159_SWCHANNELID159_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID159_SWCHANNELID159_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID159_RESETVAL                     (0x00000000U)

/* SWCHANNELID159TS */

#define CSL_SMSETSW_SWCHANNELID159TS_SWCHANNELID159TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID159TS_SWCHANNELID159TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID159TS_SWCHANNELID159TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID159TS_SWCHANNELID159TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID159TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID160 */

#define CSL_SMSETSW_SWCHANNELID160_SWCHANNELID160_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID160_SWCHANNELID160_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID160_SWCHANNELID160_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID160_SWCHANNELID160_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID160_RESETVAL                     (0x00000000U)

/* SWCHANNELID160TS */

#define CSL_SMSETSW_SWCHANNELID160TS_SWCHANNELID160TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID160TS_SWCHANNELID160TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID160TS_SWCHANNELID160TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID160TS_SWCHANNELID160TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID160TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID161 */

#define CSL_SMSETSW_SWCHANNELID161_SWCHANNELID161_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID161_SWCHANNELID161_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID161_SWCHANNELID161_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID161_SWCHANNELID161_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID161_RESETVAL                     (0x00000000U)

/* SWCHANNELID161TS */

#define CSL_SMSETSW_SWCHANNELID161TS_SWCHANNELID161TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID161TS_SWCHANNELID161TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID161TS_SWCHANNELID161TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID161TS_SWCHANNELID161TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID161TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID162 */

#define CSL_SMSETSW_SWCHANNELID162_SWCHANNELID162_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID162_SWCHANNELID162_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID162_SWCHANNELID162_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID162_SWCHANNELID162_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID162_RESETVAL                     (0x00000000U)

/* SWCHANNELID162TS */

#define CSL_SMSETSW_SWCHANNELID162TS_SWCHANNELID162TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID162TS_SWCHANNELID162TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID162TS_SWCHANNELID162TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID162TS_SWCHANNELID162TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID162TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID163 */

#define CSL_SMSETSW_SWCHANNELID163_SWCHANNELID163_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID163_SWCHANNELID163_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID163_SWCHANNELID163_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID163_SWCHANNELID163_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID163_RESETVAL                     (0x00000000U)

/* SWCHANNELID163TS */

#define CSL_SMSETSW_SWCHANNELID163TS_SWCHANNELID163TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID163TS_SWCHANNELID163TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID163TS_SWCHANNELID163TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID163TS_SWCHANNELID163TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID163TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID164 */

#define CSL_SMSETSW_SWCHANNELID164_SWCHANNELID164_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID164_SWCHANNELID164_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID164_SWCHANNELID164_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID164_SWCHANNELID164_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID164_RESETVAL                     (0x00000000U)

/* SWCHANNELID164TS */

#define CSL_SMSETSW_SWCHANNELID164TS_SWCHANNELID164TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID164TS_SWCHANNELID164TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID164TS_SWCHANNELID164TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID164TS_SWCHANNELID164TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID164TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID165 */

#define CSL_SMSETSW_SWCHANNELID165_SWCHANNELID165_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID165_SWCHANNELID165_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID165_SWCHANNELID165_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID165_SWCHANNELID165_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID165_RESETVAL                     (0x00000000U)

/* SWCHANNELID165TS */

#define CSL_SMSETSW_SWCHANNELID165TS_SWCHANNELID165TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID165TS_SWCHANNELID165TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID165TS_SWCHANNELID165TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID165TS_SWCHANNELID165TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID165TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID166 */

#define CSL_SMSETSW_SWCHANNELID166_SWCHANNELID166_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID166_SWCHANNELID166_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID166_SWCHANNELID166_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID166_SWCHANNELID166_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID166_RESETVAL                     (0x00000000U)

/* SWCHANNELID166TS */

#define CSL_SMSETSW_SWCHANNELID166TS_SWCHANNELID166TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID166TS_SWCHANNELID166TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID166TS_SWCHANNELID166TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID166TS_SWCHANNELID166TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID166TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID167 */

#define CSL_SMSETSW_SWCHANNELID167_SWCHANNELID167_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID167_SWCHANNELID167_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID167_SWCHANNELID167_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID167_SWCHANNELID167_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID167_RESETVAL                     (0x00000000U)

/* SWCHANNELID167TS */

#define CSL_SMSETSW_SWCHANNELID167TS_SWCHANNELID167TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID167TS_SWCHANNELID167TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID167TS_SWCHANNELID167TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID167TS_SWCHANNELID167TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID167TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID168 */

#define CSL_SMSETSW_SWCHANNELID168_SWCHANNELID168_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID168_SWCHANNELID168_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID168_SWCHANNELID168_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID168_SWCHANNELID168_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID168_RESETVAL                     (0x00000000U)

/* SWCHANNELID168TS */

#define CSL_SMSETSW_SWCHANNELID168TS_SWCHANNELID168TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID168TS_SWCHANNELID168TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID168TS_SWCHANNELID168TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID168TS_SWCHANNELID168TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID168TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID169 */

#define CSL_SMSETSW_SWCHANNELID169_SWCHANNELID169_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID169_SWCHANNELID169_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID169_SWCHANNELID169_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID169_SWCHANNELID169_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID169_RESETVAL                     (0x00000000U)

/* SWCHANNELID169TS */

#define CSL_SMSETSW_SWCHANNELID169TS_SWCHANNELID169TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID169TS_SWCHANNELID169TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID169TS_SWCHANNELID169TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID169TS_SWCHANNELID169TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID169TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID170 */

#define CSL_SMSETSW_SWCHANNELID170_SWCHANNELID170_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID170_SWCHANNELID170_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID170_SWCHANNELID170_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID170_SWCHANNELID170_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID170_RESETVAL                     (0x00000000U)

/* SWCHANNELID170TS */

#define CSL_SMSETSW_SWCHANNELID170TS_SWCHANNELID170TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID170TS_SWCHANNELID170TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID170TS_SWCHANNELID170TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID170TS_SWCHANNELID170TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID170TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID171 */

#define CSL_SMSETSW_SWCHANNELID171_SWCHANNELID171_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID171_SWCHANNELID171_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID171_SWCHANNELID171_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID171_SWCHANNELID171_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID171_RESETVAL                     (0x00000000U)

/* SWCHANNELID171TS */

#define CSL_SMSETSW_SWCHANNELID171TS_SWCHANNELID171TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID171TS_SWCHANNELID171TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID171TS_SWCHANNELID171TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID171TS_SWCHANNELID171TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID171TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID172 */

#define CSL_SMSETSW_SWCHANNELID172_SWCHANNELID172_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID172_SWCHANNELID172_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID172_SWCHANNELID172_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID172_SWCHANNELID172_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID172_RESETVAL                     (0x00000000U)

/* SWCHANNELID172TS */

#define CSL_SMSETSW_SWCHANNELID172TS_SWCHANNELID172TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID172TS_SWCHANNELID172TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID172TS_SWCHANNELID172TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID172TS_SWCHANNELID172TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID172TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID173 */

#define CSL_SMSETSW_SWCHANNELID173_SWCHANNELID173_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID173_SWCHANNELID173_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID173_SWCHANNELID173_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID173_SWCHANNELID173_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID173_RESETVAL                     (0x00000000U)

/* SWCHANNELID173TS */

#define CSL_SMSETSW_SWCHANNELID173TS_SWCHANNELID173TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID173TS_SWCHANNELID173TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID173TS_SWCHANNELID173TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID173TS_SWCHANNELID173TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID173TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID174 */

#define CSL_SMSETSW_SWCHANNELID174_SWCHANNELID174_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID174_SWCHANNELID174_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID174_SWCHANNELID174_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID174_SWCHANNELID174_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID174_RESETVAL                     (0x00000000U)

/* SWCHANNELID174TS */

#define CSL_SMSETSW_SWCHANNELID174TS_SWCHANNELID174TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID174TS_SWCHANNELID174TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID174TS_SWCHANNELID174TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID174TS_SWCHANNELID174TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID174TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID175 */

#define CSL_SMSETSW_SWCHANNELID175_SWCHANNELID175_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID175_SWCHANNELID175_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID175_SWCHANNELID175_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID175_SWCHANNELID175_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID175_RESETVAL                     (0x00000000U)

/* SWCHANNELID175TS */

#define CSL_SMSETSW_SWCHANNELID175TS_SWCHANNELID175TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID175TS_SWCHANNELID175TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID175TS_SWCHANNELID175TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID175TS_SWCHANNELID175TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID175TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID176 */

#define CSL_SMSETSW_SWCHANNELID176_SWCHANNELID176_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID176_SWCHANNELID176_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID176_SWCHANNELID176_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID176_SWCHANNELID176_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID176_RESETVAL                     (0x00000000U)

/* SWCHANNELID176TS */

#define CSL_SMSETSW_SWCHANNELID176TS_SWCHANNELID176TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID176TS_SWCHANNELID176TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID176TS_SWCHANNELID176TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID176TS_SWCHANNELID176TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID176TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID177 */

#define CSL_SMSETSW_SWCHANNELID177_SWCHANNELID177_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID177_SWCHANNELID177_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID177_SWCHANNELID177_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID177_SWCHANNELID177_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID177_RESETVAL                     (0x00000000U)

/* SWCHANNELID177TS */

#define CSL_SMSETSW_SWCHANNELID177TS_SWCHANNELID177TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID177TS_SWCHANNELID177TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID177TS_SWCHANNELID177TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID177TS_SWCHANNELID177TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID177TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID178 */

#define CSL_SMSETSW_SWCHANNELID178_SWCHANNELID178_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID178_SWCHANNELID178_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID178_SWCHANNELID178_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID178_SWCHANNELID178_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID178_RESETVAL                     (0x00000000U)

/* SWCHANNELID178TS */

#define CSL_SMSETSW_SWCHANNELID178TS_SWCHANNELID178TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID178TS_SWCHANNELID178TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID178TS_SWCHANNELID178TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID178TS_SWCHANNELID178TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID178TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID179 */

#define CSL_SMSETSW_SWCHANNELID179_SWCHANNELID179_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID179_SWCHANNELID179_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID179_SWCHANNELID179_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID179_SWCHANNELID179_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID179_RESETVAL                     (0x00000000U)

/* SWCHANNELID179TS */

#define CSL_SMSETSW_SWCHANNELID179TS_SWCHANNELID179TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID179TS_SWCHANNELID179TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID179TS_SWCHANNELID179TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID179TS_SWCHANNELID179TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID179TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID180 */

#define CSL_SMSETSW_SWCHANNELID180_SWCHANNELID180_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID180_SWCHANNELID180_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID180_SWCHANNELID180_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID180_SWCHANNELID180_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID180_RESETVAL                     (0x00000000U)

/* SWCHANNELID180TS */

#define CSL_SMSETSW_SWCHANNELID180TS_SWCHANNELID180TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID180TS_SWCHANNELID180TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID180TS_SWCHANNELID180TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID180TS_SWCHANNELID180TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID180TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID181 */

#define CSL_SMSETSW_SWCHANNELID181_SWCHANNELID181_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID181_SWCHANNELID181_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID181_SWCHANNELID181_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID181_SWCHANNELID181_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID181_RESETVAL                     (0x00000000U)

/* SWCHANNELID181TS */

#define CSL_SMSETSW_SWCHANNELID181TS_SWCHANNELID181TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID181TS_SWCHANNELID181TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID181TS_SWCHANNELID181TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID181TS_SWCHANNELID181TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID181TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID182 */

#define CSL_SMSETSW_SWCHANNELID182_SWCHANNELID182_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID182_SWCHANNELID182_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID182_SWCHANNELID182_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID182_SWCHANNELID182_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID182_RESETVAL                     (0x00000000U)

/* SWCHANNELID182TS */

#define CSL_SMSETSW_SWCHANNELID182TS_SWCHANNELID182TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID182TS_SWCHANNELID182TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID182TS_SWCHANNELID182TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID182TS_SWCHANNELID182TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID182TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID183 */

#define CSL_SMSETSW_SWCHANNELID183_SWCHANNELID183_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID183_SWCHANNELID183_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID183_SWCHANNELID183_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID183_SWCHANNELID183_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID183_RESETVAL                     (0x00000000U)

/* SWCHANNELID183TS */

#define CSL_SMSETSW_SWCHANNELID183TS_SWCHANNELID183TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID183TS_SWCHANNELID183TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID183TS_SWCHANNELID183TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID183TS_SWCHANNELID183TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID183TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID184 */

#define CSL_SMSETSW_SWCHANNELID184_SWCHANNELID184_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID184_SWCHANNELID184_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID184_SWCHANNELID184_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID184_SWCHANNELID184_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID184_RESETVAL                     (0x00000000U)

/* SWCHANNELID184TS */

#define CSL_SMSETSW_SWCHANNELID184TS_SWCHANNELID184TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID184TS_SWCHANNELID184TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID184TS_SWCHANNELID184TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID184TS_SWCHANNELID184TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID184TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID185 */

#define CSL_SMSETSW_SWCHANNELID185_SWCHANNELID185_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID185_SWCHANNELID185_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID185_SWCHANNELID185_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID185_SWCHANNELID185_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID185_RESETVAL                     (0x00000000U)

/* SWCHANNELID185TS */

#define CSL_SMSETSW_SWCHANNELID185TS_SWCHANNELID185TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID185TS_SWCHANNELID185TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID185TS_SWCHANNELID185TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID185TS_SWCHANNELID185TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID185TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID186 */

#define CSL_SMSETSW_SWCHANNELID186_SWCHANNELID186_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID186_SWCHANNELID186_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID186_SWCHANNELID186_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID186_SWCHANNELID186_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID186_RESETVAL                     (0x00000000U)

/* SWCHANNELID186TS */

#define CSL_SMSETSW_SWCHANNELID186TS_SWCHANNELID186TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID186TS_SWCHANNELID186TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID186TS_SWCHANNELID186TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID186TS_SWCHANNELID186TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID186TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID187 */

#define CSL_SMSETSW_SWCHANNELID187_SWCHANNELID187_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID187_SWCHANNELID187_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID187_SWCHANNELID187_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID187_SWCHANNELID187_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID187_RESETVAL                     (0x00000000U)

/* SWCHANNELID187TS */

#define CSL_SMSETSW_SWCHANNELID187TS_SWCHANNELID187TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID187TS_SWCHANNELID187TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID187TS_SWCHANNELID187TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID187TS_SWCHANNELID187TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID187TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID188 */

#define CSL_SMSETSW_SWCHANNELID188_SWCHANNELID188_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID188_SWCHANNELID188_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID188_SWCHANNELID188_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID188_SWCHANNELID188_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID188_RESETVAL                     (0x00000000U)

/* SWCHANNELID188TS */

#define CSL_SMSETSW_SWCHANNELID188TS_SWCHANNELID188TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID188TS_SWCHANNELID188TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID188TS_SWCHANNELID188TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID188TS_SWCHANNELID188TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID188TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID189 */

#define CSL_SMSETSW_SWCHANNELID189_SWCHANNELID189_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID189_SWCHANNELID189_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID189_SWCHANNELID189_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID189_SWCHANNELID189_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID189_RESETVAL                     (0x00000000U)

/* SWCHANNELID189TS */

#define CSL_SMSETSW_SWCHANNELID189TS_SWCHANNELID189TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID189TS_SWCHANNELID189TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID189TS_SWCHANNELID189TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID189TS_SWCHANNELID189TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID189TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID190 */

#define CSL_SMSETSW_SWCHANNELID190_SWCHANNELID190_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID190_SWCHANNELID190_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID190_SWCHANNELID190_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID190_SWCHANNELID190_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID190_RESETVAL                     (0x00000000U)

/* SWCHANNELID190TS */

#define CSL_SMSETSW_SWCHANNELID190TS_SWCHANNELID190TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID190TS_SWCHANNELID190TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID190TS_SWCHANNELID190TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID190TS_SWCHANNELID190TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID190TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID191 */

#define CSL_SMSETSW_SWCHANNELID191_SWCHANNELID191_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID191_SWCHANNELID191_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID191_SWCHANNELID191_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID191_SWCHANNELID191_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID191_RESETVAL                     (0x00000000U)

/* SWCHANNELID191TS */

#define CSL_SMSETSW_SWCHANNELID191TS_SWCHANNELID191TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID191TS_SWCHANNELID191TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID191TS_SWCHANNELID191TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID191TS_SWCHANNELID191TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID191TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID192 */

#define CSL_SMSETSW_SWCHANNELID192_SWCHANNELID192_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID192_SWCHANNELID192_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID192_SWCHANNELID192_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID192_SWCHANNELID192_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID192_RESETVAL                     (0x00000000U)

/* SWCHANNELID192TS */

#define CSL_SMSETSW_SWCHANNELID192TS_SWCHANNELID192TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID192TS_SWCHANNELID192TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID192TS_SWCHANNELID192TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID192TS_SWCHANNELID192TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID192TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID193 */

#define CSL_SMSETSW_SWCHANNELID193_SWCHANNELID193_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID193_SWCHANNELID193_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID193_SWCHANNELID193_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID193_SWCHANNELID193_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID193_RESETVAL                     (0x00000000U)

/* SWCHANNELID193TS */

#define CSL_SMSETSW_SWCHANNELID193TS_SWCHANNELID193TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID193TS_SWCHANNELID193TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID193TS_SWCHANNELID193TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID193TS_SWCHANNELID193TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID193TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID194 */

#define CSL_SMSETSW_SWCHANNELID194_SWCHANNELID194_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID194_SWCHANNELID194_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID194_SWCHANNELID194_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID194_SWCHANNELID194_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID194_RESETVAL                     (0x00000000U)

/* SWCHANNELID194TS */

#define CSL_SMSETSW_SWCHANNELID194TS_SWCHANNELID194TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID194TS_SWCHANNELID194TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID194TS_SWCHANNELID194TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID194TS_SWCHANNELID194TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID194TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID195 */

#define CSL_SMSETSW_SWCHANNELID195_SWCHANNELID195_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID195_SWCHANNELID195_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID195_SWCHANNELID195_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID195_SWCHANNELID195_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID195_RESETVAL                     (0x00000000U)

/* SWCHANNELID195TS */

#define CSL_SMSETSW_SWCHANNELID195TS_SWCHANNELID195TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID195TS_SWCHANNELID195TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID195TS_SWCHANNELID195TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID195TS_SWCHANNELID195TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID195TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID196 */

#define CSL_SMSETSW_SWCHANNELID196_SWCHANNELID196_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID196_SWCHANNELID196_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID196_SWCHANNELID196_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID196_SWCHANNELID196_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID196_RESETVAL                     (0x00000000U)

/* SWCHANNELID196TS */

#define CSL_SMSETSW_SWCHANNELID196TS_SWCHANNELID196TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID196TS_SWCHANNELID196TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID196TS_SWCHANNELID196TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID196TS_SWCHANNELID196TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID196TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID197 */

#define CSL_SMSETSW_SWCHANNELID197_SWCHANNELID197_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID197_SWCHANNELID197_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID197_SWCHANNELID197_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID197_SWCHANNELID197_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID197_RESETVAL                     (0x00000000U)

/* SWCHANNELID197TS */

#define CSL_SMSETSW_SWCHANNELID197TS_SWCHANNELID197TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID197TS_SWCHANNELID197TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID197TS_SWCHANNELID197TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID197TS_SWCHANNELID197TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID197TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID198 */

#define CSL_SMSETSW_SWCHANNELID198_SWCHANNELID198_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID198_SWCHANNELID198_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID198_SWCHANNELID198_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID198_SWCHANNELID198_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID198_RESETVAL                     (0x00000000U)

/* SWCHANNELID198TS */

#define CSL_SMSETSW_SWCHANNELID198TS_SWCHANNELID198TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID198TS_SWCHANNELID198TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID198TS_SWCHANNELID198TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID198TS_SWCHANNELID198TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID198TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID199 */

#define CSL_SMSETSW_SWCHANNELID199_SWCHANNELID199_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID199_SWCHANNELID199_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID199_SWCHANNELID199_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID199_SWCHANNELID199_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID199_RESETVAL                     (0x00000000U)

/* SWCHANNELID199TS */

#define CSL_SMSETSW_SWCHANNELID199TS_SWCHANNELID199TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID199TS_SWCHANNELID199TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID199TS_SWCHANNELID199TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID199TS_SWCHANNELID199TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID199TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID200 */

#define CSL_SMSETSW_SWCHANNELID200_SWCHANNELID200_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID200_SWCHANNELID200_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID200_SWCHANNELID200_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID200_SWCHANNELID200_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID200_RESETVAL                     (0x00000000U)

/* SWCHANNELID200TS */

#define CSL_SMSETSW_SWCHANNELID200TS_SWCHANNELID200TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID200TS_SWCHANNELID200TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID200TS_SWCHANNELID200TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID200TS_SWCHANNELID200TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID200TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID201 */

#define CSL_SMSETSW_SWCHANNELID201_SWCHANNELID201_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID201_SWCHANNELID201_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID201_SWCHANNELID201_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID201_SWCHANNELID201_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID201_RESETVAL                     (0x00000000U)

/* SWCHANNELID201TS */

#define CSL_SMSETSW_SWCHANNELID201TS_SWCHANNELID201TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID201TS_SWCHANNELID201TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID201TS_SWCHANNELID201TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID201TS_SWCHANNELID201TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID201TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID202 */

#define CSL_SMSETSW_SWCHANNELID202_SWCHANNELID202_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID202_SWCHANNELID202_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID202_SWCHANNELID202_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID202_SWCHANNELID202_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID202_RESETVAL                     (0x00000000U)

/* SWCHANNELID202TS */

#define CSL_SMSETSW_SWCHANNELID202TS_SWCHANNELID202TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID202TS_SWCHANNELID202TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID202TS_SWCHANNELID202TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID202TS_SWCHANNELID202TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID202TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID203 */

#define CSL_SMSETSW_SWCHANNELID203_SWCHANNELID203_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID203_SWCHANNELID203_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID203_SWCHANNELID203_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID203_SWCHANNELID203_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID203_RESETVAL                     (0x00000000U)

/* SWCHANNELID203TS */

#define CSL_SMSETSW_SWCHANNELID203TS_SWCHANNELID203TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID203TS_SWCHANNELID203TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID203TS_SWCHANNELID203TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID203TS_SWCHANNELID203TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID203TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID204 */

#define CSL_SMSETSW_SWCHANNELID204_SWCHANNELID204_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID204_SWCHANNELID204_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID204_SWCHANNELID204_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID204_SWCHANNELID204_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID204_RESETVAL                     (0x00000000U)

/* SWCHANNELID204TS */

#define CSL_SMSETSW_SWCHANNELID204TS_SWCHANNELID204TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID204TS_SWCHANNELID204TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID204TS_SWCHANNELID204TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID204TS_SWCHANNELID204TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID204TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID205 */

#define CSL_SMSETSW_SWCHANNELID205_SWCHANNELID205_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID205_SWCHANNELID205_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID205_SWCHANNELID205_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID205_SWCHANNELID205_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID205_RESETVAL                     (0x00000000U)

/* SWCHANNELID205TS */

#define CSL_SMSETSW_SWCHANNELID205TS_SWCHANNELID205TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID205TS_SWCHANNELID205TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID205TS_SWCHANNELID205TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID205TS_SWCHANNELID205TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID205TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID206 */

#define CSL_SMSETSW_SWCHANNELID206_SWCHANNELID206_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID206_SWCHANNELID206_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID206_SWCHANNELID206_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID206_SWCHANNELID206_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID206_RESETVAL                     (0x00000000U)

/* SWCHANNELID206TS */

#define CSL_SMSETSW_SWCHANNELID206TS_SWCHANNELID206TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID206TS_SWCHANNELID206TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID206TS_SWCHANNELID206TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID206TS_SWCHANNELID206TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID206TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID207 */

#define CSL_SMSETSW_SWCHANNELID207_SWCHANNELID207_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID207_SWCHANNELID207_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID207_SWCHANNELID207_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID207_SWCHANNELID207_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID207_RESETVAL                     (0x00000000U)

/* SWCHANNELID207TS */

#define CSL_SMSETSW_SWCHANNELID207TS_SWCHANNELID207TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID207TS_SWCHANNELID207TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID207TS_SWCHANNELID207TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID207TS_SWCHANNELID207TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID207TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID208 */

#define CSL_SMSETSW_SWCHANNELID208_SWCHANNELID208_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID208_SWCHANNELID208_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID208_SWCHANNELID208_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID208_SWCHANNELID208_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID208_RESETVAL                     (0x00000000U)

/* SWCHANNELID208TS */

#define CSL_SMSETSW_SWCHANNELID208TS_SWCHANNELID208TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID208TS_SWCHANNELID208TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID208TS_SWCHANNELID208TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID208TS_SWCHANNELID208TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID208TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID209 */

#define CSL_SMSETSW_SWCHANNELID209_SWCHANNELID209_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID209_SWCHANNELID209_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID209_SWCHANNELID209_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID209_SWCHANNELID209_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID209_RESETVAL                     (0x00000000U)

/* SWCHANNELID209TS */

#define CSL_SMSETSW_SWCHANNELID209TS_SWCHANNELID209TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID209TS_SWCHANNELID209TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID209TS_SWCHANNELID209TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID209TS_SWCHANNELID209TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID209TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID210 */

#define CSL_SMSETSW_SWCHANNELID210_SWCHANNELID210_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID210_SWCHANNELID210_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID210_SWCHANNELID210_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID210_SWCHANNELID210_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID210_RESETVAL                     (0x00000000U)

/* SWCHANNELID210TS */

#define CSL_SMSETSW_SWCHANNELID210TS_SWCHANNELID210TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID210TS_SWCHANNELID210TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID210TS_SWCHANNELID210TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID210TS_SWCHANNELID210TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID210TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID211 */

#define CSL_SMSETSW_SWCHANNELID211_SWCHANNELID211_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID211_SWCHANNELID211_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID211_SWCHANNELID211_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID211_SWCHANNELID211_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID211_RESETVAL                     (0x00000000U)

/* SWCHANNELID211TS */

#define CSL_SMSETSW_SWCHANNELID211TS_SWCHANNELID211TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID211TS_SWCHANNELID211TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID211TS_SWCHANNELID211TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID211TS_SWCHANNELID211TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID211TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID212 */

#define CSL_SMSETSW_SWCHANNELID212_SWCHANNELID212_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID212_SWCHANNELID212_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID212_SWCHANNELID212_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID212_SWCHANNELID212_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID212_RESETVAL                     (0x00000000U)

/* SWCHANNELID212TS */

#define CSL_SMSETSW_SWCHANNELID212TS_SWCHANNELID212TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID212TS_SWCHANNELID212TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID212TS_SWCHANNELID212TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID212TS_SWCHANNELID212TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID212TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID213 */

#define CSL_SMSETSW_SWCHANNELID213_SWCHANNELID213_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID213_SWCHANNELID213_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID213_SWCHANNELID213_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID213_SWCHANNELID213_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID213_RESETVAL                     (0x00000000U)

/* SWCHANNELID213TS */

#define CSL_SMSETSW_SWCHANNELID213TS_SWCHANNELID213TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID213TS_SWCHANNELID213TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID213TS_SWCHANNELID213TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID213TS_SWCHANNELID213TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID213TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID214 */

#define CSL_SMSETSW_SWCHANNELID214_SWCHANNELID214_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID214_SWCHANNELID214_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID214_SWCHANNELID214_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID214_SWCHANNELID214_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID214_RESETVAL                     (0x00000000U)

/* SWCHANNELID214TS */

#define CSL_SMSETSW_SWCHANNELID214TS_SWCHANNELID214TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID214TS_SWCHANNELID214TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID214TS_SWCHANNELID214TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID214TS_SWCHANNELID214TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID214TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID215 */

#define CSL_SMSETSW_SWCHANNELID215_SWCHANNELID215_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID215_SWCHANNELID215_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID215_SWCHANNELID215_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID215_SWCHANNELID215_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID215_RESETVAL                     (0x00000000U)

/* SWCHANNELID215TS */

#define CSL_SMSETSW_SWCHANNELID215TS_SWCHANNELID215TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID215TS_SWCHANNELID215TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID215TS_SWCHANNELID215TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID215TS_SWCHANNELID215TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID215TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID216 */

#define CSL_SMSETSW_SWCHANNELID216_SWCHANNELID216_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID216_SWCHANNELID216_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID216_SWCHANNELID216_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID216_SWCHANNELID216_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID216_RESETVAL                     (0x00000000U)

/* SWCHANNELID216TS */

#define CSL_SMSETSW_SWCHANNELID216TS_SWCHANNELID216TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID216TS_SWCHANNELID216TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID216TS_SWCHANNELID216TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID216TS_SWCHANNELID216TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID216TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID217 */

#define CSL_SMSETSW_SWCHANNELID217_SWCHANNELID217_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID217_SWCHANNELID217_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID217_SWCHANNELID217_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID217_SWCHANNELID217_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID217_RESETVAL                     (0x00000000U)

/* SWCHANNELID217TS */

#define CSL_SMSETSW_SWCHANNELID217TS_SWCHANNELID217TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID217TS_SWCHANNELID217TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID217TS_SWCHANNELID217TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID217TS_SWCHANNELID217TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID217TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID218 */

#define CSL_SMSETSW_SWCHANNELID218_SWCHANNELID218_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID218_SWCHANNELID218_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID218_SWCHANNELID218_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID218_SWCHANNELID218_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID218_RESETVAL                     (0x00000000U)

/* SWCHANNELID218TS */

#define CSL_SMSETSW_SWCHANNELID218TS_SWCHANNELID218TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID218TS_SWCHANNELID218TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID218TS_SWCHANNELID218TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID218TS_SWCHANNELID218TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID218TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID219 */

#define CSL_SMSETSW_SWCHANNELID219_SWCHANNELID219_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID219_SWCHANNELID219_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID219_SWCHANNELID219_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID219_SWCHANNELID219_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID219_RESETVAL                     (0x00000000U)

/* SWCHANNELID219TS */

#define CSL_SMSETSW_SWCHANNELID219TS_SWCHANNELID219TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID219TS_SWCHANNELID219TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID219TS_SWCHANNELID219TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID219TS_SWCHANNELID219TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID219TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID220 */

#define CSL_SMSETSW_SWCHANNELID220_SWCHANNELID220_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID220_SWCHANNELID220_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID220_SWCHANNELID220_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID220_SWCHANNELID220_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID220_RESETVAL                     (0x00000000U)

/* SWCHANNELID220TS */

#define CSL_SMSETSW_SWCHANNELID220TS_SWCHANNELID220TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID220TS_SWCHANNELID220TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID220TS_SWCHANNELID220TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID220TS_SWCHANNELID220TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID220TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID221 */

#define CSL_SMSETSW_SWCHANNELID221_SWCHANNELID221_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID221_SWCHANNELID221_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID221_SWCHANNELID221_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID221_SWCHANNELID221_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID221_RESETVAL                     (0x00000000U)

/* SWCHANNELID221TS */

#define CSL_SMSETSW_SWCHANNELID221TS_SWCHANNELID221TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID221TS_SWCHANNELID221TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID221TS_SWCHANNELID221TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID221TS_SWCHANNELID221TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID221TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID222 */

#define CSL_SMSETSW_SWCHANNELID222_SWCHANNELID222_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID222_SWCHANNELID222_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID222_SWCHANNELID222_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID222_SWCHANNELID222_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID222_RESETVAL                     (0x00000000U)

/* SWCHANNELID222TS */

#define CSL_SMSETSW_SWCHANNELID222TS_SWCHANNELID222TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID222TS_SWCHANNELID222TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID222TS_SWCHANNELID222TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID222TS_SWCHANNELID222TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID222TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID223 */

#define CSL_SMSETSW_SWCHANNELID223_SWCHANNELID223_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID223_SWCHANNELID223_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID223_SWCHANNELID223_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID223_SWCHANNELID223_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID223_RESETVAL                     (0x00000000U)

/* SWCHANNELID223TS */

#define CSL_SMSETSW_SWCHANNELID223TS_SWCHANNELID223TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID223TS_SWCHANNELID223TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID223TS_SWCHANNELID223TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID223TS_SWCHANNELID223TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID223TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID224 */

#define CSL_SMSETSW_SWCHANNELID224_SWCHANNELID224_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID224_SWCHANNELID224_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID224_SWCHANNELID224_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID224_SWCHANNELID224_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID224_RESETVAL                     (0x00000000U)

/* SWCHANNELID224TS */

#define CSL_SMSETSW_SWCHANNELID224TS_SWCHANNELID224TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID224TS_SWCHANNELID224TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID224TS_SWCHANNELID224TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID224TS_SWCHANNELID224TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID224TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID225 */

#define CSL_SMSETSW_SWCHANNELID225_SWCHANNELID225_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID225_SWCHANNELID225_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID225_SWCHANNELID225_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID225_SWCHANNELID225_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID225_RESETVAL                     (0x00000000U)

/* SWCHANNELID225TS */

#define CSL_SMSETSW_SWCHANNELID225TS_SWCHANNELID225TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID225TS_SWCHANNELID225TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID225TS_SWCHANNELID225TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID225TS_SWCHANNELID225TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID225TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID226 */

#define CSL_SMSETSW_SWCHANNELID226_SWCHANNELID226_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID226_SWCHANNELID226_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID226_SWCHANNELID226_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID226_SWCHANNELID226_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID226_RESETVAL                     (0x00000000U)

/* SWCHANNELID226TS */

#define CSL_SMSETSW_SWCHANNELID226TS_SWCHANNELID226TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID226TS_SWCHANNELID226TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID226TS_SWCHANNELID226TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID226TS_SWCHANNELID226TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID226TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID227 */

#define CSL_SMSETSW_SWCHANNELID227_SWCHANNELID227_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID227_SWCHANNELID227_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID227_SWCHANNELID227_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID227_SWCHANNELID227_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID227_RESETVAL                     (0x00000000U)

/* SWCHANNELID227TS */

#define CSL_SMSETSW_SWCHANNELID227TS_SWCHANNELID227TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID227TS_SWCHANNELID227TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID227TS_SWCHANNELID227TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID227TS_SWCHANNELID227TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID227TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID228 */

#define CSL_SMSETSW_SWCHANNELID228_SWCHANNELID228_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID228_SWCHANNELID228_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID228_SWCHANNELID228_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID228_SWCHANNELID228_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID228_RESETVAL                     (0x00000000U)

/* SWCHANNELID228TS */

#define CSL_SMSETSW_SWCHANNELID228TS_SWCHANNELID228TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID228TS_SWCHANNELID228TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID228TS_SWCHANNELID228TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID228TS_SWCHANNELID228TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID228TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID229 */

#define CSL_SMSETSW_SWCHANNELID229_SWCHANNELID229_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID229_SWCHANNELID229_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID229_SWCHANNELID229_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID229_SWCHANNELID229_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID229_RESETVAL                     (0x00000000U)

/* SWCHANNELID229TS */

#define CSL_SMSETSW_SWCHANNELID229TS_SWCHANNELID229TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID229TS_SWCHANNELID229TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID229TS_SWCHANNELID229TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID229TS_SWCHANNELID229TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID229TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID230 */

#define CSL_SMSETSW_SWCHANNELID230_SWCHANNELID230_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID230_SWCHANNELID230_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID230_SWCHANNELID230_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID230_SWCHANNELID230_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID230_RESETVAL                     (0x00000000U)

/* SWCHANNELID230TS */

#define CSL_SMSETSW_SWCHANNELID230TS_SWCHANNELID230TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID230TS_SWCHANNELID230TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID230TS_SWCHANNELID230TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID230TS_SWCHANNELID230TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID230TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID231 */

#define CSL_SMSETSW_SWCHANNELID231_SWCHANNELID231_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID231_SWCHANNELID231_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID231_SWCHANNELID231_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID231_SWCHANNELID231_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID231_RESETVAL                     (0x00000000U)

/* SWCHANNELID231TS */

#define CSL_SMSETSW_SWCHANNELID231TS_SWCHANNELID231TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID231TS_SWCHANNELID231TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID231TS_SWCHANNELID231TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID231TS_SWCHANNELID231TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID231TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID232 */

#define CSL_SMSETSW_SWCHANNELID232_SWCHANNELID232_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID232_SWCHANNELID232_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID232_SWCHANNELID232_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID232_SWCHANNELID232_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID232_RESETVAL                     (0x00000000U)

/* SWCHANNELID232TS */

#define CSL_SMSETSW_SWCHANNELID232TS_SWCHANNELID232TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID232TS_SWCHANNELID232TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID232TS_SWCHANNELID232TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID232TS_SWCHANNELID232TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID232TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID233 */

#define CSL_SMSETSW_SWCHANNELID233_SWCHANNELID233_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID233_SWCHANNELID233_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID233_SWCHANNELID233_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID233_SWCHANNELID233_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID233_RESETVAL                     (0x00000000U)

/* SWCHANNELID233TS */

#define CSL_SMSETSW_SWCHANNELID233TS_SWCHANNELID233TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID233TS_SWCHANNELID233TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID233TS_SWCHANNELID233TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID233TS_SWCHANNELID233TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID233TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID234 */

#define CSL_SMSETSW_SWCHANNELID234_SWCHANNELID234_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID234_SWCHANNELID234_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID234_SWCHANNELID234_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID234_SWCHANNELID234_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID234_RESETVAL                     (0x00000000U)

/* SWCHANNELID234TS */

#define CSL_SMSETSW_SWCHANNELID234TS_SWCHANNELID234TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID234TS_SWCHANNELID234TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID234TS_SWCHANNELID234TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID234TS_SWCHANNELID234TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID234TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID235 */

#define CSL_SMSETSW_SWCHANNELID235_SWCHANNELID235_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID235_SWCHANNELID235_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID235_SWCHANNELID235_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID235_SWCHANNELID235_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID235_RESETVAL                     (0x00000000U)

/* SWCHANNELID235TS */

#define CSL_SMSETSW_SWCHANNELID235TS_SWCHANNELID235TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID235TS_SWCHANNELID235TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID235TS_SWCHANNELID235TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID235TS_SWCHANNELID235TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID235TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID236 */

#define CSL_SMSETSW_SWCHANNELID236_SWCHANNELID236_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID236_SWCHANNELID236_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID236_SWCHANNELID236_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID236_SWCHANNELID236_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID236_RESETVAL                     (0x00000000U)

/* SWCHANNELID236TS */

#define CSL_SMSETSW_SWCHANNELID236TS_SWCHANNELID236TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID236TS_SWCHANNELID236TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID236TS_SWCHANNELID236TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID236TS_SWCHANNELID236TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID236TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID237 */

#define CSL_SMSETSW_SWCHANNELID237_SWCHANNELID237_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID237_SWCHANNELID237_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID237_SWCHANNELID237_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID237_SWCHANNELID237_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID237_RESETVAL                     (0x00000000U)

/* SWCHANNELID237TS */

#define CSL_SMSETSW_SWCHANNELID237TS_SWCHANNELID237TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID237TS_SWCHANNELID237TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID237TS_SWCHANNELID237TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID237TS_SWCHANNELID237TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID237TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID238 */

#define CSL_SMSETSW_SWCHANNELID238_SWCHANNELID238_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID238_SWCHANNELID238_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID238_SWCHANNELID238_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID238_SWCHANNELID238_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID238_RESETVAL                     (0x00000000U)

/* SWCHANNELID238TS */

#define CSL_SMSETSW_SWCHANNELID238TS_SWCHANNELID238TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID238TS_SWCHANNELID238TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID238TS_SWCHANNELID238TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID238TS_SWCHANNELID238TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID238TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID239 */

#define CSL_SMSETSW_SWCHANNELID239_SWCHANNELID239_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID239_SWCHANNELID239_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID239_SWCHANNELID239_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID239_SWCHANNELID239_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID239_RESETVAL                     (0x00000000U)

/* SWCHANNELID239TS */

#define CSL_SMSETSW_SWCHANNELID239TS_SWCHANNELID239TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID239TS_SWCHANNELID239TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID239TS_SWCHANNELID239TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID239TS_SWCHANNELID239TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID239TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID240 */

#define CSL_SMSETSW_SWCHANNELID240_SWCHANNELID240_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID240_SWCHANNELID240_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID240_SWCHANNELID240_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID240_SWCHANNELID240_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID240_RESETVAL                     (0x00000000U)

/* SWCHANNELID240TS */

#define CSL_SMSETSW_SWCHANNELID240TS_SWCHANNELID240TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID240TS_SWCHANNELID240TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID240TS_SWCHANNELID240TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID240TS_SWCHANNELID240TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID240TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID241 */

#define CSL_SMSETSW_SWCHANNELID241_SWCHANNELID241_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID241_SWCHANNELID241_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID241_SWCHANNELID241_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID241_SWCHANNELID241_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID241_RESETVAL                     (0x00000000U)

/* SWCHANNELID241TS */

#define CSL_SMSETSW_SWCHANNELID241TS_SWCHANNELID241TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID241TS_SWCHANNELID241TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID241TS_SWCHANNELID241TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID241TS_SWCHANNELID241TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID241TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID242 */

#define CSL_SMSETSW_SWCHANNELID242_SWCHANNELID242_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID242_SWCHANNELID242_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID242_SWCHANNELID242_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID242_SWCHANNELID242_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID242_RESETVAL                     (0x00000000U)

/* SWCHANNELID242TS */

#define CSL_SMSETSW_SWCHANNELID242TS_SWCHANNELID242TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID242TS_SWCHANNELID242TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID242TS_SWCHANNELID242TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID242TS_SWCHANNELID242TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID242TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID243 */

#define CSL_SMSETSW_SWCHANNELID243_SWCHANNELID243_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID243_SWCHANNELID243_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID243_SWCHANNELID243_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID243_SWCHANNELID243_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID243_RESETVAL                     (0x00000000U)

/* SWCHANNELID243TS */

#define CSL_SMSETSW_SWCHANNELID243TS_SWCHANNELID243TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID243TS_SWCHANNELID243TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID243TS_SWCHANNELID243TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID243TS_SWCHANNELID243TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID243TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID244 */

#define CSL_SMSETSW_SWCHANNELID244_SWCHANNELID244_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID244_SWCHANNELID244_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID244_SWCHANNELID244_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID244_SWCHANNELID244_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID244_RESETVAL                     (0x00000000U)

/* SWCHANNELID244TS */

#define CSL_SMSETSW_SWCHANNELID244TS_SWCHANNELID244TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID244TS_SWCHANNELID244TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID244TS_SWCHANNELID244TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID244TS_SWCHANNELID244TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID244TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID245 */

#define CSL_SMSETSW_SWCHANNELID245_SWCHANNELID245_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID245_SWCHANNELID245_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID245_SWCHANNELID245_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID245_SWCHANNELID245_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID245_RESETVAL                     (0x00000000U)

/* SWCHANNELID245TS */

#define CSL_SMSETSW_SWCHANNELID245TS_SWCHANNELID245TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID245TS_SWCHANNELID245TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID245TS_SWCHANNELID245TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID245TS_SWCHANNELID245TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID245TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID246 */

#define CSL_SMSETSW_SWCHANNELID246_SWCHANNELID246_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID246_SWCHANNELID246_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID246_SWCHANNELID246_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID246_SWCHANNELID246_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID246_RESETVAL                     (0x00000000U)

/* SWCHANNELID246TS */

#define CSL_SMSETSW_SWCHANNELID246TS_SWCHANNELID246TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID246TS_SWCHANNELID246TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID246TS_SWCHANNELID246TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID246TS_SWCHANNELID246TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID246TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID247 */

#define CSL_SMSETSW_SWCHANNELID247_SWCHANNELID247_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID247_SWCHANNELID247_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID247_SWCHANNELID247_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID247_SWCHANNELID247_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID247_RESETVAL                     (0x00000000U)

/* SWCHANNELID247TS */

#define CSL_SMSETSW_SWCHANNELID247TS_SWCHANNELID247TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID247TS_SWCHANNELID247TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID247TS_SWCHANNELID247TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID247TS_SWCHANNELID247TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID247TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID248 */

#define CSL_SMSETSW_SWCHANNELID248_SWCHANNELID248_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID248_SWCHANNELID248_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID248_SWCHANNELID248_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID248_SWCHANNELID248_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID248_RESETVAL                     (0x00000000U)

/* SWCHANNELID248TS */

#define CSL_SMSETSW_SWCHANNELID248TS_SWCHANNELID248TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID248TS_SWCHANNELID248TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID248TS_SWCHANNELID248TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID248TS_SWCHANNELID248TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID248TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID249 */

#define CSL_SMSETSW_SWCHANNELID249_SWCHANNELID249_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID249_SWCHANNELID249_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID249_SWCHANNELID249_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID249_SWCHANNELID249_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID249_RESETVAL                     (0x00000000U)

/* SWCHANNELID249TS */

#define CSL_SMSETSW_SWCHANNELID249TS_SWCHANNELID249TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID249TS_SWCHANNELID249TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID249TS_SWCHANNELID249TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID249TS_SWCHANNELID249TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID249TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID250 */

#define CSL_SMSETSW_SWCHANNELID250_SWCHANNELID250_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID250_SWCHANNELID250_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID250_SWCHANNELID250_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID250_SWCHANNELID250_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID250_RESETVAL                     (0x00000000U)

/* SWCHANNELID250TS */

#define CSL_SMSETSW_SWCHANNELID250TS_SWCHANNELID250TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID250TS_SWCHANNELID250TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID250TS_SWCHANNELID250TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID250TS_SWCHANNELID250TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID250TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID251 */

#define CSL_SMSETSW_SWCHANNELID251_SWCHANNELID251_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID251_SWCHANNELID251_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID251_SWCHANNELID251_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID251_SWCHANNELID251_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID251_RESETVAL                     (0x00000000U)

/* SWCHANNELID251TS */

#define CSL_SMSETSW_SWCHANNELID251TS_SWCHANNELID251TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID251TS_SWCHANNELID251TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID251TS_SWCHANNELID251TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID251TS_SWCHANNELID251TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID251TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID252 */

#define CSL_SMSETSW_SWCHANNELID252_SWCHANNELID252_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID252_SWCHANNELID252_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID252_SWCHANNELID252_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID252_SWCHANNELID252_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID252_RESETVAL                     (0x00000000U)

/* SWCHANNELID252TS */

#define CSL_SMSETSW_SWCHANNELID252TS_SWCHANNELID252TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID252TS_SWCHANNELID252TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID252TS_SWCHANNELID252TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID252TS_SWCHANNELID252TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID252TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID253 */

#define CSL_SMSETSW_SWCHANNELID253_SWCHANNELID253_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID253_SWCHANNELID253_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID253_SWCHANNELID253_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID253_SWCHANNELID253_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID253_RESETVAL                     (0x00000000U)

/* SWCHANNELID253TS */

#define CSL_SMSETSW_SWCHANNELID253TS_SWCHANNELID253TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID253TS_SWCHANNELID253TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID253TS_SWCHANNELID253TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID253TS_SWCHANNELID253TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID253TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID254 */

#define CSL_SMSETSW_SWCHANNELID254_SWCHANNELID254_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID254_SWCHANNELID254_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID254_SWCHANNELID254_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID254_SWCHANNELID254_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID254_RESETVAL                     (0x00000000U)

/* SWCHANNELID254TS */

#define CSL_SMSETSW_SWCHANNELID254TS_SWCHANNELID254TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID254TS_SWCHANNELID254TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID254TS_SWCHANNELID254TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID254TS_SWCHANNELID254TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID254TS_RESETVAL                   (0x00000000U)

/* SWCHANNELID255 */

#define CSL_SMSETSW_SWCHANNELID255_SWCHANNELID255_MASK          (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID255_SWCHANNELID255_SHIFT         (0U)
#define CSL_SMSETSW_SWCHANNELID255_SWCHANNELID255_RESETVAL      (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID255_SWCHANNELID255_MAX           (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID255_RESETVAL                     (0x00000000U)

/* SWCHANNELID255TS */

#define CSL_SMSETSW_SWCHANNELID255TS_SWCHANNELID255TS_MASK      (0xFFFFFFFFU)
#define CSL_SMSETSW_SWCHANNELID255TS_SWCHANNELID255TS_SHIFT     (0U)
#define CSL_SMSETSW_SWCHANNELID255TS_SWCHANNELID255TS_RESETVAL  (0x00000000U)
#define CSL_SMSETSW_SWCHANNELID255TS_SWCHANNELID255TS_MAX       (0xffffffffU)

#define CSL_SMSETSW_SWCHANNELID255TS_RESETVAL                   (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif

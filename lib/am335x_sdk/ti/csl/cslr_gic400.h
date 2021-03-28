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
#ifndef CSLR_GIC400_H_
#define CSLR_GIC400_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for Distributor
**************************************************************************/
typedef struct {
    volatile Uint32 GICD_CTLR;
    volatile Uint32 GICD_TYPER;
    volatile Uint32 GICD_IIDR;
    volatile Uint8  RSVD0[116];
    volatile Uint32 GICD_IGROUPR0;
    volatile Uint32 GICD_IGROUPR1;
    volatile Uint32 GICD_IGROUPR2;
    volatile Uint32 GICD_IGROUPR3;
    volatile Uint32 GICD_IGROUPR4;
    volatile Uint32 GICD_IGROUPR5;
    volatile Uint32 GICD_IGROUPR6;
    volatile Uint32 GICD_IGROUPR7;
    volatile Uint32 GICD_IGROUPR8;
    volatile Uint32 GICD_IGROUPR9;
    volatile Uint32 GICD_IGROUPR10;
    volatile Uint32 GICD_IGROUPR11;
    volatile Uint32 GICD_IGROUPR12;
    volatile Uint32 GICD_IGROUPR13;
    volatile Uint32 GICD_IGROUPR14;
    volatile Uint32 GICD_IGROUPR15;
    volatile Uint8  RSVD1[64];
    volatile Uint32 GICD_ISENABLER0;
    volatile Uint32 GICD_ISENABLER1;
    volatile Uint32 GICD_ISENABLER2;
    volatile Uint32 GICD_ISENABLER3;
    volatile Uint32 GICD_ISENABLER4;
    volatile Uint32 GICD_ISENABLER5;
    volatile Uint32 GICD_ISENABLER6;
    volatile Uint32 GICD_ISENABLER7;
    volatile Uint32 GICD_ISENABLER8;
    volatile Uint32 GICD_ISENABLER9;
    volatile Uint32 GICD_ISENABLER10;
    volatile Uint32 GICD_ISENABLER11;
    volatile Uint32 GICD_ISENABLER12;
    volatile Uint32 GICD_ISENABLER13;
    volatile Uint32 GICD_ISENABLER14;
    volatile Uint32 GICD_ISENABLER15;
    volatile Uint8  RSVD2[64];
    volatile Uint32 GICD_ICENABLER0;
    volatile Uint32 GICD_ICENABLER1;
    volatile Uint32 GICD_ICENABLER2;
    volatile Uint32 GICD_ICENABLER3;
    volatile Uint32 GICD_ICENABLER4;
    volatile Uint32 GICD_ICENABLER5;
    volatile Uint32 GICD_ICENABLER6;
    volatile Uint32 GICD_ICENABLER7;
    volatile Uint32 GICD_ICENABLER8;
    volatile Uint32 GICD_ICENABLER9;
    volatile Uint32 GICD_ICENABLER10;
    volatile Uint32 GICD_ICENABLER11;
    volatile Uint32 GICD_ICENABLER12;
    volatile Uint32 GICD_ICENABLER13;
    volatile Uint32 GICD_ICENABLER14;
    volatile Uint32 GICD_ICENABLER15;
    volatile Uint8  RSVD3[64];
    volatile Uint32 GICD_ISPENDR0;
    volatile Uint32 GICD_ISPENDR1;
    volatile Uint32 GICD_ISPENDR2;
    volatile Uint32 GICD_ISPENDR3;
    volatile Uint32 GICD_ISPENDR4;
    volatile Uint32 GICD_ISPENDR5;
    volatile Uint32 GICD_ISPENDR6;
    volatile Uint32 GICD_ISPENDR7;
    volatile Uint32 GICD_ISPENDR8;
    volatile Uint32 GICD_ISPENDR9;
    volatile Uint32 GICD_ISPENDR10;
    volatile Uint32 GICD_ISPENDR11;
    volatile Uint32 GICD_ISPENDR12;
    volatile Uint32 GICD_ISPENDR13;
    volatile Uint32 GICD_ISPENDR14;
    volatile Uint32 GICD_ISPENDR15;
    volatile Uint8  RSVD4[64];
    volatile Uint32 GICD_ICPENDR0;
    volatile Uint32 GICD_ICPENDR1;
    volatile Uint32 GICD_ICPENDR2;
    volatile Uint32 GICD_ICPENDR3;
    volatile Uint32 GICD_ICPENDR4;
    volatile Uint32 GICD_ICPENDR5;
    volatile Uint32 GICD_ICPENDR6;
    volatile Uint32 GICD_ICPENDR7;
    volatile Uint32 GICD_ICPENDR8;
    volatile Uint32 GICD_ICPENDR9;
    volatile Uint32 GICD_ICPENDR10;
    volatile Uint32 GICD_ICPENDR11;
    volatile Uint32 GICD_ICPENDR12;
    volatile Uint32 GICD_ICPENDR13;
    volatile Uint32 GICD_ICPENDR14;
    volatile Uint32 GICD_ICPENDR15;
    volatile Uint8  RSVD5[64];
    volatile Uint32 GICD_ISACTIVER0;
    volatile Uint32 GICD_ISACTIVER1;
    volatile Uint32 GICD_ISACTIVER2;
    volatile Uint32 GICD_ISACTIVER3;
    volatile Uint32 GICD_ISACTIVER4;
    volatile Uint32 GICD_ISACTIVER5;
    volatile Uint32 GICD_ISACTIVER6;
    volatile Uint32 GICD_ISACTIVER7;
    volatile Uint32 GICD_ISACTIVER8;
    volatile Uint32 GICD_ISACTIVER9;
    volatile Uint32 GICD_ISACTIVER10;
    volatile Uint32 GICD_ISACTIVER11;
    volatile Uint32 GICD_ISACTIVER12;
    volatile Uint32 GICD_ISACTIVER13;
    volatile Uint32 GICD_ISACTIVER14;
    volatile Uint32 GICD_ISACTIVER15;
    volatile Uint8  RSVD6[64];
    volatile Uint32 GICD_ICACTIVER0;
    volatile Uint32 GICD_ICACTIVER1;
    volatile Uint32 GICD_ICACTIVER2;
    volatile Uint32 GICD_ICACTIVER3;
    volatile Uint32 GICD_ICACTIVER4;
    volatile Uint32 GICD_ICACTIVER5;
    volatile Uint32 GICD_ICACTIVER6;
    volatile Uint32 GICD_ICACTIVER7;
    volatile Uint32 GICD_ICACTIVER8;
    volatile Uint32 GICD_ICACTIVER9;
    volatile Uint32 GICD_ICACTIVER10;
    volatile Uint32 GICD_ICACTIVER11;
    volatile Uint32 GICD_ICACTIVER12;
    volatile Uint32 GICD_ICACTIVER13;
    volatile Uint32 GICD_ICACTIVER14;
    volatile Uint32 GICD_ICACTIVER15;
    volatile Uint8  RSVD7[64];
    volatile Uint32 GICD_IPRIORITYR0;
    volatile Uint32 GICD_IPRIORITYR1;
    volatile Uint32 GICD_IPRIORITYR2;
    volatile Uint32 GICD_IPRIORITYR3;
    volatile Uint32 GICD_IPRIORITYR4;
    volatile Uint32 GICD_IPRIORITYR5;
    volatile Uint32 GICD_IPRIORITYR6;
    volatile Uint32 GICD_IPRIORITYR7;
    volatile Uint32 GICD_IPRIORITYR8;
    volatile Uint32 GICD_IPRIORITYR9;
    volatile Uint32 GICD_IPRIORITYR10;
    volatile Uint32 GICD_IPRIORITYR11;
    volatile Uint32 GICD_IPRIORITYR12;
    volatile Uint32 GICD_IPRIORITYR13;
    volatile Uint32 GICD_IPRIORITYR14;
    volatile Uint32 GICD_IPRIORITYR15;
    volatile Uint32 GICD_IPRIORITYR16;
    volatile Uint32 GICD_IPRIORITYR17;
    volatile Uint32 GICD_IPRIORITYR18;
    volatile Uint32 GICD_IPRIORITYR19;
    volatile Uint32 GICD_IPRIORITYR20;
    volatile Uint32 GICD_IPRIORITYR21;
    volatile Uint32 GICD_IPRIORITYR22;
    volatile Uint32 GICD_IPRIORITYR23;
    volatile Uint32 GICD_IPRIORITYR24;
    volatile Uint32 GICD_IPRIORITYR25;
    volatile Uint32 GICD_IPRIORITYR26;
    volatile Uint32 GICD_IPRIORITYR27;
    volatile Uint32 GICD_IPRIORITYR28;
    volatile Uint32 GICD_IPRIORITYR29;
    volatile Uint32 GICD_IPRIORITYR30;
    volatile Uint32 GICD_IPRIORITYR31;
    volatile Uint32 GICD_IPRIORITYR32;
    volatile Uint32 GICD_IPRIORITYR33;
    volatile Uint32 GICD_IPRIORITYR34;
    volatile Uint32 GICD_IPRIORITYR35;
    volatile Uint32 GICD_IPRIORITYR36;
    volatile Uint32 GICD_IPRIORITYR37;
    volatile Uint32 GICD_IPRIORITYR38;
    volatile Uint32 GICD_IPRIORITYR39;
    volatile Uint32 GICD_IPRIORITYR40;
    volatile Uint32 GICD_IPRIORITYR41;
    volatile Uint32 GICD_IPRIORITYR42;
    volatile Uint32 GICD_IPRIORITYR43;
    volatile Uint32 GICD_IPRIORITYR44;
    volatile Uint32 GICD_IPRIORITYR45;
    volatile Uint32 GICD_IPRIORITYR46;
    volatile Uint32 GICD_IPRIORITYR47;
    volatile Uint32 GICD_IPRIORITYR48;
    volatile Uint32 GICD_IPRIORITYR49;
    volatile Uint32 GICD_IPRIORITYR50;
    volatile Uint32 GICD_IPRIORITYR51;
    volatile Uint32 GICD_IPRIORITYR52;
    volatile Uint32 GICD_IPRIORITYR53;
    volatile Uint32 GICD_IPRIORITYR54;
    volatile Uint32 GICD_IPRIORITYR55;
    volatile Uint32 GICD_IPRIORITYR56;
    volatile Uint32 GICD_IPRIORITYR57;
    volatile Uint32 GICD_IPRIORITYR58;
    volatile Uint32 GICD_IPRIORITYR59;
    volatile Uint32 GICD_IPRIORITYR60;
    volatile Uint32 GICD_IPRIORITYR61;
    volatile Uint32 GICD_IPRIORITYR62;
    volatile Uint32 GICD_IPRIORITYR63;
    volatile Uint32 GICD_IPRIORITYR64;
    volatile Uint32 GICD_IPRIORITYR65;
    volatile Uint32 GICD_IPRIORITYR66;
    volatile Uint32 GICD_IPRIORITYR67;
    volatile Uint32 GICD_IPRIORITYR68;
    volatile Uint32 GICD_IPRIORITYR69;
    volatile Uint32 GICD_IPRIORITYR70;
    volatile Uint32 GICD_IPRIORITYR71;
    volatile Uint32 GICD_IPRIORITYR72;
    volatile Uint32 GICD_IPRIORITYR73;
    volatile Uint32 GICD_IPRIORITYR74;
    volatile Uint32 GICD_IPRIORITYR75;
    volatile Uint32 GICD_IPRIORITYR76;
    volatile Uint32 GICD_IPRIORITYR77;
    volatile Uint32 GICD_IPRIORITYR78;
    volatile Uint32 GICD_IPRIORITYR79;
    volatile Uint32 GICD_IPRIORITYR80;
    volatile Uint32 GICD_IPRIORITYR81;
    volatile Uint32 GICD_IPRIORITYR82;
    volatile Uint32 GICD_IPRIORITYR83;
    volatile Uint32 GICD_IPRIORITYR84;
    volatile Uint32 GICD_IPRIORITYR85;
    volatile Uint32 GICD_IPRIORITYR86;
    volatile Uint32 GICD_IPRIORITYR87;
    volatile Uint32 GICD_IPRIORITYR88;
    volatile Uint32 GICD_IPRIORITYR89;
    volatile Uint32 GICD_IPRIORITYR90;
    volatile Uint32 GICD_IPRIORITYR91;
    volatile Uint32 GICD_IPRIORITYR92;
    volatile Uint32 GICD_IPRIORITYR93;
    volatile Uint32 GICD_IPRIORITYR94;
    volatile Uint32 GICD_IPRIORITYR95;
    volatile Uint32 GICD_IPRIORITYR96;
    volatile Uint32 GICD_IPRIORITYR97;
    volatile Uint32 GICD_IPRIORITYR98;
    volatile Uint32 GICD_IPRIORITYR99;
    volatile Uint32 GICD_IPRIORITYR100;
    volatile Uint32 GICD_IPRIORITYR101;
    volatile Uint32 GICD_IPRIORITYR102;
    volatile Uint32 GICD_IPRIORITYR103;
    volatile Uint32 GICD_IPRIORITYR104;
    volatile Uint32 GICD_IPRIORITYR105;
    volatile Uint32 GICD_IPRIORITYR106;
    volatile Uint32 GICD_IPRIORITYR107;
    volatile Uint32 GICD_IPRIORITYR108;
    volatile Uint32 GICD_IPRIORITYR109;
    volatile Uint32 GICD_IPRIORITYR110;
    volatile Uint32 GICD_IPRIORITYR111;
    volatile Uint32 GICD_IPRIORITYR112;
    volatile Uint32 GICD_IPRIORITYR113;
    volatile Uint32 GICD_IPRIORITYR114;
    volatile Uint32 GICD_IPRIORITYR115;
    volatile Uint32 GICD_IPRIORITYR116;
    volatile Uint32 GICD_IPRIORITYR117;
    volatile Uint32 GICD_IPRIORITYR118;
    volatile Uint32 GICD_IPRIORITYR119;
    volatile Uint32 GICD_IPRIORITYR120;
    volatile Uint32 GICD_IPRIORITYR121;
    volatile Uint32 GICD_IPRIORITYR122;
    volatile Uint32 GICD_IPRIORITYR123;
    volatile Uint32 GICD_IPRIORITYR124;
    volatile Uint32 GICD_IPRIORITYR125;
    volatile Uint32 GICD_IPRIORITYR126;
    volatile Uint32 GICD_IPRIORITYR127;
    volatile Uint8  RSVD8[512];
    volatile Uint32 GICD_ITARGETSR0;
    volatile Uint32 GICD_ITARGETSR1;
    volatile Uint32 GICD_ITARGETSR2;
    volatile Uint32 GICD_ITARGETSR3;
    volatile Uint32 GICD_ITARGETSR4;
    volatile Uint32 GICD_ITARGETSR5;
    volatile Uint32 GICD_ITARGETSR6;
    volatile Uint32 GICD_ITARGETSR7;
    volatile Uint32 GICD_ITARGETSR8;
    volatile Uint32 GICD_ITARGETSR9;
    volatile Uint32 GICD_ITARGETSR10;
    volatile Uint32 GICD_ITARGETSR11;
    volatile Uint32 GICD_ITARGETSR12;
    volatile Uint32 GICD_ITARGETSR13;
    volatile Uint32 GICD_ITARGETSR14;
    volatile Uint32 GICD_ITARGETSR15;
    volatile Uint32 GICD_ITARGETSR16;
    volatile Uint32 GICD_ITARGETSR17;
    volatile Uint32 GICD_ITARGETSR18;
    volatile Uint32 GICD_ITARGETSR19;
    volatile Uint32 GICD_ITARGETSR20;
    volatile Uint32 GICD_ITARGETSR21;
    volatile Uint32 GICD_ITARGETSR22;
    volatile Uint32 GICD_ITARGETSR23;
    volatile Uint32 GICD_ITARGETSR24;
    volatile Uint32 GICD_ITARGETSR25;
    volatile Uint32 GICD_ITARGETSR26;
    volatile Uint32 GICD_ITARGETSR27;
    volatile Uint32 GICD_ITARGETSR28;
    volatile Uint32 GICD_ITARGETSR29;
    volatile Uint32 GICD_ITARGETSR30;
    volatile Uint32 GICD_ITARGETSR31;
    volatile Uint32 GICD_ITARGETSR32;
    volatile Uint32 GICD_ITARGETSR33;
    volatile Uint32 GICD_ITARGETSR34;
    volatile Uint32 GICD_ITARGETSR35;
    volatile Uint32 GICD_ITARGETSR36;
    volatile Uint32 GICD_ITARGETSR37;
    volatile Uint32 GICD_ITARGETSR38;
    volatile Uint32 GICD_ITARGETSR39;
    volatile Uint32 GICD_ITARGETSR40;
    volatile Uint32 GICD_ITARGETSR41;
    volatile Uint32 GICD_ITARGETSR42;
    volatile Uint32 GICD_ITARGETSR43;
    volatile Uint32 GICD_ITARGETSR44;
    volatile Uint32 GICD_ITARGETSR45;
    volatile Uint32 GICD_ITARGETSR46;
    volatile Uint32 GICD_ITARGETSR47;
    volatile Uint32 GICD_ITARGETSR48;
    volatile Uint32 GICD_ITARGETSR49;
    volatile Uint32 GICD_ITARGETSR50;
    volatile Uint32 GICD_ITARGETSR51;
    volatile Uint32 GICD_ITARGETSR52;
    volatile Uint32 GICD_ITARGETSR53;
    volatile Uint32 GICD_ITARGETSR54;
    volatile Uint32 GICD_ITARGETSR55;
    volatile Uint32 GICD_ITARGETSR56;
    volatile Uint32 GICD_ITARGETSR57;
    volatile Uint32 GICD_ITARGETSR58;
    volatile Uint32 GICD_ITARGETSR59;
    volatile Uint32 GICD_ITARGETSR60;
    volatile Uint32 GICD_ITARGETSR61;
    volatile Uint32 GICD_ITARGETSR62;
    volatile Uint32 GICD_ITARGETSR63;
    volatile Uint32 GICD_ITARGETSR64;
    volatile Uint32 GICD_ITARGETSR65;
    volatile Uint32 GICD_ITARGETSR66;
    volatile Uint32 GICD_ITARGETSR67;
    volatile Uint32 GICD_ITARGETSR68;
    volatile Uint32 GICD_ITARGETSR69;
    volatile Uint32 GICD_ITARGETSR70;
    volatile Uint32 GICD_ITARGETSR71;
    volatile Uint32 GICD_ITARGETSR72;
    volatile Uint32 GICD_ITARGETSR73;
    volatile Uint32 GICD_ITARGETSR74;
    volatile Uint32 GICD_ITARGETSR75;
    volatile Uint32 GICD_ITARGETSR76;
    volatile Uint32 GICD_ITARGETSR77;
    volatile Uint32 GICD_ITARGETSR78;
    volatile Uint32 GICD_ITARGETSR79;
    volatile Uint32 GICD_ITARGETSR80;
    volatile Uint32 GICD_ITARGETSR81;
    volatile Uint32 GICD_ITARGETSR82;
    volatile Uint32 GICD_ITARGETSR83;
    volatile Uint32 GICD_ITARGETSR84;
    volatile Uint32 GICD_ITARGETSR85;
    volatile Uint32 GICD_ITARGETSR86;
    volatile Uint32 GICD_ITARGETSR87;
    volatile Uint32 GICD_ITARGETSR88;
    volatile Uint32 GICD_ITARGETSR89;
    volatile Uint32 GICD_ITARGETSR90;
    volatile Uint32 GICD_ITARGETSR91;
    volatile Uint32 GICD_ITARGETSR92;
    volatile Uint32 GICD_ITARGETSR93;
    volatile Uint32 GICD_ITARGETSR94;
    volatile Uint32 GICD_ITARGETSR95;
    volatile Uint32 GICD_ITARGETSR96;
    volatile Uint32 GICD_ITARGETSR97;
    volatile Uint32 GICD_ITARGETSR98;
    volatile Uint32 GICD_ITARGETSR99;
    volatile Uint32 GICD_ITARGETSR100;
    volatile Uint32 GICD_ITARGETSR101;
    volatile Uint32 GICD_ITARGETSR102;
    volatile Uint32 GICD_ITARGETSR103;
    volatile Uint32 GICD_ITARGETSR104;
    volatile Uint32 GICD_ITARGETSR105;
    volatile Uint32 GICD_ITARGETSR106;
    volatile Uint32 GICD_ITARGETSR107;
    volatile Uint32 GICD_ITARGETSR108;
    volatile Uint32 GICD_ITARGETSR109;
    volatile Uint32 GICD_ITARGETSR110;
    volatile Uint32 GICD_ITARGETSR111;
    volatile Uint32 GICD_ITARGETSR112;
    volatile Uint32 GICD_ITARGETSR113;
    volatile Uint32 GICD_ITARGETSR114;
    volatile Uint32 GICD_ITARGETSR115;
    volatile Uint32 GICD_ITARGETSR116;
    volatile Uint32 GICD_ITARGETSR117;
    volatile Uint32 GICD_ITARGETSR118;
    volatile Uint32 GICD_ITARGETSR119;
    volatile Uint32 GICD_ITARGETSR120;
    volatile Uint32 GICD_ITARGETSR121;
    volatile Uint32 GICD_ITARGETSR122;
    volatile Uint32 GICD_ITARGETSR123;
    volatile Uint32 GICD_ITARGETSR124;
    volatile Uint32 GICD_ITARGETSR125;
    volatile Uint32 GICD_ITARGETSR126;
    volatile Uint32 GICD_ITARGETSR127;
    volatile Uint8  RSVD9[512];
    volatile Uint32 GICD_ICFGR0;
    volatile Uint32 GICD_ICFGR1;
    volatile Uint32 GICD_ICFGR2;
    volatile Uint32 GICD_ICFGR3;
    volatile Uint32 GICD_ICFGR4;
    volatile Uint32 GICD_ICFGR5;
    volatile Uint32 GICD_ICFGR6;
    volatile Uint32 GICD_ICFGR7;
    volatile Uint32 GICD_ICFGR8;
    volatile Uint32 GICD_ICFGR9;
    volatile Uint32 GICD_ICFGR10;
    volatile Uint32 GICD_ICFGR11;
    volatile Uint32 GICD_ICFGR12;
    volatile Uint32 GICD_ICFGR13;
    volatile Uint32 GICD_ICFGR14;
    volatile Uint32 GICD_ICFGR15;
    volatile Uint32 GICD_ICFGR16;
    volatile Uint32 GICD_ICFGR17;
    volatile Uint32 GICD_ICFGR18;
    volatile Uint32 GICD_ICFGR19;
    volatile Uint32 GICD_ICFGR20;
    volatile Uint32 GICD_ICFGR21;
    volatile Uint32 GICD_ICFGR22;
    volatile Uint32 GICD_ICFGR23;
    volatile Uint32 GICD_ICFGR24;
    volatile Uint32 GICD_ICFGR25;
    volatile Uint32 GICD_ICFGR26;
    volatile Uint32 GICD_ICFGR27;
    volatile Uint32 GICD_ICFGR28;
    volatile Uint32 GICD_ICFGR29;
    volatile Uint32 GICD_ICFGR30;
    volatile Uint32 GICD_ICFGR31;
    volatile Uint8  RSVD10[128];
    volatile Uint32 GICD_PPISR;
    volatile Uint32 GICD_SPISR0;
    volatile Uint32 GICD_SPISR1;
    volatile Uint32 GICD_SPISR2;
    volatile Uint32 GICD_SPISR3;
    volatile Uint32 GICD_SPISR4;
    volatile Uint32 GICD_SPISR5;
    volatile Uint32 GICD_SPISR6;
    volatile Uint32 GICD_SPISR7;
    volatile Uint32 GICD_SPISR8;
    volatile Uint32 GICD_SPISR9;
    volatile Uint32 GICD_SPISR10;
    volatile Uint32 GICD_SPISR11;
    volatile Uint32 GICD_SPISR12;
    volatile Uint32 GICD_SPISR13;
    volatile Uint32 GICD_SPISR14;
    volatile Uint8  RSVD11[448];
    volatile Uint32 GICD_SGIR;
    volatile Uint8  RSVD12[12];
    volatile Uint32 GICD_CPENDSGIR0;
    volatile Uint32 GICD_CPENDSGIR1;
    volatile Uint32 GICD_CPENDSGIR2;
    volatile Uint32 GICD_CPENDSGIR3;
    volatile Uint32 GICD_SPENDSGIR0;
    volatile Uint32 GICD_SPENDSGIR1;
    volatile Uint32 GICD_SPENDSGIR2;
    volatile Uint32 GICD_SPENDSGIR3;
    volatile Uint8  RSVD13[160];
    volatile Uint32 GICD_PIDR4;
    volatile Uint32 GICD_PIDR5;
    volatile Uint32 GICD_PIDR6;
    volatile Uint32 GICD_PIDR7;
    volatile Uint32 GICD_PIDR0;
    volatile Uint32 GICD_PIDR1;
    volatile Uint32 GICD_PIDR2;
    volatile Uint32 GICD_PIDR3;
    volatile Uint32 GICD_CIDR0;
    volatile Uint32 GICD_CIDR1;
    volatile Uint32 GICD_CIDR2;
    volatile Uint32 GICD_CIDR3;
} CSL_Gic400DistributorRegs;


/**************************************************************************
* Register Overlay Structure for GICC
**************************************************************************/
typedef struct {
    volatile Uint32 GICC_CTLR;
    volatile Uint32 GICC_PMR;
    volatile Uint32 GICC_BPR;
    volatile Uint32 GICC_IAR;
    volatile Uint32 GICC_EOIR;
    volatile Uint32 GICC_RPR;
    volatile Uint32 GICC_HPPIR;
    volatile Uint32 GICC_ABPR;
    volatile Uint32 GICC_AIAR;
    volatile Uint32 GICC_AEOIR;
    volatile Uint32 GICC_AHPPIR;
    volatile Uint8  RSVD0[164];
    volatile Uint32 GICC_APR0;
    volatile Uint8  RSVD1[12];
    volatile Uint32 GICC_NSAPR0;
    volatile Uint8  RSVD2[24];
    volatile Uint32 GICC_IIDR;
    volatile Uint8  RSVD3[3840];
    volatile Uint32 GICC_DIR;
} CSL_Gic400GiccRegs;


/**************************************************************************
* Register Overlay Structure for GICH
**************************************************************************/
typedef struct {
    volatile Uint32 GICH_HCR;
    volatile Uint32 GICH_VTR;
    volatile Uint32 GICH_VMCR;
    volatile Uint8  RSVD0[4];
    volatile Uint32 GICH_MISR;
    volatile Uint8  RSVD1[12];
    volatile Uint32 GICH_EISR0;
    volatile Uint8  RSVD2[12];
    volatile Uint32 GICH_ELSR0;
    volatile Uint8  RSVD3[188];
    volatile Uint32 GICH_APR0;
    volatile Uint8  RSVD4[12];
    volatile Uint32 GICH_LR0;
    volatile Uint32 GICH_LR1;
    volatile Uint32 GICH_LR2;
    volatile Uint32 GICH_LR3;
} CSL_Gic400GichRegs;


/**************************************************************************
* Register Overlay Structure for GICV
**************************************************************************/
typedef struct {
    volatile Uint32 GICV_CTLR;
    volatile Uint32 GICV_PMR;
    volatile Uint32 GICV_BPR;
    volatile Uint32 GICV_IAR;
    volatile Uint32 GICV_EOIR;
    volatile Uint32 GICV_RPR;
    volatile Uint32 GICV_HPPIR;
    volatile Uint32 GICV_ABPR;
    volatile Uint32 GICV_AIAR;
    volatile Uint32 GICV_AEOIR;
    volatile Uint32 GICV_AHPPIR;
    volatile Uint8  RSVD0[164];
    volatile Uint32 GICV_APR0;
    volatile Uint8  RSVD1[40];
    volatile Uint32 GICV_IIDR;
    volatile Uint8  RSVD2[3840];
    volatile Uint32 GICV_DIR;
} CSL_Gic400GicvRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint8  RSVD3[4096];
    CSL_Gic400DistributorRegs	DISTRIBUTOR;
    CSL_Gic400GiccRegs	GICC;
    volatile Uint8  RSVD4[4092];
    CSL_Gic400GichRegs	GICH;
    volatile Uint8  RSVD5[7920];
    CSL_Gic400GicvRegs	GICV;
} CSL_Gic400Regs;




/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_GIC400_GICD_CTLR                                    (0x1000U)
#define CSL_GIC400_GICD_TYPER                                   (0x1004U)
#define CSL_GIC400_GICD_IIDR                                    (0x1008U)
#define CSL_GIC400_GICD_IGROUPR0                                (0x1080U)
#define CSL_GIC400_GICD_IGROUPR1                                (0x1084U)
#define CSL_GIC400_GICD_IGROUPR2                                (0x1088U)
#define CSL_GIC400_GICD_IGROUPR3                                (0x108CU)
#define CSL_GIC400_GICD_IGROUPR4                                (0x1090U)
#define CSL_GIC400_GICD_IGROUPR5                                (0x1094U)
#define CSL_GIC400_GICD_IGROUPR6                                (0x1098U)
#define CSL_GIC400_GICD_IGROUPR7                                (0x109CU)
#define CSL_GIC400_GICD_IGROUPR8                                (0x10A0U)
#define CSL_GIC400_GICD_IGROUPR9                                (0x10A4U)
#define CSL_GIC400_GICD_IGROUPR10                               (0x10A8U)
#define CSL_GIC400_GICD_IGROUPR11                               (0x10ACU)
#define CSL_GIC400_GICD_IGROUPR12                               (0x10B0U)
#define CSL_GIC400_GICD_IGROUPR13                               (0x10B4U)
#define CSL_GIC400_GICD_IGROUPR14                               (0x10B8U)
#define CSL_GIC400_GICD_IGROUPR15                               (0x10BCU)
#define CSL_GIC400_GICD_ISENABLER0                              (0x1100U)
#define CSL_GIC400_GICD_ISENABLER1                              (0x1104U)
#define CSL_GIC400_GICD_ISENABLER2                              (0x1108U)
#define CSL_GIC400_GICD_ISENABLER3                              (0x110CU)
#define CSL_GIC400_GICD_ISENABLER4                              (0x1110U)
#define CSL_GIC400_GICD_ISENABLER5                              (0x1114U)
#define CSL_GIC400_GICD_ISENABLER6                              (0x1118U)
#define CSL_GIC400_GICD_ISENABLER7                              (0x111CU)
#define CSL_GIC400_GICD_ISENABLER8                              (0x1120U)
#define CSL_GIC400_GICD_ISENABLER9                              (0x1124U)
#define CSL_GIC400_GICD_ISENABLER10                             (0x1128U)
#define CSL_GIC400_GICD_ISENABLER11                             (0x112CU)
#define CSL_GIC400_GICD_ISENABLER12                             (0x1130U)
#define CSL_GIC400_GICD_ISENABLER13                             (0x1134U)
#define CSL_GIC400_GICD_ISENABLER14                             (0x1138U)
#define CSL_GIC400_GICD_ISENABLER15                             (0x113CU)
#define CSL_GIC400_GICD_ICENABLER0                              (0x1180U)
#define CSL_GIC400_GICD_ICENABLER1                              (0x1184U)
#define CSL_GIC400_GICD_ICENABLER2                              (0x1188U)
#define CSL_GIC400_GICD_ICENABLER3                              (0x118CU)
#define CSL_GIC400_GICD_ICENABLER4                              (0x1190U)
#define CSL_GIC400_GICD_ICENABLER5                              (0x1194U)
#define CSL_GIC400_GICD_ICENABLER6                              (0x1198U)
#define CSL_GIC400_GICD_ICENABLER7                              (0x119CU)
#define CSL_GIC400_GICD_ICENABLER8                              (0x11A0U)
#define CSL_GIC400_GICD_ICENABLER9                              (0x11A4U)
#define CSL_GIC400_GICD_ICENABLER10                             (0x11A8U)
#define CSL_GIC400_GICD_ICENABLER11                             (0x11ACU)
#define CSL_GIC400_GICD_ICENABLER12                             (0x11B0U)
#define CSL_GIC400_GICD_ICENABLER13                             (0x11B4U)
#define CSL_GIC400_GICD_ICENABLER14                             (0x11B8U)
#define CSL_GIC400_GICD_ICENABLER15                             (0x11BCU)
#define CSL_GIC400_GICD_ISPENDR0                                (0x1200U)
#define CSL_GIC400_GICD_ISPENDR1                                (0x1204U)
#define CSL_GIC400_GICD_ISPENDR2                                (0x1208U)
#define CSL_GIC400_GICD_ISPENDR3                                (0x120CU)
#define CSL_GIC400_GICD_ISPENDR4                                (0x1210U)
#define CSL_GIC400_GICD_ISPENDR5                                (0x1214U)
#define CSL_GIC400_GICD_ISPENDR6                                (0x1218U)
#define CSL_GIC400_GICD_ISPENDR7                                (0x121CU)
#define CSL_GIC400_GICD_ISPENDR8                                (0x1220U)
#define CSL_GIC400_GICD_ISPENDR9                                (0x1224U)
#define CSL_GIC400_GICD_ISPENDR10                               (0x1228U)
#define CSL_GIC400_GICD_ISPENDR11                               (0x122CU)
#define CSL_GIC400_GICD_ISPENDR12                               (0x1230U)
#define CSL_GIC400_GICD_ISPENDR13                               (0x1234U)
#define CSL_GIC400_GICD_ISPENDR14                               (0x1238U)
#define CSL_GIC400_GICD_ISPENDR15                               (0x123CU)
#define CSL_GIC400_GICD_ICPENDR0                                (0x1280U)
#define CSL_GIC400_GICD_ICPENDR1                                (0x1284U)
#define CSL_GIC400_GICD_ICPENDR2                                (0x1288U)
#define CSL_GIC400_GICD_ICPENDR3                                (0x128CU)
#define CSL_GIC400_GICD_ICPENDR4                                (0x1290U)
#define CSL_GIC400_GICD_ICPENDR5                                (0x1294U)
#define CSL_GIC400_GICD_ICPENDR6                                (0x1298U)
#define CSL_GIC400_GICD_ICPENDR7                                (0x129CU)
#define CSL_GIC400_GICD_ICPENDR8                                (0x12A0U)
#define CSL_GIC400_GICD_ICPENDR9                                (0x12A4U)
#define CSL_GIC400_GICD_ICPENDR10                               (0x12A8U)
#define CSL_GIC400_GICD_ICPENDR11                               (0x12ACU)
#define CSL_GIC400_GICD_ICPENDR12                               (0x12B0U)
#define CSL_GIC400_GICD_ICPENDR13                               (0x12B4U)
#define CSL_GIC400_GICD_ICPENDR14                               (0x12B8U)
#define CSL_GIC400_GICD_ICPENDR15                               (0x12BCU)
#define CSL_GIC400_GICD_ISACTIVER0                              (0x1300U)
#define CSL_GIC400_GICD_ISACTIVER1                              (0x1304U)
#define CSL_GIC400_GICD_ISACTIVER2                              (0x1308U)
#define CSL_GIC400_GICD_ISACTIVER3                              (0x130CU)
#define CSL_GIC400_GICD_ISACTIVER4                              (0x1310U)
#define CSL_GIC400_GICD_ISACTIVER5                              (0x1314U)
#define CSL_GIC400_GICD_ISACTIVER6                              (0x1318U)
#define CSL_GIC400_GICD_ISACTIVER7                              (0x131CU)
#define CSL_GIC400_GICD_ISACTIVER8                              (0x1320U)
#define CSL_GIC400_GICD_ISACTIVER9                              (0x1324U)
#define CSL_GIC400_GICD_ISACTIVER10                             (0x1328U)
#define CSL_GIC400_GICD_ISACTIVER11                             (0x132CU)
#define CSL_GIC400_GICD_ISACTIVER12                             (0x1330U)
#define CSL_GIC400_GICD_ISACTIVER13                             (0x1334U)
#define CSL_GIC400_GICD_ISACTIVER14                             (0x1338U)
#define CSL_GIC400_GICD_ISACTIVER15                             (0x133CU)
#define CSL_GIC400_GICD_ICACTIVER0                              (0x1380U)
#define CSL_GIC400_GICD_ICACTIVER1                              (0x1384U)
#define CSL_GIC400_GICD_ICACTIVER2                              (0x1388U)
#define CSL_GIC400_GICD_ICACTIVER3                              (0x138CU)
#define CSL_GIC400_GICD_ICACTIVER4                              (0x1390U)
#define CSL_GIC400_GICD_ICACTIVER5                              (0x1394U)
#define CSL_GIC400_GICD_ICACTIVER6                              (0x1398U)
#define CSL_GIC400_GICD_ICACTIVER7                              (0x139CU)
#define CSL_GIC400_GICD_ICACTIVER8                              (0x13A0U)
#define CSL_GIC400_GICD_ICACTIVER9                              (0x13A4U)
#define CSL_GIC400_GICD_ICACTIVER10                             (0x13A8U)
#define CSL_GIC400_GICD_ICACTIVER11                             (0x13ACU)
#define CSL_GIC400_GICD_ICACTIVER12                             (0x13B0U)
#define CSL_GIC400_GICD_ICACTIVER13                             (0x13B4U)
#define CSL_GIC400_GICD_ICACTIVER14                             (0x13B8U)
#define CSL_GIC400_GICD_ICACTIVER15                             (0x13BCU)
#define CSL_GIC400_GICD_IPRIORITYR0                             (0x1400U)
#define CSL_GIC400_GICD_IPRIORITYR1                             (0x1404U)
#define CSL_GIC400_GICD_IPRIORITYR2                             (0x1408U)
#define CSL_GIC400_GICD_IPRIORITYR3                             (0x140CU)
#define CSL_GIC400_GICD_IPRIORITYR4                             (0x1410U)
#define CSL_GIC400_GICD_IPRIORITYR5                             (0x1414U)
#define CSL_GIC400_GICD_IPRIORITYR6                             (0x1418U)
#define CSL_GIC400_GICD_IPRIORITYR7                             (0x141CU)
#define CSL_GIC400_GICD_IPRIORITYR8                             (0x1420U)
#define CSL_GIC400_GICD_IPRIORITYR9                             (0x1424U)
#define CSL_GIC400_GICD_IPRIORITYR10                            (0x1428U)
#define CSL_GIC400_GICD_IPRIORITYR11                            (0x142CU)
#define CSL_GIC400_GICD_IPRIORITYR12                            (0x1430U)
#define CSL_GIC400_GICD_IPRIORITYR13                            (0x1434U)
#define CSL_GIC400_GICD_IPRIORITYR14                            (0x1438U)
#define CSL_GIC400_GICD_IPRIORITYR15                            (0x143CU)
#define CSL_GIC400_GICD_IPRIORITYR16                            (0x1440U)
#define CSL_GIC400_GICD_IPRIORITYR17                            (0x1444U)
#define CSL_GIC400_GICD_IPRIORITYR18                            (0x1448U)
#define CSL_GIC400_GICD_IPRIORITYR19                            (0x144CU)
#define CSL_GIC400_GICD_IPRIORITYR20                            (0x1450U)
#define CSL_GIC400_GICD_IPRIORITYR21                            (0x1454U)
#define CSL_GIC400_GICD_IPRIORITYR22                            (0x1458U)
#define CSL_GIC400_GICD_IPRIORITYR23                            (0x145CU)
#define CSL_GIC400_GICD_IPRIORITYR24                            (0x1460U)
#define CSL_GIC400_GICD_IPRIORITYR25                            (0x1464U)
#define CSL_GIC400_GICD_IPRIORITYR26                            (0x1468U)
#define CSL_GIC400_GICD_IPRIORITYR27                            (0x146CU)
#define CSL_GIC400_GICD_IPRIORITYR28                            (0x1470U)
#define CSL_GIC400_GICD_IPRIORITYR29                            (0x1474U)
#define CSL_GIC400_GICD_IPRIORITYR30                            (0x1478U)
#define CSL_GIC400_GICD_IPRIORITYR31                            (0x147CU)
#define CSL_GIC400_GICD_IPRIORITYR32                            (0x1480U)
#define CSL_GIC400_GICD_IPRIORITYR33                            (0x1484U)
#define CSL_GIC400_GICD_IPRIORITYR34                            (0x1488U)
#define CSL_GIC400_GICD_IPRIORITYR35                            (0x148CU)
#define CSL_GIC400_GICD_IPRIORITYR36                            (0x1490U)
#define CSL_GIC400_GICD_IPRIORITYR37                            (0x1494U)
#define CSL_GIC400_GICD_IPRIORITYR38                            (0x1498U)
#define CSL_GIC400_GICD_IPRIORITYR39                            (0x149CU)
#define CSL_GIC400_GICD_IPRIORITYR40                            (0x14A0U)
#define CSL_GIC400_GICD_IPRIORITYR41                            (0x14A4U)
#define CSL_GIC400_GICD_IPRIORITYR42                            (0x14A8U)
#define CSL_GIC400_GICD_IPRIORITYR43                            (0x14ACU)
#define CSL_GIC400_GICD_IPRIORITYR44                            (0x14B0U)
#define CSL_GIC400_GICD_IPRIORITYR45                            (0x14B4U)
#define CSL_GIC400_GICD_IPRIORITYR46                            (0x14B8U)
#define CSL_GIC400_GICD_IPRIORITYR47                            (0x14BCU)
#define CSL_GIC400_GICD_IPRIORITYR48                            (0x14C0U)
#define CSL_GIC400_GICD_IPRIORITYR49                            (0x14C4U)
#define CSL_GIC400_GICD_IPRIORITYR50                            (0x14C8U)
#define CSL_GIC400_GICD_IPRIORITYR51                            (0x14CCU)
#define CSL_GIC400_GICD_IPRIORITYR52                            (0x14D0U)
#define CSL_GIC400_GICD_IPRIORITYR53                            (0x14D4U)
#define CSL_GIC400_GICD_IPRIORITYR54                            (0x14D8U)
#define CSL_GIC400_GICD_IPRIORITYR55                            (0x14DCU)
#define CSL_GIC400_GICD_IPRIORITYR56                            (0x14E0U)
#define CSL_GIC400_GICD_IPRIORITYR57                            (0x14E4U)
#define CSL_GIC400_GICD_IPRIORITYR58                            (0x14E8U)
#define CSL_GIC400_GICD_IPRIORITYR59                            (0x14ECU)
#define CSL_GIC400_GICD_IPRIORITYR60                            (0x14F0U)
#define CSL_GIC400_GICD_IPRIORITYR61                            (0x14F4U)
#define CSL_GIC400_GICD_IPRIORITYR62                            (0x14F8U)
#define CSL_GIC400_GICD_IPRIORITYR63                            (0x14FCU)
#define CSL_GIC400_GICD_IPRIORITYR64                            (0x1500U)
#define CSL_GIC400_GICD_IPRIORITYR65                            (0x1504U)
#define CSL_GIC400_GICD_IPRIORITYR66                            (0x1508U)
#define CSL_GIC400_GICD_IPRIORITYR67                            (0x150CU)
#define CSL_GIC400_GICD_IPRIORITYR68                            (0x1510U)
#define CSL_GIC400_GICD_IPRIORITYR69                            (0x1514U)
#define CSL_GIC400_GICD_IPRIORITYR70                            (0x1518U)
#define CSL_GIC400_GICD_IPRIORITYR71                            (0x151CU)
#define CSL_GIC400_GICD_IPRIORITYR72                            (0x1520U)
#define CSL_GIC400_GICD_IPRIORITYR73                            (0x1524U)
#define CSL_GIC400_GICD_IPRIORITYR74                            (0x1528U)
#define CSL_GIC400_GICD_IPRIORITYR75                            (0x152CU)
#define CSL_GIC400_GICD_IPRIORITYR76                            (0x1530U)
#define CSL_GIC400_GICD_IPRIORITYR77                            (0x1534U)
#define CSL_GIC400_GICD_IPRIORITYR78                            (0x1538U)
#define CSL_GIC400_GICD_IPRIORITYR79                            (0x153CU)
#define CSL_GIC400_GICD_IPRIORITYR80                            (0x1540U)
#define CSL_GIC400_GICD_IPRIORITYR81                            (0x1544U)
#define CSL_GIC400_GICD_IPRIORITYR82                            (0x1548U)
#define CSL_GIC400_GICD_IPRIORITYR83                            (0x154CU)
#define CSL_GIC400_GICD_IPRIORITYR84                            (0x1550U)
#define CSL_GIC400_GICD_IPRIORITYR85                            (0x1554U)
#define CSL_GIC400_GICD_IPRIORITYR86                            (0x1558U)
#define CSL_GIC400_GICD_IPRIORITYR87                            (0x155CU)
#define CSL_GIC400_GICD_IPRIORITYR88                            (0x1560U)
#define CSL_GIC400_GICD_IPRIORITYR89                            (0x1564U)
#define CSL_GIC400_GICD_IPRIORITYR90                            (0x1568U)
#define CSL_GIC400_GICD_IPRIORITYR91                            (0x156CU)
#define CSL_GIC400_GICD_IPRIORITYR92                            (0x1570U)
#define CSL_GIC400_GICD_IPRIORITYR93                            (0x1574U)
#define CSL_GIC400_GICD_IPRIORITYR94                            (0x1578U)
#define CSL_GIC400_GICD_IPRIORITYR95                            (0x157CU)
#define CSL_GIC400_GICD_IPRIORITYR96                            (0x1580U)
#define CSL_GIC400_GICD_IPRIORITYR97                            (0x1584U)
#define CSL_GIC400_GICD_IPRIORITYR98                            (0x1588U)
#define CSL_GIC400_GICD_IPRIORITYR99                            (0x158CU)
#define CSL_GIC400_GICD_IPRIORITYR100                           (0x1590U)
#define CSL_GIC400_GICD_IPRIORITYR101                           (0x1594U)
#define CSL_GIC400_GICD_IPRIORITYR102                           (0x1598U)
#define CSL_GIC400_GICD_IPRIORITYR103                           (0x159CU)
#define CSL_GIC400_GICD_IPRIORITYR104                           (0x15A0U)
#define CSL_GIC400_GICD_IPRIORITYR105                           (0x15A4U)
#define CSL_GIC400_GICD_IPRIORITYR106                           (0x15A8U)
#define CSL_GIC400_GICD_IPRIORITYR107                           (0x15ACU)
#define CSL_GIC400_GICD_IPRIORITYR108                           (0x15B0U)
#define CSL_GIC400_GICD_IPRIORITYR109                           (0x15B4U)
#define CSL_GIC400_GICD_IPRIORITYR110                           (0x15B8U)
#define CSL_GIC400_GICD_IPRIORITYR111                           (0x15BCU)
#define CSL_GIC400_GICD_IPRIORITYR112                           (0x15C0U)
#define CSL_GIC400_GICD_IPRIORITYR113                           (0x15C4U)
#define CSL_GIC400_GICD_IPRIORITYR114                           (0x15C8U)
#define CSL_GIC400_GICD_IPRIORITYR115                           (0x15CCU)
#define CSL_GIC400_GICD_IPRIORITYR116                           (0x15D0U)
#define CSL_GIC400_GICD_IPRIORITYR117                           (0x15D4U)
#define CSL_GIC400_GICD_IPRIORITYR118                           (0x15D8U)
#define CSL_GIC400_GICD_IPRIORITYR119                           (0x15DCU)
#define CSL_GIC400_GICD_IPRIORITYR120                           (0x15E0U)
#define CSL_GIC400_GICD_IPRIORITYR121                           (0x15E4U)
#define CSL_GIC400_GICD_IPRIORITYR122                           (0x15E8U)
#define CSL_GIC400_GICD_IPRIORITYR123                           (0x15ECU)
#define CSL_GIC400_GICD_IPRIORITYR124                           (0x15F0U)
#define CSL_GIC400_GICD_IPRIORITYR125                           (0x15F4U)
#define CSL_GIC400_GICD_IPRIORITYR126                           (0x15F8U)
#define CSL_GIC400_GICD_IPRIORITYR127                           (0x15FCU)
#define CSL_GIC400_GICD_ITARGETSR0                              (0x1800U)
#define CSL_GIC400_GICD_ITARGETSR1                              (0x1804U)
#define CSL_GIC400_GICD_ITARGETSR2                              (0x1808U)
#define CSL_GIC400_GICD_ITARGETSR3                              (0x180CU)
#define CSL_GIC400_GICD_ITARGETSR4                              (0x1810U)
#define CSL_GIC400_GICD_ITARGETSR5                              (0x1814U)
#define CSL_GIC400_GICD_ITARGETSR6                              (0x1818U)
#define CSL_GIC400_GICD_ITARGETSR7                              (0x181CU)
#define CSL_GIC400_GICD_ITARGETSR8                              (0x1820U)
#define CSL_GIC400_GICD_ITARGETSR9                              (0x1824U)
#define CSL_GIC400_GICD_ITARGETSR10                             (0x1828U)
#define CSL_GIC400_GICD_ITARGETSR11                             (0x182CU)
#define CSL_GIC400_GICD_ITARGETSR12                             (0x1830U)
#define CSL_GIC400_GICD_ITARGETSR13                             (0x1834U)
#define CSL_GIC400_GICD_ITARGETSR14                             (0x1838U)
#define CSL_GIC400_GICD_ITARGETSR15                             (0x183CU)
#define CSL_GIC400_GICD_ITARGETSR16                             (0x1840U)
#define CSL_GIC400_GICD_ITARGETSR17                             (0x1844U)
#define CSL_GIC400_GICD_ITARGETSR18                             (0x1848U)
#define CSL_GIC400_GICD_ITARGETSR19                             (0x184CU)
#define CSL_GIC400_GICD_ITARGETSR20                             (0x1850U)
#define CSL_GIC400_GICD_ITARGETSR21                             (0x1854U)
#define CSL_GIC400_GICD_ITARGETSR22                             (0x1858U)
#define CSL_GIC400_GICD_ITARGETSR23                             (0x185CU)
#define CSL_GIC400_GICD_ITARGETSR24                             (0x1860U)
#define CSL_GIC400_GICD_ITARGETSR25                             (0x1864U)
#define CSL_GIC400_GICD_ITARGETSR26                             (0x1868U)
#define CSL_GIC400_GICD_ITARGETSR27                             (0x186CU)
#define CSL_GIC400_GICD_ITARGETSR28                             (0x1870U)
#define CSL_GIC400_GICD_ITARGETSR29                             (0x1874U)
#define CSL_GIC400_GICD_ITARGETSR30                             (0x1878U)
#define CSL_GIC400_GICD_ITARGETSR31                             (0x187CU)
#define CSL_GIC400_GICD_ITARGETSR32                             (0x1880U)
#define CSL_GIC400_GICD_ITARGETSR33                             (0x1884U)
#define CSL_GIC400_GICD_ITARGETSR34                             (0x1888U)
#define CSL_GIC400_GICD_ITARGETSR35                             (0x188CU)
#define CSL_GIC400_GICD_ITARGETSR36                             (0x1890U)
#define CSL_GIC400_GICD_ITARGETSR37                             (0x1894U)
#define CSL_GIC400_GICD_ITARGETSR38                             (0x1898U)
#define CSL_GIC400_GICD_ITARGETSR39                             (0x189CU)
#define CSL_GIC400_GICD_ITARGETSR40                             (0x18A0U)
#define CSL_GIC400_GICD_ITARGETSR41                             (0x18A4U)
#define CSL_GIC400_GICD_ITARGETSR42                             (0x18A8U)
#define CSL_GIC400_GICD_ITARGETSR43                             (0x18ACU)
#define CSL_GIC400_GICD_ITARGETSR44                             (0x18B0U)
#define CSL_GIC400_GICD_ITARGETSR45                             (0x18B4U)
#define CSL_GIC400_GICD_ITARGETSR46                             (0x18B8U)
#define CSL_GIC400_GICD_ITARGETSR47                             (0x18BCU)
#define CSL_GIC400_GICD_ITARGETSR48                             (0x18C0U)
#define CSL_GIC400_GICD_ITARGETSR49                             (0x18C4U)
#define CSL_GIC400_GICD_ITARGETSR50                             (0x18C8U)
#define CSL_GIC400_GICD_ITARGETSR51                             (0x18CCU)
#define CSL_GIC400_GICD_ITARGETSR52                             (0x18D0U)
#define CSL_GIC400_GICD_ITARGETSR53                             (0x18D4U)
#define CSL_GIC400_GICD_ITARGETSR54                             (0x18D8U)
#define CSL_GIC400_GICD_ITARGETSR55                             (0x18DCU)
#define CSL_GIC400_GICD_ITARGETSR56                             (0x18E0U)
#define CSL_GIC400_GICD_ITARGETSR57                             (0x18E4U)
#define CSL_GIC400_GICD_ITARGETSR58                             (0x18E8U)
#define CSL_GIC400_GICD_ITARGETSR59                             (0x18ECU)
#define CSL_GIC400_GICD_ITARGETSR60                             (0x18F0U)
#define CSL_GIC400_GICD_ITARGETSR61                             (0x18F4U)
#define CSL_GIC400_GICD_ITARGETSR62                             (0x18F8U)
#define CSL_GIC400_GICD_ITARGETSR63                             (0x18FCU)
#define CSL_GIC400_GICD_ITARGETSR64                             (0x1900U)
#define CSL_GIC400_GICD_ITARGETSR65                             (0x1904U)
#define CSL_GIC400_GICD_ITARGETSR66                             (0x1908U)
#define CSL_GIC400_GICD_ITARGETSR67                             (0x190CU)
#define CSL_GIC400_GICD_ITARGETSR68                             (0x1910U)
#define CSL_GIC400_GICD_ITARGETSR69                             (0x1914U)
#define CSL_GIC400_GICD_ITARGETSR70                             (0x1918U)
#define CSL_GIC400_GICD_ITARGETSR71                             (0x191CU)
#define CSL_GIC400_GICD_ITARGETSR72                             (0x1920U)
#define CSL_GIC400_GICD_ITARGETSR73                             (0x1924U)
#define CSL_GIC400_GICD_ITARGETSR74                             (0x1928U)
#define CSL_GIC400_GICD_ITARGETSR75                             (0x192CU)
#define CSL_GIC400_GICD_ITARGETSR76                             (0x1930U)
#define CSL_GIC400_GICD_ITARGETSR77                             (0x1934U)
#define CSL_GIC400_GICD_ITARGETSR78                             (0x1938U)
#define CSL_GIC400_GICD_ITARGETSR79                             (0x193CU)
#define CSL_GIC400_GICD_ITARGETSR80                             (0x1940U)
#define CSL_GIC400_GICD_ITARGETSR81                             (0x1944U)
#define CSL_GIC400_GICD_ITARGETSR82                             (0x1948U)
#define CSL_GIC400_GICD_ITARGETSR83                             (0x194CU)
#define CSL_GIC400_GICD_ITARGETSR84                             (0x1950U)
#define CSL_GIC400_GICD_ITARGETSR85                             (0x1954U)
#define CSL_GIC400_GICD_ITARGETSR86                             (0x1958U)
#define CSL_GIC400_GICD_ITARGETSR87                             (0x195CU)
#define CSL_GIC400_GICD_ITARGETSR88                             (0x1960U)
#define CSL_GIC400_GICD_ITARGETSR89                             (0x1964U)
#define CSL_GIC400_GICD_ITARGETSR90                             (0x1968U)
#define CSL_GIC400_GICD_ITARGETSR91                             (0x196CU)
#define CSL_GIC400_GICD_ITARGETSR92                             (0x1970U)
#define CSL_GIC400_GICD_ITARGETSR93                             (0x1974U)
#define CSL_GIC400_GICD_ITARGETSR94                             (0x1978U)
#define CSL_GIC400_GICD_ITARGETSR95                             (0x197CU)
#define CSL_GIC400_GICD_ITARGETSR96                             (0x1980U)
#define CSL_GIC400_GICD_ITARGETSR97                             (0x1984U)
#define CSL_GIC400_GICD_ITARGETSR98                             (0x1988U)
#define CSL_GIC400_GICD_ITARGETSR99                             (0x198CU)
#define CSL_GIC400_GICD_ITARGETSR100                            (0x1990U)
#define CSL_GIC400_GICD_ITARGETSR101                            (0x1994U)
#define CSL_GIC400_GICD_ITARGETSR102                            (0x1998U)
#define CSL_GIC400_GICD_ITARGETSR103                            (0x199CU)
#define CSL_GIC400_GICD_ITARGETSR104                            (0x19A0U)
#define CSL_GIC400_GICD_ITARGETSR105                            (0x19A4U)
#define CSL_GIC400_GICD_ITARGETSR106                            (0x19A8U)
#define CSL_GIC400_GICD_ITARGETSR107                            (0x19ACU)
#define CSL_GIC400_GICD_ITARGETSR108                            (0x19B0U)
#define CSL_GIC400_GICD_ITARGETSR109                            (0x19B4U)
#define CSL_GIC400_GICD_ITARGETSR110                            (0x19B8U)
#define CSL_GIC400_GICD_ITARGETSR111                            (0x19BCU)
#define CSL_GIC400_GICD_ITARGETSR112                            (0x19C0U)
#define CSL_GIC400_GICD_ITARGETSR113                            (0x19C4U)
#define CSL_GIC400_GICD_ITARGETSR114                            (0x19C8U)
#define CSL_GIC400_GICD_ITARGETSR115                            (0x19CCU)
#define CSL_GIC400_GICD_ITARGETSR116                            (0x19D0U)
#define CSL_GIC400_GICD_ITARGETSR117                            (0x19D4U)
#define CSL_GIC400_GICD_ITARGETSR118                            (0x19D8U)
#define CSL_GIC400_GICD_ITARGETSR119                            (0x19DCU)
#define CSL_GIC400_GICD_ITARGETSR120                            (0x19E0U)
#define CSL_GIC400_GICD_ITARGETSR121                            (0x19E4U)
#define CSL_GIC400_GICD_ITARGETSR122                            (0x19E8U)
#define CSL_GIC400_GICD_ITARGETSR123                            (0x19ECU)
#define CSL_GIC400_GICD_ITARGETSR124                            (0x19F0U)
#define CSL_GIC400_GICD_ITARGETSR125                            (0x19F4U)
#define CSL_GIC400_GICD_ITARGETSR126                            (0x19F8U)
#define CSL_GIC400_GICD_ITARGETSR127                            (0x19FCU)
#define CSL_GIC400_GICD_ICFGR0                                  (0x1C00U)
#define CSL_GIC400_GICD_ICFGR1                                  (0x1C04U)
#define CSL_GIC400_GICD_ICFGR2                                  (0x1C08U)
#define CSL_GIC400_GICD_ICFGR3                                  (0x1C0CU)
#define CSL_GIC400_GICD_ICFGR4                                  (0x1C10U)
#define CSL_GIC400_GICD_ICFGR5                                  (0x1C14U)
#define CSL_GIC400_GICD_ICFGR6                                  (0x1C18U)
#define CSL_GIC400_GICD_ICFGR7                                  (0x1C1CU)
#define CSL_GIC400_GICD_ICFGR8                                  (0x1C20U)
#define CSL_GIC400_GICD_ICFGR9                                  (0x1C24U)
#define CSL_GIC400_GICD_ICFGR10                                 (0x1C28U)
#define CSL_GIC400_GICD_ICFGR11                                 (0x1C2CU)
#define CSL_GIC400_GICD_ICFGR12                                 (0x1C30U)
#define CSL_GIC400_GICD_ICFGR13                                 (0x1C34U)
#define CSL_GIC400_GICD_ICFGR14                                 (0x1C38U)
#define CSL_GIC400_GICD_ICFGR15                                 (0x1C3CU)
#define CSL_GIC400_GICD_ICFGR16                                 (0x1C40U)
#define CSL_GIC400_GICD_ICFGR17                                 (0x1C44U)
#define CSL_GIC400_GICD_ICFGR18                                 (0x1C48U)
#define CSL_GIC400_GICD_ICFGR19                                 (0x1C4CU)
#define CSL_GIC400_GICD_ICFGR20                                 (0x1C50U)
#define CSL_GIC400_GICD_ICFGR21                                 (0x1C54U)
#define CSL_GIC400_GICD_ICFGR22                                 (0x1C58U)
#define CSL_GIC400_GICD_ICFGR23                                 (0x1C5CU)
#define CSL_GIC400_GICD_ICFGR24                                 (0x1C60U)
#define CSL_GIC400_GICD_ICFGR25                                 (0x1C64U)
#define CSL_GIC400_GICD_ICFGR26                                 (0x1C68U)
#define CSL_GIC400_GICD_ICFGR27                                 (0x1C6CU)
#define CSL_GIC400_GICD_ICFGR28                                 (0x1C70U)
#define CSL_GIC400_GICD_ICFGR29                                 (0x1C74U)
#define CSL_GIC400_GICD_ICFGR30                                 (0x1C78U)
#define CSL_GIC400_GICD_ICFGR31                                 (0x1C7CU)
#define CSL_GIC400_GICD_PPISR                                   (0x1D00U)
#define CSL_GIC400_GICD_SPISR0                                  (0x1D04U)
#define CSL_GIC400_GICD_SPISR1                                  (0x1D08U)
#define CSL_GIC400_GICD_SPISR2                                  (0x1D0CU)
#define CSL_GIC400_GICD_SPISR3                                  (0x1D10U)
#define CSL_GIC400_GICD_SPISR4                                  (0x1D14U)
#define CSL_GIC400_GICD_SPISR5                                  (0x1D18U)
#define CSL_GIC400_GICD_SPISR6                                  (0x1D1CU)
#define CSL_GIC400_GICD_SPISR7                                  (0x1D20U)
#define CSL_GIC400_GICD_SPISR8                                  (0x1D24U)
#define CSL_GIC400_GICD_SPISR9                                  (0x1D28U)
#define CSL_GIC400_GICD_SPISR10                                 (0x1D2CU)
#define CSL_GIC400_GICD_SPISR11                                 (0x1D30U)
#define CSL_GIC400_GICD_SPISR12                                 (0x1D34U)
#define CSL_GIC400_GICD_SPISR13                                 (0x1D38U)
#define CSL_GIC400_GICD_SPISR14                                 (0x1D3CU)
#define CSL_GIC400_GICD_SGIR                                    (0x1F00U)
#define CSL_GIC400_GICD_CPENDSGIR0                              (0x1F10U)
#define CSL_GIC400_GICD_CPENDSGIR1                              (0x1F14U)
#define CSL_GIC400_GICD_CPENDSGIR2                              (0x1F18U)
#define CSL_GIC400_GICD_CPENDSGIR3                              (0x1F1CU)
#define CSL_GIC400_GICD_SPENDSGIR0                              (0x1F20U)
#define CSL_GIC400_GICD_SPENDSGIR1                              (0x1F24U)
#define CSL_GIC400_GICD_SPENDSGIR2                              (0x1F28U)
#define CSL_GIC400_GICD_SPENDSGIR3                              (0x1F2CU)
#define CSL_GIC400_GICD_PIDR4                                   (0x1FD0U)
#define CSL_GIC400_GICD_PIDR5                                   (0x1FD4U)
#define CSL_GIC400_GICD_PIDR6                                   (0x1FD8U)
#define CSL_GIC400_GICD_PIDR7                                   (0x1FDCU)
#define CSL_GIC400_GICD_PIDR0                                   (0x1FE0U)
#define CSL_GIC400_GICD_PIDR1                                   (0x1FE4U)
#define CSL_GIC400_GICD_PIDR2                                   (0x1FE8U)
#define CSL_GIC400_GICD_PIDR3                                   (0x1FECU)
#define CSL_GIC400_GICD_CIDR0                                   (0x1FF0U)
#define CSL_GIC400_GICD_CIDR1                                   (0x1FF4U)
#define CSL_GIC400_GICD_CIDR2                                   (0x1FF8U)
#define CSL_GIC400_GICD_CIDR3                                   (0x1FFCU)
#define CSL_GIC400_GICC_CTLR                                    (0x2000U)
#define CSL_GIC400_GICC_PMR                                     (0x2004U)
#define CSL_GIC400_GICC_BPR                                     (0x2008U)
#define CSL_GIC400_GICC_IAR                                     (0x200CU)
#define CSL_GIC400_GICC_EOIR                                    (0x2010U)
#define CSL_GIC400_GICC_RPR                                     (0x2014U)
#define CSL_GIC400_GICC_HPPIR                                   (0x2018U)
#define CSL_GIC400_GICC_ABPR                                    (0x201CU)
#define CSL_GIC400_GICC_AIAR                                    (0x2020U)
#define CSL_GIC400_GICC_AEOIR                                   (0x2024U)
#define CSL_GIC400_GICC_AHPPIR                                  (0x2028U)
#define CSL_GIC400_GICC_APR0                                    (0x20D0U)
#define CSL_GIC400_GICC_NSAPR0                                  (0x20E0U)
#define CSL_GIC400_GICC_IIDR                                    (0x20FCU)
#define CSL_GIC400_GICC_DIR                                     (0x3000U)
#define CSL_GIC400_GICH_HCR                                     (0x4000U)
#define CSL_GIC400_GICH_VTR                                     (0x4004U)
#define CSL_GIC400_GICH_VMCR                                    (0x4008U)
#define CSL_GIC400_GICH_MISR                                    (0x4010U)
#define CSL_GIC400_GICH_EISR0                                   (0x4020U)
#define CSL_GIC400_GICH_ELSR0                                   (0x4030U)
#define CSL_GIC400_GICH_APR0                                    (0x40F0U)
#define CSL_GIC400_GICH_LR0                                     (0x4100U)
#define CSL_GIC400_GICH_LR1                                     (0x4104U)
#define CSL_GIC400_GICH_LR2                                     (0x4108U)
#define CSL_GIC400_GICH_LR3                                     (0x410CU)
#define CSL_GIC400_GICV_CTLR                                    (0x6000U)
#define CSL_GIC400_GICV_PMR                                     (0x6004U)
#define CSL_GIC400_GICV_BPR                                     (0x6008U)
#define CSL_GIC400_GICV_IAR                                     (0x600CU)
#define CSL_GIC400_GICV_EOIR                                    (0x6010U)
#define CSL_GIC400_GICV_RPR                                     (0x6014U)
#define CSL_GIC400_GICV_HPPIR                                   (0x6018U)
#define CSL_GIC400_GICV_ABPR                                    (0x601CU)
#define CSL_GIC400_GICV_AIAR                                    (0x6020U)
#define CSL_GIC400_GICV_AEOIR                                   (0x6024U)
#define CSL_GIC400_GICV_AHPPIR                                  (0x6028U)
#define CSL_GIC400_GICV_APR0                                    (0x60D0U)
#define CSL_GIC400_GICV_IIDR                                    (0x60FCU)
#define CSL_GIC400_GICV_DIR                                     (0x7000U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* GICD_CTLR */

#define CSL_GIC400_GICD_CTLR_GICD_CTLR_MASK                     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_CTLR_GICD_CTLR_SHIFT                    (0x00000000U)
#define CSL_GIC400_GICD_CTLR_GICD_CTLR_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_CTLR_GICD_CTLR_MAX                      (0xffffffffU)

#define CSL_GIC400_GICD_CTLR_RESETVAL                           (0x00000000U)

/* GICD_TYPER */

#define CSL_GIC400_GICD_TYPER_GICD_TYPER_MASK                   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_TYPER_GICD_TYPER_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICD_TYPER_GICD_TYPER_RESETVAL               (0x00000000U)
#define CSL_GIC400_GICD_TYPER_GICD_TYPER_MAX                    (0xffffffffU)

#define CSL_GIC400_GICD_TYPER_RESETVAL                          (0x00000000U)

/* GICD_IIDR */

#define CSL_GIC400_GICD_IIDR_PRODUCDID_MASK                     (0xFF000000U)
#define CSL_GIC400_GICD_IIDR_PRODUCDID_SHIFT                    (0x00000018U)
#define CSL_GIC400_GICD_IIDR_PRODUCDID_RESETVAL                 (0x00000002U)
#define CSL_GIC400_GICD_IIDR_PRODUCDID_MAX                      (0x000000ffU)

#define CSL_GIC400_GICD_IIDR_VARIANT_MASK                       (0x000F0000U)
#define CSL_GIC400_GICD_IIDR_VARIANT_SHIFT                      (0x00000010U)
#define CSL_GIC400_GICD_IIDR_VARIANT_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICD_IIDR_VARIANT_MAX                        (0x0000000fU)

#define CSL_GIC400_GICD_IIDR_REVISION_MASK                      (0x0000F000U)
#define CSL_GIC400_GICD_IIDR_REVISION_SHIFT                     (0x0000000CU)
#define CSL_GIC400_GICD_IIDR_REVISION_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_IIDR_REVISION_MAX                       (0x0000000fU)

#define CSL_GIC400_GICD_IIDR_IMPLEMENTER_MASK                   (0x00000FFFU)
#define CSL_GIC400_GICD_IIDR_IMPLEMENTER_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICD_IIDR_IMPLEMENTER_RESETVAL               (0x0000043bU)
#define CSL_GIC400_GICD_IIDR_IMPLEMENTER_MAX                    (0x00000fffU)

#define CSL_GIC400_GICD_IIDR_RESETVAL                           (0x0200043bU)

/* GICD_IGROUPR0 */

#define CSL_GIC400_GICD_IGROUPR0_GICD_IGROUPR0_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR0_GICD_IGROUPR0_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR0_GICD_IGROUPR0_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR0_GICD_IGROUPR0_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR0_RESETVAL                       (0x00000000U)

/* GICD_IGROUPR1 */

#define CSL_GIC400_GICD_IGROUPR1_GICD_IGROUPR1_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR1_GICD_IGROUPR1_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR1_GICD_IGROUPR1_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR1_GICD_IGROUPR1_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR1_RESETVAL                       (0x00000000U)

/* GICD_IGROUPR2 */

#define CSL_GIC400_GICD_IGROUPR2_GICD_IGROUPR2_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR2_GICD_IGROUPR2_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR2_GICD_IGROUPR2_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR2_GICD_IGROUPR2_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR2_RESETVAL                       (0x00000000U)

/* GICD_IGROUPR3 */

#define CSL_GIC400_GICD_IGROUPR3_GICD_IGROUPR3_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR3_GICD_IGROUPR3_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR3_GICD_IGROUPR3_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR3_GICD_IGROUPR3_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR3_RESETVAL                       (0x00000000U)

/* GICD_IGROUPR4 */

#define CSL_GIC400_GICD_IGROUPR4_GICD_IGROUPR4_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR4_GICD_IGROUPR4_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR4_GICD_IGROUPR4_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR4_GICD_IGROUPR4_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR4_RESETVAL                       (0x00000000U)

/* GICD_IGROUPR5 */

#define CSL_GIC400_GICD_IGROUPR5_GICD_IGROUPR5_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR5_GICD_IGROUPR5_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR5_GICD_IGROUPR5_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR5_GICD_IGROUPR5_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR5_RESETVAL                       (0x00000000U)

/* GICD_IGROUPR6 */

#define CSL_GIC400_GICD_IGROUPR6_GICD_IGROUPR6_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR6_GICD_IGROUPR6_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR6_GICD_IGROUPR6_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR6_GICD_IGROUPR6_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR6_RESETVAL                       (0x00000000U)

/* GICD_IGROUPR7 */

#define CSL_GIC400_GICD_IGROUPR7_GICD_IGROUPR7_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR7_GICD_IGROUPR7_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR7_GICD_IGROUPR7_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR7_GICD_IGROUPR7_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR7_RESETVAL                       (0x00000000U)

/* GICD_IGROUPR8 */

#define CSL_GIC400_GICD_IGROUPR8_GICD_IGROUPR8_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR8_GICD_IGROUPR8_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR8_GICD_IGROUPR8_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR8_GICD_IGROUPR8_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR8_RESETVAL                       (0x00000000U)

/* GICD_IGROUPR9 */

#define CSL_GIC400_GICD_IGROUPR9_GICD_IGROUPR9_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR9_GICD_IGROUPR9_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR9_GICD_IGROUPR9_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR9_GICD_IGROUPR9_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR9_RESETVAL                       (0x00000000U)

/* GICD_IGROUPR10 */

#define CSL_GIC400_GICD_IGROUPR10_GICD_IGROUPR10_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR10_GICD_IGROUPR10_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR10_GICD_IGROUPR10_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR10_GICD_IGROUPR10_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR10_RESETVAL                      (0x00000000U)

/* GICD_IGROUPR11 */

#define CSL_GIC400_GICD_IGROUPR11_GICD_IGROUPR11_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR11_GICD_IGROUPR11_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR11_GICD_IGROUPR11_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR11_GICD_IGROUPR11_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR11_RESETVAL                      (0x00000000U)

/* GICD_IGROUPR12 */

#define CSL_GIC400_GICD_IGROUPR12_GICD_IGROUPR12_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR12_GICD_IGROUPR12_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR12_GICD_IGROUPR12_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR12_GICD_IGROUPR12_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR12_RESETVAL                      (0x00000000U)

/* GICD_IGROUPR13 */

#define CSL_GIC400_GICD_IGROUPR13_GICD_IGROUPR13_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR13_GICD_IGROUPR13_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR13_GICD_IGROUPR13_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR13_GICD_IGROUPR13_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR13_RESETVAL                      (0x00000000U)

/* GICD_IGROUPR14 */

#define CSL_GIC400_GICD_IGROUPR14_GICD_IGROUPR14_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR14_GICD_IGROUPR14_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR14_GICD_IGROUPR14_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR14_GICD_IGROUPR14_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR14_RESETVAL                      (0x00000000U)

/* GICD_IGROUPR15 */

#define CSL_GIC400_GICD_IGROUPR15_GICD_IGROUPR15_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IGROUPR15_GICD_IGROUPR15_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR15_GICD_IGROUPR15_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_IGROUPR15_GICD_IGROUPR15_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_IGROUPR15_RESETVAL                      (0x00000000U)

/* GICD_ISENABLER0 */

#define CSL_GIC400_GICD_ISENABLER0_GICD_ISENABLER0_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER0_GICD_ISENABLER0_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER0_GICD_ISENABLER0_RESETVAL     (0x0000ffffU)
#define CSL_GIC400_GICD_ISENABLER0_GICD_ISENABLER0_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER0_RESETVAL                     (0x0000ffffU)

/* GICD_ISENABLER1 */

#define CSL_GIC400_GICD_ISENABLER1_GICD_ISENABLER1_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER1_GICD_ISENABLER1_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER1_GICD_ISENABLER1_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER1_GICD_ISENABLER1_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER1_RESETVAL                     (0x00000000U)

/* GICD_ISENABLER2 */

#define CSL_GIC400_GICD_ISENABLER2_GICD_ISENABLER2_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER2_GICD_ISENABLER2_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER2_GICD_ISENABLER2_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER2_GICD_ISENABLER2_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER2_RESETVAL                     (0x00000000U)

/* GICD_ISENABLER3 */

#define CSL_GIC400_GICD_ISENABLER3_GICD_ISENABLER3_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER3_GICD_ISENABLER3_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER3_GICD_ISENABLER3_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER3_GICD_ISENABLER3_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER3_RESETVAL                     (0x00000000U)

/* GICD_ISENABLER4 */

#define CSL_GIC400_GICD_ISENABLER4_GICD_ISENABLER4_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER4_GICD_ISENABLER4_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER4_GICD_ISENABLER4_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER4_GICD_ISENABLER4_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER4_RESETVAL                     (0x00000000U)

/* GICD_ISENABLER5 */

#define CSL_GIC400_GICD_ISENABLER5_GICD_ISENABLER5_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER5_GICD_ISENABLER5_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER5_GICD_ISENABLER5_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER5_GICD_ISENABLER5_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER5_RESETVAL                     (0x00000000U)

/* GICD_ISENABLER6 */

#define CSL_GIC400_GICD_ISENABLER6_GICD_ISENABLER6_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER6_GICD_ISENABLER6_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER6_GICD_ISENABLER6_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER6_GICD_ISENABLER6_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER6_RESETVAL                     (0x00000000U)

/* GICD_ISENABLER7 */

#define CSL_GIC400_GICD_ISENABLER7_GICD_ISENABLER7_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER7_GICD_ISENABLER7_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER7_GICD_ISENABLER7_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER7_GICD_ISENABLER7_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER7_RESETVAL                     (0x00000000U)

/* GICD_ISENABLER8 */

#define CSL_GIC400_GICD_ISENABLER8_GICD_ISENABLER8_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER8_GICD_ISENABLER8_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER8_GICD_ISENABLER8_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER8_GICD_ISENABLER8_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER8_RESETVAL                     (0x00000000U)

/* GICD_ISENABLER9 */

#define CSL_GIC400_GICD_ISENABLER9_GICD_ISENABLER9_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER9_GICD_ISENABLER9_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER9_GICD_ISENABLER9_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER9_GICD_ISENABLER9_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER9_RESETVAL                     (0x00000000U)

/* GICD_ISENABLER10 */

#define CSL_GIC400_GICD_ISENABLER10_GICD_ISENABLER10_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER10_GICD_ISENABLER10_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER10_GICD_ISENABLER10_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER10_GICD_ISENABLER10_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER10_RESETVAL                    (0x00000000U)

/* GICD_ISENABLER11 */

#define CSL_GIC400_GICD_ISENABLER11_GICD_ISENABLER11_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER11_GICD_ISENABLER11_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER11_GICD_ISENABLER11_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER11_GICD_ISENABLER11_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER11_RESETVAL                    (0x00000000U)

/* GICD_ISENABLER12 */

#define CSL_GIC400_GICD_ISENABLER12_GICD_ISENABLER12_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER12_GICD_ISENABLER12_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER12_GICD_ISENABLER12_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER12_GICD_ISENABLER12_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER12_RESETVAL                    (0x00000000U)

/* GICD_ISENABLER13 */

#define CSL_GIC400_GICD_ISENABLER13_GICD_ISENABLER13_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER13_GICD_ISENABLER13_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER13_GICD_ISENABLER13_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER13_GICD_ISENABLER13_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER13_RESETVAL                    (0x00000000U)

/* GICD_ISENABLER14 */

#define CSL_GIC400_GICD_ISENABLER14_GICD_ISENABLER14_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER14_GICD_ISENABLER14_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER14_GICD_ISENABLER14_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER14_GICD_ISENABLER14_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER14_RESETVAL                    (0x00000000U)

/* GICD_ISENABLER15 */

#define CSL_GIC400_GICD_ISENABLER15_GICD_ISENABLER15_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISENABLER15_GICD_ISENABLER15_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER15_GICD_ISENABLER15_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ISENABLER15_GICD_ISENABLER15_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ISENABLER15_RESETVAL                    (0x00000000U)

/* GICD_ICENABLER0 */

#define CSL_GIC400_GICD_ICENABLER0_GICD_ICENABLER0_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER0_GICD_ICENABLER0_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER0_GICD_ICENABLER0_RESETVAL     (0x0000ffffU)
#define CSL_GIC400_GICD_ICENABLER0_GICD_ICENABLER0_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER0_RESETVAL                     (0x0000ffffU)

/* GICD_ICENABLER1 */

#define CSL_GIC400_GICD_ICENABLER1_GICD_ICENABLER1_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER1_GICD_ICENABLER1_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER1_GICD_ICENABLER1_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER1_GICD_ICENABLER1_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER1_RESETVAL                     (0x00000000U)

/* GICD_ICENABLER2 */

#define CSL_GIC400_GICD_ICENABLER2_GICD_ICENABLER2_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER2_GICD_ICENABLER2_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER2_GICD_ICENABLER2_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER2_GICD_ICENABLER2_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER2_RESETVAL                     (0x00000000U)

/* GICD_ICENABLER3 */

#define CSL_GIC400_GICD_ICENABLER3_GICD_ICENABLER3_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER3_GICD_ICENABLER3_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER3_GICD_ICENABLER3_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER3_GICD_ICENABLER3_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER3_RESETVAL                     (0x00000000U)

/* GICD_ICENABLER4 */

#define CSL_GIC400_GICD_ICENABLER4_GICD_ICENABLER4_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER4_GICD_ICENABLER4_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER4_GICD_ICENABLER4_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER4_GICD_ICENABLER4_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER4_RESETVAL                     (0x00000000U)

/* GICD_ICENABLER5 */

#define CSL_GIC400_GICD_ICENABLER5_GICD_ICENABLER5_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER5_GICD_ICENABLER5_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER5_GICD_ICENABLER5_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER5_GICD_ICENABLER5_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER5_RESETVAL                     (0x00000000U)

/* GICD_ICENABLER6 */

#define CSL_GIC400_GICD_ICENABLER6_GICD_ICENABLER6_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER6_GICD_ICENABLER6_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER6_GICD_ICENABLER6_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER6_GICD_ICENABLER6_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER6_RESETVAL                     (0x00000000U)

/* GICD_ICENABLER7 */

#define CSL_GIC400_GICD_ICENABLER7_GICD_ICENABLER7_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER7_GICD_ICENABLER7_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER7_GICD_ICENABLER7_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER7_GICD_ICENABLER7_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER7_RESETVAL                     (0x00000000U)

/* GICD_ICENABLER8 */

#define CSL_GIC400_GICD_ICENABLER8_GICD_ICENABLER8_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER8_GICD_ICENABLER8_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER8_GICD_ICENABLER8_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER8_GICD_ICENABLER8_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER8_RESETVAL                     (0x00000000U)

/* GICD_ICENABLER9 */

#define CSL_GIC400_GICD_ICENABLER9_GICD_ICENABLER9_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER9_GICD_ICENABLER9_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER9_GICD_ICENABLER9_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER9_GICD_ICENABLER9_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER9_RESETVAL                     (0x00000000U)

/* GICD_ICENABLER10 */

#define CSL_GIC400_GICD_ICENABLER10_GICD_ICENABLER10_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER10_GICD_ICENABLER10_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER10_GICD_ICENABLER10_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER10_GICD_ICENABLER10_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER10_RESETVAL                    (0x00000000U)

/* GICD_ICENABLER11 */

#define CSL_GIC400_GICD_ICENABLER11_GICD_ICENABLER11_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER11_GICD_ICENABLER11_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER11_GICD_ICENABLER11_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER11_GICD_ICENABLER11_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER11_RESETVAL                    (0x00000000U)

/* GICD_ICENABLER12 */

#define CSL_GIC400_GICD_ICENABLER12_GICD_ICENABLER12_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER12_GICD_ICENABLER12_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER12_GICD_ICENABLER12_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER12_GICD_ICENABLER12_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER12_RESETVAL                    (0x00000000U)

/* GICD_ICENABLER13 */

#define CSL_GIC400_GICD_ICENABLER13_GICD_ICENABLER13_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER13_GICD_ICENABLER13_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER13_GICD_ICENABLER13_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER13_GICD_ICENABLER13_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER13_RESETVAL                    (0x00000000U)

/* GICD_ICENABLER14 */

#define CSL_GIC400_GICD_ICENABLER14_GICD_ICENABLER14_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER14_GICD_ICENABLER14_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER14_GICD_ICENABLER14_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER14_GICD_ICENABLER14_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER14_RESETVAL                    (0x00000000U)

/* GICD_ICENABLER15 */

#define CSL_GIC400_GICD_ICENABLER15_GICD_ICENABLER15_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICENABLER15_GICD_ICENABLER15_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER15_GICD_ICENABLER15_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ICENABLER15_GICD_ICENABLER15_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ICENABLER15_RESETVAL                    (0x00000000U)

/* GICD_ISPENDR0 */

#define CSL_GIC400_GICD_ISPENDR0_GICD_ISPENDR0_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR0_GICD_ISPENDR0_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR0_GICD_ISPENDR0_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR0_GICD_ISPENDR0_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR0_RESETVAL                       (0x00000000U)

/* GICD_ISPENDR1 */

#define CSL_GIC400_GICD_ISPENDR1_GICD_ISPENDR1_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR1_GICD_ISPENDR1_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR1_GICD_ISPENDR1_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR1_GICD_ISPENDR1_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR1_RESETVAL                       (0x00000000U)

/* GICD_ISPENDR2 */

#define CSL_GIC400_GICD_ISPENDR2_GICD_ISPENDR2_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR2_GICD_ISPENDR2_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR2_GICD_ISPENDR2_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR2_GICD_ISPENDR2_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR2_RESETVAL                       (0x00000000U)

/* GICD_ISPENDR3 */

#define CSL_GIC400_GICD_ISPENDR3_GICD_ISPENDR3_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR3_GICD_ISPENDR3_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR3_GICD_ISPENDR3_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR3_GICD_ISPENDR3_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR3_RESETVAL                       (0x00000000U)

/* GICD_ISPENDR4 */

#define CSL_GIC400_GICD_ISPENDR4_GICD_ISPENDR4_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR4_GICD_ISPENDR4_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR4_GICD_ISPENDR4_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR4_GICD_ISPENDR4_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR4_RESETVAL                       (0x00000000U)

/* GICD_ISPENDR5 */

#define CSL_GIC400_GICD_ISPENDR5_GICD_ISPENDR5_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR5_GICD_ISPENDR5_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR5_GICD_ISPENDR5_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR5_GICD_ISPENDR5_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR5_RESETVAL                       (0x00000000U)

/* GICD_ISPENDR6 */

#define CSL_GIC400_GICD_ISPENDR6_GICD_ISPENDR6_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR6_GICD_ISPENDR6_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR6_GICD_ISPENDR6_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR6_GICD_ISPENDR6_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR6_RESETVAL                       (0x00000000U)

/* GICD_ISPENDR7 */

#define CSL_GIC400_GICD_ISPENDR7_GICD_ISPENDR7_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR7_GICD_ISPENDR7_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR7_GICD_ISPENDR7_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR7_GICD_ISPENDR7_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR7_RESETVAL                       (0x00000000U)

/* GICD_ISPENDR8 */

#define CSL_GIC400_GICD_ISPENDR8_GICD_ISPENDR8_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR8_GICD_ISPENDR8_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR8_GICD_ISPENDR8_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR8_GICD_ISPENDR8_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR8_RESETVAL                       (0x00000000U)

/* GICD_ISPENDR9 */

#define CSL_GIC400_GICD_ISPENDR9_GICD_ISPENDR9_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR9_GICD_ISPENDR9_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR9_GICD_ISPENDR9_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR9_GICD_ISPENDR9_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR9_RESETVAL                       (0x00000000U)

/* GICD_ISPENDR10 */

#define CSL_GIC400_GICD_ISPENDR10_GICD_ISPENDR10_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR10_GICD_ISPENDR10_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR10_GICD_ISPENDR10_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR10_GICD_ISPENDR10_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR10_RESETVAL                      (0x00000000U)

/* GICD_ISPENDR11 */

#define CSL_GIC400_GICD_ISPENDR11_GICD_ISPENDR11_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR11_GICD_ISPENDR11_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR11_GICD_ISPENDR11_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR11_GICD_ISPENDR11_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR11_RESETVAL                      (0x00000000U)

/* GICD_ISPENDR12 */

#define CSL_GIC400_GICD_ISPENDR12_GICD_ISPENDR12_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR12_GICD_ISPENDR12_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR12_GICD_ISPENDR12_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR12_GICD_ISPENDR12_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR12_RESETVAL                      (0x00000000U)

/* GICD_ISPENDR13 */

#define CSL_GIC400_GICD_ISPENDR13_GICD_ISPENDR13_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR13_GICD_ISPENDR13_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR13_GICD_ISPENDR13_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR13_GICD_ISPENDR13_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR13_RESETVAL                      (0x00000000U)

/* GICD_ISPENDR14 */

#define CSL_GIC400_GICD_ISPENDR14_GICD_ISPENDR14_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISPENDR14_GICD_ISPENDR14_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR14_GICD_ISPENDR14_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_ISPENDR14_GICD_ISPENDR14_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_ISPENDR14_RESETVAL                      (0x00000000U)

/* GICD_ISPENDR15 */

#define CSL_GIC400_GICD_ISPENDR15_RESETVAL                      (0x00000000U)

/* GICD_ICPENDR0 */

#define CSL_GIC400_GICD_ICPENDR0_GICD_ICPENDR0_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR0_GICD_ICPENDR0_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR0_GICD_ICPENDR0_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR0_GICD_ICPENDR0_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR0_RESETVAL                       (0x00000000U)

/* GICD_ICPENDR1 */

#define CSL_GIC400_GICD_ICPENDR1_GICD_ICPENDR1_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR1_GICD_ICPENDR1_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR1_GICD_ICPENDR1_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR1_GICD_ICPENDR1_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR1_RESETVAL                       (0x00000000U)

/* GICD_ICPENDR2 */

#define CSL_GIC400_GICD_ICPENDR2_GICD_ICPENDR2_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR2_GICD_ICPENDR2_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR2_GICD_ICPENDR2_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR2_GICD_ICPENDR2_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR2_RESETVAL                       (0x00000000U)

/* GICD_ICPENDR3 */

#define CSL_GIC400_GICD_ICPENDR3_GICD_ICPENDR3_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR3_GICD_ICPENDR3_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR3_GICD_ICPENDR3_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR3_GICD_ICPENDR3_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR3_RESETVAL                       (0x00000000U)

/* GICD_ICPENDR4 */

#define CSL_GIC400_GICD_ICPENDR4_GICD_ICPENDR4_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR4_GICD_ICPENDR4_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR4_GICD_ICPENDR4_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR4_GICD_ICPENDR4_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR4_RESETVAL                       (0x00000000U)

/* GICD_ICPENDR5 */

#define CSL_GIC400_GICD_ICPENDR5_GICD_ICPENDR5_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR5_GICD_ICPENDR5_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR5_GICD_ICPENDR5_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR5_GICD_ICPENDR5_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR5_RESETVAL                       (0x00000000U)

/* GICD_ICPENDR6 */

#define CSL_GIC400_GICD_ICPENDR6_GICD_ICPENDR6_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR6_GICD_ICPENDR6_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR6_GICD_ICPENDR6_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR6_GICD_ICPENDR6_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR6_RESETVAL                       (0x00000000U)

/* GICD_ICPENDR7 */

#define CSL_GIC400_GICD_ICPENDR7_GICD_ICPENDR7_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR7_GICD_ICPENDR7_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR7_GICD_ICPENDR7_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR7_GICD_ICPENDR7_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR7_RESETVAL                       (0x00000000U)

/* GICD_ICPENDR8 */

#define CSL_GIC400_GICD_ICPENDR8_GICD_ICPENDR8_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR8_GICD_ICPENDR8_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR8_GICD_ICPENDR8_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR8_GICD_ICPENDR8_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR8_RESETVAL                       (0x00000000U)

/* GICD_ICPENDR9 */

#define CSL_GIC400_GICD_ICPENDR9_GICD_ICPENDR9_MASK             (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR9_GICD_ICPENDR9_SHIFT            (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR9_GICD_ICPENDR9_RESETVAL         (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR9_GICD_ICPENDR9_MAX              (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR9_RESETVAL                       (0x00000000U)

/* GICD_ICPENDR10 */

#define CSL_GIC400_GICD_ICPENDR10_GICD_ICPENDR10_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR10_GICD_ICPENDR10_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR10_GICD_ICPENDR10_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR10_GICD_ICPENDR10_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR10_RESETVAL                      (0x00000000U)

/* GICD_ICPENDR11 */

#define CSL_GIC400_GICD_ICPENDR11_GICD_ICPENDR11_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR11_GICD_ICPENDR11_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR11_GICD_ICPENDR11_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR11_GICD_ICPENDR11_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR11_RESETVAL                      (0x00000000U)

/* GICD_ICPENDR12 */

#define CSL_GIC400_GICD_ICPENDR12_GICD_ICPENDR12_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR12_GICD_ICPENDR12_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR12_GICD_ICPENDR12_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR12_GICD_ICPENDR12_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR12_RESETVAL                      (0x00000000U)

/* GICD_ICPENDR13 */

#define CSL_GIC400_GICD_ICPENDR13_GICD_ICPENDR13_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR13_GICD_ICPENDR13_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR13_GICD_ICPENDR13_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR13_GICD_ICPENDR13_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR13_RESETVAL                      (0x00000000U)

/* GICD_ICPENDR14 */

#define CSL_GIC400_GICD_ICPENDR14_GICD_ICPENDR14_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR14_GICD_ICPENDR14_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR14_GICD_ICPENDR14_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR14_GICD_ICPENDR14_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR14_RESETVAL                      (0x00000000U)

/* GICD_ICPENDR15 */

#define CSL_GIC400_GICD_ICPENDR15_GICD_ICPENDR15_MASK           (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICPENDR15_GICD_ICPENDR15_SHIFT          (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR15_GICD_ICPENDR15_RESETVAL       (0x00000000U)
#define CSL_GIC400_GICD_ICPENDR15_GICD_ICPENDR15_MAX            (0xffffffffU)

#define CSL_GIC400_GICD_ICPENDR15_RESETVAL                      (0x00000000U)

/* GICD_ISACTIVER0 */

#define CSL_GIC400_GICD_ISACTIVER0_GICD_ISACTIVER0_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER0_GICD_ISACTIVER0_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER0_GICD_ISACTIVER0_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER0_GICD_ISACTIVER0_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER0_RESETVAL                     (0x00000000U)

/* GICD_ISACTIVER1 */

#define CSL_GIC400_GICD_ISACTIVER1_GICD_ISACTIVER1_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER1_GICD_ISACTIVER1_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER1_GICD_ISACTIVER1_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER1_GICD_ISACTIVER1_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER1_RESETVAL                     (0x00000000U)

/* GICD_ISACTIVER2 */

#define CSL_GIC400_GICD_ISACTIVER2_GICD_ISACTIVER2_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER2_GICD_ISACTIVER2_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER2_GICD_ISACTIVER2_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER2_GICD_ISACTIVER2_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER2_RESETVAL                     (0x00000000U)

/* GICD_ISACTIVER3 */

#define CSL_GIC400_GICD_ISACTIVER3_GICD_ISACTIVER3_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER3_GICD_ISACTIVER3_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER3_GICD_ISACTIVER3_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER3_GICD_ISACTIVER3_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER3_RESETVAL                     (0x00000000U)

/* GICD_ISACTIVER4 */

#define CSL_GIC400_GICD_ISACTIVER4_GICD_ISACTIVER4_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER4_GICD_ISACTIVER4_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER4_GICD_ISACTIVER4_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER4_GICD_ISACTIVER4_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER4_RESETVAL                     (0x00000000U)

/* GICD_ISACTIVER5 */

#define CSL_GIC400_GICD_ISACTIVER5_GICD_ISACTIVER5_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER5_GICD_ISACTIVER5_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER5_GICD_ISACTIVER5_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER5_GICD_ISACTIVER5_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER5_RESETVAL                     (0x00000000U)

/* GICD_ISACTIVER6 */

#define CSL_GIC400_GICD_ISACTIVER6_GICD_ISACTIVER6_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER6_GICD_ISACTIVER6_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER6_GICD_ISACTIVER6_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER6_GICD_ISACTIVER6_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER6_RESETVAL                     (0x00000000U)

/* GICD_ISACTIVER7 */

#define CSL_GIC400_GICD_ISACTIVER7_GICD_ISACTIVER7_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER7_GICD_ISACTIVER7_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER7_GICD_ISACTIVER7_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER7_GICD_ISACTIVER7_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER7_RESETVAL                     (0x00000000U)

/* GICD_ISACTIVER8 */

#define CSL_GIC400_GICD_ISACTIVER8_GICD_ISACTIVER8_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER8_GICD_ISACTIVER8_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER8_GICD_ISACTIVER8_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER8_GICD_ISACTIVER8_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER8_RESETVAL                     (0x00000000U)

/* GICD_ISACTIVER9 */

#define CSL_GIC400_GICD_ISACTIVER9_GICD_ISACTIVER9_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER9_GICD_ISACTIVER9_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER9_GICD_ISACTIVER9_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER9_GICD_ISACTIVER9_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER9_RESETVAL                     (0x00000000U)

/* GICD_ISACTIVER10 */

#define CSL_GIC400_GICD_ISACTIVER10_GICD_ISACTIVER10_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER10_GICD_ISACTIVER10_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER10_GICD_ISACTIVER10_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER10_GICD_ISACTIVER10_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER10_RESETVAL                    (0x00000000U)

/* GICD_ISACTIVER11 */

#define CSL_GIC400_GICD_ISACTIVER11_GICD_ISACTIVER11_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER11_GICD_ISACTIVER11_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER11_GICD_ISACTIVER11_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER11_GICD_ISACTIVER11_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER11_RESETVAL                    (0x00000000U)

/* GICD_ISACTIVER12 */

#define CSL_GIC400_GICD_ISACTIVER12_GICD_ISACTIVER12_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER12_GICD_ISACTIVER12_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER12_GICD_ISACTIVER12_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER12_GICD_ISACTIVER12_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER12_RESETVAL                    (0x00000000U)

/* GICD_ISACTIVER13 */

#define CSL_GIC400_GICD_ISACTIVER13_GICD_ISACTIVER13_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER13_GICD_ISACTIVER13_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER13_GICD_ISACTIVER13_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER13_GICD_ISACTIVER13_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER13_RESETVAL                    (0x00000000U)

/* GICD_ISACTIVER14 */

#define CSL_GIC400_GICD_ISACTIVER14_GICD_ISACTIVER14_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER14_GICD_ISACTIVER14_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER14_GICD_ISACTIVER14_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER14_GICD_ISACTIVER14_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER14_RESETVAL                    (0x00000000U)

/* GICD_ISACTIVER15 */

#define CSL_GIC400_GICD_ISACTIVER15_GICD_ISACTIVER15_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ISACTIVER15_GICD_ISACTIVER15_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER15_GICD_ISACTIVER15_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ISACTIVER15_GICD_ISACTIVER15_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ISACTIVER15_RESETVAL                    (0x00000000U)

/* GICD_ICACTIVER0 */

#define CSL_GIC400_GICD_ICACTIVER0_GICD_ICACTIVER0_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER0_GICD_ICACTIVER0_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER0_GICD_ICACTIVER0_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER0_GICD_ICACTIVER0_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER0_RESETVAL                     (0x00000000U)

/* GICD_ICACTIVER1 */

#define CSL_GIC400_GICD_ICACTIVER1_GICD_ICACTIVER1_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER1_GICD_ICACTIVER1_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER1_GICD_ICACTIVER1_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER1_GICD_ICACTIVER1_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER1_RESETVAL                     (0x00000000U)

/* GICD_ICACTIVER2 */

#define CSL_GIC400_GICD_ICACTIVER2_GICD_ICACTIVER2_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER2_GICD_ICACTIVER2_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER2_GICD_ICACTIVER2_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER2_GICD_ICACTIVER2_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER2_RESETVAL                     (0x00000000U)

/* GICD_ICACTIVER3 */

#define CSL_GIC400_GICD_ICACTIVER3_GICD_ICACTIVER3_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER3_GICD_ICACTIVER3_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER3_GICD_ICACTIVER3_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER3_GICD_ICACTIVER3_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER3_RESETVAL                     (0x00000000U)

/* GICD_ICACTIVER4 */

#define CSL_GIC400_GICD_ICACTIVER4_GICD_ICACTIVER4_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER4_GICD_ICACTIVER4_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER4_GICD_ICACTIVER4_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER4_GICD_ICACTIVER4_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER4_RESETVAL                     (0x00000000U)

/* GICD_ICACTIVER5 */

#define CSL_GIC400_GICD_ICACTIVER5_GICD_ICACTIVER5_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER5_GICD_ICACTIVER5_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER5_GICD_ICACTIVER5_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER5_GICD_ICACTIVER5_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER5_RESETVAL                     (0x00000000U)

/* GICD_ICACTIVER6 */

#define CSL_GIC400_GICD_ICACTIVER6_GICD_ICACTIVER6_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER6_GICD_ICACTIVER6_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER6_GICD_ICACTIVER6_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER6_GICD_ICACTIVER6_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER6_RESETVAL                     (0x00000000U)

/* GICD_ICACTIVER7 */

#define CSL_GIC400_GICD_ICACTIVER7_GICD_ICACTIVER7_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER7_GICD_ICACTIVER7_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER7_GICD_ICACTIVER7_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER7_GICD_ICACTIVER7_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER7_RESETVAL                     (0x00000000U)

/* GICD_ICACTIVER8 */

#define CSL_GIC400_GICD_ICACTIVER8_GICD_ICACTIVER8_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER8_GICD_ICACTIVER8_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER8_GICD_ICACTIVER8_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER8_GICD_ICACTIVER8_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER8_RESETVAL                     (0x00000000U)

/* GICD_ICACTIVER9 */

#define CSL_GIC400_GICD_ICACTIVER9_GICD_ICACTIVER9_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER9_GICD_ICACTIVER9_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER9_GICD_ICACTIVER9_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER9_GICD_ICACTIVER9_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER9_RESETVAL                     (0x00000000U)

/* GICD_ICACTIVER10 */

#define CSL_GIC400_GICD_ICACTIVER10_GICD_ICACTIVER10_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER10_GICD_ICACTIVER10_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER10_GICD_ICACTIVER10_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER10_GICD_ICACTIVER10_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER10_RESETVAL                    (0x00000000U)

/* GICD_ICACTIVER11 */

#define CSL_GIC400_GICD_ICACTIVER11_GICD_ICACTIVER11_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER11_GICD_ICACTIVER11_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER11_GICD_ICACTIVER11_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER11_GICD_ICACTIVER11_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER11_RESETVAL                    (0x00000000U)

/* GICD_ICACTIVER12 */

#define CSL_GIC400_GICD_ICACTIVER12_GICD_ICACTIVER12_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER12_GICD_ICACTIVER12_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER12_GICD_ICACTIVER12_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER12_GICD_ICACTIVER12_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER12_RESETVAL                    (0x00000000U)

/* GICD_ICACTIVER13 */

#define CSL_GIC400_GICD_ICACTIVER13_GICD_ICACTIVER13_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER13_GICD_ICACTIVER13_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER13_GICD_ICACTIVER13_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER13_GICD_ICACTIVER13_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER13_RESETVAL                    (0x00000000U)

/* GICD_ICACTIVER14 */

#define CSL_GIC400_GICD_ICACTIVER14_GICD_ICACTIVER14_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER14_GICD_ICACTIVER14_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER14_GICD_ICACTIVER14_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER14_GICD_ICACTIVER14_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER14_RESETVAL                    (0x00000000U)

/* GICD_ICACTIVER15 */

#define CSL_GIC400_GICD_ICACTIVER15_GICD_ICACTIVER15_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICACTIVER15_GICD_ICACTIVER15_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER15_GICD_ICACTIVER15_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ICACTIVER15_GICD_ICACTIVER15_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ICACTIVER15_RESETVAL                    (0x00000000U)

/* GICD_IPRIORITYR0 */

#define CSL_GIC400_GICD_IPRIORITYR0_GICD_IPRIORITYR0_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR0_GICD_IPRIORITYR0_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR0_GICD_IPRIORITYR0_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR0_GICD_IPRIORITYR0_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR0_RESETVAL                    (0x00000000U)

/* GICD_IPRIORITYR1 */

#define CSL_GIC400_GICD_IPRIORITYR1_GICD_IPRIORITYR1_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR1_GICD_IPRIORITYR1_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR1_GICD_IPRIORITYR1_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR1_GICD_IPRIORITYR1_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR1_RESETVAL                    (0x00000000U)

/* GICD_IPRIORITYR2 */

#define CSL_GIC400_GICD_IPRIORITYR2_GICD_IPRIORITYR2_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR2_GICD_IPRIORITYR2_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR2_GICD_IPRIORITYR2_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR2_GICD_IPRIORITYR2_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR2_RESETVAL                    (0x00000000U)

/* GICD_IPRIORITYR3 */

#define CSL_GIC400_GICD_IPRIORITYR3_GICD_IPRIORITYR3_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR3_GICD_IPRIORITYR3_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR3_GICD_IPRIORITYR3_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR3_GICD_IPRIORITYR3_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR3_RESETVAL                    (0x00000000U)

/* GICD_IPRIORITYR4 */

#define CSL_GIC400_GICD_IPRIORITYR4_GICD_IPRIORITYR4_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR4_GICD_IPRIORITYR4_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR4_GICD_IPRIORITYR4_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR4_GICD_IPRIORITYR4_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR4_RESETVAL                    (0x00000000U)

/* GICD_IPRIORITYR5 */

#define CSL_GIC400_GICD_IPRIORITYR5_GICD_IPRIORITYR5_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR5_GICD_IPRIORITYR5_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR5_GICD_IPRIORITYR5_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR5_GICD_IPRIORITYR5_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR5_RESETVAL                    (0x00000000U)

/* GICD_IPRIORITYR6 */

#define CSL_GIC400_GICD_IPRIORITYR6_GICD_IPRIORITYR6_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR6_GICD_IPRIORITYR6_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR6_GICD_IPRIORITYR6_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR6_GICD_IPRIORITYR6_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR6_RESETVAL                    (0x00000000U)

/* GICD_IPRIORITYR7 */

#define CSL_GIC400_GICD_IPRIORITYR7_GICD_IPRIORITYR7_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR7_GICD_IPRIORITYR7_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR7_GICD_IPRIORITYR7_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR7_GICD_IPRIORITYR7_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR7_RESETVAL                    (0x00000000U)

/* GICD_IPRIORITYR8 */

#define CSL_GIC400_GICD_IPRIORITYR8_GICD_IPRIORITYR8_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR8_GICD_IPRIORITYR8_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR8_GICD_IPRIORITYR8_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR8_GICD_IPRIORITYR8_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR8_RESETVAL                    (0x00000000U)

/* GICD_IPRIORITYR9 */

#define CSL_GIC400_GICD_IPRIORITYR9_GICD_IPRIORITYR9_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR9_GICD_IPRIORITYR9_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR9_GICD_IPRIORITYR9_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR9_GICD_IPRIORITYR9_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR9_RESETVAL                    (0x00000000U)

/* GICD_IPRIORITYR10 */

#define CSL_GIC400_GICD_IPRIORITYR10_GICD_IPRIORITYR10_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR10_GICD_IPRIORITYR10_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR10_GICD_IPRIORITYR10_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR10_GICD_IPRIORITYR10_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR10_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR11 */

#define CSL_GIC400_GICD_IPRIORITYR11_GICD_IPRIORITYR11_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR11_GICD_IPRIORITYR11_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR11_GICD_IPRIORITYR11_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR11_GICD_IPRIORITYR11_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR11_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR12 */

#define CSL_GIC400_GICD_IPRIORITYR12_GICD_IPRIORITYR12_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR12_GICD_IPRIORITYR12_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR12_GICD_IPRIORITYR12_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR12_GICD_IPRIORITYR12_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR12_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR13 */

#define CSL_GIC400_GICD_IPRIORITYR13_GICD_IPRIORITYR13_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR13_GICD_IPRIORITYR13_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR13_GICD_IPRIORITYR13_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR13_GICD_IPRIORITYR13_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR13_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR14 */

#define CSL_GIC400_GICD_IPRIORITYR14_GICD_IPRIORITYR14_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR14_GICD_IPRIORITYR14_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR14_GICD_IPRIORITYR14_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR14_GICD_IPRIORITYR14_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR14_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR15 */

#define CSL_GIC400_GICD_IPRIORITYR15_GICD_IPRIORITYR15_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR15_GICD_IPRIORITYR15_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR15_GICD_IPRIORITYR15_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR15_GICD_IPRIORITYR15_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR15_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR16 */

#define CSL_GIC400_GICD_IPRIORITYR16_GICD_IPRIORITYR16_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR16_GICD_IPRIORITYR16_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR16_GICD_IPRIORITYR16_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR16_GICD_IPRIORITYR16_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR16_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR17 */

#define CSL_GIC400_GICD_IPRIORITYR17_GICD_IPRIORITYR17_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR17_GICD_IPRIORITYR17_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR17_GICD_IPRIORITYR17_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR17_GICD_IPRIORITYR17_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR17_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR18 */

#define CSL_GIC400_GICD_IPRIORITYR18_GICD_IPRIORITYR18_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR18_GICD_IPRIORITYR18_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR18_GICD_IPRIORITYR18_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR18_GICD_IPRIORITYR18_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR18_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR19 */

#define CSL_GIC400_GICD_IPRIORITYR19_GICD_IPRIORITYR19_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR19_GICD_IPRIORITYR19_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR19_GICD_IPRIORITYR19_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR19_GICD_IPRIORITYR19_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR19_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR20 */

#define CSL_GIC400_GICD_IPRIORITYR20_GICD_IPRIORITYR20_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR20_GICD_IPRIORITYR20_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR20_GICD_IPRIORITYR20_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR20_GICD_IPRIORITYR20_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR20_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR21 */

#define CSL_GIC400_GICD_IPRIORITYR21_GICD_IPRIORITYR21_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR21_GICD_IPRIORITYR21_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR21_GICD_IPRIORITYR21_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR21_GICD_IPRIORITYR21_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR21_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR22 */

#define CSL_GIC400_GICD_IPRIORITYR22_GICD_IPRIORITYR22_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR22_GICD_IPRIORITYR22_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR22_GICD_IPRIORITYR22_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR22_GICD_IPRIORITYR22_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR22_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR23 */

#define CSL_GIC400_GICD_IPRIORITYR23_GICD_IPRIORITYR23_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR23_GICD_IPRIORITYR23_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR23_GICD_IPRIORITYR23_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR23_GICD_IPRIORITYR23_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR23_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR24 */

#define CSL_GIC400_GICD_IPRIORITYR24_GICD_IPRIORITYR24_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR24_GICD_IPRIORITYR24_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR24_GICD_IPRIORITYR24_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR24_GICD_IPRIORITYR24_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR24_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR25 */

#define CSL_GIC400_GICD_IPRIORITYR25_GICD_IPRIORITYR25_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR25_GICD_IPRIORITYR25_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR25_GICD_IPRIORITYR25_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR25_GICD_IPRIORITYR25_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR25_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR26 */

#define CSL_GIC400_GICD_IPRIORITYR26_GICD_IPRIORITYR26_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR26_GICD_IPRIORITYR26_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR26_GICD_IPRIORITYR26_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR26_GICD_IPRIORITYR26_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR26_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR27 */

#define CSL_GIC400_GICD_IPRIORITYR27_GICD_IPRIORITYR27_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR27_GICD_IPRIORITYR27_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR27_GICD_IPRIORITYR27_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR27_GICD_IPRIORITYR27_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR27_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR28 */

#define CSL_GIC400_GICD_IPRIORITYR28_GICD_IPRIORITYR28_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR28_GICD_IPRIORITYR28_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR28_GICD_IPRIORITYR28_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR28_GICD_IPRIORITYR28_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR28_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR29 */

#define CSL_GIC400_GICD_IPRIORITYR29_GICD_IPRIORITYR29_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR29_GICD_IPRIORITYR29_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR29_GICD_IPRIORITYR29_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR29_GICD_IPRIORITYR29_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR29_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR30 */

#define CSL_GIC400_GICD_IPRIORITYR30_GICD_IPRIORITYR30_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR30_GICD_IPRIORITYR30_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR30_GICD_IPRIORITYR30_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR30_GICD_IPRIORITYR30_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR30_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR31 */

#define CSL_GIC400_GICD_IPRIORITYR31_GICD_IPRIORITYR31_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR31_GICD_IPRIORITYR31_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR31_GICD_IPRIORITYR31_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR31_GICD_IPRIORITYR31_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR31_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR32 */

#define CSL_GIC400_GICD_IPRIORITYR32_GICD_IPRIORITYR32_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR32_GICD_IPRIORITYR32_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR32_GICD_IPRIORITYR32_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR32_GICD_IPRIORITYR32_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR32_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR33 */

#define CSL_GIC400_GICD_IPRIORITYR33_GICD_IPRIORITYR33_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR33_GICD_IPRIORITYR33_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR33_GICD_IPRIORITYR33_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR33_GICD_IPRIORITYR33_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR33_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR34 */

#define CSL_GIC400_GICD_IPRIORITYR34_GICD_IPRIORITYR34_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR34_GICD_IPRIORITYR34_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR34_GICD_IPRIORITYR34_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR34_GICD_IPRIORITYR34_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR34_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR35 */

#define CSL_GIC400_GICD_IPRIORITYR35_GICD_IPRIORITYR35_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR35_GICD_IPRIORITYR35_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR35_GICD_IPRIORITYR35_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR35_GICD_IPRIORITYR35_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR35_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR36 */

#define CSL_GIC400_GICD_IPRIORITYR36_GICD_IPRIORITYR36_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR36_GICD_IPRIORITYR36_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR36_GICD_IPRIORITYR36_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR36_GICD_IPRIORITYR36_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR36_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR37 */

#define CSL_GIC400_GICD_IPRIORITYR37_GICD_IPRIORITYR37_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR37_GICD_IPRIORITYR37_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR37_GICD_IPRIORITYR37_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR37_GICD_IPRIORITYR37_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR37_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR38 */

#define CSL_GIC400_GICD_IPRIORITYR38_GICD_IPRIORITYR38_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR38_GICD_IPRIORITYR38_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR38_GICD_IPRIORITYR38_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR38_GICD_IPRIORITYR38_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR38_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR39 */

#define CSL_GIC400_GICD_IPRIORITYR39_GICD_IPRIORITYR39_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR39_GICD_IPRIORITYR39_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR39_GICD_IPRIORITYR39_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR39_GICD_IPRIORITYR39_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR39_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR40 */

#define CSL_GIC400_GICD_IPRIORITYR40_GICD_IPRIORITYR40_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR40_GICD_IPRIORITYR40_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR40_GICD_IPRIORITYR40_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR40_GICD_IPRIORITYR40_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR40_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR41 */

#define CSL_GIC400_GICD_IPRIORITYR41_GICD_IPRIORITYR41_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR41_GICD_IPRIORITYR41_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR41_GICD_IPRIORITYR41_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR41_GICD_IPRIORITYR41_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR41_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR42 */

#define CSL_GIC400_GICD_IPRIORITYR42_GICD_IPRIORITYR42_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR42_GICD_IPRIORITYR42_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR42_GICD_IPRIORITYR42_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR42_GICD_IPRIORITYR42_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR42_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR43 */

#define CSL_GIC400_GICD_IPRIORITYR43_GICD_IPRIORITYR43_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR43_GICD_IPRIORITYR43_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR43_GICD_IPRIORITYR43_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR43_GICD_IPRIORITYR43_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR43_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR44 */

#define CSL_GIC400_GICD_IPRIORITYR44_GICD_IPRIORITYR44_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR44_GICD_IPRIORITYR44_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR44_GICD_IPRIORITYR44_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR44_GICD_IPRIORITYR44_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR44_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR45 */

#define CSL_GIC400_GICD_IPRIORITYR45_GICD_IPRIORITYR45_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR45_GICD_IPRIORITYR45_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR45_GICD_IPRIORITYR45_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR45_GICD_IPRIORITYR45_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR45_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR46 */

#define CSL_GIC400_GICD_IPRIORITYR46_GICD_IPRIORITYR46_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR46_GICD_IPRIORITYR46_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR46_GICD_IPRIORITYR46_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR46_GICD_IPRIORITYR46_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR46_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR47 */

#define CSL_GIC400_GICD_IPRIORITYR47_GICD_IPRIORITYR47_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR47_GICD_IPRIORITYR47_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR47_GICD_IPRIORITYR47_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR47_GICD_IPRIORITYR47_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR47_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR48 */

#define CSL_GIC400_GICD_IPRIORITYR48_GICD_IPRIORITYR48_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR48_GICD_IPRIORITYR48_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR48_GICD_IPRIORITYR48_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR48_GICD_IPRIORITYR48_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR48_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR49 */

#define CSL_GIC400_GICD_IPRIORITYR49_GICD_IPRIORITYR49_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR49_GICD_IPRIORITYR49_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR49_GICD_IPRIORITYR49_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR49_GICD_IPRIORITYR49_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR49_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR50 */

#define CSL_GIC400_GICD_IPRIORITYR50_GICD_IPRIORITYR50_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR50_GICD_IPRIORITYR50_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR50_GICD_IPRIORITYR50_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR50_GICD_IPRIORITYR50_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR50_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR51 */

#define CSL_GIC400_GICD_IPRIORITYR51_GICD_IPRIORITYR51_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR51_GICD_IPRIORITYR51_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR51_GICD_IPRIORITYR51_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR51_GICD_IPRIORITYR51_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR51_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR52 */

#define CSL_GIC400_GICD_IPRIORITYR52_GICD_IPRIORITYR52_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR52_GICD_IPRIORITYR52_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR52_GICD_IPRIORITYR52_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR52_GICD_IPRIORITYR52_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR52_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR53 */

#define CSL_GIC400_GICD_IPRIORITYR53_GICD_IPRIORITYR53_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR53_GICD_IPRIORITYR53_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR53_GICD_IPRIORITYR53_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR53_GICD_IPRIORITYR53_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR53_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR54 */

#define CSL_GIC400_GICD_IPRIORITYR54_GICD_IPRIORITYR54_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR54_GICD_IPRIORITYR54_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR54_GICD_IPRIORITYR54_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR54_GICD_IPRIORITYR54_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR54_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR55 */

#define CSL_GIC400_GICD_IPRIORITYR55_GICD_IPRIORITYR55_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR55_GICD_IPRIORITYR55_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR55_GICD_IPRIORITYR55_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR55_GICD_IPRIORITYR55_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR55_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR56 */

#define CSL_GIC400_GICD_IPRIORITYR56_GICD_IPRIORITYR56_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR56_GICD_IPRIORITYR56_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR56_GICD_IPRIORITYR56_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR56_GICD_IPRIORITYR56_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR56_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR57 */

#define CSL_GIC400_GICD_IPRIORITYR57_GICD_IPRIORITYR57_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR57_GICD_IPRIORITYR57_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR57_GICD_IPRIORITYR57_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR57_GICD_IPRIORITYR57_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR57_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR58 */

#define CSL_GIC400_GICD_IPRIORITYR58_GICD_IPRIORITYR58_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR58_GICD_IPRIORITYR58_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR58_GICD_IPRIORITYR58_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR58_GICD_IPRIORITYR58_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR58_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR59 */

#define CSL_GIC400_GICD_IPRIORITYR59_GICD_IPRIORITYR59_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR59_GICD_IPRIORITYR59_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR59_GICD_IPRIORITYR59_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR59_GICD_IPRIORITYR59_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR59_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR60 */

#define CSL_GIC400_GICD_IPRIORITYR60_GICD_IPRIORITYR60_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR60_GICD_IPRIORITYR60_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR60_GICD_IPRIORITYR60_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR60_GICD_IPRIORITYR60_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR60_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR61 */

#define CSL_GIC400_GICD_IPRIORITYR61_GICD_IPRIORITYR61_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR61_GICD_IPRIORITYR61_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR61_GICD_IPRIORITYR61_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR61_GICD_IPRIORITYR61_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR61_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR62 */

#define CSL_GIC400_GICD_IPRIORITYR62_GICD_IPRIORITYR62_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR62_GICD_IPRIORITYR62_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR62_GICD_IPRIORITYR62_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR62_GICD_IPRIORITYR62_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR62_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR63 */

#define CSL_GIC400_GICD_IPRIORITYR63_GICD_IPRIORITYR63_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR63_GICD_IPRIORITYR63_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR63_GICD_IPRIORITYR63_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR63_GICD_IPRIORITYR63_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR63_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR64 */

#define CSL_GIC400_GICD_IPRIORITYR64_GICD_IPRIORITYR64_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR64_GICD_IPRIORITYR64_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR64_GICD_IPRIORITYR64_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR64_GICD_IPRIORITYR64_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR64_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR65 */

#define CSL_GIC400_GICD_IPRIORITYR65_GICD_IPRIORITYR65_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR65_GICD_IPRIORITYR65_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR65_GICD_IPRIORITYR65_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR65_GICD_IPRIORITYR65_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR65_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR66 */

#define CSL_GIC400_GICD_IPRIORITYR66_GICD_IPRIORITYR66_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR66_GICD_IPRIORITYR66_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR66_GICD_IPRIORITYR66_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR66_GICD_IPRIORITYR66_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR66_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR67 */

#define CSL_GIC400_GICD_IPRIORITYR67_GICD_IPRIORITYR67_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR67_GICD_IPRIORITYR67_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR67_GICD_IPRIORITYR67_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR67_GICD_IPRIORITYR67_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR67_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR68 */

#define CSL_GIC400_GICD_IPRIORITYR68_GICD_IPRIORITYR68_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR68_GICD_IPRIORITYR68_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR68_GICD_IPRIORITYR68_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR68_GICD_IPRIORITYR68_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR68_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR69 */

#define CSL_GIC400_GICD_IPRIORITYR69_GICD_IPRIORITYR69_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR69_GICD_IPRIORITYR69_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR69_GICD_IPRIORITYR69_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR69_GICD_IPRIORITYR69_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR69_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR70 */

#define CSL_GIC400_GICD_IPRIORITYR70_GICD_IPRIORITYR70_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR70_GICD_IPRIORITYR70_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR70_GICD_IPRIORITYR70_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR70_GICD_IPRIORITYR70_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR70_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR71 */

#define CSL_GIC400_GICD_IPRIORITYR71_GICD_IPRIORITYR71_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR71_GICD_IPRIORITYR71_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR71_GICD_IPRIORITYR71_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR71_GICD_IPRIORITYR71_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR71_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR72 */

#define CSL_GIC400_GICD_IPRIORITYR72_GICD_IPRIORITYR72_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR72_GICD_IPRIORITYR72_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR72_GICD_IPRIORITYR72_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR72_GICD_IPRIORITYR72_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR72_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR73 */

#define CSL_GIC400_GICD_IPRIORITYR73_GICD_IPRIORITYR73_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR73_GICD_IPRIORITYR73_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR73_GICD_IPRIORITYR73_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR73_GICD_IPRIORITYR73_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR73_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR74 */

#define CSL_GIC400_GICD_IPRIORITYR74_GICD_IPRIORITYR74_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR74_GICD_IPRIORITYR74_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR74_GICD_IPRIORITYR74_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR74_GICD_IPRIORITYR74_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR74_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR75 */

#define CSL_GIC400_GICD_IPRIORITYR75_GICD_IPRIORITYR75_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR75_GICD_IPRIORITYR75_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR75_GICD_IPRIORITYR75_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR75_GICD_IPRIORITYR75_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR75_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR76 */

#define CSL_GIC400_GICD_IPRIORITYR76_GICD_IPRIORITYR76_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR76_GICD_IPRIORITYR76_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR76_GICD_IPRIORITYR76_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR76_GICD_IPRIORITYR76_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR76_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR77 */

#define CSL_GIC400_GICD_IPRIORITYR77_GICD_IPRIORITYR77_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR77_GICD_IPRIORITYR77_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR77_GICD_IPRIORITYR77_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR77_GICD_IPRIORITYR77_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR77_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR78 */

#define CSL_GIC400_GICD_IPRIORITYR78_GICD_IPRIORITYR78_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR78_GICD_IPRIORITYR78_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR78_GICD_IPRIORITYR78_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR78_GICD_IPRIORITYR78_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR78_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR79 */

#define CSL_GIC400_GICD_IPRIORITYR79_GICD_IPRIORITYR79_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR79_GICD_IPRIORITYR79_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR79_GICD_IPRIORITYR79_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR79_GICD_IPRIORITYR79_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR79_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR80 */

#define CSL_GIC400_GICD_IPRIORITYR80_GICD_IPRIORITYR80_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR80_GICD_IPRIORITYR80_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR80_GICD_IPRIORITYR80_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR80_GICD_IPRIORITYR80_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR80_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR81 */

#define CSL_GIC400_GICD_IPRIORITYR81_GICD_IPRIORITYR81_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR81_GICD_IPRIORITYR81_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR81_GICD_IPRIORITYR81_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR81_GICD_IPRIORITYR81_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR81_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR82 */

#define CSL_GIC400_GICD_IPRIORITYR82_GICD_IPRIORITYR82_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR82_GICD_IPRIORITYR82_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR82_GICD_IPRIORITYR82_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR82_GICD_IPRIORITYR82_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR82_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR83 */

#define CSL_GIC400_GICD_IPRIORITYR83_GICD_IPRIORITYR83_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR83_GICD_IPRIORITYR83_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR83_GICD_IPRIORITYR83_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR83_GICD_IPRIORITYR83_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR83_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR84 */

#define CSL_GIC400_GICD_IPRIORITYR84_GICD_IPRIORITYR84_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR84_GICD_IPRIORITYR84_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR84_GICD_IPRIORITYR84_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR84_GICD_IPRIORITYR84_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR84_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR85 */

#define CSL_GIC400_GICD_IPRIORITYR85_GICD_IPRIORITYR85_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR85_GICD_IPRIORITYR85_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR85_GICD_IPRIORITYR85_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR85_GICD_IPRIORITYR85_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR85_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR86 */

#define CSL_GIC400_GICD_IPRIORITYR86_GICD_IPRIORITYR86_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR86_GICD_IPRIORITYR86_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR86_GICD_IPRIORITYR86_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR86_GICD_IPRIORITYR86_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR86_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR87 */

#define CSL_GIC400_GICD_IPRIORITYR87_GICD_IPRIORITYR87_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR87_GICD_IPRIORITYR87_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR87_GICD_IPRIORITYR87_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR87_GICD_IPRIORITYR87_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR87_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR88 */

#define CSL_GIC400_GICD_IPRIORITYR88_GICD_IPRIORITYR88_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR88_GICD_IPRIORITYR88_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR88_GICD_IPRIORITYR88_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR88_GICD_IPRIORITYR88_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR88_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR89 */

#define CSL_GIC400_GICD_IPRIORITYR89_GICD_IPRIORITYR89_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR89_GICD_IPRIORITYR89_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR89_GICD_IPRIORITYR89_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR89_GICD_IPRIORITYR89_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR89_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR90 */

#define CSL_GIC400_GICD_IPRIORITYR90_GICD_IPRIORITYR90_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR90_GICD_IPRIORITYR90_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR90_GICD_IPRIORITYR90_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR90_GICD_IPRIORITYR90_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR90_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR91 */

#define CSL_GIC400_GICD_IPRIORITYR91_GICD_IPRIORITYR91_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR91_GICD_IPRIORITYR91_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR91_GICD_IPRIORITYR91_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR91_GICD_IPRIORITYR91_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR91_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR92 */

#define CSL_GIC400_GICD_IPRIORITYR92_GICD_IPRIORITYR92_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR92_GICD_IPRIORITYR92_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR92_GICD_IPRIORITYR92_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR92_GICD_IPRIORITYR92_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR92_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR93 */

#define CSL_GIC400_GICD_IPRIORITYR93_GICD_IPRIORITYR93_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR93_GICD_IPRIORITYR93_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR93_GICD_IPRIORITYR93_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR93_GICD_IPRIORITYR93_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR93_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR94 */

#define CSL_GIC400_GICD_IPRIORITYR94_GICD_IPRIORITYR94_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR94_GICD_IPRIORITYR94_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR94_GICD_IPRIORITYR94_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR94_GICD_IPRIORITYR94_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR94_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR95 */

#define CSL_GIC400_GICD_IPRIORITYR95_GICD_IPRIORITYR95_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR95_GICD_IPRIORITYR95_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR95_GICD_IPRIORITYR95_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR95_GICD_IPRIORITYR95_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR95_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR96 */

#define CSL_GIC400_GICD_IPRIORITYR96_GICD_IPRIORITYR96_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR96_GICD_IPRIORITYR96_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR96_GICD_IPRIORITYR96_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR96_GICD_IPRIORITYR96_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR96_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR97 */

#define CSL_GIC400_GICD_IPRIORITYR97_GICD_IPRIORITYR97_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR97_GICD_IPRIORITYR97_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR97_GICD_IPRIORITYR97_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR97_GICD_IPRIORITYR97_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR97_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR98 */

#define CSL_GIC400_GICD_IPRIORITYR98_GICD_IPRIORITYR98_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR98_GICD_IPRIORITYR98_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR98_GICD_IPRIORITYR98_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR98_GICD_IPRIORITYR98_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR98_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR99 */

#define CSL_GIC400_GICD_IPRIORITYR99_GICD_IPRIORITYR99_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR99_GICD_IPRIORITYR99_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR99_GICD_IPRIORITYR99_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR99_GICD_IPRIORITYR99_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR99_RESETVAL                   (0x00000000U)

/* GICD_IPRIORITYR100 */

#define CSL_GIC400_GICD_IPRIORITYR100_GICD_IPRIORITYR100_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR100_GICD_IPRIORITYR100_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR100_GICD_IPRIORITYR100_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR100_GICD_IPRIORITYR100_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR100_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR101 */

#define CSL_GIC400_GICD_IPRIORITYR101_GICD_IPRIORITYR101_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR101_GICD_IPRIORITYR101_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR101_GICD_IPRIORITYR101_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR101_GICD_IPRIORITYR101_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR101_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR102 */

#define CSL_GIC400_GICD_IPRIORITYR102_GICD_IPRIORITYR102_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR102_GICD_IPRIORITYR102_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR102_GICD_IPRIORITYR102_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR102_GICD_IPRIORITYR102_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR102_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR103 */

#define CSL_GIC400_GICD_IPRIORITYR103_GICD_IPRIORITYR103_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR103_GICD_IPRIORITYR103_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR103_GICD_IPRIORITYR103_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR103_GICD_IPRIORITYR103_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR103_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR104 */

#define CSL_GIC400_GICD_IPRIORITYR104_GICD_IPRIORITYR104_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR104_GICD_IPRIORITYR104_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR104_GICD_IPRIORITYR104_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR104_GICD_IPRIORITYR104_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR104_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR105 */

#define CSL_GIC400_GICD_IPRIORITYR105_GICD_IPRIORITYR105_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR105_GICD_IPRIORITYR105_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR105_GICD_IPRIORITYR105_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR105_GICD_IPRIORITYR105_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR105_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR106 */

#define CSL_GIC400_GICD_IPRIORITYR106_GICD_IPRIORITYR106_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR106_GICD_IPRIORITYR106_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR106_GICD_IPRIORITYR106_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR106_GICD_IPRIORITYR106_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR106_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR107 */

#define CSL_GIC400_GICD_IPRIORITYR107_GICD_IPRIORITYR107_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR107_GICD_IPRIORITYR107_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR107_GICD_IPRIORITYR107_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR107_GICD_IPRIORITYR107_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR107_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR108 */

#define CSL_GIC400_GICD_IPRIORITYR108_GICD_IPRIORITYR108_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR108_GICD_IPRIORITYR108_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR108_GICD_IPRIORITYR108_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR108_GICD_IPRIORITYR108_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR108_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR109 */

#define CSL_GIC400_GICD_IPRIORITYR109_GICD_IPRIORITYR109_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR109_GICD_IPRIORITYR109_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR109_GICD_IPRIORITYR109_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR109_GICD_IPRIORITYR109_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR109_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR110 */

#define CSL_GIC400_GICD_IPRIORITYR110_GICD_IPRIORITYR110_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR110_GICD_IPRIORITYR110_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR110_GICD_IPRIORITYR110_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR110_GICD_IPRIORITYR110_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR110_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR111 */

#define CSL_GIC400_GICD_IPRIORITYR111_GICD_IPRIORITYR111_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR111_GICD_IPRIORITYR111_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR111_GICD_IPRIORITYR111_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR111_GICD_IPRIORITYR111_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR111_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR112 */

#define CSL_GIC400_GICD_IPRIORITYR112_GICD_IPRIORITYR112_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR112_GICD_IPRIORITYR112_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR112_GICD_IPRIORITYR112_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR112_GICD_IPRIORITYR112_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR112_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR113 */

#define CSL_GIC400_GICD_IPRIORITYR113_GICD_IPRIORITYR113_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR113_GICD_IPRIORITYR113_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR113_GICD_IPRIORITYR113_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR113_GICD_IPRIORITYR113_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR113_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR114 */

#define CSL_GIC400_GICD_IPRIORITYR114_GICD_IPRIORITYR114_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR114_GICD_IPRIORITYR114_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR114_GICD_IPRIORITYR114_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR114_GICD_IPRIORITYR114_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR114_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR115 */

#define CSL_GIC400_GICD_IPRIORITYR115_GICD_IPRIORITYR115_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR115_GICD_IPRIORITYR115_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR115_GICD_IPRIORITYR115_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR115_GICD_IPRIORITYR115_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR115_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR116 */

#define CSL_GIC400_GICD_IPRIORITYR116_GICD_IPRIORITYR116_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR116_GICD_IPRIORITYR116_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR116_GICD_IPRIORITYR116_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR116_GICD_IPRIORITYR116_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR116_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR117 */

#define CSL_GIC400_GICD_IPRIORITYR117_GICD_IPRIORITYR117_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR117_GICD_IPRIORITYR117_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR117_GICD_IPRIORITYR117_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR117_GICD_IPRIORITYR117_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR117_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR118 */

#define CSL_GIC400_GICD_IPRIORITYR118_GICD_IPRIORITYR118_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR118_GICD_IPRIORITYR118_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR118_GICD_IPRIORITYR118_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR118_GICD_IPRIORITYR118_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR118_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR119 */

#define CSL_GIC400_GICD_IPRIORITYR119_GICD_IPRIORITYR119_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR119_GICD_IPRIORITYR119_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR119_GICD_IPRIORITYR119_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR119_GICD_IPRIORITYR119_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR119_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR120 */

#define CSL_GIC400_GICD_IPRIORITYR120_GICD_IPRIORITYR120_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR120_GICD_IPRIORITYR120_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR120_GICD_IPRIORITYR120_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR120_GICD_IPRIORITYR120_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR120_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR121 */

#define CSL_GIC400_GICD_IPRIORITYR121_GICD_IPRIORITYR121_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR121_GICD_IPRIORITYR121_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR121_GICD_IPRIORITYR121_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR121_GICD_IPRIORITYR121_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR121_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR122 */

#define CSL_GIC400_GICD_IPRIORITYR122_GICD_IPRIORITYR122_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR122_GICD_IPRIORITYR122_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR122_GICD_IPRIORITYR122_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR122_GICD_IPRIORITYR122_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR122_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR123 */

#define CSL_GIC400_GICD_IPRIORITYR123_GICD_IPRIORITYR123_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR123_GICD_IPRIORITYR123_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR123_GICD_IPRIORITYR123_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR123_GICD_IPRIORITYR123_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR123_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR124 */

#define CSL_GIC400_GICD_IPRIORITYR124_GICD_IPRIORITYR124_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR124_GICD_IPRIORITYR124_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR124_GICD_IPRIORITYR124_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR124_GICD_IPRIORITYR124_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR124_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR125 */

#define CSL_GIC400_GICD_IPRIORITYR125_GICD_IPRIORITYR125_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR125_GICD_IPRIORITYR125_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR125_GICD_IPRIORITYR125_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR125_GICD_IPRIORITYR125_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR125_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR126 */

#define CSL_GIC400_GICD_IPRIORITYR126_GICD_IPRIORITYR126_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR126_GICD_IPRIORITYR126_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR126_GICD_IPRIORITYR126_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR126_GICD_IPRIORITYR126_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR126_RESETVAL                  (0x00000000U)

/* GICD_IPRIORITYR127 */

#define CSL_GIC400_GICD_IPRIORITYR127_GICD_IPRIORITYR127_MASK   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_IPRIORITYR127_GICD_IPRIORITYR127_SHIFT  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR127_GICD_IPRIORITYR127_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_IPRIORITYR127_GICD_IPRIORITYR127_MAX    (0xffffffffU)

#define CSL_GIC400_GICD_IPRIORITYR127_RESETVAL                  (0x00000000U)

/* GICD_ITARGETSR0 */

#define CSL_GIC400_GICD_ITARGETSR0_GICD_ITARGETSR0_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR0_GICD_ITARGETSR0_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR0_GICD_ITARGETSR0_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR0_GICD_ITARGETSR0_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR0_RESETVAL                     (0x00000000U)

/* GICD_ITARGETSR1 */

#define CSL_GIC400_GICD_ITARGETSR1_GICD_ITARGETSR1_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR1_GICD_ITARGETSR1_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR1_GICD_ITARGETSR1_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR1_GICD_ITARGETSR1_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR1_RESETVAL                     (0x00000000U)

/* GICD_ITARGETSR2 */

#define CSL_GIC400_GICD_ITARGETSR2_GICD_ITARGETSR2_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR2_GICD_ITARGETSR2_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR2_GICD_ITARGETSR2_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR2_GICD_ITARGETSR2_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR2_RESETVAL                     (0x00000000U)

/* GICD_ITARGETSR3 */

#define CSL_GIC400_GICD_ITARGETSR3_GICD_ITARGETSR3_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR3_GICD_ITARGETSR3_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR3_GICD_ITARGETSR3_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR3_GICD_ITARGETSR3_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR3_RESETVAL                     (0x00000000U)

/* GICD_ITARGETSR4 */

#define CSL_GIC400_GICD_ITARGETSR4_GICD_ITARGETSR4_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR4_GICD_ITARGETSR4_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR4_GICD_ITARGETSR4_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR4_GICD_ITARGETSR4_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR4_RESETVAL                     (0x00000000U)

/* GICD_ITARGETSR5 */

#define CSL_GIC400_GICD_ITARGETSR5_GICD_ITARGETSR5_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR5_GICD_ITARGETSR5_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR5_GICD_ITARGETSR5_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR5_GICD_ITARGETSR5_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR5_RESETVAL                     (0x00000000U)

/* GICD_ITARGETSR6 */

#define CSL_GIC400_GICD_ITARGETSR6_GICD_ITARGETSR6_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR6_GICD_ITARGETSR6_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR6_GICD_ITARGETSR6_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR6_GICD_ITARGETSR6_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR6_RESETVAL                     (0x00000000U)

/* GICD_ITARGETSR7 */

#define CSL_GIC400_GICD_ITARGETSR7_GICD_ITARGETSR7_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR7_GICD_ITARGETSR7_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR7_GICD_ITARGETSR7_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR7_GICD_ITARGETSR7_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR7_RESETVAL                     (0x00000000U)

/* GICD_ITARGETSR8 */

#define CSL_GIC400_GICD_ITARGETSR8_GICD_ITARGETSR8_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR8_GICD_ITARGETSR8_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR8_GICD_ITARGETSR8_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR8_GICD_ITARGETSR8_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR8_RESETVAL                     (0x00000000U)

/* GICD_ITARGETSR9 */

#define CSL_GIC400_GICD_ITARGETSR9_GICD_ITARGETSR9_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR9_GICD_ITARGETSR9_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR9_GICD_ITARGETSR9_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR9_GICD_ITARGETSR9_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR9_RESETVAL                     (0x00000000U)

/* GICD_ITARGETSR10 */

#define CSL_GIC400_GICD_ITARGETSR10_GICD_ITARGETSR10_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR10_GICD_ITARGETSR10_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR10_GICD_ITARGETSR10_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR10_GICD_ITARGETSR10_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR10_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR11 */

#define CSL_GIC400_GICD_ITARGETSR11_GICD_ITARGETSR11_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR11_GICD_ITARGETSR11_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR11_GICD_ITARGETSR11_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR11_GICD_ITARGETSR11_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR11_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR12 */

#define CSL_GIC400_GICD_ITARGETSR12_GICD_ITARGETSR12_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR12_GICD_ITARGETSR12_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR12_GICD_ITARGETSR12_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR12_GICD_ITARGETSR12_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR12_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR13 */

#define CSL_GIC400_GICD_ITARGETSR13_GICD_ITARGETSR13_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR13_GICD_ITARGETSR13_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR13_GICD_ITARGETSR13_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR13_GICD_ITARGETSR13_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR13_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR14 */

#define CSL_GIC400_GICD_ITARGETSR14_GICD_ITARGETSR14_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR14_GICD_ITARGETSR14_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR14_GICD_ITARGETSR14_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR14_GICD_ITARGETSR14_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR14_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR15 */

#define CSL_GIC400_GICD_ITARGETSR15_GICD_ITARGETSR15_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR15_GICD_ITARGETSR15_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR15_GICD_ITARGETSR15_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR15_GICD_ITARGETSR15_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR15_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR16 */

#define CSL_GIC400_GICD_ITARGETSR16_GICD_ITARGETSR16_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR16_GICD_ITARGETSR16_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR16_GICD_ITARGETSR16_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR16_GICD_ITARGETSR16_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR16_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR17 */

#define CSL_GIC400_GICD_ITARGETSR17_GICD_ITARGETSR17_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR17_GICD_ITARGETSR17_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR17_GICD_ITARGETSR17_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR17_GICD_ITARGETSR17_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR17_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR18 */

#define CSL_GIC400_GICD_ITARGETSR18_GICD_ITARGETSR18_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR18_GICD_ITARGETSR18_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR18_GICD_ITARGETSR18_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR18_GICD_ITARGETSR18_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR18_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR19 */

#define CSL_GIC400_GICD_ITARGETSR19_GICD_ITARGETSR19_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR19_GICD_ITARGETSR19_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR19_GICD_ITARGETSR19_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR19_GICD_ITARGETSR19_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR19_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR20 */

#define CSL_GIC400_GICD_ITARGETSR20_GICD_ITARGETSR20_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR20_GICD_ITARGETSR20_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR20_GICD_ITARGETSR20_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR20_GICD_ITARGETSR20_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR20_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR21 */

#define CSL_GIC400_GICD_ITARGETSR21_GICD_ITARGETSR21_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR21_GICD_ITARGETSR21_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR21_GICD_ITARGETSR21_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR21_GICD_ITARGETSR21_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR21_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR22 */

#define CSL_GIC400_GICD_ITARGETSR22_GICD_ITARGETSR22_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR22_GICD_ITARGETSR22_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR22_GICD_ITARGETSR22_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR22_GICD_ITARGETSR22_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR22_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR23 */

#define CSL_GIC400_GICD_ITARGETSR23_GICD_ITARGETSR23_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR23_GICD_ITARGETSR23_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR23_GICD_ITARGETSR23_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR23_GICD_ITARGETSR23_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR23_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR24 */

#define CSL_GIC400_GICD_ITARGETSR24_GICD_ITARGETSR24_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR24_GICD_ITARGETSR24_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR24_GICD_ITARGETSR24_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR24_GICD_ITARGETSR24_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR24_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR25 */

#define CSL_GIC400_GICD_ITARGETSR25_GICD_ITARGETSR25_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR25_GICD_ITARGETSR25_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR25_GICD_ITARGETSR25_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR25_GICD_ITARGETSR25_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR25_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR26 */

#define CSL_GIC400_GICD_ITARGETSR26_GICD_ITARGETSR26_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR26_GICD_ITARGETSR26_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR26_GICD_ITARGETSR26_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR26_GICD_ITARGETSR26_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR26_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR27 */

#define CSL_GIC400_GICD_ITARGETSR27_GICD_ITARGETSR27_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR27_GICD_ITARGETSR27_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR27_GICD_ITARGETSR27_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR27_GICD_ITARGETSR27_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR27_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR28 */

#define CSL_GIC400_GICD_ITARGETSR28_GICD_ITARGETSR28_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR28_GICD_ITARGETSR28_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR28_GICD_ITARGETSR28_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR28_GICD_ITARGETSR28_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR28_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR29 */

#define CSL_GIC400_GICD_ITARGETSR29_GICD_ITARGETSR29_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR29_GICD_ITARGETSR29_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR29_GICD_ITARGETSR29_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR29_GICD_ITARGETSR29_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR29_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR30 */

#define CSL_GIC400_GICD_ITARGETSR30_GICD_ITARGETSR30_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR30_GICD_ITARGETSR30_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR30_GICD_ITARGETSR30_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR30_GICD_ITARGETSR30_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR30_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR31 */

#define CSL_GIC400_GICD_ITARGETSR31_GICD_ITARGETSR31_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR31_GICD_ITARGETSR31_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR31_GICD_ITARGETSR31_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR31_GICD_ITARGETSR31_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR31_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR32 */

#define CSL_GIC400_GICD_ITARGETSR32_GICD_ITARGETSR32_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR32_GICD_ITARGETSR32_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR32_GICD_ITARGETSR32_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR32_GICD_ITARGETSR32_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR32_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR33 */

#define CSL_GIC400_GICD_ITARGETSR33_GICD_ITARGETSR33_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR33_GICD_ITARGETSR33_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR33_GICD_ITARGETSR33_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR33_GICD_ITARGETSR33_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR33_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR34 */

#define CSL_GIC400_GICD_ITARGETSR34_GICD_ITARGETSR34_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR34_GICD_ITARGETSR34_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR34_GICD_ITARGETSR34_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR34_GICD_ITARGETSR34_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR34_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR35 */

#define CSL_GIC400_GICD_ITARGETSR35_GICD_ITARGETSR35_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR35_GICD_ITARGETSR35_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR35_GICD_ITARGETSR35_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR35_GICD_ITARGETSR35_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR35_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR36 */

#define CSL_GIC400_GICD_ITARGETSR36_GICD_ITARGETSR36_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR36_GICD_ITARGETSR36_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR36_GICD_ITARGETSR36_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR36_GICD_ITARGETSR36_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR36_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR37 */

#define CSL_GIC400_GICD_ITARGETSR37_GICD_ITARGETSR37_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR37_GICD_ITARGETSR37_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR37_GICD_ITARGETSR37_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR37_GICD_ITARGETSR37_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR37_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR38 */

#define CSL_GIC400_GICD_ITARGETSR38_GICD_ITARGETSR38_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR38_GICD_ITARGETSR38_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR38_GICD_ITARGETSR38_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR38_GICD_ITARGETSR38_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR38_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR39 */

#define CSL_GIC400_GICD_ITARGETSR39_GICD_ITARGETSR39_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR39_GICD_ITARGETSR39_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR39_GICD_ITARGETSR39_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR39_GICD_ITARGETSR39_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR39_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR40 */

#define CSL_GIC400_GICD_ITARGETSR40_GICD_ITARGETSR40_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR40_GICD_ITARGETSR40_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR40_GICD_ITARGETSR40_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR40_GICD_ITARGETSR40_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR40_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR41 */

#define CSL_GIC400_GICD_ITARGETSR41_GICD_ITARGETSR41_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR41_GICD_ITARGETSR41_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR41_GICD_ITARGETSR41_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR41_GICD_ITARGETSR41_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR41_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR42 */

#define CSL_GIC400_GICD_ITARGETSR42_GICD_ITARGETSR42_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR42_GICD_ITARGETSR42_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR42_GICD_ITARGETSR42_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR42_GICD_ITARGETSR42_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR42_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR43 */

#define CSL_GIC400_GICD_ITARGETSR43_GICD_ITARGETSR43_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR43_GICD_ITARGETSR43_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR43_GICD_ITARGETSR43_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR43_GICD_ITARGETSR43_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR43_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR44 */

#define CSL_GIC400_GICD_ITARGETSR44_GICD_ITARGETSR44_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR44_GICD_ITARGETSR44_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR44_GICD_ITARGETSR44_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR44_GICD_ITARGETSR44_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR44_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR45 */

#define CSL_GIC400_GICD_ITARGETSR45_GICD_ITARGETSR45_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR45_GICD_ITARGETSR45_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR45_GICD_ITARGETSR45_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR45_GICD_ITARGETSR45_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR45_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR46 */

#define CSL_GIC400_GICD_ITARGETSR46_GICD_ITARGETSR46_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR46_GICD_ITARGETSR46_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR46_GICD_ITARGETSR46_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR46_GICD_ITARGETSR46_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR46_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR47 */

#define CSL_GIC400_GICD_ITARGETSR47_GICD_ITARGETSR47_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR47_GICD_ITARGETSR47_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR47_GICD_ITARGETSR47_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR47_GICD_ITARGETSR47_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR47_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR48 */

#define CSL_GIC400_GICD_ITARGETSR48_GICD_ITARGETSR48_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR48_GICD_ITARGETSR48_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR48_GICD_ITARGETSR48_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR48_GICD_ITARGETSR48_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR48_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR49 */

#define CSL_GIC400_GICD_ITARGETSR49_GICD_ITARGETSR49_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR49_GICD_ITARGETSR49_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR49_GICD_ITARGETSR49_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR49_GICD_ITARGETSR49_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR49_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR50 */

#define CSL_GIC400_GICD_ITARGETSR50_GICD_ITARGETSR50_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR50_GICD_ITARGETSR50_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR50_GICD_ITARGETSR50_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR50_GICD_ITARGETSR50_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR50_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR51 */

#define CSL_GIC400_GICD_ITARGETSR51_GICD_ITARGETSR51_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR51_GICD_ITARGETSR51_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR51_GICD_ITARGETSR51_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR51_GICD_ITARGETSR51_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR51_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR52 */

#define CSL_GIC400_GICD_ITARGETSR52_GICD_ITARGETSR52_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR52_GICD_ITARGETSR52_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR52_GICD_ITARGETSR52_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR52_GICD_ITARGETSR52_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR52_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR53 */

#define CSL_GIC400_GICD_ITARGETSR53_GICD_ITARGETSR53_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR53_GICD_ITARGETSR53_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR53_GICD_ITARGETSR53_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR53_GICD_ITARGETSR53_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR53_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR54 */

#define CSL_GIC400_GICD_ITARGETSR54_GICD_ITARGETSR54_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR54_GICD_ITARGETSR54_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR54_GICD_ITARGETSR54_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR54_GICD_ITARGETSR54_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR54_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR55 */

#define CSL_GIC400_GICD_ITARGETSR55_GICD_ITARGETSR55_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR55_GICD_ITARGETSR55_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR55_GICD_ITARGETSR55_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR55_GICD_ITARGETSR55_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR55_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR56 */

#define CSL_GIC400_GICD_ITARGETSR56_GICD_ITARGETSR56_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR56_GICD_ITARGETSR56_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR56_GICD_ITARGETSR56_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR56_GICD_ITARGETSR56_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR56_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR57 */

#define CSL_GIC400_GICD_ITARGETSR57_GICD_ITARGETSR57_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR57_GICD_ITARGETSR57_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR57_GICD_ITARGETSR57_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR57_GICD_ITARGETSR57_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR57_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR58 */

#define CSL_GIC400_GICD_ITARGETSR58_GICD_ITARGETSR58_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR58_GICD_ITARGETSR58_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR58_GICD_ITARGETSR58_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR58_GICD_ITARGETSR58_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR58_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR59 */

#define CSL_GIC400_GICD_ITARGETSR59_GICD_ITARGETSR59_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR59_GICD_ITARGETSR59_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR59_GICD_ITARGETSR59_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR59_GICD_ITARGETSR59_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR59_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR60 */

#define CSL_GIC400_GICD_ITARGETSR60_GICD_ITARGETSR60_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR60_GICD_ITARGETSR60_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR60_GICD_ITARGETSR60_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR60_GICD_ITARGETSR60_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR60_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR61 */

#define CSL_GIC400_GICD_ITARGETSR61_GICD_ITARGETSR61_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR61_GICD_ITARGETSR61_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR61_GICD_ITARGETSR61_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR61_GICD_ITARGETSR61_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR61_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR62 */

#define CSL_GIC400_GICD_ITARGETSR62_GICD_ITARGETSR62_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR62_GICD_ITARGETSR62_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR62_GICD_ITARGETSR62_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR62_GICD_ITARGETSR62_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR62_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR63 */

#define CSL_GIC400_GICD_ITARGETSR63_GICD_ITARGETSR63_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR63_GICD_ITARGETSR63_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR63_GICD_ITARGETSR63_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR63_GICD_ITARGETSR63_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR63_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR64 */

#define CSL_GIC400_GICD_ITARGETSR64_GICD_ITARGETSR64_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR64_GICD_ITARGETSR64_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR64_GICD_ITARGETSR64_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR64_GICD_ITARGETSR64_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR64_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR65 */

#define CSL_GIC400_GICD_ITARGETSR65_GICD_ITARGETSR65_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR65_GICD_ITARGETSR65_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR65_GICD_ITARGETSR65_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR65_GICD_ITARGETSR65_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR65_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR66 */

#define CSL_GIC400_GICD_ITARGETSR66_GICD_ITARGETSR66_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR66_GICD_ITARGETSR66_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR66_GICD_ITARGETSR66_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR66_GICD_ITARGETSR66_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR66_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR67 */

#define CSL_GIC400_GICD_ITARGETSR67_GICD_ITARGETSR67_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR67_GICD_ITARGETSR67_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR67_GICD_ITARGETSR67_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR67_GICD_ITARGETSR67_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR67_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR68 */

#define CSL_GIC400_GICD_ITARGETSR68_GICD_ITARGETSR68_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR68_GICD_ITARGETSR68_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR68_GICD_ITARGETSR68_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR68_GICD_ITARGETSR68_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR68_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR69 */

#define CSL_GIC400_GICD_ITARGETSR69_GICD_ITARGETSR69_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR69_GICD_ITARGETSR69_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR69_GICD_ITARGETSR69_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR69_GICD_ITARGETSR69_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR69_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR70 */

#define CSL_GIC400_GICD_ITARGETSR70_GICD_ITARGETSR70_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR70_GICD_ITARGETSR70_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR70_GICD_ITARGETSR70_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR70_GICD_ITARGETSR70_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR70_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR71 */

#define CSL_GIC400_GICD_ITARGETSR71_GICD_ITARGETSR71_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR71_GICD_ITARGETSR71_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR71_GICD_ITARGETSR71_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR71_GICD_ITARGETSR71_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR71_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR72 */

#define CSL_GIC400_GICD_ITARGETSR72_GICD_ITARGETSR72_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR72_GICD_ITARGETSR72_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR72_GICD_ITARGETSR72_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR72_GICD_ITARGETSR72_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR72_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR73 */

#define CSL_GIC400_GICD_ITARGETSR73_GICD_ITARGETSR73_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR73_GICD_ITARGETSR73_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR73_GICD_ITARGETSR73_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR73_GICD_ITARGETSR73_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR73_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR74 */

#define CSL_GIC400_GICD_ITARGETSR74_GICD_ITARGETSR74_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR74_GICD_ITARGETSR74_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR74_GICD_ITARGETSR74_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR74_GICD_ITARGETSR74_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR74_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR75 */

#define CSL_GIC400_GICD_ITARGETSR75_GICD_ITARGETSR75_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR75_GICD_ITARGETSR75_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR75_GICD_ITARGETSR75_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR75_GICD_ITARGETSR75_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR75_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR76 */

#define CSL_GIC400_GICD_ITARGETSR76_GICD_ITARGETSR76_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR76_GICD_ITARGETSR76_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR76_GICD_ITARGETSR76_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR76_GICD_ITARGETSR76_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR76_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR77 */

#define CSL_GIC400_GICD_ITARGETSR77_GICD_ITARGETSR77_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR77_GICD_ITARGETSR77_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR77_GICD_ITARGETSR77_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR77_GICD_ITARGETSR77_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR77_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR78 */

#define CSL_GIC400_GICD_ITARGETSR78_GICD_ITARGETSR78_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR78_GICD_ITARGETSR78_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR78_GICD_ITARGETSR78_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR78_GICD_ITARGETSR78_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR78_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR79 */

#define CSL_GIC400_GICD_ITARGETSR79_GICD_ITARGETSR79_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR79_GICD_ITARGETSR79_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR79_GICD_ITARGETSR79_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR79_GICD_ITARGETSR79_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR79_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR80 */

#define CSL_GIC400_GICD_ITARGETSR80_GICD_ITARGETSR80_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR80_GICD_ITARGETSR80_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR80_GICD_ITARGETSR80_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR80_GICD_ITARGETSR80_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR80_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR81 */

#define CSL_GIC400_GICD_ITARGETSR81_GICD_ITARGETSR81_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR81_GICD_ITARGETSR81_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR81_GICD_ITARGETSR81_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR81_GICD_ITARGETSR81_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR81_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR82 */

#define CSL_GIC400_GICD_ITARGETSR82_GICD_ITARGETSR82_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR82_GICD_ITARGETSR82_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR82_GICD_ITARGETSR82_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR82_GICD_ITARGETSR82_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR82_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR83 */

#define CSL_GIC400_GICD_ITARGETSR83_GICD_ITARGETSR83_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR83_GICD_ITARGETSR83_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR83_GICD_ITARGETSR83_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR83_GICD_ITARGETSR83_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR83_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR84 */

#define CSL_GIC400_GICD_ITARGETSR84_GICD_ITARGETSR84_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR84_GICD_ITARGETSR84_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR84_GICD_ITARGETSR84_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR84_GICD_ITARGETSR84_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR84_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR85 */

#define CSL_GIC400_GICD_ITARGETSR85_GICD_ITARGETSR85_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR85_GICD_ITARGETSR85_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR85_GICD_ITARGETSR85_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR85_GICD_ITARGETSR85_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR85_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR86 */

#define CSL_GIC400_GICD_ITARGETSR86_GICD_ITARGETSR86_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR86_GICD_ITARGETSR86_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR86_GICD_ITARGETSR86_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR86_GICD_ITARGETSR86_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR86_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR87 */

#define CSL_GIC400_GICD_ITARGETSR87_GICD_ITARGETSR87_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR87_GICD_ITARGETSR87_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR87_GICD_ITARGETSR87_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR87_GICD_ITARGETSR87_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR87_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR88 */

#define CSL_GIC400_GICD_ITARGETSR88_GICD_ITARGETSR88_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR88_GICD_ITARGETSR88_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR88_GICD_ITARGETSR88_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR88_GICD_ITARGETSR88_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR88_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR89 */

#define CSL_GIC400_GICD_ITARGETSR89_GICD_ITARGETSR89_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR89_GICD_ITARGETSR89_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR89_GICD_ITARGETSR89_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR89_GICD_ITARGETSR89_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR89_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR90 */

#define CSL_GIC400_GICD_ITARGETSR90_GICD_ITARGETSR90_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR90_GICD_ITARGETSR90_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR90_GICD_ITARGETSR90_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR90_GICD_ITARGETSR90_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR90_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR91 */

#define CSL_GIC400_GICD_ITARGETSR91_GICD_ITARGETSR91_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR91_GICD_ITARGETSR91_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR91_GICD_ITARGETSR91_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR91_GICD_ITARGETSR91_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR91_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR92 */

#define CSL_GIC400_GICD_ITARGETSR92_GICD_ITARGETSR92_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR92_GICD_ITARGETSR92_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR92_GICD_ITARGETSR92_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR92_GICD_ITARGETSR92_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR92_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR93 */

#define CSL_GIC400_GICD_ITARGETSR93_GICD_ITARGETSR93_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR93_GICD_ITARGETSR93_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR93_GICD_ITARGETSR93_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR93_GICD_ITARGETSR93_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR93_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR94 */

#define CSL_GIC400_GICD_ITARGETSR94_GICD_ITARGETSR94_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR94_GICD_ITARGETSR94_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR94_GICD_ITARGETSR94_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR94_GICD_ITARGETSR94_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR94_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR95 */

#define CSL_GIC400_GICD_ITARGETSR95_GICD_ITARGETSR95_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR95_GICD_ITARGETSR95_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR95_GICD_ITARGETSR95_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR95_GICD_ITARGETSR95_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR95_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR96 */

#define CSL_GIC400_GICD_ITARGETSR96_GICD_ITARGETSR96_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR96_GICD_ITARGETSR96_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR96_GICD_ITARGETSR96_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR96_GICD_ITARGETSR96_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR96_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR97 */

#define CSL_GIC400_GICD_ITARGETSR97_GICD_ITARGETSR97_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR97_GICD_ITARGETSR97_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR97_GICD_ITARGETSR97_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR97_GICD_ITARGETSR97_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR97_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR98 */

#define CSL_GIC400_GICD_ITARGETSR98_GICD_ITARGETSR98_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR98_GICD_ITARGETSR98_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR98_GICD_ITARGETSR98_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR98_GICD_ITARGETSR98_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR98_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR99 */

#define CSL_GIC400_GICD_ITARGETSR99_GICD_ITARGETSR99_MASK       (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR99_GICD_ITARGETSR99_SHIFT      (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR99_GICD_ITARGETSR99_RESETVAL   (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR99_GICD_ITARGETSR99_MAX        (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR99_RESETVAL                    (0x00000000U)

/* GICD_ITARGETSR100 */

#define CSL_GIC400_GICD_ITARGETSR100_GICD_ITARGETSR100_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR100_GICD_ITARGETSR100_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR100_GICD_ITARGETSR100_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR100_GICD_ITARGETSR100_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR100_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR101 */

#define CSL_GIC400_GICD_ITARGETSR101_GICD_ITARGETSR101_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR101_GICD_ITARGETSR101_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR101_GICD_ITARGETSR101_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR101_GICD_ITARGETSR101_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR101_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR102 */

#define CSL_GIC400_GICD_ITARGETSR102_GICD_ITARGETSR102_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR102_GICD_ITARGETSR102_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR102_GICD_ITARGETSR102_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR102_GICD_ITARGETSR102_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR102_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR103 */

#define CSL_GIC400_GICD_ITARGETSR103_GICD_ITARGETSR103_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR103_GICD_ITARGETSR103_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR103_GICD_ITARGETSR103_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR103_GICD_ITARGETSR103_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR103_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR104 */

#define CSL_GIC400_GICD_ITARGETSR104_GICD_ITARGETSR104_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR104_GICD_ITARGETSR104_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR104_GICD_ITARGETSR104_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR104_GICD_ITARGETSR104_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR104_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR105 */

#define CSL_GIC400_GICD_ITARGETSR105_GICD_ITARGETSR105_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR105_GICD_ITARGETSR105_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR105_GICD_ITARGETSR105_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR105_GICD_ITARGETSR105_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR105_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR106 */

#define CSL_GIC400_GICD_ITARGETSR106_GICD_ITARGETSR106_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR106_GICD_ITARGETSR106_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR106_GICD_ITARGETSR106_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR106_GICD_ITARGETSR106_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR106_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR107 */

#define CSL_GIC400_GICD_ITARGETSR107_GICD_ITARGETSR107_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR107_GICD_ITARGETSR107_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR107_GICD_ITARGETSR107_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR107_GICD_ITARGETSR107_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR107_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR108 */

#define CSL_GIC400_GICD_ITARGETSR108_GICD_ITARGETSR108_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR108_GICD_ITARGETSR108_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR108_GICD_ITARGETSR108_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR108_GICD_ITARGETSR108_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR108_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR109 */

#define CSL_GIC400_GICD_ITARGETSR109_GICD_ITARGETSR109_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR109_GICD_ITARGETSR109_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR109_GICD_ITARGETSR109_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR109_GICD_ITARGETSR109_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR109_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR110 */

#define CSL_GIC400_GICD_ITARGETSR110_GICD_ITARGETSR110_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR110_GICD_ITARGETSR110_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR110_GICD_ITARGETSR110_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR110_GICD_ITARGETSR110_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR110_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR111 */

#define CSL_GIC400_GICD_ITARGETSR111_GICD_ITARGETSR111_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR111_GICD_ITARGETSR111_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR111_GICD_ITARGETSR111_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR111_GICD_ITARGETSR111_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR111_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR112 */

#define CSL_GIC400_GICD_ITARGETSR112_GICD_ITARGETSR112_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR112_GICD_ITARGETSR112_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR112_GICD_ITARGETSR112_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR112_GICD_ITARGETSR112_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR112_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR113 */

#define CSL_GIC400_GICD_ITARGETSR113_GICD_ITARGETSR113_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR113_GICD_ITARGETSR113_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR113_GICD_ITARGETSR113_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR113_GICD_ITARGETSR113_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR113_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR114 */

#define CSL_GIC400_GICD_ITARGETSR114_GICD_ITARGETSR114_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR114_GICD_ITARGETSR114_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR114_GICD_ITARGETSR114_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR114_GICD_ITARGETSR114_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR114_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR115 */

#define CSL_GIC400_GICD_ITARGETSR115_GICD_ITARGETSR115_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR115_GICD_ITARGETSR115_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR115_GICD_ITARGETSR115_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR115_GICD_ITARGETSR115_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR115_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR116 */

#define CSL_GIC400_GICD_ITARGETSR116_GICD_ITARGETSR116_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR116_GICD_ITARGETSR116_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR116_GICD_ITARGETSR116_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR116_GICD_ITARGETSR116_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR116_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR117 */

#define CSL_GIC400_GICD_ITARGETSR117_GICD_ITARGETSR117_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR117_GICD_ITARGETSR117_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR117_GICD_ITARGETSR117_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR117_GICD_ITARGETSR117_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR117_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR118 */

#define CSL_GIC400_GICD_ITARGETSR118_GICD_ITARGETSR118_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR118_GICD_ITARGETSR118_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR118_GICD_ITARGETSR118_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR118_GICD_ITARGETSR118_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR118_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR119 */

#define CSL_GIC400_GICD_ITARGETSR119_GICD_ITARGETSR119_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR119_GICD_ITARGETSR119_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR119_GICD_ITARGETSR119_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR119_GICD_ITARGETSR119_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR119_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR120 */

#define CSL_GIC400_GICD_ITARGETSR120_GICD_ITARGETSR120_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR120_GICD_ITARGETSR120_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR120_GICD_ITARGETSR120_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR120_GICD_ITARGETSR120_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR120_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR121 */

#define CSL_GIC400_GICD_ITARGETSR121_GICD_ITARGETSR121_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR121_GICD_ITARGETSR121_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR121_GICD_ITARGETSR121_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR121_GICD_ITARGETSR121_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR121_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR122 */

#define CSL_GIC400_GICD_ITARGETSR122_GICD_ITARGETSR122_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR122_GICD_ITARGETSR122_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR122_GICD_ITARGETSR122_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR122_GICD_ITARGETSR122_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR122_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR123 */

#define CSL_GIC400_GICD_ITARGETSR123_GICD_ITARGETSR123_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR123_GICD_ITARGETSR123_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR123_GICD_ITARGETSR123_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR123_GICD_ITARGETSR123_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR123_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR124 */

#define CSL_GIC400_GICD_ITARGETSR124_GICD_ITARGETSR124_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR124_GICD_ITARGETSR124_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR124_GICD_ITARGETSR124_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR124_GICD_ITARGETSR124_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR124_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR125 */

#define CSL_GIC400_GICD_ITARGETSR125_GICD_ITARGETSR125_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR125_GICD_ITARGETSR125_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR125_GICD_ITARGETSR125_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR125_GICD_ITARGETSR125_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR125_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR126 */

#define CSL_GIC400_GICD_ITARGETSR126_GICD_ITARGETSR126_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR126_GICD_ITARGETSR126_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR126_GICD_ITARGETSR126_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR126_GICD_ITARGETSR126_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR126_RESETVAL                   (0x00000000U)

/* GICD_ITARGETSR127 */

#define CSL_GIC400_GICD_ITARGETSR127_GICD_ITARGETSR127_MASK     (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ITARGETSR127_GICD_ITARGETSR127_SHIFT    (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR127_GICD_ITARGETSR127_RESETVAL  (0x00000000U)
#define CSL_GIC400_GICD_ITARGETSR127_GICD_ITARGETSR127_MAX      (0xffffffffU)

#define CSL_GIC400_GICD_ITARGETSR127_RESETVAL                   (0x00000000U)

/* GICD_ICFGR0 */

#define CSL_GIC400_GICD_ICFGR0_GICD_ICFGR0_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR0_GICD_ICFGR0_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_ICFGR0_GICD_ICFGR0_RESETVAL             (0xaaaaaaaaU)
#define CSL_GIC400_GICD_ICFGR0_GICD_ICFGR0_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR0_RESETVAL                         (0xaaaaaaaaU)

/* GICD_ICFGR1 */

#define CSL_GIC400_GICD_ICFGR1_GICD_ICFGR1_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR1_GICD_ICFGR1_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_ICFGR1_GICD_ICFGR1_RESETVAL             (0x55540000U)
#define CSL_GIC400_GICD_ICFGR1_GICD_ICFGR1_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR1_RESETVAL                         (0x55540000U)

/* GICD_ICFGR2 */

#define CSL_GIC400_GICD_ICFGR2_GICD_ICFGR2_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR2_GICD_ICFGR2_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_ICFGR2_GICD_ICFGR2_RESETVAL             (0x55555555U)
#define CSL_GIC400_GICD_ICFGR2_GICD_ICFGR2_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR2_RESETVAL                         (0x55555555U)

/* GICD_ICFGR3 */

#define CSL_GIC400_GICD_ICFGR3_GICD_ICFGR3_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR3_GICD_ICFGR3_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_ICFGR3_GICD_ICFGR3_RESETVAL             (0x55555555U)
#define CSL_GIC400_GICD_ICFGR3_GICD_ICFGR3_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR3_RESETVAL                         (0x55555555U)

/* GICD_ICFGR4 */

#define CSL_GIC400_GICD_ICFGR4_GICD_ICFGR4_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR4_GICD_ICFGR4_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_ICFGR4_GICD_ICFGR4_RESETVAL             (0x55555555U)
#define CSL_GIC400_GICD_ICFGR4_GICD_ICFGR4_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR4_RESETVAL                         (0x55555555U)

/* GICD_ICFGR5 */

#define CSL_GIC400_GICD_ICFGR5_GICD_ICFGR5_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR5_GICD_ICFGR5_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_ICFGR5_GICD_ICFGR5_RESETVAL             (0x55555555U)
#define CSL_GIC400_GICD_ICFGR5_GICD_ICFGR5_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR5_RESETVAL                         (0x55555555U)

/* GICD_ICFGR6 */

#define CSL_GIC400_GICD_ICFGR6_GICD_ICFGR6_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR6_GICD_ICFGR6_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_ICFGR6_GICD_ICFGR6_RESETVAL             (0x55555555U)
#define CSL_GIC400_GICD_ICFGR6_GICD_ICFGR6_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR6_RESETVAL                         (0x55555555U)

/* GICD_ICFGR7 */

#define CSL_GIC400_GICD_ICFGR7_GICD_ICFGR7_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR7_GICD_ICFGR7_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_ICFGR7_GICD_ICFGR7_RESETVAL             (0x55555555U)
#define CSL_GIC400_GICD_ICFGR7_GICD_ICFGR7_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR7_RESETVAL                         (0x55555555U)

/* GICD_ICFGR8 */

#define CSL_GIC400_GICD_ICFGR8_GICD_ICFGR8_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR8_GICD_ICFGR8_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_ICFGR8_GICD_ICFGR8_RESETVAL             (0x55555555U)
#define CSL_GIC400_GICD_ICFGR8_GICD_ICFGR8_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR8_RESETVAL                         (0x55555555U)

/* GICD_ICFGR9 */

#define CSL_GIC400_GICD_ICFGR9_GICD_ICFGR9_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR9_GICD_ICFGR9_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_ICFGR9_GICD_ICFGR9_RESETVAL             (0x55555555U)
#define CSL_GIC400_GICD_ICFGR9_GICD_ICFGR9_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR9_RESETVAL                         (0x55555555U)

/* GICD_ICFGR10 */

#define CSL_GIC400_GICD_ICFGR10_GICD_ICFGR10_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR10_GICD_ICFGR10_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR10_GICD_ICFGR10_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR10_GICD_ICFGR10_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR10_RESETVAL                        (0x55555555U)

/* GICD_ICFGR11 */

#define CSL_GIC400_GICD_ICFGR11_GICD_ICFGR11_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR11_GICD_ICFGR11_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR11_GICD_ICFGR11_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR11_GICD_ICFGR11_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR11_RESETVAL                        (0x55555555U)

/* GICD_ICFGR12 */

#define CSL_GIC400_GICD_ICFGR12_GICD_ICFGR12_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR12_GICD_ICFGR12_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR12_GICD_ICFGR12_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR12_GICD_ICFGR12_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR12_RESETVAL                        (0x55555555U)

/* GICD_ICFGR13 */

#define CSL_GIC400_GICD_ICFGR13_GICD_ICFGR13_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR13_GICD_ICFGR13_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR13_GICD_ICFGR13_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR13_GICD_ICFGR13_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR13_RESETVAL                        (0x55555555U)

/* GICD_ICFGR14 */

#define CSL_GIC400_GICD_ICFGR14_GICD_ICFGR14_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR14_GICD_ICFGR14_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR14_GICD_ICFGR14_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR14_GICD_ICFGR14_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR14_RESETVAL                        (0x55555555U)

/* GICD_ICFGR15 */

#define CSL_GIC400_GICD_ICFGR15_GICD_ICFGR15_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR15_GICD_ICFGR15_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR15_GICD_ICFGR15_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR15_GICD_ICFGR15_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR15_RESETVAL                        (0x55555555U)

/* GICD_ICFGR16 */

#define CSL_GIC400_GICD_ICFGR16_GICD_ICFGR16_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR16_GICD_ICFGR16_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR16_GICD_ICFGR16_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR16_GICD_ICFGR16_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR16_RESETVAL                        (0x55555555U)

/* GICD_ICFGR17 */

#define CSL_GIC400_GICD_ICFGR17_GICD_ICFGR17_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR17_GICD_ICFGR17_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR17_GICD_ICFGR17_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR17_GICD_ICFGR17_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR17_RESETVAL                        (0x55555555U)

/* GICD_ICFGR18 */

#define CSL_GIC400_GICD_ICFGR18_GICD_ICFGR18_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR18_GICD_ICFGR18_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR18_GICD_ICFGR18_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR18_GICD_ICFGR18_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR18_RESETVAL                        (0x55555555U)

/* GICD_ICFGR19 */

#define CSL_GIC400_GICD_ICFGR19_GICD_ICFGR19_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR19_GICD_ICFGR19_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR19_GICD_ICFGR19_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR19_GICD_ICFGR19_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR19_RESETVAL                        (0x55555555U)

/* GICD_ICFGR20 */

#define CSL_GIC400_GICD_ICFGR20_GICD_ICFGR20_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR20_GICD_ICFGR20_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR20_GICD_ICFGR20_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR20_GICD_ICFGR20_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR20_RESETVAL                        (0x55555555U)

/* GICD_ICFGR21 */

#define CSL_GIC400_GICD_ICFGR21_GICD_ICFGR21_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR21_GICD_ICFGR21_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR21_GICD_ICFGR21_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR21_GICD_ICFGR21_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR21_RESETVAL                        (0x55555555U)

/* GICD_ICFGR22 */

#define CSL_GIC400_GICD_ICFGR22_GICD_ICFGR22_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR22_GICD_ICFGR22_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR22_GICD_ICFGR22_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR22_GICD_ICFGR22_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR22_RESETVAL                        (0x55555555U)

/* GICD_ICFGR23 */

#define CSL_GIC400_GICD_ICFGR23_GICD_ICFGR23_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR23_GICD_ICFGR23_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR23_GICD_ICFGR23_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR23_GICD_ICFGR23_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR23_RESETVAL                        (0x55555555U)

/* GICD_ICFGR24 */

#define CSL_GIC400_GICD_ICFGR24_GICD_ICFGR24_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR24_GICD_ICFGR24_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR24_GICD_ICFGR24_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR24_GICD_ICFGR24_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR24_RESETVAL                        (0x55555555U)

/* GICD_ICFGR25 */

#define CSL_GIC400_GICD_ICFGR25_GICD_ICFGR25_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR25_GICD_ICFGR25_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR25_GICD_ICFGR25_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR25_GICD_ICFGR25_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR25_RESETVAL                        (0x55555555U)

/* GICD_ICFGR26 */

#define CSL_GIC400_GICD_ICFGR26_GICD_ICFGR26_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR26_GICD_ICFGR26_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR26_GICD_ICFGR26_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR26_GICD_ICFGR26_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR26_RESETVAL                        (0x55555555U)

/* GICD_ICFGR27 */

#define CSL_GIC400_GICD_ICFGR27_GICD_ICFGR27_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR27_GICD_ICFGR27_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR27_GICD_ICFGR27_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR27_GICD_ICFGR27_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR27_RESETVAL                        (0x55555555U)

/* GICD_ICFGR28 */

#define CSL_GIC400_GICD_ICFGR28_GICD_ICFGR28_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR28_GICD_ICFGR28_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR28_GICD_ICFGR28_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR28_GICD_ICFGR28_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR28_RESETVAL                        (0x55555555U)

/* GICD_ICFGR29 */

#define CSL_GIC400_GICD_ICFGR29_GICD_ICFGR29_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR29_GICD_ICFGR29_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR29_GICD_ICFGR29_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR29_GICD_ICFGR29_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR29_RESETVAL                        (0x55555555U)

/* GICD_ICFGR30 */

#define CSL_GIC400_GICD_ICFGR30_GICD_ICFGR30_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR30_GICD_ICFGR30_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR30_GICD_ICFGR30_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR30_GICD_ICFGR30_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR30_RESETVAL                        (0x55555555U)

/* GICD_ICFGR31 */

#define CSL_GIC400_GICD_ICFGR31_GICD_ICFGR31_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_ICFGR31_GICD_ICFGR31_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_ICFGR31_GICD_ICFGR31_RESETVAL           (0x55555555U)
#define CSL_GIC400_GICD_ICFGR31_GICD_ICFGR31_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_ICFGR31_RESETVAL                        (0x55555555U)

/* GICD_PPISR */

#define CSL_GIC400_GICD_PPISR_GICD_PPISR_MASK                   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_PPISR_GICD_PPISR_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICD_PPISR_GICD_PPISR_RESETVAL               (0x00000000U)
#define CSL_GIC400_GICD_PPISR_GICD_PPISR_MAX                    (0xffffffffU)

#define CSL_GIC400_GICD_PPISR_RESETVAL                          (0x00000000U)

/* GICD_SPISR0 */

#define CSL_GIC400_GICD_SPISR0_IRQS31_MASK                      (0x80000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS31_SHIFT                     (0x0000001FU)
#define CSL_GIC400_GICD_SPISR0_IRQS31_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS31_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS30_MASK                      (0x40000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS30_SHIFT                     (0x0000001EU)
#define CSL_GIC400_GICD_SPISR0_IRQS30_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS30_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS29_MASK                      (0x20000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS29_SHIFT                     (0x0000001DU)
#define CSL_GIC400_GICD_SPISR0_IRQS29_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS29_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS28_MASK                      (0x10000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS28_SHIFT                     (0x0000001CU)
#define CSL_GIC400_GICD_SPISR0_IRQS28_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS28_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS27_MASK                      (0x08000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS27_SHIFT                     (0x0000001BU)
#define CSL_GIC400_GICD_SPISR0_IRQS27_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS27_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS26_MASK                      (0x04000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS26_SHIFT                     (0x0000001AU)
#define CSL_GIC400_GICD_SPISR0_IRQS26_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS26_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS25_MASK                      (0x02000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS25_SHIFT                     (0x00000019U)
#define CSL_GIC400_GICD_SPISR0_IRQS25_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS25_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS24_MASK                      (0x01000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS24_SHIFT                     (0x00000018U)
#define CSL_GIC400_GICD_SPISR0_IRQS24_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS24_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS23_MASK                      (0x00800000U)
#define CSL_GIC400_GICD_SPISR0_IRQS23_SHIFT                     (0x00000017U)
#define CSL_GIC400_GICD_SPISR0_IRQS23_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS23_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS22_MASK                      (0x00400000U)
#define CSL_GIC400_GICD_SPISR0_IRQS22_SHIFT                     (0x00000016U)
#define CSL_GIC400_GICD_SPISR0_IRQS22_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS22_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS21_MASK                      (0x00200000U)
#define CSL_GIC400_GICD_SPISR0_IRQS21_SHIFT                     (0x00000015U)
#define CSL_GIC400_GICD_SPISR0_IRQS21_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS21_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS20_MASK                      (0x00100000U)
#define CSL_GIC400_GICD_SPISR0_IRQS20_SHIFT                     (0x00000014U)
#define CSL_GIC400_GICD_SPISR0_IRQS20_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS20_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS19_MASK                      (0x00080000U)
#define CSL_GIC400_GICD_SPISR0_IRQS19_SHIFT                     (0x00000013U)
#define CSL_GIC400_GICD_SPISR0_IRQS19_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS19_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS18_MASK                      (0x00040000U)
#define CSL_GIC400_GICD_SPISR0_IRQS18_SHIFT                     (0x00000012U)
#define CSL_GIC400_GICD_SPISR0_IRQS18_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS18_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS17_MASK                      (0x00020000U)
#define CSL_GIC400_GICD_SPISR0_IRQS17_SHIFT                     (0x00000011U)
#define CSL_GIC400_GICD_SPISR0_IRQS17_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS17_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS16_MASK                      (0x00010000U)
#define CSL_GIC400_GICD_SPISR0_IRQS16_SHIFT                     (0x00000010U)
#define CSL_GIC400_GICD_SPISR0_IRQS16_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS16_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS15_MASK                      (0x00008000U)
#define CSL_GIC400_GICD_SPISR0_IRQS15_SHIFT                     (0x0000000FU)
#define CSL_GIC400_GICD_SPISR0_IRQS15_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS15_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS14_MASK                      (0x00004000U)
#define CSL_GIC400_GICD_SPISR0_IRQS14_SHIFT                     (0x0000000EU)
#define CSL_GIC400_GICD_SPISR0_IRQS14_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS14_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS13_MASK                      (0x00002000U)
#define CSL_GIC400_GICD_SPISR0_IRQS13_SHIFT                     (0x0000000DU)
#define CSL_GIC400_GICD_SPISR0_IRQS13_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS13_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS12_MASK                      (0x00001000U)
#define CSL_GIC400_GICD_SPISR0_IRQS12_SHIFT                     (0x0000000CU)
#define CSL_GIC400_GICD_SPISR0_IRQS12_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS12_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS11_MASK                      (0x00000800U)
#define CSL_GIC400_GICD_SPISR0_IRQS11_SHIFT                     (0x0000000BU)
#define CSL_GIC400_GICD_SPISR0_IRQS11_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS11_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS10_MASK                      (0x00000400U)
#define CSL_GIC400_GICD_SPISR0_IRQS10_SHIFT                     (0x0000000AU)
#define CSL_GIC400_GICD_SPISR0_IRQS10_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS10_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS9_MASK                       (0x00000200U)
#define CSL_GIC400_GICD_SPISR0_IRQS9_SHIFT                      (0x00000009U)
#define CSL_GIC400_GICD_SPISR0_IRQS9_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS9_MAX                        (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS8_MASK                       (0x00000100U)
#define CSL_GIC400_GICD_SPISR0_IRQS8_SHIFT                      (0x00000008U)
#define CSL_GIC400_GICD_SPISR0_IRQS8_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS8_MAX                        (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS7_MASK                       (0x00000080U)
#define CSL_GIC400_GICD_SPISR0_IRQS7_SHIFT                      (0x00000007U)
#define CSL_GIC400_GICD_SPISR0_IRQS7_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS7_MAX                        (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS6_MASK                       (0x00000040U)
#define CSL_GIC400_GICD_SPISR0_IRQS6_SHIFT                      (0x00000006U)
#define CSL_GIC400_GICD_SPISR0_IRQS6_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS6_MAX                        (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS5_MASK                       (0x00000020U)
#define CSL_GIC400_GICD_SPISR0_IRQS5_SHIFT                      (0x00000005U)
#define CSL_GIC400_GICD_SPISR0_IRQS5_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS5_MAX                        (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS4_MASK                       (0x00000010U)
#define CSL_GIC400_GICD_SPISR0_IRQS4_SHIFT                      (0x00000004U)
#define CSL_GIC400_GICD_SPISR0_IRQS4_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS4_MAX                        (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS3_MASK                       (0x00000008U)
#define CSL_GIC400_GICD_SPISR0_IRQS3_SHIFT                      (0x00000003U)
#define CSL_GIC400_GICD_SPISR0_IRQS3_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS3_MAX                        (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS2_MASK                       (0x00000004U)
#define CSL_GIC400_GICD_SPISR0_IRQS2_SHIFT                      (0x00000002U)
#define CSL_GIC400_GICD_SPISR0_IRQS2_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS2_MAX                        (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS1_MASK                       (0x00000002U)
#define CSL_GIC400_GICD_SPISR0_IRQS1_SHIFT                      (0x00000001U)
#define CSL_GIC400_GICD_SPISR0_IRQS1_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS1_MAX                        (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_IRQS0_MASK                       (0x00000001U)
#define CSL_GIC400_GICD_SPISR0_IRQS0_SHIFT                      (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS0_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICD_SPISR0_IRQS0_MAX                        (0x00000001U)

#define CSL_GIC400_GICD_SPISR0_RESETVAL                         (0x00000000U)

/* GICD_SPISR1 */

#define CSL_GIC400_GICD_SPISR1_IRQS63_MASK                      (0x80000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS63_SHIFT                     (0x0000001FU)
#define CSL_GIC400_GICD_SPISR1_IRQS63_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS63_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS62_MASK                      (0x40000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS62_SHIFT                     (0x0000001EU)
#define CSL_GIC400_GICD_SPISR1_IRQS62_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS62_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS61_MASK                      (0x20000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS61_SHIFT                     (0x0000001DU)
#define CSL_GIC400_GICD_SPISR1_IRQS61_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS61_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS60_MASK                      (0x10000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS60_SHIFT                     (0x0000001CU)
#define CSL_GIC400_GICD_SPISR1_IRQS60_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS60_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS59_MASK                      (0x08000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS59_SHIFT                     (0x0000001BU)
#define CSL_GIC400_GICD_SPISR1_IRQS59_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS59_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS58_MASK                      (0x04000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS58_SHIFT                     (0x0000001AU)
#define CSL_GIC400_GICD_SPISR1_IRQS58_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS58_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS57_MASK                      (0x02000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS57_SHIFT                     (0x00000019U)
#define CSL_GIC400_GICD_SPISR1_IRQS57_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS57_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS56_MASK                      (0x01000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS56_SHIFT                     (0x00000018U)
#define CSL_GIC400_GICD_SPISR1_IRQS56_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS56_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS55_MASK                      (0x00800000U)
#define CSL_GIC400_GICD_SPISR1_IRQS55_SHIFT                     (0x00000017U)
#define CSL_GIC400_GICD_SPISR1_IRQS55_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS55_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS54_MASK                      (0x00400000U)
#define CSL_GIC400_GICD_SPISR1_IRQS54_SHIFT                     (0x00000016U)
#define CSL_GIC400_GICD_SPISR1_IRQS54_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS54_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS53_MASK                      (0x00200000U)
#define CSL_GIC400_GICD_SPISR1_IRQS53_SHIFT                     (0x00000015U)
#define CSL_GIC400_GICD_SPISR1_IRQS53_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS53_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS52_MASK                      (0x00100000U)
#define CSL_GIC400_GICD_SPISR1_IRQS52_SHIFT                     (0x00000014U)
#define CSL_GIC400_GICD_SPISR1_IRQS52_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS52_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS51_MASK                      (0x00080000U)
#define CSL_GIC400_GICD_SPISR1_IRQS51_SHIFT                     (0x00000013U)
#define CSL_GIC400_GICD_SPISR1_IRQS51_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS51_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS50_MASK                      (0x00040000U)
#define CSL_GIC400_GICD_SPISR1_IRQS50_SHIFT                     (0x00000012U)
#define CSL_GIC400_GICD_SPISR1_IRQS50_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS50_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS49_MASK                      (0x00020000U)
#define CSL_GIC400_GICD_SPISR1_IRQS49_SHIFT                     (0x00000011U)
#define CSL_GIC400_GICD_SPISR1_IRQS49_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS49_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS48_MASK                      (0x00010000U)
#define CSL_GIC400_GICD_SPISR1_IRQS48_SHIFT                     (0x00000010U)
#define CSL_GIC400_GICD_SPISR1_IRQS48_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS48_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS47_MASK                      (0x00008000U)
#define CSL_GIC400_GICD_SPISR1_IRQS47_SHIFT                     (0x0000000FU)
#define CSL_GIC400_GICD_SPISR1_IRQS47_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS47_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS46_MASK                      (0x00004000U)
#define CSL_GIC400_GICD_SPISR1_IRQS46_SHIFT                     (0x0000000EU)
#define CSL_GIC400_GICD_SPISR1_IRQS46_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS46_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS45_MASK                      (0x00002000U)
#define CSL_GIC400_GICD_SPISR1_IRQS45_SHIFT                     (0x0000000DU)
#define CSL_GIC400_GICD_SPISR1_IRQS45_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS45_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS44_MASK                      (0x00001000U)
#define CSL_GIC400_GICD_SPISR1_IRQS44_SHIFT                     (0x0000000CU)
#define CSL_GIC400_GICD_SPISR1_IRQS44_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS44_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS43_MASK                      (0x00000800U)
#define CSL_GIC400_GICD_SPISR1_IRQS43_SHIFT                     (0x0000000BU)
#define CSL_GIC400_GICD_SPISR1_IRQS43_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS43_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS42_MASK                      (0x00000400U)
#define CSL_GIC400_GICD_SPISR1_IRQS42_SHIFT                     (0x0000000AU)
#define CSL_GIC400_GICD_SPISR1_IRQS42_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS42_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS41_MASK                      (0x00000200U)
#define CSL_GIC400_GICD_SPISR1_IRQS41_SHIFT                     (0x00000009U)
#define CSL_GIC400_GICD_SPISR1_IRQS41_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS41_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS40_MASK                      (0x00000100U)
#define CSL_GIC400_GICD_SPISR1_IRQS40_SHIFT                     (0x00000008U)
#define CSL_GIC400_GICD_SPISR1_IRQS40_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS40_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS39_MASK                      (0x00000080U)
#define CSL_GIC400_GICD_SPISR1_IRQS39_SHIFT                     (0x00000007U)
#define CSL_GIC400_GICD_SPISR1_IRQS39_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS39_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS38_MASK                      (0x00000040U)
#define CSL_GIC400_GICD_SPISR1_IRQS38_SHIFT                     (0x00000006U)
#define CSL_GIC400_GICD_SPISR1_IRQS38_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS38_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS37_MASK                      (0x00000020U)
#define CSL_GIC400_GICD_SPISR1_IRQS37_SHIFT                     (0x00000005U)
#define CSL_GIC400_GICD_SPISR1_IRQS37_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS37_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS36_MASK                      (0x00000010U)
#define CSL_GIC400_GICD_SPISR1_IRQS36_SHIFT                     (0x00000004U)
#define CSL_GIC400_GICD_SPISR1_IRQS36_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS36_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS35_MASK                      (0x00000008U)
#define CSL_GIC400_GICD_SPISR1_IRQS35_SHIFT                     (0x00000003U)
#define CSL_GIC400_GICD_SPISR1_IRQS35_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS35_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS34_MASK                      (0x00000004U)
#define CSL_GIC400_GICD_SPISR1_IRQS34_SHIFT                     (0x00000002U)
#define CSL_GIC400_GICD_SPISR1_IRQS34_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS34_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS33_MASK                      (0x00000002U)
#define CSL_GIC400_GICD_SPISR1_IRQS33_SHIFT                     (0x00000001U)
#define CSL_GIC400_GICD_SPISR1_IRQS33_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS33_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_IRQS32_MASK                      (0x00000001U)
#define CSL_GIC400_GICD_SPISR1_IRQS32_SHIFT                     (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS32_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR1_IRQS32_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR1_RESETVAL                         (0x00000000U)

/* GICD_SPISR2 */

#define CSL_GIC400_GICD_SPISR2_IRQS95_MASK                      (0x80000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS95_SHIFT                     (0x0000001FU)
#define CSL_GIC400_GICD_SPISR2_IRQS95_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS95_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS94_MASK                      (0x40000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS94_SHIFT                     (0x0000001EU)
#define CSL_GIC400_GICD_SPISR2_IRQS94_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS94_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS93_MASK                      (0x20000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS93_SHIFT                     (0x0000001DU)
#define CSL_GIC400_GICD_SPISR2_IRQS93_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS93_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS92_MASK                      (0x10000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS92_SHIFT                     (0x0000001CU)
#define CSL_GIC400_GICD_SPISR2_IRQS92_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS92_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS91_MASK                      (0x08000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS91_SHIFT                     (0x0000001BU)
#define CSL_GIC400_GICD_SPISR2_IRQS91_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS91_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS90_MASK                      (0x04000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS90_SHIFT                     (0x0000001AU)
#define CSL_GIC400_GICD_SPISR2_IRQS90_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS90_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS89_MASK                      (0x02000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS89_SHIFT                     (0x00000019U)
#define CSL_GIC400_GICD_SPISR2_IRQS89_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS89_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS88_MASK                      (0x01000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS88_SHIFT                     (0x00000018U)
#define CSL_GIC400_GICD_SPISR2_IRQS88_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS88_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS87_MASK                      (0x00800000U)
#define CSL_GIC400_GICD_SPISR2_IRQS87_SHIFT                     (0x00000017U)
#define CSL_GIC400_GICD_SPISR2_IRQS87_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS87_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS86_MASK                      (0x00400000U)
#define CSL_GIC400_GICD_SPISR2_IRQS86_SHIFT                     (0x00000016U)
#define CSL_GIC400_GICD_SPISR2_IRQS86_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS86_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS85_MASK                      (0x00200000U)
#define CSL_GIC400_GICD_SPISR2_IRQS85_SHIFT                     (0x00000015U)
#define CSL_GIC400_GICD_SPISR2_IRQS85_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS85_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS84_MASK                      (0x00100000U)
#define CSL_GIC400_GICD_SPISR2_IRQS84_SHIFT                     (0x00000014U)
#define CSL_GIC400_GICD_SPISR2_IRQS84_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS84_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS83_MASK                      (0x00080000U)
#define CSL_GIC400_GICD_SPISR2_IRQS83_SHIFT                     (0x00000013U)
#define CSL_GIC400_GICD_SPISR2_IRQS83_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS83_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS82_MASK                      (0x00040000U)
#define CSL_GIC400_GICD_SPISR2_IRQS82_SHIFT                     (0x00000012U)
#define CSL_GIC400_GICD_SPISR2_IRQS82_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS82_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS81_MASK                      (0x00020000U)
#define CSL_GIC400_GICD_SPISR2_IRQS81_SHIFT                     (0x00000011U)
#define CSL_GIC400_GICD_SPISR2_IRQS81_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS81_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS80_MASK                      (0x00010000U)
#define CSL_GIC400_GICD_SPISR2_IRQS80_SHIFT                     (0x00000010U)
#define CSL_GIC400_GICD_SPISR2_IRQS80_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS80_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS79_MASK                      (0x00008000U)
#define CSL_GIC400_GICD_SPISR2_IRQS79_SHIFT                     (0x0000000FU)
#define CSL_GIC400_GICD_SPISR2_IRQS79_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS79_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS78_MASK                      (0x00004000U)
#define CSL_GIC400_GICD_SPISR2_IRQS78_SHIFT                     (0x0000000EU)
#define CSL_GIC400_GICD_SPISR2_IRQS78_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS78_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS77_MASK                      (0x00002000U)
#define CSL_GIC400_GICD_SPISR2_IRQS77_SHIFT                     (0x0000000DU)
#define CSL_GIC400_GICD_SPISR2_IRQS77_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS77_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS76_MASK                      (0x00001000U)
#define CSL_GIC400_GICD_SPISR2_IRQS76_SHIFT                     (0x0000000CU)
#define CSL_GIC400_GICD_SPISR2_IRQS76_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS76_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS75_MASK                      (0x00000800U)
#define CSL_GIC400_GICD_SPISR2_IRQS75_SHIFT                     (0x0000000BU)
#define CSL_GIC400_GICD_SPISR2_IRQS75_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS75_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS74_MASK                      (0x00000400U)
#define CSL_GIC400_GICD_SPISR2_IRQS74_SHIFT                     (0x0000000AU)
#define CSL_GIC400_GICD_SPISR2_IRQS74_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS74_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS73_MASK                      (0x00000200U)
#define CSL_GIC400_GICD_SPISR2_IRQS73_SHIFT                     (0x00000009U)
#define CSL_GIC400_GICD_SPISR2_IRQS73_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS73_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS72_MASK                      (0x00000100U)
#define CSL_GIC400_GICD_SPISR2_IRQS72_SHIFT                     (0x00000008U)
#define CSL_GIC400_GICD_SPISR2_IRQS72_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS72_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS71_MASK                      (0x00000080U)
#define CSL_GIC400_GICD_SPISR2_IRQS71_SHIFT                     (0x00000007U)
#define CSL_GIC400_GICD_SPISR2_IRQS71_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS71_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS70_MASK                      (0x00000040U)
#define CSL_GIC400_GICD_SPISR2_IRQS70_SHIFT                     (0x00000006U)
#define CSL_GIC400_GICD_SPISR2_IRQS70_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS70_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS69_MASK                      (0x00000020U)
#define CSL_GIC400_GICD_SPISR2_IRQS69_SHIFT                     (0x00000005U)
#define CSL_GIC400_GICD_SPISR2_IRQS69_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS69_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS68_MASK                      (0x00000010U)
#define CSL_GIC400_GICD_SPISR2_IRQS68_SHIFT                     (0x00000004U)
#define CSL_GIC400_GICD_SPISR2_IRQS68_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS68_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS67_MASK                      (0x00000008U)
#define CSL_GIC400_GICD_SPISR2_IRQS67_SHIFT                     (0x00000003U)
#define CSL_GIC400_GICD_SPISR2_IRQS67_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS67_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS66_MASK                      (0x00000004U)
#define CSL_GIC400_GICD_SPISR2_IRQS66_SHIFT                     (0x00000002U)
#define CSL_GIC400_GICD_SPISR2_IRQS66_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS66_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS65_MASK                      (0x00000002U)
#define CSL_GIC400_GICD_SPISR2_IRQS65_SHIFT                     (0x00000001U)
#define CSL_GIC400_GICD_SPISR2_IRQS65_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS65_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_IRQS64_MASK                      (0x00000001U)
#define CSL_GIC400_GICD_SPISR2_IRQS64_SHIFT                     (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS64_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR2_IRQS64_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR2_RESETVAL                         (0x00000000U)

/* GICD_SPISR3 */

#define CSL_GIC400_GICD_SPISR3_IRQS127_MASK                     (0x80000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS127_SHIFT                    (0x0000001FU)
#define CSL_GIC400_GICD_SPISR3_IRQS127_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS127_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS126_MASK                     (0x40000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS126_SHIFT                    (0x0000001EU)
#define CSL_GIC400_GICD_SPISR3_IRQS126_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS126_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS125_MASK                     (0x20000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS125_SHIFT                    (0x0000001DU)
#define CSL_GIC400_GICD_SPISR3_IRQS125_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS125_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS124_MASK                     (0x10000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS124_SHIFT                    (0x0000001CU)
#define CSL_GIC400_GICD_SPISR3_IRQS124_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS124_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS123_MASK                     (0x08000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS123_SHIFT                    (0x0000001BU)
#define CSL_GIC400_GICD_SPISR3_IRQS123_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS123_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS122_MASK                     (0x04000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS122_SHIFT                    (0x0000001AU)
#define CSL_GIC400_GICD_SPISR3_IRQS122_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS122_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS121_MASK                     (0x02000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS121_SHIFT                    (0x00000019U)
#define CSL_GIC400_GICD_SPISR3_IRQS121_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS121_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS120_MASK                     (0x01000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS120_SHIFT                    (0x00000018U)
#define CSL_GIC400_GICD_SPISR3_IRQS120_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS120_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS119_MASK                     (0x00800000U)
#define CSL_GIC400_GICD_SPISR3_IRQS119_SHIFT                    (0x00000017U)
#define CSL_GIC400_GICD_SPISR3_IRQS119_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS119_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS118_MASK                     (0x00400000U)
#define CSL_GIC400_GICD_SPISR3_IRQS118_SHIFT                    (0x00000016U)
#define CSL_GIC400_GICD_SPISR3_IRQS118_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS118_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS117_MASK                     (0x00200000U)
#define CSL_GIC400_GICD_SPISR3_IRQS117_SHIFT                    (0x00000015U)
#define CSL_GIC400_GICD_SPISR3_IRQS117_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS117_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS116_MASK                     (0x00100000U)
#define CSL_GIC400_GICD_SPISR3_IRQS116_SHIFT                    (0x00000014U)
#define CSL_GIC400_GICD_SPISR3_IRQS116_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS116_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS115_MASK                     (0x00080000U)
#define CSL_GIC400_GICD_SPISR3_IRQS115_SHIFT                    (0x00000013U)
#define CSL_GIC400_GICD_SPISR3_IRQS115_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS115_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS114_MASK                     (0x00040000U)
#define CSL_GIC400_GICD_SPISR3_IRQS114_SHIFT                    (0x00000012U)
#define CSL_GIC400_GICD_SPISR3_IRQS114_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS114_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS113_MASK                     (0x00020000U)
#define CSL_GIC400_GICD_SPISR3_IRQS113_SHIFT                    (0x00000011U)
#define CSL_GIC400_GICD_SPISR3_IRQS113_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS113_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS112_MASK                     (0x00010000U)
#define CSL_GIC400_GICD_SPISR3_IRQS112_SHIFT                    (0x00000010U)
#define CSL_GIC400_GICD_SPISR3_IRQS112_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS112_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS111_MASK                     (0x00008000U)
#define CSL_GIC400_GICD_SPISR3_IRQS111_SHIFT                    (0x0000000FU)
#define CSL_GIC400_GICD_SPISR3_IRQS111_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS111_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS110_MASK                     (0x00004000U)
#define CSL_GIC400_GICD_SPISR3_IRQS110_SHIFT                    (0x0000000EU)
#define CSL_GIC400_GICD_SPISR3_IRQS110_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS110_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS109_MASK                     (0x00002000U)
#define CSL_GIC400_GICD_SPISR3_IRQS109_SHIFT                    (0x0000000DU)
#define CSL_GIC400_GICD_SPISR3_IRQS109_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS109_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS108_MASK                     (0x00001000U)
#define CSL_GIC400_GICD_SPISR3_IRQS108_SHIFT                    (0x0000000CU)
#define CSL_GIC400_GICD_SPISR3_IRQS108_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS108_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS107_MASK                     (0x00000800U)
#define CSL_GIC400_GICD_SPISR3_IRQS107_SHIFT                    (0x0000000BU)
#define CSL_GIC400_GICD_SPISR3_IRQS107_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS107_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS106_MASK                     (0x00000400U)
#define CSL_GIC400_GICD_SPISR3_IRQS106_SHIFT                    (0x0000000AU)
#define CSL_GIC400_GICD_SPISR3_IRQS106_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS106_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS105_MASK                     (0x00000200U)
#define CSL_GIC400_GICD_SPISR3_IRQS105_SHIFT                    (0x00000009U)
#define CSL_GIC400_GICD_SPISR3_IRQS105_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS105_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS104_MASK                     (0x00000100U)
#define CSL_GIC400_GICD_SPISR3_IRQS104_SHIFT                    (0x00000008U)
#define CSL_GIC400_GICD_SPISR3_IRQS104_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS104_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS103_MASK                     (0x00000080U)
#define CSL_GIC400_GICD_SPISR3_IRQS103_SHIFT                    (0x00000007U)
#define CSL_GIC400_GICD_SPISR3_IRQS103_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS103_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS102_MASK                     (0x00000040U)
#define CSL_GIC400_GICD_SPISR3_IRQS102_SHIFT                    (0x00000006U)
#define CSL_GIC400_GICD_SPISR3_IRQS102_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS102_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS101_MASK                     (0x00000020U)
#define CSL_GIC400_GICD_SPISR3_IRQS101_SHIFT                    (0x00000005U)
#define CSL_GIC400_GICD_SPISR3_IRQS101_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS101_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS100_MASK                     (0x00000010U)
#define CSL_GIC400_GICD_SPISR3_IRQS100_SHIFT                    (0x00000004U)
#define CSL_GIC400_GICD_SPISR3_IRQS100_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS100_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS99_MASK                      (0x00000008U)
#define CSL_GIC400_GICD_SPISR3_IRQS99_SHIFT                     (0x00000003U)
#define CSL_GIC400_GICD_SPISR3_IRQS99_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS99_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS98_MASK                      (0x00000004U)
#define CSL_GIC400_GICD_SPISR3_IRQS98_SHIFT                     (0x00000002U)
#define CSL_GIC400_GICD_SPISR3_IRQS98_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS98_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS97_MASK                      (0x00000002U)
#define CSL_GIC400_GICD_SPISR3_IRQS97_SHIFT                     (0x00000001U)
#define CSL_GIC400_GICD_SPISR3_IRQS97_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS97_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_IRQS96_MASK                      (0x00000001U)
#define CSL_GIC400_GICD_SPISR3_IRQS96_SHIFT                     (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS96_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SPISR3_IRQS96_MAX                       (0x00000001U)

#define CSL_GIC400_GICD_SPISR3_RESETVAL                         (0x00000000U)

/* GICD_SPISR4 */

#define CSL_GIC400_GICD_SPISR4_IRQS159_MASK                     (0x80000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS159_SHIFT                    (0x0000001FU)
#define CSL_GIC400_GICD_SPISR4_IRQS159_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS159_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS158_MASK                     (0x40000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS158_SHIFT                    (0x0000001EU)
#define CSL_GIC400_GICD_SPISR4_IRQS158_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS158_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS157_MASK                     (0x20000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS157_SHIFT                    (0x0000001DU)
#define CSL_GIC400_GICD_SPISR4_IRQS157_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS157_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS156_MASK                     (0x10000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS156_SHIFT                    (0x0000001CU)
#define CSL_GIC400_GICD_SPISR4_IRQS156_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS156_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS155_MASK                     (0x08000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS155_SHIFT                    (0x0000001BU)
#define CSL_GIC400_GICD_SPISR4_IRQS155_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS155_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS154_MASK                     (0x04000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS154_SHIFT                    (0x0000001AU)
#define CSL_GIC400_GICD_SPISR4_IRQS154_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS154_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS153_MASK                     (0x02000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS153_SHIFT                    (0x00000019U)
#define CSL_GIC400_GICD_SPISR4_IRQS153_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS153_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS152_MASK                     (0x01000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS152_SHIFT                    (0x00000018U)
#define CSL_GIC400_GICD_SPISR4_IRQS152_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS152_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS151_MASK                     (0x00800000U)
#define CSL_GIC400_GICD_SPISR4_IRQS151_SHIFT                    (0x00000017U)
#define CSL_GIC400_GICD_SPISR4_IRQS151_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS151_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS150_MASK                     (0x00400000U)
#define CSL_GIC400_GICD_SPISR4_IRQS150_SHIFT                    (0x00000016U)
#define CSL_GIC400_GICD_SPISR4_IRQS150_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS150_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS149_MASK                     (0x00200000U)
#define CSL_GIC400_GICD_SPISR4_IRQS149_SHIFT                    (0x00000015U)
#define CSL_GIC400_GICD_SPISR4_IRQS149_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS149_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS148_MASK                     (0x00100000U)
#define CSL_GIC400_GICD_SPISR4_IRQS148_SHIFT                    (0x00000014U)
#define CSL_GIC400_GICD_SPISR4_IRQS148_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS148_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS147_MASK                     (0x00080000U)
#define CSL_GIC400_GICD_SPISR4_IRQS147_SHIFT                    (0x00000013U)
#define CSL_GIC400_GICD_SPISR4_IRQS147_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS147_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS146_MASK                     (0x00040000U)
#define CSL_GIC400_GICD_SPISR4_IRQS146_SHIFT                    (0x00000012U)
#define CSL_GIC400_GICD_SPISR4_IRQS146_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS146_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS145_MASK                     (0x00020000U)
#define CSL_GIC400_GICD_SPISR4_IRQS145_SHIFT                    (0x00000011U)
#define CSL_GIC400_GICD_SPISR4_IRQS145_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS145_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS144_MASK                     (0x00010000U)
#define CSL_GIC400_GICD_SPISR4_IRQS144_SHIFT                    (0x00000010U)
#define CSL_GIC400_GICD_SPISR4_IRQS144_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS144_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS143_MASK                     (0x00008000U)
#define CSL_GIC400_GICD_SPISR4_IRQS143_SHIFT                    (0x0000000FU)
#define CSL_GIC400_GICD_SPISR4_IRQS143_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS143_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS142_MASK                     (0x00004000U)
#define CSL_GIC400_GICD_SPISR4_IRQS142_SHIFT                    (0x0000000EU)
#define CSL_GIC400_GICD_SPISR4_IRQS142_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS142_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS141_MASK                     (0x00002000U)
#define CSL_GIC400_GICD_SPISR4_IRQS141_SHIFT                    (0x0000000DU)
#define CSL_GIC400_GICD_SPISR4_IRQS141_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS141_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS140_MASK                     (0x00001000U)
#define CSL_GIC400_GICD_SPISR4_IRQS140_SHIFT                    (0x0000000CU)
#define CSL_GIC400_GICD_SPISR4_IRQS140_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS140_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS139_MASK                     (0x00000800U)
#define CSL_GIC400_GICD_SPISR4_IRQS139_SHIFT                    (0x0000000BU)
#define CSL_GIC400_GICD_SPISR4_IRQS139_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS139_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS138_MASK                     (0x00000400U)
#define CSL_GIC400_GICD_SPISR4_IRQS138_SHIFT                    (0x0000000AU)
#define CSL_GIC400_GICD_SPISR4_IRQS138_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS138_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS137_MASK                     (0x00000200U)
#define CSL_GIC400_GICD_SPISR4_IRQS137_SHIFT                    (0x00000009U)
#define CSL_GIC400_GICD_SPISR4_IRQS137_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS137_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS136_MASK                     (0x00000100U)
#define CSL_GIC400_GICD_SPISR4_IRQS136_SHIFT                    (0x00000008U)
#define CSL_GIC400_GICD_SPISR4_IRQS136_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS136_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS135_MASK                     (0x00000080U)
#define CSL_GIC400_GICD_SPISR4_IRQS135_SHIFT                    (0x00000007U)
#define CSL_GIC400_GICD_SPISR4_IRQS135_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS135_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS134_MASK                     (0x00000040U)
#define CSL_GIC400_GICD_SPISR4_IRQS134_SHIFT                    (0x00000006U)
#define CSL_GIC400_GICD_SPISR4_IRQS134_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS134_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS133_MASK                     (0x00000020U)
#define CSL_GIC400_GICD_SPISR4_IRQS133_SHIFT                    (0x00000005U)
#define CSL_GIC400_GICD_SPISR4_IRQS133_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS133_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS132_MASK                     (0x00000010U)
#define CSL_GIC400_GICD_SPISR4_IRQS132_SHIFT                    (0x00000004U)
#define CSL_GIC400_GICD_SPISR4_IRQS132_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS132_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS131_MASK                     (0x00000008U)
#define CSL_GIC400_GICD_SPISR4_IRQS131_SHIFT                    (0x00000003U)
#define CSL_GIC400_GICD_SPISR4_IRQS131_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS131_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS130_MASK                     (0x00000004U)
#define CSL_GIC400_GICD_SPISR4_IRQS130_SHIFT                    (0x00000002U)
#define CSL_GIC400_GICD_SPISR4_IRQS130_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS130_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS129_MASK                     (0x00000002U)
#define CSL_GIC400_GICD_SPISR4_IRQS129_SHIFT                    (0x00000001U)
#define CSL_GIC400_GICD_SPISR4_IRQS129_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS129_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_IRQS128_MASK                     (0x00000001U)
#define CSL_GIC400_GICD_SPISR4_IRQS128_SHIFT                    (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS128_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR4_IRQS128_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR4_RESETVAL                         (0x00000000U)

/* GICD_SPISR5 */

#define CSL_GIC400_GICD_SPISR5_IRQS191_MASK                     (0x80000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS191_SHIFT                    (0x0000001FU)
#define CSL_GIC400_GICD_SPISR5_IRQS191_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS191_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS190_MASK                     (0x40000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS190_SHIFT                    (0x0000001EU)
#define CSL_GIC400_GICD_SPISR5_IRQS190_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS190_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS189_MASK                     (0x20000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS189_SHIFT                    (0x0000001DU)
#define CSL_GIC400_GICD_SPISR5_IRQS189_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS189_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS188_MASK                     (0x10000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS188_SHIFT                    (0x0000001CU)
#define CSL_GIC400_GICD_SPISR5_IRQS188_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS188_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS187_MASK                     (0x08000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS187_SHIFT                    (0x0000001BU)
#define CSL_GIC400_GICD_SPISR5_IRQS187_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS187_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS186_MASK                     (0x04000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS186_SHIFT                    (0x0000001AU)
#define CSL_GIC400_GICD_SPISR5_IRQS186_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS186_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS185_MASK                     (0x02000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS185_SHIFT                    (0x00000019U)
#define CSL_GIC400_GICD_SPISR5_IRQS185_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS185_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS184_MASK                     (0x01000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS184_SHIFT                    (0x00000018U)
#define CSL_GIC400_GICD_SPISR5_IRQS184_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS184_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS183_MASK                     (0x00800000U)
#define CSL_GIC400_GICD_SPISR5_IRQS183_SHIFT                    (0x00000017U)
#define CSL_GIC400_GICD_SPISR5_IRQS183_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS183_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS182_MASK                     (0x00400000U)
#define CSL_GIC400_GICD_SPISR5_IRQS182_SHIFT                    (0x00000016U)
#define CSL_GIC400_GICD_SPISR5_IRQS182_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS182_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS181_MASK                     (0x00200000U)
#define CSL_GIC400_GICD_SPISR5_IRQS181_SHIFT                    (0x00000015U)
#define CSL_GIC400_GICD_SPISR5_IRQS181_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS181_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS180_MASK                     (0x00100000U)
#define CSL_GIC400_GICD_SPISR5_IRQS180_SHIFT                    (0x00000014U)
#define CSL_GIC400_GICD_SPISR5_IRQS180_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS180_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS179_MASK                     (0x00080000U)
#define CSL_GIC400_GICD_SPISR5_IRQS179_SHIFT                    (0x00000013U)
#define CSL_GIC400_GICD_SPISR5_IRQS179_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS179_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS178_MASK                     (0x00040000U)
#define CSL_GIC400_GICD_SPISR5_IRQS178_SHIFT                    (0x00000012U)
#define CSL_GIC400_GICD_SPISR5_IRQS178_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS178_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS177_MASK                     (0x00020000U)
#define CSL_GIC400_GICD_SPISR5_IRQS177_SHIFT                    (0x00000011U)
#define CSL_GIC400_GICD_SPISR5_IRQS177_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS177_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS176_MASK                     (0x00010000U)
#define CSL_GIC400_GICD_SPISR5_IRQS176_SHIFT                    (0x00000010U)
#define CSL_GIC400_GICD_SPISR5_IRQS176_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS176_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS175_MASK                     (0x00008000U)
#define CSL_GIC400_GICD_SPISR5_IRQS175_SHIFT                    (0x0000000FU)
#define CSL_GIC400_GICD_SPISR5_IRQS175_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS175_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS174_MASK                     (0x00004000U)
#define CSL_GIC400_GICD_SPISR5_IRQS174_SHIFT                    (0x0000000EU)
#define CSL_GIC400_GICD_SPISR5_IRQS174_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS174_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS173_MASK                     (0x00002000U)
#define CSL_GIC400_GICD_SPISR5_IRQS173_SHIFT                    (0x0000000DU)
#define CSL_GIC400_GICD_SPISR5_IRQS173_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS173_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS172_MASK                     (0x00001000U)
#define CSL_GIC400_GICD_SPISR5_IRQS172_SHIFT                    (0x0000000CU)
#define CSL_GIC400_GICD_SPISR5_IRQS172_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS172_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS171_MASK                     (0x00000800U)
#define CSL_GIC400_GICD_SPISR5_IRQS171_SHIFT                    (0x0000000BU)
#define CSL_GIC400_GICD_SPISR5_IRQS171_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS171_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS170_MASK                     (0x00000400U)
#define CSL_GIC400_GICD_SPISR5_IRQS170_SHIFT                    (0x0000000AU)
#define CSL_GIC400_GICD_SPISR5_IRQS170_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS170_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS169_MASK                     (0x00000200U)
#define CSL_GIC400_GICD_SPISR5_IRQS169_SHIFT                    (0x00000009U)
#define CSL_GIC400_GICD_SPISR5_IRQS169_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS169_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS168_MASK                     (0x00000100U)
#define CSL_GIC400_GICD_SPISR5_IRQS168_SHIFT                    (0x00000008U)
#define CSL_GIC400_GICD_SPISR5_IRQS168_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS168_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS167_MASK                     (0x00000080U)
#define CSL_GIC400_GICD_SPISR5_IRQS167_SHIFT                    (0x00000007U)
#define CSL_GIC400_GICD_SPISR5_IRQS167_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS167_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS166_MASK                     (0x00000040U)
#define CSL_GIC400_GICD_SPISR5_IRQS166_SHIFT                    (0x00000006U)
#define CSL_GIC400_GICD_SPISR5_IRQS166_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS166_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS165_MASK                     (0x00000020U)
#define CSL_GIC400_GICD_SPISR5_IRQS165_SHIFT                    (0x00000005U)
#define CSL_GIC400_GICD_SPISR5_IRQS165_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS165_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS164_MASK                     (0x00000010U)
#define CSL_GIC400_GICD_SPISR5_IRQS164_SHIFT                    (0x00000004U)
#define CSL_GIC400_GICD_SPISR5_IRQS164_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS164_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS163_MASK                     (0x00000008U)
#define CSL_GIC400_GICD_SPISR5_IRQS163_SHIFT                    (0x00000003U)
#define CSL_GIC400_GICD_SPISR5_IRQS163_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS163_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS162_MASK                     (0x00000004U)
#define CSL_GIC400_GICD_SPISR5_IRQS162_SHIFT                    (0x00000002U)
#define CSL_GIC400_GICD_SPISR5_IRQS162_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS162_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS161_MASK                     (0x00000002U)
#define CSL_GIC400_GICD_SPISR5_IRQS161_SHIFT                    (0x00000001U)
#define CSL_GIC400_GICD_SPISR5_IRQS161_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS161_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_IRQS160_MASK                     (0x00000001U)
#define CSL_GIC400_GICD_SPISR5_IRQS160_SHIFT                    (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS160_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR5_IRQS160_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR5_RESETVAL                         (0x00000000U)

/* GICD_SPISR6 */

#define CSL_GIC400_GICD_SPISR6_IRQS223_MASK                     (0x80000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS223_SHIFT                    (0x0000001FU)
#define CSL_GIC400_GICD_SPISR6_IRQS223_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS223_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS222_MASK                     (0x40000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS222_SHIFT                    (0x0000001EU)
#define CSL_GIC400_GICD_SPISR6_IRQS222_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS222_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS221_MASK                     (0x20000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS221_SHIFT                    (0x0000001DU)
#define CSL_GIC400_GICD_SPISR6_IRQS221_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS221_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS220_MASK                     (0x10000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS220_SHIFT                    (0x0000001CU)
#define CSL_GIC400_GICD_SPISR6_IRQS220_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS220_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS219_MASK                     (0x08000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS219_SHIFT                    (0x0000001BU)
#define CSL_GIC400_GICD_SPISR6_IRQS219_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS219_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS218_MASK                     (0x04000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS218_SHIFT                    (0x0000001AU)
#define CSL_GIC400_GICD_SPISR6_IRQS218_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS218_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS217_MASK                     (0x02000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS217_SHIFT                    (0x00000019U)
#define CSL_GIC400_GICD_SPISR6_IRQS217_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS217_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS216_MASK                     (0x01000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS216_SHIFT                    (0x00000018U)
#define CSL_GIC400_GICD_SPISR6_IRQS216_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS216_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS215_MASK                     (0x00800000U)
#define CSL_GIC400_GICD_SPISR6_IRQS215_SHIFT                    (0x00000017U)
#define CSL_GIC400_GICD_SPISR6_IRQS215_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS215_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS214_MASK                     (0x00400000U)
#define CSL_GIC400_GICD_SPISR6_IRQS214_SHIFT                    (0x00000016U)
#define CSL_GIC400_GICD_SPISR6_IRQS214_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS214_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS213_MASK                     (0x00200000U)
#define CSL_GIC400_GICD_SPISR6_IRQS213_SHIFT                    (0x00000015U)
#define CSL_GIC400_GICD_SPISR6_IRQS213_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS213_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS212_MASK                     (0x00100000U)
#define CSL_GIC400_GICD_SPISR6_IRQS212_SHIFT                    (0x00000014U)
#define CSL_GIC400_GICD_SPISR6_IRQS212_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS212_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS211_MASK                     (0x00080000U)
#define CSL_GIC400_GICD_SPISR6_IRQS211_SHIFT                    (0x00000013U)
#define CSL_GIC400_GICD_SPISR6_IRQS211_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS211_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS210_MASK                     (0x00040000U)
#define CSL_GIC400_GICD_SPISR6_IRQS210_SHIFT                    (0x00000012U)
#define CSL_GIC400_GICD_SPISR6_IRQS210_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS210_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS209_MASK                     (0x00020000U)
#define CSL_GIC400_GICD_SPISR6_IRQS209_SHIFT                    (0x00000011U)
#define CSL_GIC400_GICD_SPISR6_IRQS209_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS209_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS208_MASK                     (0x00010000U)
#define CSL_GIC400_GICD_SPISR6_IRQS208_SHIFT                    (0x00000010U)
#define CSL_GIC400_GICD_SPISR6_IRQS208_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS208_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS207_MASK                     (0x00008000U)
#define CSL_GIC400_GICD_SPISR6_IRQS207_SHIFT                    (0x0000000FU)
#define CSL_GIC400_GICD_SPISR6_IRQS207_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS207_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS206_MASK                     (0x00004000U)
#define CSL_GIC400_GICD_SPISR6_IRQS206_SHIFT                    (0x0000000EU)
#define CSL_GIC400_GICD_SPISR6_IRQS206_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS206_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS205_MASK                     (0x00002000U)
#define CSL_GIC400_GICD_SPISR6_IRQS205_SHIFT                    (0x0000000DU)
#define CSL_GIC400_GICD_SPISR6_IRQS205_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS205_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS204_MASK                     (0x00001000U)
#define CSL_GIC400_GICD_SPISR6_IRQS204_SHIFT                    (0x0000000CU)
#define CSL_GIC400_GICD_SPISR6_IRQS204_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS204_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS203_MASK                     (0x00000800U)
#define CSL_GIC400_GICD_SPISR6_IRQS203_SHIFT                    (0x0000000BU)
#define CSL_GIC400_GICD_SPISR6_IRQS203_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS203_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS202_MASK                     (0x00000400U)
#define CSL_GIC400_GICD_SPISR6_IRQS202_SHIFT                    (0x0000000AU)
#define CSL_GIC400_GICD_SPISR6_IRQS202_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS202_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS201_MASK                     (0x00000200U)
#define CSL_GIC400_GICD_SPISR6_IRQS201_SHIFT                    (0x00000009U)
#define CSL_GIC400_GICD_SPISR6_IRQS201_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS201_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS200_MASK                     (0x00000100U)
#define CSL_GIC400_GICD_SPISR6_IRQS200_SHIFT                    (0x00000008U)
#define CSL_GIC400_GICD_SPISR6_IRQS200_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS200_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS199_MASK                     (0x00000080U)
#define CSL_GIC400_GICD_SPISR6_IRQS199_SHIFT                    (0x00000007U)
#define CSL_GIC400_GICD_SPISR6_IRQS199_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS199_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS198_MASK                     (0x00000040U)
#define CSL_GIC400_GICD_SPISR6_IRQS198_SHIFT                    (0x00000006U)
#define CSL_GIC400_GICD_SPISR6_IRQS198_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS198_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS197_MASK                     (0x00000020U)
#define CSL_GIC400_GICD_SPISR6_IRQS197_SHIFT                    (0x00000005U)
#define CSL_GIC400_GICD_SPISR6_IRQS197_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS197_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS196_MASK                     (0x00000010U)
#define CSL_GIC400_GICD_SPISR6_IRQS196_SHIFT                    (0x00000004U)
#define CSL_GIC400_GICD_SPISR6_IRQS196_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS196_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS195_MASK                     (0x00000008U)
#define CSL_GIC400_GICD_SPISR6_IRQS195_SHIFT                    (0x00000003U)
#define CSL_GIC400_GICD_SPISR6_IRQS195_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS195_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS194_MASK                     (0x00000004U)
#define CSL_GIC400_GICD_SPISR6_IRQS194_SHIFT                    (0x00000002U)
#define CSL_GIC400_GICD_SPISR6_IRQS194_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS194_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS193_MASK                     (0x00000002U)
#define CSL_GIC400_GICD_SPISR6_IRQS193_SHIFT                    (0x00000001U)
#define CSL_GIC400_GICD_SPISR6_IRQS193_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS193_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_IRQS192_MASK                     (0x00000001U)
#define CSL_GIC400_GICD_SPISR6_IRQS192_SHIFT                    (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS192_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_SPISR6_IRQS192_MAX                      (0x00000001U)

#define CSL_GIC400_GICD_SPISR6_RESETVAL                         (0x00000000U)

/* GICD_SPISR7 */

#define CSL_GIC400_GICD_SPISR7_GICD_SPISR7_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_SPISR7_GICD_SPISR7_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_SPISR7_GICD_SPISR7_RESETVAL             (0x00000000U)
#define CSL_GIC400_GICD_SPISR7_GICD_SPISR7_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_SPISR7_RESETVAL                         (0x00000000U)

/* GICD_SPISR8 */

#define CSL_GIC400_GICD_SPISR8_GICD_SPISR8_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_SPISR8_GICD_SPISR8_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_SPISR8_GICD_SPISR8_RESETVAL             (0x00000000U)
#define CSL_GIC400_GICD_SPISR8_GICD_SPISR8_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_SPISR8_RESETVAL                         (0x00000000U)

/* GICD_SPISR9 */

#define CSL_GIC400_GICD_SPISR9_GICD_SPISR9_MASK                 (0xFFFFFFFFU)
#define CSL_GIC400_GICD_SPISR9_GICD_SPISR9_SHIFT                (0x00000000U)
#define CSL_GIC400_GICD_SPISR9_GICD_SPISR9_RESETVAL             (0x00000000U)
#define CSL_GIC400_GICD_SPISR9_GICD_SPISR9_MAX                  (0xffffffffU)

#define CSL_GIC400_GICD_SPISR9_RESETVAL                         (0x00000000U)

/* GICD_SPISR10 */

#define CSL_GIC400_GICD_SPISR10_GICD_SPISR10_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_SPISR10_GICD_SPISR10_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_SPISR10_GICD_SPISR10_RESETVAL           (0x00000000U)
#define CSL_GIC400_GICD_SPISR10_GICD_SPISR10_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_SPISR10_RESETVAL                        (0x00000000U)

/* GICD_SPISR11 */

#define CSL_GIC400_GICD_SPISR11_GICD_SPISR11_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_SPISR11_GICD_SPISR11_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_SPISR11_GICD_SPISR11_RESETVAL           (0x00000000U)
#define CSL_GIC400_GICD_SPISR11_GICD_SPISR11_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_SPISR11_RESETVAL                        (0x00000000U)

/* GICD_SPISR12 */

#define CSL_GIC400_GICD_SPISR12_GICD_SPISR12_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_SPISR12_GICD_SPISR12_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_SPISR12_GICD_SPISR12_RESETVAL           (0x00000000U)
#define CSL_GIC400_GICD_SPISR12_GICD_SPISR12_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_SPISR12_RESETVAL                        (0x00000000U)

/* GICD_SPISR13 */

#define CSL_GIC400_GICD_SPISR13_GICD_SPISR13_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_SPISR13_GICD_SPISR13_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_SPISR13_GICD_SPISR13_RESETVAL           (0x00000000U)
#define CSL_GIC400_GICD_SPISR13_GICD_SPISR13_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_SPISR13_RESETVAL                        (0x00000000U)

/* GICD_SPISR14 */

#define CSL_GIC400_GICD_SPISR14_GICD_SPISR14_MASK               (0xFFFFFFFFU)
#define CSL_GIC400_GICD_SPISR14_GICD_SPISR14_SHIFT              (0x00000000U)
#define CSL_GIC400_GICD_SPISR14_GICD_SPISR14_RESETVAL           (0x00000000U)
#define CSL_GIC400_GICD_SPISR14_GICD_SPISR14_MAX                (0xffffffffU)

#define CSL_GIC400_GICD_SPISR14_RESETVAL                        (0x00000000U)

/* GICD_SGIR */

#define CSL_GIC400_GICD_SGIR_TARGETLISTFILTER_MASK              (0x03000000U)
#define CSL_GIC400_GICD_SGIR_TARGETLISTFILTER_SHIFT             (0x00000018U)
#define CSL_GIC400_GICD_SGIR_TARGETLISTFILTER_RESETVAL          (0x00000000U)
#define CSL_GIC400_GICD_SGIR_TARGETLISTFILTER_MAX               (0x00000003U)

#define CSL_GIC400_GICD_SGIR_CPUTARGETLIST_MASK                 (0x00FF0000U)
#define CSL_GIC400_GICD_SGIR_CPUTARGETLIST_SHIFT                (0x00000010U)
#define CSL_GIC400_GICD_SGIR_CPUTARGETLIST_RESETVAL             (0x00000000U)
#define CSL_GIC400_GICD_SGIR_CPUTARGETLIST_MAX                  (0x000000ffU)

#define CSL_GIC400_GICD_SGIR_SATT_MASK                          (0x00008000U)
#define CSL_GIC400_GICD_SGIR_SATT_SHIFT                         (0x0000000FU)
#define CSL_GIC400_GICD_SGIR_SATT_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICD_SGIR_SATT_MAX                           (0x00000001U)

#define CSL_GIC400_GICD_SGIR_SGIINTID_MASK                      (0x0000000FU)
#define CSL_GIC400_GICD_SGIR_SGIINTID_SHIFT                     (0x00000000U)
#define CSL_GIC400_GICD_SGIR_SGIINTID_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICD_SGIR_SGIINTID_MAX                       (0x0000000fU)

#define CSL_GIC400_GICD_SGIR_RESETVAL                           (0x00000000U)

/* GICD_CPENDSGIR0 */

#define CSL_GIC400_GICD_CPENDSGIR0_GICD_CPENDSGIR0_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_CPENDSGIR0_GICD_CPENDSGIR0_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_CPENDSGIR0_GICD_CPENDSGIR0_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_CPENDSGIR0_GICD_CPENDSGIR0_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_CPENDSGIR0_RESETVAL                     (0x00000000U)

/* GICD_CPENDSGIR1 */

#define CSL_GIC400_GICD_CPENDSGIR1_GICD_CPENDSGIR1_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_CPENDSGIR1_GICD_CPENDSGIR1_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_CPENDSGIR1_GICD_CPENDSGIR1_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_CPENDSGIR1_GICD_CPENDSGIR1_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_CPENDSGIR1_RESETVAL                     (0x00000000U)

/* GICD_CPENDSGIR2 */

#define CSL_GIC400_GICD_CPENDSGIR2_GICD_CPENDSGIR2_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_CPENDSGIR2_GICD_CPENDSGIR2_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_CPENDSGIR2_GICD_CPENDSGIR2_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_CPENDSGIR2_GICD_CPENDSGIR2_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_CPENDSGIR2_RESETVAL                     (0x00000000U)

/* GICD_CPENDSGIR3 */

#define CSL_GIC400_GICD_CPENDSGIR3_GICD_CPENDSGIR3_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_CPENDSGIR3_GICD_CPENDSGIR3_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_CPENDSGIR3_GICD_CPENDSGIR3_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_CPENDSGIR3_GICD_CPENDSGIR3_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_CPENDSGIR3_RESETVAL                     (0x00000000U)

/* GICD_SPENDSGIR0 */

#define CSL_GIC400_GICD_SPENDSGIR0_GICD_SPENDSGIR0_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_SPENDSGIR0_GICD_SPENDSGIR0_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_SPENDSGIR0_GICD_SPENDSGIR0_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_SPENDSGIR0_GICD_SPENDSGIR0_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_SPENDSGIR0_RESETVAL                     (0x00000000U)

/* GICD_SPENDSGIR1 */

#define CSL_GIC400_GICD_SPENDSGIR1_GICD_SPENDSGIR1_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_SPENDSGIR1_GICD_SPENDSGIR1_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_SPENDSGIR1_GICD_SPENDSGIR1_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_SPENDSGIR1_GICD_SPENDSGIR1_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_SPENDSGIR1_RESETVAL                     (0x00000000U)

/* GICD_SPENDSGIR2 */

#define CSL_GIC400_GICD_SPENDSGIR2_GICD_SPENDSGIR2_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_SPENDSGIR2_GICD_SPENDSGIR2_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_SPENDSGIR2_GICD_SPENDSGIR2_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_SPENDSGIR2_GICD_SPENDSGIR2_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_SPENDSGIR2_RESETVAL                     (0x00000000U)

/* GICD_SPENDSGIR3 */

#define CSL_GIC400_GICD_SPENDSGIR3_GICD_SPENDSGIR3_MASK         (0xFFFFFFFFU)
#define CSL_GIC400_GICD_SPENDSGIR3_GICD_SPENDSGIR3_SHIFT        (0x00000000U)
#define CSL_GIC400_GICD_SPENDSGIR3_GICD_SPENDSGIR3_RESETVAL     (0x00000000U)
#define CSL_GIC400_GICD_SPENDSGIR3_GICD_SPENDSGIR3_MAX          (0xffffffffU)

#define CSL_GIC400_GICD_SPENDSGIR3_RESETVAL                     (0x00000000U)

/* GICD_PIDR4 */

#define CSL_GIC400_GICD_PIDR4_GICD_PIDR4_MASK                   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_PIDR4_GICD_PIDR4_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICD_PIDR4_GICD_PIDR4_RESETVAL               (0x00000004U)
#define CSL_GIC400_GICD_PIDR4_GICD_PIDR4_MAX                    (0xffffffffU)

#define CSL_GIC400_GICD_PIDR4_RESETVAL                          (0x00000004U)

/* GICD_PIDR5 */

#define CSL_GIC400_GICD_PIDR5_GICD_PIDR5_MASK                   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_PIDR5_GICD_PIDR5_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICD_PIDR5_GICD_PIDR5_RESETVAL               (0x00000000U)
#define CSL_GIC400_GICD_PIDR5_GICD_PIDR5_MAX                    (0xffffffffU)

#define CSL_GIC400_GICD_PIDR5_RESETVAL                          (0x00000000U)

/* GICD_PIDR6 */

#define CSL_GIC400_GICD_PIDR6_GICD_PIDR6_MASK                   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_PIDR6_GICD_PIDR6_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICD_PIDR6_GICD_PIDR6_RESETVAL               (0x00000000U)
#define CSL_GIC400_GICD_PIDR6_GICD_PIDR6_MAX                    (0xffffffffU)

#define CSL_GIC400_GICD_PIDR6_RESETVAL                          (0x00000000U)

/* GICD_PIDR7 */

#define CSL_GIC400_GICD_PIDR7_GICD_PIDR7_MASK                   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_PIDR7_GICD_PIDR7_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICD_PIDR7_GICD_PIDR7_RESETVAL               (0x00000000U)
#define CSL_GIC400_GICD_PIDR7_GICD_PIDR7_MAX                    (0xffffffffU)

#define CSL_GIC400_GICD_PIDR7_RESETVAL                          (0x00000000U)

/* GICD_PIDR0 */

#define CSL_GIC400_GICD_PIDR0_GICD_PIDR0_MASK                   (0xFFFFFFFFU)
#define CSL_GIC400_GICD_PIDR0_GICD_PIDR0_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICD_PIDR0_GICD_PIDR0_RESETVAL               (0x00000090U)
#define CSL_GIC400_GICD_PIDR0_GICD_PIDR0_MAX                    (0xffffffffU)

#define CSL_GIC400_GICD_PIDR0_RESETVAL                          (0x00000090U)

/* GICD_PIDR1 */

#define CSL_GIC400_GICD_PIDR1_DEVID_MASK                        (0x0000000FU)
#define CSL_GIC400_GICD_PIDR1_DEVID_SHIFT                       (0x00000000U)
#define CSL_GIC400_GICD_PIDR1_DEVID_RESETVAL                    (0x00000004U)
#define CSL_GIC400_GICD_PIDR1_DEVID_MAX                         (0x0000000fU)

#define CSL_GIC400_GICD_PIDR1_ARCHID_MASK                       (0x000000F0U)
#define CSL_GIC400_GICD_PIDR1_ARCHID_SHIFT                      (0x00000004U)
#define CSL_GIC400_GICD_PIDR1_ARCHID_RESETVAL                   (0x0000000bU)
#define CSL_GIC400_GICD_PIDR1_ARCHID_MAX                        (0x0000000fU)

#define CSL_GIC400_GICD_PIDR1_RESETVAL                          (0x000000b4U)

/* GICD_PIDR2 */

#define CSL_GIC400_GICD_PIDR2_ARCHID_MASK                       (0x00000007U)
#define CSL_GIC400_GICD_PIDR2_ARCHID_SHIFT                      (0x00000000U)
#define CSL_GIC400_GICD_PIDR2_ARCHID_RESETVAL                   (0x00000003U)
#define CSL_GIC400_GICD_PIDR2_ARCHID_MAX                        (0x00000007U)

#define CSL_GIC400_GICD_PIDR2_USESJEPCODE_MASK                  (0x00000008U)
#define CSL_GIC400_GICD_PIDR2_USESJEPCODE_SHIFT                 (0x00000003U)
#define CSL_GIC400_GICD_PIDR2_USESJEPCODE_RESETVAL              (0x00000001U)
#define CSL_GIC400_GICD_PIDR2_USESJEPCODE_MAX                   (0x00000001U)

#define CSL_GIC400_GICD_PIDR2_ARCHREV_MASK                      (0x000000F0U)
#define CSL_GIC400_GICD_PIDR2_ARCHREV_SHIFT                     (0x00000004U)
#define CSL_GIC400_GICD_PIDR2_ARCHREV_RESETVAL                  (0x00000002U)
#define CSL_GIC400_GICD_PIDR2_ARCHREV_MAX                       (0x0000000fU)

#define CSL_GIC400_GICD_PIDR2_RESETVAL                          (0x0000002bU)

/* GICD_PIDR3 */

#define CSL_GIC400_GICD_PIDR3_REVISION_MASK                     (0x000000F0U)
#define CSL_GIC400_GICD_PIDR3_REVISION_SHIFT                    (0x00000004U)
#define CSL_GIC400_GICD_PIDR3_REVISION_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICD_PIDR3_REVISION_MAX                      (0x0000000fU)

#define CSL_GIC400_GICD_PIDR3_RESETVAL                          (0x00000000U)

/* GICD_CIDR0 */

#define CSL_GIC400_GICD_CIDR0_REVISION_MASK                     (0x000000FFU)
#define CSL_GIC400_GICD_CIDR0_REVISION_SHIFT                    (0x00000000U)
#define CSL_GIC400_GICD_CIDR0_REVISION_RESETVAL                 (0x0000000dU)
#define CSL_GIC400_GICD_CIDR0_REVISION_MAX                      (0x000000ffU)

#define CSL_GIC400_GICD_CIDR0_RESETVAL                          (0x0000000dU)

/* GICD_CIDR1 */

#define CSL_GIC400_GICD_CIDR1_REVISION_MASK                     (0x000000FFU)
#define CSL_GIC400_GICD_CIDR1_REVISION_SHIFT                    (0x00000000U)
#define CSL_GIC400_GICD_CIDR1_REVISION_RESETVAL                 (0x000000f0U)
#define CSL_GIC400_GICD_CIDR1_REVISION_MAX                      (0x000000ffU)

#define CSL_GIC400_GICD_CIDR1_RESETVAL                          (0x000000f0U)

/* GICD_CIDR2 */

#define CSL_GIC400_GICD_CIDR2_REVISION_MASK                     (0x000000FFU)
#define CSL_GIC400_GICD_CIDR2_REVISION_SHIFT                    (0x00000000U)
#define CSL_GIC400_GICD_CIDR2_REVISION_RESETVAL                 (0x00000005U)
#define CSL_GIC400_GICD_CIDR2_REVISION_MAX                      (0x000000ffU)

#define CSL_GIC400_GICD_CIDR2_RESETVAL                          (0x00000005U)

/* GICD_CIDR3 */

#define CSL_GIC400_GICD_CIDR3_REVISION_MASK                     (0x000000FFU)
#define CSL_GIC400_GICD_CIDR3_REVISION_SHIFT                    (0x00000000U)
#define CSL_GIC400_GICD_CIDR3_REVISION_RESETVAL                 (0x000000b1U)
#define CSL_GIC400_GICD_CIDR3_REVISION_MAX                      (0x000000ffU)

#define CSL_GIC400_GICD_CIDR3_RESETVAL                          (0x000000b1U)

/* GICC_CTLR */

#define CSL_GIC400_GICC_CTLR_GICC_CTLR_MASK                     (0xFFFFFFFFU)
#define CSL_GIC400_GICC_CTLR_GICC_CTLR_SHIFT                    (0x00000000U)
#define CSL_GIC400_GICC_CTLR_GICC_CTLR_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICC_CTLR_GICC_CTLR_MAX                      (0xffffffffU)

#define CSL_GIC400_GICC_CTLR_RESETVAL                           (0x00000000U)

/* GICC_PMR */

#define CSL_GIC400_GICC_PMR_PRIORITY_MASK                       (0x000000FFU)
#define CSL_GIC400_GICC_PMR_PRIORITY_SHIFT                      (0x00000000U)
#define CSL_GIC400_GICC_PMR_PRIORITY_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICC_PMR_PRIORITY_MAX                        (0x000000ffU)

#define CSL_GIC400_GICC_PMR_RESETVAL                            (0x00000000U)

/* GICC_BPR */

#define CSL_GIC400_GICC_BPR_BINARYPOINT_MASK                    (0x00000007U)
#define CSL_GIC400_GICC_BPR_BINARYPOINT_SHIFT                   (0x00000000U)
#define CSL_GIC400_GICC_BPR_BINARYPOINT_RESETVAL                (0x00000002U)
#define CSL_GIC400_GICC_BPR_BINARYPOINT_MAX                     (0x00000007U)

#define CSL_GIC400_GICC_BPR_RESETVAL                            (0x00000002U)

/* GICC_IAR */

#define CSL_GIC400_GICC_IAR_ACKINTID_MASK                       (0x000003FFU)
#define CSL_GIC400_GICC_IAR_ACKINTID_SHIFT                      (0x00000000U)
#define CSL_GIC400_GICC_IAR_ACKINTID_RESETVAL                   (0x000003ffU)
#define CSL_GIC400_GICC_IAR_ACKINTID_MAX                        (0x000003ffU)

#define CSL_GIC400_GICC_IAR_CPUID_MASK                          (0x00001C00U)
#define CSL_GIC400_GICC_IAR_CPUID_SHIFT                         (0x0000000AU)
#define CSL_GIC400_GICC_IAR_CPUID_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_IAR_CPUID_MAX                           (0x00000007U)

#define CSL_GIC400_GICC_IAR_RESETVAL                            (0x000003ffU)

/* GICC_EOIR */

#define CSL_GIC400_GICC_EOIR_EOINTID_MASK                       (0x000003FFU)
#define CSL_GIC400_GICC_EOIR_EOINTID_SHIFT                      (0x00000000U)
#define CSL_GIC400_GICC_EOIR_EOINTID_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICC_EOIR_EOINTID_MAX                        (0x000003ffU)

#define CSL_GIC400_GICC_EOIR_CPUID_MASK                         (0x00001C00U)
#define CSL_GIC400_GICC_EOIR_CPUID_SHIFT                        (0x0000000AU)
#define CSL_GIC400_GICC_EOIR_CPUID_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICC_EOIR_CPUID_MAX                          (0x00000007U)

#define CSL_GIC400_GICC_EOIR_RESETVAL                           (0x00000000U)

/* GICC_RPR */

#define CSL_GIC400_GICC_RPR_PRIORITY_MASK                       (0x000000FFU)
#define CSL_GIC400_GICC_RPR_PRIORITY_SHIFT                      (0x00000000U)
#define CSL_GIC400_GICC_RPR_PRIORITY_RESETVAL                   (0x000000ffU)
#define CSL_GIC400_GICC_RPR_PRIORITY_MAX                        (0x000000ffU)

#define CSL_GIC400_GICC_RPR_RESETVAL                            (0x000000ffU)

/* GICC_HPPIR */

#define CSL_GIC400_GICC_HPPIR_HPINTID_MASK                      (0x000003FFU)
#define CSL_GIC400_GICC_HPPIR_HPINTID_SHIFT                     (0x00000000U)
#define CSL_GIC400_GICC_HPPIR_HPINTID_RESETVAL                  (0x000003ffU)
#define CSL_GIC400_GICC_HPPIR_HPINTID_MAX                       (0x000003ffU)

#define CSL_GIC400_GICC_HPPIR_CPUID_MASK                        (0x00001C00U)
#define CSL_GIC400_GICC_HPPIR_CPUID_SHIFT                       (0x0000000AU)
#define CSL_GIC400_GICC_HPPIR_CPUID_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_HPPIR_CPUID_MAX                         (0x00000007U)

#define CSL_GIC400_GICC_HPPIR_RESETVAL                          (0x000003ffU)

/* GICC_ABPR */

#define CSL_GIC400_GICC_ABPR_BINARYPOINT_MASK                   (0x00000007U)
#define CSL_GIC400_GICC_ABPR_BINARYPOINT_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICC_ABPR_BINARYPOINT_RESETVAL               (0x00000003U)
#define CSL_GIC400_GICC_ABPR_BINARYPOINT_MAX                    (0x00000007U)

#define CSL_GIC400_GICC_ABPR_RESETVAL                           (0x00000003U)

/* GICC_AIAR */

#define CSL_GIC400_GICC_AIAR_AACKINTID_MASK                     (0x000003FFU)
#define CSL_GIC400_GICC_AIAR_AACKINTID_SHIFT                    (0x00000000U)
#define CSL_GIC400_GICC_AIAR_AACKINTID_RESETVAL                 (0x000003ffU)
#define CSL_GIC400_GICC_AIAR_AACKINTID_MAX                      (0x000003ffU)

#define CSL_GIC400_GICC_AIAR_CPUID_MASK                         (0x00001C00U)
#define CSL_GIC400_GICC_AIAR_CPUID_SHIFT                        (0x0000000AU)
#define CSL_GIC400_GICC_AIAR_CPUID_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICC_AIAR_CPUID_MAX                          (0x00000007U)

#define CSL_GIC400_GICC_AIAR_RESETVAL                           (0x000003ffU)

/* GICC_AEOIR */

#define CSL_GIC400_GICC_AEOIR_AEOINTID_MASK                     (0x000003FFU)
#define CSL_GIC400_GICC_AEOIR_AEOINTID_SHIFT                    (0x00000000U)
#define CSL_GIC400_GICC_AEOIR_AEOINTID_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICC_AEOIR_AEOINTID_MAX                      (0x000003ffU)

#define CSL_GIC400_GICC_AEOIR_CPUID_MASK                        (0x00001C00U)
#define CSL_GIC400_GICC_AEOIR_CPUID_SHIFT                       (0x0000000AU)
#define CSL_GIC400_GICC_AEOIR_CPUID_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_AEOIR_CPUID_MAX                         (0x00000007U)

#define CSL_GIC400_GICC_AEOIR_RESETVAL                          (0x00000000U)

/* GICC_AHPPIR */

#define CSL_GIC400_GICC_AHPPIR_AHPINTID_MASK                    (0x000003FFU)
#define CSL_GIC400_GICC_AHPPIR_AHPINTID_SHIFT                   (0x00000000U)
#define CSL_GIC400_GICC_AHPPIR_AHPINTID_RESETVAL                (0x000003ffU)
#define CSL_GIC400_GICC_AHPPIR_AHPINTID_MAX                     (0x000003ffU)

#define CSL_GIC400_GICC_AHPPIR_CPUID_MASK                       (0x00001C00U)
#define CSL_GIC400_GICC_AHPPIR_CPUID_SHIFT                      (0x0000000AU)
#define CSL_GIC400_GICC_AHPPIR_CPUID_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICC_AHPPIR_CPUID_MAX                        (0x00000007U)

#define CSL_GIC400_GICC_AHPPIR_RESETVAL                         (0x000003ffU)

/* GICC_APR0 */

#define CSL_GIC400_GICC_APR0_AP0_MASK                           (0x00000001U)
#define CSL_GIC400_GICC_APR0_AP0_SHIFT                          (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP0_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP0_MAX                            (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP1_MASK                           (0x00000002U)
#define CSL_GIC400_GICC_APR0_AP1_SHIFT                          (0x00000001U)
#define CSL_GIC400_GICC_APR0_AP1_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP1_MAX                            (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP2_MASK                           (0x00000004U)
#define CSL_GIC400_GICC_APR0_AP2_SHIFT                          (0x00000002U)
#define CSL_GIC400_GICC_APR0_AP2_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP2_MAX                            (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP3_MASK                           (0x00000008U)
#define CSL_GIC400_GICC_APR0_AP3_SHIFT                          (0x00000003U)
#define CSL_GIC400_GICC_APR0_AP3_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP3_MAX                            (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP4_MASK                           (0x00000010U)
#define CSL_GIC400_GICC_APR0_AP4_SHIFT                          (0x00000004U)
#define CSL_GIC400_GICC_APR0_AP4_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP4_MAX                            (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP5_MASK                           (0x00000020U)
#define CSL_GIC400_GICC_APR0_AP5_SHIFT                          (0x00000005U)
#define CSL_GIC400_GICC_APR0_AP5_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP5_MAX                            (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP6_MASK                           (0x00000040U)
#define CSL_GIC400_GICC_APR0_AP6_SHIFT                          (0x00000006U)
#define CSL_GIC400_GICC_APR0_AP6_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP6_MAX                            (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP7_MASK                           (0x00000080U)
#define CSL_GIC400_GICC_APR0_AP7_SHIFT                          (0x00000007U)
#define CSL_GIC400_GICC_APR0_AP7_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP7_MAX                            (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP8_MASK                           (0x00000100U)
#define CSL_GIC400_GICC_APR0_AP8_SHIFT                          (0x00000008U)
#define CSL_GIC400_GICC_APR0_AP8_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP8_MAX                            (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP9_MASK                           (0x00000200U)
#define CSL_GIC400_GICC_APR0_AP9_SHIFT                          (0x00000009U)
#define CSL_GIC400_GICC_APR0_AP9_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP9_MAX                            (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP10_MASK                          (0x00000400U)
#define CSL_GIC400_GICC_APR0_AP10_SHIFT                         (0x0000000AU)
#define CSL_GIC400_GICC_APR0_AP10_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP10_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP11_MASK                          (0x00000800U)
#define CSL_GIC400_GICC_APR0_AP11_SHIFT                         (0x0000000BU)
#define CSL_GIC400_GICC_APR0_AP11_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP11_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP12_MASK                          (0x00001000U)
#define CSL_GIC400_GICC_APR0_AP12_SHIFT                         (0x0000000CU)
#define CSL_GIC400_GICC_APR0_AP12_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP12_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP13_MASK                          (0x00002000U)
#define CSL_GIC400_GICC_APR0_AP13_SHIFT                         (0x0000000DU)
#define CSL_GIC400_GICC_APR0_AP13_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP13_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP14_MASK                          (0x00004000U)
#define CSL_GIC400_GICC_APR0_AP14_SHIFT                         (0x0000000EU)
#define CSL_GIC400_GICC_APR0_AP14_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP14_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP15_MASK                          (0x00008000U)
#define CSL_GIC400_GICC_APR0_AP15_SHIFT                         (0x0000000FU)
#define CSL_GIC400_GICC_APR0_AP15_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP15_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP16_MASK                          (0x00010000U)
#define CSL_GIC400_GICC_APR0_AP16_SHIFT                         (0x00000010U)
#define CSL_GIC400_GICC_APR0_AP16_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP16_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP17_MASK                          (0x00020000U)
#define CSL_GIC400_GICC_APR0_AP17_SHIFT                         (0x00000011U)
#define CSL_GIC400_GICC_APR0_AP17_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP17_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP18_MASK                          (0x00040000U)
#define CSL_GIC400_GICC_APR0_AP18_SHIFT                         (0x00000012U)
#define CSL_GIC400_GICC_APR0_AP18_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP18_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP19_MASK                          (0x00080000U)
#define CSL_GIC400_GICC_APR0_AP19_SHIFT                         (0x00000013U)
#define CSL_GIC400_GICC_APR0_AP19_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP19_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP20_MASK                          (0x00100000U)
#define CSL_GIC400_GICC_APR0_AP20_SHIFT                         (0x00000014U)
#define CSL_GIC400_GICC_APR0_AP20_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP20_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP21_MASK                          (0x00200000U)
#define CSL_GIC400_GICC_APR0_AP21_SHIFT                         (0x00000015U)
#define CSL_GIC400_GICC_APR0_AP21_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP21_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP22_MASK                          (0x00400000U)
#define CSL_GIC400_GICC_APR0_AP22_SHIFT                         (0x00000016U)
#define CSL_GIC400_GICC_APR0_AP22_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP22_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP23_MASK                          (0x00800000U)
#define CSL_GIC400_GICC_APR0_AP23_SHIFT                         (0x00000017U)
#define CSL_GIC400_GICC_APR0_AP23_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP23_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP24_MASK                          (0x01000000U)
#define CSL_GIC400_GICC_APR0_AP24_SHIFT                         (0x00000018U)
#define CSL_GIC400_GICC_APR0_AP24_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP24_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP25_MASK                          (0x02000000U)
#define CSL_GIC400_GICC_APR0_AP25_SHIFT                         (0x00000019U)
#define CSL_GIC400_GICC_APR0_AP25_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP25_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP26_MASK                          (0x04000000U)
#define CSL_GIC400_GICC_APR0_AP26_SHIFT                         (0x0000001AU)
#define CSL_GIC400_GICC_APR0_AP26_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP26_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP27_MASK                          (0x08000000U)
#define CSL_GIC400_GICC_APR0_AP27_SHIFT                         (0x0000001BU)
#define CSL_GIC400_GICC_APR0_AP27_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP27_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP28_MASK                          (0x10000000U)
#define CSL_GIC400_GICC_APR0_AP28_SHIFT                         (0x0000001CU)
#define CSL_GIC400_GICC_APR0_AP28_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP28_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP29_MASK                          (0x20000000U)
#define CSL_GIC400_GICC_APR0_AP29_SHIFT                         (0x0000001DU)
#define CSL_GIC400_GICC_APR0_AP29_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP29_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP30_MASK                          (0x40000000U)
#define CSL_GIC400_GICC_APR0_AP30_SHIFT                         (0x0000001EU)
#define CSL_GIC400_GICC_APR0_AP30_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP30_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_AP31_MASK                          (0x80000000U)
#define CSL_GIC400_GICC_APR0_AP31_SHIFT                         (0x0000001FU)
#define CSL_GIC400_GICC_APR0_AP31_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_APR0_AP31_MAX                           (0x00000001U)

#define CSL_GIC400_GICC_APR0_RESETVAL                           (0x00000000U)

/* GICC_NSAPR0 */

#define CSL_GIC400_GICC_NSAPR0_AP0_MASK                         (0x00000001U)
#define CSL_GIC400_GICC_NSAPR0_AP0_SHIFT                        (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP0_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP0_MAX                          (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP1_MASK                         (0x00000002U)
#define CSL_GIC400_GICC_NSAPR0_AP1_SHIFT                        (0x00000001U)
#define CSL_GIC400_GICC_NSAPR0_AP1_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP1_MAX                          (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP2_MASK                         (0x00000004U)
#define CSL_GIC400_GICC_NSAPR0_AP2_SHIFT                        (0x00000002U)
#define CSL_GIC400_GICC_NSAPR0_AP2_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP2_MAX                          (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP3_MASK                         (0x00000008U)
#define CSL_GIC400_GICC_NSAPR0_AP3_SHIFT                        (0x00000003U)
#define CSL_GIC400_GICC_NSAPR0_AP3_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP3_MAX                          (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP4_MASK                         (0x00000010U)
#define CSL_GIC400_GICC_NSAPR0_AP4_SHIFT                        (0x00000004U)
#define CSL_GIC400_GICC_NSAPR0_AP4_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP4_MAX                          (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP5_MASK                         (0x00000020U)
#define CSL_GIC400_GICC_NSAPR0_AP5_SHIFT                        (0x00000005U)
#define CSL_GIC400_GICC_NSAPR0_AP5_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP5_MAX                          (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP6_MASK                         (0x00000040U)
#define CSL_GIC400_GICC_NSAPR0_AP6_SHIFT                        (0x00000006U)
#define CSL_GIC400_GICC_NSAPR0_AP6_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP6_MAX                          (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP7_MASK                         (0x00000080U)
#define CSL_GIC400_GICC_NSAPR0_AP7_SHIFT                        (0x00000007U)
#define CSL_GIC400_GICC_NSAPR0_AP7_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP7_MAX                          (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP8_MASK                         (0x00000100U)
#define CSL_GIC400_GICC_NSAPR0_AP8_SHIFT                        (0x00000008U)
#define CSL_GIC400_GICC_NSAPR0_AP8_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP8_MAX                          (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP9_MASK                         (0x00000200U)
#define CSL_GIC400_GICC_NSAPR0_AP9_SHIFT                        (0x00000009U)
#define CSL_GIC400_GICC_NSAPR0_AP9_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP9_MAX                          (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP10_MASK                        (0x00000400U)
#define CSL_GIC400_GICC_NSAPR0_AP10_SHIFT                       (0x0000000AU)
#define CSL_GIC400_GICC_NSAPR0_AP10_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP10_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP11_MASK                        (0x00000800U)
#define CSL_GIC400_GICC_NSAPR0_AP11_SHIFT                       (0x0000000BU)
#define CSL_GIC400_GICC_NSAPR0_AP11_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP11_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP12_MASK                        (0x00001000U)
#define CSL_GIC400_GICC_NSAPR0_AP12_SHIFT                       (0x0000000CU)
#define CSL_GIC400_GICC_NSAPR0_AP12_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP12_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP13_MASK                        (0x00002000U)
#define CSL_GIC400_GICC_NSAPR0_AP13_SHIFT                       (0x0000000DU)
#define CSL_GIC400_GICC_NSAPR0_AP13_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP13_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP14_MASK                        (0x00004000U)
#define CSL_GIC400_GICC_NSAPR0_AP14_SHIFT                       (0x0000000EU)
#define CSL_GIC400_GICC_NSAPR0_AP14_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP14_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP15_MASK                        (0x00008000U)
#define CSL_GIC400_GICC_NSAPR0_AP15_SHIFT                       (0x0000000FU)
#define CSL_GIC400_GICC_NSAPR0_AP15_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP15_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP16_MASK                        (0x00010000U)
#define CSL_GIC400_GICC_NSAPR0_AP16_SHIFT                       (0x00000010U)
#define CSL_GIC400_GICC_NSAPR0_AP16_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP16_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP17_MASK                        (0x00020000U)
#define CSL_GIC400_GICC_NSAPR0_AP17_SHIFT                       (0x00000011U)
#define CSL_GIC400_GICC_NSAPR0_AP17_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP17_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP18_MASK                        (0x00040000U)
#define CSL_GIC400_GICC_NSAPR0_AP18_SHIFT                       (0x00000012U)
#define CSL_GIC400_GICC_NSAPR0_AP18_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP18_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP19_MASK                        (0x00080000U)
#define CSL_GIC400_GICC_NSAPR0_AP19_SHIFT                       (0x00000013U)
#define CSL_GIC400_GICC_NSAPR0_AP19_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP19_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP20_MASK                        (0x00100000U)
#define CSL_GIC400_GICC_NSAPR0_AP20_SHIFT                       (0x00000014U)
#define CSL_GIC400_GICC_NSAPR0_AP20_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP20_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP21_MASK                        (0x00200000U)
#define CSL_GIC400_GICC_NSAPR0_AP21_SHIFT                       (0x00000015U)
#define CSL_GIC400_GICC_NSAPR0_AP21_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP21_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP22_MASK                        (0x00400000U)
#define CSL_GIC400_GICC_NSAPR0_AP22_SHIFT                       (0x00000016U)
#define CSL_GIC400_GICC_NSAPR0_AP22_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP22_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP23_MASK                        (0x00800000U)
#define CSL_GIC400_GICC_NSAPR0_AP23_SHIFT                       (0x00000017U)
#define CSL_GIC400_GICC_NSAPR0_AP23_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP23_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP24_MASK                        (0x01000000U)
#define CSL_GIC400_GICC_NSAPR0_AP24_SHIFT                       (0x00000018U)
#define CSL_GIC400_GICC_NSAPR0_AP24_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP24_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP25_MASK                        (0x02000000U)
#define CSL_GIC400_GICC_NSAPR0_AP25_SHIFT                       (0x00000019U)
#define CSL_GIC400_GICC_NSAPR0_AP25_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP25_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP26_MASK                        (0x04000000U)
#define CSL_GIC400_GICC_NSAPR0_AP26_SHIFT                       (0x0000001AU)
#define CSL_GIC400_GICC_NSAPR0_AP26_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP26_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP27_MASK                        (0x08000000U)
#define CSL_GIC400_GICC_NSAPR0_AP27_SHIFT                       (0x0000001BU)
#define CSL_GIC400_GICC_NSAPR0_AP27_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP27_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP28_MASK                        (0x10000000U)
#define CSL_GIC400_GICC_NSAPR0_AP28_SHIFT                       (0x0000001CU)
#define CSL_GIC400_GICC_NSAPR0_AP28_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP28_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP29_MASK                        (0x20000000U)
#define CSL_GIC400_GICC_NSAPR0_AP29_SHIFT                       (0x0000001DU)
#define CSL_GIC400_GICC_NSAPR0_AP29_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP29_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP30_MASK                        (0x40000000U)
#define CSL_GIC400_GICC_NSAPR0_AP30_SHIFT                       (0x0000001EU)
#define CSL_GIC400_GICC_NSAPR0_AP30_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP30_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_AP31_MASK                        (0x80000000U)
#define CSL_GIC400_GICC_NSAPR0_AP31_SHIFT                       (0x0000001FU)
#define CSL_GIC400_GICC_NSAPR0_AP31_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICC_NSAPR0_AP31_MAX                         (0x00000001U)

#define CSL_GIC400_GICC_NSAPR0_RESETVAL                         (0x00000000U)

/* GICC_IIDR */

#define CSL_GIC400_GICC_IIDR_IMPLEMENTER_MASK                   (0x00000FFFU)
#define CSL_GIC400_GICC_IIDR_IMPLEMENTER_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICC_IIDR_IMPLEMENTER_RESETVAL               (0x0000043bU)
#define CSL_GIC400_GICC_IIDR_IMPLEMENTER_MAX                    (0x00000fffU)

#define CSL_GIC400_GICC_IIDR_REVISION_MASK                      (0x0000F000U)
#define CSL_GIC400_GICC_IIDR_REVISION_SHIFT                     (0x0000000CU)
#define CSL_GIC400_GICC_IIDR_REVISION_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICC_IIDR_REVISION_MAX                       (0x0000000fU)

#define CSL_GIC400_GICC_IIDR_ARCHITECTUREVERSION_MASK           (0x000F0000U)
#define CSL_GIC400_GICC_IIDR_ARCHITECTUREVERSION_SHIFT          (0x00000010U)
#define CSL_GIC400_GICC_IIDR_ARCHITECTUREVERSION_RESETVAL       (0x00000002U)
#define CSL_GIC400_GICC_IIDR_ARCHITECTUREVERSION_MAX            (0x0000000fU)

#define CSL_GIC400_GICC_IIDR_PRODUCTID_MASK                     (0xFFF00000U)
#define CSL_GIC400_GICC_IIDR_PRODUCTID_SHIFT                    (0x00000014U)
#define CSL_GIC400_GICC_IIDR_PRODUCTID_RESETVAL                 (0x00000020U)
#define CSL_GIC400_GICC_IIDR_PRODUCTID_MAX                      (0x00000fffU)

#define CSL_GIC400_GICC_IIDR_RESETVAL                           (0x0202043bU)

/* GICC_DIR */

#define CSL_GIC400_GICC_DIR_INTERRUPTID_MASK                    (0x000003FFU)
#define CSL_GIC400_GICC_DIR_INTERRUPTID_SHIFT                   (0x00000000U)
#define CSL_GIC400_GICC_DIR_INTERRUPTID_RESETVAL                (0x00000000U)
#define CSL_GIC400_GICC_DIR_INTERRUPTID_MAX                     (0x000003ffU)

#define CSL_GIC400_GICC_DIR_CPUID_MASK                          (0x00001C00U)
#define CSL_GIC400_GICC_DIR_CPUID_SHIFT                         (0x0000000AU)
#define CSL_GIC400_GICC_DIR_CPUID_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICC_DIR_CPUID_MAX                           (0x00000007U)

#define CSL_GIC400_GICC_DIR_RESETVAL                            (0x00000000U)

/* GICH_HCR */

#define CSL_GIC400_GICH_HCR_EN_MASK                             (0x00000001U)
#define CSL_GIC400_GICH_HCR_EN_SHIFT                            (0x00000000U)
#define CSL_GIC400_GICH_HCR_EN_RESETVAL                         (0x00000000U)
#define CSL_GIC400_GICH_HCR_EN_MAX                              (0x00000001U)

#define CSL_GIC400_GICH_HCR_UIE_MASK                            (0x00000002U)
#define CSL_GIC400_GICH_HCR_UIE_SHIFT                           (0x00000001U)
#define CSL_GIC400_GICH_HCR_UIE_RESETVAL                        (0x00000000U)
#define CSL_GIC400_GICH_HCR_UIE_MAX                             (0x00000001U)

#define CSL_GIC400_GICH_HCR_SKIDIE_MASK                         (0x00000004U)
#define CSL_GIC400_GICH_HCR_SKIDIE_SHIFT                        (0x00000002U)
#define CSL_GIC400_GICH_HCR_SKIDIE_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICH_HCR_SKIDIE_MAX                          (0x00000001U)

#define CSL_GIC400_GICH_HCR_NPIE_MASK                           (0x00000008U)
#define CSL_GIC400_GICH_HCR_NPIE_SHIFT                          (0x00000003U)
#define CSL_GIC400_GICH_HCR_NPIE_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_HCR_NPIE_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_HCR_VESIE_MASK                          (0x00000010U)
#define CSL_GIC400_GICH_HCR_VESIE_SHIFT                         (0x00000004U)
#define CSL_GIC400_GICH_HCR_VESIE_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_HCR_VESIE_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_HCR_VDSIE_MASK                          (0x00000020U)
#define CSL_GIC400_GICH_HCR_VDSIE_SHIFT                         (0x00000005U)
#define CSL_GIC400_GICH_HCR_VDSIE_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_HCR_VDSIE_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_HCR_VENSIE_MASK                         (0x00000040U)
#define CSL_GIC400_GICH_HCR_VENSIE_SHIFT                        (0x00000006U)
#define CSL_GIC400_GICH_HCR_VENSIE_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICH_HCR_VENSIE_MAX                          (0x00000001U)

#define CSL_GIC400_GICH_HCR_VDNSIE_MASK                         (0x00000080U)
#define CSL_GIC400_GICH_HCR_VDNSIE_SHIFT                        (0x00000007U)
#define CSL_GIC400_GICH_HCR_VDNSIE_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICH_HCR_VDNSIE_MAX                          (0x00000001U)

#define CSL_GIC400_GICH_HCR_EOICOUNT_MASK                       (0xF8000000U)
#define CSL_GIC400_GICH_HCR_EOICOUNT_SHIFT                      (0x0000001BU)
#define CSL_GIC400_GICH_HCR_EOICOUNT_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICH_HCR_EOICOUNT_MAX                        (0x0000001fU)

#define CSL_GIC400_GICH_HCR_RESETVAL                            (0x00000000U)

/* GICH_VTR */

#define CSL_GIC400_GICH_VTR_LISTREGS_MASK                       (0x0000003FU)
#define CSL_GIC400_GICH_VTR_LISTREGS_SHIFT                      (0x00000000U)
#define CSL_GIC400_GICH_VTR_LISTREGS_RESETVAL                   (0x00000003U)
#define CSL_GIC400_GICH_VTR_LISTREGS_MAX                        (0x0000003fU)

#define CSL_GIC400_GICH_VTR_PREBITS_MASK                        (0x1C000000U)
#define CSL_GIC400_GICH_VTR_PREBITS_SHIFT                       (0x0000001AU)
#define CSL_GIC400_GICH_VTR_PREBITS_RESETVAL                    (0x00000004U)
#define CSL_GIC400_GICH_VTR_PREBITS_MAX                         (0x00000007U)

#define CSL_GIC400_GICH_VTR_PRIBITS_MASK                        (0xE0000000U)
#define CSL_GIC400_GICH_VTR_PRIBITS_SHIFT                       (0x0000001DU)
#define CSL_GIC400_GICH_VTR_PRIBITS_RESETVAL                    (0x00000004U)
#define CSL_GIC400_GICH_VTR_PRIBITS_MAX                         (0x00000007U)

#define CSL_GIC400_GICH_VTR_RESETVAL                            (0x90000003U)

/* GICH_VMCR */

#define CSL_GIC400_GICH_VMCR_VMSEN_MASK                         (0x00000001U)
#define CSL_GIC400_GICH_VMCR_VMSEN_SHIFT                        (0x00000000U)
#define CSL_GIC400_GICH_VMCR_VMSEN_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICH_VMCR_VMSEN_MAX                          (0x00000001U)

#define CSL_GIC400_GICH_VMCR_VMNSEN_MASK                        (0x00000002U)
#define CSL_GIC400_GICH_VMCR_VMNSEN_SHIFT                       (0x00000001U)
#define CSL_GIC400_GICH_VMCR_VMNSEN_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICH_VMCR_VMNSEN_MAX                         (0x00000001U)

#define CSL_GIC400_GICH_VMCR_VMACKCTL_MASK                      (0x00000004U)
#define CSL_GIC400_GICH_VMCR_VMACKCTL_SHIFT                     (0x00000002U)
#define CSL_GIC400_GICH_VMCR_VMACKCTL_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICH_VMCR_VMACKCTL_MAX                       (0x00000001U)

#define CSL_GIC400_GICH_VMCR_VMFIQEN_MASK                       (0x00000008U)
#define CSL_GIC400_GICH_VMCR_VMFIQEN_SHIFT                      (0x00000003U)
#define CSL_GIC400_GICH_VMCR_VMFIQEN_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICH_VMCR_VMFIQEN_MAX                        (0x00000001U)

#define CSL_GIC400_GICH_VMCR_VMSBPR_MASK                        (0x00000010U)
#define CSL_GIC400_GICH_VMCR_VMSBPR_SHIFT                       (0x00000004U)
#define CSL_GIC400_GICH_VMCR_VMSBPR_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICH_VMCR_VMSBPR_MAX                         (0x00000001U)

#define CSL_GIC400_GICH_VMCR_VEM_MASK                           (0x00000200U)
#define CSL_GIC400_GICH_VMCR_VEM_SHIFT                          (0x00000009U)
#define CSL_GIC400_GICH_VMCR_VEM_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_VMCR_VEM_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_VMCR_VMNSBP_MASK                        (0x001C0000U)
#define CSL_GIC400_GICH_VMCR_VMNSBP_SHIFT                       (0x00000012U)
#define CSL_GIC400_GICH_VMCR_VMNSBP_RESETVAL                    (0x00000003U)
#define CSL_GIC400_GICH_VMCR_VMNSBP_MAX                         (0x00000007U)

#define CSL_GIC400_GICH_VMCR_VMBP_MASK                          (0x00E00000U)
#define CSL_GIC400_GICH_VMCR_VMBP_SHIFT                         (0x00000015U)
#define CSL_GIC400_GICH_VMCR_VMBP_RESETVAL                      (0x00000002U)
#define CSL_GIC400_GICH_VMCR_VMBP_MAX                           (0x00000007U)

#define CSL_GIC400_GICH_VMCR_VMPRIMASK_MASK                     (0xF8000000U)
#define CSL_GIC400_GICH_VMCR_VMPRIMASK_SHIFT                    (0x0000001BU)
#define CSL_GIC400_GICH_VMCR_VMPRIMASK_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICH_VMCR_VMPRIMASK_MAX                      (0x0000001fU)

#define CSL_GIC400_GICH_VMCR_RESETVAL                           (0x004c0000U)

/* GICH_MISR */

#define CSL_GIC400_GICH_MISR_EI_MASK                            (0x00000001U)
#define CSL_GIC400_GICH_MISR_EI_SHIFT                           (0x00000000U)
#define CSL_GIC400_GICH_MISR_EI_RESETVAL                        (0x00000000U)
#define CSL_GIC400_GICH_MISR_EI_MAX                             (0x00000001U)

#define CSL_GIC400_GICH_MISR_UI_MASK                            (0x00000002U)
#define CSL_GIC400_GICH_MISR_UI_SHIFT                           (0x00000001U)
#define CSL_GIC400_GICH_MISR_UI_RESETVAL                        (0x00000000U)
#define CSL_GIC400_GICH_MISR_UI_MAX                             (0x00000001U)

#define CSL_GIC400_GICH_MISR_SKIDI_MASK                         (0x00000004U)
#define CSL_GIC400_GICH_MISR_SKIDI_SHIFT                        (0x00000002U)
#define CSL_GIC400_GICH_MISR_SKIDI_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICH_MISR_SKIDI_MAX                          (0x00000001U)

#define CSL_GIC400_GICH_MISR_NPI_MASK                           (0x00000008U)
#define CSL_GIC400_GICH_MISR_NPI_SHIFT                          (0x00000003U)
#define CSL_GIC400_GICH_MISR_NPI_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_MISR_NPI_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_MISR_VESI_MASK                          (0x00000010U)
#define CSL_GIC400_GICH_MISR_VESI_SHIFT                         (0x00000004U)
#define CSL_GIC400_GICH_MISR_VESI_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_MISR_VESI_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_MISR_VDSI_MASK                          (0x00000020U)
#define CSL_GIC400_GICH_MISR_VDSI_SHIFT                         (0x00000005U)
#define CSL_GIC400_GICH_MISR_VDSI_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_MISR_VDSI_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_MISR_VENSI_MASK                         (0x00000040U)
#define CSL_GIC400_GICH_MISR_VENSI_SHIFT                        (0x00000006U)
#define CSL_GIC400_GICH_MISR_VENSI_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICH_MISR_VENSI_MAX                          (0x00000001U)

#define CSL_GIC400_GICH_MISR_VDNSI_MASK                         (0x00000080U)
#define CSL_GIC400_GICH_MISR_VDNSI_SHIFT                        (0x00000007U)
#define CSL_GIC400_GICH_MISR_VDNSI_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICH_MISR_VDNSI_MAX                          (0x00000001U)

#define CSL_GIC400_GICH_MISR_RESETVAL                           (0x00000000U)

/* GICH_EISR0 */

#define CSL_GIC400_GICH_EISR0_LR0_MASK                          (0x00000001U)
#define CSL_GIC400_GICH_EISR0_LR0_SHIFT                         (0x00000000U)
#define CSL_GIC400_GICH_EISR0_LR0_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_EISR0_LR0_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_EISR0_LR1_MASK                          (0x00000002U)
#define CSL_GIC400_GICH_EISR0_LR1_SHIFT                         (0x00000001U)
#define CSL_GIC400_GICH_EISR0_LR1_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_EISR0_LR1_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_EISR0_LR2_MASK                          (0x00000004U)
#define CSL_GIC400_GICH_EISR0_LR2_SHIFT                         (0x00000002U)
#define CSL_GIC400_GICH_EISR0_LR2_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_EISR0_LR2_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_EISR0_LR3_MASK                          (0x00000008U)
#define CSL_GIC400_GICH_EISR0_LR3_SHIFT                         (0x00000003U)
#define CSL_GIC400_GICH_EISR0_LR3_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_EISR0_LR3_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_EISR0_RESETVAL                          (0x00000000U)

/* GICH_ELSR0 */

#define CSL_GIC400_GICH_ELSR0_LR0_MASK                          (0x00000001U)
#define CSL_GIC400_GICH_ELSR0_LR0_SHIFT                         (0x00000000U)
#define CSL_GIC400_GICH_ELSR0_LR0_RESETVAL                      (0x00000001U)
#define CSL_GIC400_GICH_ELSR0_LR0_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_ELSR0_LR1_MASK                          (0x00000002U)
#define CSL_GIC400_GICH_ELSR0_LR1_SHIFT                         (0x00000001U)
#define CSL_GIC400_GICH_ELSR0_LR1_RESETVAL                      (0x00000001U)
#define CSL_GIC400_GICH_ELSR0_LR1_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_ELSR0_LR2_MASK                          (0x00000004U)
#define CSL_GIC400_GICH_ELSR0_LR2_SHIFT                         (0x00000002U)
#define CSL_GIC400_GICH_ELSR0_LR2_RESETVAL                      (0x00000001U)
#define CSL_GIC400_GICH_ELSR0_LR2_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_ELSR0_LR3_MASK                          (0x00000008U)
#define CSL_GIC400_GICH_ELSR0_LR3_SHIFT                         (0x00000003U)
#define CSL_GIC400_GICH_ELSR0_LR3_RESETVAL                      (0x00000001U)
#define CSL_GIC400_GICH_ELSR0_LR3_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_ELSR0_RESETVAL                          (0x0000000fU)

/* GICH_APR0 */

#define CSL_GIC400_GICH_APR0_AP0_MASK                           (0x00000001U)
#define CSL_GIC400_GICH_APR0_AP0_SHIFT                          (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP0_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP0_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP1_MASK                           (0x00000002U)
#define CSL_GIC400_GICH_APR0_AP1_SHIFT                          (0x00000001U)
#define CSL_GIC400_GICH_APR0_AP1_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP1_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP2_MASK                           (0x00000004U)
#define CSL_GIC400_GICH_APR0_AP2_SHIFT                          (0x00000002U)
#define CSL_GIC400_GICH_APR0_AP2_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP2_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP3_MASK                           (0x00000008U)
#define CSL_GIC400_GICH_APR0_AP3_SHIFT                          (0x00000003U)
#define CSL_GIC400_GICH_APR0_AP3_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP3_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP4_MASK                           (0x00000010U)
#define CSL_GIC400_GICH_APR0_AP4_SHIFT                          (0x00000004U)
#define CSL_GIC400_GICH_APR0_AP4_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP4_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP5_MASK                           (0x00000020U)
#define CSL_GIC400_GICH_APR0_AP5_SHIFT                          (0x00000005U)
#define CSL_GIC400_GICH_APR0_AP5_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP5_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP6_MASK                           (0x00000040U)
#define CSL_GIC400_GICH_APR0_AP6_SHIFT                          (0x00000006U)
#define CSL_GIC400_GICH_APR0_AP6_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP6_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP7_MASK                           (0x00000080U)
#define CSL_GIC400_GICH_APR0_AP7_SHIFT                          (0x00000007U)
#define CSL_GIC400_GICH_APR0_AP7_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP7_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP8_MASK                           (0x00000100U)
#define CSL_GIC400_GICH_APR0_AP8_SHIFT                          (0x00000008U)
#define CSL_GIC400_GICH_APR0_AP8_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP8_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP9_MASK                           (0x00000200U)
#define CSL_GIC400_GICH_APR0_AP9_SHIFT                          (0x00000009U)
#define CSL_GIC400_GICH_APR0_AP9_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP9_MAX                            (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP10_MASK                          (0x00000400U)
#define CSL_GIC400_GICH_APR0_AP10_SHIFT                         (0x0000000AU)
#define CSL_GIC400_GICH_APR0_AP10_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP10_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP11_MASK                          (0x00000800U)
#define CSL_GIC400_GICH_APR0_AP11_SHIFT                         (0x0000000BU)
#define CSL_GIC400_GICH_APR0_AP11_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP11_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP12_MASK                          (0x00001000U)
#define CSL_GIC400_GICH_APR0_AP12_SHIFT                         (0x0000000CU)
#define CSL_GIC400_GICH_APR0_AP12_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP12_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP13_MASK                          (0x00002000U)
#define CSL_GIC400_GICH_APR0_AP13_SHIFT                         (0x0000000DU)
#define CSL_GIC400_GICH_APR0_AP13_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP13_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP14_MASK                          (0x00004000U)
#define CSL_GIC400_GICH_APR0_AP14_SHIFT                         (0x0000000EU)
#define CSL_GIC400_GICH_APR0_AP14_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP14_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP15_MASK                          (0x00008000U)
#define CSL_GIC400_GICH_APR0_AP15_SHIFT                         (0x0000000FU)
#define CSL_GIC400_GICH_APR0_AP15_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP15_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP16_MASK                          (0x00010000U)
#define CSL_GIC400_GICH_APR0_AP16_SHIFT                         (0x00000010U)
#define CSL_GIC400_GICH_APR0_AP16_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP16_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP17_MASK                          (0x00020000U)
#define CSL_GIC400_GICH_APR0_AP17_SHIFT                         (0x00000011U)
#define CSL_GIC400_GICH_APR0_AP17_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP17_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP18_MASK                          (0x00040000U)
#define CSL_GIC400_GICH_APR0_AP18_SHIFT                         (0x00000012U)
#define CSL_GIC400_GICH_APR0_AP18_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP18_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP19_MASK                          (0x00080000U)
#define CSL_GIC400_GICH_APR0_AP19_SHIFT                         (0x00000013U)
#define CSL_GIC400_GICH_APR0_AP19_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP19_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP20_MASK                          (0x00100000U)
#define CSL_GIC400_GICH_APR0_AP20_SHIFT                         (0x00000014U)
#define CSL_GIC400_GICH_APR0_AP20_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP20_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP21_MASK                          (0x00200000U)
#define CSL_GIC400_GICH_APR0_AP21_SHIFT                         (0x00000015U)
#define CSL_GIC400_GICH_APR0_AP21_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP21_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP22_MASK                          (0x00400000U)
#define CSL_GIC400_GICH_APR0_AP22_SHIFT                         (0x00000016U)
#define CSL_GIC400_GICH_APR0_AP22_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP22_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP23_MASK                          (0x00800000U)
#define CSL_GIC400_GICH_APR0_AP23_SHIFT                         (0x00000017U)
#define CSL_GIC400_GICH_APR0_AP23_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP23_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP24_MASK                          (0x01000000U)
#define CSL_GIC400_GICH_APR0_AP24_SHIFT                         (0x00000018U)
#define CSL_GIC400_GICH_APR0_AP24_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP24_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP25_MASK                          (0x02000000U)
#define CSL_GIC400_GICH_APR0_AP25_SHIFT                         (0x00000019U)
#define CSL_GIC400_GICH_APR0_AP25_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP25_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP26_MASK                          (0x04000000U)
#define CSL_GIC400_GICH_APR0_AP26_SHIFT                         (0x0000001AU)
#define CSL_GIC400_GICH_APR0_AP26_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP26_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP27_MASK                          (0x08000000U)
#define CSL_GIC400_GICH_APR0_AP27_SHIFT                         (0x0000001BU)
#define CSL_GIC400_GICH_APR0_AP27_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP27_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP28_MASK                          (0x10000000U)
#define CSL_GIC400_GICH_APR0_AP28_SHIFT                         (0x0000001CU)
#define CSL_GIC400_GICH_APR0_AP28_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP28_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP29_MASK                          (0x20000000U)
#define CSL_GIC400_GICH_APR0_AP29_SHIFT                         (0x0000001DU)
#define CSL_GIC400_GICH_APR0_AP29_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP29_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP30_MASK                          (0x40000000U)
#define CSL_GIC400_GICH_APR0_AP30_SHIFT                         (0x0000001EU)
#define CSL_GIC400_GICH_APR0_AP30_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP30_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_AP31_MASK                          (0x80000000U)
#define CSL_GIC400_GICH_APR0_AP31_SHIFT                         (0x0000001FU)
#define CSL_GIC400_GICH_APR0_AP31_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_APR0_AP31_MAX                           (0x00000001U)

#define CSL_GIC400_GICH_APR0_RESETVAL                           (0x00000000U)

/* GICH_LR0 */

#define CSL_GIC400_GICH_LR0_VIRTUALID_MASK                      (0x000003FFU)
#define CSL_GIC400_GICH_LR0_VIRTUALID_SHIFT                     (0x00000000U)
#define CSL_GIC400_GICH_LR0_VIRTUALID_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICH_LR0_VIRTUALID_MAX                       (0x000003ffU)

#define CSL_GIC400_GICH_LR0_PHYSICALID_MASK                     (0x000FFC00U)
#define CSL_GIC400_GICH_LR0_PHYSICALID_SHIFT                    (0x0000000AU)
#define CSL_GIC400_GICH_LR0_PHYSICALID_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICH_LR0_PHYSICALID_MAX                      (0x000003ffU)

#define CSL_GIC400_GICH_LR0_PRIORITY_MASK                       (0x0F800000U)
#define CSL_GIC400_GICH_LR0_PRIORITY_SHIFT                      (0x00000017U)
#define CSL_GIC400_GICH_LR0_PRIORITY_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICH_LR0_PRIORITY_MAX                        (0x0000001fU)

#define CSL_GIC400_GICH_LR0_STATE_MASK                          (0x30000000U)
#define CSL_GIC400_GICH_LR0_STATE_SHIFT                         (0x0000001CU)
#define CSL_GIC400_GICH_LR0_STATE_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_LR0_STATE_MAX                           (0x00000003U)

#define CSL_GIC400_GICH_LR0_NS_MASK                             (0x40000000U)
#define CSL_GIC400_GICH_LR0_NS_SHIFT                            (0x0000001EU)
#define CSL_GIC400_GICH_LR0_NS_RESETVAL                         (0x00000000U)
#define CSL_GIC400_GICH_LR0_NS_MAX                              (0x00000001U)

#define CSL_GIC400_GICH_LR0_HW_MASK                             (0x80000000U)
#define CSL_GIC400_GICH_LR0_HW_SHIFT                            (0x0000001FU)
#define CSL_GIC400_GICH_LR0_HW_RESETVAL                         (0x00000000U)
#define CSL_GIC400_GICH_LR0_HW_MAX                              (0x00000001U)

#define CSL_GIC400_GICH_LR0_RESETVAL                            (0x00000000U)

/* GICH_LR1 */

#define CSL_GIC400_GICH_LR1_VIRTUALID_MASK                      (0x000003FFU)
#define CSL_GIC400_GICH_LR1_VIRTUALID_SHIFT                     (0x00000000U)
#define CSL_GIC400_GICH_LR1_VIRTUALID_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICH_LR1_VIRTUALID_MAX                       (0x000003ffU)

#define CSL_GIC400_GICH_LR1_PHYSICALID_MASK                     (0x000FFC00U)
#define CSL_GIC400_GICH_LR1_PHYSICALID_SHIFT                    (0x0000000AU)
#define CSL_GIC400_GICH_LR1_PHYSICALID_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICH_LR1_PHYSICALID_MAX                      (0x000003ffU)

#define CSL_GIC400_GICH_LR1_PRIORITY_MASK                       (0x0F800000U)
#define CSL_GIC400_GICH_LR1_PRIORITY_SHIFT                      (0x00000017U)
#define CSL_GIC400_GICH_LR1_PRIORITY_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICH_LR1_PRIORITY_MAX                        (0x0000001fU)

#define CSL_GIC400_GICH_LR1_STATE_MASK                          (0x30000000U)
#define CSL_GIC400_GICH_LR1_STATE_SHIFT                         (0x0000001CU)
#define CSL_GIC400_GICH_LR1_STATE_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_LR1_STATE_MAX                           (0x00000003U)

#define CSL_GIC400_GICH_LR1_NS_MASK                             (0x40000000U)
#define CSL_GIC400_GICH_LR1_NS_SHIFT                            (0x0000001EU)
#define CSL_GIC400_GICH_LR1_NS_RESETVAL                         (0x00000000U)
#define CSL_GIC400_GICH_LR1_NS_MAX                              (0x00000001U)

#define CSL_GIC400_GICH_LR1_HW_MASK                             (0x80000000U)
#define CSL_GIC400_GICH_LR1_HW_SHIFT                            (0x0000001FU)
#define CSL_GIC400_GICH_LR1_HW_RESETVAL                         (0x00000000U)
#define CSL_GIC400_GICH_LR1_HW_MAX                              (0x00000001U)

#define CSL_GIC400_GICH_LR1_RESETVAL                            (0x00000000U)

/* GICH_LR2 */

#define CSL_GIC400_GICH_LR2_VIRTUALID_MASK                      (0x000003FFU)
#define CSL_GIC400_GICH_LR2_VIRTUALID_SHIFT                     (0x00000000U)
#define CSL_GIC400_GICH_LR2_VIRTUALID_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICH_LR2_VIRTUALID_MAX                       (0x000003ffU)

#define CSL_GIC400_GICH_LR2_PHYSICALID_MASK                     (0x000FFC00U)
#define CSL_GIC400_GICH_LR2_PHYSICALID_SHIFT                    (0x0000000AU)
#define CSL_GIC400_GICH_LR2_PHYSICALID_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICH_LR2_PHYSICALID_MAX                      (0x000003ffU)

#define CSL_GIC400_GICH_LR2_PRIORITY_MASK                       (0x0F800000U)
#define CSL_GIC400_GICH_LR2_PRIORITY_SHIFT                      (0x00000017U)
#define CSL_GIC400_GICH_LR2_PRIORITY_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICH_LR2_PRIORITY_MAX                        (0x0000001fU)

#define CSL_GIC400_GICH_LR2_STATE_MASK                          (0x30000000U)
#define CSL_GIC400_GICH_LR2_STATE_SHIFT                         (0x0000001CU)
#define CSL_GIC400_GICH_LR2_STATE_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_LR2_STATE_MAX                           (0x00000003U)

#define CSL_GIC400_GICH_LR2_NS_MASK                             (0x40000000U)
#define CSL_GIC400_GICH_LR2_NS_SHIFT                            (0x0000001EU)
#define CSL_GIC400_GICH_LR2_NS_RESETVAL                         (0x00000000U)
#define CSL_GIC400_GICH_LR2_NS_MAX                              (0x00000001U)

#define CSL_GIC400_GICH_LR2_HW_MASK                             (0x80000000U)
#define CSL_GIC400_GICH_LR2_HW_SHIFT                            (0x0000001FU)
#define CSL_GIC400_GICH_LR2_HW_RESETVAL                         (0x00000000U)
#define CSL_GIC400_GICH_LR2_HW_MAX                              (0x00000001U)

#define CSL_GIC400_GICH_LR2_RESETVAL                            (0x00000000U)

/* GICH_LR3 */

#define CSL_GIC400_GICH_LR3_VIRTUALID_MASK                      (0x000003FFU)
#define CSL_GIC400_GICH_LR3_VIRTUALID_SHIFT                     (0x00000000U)
#define CSL_GIC400_GICH_LR3_VIRTUALID_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICH_LR3_VIRTUALID_MAX                       (0x000003ffU)

#define CSL_GIC400_GICH_LR3_PHYSICALID_MASK                     (0x000FFC00U)
#define CSL_GIC400_GICH_LR3_PHYSICALID_SHIFT                    (0x0000000AU)
#define CSL_GIC400_GICH_LR3_PHYSICALID_RESETVAL                 (0x00000000U)
#define CSL_GIC400_GICH_LR3_PHYSICALID_MAX                      (0x000003ffU)

#define CSL_GIC400_GICH_LR3_PRIORITY_MASK                       (0x0F800000U)
#define CSL_GIC400_GICH_LR3_PRIORITY_SHIFT                      (0x00000017U)
#define CSL_GIC400_GICH_LR3_PRIORITY_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICH_LR3_PRIORITY_MAX                        (0x0000001fU)

#define CSL_GIC400_GICH_LR3_STATE_MASK                          (0x30000000U)
#define CSL_GIC400_GICH_LR3_STATE_SHIFT                         (0x0000001CU)
#define CSL_GIC400_GICH_LR3_STATE_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICH_LR3_STATE_MAX                           (0x00000003U)

#define CSL_GIC400_GICH_LR3_NS_MASK                             (0x40000000U)
#define CSL_GIC400_GICH_LR3_NS_SHIFT                            (0x0000001EU)
#define CSL_GIC400_GICH_LR3_NS_RESETVAL                         (0x00000000U)
#define CSL_GIC400_GICH_LR3_NS_MAX                              (0x00000001U)

#define CSL_GIC400_GICH_LR3_HW_MASK                             (0x80000000U)
#define CSL_GIC400_GICH_LR3_HW_SHIFT                            (0x0000001FU)
#define CSL_GIC400_GICH_LR3_HW_RESETVAL                         (0x00000000U)
#define CSL_GIC400_GICH_LR3_HW_MAX                              (0x00000001U)

#define CSL_GIC400_GICH_LR3_RESETVAL                            (0x00000000U)

/* GICV_CTLR */

#define CSL_GIC400_GICV_CTLR_ENABLEGRP0_MASK                    (0x00000001U)
#define CSL_GIC400_GICV_CTLR_ENABLEGRP0_SHIFT                   (0x00000000U)
#define CSL_GIC400_GICV_CTLR_ENABLEGRP0_RESETVAL                (0x00000000U)
#define CSL_GIC400_GICV_CTLR_ENABLEGRP0_MAX                     (0x00000001U)

#define CSL_GIC400_GICV_CTLR_ENABLEGRP1_MASK                    (0x00000002U)
#define CSL_GIC400_GICV_CTLR_ENABLEGRP1_SHIFT                   (0x00000001U)
#define CSL_GIC400_GICV_CTLR_ENABLEGRP1_RESETVAL                (0x00000000U)
#define CSL_GIC400_GICV_CTLR_ENABLEGRP1_MAX                     (0x00000001U)

#define CSL_GIC400_GICV_CTLR_ACKCTL_MASK                        (0x00000004U)
#define CSL_GIC400_GICV_CTLR_ACKCTL_SHIFT                       (0x00000002U)
#define CSL_GIC400_GICV_CTLR_ACKCTL_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICV_CTLR_ACKCTL_MAX                         (0x00000001U)

#define CSL_GIC400_GICV_CTLR_FIQEN_MASK                         (0x00000008U)
#define CSL_GIC400_GICV_CTLR_FIQEN_SHIFT                        (0x00000003U)
#define CSL_GIC400_GICV_CTLR_FIQEN_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICV_CTLR_FIQEN_MAX                          (0x00000001U)

#define CSL_GIC400_GICV_CTLR_CBPR_MASK                          (0x00000010U)
#define CSL_GIC400_GICV_CTLR_CBPR_SHIFT                         (0x00000004U)
#define CSL_GIC400_GICV_CTLR_CBPR_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_CTLR_CBPR_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_CTLR_EOIMODE_MASK                       (0x00000200U)
#define CSL_GIC400_GICV_CTLR_EOIMODE_SHIFT                      (0x00000009U)
#define CSL_GIC400_GICV_CTLR_EOIMODE_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICV_CTLR_EOIMODE_MAX                        (0x00000001U)

#define CSL_GIC400_GICV_CTLR_RESETVAL                           (0x00000000U)

/* GICV_PMR */

#define CSL_GIC400_GICV_PMR_PRIORITY_MASK                       (0x000000F8U)
#define CSL_GIC400_GICV_PMR_PRIORITY_SHIFT                      (0x00000003U)
#define CSL_GIC400_GICV_PMR_PRIORITY_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICV_PMR_PRIORITY_MAX                        (0x0000001fU)

#define CSL_GIC400_GICV_PMR_RESETVAL                            (0x00000000U)

/* GICV_BPR */

#define CSL_GIC400_GICV_BPR_BINARYPOINT_MASK                    (0x00000007U)
#define CSL_GIC400_GICV_BPR_BINARYPOINT_SHIFT                   (0x00000000U)
#define CSL_GIC400_GICV_BPR_BINARYPOINT_RESETVAL                (0x00000002U)
#define CSL_GIC400_GICV_BPR_BINARYPOINT_MAX                     (0x00000007U)

#define CSL_GIC400_GICV_BPR_RESETVAL                            (0x00000002U)

/* GICV_IAR */

#define CSL_GIC400_GICV_IAR_INTERRUPTID_MASK                    (0x000003FFU)
#define CSL_GIC400_GICV_IAR_INTERRUPTID_SHIFT                   (0x00000000U)
#define CSL_GIC400_GICV_IAR_INTERRUPTID_RESETVAL                (0x000003ffU)
#define CSL_GIC400_GICV_IAR_INTERRUPTID_MAX                     (0x000003ffU)

#define CSL_GIC400_GICV_IAR_CPUID_MASK                          (0x00001C00U)
#define CSL_GIC400_GICV_IAR_CPUID_SHIFT                         (0x0000000AU)
#define CSL_GIC400_GICV_IAR_CPUID_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_IAR_CPUID_MAX                           (0x00000007U)

#define CSL_GIC400_GICV_IAR_RESETVAL                            (0x000003ffU)

/* GICV_EOIR */

#define CSL_GIC400_GICV_EOIR_EOIINTID_MASK                      (0x000003FFU)
#define CSL_GIC400_GICV_EOIR_EOIINTID_SHIFT                     (0x00000000U)
#define CSL_GIC400_GICV_EOIR_EOIINTID_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICV_EOIR_EOIINTID_MAX                       (0x000003ffU)

#define CSL_GIC400_GICV_EOIR_CPUID_MASK                         (0x00001C00U)
#define CSL_GIC400_GICV_EOIR_CPUID_SHIFT                        (0x0000000AU)
#define CSL_GIC400_GICV_EOIR_CPUID_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICV_EOIR_CPUID_MAX                          (0x00000007U)

#define CSL_GIC400_GICV_EOIR_RESETVAL                           (0x00000000U)

/* GICV_RPR */

#define CSL_GIC400_GICV_RPR_INTERRUPTID_MASK                    (0x000003FFU)
#define CSL_GIC400_GICV_RPR_INTERRUPTID_SHIFT                   (0x00000000U)
#define CSL_GIC400_GICV_RPR_INTERRUPTID_RESETVAL                (0x000000ffU)
#define CSL_GIC400_GICV_RPR_INTERRUPTID_MAX                     (0x000003ffU)

#define CSL_GIC400_GICV_RPR_CPUID_MASK                          (0x00001C00U)
#define CSL_GIC400_GICV_RPR_CPUID_SHIFT                         (0x0000000AU)
#define CSL_GIC400_GICV_RPR_CPUID_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_RPR_CPUID_MAX                           (0x00000007U)

#define CSL_GIC400_GICV_RPR_RESETVAL                            (0x000000ffU)

/* GICV_HPPIR */

#define CSL_GIC400_GICV_HPPIR_PENDINTID_MASK                    (0x000003FFU)
#define CSL_GIC400_GICV_HPPIR_PENDINTID_SHIFT                   (0x00000000U)
#define CSL_GIC400_GICV_HPPIR_PENDINTID_RESETVAL                (0x000003ffU)
#define CSL_GIC400_GICV_HPPIR_PENDINTID_MAX                     (0x000003ffU)

#define CSL_GIC400_GICV_HPPIR_CPUID_MASK                        (0x00001C00U)
#define CSL_GIC400_GICV_HPPIR_CPUID_SHIFT                       (0x0000000AU)
#define CSL_GIC400_GICV_HPPIR_CPUID_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICV_HPPIR_CPUID_MAX                         (0x00000007U)

#define CSL_GIC400_GICV_HPPIR_RESETVAL                          (0x000003ffU)

/* GICV_ABPR */

#define CSL_GIC400_GICV_ABPR_BINARYPOINT_MASK                   (0x00000007U)
#define CSL_GIC400_GICV_ABPR_BINARYPOINT_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICV_ABPR_BINARYPOINT_RESETVAL               (0x00000003U)
#define CSL_GIC400_GICV_ABPR_BINARYPOINT_MAX                    (0x00000007U)

#define CSL_GIC400_GICV_ABPR_RESETVAL                           (0x00000003U)

/* GICV_AIAR */

#define CSL_GIC400_GICV_AIAR_INTERRUPTID_MASK                   (0x000003FFU)
#define CSL_GIC400_GICV_AIAR_INTERRUPTID_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICV_AIAR_INTERRUPTID_RESETVAL               (0x000003ffU)
#define CSL_GIC400_GICV_AIAR_INTERRUPTID_MAX                    (0x000003ffU)

#define CSL_GIC400_GICV_AIAR_CPUID_MASK                         (0x00001C00U)
#define CSL_GIC400_GICV_AIAR_CPUID_SHIFT                        (0x0000000AU)
#define CSL_GIC400_GICV_AIAR_CPUID_RESETVAL                     (0x00000000U)
#define CSL_GIC400_GICV_AIAR_CPUID_MAX                          (0x00000007U)

#define CSL_GIC400_GICV_AIAR_RESETVAL                           (0x000003ffU)

/* GICV_AEOIR */

#define CSL_GIC400_GICV_AEOIR_INTERRUPTID_MASK                  (0x000003FFU)
#define CSL_GIC400_GICV_AEOIR_INTERRUPTID_SHIFT                 (0x00000000U)
#define CSL_GIC400_GICV_AEOIR_INTERRUPTID_RESETVAL              (0x00000000U)
#define CSL_GIC400_GICV_AEOIR_INTERRUPTID_MAX                   (0x000003ffU)

#define CSL_GIC400_GICV_AEOIR_CPUID_MASK                        (0x00001C00U)
#define CSL_GIC400_GICV_AEOIR_CPUID_SHIFT                       (0x0000000AU)
#define CSL_GIC400_GICV_AEOIR_CPUID_RESETVAL                    (0x00000000U)
#define CSL_GIC400_GICV_AEOIR_CPUID_MAX                         (0x00000007U)

#define CSL_GIC400_GICV_AEOIR_RESETVAL                          (0x00000000U)

/* GICV_AHPPIR */

#define CSL_GIC400_GICV_AHPPIR_PENDINTID_MASK                   (0x000003FFU)
#define CSL_GIC400_GICV_AHPPIR_PENDINTID_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICV_AHPPIR_PENDINTID_RESETVAL               (0x000003ffU)
#define CSL_GIC400_GICV_AHPPIR_PENDINTID_MAX                    (0x000003ffU)

#define CSL_GIC400_GICV_AHPPIR_CPUID_MASK                       (0x00001C00U)
#define CSL_GIC400_GICV_AHPPIR_CPUID_SHIFT                      (0x0000000AU)
#define CSL_GIC400_GICV_AHPPIR_CPUID_RESETVAL                   (0x00000000U)
#define CSL_GIC400_GICV_AHPPIR_CPUID_MAX                        (0x00000007U)

#define CSL_GIC400_GICV_AHPPIR_RESETVAL                         (0x000003ffU)

/* GICV_APR0 */

#define CSL_GIC400_GICV_APR0_AP0_MASK                           (0x00000001U)
#define CSL_GIC400_GICV_APR0_AP0_SHIFT                          (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP0_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP0_MAX                            (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP1_MASK                           (0x00000002U)
#define CSL_GIC400_GICV_APR0_AP1_SHIFT                          (0x00000001U)
#define CSL_GIC400_GICV_APR0_AP1_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP1_MAX                            (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP2_MASK                           (0x00000004U)
#define CSL_GIC400_GICV_APR0_AP2_SHIFT                          (0x00000002U)
#define CSL_GIC400_GICV_APR0_AP2_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP2_MAX                            (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP3_MASK                           (0x00000008U)
#define CSL_GIC400_GICV_APR0_AP3_SHIFT                          (0x00000003U)
#define CSL_GIC400_GICV_APR0_AP3_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP3_MAX                            (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP4_MASK                           (0x00000010U)
#define CSL_GIC400_GICV_APR0_AP4_SHIFT                          (0x00000004U)
#define CSL_GIC400_GICV_APR0_AP4_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP4_MAX                            (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP5_MASK                           (0x00000020U)
#define CSL_GIC400_GICV_APR0_AP5_SHIFT                          (0x00000005U)
#define CSL_GIC400_GICV_APR0_AP5_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP5_MAX                            (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP6_MASK                           (0x00000040U)
#define CSL_GIC400_GICV_APR0_AP6_SHIFT                          (0x00000006U)
#define CSL_GIC400_GICV_APR0_AP6_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP6_MAX                            (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP7_MASK                           (0x00000080U)
#define CSL_GIC400_GICV_APR0_AP7_SHIFT                          (0x00000007U)
#define CSL_GIC400_GICV_APR0_AP7_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP7_MAX                            (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP8_MASK                           (0x00000100U)
#define CSL_GIC400_GICV_APR0_AP8_SHIFT                          (0x00000008U)
#define CSL_GIC400_GICV_APR0_AP8_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP8_MAX                            (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP9_MASK                           (0x00000200U)
#define CSL_GIC400_GICV_APR0_AP9_SHIFT                          (0x00000009U)
#define CSL_GIC400_GICV_APR0_AP9_RESETVAL                       (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP9_MAX                            (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP10_MASK                          (0x00000400U)
#define CSL_GIC400_GICV_APR0_AP10_SHIFT                         (0x0000000AU)
#define CSL_GIC400_GICV_APR0_AP10_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP10_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP11_MASK                          (0x00000800U)
#define CSL_GIC400_GICV_APR0_AP11_SHIFT                         (0x0000000BU)
#define CSL_GIC400_GICV_APR0_AP11_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP11_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP12_MASK                          (0x00001000U)
#define CSL_GIC400_GICV_APR0_AP12_SHIFT                         (0x0000000CU)
#define CSL_GIC400_GICV_APR0_AP12_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP12_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP13_MASK                          (0x00002000U)
#define CSL_GIC400_GICV_APR0_AP13_SHIFT                         (0x0000000DU)
#define CSL_GIC400_GICV_APR0_AP13_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP13_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP14_MASK                          (0x00004000U)
#define CSL_GIC400_GICV_APR0_AP14_SHIFT                         (0x0000000EU)
#define CSL_GIC400_GICV_APR0_AP14_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP14_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP15_MASK                          (0x00008000U)
#define CSL_GIC400_GICV_APR0_AP15_SHIFT                         (0x0000000FU)
#define CSL_GIC400_GICV_APR0_AP15_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP15_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP16_MASK                          (0x00010000U)
#define CSL_GIC400_GICV_APR0_AP16_SHIFT                         (0x00000010U)
#define CSL_GIC400_GICV_APR0_AP16_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP16_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP17_MASK                          (0x00020000U)
#define CSL_GIC400_GICV_APR0_AP17_SHIFT                         (0x00000011U)
#define CSL_GIC400_GICV_APR0_AP17_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP17_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP18_MASK                          (0x00040000U)
#define CSL_GIC400_GICV_APR0_AP18_SHIFT                         (0x00000012U)
#define CSL_GIC400_GICV_APR0_AP18_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP18_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP19_MASK                          (0x00080000U)
#define CSL_GIC400_GICV_APR0_AP19_SHIFT                         (0x00000013U)
#define CSL_GIC400_GICV_APR0_AP19_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP19_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP20_MASK                          (0x00100000U)
#define CSL_GIC400_GICV_APR0_AP20_SHIFT                         (0x00000014U)
#define CSL_GIC400_GICV_APR0_AP20_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP20_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP21_MASK                          (0x00200000U)
#define CSL_GIC400_GICV_APR0_AP21_SHIFT                         (0x00000015U)
#define CSL_GIC400_GICV_APR0_AP21_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP21_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP22_MASK                          (0x00400000U)
#define CSL_GIC400_GICV_APR0_AP22_SHIFT                         (0x00000016U)
#define CSL_GIC400_GICV_APR0_AP22_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP22_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP23_MASK                          (0x00800000U)
#define CSL_GIC400_GICV_APR0_AP23_SHIFT                         (0x00000017U)
#define CSL_GIC400_GICV_APR0_AP23_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP23_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP24_MASK                          (0x01000000U)
#define CSL_GIC400_GICV_APR0_AP24_SHIFT                         (0x00000018U)
#define CSL_GIC400_GICV_APR0_AP24_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP24_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP25_MASK                          (0x02000000U)
#define CSL_GIC400_GICV_APR0_AP25_SHIFT                         (0x00000019U)
#define CSL_GIC400_GICV_APR0_AP25_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP25_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP26_MASK                          (0x04000000U)
#define CSL_GIC400_GICV_APR0_AP26_SHIFT                         (0x0000001AU)
#define CSL_GIC400_GICV_APR0_AP26_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP26_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP27_MASK                          (0x08000000U)
#define CSL_GIC400_GICV_APR0_AP27_SHIFT                         (0x0000001BU)
#define CSL_GIC400_GICV_APR0_AP27_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP27_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP28_MASK                          (0x10000000U)
#define CSL_GIC400_GICV_APR0_AP28_SHIFT                         (0x0000001CU)
#define CSL_GIC400_GICV_APR0_AP28_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP28_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP29_MASK                          (0x20000000U)
#define CSL_GIC400_GICV_APR0_AP29_SHIFT                         (0x0000001DU)
#define CSL_GIC400_GICV_APR0_AP29_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP29_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP30_MASK                          (0x40000000U)
#define CSL_GIC400_GICV_APR0_AP30_SHIFT                         (0x0000001EU)
#define CSL_GIC400_GICV_APR0_AP30_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP30_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_AP31_MASK                          (0x80000000U)
#define CSL_GIC400_GICV_APR0_AP31_SHIFT                         (0x0000001FU)
#define CSL_GIC400_GICV_APR0_AP31_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_APR0_AP31_MAX                           (0x00000001U)

#define CSL_GIC400_GICV_APR0_RESETVAL                           (0x00000000U)

/* GICV_IIDR */

#define CSL_GIC400_GICV_IIDR_IMPLEMENTER_MASK                   (0x00000FFFU)
#define CSL_GIC400_GICV_IIDR_IMPLEMENTER_SHIFT                  (0x00000000U)
#define CSL_GIC400_GICV_IIDR_IMPLEMENTER_RESETVAL               (0x0000043bU)
#define CSL_GIC400_GICV_IIDR_IMPLEMENTER_MAX                    (0x00000fffU)

#define CSL_GIC400_GICV_IIDR_REVISION_MASK                      (0x0000F000U)
#define CSL_GIC400_GICV_IIDR_REVISION_SHIFT                     (0x0000000CU)
#define CSL_GIC400_GICV_IIDR_REVISION_RESETVAL                  (0x00000000U)
#define CSL_GIC400_GICV_IIDR_REVISION_MAX                       (0x0000000fU)

#define CSL_GIC400_GICV_IIDR_ARCHITECTUREVERSION_MASK           (0x000F0000U)
#define CSL_GIC400_GICV_IIDR_ARCHITECTUREVERSION_SHIFT          (0x00000010U)
#define CSL_GIC400_GICV_IIDR_ARCHITECTUREVERSION_RESETVAL       (0x00000002U)
#define CSL_GIC400_GICV_IIDR_ARCHITECTUREVERSION_MAX            (0x0000000fU)

#define CSL_GIC400_GICV_IIDR_PRODUCTID_MASK                     (0xFFF00000U)
#define CSL_GIC400_GICV_IIDR_PRODUCTID_SHIFT                    (0x00000014U)
#define CSL_GIC400_GICV_IIDR_PRODUCTID_RESETVAL                 (0x00000020U)
#define CSL_GIC400_GICV_IIDR_PRODUCTID_MAX                      (0x00000fffU)

#define CSL_GIC400_GICV_IIDR_RESETVAL                           (0x0202043bU)

/* GICV_DIR */

#define CSL_GIC400_GICV_DIR_INTERRUPTID_MASK                    (0x000003FFU)
#define CSL_GIC400_GICV_DIR_INTERRUPTID_SHIFT                   (0x00000000U)
#define CSL_GIC400_GICV_DIR_INTERRUPTID_RESETVAL                (0x00000000U)
#define CSL_GIC400_GICV_DIR_INTERRUPTID_MAX                     (0x000003ffU)

#define CSL_GIC400_GICV_DIR_CPUID_MASK                          (0x00001C00U)
#define CSL_GIC400_GICV_DIR_CPUID_SHIFT                         (0x0000000AU)
#define CSL_GIC400_GICV_DIR_CPUID_RESETVAL                      (0x00000000U)
#define CSL_GIC400_GICV_DIR_CPUID_MAX                           (0x00000007U)

#define CSL_GIC400_GICV_DIR_RESETVAL                            (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif

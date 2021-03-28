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
#ifndef CSLR_ARMGICDISTR_H_
#define CSLR_ARMGICDISTR_H_

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
    volatile Uint32 DCR;
    volatile Uint32 ICTR;
    volatile Uint32 IIDR;
    volatile Uint8  RSVD0[116];
    volatile Uint32 ISR0;
    volatile Uint32 ISR1;
    volatile Uint32 ISR2;
    volatile Uint32 ISR3;
    volatile Uint32 ISR4;
    volatile Uint32 ISR5;
    volatile Uint8  RSVD1[104];
    volatile Uint32 ISER0;
    volatile Uint32 ISER1;
    volatile Uint32 ISER2;
    volatile Uint32 ISER3;
    volatile Uint32 ISER4;
    volatile Uint32 ISER5;
    volatile Uint8  RSVD2[104];
    volatile Uint32 ICER0;
    volatile Uint32 ICER1;
    volatile Uint32 ICER2;
    volatile Uint32 ICER3;
    volatile Uint32 ICER4;
    volatile Uint32 ICER5;
    volatile Uint8  RSVD3[104];
    volatile Uint32 ISPR0;
    volatile Uint32 ISPR1;
    volatile Uint32 ISPR2;
    volatile Uint32 ISPR3;
    volatile Uint32 ISPR4;
    volatile Uint32 ISPR5;
    volatile Uint8  RSVD4[104];
    volatile Uint32 ICPR0;
    volatile Uint32 ICPR1;
    volatile Uint32 ICPR2;
    volatile Uint32 ICPR3;
    volatile Uint32 ICPR4;
    volatile Uint32 ICPR5;
    volatile Uint8  RSVD5[104];
    volatile Uint32 ISACTIVER0;
    volatile Uint32 ISACTIVER1;
    volatile Uint32 ISACTIVER2;
    volatile Uint32 ISACTIVER3;
    volatile Uint32 ISACTIVER4;
    volatile Uint32 ISACTIVER5;
    volatile Uint8  RSVD6[104];
    volatile Uint32 ICACTIVER0;
    volatile Uint32 ICACTIVER1;
    volatile Uint32 ICACTIVER2;
    volatile Uint32 ICACTIVER3;
    volatile Uint32 ICACTIVER4;
    volatile Uint32 ICACTIVER5;
    volatile Uint8  RSVD7[104];
    volatile Uint32 IPR0;
    volatile Uint32 IPR1;
    volatile Uint32 IPR2;
    volatile Uint32 IPR3;
    volatile Uint32 IPR4;
    volatile Uint32 IPR5;
    volatile Uint32 IPR6;
    volatile Uint32 IPR7;
    volatile Uint32 IPR8;
    volatile Uint32 IPR9;
    volatile Uint32 IPR10;
    volatile Uint32 IPR11;
    volatile Uint32 IPR12;
    volatile Uint32 IPR13;
    volatile Uint32 IPR14;
    volatile Uint32 IPR15;
    volatile Uint32 IPR16;
    volatile Uint32 IPR17;
    volatile Uint32 IPR18;
    volatile Uint32 IPR19;
    volatile Uint32 IPR20;
    volatile Uint32 IPR21;
    volatile Uint32 IPR22;
    volatile Uint32 IPR23;
    volatile Uint32 IPR24;
    volatile Uint32 IPR25;
    volatile Uint32 IPR26;
    volatile Uint32 IPR27;
    volatile Uint32 IPR28;
    volatile Uint32 IPR29;
    volatile Uint32 IPR30;
    volatile Uint32 IPR31;
    volatile Uint32 IPR32;
    volatile Uint32 IPR33;
    volatile Uint32 IPR34;
    volatile Uint32 IPR35;
    volatile Uint32 IPR36;
    volatile Uint32 IPR37;
    volatile Uint32 IPR38;
    volatile Uint32 IPR39;
    volatile Uint32 IPR40;
    volatile Uint32 IPR41;
    volatile Uint32 IPR42;
    volatile Uint32 IPR43;
    volatile Uint32 IPR44;
    volatile Uint32 IPR45;
    volatile Uint32 IPR46;
    volatile Uint32 IPR47;
    volatile Uint8  RSVD8[832];
    volatile Uint32 IPTR0;
    volatile Uint32 IPTR1;
    volatile Uint32 IPTR2;
    volatile Uint32 IPTR3;
    volatile Uint32 IPTR4;
    volatile Uint32 IPTR5;
    volatile Uint32 IPTR6;
    volatile Uint32 IPTR7;
    volatile Uint32 IPTR8;
    volatile Uint32 IPTR9;
    volatile Uint32 IPTR10;
    volatile Uint32 IPTR11;
    volatile Uint32 IPTR12;
    volatile Uint32 IPTR13;
    volatile Uint32 IPTR14;
    volatile Uint32 IPTR15;
    volatile Uint32 IPTR16;
    volatile Uint32 IPTR17;
    volatile Uint32 IPTR18;
    volatile Uint32 IPTR19;
    volatile Uint32 IPTR20;
    volatile Uint32 IPTR21;
    volatile Uint32 IPTR22;
    volatile Uint32 IPTR23;
    volatile Uint32 IPTR24;
    volatile Uint32 IPTR25;
    volatile Uint32 IPTR26;
    volatile Uint32 IPTR27;
    volatile Uint32 IPTR28;
    volatile Uint32 IPTR29;
    volatile Uint32 IPTR30;
    volatile Uint32 IPTR31;
    volatile Uint32 IPTR32;
    volatile Uint32 IPTR33;
    volatile Uint32 IPTR34;
    volatile Uint32 IPTR35;
    volatile Uint32 IPTR36;
    volatile Uint32 IPTR37;
    volatile Uint32 IPTR38;
    volatile Uint32 IPTR39;
    volatile Uint32 IPTR40;
    volatile Uint32 IPTR41;
    volatile Uint32 IPTR42;
    volatile Uint32 IPTR43;
    volatile Uint32 IPTR44;
    volatile Uint32 IPTR45;
    volatile Uint32 IPTR46;
    volatile Uint32 IPTR47;
    volatile Uint8  RSVD9[832];
    volatile Uint32 ICFR0;
    volatile Uint32 ICFR1;
    volatile Uint32 ICFR2;
    volatile Uint32 ICFR3;
    volatile Uint32 ICFR4;
    volatile Uint32 ICFR5;
    volatile Uint32 ICFR6;
    volatile Uint32 ICFR7;
    volatile Uint32 ICFR8;
    volatile Uint32 ICFR9;
    volatile Uint32 ICFR10;
    volatile Uint32 ICFR11;
    volatile Uint8  RSVD10[208];
    volatile Uint32 PPISR;
    volatile Uint32 SPISR0;
    volatile Uint32 SPISR1;
    volatile Uint32 SPISR2;
    volatile Uint32 SPISR3;
    volatile Uint32 SPISR4;
    volatile Uint8  RSVD11[488];
    volatile Uint32 SGIR;
    volatile Uint8  RSVD12[12];
    volatile Uint32 CPENDSGIR0;
    volatile Uint32 CPENDSGIR1;
    volatile Uint32 CPENDSGIR2;
    volatile Uint32 CPENDSGIR3;
    volatile Uint32 SPENDSGIR0;
    volatile Uint32 SPENDSGIR1;
    volatile Uint32 SPENDSGIR2;
    volatile Uint32 SPENDSGIR3;
    volatile Uint8  RSVD13[160];
    volatile Uint32 PIDR4;
    volatile Uint32 PIDR5;
    volatile Uint32 PIDR6;
    volatile Uint32 PIDR7;
    volatile Uint32 PIDR0;
    volatile Uint32 PIDR1;
    volatile Uint32 PIDR2;
    volatile Uint32 PIDR3;
    volatile Uint32 CIDR0;
    volatile Uint32 CIDR1;
    volatile Uint32 CIDR2;
    volatile Uint32 CIDR3;
} CSL_ArmGicDistrRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Distributor Control Register */
#define CSL_ARMGICDISTR_DCR                                     (0x0U)

/* Interrupt Controller Type Register */
#define CSL_ARMGICDISTR_ICTR                                    (0x4U)

/* Distributor Implementer Identification Register */
#define CSL_ARMGICDISTR_IIDR                                    (0x8U)

/* Interrupt Security Registers */
#define CSL_ARMGICDISTR_ISR0                                    (0x80U)

/* Interrupt Security Registers */
#define CSL_ARMGICDISTR_ISR1                                    (0x84U)

/* Interrupt Security Registers */
#define CSL_ARMGICDISTR_ISR2                                    (0x88U)

/* Interrupt Security Registers */
#define CSL_ARMGICDISTR_ISR3                                    (0x8CU)

/* Interrupt Security Registers */
#define CSL_ARMGICDISTR_ISR4                                    (0x90U)

/* Interrupt Security Registers */
#define CSL_ARMGICDISTR_ISR5                                    (0x94U)

/* Interrupt Set-Enable Registers */
#define CSL_ARMGICDISTR_ISER0                                   (0x100U)

/* Interrupt Set-Enable Registers */
#define CSL_ARMGICDISTR_ISER1                                   (0x104U)

/* Interrupt Set-Enable Registers */
#define CSL_ARMGICDISTR_ISER2                                   (0x108U)

/* Interrupt Set-Enable Registers */
#define CSL_ARMGICDISTR_ISER3                                   (0x10CU)

/* Interrupt Set-Enable Registers */
#define CSL_ARMGICDISTR_ISER4                                   (0x110U)

/* Interrupt Set-Enable Registers */
#define CSL_ARMGICDISTR_ISER5                                   (0x114U)

/* Interrupt Clear-Enable Registers */
#define CSL_ARMGICDISTR_ICER0                                   (0x180U)

/* Interrupt Clear-Enable Registers */
#define CSL_ARMGICDISTR_ICER1                                   (0x184U)

/* Interrupt Clear-Enable Registers */
#define CSL_ARMGICDISTR_ICER2                                   (0x188U)

/* Interrupt Clear-Enable Registers */
#define CSL_ARMGICDISTR_ICER3                                   (0x18CU)

/* Interrupt Clear-Enable Registers */
#define CSL_ARMGICDISTR_ICER4                                   (0x190U)

/* Interrupt Clear-Enable Registers */
#define CSL_ARMGICDISTR_ICER5                                   (0x194U)

/* Interrupt Set-Pending Registers */
#define CSL_ARMGICDISTR_ISPR0                                   (0x200U)

/* Interrupt Set-Pending Registers */
#define CSL_ARMGICDISTR_ISPR1                                   (0x204U)

/* Interrupt Set-Pending Registers */
#define CSL_ARMGICDISTR_ISPR2                                   (0x208U)

/* Interrupt Set-Pending Registers */
#define CSL_ARMGICDISTR_ISPR3                                   (0x20CU)

/* Interrupt Set-Pending Registers */
#define CSL_ARMGICDISTR_ISPR4                                   (0x210U)

/* Interrupt Set-Pending Registers */
#define CSL_ARMGICDISTR_ISPR5                                   (0x214U)

/* Interrupt Clear-Pending Registers */
#define CSL_ARMGICDISTR_ICPR0                                   (0x280U)

/* Interrupt Clear-Pending Registers */
#define CSL_ARMGICDISTR_ICPR1                                   (0x284U)

/* Interrupt Clear-Pending Registers */
#define CSL_ARMGICDISTR_ICPR2                                   (0x288U)

/* Interrupt Clear-Pending Registers */
#define CSL_ARMGICDISTR_ICPR3                                   (0x28CU)

/* Interrupt Clear-Pending Registers */
#define CSL_ARMGICDISTR_ICPR4                                   (0x290U)

/* Interrupt Clear-Pending Registers */
#define CSL_ARMGICDISTR_ICPR5                                   (0x294U)

/* Interrupt Set-Active Registers */
#define CSL_ARMGICDISTR_ISACTIVER0                              (0x300U)

/* Interrupt Set-Active Registers */
#define CSL_ARMGICDISTR_ISACTIVER1                              (0x304U)

/* Interrupt Set-Active Registers */
#define CSL_ARMGICDISTR_ISACTIVER2                              (0x308U)

/* Interrupt Set-Active Registers */
#define CSL_ARMGICDISTR_ISACTIVER3                              (0x30CU)

/* Interrupt Set-Active Registers */
#define CSL_ARMGICDISTR_ISACTIVER4                              (0x310U)

/* Interrupt Set-Active Registers */
#define CSL_ARMGICDISTR_ISACTIVER5                              (0x314U)

/* Interrupt Clear-Active Registers */
#define CSL_ARMGICDISTR_ICACTIVER0                              (0x380U)

/* Interrupt Clear-Active Registers */
#define CSL_ARMGICDISTR_ICACTIVER1                              (0x384U)

/* Interrupt Clear-Active Registers */
#define CSL_ARMGICDISTR_ICACTIVER2                              (0x388U)

/* Interrupt Clear-Active Registers */
#define CSL_ARMGICDISTR_ICACTIVER3                              (0x38CU)

/* Interrupt Clear-Active Registers */
#define CSL_ARMGICDISTR_ICACTIVER4                              (0x390U)

/* Interrupt Clear-Active Registers */
#define CSL_ARMGICDISTR_ICACTIVER5                              (0x394U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR0                                    (0x400U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR1                                    (0x404U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR2                                    (0x408U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR3                                    (0x40CU)

/* IPR4 */
#define CSL_ARMGICDISTR_IPR4                                    (0x410U)

/* IPR5 */
#define CSL_ARMGICDISTR_IPR5                                    (0x414U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR6                                    (0x418U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR7                                    (0x41CU)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR8                                    (0x420U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR9                                    (0x424U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR10                                   (0x428U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR11                                   (0x42CU)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR12                                   (0x430U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR13                                   (0x434U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR14                                   (0x438U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR15                                   (0x43CU)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR16                                   (0x440U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR17                                   (0x444U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR18                                   (0x448U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR19                                   (0x44CU)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR20                                   (0x450U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR21                                   (0x454U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR22                                   (0x458U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR23                                   (0x45CU)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR24                                   (0x460U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR25                                   (0x464U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR26                                   (0x468U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR27                                   (0x46CU)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR28                                   (0x470U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR29                                   (0x474U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR30                                   (0x478U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR31                                   (0x47CU)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR32                                   (0x480U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR33                                   (0x484U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR34                                   (0x488U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR35                                   (0x48CU)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR36                                   (0x490U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR37                                   (0x494U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR38                                   (0x498U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR39                                   (0x49CU)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR40                                   (0x4A0U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR41                                   (0x4A4U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR42                                   (0x4A8U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR43                                   (0x4ACU)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR44                                   (0x4B0U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR45                                   (0x4B4U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR46                                   (0x4B8U)

/* Interrupt Priority Registers */
#define CSL_ARMGICDISTR_IPR47                                   (0x4BCU)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR0                                   (0x800U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR1                                   (0x804U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR2                                   (0x808U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR3                                   (0x80CU)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR4                                   (0x810U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR5                                   (0x814U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR6                                   (0x818U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR7                                   (0x81CU)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR8                                   (0x820U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR9                                   (0x824U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR10                                  (0x828U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR11                                  (0x82CU)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR12                                  (0x830U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR13                                  (0x834U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR14                                  (0x838U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR15                                  (0x83CU)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR16                                  (0x840U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR17                                  (0x844U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR18                                  (0x848U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR19                                  (0x84CU)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR20                                  (0x850U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR21                                  (0x854U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR22                                  (0x858U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR23                                  (0x85CU)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR24                                  (0x860U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR25                                  (0x864U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR26                                  (0x868U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR27                                  (0x86CU)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR28                                  (0x870U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR29                                  (0x874U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR30                                  (0x878U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR31                                  (0x87CU)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR32                                  (0x880U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR33                                  (0x884U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR34                                  (0x888U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR35                                  (0x88CU)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR36                                  (0x890U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR37                                  (0x894U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR38                                  (0x898U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR39                                  (0x89CU)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR40                                  (0x8A0U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR41                                  (0x8A4U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR42                                  (0x8A8U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR43                                  (0x8ACU)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR44                                  (0x8B0U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR45                                  (0x8B4U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR46                                  (0x8B8U)

/* Interrupt Processor Targets Registers */
#define CSL_ARMGICDISTR_IPTR47                                  (0x8BCU)

/* Interrupt Configuration Register For Int_config[1], the most significant 
 * bit, bit [2F+1], the encoding is: 0 Corresponding interrupt is 
 * level-sensitive. 1 Corresponding interupt is edge-triggered. Int_config[0], 
 * the least significant bit, bit [2F], is Reserved For SGIs: Int_config[1] 
 * Not programmable,RAO/WI If the bit corresponds to a Secure interrupt, it is 
 * RAZ/WI to Non-secure accesses. This is the usual behavior of bits that 
 * correspond to Secure interrupts */
#define CSL_ARMGICDISTR_ICFR0                                   (0xC00U)

/* Interrupt Configuration Register For Int_config[1], the most significant 
 * bit, bit [2F+1], the encoding is: 0 Corresponding interrupt is 
 * level-sensitive. 1 Corresponding interupt is edge-triggered. Int_config[0], 
 * the least significant bit, bit [2F], is Reserved Int_config[1] For PPIs it 
 * is IMPLEMENTATION DEFINED whether this bit is programmable. A read of this 
 * bit always returns the correct value to indicate whether the corresponding 
 * interrupt is level-sensitive or edge-triggered. */
#define CSL_ARMGICDISTR_ICFR1                                   (0xC04U)

/* Interrupt Configuration Register For Int_config[1], the most significant 
 * bit, bit [2F+1], the encoding is: 0 Corresponding interrupt is 
 * level-sensitive. 1 Corresponding interupt is edge-triggered. Int_config[0], 
 * the least significant bit, bit [2F], is Reserved Int_config[1] For SPIs 
 * this bit is programmable. A read of this bit always returns the correct 
 * value to indicate whether the corresponding interrupt is level-sensitive or 
 * edge-triggered. */
#define CSL_ARMGICDISTR_ICFR2                                   (0xC08U)

/* Interrupt Configuration Register For Int_config[1], the most significant 
 * bit, bit [2F+1], the encoding is: 0 Corresponding interrupt is 
 * level-sensitive. 1 Corresponding interupt is edge-triggered. Int_config[0], 
 * the least significant bit, bit [2F], is Reserved Int_config[1] For SPIs 
 * this bit is programmable. A read of this bit always returns the correct 
 * value to indicate whether the corresponding interrupt is level-sensitive or 
 * edge-triggered. */
#define CSL_ARMGICDISTR_ICFR3                                   (0xC0CU)

/* Interrupt Configuration Register For Int_config[1], the most significant 
 * bit, bit [2F+1], the encoding is: 0 Corresponding interrupt is 
 * level-sensitive. 1 Corresponding interupt is edge-triggered. Int_config[0], 
 * the least significant bit, bit [2F], is Reserved Int_config[1] For SPIs 
 * this bit is programmable. A read of this bit always returns the correct 
 * value to indicate whether the corresponding interrupt is level-sensitive or 
 * edge-triggered. */
#define CSL_ARMGICDISTR_ICFR4                                   (0xC10U)

/* Interrupt Configuration Register For Int_config[1], the most significant 
 * bit, bit [2F+1], the encoding is: 0 Corresponding interrupt is 
 * level-sensitive. 1 Corresponding interupt is edge-triggered. Int_config[0], 
 * the least significant bit, bit [2F], is Reserved Int_config[1] For SPIs 
 * this bit is programmable. A read of this bit always returns the correct 
 * value to indicate whether the corresponding interrupt is level-sensitive or 
 * edge-triggered. */
#define CSL_ARMGICDISTR_ICFR5                                   (0xC14U)

/* Interrupt Configuration Register For Int_config[1], the most significant 
 * bit, bit [2F+1], the encoding is: 0 Corresponding interrupt is 
 * level-sensitive. 1 Corresponding interupt is edge-triggered. Int_config[0], 
 * the least significant bit, bit [2F], is Reserved Int_config[1] For SPIs 
 * this bit is programmable. A read of this bit always returns the correct 
 * value to indicate whether the corresponding interrupt is level-sensitive or 
 * edge-triggered. */
#define CSL_ARMGICDISTR_ICFR6                                   (0xC18U)

/* Interrupt Configuration Register For Int_config[1], the most significant 
 * bit, bit [2F+1], the encoding is: 0 Corresponding interrupt is 
 * level-sensitive. 1 Corresponding interupt is edge-triggered. Int_config[0], 
 * the least significant bit, bit [2F], is Reserved Int_config[1] For SPIs 
 * this bit is programmable. A read of this bit always returns the correct 
 * value to indicate whether the corresponding interrupt is level-sensitive or 
 * edge-triggered. */
#define CSL_ARMGICDISTR_ICFR7                                   (0xC1CU)

/* Interrupt Configuration Register For Int_config[1], the most significant 
 * bit, bit [2F+1], the encoding is: 0 Corresponding interrupt is 
 * level-sensitive. 1 Corresponding interupt is edge-triggered. Int_config[0], 
 * the least significant bit, bit [2F], is Reserved Int_config[1] For SPIs 
 * this bit is programmable. A read of this bit always returns the correct 
 * value to indicate whether the corresponding interrupt is level-sensitive or 
 * edge-triggered. */
#define CSL_ARMGICDISTR_ICFR8                                   (0xC20U)

/* Interrupt Configuration Register For Int_config[1], the most significant 
 * bit, bit [2F+1], the encoding is: 0 Corresponding interrupt is 
 * level-sensitive. 1 Corresponding interupt is edge-triggered. Int_config[0], 
 * the least significant bit, bit [2F], is Reserved Int_config[1] For SPIs 
 * this bit is programmable. A read of this bit always returns the correct 
 * value to indicate whether the corresponding interrupt is level-sensitive or 
 * edge-triggered. */
#define CSL_ARMGICDISTR_ICFR9                                   (0xC24U)

/* Interrupt Configuration Register For Int_config[1], the most significant 
 * bit, bit [2F+1], the encoding is: 0 Corresponding interrupt is 
 * level-sensitive. 1 Corresponding interupt is edge-triggered. Int_config[0], 
 * the least significant bit, bit [2F], is Reserved Int_config[1] For SPIs 
 * this bit is programmable. A read of this bit always returns the correct 
 * value to indicate whether the corresponding interrupt is level-sensitive or 
 * edge-triggered. */
#define CSL_ARMGICDISTR_ICFR10                                  (0xC28U)

/* Interrupt Configuration Register For Int_config[1], the most significant 
 * bit, bit [2F+1], the encoding is: 0 Corresponding interrupt is 
 * level-sensitive. 1 Corresponding interupt is edge-triggered. Int_config[0], 
 * the least significant bit, bit [2F], is Reserved Int_config[1] For SPIs 
 * this bit is programmable. A read of this bit always returns the correct 
 * value to indicate whether the corresponding interrupt is level-sensitive or 
 * edge-triggered. */
#define CSL_ARMGICDISTR_ICFR11                                  (0xC2CU)

/* Private Peripheral Interrupt Status Register PPI0-5 are active-LOW 
 * level-sensitive. PPI6 is active-HIGH level-sensitive. */
#define CSL_ARMGICDISTR_PPISR                                   (0xD00U)

/* Shared Peripheral Interrupt Status Registers 31-0 */
#define CSL_ARMGICDISTR_SPISR0                                  (0xD04U)

/* Shared Peripheral Interrupt Status Registers 63-32 */
#define CSL_ARMGICDISTR_SPISR1                                  (0xD08U)

/* Shared Peripheral Interrupt Status Registers 95-64 */
#define CSL_ARMGICDISTR_SPISR2                                  (0xD0CU)

/* Shared Peripheral Interrupt Status Registers 127-96 */
#define CSL_ARMGICDISTR_SPISR3                                  (0xD10U)

/* Shared Peripheral Interrupt Status Registers 159-128 */
#define CSL_ARMGICDISTR_SPISR4                                  (0xD14U)

/* Software Generated Interrupt Register */
#define CSL_ARMGICDISTR_SGIR                                    (0xF00U)

/* SGI Clear-Pending Registers */
#define CSL_ARMGICDISTR_CPENDSGIR0                              (0xF10U)

/* SGI Clear-Pending Registers */
#define CSL_ARMGICDISTR_CPENDSGIR1                              (0xF14U)

/* SGI Clear-Pending Registers */
#define CSL_ARMGICDISTR_CPENDSGIR2                              (0xF18U)

/* SGI Clear-Pending Registers */
#define CSL_ARMGICDISTR_CPENDSGIR3                              (0xF1CU)

/* SGI Set-Pending Registers */
#define CSL_ARMGICDISTR_SPENDSGIR0                              (0xF20U)

/* SGI Set-Pending Registers */
#define CSL_ARMGICDISTR_SPENDSGIR1                              (0xF24U)

/* SGI Set-Pending Registers */
#define CSL_ARMGICDISTR_SPENDSGIR2                              (0xF28U)

/* SGI Set-Pending Registers */
#define CSL_ARMGICDISTR_SPENDSGIR3                              (0xF2CU)

/* Peripheral ID4 Register */
#define CSL_ARMGICDISTR_PIDR4                                   (0xFD0U)

/* PIDR5 */
#define CSL_ARMGICDISTR_PIDR5                                   (0xFD4U)

/* PIDR6 */
#define CSL_ARMGICDISTR_PIDR6                                   (0xFD8U)

/* PIDR7 */
#define CSL_ARMGICDISTR_PIDR7                                   (0xFDCU)

/* PIDR0 */
#define CSL_ARMGICDISTR_PIDR0                                   (0xFE0U)

/* PIDR1 */
#define CSL_ARMGICDISTR_PIDR1                                   (0xFE4U)

/* PIDR2 */
#define CSL_ARMGICDISTR_PIDR2                                   (0xFE8U)

/* PIDR3 */
#define CSL_ARMGICDISTR_PIDR3                                   (0xFECU)

/* Component ID0 Register */
#define CSL_ARMGICDISTR_CIDR0                                   (0xFF0U)

/* CIDR1 */
#define CSL_ARMGICDISTR_CIDR1                                   (0xFF4U)

/* CIDR2 */
#define CSL_ARMGICDISTR_CIDR2                                   (0xFF8U)

/* CIDR3 */
#define CSL_ARMGICDISTR_CIDR3                                   (0xFFCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* DCR */

#define CSL_ARMGICDISTR_DCR_ENS_MASK                            (0x00000001U)
#define CSL_ARMGICDISTR_DCR_ENS_SHIFT                           (0U)
#define CSL_ARMGICDISTR_DCR_ENS_RESETVAL                        (0x00000000U)
#define CSL_ARMGICDISTR_DCR_ENS_MAX                             (0x00000001U)

#define CSL_ARMGICDISTR_DCR_ENNS_MASK                           (0x00000002U)
#define CSL_ARMGICDISTR_DCR_ENNS_SHIFT                          (1U)
#define CSL_ARMGICDISTR_DCR_ENNS_RESETVAL                       (0x00000000U)
#define CSL_ARMGICDISTR_DCR_ENNS_MAX                            (0x00000001U)

#define CSL_ARMGICDISTR_DCR_RESETVAL                            (0x00000000U)

/* ICTR */

#define CSL_ARMGICDISTR_ICTR_ITLINESNUMBER_MASK                 (0x0000001FU)
#define CSL_ARMGICDISTR_ICTR_ITLINESNUMBER_SHIFT                (0U)
#define CSL_ARMGICDISTR_ICTR_ITLINESNUMBER_RESETVAL             (0x00000005U)
#define CSL_ARMGICDISTR_ICTR_ITLINESNUMBER_MAX                  (0x0000001fU)

#define CSL_ARMGICDISTR_ICTR_CPUNUMBER_MASK                     (0x000000E0U)
#define CSL_ARMGICDISTR_ICTR_CPUNUMBER_SHIFT                    (5U)
#define CSL_ARMGICDISTR_ICTR_CPUNUMBER_RESETVAL                 (0x00000001U)
#define CSL_ARMGICDISTR_ICTR_CPUNUMBER_MAX                      (0x00000007U)

#define CSL_ARMGICDISTR_ICTR_SECURITYEXTN_MASK                  (0x00000400U)
#define CSL_ARMGICDISTR_ICTR_SECURITYEXTN_SHIFT                 (10U)
#define CSL_ARMGICDISTR_ICTR_SECURITYEXTN_RESETVAL              (0x00000001U)
#define CSL_ARMGICDISTR_ICTR_SECURITYEXTN_MAX                   (0x00000001U)

#define CSL_ARMGICDISTR_ICTR_LSPI_MASK                          (0x0000F800U)
#define CSL_ARMGICDISTR_ICTR_LSPI_SHIFT                         (11U)
#define CSL_ARMGICDISTR_ICTR_LSPI_RESETVAL                      (0x0000001fU)
#define CSL_ARMGICDISTR_ICTR_LSPI_MAX                           (0x0000001fU)

#define CSL_ARMGICDISTR_ICTR_RESETVAL                           (0x0000fc25U)

/* IIDR */

#define CSL_ARMGICDISTR_IIDR_IMPLEMENTER_MASK                   (0x00000FFFU)
#define CSL_ARMGICDISTR_IIDR_IMPLEMENTER_SHIFT                  (0U)
#define CSL_ARMGICDISTR_IIDR_IMPLEMENTER_RESETVAL               (0x0000043bU)
#define CSL_ARMGICDISTR_IIDR_IMPLEMENTER_MAX                    (0x00000fffU)

#define CSL_ARMGICDISTR_IIDR_REVISION_MASK                      (0x0000F000U)
#define CSL_ARMGICDISTR_IIDR_REVISION_SHIFT                     (12U)
#define CSL_ARMGICDISTR_IIDR_REVISION_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_IIDR_REVISION_MAX                       (0x0000000fU)

#define CSL_ARMGICDISTR_IIDR_VARIANT_MASK                       (0x000F0000U)
#define CSL_ARMGICDISTR_IIDR_VARIANT_SHIFT                      (16U)
#define CSL_ARMGICDISTR_IIDR_VARIANT_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_IIDR_VARIANT_MAX                        (0x0000000fU)

#define CSL_ARMGICDISTR_IIDR_PRODUCTID_MASK                     (0xFF000000U)
#define CSL_ARMGICDISTR_IIDR_PRODUCTID_SHIFT                    (24U)
#define CSL_ARMGICDISTR_IIDR_PRODUCTID_RESETVAL                 (0x00000000U)
#define CSL_ARMGICDISTR_IIDR_PRODUCTID_MAX                      (0x000000ffU)

#define CSL_ARMGICDISTR_IIDR_RESETVAL                           (0x0000043bU)

/* ISR0 */

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_0_MASK            (0x00000001U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_0_SHIFT           (0U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_0_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_0_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_1_MASK            (0x00000002U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_1_SHIFT           (1U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_1_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_1_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_2_MASK            (0x00000004U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_2_SHIFT           (2U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_2_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_2_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_3_MASK            (0x00000008U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_3_SHIFT           (3U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_3_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_3_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_4_MASK            (0x00000010U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_4_SHIFT           (4U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_4_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_4_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_5_MASK            (0x00000020U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_5_SHIFT           (5U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_5_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_5_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_6_MASK            (0x00000040U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_6_SHIFT           (6U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_6_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_6_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_7_MASK            (0x00000080U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_7_SHIFT           (7U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_7_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_7_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_8_MASK            (0x00000100U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_8_SHIFT           (8U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_8_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_8_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_9_MASK            (0x00000200U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_9_SHIFT           (9U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_9_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_9_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_10_MASK           (0x00000400U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_10_SHIFT          (10U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_10_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_10_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_11_MASK           (0x00000800U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_11_SHIFT          (11U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_11_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_11_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_12_MASK           (0x00001000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_12_SHIFT          (12U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_12_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_12_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_13_MASK           (0x00002000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_13_SHIFT          (13U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_13_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_13_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_14_MASK           (0x00004000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_14_SHIFT          (14U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_14_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_14_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_15_MASK           (0x00008000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_15_SHIFT          (15U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_15_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_15_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_27_MASK           (0x08000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_27_SHIFT          (27U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_27_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_27_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_28_MASK           (0x10000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_28_SHIFT          (28U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_28_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_28_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_29_MASK           (0x20000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_29_SHIFT          (29U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_29_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_29_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_30_MASK           (0x40000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_30_SHIFT          (30U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_30_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_30_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_31_MASK           (0x80000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_31_SHIFT          (31U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_31_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_31_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_25_MASK           (0x02000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_25_SHIFT          (25U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_25_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_25_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_26_MASK           (0x04000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_26_SHIFT          (26U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_26_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISR0_SECURITY_STS_FOR_26_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISR0_RESETVAL                           (0x00000000U)

/* ISR1 */

#define CSL_ARMGICDISTR_ISR1_SECURITY_STS_FOR_32_63_MASK        (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISR1_SECURITY_STS_FOR_32_63_SHIFT       (0U)
#define CSL_ARMGICDISTR_ISR1_SECURITY_STS_FOR_32_63_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_ISR1_SECURITY_STS_FOR_32_63_MAX         (0xffffffffU)

#define CSL_ARMGICDISTR_ISR1_RESETVAL                           (0x00000000U)

/* ISR2 */

#define CSL_ARMGICDISTR_ISR2_SECURITY_STS_FOR_64_95_MASK        (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISR2_SECURITY_STS_FOR_64_95_SHIFT       (0U)
#define CSL_ARMGICDISTR_ISR2_SECURITY_STS_FOR_64_95_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_ISR2_SECURITY_STS_FOR_64_95_MAX         (0xffffffffU)

#define CSL_ARMGICDISTR_ISR2_RESETVAL                           (0x00000000U)

/* ISR3 */

#define CSL_ARMGICDISTR_ISR3_SECURITY_STS_FOR_96_127_MASK       (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISR3_SECURITY_STS_FOR_96_127_SHIFT      (0U)
#define CSL_ARMGICDISTR_ISR3_SECURITY_STS_FOR_96_127_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ISR3_SECURITY_STS_FOR_96_127_MAX        (0xffffffffU)

#define CSL_ARMGICDISTR_ISR3_RESETVAL                           (0x00000000U)

/* ISR4 */

#define CSL_ARMGICDISTR_ISR4_SECURITY_STS_FOR_127_159_MASK      (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISR4_SECURITY_STS_FOR_127_159_SHIFT     (0U)
#define CSL_ARMGICDISTR_ISR4_SECURITY_STS_FOR_127_159_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISR4_SECURITY_STS_FOR_127_159_MAX       (0xffffffffU)

#define CSL_ARMGICDISTR_ISR4_RESETVAL                           (0x00000000U)

/* ISR5 */

#define CSL_ARMGICDISTR_ISR5_SECURITY_STS_FOR_160_191_MASK      (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISR5_SECURITY_STS_FOR_160_191_SHIFT     (0U)
#define CSL_ARMGICDISTR_ISR5_SECURITY_STS_FOR_160_191_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISR5_SECURITY_STS_FOR_160_191_MAX       (0xffffffffU)

#define CSL_ARMGICDISTR_ISR5_RESETVAL                           (0x00000000U)

/* ISER0 */

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_0_MASK                 (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_0_SHIFT                (0U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_0_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_0_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_1_MASK                 (0x00000002U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_1_SHIFT                (1U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_1_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_1_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_2_MASK                 (0x00000004U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_2_SHIFT                (2U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_2_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_2_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_3_MASK                 (0x00000008U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_3_SHIFT                (3U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_3_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_3_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_4_MASK                 (0x00000010U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_4_SHIFT                (4U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_4_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_4_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_5_MASK                 (0x00000020U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_5_SHIFT                (5U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_5_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_5_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_6_MASK                 (0x00000040U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_6_SHIFT                (6U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_6_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_6_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_7_MASK                 (0x00000080U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_7_SHIFT                (7U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_7_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_7_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_8_MASK                 (0x00000100U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_8_SHIFT                (8U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_8_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_8_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_9_MASK                 (0x00000200U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_9_SHIFT                (9U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_9_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_9_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_10_MASK                (0x00000400U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_10_SHIFT               (10U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_10_RESETVAL            (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_10_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_11_MASK                (0x00000800U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_11_SHIFT               (11U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_11_RESETVAL            (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_11_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_12_MASK                (0x00001000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_12_SHIFT               (12U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_12_RESETVAL            (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_12_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_13_MASK                (0x00002000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_13_SHIFT               (13U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_13_RESETVAL            (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_13_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_14_MASK                (0x00004000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_14_SHIFT               (14U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_14_RESETVAL            (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_14_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_15_MASK                (0x00008000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_15_SHIFT               (15U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_15_RESETVAL            (0x00000001U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_15_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_27_MASK                (0x08000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_27_SHIFT               (27U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_27_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_27_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_28_MASK                (0x10000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_28_SHIFT               (28U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_28_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_28_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_29_MASK                (0x20000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_29_SHIFT               (29U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_29_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_29_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_30_MASK                (0x40000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_30_SHIFT               (30U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_30_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_30_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_31_MASK                (0x80000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_31_SHIFT               (31U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_31_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_31_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_25_MASK                (0x02000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_25_SHIFT               (25U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_25_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_25_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_26_MASK                (0x04000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_26_SHIFT               (26U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_26_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ISER0_SET_EN_FOR_26_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ISER0_RESETVAL                          (0x0000ffffU)

/* ISER1 */

#define CSL_ARMGICDISTR_ISER1_SET_EN_FOR_63_32_MASK             (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISER1_SET_EN_FOR_63_32_SHIFT            (0U)
#define CSL_ARMGICDISTR_ISER1_SET_EN_FOR_63_32_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ISER1_SET_EN_FOR_63_32_MAX              (0xffffffffU)

#define CSL_ARMGICDISTR_ISER1_RESETVAL                          (0x00000000U)

/* ISER2 */

#define CSL_ARMGICDISTR_ISER2_SET_EN_FOR_95_64_MASK             (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISER2_SET_EN_FOR_95_64_SHIFT            (0U)
#define CSL_ARMGICDISTR_ISER2_SET_EN_FOR_95_64_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ISER2_SET_EN_FOR_95_64_MAX              (0xffffffffU)

#define CSL_ARMGICDISTR_ISER2_RESETVAL                          (0x00000000U)

/* ISER3 */

#define CSL_ARMGICDISTR_ISER3_SET_EN_FOR_127_96_MASK            (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISER3_SET_EN_FOR_127_96_SHIFT           (0U)
#define CSL_ARMGICDISTR_ISER3_SET_EN_FOR_127_96_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISER3_SET_EN_FOR_127_96_MAX             (0xffffffffU)

#define CSL_ARMGICDISTR_ISER3_RESETVAL                          (0x00000000U)

/* ISER4 */

#define CSL_ARMGICDISTR_ISER4_SET_EN_FOR_159_128_MASK           (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISER4_SET_EN_FOR_159_128_SHIFT          (0U)
#define CSL_ARMGICDISTR_ISER4_SET_EN_FOR_159_128_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISER4_SET_EN_FOR_159_128_MAX            (0xffffffffU)

#define CSL_ARMGICDISTR_ISER4_RESETVAL                          (0x00000000U)

/* ISER5 */

#define CSL_ARMGICDISTR_ISER5_SET_EN_FOR_191_160_MASK           (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISER5_SET_EN_FOR_191_160_SHIFT          (0U)
#define CSL_ARMGICDISTR_ISER5_SET_EN_FOR_191_160_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISER5_SET_EN_FOR_191_160_MAX            (0xffffffffU)

#define CSL_ARMGICDISTR_ISER5_RESETVAL                          (0x00000000U)

/* ICER0 */

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_0_MASK                 (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_0_SHIFT                (0U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_0_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_0_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_1_MASK                 (0x00000002U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_1_SHIFT                (1U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_1_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_1_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_2_MASK                 (0x00000004U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_2_SHIFT                (2U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_2_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_2_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_3_MASK                 (0x00000008U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_3_SHIFT                (3U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_3_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_3_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_4_MASK                 (0x00000010U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_4_SHIFT                (4U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_4_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_4_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_5_MASK                 (0x00000020U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_5_SHIFT                (5U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_5_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_5_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_6_MASK                 (0x00000040U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_6_SHIFT                (6U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_6_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_6_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_7_MASK                 (0x00000080U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_7_SHIFT                (7U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_7_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_7_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_8_MASK                 (0x00000100U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_8_SHIFT                (8U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_8_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_8_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_9_MASK                 (0x00000200U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_9_SHIFT                (9U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_9_RESETVAL             (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_9_MAX                  (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_10_MASK                (0x00000400U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_10_SHIFT               (10U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_10_RESETVAL            (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_10_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_11_MASK                (0x00000800U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_11_SHIFT               (11U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_11_RESETVAL            (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_11_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_12_MASK                (0x00001000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_12_SHIFT               (12U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_12_RESETVAL            (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_12_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_13_MASK                (0x00002000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_13_SHIFT               (13U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_13_RESETVAL            (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_13_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_14_MASK                (0x00004000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_14_SHIFT               (14U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_14_RESETVAL            (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_14_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_15_MASK                (0x00008000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_15_SHIFT               (15U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_15_RESETVAL            (0x00000001U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_15_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_27_MASK                (0x08000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_27_SHIFT               (27U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_27_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_27_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_28_MASK                (0x10000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_28_SHIFT               (28U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_28_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_28_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_29_MASK                (0x20000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_29_SHIFT               (29U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_29_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_29_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_30_MASK                (0x40000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_30_SHIFT               (30U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_30_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_30_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_31_MASK                (0x80000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_31_SHIFT               (31U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_31_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_31_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_25_MASK                (0x02000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_25_SHIFT               (25U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_25_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_25_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_26_MASK                (0x04000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_26_SHIFT               (26U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_26_RESETVAL            (0x00000000U)
#define CSL_ARMGICDISTR_ICER0_CLR_EN_FOR_26_MAX                 (0x00000001U)

#define CSL_ARMGICDISTR_ICER0_RESETVAL                          (0x0000ffffU)

/* ICER1 */

#define CSL_ARMGICDISTR_ICER1_CLR_EN_FOR_63_32_MASK             (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICER1_CLR_EN_FOR_63_32_SHIFT            (0U)
#define CSL_ARMGICDISTR_ICER1_CLR_EN_FOR_63_32_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ICER1_CLR_EN_FOR_63_32_MAX              (0xffffffffU)

#define CSL_ARMGICDISTR_ICER1_RESETVAL                          (0x00000000U)

/* ICER2 */

#define CSL_ARMGICDISTR_ICER2_CLR_EN_FOR_95_64_MASK             (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICER2_CLR_EN_FOR_95_64_SHIFT            (0U)
#define CSL_ARMGICDISTR_ICER2_CLR_EN_FOR_95_64_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ICER2_CLR_EN_FOR_95_64_MAX              (0xffffffffU)

#define CSL_ARMGICDISTR_ICER2_RESETVAL                          (0x00000000U)

/* ICER3 */

#define CSL_ARMGICDISTR_ICER3_CLR_EN_FOR_127_96_MASK            (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICER3_CLR_EN_FOR_127_96_SHIFT           (0U)
#define CSL_ARMGICDISTR_ICER3_CLR_EN_FOR_127_96_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICER3_CLR_EN_FOR_127_96_MAX             (0xffffffffU)

#define CSL_ARMGICDISTR_ICER3_RESETVAL                          (0x00000000U)

/* ICER4 */

#define CSL_ARMGICDISTR_ICER4_CLR_EN_FOR_159_128_MASK           (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICER4_CLR_EN_FOR_159_128_SHIFT          (0U)
#define CSL_ARMGICDISTR_ICER4_CLR_EN_FOR_159_128_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ICER4_CLR_EN_FOR_159_128_MAX            (0xffffffffU)

#define CSL_ARMGICDISTR_ICER4_RESETVAL                          (0x00000000U)

/* ICER5 */

#define CSL_ARMGICDISTR_ICER5_CLR_EN_FOR_191_160_MASK           (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICER5_CLR_EN_FOR_191_160_SHIFT          (0U)
#define CSL_ARMGICDISTR_ICER5_CLR_EN_FOR_191_160_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ICER5_CLR_EN_FOR_191_160_MAX            (0xffffffffU)

#define CSL_ARMGICDISTR_ICER5_RESETVAL                          (0x00000000U)

/* ISPR0 */

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_0_MASK            (0x00000001U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_0_SHIFT           (0U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_0_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_0_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_1_MASK            (0x00000002U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_1_SHIFT           (1U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_1_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_1_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_2_MASK            (0x00000004U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_2_SHIFT           (2U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_2_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_2_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_3_MASK            (0x00000008U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_3_SHIFT           (3U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_3_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_3_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_4_MASK            (0x00000010U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_4_SHIFT           (4U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_4_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_4_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_5_MASK            (0x00000020U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_5_SHIFT           (5U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_5_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_5_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_6_MASK            (0x00000040U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_6_SHIFT           (6U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_6_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_6_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_7_MASK            (0x00000080U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_7_SHIFT           (7U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_7_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_7_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_8_MASK            (0x00000100U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_8_SHIFT           (8U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_8_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_8_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_9_MASK            (0x00000200U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_9_SHIFT           (9U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_9_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_9_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_10_MASK           (0x00000400U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_10_SHIFT          (10U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_10_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_10_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_11_MASK           (0x00000800U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_11_SHIFT          (11U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_11_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_11_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_12_MASK           (0x00001000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_12_SHIFT          (12U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_12_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_12_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_13_MASK           (0x00002000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_13_SHIFT          (13U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_13_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_13_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_14_MASK           (0x00004000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_14_SHIFT          (14U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_14_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_14_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_15_MASK           (0x00008000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_15_SHIFT          (15U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_15_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_15_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_27_MASK           (0x08000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_27_SHIFT          (27U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_27_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_27_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_28_MASK           (0x10000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_28_SHIFT          (28U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_28_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_28_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_29_MASK           (0x20000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_29_SHIFT          (29U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_29_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_29_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_30_MASK           (0x40000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_30_SHIFT          (30U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_30_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_30_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_31_MASK           (0x80000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_31_SHIFT          (31U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_31_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_31_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_25_MASK           (0x02000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_25_SHIFT          (25U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_25_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_25_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_26_MASK           (0x04000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_26_SHIFT          (26U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_26_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ISPR0_SET_PENDING_FOR_26_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_ISPR0_RESETVAL                          (0x00000000U)

/* ISPR1 */

#define CSL_ARMGICDISTR_ISPR1_SET_PENDING_FOR_63_32_MASK        (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISPR1_SET_PENDING_FOR_63_32_SHIFT       (0U)
#define CSL_ARMGICDISTR_ISPR1_SET_PENDING_FOR_63_32_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_ISPR1_SET_PENDING_FOR_63_32_MAX         (0xffffffffU)

#define CSL_ARMGICDISTR_ISPR1_RESETVAL                          (0x00000000U)

/* ISPR2 */

#define CSL_ARMGICDISTR_ISPR2_SET_PENDING_FOR_95_64_MASK        (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISPR2_SET_PENDING_FOR_95_64_SHIFT       (0U)
#define CSL_ARMGICDISTR_ISPR2_SET_PENDING_FOR_95_64_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_ISPR2_SET_PENDING_FOR_95_64_MAX         (0xffffffffU)

#define CSL_ARMGICDISTR_ISPR2_RESETVAL                          (0x00000000U)

/* ISPR3 */

#define CSL_ARMGICDISTR_ISPR3_SET_PENDING_FOR_127_96_MASK       (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISPR3_SET_PENDING_FOR_127_96_SHIFT      (0U)
#define CSL_ARMGICDISTR_ISPR3_SET_PENDING_FOR_127_96_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ISPR3_SET_PENDING_FOR_127_96_MAX        (0xffffffffU)

#define CSL_ARMGICDISTR_ISPR3_RESETVAL                          (0x00000000U)

/* ISPR4 */

#define CSL_ARMGICDISTR_ISPR4_SET_PENDING_FOR_159_128_MASK      (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISPR4_SET_PENDING_FOR_159_128_SHIFT     (0U)
#define CSL_ARMGICDISTR_ISPR4_SET_PENDING_FOR_159_128_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISPR4_SET_PENDING_FOR_159_128_MAX       (0xffffffffU)

#define CSL_ARMGICDISTR_ISPR4_RESETVAL                          (0x00000000U)

/* ISPR5 */

#define CSL_ARMGICDISTR_ISPR5_SET_PENDING_FOR_191_160_MASK      (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISPR5_SET_PENDING_FOR_191_160_SHIFT     (0U)
#define CSL_ARMGICDISTR_ISPR5_SET_PENDING_FOR_191_160_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISPR5_SET_PENDING_FOR_191_160_MAX       (0xffffffffU)

#define CSL_ARMGICDISTR_ISPR5_RESETVAL                          (0x00000000U)

/* ICPR0 */

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_0_MASK             (0x00000001U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_0_SHIFT            (0U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_0_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_0_MAX              (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_1_MASK             (0x00000002U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_1_SHIFT            (1U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_1_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_1_MAX              (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_2_MASK             (0x00000004U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_2_SHIFT            (2U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_2_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_2_MAX              (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_3_MASK             (0x00000008U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_3_SHIFT            (3U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_3_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_3_MAX              (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_4_MASK             (0x00000010U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_4_SHIFT            (4U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_4_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_4_MAX              (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_5_MASK             (0x00000020U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_5_SHIFT            (5U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_5_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_5_MAX              (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_6_MASK             (0x00000040U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_6_SHIFT            (6U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_6_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_6_MAX              (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_7_MASK             (0x00000080U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_7_SHIFT            (7U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_7_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_7_MAX              (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_8_MASK             (0x00000100U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_8_SHIFT            (8U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_8_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_8_MAX              (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_9_MASK             (0x00000200U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_9_SHIFT            (9U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_9_RESETVAL         (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_9_MAX              (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_10_MASK            (0x00000400U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_10_SHIFT           (10U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_10_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_10_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_11_MASK            (0x00000800U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_11_SHIFT           (11U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_11_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_11_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_12_MASK            (0x00001000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_12_SHIFT           (12U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_12_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_12_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_13_MASK            (0x00002000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_13_SHIFT           (13U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_13_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_13_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_14_MASK            (0x00004000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_14_SHIFT           (14U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_14_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_14_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_15_MASK            (0x00008000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_15_SHIFT           (15U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_15_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_15_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_27_MASK            (0x08000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_27_SHIFT           (27U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_27_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_27_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_28_MASK            (0x10000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_28_SHIFT           (28U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_28_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_28_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_29_MASK            (0x20000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_29_SHIFT           (29U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_29_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_29_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_30_MASK            (0x40000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_30_SHIFT           (30U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_30_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_30_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_31_MASK            (0x80000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_31_SHIFT           (31U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_31_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_31_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_25_MASK            (0x02000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_25_SHIFT           (25U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_25_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_25_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_26_MASK            (0x04000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_26_SHIFT           (26U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_26_RESETVAL        (0x00000000U)
#define CSL_ARMGICDISTR_ICPR0_CLRPENDING_FOR_26_MAX             (0x00000001U)

#define CSL_ARMGICDISTR_ICPR0_RESETVAL                          (0x00000000U)

/* ICPR1 */

#define CSL_ARMGICDISTR_ICPR1_CLRPENDING_FOR_63_32_MASK         (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICPR1_CLRPENDING_FOR_63_32_SHIFT        (0U)
#define CSL_ARMGICDISTR_ICPR1_CLRPENDING_FOR_63_32_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_ICPR1_CLRPENDING_FOR_63_32_MAX          (0xffffffffU)

#define CSL_ARMGICDISTR_ICPR1_RESETVAL                          (0x00000000U)

/* ICPR2 */

#define CSL_ARMGICDISTR_ICPR2_CLRPENDING_FOR_95_64_MASK         (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICPR2_CLRPENDING_FOR_95_64_SHIFT        (0U)
#define CSL_ARMGICDISTR_ICPR2_CLRPENDING_FOR_95_64_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_ICPR2_CLRPENDING_FOR_95_64_MAX          (0xffffffffU)

#define CSL_ARMGICDISTR_ICPR2_RESETVAL                          (0x00000000U)

/* ICPR3 */

#define CSL_ARMGICDISTR_ICPR3_CLRPENDING_FOR_127_96_MASK        (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICPR3_CLRPENDING_FOR_127_96_SHIFT       (0U)
#define CSL_ARMGICDISTR_ICPR3_CLRPENDING_FOR_127_96_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_ICPR3_CLRPENDING_FOR_127_96_MAX         (0xffffffffU)

#define CSL_ARMGICDISTR_ICPR3_RESETVAL                          (0x00000000U)

/* ICPR4 */

#define CSL_ARMGICDISTR_ICPR4_CLRPENDING_FOR_159_128_MASK       (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICPR4_CLRPENDING_FOR_159_128_SHIFT      (0U)
#define CSL_ARMGICDISTR_ICPR4_CLRPENDING_FOR_159_128_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ICPR4_CLRPENDING_FOR_159_128_MAX        (0xffffffffU)

#define CSL_ARMGICDISTR_ICPR4_RESETVAL                          (0x00000000U)

/* ICPR5 */

#define CSL_ARMGICDISTR_ICPR5_CLRPENDING_FOR_191_160_MASK       (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICPR5_CLRPENDING_FOR_191_160_SHIFT      (0U)
#define CSL_ARMGICDISTR_ICPR5_CLRPENDING_FOR_191_160_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ICPR5_CLRPENDING_FOR_191_160_MAX        (0xffffffffU)

#define CSL_ARMGICDISTR_ICPR5_RESETVAL                          (0x00000000U)

/* ISACTIVER0 */

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_0_MASK       (0x00000001U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_0_SHIFT      (0U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_0_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_0_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_1_MASK       (0x00000002U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_1_SHIFT      (1U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_1_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_1_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_2_MASK       (0x00000004U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_2_SHIFT      (2U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_2_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_2_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_3_MASK       (0x00000008U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_3_SHIFT      (3U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_3_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_3_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_4_MASK       (0x00000010U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_4_SHIFT      (4U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_4_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_4_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_5_MASK       (0x00000020U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_5_SHIFT      (5U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_5_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_5_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_6_MASK       (0x00000040U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_6_SHIFT      (6U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_6_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_6_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_7_MASK       (0x00000080U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_7_SHIFT      (7U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_7_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_7_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_8_MASK       (0x00000100U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_8_SHIFT      (8U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_8_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_8_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_9_MASK       (0x00000200U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_9_SHIFT      (9U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_9_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_9_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_10_MASK      (0x00000400U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_10_SHIFT     (10U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_10_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_10_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_11_MASK      (0x00000800U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_11_SHIFT     (11U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_11_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_11_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_12_MASK      (0x00001000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_12_SHIFT     (12U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_12_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_12_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_13_MASK      (0x00002000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_13_SHIFT     (13U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_13_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_13_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_14_MASK      (0x00004000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_14_SHIFT     (14U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_14_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_14_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_15_MASK      (0x00008000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_15_SHIFT     (15U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_15_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_15_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_27_MASK      (0x08000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_27_SHIFT     (27U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_27_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_27_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_28_MASK      (0x10000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_28_SHIFT     (28U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_28_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_28_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_29_MASK      (0x20000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_29_SHIFT     (29U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_29_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_29_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_30_MASK      (0x40000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_30_SHIFT     (30U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_30_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_30_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_31_MASK      (0x80000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_31_SHIFT     (31U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_31_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_31_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_25_MASK      (0x02000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_25_SHIFT     (25U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_25_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_25_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_26_MASK      (0x04000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_26_SHIFT     (26U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_26_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER0_ACTIVE_BITS_FOR_26_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ISACTIVER0_RESETVAL                     (0x00000000U)

/* ISACTIVER1 */

#define CSL_ARMGICDISTR_ISACTIVER1_ACTIVE_BITS_FOR_63_32_MASK   (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISACTIVER1_ACTIVE_BITS_FOR_63_32_SHIFT  (0U)
#define CSL_ARMGICDISTR_ISACTIVER1_ACTIVE_BITS_FOR_63_32_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER1_ACTIVE_BITS_FOR_63_32_MAX    (0xffffffffU)

#define CSL_ARMGICDISTR_ISACTIVER1_RESETVAL                     (0x00000000U)

/* ISACTIVER2 */

#define CSL_ARMGICDISTR_ISACTIVER2_ACTIVE_BITS_FOR_95_64_MASK   (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISACTIVER2_ACTIVE_BITS_FOR_95_64_SHIFT  (0U)
#define CSL_ARMGICDISTR_ISACTIVER2_ACTIVE_BITS_FOR_95_64_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER2_ACTIVE_BITS_FOR_95_64_MAX    (0xffffffffU)

#define CSL_ARMGICDISTR_ISACTIVER2_RESETVAL                     (0x00000000U)

/* ISACTIVER3 */

#define CSL_ARMGICDISTR_ISACTIVER3_ACTIVE_BITS_FOR_127_96_MASK  (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISACTIVER3_ACTIVE_BITS_FOR_127_96_SHIFT  (0U)
#define CSL_ARMGICDISTR_ISACTIVER3_ACTIVE_BITS_FOR_127_96_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER3_ACTIVE_BITS_FOR_127_96_MAX   (0xffffffffU)

#define CSL_ARMGICDISTR_ISACTIVER3_RESETVAL                     (0x00000000U)

/* ISACTIVER4 */

#define CSL_ARMGICDISTR_ISACTIVER4_ACTIVE_BITS_FOR_159_128_MASK  (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISACTIVER4_ACTIVE_BITS_FOR_159_128_SHIFT  (0U)
#define CSL_ARMGICDISTR_ISACTIVER4_ACTIVE_BITS_FOR_159_128_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER4_ACTIVE_BITS_FOR_159_128_MAX  (0xffffffffU)

#define CSL_ARMGICDISTR_ISACTIVER4_RESETVAL                     (0x00000000U)

/* ISACTIVER5 */

#define CSL_ARMGICDISTR_ISACTIVER5_ACTIVE_BITS_FOR_191_160_MASK  (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ISACTIVER5_ACTIVE_BITS_FOR_191_160_SHIFT  (0U)
#define CSL_ARMGICDISTR_ISACTIVER5_ACTIVE_BITS_FOR_191_160_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ISACTIVER5_ACTIVE_BITS_FOR_191_160_MAX  (0xffffffffU)

#define CSL_ARMGICDISTR_ISACTIVER5_RESETVAL                     (0x00000000U)

/* ICACTIVER0 */

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_0_MASK       (0x00000001U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_0_SHIFT      (0U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_0_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_0_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_1_MASK       (0x00000002U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_1_SHIFT      (1U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_1_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_1_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_2_MASK       (0x00000004U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_2_SHIFT      (2U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_2_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_2_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_3_MASK       (0x00000008U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_3_SHIFT      (3U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_3_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_3_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_4_MASK       (0x00000010U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_4_SHIFT      (4U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_4_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_4_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_5_MASK       (0x00000020U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_5_SHIFT      (5U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_5_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_5_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_6_MASK       (0x00000040U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_6_SHIFT      (6U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_6_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_6_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_7_MASK       (0x00000080U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_7_SHIFT      (7U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_7_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_7_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_8_MASK       (0x00000100U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_8_SHIFT      (8U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_8_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_8_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_9_MASK       (0x00000200U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_9_SHIFT      (9U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_9_RESETVAL   (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_9_MAX        (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_10_MASK      (0x00000400U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_10_SHIFT     (10U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_10_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_10_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_11_MASK      (0x00000800U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_11_SHIFT     (11U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_11_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_11_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_12_MASK      (0x00001000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_12_SHIFT     (12U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_12_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_12_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_13_MASK      (0x00002000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_13_SHIFT     (13U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_13_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_13_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_14_MASK      (0x00004000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_14_SHIFT     (14U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_14_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_14_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_15_MASK      (0x00008000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_15_SHIFT     (15U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_15_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_15_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_27_MASK      (0x08000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_27_SHIFT     (27U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_27_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_27_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_28_MASK      (0x10000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_28_SHIFT     (28U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_28_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_28_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_29_MASK      (0x20000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_29_SHIFT     (29U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_29_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_29_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_30_MASK      (0x40000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_30_SHIFT     (30U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_30_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_30_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_31_MASK      (0x80000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_31_SHIFT     (31U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_31_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_31_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_25_MASK      (0x02000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_25_SHIFT     (25U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_25_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_25_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_26_MASK      (0x04000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_26_SHIFT     (26U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_26_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER0_ACTIVE_BITS_FOR_26_MAX       (0x00000001U)

#define CSL_ARMGICDISTR_ICACTIVER0_RESETVAL                     (0x00000000U)

/* ICACTIVER1 */

#define CSL_ARMGICDISTR_ICACTIVER1_ACTIVE_BITS_FOR_63_32_MASK   (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICACTIVER1_ACTIVE_BITS_FOR_63_32_SHIFT  (0U)
#define CSL_ARMGICDISTR_ICACTIVER1_ACTIVE_BITS_FOR_63_32_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER1_ACTIVE_BITS_FOR_63_32_MAX    (0xffffffffU)

#define CSL_ARMGICDISTR_ICACTIVER1_RESETVAL                     (0x00000000U)

/* ICACTIVER2 */

#define CSL_ARMGICDISTR_ICACTIVER2_ACTIVE_BITS_FOR_95_64_MASK   (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICACTIVER2_ACTIVE_BITS_FOR_95_64_SHIFT  (0U)
#define CSL_ARMGICDISTR_ICACTIVER2_ACTIVE_BITS_FOR_95_64_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER2_ACTIVE_BITS_FOR_95_64_MAX    (0xffffffffU)

#define CSL_ARMGICDISTR_ICACTIVER2_RESETVAL                     (0x00000000U)

/* ICACTIVER3 */

#define CSL_ARMGICDISTR_ICACTIVER3_ACTIVE_BITS_FOR_127_96_MASK  (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICACTIVER3_ACTIVE_BITS_FOR_127_96_SHIFT  (0U)
#define CSL_ARMGICDISTR_ICACTIVER3_ACTIVE_BITS_FOR_127_96_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER3_ACTIVE_BITS_FOR_127_96_MAX   (0xffffffffU)

#define CSL_ARMGICDISTR_ICACTIVER3_RESETVAL                     (0x00000000U)

/* ICACTIVER4 */

#define CSL_ARMGICDISTR_ICACTIVER4_ACTIVE_BITS_FOR_159_128_MASK  (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICACTIVER4_ACTIVE_BITS_FOR_159_128_SHIFT  (0U)
#define CSL_ARMGICDISTR_ICACTIVER4_ACTIVE_BITS_FOR_159_128_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER4_ACTIVE_BITS_FOR_159_128_MAX  (0xffffffffU)

#define CSL_ARMGICDISTR_ICACTIVER4_RESETVAL                     (0x00000000U)

/* ICACTIVER5 */

#define CSL_ARMGICDISTR_ICACTIVER5_ACTIVE_BITS_FOR_191_160_MASK  (0xFFFFFFFFU)
#define CSL_ARMGICDISTR_ICACTIVER5_ACTIVE_BITS_FOR_191_160_SHIFT  (0U)
#define CSL_ARMGICDISTR_ICACTIVER5_ACTIVE_BITS_FOR_191_160_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_ICACTIVER5_ACTIVE_BITS_FOR_191_160_MAX  (0xffffffffU)

#define CSL_ARMGICDISTR_ICACTIVER5_RESETVAL                     (0x00000000U)

/* IPR0 */

#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_2_MASK         (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_2_SHIFT        (16U)
#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_2_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_2_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_1_MASK         (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_1_SHIFT        (8U)
#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_1_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_1_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_3_MASK         (0xFF000000U)
#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_3_SHIFT        (24U)
#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_3_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_3_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_0_MASK         (0x000000FFU)
#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_0_SHIFT        (0U)
#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_0_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR0_PRIORITY_BYTEOFFSET_0_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR0_RESETVAL                           (0x00000000U)

/* IPR1 */

#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_2_MASK         (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_2_SHIFT        (16U)
#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_2_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_2_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_1_MASK         (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_1_SHIFT        (8U)
#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_1_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_1_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_3_MASK         (0xFF000000U)
#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_3_SHIFT        (24U)
#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_3_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_3_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_0_MASK         (0x000000FFU)
#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_0_SHIFT        (0U)
#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_0_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR1_PRIORITY_BYTEOFFSET_0_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR1_RESETVAL                           (0x00000000U)

/* IPR2 */

#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_2_MASK         (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_2_SHIFT        (16U)
#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_2_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_2_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_1_MASK         (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_1_SHIFT        (8U)
#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_1_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_1_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_3_MASK         (0xFF000000U)
#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_3_SHIFT        (24U)
#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_3_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_3_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_0_MASK         (0x000000FFU)
#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_0_SHIFT        (0U)
#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_0_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR2_PRIORITY_BYTEOFFSET_0_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR2_RESETVAL                           (0x00000000U)

/* IPR3 */

#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_2_MASK         (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_2_SHIFT        (16U)
#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_2_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_2_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_1_MASK         (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_1_SHIFT        (8U)
#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_1_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_1_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_3_MASK         (0xFF000000U)
#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_3_SHIFT        (24U)
#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_3_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_3_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_0_MASK         (0x000000FFU)
#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_0_SHIFT        (0U)
#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_0_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR3_PRIORITY_BYTEOFFSET_0_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR3_RESETVAL                           (0x00000000U)

/* IPR4 */

#define CSL_ARMGICDISTR_IPR4_RESETVAL                           (0x00000000U)

/* IPR5 */

#define CSL_ARMGICDISTR_IPR5_RESETVAL                           (0x00000000U)

/* IPR6 */

#define CSL_ARMGICDISTR_IPR6_PRIORITY_BYTEOFFSET_3_MASK         (0xFF000000U)
#define CSL_ARMGICDISTR_IPR6_PRIORITY_BYTEOFFSET_3_SHIFT        (24U)
#define CSL_ARMGICDISTR_IPR6_PRIORITY_BYTEOFFSET_3_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR6_PRIORITY_BYTEOFFSET_3_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR6_PRIORITY_BYTEOFFSET_2_MASK         (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR6_PRIORITY_BYTEOFFSET_2_SHIFT        (16U)
#define CSL_ARMGICDISTR_IPR6_PRIORITY_BYTEOFFSET_2_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR6_PRIORITY_BYTEOFFSET_2_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR6_PRIORITY_BYTEOFFSET_1_MASK         (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR6_PRIORITY_BYTEOFFSET_1_SHIFT        (8U)
#define CSL_ARMGICDISTR_IPR6_PRIORITY_BYTEOFFSET_1_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR6_PRIORITY_BYTEOFFSET_1_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR6_RESETVAL                           (0x00000000U)

/* IPR7 */

#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_2_MASK         (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_2_SHIFT        (16U)
#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_2_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_2_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_1_MASK         (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_1_SHIFT        (8U)
#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_1_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_1_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_3_MASK         (0xFF000000U)
#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_3_SHIFT        (24U)
#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_3_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_3_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_0_MASK         (0x000000FFU)
#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_0_SHIFT        (0U)
#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_0_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR7_PRIORITY_BYTEOFFSET_0_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR7_RESETVAL                           (0x00000000U)

/* IPR8 */

#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_2_MASK         (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_2_SHIFT        (16U)
#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_2_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_2_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_1_MASK         (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_1_SHIFT        (8U)
#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_1_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_1_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_3_MASK         (0xFF000000U)
#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_3_SHIFT        (24U)
#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_3_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_3_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_0_MASK         (0x000000FFU)
#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_0_SHIFT        (0U)
#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_0_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR8_PRIORITY_BYTEOFFSET_0_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR8_RESETVAL                           (0x00000000U)

/* IPR9 */

#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_2_MASK         (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_2_SHIFT        (16U)
#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_2_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_2_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_1_MASK         (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_1_SHIFT        (8U)
#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_1_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_1_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_3_MASK         (0xFF000000U)
#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_3_SHIFT        (24U)
#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_3_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_3_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_0_MASK         (0x000000FFU)
#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_0_SHIFT        (0U)
#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_0_RESETVAL     (0x00000000U)
#define CSL_ARMGICDISTR_IPR9_PRIORITY_BYTEOFFSET_0_MAX          (0x000000ffU)

#define CSL_ARMGICDISTR_IPR9_RESETVAL                           (0x00000000U)

/* IPR10 */

#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR10_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR10_RESETVAL                          (0x00000000U)

/* IPR11 */

#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR11_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR11_RESETVAL                          (0x00000000U)

/* IPR12 */

#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR12_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR12_RESETVAL                          (0x00000000U)

/* IPR13 */

#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR13_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR13_RESETVAL                          (0x00000000U)

/* IPR14 */

#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR14_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR14_RESETVAL                          (0x00000000U)

/* IPR15 */

#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR15_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR15_RESETVAL                          (0x00000000U)

/* IPR16 */

#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR16_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR16_RESETVAL                          (0x00000000U)

/* IPR17 */

#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR17_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR17_RESETVAL                          (0x00000000U)

/* IPR18 */

#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR18_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR18_RESETVAL                          (0x00000000U)

/* IPR19 */

#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR19_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR19_RESETVAL                          (0x00000000U)

/* IPR20 */

#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR20_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR20_RESETVAL                          (0x00000000U)

/* IPR21 */

#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR21_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR21_RESETVAL                          (0x00000000U)

/* IPR22 */

#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR22_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR22_RESETVAL                          (0x00000000U)

/* IPR23 */

#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR23_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR23_RESETVAL                          (0x00000000U)

/* IPR24 */

#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR24_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR24_RESETVAL                          (0x00000000U)

/* IPR25 */

#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR25_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR25_RESETVAL                          (0x00000000U)

/* IPR26 */

#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR26_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR26_RESETVAL                          (0x00000000U)

/* IPR27 */

#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR27_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR27_RESETVAL                          (0x00000000U)

/* IPR28 */

#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR28_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR28_RESETVAL                          (0x00000000U)

/* IPR29 */

#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR29_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR29_RESETVAL                          (0x00000000U)

/* IPR30 */

#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR30_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR30_RESETVAL                          (0x00000000U)

/* IPR31 */

#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR31_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR31_RESETVAL                          (0x00000000U)

/* IPR32 */

#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR32_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR32_RESETVAL                          (0x00000000U)

/* IPR33 */

#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR33_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR33_RESETVAL                          (0x00000000U)

/* IPR34 */

#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR34_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR34_RESETVAL                          (0x00000000U)

/* IPR35 */

#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR35_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR35_RESETVAL                          (0x00000000U)

/* IPR36 */

#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR36_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR36_RESETVAL                          (0x00000000U)

/* IPR37 */

#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR37_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR37_RESETVAL                          (0x00000000U)

/* IPR38 */

#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR38_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR38_RESETVAL                          (0x00000000U)

/* IPR39 */

#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR39_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR39_RESETVAL                          (0x00000000U)

/* IPR40 */

#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR40_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR40_RESETVAL                          (0x00000000U)

/* IPR41 */

#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR41_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR41_RESETVAL                          (0x00000000U)

/* IPR42 */

#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR42_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR42_RESETVAL                          (0x00000000U)

/* IPR43 */

#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR43_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR43_RESETVAL                          (0x00000000U)

/* IPR44 */

#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR44_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR44_RESETVAL                          (0x00000000U)

/* IPR45 */

#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR45_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR45_RESETVAL                          (0x00000000U)

/* IPR46 */

#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR46_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR46_RESETVAL                          (0x00000000U)

/* IPR47 */

#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_2_MASK        (0x00FF0000U)
#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_2_SHIFT       (16U)
#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_2_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_2_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_1_MASK        (0x0000FF00U)
#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_1_SHIFT       (8U)
#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_1_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_1_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_3_MASK        (0xFF000000U)
#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_3_SHIFT       (24U)
#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_3_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_3_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_0_MASK        (0x000000FFU)
#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_0_SHIFT       (0U)
#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_0_RESETVAL    (0x00000000U)
#define CSL_ARMGICDISTR_IPR47_PRIORITY_BYTEOFFSET_0_MAX         (0x000000ffU)

#define CSL_ARMGICDISTR_IPR47_RESETVAL                          (0x00000000U)

/* IPTR0 */

#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_0_MASK      (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_0_SHIFT     (0U)
#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_0_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_1_MASK      (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_1_SHIFT     (8U)
#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_1_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_2_MASK      (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_2_SHIFT     (16U)
#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_2_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_3_MASK      (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_3_SHIFT     (24U)
#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR0_CPUTARGETS_BYTEOFFSET_3_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR0_RESETVAL                          (0x01010101U)

/* IPTR1 */

#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_0_MASK      (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_0_SHIFT     (0U)
#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_0_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_1_MASK      (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_1_SHIFT     (8U)
#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_1_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_2_MASK      (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_2_SHIFT     (16U)
#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_2_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_3_MASK      (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_3_SHIFT     (24U)
#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR1_CPUTARGETS_BYTEOFFSET_3_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR1_RESETVAL                          (0x01010101U)

/* IPTR2 */

#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_0_MASK      (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_0_SHIFT     (0U)
#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_0_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_1_MASK      (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_1_SHIFT     (8U)
#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_1_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_2_MASK      (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_2_SHIFT     (16U)
#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_2_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_3_MASK      (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_3_SHIFT     (24U)
#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR2_CPUTARGETS_BYTEOFFSET_3_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR2_RESETVAL                          (0x01010101U)

/* IPTR3 */

#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_0_MASK      (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_0_SHIFT     (0U)
#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_0_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_1_MASK      (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_1_SHIFT     (8U)
#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_1_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_2_MASK      (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_2_SHIFT     (16U)
#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_2_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_3_MASK      (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_3_SHIFT     (24U)
#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR3_CPUTARGETS_BYTEOFFSET_3_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR3_RESETVAL                          (0x01010101U)

/* IPTR4 */

#define CSL_ARMGICDISTR_IPTR4_RESETVAL                          (0x00000000U)

/* IPTR5 */

#define CSL_ARMGICDISTR_IPTR5_RESETVAL                          (0x00000000U)

/* IPTR6 */

#define CSL_ARMGICDISTR_IPTR6_CPUTARGETS_BYTEOFFSET_3_MASK      (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR6_CPUTARGETS_BYTEOFFSET_3_SHIFT     (24U)
#define CSL_ARMGICDISTR_IPTR6_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR6_CPUTARGETS_BYTEOFFSET_3_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR6_CPUTARGETS_BYTEOFFSET_2_MASK      (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR6_CPUTARGETS_BYTEOFFSET_2_SHIFT     (16U)
#define CSL_ARMGICDISTR_IPTR6_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR6_CPUTARGETS_BYTEOFFSET_2_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR6_CPUTARGETS_BYTEOFFSET_1_MASK      (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR6_CPUTARGETS_BYTEOFFSET_1_SHIFT     (8U)
#define CSL_ARMGICDISTR_IPTR6_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR6_CPUTARGETS_BYTEOFFSET_1_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR6_RESETVAL                          (0x01010100U)

/* IPTR7 */

#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_0_MASK      (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_0_SHIFT     (0U)
#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_0_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_1_MASK      (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_1_SHIFT     (8U)
#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_1_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_2_MASK      (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_2_SHIFT     (16U)
#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_2_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_3_MASK      (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_3_SHIFT     (24U)
#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000001U)
#define CSL_ARMGICDISTR_IPTR7_CPUTARGETS_BYTEOFFSET_3_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR7_RESETVAL                          (0x01010101U)

/* IPTR8 */

#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_0_MASK      (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_0_SHIFT     (0U)
#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_0_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_1_MASK      (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_1_SHIFT     (8U)
#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_1_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_2_MASK      (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_2_SHIFT     (16U)
#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_2_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_3_MASK      (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_3_SHIFT     (24U)
#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR8_CPUTARGETS_BYTEOFFSET_3_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR8_RESETVAL                          (0x00000000U)

/* IPTR9 */

#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_0_MASK      (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_0_SHIFT     (0U)
#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_0_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_1_MASK      (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_1_SHIFT     (8U)
#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_1_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_2_MASK      (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_2_SHIFT     (16U)
#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_2_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_3_MASK      (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_3_SHIFT     (24U)
#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR9_CPUTARGETS_BYTEOFFSET_3_MAX       (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR9_RESETVAL                          (0x00000000U)

/* IPTR10 */

#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR10_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR10_RESETVAL                         (0x00000000U)

/* IPTR11 */

#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR11_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR11_RESETVAL                         (0x00000000U)

/* IPTR12 */

#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR12_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR12_RESETVAL                         (0x00000000U)

/* IPTR13 */

#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR13_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR13_RESETVAL                         (0x00000000U)

/* IPTR14 */

#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR14_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR14_RESETVAL                         (0x00000000U)

/* IPTR15 */

#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR15_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR15_RESETVAL                         (0x00000000U)

/* IPTR16 */

#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR16_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR16_RESETVAL                         (0x00000000U)

/* IPTR17 */

#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR17_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR17_RESETVAL                         (0x00000000U)

/* IPTR18 */

#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR18_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR18_RESETVAL                         (0x00000000U)

/* IPTR19 */

#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR19_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR19_RESETVAL                         (0x00000000U)

/* IPTR20 */

#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR20_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR20_RESETVAL                         (0x00000000U)

/* IPTR21 */

#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR21_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR21_RESETVAL                         (0x00000000U)

/* IPTR22 */

#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR22_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR22_RESETVAL                         (0x00000000U)

/* IPTR23 */

#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR23_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR23_RESETVAL                         (0x00000000U)

/* IPTR24 */

#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR24_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR24_RESETVAL                         (0x00000000U)

/* IPTR25 */

#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR25_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR25_RESETVAL                         (0x00000000U)

/* IPTR26 */

#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR26_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR26_RESETVAL                         (0x00000000U)

/* IPTR27 */

#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR27_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR27_RESETVAL                         (0x00000000U)

/* IPTR28 */

#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR28_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR28_RESETVAL                         (0x00000000U)

/* IPTR29 */

#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR29_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR29_RESETVAL                         (0x00000000U)

/* IPTR30 */

#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR30_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR30_RESETVAL                         (0x00000000U)

/* IPTR31 */

#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR31_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR31_RESETVAL                         (0x00000000U)

/* IPTR32 */

#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR32_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR32_RESETVAL                         (0x00000000U)

/* IPTR33 */

#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR33_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR33_RESETVAL                         (0x00000000U)

/* IPTR34 */

#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR34_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR34_RESETVAL                         (0x00000000U)

/* IPTR35 */

#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR35_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR35_RESETVAL                         (0x00000000U)

/* IPTR36 */

#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR36_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR36_RESETVAL                         (0x00000000U)

/* IPTR37 */

#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR37_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR37_RESETVAL                         (0x00000000U)

/* IPTR38 */

#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR38_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR38_RESETVAL                         (0x00000000U)

/* IPTR39 */

#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR39_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR39_RESETVAL                         (0x00000000U)

/* IPTR40 */

#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR40_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR40_RESETVAL                         (0x00000000U)

/* IPTR41 */

#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR41_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR41_RESETVAL                         (0x00000000U)

/* IPTR42 */

#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR42_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR42_RESETVAL                         (0x00000000U)

/* IPTR43 */

#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR43_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR43_RESETVAL                         (0x00000000U)

/* IPTR44 */

#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR44_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR44_RESETVAL                         (0x00000000U)

/* IPTR45 */

#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR45_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR45_RESETVAL                         (0x00000000U)

/* IPTR46 */

#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR46_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR46_RESETVAL                         (0x00000000U)

/* IPTR47 */

#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_0_MASK     (0x000000FFU)
#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_0_SHIFT    (0U)
#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_0_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_0_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_1_MASK     (0x0000FF00U)
#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_1_SHIFT    (8U)
#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_1_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_1_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_2_MASK     (0x00FF0000U)
#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_2_SHIFT    (16U)
#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_2_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_2_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_3_MASK     (0xFF000000U)
#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_3_SHIFT    (24U)
#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_3_RESETVAL  (0x00000000U)
#define CSL_ARMGICDISTR_IPTR47_CPUTARGETS_BYTEOFFSET_3_MAX      (0x000000ffU)

#define CSL_ARMGICDISTR_IPTR47_RESETVAL                         (0x00000000U)

/* ICFR0 */

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_0_MASK           (0x00000003U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_0_SHIFT          (0U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_0_RESETVAL       (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_0_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_1_MASK           (0x0000000CU)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_1_SHIFT          (2U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_1_RESETVAL       (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_1_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_2_MASK           (0x00000030U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_2_SHIFT          (4U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_2_RESETVAL       (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_2_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_3_MASK           (0x000000C0U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_3_SHIFT          (6U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_3_RESETVAL       (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_3_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_4_MASK           (0x00000300U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_4_SHIFT          (8U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_4_RESETVAL       (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_4_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_5_MASK           (0x00000C00U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_5_SHIFT          (10U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_5_RESETVAL       (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_5_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_6_MASK           (0x00003000U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_6_SHIFT          (12U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_6_RESETVAL       (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_6_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_7_MASK           (0x0000C000U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_7_SHIFT          (14U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_7_RESETVAL       (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_7_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_8_MASK           (0x00030000U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_8_SHIFT          (16U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_8_RESETVAL       (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_8_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_9_MASK           (0x000C0000U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_9_SHIFT          (18U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_9_RESETVAL       (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_9_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_10_MASK          (0x00300000U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_10_SHIFT         (20U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_10_RESETVAL      (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_10_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_11_MASK          (0x00C00000U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_11_SHIFT         (22U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_11_RESETVAL      (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_11_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_12_MASK          (0x03000000U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_12_SHIFT         (24U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_12_RESETVAL      (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_12_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_13_MASK          (0x0C000000U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_13_SHIFT         (26U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_13_RESETVAL      (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_13_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_14_MASK          (0x30000000U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_14_SHIFT         (28U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_14_RESETVAL      (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_14_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_15_MASK          (0xC0000000U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_15_SHIFT         (30U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_15_RESETVAL      (0x00000002U)
#define CSL_ARMGICDISTR_ICFR0_INT_CONFIG_FIELD_15_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR0_RESETVAL                          (0xaaaaaaaaU)

/* ICFR1 */

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_11_MASK          (0x00C00000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_11_SHIFT         (22U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_11_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_11_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_12_MASK          (0x03000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_12_SHIFT         (24U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_12_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_12_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_13_MASK          (0x0C000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_13_SHIFT         (26U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_13_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_13_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_14_MASK          (0x30000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_14_SHIFT         (28U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_14_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_14_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_15_MASK          (0xC0000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_15_SHIFT         (30U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_15_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_15_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_10_MASK          (0x00300000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_10_SHIFT         (20U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_10_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_10_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_9_MASK           (0x000C0000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_9_SHIFT          (18U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_9_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_9_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_0_MASK           (0x00000003U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_0_SHIFT          (0U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_0_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_0_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_1_MASK           (0x0000000CU)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_1_SHIFT          (2U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_1_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_1_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_2_MASK           (0x00000030U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_2_SHIFT          (4U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_2_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_2_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_3_MASK           (0x000000C0U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_3_SHIFT          (6U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_3_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_3_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_4_MASK           (0x00000300U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_4_SHIFT          (8U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_4_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_4_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_5_MASK           (0x00000C00U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_5_SHIFT          (10U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_5_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_5_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_6_MASK           (0x00003000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_6_SHIFT          (12U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_6_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_6_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_7_MASK           (0x0000C000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_7_SHIFT          (14U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_7_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_7_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_8_MASK           (0x00030000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_8_SHIFT          (16U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_8_RESETVAL       (0x00000000U)
#define CSL_ARMGICDISTR_ICFR1_INT_CONFIG_FIELD_8_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR1_RESETVAL                          (0x55540000U)

/* ICFR2 */

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_0_MASK           (0x00000003U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_0_SHIFT          (0U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_0_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_0_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_1_MASK           (0x0000000CU)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_1_SHIFT          (2U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_1_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_1_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_2_MASK           (0x00000030U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_2_SHIFT          (4U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_2_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_2_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_3_MASK           (0x000000C0U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_3_SHIFT          (6U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_3_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_3_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_4_MASK           (0x00000300U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_4_SHIFT          (8U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_4_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_4_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_5_MASK           (0x00000C00U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_5_SHIFT          (10U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_5_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_5_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_6_MASK           (0x00003000U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_6_SHIFT          (12U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_6_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_6_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_7_MASK           (0x0000C000U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_7_SHIFT          (14U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_7_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_7_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_8_MASK           (0x00030000U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_8_SHIFT          (16U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_8_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_8_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_9_MASK           (0x000C0000U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_9_SHIFT          (18U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_9_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_9_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_10_MASK          (0x00300000U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_10_SHIFT         (20U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_10_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_10_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_11_MASK          (0x00C00000U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_11_SHIFT         (22U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_11_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_11_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_12_MASK          (0x03000000U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_12_SHIFT         (24U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_12_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_12_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_13_MASK          (0x0C000000U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_13_SHIFT         (26U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_13_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_13_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_14_MASK          (0x30000000U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_14_SHIFT         (28U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_14_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_14_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_15_MASK          (0xC0000000U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_15_SHIFT         (30U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_15_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR2_INT_CONFIG_FIELD_15_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR2_RESETVAL                          (0x55555555U)

/* ICFR3 */

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_0_MASK           (0x00000003U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_0_SHIFT          (0U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_0_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_0_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_1_MASK           (0x0000000CU)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_1_SHIFT          (2U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_1_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_1_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_2_MASK           (0x00000030U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_2_SHIFT          (4U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_2_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_2_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_3_MASK           (0x000000C0U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_3_SHIFT          (6U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_3_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_3_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_4_MASK           (0x00000300U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_4_SHIFT          (8U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_4_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_4_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_5_MASK           (0x00000C00U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_5_SHIFT          (10U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_5_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_5_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_6_MASK           (0x00003000U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_6_SHIFT          (12U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_6_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_6_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_7_MASK           (0x0000C000U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_7_SHIFT          (14U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_7_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_7_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_8_MASK           (0x00030000U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_8_SHIFT          (16U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_8_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_8_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_9_MASK           (0x000C0000U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_9_SHIFT          (18U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_9_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_9_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_10_MASK          (0x00300000U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_10_SHIFT         (20U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_10_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_10_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_11_MASK          (0x00C00000U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_11_SHIFT         (22U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_11_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_11_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_12_MASK          (0x03000000U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_12_SHIFT         (24U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_12_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_12_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_13_MASK          (0x0C000000U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_13_SHIFT         (26U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_13_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_13_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_14_MASK          (0x30000000U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_14_SHIFT         (28U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_14_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_14_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_15_MASK          (0xC0000000U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_15_SHIFT         (30U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_15_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR3_INT_CONFIG_FIELD_15_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR3_RESETVAL                          (0x55555555U)

/* ICFR4 */

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_0_MASK           (0x00000003U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_0_SHIFT          (0U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_0_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_0_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_1_MASK           (0x0000000CU)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_1_SHIFT          (2U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_1_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_1_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_2_MASK           (0x00000030U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_2_SHIFT          (4U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_2_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_2_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_3_MASK           (0x000000C0U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_3_SHIFT          (6U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_3_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_3_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_4_MASK           (0x00000300U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_4_SHIFT          (8U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_4_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_4_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_5_MASK           (0x00000C00U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_5_SHIFT          (10U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_5_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_5_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_6_MASK           (0x00003000U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_6_SHIFT          (12U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_6_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_6_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_7_MASK           (0x0000C000U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_7_SHIFT          (14U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_7_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_7_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_8_MASK           (0x00030000U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_8_SHIFT          (16U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_8_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_8_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_9_MASK           (0x000C0000U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_9_SHIFT          (18U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_9_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_9_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_10_MASK          (0x00300000U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_10_SHIFT         (20U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_10_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_10_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_11_MASK          (0x00C00000U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_11_SHIFT         (22U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_11_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_11_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_12_MASK          (0x03000000U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_12_SHIFT         (24U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_12_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_12_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_13_MASK          (0x0C000000U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_13_SHIFT         (26U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_13_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_13_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_14_MASK          (0x30000000U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_14_SHIFT         (28U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_14_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_14_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_15_MASK          (0xC0000000U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_15_SHIFT         (30U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_15_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR4_INT_CONFIG_FIELD_15_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR4_RESETVAL                          (0x55555555U)

/* ICFR5 */

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_0_MASK           (0x00000003U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_0_SHIFT          (0U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_0_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_0_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_1_MASK           (0x0000000CU)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_1_SHIFT          (2U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_1_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_1_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_2_MASK           (0x00000030U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_2_SHIFT          (4U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_2_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_2_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_3_MASK           (0x000000C0U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_3_SHIFT          (6U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_3_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_3_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_4_MASK           (0x00000300U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_4_SHIFT          (8U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_4_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_4_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_5_MASK           (0x00000C00U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_5_SHIFT          (10U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_5_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_5_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_6_MASK           (0x00003000U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_6_SHIFT          (12U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_6_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_6_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_7_MASK           (0x0000C000U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_7_SHIFT          (14U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_7_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_7_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_8_MASK           (0x00030000U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_8_SHIFT          (16U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_8_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_8_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_9_MASK           (0x000C0000U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_9_SHIFT          (18U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_9_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_9_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_10_MASK          (0x00300000U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_10_SHIFT         (20U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_10_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_10_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_11_MASK          (0x00C00000U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_11_SHIFT         (22U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_11_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_11_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_12_MASK          (0x03000000U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_12_SHIFT         (24U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_12_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_12_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_13_MASK          (0x0C000000U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_13_SHIFT         (26U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_13_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_13_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_14_MASK          (0x30000000U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_14_SHIFT         (28U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_14_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_14_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_15_MASK          (0xC0000000U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_15_SHIFT         (30U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_15_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR5_INT_CONFIG_FIELD_15_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR5_RESETVAL                          (0x55555555U)

/* ICFR6 */

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_0_MASK           (0x00000003U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_0_SHIFT          (0U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_0_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_0_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_1_MASK           (0x0000000CU)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_1_SHIFT          (2U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_1_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_1_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_2_MASK           (0x00000030U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_2_SHIFT          (4U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_2_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_2_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_3_MASK           (0x000000C0U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_3_SHIFT          (6U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_3_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_3_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_4_MASK           (0x00000300U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_4_SHIFT          (8U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_4_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_4_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_5_MASK           (0x00000C00U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_5_SHIFT          (10U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_5_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_5_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_6_MASK           (0x00003000U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_6_SHIFT          (12U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_6_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_6_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_7_MASK           (0x0000C000U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_7_SHIFT          (14U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_7_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_7_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_8_MASK           (0x00030000U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_8_SHIFT          (16U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_8_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_8_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_9_MASK           (0x000C0000U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_9_SHIFT          (18U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_9_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_9_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_10_MASK          (0x00300000U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_10_SHIFT         (20U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_10_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_10_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_11_MASK          (0x00C00000U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_11_SHIFT         (22U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_11_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_11_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_12_MASK          (0x03000000U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_12_SHIFT         (24U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_12_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_12_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_13_MASK          (0x0C000000U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_13_SHIFT         (26U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_13_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_13_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_14_MASK          (0x30000000U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_14_SHIFT         (28U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_14_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_14_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_15_MASK          (0xC0000000U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_15_SHIFT         (30U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_15_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR6_INT_CONFIG_FIELD_15_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR6_RESETVAL                          (0x55555555U)

/* ICFR7 */

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_0_MASK           (0x00000003U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_0_SHIFT          (0U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_0_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_0_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_1_MASK           (0x0000000CU)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_1_SHIFT          (2U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_1_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_1_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_2_MASK           (0x00000030U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_2_SHIFT          (4U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_2_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_2_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_3_MASK           (0x000000C0U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_3_SHIFT          (6U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_3_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_3_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_4_MASK           (0x00000300U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_4_SHIFT          (8U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_4_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_4_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_5_MASK           (0x00000C00U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_5_SHIFT          (10U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_5_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_5_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_6_MASK           (0x00003000U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_6_SHIFT          (12U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_6_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_6_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_7_MASK           (0x0000C000U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_7_SHIFT          (14U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_7_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_7_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_8_MASK           (0x00030000U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_8_SHIFT          (16U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_8_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_8_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_9_MASK           (0x000C0000U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_9_SHIFT          (18U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_9_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_9_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_10_MASK          (0x00300000U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_10_SHIFT         (20U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_10_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_10_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_11_MASK          (0x00C00000U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_11_SHIFT         (22U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_11_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_11_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_12_MASK          (0x03000000U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_12_SHIFT         (24U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_12_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_12_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_13_MASK          (0x0C000000U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_13_SHIFT         (26U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_13_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_13_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_14_MASK          (0x30000000U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_14_SHIFT         (28U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_14_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_14_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_15_MASK          (0xC0000000U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_15_SHIFT         (30U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_15_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR7_INT_CONFIG_FIELD_15_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR7_RESETVAL                          (0x55555555U)

/* ICFR8 */

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_0_MASK           (0x00000003U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_0_SHIFT          (0U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_0_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_0_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_1_MASK           (0x0000000CU)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_1_SHIFT          (2U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_1_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_1_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_2_MASK           (0x00000030U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_2_SHIFT          (4U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_2_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_2_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_3_MASK           (0x000000C0U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_3_SHIFT          (6U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_3_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_3_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_4_MASK           (0x00000300U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_4_SHIFT          (8U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_4_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_4_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_5_MASK           (0x00000C00U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_5_SHIFT          (10U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_5_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_5_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_6_MASK           (0x00003000U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_6_SHIFT          (12U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_6_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_6_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_7_MASK           (0x0000C000U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_7_SHIFT          (14U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_7_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_7_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_8_MASK           (0x00030000U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_8_SHIFT          (16U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_8_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_8_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_9_MASK           (0x000C0000U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_9_SHIFT          (18U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_9_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_9_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_10_MASK          (0x00300000U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_10_SHIFT         (20U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_10_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_10_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_11_MASK          (0x00C00000U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_11_SHIFT         (22U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_11_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_11_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_12_MASK          (0x03000000U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_12_SHIFT         (24U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_12_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_12_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_13_MASK          (0x0C000000U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_13_SHIFT         (26U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_13_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_13_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_14_MASK          (0x30000000U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_14_SHIFT         (28U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_14_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_14_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_15_MASK          (0xC0000000U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_15_SHIFT         (30U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_15_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR8_INT_CONFIG_FIELD_15_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR8_RESETVAL                          (0x55555555U)

/* ICFR9 */

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_0_MASK           (0x00000003U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_0_SHIFT          (0U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_0_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_0_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_1_MASK           (0x0000000CU)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_1_SHIFT          (2U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_1_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_1_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_2_MASK           (0x00000030U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_2_SHIFT          (4U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_2_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_2_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_3_MASK           (0x000000C0U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_3_SHIFT          (6U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_3_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_3_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_4_MASK           (0x00000300U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_4_SHIFT          (8U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_4_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_4_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_5_MASK           (0x00000C00U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_5_SHIFT          (10U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_5_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_5_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_6_MASK           (0x00003000U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_6_SHIFT          (12U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_6_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_6_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_7_MASK           (0x0000C000U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_7_SHIFT          (14U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_7_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_7_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_8_MASK           (0x00030000U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_8_SHIFT          (16U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_8_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_8_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_9_MASK           (0x000C0000U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_9_SHIFT          (18U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_9_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_9_MAX            (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_10_MASK          (0x00300000U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_10_SHIFT         (20U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_10_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_10_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_11_MASK          (0x00C00000U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_11_SHIFT         (22U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_11_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_11_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_12_MASK          (0x03000000U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_12_SHIFT         (24U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_12_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_12_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_13_MASK          (0x0C000000U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_13_SHIFT         (26U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_13_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_13_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_14_MASK          (0x30000000U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_14_SHIFT         (28U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_14_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_14_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_15_MASK          (0xC0000000U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_15_SHIFT         (30U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_15_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR9_INT_CONFIG_FIELD_15_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR9_RESETVAL                          (0x55555555U)

/* ICFR10 */

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_0_MASK          (0x00000003U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_0_SHIFT         (0U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_0_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_0_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_1_MASK          (0x0000000CU)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_1_SHIFT         (2U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_1_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_1_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_2_MASK          (0x00000030U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_2_SHIFT         (4U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_2_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_2_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_3_MASK          (0x000000C0U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_3_SHIFT         (6U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_3_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_3_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_4_MASK          (0x00000300U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_4_SHIFT         (8U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_4_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_4_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_5_MASK          (0x00000C00U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_5_SHIFT         (10U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_5_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_5_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_6_MASK          (0x00003000U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_6_SHIFT         (12U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_6_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_6_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_7_MASK          (0x0000C000U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_7_SHIFT         (14U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_7_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_7_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_8_MASK          (0x00030000U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_8_SHIFT         (16U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_8_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_8_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_9_MASK          (0x000C0000U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_9_SHIFT         (18U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_9_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_9_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_10_MASK         (0x00300000U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_10_SHIFT        (20U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_10_RESETVAL     (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_10_MAX          (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_11_MASK         (0x00C00000U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_11_SHIFT        (22U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_11_RESETVAL     (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_11_MAX          (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_12_MASK         (0x03000000U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_12_SHIFT        (24U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_12_RESETVAL     (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_12_MAX          (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_13_MASK         (0x0C000000U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_13_SHIFT        (26U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_13_RESETVAL     (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_13_MAX          (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_14_MASK         (0x30000000U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_14_SHIFT        (28U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_14_RESETVAL     (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_14_MAX          (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_15_MASK         (0xC0000000U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_15_SHIFT        (30U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_15_RESETVAL     (0x00000001U)
#define CSL_ARMGICDISTR_ICFR10_INT_CONFIG_FIELD_15_MAX          (0x00000003U)

#define CSL_ARMGICDISTR_ICFR10_RESETVAL                         (0x55555555U)

/* ICFR11 */

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_0_MASK          (0x00000003U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_0_SHIFT         (0U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_0_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_0_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_1_MASK          (0x0000000CU)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_1_SHIFT         (2U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_1_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_1_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_2_MASK          (0x00000030U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_2_SHIFT         (4U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_2_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_2_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_3_MASK          (0x000000C0U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_3_SHIFT         (6U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_3_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_3_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_4_MASK          (0x00000300U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_4_SHIFT         (8U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_4_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_4_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_5_MASK          (0x00000C00U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_5_SHIFT         (10U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_5_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_5_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_6_MASK          (0x00003000U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_6_SHIFT         (12U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_6_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_6_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_7_MASK          (0x0000C000U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_7_SHIFT         (14U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_7_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_7_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_8_MASK          (0x00030000U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_8_SHIFT         (16U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_8_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_8_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_9_MASK          (0x000C0000U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_9_SHIFT         (18U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_9_RESETVAL      (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_9_MAX           (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_10_MASK         (0x00300000U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_10_SHIFT        (20U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_10_RESETVAL     (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_10_MAX          (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_11_MASK         (0x00C00000U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_11_SHIFT        (22U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_11_RESETVAL     (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_11_MAX          (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_12_MASK         (0x03000000U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_12_SHIFT        (24U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_12_RESETVAL     (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_12_MAX          (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_13_MASK         (0x0C000000U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_13_SHIFT        (26U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_13_RESETVAL     (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_13_MAX          (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_14_MASK         (0x30000000U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_14_SHIFT        (28U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_14_RESETVAL     (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_14_MAX          (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_15_MASK         (0xC0000000U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_15_SHIFT        (30U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_15_RESETVAL     (0x00000001U)
#define CSL_ARMGICDISTR_ICFR11_INT_CONFIG_FIELD_15_MAX          (0x00000003U)

#define CSL_ARMGICDISTR_ICFR11_RESETVAL                         (0x55555555U)

/* PPISR */

#define CSL_ARMGICDISTR_PPISR_PPI_STS_0_MASK                    (0x00001000U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_0_SHIFT                   (12U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_0_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_0_MAX                     (0x00000001U)

#define CSL_ARMGICDISTR_PPISR_PPI_STS_1_MASK                    (0x00002000U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_1_SHIFT                   (13U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_1_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_1_MAX                     (0x00000001U)

#define CSL_ARMGICDISTR_PPISR_PPI_STS_2_MASK                    (0x00004000U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_2_SHIFT                   (14U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_2_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_2_MAX                     (0x00000001U)

#define CSL_ARMGICDISTR_PPISR_PPI_STS_3_MASK                    (0x00008000U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_3_SHIFT                   (15U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_3_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_3_MAX                     (0x00000001U)

#define CSL_ARMGICDISTR_PPISR_PPI_STS_4_MASK                    (0x00000800U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_4_SHIFT                   (11U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_4_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_4_MAX                     (0x00000001U)

#define CSL_ARMGICDISTR_PPISR_PPI_STS_5_MASK                    (0x00000400U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_5_SHIFT                   (10U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_5_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_5_MAX                     (0x00000001U)

#define CSL_ARMGICDISTR_PPISR_PPI_STS_6_MASK                    (0x00000200U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_6_SHIFT                   (9U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_6_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_PPISR_PPI_STS_6_MAX                     (0x00000001U)

#define CSL_ARMGICDISTR_PPISR_RESETVAL                          (0x00000000U)

/* SPISR0 */

#define CSL_ARMGICDISTR_SPISR0_SPI_0_MASK                       (0x00000001U)
#define CSL_ARMGICDISTR_SPISR0_SPI_0_SHIFT                      (0U)
#define CSL_ARMGICDISTR_SPISR0_SPI_0_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_0_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_1_MASK                       (0x00000002U)
#define CSL_ARMGICDISTR_SPISR0_SPI_1_SHIFT                      (1U)
#define CSL_ARMGICDISTR_SPISR0_SPI_1_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_1_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_2_MASK                       (0x00000004U)
#define CSL_ARMGICDISTR_SPISR0_SPI_2_SHIFT                      (2U)
#define CSL_ARMGICDISTR_SPISR0_SPI_2_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_2_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_3_MASK                       (0x00000008U)
#define CSL_ARMGICDISTR_SPISR0_SPI_3_SHIFT                      (3U)
#define CSL_ARMGICDISTR_SPISR0_SPI_3_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_3_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_4_MASK                       (0x00000010U)
#define CSL_ARMGICDISTR_SPISR0_SPI_4_SHIFT                      (4U)
#define CSL_ARMGICDISTR_SPISR0_SPI_4_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_4_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_5_MASK                       (0x00000020U)
#define CSL_ARMGICDISTR_SPISR0_SPI_5_SHIFT                      (5U)
#define CSL_ARMGICDISTR_SPISR0_SPI_5_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_5_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_6_MASK                       (0x00000040U)
#define CSL_ARMGICDISTR_SPISR0_SPI_6_SHIFT                      (6U)
#define CSL_ARMGICDISTR_SPISR0_SPI_6_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_6_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_7_MASK                       (0x00000080U)
#define CSL_ARMGICDISTR_SPISR0_SPI_7_SHIFT                      (7U)
#define CSL_ARMGICDISTR_SPISR0_SPI_7_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_7_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_8_MASK                       (0x00000100U)
#define CSL_ARMGICDISTR_SPISR0_SPI_8_SHIFT                      (8U)
#define CSL_ARMGICDISTR_SPISR0_SPI_8_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_8_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_9_MASK                       (0x00000200U)
#define CSL_ARMGICDISTR_SPISR0_SPI_9_SHIFT                      (9U)
#define CSL_ARMGICDISTR_SPISR0_SPI_9_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_9_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_10_MASK                      (0x00000400U)
#define CSL_ARMGICDISTR_SPISR0_SPI_10_SHIFT                     (10U)
#define CSL_ARMGICDISTR_SPISR0_SPI_10_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_10_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_11_MASK                      (0x00000800U)
#define CSL_ARMGICDISTR_SPISR0_SPI_11_SHIFT                     (11U)
#define CSL_ARMGICDISTR_SPISR0_SPI_11_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_11_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_12_MASK                      (0x00001000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_12_SHIFT                     (12U)
#define CSL_ARMGICDISTR_SPISR0_SPI_12_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_12_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_13_MASK                      (0x00002000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_13_SHIFT                     (13U)
#define CSL_ARMGICDISTR_SPISR0_SPI_13_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_13_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_14_MASK                      (0x00004000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_14_SHIFT                     (14U)
#define CSL_ARMGICDISTR_SPISR0_SPI_14_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_14_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_15_MASK                      (0x00008000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_15_SHIFT                     (15U)
#define CSL_ARMGICDISTR_SPISR0_SPI_15_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_15_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_16_MASK                      (0x00010000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_16_SHIFT                     (16U)
#define CSL_ARMGICDISTR_SPISR0_SPI_16_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_16_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_17_MASK                      (0x00020000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_17_SHIFT                     (17U)
#define CSL_ARMGICDISTR_SPISR0_SPI_17_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_17_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_18_MASK                      (0x00040000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_18_SHIFT                     (18U)
#define CSL_ARMGICDISTR_SPISR0_SPI_18_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_18_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_19_MASK                      (0x00080000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_19_SHIFT                     (19U)
#define CSL_ARMGICDISTR_SPISR0_SPI_19_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_19_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_20_MASK                      (0x00100000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_20_SHIFT                     (20U)
#define CSL_ARMGICDISTR_SPISR0_SPI_20_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_20_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_21_MASK                      (0x00200000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_21_SHIFT                     (21U)
#define CSL_ARMGICDISTR_SPISR0_SPI_21_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_21_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_22_MASK                      (0x00400000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_22_SHIFT                     (22U)
#define CSL_ARMGICDISTR_SPISR0_SPI_22_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_22_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_23_MASK                      (0x00800000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_23_SHIFT                     (23U)
#define CSL_ARMGICDISTR_SPISR0_SPI_23_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_23_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_24_MASK                      (0x01000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_24_SHIFT                     (24U)
#define CSL_ARMGICDISTR_SPISR0_SPI_24_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_24_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_25_MASK                      (0x02000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_25_SHIFT                     (25U)
#define CSL_ARMGICDISTR_SPISR0_SPI_25_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_25_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_26_MASK                      (0x04000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_26_SHIFT                     (26U)
#define CSL_ARMGICDISTR_SPISR0_SPI_26_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_26_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_27_MASK                      (0x08000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_27_SHIFT                     (27U)
#define CSL_ARMGICDISTR_SPISR0_SPI_27_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_27_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_28_MASK                      (0x10000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_28_SHIFT                     (28U)
#define CSL_ARMGICDISTR_SPISR0_SPI_28_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_28_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_29_MASK                      (0x20000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_29_SHIFT                     (29U)
#define CSL_ARMGICDISTR_SPISR0_SPI_29_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_29_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_30_MASK                      (0x40000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_30_SHIFT                     (30U)
#define CSL_ARMGICDISTR_SPISR0_SPI_30_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_30_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_SPI_31_MASK                      (0x80000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_31_SHIFT                     (31U)
#define CSL_ARMGICDISTR_SPISR0_SPI_31_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR0_SPI_31_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR0_RESETVAL                         (0x00000000U)

/* SPISR1 */

#define CSL_ARMGICDISTR_SPISR1_SPI_32_MASK                      (0x00000001U)
#define CSL_ARMGICDISTR_SPISR1_SPI_32_SHIFT                     (0U)
#define CSL_ARMGICDISTR_SPISR1_SPI_32_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_32_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_33_MASK                      (0x00000002U)
#define CSL_ARMGICDISTR_SPISR1_SPI_33_SHIFT                     (1U)
#define CSL_ARMGICDISTR_SPISR1_SPI_33_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_33_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_34_MASK                      (0x00000004U)
#define CSL_ARMGICDISTR_SPISR1_SPI_34_SHIFT                     (2U)
#define CSL_ARMGICDISTR_SPISR1_SPI_34_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_34_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_35_MASK                      (0x00000008U)
#define CSL_ARMGICDISTR_SPISR1_SPI_35_SHIFT                     (3U)
#define CSL_ARMGICDISTR_SPISR1_SPI_35_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_35_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_36_MASK                      (0x00000010U)
#define CSL_ARMGICDISTR_SPISR1_SPI_36_SHIFT                     (4U)
#define CSL_ARMGICDISTR_SPISR1_SPI_36_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_36_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_37_MASK                      (0x00000020U)
#define CSL_ARMGICDISTR_SPISR1_SPI_37_SHIFT                     (5U)
#define CSL_ARMGICDISTR_SPISR1_SPI_37_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_37_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_38_MASK                      (0x00000040U)
#define CSL_ARMGICDISTR_SPISR1_SPI_38_SHIFT                     (6U)
#define CSL_ARMGICDISTR_SPISR1_SPI_38_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_38_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_39_MASK                      (0x00000080U)
#define CSL_ARMGICDISTR_SPISR1_SPI_39_SHIFT                     (7U)
#define CSL_ARMGICDISTR_SPISR1_SPI_39_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_39_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_40_MASK                      (0x00000100U)
#define CSL_ARMGICDISTR_SPISR1_SPI_40_SHIFT                     (8U)
#define CSL_ARMGICDISTR_SPISR1_SPI_40_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_40_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_41_MASK                      (0x00000200U)
#define CSL_ARMGICDISTR_SPISR1_SPI_41_SHIFT                     (9U)
#define CSL_ARMGICDISTR_SPISR1_SPI_41_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_41_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_42_MASK                      (0x00000400U)
#define CSL_ARMGICDISTR_SPISR1_SPI_42_SHIFT                     (10U)
#define CSL_ARMGICDISTR_SPISR1_SPI_42_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_42_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_43_MASK                      (0x00000800U)
#define CSL_ARMGICDISTR_SPISR1_SPI_43_SHIFT                     (11U)
#define CSL_ARMGICDISTR_SPISR1_SPI_43_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_43_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_44_MASK                      (0x00001000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_44_SHIFT                     (12U)
#define CSL_ARMGICDISTR_SPISR1_SPI_44_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_44_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_45_MASK                      (0x00002000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_45_SHIFT                     (13U)
#define CSL_ARMGICDISTR_SPISR1_SPI_45_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_45_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_46_MASK                      (0x00004000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_46_SHIFT                     (14U)
#define CSL_ARMGICDISTR_SPISR1_SPI_46_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_46_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_47_MASK                      (0x00008000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_47_SHIFT                     (15U)
#define CSL_ARMGICDISTR_SPISR1_SPI_47_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_47_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_48_MASK                      (0x00010000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_48_SHIFT                     (16U)
#define CSL_ARMGICDISTR_SPISR1_SPI_48_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_48_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_49_MASK                      (0x00020000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_49_SHIFT                     (17U)
#define CSL_ARMGICDISTR_SPISR1_SPI_49_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_49_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_50_MASK                      (0x00040000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_50_SHIFT                     (18U)
#define CSL_ARMGICDISTR_SPISR1_SPI_50_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_50_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_51_MASK                      (0x00080000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_51_SHIFT                     (19U)
#define CSL_ARMGICDISTR_SPISR1_SPI_51_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_51_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_52_MASK                      (0x00100000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_52_SHIFT                     (20U)
#define CSL_ARMGICDISTR_SPISR1_SPI_52_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_52_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_53_MASK                      (0x00200000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_53_SHIFT                     (21U)
#define CSL_ARMGICDISTR_SPISR1_SPI_53_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_53_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_54_MASK                      (0x00400000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_54_SHIFT                     (22U)
#define CSL_ARMGICDISTR_SPISR1_SPI_54_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_54_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_55_MASK                      (0x00800000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_55_SHIFT                     (23U)
#define CSL_ARMGICDISTR_SPISR1_SPI_55_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_55_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_56_MASK                      (0x01000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_56_SHIFT                     (24U)
#define CSL_ARMGICDISTR_SPISR1_SPI_56_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_56_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_57_MASK                      (0x02000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_57_SHIFT                     (25U)
#define CSL_ARMGICDISTR_SPISR1_SPI_57_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_57_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_58_MASK                      (0x04000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_58_SHIFT                     (26U)
#define CSL_ARMGICDISTR_SPISR1_SPI_58_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_58_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_59_MASK                      (0x08000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_59_SHIFT                     (27U)
#define CSL_ARMGICDISTR_SPISR1_SPI_59_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_59_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_60_MASK                      (0x10000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_60_SHIFT                     (28U)
#define CSL_ARMGICDISTR_SPISR1_SPI_60_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_60_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_61_MASK                      (0x20000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_61_SHIFT                     (29U)
#define CSL_ARMGICDISTR_SPISR1_SPI_61_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_61_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_62_MASK                      (0x40000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_62_SHIFT                     (30U)
#define CSL_ARMGICDISTR_SPISR1_SPI_62_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_62_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_SPI_63_MASK                      (0x80000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_63_SHIFT                     (31U)
#define CSL_ARMGICDISTR_SPISR1_SPI_63_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SPISR1_SPI_63_MAX                       (0x00000001U)

#define CSL_ARMGICDISTR_SPISR1_RESETVAL                         (0x00000000U)

/* SPISR2 */

#define CSL_ARMGICDISTR_SPISR2_ID64_MASK                        (0x00000001U)
#define CSL_ARMGICDISTR_SPISR2_ID64_SHIFT                       (0U)
#define CSL_ARMGICDISTR_SPISR2_ID64_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID64_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID65_MASK                        (0x00000002U)
#define CSL_ARMGICDISTR_SPISR2_ID65_SHIFT                       (1U)
#define CSL_ARMGICDISTR_SPISR2_ID65_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID65_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID66_MASK                        (0x00000004U)
#define CSL_ARMGICDISTR_SPISR2_ID66_SHIFT                       (2U)
#define CSL_ARMGICDISTR_SPISR2_ID66_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID66_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID67_MASK                        (0x00000008U)
#define CSL_ARMGICDISTR_SPISR2_ID67_SHIFT                       (3U)
#define CSL_ARMGICDISTR_SPISR2_ID67_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID67_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID68_MASK                        (0x00000010U)
#define CSL_ARMGICDISTR_SPISR2_ID68_SHIFT                       (4U)
#define CSL_ARMGICDISTR_SPISR2_ID68_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID68_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID69_MASK                        (0x00000020U)
#define CSL_ARMGICDISTR_SPISR2_ID69_SHIFT                       (5U)
#define CSL_ARMGICDISTR_SPISR2_ID69_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID69_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID70_MASK                        (0x00000040U)
#define CSL_ARMGICDISTR_SPISR2_ID70_SHIFT                       (6U)
#define CSL_ARMGICDISTR_SPISR2_ID70_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID70_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID71_MASK                        (0x00000080U)
#define CSL_ARMGICDISTR_SPISR2_ID71_SHIFT                       (7U)
#define CSL_ARMGICDISTR_SPISR2_ID71_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID71_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID72_MASK                        (0x00000100U)
#define CSL_ARMGICDISTR_SPISR2_ID72_SHIFT                       (8U)
#define CSL_ARMGICDISTR_SPISR2_ID72_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID72_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID73_MASK                        (0x00000200U)
#define CSL_ARMGICDISTR_SPISR2_ID73_SHIFT                       (9U)
#define CSL_ARMGICDISTR_SPISR2_ID73_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID73_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID74_MASK                        (0x00000400U)
#define CSL_ARMGICDISTR_SPISR2_ID74_SHIFT                       (10U)
#define CSL_ARMGICDISTR_SPISR2_ID74_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID74_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID75_MASK                        (0x00000800U)
#define CSL_ARMGICDISTR_SPISR2_ID75_SHIFT                       (11U)
#define CSL_ARMGICDISTR_SPISR2_ID75_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID75_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID76_MASK                        (0x00001000U)
#define CSL_ARMGICDISTR_SPISR2_ID76_SHIFT                       (12U)
#define CSL_ARMGICDISTR_SPISR2_ID76_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID76_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID77_MASK                        (0x00002000U)
#define CSL_ARMGICDISTR_SPISR2_ID77_SHIFT                       (13U)
#define CSL_ARMGICDISTR_SPISR2_ID77_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID77_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID78_MASK                        (0x00004000U)
#define CSL_ARMGICDISTR_SPISR2_ID78_SHIFT                       (14U)
#define CSL_ARMGICDISTR_SPISR2_ID78_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID78_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID79_MASK                        (0x00008000U)
#define CSL_ARMGICDISTR_SPISR2_ID79_SHIFT                       (15U)
#define CSL_ARMGICDISTR_SPISR2_ID79_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID79_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID80_MASK                        (0x00010000U)
#define CSL_ARMGICDISTR_SPISR2_ID80_SHIFT                       (16U)
#define CSL_ARMGICDISTR_SPISR2_ID80_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID80_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID81_MASK                        (0x00020000U)
#define CSL_ARMGICDISTR_SPISR2_ID81_SHIFT                       (17U)
#define CSL_ARMGICDISTR_SPISR2_ID81_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID81_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID82_MASK                        (0x00040000U)
#define CSL_ARMGICDISTR_SPISR2_ID82_SHIFT                       (18U)
#define CSL_ARMGICDISTR_SPISR2_ID82_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID82_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID83_MASK                        (0x00080000U)
#define CSL_ARMGICDISTR_SPISR2_ID83_SHIFT                       (19U)
#define CSL_ARMGICDISTR_SPISR2_ID83_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID83_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID84_MASK                        (0x00100000U)
#define CSL_ARMGICDISTR_SPISR2_ID84_SHIFT                       (20U)
#define CSL_ARMGICDISTR_SPISR2_ID84_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID84_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID85_MASK                        (0x00200000U)
#define CSL_ARMGICDISTR_SPISR2_ID85_SHIFT                       (21U)
#define CSL_ARMGICDISTR_SPISR2_ID85_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID85_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID86_MASK                        (0x00400000U)
#define CSL_ARMGICDISTR_SPISR2_ID86_SHIFT                       (22U)
#define CSL_ARMGICDISTR_SPISR2_ID86_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID86_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID87_MASK                        (0x00800000U)
#define CSL_ARMGICDISTR_SPISR2_ID87_SHIFT                       (23U)
#define CSL_ARMGICDISTR_SPISR2_ID87_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID87_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID88_MASK                        (0x01000000U)
#define CSL_ARMGICDISTR_SPISR2_ID88_SHIFT                       (24U)
#define CSL_ARMGICDISTR_SPISR2_ID88_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID88_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID89_MASK                        (0x02000000U)
#define CSL_ARMGICDISTR_SPISR2_ID89_SHIFT                       (25U)
#define CSL_ARMGICDISTR_SPISR2_ID89_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID89_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID90_MASK                        (0x04000000U)
#define CSL_ARMGICDISTR_SPISR2_ID90_SHIFT                       (26U)
#define CSL_ARMGICDISTR_SPISR2_ID90_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID90_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID91_MASK                        (0x08000000U)
#define CSL_ARMGICDISTR_SPISR2_ID91_SHIFT                       (27U)
#define CSL_ARMGICDISTR_SPISR2_ID91_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID91_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID92_MASK                        (0x10000000U)
#define CSL_ARMGICDISTR_SPISR2_ID92_SHIFT                       (28U)
#define CSL_ARMGICDISTR_SPISR2_ID92_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID92_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID93_MASK                        (0x20000000U)
#define CSL_ARMGICDISTR_SPISR2_ID93_SHIFT                       (29U)
#define CSL_ARMGICDISTR_SPISR2_ID93_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID93_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID94_MASK                        (0x40000000U)
#define CSL_ARMGICDISTR_SPISR2_ID94_SHIFT                       (30U)
#define CSL_ARMGICDISTR_SPISR2_ID94_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID94_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_ID95_MASK                        (0x80000000U)
#define CSL_ARMGICDISTR_SPISR2_ID95_SHIFT                       (31U)
#define CSL_ARMGICDISTR_SPISR2_ID95_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR2_ID95_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR2_RESETVAL                         (0x00000000U)

/* SPISR3 */

#define CSL_ARMGICDISTR_SPISR3_ID96_MASK                        (0x00000001U)
#define CSL_ARMGICDISTR_SPISR3_ID96_SHIFT                       (0U)
#define CSL_ARMGICDISTR_SPISR3_ID96_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID96_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID97_MASK                        (0x00000002U)
#define CSL_ARMGICDISTR_SPISR3_ID97_SHIFT                       (1U)
#define CSL_ARMGICDISTR_SPISR3_ID97_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID97_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID98_MASK                        (0x00000004U)
#define CSL_ARMGICDISTR_SPISR3_ID98_SHIFT                       (2U)
#define CSL_ARMGICDISTR_SPISR3_ID98_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID98_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID99_MASK                        (0x00000008U)
#define CSL_ARMGICDISTR_SPISR3_ID99_SHIFT                       (3U)
#define CSL_ARMGICDISTR_SPISR3_ID99_RESETVAL                    (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID99_MAX                         (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID100_MASK                       (0x00000010U)
#define CSL_ARMGICDISTR_SPISR3_ID100_SHIFT                      (4U)
#define CSL_ARMGICDISTR_SPISR3_ID100_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID100_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID101_MASK                       (0x00000020U)
#define CSL_ARMGICDISTR_SPISR3_ID101_SHIFT                      (5U)
#define CSL_ARMGICDISTR_SPISR3_ID101_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID101_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID102_MASK                       (0x00000040U)
#define CSL_ARMGICDISTR_SPISR3_ID102_SHIFT                      (6U)
#define CSL_ARMGICDISTR_SPISR3_ID102_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID102_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID103_MASK                       (0x00000080U)
#define CSL_ARMGICDISTR_SPISR3_ID103_SHIFT                      (7U)
#define CSL_ARMGICDISTR_SPISR3_ID103_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID103_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID104_MASK                       (0x00000100U)
#define CSL_ARMGICDISTR_SPISR3_ID104_SHIFT                      (8U)
#define CSL_ARMGICDISTR_SPISR3_ID104_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID104_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID105_MASK                       (0x00000200U)
#define CSL_ARMGICDISTR_SPISR3_ID105_SHIFT                      (9U)
#define CSL_ARMGICDISTR_SPISR3_ID105_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID105_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID106_MASK                       (0x00000400U)
#define CSL_ARMGICDISTR_SPISR3_ID106_SHIFT                      (10U)
#define CSL_ARMGICDISTR_SPISR3_ID106_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID106_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID107_MASK                       (0x00000800U)
#define CSL_ARMGICDISTR_SPISR3_ID107_SHIFT                      (11U)
#define CSL_ARMGICDISTR_SPISR3_ID107_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID107_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID108_MASK                       (0x00001000U)
#define CSL_ARMGICDISTR_SPISR3_ID108_SHIFT                      (12U)
#define CSL_ARMGICDISTR_SPISR3_ID108_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID108_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID109_MASK                       (0x00002000U)
#define CSL_ARMGICDISTR_SPISR3_ID109_SHIFT                      (13U)
#define CSL_ARMGICDISTR_SPISR3_ID109_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID109_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID110_MASK                       (0x00004000U)
#define CSL_ARMGICDISTR_SPISR3_ID110_SHIFT                      (14U)
#define CSL_ARMGICDISTR_SPISR3_ID110_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID110_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID111_MASK                       (0x00008000U)
#define CSL_ARMGICDISTR_SPISR3_ID111_SHIFT                      (15U)
#define CSL_ARMGICDISTR_SPISR3_ID111_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID111_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID112_MASK                       (0x00010000U)
#define CSL_ARMGICDISTR_SPISR3_ID112_SHIFT                      (16U)
#define CSL_ARMGICDISTR_SPISR3_ID112_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID112_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID113_MASK                       (0x00020000U)
#define CSL_ARMGICDISTR_SPISR3_ID113_SHIFT                      (17U)
#define CSL_ARMGICDISTR_SPISR3_ID113_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID113_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID114_MASK                       (0x00040000U)
#define CSL_ARMGICDISTR_SPISR3_ID114_SHIFT                      (18U)
#define CSL_ARMGICDISTR_SPISR3_ID114_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID114_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID115_MASK                       (0x00080000U)
#define CSL_ARMGICDISTR_SPISR3_ID115_SHIFT                      (19U)
#define CSL_ARMGICDISTR_SPISR3_ID115_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID115_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID116_MASK                       (0x00100000U)
#define CSL_ARMGICDISTR_SPISR3_ID116_SHIFT                      (20U)
#define CSL_ARMGICDISTR_SPISR3_ID116_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID116_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID117_MASK                       (0x00200000U)
#define CSL_ARMGICDISTR_SPISR3_ID117_SHIFT                      (21U)
#define CSL_ARMGICDISTR_SPISR3_ID117_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID117_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID118_MASK                       (0x00400000U)
#define CSL_ARMGICDISTR_SPISR3_ID118_SHIFT                      (22U)
#define CSL_ARMGICDISTR_SPISR3_ID118_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID118_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID119_MASK                       (0x00800000U)
#define CSL_ARMGICDISTR_SPISR3_ID119_SHIFT                      (23U)
#define CSL_ARMGICDISTR_SPISR3_ID119_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID119_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID120_MASK                       (0x01000000U)
#define CSL_ARMGICDISTR_SPISR3_ID120_SHIFT                      (24U)
#define CSL_ARMGICDISTR_SPISR3_ID120_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID120_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID121_MASK                       (0x02000000U)
#define CSL_ARMGICDISTR_SPISR3_ID121_SHIFT                      (25U)
#define CSL_ARMGICDISTR_SPISR3_ID121_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID121_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID122_MASK                       (0x04000000U)
#define CSL_ARMGICDISTR_SPISR3_ID122_SHIFT                      (26U)
#define CSL_ARMGICDISTR_SPISR3_ID122_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID122_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID123_MASK                       (0x08000000U)
#define CSL_ARMGICDISTR_SPISR3_ID123_SHIFT                      (27U)
#define CSL_ARMGICDISTR_SPISR3_ID123_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID123_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID124_MASK                       (0x10000000U)
#define CSL_ARMGICDISTR_SPISR3_ID124_SHIFT                      (28U)
#define CSL_ARMGICDISTR_SPISR3_ID124_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID124_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID125_MASK                       (0x20000000U)
#define CSL_ARMGICDISTR_SPISR3_ID125_SHIFT                      (29U)
#define CSL_ARMGICDISTR_SPISR3_ID125_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID125_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID126_MASK                       (0x40000000U)
#define CSL_ARMGICDISTR_SPISR3_ID126_SHIFT                      (30U)
#define CSL_ARMGICDISTR_SPISR3_ID126_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID126_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_ID127_MASK                       (0x80000000U)
#define CSL_ARMGICDISTR_SPISR3_ID127_SHIFT                      (31U)
#define CSL_ARMGICDISTR_SPISR3_ID127_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR3_ID127_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR3_RESETVAL                         (0x00000000U)

/* SPISR4 */

#define CSL_ARMGICDISTR_SPISR4_ID128_MASK                       (0x00000001U)
#define CSL_ARMGICDISTR_SPISR4_ID128_SHIFT                      (0U)
#define CSL_ARMGICDISTR_SPISR4_ID128_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID128_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID129_MASK                       (0x00000002U)
#define CSL_ARMGICDISTR_SPISR4_ID129_SHIFT                      (1U)
#define CSL_ARMGICDISTR_SPISR4_ID129_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID129_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID130_MASK                       (0x00000004U)
#define CSL_ARMGICDISTR_SPISR4_ID130_SHIFT                      (2U)
#define CSL_ARMGICDISTR_SPISR4_ID130_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID130_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID131_MASK                       (0x00000008U)
#define CSL_ARMGICDISTR_SPISR4_ID131_SHIFT                      (3U)
#define CSL_ARMGICDISTR_SPISR4_ID131_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID131_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID132_MASK                       (0x00000010U)
#define CSL_ARMGICDISTR_SPISR4_ID132_SHIFT                      (4U)
#define CSL_ARMGICDISTR_SPISR4_ID132_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID132_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID133_MASK                       (0x00000020U)
#define CSL_ARMGICDISTR_SPISR4_ID133_SHIFT                      (5U)
#define CSL_ARMGICDISTR_SPISR4_ID133_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID133_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID134_MASK                       (0x00000040U)
#define CSL_ARMGICDISTR_SPISR4_ID134_SHIFT                      (6U)
#define CSL_ARMGICDISTR_SPISR4_ID134_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID134_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID135_MASK                       (0x00000080U)
#define CSL_ARMGICDISTR_SPISR4_ID135_SHIFT                      (7U)
#define CSL_ARMGICDISTR_SPISR4_ID135_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID135_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID136_MASK                       (0x00000100U)
#define CSL_ARMGICDISTR_SPISR4_ID136_SHIFT                      (8U)
#define CSL_ARMGICDISTR_SPISR4_ID136_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID136_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID137_MASK                       (0x00000200U)
#define CSL_ARMGICDISTR_SPISR4_ID137_SHIFT                      (9U)
#define CSL_ARMGICDISTR_SPISR4_ID137_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID137_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID138_MASK                       (0x00000400U)
#define CSL_ARMGICDISTR_SPISR4_ID138_SHIFT                      (10U)
#define CSL_ARMGICDISTR_SPISR4_ID138_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID138_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID139_MASK                       (0x00000800U)
#define CSL_ARMGICDISTR_SPISR4_ID139_SHIFT                      (11U)
#define CSL_ARMGICDISTR_SPISR4_ID139_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID139_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID140_MASK                       (0x00001000U)
#define CSL_ARMGICDISTR_SPISR4_ID140_SHIFT                      (12U)
#define CSL_ARMGICDISTR_SPISR4_ID140_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID140_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID141_MASK                       (0x00002000U)
#define CSL_ARMGICDISTR_SPISR4_ID141_SHIFT                      (13U)
#define CSL_ARMGICDISTR_SPISR4_ID141_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID141_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID142_MASK                       (0x00004000U)
#define CSL_ARMGICDISTR_SPISR4_ID142_SHIFT                      (14U)
#define CSL_ARMGICDISTR_SPISR4_ID142_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID142_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID143_MASK                       (0x00008000U)
#define CSL_ARMGICDISTR_SPISR4_ID143_SHIFT                      (15U)
#define CSL_ARMGICDISTR_SPISR4_ID143_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID143_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID144_MASK                       (0x00010000U)
#define CSL_ARMGICDISTR_SPISR4_ID144_SHIFT                      (16U)
#define CSL_ARMGICDISTR_SPISR4_ID144_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID144_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID145_MASK                       (0x00020000U)
#define CSL_ARMGICDISTR_SPISR4_ID145_SHIFT                      (17U)
#define CSL_ARMGICDISTR_SPISR4_ID145_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID145_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID146_MASK                       (0x00040000U)
#define CSL_ARMGICDISTR_SPISR4_ID146_SHIFT                      (18U)
#define CSL_ARMGICDISTR_SPISR4_ID146_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID146_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID147_MASK                       (0x00080000U)
#define CSL_ARMGICDISTR_SPISR4_ID147_SHIFT                      (19U)
#define CSL_ARMGICDISTR_SPISR4_ID147_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID147_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID148_MASK                       (0x00100000U)
#define CSL_ARMGICDISTR_SPISR4_ID148_SHIFT                      (20U)
#define CSL_ARMGICDISTR_SPISR4_ID148_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID148_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID149_MASK                       (0x00200000U)
#define CSL_ARMGICDISTR_SPISR4_ID149_SHIFT                      (21U)
#define CSL_ARMGICDISTR_SPISR4_ID149_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID149_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID150_MASK                       (0x00400000U)
#define CSL_ARMGICDISTR_SPISR4_ID150_SHIFT                      (22U)
#define CSL_ARMGICDISTR_SPISR4_ID150_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID150_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID151_MASK                       (0x00800000U)
#define CSL_ARMGICDISTR_SPISR4_ID151_SHIFT                      (23U)
#define CSL_ARMGICDISTR_SPISR4_ID151_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID151_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID152_MASK                       (0x01000000U)
#define CSL_ARMGICDISTR_SPISR4_ID152_SHIFT                      (24U)
#define CSL_ARMGICDISTR_SPISR4_ID152_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID152_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID153_MASK                       (0x02000000U)
#define CSL_ARMGICDISTR_SPISR4_ID153_SHIFT                      (25U)
#define CSL_ARMGICDISTR_SPISR4_ID153_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID153_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID154_MASK                       (0x04000000U)
#define CSL_ARMGICDISTR_SPISR4_ID154_SHIFT                      (26U)
#define CSL_ARMGICDISTR_SPISR4_ID154_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID154_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID155_MASK                       (0x08000000U)
#define CSL_ARMGICDISTR_SPISR4_ID155_SHIFT                      (27U)
#define CSL_ARMGICDISTR_SPISR4_ID155_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID155_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID156_MASK                       (0x10000000U)
#define CSL_ARMGICDISTR_SPISR4_ID156_SHIFT                      (28U)
#define CSL_ARMGICDISTR_SPISR4_ID156_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID156_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID157_MASK                       (0x20000000U)
#define CSL_ARMGICDISTR_SPISR4_ID157_SHIFT                      (29U)
#define CSL_ARMGICDISTR_SPISR4_ID157_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID157_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID158_MASK                       (0x40000000U)
#define CSL_ARMGICDISTR_SPISR4_ID158_SHIFT                      (30U)
#define CSL_ARMGICDISTR_SPISR4_ID158_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID158_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_ID159_MASK                       (0x80000000U)
#define CSL_ARMGICDISTR_SPISR4_ID159_SHIFT                      (31U)
#define CSL_ARMGICDISTR_SPISR4_ID159_RESETVAL                   (0x00000000U)
#define CSL_ARMGICDISTR_SPISR4_ID159_MAX                        (0x00000001U)

#define CSL_ARMGICDISTR_SPISR4_RESETVAL                         (0x00000000U)

/* SGIR */

#define CSL_ARMGICDISTR_SGIR_SATT_MASK                          (0x00008000U)
#define CSL_ARMGICDISTR_SGIR_SATT_SHIFT                         (15U)
#define CSL_ARMGICDISTR_SGIR_SATT_RESETVAL                      (0x00000000U)
#define CSL_ARMGICDISTR_SGIR_SATT_MAX                           (0x00000001U)

#define CSL_ARMGICDISTR_SGIR_SGIINTID_MASK                      (0x0000000FU)
#define CSL_ARMGICDISTR_SGIR_SGIINTID_SHIFT                     (0U)
#define CSL_ARMGICDISTR_SGIR_SGIINTID_RESETVAL                  (0x00000000U)
#define CSL_ARMGICDISTR_SGIR_SGIINTID_MAX                       (0x0000000fU)

#define CSL_ARMGICDISTR_SGIR_CPUTARGETLIST_MASK                 (0x00FF0000U)
#define CSL_ARMGICDISTR_SGIR_CPUTARGETLIST_SHIFT                (16U)
#define CSL_ARMGICDISTR_SGIR_CPUTARGETLIST_RESETVAL             (0x00000000U)
#define CSL_ARMGICDISTR_SGIR_CPUTARGETLIST_MAX                  (0x000000ffU)

#define CSL_ARMGICDISTR_SGIR_TARGETLISTFILTER_MASK              (0x03000000U)
#define CSL_ARMGICDISTR_SGIR_TARGETLISTFILTER_SHIFT             (24U)
#define CSL_ARMGICDISTR_SGIR_TARGETLISTFILTER_RESETVAL          (0x00000000U)
#define CSL_ARMGICDISTR_SGIR_TARGETLISTFILTER_MAX               (0x00000003U)

#define CSL_ARMGICDISTR_SGIR_RESETVAL                           (0x00000000U)

/* CPENDSGIR0 */

#define CSL_ARMGICDISTR_CPENDSGIR0_SGI0_MASK                    (0x000000FFU)
#define CSL_ARMGICDISTR_CPENDSGIR0_SGI0_SHIFT                   (0U)
#define CSL_ARMGICDISTR_CPENDSGIR0_SGI0_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR0_SGI0_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR0_SGI1_MASK                    (0x0000FF00U)
#define CSL_ARMGICDISTR_CPENDSGIR0_SGI1_SHIFT                   (8U)
#define CSL_ARMGICDISTR_CPENDSGIR0_SGI1_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR0_SGI1_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR0_SGI2_MASK                    (0x00FF0000U)
#define CSL_ARMGICDISTR_CPENDSGIR0_SGI2_SHIFT                   (16U)
#define CSL_ARMGICDISTR_CPENDSGIR0_SGI2_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR0_SGI2_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR0_SGI3_MASK                    (0xFF000000U)
#define CSL_ARMGICDISTR_CPENDSGIR0_SGI3_SHIFT                   (24U)
#define CSL_ARMGICDISTR_CPENDSGIR0_SGI3_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR0_SGI3_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR0_RESETVAL                     (0x00000000U)

/* CPENDSGIR1 */

#define CSL_ARMGICDISTR_CPENDSGIR1_SGI4_MASK                    (0x000000FFU)
#define CSL_ARMGICDISTR_CPENDSGIR1_SGI4_SHIFT                   (0U)
#define CSL_ARMGICDISTR_CPENDSGIR1_SGI4_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR1_SGI4_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR1_SGI5_MASK                    (0x0000FF00U)
#define CSL_ARMGICDISTR_CPENDSGIR1_SGI5_SHIFT                   (8U)
#define CSL_ARMGICDISTR_CPENDSGIR1_SGI5_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR1_SGI5_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR1_SGI6_MASK                    (0x00FF0000U)
#define CSL_ARMGICDISTR_CPENDSGIR1_SGI6_SHIFT                   (16U)
#define CSL_ARMGICDISTR_CPENDSGIR1_SGI6_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR1_SGI6_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR1_SGI7_MASK                    (0xFF000000U)
#define CSL_ARMGICDISTR_CPENDSGIR1_SGI7_SHIFT                   (24U)
#define CSL_ARMGICDISTR_CPENDSGIR1_SGI7_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR1_SGI7_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR1_RESETVAL                     (0x00000000U)

/* CPENDSGIR2 */

#define CSL_ARMGICDISTR_CPENDSGIR2_SGI8_MASK                    (0x000000FFU)
#define CSL_ARMGICDISTR_CPENDSGIR2_SGI8_SHIFT                   (0U)
#define CSL_ARMGICDISTR_CPENDSGIR2_SGI8_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR2_SGI8_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR2_SGI9_MASK                    (0x0000FF00U)
#define CSL_ARMGICDISTR_CPENDSGIR2_SGI9_SHIFT                   (8U)
#define CSL_ARMGICDISTR_CPENDSGIR2_SGI9_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR2_SGI9_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR2_SGI10_MASK                   (0x00FF0000U)
#define CSL_ARMGICDISTR_CPENDSGIR2_SGI10_SHIFT                  (16U)
#define CSL_ARMGICDISTR_CPENDSGIR2_SGI10_RESETVAL               (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR2_SGI10_MAX                    (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR2_SGI11_MASK                   (0xFF000000U)
#define CSL_ARMGICDISTR_CPENDSGIR2_SGI11_SHIFT                  (24U)
#define CSL_ARMGICDISTR_CPENDSGIR2_SGI11_RESETVAL               (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR2_SGI11_MAX                    (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR2_RESETVAL                     (0x00000000U)

/* CPENDSGIR3 */

#define CSL_ARMGICDISTR_CPENDSGIR3_SGI12_MASK                   (0x000000FFU)
#define CSL_ARMGICDISTR_CPENDSGIR3_SGI12_SHIFT                  (0U)
#define CSL_ARMGICDISTR_CPENDSGIR3_SGI12_RESETVAL               (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR3_SGI12_MAX                    (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR3_SGI13_MASK                   (0x0000FF00U)
#define CSL_ARMGICDISTR_CPENDSGIR3_SGI13_SHIFT                  (8U)
#define CSL_ARMGICDISTR_CPENDSGIR3_SGI13_RESETVAL               (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR3_SGI13_MAX                    (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR3_SGI14_MASK                   (0x00FF0000U)
#define CSL_ARMGICDISTR_CPENDSGIR3_SGI14_SHIFT                  (16U)
#define CSL_ARMGICDISTR_CPENDSGIR3_SGI14_RESETVAL               (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR3_SGI14_MAX                    (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR3_SGI15_MASK                   (0xFF000000U)
#define CSL_ARMGICDISTR_CPENDSGIR3_SGI15_SHIFT                  (24U)
#define CSL_ARMGICDISTR_CPENDSGIR3_SGI15_RESETVAL               (0x00000000U)
#define CSL_ARMGICDISTR_CPENDSGIR3_SGI15_MAX                    (0x000000ffU)

#define CSL_ARMGICDISTR_CPENDSGIR3_RESETVAL                     (0x00000000U)

/* SPENDSGIR0 */

#define CSL_ARMGICDISTR_SPENDSGIR0_SGI0_MASK                    (0x000000FFU)
#define CSL_ARMGICDISTR_SPENDSGIR0_SGI0_SHIFT                   (0U)
#define CSL_ARMGICDISTR_SPENDSGIR0_SGI0_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR0_SGI0_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR0_SGI1_MASK                    (0x0000FF00U)
#define CSL_ARMGICDISTR_SPENDSGIR0_SGI1_SHIFT                   (8U)
#define CSL_ARMGICDISTR_SPENDSGIR0_SGI1_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR0_SGI1_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR0_SGI2_MASK                    (0x00FF0000U)
#define CSL_ARMGICDISTR_SPENDSGIR0_SGI2_SHIFT                   (16U)
#define CSL_ARMGICDISTR_SPENDSGIR0_SGI2_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR0_SGI2_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR0_SGI3_MASK                    (0xFF000000U)
#define CSL_ARMGICDISTR_SPENDSGIR0_SGI3_SHIFT                   (24U)
#define CSL_ARMGICDISTR_SPENDSGIR0_SGI3_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR0_SGI3_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR0_RESETVAL                     (0x00000000U)

/* SPENDSGIR1 */

#define CSL_ARMGICDISTR_SPENDSGIR1_SGI4_MASK                    (0x000000FFU)
#define CSL_ARMGICDISTR_SPENDSGIR1_SGI4_SHIFT                   (0U)
#define CSL_ARMGICDISTR_SPENDSGIR1_SGI4_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR1_SGI4_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR1_SGI5_MASK                    (0x0000FF00U)
#define CSL_ARMGICDISTR_SPENDSGIR1_SGI5_SHIFT                   (8U)
#define CSL_ARMGICDISTR_SPENDSGIR1_SGI5_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR1_SGI5_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR1_SGI6_MASK                    (0x00FF0000U)
#define CSL_ARMGICDISTR_SPENDSGIR1_SGI6_SHIFT                   (16U)
#define CSL_ARMGICDISTR_SPENDSGIR1_SGI6_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR1_SGI6_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR1_SGI7_MASK                    (0xFF000000U)
#define CSL_ARMGICDISTR_SPENDSGIR1_SGI7_SHIFT                   (24U)
#define CSL_ARMGICDISTR_SPENDSGIR1_SGI7_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR1_SGI7_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR1_RESETVAL                     (0x00000000U)

/* SPENDSGIR2 */

#define CSL_ARMGICDISTR_SPENDSGIR2_SGI8_MASK                    (0x000000FFU)
#define CSL_ARMGICDISTR_SPENDSGIR2_SGI8_SHIFT                   (0U)
#define CSL_ARMGICDISTR_SPENDSGIR2_SGI8_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR2_SGI8_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR2_SGI9_MASK                    (0x0000FF00U)
#define CSL_ARMGICDISTR_SPENDSGIR2_SGI9_SHIFT                   (8U)
#define CSL_ARMGICDISTR_SPENDSGIR2_SGI9_RESETVAL                (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR2_SGI9_MAX                     (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR2_SGI10_MASK                   (0x00FF0000U)
#define CSL_ARMGICDISTR_SPENDSGIR2_SGI10_SHIFT                  (16U)
#define CSL_ARMGICDISTR_SPENDSGIR2_SGI10_RESETVAL               (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR2_SGI10_MAX                    (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR2_SGI11_MASK                   (0xFF000000U)
#define CSL_ARMGICDISTR_SPENDSGIR2_SGI11_SHIFT                  (24U)
#define CSL_ARMGICDISTR_SPENDSGIR2_SGI11_RESETVAL               (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR2_SGI11_MAX                    (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR2_RESETVAL                     (0x00000000U)

/* SPENDSGIR3 */

#define CSL_ARMGICDISTR_SPENDSGIR3_SGI12_MASK                   (0x000000FFU)
#define CSL_ARMGICDISTR_SPENDSGIR3_SGI12_SHIFT                  (0U)
#define CSL_ARMGICDISTR_SPENDSGIR3_SGI12_RESETVAL               (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR3_SGI12_MAX                    (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR3_SGI13_MASK                   (0x0000FF00U)
#define CSL_ARMGICDISTR_SPENDSGIR3_SGI13_SHIFT                  (8U)
#define CSL_ARMGICDISTR_SPENDSGIR3_SGI13_RESETVAL               (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR3_SGI13_MAX                    (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR3_SGI14_MASK                   (0x00FF0000U)
#define CSL_ARMGICDISTR_SPENDSGIR3_SGI14_SHIFT                  (16U)
#define CSL_ARMGICDISTR_SPENDSGIR3_SGI14_RESETVAL               (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR3_SGI14_MAX                    (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR3_SGI15_MASK                   (0xFF000000U)
#define CSL_ARMGICDISTR_SPENDSGIR3_SGI15_SHIFT                  (24U)
#define CSL_ARMGICDISTR_SPENDSGIR3_SGI15_RESETVAL               (0x00000000U)
#define CSL_ARMGICDISTR_SPENDSGIR3_SGI15_MAX                    (0x000000ffU)

#define CSL_ARMGICDISTR_SPENDSGIR3_RESETVAL                     (0x00000000U)

/* PIDR4 */

#define CSL_ARMGICDISTR_PIDR4_CONTINUATION_CODE_MASK            (0x0000000FU)
#define CSL_ARMGICDISTR_PIDR4_CONTINUATION_CODE_SHIFT           (0U)
#define CSL_ARMGICDISTR_PIDR4_CONTINUATION_CODE_RESETVAL        (0x00000004U)
#define CSL_ARMGICDISTR_PIDR4_CONTINUATION_CODE_MAX             (0x0000000fU)

#define CSL_ARMGICDISTR_PIDR4_RESETVAL                          (0x00000004U)

/* PIDR5 */

#define CSL_ARMGICDISTR_PIDR5_RESETVAL                          (0x00000000U)

/* PIDR6 */

#define CSL_ARMGICDISTR_PIDR6_RESETVAL                          (0x00000000U)

/* PIDR7 */

#define CSL_ARMGICDISTR_PIDR7_RESETVAL                          (0x00000000U)

/* PIDR0 */

#define CSL_ARMGICDISTR_PIDR0_DEVID_FIELD_MASK                  (0x000000FFU)
#define CSL_ARMGICDISTR_PIDR0_DEVID_FIELD_SHIFT                 (0U)
#define CSL_ARMGICDISTR_PIDR0_DEVID_FIELD_RESETVAL              (0x00000090U)
#define CSL_ARMGICDISTR_PIDR0_DEVID_FIELD_MAX                   (0x000000ffU)

#define CSL_ARMGICDISTR_PIDR0_RESETVAL                          (0x00000090U)

/* PIDR1 */

#define CSL_ARMGICDISTR_PIDR1_DEVID_MASK                        (0x0000000FU)
#define CSL_ARMGICDISTR_PIDR1_DEVID_SHIFT                       (0U)
#define CSL_ARMGICDISTR_PIDR1_DEVID_RESETVAL                    (0x00000004U)
#define CSL_ARMGICDISTR_PIDR1_DEVID_MAX                         (0x0000000fU)

#define CSL_ARMGICDISTR_PIDR1_ARCHID_LOWER_FIELD_MASK           (0x000000F0U)
#define CSL_ARMGICDISTR_PIDR1_ARCHID_LOWER_FIELD_SHIFT          (4U)
#define CSL_ARMGICDISTR_PIDR1_ARCHID_LOWER_FIELD_RESETVAL       (0x0000000bU)
#define CSL_ARMGICDISTR_PIDR1_ARCHID_LOWER_FIELD_MAX            (0x0000000fU)

#define CSL_ARMGICDISTR_PIDR1_RESETVAL                          (0x000000b4U)

/* PIDR2 */

#define CSL_ARMGICDISTR_PIDR2_ARCHID_HIGHER_FIELD_MASK          (0x00000007U)
#define CSL_ARMGICDISTR_PIDR2_ARCHID_HIGHER_FIELD_SHIFT         (0U)
#define CSL_ARMGICDISTR_PIDR2_ARCHID_HIGHER_FIELD_RESETVAL      (0x00000003U)
#define CSL_ARMGICDISTR_PIDR2_ARCHID_HIGHER_FIELD_MAX           (0x00000007U)

#define CSL_ARMGICDISTR_PIDR2_USESJEP_CODE_FIELD_MASK           (0x00000008U)
#define CSL_ARMGICDISTR_PIDR2_USESJEP_CODE_FIELD_SHIFT          (3U)
#define CSL_ARMGICDISTR_PIDR2_USESJEP_CODE_FIELD_RESETVAL       (0x00000001U)
#define CSL_ARMGICDISTR_PIDR2_USESJEP_CODE_FIELD_MAX            (0x00000001U)

#define CSL_ARMGICDISTR_PIDR2_ARCHREV_FIELD_MASK                (0x000000F0U)
#define CSL_ARMGICDISTR_PIDR2_ARCHREV_FIELD_SHIFT               (4U)
#define CSL_ARMGICDISTR_PIDR2_ARCHREV_FIELD_RESETVAL            (0x00000002U)
#define CSL_ARMGICDISTR_PIDR2_ARCHREV_FIELD_MAX                 (0x0000000fU)

#define CSL_ARMGICDISTR_PIDR2_RESETVAL                          (0x0000002bU)

/* PIDR3 */

#define CSL_ARMGICDISTR_PIDR3_REVISION_FIELD_MASK               (0x000000F0U)
#define CSL_ARMGICDISTR_PIDR3_REVISION_FIELD_SHIFT              (4U)
#define CSL_ARMGICDISTR_PIDR3_REVISION_FIELD_RESETVAL           (0x00000000U)
#define CSL_ARMGICDISTR_PIDR3_REVISION_FIELD_MAX                (0x0000000fU)

#define CSL_ARMGICDISTR_PIDR3_RESETVAL                          (0x00000000U)

/* CIDR0 */

#define CSL_ARMGICDISTR_CIDR0_PREAMBLE_MASK                     (0x000000FFU)
#define CSL_ARMGICDISTR_CIDR0_PREAMBLE_SHIFT                    (0U)
#define CSL_ARMGICDISTR_CIDR0_PREAMBLE_RESETVAL                 (0x0000000dU)
#define CSL_ARMGICDISTR_CIDR0_PREAMBLE_MAX                      (0x000000ffU)

#define CSL_ARMGICDISTR_CIDR0_RESETVAL                          (0x0000000dU)

/* CIDR1 */

#define CSL_ARMGICDISTR_CIDR1_PREAMBLE_MASK                     (0x000000FFU)
#define CSL_ARMGICDISTR_CIDR1_PREAMBLE_SHIFT                    (0U)
#define CSL_ARMGICDISTR_CIDR1_PREAMBLE_RESETVAL                 (0x000000f0U)
#define CSL_ARMGICDISTR_CIDR1_PREAMBLE_MAX                      (0x000000ffU)

#define CSL_ARMGICDISTR_CIDR1_RESETVAL                          (0x000000f0U)

/* CIDR2 */

#define CSL_ARMGICDISTR_CIDR2_PREAMBLE_MASK                     (0x000000FFU)
#define CSL_ARMGICDISTR_CIDR2_PREAMBLE_SHIFT                    (0U)
#define CSL_ARMGICDISTR_CIDR2_PREAMBLE_RESETVAL                 (0x00000005U)
#define CSL_ARMGICDISTR_CIDR2_PREAMBLE_MAX                      (0x000000ffU)

#define CSL_ARMGICDISTR_CIDR2_RESETVAL                          (0x00000005U)

/* CIDR3 */

#define CSL_ARMGICDISTR_CIDR3_PREAMBLE_MASK                     (0x000000FFU)
#define CSL_ARMGICDISTR_CIDR3_PREAMBLE_SHIFT                    (0U)
#define CSL_ARMGICDISTR_CIDR3_PREAMBLE_RESETVAL                 (0x000000b1U)
#define CSL_ARMGICDISTR_CIDR3_PREAMBLE_MAX                      (0x000000ffU)

#define CSL_ARMGICDISTR_CIDR3_RESETVAL                          (0x000000b1U)

#ifdef __cplusplus
}
#endif
#endif

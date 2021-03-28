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
#ifndef CSLR_MSMC_H_
#define CSLR_MSMC_H_
#ifdef __cplusplus
extern "C"
{
#endif

/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Removed the redundant 'CSL_MsmcSbndRegs' structure for SBND
 *         since this was a data structure with a single field.
 *      b) Modified the 'CSL_MsmcSms_mpax_prividRegs' to the the new
 *         counterpart 'CSL_MsmcSms_mpax_per_prividRegs' which in turn
 *         now includes an array of 8 MPAXH and MPAXL registers.
 *      c) Modified the 'CSL_MsmcSes_mpax_prividRegs' to the the new
 *         counterpart 'CSL_MsmcSes_mpax_per_prividRegs' which in turn
 *         now includes an array of 8 MPAXH and MPAXL registers.
 *      d) Modified the header file includes to be RTSC compliant
 */

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for SBND
\**************************************************************************/

typedef struct
{
    volatile Uint32 MPAXL;
    volatile Uint32 MPAXH;
}CSL_Msmc_Control_Regs;

/**************************************************************************\
* Register Overlay Structure for SMS_MPAX_per_PrivID
\**************************************************************************/
typedef struct
{
    CSL_Msmc_Control_Regs SMS[8];
} CSL_MsmcSms_mpax_per_prividRegs;

/**************************************************************************\
* Register Overlay Structure for SES_MPAX_per_PrivID
\**************************************************************************/
typedef struct
{
      CSL_Msmc_Control_Regs SES[8];
} CSL_MsmcSes_mpax_per_prividRegs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 PID;
    volatile Uint32 SMCC;
    volatile Uint32 SMCERRAR;
    volatile Uint32 SMCERRXR;
    volatile Uint32 SMEDCC;
    volatile Uint32 SMCEA;
    volatile Uint32 SMSECC;
    volatile Uint32 SMPFAR;
    volatile Uint32 SMPFXR;
    volatile Uint32 SMPFR;
    volatile Uint32 SMPFCR;
    volatile Uint32 SMIDCFG;
    volatile Uint32 SBND[8];
    volatile Uint32 SBNDM;
    volatile Uint32 SBNDE;
    volatile Uint32 SMEDCTST;
    volatile Uint32 CFGLCK;
    volatile Uint32 CFGULCK;
    volatile Uint32 CFGLCKSTAT;
    volatile Uint32 SMS_MPAX_LCK;
    volatile Uint32 SMS_MPAX_ULCK;
    volatile Uint32 SMS_MPAX_LCKSTAT;
    volatile Uint32 SES_MPAX_LCK;
    volatile Uint32 SES_MPAX_ULCK;
    volatile Uint32 SES_MPAX_LCKSTAT;
    volatile Uint32 SMESTAT;
    volatile Uint32 SMIRSTAT;
    volatile Uint32 SMIRC;
    volatile Uint32 SMIESTAT;
    volatile Uint32 SMIEC;
    volatile Uint8 RSVD0[12];
    volatile Uint32 SMATH;
    volatile Uint32 SMAH;
    volatile Uint32 SMARM;
    volatile Uint32 SMAWM;
    volatile Uint32 SMAV;
    volatile Uint32 SMAMP;
    volatile Uint32 SMAEP;
    volatile Uint32 SMAC;
    volatile Uint32 SMCFG;
    volatile Uint32 SMNCERRAR;
    volatile Uint32 SMNCERRXR;
    volatile Uint32 SMNCEA;
    volatile Uint8 RSVD1[304];
    CSL_MsmcSms_mpax_per_prividRegs SMS_MPAX_PER_PRIVID[16];
    CSL_MsmcSes_mpax_per_prividRegs SES_MPAX_PER_PRIVID[16];
} CSL_MsmcRegs;
/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_MSMC_PID                                            (0x0u)
#define CSL_MSMC_SMCC                                           (0x4u)
#define CSL_MSMC_SMCERRAR                                       (0x8u)
#define CSL_MSMC_SMCERRXR                                       (0xCu)
#define CSL_MSMC_SMEDCC                                         (0x10u)
#define CSL_MSMC_SMCEA                                          (0x14u)
#define CSL_MSMC_SMSECC                                         (0x18u)
#define CSL_MSMC_SMPFAR                                         (0x1Cu)
#define CSL_MSMC_SMPFXR                                         (0x20u)
#define CSL_MSMC_SMPFR                                          (0x24u)
#define CSL_MSMC_SMPFCR                                         (0x28u)
#define CSL_MSMC_SMIDCFG                                        (0x2Cu)
#define CSL_MSMC_SBNDM                                          (0x50u)
#define CSL_MSMC_SBNDE                                          (0x54u)
#define CSL_MSMC_SMEDCTST                                       (0x58u)
#define CSL_MSMC_CFGLCK                                         (0x5Cu)
#define CSL_MSMC_CFGULCK                                        (0x60u)
#define CSL_MSMC_CFGLCKSTAT                                     (0x64u)
#define CSL_MSMC_SMS_MPAX_LCK                                   (0x68u)
#define CSL_MSMC_SMS_MPAX_ULCK                                  (0x6Cu)
#define CSL_MSMC_SMS_MPAX_LCKSTAT                               (0x70u)
#define CSL_MSMC_SES_MPAX_LCK                                   (0x74u)
#define CSL_MSMC_SES_MPAX_ULCK                                  (0x78u)
#define CSL_MSMC_SES_MPAX_LCKSTAT                               (0x7Cu)
#define CSL_MSMC_SMESTAT                                        (0x80u)
#define CSL_MSMC_SMIRC                                          (0x88u)
#define CSL_MSMC_SMIRSTAT                                       (0x84u)
#define CSL_MSMC_SMIESTAT                                       (0x8Cu)
#define CSL_MSMC_SMIEC                                          (0x90u)
#define CSL_MSMC_SMATH                                          (0xA0u)
#define CSL_MSMC_SMAH                                           (0xA4u)
#define CSL_MSMC_SMARM                                          (0xA8u)
#define CSL_MSMC_SMAWM                                          (0xACu)
#define CSL_MSMC_SMAV                                           (0xB0u)
#define CSL_MSMC_SMAMP                                          (0xB4u)
#define CSL_MSMC_SMAEP                                          (0xB8u)
#define CSL_MSMC_SMAC                                           (0xBCu)
#define CSL_MSMC_SMS_MPAXL_0_0                                  (0x200u)
#define CSL_MSMC_SMS_MPAXH_0_0                                  (0x204u)
#define CSL_MSMC_SMS_MPAXL_0_1                                  (0x208u)
#define CSL_MSMC_SMS_MPAXH_0_1                                  (0x20Cu)
#define CSL_MSMC_SMS_MPAXL_0_2                                  (0x210u)
#define CSL_MSMC_SMS_MPAXH_0_2                                  (0x214u)
#define CSL_MSMC_SMS_MPAXL_0_3                                  (0x218u)
#define CSL_MSMC_SMS_MPAXH_0_3                                  (0x21Cu)
#define CSL_MSMC_SMS_MPAXL_0_4                                  (0x220u)
#define CSL_MSMC_SMS_MPAXH_0_4                                  (0x224u)
#define CSL_MSMC_SMS_MPAXL_0_5                                  (0x228u)
#define CSL_MSMC_SMS_MPAXH_0_5                                  (0x22Cu)
#define CSL_MSMC_SMS_MPAXL_0_6                                  (0x230u)
#define CSL_MSMC_SMS_MPAXH_0_6                                  (0x234u)
#define CSL_MSMC_SMS_MPAXL_0_7                                  (0x238u)
#define CSL_MSMC_SMS_MPAXH_0_7                                  (0x23Cu)
#define CSL_MSMC_SMS_MPAXL_1_0                                  (0x240u)
#define CSL_MSMC_SMS_MPAXH_1_0                                  (0x244u)
#define CSL_MSMC_SMS_MPAXL_1_1                                  (0x248u)
#define CSL_MSMC_SMS_MPAXH_1_1                                  (0x24Cu)
#define CSL_MSMC_SMS_MPAXL_1_2                                  (0x250u)
#define CSL_MSMC_SMS_MPAXH_1_2                                  (0x254u)
#define CSL_MSMC_SMS_MPAXL_1_3                                  (0x258u)
#define CSL_MSMC_SMS_MPAXH_1_3                                  (0x25Cu)
#define CSL_MSMC_SMS_MPAXL_1_4                                  (0x260u)
#define CSL_MSMC_SMS_MPAXH_1_4                                  (0x264u)
#define CSL_MSMC_SMS_MPAXL_1_5                                  (0x268u)
#define CSL_MSMC_SMS_MPAXH_1_5                                  (0x26Cu)
#define CSL_MSMC_SMS_MPAXL_1_6                                  (0x270u)
#define CSL_MSMC_SMS_MPAXH_1_6                                  (0x274u)
#define CSL_MSMC_SMS_MPAXL_1_7                                  (0x278u)
#define CSL_MSMC_SMS_MPAXH_1_7                                  (0x27Cu)
#define CSL_MSMC_SMS_MPAXL_2_0                                  (0x280u)
#define CSL_MSMC_SMS_MPAXH_2_0                                  (0x284u)
#define CSL_MSMC_SMS_MPAXL_2_1                                  (0x288u)
#define CSL_MSMC_SMS_MPAXH_2_1                                  (0x28Cu)
#define CSL_MSMC_SMS_MPAXL_2_2                                  (0x290u)
#define CSL_MSMC_SMS_MPAXH_2_2                                  (0x294u)
#define CSL_MSMC_SMS_MPAXL_2_3                                  (0x298u)
#define CSL_MSMC_SMS_MPAXH_2_3                                  (0x29Cu)
#define CSL_MSMC_SMS_MPAXL_2_4                                  (0x2A0u)
#define CSL_MSMC_SMS_MPAXH_2_4                                  (0x2A4u)
#define CSL_MSMC_SMS_MPAXL_2_5                                  (0x2A8u)
#define CSL_MSMC_SMS_MPAXH_2_5                                  (0x2ACu)
#define CSL_MSMC_SMS_MPAXL_2_6                                  (0x2B0u)
#define CSL_MSMC_SMS_MPAXH_2_6                                  (0x2B4u)
#define CSL_MSMC_SMS_MPAXL_2_7                                  (0x2B8u)
#define CSL_MSMC_SMS_MPAXH_2_7                                  (0x2BCu)
#define CSL_MSMC_SMS_MPAXL_3_0                                  (0x2C0u)
#define CSL_MSMC_SMS_MPAXH_3_0                                  (0x2C4u)
#define CSL_MSMC_SMS_MPAXL_3_1                                  (0x2C8u)
#define CSL_MSMC_SMS_MPAXH_3_1                                  (0x2CCu)
#define CSL_MSMC_SMS_MPAXL_3_2                                  (0x2D0u)
#define CSL_MSMC_SMS_MPAXH_3_2                                  (0x2D4u)
#define CSL_MSMC_SMS_MPAXL_3_3                                  (0x2D8u)
#define CSL_MSMC_SMS_MPAXH_3_3                                  (0x2DCu)
#define CSL_MSMC_SMS_MPAXL_3_4                                  (0x2E0u)
#define CSL_MSMC_SMS_MPAXH_3_4                                  (0x2E4u)
#define CSL_MSMC_SMS_MPAXL_3_5                                  (0x2E8u)
#define CSL_MSMC_SMS_MPAXH_3_5                                  (0x2ECu)
#define CSL_MSMC_SMS_MPAXL_3_6                                  (0x2F0u)
#define CSL_MSMC_SMS_MPAXH_3_6                                  (0x2F4u)
#define CSL_MSMC_SMS_MPAXL_3_7                                  (0x2F8u)
#define CSL_MSMC_SMS_MPAXH_3_7                                  (0x2FCu)
#define CSL_MSMC_SMS_MPAXL_4_0                                  (0x300u)
#define CSL_MSMC_SMS_MPAXH_4_0                                  (0x304u)
#define CSL_MSMC_SMS_MPAXL_4_1                                  (0x308u)
#define CSL_MSMC_SMS_MPAXH_4_1                                  (0x30Cu)
#define CSL_MSMC_SMS_MPAXL_4_2                                  (0x310u)
#define CSL_MSMC_SMS_MPAXH_4_2                                  (0x314u)
#define CSL_MSMC_SMS_MPAXL_4_3                                  (0x318u)
#define CSL_MSMC_SMS_MPAXH_4_3                                  (0x31Cu)
#define CSL_MSMC_SMS_MPAXL_4_4                                  (0x320u)
#define CSL_MSMC_SMS_MPAXH_4_4                                  (0x324u)
#define CSL_MSMC_SMS_MPAXL_4_5                                  (0x328u)
#define CSL_MSMC_SMS_MPAXH_4_5                                  (0x32Cu)
#define CSL_MSMC_SMS_MPAXL_4_6                                  (0x330u)
#define CSL_MSMC_SMS_MPAXH_4_6                                  (0x334u)
#define CSL_MSMC_SMS_MPAXL_4_7                                  (0x338u)
#define CSL_MSMC_SMS_MPAXH_4_7                                  (0x33Cu)
#define CSL_MSMC_SMS_MPAXL_5_0                                  (0x340u)
#define CSL_MSMC_SMS_MPAXH_5_0                                  (0x344u)
#define CSL_MSMC_SMS_MPAXL_5_1                                  (0x348u)
#define CSL_MSMC_SMS_MPAXH_5_1                                  (0x34Cu)
#define CSL_MSMC_SMS_MPAXL_5_2                                  (0x350u)
#define CSL_MSMC_SMS_MPAXH_5_2                                  (0x354u)
#define CSL_MSMC_SMS_MPAXL_5_3                                  (0x358u)
#define CSL_MSMC_SMS_MPAXH_5_3                                  (0x35Cu)
#define CSL_MSMC_SMS_MPAXL_5_4                                  (0x360u)
#define CSL_MSMC_SMS_MPAXH_5_4                                  (0x364u)
#define CSL_MSMC_SMS_MPAXL_5_5                                  (0x368u)
#define CSL_MSMC_SMS_MPAXH_5_5                                  (0x36Cu)
#define CSL_MSMC_SMS_MPAXL_5_6                                  (0x370u)
#define CSL_MSMC_SMS_MPAXH_5_6                                  (0x374u)
#define CSL_MSMC_SMS_MPAXL_5_7                                  (0x378u)
#define CSL_MSMC_SMS_MPAXH_5_7                                  (0x37Cu)
#define CSL_MSMC_SMS_MPAXL_6_0                                  (0x380u)
#define CSL_MSMC_SMS_MPAXH_6_0                                  (0x384u)
#define CSL_MSMC_SMS_MPAXL_6_1                                  (0x388u)
#define CSL_MSMC_SMS_MPAXH_6_1                                  (0x38Cu)
#define CSL_MSMC_SMS_MPAXL_6_2                                  (0x390u)
#define CSL_MSMC_SMS_MPAXH_6_2                                  (0x394u)
#define CSL_MSMC_SMS_MPAXL_6_3                                  (0x398u)
#define CSL_MSMC_SMS_MPAXH_6_3                                  (0x39Cu)
#define CSL_MSMC_SMS_MPAXL_6_4                                  (0x3A0u)
#define CSL_MSMC_SMS_MPAXH_6_4                                  (0x3A4u)
#define CSL_MSMC_SMS_MPAXL_6_5                                  (0x3A8u)
#define CSL_MSMC_SMS_MPAXH_6_5                                  (0x3ACu)
#define CSL_MSMC_SMS_MPAXL_6_6                                  (0x3B0u)
#define CSL_MSMC_SMS_MPAXH_6_6                                  (0x3B4u)
#define CSL_MSMC_SMS_MPAXL_6_7                                  (0x3B8u)
#define CSL_MSMC_SMS_MPAXH_6_7                                  (0x3BCu)
#define CSL_MSMC_SMS_MPAXL_7_0                                  (0x3C0u)
#define CSL_MSMC_SMS_MPAXH_7_0                                  (0x3C4u)
#define CSL_MSMC_SMS_MPAXL_7_1                                  (0x3C8u)
#define CSL_MSMC_SMS_MPAXH_7_1                                  (0x3CCu)
#define CSL_MSMC_SMS_MPAXL_7_2                                  (0x3D0u)
#define CSL_MSMC_SMS_MPAXH_7_2                                  (0x3D4u)
#define CSL_MSMC_SMS_MPAXL_7_3                                  (0x3D8u)
#define CSL_MSMC_SMS_MPAXH_7_3                                  (0x3DCu)
#define CSL_MSMC_SMS_MPAXL_7_4                                  (0x3E0u)
#define CSL_MSMC_SMS_MPAXH_7_4                                  (0x3E4u)
#define CSL_MSMC_SMS_MPAXL_7_5                                  (0x3E8u)
#define CSL_MSMC_SMS_MPAXH_7_5                                  (0x3ECu)
#define CSL_MSMC_SMS_MPAXL_7_6                                  (0x3F0u)
#define CSL_MSMC_SMS_MPAXH_7_6                                  (0x3F4u)
#define CSL_MSMC_SMS_MPAXL_7_7                                  (0x3F8u)
#define CSL_MSMC_SMS_MPAXH_7_7                                  (0x3FCu)
#define CSL_MSMC_SMS_MPAXL_8_0                                  (0x400u)
#define CSL_MSMC_SMS_MPAXH_8_0                                  (0x404u)
#define CSL_MSMC_SMS_MPAXL_8_1                                  (0x408u)
#define CSL_MSMC_SMS_MPAXH_8_1                                  (0x40Cu)
#define CSL_MSMC_SMS_MPAXL_8_2                                  (0x410u)
#define CSL_MSMC_SMS_MPAXH_8_2                                  (0x414u)
#define CSL_MSMC_SMS_MPAXL_8_3                                  (0x418u)
#define CSL_MSMC_SMS_MPAXH_8_3                                  (0x41Cu)
#define CSL_MSMC_SMS_MPAXL_8_4                                  (0x420u)
#define CSL_MSMC_SMS_MPAXH_8_4                                  (0x424u)
#define CSL_MSMC_SMS_MPAXL_8_5                                  (0x428u)
#define CSL_MSMC_SMS_MPAXH_8_5                                  (0x42Cu)
#define CSL_MSMC_SMS_MPAXL_8_6                                  (0x430u)
#define CSL_MSMC_SMS_MPAXH_8_6                                  (0x434u)
#define CSL_MSMC_SMS_MPAXL_8_7                                  (0x438u)
#define CSL_MSMC_SMS_MPAXH_8_7                                  (0x43Cu)
#define CSL_MSMC_SMS_MPAXL_9_0                                  (0x440u)
#define CSL_MSMC_SMS_MPAXH_9_0                                  (0x444u)
#define CSL_MSMC_SMS_MPAXL_9_1                                  (0x448u)
#define CSL_MSMC_SMS_MPAXH_9_1                                  (0x44Cu)
#define CSL_MSMC_SMS_MPAXL_9_2                                  (0x450u)
#define CSL_MSMC_SMS_MPAXH_9_2                                  (0x454u)
#define CSL_MSMC_SMS_MPAXL_9_3                                  (0x458u)
#define CSL_MSMC_SMS_MPAXH_9_3                                  (0x45Cu)
#define CSL_MSMC_SMS_MPAXL_9_4                                  (0x460u)
#define CSL_MSMC_SMS_MPAXH_9_4                                  (0x464u)
#define CSL_MSMC_SMS_MPAXL_9_5                                  (0x468u)
#define CSL_MSMC_SMS_MPAXH_9_5                                  (0x46Cu)
#define CSL_MSMC_SMS_MPAXL_9_6                                  (0x470u)
#define CSL_MSMC_SMS_MPAXH_9_6                                  (0x474u)
#define CSL_MSMC_SMS_MPAXL_9_7                                  (0x478u)
#define CSL_MSMC_SMS_MPAXH_9_7                                  (0x47Cu)
#define CSL_MSMC_SMS_MPAXL_A_0                                  (0x480u)
#define CSL_MSMC_SMS_MPAXH_A_0                                  (0x484u)
#define CSL_MSMC_SMS_MPAXL_A_1                                  (0x488u)
#define CSL_MSMC_SMS_MPAXH_A_1                                  (0x48Cu)
#define CSL_MSMC_SMS_MPAXL_A_2                                  (0x490u)
#define CSL_MSMC_SMS_MPAXH_A_2                                  (0x494u)
#define CSL_MSMC_SMS_MPAXL_A_3                                  (0x498u)
#define CSL_MSMC_SMS_MPAXH_A_3                                  (0x49Cu)
#define CSL_MSMC_SMS_MPAXL_A_4                                  (0x4A0u)
#define CSL_MSMC_SMS_MPAXH_A_4                                  (0x4A4u)
#define CSL_MSMC_SMS_MPAXL_A_5                                  (0x4A8u)
#define CSL_MSMC_SMS_MPAXH_A_5                                  (0x4ACu)
#define CSL_MSMC_SMS_MPAXL_A_6                                  (0x4B0u)
#define CSL_MSMC_SMS_MPAXH_A_6                                  (0x4B4u)
#define CSL_MSMC_SMS_MPAXL_A_7                                  (0x4B8u)
#define CSL_MSMC_SMS_MPAXH_A_7                                  (0x4BCu)
#define CSL_MSMC_SMS_MPAXL_B_0                                  (0x4C0u)
#define CSL_MSMC_SMS_MPAXH_B_0                                  (0x4C4u)
#define CSL_MSMC_SMS_MPAXL_B_1                                  (0x4C8u)
#define CSL_MSMC_SMS_MPAXH_B_1                                  (0x4CCu)
#define CSL_MSMC_SMS_MPAXL_B_2                                  (0x4D0u)
#define CSL_MSMC_SMS_MPAXH_B_2                                  (0x4D4u)
#define CSL_MSMC_SMS_MPAXL_B_3                                  (0x4D8u)
#define CSL_MSMC_SMS_MPAXH_B_3                                  (0x4DCu)
#define CSL_MSMC_SMS_MPAXL_B_4                                  (0x4E0u)
#define CSL_MSMC_SMS_MPAXH_B_4                                  (0x4E4u)
#define CSL_MSMC_SMS_MPAXL_B_5                                  (0x4E8u)
#define CSL_MSMC_SMS_MPAXH_B_5                                  (0x4ECu)
#define CSL_MSMC_SMS_MPAXL_B_6                                  (0x4F0u)
#define CSL_MSMC_SMS_MPAXH_B_6                                  (0x4F4u)
#define CSL_MSMC_SMS_MPAXL_B_7                                  (0x4F8u)
#define CSL_MSMC_SMS_MPAXH_B_7                                  (0x4FCu)
#define CSL_MSMC_SMS_MPAXL_C_0                                  (0x500u)
#define CSL_MSMC_SMS_MPAXH_C_0                                  (0x504u)
#define CSL_MSMC_SMS_MPAXL_C_1                                  (0x508u)
#define CSL_MSMC_SMS_MPAXH_C_1                                  (0x50Cu)
#define CSL_MSMC_SMS_MPAXL_C_2                                  (0x510u)
#define CSL_MSMC_SMS_MPAXH_C_2                                  (0x514u)
#define CSL_MSMC_SMS_MPAXL_C_3                                  (0x518u)
#define CSL_MSMC_SMS_MPAXH_C_3                                  (0x51Cu)
#define CSL_MSMC_SMS_MPAXL_C_4                                  (0x520u)
#define CSL_MSMC_SMS_MPAXH_C_4                                  (0x524u)
#define CSL_MSMC_SMS_MPAXL_C_5                                  (0x528u)
#define CSL_MSMC_SMS_MPAXH_C_5                                  (0x52Cu)
#define CSL_MSMC_SMS_MPAXL_C_6                                  (0x530u)
#define CSL_MSMC_SMS_MPAXH_C_6                                  (0x534u)
#define CSL_MSMC_SMS_MPAXL_C_7                                  (0x538u)
#define CSL_MSMC_SMS_MPAXH_C_7                                  (0x53Cu)
#define CSL_MSMC_SMS_MPAXL_D_0                                  (0x540u)
#define CSL_MSMC_SMS_MPAXH_D_0                                  (0x544u)
#define CSL_MSMC_SMS_MPAXL_D_1                                  (0x548u)
#define CSL_MSMC_SMS_MPAXH_D_1                                  (0x54Cu)
#define CSL_MSMC_SMS_MPAXL_D_2                                  (0x550u)
#define CSL_MSMC_SMS_MPAXH_D_2                                  (0x554u)
#define CSL_MSMC_SMS_MPAXL_D_3                                  (0x558u)
#define CSL_MSMC_SMS_MPAXH_D_3                                  (0x55Cu)
#define CSL_MSMC_SMS_MPAXL_D_4                                  (0x560u)
#define CSL_MSMC_SMS_MPAXH_D_4                                  (0x564u)
#define CSL_MSMC_SMS_MPAXL_D_5                                  (0x568u)
#define CSL_MSMC_SMS_MPAXH_D_5                                  (0x56Cu)
#define CSL_MSMC_SMS_MPAXL_D_6                                  (0x570u)
#define CSL_MSMC_SMS_MPAXH_D_6                                  (0x574u)
#define CSL_MSMC_SMS_MPAXL_D_7                                  (0x578u)
#define CSL_MSMC_SMS_MPAXH_D_7                                  (0x57Cu)
#define CSL_MSMC_SMS_MPAXL_E_0                                  (0x580u)
#define CSL_MSMC_SMS_MPAXH_E_0                                  (0x584u)
#define CSL_MSMC_SMS_MPAXL_E_1                                  (0x588u)
#define CSL_MSMC_SMS_MPAXH_E_1                                  (0x58Cu)
#define CSL_MSMC_SMS_MPAXL_E_2                                  (0x590u)
#define CSL_MSMC_SMS_MPAXH_E_2                                  (0x594u)
#define CSL_MSMC_SMS_MPAXL_E_3                                  (0x598u)
#define CSL_MSMC_SMS_MPAXH_E_3                                  (0x59Cu)
#define CSL_MSMC_SMS_MPAXL_E_4                                  (0x5A0u)
#define CSL_MSMC_SMS_MPAXH_E_4                                  (0x5A4u)
#define CSL_MSMC_SMS_MPAXL_E_5                                  (0x5A8u)
#define CSL_MSMC_SMS_MPAXH_E_5                                  (0x5ACu)
#define CSL_MSMC_SMS_MPAXL_E_6                                  (0x5B0u)
#define CSL_MSMC_SMS_MPAXH_E_6                                  (0x5B4u)
#define CSL_MSMC_SMS_MPAXL_E_7                                  (0x5B8u)
#define CSL_MSMC_SMS_MPAXH_E_7                                  (0x5BCu)
#define CSL_MSMC_SMS_MPAXL_F_0                                  (0x5C0u)
#define CSL_MSMC_SMS_MPAXH_F_0                                  (0x5C4u)
#define CSL_MSMC_SMS_MPAXL_F_1                                  (0x5C8u)
#define CSL_MSMC_SMS_MPAXH_F_1                                  (0x5CCu)
#define CSL_MSMC_SMS_MPAXL_F_2                                  (0x5D0u)
#define CSL_MSMC_SMS_MPAXH_F_2                                  (0x5D4u)
#define CSL_MSMC_SMS_MPAXL_F_3                                  (0x5D8u)
#define CSL_MSMC_SMS_MPAXH_F_3                                  (0x5DCu)
#define CSL_MSMC_SMS_MPAXL_F_4                                  (0x5E0u)
#define CSL_MSMC_SMS_MPAXH_F_4                                  (0x5E4u)
#define CSL_MSMC_SMS_MPAXL_F_5                                  (0x5E8u)
#define CSL_MSMC_SMS_MPAXH_F_5                                  (0x5ECu)
#define CSL_MSMC_SMS_MPAXL_F_6                                  (0x5F0u)
#define CSL_MSMC_SMS_MPAXH_F_6                                  (0x5F4u)
#define CSL_MSMC_SMS_MPAXL_F_7                                  (0x5F8u)
#define CSL_MSMC_SMS_MPAXH_F_7                                  (0x5FCu)
#define CSL_MSMC_SES_MPAXL_0_0                                  (0x600u)
#define CSL_MSMC_SES_MPAXH_0_0                                  (0x604u)
#define CSL_MSMC_SES_MPAXL_0_1                                  (0x608u)
#define CSL_MSMC_SES_MPAXH_0_1                                  (0x60Cu)
#define CSL_MSMC_SES_MPAXL_0_2                                  (0x610u)
#define CSL_MSMC_SES_MPAXH_0_2                                  (0x614u)
#define CSL_MSMC_SES_MPAXL_0_3                                  (0x618u)
#define CSL_MSMC_SES_MPAXH_0_3                                  (0x61Cu)
#define CSL_MSMC_SES_MPAXL_0_4                                  (0x620u)
#define CSL_MSMC_SES_MPAXH_0_4                                  (0x624u)
#define CSL_MSMC_SES_MPAXL_0_5                                  (0x628u)
#define CSL_MSMC_SES_MPAXH_0_5                                  (0x62Cu)
#define CSL_MSMC_SES_MPAXL_0_6                                  (0x630u)
#define CSL_MSMC_SES_MPAXH_0_6                                  (0x634u)
#define CSL_MSMC_SES_MPAXL_0_7                                  (0x638u)
#define CSL_MSMC_SES_MPAXH_0_7                                  (0x63Cu)
#define CSL_MSMC_SES_MPAXL_1_0                                  (0x640u)
#define CSL_MSMC_SES_MPAXH_1_0                                  (0x644u)
#define CSL_MSMC_SES_MPAXL_1_1                                  (0x648u)
#define CSL_MSMC_SES_MPAXH_1_1                                  (0x64Cu)
#define CSL_MSMC_SES_MPAXL_1_2                                  (0x650u)
#define CSL_MSMC_SES_MPAXH_1_2                                  (0x654u)
#define CSL_MSMC_SES_MPAXL_1_3                                  (0x658u)
#define CSL_MSMC_SES_MPAXH_1_3                                  (0x65Cu)
#define CSL_MSMC_SES_MPAXL_1_4                                  (0x660u)
#define CSL_MSMC_SES_MPAXH_1_4                                  (0x664u)
#define CSL_MSMC_SES_MPAXL_1_5                                  (0x668u)
#define CSL_MSMC_SES_MPAXH_1_5                                  (0x66Cu)
#define CSL_MSMC_SES_MPAXL_1_6                                  (0x670u)
#define CSL_MSMC_SES_MPAXH_1_6                                  (0x674u)
#define CSL_MSMC_SES_MPAXL_1_7                                  (0x678u)
#define CSL_MSMC_SES_MPAXH_1_7                                  (0x67Cu)
#define CSL_MSMC_SES_MPAXL_2_0                                  (0x680u)
#define CSL_MSMC_SES_MPAXH_2_0                                  (0x684u)
#define CSL_MSMC_SES_MPAXL_2_1                                  (0x688u)
#define CSL_MSMC_SES_MPAXH_2_1                                  (0x68Cu)
#define CSL_MSMC_SES_MPAXL_2_2                                  (0x690u)
#define CSL_MSMC_SES_MPAXH_2_2                                  (0x694u)
#define CSL_MSMC_SES_MPAXL_2_3                                  (0x698u)
#define CSL_MSMC_SES_MPAXH_2_3                                  (0x69Cu)
#define CSL_MSMC_SES_MPAXL_2_4                                  (0x6A0u)
#define CSL_MSMC_SES_MPAXH_2_4                                  (0x6A4u)
#define CSL_MSMC_SES_MPAXL_2_5                                  (0x6A8u)
#define CSL_MSMC_SES_MPAXH_2_5                                  (0x6ACu)
#define CSL_MSMC_SES_MPAXL_2_6                                  (0x6B0u)
#define CSL_MSMC_SES_MPAXH_2_6                                  (0x6B4u)
#define CSL_MSMC_SES_MPAXL_2_7                                  (0x6B8u)
#define CSL_MSMC_SES_MPAXH_2_7                                  (0x6BCu)
#define CSL_MSMC_SES_MPAXL_3_0                                  (0x6C0u)
#define CSL_MSMC_SES_MPAXH_3_0                                  (0x6C4u)
#define CSL_MSMC_SES_MPAXL_3_1                                  (0x6C8u)
#define CSL_MSMC_SES_MPAXH_3_1                                  (0x6CCu)
#define CSL_MSMC_SES_MPAXL_3_2                                  (0x6D0u)
#define CSL_MSMC_SES_MPAXH_3_2                                  (0x6D4u)
#define CSL_MSMC_SES_MPAXL_3_3                                  (0x6D8u)
#define CSL_MSMC_SES_MPAXH_3_3                                  (0x6DCu)
#define CSL_MSMC_SES_MPAXL_3_4                                  (0x6E0u)
#define CSL_MSMC_SES_MPAXH_3_4                                  (0x6E4u)
#define CSL_MSMC_SES_MPAXL_3_5                                  (0x6E8u)
#define CSL_MSMC_SES_MPAXH_3_5                                  (0x6ECu)
#define CSL_MSMC_SES_MPAXL_3_6                                  (0x6F0u)
#define CSL_MSMC_SES_MPAXH_3_6                                  (0x6F4u)
#define CSL_MSMC_SES_MPAXL_3_7                                  (0x6F8u)
#define CSL_MSMC_SES_MPAXH_3_7                                  (0x6FCu)
#define CSL_MSMC_SES_MPAXL_4_0                                  (0x700u)
#define CSL_MSMC_SES_MPAXH_4_0                                  (0x704u)
#define CSL_MSMC_SES_MPAXL_4_1                                  (0x708u)
#define CSL_MSMC_SES_MPAXH_4_1                                  (0x70Cu)
#define CSL_MSMC_SES_MPAXL_4_2                                  (0x710u)
#define CSL_MSMC_SES_MPAXH_4_2                                  (0x714u)
#define CSL_MSMC_SES_MPAXL_4_3                                  (0x718u)
#define CSL_MSMC_SES_MPAXH_4_3                                  (0x71Cu)
#define CSL_MSMC_SES_MPAXL_4_4                                  (0x720u)
#define CSL_MSMC_SES_MPAXH_4_4                                  (0x724u)
#define CSL_MSMC_SES_MPAXL_4_5                                  (0x728u)
#define CSL_MSMC_SES_MPAXH_4_5                                  (0x72Cu)
#define CSL_MSMC_SES_MPAXL_4_6                                  (0x730u)
#define CSL_MSMC_SES_MPAXH_4_6                                  (0x734u)
#define CSL_MSMC_SES_MPAXL_4_7                                  (0x738u)
#define CSL_MSMC_SES_MPAXH_4_7                                  (0x73Cu)
#define CSL_MSMC_SES_MPAXL_5_0                                  (0x740u)
#define CSL_MSMC_SES_MPAXH_5_0                                  (0x744u)
#define CSL_MSMC_SES_MPAXL_5_1                                  (0x748u)
#define CSL_MSMC_SES_MPAXH_5_1                                  (0x74Cu)
#define CSL_MSMC_SES_MPAXL_5_2                                  (0x750u)
#define CSL_MSMC_SES_MPAXH_5_2                                  (0x754u)
#define CSL_MSMC_SES_MPAXL_5_3                                  (0x758u)
#define CSL_MSMC_SES_MPAXH_5_3                                  (0x75Cu)
#define CSL_MSMC_SES_MPAXL_5_4                                  (0x760u)
#define CSL_MSMC_SES_MPAXH_5_4                                  (0x764u)
#define CSL_MSMC_SES_MPAXL_5_5                                  (0x768u)
#define CSL_MSMC_SES_MPAXH_5_5                                  (0x76Cu)
#define CSL_MSMC_SES_MPAXL_5_6                                  (0x770u)
#define CSL_MSMC_SES_MPAXH_5_6                                  (0x774u)
#define CSL_MSMC_SES_MPAXL_5_7                                  (0x778u)
#define CSL_MSMC_SES_MPAXH_5_7                                  (0x77Cu)
#define CSL_MSMC_SES_MPAXL_6_0                                  (0x780u)
#define CSL_MSMC_SES_MPAXH_6_0                                  (0x784u)
#define CSL_MSMC_SES_MPAXL_6_1                                  (0x788u)
#define CSL_MSMC_SES_MPAXH_6_1                                  (0x78Cu)
#define CSL_MSMC_SES_MPAXL_6_2                                  (0x790u)
#define CSL_MSMC_SES_MPAXH_6_2                                  (0x794u)
#define CSL_MSMC_SES_MPAXL_6_3                                  (0x798u)
#define CSL_MSMC_SES_MPAXH_6_3                                  (0x79Cu)
#define CSL_MSMC_SES_MPAXL_6_4                                  (0x7A0u)
#define CSL_MSMC_SES_MPAXH_6_4                                  (0x7A4u)
#define CSL_MSMC_SES_MPAXL_6_5                                  (0x7A8u)
#define CSL_MSMC_SES_MPAXH_6_5                                  (0x7ACu)
#define CSL_MSMC_SES_MPAXL_6_6                                  (0x7B0u)
#define CSL_MSMC_SES_MPAXH_6_6                                  (0x7B4u)
#define CSL_MSMC_SES_MPAXL_6_7                                  (0x7B8u)
#define CSL_MSMC_SES_MPAXH_6_7                                  (0x7BCu)
#define CSL_MSMC_SES_MPAXL_7_0                                  (0x7C0u)
#define CSL_MSMC_SES_MPAXH_7_0                                  (0x7C4u)
#define CSL_MSMC_SES_MPAXL_7_1                                  (0x7C8u)
#define CSL_MSMC_SES_MPAXH_7_1                                  (0x7CCu)
#define CSL_MSMC_SES_MPAXL_7_2                                  (0x7D0u)
#define CSL_MSMC_SES_MPAXH_7_2                                  (0x7D4u)
#define CSL_MSMC_SES_MPAXL_7_3                                  (0x7D8u)
#define CSL_MSMC_SES_MPAXH_7_3                                  (0x7DCu)
#define CSL_MSMC_SES_MPAXL_7_4                                  (0x7E0u)
#define CSL_MSMC_SES_MPAXH_7_4                                  (0x7E4u)
#define CSL_MSMC_SES_MPAXL_7_5                                  (0x7E8u)
#define CSL_MSMC_SES_MPAXH_7_5                                  (0x7ECu)
#define CSL_MSMC_SES_MPAXL_7_6                                  (0x7F0u)
#define CSL_MSMC_SES_MPAXH_7_6                                  (0x7F4u)
#define CSL_MSMC_SES_MPAXL_7_7                                  (0x7F8u)
#define CSL_MSMC_SES_MPAXH_7_7                                  (0x7FCu)
#define CSL_MSMC_SES_MPAXL_8_0                                  (0x800u)
#define CSL_MSMC_SES_MPAXH_8_0                                  (0x804u)
#define CSL_MSMC_SES_MPAXL_8_1                                  (0x808u)
#define CSL_MSMC_SES_MPAXH_8_1                                  (0x80Cu)
#define CSL_MSMC_SES_MPAXL_8_2                                  (0x810u)
#define CSL_MSMC_SES_MPAXH_8_2                                  (0x814u)
#define CSL_MSMC_SES_MPAXL_8_3                                  (0x818u)
#define CSL_MSMC_SES_MPAXH_8_3                                  (0x81Cu)
#define CSL_MSMC_SES_MPAXL_8_4                                  (0x820u)
#define CSL_MSMC_SES_MPAXH_8_4                                  (0x824u)
#define CSL_MSMC_SES_MPAXL_8_5                                  (0x828u)
#define CSL_MSMC_SES_MPAXH_8_5                                  (0x82Cu)
#define CSL_MSMC_SES_MPAXL_8_6                                  (0x830u)
#define CSL_MSMC_SES_MPAXH_8_6                                  (0x834u)
#define CSL_MSMC_SES_MPAXL_8_7                                  (0x838u)
#define CSL_MSMC_SES_MPAXH_8_7                                  (0x83Cu)
#define CSL_MSMC_SES_MPAXL_9_0                                  (0x840u)
#define CSL_MSMC_SES_MPAXH_9_0                                  (0x844u)
#define CSL_MSMC_SES_MPAXL_9_1                                  (0x848u)
#define CSL_MSMC_SES_MPAXH_9_1                                  (0x84Cu)
#define CSL_MSMC_SES_MPAXL_9_2                                  (0x850u)
#define CSL_MSMC_SES_MPAXH_9_2                                  (0x854u)
#define CSL_MSMC_SES_MPAXL_9_3                                  (0x858u)
#define CSL_MSMC_SES_MPAXH_9_3                                  (0x85Cu)
#define CSL_MSMC_SES_MPAXL_9_4                                  (0x860u)
#define CSL_MSMC_SES_MPAXH_9_4                                  (0x864u)
#define CSL_MSMC_SES_MPAXL_9_5                                  (0x868u)
#define CSL_MSMC_SES_MPAXH_9_5                                  (0x86Cu)
#define CSL_MSMC_SES_MPAXL_9_6                                  (0x870u)
#define CSL_MSMC_SES_MPAXH_9_6                                  (0x874u)
#define CSL_MSMC_SES_MPAXL_9_7                                  (0x878u)
#define CSL_MSMC_SES_MPAXH_9_7                                  (0x87Cu)
#define CSL_MSMC_SES_MPAXL_A_0                                  (0x880u)
#define CSL_MSMC_SES_MPAXH_A_0                                  (0x884u)
#define CSL_MSMC_SES_MPAXL_A_1                                  (0x888u)
#define CSL_MSMC_SES_MPAXH_A_1                                  (0x88Cu)
#define CSL_MSMC_SES_MPAXL_A_2                                  (0x890u)
#define CSL_MSMC_SES_MPAXH_A_2                                  (0x894u)
#define CSL_MSMC_SES_MPAXL_A_3                                  (0x898u)
#define CSL_MSMC_SES_MPAXH_A_3                                  (0x89Cu)
#define CSL_MSMC_SES_MPAXL_A_4                                  (0x8A0u)
#define CSL_MSMC_SES_MPAXH_A_4                                  (0x8A4u)
#define CSL_MSMC_SES_MPAXL_A_5                                  (0x8A8u)
#define CSL_MSMC_SES_MPAXH_A_5                                  (0x8ACu)
#define CSL_MSMC_SES_MPAXL_A_6                                  (0x8B0u)
#define CSL_MSMC_SES_MPAXH_A_6                                  (0x8B4u)
#define CSL_MSMC_SES_MPAXL_A_7                                  (0x8B8u)
#define CSL_MSMC_SES_MPAXH_A_7                                  (0x8BCu)
#define CSL_MSMC_SES_MPAXL_B_0                                  (0x8C0u)
#define CSL_MSMC_SES_MPAXH_B_0                                  (0x8C4u)
#define CSL_MSMC_SES_MPAXL_B_1                                  (0x8C8u)
#define CSL_MSMC_SES_MPAXH_B_1                                  (0x8CCu)
#define CSL_MSMC_SES_MPAXL_B_2                                  (0x8D0u)
#define CSL_MSMC_SES_MPAXH_B_2                                  (0x8D4u)
#define CSL_MSMC_SES_MPAXL_B_3                                  (0x8D8u)
#define CSL_MSMC_SES_MPAXH_B_3                                  (0x8DCu)
#define CSL_MSMC_SES_MPAXL_B_4                                  (0x8E0u)
#define CSL_MSMC_SES_MPAXH_B_4                                  (0x8E4u)
#define CSL_MSMC_SES_MPAXL_B_5                                  (0x8E8u)
#define CSL_MSMC_SES_MPAXH_B_5                                  (0x8ECu)
#define CSL_MSMC_SES_MPAXL_B_6                                  (0x8F0u)
#define CSL_MSMC_SES_MPAXH_B_6                                  (0x8F4u)
#define CSL_MSMC_SES_MPAXL_B_7                                  (0x8F8u)
#define CSL_MSMC_SES_MPAXH_B_7                                  (0x8FCu)
#define CSL_MSMC_SES_MPAXL_C_0                                  (0x900u)
#define CSL_MSMC_SES_MPAXH_C_0                                  (0x904u)
#define CSL_MSMC_SES_MPAXL_C_1                                  (0x908u)
#define CSL_MSMC_SES_MPAXH_C_1                                  (0x90Cu)
#define CSL_MSMC_SES_MPAXL_C_2                                  (0x910u)
#define CSL_MSMC_SES_MPAXH_C_2                                  (0x914u)
#define CSL_MSMC_SES_MPAXL_C_3                                  (0x918u)
#define CSL_MSMC_SES_MPAXH_C_3                                  (0x91Cu)
#define CSL_MSMC_SES_MPAXL_C_4                                  (0x920u)
#define CSL_MSMC_SES_MPAXH_C_4                                  (0x924u)
#define CSL_MSMC_SES_MPAXL_C_5                                  (0x928u)
#define CSL_MSMC_SES_MPAXH_C_5                                  (0x92Cu)
#define CSL_MSMC_SES_MPAXL_C_6                                  (0x930u)
#define CSL_MSMC_SES_MPAXH_C_6                                  (0x934u)
#define CSL_MSMC_SES_MPAXL_C_7                                  (0x938u)
#define CSL_MSMC_SES_MPAXH_C_7                                  (0x93Cu)
#define CSL_MSMC_SES_MPAXL_D_0                                  (0x940u)
#define CSL_MSMC_SES_MPAXH_D_0                                  (0x944u)
#define CSL_MSMC_SES_MPAXL_D_1                                  (0x948u)
#define CSL_MSMC_SES_MPAXH_D_1                                  (0x94Cu)
#define CSL_MSMC_SES_MPAXL_D_2                                  (0x950u)
#define CSL_MSMC_SES_MPAXH_D_2                                  (0x954u)
#define CSL_MSMC_SES_MPAXL_D_3                                  (0x958u)
#define CSL_MSMC_SES_MPAXH_D_3                                  (0x95Cu)
#define CSL_MSMC_SES_MPAXL_D_4                                  (0x960u)
#define CSL_MSMC_SES_MPAXH_D_4                                  (0x964u)
#define CSL_MSMC_SES_MPAXL_D_5                                  (0x968u)
#define CSL_MSMC_SES_MPAXH_D_5                                  (0x96Cu)
#define CSL_MSMC_SES_MPAXL_D_6                                  (0x970u)
#define CSL_MSMC_SES_MPAXH_D_6                                  (0x974u)
#define CSL_MSMC_SES_MPAXL_D_7                                  (0x978u)
#define CSL_MSMC_SES_MPAXH_D_7                                  (0x97Cu)
#define CSL_MSMC_SES_MPAXL_E_0                                  (0x980u)
#define CSL_MSMC_SES_MPAXH_E_0                                  (0x984u)
#define CSL_MSMC_SES_MPAXL_E_1                                  (0x988u)
#define CSL_MSMC_SES_MPAXH_E_1                                  (0x98Cu)
#define CSL_MSMC_SES_MPAXL_E_2                                  (0x990u)
#define CSL_MSMC_SES_MPAXH_E_2                                  (0x994u)
#define CSL_MSMC_SES_MPAXL_E_3                                  (0x998u)
#define CSL_MSMC_SES_MPAXH_E_3                                  (0x99Cu)
#define CSL_MSMC_SES_MPAXL_E_4                                  (0x9A0u)
#define CSL_MSMC_SES_MPAXH_E_4                                  (0x9A4u)
#define CSL_MSMC_SES_MPAXL_E_5                                  (0x9A8u)
#define CSL_MSMC_SES_MPAXH_E_5                                  (0x9ACu)
#define CSL_MSMC_SES_MPAXL_E_6                                  (0x9B0u)
#define CSL_MSMC_SES_MPAXH_E_6                                  (0x9B4u)
#define CSL_MSMC_SES_MPAXL_E_7                                  (0x9B8u)
#define CSL_MSMC_SES_MPAXH_E_7                                  (0x9BCu)
#define CSL_MSMC_SES_MPAXL_F_0                                  (0x9C0u)
#define CSL_MSMC_SES_MPAXH_F_0                                  (0x9C4u)
#define CSL_MSMC_SES_MPAXL_F_1                                  (0x9C8u)
#define CSL_MSMC_SES_MPAXH_F_1                                  (0x9CCu)
#define CSL_MSMC_SES_MPAXL_F_2                                  (0x9D0u)
#define CSL_MSMC_SES_MPAXH_F_2                                  (0x9D4u)
#define CSL_MSMC_SES_MPAXL_F_3                                  (0x9D8u)
#define CSL_MSMC_SES_MPAXH_F_3                                  (0x9DCu)
#define CSL_MSMC_SES_MPAXL_F_4                                  (0x9E0u)
#define CSL_MSMC_SES_MPAXH_F_4                                  (0x9E4u)
#define CSL_MSMC_SES_MPAXL_F_5                                  (0x9E8u)
#define CSL_MSMC_SES_MPAXH_F_5                                  (0x9ECu)
#define CSL_MSMC_SES_MPAXL_F_6                                  (0x9F0u)
#define CSL_MSMC_SES_MPAXH_F_6                                  (0x9F4u)
#define CSL_MSMC_SES_MPAXL_F_7                                  (0x9F8u)
#define CSL_MSMC_SES_MPAXH_F_7                                  (0x9FCu)
#define CSL_MSMC_SMCFG                                          (0xC0u)
#define CSL_MSMC_SMNCERRAR                                      (0xC4u)
#define CSL_MSMC_SMNCERRXR                                      (0xC8u)
#define CSL_MSMC_SMNCEA                                         (0xCCu)
#define CSL_MSMC_SMSECIL                                        (0xE0u)
#define CSL_MSMC_SMSECIH                                        (0xE4u)
#define CSL_MSMC_SMSECEL                                        (0xE8u)
#define CSL_MSMC_SMSECEH                                        (0xECu)
#define CSL_MSMC_SGSECIL                                        (0xF0u)
#define CSL_MSMC_SGSECIH                                        (0xF4u)
#define CSL_MSMC_SGSECEL                                        (0xF8u)
#define CSL_MSMC_SGSECEH                                        (0xFCu)
#define CSL_MSMC_COHSTAT                                        (0x100u)
#define CSL_MSMC_COHCTRL                                        (0x104u)
#define CSL_MSMC_SBND(i)                                        (0x30u + (i * 4u))



/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* SMS_MPAXL_0 */

#define CSL_MSMC_SMS_MPAXL_0_UX_MASK     (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_0_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SMS_MPAXL_0_UX_RESETVAL (0x00000001u)

#define CSL_MSMC_SMS_MPAXL_0_UW_MASK     (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_0_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_0_UW_RESETVAL (0x00000001u)

#define CSL_MSMC_SMS_MPAXL_0_UR_MASK     (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_0_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_0_UR_RESETVAL (0x00000001u)

#define CSL_MSMC_SMS_MPAXL_0_SX_MASK     (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_0_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SMS_MPAXL_0_SX_RESETVAL (0x00000001u)

#define CSL_MSMC_SMS_MPAXL_0_SW_MASK     (0x00000010u)
#define CSL_MSMC_SMS_MPAXL_0_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_0_SW_RESETVAL (0x00000001u)

#define CSL_MSMC_SMS_MPAXL_0_SR_MASK     (0x00000020u)
#define CSL_MSMC_SMS_MPAXL_0_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SMS_MPAXL_0_SR_RESETVAL (0x00000001u)



#define CSL_MSMC_SMS_MPAXL_0_RADDR_MASK  (0x000FFF00u)
#define CSL_MSMC_SMS_MPAXL_0_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_0_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_0__CNST_MASK  (0x0FF00000u)
#define CSL_MSMC_SMS_MPAXL_0__CNST_SHIFT (0x00000014u)
#define CSL_MSMC_SMS_MPAXL_0__CNST_RESETVAL (0x0000000Cu)


#define CSL_MSMC_SMS_MPAXL_0_RESETVAL    (0x00C000BFu)

/* SMS_MPAXH_0 */

#define CSL_MSMC_SMS_MPAXH_0_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SMS_MPAXH_0_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SMS_MPAXH_0_SEGSZ_RESETVAL (0x00000017u)


#define CSL_MSMC_SMS_MPAXH_0_BADDR_MASK  (0x00FFF000u)
#define CSL_MSMC_SMS_MPAXH_0_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SMS_MPAXH_0_BADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXH_0__CNST_MASK  (0xFF000000u)
#define CSL_MSMC_SMS_MPAXH_0__CNST_SHIFT (0x00000018u)
#define CSL_MSMC_SMS_MPAXH_0__CNST_RESETVAL (0x0000000Cu)

#define CSL_MSMC_SMS_MPAXH_0_RESETVAL    (0x0C000017u)

/* SMS_MPAXL_1 */

#define CSL_MSMC_SMS_MPAXL_1_UX_MASK     (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_1_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SMS_MPAXL_1_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_1_UW_MASK     (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_1_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_1_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_1_UR_MASK     (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_1_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_1_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_1_SX_MASK     (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_1_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SMS_MPAXL_1_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_1_SW_MASK     (0x00000010u)
#define CSL_MSMC_SMS_MPAXL_1_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_1_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_1_SR_MASK     (0x00000020u)
#define CSL_MSMC_SMS_MPAXL_1_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SMS_MPAXL_1_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SMS_MPAXL_1_RADDR_MASK  (0x000FFF00u)
#define CSL_MSMC_SMS_MPAXL_1_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_1_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_1__CNST_MASK  (0x0FF00000u)
#define CSL_MSMC_SMS_MPAXL_1__CNST_SHIFT (0x00000014u)
#define CSL_MSMC_SMS_MPAXL_1__CNST_RESETVAL (0x0000000Cu)


#define CSL_MSMC_SMS_MPAXL_1_RESETVAL    (0x00C00000u)

/* SMS_MPAXH_1 */

#define CSL_MSMC_SMS_MPAXH_1_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SMS_MPAXH_1_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SMS_MPAXH_1_SEGSZ_RESETVAL (0x00000000u)


#define CSL_MSMC_SMS_MPAXH_1_BADDR_MASK  (0x00FFF000u)
#define CSL_MSMC_SMS_MPAXH_1_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SMS_MPAXH_1_BADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXH_1__CNST_MASK  (0xFF000000u)
#define CSL_MSMC_SMS_MPAXH_1__CNST_SHIFT (0x00000018u)
#define CSL_MSMC_SMS_MPAXH_1__CNST_RESETVAL (0x0000000Cu)

#define CSL_MSMC_SMS_MPAXH_1_RESETVAL    (0x0C000000u)

/* SMS_MPAXL_2 */

#define CSL_MSMC_SMS_MPAXL_2_UX_MASK     (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_2_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SMS_MPAXL_2_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_2_UW_MASK     (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_2_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_2_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_2_UR_MASK     (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_2_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_2_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_2_SX_MASK     (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_2_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SMS_MPAXL_2_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_2_SW_MASK     (0x00000010u)
#define CSL_MSMC_SMS_MPAXL_2_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_2_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_2_SR_MASK     (0x00000020u)
#define CSL_MSMC_SMS_MPAXL_2_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SMS_MPAXL_2_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SMS_MPAXL_2_RADDR_MASK  (0x000FFF00u)
#define CSL_MSMC_SMS_MPAXL_2_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_2_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_2__CNST_MASK  (0x0FF00000u)
#define CSL_MSMC_SMS_MPAXL_2__CNST_SHIFT (0x00000014u)
#define CSL_MSMC_SMS_MPAXL_2__CNST_RESETVAL (0x0000000Cu)


#define CSL_MSMC_SMS_MPAXL_2_RESETVAL    (0x00C00000u)

/* SMS_MPAXH_2 */

#define CSL_MSMC_SMS_MPAXH_2_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SMS_MPAXH_2_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SMS_MPAXH_2_SEGSZ_RESETVAL (0x00000000u)


#define CSL_MSMC_SMS_MPAXH_2_BADDR_MASK  (0x00FFF000u)
#define CSL_MSMC_SMS_MPAXH_2_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SMS_MPAXH_2_BADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXH_2__CNST_MASK  (0xFF000000u)
#define CSL_MSMC_SMS_MPAXH_2__CNST_SHIFT (0x00000018u)
#define CSL_MSMC_SMS_MPAXH_2__CNST_RESETVAL (0x0000000Cu)

#define CSL_MSMC_SMS_MPAXH_2_RESETVAL    (0x0C000000u)

/* SMS_MPAXL_3 */

#define CSL_MSMC_SMS_MPAXL_3_UX_MASK     (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_3_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SMS_MPAXL_3_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_3_UW_MASK     (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_3_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_3_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_3_UR_MASK     (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_3_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_3_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_3_SX_MASK     (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_3_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SMS_MPAXL_3_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_3_SW_MASK     (0x00000010u)
#define CSL_MSMC_SMS_MPAXL_3_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_3_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_3_SR_MASK     (0x00000020u)
#define CSL_MSMC_SMS_MPAXL_3_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SMS_MPAXL_3_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SMS_MPAXL_3_RADDR_MASK  (0x000FFF00u)
#define CSL_MSMC_SMS_MPAXL_3_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_3_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_3__CNST_MASK  (0x0FF00000u)
#define CSL_MSMC_SMS_MPAXL_3__CNST_SHIFT (0x00000014u)
#define CSL_MSMC_SMS_MPAXL_3__CNST_RESETVAL (0x0000000Cu)


#define CSL_MSMC_SMS_MPAXL_3_RESETVAL    (0x00C00000u)

/* SMS_MPAXH_3 */

#define CSL_MSMC_SMS_MPAXH_3_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SMS_MPAXH_3_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SMS_MPAXH_3_SEGSZ_RESETVAL (0x00000000u)


#define CSL_MSMC_SMS_MPAXH_3_BADDR_MASK  (0x00FFF000u)
#define CSL_MSMC_SMS_MPAXH_3_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SMS_MPAXH_3_BADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXH_3__CNST_MASK  (0xFF000000u)
#define CSL_MSMC_SMS_MPAXH_3__CNST_SHIFT (0x00000018u)
#define CSL_MSMC_SMS_MPAXH_3__CNST_RESETVAL (0x0000000Cu)

#define CSL_MSMC_SMS_MPAXH_3_RESETVAL    (0x0C000000u)

/* SMS_MPAXL_4 */

#define CSL_MSMC_SMS_MPAXL_4_UX_MASK     (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_4_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SMS_MPAXL_4_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_4_UW_MASK     (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_4_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_4_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_4_UR_MASK     (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_4_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_4_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_4_SX_MASK     (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_4_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SMS_MPAXL_4_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_4_SW_MASK     (0x00000010u)
#define CSL_MSMC_SMS_MPAXL_4_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_4_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_4_SR_MASK     (0x00000020u)
#define CSL_MSMC_SMS_MPAXL_4_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SMS_MPAXL_4_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SMS_MPAXL_4_RADDR_MASK  (0x000FFF00u)
#define CSL_MSMC_SMS_MPAXL_4_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_4_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_4__CNST_MASK  (0x0FF00000u)
#define CSL_MSMC_SMS_MPAXL_4__CNST_SHIFT (0x00000014u)
#define CSL_MSMC_SMS_MPAXL_4__CNST_RESETVAL (0x0000000Cu)


#define CSL_MSMC_SMS_MPAXL_4_RESETVAL    (0x00C00000u)

/* SMS_MPAXH_4 */

#define CSL_MSMC_SMS_MPAXH_4_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SMS_MPAXH_4_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SMS_MPAXH_4_SEGSZ_RESETVAL (0x00000000u)


#define CSL_MSMC_SMS_MPAXH_4_BADDR_MASK  (0x00FFF000u)
#define CSL_MSMC_SMS_MPAXH_4_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SMS_MPAXH_4_BADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXH_4__CNST_MASK  (0xFF000000u)
#define CSL_MSMC_SMS_MPAXH_4__CNST_SHIFT (0x00000018u)
#define CSL_MSMC_SMS_MPAXH_4__CNST_RESETVAL (0x0000000Cu)

#define CSL_MSMC_SMS_MPAXH_4_RESETVAL    (0x0C000000u)

/* SMS_MPAXL_5 */

#define CSL_MSMC_SMS_MPAXL_5_UX_MASK     (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_5_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SMS_MPAXL_5_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_5_UW_MASK     (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_5_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_5_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_5_UR_MASK     (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_5_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_5_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_5_SX_MASK     (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_5_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SMS_MPAXL_5_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_5_SW_MASK     (0x00000010u)
#define CSL_MSMC_SMS_MPAXL_5_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_5_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_5_SR_MASK     (0x00000020u)
#define CSL_MSMC_SMS_MPAXL_5_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SMS_MPAXL_5_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SMS_MPAXL_5_RADDR_MASK  (0x000FFF00u)
#define CSL_MSMC_SMS_MPAXL_5_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_5_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_5__CNST_MASK  (0x0FF00000u)
#define CSL_MSMC_SMS_MPAXL_5__CNST_SHIFT (0x00000014u)
#define CSL_MSMC_SMS_MPAXL_5__CNST_RESETVAL (0x0000000Cu)


#define CSL_MSMC_SMS_MPAXL_5_RESETVAL    (0x00C00000u)

/* SMS_MPAXH_5 */

#define CSL_MSMC_SMS_MPAXH_5_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SMS_MPAXH_5_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SMS_MPAXH_5_SEGSZ_RESETVAL (0x00000000u)


#define CSL_MSMC_SMS_MPAXH_5_BADDR_MASK  (0x00FFF000u)
#define CSL_MSMC_SMS_MPAXH_5_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SMS_MPAXH_5_BADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXH_5__CNST_MASK  (0xFF000000u)
#define CSL_MSMC_SMS_MPAXH_5__CNST_SHIFT (0x00000018u)
#define CSL_MSMC_SMS_MPAXH_5__CNST_RESETVAL (0x0000000Cu)

#define CSL_MSMC_SMS_MPAXH_5_RESETVAL    (0x0C000000u)

/* SMS_MPAXL_6 */

#define CSL_MSMC_SMS_MPAXL_6_UX_MASK     (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_6_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SMS_MPAXL_6_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_6_UW_MASK     (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_6_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_6_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_6_UR_MASK     (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_6_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_6_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_6_SX_MASK     (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_6_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SMS_MPAXL_6_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_6_SW_MASK     (0x00000010u)
#define CSL_MSMC_SMS_MPAXL_6_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_6_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_6_SR_MASK     (0x00000020u)
#define CSL_MSMC_SMS_MPAXL_6_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SMS_MPAXL_6_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SMS_MPAXL_6_RADDR_MASK  (0x000FFF00u)
#define CSL_MSMC_SMS_MPAXL_6_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_6_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_6__CNST_MASK  (0x0FF00000u)
#define CSL_MSMC_SMS_MPAXL_6__CNST_SHIFT (0x00000014u)
#define CSL_MSMC_SMS_MPAXL_6__CNST_RESETVAL (0x0000000Cu)


#define CSL_MSMC_SMS_MPAXL_6_RESETVAL    (0x00C00000u)

/* SMS_MPAXH_6 */

#define CSL_MSMC_SMS_MPAXH_6_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SMS_MPAXH_6_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SMS_MPAXH_6_SEGSZ_RESETVAL (0x00000000u)


#define CSL_MSMC_SMS_MPAXH_6_BADDR_MASK  (0x00FFF000u)
#define CSL_MSMC_SMS_MPAXH_6_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SMS_MPAXH_6_BADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXH_6__CNST_MASK  (0xFF000000u)
#define CSL_MSMC_SMS_MPAXH_6__CNST_SHIFT (0x00000018u)
#define CSL_MSMC_SMS_MPAXH_6__CNST_RESETVAL (0x0000000Cu)

#define CSL_MSMC_SMS_MPAXH_6_RESETVAL    (0x0C000000u)

/* SMS_MPAXL_7 */

#define CSL_MSMC_SMS_MPAXL_7_UX_MASK     (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_7_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SMS_MPAXL_7_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_7_UW_MASK     (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_7_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SMS_MPAXL_7_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_7_UR_MASK     (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_7_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SMS_MPAXL_7_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_7_SX_MASK     (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_7_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SMS_MPAXL_7_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_7_SW_MASK     (0x00000010u)
#define CSL_MSMC_SMS_MPAXL_7_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SMS_MPAXL_7_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_7_SR_MASK     (0x00000020u)
#define CSL_MSMC_SMS_MPAXL_7_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SMS_MPAXL_7_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SMS_MPAXL_7_RADDR_MASK  (0x000FFF00u)
#define CSL_MSMC_SMS_MPAXL_7_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SMS_MPAXL_7_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXL_7__CNST_MASK  (0x0FF00000u)
#define CSL_MSMC_SMS_MPAXL_7__CNST_SHIFT (0x00000014u)
#define CSL_MSMC_SMS_MPAXL_7__CNST_RESETVAL (0x0000000Cu)


#define CSL_MSMC_SMS_MPAXL_7_RESETVAL    (0x00C00000u)

/* SMS_MPAXH_7 */

#define CSL_MSMC_SMS_MPAXH_7_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SMS_MPAXH_7_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SMS_MPAXH_7_SEGSZ_RESETVAL (0x00000000u)


#define CSL_MSMC_SMS_MPAXH_7_BADDR_MASK  (0x00FFF000u)
#define CSL_MSMC_SMS_MPAXH_7_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SMS_MPAXH_7_BADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAXH_7__CNST_MASK  (0xFF000000u)
#define CSL_MSMC_SMS_MPAXH_7__CNST_SHIFT (0x00000018u)
#define CSL_MSMC_SMS_MPAXH_7__CNST_RESETVAL (0x0000000Cu)

#define CSL_MSMC_SMS_MPAXH_7_RESETVAL    (0x0C000000u)

/* SES_MPAXL_0 */

#define CSL_MSMC_SES_MPAXL_0_UX_MASK     (0x00000001u)
#define CSL_MSMC_SES_MPAXL_0_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SES_MPAXL_0_UX_RESETVAL (0x00000001u)

#define CSL_MSMC_SES_MPAXL_0_UW_MASK     (0x00000002u)
#define CSL_MSMC_SES_MPAXL_0_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SES_MPAXL_0_UW_RESETVAL (0x00000001u)

#define CSL_MSMC_SES_MPAXL_0_UR_MASK     (0x00000004u)
#define CSL_MSMC_SES_MPAXL_0_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SES_MPAXL_0_UR_RESETVAL (0x00000001u)

#define CSL_MSMC_SES_MPAXL_0_SX_MASK     (0x00000008u)
#define CSL_MSMC_SES_MPAXL_0_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SES_MPAXL_0_SX_RESETVAL (0x00000001u)

#define CSL_MSMC_SES_MPAXL_0_SW_MASK     (0x00000010u)
#define CSL_MSMC_SES_MPAXL_0_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SES_MPAXL_0_SW_RESETVAL (0x00000001u)

#define CSL_MSMC_SES_MPAXL_0_SR_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXL_0_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXL_0_SR_RESETVAL (0x00000001u)



#define CSL_MSMC_SES_MPAXL_0_RADDR_MASK  (0xFFFFFF00u)
#define CSL_MSMC_SES_MPAXL_0_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SES_MPAXL_0_RADDR_RESETVAL (0x00800000u)

#define CSL_MSMC_SES_MPAXL_0_RESETVAL    (0x800000BFu)

/* SES_MPAXH_0 */

#define CSL_MSMC_SES_MPAXH_0_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SES_MPAXH_0_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SES_MPAXH_0_SEGSZ_RESETVAL (0x0000001Eu)

#define CSL_MSMC_SES_MPAXH_0_AI_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXH_0_AI_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXH_0_AI_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_0_BE_MASK     (0x00000040u)
#define CSL_MSMC_SES_MPAXH_0_BE_SHIFT    (0x00000006u)
#define CSL_MSMC_SES_MPAXH_0_BE_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_0_BADDR_MASK  (0xFFFFF000u)
#define CSL_MSMC_SES_MPAXH_0_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SES_MPAXH_0_BADDR_RESETVAL (0x00080000u)


#define CSL_MSMC_SES_MPAXH_0_RESETVAL    (0x8000001Eu)

/* SES_MPAXL_1 */

#define CSL_MSMC_SES_MPAXL_1_UX_MASK     (0x00000001u)
#define CSL_MSMC_SES_MPAXL_1_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SES_MPAXL_1_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_1_UW_MASK     (0x00000002u)
#define CSL_MSMC_SES_MPAXL_1_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SES_MPAXL_1_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_1_UR_MASK     (0x00000004u)
#define CSL_MSMC_SES_MPAXL_1_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SES_MPAXL_1_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_1_SX_MASK     (0x00000008u)
#define CSL_MSMC_SES_MPAXL_1_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SES_MPAXL_1_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_1_SW_MASK     (0x00000010u)
#define CSL_MSMC_SES_MPAXL_1_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SES_MPAXL_1_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_1_SR_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXL_1_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXL_1_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SES_MPAXL_1_RADDR_MASK  (0xFFFFFF00u)
#define CSL_MSMC_SES_MPAXL_1_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SES_MPAXL_1_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_1_RESETVAL    (0x00000000u)

/* SES_MPAXH_1 */

#define CSL_MSMC_SES_MPAXH_1_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SES_MPAXH_1_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SES_MPAXH_1_SEGSZ_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_1_AI_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXH_1_AI_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXH_1_AI_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_1_BE_MASK     (0x00000040u)
#define CSL_MSMC_SES_MPAXH_1_BE_SHIFT    (0x00000006u)
#define CSL_MSMC_SES_MPAXH_1_BE_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_1_BADDR_MASK  (0xFFFFF000u)
#define CSL_MSMC_SES_MPAXH_1_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SES_MPAXH_1_BADDR_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_1_RESETVAL    (0x00000000u)

/* SES_MPAXL_2 */

#define CSL_MSMC_SES_MPAXL_2_UX_MASK     (0x00000001u)
#define CSL_MSMC_SES_MPAXL_2_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SES_MPAXL_2_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_2_UW_MASK     (0x00000002u)
#define CSL_MSMC_SES_MPAXL_2_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SES_MPAXL_2_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_2_UR_MASK     (0x00000004u)
#define CSL_MSMC_SES_MPAXL_2_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SES_MPAXL_2_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_2_SX_MASK     (0x00000008u)
#define CSL_MSMC_SES_MPAXL_2_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SES_MPAXL_2_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_2_SW_MASK     (0x00000010u)
#define CSL_MSMC_SES_MPAXL_2_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SES_MPAXL_2_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_2_SR_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXL_2_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXL_2_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SES_MPAXL_2_RADDR_MASK  (0xFFFFFF00u)
#define CSL_MSMC_SES_MPAXL_2_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SES_MPAXL_2_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_2_RESETVAL    (0x00000000u)

/* SES_MPAXH_2 */

#define CSL_MSMC_SES_MPAXH_2_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SES_MPAXH_2_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SES_MPAXH_2_SEGSZ_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_2_AI_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXH_2_AI_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXH_2_AI_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_2_BE_MASK     (0x00000040u)
#define CSL_MSMC_SES_MPAXH_2_BE_SHIFT    (0x00000006u)
#define CSL_MSMC_SES_MPAXH_2_BE_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_2_BADDR_MASK  (0xFFFFF000u)
#define CSL_MSMC_SES_MPAXH_2_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SES_MPAXH_2_BADDR_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_2_RESETVAL    (0x00000000u)

/* SES_MPAXL_3 */

#define CSL_MSMC_SES_MPAXL_3_UX_MASK     (0x00000001u)
#define CSL_MSMC_SES_MPAXL_3_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SES_MPAXL_3_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_3_UW_MASK     (0x00000002u)
#define CSL_MSMC_SES_MPAXL_3_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SES_MPAXL_3_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_3_UR_MASK     (0x00000004u)
#define CSL_MSMC_SES_MPAXL_3_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SES_MPAXL_3_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_3_SX_MASK     (0x00000008u)
#define CSL_MSMC_SES_MPAXL_3_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SES_MPAXL_3_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_3_SW_MASK     (0x00000010u)
#define CSL_MSMC_SES_MPAXL_3_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SES_MPAXL_3_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_3_SR_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXL_3_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXL_3_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SES_MPAXL_3_RADDR_MASK  (0xFFFFFF00u)
#define CSL_MSMC_SES_MPAXL_3_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SES_MPAXL_3_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_3_RESETVAL    (0x00000000u)

/* SES_MPAXH_3 */

#define CSL_MSMC_SES_MPAXH_3_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SES_MPAXH_3_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SES_MPAXH_3_SEGSZ_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_3_AI_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXH_3_AI_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXH_3_AI_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_3_BE_MASK     (0x00000040u)
#define CSL_MSMC_SES_MPAXH_3_BE_SHIFT    (0x00000006u)
#define CSL_MSMC_SES_MPAXH_3_BE_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_3_BADDR_MASK  (0xFFFFF000u)
#define CSL_MSMC_SES_MPAXH_3_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SES_MPAXH_3_BADDR_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_3_RESETVAL    (0x00000000u)

/* SES_MPAXL_4 */

#define CSL_MSMC_SES_MPAXL_4_UX_MASK     (0x00000001u)
#define CSL_MSMC_SES_MPAXL_4_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SES_MPAXL_4_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_4_UW_MASK     (0x00000002u)
#define CSL_MSMC_SES_MPAXL_4_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SES_MPAXL_4_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_4_UR_MASK     (0x00000004u)
#define CSL_MSMC_SES_MPAXL_4_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SES_MPAXL_4_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_4_SX_MASK     (0x00000008u)
#define CSL_MSMC_SES_MPAXL_4_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SES_MPAXL_4_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_4_SW_MASK     (0x00000010u)
#define CSL_MSMC_SES_MPAXL_4_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SES_MPAXL_4_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_4_SR_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXL_4_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXL_4_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SES_MPAXL_4_RADDR_MASK  (0xFFFFFF00u)
#define CSL_MSMC_SES_MPAXL_4_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SES_MPAXL_4_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_4_RESETVAL    (0x00000000u)

/* SES_MPAXH_4 */

#define CSL_MSMC_SES_MPAXH_4_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SES_MPAXH_4_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SES_MPAXH_4_SEGSZ_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_4_AI_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXH_4_AI_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXH_4_AI_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_4_BE_MASK     (0x00000040u)
#define CSL_MSMC_SES_MPAXH_4_BE_SHIFT    (0x00000006u)
#define CSL_MSMC_SES_MPAXH_4_BE_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_4_BADDR_MASK  (0xFFFFF000u)
#define CSL_MSMC_SES_MPAXH_4_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SES_MPAXH_4_BADDR_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_4_RESETVAL    (0x00000000u)

/* SES_MPAXL_5 */

#define CSL_MSMC_SES_MPAXL_5_UX_MASK     (0x00000001u)
#define CSL_MSMC_SES_MPAXL_5_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SES_MPAXL_5_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_5_UW_MASK     (0x00000002u)
#define CSL_MSMC_SES_MPAXL_5_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SES_MPAXL_5_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_5_UR_MASK     (0x00000004u)
#define CSL_MSMC_SES_MPAXL_5_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SES_MPAXL_5_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_5_SX_MASK     (0x00000008u)
#define CSL_MSMC_SES_MPAXL_5_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SES_MPAXL_5_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_5_SW_MASK     (0x00000010u)
#define CSL_MSMC_SES_MPAXL_5_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SES_MPAXL_5_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_5_SR_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXL_5_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXL_5_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SES_MPAXL_5_RADDR_MASK  (0xFFFFFF00u)
#define CSL_MSMC_SES_MPAXL_5_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SES_MPAXL_5_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_5_RESETVAL    (0x00000000u)

/* SES_MPAXH_5 */

#define CSL_MSMC_SES_MPAXH_5_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SES_MPAXH_5_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SES_MPAXH_5_SEGSZ_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_5_AI_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXH_5_AI_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXH_5_AI_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_5_BE_MASK     (0x00000040u)
#define CSL_MSMC_SES_MPAXH_5_BE_SHIFT    (0x00000006u)
#define CSL_MSMC_SES_MPAXH_5_BE_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_5_BADDR_MASK  (0xFFFFF000u)
#define CSL_MSMC_SES_MPAXH_5_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SES_MPAXH_5_BADDR_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_5_RESETVAL    (0x00000000u)

/* SES_MPAXL_6 */

#define CSL_MSMC_SES_MPAXL_6_UX_MASK     (0x00000001u)
#define CSL_MSMC_SES_MPAXL_6_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SES_MPAXL_6_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_6_UW_MASK     (0x00000002u)
#define CSL_MSMC_SES_MPAXL_6_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SES_MPAXL_6_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_6_UR_MASK     (0x00000004u)
#define CSL_MSMC_SES_MPAXL_6_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SES_MPAXL_6_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_6_SX_MASK     (0x00000008u)
#define CSL_MSMC_SES_MPAXL_6_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SES_MPAXL_6_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_6_SW_MASK     (0x00000010u)
#define CSL_MSMC_SES_MPAXL_6_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SES_MPAXL_6_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_6_SR_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXL_6_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXL_6_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SES_MPAXL_6_RADDR_MASK  (0xFFFFFF00u)
#define CSL_MSMC_SES_MPAXL_6_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SES_MPAXL_6_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_6_RESETVAL    (0x00000000u)

/* SES_MPAXH_6 */

#define CSL_MSMC_SES_MPAXH_6_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SES_MPAXH_6_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SES_MPAXH_6_SEGSZ_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_6_AI_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXH_6_AI_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXH_6_AI_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_6_BE_MASK     (0x00000040u)
#define CSL_MSMC_SES_MPAXH_6_BE_SHIFT    (0x00000006u)
#define CSL_MSMC_SES_MPAXH_6_BE_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_6_BADDR_MASK  (0xFFFFF000u)
#define CSL_MSMC_SES_MPAXH_6_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SES_MPAXH_6_BADDR_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_6_RESETVAL    (0x00000000u)

/* SES_MPAXL_7 */

#define CSL_MSMC_SES_MPAXL_7_UX_MASK     (0x00000001u)
#define CSL_MSMC_SES_MPAXL_7_UX_SHIFT    (0x00000000u)
#define CSL_MSMC_SES_MPAXL_7_UX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_7_UW_MASK     (0x00000002u)
#define CSL_MSMC_SES_MPAXL_7_UW_SHIFT    (0x00000001u)
#define CSL_MSMC_SES_MPAXL_7_UW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_7_UR_MASK     (0x00000004u)
#define CSL_MSMC_SES_MPAXL_7_UR_SHIFT    (0x00000002u)
#define CSL_MSMC_SES_MPAXL_7_UR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_7_SX_MASK     (0x00000008u)
#define CSL_MSMC_SES_MPAXL_7_SX_SHIFT    (0x00000003u)
#define CSL_MSMC_SES_MPAXL_7_SX_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_7_SW_MASK     (0x00000010u)
#define CSL_MSMC_SES_MPAXL_7_SW_SHIFT    (0x00000004u)
#define CSL_MSMC_SES_MPAXL_7_SW_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_7_SR_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXL_7_SR_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXL_7_SR_RESETVAL (0x00000000u)



#define CSL_MSMC_SES_MPAXL_7_RADDR_MASK  (0xFFFFFF00u)
#define CSL_MSMC_SES_MPAXL_7_RADDR_SHIFT (0x00000008u)
#define CSL_MSMC_SES_MPAXL_7_RADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXL_7_RESETVAL    (0x00000000u)

/* SES_MPAXH_7 */

#define CSL_MSMC_SES_MPAXH_7_SEGSZ_MASK  (0x0000001Fu)
#define CSL_MSMC_SES_MPAXH_7_SEGSZ_SHIFT (0x00000000u)
#define CSL_MSMC_SES_MPAXH_7_SEGSZ_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_7_AI_MASK     (0x00000020u)
#define CSL_MSMC_SES_MPAXH_7_AI_SHIFT    (0x00000005u)
#define CSL_MSMC_SES_MPAXH_7_AI_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAXH_7_BE_MASK     (0x00000040u)
#define CSL_MSMC_SES_MPAXH_7_BE_SHIFT    (0x00000006u)
#define CSL_MSMC_SES_MPAXH_7_BE_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_7_BADDR_MASK  (0xFFFFF000u)
#define CSL_MSMC_SES_MPAXH_7_BADDR_SHIFT (0x0000000Cu)
#define CSL_MSMC_SES_MPAXH_7_BADDR_RESETVAL (0x00000000u)


#define CSL_MSMC_SES_MPAXH_7_RESETVAL    (0x00000000u)

/* PID */

#define CSL_MSMC_PID_Y_MASK              (0x0000003Fu)
#define CSL_MSMC_PID_Y_SHIFT             (0x00000000u)
#define CSL_MSMC_PID_Y_RESETVAL          (0x00000000u)

#define CSL_MSMC_PID_CUSTOM_MASK         (0x000000C0u)
#define CSL_MSMC_PID_CUSTOM_SHIFT        (0x00000006u)
#define CSL_MSMC_PID_CUSTOM_RESETVAL     (0x00000000u)

#define CSL_MSMC_PID_X_MASK              (0x00000700u)
#define CSL_MSMC_PID_X_SHIFT             (0x00000008u)
#define CSL_MSMC_PID_X_RESETVAL          (0x00000000u)

#define CSL_MSMC_PID_R_MASK              (0x0000F800u)
#define CSL_MSMC_PID_R_SHIFT             (0x0000000Bu)
#define CSL_MSMC_PID_R_RESETVAL          (0x00000000u)

#define CSL_MSMC_PID_FUNC_MASK           (0x0FFF0000u)
#define CSL_MSMC_PID_FUNC_SHIFT          (0x00000010u)
#define CSL_MSMC_PID_FUNC_RESETVAL       (0x00000500u)

#define CSL_MSMC_PID_BU_MASK             (0x30000000u)
#define CSL_MSMC_PID_BU_SHIFT            (0x0000001Cu)
#define CSL_MSMC_PID_BU_RESETVAL         (0x00000000u)

#define CSL_MSMC_PID_SCHEME_MASK         (0xC0000000u)
#define CSL_MSMC_PID_SCHEME_SHIFT        (0x0000001Eu)
#define CSL_MSMC_PID_SCHEME_RESETVAL     (0x00000001u)

#define CSL_MSMC_PID_RESETVAL            (0x45000000u)

/* SMCC */

#define CSL_MSMC_SMCC_MCP_MASK           (0x00000001u)
#define CSL_MSMC_SMCC_MCP_SHIFT          (0x00000000u)
#define CSL_MSMC_SMCC_MCP_RESETVAL       (0x00000000u)

#define CSL_MSMC_SMCC__RESV1_MASK        (0xFFFFFFFEu)
#define CSL_MSMC_SMCC__RESV1_SHIFT       (0x00000001u)
#define CSL_MSMC_SMCC__RESV1_RESETVAL    (0x00000000u)

#define CSL_MSMC_SMCC_RESETVAL           (0x00000000u)

/* SMCERRAR */

#define CSL_MSMC_SMCERRAR_SEADDR_MASK    (0xFFFFFFFFu)
#define CSL_MSMC_SMCERRAR_SEADDR_SHIFT   (0x00000000u)
#define CSL_MSMC_SMCERRAR_SEADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMCERRAR_RESETVAL       (0x00000000u)

/* SMCERRXR */

#define CSL_MSMC_SMCERRXR_SEEADDR_MASK   (0x0000000Fu)
#define CSL_MSMC_SMCERRXR_SEEADDR_SHIFT  (0x00000000u)
#define CSL_MSMC_SMCERRXR_SEEADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMCERRXR_SEPID_MASK     (0x000000F0u)
#define CSL_MSMC_SMCERRXR_SEPID_SHIFT    (0x00000004u)
#define CSL_MSMC_SMCERRXR_SEPID_RESETVAL (0x00000000u)

#define CSL_MSMC_SMCERRXR_SER_MASK       (0x00000100u)
#define CSL_MSMC_SMCERRXR_SER_SHIFT      (0x00000008u)
#define CSL_MSMC_SMCERRXR_SER_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMCERRXR__RESV1_MASK    (0x0000FE00u)
#define CSL_MSMC_SMCERRXR__RESV1_SHIFT   (0x00000009u)
#define CSL_MSMC_SMCERRXR__RESV1_RESETVAL (0x00000000u)

#define CSL_MSMC_SMCERRXR_ESYN_MASK      (0x00FF0000u)
#define CSL_MSMC_SMCERRXR_ESYN_SHIFT     (0x00000010u)
#define CSL_MSMC_SMCERRXR_ESYN_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMCERRXR__RESV2_MASK    (0xFF000000u)
#define CSL_MSMC_SMCERRXR__RESV2_SHIFT   (0x00000018u)
#define CSL_MSMC_SMCERRXR__RESV2_RESETVAL (0x00000000u)

#define CSL_MSMC_SMCERRXR_RESETVAL       (0x00000000u)

/* SMEDCC */

#define CSL_MSMC_SMEDCC_REFDEL_MASK      (0x000000FFu)
#define CSL_MSMC_SMEDCC_REFDEL_SHIFT     (0x00000000u)
#define CSL_MSMC_SMEDCC_REFDEL_RESETVAL  (0x00000001u)

#define CSL_MSMC_SMEDCC__RESV1_MASK      (0x03FFFF00u)
#define CSL_MSMC_SMEDCC__RESV1_SHIFT     (0x00000008u)
#define CSL_MSMC_SMEDCC__RESV1_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMEDCC_PRR_MASK         (0x04000000u)
#define CSL_MSMC_SMEDCC_PRR_SHIFT        (0x0000001Au)
#define CSL_MSMC_SMEDCC_PRR_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMEDCC_CSE_MASK         (0x08000000u)
#define CSL_MSMC_SMEDCC_CSE_SHIFT        (0x0000001Bu)
#define CSL_MSMC_SMEDCC_CSE_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMEDCC__RESV2_MASK      (0x30000000u)
#define CSL_MSMC_SMEDCC__RESV2_SHIFT     (0x0000001Cu)
#define CSL_MSMC_SMEDCC__RESV2_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMEDCC_ECM_MASK         (0x40000000u)
#define CSL_MSMC_SMEDCC_ECM_SHIFT        (0x0000001Eu)
#define CSL_MSMC_SMEDCC_ECM_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMEDCC_SEN_MASK         (0x80000000u)
#define CSL_MSMC_SMEDCC_SEN_SHIFT        (0x0000001Fu)
#define CSL_MSMC_SMEDCC_SEN_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMEDCC_RESETVAL         (0x00000001u)

/* SMCEA */

#define CSL_MSMC_SMCEA_SECA_MASK         (0x00FFFFFFu)
#define CSL_MSMC_SMCEA_SECA_SHIFT        (0x00000000u)
#define CSL_MSMC_SMCEA_SECA_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMCEA_ESYN_MASK         (0xFF000000u)
#define CSL_MSMC_SMCEA_ESYN_SHIFT        (0x00000018u)
#define CSL_MSMC_SMCEA_ESYN_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMCEA_RESETVAL          (0x00000000u)

/* SMSECC */

#define CSL_MSMC_SMSECC_SCEC_MASK        (0x0000FFFFu)
#define CSL_MSMC_SMSECC_SCEC_SHIFT       (0x00000000u)
#define CSL_MSMC_SMSECC_SCEC_RESETVAL    (0x00000000u)

#define CSL_MSMC_SMSECC_SNCEC_MASK       (0xFFFF0000u)
#define CSL_MSMC_SMSECC_SNCEC_SHIFT      (0x00000010u)
#define CSL_MSMC_SMSECC_SNCEC_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMSECC_RESETVAL         (0x00000000u)

/* SMPFAR */

#define CSL_MSMC_SMPFAR_FAULT_ADDRESS_MASK (0xFFFFFFFFu)
#define CSL_MSMC_SMPFAR_FAULT_ADDRESS_SHIFT (0x00000000u)
#define CSL_MSMC_SMPFAR_FAULT_ADDRESS_RESETVAL (0x00000000u)

#define CSL_MSMC_SMPFAR_RESETVAL         (0x00000000u)

/* SMPFXR */

#define CSL_MSMC_SMPFXR_NM_MASK          (0x00000001u)
#define CSL_MSMC_SMPFXR_NM_SHIFT         (0x00000000u)
#define CSL_MSMC_SMPFXR_NM_RESETVAL      (0x00000000u)

#define CSL_MSMC_SMPFXR__RESV1_MASK      (0xFFFFFFFEu)
#define CSL_MSMC_SMPFXR__RESV1_SHIFT     (0x00000001u)
#define CSL_MSMC_SMPFXR__RESV1_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMPFXR_RESETVAL         (0x00000000u)

/* SMPFR */

#define CSL_MSMC_SMPFR_FMSTID_MASK       (0x000000FFu)
#define CSL_MSMC_SMPFR_FMSTID_SHIFT      (0x00000000u)
#define CSL_MSMC_SMPFR_FMSTID_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMPFR_FPID_MASK         (0x00000F00u)
#define CSL_MSMC_SMPFR_FPID_SHIFT        (0x00000008u)
#define CSL_MSMC_SMPFR_FPID_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMPFR__RESV1_MASK       (0xFFFFF000u)
#define CSL_MSMC_SMPFR__RESV1_SHIFT      (0x0000000Cu)
#define CSL_MSMC_SMPFR__RESV1_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMPFR_RESETVAL          (0x00000000u)

/* SMPFCR */

#define CSL_MSMC_SMPFCR_CLR_MASK         (0x00000001u)
#define CSL_MSMC_SMPFCR_CLR_SHIFT        (0x00000000u)
#define CSL_MSMC_SMPFCR_CLR_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMPFCR__RESV1_MASK      (0xFFFFFFFEu)
#define CSL_MSMC_SMPFCR__RESV1_SHIFT     (0x00000001u)
#define CSL_MSMC_SMPFCR__RESV1_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMPFCR_RESETVAL         (0x00000000u)

/* SMIDCFG */

#define CSL_MSMC_SMIDCFG_LK_SHIFT                               (0u)
#define CSL_MSMC_SMIDCFG_LK_MASK                                (0x00000001u)
#define CSL_MSMC_SMIDCFG_LK_RESETVAL                            (0x00000000u)
#define CSL_MSMC_SMIDCFG_LK_MAX                                 (0x00000001u)

#define CSL_MSMC_SMIDCFG__RESV1_SHIFT                           (1u)
#define CSL_MSMC_SMIDCFG__RESV1_MASK                            (0x000000FEu)
#define CSL_MSMC_SMIDCFG__RESV1_RESETVAL                        (0x00000000u)
#define CSL_MSMC_SMIDCFG__RESV1_MAX                             (0x0000007fu)

#define CSL_MSMC_SMIDCFG_SM_MSTID_INT_SHIFT                     (8u)
#define CSL_MSMC_SMIDCFG_SM_MSTID_INT_MASK                      (0x0000FF00u)
#define CSL_MSMC_SMIDCFG_SM_MSTID_INT_RESETVAL                  (0x00000000u)
#define CSL_MSMC_SMIDCFG_SM_MSTID_INT_MAX                       (0x000000ffu)

#define CSL_MSMC_SMIDCFG__RESV2_SHIFT                           (16u)
#define CSL_MSMC_SMIDCFG__RESV2_MASK                            (0x7FFF0000u)
#define CSL_MSMC_SMIDCFG__RESV2_RESETVAL                        (0x00000000u)
#define CSL_MSMC_SMIDCFG__RESV2_MAX                             (0x00007fffu)

#define CSL_MSMC_SMIDCFG_NS_SHIFT                               (31u)
#define CSL_MSMC_SMIDCFG_NS_MASK                                (0x80000000u)
#define CSL_MSMC_SMIDCFG_NS_RESETVAL                            (0x00000000u)
#define CSL_MSMC_SMIDCFG_NS_MAX                                 (0x00000001u)

#define CSL_MSMC_SMIDCFG_RESETVAL                               (0x00000000u)

/* SBNDC0 */

#define CSL_MSMC_SBNDC0_SCNTCM_MASK      (0x000000FFu)
#define CSL_MSMC_SBNDC0_SCNTCM_SHIFT     (0x00000000u)
#define CSL_MSMC_SBNDC0_SCNTCM_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC0__RESV1_MASK      (0x0000FF00u)
#define CSL_MSMC_SBNDC0__RESV1_SHIFT     (0x00000008u)
#define CSL_MSMC_SBNDC0__RESV1_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC0_SCNTCE_MASK      (0x00FF0000u)
#define CSL_MSMC_SBNDC0_SCNTCE_SHIFT     (0x00000010u)
#define CSL_MSMC_SBNDC0_SCNTCE_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC0__RESV2_MASK      (0xFF000000u)
#define CSL_MSMC_SBNDC0__RESV2_SHIFT     (0x00000018u)
#define CSL_MSMC_SBNDC0__RESV2_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC0_RESETVAL         (0x001F001Fu)

/* SBNDC1 */

#define CSL_MSMC_SBNDC1_SCNTCM_MASK      (0x000000FFu)
#define CSL_MSMC_SBNDC1_SCNTCM_SHIFT     (0x00000000u)
#define CSL_MSMC_SBNDC1_SCNTCM_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC1__RESV1_MASK      (0x0000FF00u)
#define CSL_MSMC_SBNDC1__RESV1_SHIFT     (0x00000008u)
#define CSL_MSMC_SBNDC1__RESV1_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC1_SCNTCE_MASK      (0x00FF0000u)
#define CSL_MSMC_SBNDC1_SCNTCE_SHIFT     (0x00000010u)
#define CSL_MSMC_SBNDC1_SCNTCE_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC1__RESV2_MASK      (0xFF000000u)
#define CSL_MSMC_SBNDC1__RESV2_SHIFT     (0x00000018u)
#define CSL_MSMC_SBNDC1__RESV2_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC1_RESETVAL         (0x001F001Fu)

/* SBNDC2 */

#define CSL_MSMC_SBNDC2_SCNTCM_MASK      (0x000000FFu)
#define CSL_MSMC_SBNDC2_SCNTCM_SHIFT     (0x00000000u)
#define CSL_MSMC_SBNDC2_SCNTCM_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC2__RESV1_MASK      (0x0000FF00u)
#define CSL_MSMC_SBNDC2__RESV1_SHIFT     (0x00000008u)
#define CSL_MSMC_SBNDC2__RESV1_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC2_SCNTCE_MASK      (0x00FF0000u)
#define CSL_MSMC_SBNDC2_SCNTCE_SHIFT     (0x00000010u)
#define CSL_MSMC_SBNDC2_SCNTCE_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC2__RESV2_MASK      (0xFF000000u)
#define CSL_MSMC_SBNDC2__RESV2_SHIFT     (0x00000018u)
#define CSL_MSMC_SBNDC2__RESV2_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC2_RESETVAL         (0x001F001Fu)

/* SBNDC3 */

#define CSL_MSMC_SBNDC3_SCNTCM_MASK      (0x000000FFu)
#define CSL_MSMC_SBNDC3_SCNTCM_SHIFT     (0x00000000u)
#define CSL_MSMC_SBNDC3_SCNTCM_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC3__RESV1_MASK      (0x0000FF00u)
#define CSL_MSMC_SBNDC3__RESV1_SHIFT     (0x00000008u)
#define CSL_MSMC_SBNDC3__RESV1_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC3_SCNTCE_MASK      (0x00FF0000u)
#define CSL_MSMC_SBNDC3_SCNTCE_SHIFT     (0x00000010u)
#define CSL_MSMC_SBNDC3_SCNTCE_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC3__RESV2_MASK      (0xFF000000u)
#define CSL_MSMC_SBNDC3__RESV2_SHIFT     (0x00000018u)
#define CSL_MSMC_SBNDC3__RESV2_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC3_RESETVAL         (0x001F001Fu)

/* SBNDC4 */

#define CSL_MSMC_SBNDC4_SCNTCM_MASK      (0x000000FFu)
#define CSL_MSMC_SBNDC4_SCNTCM_SHIFT     (0x00000000u)
#define CSL_MSMC_SBNDC4_SCNTCM_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC4__RESV1_MASK      (0x0000FF00u)
#define CSL_MSMC_SBNDC4__RESV1_SHIFT     (0x00000008u)
#define CSL_MSMC_SBNDC4__RESV1_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC4_SCNTCE_MASK      (0x00FF0000u)
#define CSL_MSMC_SBNDC4_SCNTCE_SHIFT     (0x00000010u)
#define CSL_MSMC_SBNDC4_SCNTCE_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC4__RESV2_MASK      (0xFF000000u)
#define CSL_MSMC_SBNDC4__RESV2_SHIFT     (0x00000018u)
#define CSL_MSMC_SBNDC4__RESV2_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC4_RESETVAL         (0x001F001Fu)

/* SBNDC5 */

#define CSL_MSMC_SBNDC5_SCNTCM_MASK      (0x000000FFu)
#define CSL_MSMC_SBNDC5_SCNTCM_SHIFT     (0x00000000u)
#define CSL_MSMC_SBNDC5_SCNTCM_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC5__RESV1_MASK      (0x0000FF00u)
#define CSL_MSMC_SBNDC5__RESV1_SHIFT     (0x00000008u)
#define CSL_MSMC_SBNDC5__RESV1_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC5_SCNTCE_MASK      (0x00FF0000u)
#define CSL_MSMC_SBNDC5_SCNTCE_SHIFT     (0x00000010u)
#define CSL_MSMC_SBNDC5_SCNTCE_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC5__RESV2_MASK      (0xFF000000u)
#define CSL_MSMC_SBNDC5__RESV2_SHIFT     (0x00000018u)
#define CSL_MSMC_SBNDC5__RESV2_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC5_RESETVAL         (0x001F001Fu)

/* SBNDC6 */

#define CSL_MSMC_SBNDC6_SCNTCM_MASK      (0x000000FFu)
#define CSL_MSMC_SBNDC6_SCNTCM_SHIFT     (0x00000000u)
#define CSL_MSMC_SBNDC6_SCNTCM_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC6__RESV1_MASK      (0x0000FF00u)
#define CSL_MSMC_SBNDC6__RESV1_SHIFT     (0x00000008u)
#define CSL_MSMC_SBNDC6__RESV1_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC6_SCNTCE_MASK      (0x00FF0000u)
#define CSL_MSMC_SBNDC6_SCNTCE_SHIFT     (0x00000010u)
#define CSL_MSMC_SBNDC6_SCNTCE_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC6__RESV2_MASK      (0xFF000000u)
#define CSL_MSMC_SBNDC6__RESV2_SHIFT     (0x00000018u)
#define CSL_MSMC_SBNDC6__RESV2_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC6_RESETVAL         (0x001F001Fu)

/* SBNDC7 */

#define CSL_MSMC_SBNDC7_SCNTCM_MASK      (0x000000FFu)
#define CSL_MSMC_SBNDC7_SCNTCM_SHIFT     (0x00000000u)
#define CSL_MSMC_SBNDC7_SCNTCM_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC7__RESV1_MASK      (0x0000FF00u)
#define CSL_MSMC_SBNDC7__RESV1_SHIFT     (0x00000008u)
#define CSL_MSMC_SBNDC7__RESV1_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC7_SCNTCE_MASK      (0x00FF0000u)
#define CSL_MSMC_SBNDC7_SCNTCE_SHIFT     (0x00000010u)
#define CSL_MSMC_SBNDC7_SCNTCE_RESETVAL  (0x0000001Fu)

#define CSL_MSMC_SBNDC7__RESV2_MASK      (0xFF000000u)
#define CSL_MSMC_SBNDC7__RESV2_SHIFT     (0x00000018u)
#define CSL_MSMC_SBNDC7__RESV2_RESETVAL  (0x00000000u)

#define CSL_MSMC_SBNDC7_RESETVAL         (0x001F001Fu)

/* SBNDM */

#define CSL_MSMC_SBNDM_SCNTMM_MASK       (0x000000FFu)
#define CSL_MSMC_SBNDM_SCNTMM_SHIFT      (0x00000000u)
#define CSL_MSMC_SBNDM_SCNTMM_RESETVAL   (0x0000001Fu)

#define CSL_MSMC_SBNDM__RESV1_MASK       (0xFFFFFF00u)
#define CSL_MSMC_SBNDM__RESV1_SHIFT      (0x00000008u)
#define CSL_MSMC_SBNDM__RESV1_RESETVAL   (0x00000000u)

#define CSL_MSMC_SBNDM_RESETVAL          (0x0000001Fu)

/* SBNDE */

#define CSL_MSMC_SBNDE_SCNTEM_MASK       (0x000000FFu)
#define CSL_MSMC_SBNDE_SCNTEM_SHIFT      (0x00000000u)
#define CSL_MSMC_SBNDE_SCNTEM_RESETVAL   (0x0000001Fu)

#define CSL_MSMC_SBNDE__RESV1_MASK       (0x0000FF00u)
#define CSL_MSMC_SBNDE__RESV1_SHIFT      (0x00000008u)
#define CSL_MSMC_SBNDE__RESV1_RESETVAL   (0x00000000u)

#define CSL_MSMC_SBNDE_SCNTEE_MASK       (0x00FF0000u)
#define CSL_MSMC_SBNDE_SCNTEE_SHIFT      (0x00000010u)
#define CSL_MSMC_SBNDE_SCNTEE_RESETVAL   (0x0000001Fu)

#define CSL_MSMC_SBNDE__RESV2_MASK       (0xFF000000u)
#define CSL_MSMC_SBNDE__RESV2_SHIFT      (0x00000018u)
#define CSL_MSMC_SBNDE__RESV2_RESETVAL   (0x00000000u)

#define CSL_MSMC_SBNDE_RESETVAL          (0x001F001Fu)

/* SMEDCTST */

#define CSL_MSMC_SMEDCTST_PF0_MASK       (0x00000001u)
#define CSL_MSMC_SMEDCTST_PF0_SHIFT      (0x00000000u)
#define CSL_MSMC_SMEDCTST_PF0_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMEDCTST_PF1_MASK       (0x00000002u)
#define CSL_MSMC_SMEDCTST_PF1_SHIFT      (0x00000001u)
#define CSL_MSMC_SMEDCTST_PF1_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMEDCTST_PF2_MASK       (0x00000004u)
#define CSL_MSMC_SMEDCTST_PF2_SHIFT      (0x00000002u)
#define CSL_MSMC_SMEDCTST_PF2_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMEDCTST_PF3_MASK       (0x00000008u)
#define CSL_MSMC_SMEDCTST_PF3_SHIFT      (0x00000003u)
#define CSL_MSMC_SMEDCTST_PF3_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMEDCTST_BCNT_MASK      (0x00000070u)
#define CSL_MSMC_SMEDCTST_BCNT_SHIFT     (0x00000004u)
#define CSL_MSMC_SMEDCTST_BCNT_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMEDCTST_SCRBADDR_MASK  (0x00FFFF80u)
#define CSL_MSMC_SMEDCTST_SCRBADDR_SHIFT (0x00000007u)
#define CSL_MSMC_SMEDCTST_SCRBADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMEDCTST_DPS_MASK       (0xFF000000u)
#define CSL_MSMC_SMEDCTST_DPS_SHIFT      (0x00000018u)
#define CSL_MSMC_SMEDCTST_DPS_RESETVAL   (0x0000002Cu)

#define CSL_MSMC_SMEDCTST_RESETVAL       (0x2C000000u)

/* CFGLCK */

#define CSL_MSMC_CFGLCK_WLCK_MASK        (0x00000001u)
#define CSL_MSMC_CFGLCK_WLCK_SHIFT       (0x00000000u)
#define CSL_MSMC_CFGLCK_WLCK_RESETVAL    (0x00000000u)


#define CSL_MSMC_CFGLCK_MGCID_MASK       (0xFFFF0000u)
#define CSL_MSMC_CFGLCK_MGCID_SHIFT      (0x00000010u)
#define CSL_MSMC_CFGLCK_MGCID_RESETVAL   (0x00002CD0u)

#define CSL_MSMC_CFGLCK_RESETVAL         (0x2CD00000u)

/* CFGULCK */

#define CSL_MSMC_CFGULCK_WEN_MASK        (0x00000001u)
#define CSL_MSMC_CFGULCK_WEN_SHIFT       (0x00000000u)
#define CSL_MSMC_CFGULCK_WEN_RESETVAL    (0x00000000u)

#define CSL_MSMC_CFGULCK__RESV1_MASK     (0x0000FFFEu)
#define CSL_MSMC_CFGULCK__RESV1_SHIFT    (0x00000001u)
#define CSL_MSMC_CFGULCK__RESV1_RESETVAL (0x00000000u)

#define CSL_MSMC_CFGULCK_MGCID_MASK      (0xFFFF0000u)
#define CSL_MSMC_CFGULCK_MGCID_SHIFT     (0x00000010u)
#define CSL_MSMC_CFGULCK_MGCID_RESETVAL  (0x00002CD0u)

#define CSL_MSMC_CFGULCK_RESETVAL        (0x2CD00000u)

/* CFGLCKSTAT */

#define CSL_MSMC_CFGLCKSTAT_WSTAT_MASK   (0x00000001u)
#define CSL_MSMC_CFGLCKSTAT_WSTAT_SHIFT  (0x00000000u)
#define CSL_MSMC_CFGLCKSTAT_WSTAT_RESETVAL (0x00000000u)

#define CSL_MSMC_CFGLCKSTAT__RESV1_MASK  (0xFFFFFFFEu)
#define CSL_MSMC_CFGLCKSTAT__RESV1_SHIFT (0x00000001u)
#define CSL_MSMC_CFGLCKSTAT__RESV1_RESETVAL (0x00000000u)

#define CSL_MSMC_CFGLCKSTAT_RESETVAL     (0x00000000u)

/* SMS_MPAX_LCK */

#define CSL_MSMC_SMS_MPAX_LCK_WLCK_MASK  (0x0000FFFFu)
#define CSL_MSMC_SMS_MPAX_LCK_WLCK_SHIFT (0x00000000u)
#define CSL_MSMC_SMS_MPAX_LCK_WLCK_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAX_LCK_MGCID_MASK (0xFFFF0000u)
#define CSL_MSMC_SMS_MPAX_LCK_MGCID_SHIFT (0x00000010u)
#define CSL_MSMC_SMS_MPAX_LCK_MGCID_RESETVAL (0x00002CD1u)

#define CSL_MSMC_SMS_MPAX_LCK_RESETVAL   (0x2CD10000u)

/* SMS_MPAX_ULCK */

#define CSL_MSMC_SMS_MPAX_ULCK_WEN_MASK  (0x0000FFFFu)
#define CSL_MSMC_SMS_MPAX_ULCK_WEN_SHIFT (0x00000000u)
#define CSL_MSMC_SMS_MPAX_ULCK_WEN_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAX_ULCK_MGCID_MASK (0xFFFF0000u)
#define CSL_MSMC_SMS_MPAX_ULCK_MGCID_SHIFT (0x00000010u)
#define CSL_MSMC_SMS_MPAX_ULCK_MGCID_RESETVAL (0x00002CD1u)

#define CSL_MSMC_SMS_MPAX_ULCK_RESETVAL  (0x2CD10000u)

/* SMS_MPAX_LCKSTAT */

#define CSL_MSMC_SMS_MPAX_LCKSTAT_WSTAT_MASK (0x0000FFFFu)
#define CSL_MSMC_SMS_MPAX_LCKSTAT_WSTAT_SHIFT (0x00000000u)
#define CSL_MSMC_SMS_MPAX_LCKSTAT_WSTAT_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAX_LCKSTAT__RESV1_MASK (0xFFFF0000u)
#define CSL_MSMC_SMS_MPAX_LCKSTAT__RESV1_SHIFT (0x00000010u)
#define CSL_MSMC_SMS_MPAX_LCKSTAT__RESV1_RESETVAL (0x00000000u)

#define CSL_MSMC_SMS_MPAX_LCKSTAT_RESETVAL (0x00000000u)

/* SES_MPAX_LCK */

#define CSL_MSMC_SES_MPAX_LCK_WLCK_MASK  (0x0000FFFFu)
#define CSL_MSMC_SES_MPAX_LCK_WLCK_SHIFT (0x00000000u)
#define CSL_MSMC_SES_MPAX_LCK_WLCK_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAX_LCK_MGCID_MASK (0xFFFF0000u)
#define CSL_MSMC_SES_MPAX_LCK_MGCID_SHIFT (0x00000010u)
#define CSL_MSMC_SES_MPAX_LCK_MGCID_RESETVAL (0x00002CD2u)

#define CSL_MSMC_SES_MPAX_LCK_RESETVAL   (0x2CD20000u)

/* SES_MPAX_ULCK */

#define CSL_MSMC_SES_MPAX_ULCK_WEN_MASK  (0x0000FFFFu)
#define CSL_MSMC_SES_MPAX_ULCK_WEN_SHIFT (0x00000000u)
#define CSL_MSMC_SES_MPAX_ULCK_WEN_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAX_ULCK_MGCID_MASK (0xFFFF0000u)
#define CSL_MSMC_SES_MPAX_ULCK_MGCID_SHIFT (0x00000010u)
#define CSL_MSMC_SES_MPAX_ULCK_MGCID_RESETVAL (0x00002CD2u)

#define CSL_MSMC_SES_MPAX_ULCK_RESETVAL  (0x2CD20000u)

/* SES_MPAX_LCKSTAT */

#define CSL_MSMC_SES_MPAX_LCKSTAT_WSTAT_MASK (0x0000FFFFu)
#define CSL_MSMC_SES_MPAX_LCKSTAT_WSTAT_SHIFT (0x00000000u)
#define CSL_MSMC_SES_MPAX_LCKSTAT_WSTAT_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAX_LCKSTAT__RESV1_MASK (0xFFFF0000u)
#define CSL_MSMC_SES_MPAX_LCKSTAT__RESV1_SHIFT (0x00000010u)
#define CSL_MSMC_SES_MPAX_LCKSTAT__RESV1_RESETVAL (0x00000000u)

#define CSL_MSMC_SES_MPAX_LCKSTAT_RESETVAL (0x00000000u)

/* SMESTAT */

#define CSL_MSMC_SMESTAT_NCSES_MASK      (0x00000001u)
#define CSL_MSMC_SMESTAT_NCSES_SHIFT     (0x00000000u)
#define CSL_MSMC_SMESTAT_NCSES_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMESTAT_CSES_MASK       (0x00000002u)
#define CSL_MSMC_SMESTAT_CSES_SHIFT      (0x00000001u)
#define CSL_MSMC_SMESTAT_CSES_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMESTAT_NCEES_MASK      (0x00000004u)
#define CSL_MSMC_SMESTAT_NCEES_SHIFT     (0x00000002u)
#define CSL_MSMC_SMESTAT_NCEES_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMESTAT_CEES_MASK       (0x00000008u)
#define CSL_MSMC_SMESTAT_CEES_SHIFT      (0x00000003u)
#define CSL_MSMC_SMESTAT_CEES_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMESTAT__RESV1_MASK     (0x0000FFF0u)
#define CSL_MSMC_SMESTAT__RESV1_SHIFT    (0x00000004u)
#define CSL_MSMC_SMESTAT__RESV1_RESETVAL (0x00000000u)

#define CSL_MSMC_SMESTAT_PFESTAT_MASK    (0xFFFF0000u)
#define CSL_MSMC_SMESTAT_PFESTAT_SHIFT   (0x00000010u)
#define CSL_MSMC_SMESTAT_PFESTAT_RESETVAL (0x00000000u)

#define CSL_MSMC_SMESTAT_RESETVAL        (0x00000000u)

/* SMIRSTAT */

#define CSL_MSMC_SMIRSTAT_NCSES_MASK     (0x00000001u)
#define CSL_MSMC_SMIRSTAT_NCSES_SHIFT    (0x00000000u)
#define CSL_MSMC_SMIRSTAT_NCSES_RESETVAL (0x00000000u)

#define CSL_MSMC_SMIRSTAT_CSES_MASK      (0x00000002u)
#define CSL_MSMC_SMIRSTAT_CSES_SHIFT     (0x00000001u)
#define CSL_MSMC_SMIRSTAT_CSES_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMIRSTAT_NCEES_MASK     (0x00000004u)
#define CSL_MSMC_SMIRSTAT_NCEES_SHIFT    (0x00000002u)
#define CSL_MSMC_SMIRSTAT_NCEES_RESETVAL (0x00000000u)

#define CSL_MSMC_SMIRSTAT_CEES_MASK      (0x00000008u)
#define CSL_MSMC_SMIRSTAT_CEES_SHIFT     (0x00000003u)
#define CSL_MSMC_SMIRSTAT_CEES_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMIRSTAT__RESV1_MASK    (0x0000FFF0u)
#define CSL_MSMC_SMIRSTAT__RESV1_SHIFT   (0x00000004u)
#define CSL_MSMC_SMIRSTAT__RESV1_RESETVAL (0x00000000u)

#define CSL_MSMC_SMIRSTAT_PFESTAT_MASK   (0xFFFF0000u)
#define CSL_MSMC_SMIRSTAT_PFESTAT_SHIFT  (0x00000010u)
#define CSL_MSMC_SMIRSTAT_PFESTAT_RESETVAL (0x00000000u)

#define CSL_MSMC_SMIRSTAT_RESETVAL       (0x00000000u)

/* SMIRC */

#define CSL_MSMC_SMIRC_NCSC_MASK         (0x00000001u)
#define CSL_MSMC_SMIRC_NCSC_SHIFT        (0x00000000u)
#define CSL_MSMC_SMIRC_NCSC_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMIRC_CSC_MASK          (0x00000002u)
#define CSL_MSMC_SMIRC_CSC_SHIFT         (0x00000001u)
#define CSL_MSMC_SMIRC_CSC_RESETVAL      (0x00000000u)

#define CSL_MSMC_SMIRC_NCEC_MASK         (0x00000004u)
#define CSL_MSMC_SMIRC_NCEC_SHIFT        (0x00000002u)
#define CSL_MSMC_SMIRC_NCEC_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMIRC_CEC_MASK          (0x00000008u)
#define CSL_MSMC_SMIRC_CEC_SHIFT         (0x00000003u)
#define CSL_MSMC_SMIRC_CEC_RESETVAL      (0x00000000u)

#define CSL_MSMC_SMIRC__RESV1_MASK       (0x0000FFF0u)
#define CSL_MSMC_SMIRC__RESV1_SHIFT      (0x00000004u)
#define CSL_MSMC_SMIRC__RESV1_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMIRC_PFIC_MASK         (0xFFFF0000u)
#define CSL_MSMC_SMIRC_PFIC_SHIFT        (0x00000010u)
#define CSL_MSMC_SMIRC_PFIC_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMIRC_RESETVAL          (0x00000000u)

/* SMIESTAT */

#define CSL_MSMC_SMIESTAT_NCSIE_MASK     (0x00000001u)
#define CSL_MSMC_SMIESTAT_NCSIE_SHIFT    (0x00000000u)
#define CSL_MSMC_SMIESTAT_NCSIE_RESETVAL (0x00000000u)

#define CSL_MSMC_SMIESTAT_CSIE_MASK      (0x00000002u)
#define CSL_MSMC_SMIESTAT_CSIE_SHIFT     (0x00000001u)
#define CSL_MSMC_SMIESTAT_CSIE_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMIESTAT_NCEIE_MASK     (0x00000004u)
#define CSL_MSMC_SMIESTAT_NCEIE_SHIFT    (0x00000002u)
#define CSL_MSMC_SMIESTAT_NCEIE_RESETVAL (0x00000000u)

#define CSL_MSMC_SMIESTAT_CEIE_MASK      (0x00000008u)
#define CSL_MSMC_SMIESTAT_CEIE_SHIFT     (0x00000003u)
#define CSL_MSMC_SMIESTAT_CEIE_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMIESTAT__RESV1_MASK    (0x0000FFF0u)
#define CSL_MSMC_SMIESTAT__RESV1_SHIFT   (0x00000004u)
#define CSL_MSMC_SMIESTAT__RESV1_RESETVAL (0x00000000u)

#define CSL_MSMC_SMIESTAT_PFIESTAT_MASK  (0xFFFF0000u)
#define CSL_MSMC_SMIESTAT_PFIESTAT_SHIFT (0x00000010u)
#define CSL_MSMC_SMIESTAT_PFIESTAT_RESETVAL (0x00000000u)

#define CSL_MSMC_SMIESTAT_RESETVAL       (0x00000000u)

/* SMIEC */

#define CSL_MSMC_SMIEC_NCSEC_MASK        (0x00000001u)
#define CSL_MSMC_SMIEC_NCSEC_SHIFT       (0x00000000u)
#define CSL_MSMC_SMIEC_NCSEC_RESETVAL    (0x00000000u)

#define CSL_MSMC_SMIEC_CSEC_MASK         (0x00000002u)
#define CSL_MSMC_SMIEC_CSEC_SHIFT        (0x00000001u)
#define CSL_MSMC_SMIEC_CSEC_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMIEC_NCEEC_MASK        (0x00000004u)
#define CSL_MSMC_SMIEC_NCEEC_SHIFT       (0x00000002u)
#define CSL_MSMC_SMIEC_NCEEC_RESETVAL    (0x00000000u)

#define CSL_MSMC_SMIEC_CEEC_MASK         (0x00000008u)
#define CSL_MSMC_SMIEC_CEEC_SHIFT        (0x00000003u)
#define CSL_MSMC_SMIEC_CEEC_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMIEC__RESV1_MASK       (0x0000FFF0u)
#define CSL_MSMC_SMIEC__RESV1_SHIFT      (0x00000004u)
#define CSL_MSMC_SMIEC__RESV1_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMIEC_PFIEC_MASK        (0xFFFF0000u)
#define CSL_MSMC_SMIEC_PFIEC_SHIFT       (0x00000010u)
#define CSL_MSMC_SMIEC_PFIEC_RESETVAL    (0x00000000u)

#define CSL_MSMC_SMIEC_RESETVAL          (0x00000000u)

/* SMATH */

#define CSL_MSMC_SMATH_THEADER_MASK      (0xFFFFFFFFu)
#define CSL_MSMC_SMATH_THEADER_SHIFT     (0x00000000u)
#define CSL_MSMC_SMATH_THEADER_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMATH_RESETVAL          (0x00000000u)

/* SMAH */

#define CSL_MSMC_SMAH_HCNT_MASK          (0x000FFFFFu)
#define CSL_MSMC_SMAH_HCNT_SHIFT         (0x00000000u)
#define CSL_MSMC_SMAH_HCNT_RESETVAL      (0x00000000u)

#define CSL_MSMC_SMAH__RESV1_MASK        (0xFFF00000u)
#define CSL_MSMC_SMAH__RESV1_SHIFT       (0x00000014u)
#define CSL_MSMC_SMAH__RESV1_RESETVAL    (0x00000000u)

#define CSL_MSMC_SMAH_RESETVAL           (0x00000000u)

/* SMARM */

#define CSL_MSMC_SMARM_RMCNT_MASK        (0x000FFFFFu)
#define CSL_MSMC_SMARM_RMCNT_SHIFT       (0x00000000u)
#define CSL_MSMC_SMARM_RMCNT_RESETVAL    (0x00000000u)

#define CSL_MSMC_SMARM__RESV1_MASK       (0xFFF00000u)
#define CSL_MSMC_SMARM__RESV1_SHIFT      (0x00000014u)
#define CSL_MSMC_SMARM__RESV1_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMARM_RESETVAL          (0x00000000u)

/* SMAWM */

#define CSL_MSMC_SMAWM_WMCNT_MASK        (0x000FFFFFu)
#define CSL_MSMC_SMAWM_WMCNT_SHIFT       (0x00000000u)
#define CSL_MSMC_SMAWM_WMCNT_RESETVAL    (0x00000000u)

#define CSL_MSMC_SMAWM__RESV1_MASK       (0xFFF00000u)
#define CSL_MSMC_SMAWM__RESV1_SHIFT      (0x00000014u)
#define CSL_MSMC_SMAWM__RESV1_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMAWM_RESETVAL          (0x00000000u)

/* SMAV */

#define CSL_MSMC_SMAV_VCNT_MASK          (0x000FFFFFu)
#define CSL_MSMC_SMAV_VCNT_SHIFT         (0x00000000u)
#define CSL_MSMC_SMAV_VCNT_RESETVAL      (0x00000000u)

#define CSL_MSMC_SMAV__RESV1_MASK        (0xFFF00000u)
#define CSL_MSMC_SMAV__RESV1_SHIFT       (0x00000014u)
#define CSL_MSMC_SMAV__RESV1_RESETVAL    (0x00000000u)

#define CSL_MSMC_SMAV_RESETVAL           (0x00000000u)

/* SMAMP */

#define CSL_MSMC_SMAMP_ACWM_MASK         (0x000FFFFFu)
#define CSL_MSMC_SMAMP_ACWM_SHIFT        (0x00000000u)
#define CSL_MSMC_SMAMP_ACWM_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMAMP__RESV1_MASK       (0x00F00000u)
#define CSL_MSMC_SMAMP__RESV1_SHIFT      (0x00000014u)
#define CSL_MSMC_SMAMP__RESV1_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMAMP_MPECNT_MASK       (0xFF000000u)
#define CSL_MSMC_SMAMP_MPECNT_SHIFT      (0x00000018u)
#define CSL_MSMC_SMAMP_MPECNT_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMAMP_RESETVAL          (0x00000000u)

/* SMAEP */

#define CSL_MSMC_SMAEP_ACWE_MASK         (0x000FFFFFu)
#define CSL_MSMC_SMAEP_ACWE_SHIFT        (0x00000000u)
#define CSL_MSMC_SMAEP_ACWE_RESETVAL     (0x00000000u)

#define CSL_MSMC_SMAEP__RESV1_MASK       (0x00F00000u)
#define CSL_MSMC_SMAEP__RESV1_SHIFT      (0x00000014u)
#define CSL_MSMC_SMAEP__RESV1_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMAEP_EPECNT_MASK       (0xFF000000u)
#define CSL_MSMC_SMAEP_EPECNT_SHIFT      (0x00000018u)
#define CSL_MSMC_SMAEP_EPECNT_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMAEP_RESETVAL          (0x00000000u)

/* SMAC */

#define CSL_MSMC_SMAC__RESV1_MASK        (0x00000001u)
#define CSL_MSMC_SMAC__RESV1_SHIFT       (0x00000000u)
#define CSL_MSMC_SMAC__RESV1_RESETVAL    (0x00000000u)

#define CSL_MSMC_SMAC_AEN_MASK           (0x00000002u)
#define CSL_MSMC_SMAC_AEN_SHIFT          (0x00000001u)
#define CSL_MSMC_SMAC_AEN_RESETVAL       (0x00000000u)

#define CSL_MSMC_SMAC_PTH_MASK           (0x0000001Cu)
#define CSL_MSMC_SMAC_PTH_SHIFT          (0x00000002u)
#define CSL_MSMC_SMAC_PTH_RESETVAL       (0x00000007u)

#define CSL_MSMC_SMAC_HM_MASK            (0x00000020u)
#define CSL_MSMC_SMAC_HM_SHIFT           (0x00000005u)
#define CSL_MSMC_SMAC_HM_RESETVAL        (0x00000000u)

#define CSL_MSMC_SMAC__RESV2_MASK        (0x000000C0u)
#define CSL_MSMC_SMAC__RESV2_SHIFT       (0x00000006u)
#define CSL_MSMC_SMAC__RESV2_RESETVAL    (0x00000000u)

#define CSL_MSMC_SMAC_PIDF_MASK          (0x00FFFF00u)
#define CSL_MSMC_SMAC_PIDF_SHIFT         (0x00000008u)
#define CSL_MSMC_SMAC_PIDF_RESETVAL      (0x0000FFFFu)

#define CSL_MSMC_SMAC_CCF_MASK           (0xFF000000u)
#define CSL_MSMC_SMAC_CCF_SHIFT          (0x00000018u)
#define CSL_MSMC_SMAC_CCF_RESETVAL       (0x000000FFu)

#define CSL_MSMC_SMAC_RESETVAL           (0xFFFFFF1Cu)

/* SMCFG */

#define CSL_MSMC_SMCFG_CMODE_MASK        (0x0000000Fu)
#define CSL_MSMC_SMCFG_CMODE_SHIFT       (0x00000000u)
#define CSL_MSMC_SMCFG_CMODE_RESETVAL    (0x00000000u)

#define CSL_MSMC_SMCFG_GIW_MASK          (0x00000010u)
#define CSL_MSMC_SMCFG_GIW_SHIFT         (0x00000004u)
#define CSL_MSMC_SMCFG_GIW_RESETVAL      (0x00000000u)

#define CSL_MSMC_SMCFG_EFZ_MASK          (0x00000020u)
#define CSL_MSMC_SMCFG_EFZ_SHIFT         (0x00000005u)
#define CSL_MSMC_SMCFG_EFZ_RESETVAL      (0x00000000u)

#define CSL_MSMC_SMCFG_INVP_MASK         (0x000001C0u)
#define CSL_MSMC_SMCFG_INVP_SHIFT        (0x00000006u)
#define CSL_MSMC_SMCFG_INVP_RESETVAL     (0x00000007u)

#define CSL_MSMC_SMCFG__RESV1_MASK       (0xFFFFFE00u)
#define CSL_MSMC_SMCFG__RESV1_SHIFT      (0x00000009u)
#define CSL_MSMC_SMCFG__RESV1_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMCFG_RESETVAL          (0x000001C0u)

/* SMNCERRAR */

#define CSL_MSMC_SMNCERRAR_SEADDR_MASK   (0xFFFFFFFFu)
#define CSL_MSMC_SMNCERRAR_SEADDR_SHIFT  (0x00000000u)
#define CSL_MSMC_SMNCERRAR_SEADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMNCERRAR_RESETVAL      (0x00000000u)

/* SMNCERRXR */

#define CSL_MSMC_SMNCERRXR_SEEADDR_MASK  (0x0000000Fu)
#define CSL_MSMC_SMNCERRXR_SEEADDR_SHIFT (0x00000000u)
#define CSL_MSMC_SMNCERRXR_SEEADDR_RESETVAL (0x00000000u)

#define CSL_MSMC_SMNCERRXR_SEPID_MASK    (0x000000F0u)
#define CSL_MSMC_SMNCERRXR_SEPID_SHIFT   (0x00000004u)
#define CSL_MSMC_SMNCERRXR_SEPID_RESETVAL (0x00000000u)

#define CSL_MSMC_SMNCERRXR_SER_MASK      (0x00000100u)
#define CSL_MSMC_SMNCERRXR_SER_SHIFT     (0x00000008u)
#define CSL_MSMC_SMNCERRXR_SER_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMNCERRXR__RESV1_MASK   (0xFFFFFE00u)
#define CSL_MSMC_SMNCERRXR__RESV1_SHIFT  (0x00000009u)
#define CSL_MSMC_SMNCERRXR__RESV1_RESETVAL (0x00000000u)

#define CSL_MSMC_SMNCERRXR_RESETVAL      (0x00000000u)

/* SMNCEA */

#define CSL_MSMC_SMNCEA_SENCA_MASK       (0x00FFFFFFu)
#define CSL_MSMC_SMNCEA_SENCA_SHIFT      (0x00000000u)
#define CSL_MSMC_SMNCEA_SENCA_RESETVAL   (0x00000000u)

#define CSL_MSMC_SMNCEA__RESV1_MASK      (0xFF000000u)
#define CSL_MSMC_SMNCEA__RESV1_SHIFT     (0x00000018u)
#define CSL_MSMC_SMNCEA__RESV1_RESETVAL  (0x00000000u)

#define CSL_MSMC_SMNCEA_RESETVAL         (0x00000000u)
#ifdef __cplusplus
}
#endif

#endif


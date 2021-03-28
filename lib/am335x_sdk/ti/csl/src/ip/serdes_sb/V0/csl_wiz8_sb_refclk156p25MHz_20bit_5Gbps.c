/**
* File: csl_wiz8_sb_refclk156p25MHz_20bit_5Gbps
*
* Version: SnowBushRel_PHY_A_20.5_20150722 - Change VREGg/h
*
* Brief:
*  Autogenerated SERDES CONFIG Functions.
*
*  It contains the various enumerations, structure definitions and function
*  declarations
*
*  
*  ============================================================================
*  (C) Copyright 2014, Texas Instruments, Inc.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
#ifndef CSL_WIZ8_SB_REFCLK156P25MHZ_20BIT_5GBPS_C
#define CSL_WIZ8_SB_REFCLK156P25MHZ_20BIT_5GBPS_C

#include <stdint.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl.h>


/* for misra warnings */
void csl_wiz8_sb_refclk156p25MHz_20bit_5Gbps(uint32_t base_addr);
void csl_wiz8_sb_refclk156p25MHz_20bit_5Gbps(uint32_t base_addr)
  {
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0000),31,24, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0014), 7, 0, (uint32_t)0x82);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0014),15, 8, (uint32_t)0x82);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0060), 7, 0, (uint32_t)0x38);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0060),15, 8, (uint32_t)0x24);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0060),23,16, (uint32_t)0x14);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0064),15, 8, (uint32_t)0xc7);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0064),23,16, (uint32_t)0xc3);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0078),15, 8, (uint32_t)0xc0);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0204), 7, 0, (uint32_t)0x80);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0204),31,24, (uint32_t)0x78);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0208), 7, 0, (uint32_t)0x26);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0208),23,16, (uint32_t)0x01);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x020c),31,24, (uint32_t)0x02);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0214), 7, 0, (uint32_t)0x38);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0214),15, 8, (uint32_t)0x6f);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0218), 7, 0, (uint32_t)0xe4);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0218),23,16, (uint32_t)0x80);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0218),31,24, (uint32_t)0x7a);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x022c),15, 8, (uint32_t)0x08);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x022c),23,16, (uint32_t)0x30);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0280), 7, 0, (uint32_t)0x86);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0280),23,16, (uint32_t)0x86);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0284), 7, 0, (uint32_t)0x85);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0284),23,16, (uint32_t)0x0f);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0284),31,24, (uint32_t)0x1d);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x028c),15, 8, (uint32_t)0x2c);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0404), 7, 0, (uint32_t)0x80);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0404),31,24, (uint32_t)0x78);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0408), 7, 0, (uint32_t)0x26);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0408),23,16, (uint32_t)0x01);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x040c),31,24, (uint32_t)0x02);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0414), 7, 0, (uint32_t)0x38);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0414),15, 8, (uint32_t)0x6f);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0418), 7, 0, (uint32_t)0xe4);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0418),23,16, (uint32_t)0x80);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0418),31,24, (uint32_t)0x7a);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x042c),15, 8, (uint32_t)0x08);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x042c),23,16, (uint32_t)0x30);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0480), 7, 0, (uint32_t)0x86);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0480),23,16, (uint32_t)0x86);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0484), 7, 0, (uint32_t)0x85);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0484),23,16, (uint32_t)0x0f);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0484),31,24, (uint32_t)0x1d);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x048c),15, 8, (uint32_t)0x2c);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0604), 7, 0, (uint32_t)0x80);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0604),31,24, (uint32_t)0x78);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0608), 7, 0, (uint32_t)0x26);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0608),23,16, (uint32_t)0x01);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x060c),31,24, (uint32_t)0x02);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0614), 7, 0, (uint32_t)0x38);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0614),15, 8, (uint32_t)0x6f);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0618), 7, 0, (uint32_t)0xe4);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0618),23,16, (uint32_t)0x80);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0618),31,24, (uint32_t)0x7a);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x062c),15, 8, (uint32_t)0x08);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x062c),23,16, (uint32_t)0x30);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0680), 7, 0, (uint32_t)0x86);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0680),23,16, (uint32_t)0x86);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0684), 7, 0, (uint32_t)0x85);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0684),23,16, (uint32_t)0x0f);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0684),31,24, (uint32_t)0x1d);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x068c),15, 8, (uint32_t)0x2c);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0804), 7, 0, (uint32_t)0x80);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0804),31,24, (uint32_t)0x78);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0808), 7, 0, (uint32_t)0x26);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0808),23,16, (uint32_t)0x01);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x080c),31,24, (uint32_t)0x02);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0814), 7, 0, (uint32_t)0x38);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0814),15, 8, (uint32_t)0x6f);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0818), 7, 0, (uint32_t)0xe4);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0818),23,16, (uint32_t)0x80);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0818),31,24, (uint32_t)0x7a);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x082c),15, 8, (uint32_t)0x08);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x082c),23,16, (uint32_t)0x30);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0880), 7, 0, (uint32_t)0x86);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0880),23,16, (uint32_t)0x86);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0884), 7, 0, (uint32_t)0x85);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0884),23,16, (uint32_t)0x0f);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0884),31,24, (uint32_t)0x1d);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x088c),15, 8, (uint32_t)0x2c);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00),15, 8, (uint32_t)0x80);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a08),23,16, (uint32_t)0xd2);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a08),31,24, (uint32_t)0x38);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a30),15, 8, (uint32_t)0x8d);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a30),23,16, (uint32_t)0x8d);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a84),15, 8, (uint32_t)0x07);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a94),31,24, (uint32_t)0x10);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0aa0),31,24, (uint32_t)0x81);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0abc),31,24, (uint32_t)0xff);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0ac0), 7, 0, (uint32_t)0x8b);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a48),15, 8, (uint32_t)0x8c);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a48),23,16, (uint32_t)0xfd);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a54), 7, 0, (uint32_t)0x72);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a54),15, 8, (uint32_t)0xec);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a54),23,16, (uint32_t)0x2f);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a58),15, 8, (uint32_t)0x21);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a58),23,16, (uint32_t)0xf9);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a58),31,24, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a5c), 7, 0, (uint32_t)0x60);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a5c),15, 8, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a5c),23,16, (uint32_t)0x04);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a5c),31,24, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a60), 7, 0, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a60),15, 8, (uint32_t)0x80);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a60),23,16, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a60),31,24, (uint32_t)0x00);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a64), 7, 0, (uint32_t)0x20);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a64),15, 8, (uint32_t)0x12);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a64),23,16, (uint32_t)0x58);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a64),31,24, (uint32_t)0x0c);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a68), 7, 0, (uint32_t)0x02);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a68),15, 8, (uint32_t)0x06);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a68),23,16, (uint32_t)0x3b);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a68),31,24, (uint32_t)0xe1);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a6c), 7, 0, (uint32_t)0xc1);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a6c),15, 8, (uint32_t)0x4c);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a6c),23,16, (uint32_t)0x07);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a6c),31,24, (uint32_t)0xb8);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a70), 7, 0, (uint32_t)0x89);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a70),15, 8, (uint32_t)0xe9);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a70),23,16, (uint32_t)0x02);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a70),31,24, (uint32_t)0x3f);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a74), 7, 0, (uint32_t)0x01);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b20),23,16, (uint32_t)0x37);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b1c),31,24, (uint32_t)0x37);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0b20), 7, 0, (uint32_t)0x5d);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0000), 7, 0, (uint32_t)0x03);
  CSL_FINSR(*(volatile uint32_t *)(base_addr + 0x0a00), 7, 0, (uint32_t)0x5f);
  }
#endif

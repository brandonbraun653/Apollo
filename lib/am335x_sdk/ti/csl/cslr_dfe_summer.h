/*
 * cslr_dfe_summer.h
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

/* The file is auto generated at 19:49:14 01/10/13 (Rev 1.68)*/

#ifndef CSLR_DFE_SUMMER_H__
#define CSLR_DFE_SUMMER_H__

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/

typedef struct 
{
    /* Addr: h(0), d(0) */
    volatile Uint32 rsvd0[1];
    /* Addr: h(4), d(4) */
    volatile Uint32 cfg0;
    /* Addr: h(8), d(8) */
    volatile Uint32 cfg1;
    /* Addr: h(C), d(12) */
    volatile Uint32 cfg2;
    /* Addr: h(10), d(16) */
    volatile Uint32 cfg3;
    /* Addr: h(14), d(20) */
    volatile Uint32 cfg4;
    /* Addr: h(18), d(24) */
    volatile Uint32 cfg5;
    /* Addr: h(1C), d(28) */
    volatile Uint32 cfg6;
    /* Addr: h(20), d(32) */
    volatile Uint32 cfg7;
    /* Addr: h(24), d(36) */
    volatile Uint32 cfg8;
    /* Addr: h(28), d(40) */
    volatile Uint32 cfg9;
    /* Addr: h(2C), d(44) */
    volatile Uint32 cfg10;
    /* Addr: h(30), d(48) */
    volatile Uint32 cfg11;
    /* Addr: h(34), d(52) */
    volatile Uint32 cfg12;
    /* Addr: h(38), d(56) */
    volatile Uint32 cfg13;
    /* Addr: h(3C), d(60) */
    volatile Uint32 cfg14;
    /* Addr: h(40), d(64) */
    volatile Uint32 cfg15;
    /* Addr: h(44), d(68) */
    volatile Uint32 cfg16;
    /* Addr: h(48), d(72) */
    volatile Uint32 cfg17;
    /* Addr: h(4C), d(76) */
    volatile Uint32 cfg18;
    /* Addr: h(50), d(80) */
    volatile Uint32 cfg19;
    /* Addr: h(54), d(84) */
    volatile Uint32 cfg20;
    /* Addr: h(58), d(88) */
    volatile Uint32 cfg21;
    /* Addr: h(5C), d(92) */
    volatile Uint32 cfg22;
    /* Addr: h(60), d(96) */
    volatile Uint32 cfg23;
    /* Addr: h(64), d(100) */
    volatile Uint32 cfg24;
    /* Addr: h(68), d(104) */
    volatile Uint32 cfg25;
    /* Addr: h(6C), d(108) */
    volatile Uint32 cfg26;
    /* Addr: h(70), d(112) */
    volatile Uint32 cfg27;
    /* Addr: h(74), d(116) */
    volatile Uint32 cfg28;
} CSL_DFE_SUMMER_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* CFG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 17;
    Uint32 shift_cfr1_str1 : 3;
    Uint32 rsvd2 : 1;
    Uint32 shift_cfr1_str0 : 3;
    Uint32 rsvd1 : 1;
    Uint32 shift_cfr0_str1 : 3;
    Uint32 rsvd0 : 1;
    Uint32 shift_cfr0_str0 : 3;
#else 
    Uint32 shift_cfr0_str0 : 3;
    Uint32 rsvd0 : 1;
    Uint32 shift_cfr0_str1 : 3;
    Uint32 rsvd1 : 1;
    Uint32 shift_cfr1_str0 : 3;
    Uint32 rsvd2 : 1;
    Uint32 shift_cfr1_str1 : 3;
    Uint32 rsvd3 : 17;
#endif 
} CSL_DFE_SUMMER_CFG0_REG;

/* Shift value for CFR 0 stream 0. The resulting gain would be 2^(shift -6) for CFR 0 stream 0  */
#define CSL_DFE_SUMMER_CFG0_REG_SHIFT_CFR0_STR0_MASK (0x00000007u)
#define CSL_DFE_SUMMER_CFG0_REG_SHIFT_CFR0_STR0_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG0_REG_SHIFT_CFR0_STR0_RESETVAL (0x00000000u)

/* Shift value for CFR 0 Stream 1.The resulting gain would be 2^(shift -6) for CFR 0 stream 1  */
#define CSL_DFE_SUMMER_CFG0_REG_SHIFT_CFR0_STR1_MASK (0x00000070u)
#define CSL_DFE_SUMMER_CFG0_REG_SHIFT_CFR0_STR1_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG0_REG_SHIFT_CFR0_STR1_RESETVAL (0x00000000u)

/* Shift value for CFR 1 Stream 0.The resulting gain would be 2^(shift -6) for CFR 1 stream 0  */
#define CSL_DFE_SUMMER_CFG0_REG_SHIFT_CFR1_STR0_MASK (0x00000700u)
#define CSL_DFE_SUMMER_CFG0_REG_SHIFT_CFR1_STR0_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG0_REG_SHIFT_CFR1_STR0_RESETVAL (0x00000000u)

/* Shift value for CFR 1 Stream 1.The resulting gain would be 2^(shift -6) for CFR 1 stream 1  */
#define CSL_DFE_SUMMER_CFG0_REG_SHIFT_CFR1_STR1_MASK (0x00007000u)
#define CSL_DFE_SUMMER_CFG0_REG_SHIFT_CFR1_STR1_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG0_REG_SHIFT_CFR1_STR1_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG0_REG_ADDR (0x00000004u)
#define CSL_DFE_SUMMER_CFG0_REG_RESETVAL (0x00000000u)

/* CFG1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 17;
    Uint32 shift_cfr3_str1 : 3;
    Uint32 rsvd2 : 1;
    Uint32 shift_cfr3_str0 : 3;
    Uint32 rsvd1 : 1;
    Uint32 shift_cfr2_str1 : 3;
    Uint32 rsvd0 : 1;
    Uint32 shift_cfr2_str0 : 3;
#else 
    Uint32 shift_cfr2_str0 : 3;
    Uint32 rsvd0 : 1;
    Uint32 shift_cfr2_str1 : 3;
    Uint32 rsvd1 : 1;
    Uint32 shift_cfr3_str0 : 3;
    Uint32 rsvd2 : 1;
    Uint32 shift_cfr3_str1 : 3;
    Uint32 rsvd3 : 17;
#endif 
} CSL_DFE_SUMMER_CFG1_REG;

/* Shift value for cfr2 stream 0.The resulting gain would be 2^(shift -6) for cfr2 stream 0  */
#define CSL_DFE_SUMMER_CFG1_REG_SHIFT_CFR2_STR0_MASK (0x00000007u)
#define CSL_DFE_SUMMER_CFG1_REG_SHIFT_CFR2_STR0_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG1_REG_SHIFT_CFR2_STR0_RESETVAL (0x00000000u)

/* Shift value for cfr2 stream 1.The resulting gain would be 2^(shift -6) for cfr2 stream 1  */
#define CSL_DFE_SUMMER_CFG1_REG_SHIFT_CFR2_STR1_MASK (0x00000070u)
#define CSL_DFE_SUMMER_CFG1_REG_SHIFT_CFR2_STR1_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG1_REG_SHIFT_CFR2_STR1_RESETVAL (0x00000000u)

/* Shift value for cfr3 stream 0.The resulting gain would be 2^(shift -6) for cfr3 stream 0  */
#define CSL_DFE_SUMMER_CFG1_REG_SHIFT_CFR3_STR0_MASK (0x00000700u)
#define CSL_DFE_SUMMER_CFG1_REG_SHIFT_CFR3_STR0_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG1_REG_SHIFT_CFR3_STR0_RESETVAL (0x00000000u)

/* Shift value for cfr3 stream 1.The resulting gain would be 2^(shift -6) for cfr3 stream 1  */
#define CSL_DFE_SUMMER_CFG1_REG_SHIFT_CFR3_STR1_MASK (0x00007000u)
#define CSL_DFE_SUMMER_CFG1_REG_SHIFT_CFR3_STR1_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG1_REG_SHIFT_CFR3_STR1_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG1_REG_ADDR (0x00000008u)
#define CSL_DFE_SUMMER_CFG1_REG_RESETVAL (0x00000000u)

/* CFG2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 numant : 4;
#else 
    Uint32 numant : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_SUMMER_CFG2_REG;

/* Single bit which decides if there are one or two streams on cfr .LSB corrosponds to cfr0, Bit 1 is cfr1 ,Bit 2 is cfr2 and Bit3 is cfr3. Bit Value 0 means one stream and bit value 1 means two streams.  */
#define CSL_DFE_SUMMER_CFG2_REG_NUMANT_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG2_REG_NUMANT_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG2_REG_NUMANT_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG2_REG_ADDR (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG2_REG_RESETVAL (0x00000000u)

/* CFG3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 summer_ssel : 4;
#else 
    Uint32 summer_ssel : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_SUMMER_CFG3_REG;

/* Generates Sync signal to update which carriers to sum to which CFR */
#define CSL_DFE_SUMMER_CFG3_REG_SUMMER_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG3_REG_SUMMER_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG3_REG_SUMMER_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG3_REG_ADDR (0x00000010u)
#define CSL_DFE_SUMMER_CFG3_REG_RESETVAL (0x00000000u)

/* CFG4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 25;
    Uint32 clear_data : 1;
    Uint32 init_state : 1;
    Uint32 rsvd0 : 1;
    Uint32 inits_ssel : 4;
#else 
    Uint32 inits_ssel : 4;
    Uint32 rsvd0 : 1;
    Uint32 init_state : 1;
    Uint32 clear_data : 1;
    Uint32 rsvd1 : 25;
#endif 
} CSL_DFE_SUMMER_CFG4_REG;

/* Select for generating the sync signal for inits block */
#define CSL_DFE_SUMMER_CFG4_REG_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG4_REG_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG4_REG_INITS_SSEL_RESETVAL (0x00000000u)

/* Init state signal value */
#define CSL_DFE_SUMMER_CFG4_REG_INIT_STATE_MASK (0x00000020u)
#define CSL_DFE_SUMMER_CFG4_REG_INIT_STATE_SHIFT (0x00000005u)
#define CSL_DFE_SUMMER_CFG4_REG_INIT_STATE_RESETVAL (0x00000001u)

/* clear_data signal value */
#define CSL_DFE_SUMMER_CFG4_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_SUMMER_CFG4_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_SUMMER_CFG4_REG_CLEAR_DATA_RESETVAL (0x00000001u)

#define CSL_DFE_SUMMER_CFG4_REG_ADDR (0x00000014u)
#define CSL_DFE_SUMMER_CFG4_REG_RESETVAL (0x00000060u)

/* CFG5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_str0_dduc1_port0 : 4;
    Uint32 cfr0_str0_dduc0_port2 : 4;
    Uint32 cfr0_str0_dduc0_port1 : 4;
    Uint32 cfr0_str0_dduc0_port0 : 4;
#else 
    Uint32 cfr0_str0_dduc0_port0 : 4;
    Uint32 cfr0_str0_dduc0_port1 : 4;
    Uint32 cfr0_str0_dduc0_port2 : 4;
    Uint32 cfr0_str0_dduc1_port0 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG5_REG;

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 0.  */
#define CSL_DFE_SUMMER_CFG5_REG_CFR0_STR0_DDUC0_PORT0_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG5_REG_CFR0_STR0_DDUC0_PORT0_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG5_REG_CFR0_STR0_DDUC0_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 0.  */
#define CSL_DFE_SUMMER_CFG5_REG_CFR0_STR0_DDUC0_PORT1_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG5_REG_CFR0_STR0_DDUC0_PORT1_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG5_REG_CFR0_STR0_DDUC0_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 0.  */
#define CSL_DFE_SUMMER_CFG5_REG_CFR0_STR0_DDUC0_PORT2_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG5_REG_CFR0_STR0_DDUC0_PORT2_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG5_REG_CFR0_STR0_DDUC0_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 0.  */
#define CSL_DFE_SUMMER_CFG5_REG_CFR0_STR0_DDUC1_PORT0_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG5_REG_CFR0_STR0_DDUC1_PORT0_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG5_REG_CFR0_STR0_DDUC1_PORT0_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG5_REG_ADDR (0x00000018u)
#define CSL_DFE_SUMMER_CFG5_REG_RESETVAL (0x00000000u)

/* CFG6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_str0_dduc2_port1 : 4;
    Uint32 cfr0_str0_dduc2_port0 : 4;
    Uint32 cfr0_str0_dduc1_port2 : 4;
    Uint32 cfr0_str0_dduc1_port1 : 4;
#else 
    Uint32 cfr0_str0_dduc1_port1 : 4;
    Uint32 cfr0_str0_dduc1_port2 : 4;
    Uint32 cfr0_str0_dduc2_port0 : 4;
    Uint32 cfr0_str0_dduc2_port1 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG6_REG;

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 0.  */
#define CSL_DFE_SUMMER_CFG6_REG_CFR0_STR0_DDUC1_PORT1_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG6_REG_CFR0_STR0_DDUC1_PORT1_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG6_REG_CFR0_STR0_DDUC1_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 0.  */
#define CSL_DFE_SUMMER_CFG6_REG_CFR0_STR0_DDUC1_PORT2_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG6_REG_CFR0_STR0_DDUC1_PORT2_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG6_REG_CFR0_STR0_DDUC1_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 0.  */
#define CSL_DFE_SUMMER_CFG6_REG_CFR0_STR0_DDUC2_PORT0_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG6_REG_CFR0_STR0_DDUC2_PORT0_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG6_REG_CFR0_STR0_DDUC2_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 0.  */
#define CSL_DFE_SUMMER_CFG6_REG_CFR0_STR0_DDUC2_PORT1_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG6_REG_CFR0_STR0_DDUC2_PORT1_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG6_REG_CFR0_STR0_DDUC2_PORT1_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG6_REG_ADDR (0x0000001Cu)
#define CSL_DFE_SUMMER_CFG6_REG_RESETVAL (0x00000000u)

/* CFG7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_str0_dduc3_port2 : 4;
    Uint32 cfr0_str0_dduc3_port1 : 4;
    Uint32 cfr0_str0_dduc3_port0 : 4;
    Uint32 cfr0_str0_dduc2_port2 : 4;
#else 
    Uint32 cfr0_str0_dduc2_port2 : 4;
    Uint32 cfr0_str0_dduc3_port0 : 4;
    Uint32 cfr0_str0_dduc3_port1 : 4;
    Uint32 cfr0_str0_dduc3_port2 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG7_REG;

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 0.  */
#define CSL_DFE_SUMMER_CFG7_REG_CFR0_STR0_DDUC2_PORT2_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG7_REG_CFR0_STR0_DDUC2_PORT2_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG7_REG_CFR0_STR0_DDUC2_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 0.  */
#define CSL_DFE_SUMMER_CFG7_REG_CFR0_STR0_DDUC3_PORT0_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG7_REG_CFR0_STR0_DDUC3_PORT0_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG7_REG_CFR0_STR0_DDUC3_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 0.  */
#define CSL_DFE_SUMMER_CFG7_REG_CFR0_STR0_DDUC3_PORT1_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG7_REG_CFR0_STR0_DDUC3_PORT1_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG7_REG_CFR0_STR0_DDUC3_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 0.  */
#define CSL_DFE_SUMMER_CFG7_REG_CFR0_STR0_DDUC3_PORT2_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG7_REG_CFR0_STR0_DDUC3_PORT2_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG7_REG_CFR0_STR0_DDUC3_PORT2_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG7_REG_ADDR (0x00000020u)
#define CSL_DFE_SUMMER_CFG7_REG_RESETVAL (0x00000000u)

/* CFG8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_str1_dduc1_port0 : 4;
    Uint32 cfr0_str1_dduc0_port2 : 4;
    Uint32 cfr0_str1_dduc0_port1 : 4;
    Uint32 cfr0_str1_dduc0_port0 : 4;
#else 
    Uint32 cfr0_str1_dduc0_port0 : 4;
    Uint32 cfr0_str1_dduc0_port1 : 4;
    Uint32 cfr0_str1_dduc0_port2 : 4;
    Uint32 cfr0_str1_dduc1_port0 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG8_REG;

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 1.  */
#define CSL_DFE_SUMMER_CFG8_REG_CFR0_STR1_DDUC0_PORT0_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG8_REG_CFR0_STR1_DDUC0_PORT0_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG8_REG_CFR0_STR1_DDUC0_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 1.  */
#define CSL_DFE_SUMMER_CFG8_REG_CFR0_STR1_DDUC0_PORT1_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG8_REG_CFR0_STR1_DDUC0_PORT1_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG8_REG_CFR0_STR1_DDUC0_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 1.  */
#define CSL_DFE_SUMMER_CFG8_REG_CFR0_STR1_DDUC0_PORT2_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG8_REG_CFR0_STR1_DDUC0_PORT2_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG8_REG_CFR0_STR1_DDUC0_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 1.  */
#define CSL_DFE_SUMMER_CFG8_REG_CFR0_STR1_DDUC1_PORT0_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG8_REG_CFR0_STR1_DDUC1_PORT0_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG8_REG_CFR0_STR1_DDUC1_PORT0_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG8_REG_ADDR (0x00000024u)
#define CSL_DFE_SUMMER_CFG8_REG_RESETVAL (0x00000000u)

/* CFG9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_str1_dduc2_port1 : 4;
    Uint32 cfr0_str1_dduc2_port0 : 4;
    Uint32 cfr0_str1_dduc1_port2 : 4;
    Uint32 cfr0_str1_dduc1_port1 : 4;
#else 
    Uint32 cfr0_str1_dduc1_port1 : 4;
    Uint32 cfr0_str1_dduc1_port2 : 4;
    Uint32 cfr0_str1_dduc2_port0 : 4;
    Uint32 cfr0_str1_dduc2_port1 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG9_REG;

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 1.  */
#define CSL_DFE_SUMMER_CFG9_REG_CFR0_STR1_DDUC1_PORT1_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG9_REG_CFR0_STR1_DDUC1_PORT1_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG9_REG_CFR0_STR1_DDUC1_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 1.  */
#define CSL_DFE_SUMMER_CFG9_REG_CFR0_STR1_DDUC1_PORT2_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG9_REG_CFR0_STR1_DDUC1_PORT2_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG9_REG_CFR0_STR1_DDUC1_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 1.  */
#define CSL_DFE_SUMMER_CFG9_REG_CFR0_STR1_DDUC2_PORT0_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG9_REG_CFR0_STR1_DDUC2_PORT0_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG9_REG_CFR0_STR1_DDUC2_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 1.  */
#define CSL_DFE_SUMMER_CFG9_REG_CFR0_STR1_DDUC2_PORT1_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG9_REG_CFR0_STR1_DDUC2_PORT1_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG9_REG_CFR0_STR1_DDUC2_PORT1_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG9_REG_ADDR (0x00000028u)
#define CSL_DFE_SUMMER_CFG9_REG_RESETVAL (0x00000000u)

/* CFG10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_str1_dduc3_port2 : 4;
    Uint32 cfr0_str1_dduc3_port1 : 4;
    Uint32 cfr0_str1_dduc3_port0 : 4;
    Uint32 cfr0_str1_dduc2_port2 : 4;
#else 
    Uint32 cfr0_str1_dduc2_port2 : 4;
    Uint32 cfr0_str1_dduc3_port0 : 4;
    Uint32 cfr0_str1_dduc3_port1 : 4;
    Uint32 cfr0_str1_dduc3_port2 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG10_REG;

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 1.  */
#define CSL_DFE_SUMMER_CFG10_REG_CFR0_STR1_DDUC2_PORT2_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG10_REG_CFR0_STR1_DDUC2_PORT2_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG10_REG_CFR0_STR1_DDUC2_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 1.  */
#define CSL_DFE_SUMMER_CFG10_REG_CFR0_STR1_DDUC3_PORT0_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG10_REG_CFR0_STR1_DDUC3_PORT0_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG10_REG_CFR0_STR1_DDUC3_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 1.  */
#define CSL_DFE_SUMMER_CFG10_REG_CFR0_STR1_DDUC3_PORT1_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG10_REG_CFR0_STR1_DDUC3_PORT1_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG10_REG_CFR0_STR1_DDUC3_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr0 stream 1.  */
#define CSL_DFE_SUMMER_CFG10_REG_CFR0_STR1_DDUC3_PORT2_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG10_REG_CFR0_STR1_DDUC3_PORT2_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG10_REG_CFR0_STR1_DDUC3_PORT2_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG10_REG_ADDR (0x0000002Cu)
#define CSL_DFE_SUMMER_CFG10_REG_RESETVAL (0x00000000u)

/* CFG11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr1_str0_dduc1_port0 : 4;
    Uint32 cfr1_str0_dduc0_port2 : 4;
    Uint32 cfr1_str0_dduc0_port1 : 4;
    Uint32 cfr1_str0_dduc0_port0 : 4;
#else 
    Uint32 cfr1_str0_dduc0_port0 : 4;
    Uint32 cfr1_str0_dduc0_port1 : 4;
    Uint32 cfr1_str0_dduc0_port2 : 4;
    Uint32 cfr1_str0_dduc1_port0 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG11_REG;

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 0.  */
#define CSL_DFE_SUMMER_CFG11_REG_CFR1_STR0_DDUC0_PORT0_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG11_REG_CFR1_STR0_DDUC0_PORT0_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG11_REG_CFR1_STR0_DDUC0_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 0.  */
#define CSL_DFE_SUMMER_CFG11_REG_CFR1_STR0_DDUC0_PORT1_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG11_REG_CFR1_STR0_DDUC0_PORT1_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG11_REG_CFR1_STR0_DDUC0_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 0.  */
#define CSL_DFE_SUMMER_CFG11_REG_CFR1_STR0_DDUC0_PORT2_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG11_REG_CFR1_STR0_DDUC0_PORT2_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG11_REG_CFR1_STR0_DDUC0_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 0.  */
#define CSL_DFE_SUMMER_CFG11_REG_CFR1_STR0_DDUC1_PORT0_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG11_REG_CFR1_STR0_DDUC1_PORT0_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG11_REG_CFR1_STR0_DDUC1_PORT0_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG11_REG_ADDR (0x00000030u)
#define CSL_DFE_SUMMER_CFG11_REG_RESETVAL (0x00000000u)

/* CFG12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr1_str0_dduc2_port1 : 4;
    Uint32 cfr1_str0_dduc2_port0 : 4;
    Uint32 cfr1_str0_dduc1_port2 : 4;
    Uint32 cfr1_str0_dduc1_port1 : 4;
#else 
    Uint32 cfr1_str0_dduc1_port1 : 4;
    Uint32 cfr1_str0_dduc1_port2 : 4;
    Uint32 cfr1_str0_dduc2_port0 : 4;
    Uint32 cfr1_str0_dduc2_port1 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG12_REG;

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 0.  */
#define CSL_DFE_SUMMER_CFG12_REG_CFR1_STR0_DDUC1_PORT1_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG12_REG_CFR1_STR0_DDUC1_PORT1_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG12_REG_CFR1_STR0_DDUC1_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 0.  */
#define CSL_DFE_SUMMER_CFG12_REG_CFR1_STR0_DDUC1_PORT2_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG12_REG_CFR1_STR0_DDUC1_PORT2_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG12_REG_CFR1_STR0_DDUC1_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 0.  */
#define CSL_DFE_SUMMER_CFG12_REG_CFR1_STR0_DDUC2_PORT0_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG12_REG_CFR1_STR0_DDUC2_PORT0_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG12_REG_CFR1_STR0_DDUC2_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 0.  */
#define CSL_DFE_SUMMER_CFG12_REG_CFR1_STR0_DDUC2_PORT1_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG12_REG_CFR1_STR0_DDUC2_PORT1_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG12_REG_CFR1_STR0_DDUC2_PORT1_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG12_REG_ADDR (0x00000034u)
#define CSL_DFE_SUMMER_CFG12_REG_RESETVAL (0x00000000u)

/* CFG13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr1_str0_dduc3_port2 : 4;
    Uint32 cfr1_str0_dduc3_port1 : 4;
    Uint32 cfr1_str0_dduc3_port0 : 4;
    Uint32 cfr1_str0_dduc2_port2 : 4;
#else 
    Uint32 cfr1_str0_dduc2_port2 : 4;
    Uint32 cfr1_str0_dduc3_port0 : 4;
    Uint32 cfr1_str0_dduc3_port1 : 4;
    Uint32 cfr1_str0_dduc3_port2 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG13_REG;

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 0.  */
#define CSL_DFE_SUMMER_CFG13_REG_CFR1_STR0_DDUC2_PORT2_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG13_REG_CFR1_STR0_DDUC2_PORT2_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG13_REG_CFR1_STR0_DDUC2_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 0.  */
#define CSL_DFE_SUMMER_CFG13_REG_CFR1_STR0_DDUC3_PORT0_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG13_REG_CFR1_STR0_DDUC3_PORT0_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG13_REG_CFR1_STR0_DDUC3_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 0.  */
#define CSL_DFE_SUMMER_CFG13_REG_CFR1_STR0_DDUC3_PORT1_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG13_REG_CFR1_STR0_DDUC3_PORT1_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG13_REG_CFR1_STR0_DDUC3_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 0.  */
#define CSL_DFE_SUMMER_CFG13_REG_CFR1_STR0_DDUC3_PORT2_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG13_REG_CFR1_STR0_DDUC3_PORT2_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG13_REG_CFR1_STR0_DDUC3_PORT2_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG13_REG_ADDR (0x00000038u)
#define CSL_DFE_SUMMER_CFG13_REG_RESETVAL (0x00000000u)

/* CFG14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr1_str1_dduc1_port0 : 4;
    Uint32 cfr1_str1_dduc0_port2 : 4;
    Uint32 cfr1_str1_dduc0_port1 : 4;
    Uint32 cfr1_str1_dduc0_port0 : 4;
#else 
    Uint32 cfr1_str1_dduc0_port0 : 4;
    Uint32 cfr1_str1_dduc0_port1 : 4;
    Uint32 cfr1_str1_dduc0_port2 : 4;
    Uint32 cfr1_str1_dduc1_port0 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG14_REG;

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 1.  */
#define CSL_DFE_SUMMER_CFG14_REG_CFR1_STR1_DDUC0_PORT0_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG14_REG_CFR1_STR1_DDUC0_PORT0_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG14_REG_CFR1_STR1_DDUC0_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 1.  */
#define CSL_DFE_SUMMER_CFG14_REG_CFR1_STR1_DDUC0_PORT1_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG14_REG_CFR1_STR1_DDUC0_PORT1_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG14_REG_CFR1_STR1_DDUC0_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 1.  */
#define CSL_DFE_SUMMER_CFG14_REG_CFR1_STR1_DDUC0_PORT2_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG14_REG_CFR1_STR1_DDUC0_PORT2_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG14_REG_CFR1_STR1_DDUC0_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 1.  */
#define CSL_DFE_SUMMER_CFG14_REG_CFR1_STR1_DDUC1_PORT0_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG14_REG_CFR1_STR1_DDUC1_PORT0_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG14_REG_CFR1_STR1_DDUC1_PORT0_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG14_REG_ADDR (0x0000003Cu)
#define CSL_DFE_SUMMER_CFG14_REG_RESETVAL (0x00000000u)

/* CFG15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr1_str1_dduc2_port1 : 4;
    Uint32 cfr1_str1_dduc2_port0 : 4;
    Uint32 cfr1_str1_dduc1_port2 : 4;
    Uint32 cfr1_str1_dduc1_port1 : 4;
#else 
    Uint32 cfr1_str1_dduc1_port1 : 4;
    Uint32 cfr1_str1_dduc1_port2 : 4;
    Uint32 cfr1_str1_dduc2_port0 : 4;
    Uint32 cfr1_str1_dduc2_port1 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG15_REG;

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 1.  */
#define CSL_DFE_SUMMER_CFG15_REG_CFR1_STR1_DDUC1_PORT1_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG15_REG_CFR1_STR1_DDUC1_PORT1_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG15_REG_CFR1_STR1_DDUC1_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 1.  */
#define CSL_DFE_SUMMER_CFG15_REG_CFR1_STR1_DDUC1_PORT2_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG15_REG_CFR1_STR1_DDUC1_PORT2_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG15_REG_CFR1_STR1_DDUC1_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 1.  */
#define CSL_DFE_SUMMER_CFG15_REG_CFR1_STR1_DDUC2_PORT0_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG15_REG_CFR1_STR1_DDUC2_PORT0_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG15_REG_CFR1_STR1_DDUC2_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 1.  */
#define CSL_DFE_SUMMER_CFG15_REG_CFR1_STR1_DDUC2_PORT1_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG15_REG_CFR1_STR1_DDUC2_PORT1_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG15_REG_CFR1_STR1_DDUC2_PORT1_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG15_REG_ADDR (0x00000040u)
#define CSL_DFE_SUMMER_CFG15_REG_RESETVAL (0x00000000u)

/* CFG16 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr1_str1_dduc3_port2 : 4;
    Uint32 cfr1_str1_dduc3_port1 : 4;
    Uint32 cfr1_str1_dduc3_port0 : 4;
    Uint32 cfr1_str1_dduc2_port2 : 4;
#else 
    Uint32 cfr1_str1_dduc2_port2 : 4;
    Uint32 cfr1_str1_dduc3_port0 : 4;
    Uint32 cfr1_str1_dduc3_port1 : 4;
    Uint32 cfr1_str1_dduc3_port2 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG16_REG;

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 1.  */
#define CSL_DFE_SUMMER_CFG16_REG_CFR1_STR1_DDUC2_PORT2_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG16_REG_CFR1_STR1_DDUC2_PORT2_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG16_REG_CFR1_STR1_DDUC2_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 1.  */
#define CSL_DFE_SUMMER_CFG16_REG_CFR1_STR1_DDUC3_PORT0_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG16_REG_CFR1_STR1_DDUC3_PORT0_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG16_REG_CFR1_STR1_DDUC3_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 1.  */
#define CSL_DFE_SUMMER_CFG16_REG_CFR1_STR1_DDUC3_PORT1_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG16_REG_CFR1_STR1_DDUC3_PORT1_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG16_REG_CFR1_STR1_DDUC3_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr1 stream 1.  */
#define CSL_DFE_SUMMER_CFG16_REG_CFR1_STR1_DDUC3_PORT2_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG16_REG_CFR1_STR1_DDUC3_PORT2_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG16_REG_CFR1_STR1_DDUC3_PORT2_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG16_REG_ADDR (0x00000044u)
#define CSL_DFE_SUMMER_CFG16_REG_RESETVAL (0x00000000u)

/* CFG17 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr2_str0_dduc1_port0 : 4;
    Uint32 cfr2_str0_dduc0_port2 : 4;
    Uint32 cfr2_str0_dduc0_port1 : 4;
    Uint32 cfr2_str0_dduc0_port0 : 4;
#else 
    Uint32 cfr2_str0_dduc0_port0 : 4;
    Uint32 cfr2_str0_dduc0_port1 : 4;
    Uint32 cfr2_str0_dduc0_port2 : 4;
    Uint32 cfr2_str0_dduc1_port0 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG17_REG;

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 0.  */
#define CSL_DFE_SUMMER_CFG17_REG_CFR2_STR0_DDUC0_PORT0_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG17_REG_CFR2_STR0_DDUC0_PORT0_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG17_REG_CFR2_STR0_DDUC0_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 0.  */
#define CSL_DFE_SUMMER_CFG17_REG_CFR2_STR0_DDUC0_PORT1_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG17_REG_CFR2_STR0_DDUC0_PORT1_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG17_REG_CFR2_STR0_DDUC0_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 0.  */
#define CSL_DFE_SUMMER_CFG17_REG_CFR2_STR0_DDUC0_PORT2_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG17_REG_CFR2_STR0_DDUC0_PORT2_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG17_REG_CFR2_STR0_DDUC0_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 0.  */
#define CSL_DFE_SUMMER_CFG17_REG_CFR2_STR0_DDUC1_PORT0_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG17_REG_CFR2_STR0_DDUC1_PORT0_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG17_REG_CFR2_STR0_DDUC1_PORT0_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG17_REG_ADDR (0x00000048u)
#define CSL_DFE_SUMMER_CFG17_REG_RESETVAL (0x00000000u)

/* CFG18 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr2_str0_dduc2_port1 : 4;
    Uint32 cfr2_str0_dduc2_port0 : 4;
    Uint32 cfr2_str0_dduc1_port2 : 4;
    Uint32 cfr2_str0_dduc1_port1 : 4;
#else 
    Uint32 cfr2_str0_dduc1_port1 : 4;
    Uint32 cfr2_str0_dduc1_port2 : 4;
    Uint32 cfr2_str0_dduc2_port0 : 4;
    Uint32 cfr2_str0_dduc2_port1 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG18_REG;

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 0.  */
#define CSL_DFE_SUMMER_CFG18_REG_CFR2_STR0_DDUC1_PORT1_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG18_REG_CFR2_STR0_DDUC1_PORT1_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG18_REG_CFR2_STR0_DDUC1_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 0.  */
#define CSL_DFE_SUMMER_CFG18_REG_CFR2_STR0_DDUC1_PORT2_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG18_REG_CFR2_STR0_DDUC1_PORT2_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG18_REG_CFR2_STR0_DDUC1_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 0.  */
#define CSL_DFE_SUMMER_CFG18_REG_CFR2_STR0_DDUC2_PORT0_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG18_REG_CFR2_STR0_DDUC2_PORT0_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG18_REG_CFR2_STR0_DDUC2_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 0.  */
#define CSL_DFE_SUMMER_CFG18_REG_CFR2_STR0_DDUC2_PORT1_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG18_REG_CFR2_STR0_DDUC2_PORT1_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG18_REG_CFR2_STR0_DDUC2_PORT1_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG18_REG_ADDR (0x0000004Cu)
#define CSL_DFE_SUMMER_CFG18_REG_RESETVAL (0x00000000u)

/* CFG19 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr2_str0_dduc3_port2 : 4;
    Uint32 cfr2_str0_dduc3_port1 : 4;
    Uint32 cfr2_str0_dduc3_port0 : 4;
    Uint32 cfr2_str0_dduc2_port2 : 4;
#else 
    Uint32 cfr2_str0_dduc2_port2 : 4;
    Uint32 cfr2_str0_dduc3_port0 : 4;
    Uint32 cfr2_str0_dduc3_port1 : 4;
    Uint32 cfr2_str0_dduc3_port2 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG19_REG;

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 0.  */
#define CSL_DFE_SUMMER_CFG19_REG_CFR2_STR0_DDUC2_PORT2_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG19_REG_CFR2_STR0_DDUC2_PORT2_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG19_REG_CFR2_STR0_DDUC2_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 0.  */
#define CSL_DFE_SUMMER_CFG19_REG_CFR2_STR0_DDUC3_PORT0_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG19_REG_CFR2_STR0_DDUC3_PORT0_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG19_REG_CFR2_STR0_DDUC3_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 0.  */
#define CSL_DFE_SUMMER_CFG19_REG_CFR2_STR0_DDUC3_PORT1_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG19_REG_CFR2_STR0_DDUC3_PORT1_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG19_REG_CFR2_STR0_DDUC3_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 0.  */
#define CSL_DFE_SUMMER_CFG19_REG_CFR2_STR0_DDUC3_PORT2_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG19_REG_CFR2_STR0_DDUC3_PORT2_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG19_REG_CFR2_STR0_DDUC3_PORT2_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG19_REG_ADDR (0x00000050u)
#define CSL_DFE_SUMMER_CFG19_REG_RESETVAL (0x00000000u)

/* CFG20 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr2_str1_dduc1_port0 : 4;
    Uint32 cfr2_str1_dduc0_port2 : 4;
    Uint32 cfr2_str1_dduc0_port1 : 4;
    Uint32 cfr2_str1_dduc0_port0 : 4;
#else 
    Uint32 cfr2_str1_dduc0_port0 : 4;
    Uint32 cfr2_str1_dduc0_port1 : 4;
    Uint32 cfr2_str1_dduc0_port2 : 4;
    Uint32 cfr2_str1_dduc1_port0 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG20_REG;

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 1.  */
#define CSL_DFE_SUMMER_CFG20_REG_CFR2_STR1_DDUC0_PORT0_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG20_REG_CFR2_STR1_DDUC0_PORT0_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG20_REG_CFR2_STR1_DDUC0_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 1.  */
#define CSL_DFE_SUMMER_CFG20_REG_CFR2_STR1_DDUC0_PORT1_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG20_REG_CFR2_STR1_DDUC0_PORT1_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG20_REG_CFR2_STR1_DDUC0_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 1.  */
#define CSL_DFE_SUMMER_CFG20_REG_CFR2_STR1_DDUC0_PORT2_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG20_REG_CFR2_STR1_DDUC0_PORT2_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG20_REG_CFR2_STR1_DDUC0_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 1.  */
#define CSL_DFE_SUMMER_CFG20_REG_CFR2_STR1_DDUC1_PORT0_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG20_REG_CFR2_STR1_DDUC1_PORT0_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG20_REG_CFR2_STR1_DDUC1_PORT0_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG20_REG_ADDR (0x00000054u)
#define CSL_DFE_SUMMER_CFG20_REG_RESETVAL (0x00000000u)

/* CFG21 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr2_str1_dduc2_port1 : 4;
    Uint32 cfr2_str1_dduc2_port0 : 4;
    Uint32 cfr2_str1_dduc1_port2 : 4;
    Uint32 cfr2_str1_dduc1_port1 : 4;
#else 
    Uint32 cfr2_str1_dduc1_port1 : 4;
    Uint32 cfr2_str1_dduc1_port2 : 4;
    Uint32 cfr2_str1_dduc2_port0 : 4;
    Uint32 cfr2_str1_dduc2_port1 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG21_REG;

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 1.  */
#define CSL_DFE_SUMMER_CFG21_REG_CFR2_STR1_DDUC1_PORT1_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG21_REG_CFR2_STR1_DDUC1_PORT1_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG21_REG_CFR2_STR1_DDUC1_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 1.  */
#define CSL_DFE_SUMMER_CFG21_REG_CFR2_STR1_DDUC1_PORT2_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG21_REG_CFR2_STR1_DDUC1_PORT2_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG21_REG_CFR2_STR1_DDUC1_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 1.  */
#define CSL_DFE_SUMMER_CFG21_REG_CFR2_STR1_DDUC2_PORT0_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG21_REG_CFR2_STR1_DDUC2_PORT0_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG21_REG_CFR2_STR1_DDUC2_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 1.  */
#define CSL_DFE_SUMMER_CFG21_REG_CFR2_STR1_DDUC2_PORT1_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG21_REG_CFR2_STR1_DDUC2_PORT1_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG21_REG_CFR2_STR1_DDUC2_PORT1_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG21_REG_ADDR (0x00000058u)
#define CSL_DFE_SUMMER_CFG21_REG_RESETVAL (0x00000000u)

/* CFG22 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr2_str1_dduc3_port2 : 4;
    Uint32 cfr2_str1_dduc3_port1 : 4;
    Uint32 cfr2_str1_dduc3_port0 : 4;
    Uint32 cfr2_str1_dduc2_port2 : 4;
#else 
    Uint32 cfr2_str1_dduc2_port2 : 4;
    Uint32 cfr2_str1_dduc3_port0 : 4;
    Uint32 cfr2_str1_dduc3_port1 : 4;
    Uint32 cfr2_str1_dduc3_port2 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG22_REG;

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 1.  */
#define CSL_DFE_SUMMER_CFG22_REG_CFR2_STR1_DDUC2_PORT2_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG22_REG_CFR2_STR1_DDUC2_PORT2_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG22_REG_CFR2_STR1_DDUC2_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 1.  */
#define CSL_DFE_SUMMER_CFG22_REG_CFR2_STR1_DDUC3_PORT0_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG22_REG_CFR2_STR1_DDUC3_PORT0_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG22_REG_CFR2_STR1_DDUC3_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 1.  */
#define CSL_DFE_SUMMER_CFG22_REG_CFR2_STR1_DDUC3_PORT1_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG22_REG_CFR2_STR1_DDUC3_PORT1_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG22_REG_CFR2_STR1_DDUC3_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr2 stream 1.  */
#define CSL_DFE_SUMMER_CFG22_REG_CFR2_STR1_DDUC3_PORT2_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG22_REG_CFR2_STR1_DDUC3_PORT2_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG22_REG_CFR2_STR1_DDUC3_PORT2_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG22_REG_ADDR (0x0000005Cu)
#define CSL_DFE_SUMMER_CFG22_REG_RESETVAL (0x00000000u)

/* CFG23 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr3_str0_dduc1_port0 : 4;
    Uint32 cfr3_str0_dduc0_port2 : 4;
    Uint32 cfr3_str0_dduc0_port1 : 4;
    Uint32 cfr3_str0_dduc0_port0 : 4;
#else 
    Uint32 cfr3_str0_dduc0_port0 : 4;
    Uint32 cfr3_str0_dduc0_port1 : 4;
    Uint32 cfr3_str0_dduc0_port2 : 4;
    Uint32 cfr3_str0_dduc1_port0 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG23_REG;

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 0.  */
#define CSL_DFE_SUMMER_CFG23_REG_CFR3_STR0_DDUC0_PORT0_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG23_REG_CFR3_STR0_DDUC0_PORT0_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG23_REG_CFR3_STR0_DDUC0_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 0.  */
#define CSL_DFE_SUMMER_CFG23_REG_CFR3_STR0_DDUC0_PORT1_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG23_REG_CFR3_STR0_DDUC0_PORT1_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG23_REG_CFR3_STR0_DDUC0_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 0.  */
#define CSL_DFE_SUMMER_CFG23_REG_CFR3_STR0_DDUC0_PORT2_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG23_REG_CFR3_STR0_DDUC0_PORT2_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG23_REG_CFR3_STR0_DDUC0_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 0.  */
#define CSL_DFE_SUMMER_CFG23_REG_CFR3_STR0_DDUC1_PORT0_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG23_REG_CFR3_STR0_DDUC1_PORT0_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG23_REG_CFR3_STR0_DDUC1_PORT0_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG23_REG_ADDR (0x00000060u)
#define CSL_DFE_SUMMER_CFG23_REG_RESETVAL (0x00000000u)

/* CFG24 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr3_str0_dduc2_port1 : 4;
    Uint32 cfr3_str0_dduc2_port0 : 4;
    Uint32 cfr3_str0_dduc1_port2 : 4;
    Uint32 cfr3_str0_dduc1_port1 : 4;
#else 
    Uint32 cfr3_str0_dduc1_port1 : 4;
    Uint32 cfr3_str0_dduc1_port2 : 4;
    Uint32 cfr3_str0_dduc2_port0 : 4;
    Uint32 cfr3_str0_dduc2_port1 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG24_REG;

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 0.  */
#define CSL_DFE_SUMMER_CFG24_REG_CFR3_STR0_DDUC1_PORT1_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG24_REG_CFR3_STR0_DDUC1_PORT1_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG24_REG_CFR3_STR0_DDUC1_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 0.  */
#define CSL_DFE_SUMMER_CFG24_REG_CFR3_STR0_DDUC1_PORT2_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG24_REG_CFR3_STR0_DDUC1_PORT2_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG24_REG_CFR3_STR0_DDUC1_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 0.  */
#define CSL_DFE_SUMMER_CFG24_REG_CFR3_STR0_DDUC2_PORT0_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG24_REG_CFR3_STR0_DDUC2_PORT0_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG24_REG_CFR3_STR0_DDUC2_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 0.  */
#define CSL_DFE_SUMMER_CFG24_REG_CFR3_STR0_DDUC2_PORT1_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG24_REG_CFR3_STR0_DDUC2_PORT1_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG24_REG_CFR3_STR0_DDUC2_PORT1_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG24_REG_ADDR (0x00000064u)
#define CSL_DFE_SUMMER_CFG24_REG_RESETVAL (0x00000000u)

/* CFG25 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr3_str0_dduc3_port2 : 4;
    Uint32 cfr3_str0_dduc3_port1 : 4;
    Uint32 cfr3_str0_dduc3_port0 : 4;
    Uint32 cfr3_str0_dduc2_port2 : 4;
#else 
    Uint32 cfr3_str0_dduc2_port2 : 4;
    Uint32 cfr3_str0_dduc3_port0 : 4;
    Uint32 cfr3_str0_dduc3_port1 : 4;
    Uint32 cfr3_str0_dduc3_port2 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG25_REG;

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 0.  */
#define CSL_DFE_SUMMER_CFG25_REG_CFR3_STR0_DDUC2_PORT2_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG25_REG_CFR3_STR0_DDUC2_PORT2_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG25_REG_CFR3_STR0_DDUC2_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 0.  */
#define CSL_DFE_SUMMER_CFG25_REG_CFR3_STR0_DDUC3_PORT0_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG25_REG_CFR3_STR0_DDUC3_PORT0_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG25_REG_CFR3_STR0_DDUC3_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 0.  */
#define CSL_DFE_SUMMER_CFG25_REG_CFR3_STR0_DDUC3_PORT1_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG25_REG_CFR3_STR0_DDUC3_PORT1_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG25_REG_CFR3_STR0_DDUC3_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 0.  */
#define CSL_DFE_SUMMER_CFG25_REG_CFR3_STR0_DDUC3_PORT2_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG25_REG_CFR3_STR0_DDUC3_PORT2_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG25_REG_CFR3_STR0_DDUC3_PORT2_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG25_REG_ADDR (0x00000068u)
#define CSL_DFE_SUMMER_CFG25_REG_RESETVAL (0x00000000u)

/* CFG26 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr3_str1_dduc1_port0 : 4;
    Uint32 cfr3_str1_dduc0_port2 : 4;
    Uint32 cfr3_str1_dduc0_port1 : 4;
    Uint32 cfr3_str1_dduc0_port0 : 4;
#else 
    Uint32 cfr3_str1_dduc0_port0 : 4;
    Uint32 cfr3_str1_dduc0_port1 : 4;
    Uint32 cfr3_str1_dduc0_port2 : 4;
    Uint32 cfr3_str1_dduc1_port0 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG26_REG;

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 1.  */
#define CSL_DFE_SUMMER_CFG26_REG_CFR3_STR1_DDUC0_PORT0_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG26_REG_CFR3_STR1_DDUC0_PORT0_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG26_REG_CFR3_STR1_DDUC0_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 1.  */
#define CSL_DFE_SUMMER_CFG26_REG_CFR3_STR1_DDUC0_PORT1_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG26_REG_CFR3_STR1_DDUC0_PORT1_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG26_REG_CFR3_STR1_DDUC0_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 0 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 1.  */
#define CSL_DFE_SUMMER_CFG26_REG_CFR3_STR1_DDUC0_PORT2_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG26_REG_CFR3_STR1_DDUC0_PORT2_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG26_REG_CFR3_STR1_DDUC0_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 1.  */
#define CSL_DFE_SUMMER_CFG26_REG_CFR3_STR1_DDUC1_PORT0_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG26_REG_CFR3_STR1_DDUC1_PORT0_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG26_REG_CFR3_STR1_DDUC1_PORT0_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG26_REG_ADDR (0x0000006Cu)
#define CSL_DFE_SUMMER_CFG26_REG_RESETVAL (0x00000000u)

/* CFG27 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr3_str1_dduc2_port1 : 4;
    Uint32 cfr3_str1_dduc2_port0 : 4;
    Uint32 cfr3_str1_dduc1_port2 : 4;
    Uint32 cfr3_str1_dduc1_port1 : 4;
#else 
    Uint32 cfr3_str1_dduc1_port1 : 4;
    Uint32 cfr3_str1_dduc1_port2 : 4;
    Uint32 cfr3_str1_dduc2_port0 : 4;
    Uint32 cfr3_str1_dduc2_port1 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG27_REG;

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 1.  */
#define CSL_DFE_SUMMER_CFG27_REG_CFR3_STR1_DDUC1_PORT1_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG27_REG_CFR3_STR1_DDUC1_PORT1_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG27_REG_CFR3_STR1_DDUC1_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 1 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 1.  */
#define CSL_DFE_SUMMER_CFG27_REG_CFR3_STR1_DDUC1_PORT2_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG27_REG_CFR3_STR1_DDUC1_PORT2_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG27_REG_CFR3_STR1_DDUC1_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 1.  */
#define CSL_DFE_SUMMER_CFG27_REG_CFR3_STR1_DDUC2_PORT0_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG27_REG_CFR3_STR1_DDUC2_PORT0_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG27_REG_CFR3_STR1_DDUC2_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 1.  */
#define CSL_DFE_SUMMER_CFG27_REG_CFR3_STR1_DDUC2_PORT1_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG27_REG_CFR3_STR1_DDUC2_PORT1_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG27_REG_CFR3_STR1_DDUC2_PORT1_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG27_REG_ADDR (0x00000070u)
#define CSL_DFE_SUMMER_CFG27_REG_RESETVAL (0x00000000u)

/* CFG28 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr3_str1_dduc3_port2 : 4;
    Uint32 cfr3_str1_dduc3_port1 : 4;
    Uint32 cfr3_str1_dduc3_port0 : 4;
    Uint32 cfr3_str1_dduc2_port2 : 4;
#else 
    Uint32 cfr3_str1_dduc2_port2 : 4;
    Uint32 cfr3_str1_dduc3_port0 : 4;
    Uint32 cfr3_str1_dduc3_port1 : 4;
    Uint32 cfr3_str1_dduc3_port2 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_SUMMER_CFG28_REG;

/* LSB corrosponds to Carrier 0 on DDUC 2 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 1.  */
#define CSL_DFE_SUMMER_CFG28_REG_CFR3_STR1_DDUC2_PORT2_MASK (0x0000000Fu)
#define CSL_DFE_SUMMER_CFG28_REG_CFR3_STR1_DDUC2_PORT2_SHIFT (0x00000000u)
#define CSL_DFE_SUMMER_CFG28_REG_CFR3_STR1_DDUC2_PORT2_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 0,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 1.  */
#define CSL_DFE_SUMMER_CFG28_REG_CFR3_STR1_DDUC3_PORT0_MASK (0x000000F0u)
#define CSL_DFE_SUMMER_CFG28_REG_CFR3_STR1_DDUC3_PORT0_SHIFT (0x00000004u)
#define CSL_DFE_SUMMER_CFG28_REG_CFR3_STR1_DDUC3_PORT0_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 1,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 1.  */
#define CSL_DFE_SUMMER_CFG28_REG_CFR3_STR1_DDUC3_PORT1_MASK (0x00000F00u)
#define CSL_DFE_SUMMER_CFG28_REG_CFR3_STR1_DDUC3_PORT1_SHIFT (0x00000008u)
#define CSL_DFE_SUMMER_CFG28_REG_CFR3_STR1_DDUC3_PORT1_RESETVAL (0x00000000u)

/* LSB corrosponds to Carrier 0 on DDUC 3 Port 2,second bit corrosponds to Carrier 1,Third bit corrosponds to Carrier 2 and MSB corrosponds to carrier 3.Set to 1 to sum onto cfr3 stream 1.  */
#define CSL_DFE_SUMMER_CFG28_REG_CFR3_STR1_DDUC3_PORT2_MASK (0x0000F000u)
#define CSL_DFE_SUMMER_CFG28_REG_CFR3_STR1_DDUC3_PORT2_SHIFT (0x0000000Cu)
#define CSL_DFE_SUMMER_CFG28_REG_CFR3_STR1_DDUC3_PORT2_RESETVAL (0x00000000u)

#define CSL_DFE_SUMMER_CFG28_REG_ADDR (0x00000074u)
#define CSL_DFE_SUMMER_CFG28_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_SUMMER_H__ */

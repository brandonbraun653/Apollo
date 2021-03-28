/******************************************************************************
 * Copyright (c) 2016-2017 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/
/*
 *  Linker command file
 *
 */

-c
-heap  0x41000
-stack 0xa000

/* Memory Map 1 - the default */
MEMORY
{
    L1PSRAM (RWX)  : org = 0x0E00000, len = 0x7FFF
    L1DSRAM (RWX)  : org = 0x0F00000, len = 0x7FFF 

    L2SRAM (RWX)   : org = 0x0800000, len = 0x47FFF
    DDR3 (RWX)     : org = 0x80000000,len = 0x10000000
}


SECTIONS
{
    .text:_c_int00 > DDR3
    .text:_isr     > DDR3   /* ISR CODE SPACE                    */
	.cachetest_ddrbuf > DDR3
    .text          > DDR3   /* CODE                              */
    .bss           > DDR3
    .data          > DDR3   /* GLOBAL & STATIC VARS              */
    .sysmem        > DDR3   /* DYNAMIC MEMORY ALLOCATION AREA    */
    .stack         > DDR3   /* SOFTWARE SYSTEM STACK             */

    .cinit         > DDR3   /* INITIALIZATION TABLES             */
    .const         > DDR3   /* CONSTANT DATA                     */
    .cio           > DDR3   /* C I/O BUFFER                      */
    .testData      > DDR3
    .init_array    > DDR3
    test_data      > DDR3
}

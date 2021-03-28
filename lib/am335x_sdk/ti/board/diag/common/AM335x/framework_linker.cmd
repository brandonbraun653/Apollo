/**
 *  ============================================================================
 *  @n   (C) Copyright 2015-2017, Texas Instruments, Inc.
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

/*
** The stack is kept at end of the image, and its size is 128 MB.
** The heap section is placed above the stack to support I/O
** operations using semi-hosting. The size of the section is 2KB.
*/

MEMORY
{
	DDR0 :              org = 0x80000000,   len = 0x40000000
	DDR0_MEMTEST : 		org = 0x80000000,   len = 0x0000A000 /* 36KB mem test */
    DIAG_MEM (RWIX):    org = 0x402F0400,   len = 0x0001FC00 /* 127KB SRAM Internal(63KB) and OCMC RAM(64KB) */ 
    SBL_MEM (RWIX):     org = 0x402F0400,   len = 0x0001FC00 /* 127KB SRAM Internal(63KB) and OCMC RAM(64KB) */ 
    OCMC_RAM (RWIX):    org = 0x40300000,   len = 0x00010000 /* 64KB OCMC SRAM*/	
}

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

SECTIONS
{
        .startcode :
        {
            . = ALIGN(4);
            *framework_entry.ao      (.text) 
        } >DIAG_MEM
		
        .text :
        {
            . = ALIGN(4);
            *(.text*)
            *(.rodata*)
        } >DIAG_MEM

        .data :
        {
            . = ALIGN(4);
            *(.data*)
        } >DIAG_MEM

        .bss :
        {
            . = ALIGN(4);
            _bss_start = .;
            *(.bss*)
            *(COMMON)
            _bss_end = .;
        } >DIAG_MEM

        .heap :
        {
            . = ALIGN(4);
            __end__ = .;
            end = __end__;
            __HeapBase = __end__;
            *(.heap*)
            . = . + 0x1000;
            __HeapLimit = .;
        } >DIAG_MEM

        .stack :
        {
            . = ALIGN(8);
            __StackLimit = . ;
            *(.stack*)
            . = . + 0x1000;
            __StackTop = .;
        } >DIAG_MEM
        _stack = __StackTop;
}
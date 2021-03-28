/**
 *  ============================================================================
 *  @n   (C) Copyright 2017, Texas Instruments, Inc.
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
    DIAG_MEM (RWIX):    org = 0x40340000,   len = 0x00040000
    SBL_MEM (RWIX):     org = 0x40330000,   len = 0x0004FFFF 
    OCMC_RAM1 (RWIX):   org = 0x40300000,   len = 0x00030000
}

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

SECTIONS
{
        .startcode :
        {
            . = ALIGN(4);
            *init.o      (.text)
        } >DDR0

        .text :
        {
            . = ALIGN(4);
            *(.text*)
            *(.rodata*)
        } >DDR0

        .data :
        {
            . = ALIGN(4);
            *(.data*)
        } >DDR0

        .bss :
        {
            . = ALIGN(4);
            _bss_start = .;
            *(.bss*)
            *(COMMON)
            _bss_end = .;
        } >DDR0

        .heap :
        {
            . = ALIGN(4);
            __end__ = .;
            end = __end__;
            __HeapBase = __end__;
            *(.heap*)
            . = . + 0x1000;
            __HeapLimit = .;
        } >DDR0

        .stack :
        {
            . = ALIGN(8);
            __StackLimit = . ;
            *(.stack*)
            . = . + 0x10000;
            __StackTop = .;
        } >DDR0
        _stack = __StackTop;

        BOARD_IO_DELAY_CODE :
        {
            . = ALIGN(4);
            *(BOARD_IO_DELAY_CODE*)
        } > OCMC_RAM1

        BOARD_IO_DELAY_DATA :
        {
            . = ALIGN(4);
            *(BOARD_IO_DELAY_DATA*)
        } > OCMC_RAM1
}


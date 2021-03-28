/**
 *  \file linker.cmd
 *
 *  \brief This file is the linker script for am5x.
 *
 */

/*
 * Copyright (C) 2018-2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

MEMORY
{
    OCMC_RAM  (RWIX): org = 0x40331000, len = 0x0004EFFF  /* OCMCRAM Region meant for flash programmer */
}

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

SECTIONS
{
        .startcode :
        {
            . = ALIGN(4);
            *(.public.*)
            *sbl_init.ao (.text) /* Need to check sbl_init.ao */
        } >OCMC_RAM

        .text :
        {
            . = ALIGN(4);
            *(.text*)
            *(.rodata*)
        } >OCMC_RAM

        .data :
        {
            . = ALIGN(4);
            *(.data*)
        } >OCMC_RAM

        .bss :
        {
            . = ALIGN(4);
            _bss_start = .;
            *(.bss*)
            *(COMMON)
            _bss_end = .;
        } >OCMC_RAM

        .heap :
        {
            . = ALIGN(4);
            __end__ = .;
            end = __end__;
            __HeapBase = __end__;
            *(.heap*)
            . = . + 0x400;
            __HeapLimit = .;
        } >OCMC_RAM

        .stack :
        {
            . = ALIGN(8);
            __StackLimit = . ;
            *(.stack*)
            . = . + 0x10000;
            __StackTop = .;
        } >OCMC_RAM
        _stack = __StackTop;
}

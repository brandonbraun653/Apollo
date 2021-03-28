/**
 *  ============================================================================
 *  @n   (C) Copyright 2016-2017, Texas Instruments, Inc.
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
    VECS     (RWIX):    org = 0x0C000000,   len = 0x400       /* Vector area */
    DIAG_MEM (RWIX):    org = 0x0C060000,   len = 0x00050000
    DDR3_MEM (RWIX):    org = 0x80000000,   len = 0x00100000
    APP_CACHED_DATA_BLK1_MEM (RWIX): org = 0x80100000,   len = 0x00100000 
}

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

SECTIONS
{
        .startcode :
        {
            . = ALIGN(4);
            *init.o      (.text)
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
        } >DDR3_MEM

        .bss :
        {
            . = ALIGN(4);
            _bss_start = .;
            *(.bss*)
            *(COMMON)
            _bss_end = .;
        } >DDR3_MEM

        .heap :
        {
            . = ALIGN(4);
            __end__ = .;
            end = __end__;
            __HeapBase = __end__;
            *(.heap*)
            . = . + 0x40000;
            __HeapLimit = .;
        } >DDR3_MEM

        .stack :
        {
            . = ALIGN(8);
            __StackLimit = . ;
            *(.stack*)
            . = . + 0x8000;
            __StackTop = .;
        } >DDR3_MEM
        _stack = __StackTop;

        BOARD_IO_DELAY_CODE :
        {
            . = ALIGN(4);
            *(BOARD_IO_DELAY_CODE*)
        } > DIAG_MEM

        BOARD_IO_DELAY_DATA :
        {
            . = ALIGN(4);
            *(BOARD_IO_DELAY_DATA*)
        } > DIAG_MEM

        __vector_base__ = ORIGIN(VECS);

        PRU0_REV2_IMEM : {
        pru_imem0_rev2_start = .;
        KEEP(*(PRU0_REV2_IMEM))
        pru_imem0_rev2_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU0_REV2_DMEM : {
        pru_dmem0_rev2_start = .;
        KEEP (*(PRU0_REV2_DMEM))
        pru_dmem0_rev2_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU0_REV2_EXT : {
        KEEP (*(PRU0_REV2_EXT))
    } > APP_CACHED_DATA_BLK1_MEM
    PRU1_REV2_IMEM : {
        pru_imem1_rev2_start = .;
        KEEP (*(PRU1_REV2_IMEM))
        pru_imem1_rev2_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU1_REV2_DMEM : {
        pru_dmem1_rev2_start = .;
        KEEP (*(PRU1_REV2_DMEM))
        pru_dmem1_rev2_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU1_REV2_EXT : {
        KEEP (*(PRU1_REV2_EXT))
    } > APP_CACHED_DATA_BLK1_MEM
}


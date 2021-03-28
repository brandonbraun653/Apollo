/**
 *  \file  k2g_ddr.lds
 *
 *  \brief This file is the linker script for k2g required for building
 *         applications with the gcc toolchain.
 *
 *  \copyright Copyright (C) 2016 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
    DDR3_A15 :   o = 0x80000000,     l = 0x10000000     /* 256MB external DDR Bank 0 */
    MSMCRAM :   o = 0x0C000000,      l = 0x000FFDFF     /* internal RAM */
	VECS :      o = 0x0C0FFC00,  l = 0x400       /* Vector area */
}


SECTIONS
{
	BOARD_IO_DELAY_DATA : {*(BOARD_IO_DELAY_DATA)}  AT> MSMCRAM
	BOARD_IO_DELAY_CODE : {*(BOARD_IO_DELAY_CODE)}  AT> MSMCRAM
        .text        : {*(.text)}         > DDR3_A15
	.data        : {*(.data)}	        > DDR3_A15
	.sbl_reg_log_bfr ALIGN(0x4): {} > MSMCRAM
	.bss ALIGN(0x4):
	{
		_bss_start = . ;
		*(.bss.*) *(COMMON);
		_bss_end = . ;
	}	> DDR3_A15

	. = ALIGN(4);
	_end = .;
	PROVIDE (end = .);

	.stack ALIGN(0x8):
	{
		stack_start = .;
		*(.stack.*) ;
		. = . + 0x3000;
		stack_end = .;
	}	> DDR3_A15

	. = ALIGN(4);
	__exidx_start = .;
	PROVIDE(__exidx_start = __exidx_start);

	.ARM.exidx :
	{
		*(.ARM.exidx* .gnu.linkonce.armexidx.*);
	} > DDR3_A15

	. = ALIGN(4);
	__exidx_end = .;
	PROVIDE(__exidx_end = __exidx_end);

	.const     ALIGN(0x4): {*(.const)}	    > DDR3_A15
	.my_sect_ddr ALIGN(0x4): {*(.my_sect_ddr)}  > DDR3_A15

	_stack = stack_end;
}





/*
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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

-e Entry
-heap  0x8000
-stack 0x2000

MEMORY
{
	DDR_MEM   : o = 0xC1080000  l = 0x2F7FFFF  /* 256MB SDRAM Data */
}

SECTIONS
{
    .text          >  DDR_MEM
    .stack         >  DDR_MEM
	                RUN_START(stackStart)
                    RUN_END(stackEnd)
    .bss           >  DDR_MEM
	                RUN_START(bss_start)
                    RUN_END(bss_end)
    .cio           >  DDR_MEM
    .const         >  DDR_MEM
    .data          >  DDR_MEM
    .switch        >  DDR_MEM
    .sysmem        >  DDR_MEM
    .far           >  DDR_MEM
    .args          >  DDR_MEM
    .ppinfo        >  DDR_MEM
    .ppdata        >  DDR_MEM
    .pinit         >  DDR_MEM
    .cinit         >  DDR_MEM
    .binit         >  DDR_MEM
    .init_array    >  DDR_MEM
    .neardata      >  DDR_MEM
    .fardata       >  DDR_MEM
    .rodata        >  DDR_MEM
}

/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

#include "a15.h"

void setNSMode()
{
    /* Set bit 10 and 11 in NSACR to allow NS access to cp10 and cp11 */
    asm("MRC p15, 0, r0, c1, c1, 2\n");
    asm("ORR r0, r0, #0x00000C00\n");
    asm("MCR p15, 0, r0, c1, c1, 2\n");

    /* Set bit 0 in SCR for NS mode */
    asm("MRC p15, 0, r0, c1, c1, 0\n");
    asm("ORR r0, r0, #0x1\n");
    asm("MCR p15, 0, r0, c1, c1, 0\n");
}

void a15EnableNeon()
{
    asm("MRC p15, #0, r1, c1, c0, #2\n");
    asm("ORR r1, r1, #(0xf << 20)\n");
    asm("MCR p15, #0, r1, c1, c0, #2\n");
    asm("MOV r1, #0\n");
}

void a15EnableVFP11co()
{
    asm("MCR p15, #0, r1, c7, c5, #4\n");
    asm("MOV r0,#0x40000000\n");
    asm("FMXR FPEXC, r0\n");
}

void a15EnableSMP()
{
    asm("MRC p15, #0, r1, c1, c0, #1\n");
    asm("ORR r1, r1, #(0x1 << 6)\n");
    asm("MCR p15, #0, r1, c1, c0, #1\n");
}

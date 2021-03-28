/**
 *  \file     linker_osal_m4.cmd
 *
 *  \brief    This file contains the System Memory Map used by OSAL test example for AM574x SoC.
 *
 *  \copyright Copyright (C) 2017 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
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

-stack  0x1000                            /* SOFTWARE STACK SIZE */
-heap   0x1000                            /* HEAP AREA SIZE */

/* SPECIFY THE SYSTEM MEMORY MAP */

MEMORY
{
    DDR3 (RWX)     : org = 0x80000000,len = 0x10000000
}

/* SPECIFY THE SECTIONS ALLOCATION INTO MEMORY */

SECTIONS
{
    .intvecs     : load > DDR3
    .intc_text   : load > DDR3
    .m4_init     : load > DDR3
    .init        : load > DDR3

    .text        : load > DDR3      /* CODE */
    .data        : load > DDR3      /* INITIALIZED GLOBAL AND STATIC VARIABLES */
    .bss         : load > DDR3      /* UNINITIALIZED OR ZERO INITIALIZED */
                                          /* GLOBAL & STATIC VARIABLES */
                    RUN_START(bssStart)
                    RUN_END(bssEnd)
    .const       : load > DDR3      /* GLOBAL CONSTANTS */
    .cinit       : load > DDR3
    .stack       : load > DDR3      /* SOFTWARE SYSTEM STACK */
                    RUN_START(stackStart)
                    RUN_END(stackEnd)
    .plt         : load > DDR3
    .sysmem      : load > DDR3

}

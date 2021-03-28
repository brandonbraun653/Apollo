@******************************************************************************
@
@ pub2mon.s - The ARM processors which support secure and non secure modes
@       restricts access to some registers to secure privileged mode only. For
@       Non secure software to configure those registers secure monitors API's
@       (SMC) are provided. This file defines the SMC API, which takes the 
@       appropriate parameters and returns valued based on operation requested.
@
@ Note: This file is generic enough to be placed under \\soc\<compiler>, but to
@       avoid multiple compiler specific folder currently this file is placed 
@       under \\soc\<arch>\<compiler>
@
@******************************************************************************
@
@ Copyright (C) 2013 Texas InSTRuments Incorporated - http://www.ti.com/
@
@  RediSTRibution and use in source and binary forms, with or without
@  modification, are permitted provided that the following conditions
@  are met:
@
@    RediSTRibutions of source code must retain the above copyright
@    notice, this list of conditions and the following disclaimer.
@
@    RediSTRibutions in binary form must reproduce the above copyright
@    notice, this list of conditions and the following disclaimer in the
@    documentation and/or other materials provided with the
@    diSTRibution.
@
@    Neither the name of Texas InSTRuments Incorporated nor the names of
@    its contributors may be used to endorse or promote products derived
@    from this software without specific prior written permission.
@
@  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
@  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
@  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
@  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
@  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
@  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
@  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
@  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
@  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
@  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
@  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
@
@******************************************************************************

@****************************** Global Symbols*********************************
        .global Pub2MonDispatch

@**************************** Code section ************************************
        .text

        @ This code is assembled for ARM instructions as these routines are not
        @ needed in secure mode.
        .code 32


@******************************************************************************
@ Function prototype: uint64_t Pub2MonDispatch(uint32_t smc_id, uint32_t param1,
@                                      uint32_t param2)
@
@ smc_id - Passed via r0, SMC ID of the functionality as defined in device
@          data sheet or TRM.
@ Param1 - Passed via r1, if not applicable for specific id pass 0.
@ Param2 - Passed via r2, if not applicable for specific id pass 0.
@
@ return - return value will be passed in r0 & r1 registers.
@
@ This is a secure monitor API which can be used to modify the secure registers.
@ A few cpu registers including lr will be modified by the smc, so they need to
@ be backed up.
@
@******************************************************************************
Pub2MonDispatch:
    stmfd   sp!, {r4-r12, lr}
    mov     r12, r0
    mov     r0, r1
    mov     r1, r2
    dsb
    smc #0
    ldmfd   sp!, {r4-r12, pc}

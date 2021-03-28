@******************************************************************************
@
@ \file   profilingHooksArmV7_AAssembly.asm
@
@ \brief  proliling hooks function.
@
@******************************************************************************
@ Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
@
@
@  Redistribution and use in source and binary forms, with or without
@  modification, are permitted provided that the following conditions
@  are met:
@
@    Redistributions of source code must retain the above copyright
@    notice, this list of conditions and the following disclaimer.
@
@    Redistributions in binary form must reproduce the above copyright
@    notice, this list of conditions and the following disclaimer in the
@    documentation and/or other materials provided with the
@    distribution.
@
@    Neither the name of Texas Instruments Incorporated nor the names of
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

@******************************************************************************
@*                               INCLUDE FILES
@******************************************************************************

@******************************************************************************
@*                                  SYMBOLS
@****************************************************************************** 

        .global	__cyg_profile_func_enter
        .global	__cyg_profile_func_exit
        .global	mySwitch
        .global	elemlog
        .global	log_idx

@******************************************************************************
@*                                 CODE SECTION
@******************************************************************************
        .text

        @ This code is assembled for ARM instructions
        .code 32

@******************************************************************************
@*                                 ASSEMBLY ROUTINES
@******************************************************************************     

@*****************************************************************************
@ This API logs the entry hooks.
@*****************************************************************************
__cyg_profile_func_enter:
	mov	ip, sp
	stmfd	sp!, {r4, r5, r6, r7, fp, ip, lr, pc}
	sub	fp, ip, #4
	mov	r7, r0
	mov	r6, r1
	MRC     p15, 0, r5, c9, c13, 0	
	movw	r4, #:lower16:log_idx
	movt	r4, #:upper16:log_idx
	ldr	r3, [r4]
	cmp	r3, #0
	beq	.L5
.L2:
	cmp	r3, #1048576
	bcs	.L1
	movw	r2, #:lower16:elemlog
	mov	r0, #1
	movt	r2, #:upper16:elemlog
	add	r1, r3, r0
	add	ip, r2, r3, asl #4
	str	r0, [r2, r3, asl #4]
	str	r1, [r4]
	str	r7, [ip, #4]
	str	r6, [ip, #8]
	str	r5, [ip, #12]
.L1:
	sub	sp, fp, #28
	ldmfd	sp, {r4, r5, r6, r7, fp, sp, pc}
.L5:
	bl	profiling_init
	ldr	r3, [r4]
	b	.L2

@*****************************************************************************
@ This API logs the exit hooks. 
@*****************************************************************************
__cyg_profile_func_exit:
	stmfd	sp!, {r4, r5, lr}
	MRC p15, 0, lr, c9, c13, 0	
	movw	r3, #:lower16:log_idx
	movt	r3, #:upper16:log_idx
	ldr	r2, [r3]
	cmp	r2, #1048576
	bcs	.L17
	movw	r1, #:lower16:elemlog
	mov	r5, #0
	movt	r1, #:upper16:elemlog
	add	r4, r2, #1
	add	ip, r1, r2, asl #4
	str	r5, [r1, r2, asl #4]
	str	r4, [r3]
	str	r0, [ip, #4]
	str	lr, [ip, #12]
.L17:
	ldrd	r4, [sp]
	add	sp, sp, #8
	ldr	pc, [sp], #4


@*****************************************************************************
@ This API logs the task switch hooks. 
@*****************************************************************************
mySwitch:
	stmfd	sp!, {r4, r5, r6, lr}
	MRC p15, 0, r4, c9, c13, 0	
	movw	r3, #:lower16:log_idx
	movt	r3, #:upper16:log_idx
	ldr	r2, [r3]
	cmp	r2, #1048576
	bcs	.L21
	movw	ip, #:lower16:elemlog
	mov	r6, #3
	movt	ip, #:upper16:elemlog
	add	r5, r2, #1
	add	lr, ip, r2, asl #4
	str	r6, [ip, r2, asl #4]
	str	r5, [r3]
	str	r1, [lr, #4]
	str	r0, [lr, #8]
	str	r4, [lr, #12]
.L21:
	ldrd	r4, [sp]
	ldr	r6, [sp, #8]
	add	sp, sp, #12
	ldr	pc, [sp], #4

@******************************************************************************
@*                                   LABELS
@******************************************************************************    

    .end


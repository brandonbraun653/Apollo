;******************************************************************************
;
; csl_arm9_cpu.asm - ARM CPU core routines
;
; Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
; All rights reserved.
;
;******************************************************************************
;****************************** Global Symbols*******************************
        .global CSL_CPUSwitchToPrivilegedMode
        .global CSL_CPUSwitchToUserMode
        .global CSL_CPUAbortHandler
        .global CSL_CPUIntStatus
        .global CSL_CPUirqd
        .global CSL_CPUirqe
        .global CSL_CPUfiqd
        .global CSL_CPUfiqe

;**************************** Code Seection ***********************************
        .text

;
; This code is assembled for ARM instructions
;
        .state32

;******************************************************************************
;
;******************************************************************************
;
; Switch the ARM core to privileged mode
;
CSL_CPUSwitchToPrivilegedMode:

    SWI   #458752
    BX      lr

;
; Switch the ARM core to user mode
;
CSL_CPUSwitchToUserMode:

    MRS     r0, CPSR
    BIC     r0, r0, #0x0F
    ORR     r0, r0, #0x10
    MSR     CPSR_c, r0
    BX      lr

;
; ARM abort handler
;
CSL_CPUAbortHandler
;  Perform Nothing
    BX      lr

;
; ARM interrupt status get function
;
CSL_CPUIntStatus:

    MRS     r0, CPSR
    AND     r1, r0, #0xC0
    MOV	    r0, r1
    BX      lr

;
; ARM IRQ disable function
;
CSL_CPUirqd:

    MRS     r0, CPSR
    ORR     r0, r0, #0x80
    MSR     CPSR_c, r0
    BX      lr

;
; ARM IRQ enable function
;
CSL_CPUirqe:

    MRS     r0, CPSR
    BIC     r0, r0, #0x80
    MSR     CPSR_c, r0
    BX      lr

;
; ARM FIQ disable function
;
CSL_CPUfiqd:

    MRS     r0, CPSR
    ORR     r0, r0, #0x40
    MSR     CPSR_c, r0
    BX      lr

;
; ARM FIQ enable function
;
CSL_CPUfiqe:

    MRS     r0, CPSR
    BIC     r0, r0, #0x40
    MSR     CPSR_c, r0
    BX      lr

;
; End of the file
;
    .end

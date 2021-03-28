;******************************************************************************
;* BOOT  v16.9.4                                                              *
;*                                                                            *
;* Copyright (c) 1996-2019 Texas Instruments Incorporated                     *
;* http://www.ti.com/                                                         *
;*                                                                            *
;*  Redistribution and  use in source  and binary forms, with  or without     *
;*  modification,  are permitted provided  that the  following conditions     *
;*  are met:                                                                  *
;*                                                                            *
;*     Redistributions  of source  code must  retain the  above copyright     *
;*     notice, this list of conditions and the following disclaimer.          *
;*                                                                            *
;*     Redistributions in binary form  must reproduce the above copyright     *
;*     notice, this  list of conditions  and the following  disclaimer in     *
;*     the  documentation  and/or   other  materials  provided  with  the     *
;*     distribution.                                                          *
;*                                                                            *
;*     Neither the  name of Texas Instruments Incorporated  nor the names     *
;*     of its  contributors may  be used to  endorse or  promote products     *
;*     derived  from   this  software  without   specific  prior  written     *
;*     permission.                                                            *
;*                                                                            *
;*  THIS SOFTWARE  IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS     *
;*  "AS IS"  AND ANY  EXPRESS OR IMPLIED  WARRANTIES, INCLUDING,  BUT NOT     *
;*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR     *
;*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT     *
;*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,     *
;*  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL  DAMAGES  (INCLUDING, BUT  NOT     *
;*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     *
;*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY     *
;*  THEORY OF  LIABILITY, WHETHER IN CONTRACT, STRICT  LIABILITY, OR TORT     *
;*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE     *
;*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.      *
;*                                                                            *
;******************************************************************************

;****************************************************************************
;* BOOT.ASM
;*
;* THIS IS THE INITAL BOOT ROUTINE FOR TMS470 C++ PROGRAMS.
;* IT MUST BE LINKED AND LOADED WITH ALL C++ PROGRAMS.
;*
;* THIS MODULE PERFORMS THE FOLLOWING ACTIONS:
;*   1) ALLOCATES THE STACK AND INITIALIZES THE STACK POINTER
;*   2) CALLS AUTO-INITIALIZATION ROUTINE
;*   3) CALLS THE FUNCTION MAIN TO START THE C++ PROGRAM
;*   4) CALLS THE STANDARD EXIT ROUTINE
;*
;* THIS MODULE DEFINES THE FOLLOWING GLOBAL SYMBOLS:
;*   1) __stack     STACK MEMORY AREA
;*   2) _c_int00    BOOT ROUTINE
;*
;****************************************************************************
   .if  __TI_ARM_V7M__ | __TI_ARM_V6M0__
	.thumbfunc _c_int00
	.thumbfunc _resetvectors
	.thumbfunc HF
   .else
	.armfunc _c_int00
	.armfunc _resetvectors
	.armfunc HF
   .endif

;****************************************************************************
; Accomodate different lowerd names in different ABIs
;****************************************************************************
   .if   __TI_EABI_ASSEMBLER
        .asg	_system_pre_init, PRE_INIT_RTN
        .asg	__TI_auto_init, AUTO_INIT_RTN
        .asg	_args_main,   ARGS_MAIN_RTN
        .asg	exit,         EXIT_RTN
        .asg    main_func_sp, MAIN_FUNC_SP
   .else ; COFF TI ARM9 ABI
        .asg	__system_pre_init, PRE_INIT_RTN
        .asg	__TI_auto_init, AUTO_INIT_RTN ; NOTE does not use COFF prefix
        .asg	__args_main,   ARGS_MAIN_RTN
        .asg	_exit,         EXIT_RTN
        .asg    _main_func_sp, MAIN_FUNC_SP
   .endif

   .if .TMS470_16BIS

;****************************************************************************
;*  16 BIT STATE BOOT ROUTINE                                               *
;****************************************************************************

   .if __TI_ARM_V7M__ | __TI_ARM_V6M0__
	.thumb
   .else
	.arm
   .endif

	.global	__stack
;***************************************************************
;* DEFINE THE USER MODE STACK (DEFAULT SIZE IS 512)
;***************************************************************
__stack:.usect	".stack", 0, 4

	.global	_c_int00
    .sect   ".bootCode"
;***************************************************************
;* FUNCTION DEF: _c_int00
;***************************************************************
_c_int00: .asmfunc stack_usage(0)

	.if !__TI_ARM_V7M__ & !__TI_ARM_V6M0__
	.if __TI_NEON_SUPPORT__ | __TI_VFP_SUPPORT__
        ;*------------------------------------------------------
	;* SETUP PRIVILEGED AND USER MODE ACCESS TO COPROCESSORS
	;* 10 AND 11, REQUIRED TO ENABLE NEON/VFP
	;* COPROCESSOR ACCESS CONTROL REG
	;* BITS [23:22] - CP11, [21:20] - CP10
	;* SET TO 0b11 TO ENABLE USER AND PRIV MODE ACCESS
        ;*------------------------------------------------------
		MRC      p15,#0x0,r0,c1,c0,#2
        MOV      r3,#0xf00000
		ORR      r0,r0,r3
        MCR      p15,#0x0,r0,c1,c0,#2

        ;*------------------------------------------------------
	; SET THE EN BIT, FPEXC[30] TO ENABLE NEON AND VFP
        ;*------------------------------------------------------
	MOV      r0,#0x40000000
        FMXR     FPEXC,r0
        .endif ; __TI_NEON_SUPPORT__ | __TI_VFP_SUPPORT__
    BL      __mpu_init
        ;------------------------------------------------------
	;* SET TO SYS MODE
        ;*------------------------------------------------------
        MRS     r0, cpsr
        BIC     r0, r0, #0x1F  ; CLEAR MODES
        ORR     r0, r0, #0x1F  ; SET SYS MODE
        MSR     cpsr_cf, r0

        ;*------------------------------------------------------
	;* CHANGE TO 16 BIT STATE
        ;*------------------------------------------------------
	ADD	r0, pc, #1
	BX	r0

		.thumb
        .else ; !__TI_ARM_V7M & !__TI_ARM_V6M0
	.if __TI_TMS470_V7M4__ & __TI_VFP_SUPPORT__
	.thumb
	;*------------------------------------------------------
	;* SETUP FULL ACCESS TO COPROCESSORS 10 AND 11,
	;* REQUIRED FOR FP. COPROCESSOR ACCESS CONTROL REG
	;* BITS [23:22] - CP11, [21:20] - CP10
	;* SET TO 0b11 TO ENABLE FULL ACCESS
        ;*------------------------------------------------------
cpacr   .set     0xE000ED88			; CAPCR address
	MOVW     r1, #cpacr & 0xFFFF
	MOVT     r1, #cpacr >> 16
	LDR      r0, [ r1 ]
	MOV      r3, #0xf0
	ORR      r0,r0,r3, LSL #16
	STR      r0, [ r1 ]
	.thumb
	.endif ; __TI_TMS470_V7M4__ & __TI_VFP_SUPPORT__
	.endif ; !__TI_ARM_V7M & !__TI_ARM_V6M0__

	;*------------------------------------------------------
        ;* INITIALIZE THE USER MODE STACK
        ;*------------------------------------------------------
	.if __TI_AVOID_EMBEDDED_CONSTANTS
	.thumb
	MOVW	r0, __stack
	MOVT	r0, __stack
	MOV	sp, r0
	MOVW	r0, __STACK_SIZE
	MOVT	r0, __STACK_SIZE
	.thumb
	.else ; __TI_AVOID_EMBEDDED_CONSTANTS
	LDR     r0, c_stack
	MOV	sp, r0
        LDR     r0, c_STACK_SIZE
	.endif ; __TI_AVOID_EMBEDDED_CONSTANTS
	ADD	sp, r0

	;*-----------------------------------------------------
	;* ALIGN THE STACK TO 64-BITS IF EABI.
	;*-----------------------------------------------------
	.if __TI_EABI_ASSEMBLER
	MOV	r7, sp
	MOVS	r0, #0x07
	BICS    r7, r0         ; Clear upper 3 bits for 64-bit alignment.
	MOV	sp, r7
	.endif

	;*-----------------------------------------------------
	;* SAVE CURRENT STACK POINTER FOR SDP ANALYSIS
	;*-----------------------------------------------------
	.if __TI_AVOID_EMBEDDED_CONSTANTS
	.thumb
	MOVW	r0, MAIN_FUNC_SP
	MOVT	r0, MAIN_FUNC_SP
	.thumb
	.else
	LDR	r0, c_mf_sp
	.endif
	MOV	r7, sp
	STR	r7, [r0]

        ;*------------------------------------------------------
	;* Call the __mpu_init hook function.
        ;*------------------------------------------------------
        ;BL      __mpu_init

        ;*------------------------------------------------------
        ;* Perform all the required initializations when
        ;* _system_pre_init() returns non-zero:
        ;*   - Process BINIT Table
        ;*   - Perform C auto initialization
        ;*   - Call global constructors
        ;*------------------------------------------------------
        BL      PRE_INIT_RTN
        CMP     R0, #0
        BEQ     bypass_auto_init
        BL      AUTO_INIT_RTN
bypass_auto_init:

        ;*------------------------------------------------------
	;* CALL APPLICATION
        ;*------------------------------------------------------
        BL      ARGS_MAIN_RTN

        ;*------------------------------------------------------
	;* IF APPLICATION DIDN'T CALL EXIT, CALL EXIT(1)
        ;*------------------------------------------------------
        MOVS    r0, #1
        BL      EXIT_RTN

        ;*------------------------------------------------------
	;* DONE, LOOP FOREVER
        ;*------------------------------------------------------
L1:     B	L1
	.endasmfunc

;***************************************************************
;* FUNCTION DEF: HF
;***************************************************************
		.global HF

HF:     .asmfunc stack_usage(0)
L2:     B   L2
		.endasmfunc

   .else           ; !.TMS470_16BIS

;****************************************************************************
;*  32 BIT STATE BOOT ROUTINE                                               *
;****************************************************************************
        .global __stack

;****************************************************************************
;*  STACK ADDRESSES                                               *
;****************************************************************************
        .sect   ".bootCode"
        .global __IRQ_STACK_END
        .global __FIQ_STACK_END
        .global __ABORT_STACK_END
        .global __UND_STACK_END
        .global __SVC_STACK_END
IRQ_STACK_ADDR .long __IRQ_STACK_END
FIQ_STACK_ADDR .long __FIQ_STACK_END
ABORT_STACK_ADDR .long __ABORT_STACK_END
UND_STACK_ADDR .long __UND_STACK_END
SVC_STACK_ADDR .long __SVC_STACK_END
;***************************************************************
;* DEFINE THE USER MODE STACK (DEFAULT SIZE IS 512)
;***************************************************************
__stack:.usect  ".stack", 0, 4

        .global _c_int00
        .global BoardDiag_timerIntrDisable
;***************************************************************
;* FUNCTION DEF: _c_int00
;***************************************************************
_c_int00: .asmfunc stack_usage(0)

        PUSH {r1}   ;Store the context of diag framework
        MOV r10, sp
        MOV r11, lr

        .if __TI_NEON_SUPPORT__ | __TI_VFP_SUPPORT__
        ;*------------------------------------------------------
        ;* SETUP PRIVILEGED AND USER MODE ACCESS TO COPROCESSORS
        ;* 10 AND 11, REQUIRED TO ENABLE NEON/VFP
        ;* COPROCESSOR ACCESS CONTROL REG
        ;* BITS [23:22] - CP11, [21:20] - CP10
        ;* SET TO 0b11 TO ENABLE USER AND PRIV MODE ACCESS
        ;*------------------------------------------------------
        MRC      p15,#0x0,r0,c1,c0,#2
        MOV      r3,#0xf00000
        ORR      r0,r0,r3
        MCR      p15,#0x0,r0,c1,c0,#2

        ;*------------------------------------------------------
        ; SET THE EN BIT, FPEXC[30] TO ENABLE NEON AND VFP
        ;*------------------------------------------------------
        MOV      r0,#0x40000000
        FMXR     FPEXC,r0
        .endif
        ;*------------------------------------------------------
        ;* SET TO IRQ MODE
        ;*------------------------------------------------------
        MRS     r0, cpsr
        BIC     r0, r0, #0x1F  ; CLEAR MODES
        ORR     r0, r0, #0x12  ; SET IRQ MODE
        MSR     cpsr_cf, r0

        ;*------------------------------------------------------
        ;* INITIALIZE THE IRQ MODE STACK
        ;*------------------------------------------------------
        .if __TI_AVOID_EMBEDDED_CONSTANTS
        MOVW    sp, IRQ_STACK_ADDR
        MOVT    sp, IRQ_STACK_ADDR
        .else
        LDR     sp, IRQ_STACK_ADDR
        .endif

        ;*------------------------------------------------------
        ;* SET TO FIQ MODE
        ;*------------------------------------------------------
        MRS     r0, cpsr
        BIC     r0, r0, #0x1F  ; CLEAR MODES
        ORR     r0, r0, #0x11  ; SET FRQ MODE
        MSR     cpsr_cf, r0

        ;*------------------------------------------------------
        ;* INITIALIZE THE FIQ MODE STACK
        ;*------------------------------------------------------
        .if __TI_AVOID_EMBEDDED_CONSTANTS
        MOVW    sp, FIQ_STACK_ADDR
        MOVT    sp, FIQ_STACK_ADDR
        .else
        LDR     sp, FIQ_STACK_ADDR
        .endif

        ;*------------------------------------------------------
        ;* SET TO ABORT` MODE
        ;*------------------------------------------------------
        MRS     r0, cpsr
        BIC     r0, r0, #0x1F  ; CLEAR MODES
        ORR     r0, r0, #0x17  ; SET ABORT MODE
        MSR     cpsr_cf, r0

        ;*------------------------------------------------------
        ;* INITIALIZE THE ABORT MODE STACK
        ;*------------------------------------------------------
        .if __TI_AVOID_EMBEDDED_CONSTANTS
        MOVW    sp, ABORT_STACK_ADDR
        MOVT    sp, ABORT_STACK_ADDR
        .else
        LDR     sp, ABORT_STACK_ADDR
        .endif

        ;*------------------------------------------------------
        ;* SET TO UNDEFINED MODE
        ;*------------------------------------------------------
        MRS     r0, cpsr
        BIC     r0, r0, #0x1F  ; CLEAR MODES
        ORR     r0, r0, #0x1B  ; SET UNDEFINED MODE
        MSR     cpsr_cf, r0

        ;*------------------------------------------------------
        ;* INITIALIZE THE UNDEFINED MODE STACK
        ;*------------------------------------------------------
        .if __TI_AVOID_EMBEDDED_CONSTANTS
        MOVW    sp, UND_STACK_ADDR
        MOVT    sp, UND_STACK_ADDR
        .else
        LDR     sp, UND_STACK_ADDR
        .endif

        ;*------------------------------------------------------
        ;* SET TO SUPERVISOR MODE
        ;*------------------------------------------------------
        MRS     r0, cpsr
        BIC     r0, r0, #0x1F  ; CLEAR MODES
        ORR     r0, r0, #0x13  ; SET SUPERVISOR MODE
        MSR     cpsr_cf, r0

        ;*------------------------------------------------------
        ;* INITIALIZE THE SUPERVISOR MODE STACK
        ;*------------------------------------------------------
        .if __TI_AVOID_EMBEDDED_CONSTANTS
        MOVW    sp, SVC_STACK_ADDR
        MOVT    sp, SVC_STACK_ADDR
        .else
        LDR     sp, SVC_STACK_ADDR
        .endif

        ;*------------------------------------------------------
        ;* SET TO SYSTEM MODE
        ;*------------------------------------------------------
        MRS     r0, cpsr
        BIC     r0, r0, #0x1F  ; CLEAR MODES
        ORR     r0, r0, #0x1F  ; SET SYSTEM MODE
        MSR     cpsr_cf, r0

        ;*------------------------------------------------------
        ;* INITIALIZE THE USER MODE STACK
        ;*------------------------------------------------------
        .if __TI_AVOID_EMBEDDED_CONSTANTS
        MOVW    sp, __stack
        MOVT    sp, __stack
        MOVW    r0, __STACK_SIZE
        MOVT    r0, __STACK_SIZE
        .else
        LDR     sp, c_stack
        LDR     r0, c_STACK_SIZE
        .endif
        ADD     sp, sp, r0

        ;*-----------------------------------------------------
        ;* ALIGN THE STACK TO 64-BITS IF EABI.
        ;*-----------------------------------------------------
        .if __TI_EABI_ASSEMBLER
        BIC     sp, sp, #0x07  ; Clear upper 3 bits for 64-bit alignment.
        .endif

        ;*-----------------------------------------------------
        ;* SAVE CURRENT STACK POINTER FOR SDP ANALYSIS
        ;*-----------------------------------------------------
        .if __TI_AVOID_EMBEDDED_CONSTANTS
        MOVW    r0, MAIN_FUNC_SP
        MOVT    r0, MAIN_FUNC_SP
        .else
        LDR     r0, c_mf_sp
        .endif
        STR     sp, [r0]

        STMFD sp!, {r10, r11}
        ;*------------------------------------------------------
        ;* Call the __mpu_init hook function.
        ;*------------------------------------------------------
        BL      __mpu_init

        ;*------------------------------------------------------
        ;* SET TO SYSTEM MODE
        ;*------------------------------------------------------
        MRS     r0, cpsr
        BIC     r0, r0, #0x1F  ; CLEAR MODES
        ORR     r0, r0, #0x1F  ; SET SYSTEM MODE
        MSR     cpsr_cf, r0

        ;*------------------------------------------------------
        ;* Perform all the required initializations when
        ;* _system_pre_init() returns non-zero:
        ;*   - Process BINIT Table
        ;*   - Perform C auto initialization
        ;*   - Call global constructors
        ;*------------------------------------------------------
        BL      PRE_INIT_RTN
        CMP     R0, #0
        BEQ     bypass_auto_init
        BL      AUTO_INIT_RTN
bypass_auto_init:

        ;*------------------------------------------------------
        ;* CALL APPLICATION
        ;*------------------------------------------------------
        BL      BoardDiag_timerIntrDisable
        BL      ARGS_MAIN_RTN
        
        LDMFD sp!, {r1, r2} ;Load the context of diag framework
        MOV sp, r1
        POP {r1}
        STR r0, [r1]
        MOV pc, r2

        ;*------------------------------------------------------
        ;* IF APPLICATION DIDN'T CALL EXIT, CALL EXIT(1)
        ;*------------------------------------------------------
        MOV     R0, #1
        BL      EXIT_RTN

        ;*------------------------------------------------------
        ;* DONE, LOOP FOREVER
        ;*------------------------------------------------------
L1:     B       L1
        .endasmfunc

;***************************************************************
;* FUNCTION DEF: HF
;***************************************************************
		.global HF

HF:     .asmfunc stack_usage(0)
L2:     B   L2
		.endasmfunc

   .endif    ; !.TMS470_16BIS

;***************************************************************
;* CONSTANTS USED BY THIS MODULE
;***************************************************************
        .if !__TI_AVOID_EMBEDDED_CONSTANTS
c_stack         .long    __stack
c_STACK_SIZE    .long    __STACK_SIZE
c_mf_sp         .long    MAIN_FUNC_SP
        .endif

        .if __TI_EABI_ASSEMBLER
        .data
        .align 4
_stkchk_called:
        .field          0,32
        .else
        .sect   ".cinit"
        .align  4
        .field          4,32
        .field          _stkchk_called+0,32
        .field          0,32

        .bss    _stkchk_called,4,4
        .symdepend ".cinit", ".bss"
        .symdepend ".cinit", ".text"
        .symdepend ".bss", ".text"
        .endif

;******************************************************
;* UNDEFINED REFERENCES                               *
;******************************************************
	.global _stkchk_called
	.global	__STACK_SIZE
        .global PRE_INIT_RTN
        .global AUTO_INIT_RTN
	.global ARGS_MAIN_RTN
	.global MAIN_FUNC_SP
	.global	EXIT_RTN
	.weak	__mpu_init
    .global	undefInstructionExptnHandler
    .global	swIntrExptnHandler
    .global	prefetchAbortExptnHandler
    .global	dataAbortExptnHandler
    .global	rsvdExptnHandler
    .global	irqExptnHandler
    .global	fiqExptnHandler

;****************************************************************************
; Setup reserved Handler
;****************************************************************************
    .global	_cslRsvdHandler
_cslRsvdHandler:
    .asmfunc
     b   _cslRsvdHandler
    .endasmfunc
;****************************************************************************
; Setup Reset Vectors always in ARM mode
;****************************************************************************
    .arm
	.global	_resetvectors
    .sect   ".rstvectors"
_resetvectors:
    .asmfunc
        LDR pc, c_int00_addr        ; Reset
        LDR pc, undefInst_addr      ; Undefined Instruction
        LDR pc, swi_addr            ; Software interrupt
        LDR pc, preAbort_addr       ; Abort (prefetch)
        LDR pc, dataAbort_addr      ; Abort (data)
        LDR pc, rsvd_addr            ; rsvd
        LDR pc, irq_addr             ; IRQ
        LDR pc, fiq_addr             ; FIQ
    .endasmfunc


c_int00_addr .long _c_int00
undefInst_addr .long undefInstructionExptnHandler
swi_addr .long swIntrExptnHandler
preAbort_addr .long prefetchAbortExptnHandler
dataAbort_addr .long dataAbortExptnHandler
rsvd_addr .long _cslRsvdHandler
irq_addr .long irqExptnHandler
fiq_addr .long fiqExptnHandler
	.end

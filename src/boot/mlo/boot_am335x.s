    .global _reset_handler
    .global SVC_Handler
    .global Prefetch_Handler
    .global Abort_Handler
    .global IRQ_Handler
    .global FIQ_Handler
    .global Vector_Table
    .global _stack
    .global _startup
    .global _bss_end
    .global _mlo_startup_entry

@************************ Internal Definitions ******************************
@
@ Define the stack sizes for different modes. The user/system mode will use
@ the rest of the total stack size
@
    .set  UND_STACK_SIZE, 0x100
    .set  ABT_STACK_SIZE, 0x100
    .set  FIQ_STACK_SIZE, 0x100
    .set  IRQ_STACK_SIZE, 0x100
    .set  SVC_STACK_SIZE, 0x200

@
@ to set the mode bits in CPSR for different modes
@
    .set  MODE_USR, 0x10
    .set  MODE_FIQ, 0x11
    .set  MODE_IRQ, 0x12
    .set  MODE_SVC, 0x13
    .set  MODE_ABT, 0x17
    .set  MODE_UND, 0x1B
    .set  MODE_SYS, 0x1F

    .equ  I_F_BIT, 0xC0

    @ This code is assembled for ARM instructions
    .section .text.startup, "ax"
    .code 32

@******************************************************************************
@
@******************************************************************************

@ _startup:
@     LDR pc, =_reset_handler
@     LDR pc, =Undefined_Handler
@     LDR pc, =SVC_Handler
@     LDR pc, =Prefetch_Handler
@     LDR pc, =Abort_Handler
@     NOP                    @Reserved vector
@     LDR pc, =IRQ_Handler
@     LDR pc, =FIQ_Handler

@ The reset handler sets up the stack pointers for all the modes. The FIQ and
@ IRQ shall be disabled during this. Then clears the BSS section, enters the
@ main function.
_startup:
    @ Set up the Stack for Undefined mode
    LDR   r0, =_stack                     @ Read the stack address
    MSR   cpsr_c, #MODE_UND|I_F_BIT       @ switch to undef mode
    MOV   sp,r0                           @ write the stack pointer
    SUB   r0, r0, #UND_STACK_SIZE         @ give stack space

    @ Set up the Stack for abort mode
    MSR   cpsr_c, #MODE_ABT|I_F_BIT       @ Change to abort mode
    MOV   sp, r0                          @ write the stack pointer
    SUB   r0,r0, #ABT_STACK_SIZE          @ give stack space

    @ Set up the Stack for FIQ mode
    MSR   cpsr_c, #MODE_FIQ|I_F_BIT       @ change to FIQ mode
    MOV   sp,r0                           @ write the stack pointer
    SUB   r0,r0, #FIQ_STACK_SIZE          @ give stack space

    @ Set up the Stack for IRQ mode
    MSR   cpsr_c, #MODE_IRQ|I_F_BIT       @ change to IRQ mode
    MOV   sp,r0                           @ write the stack pointer
    SUB   r0,r0, #IRQ_STACK_SIZE          @ give stack space

    @ Set up the Stack for SVC mode
    MSR   cpsr_c, #MODE_SVC|I_F_BIT       @ change to SVC mode
    MOV   sp,r0                           @ write the stack pointer
    SUB   r0,r0, #SVC_STACK_SIZE          @ give stack space

    @ Set up the Stack for User/System mode
    MSR   cpsr_c, #MODE_SYS|I_F_BIT       @ change to system mode
    MOV   sp,r0                           @ write the stack pointer

    @ Switch back to SVC mode to start the MLO in priviledged mode
    MSR   cpsr_c, #MODE_SVC|I_F_BIT

    @ Enter the MLO startup
    b _mlo_startup_entry
@    LDR   r10,=_mlo_startup_entry                       @ Get the address of main
@    MOV   lr,pc                           @ Dummy return
@    BX    r10                             @ Branch to main

@ End of the file
    .end

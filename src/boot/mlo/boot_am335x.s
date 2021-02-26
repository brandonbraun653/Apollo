    .global _reset_handler
    .global _startup
    .global _bss_end

    .extern _mlo_startup_entry
    .extern _stack
    .extern SVC_Handler
    .extern Prefetch_Handler
    .extern Abort_Handler
    .extern IRQ_Handler
    .extern FIQ_Handler

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

/* Set the MLO stack to the pre-allocated area in OCM */
    @.equ  _stack, 0x4030B800

@-------------------------------------------------------------------------------
@ Reset Handler Function Defintion:
@   The reset handler sets up the stack pointers for all the modes. The FIQ and
@   IRQ shall be disabled during this. Then clears the BSS section, enters the
@   main function.
@-------------------------------------------------------------------------------
    .section .text.startup, "ax"
    .arm
    .code 32

_reset_handler:
    mrs r0, cpsr                          @ copy the CPSR to r0
    bic r0, r0, #0x1F                     @ clear the mode bits so we start from a known state
    orr r0, r0, #0x13                     @ set SVC mode, defined in ARM Table B1-1. CPSR M[4:0] bits
    orr r0, r0, #0xC0                     @ disable (mask) FIQ and IRQ. These are the CPSR I/F bits
    msr cpsr, r0                          @ copy modified r0 into CPSR

    @ Set up the Stack for Undefined mode
    ldr   r0, =_stack                     @ Read the stack address
    msr   cpsr_c, #MODE_UND|I_F_BIT       @ switch to undef mode
    mov   sp,r0                           @ write the stack pointer
    sub   r0, r0, #UND_STACK_SIZE         @ give stack space

    @ Set up the Stack for abort mode
    msr   cpsr_c, #MODE_ABT|I_F_BIT       @ Change to abort mode
    mov   sp, r0                          @ write the stack pointer
    sub   r0,r0, #ABT_STACK_SIZE          @ give stack space

    @ Set up the Stack for FIQ mode
    msr   cpsr_c, #MODE_FIQ|I_F_BIT       @ change to FIQ mode
    mov   sp,r0                           @ write the stack pointer
    sub   r0,r0, #FIQ_STACK_SIZE          @ give stack space

    @ Set up the Stack for IRQ mode
    msr   cpsr_c, #MODE_IRQ|I_F_BIT       @ change to IRQ mode
    mov   sp,r0                           @ write the stack pointer
    sub   r0,r0, #IRQ_STACK_SIZE          @ give stack space

    @ Set up the Stack for SVC mode
    msr   cpsr_c, #MODE_SVC|I_F_BIT       @ change to SVC mode
    mov   sp,r0                           @ write the stack pointer
    sub   r0,r0, #SVC_STACK_SIZE          @ give stack space

    @ Set up the Stack for User/System mode
    msr   cpsr_c, #MODE_SYS|I_F_BIT       @ change to system mode
    mov   sp,r0                           @ write the stack pointer

    @ Switch back to SVC mode to start the MLO in priviledged mode
    msr   cpsr_c, #MODE_SVC|I_F_BIT

    @ Enter the MLO startup
    b     _mlo_startup_entry


@-------------------------------------------------------------------------------
@ MLO Exception Vector Table Defintion:
@   This
@-------------------------------------------------------------------------------
    .section .ram_exceptions, "ax"
    .arm
    .code 32

_exception_vectors:
    b _reset_handler
    ldr pc, =_undf
    ldr pc, =_swi
    ldr pc, =_pabt
    ldr pc, =_dabt
    nop                    @Reserved vector
    ldr pc, =_irq
    ldr pc, =_fiq

/* Allocate addresses for the exception handlers */
_undf:  .word Undefined_Handler
_swi:   .word SVC_Handler
_pabt:  .word Prefetch_Handler
_dabt:  .word Abort_Handler
_irq:   .word IRQ_Handler
_fiq:   .word FIQ_Handler

/* Default exception handlers that simply spin */
__undf:  b .
__swi:   b .
__pabt:  b .
__dabt:  b .
__irq:   b .
__fiq:   b .

@ End of the file
    .end

/* Linker Settings */
--retain="*(.bootCode)"
--retain="*(.startupCode)"
--retain="*(.startupData)"
--retain="*(.intvecs)"
--retain="*(.intc_text)"
--retain="*(.rstvectors)"
--retain="*(.irqStack)"
--retain="*(.fiqStack)"
--retain="*(.abortStack)"
--retain="*(.undStack)"
--retain="*(.svcStack)"
--fill_value=0
--stack_size=0x2000
--heap_size=0x1000
--entry_point=_resetvectors     /* Default C RTS boot.asm   */

-stack  0x2000                              /* SOFTWARE STACK SIZE           */
-heap   0x2000                              /* HEAP AREA SIZE                */

/* Stack Sizes for various modes */
__IRQ_STACK_SIZE = 0x1000;
__FIQ_STACK_SIZE = 0x1000;
__ABORT_STACK_SIZE = 0x1000;
__UND_STACK_SIZE = 0x1000;
__SVC_STACK_SIZE = 0x1000;

/* Memory Map */
MEMORY
{
    VECTORS (X)             : origin=0x41C7F000 length=0x1000
    /*  Reset Vectors base address(RESET_VECTORS) should be 64 bytes aligned  */
    RESET_VECTORS (X)       : origin=0x41C00000 length=0x100
    /* MCU0_R5F_0 local view */
    MCU0_R5F_TCMA_SBL_RSVD (X)  : origin=0x0        length=0x100
    MCU0_R5F_TCMA (X)       : origin=0x100      length=0x8000 - 0x100
    MCU0_R5F_TCMB0 (RWIX)   : origin=0x41010000 length=0x8000

    /* MCU0_R5F_1 SoC view */
    MCU0_R5F1_ATCM (RWIX)   : origin=0x41400000 length=0x8000
    MCU0_R5F1_BTCM (RWIX)   : origin=0x41410000 length=0x8000

    /* MCU0 share locations */
    OCMRAM  (RWIX)          : origin=0x41C00100 length=0x80000 - 0x1100      /* ~510KB */

    /* j721e MCMS3 locations */
    /* j721e Reserved Memory for ARM Trusted Firmware */
    MSMC3_ARM_FW   (RWIX)   : origin=0x70000000 length=0x40000         /* 256KB */
    MSMC3   (RWIX)          : origin=0x70040000 length=0x100000        /* 8MB - 320KB */
    /* j721e Reserved Memory for DMSC Firmware */
    MSMC3_DMSC_FW  (RWIX)   : origin=0x707F0000 length=0x10000         /* 64KB */

    DDR0    (RWIX)          : origin=0x80000000 length=0x80000000      /* 2GB */
}

/* Section Configuration */
SECTIONS
{
    /* 'intvecs' and 'intc_text' sections shall be placed within */
    /* a range of +\- 16 MB */
    .intvecs       : {} palign(8)      > VECTORS
    .intc_text     : {} palign(8)      > VECTORS
    .rstvectors    : {} palign(8)      > RESET_VECTORS
    .bootCode      : {} palign(8)      > MSMC3
    .startupCode   : {} palign(8)      > MSMC3
    .startupData   : {} palign(8)      > MSMC3, type = NOINIT
    .text          : {} palign(8)      > MSMC3
    .const         : {} palign(8)      > MSMC3
    .cinit         : {} palign(8)      > MSMC3
    .pinit         : {} palign(8)      > MSMC3
    .bss           : {} align(4)       > MSMC3
    .far           : {} align(4)       > MSMC3
    .data          : {} palign(128)    > MSMC3
    .boardcfg_data : {} palign(128)    > MSMC3
    .sysmem        : {}                > MSMC3
    .data_buffer   : {} palign(128)    > MSMC3

    /* USB or any other LLD buffer for benchmarking */
    .benchmark_buffer (NOLOAD) {} ALIGN (8) > MSMC3

    .stack      : {} align(4)       > MSMC3  (HIGH)
    .irqStack   : {. = . + __IRQ_STACK_SIZE;} align(4)      > MSMC3  (HIGH)
    RUN_START(__IRQ_STACK_START)
    RUN_END(__IRQ_STACK_END)
    .fiqStack   : {. = . + __FIQ_STACK_SIZE;} align(4)      > MSMC3  (HIGH)
    RUN_START(__FIQ_STACK_START)
    RUN_END(__FIQ_STACK_END)
    .abortStack : {. = . + __ABORT_STACK_SIZE;} align(4)    > MSMC3  (HIGH)
    RUN_START(__ABORT_STACK_START)
    RUN_END(__ABORT_STACK_END)
    .undStack   : {. = . + __UND_STACK_SIZE;} align(4)      > MSMC3  (HIGH)
    RUN_START(__UND_STACK_START)
    RUN_END(__UND_STACK_END)
    .svcStack   : {. = . + __SVC_STACK_SIZE;} align(4)      > MSMC3  (HIGH)
    RUN_START(__SVC_STACK_START)
    RUN_END(__SVC_STACK_END)
}

/* Linker Settings                                                            */
/* Standard linker options													  */
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
--entry_point=_resetvectors		/* Default C RTS boot.asm	*/

-stack  0x2000                              /* SOFTWARE STACK SIZE           */
-heap   0x2000                              /* HEAP AREA SIZE                */

/* Stack Sizes for various modes */
__IRQ_STACK_SIZE = 0x1000;
__FIQ_STACK_SIZE = 0x1000;
__ABORT_STACK_SIZE = 0x1000;
__UND_STACK_SIZE = 0x1000;
__SVC_STACK_SIZE = 0x1000;

/*----------------------------------------------------------------------------*/
/* Memory Map                                                                 */
MEMORY
{
    MCU1_0_VECTORS (X)  		: origin=0x41C7F000 length=0x1000
    MCU1_1_VECTORS (X)  		: origin=0x41C7E000 length=0x1000
    /*  Reset Vectors base address(RESET_VECTORS) should be 64 bytes aligned  */
    MCU1_0_RESET_VECTORS (X)  		: origin=0x41C00000 length=0x100
    MCU1_1_RESET_VECTORS (X)  		: origin=0x41C00100 length=0x200 - 0x100
    /* MCU0_R5F_0 local view */
    MCU0_R5F_TCMA_SBL_RSVD (X)	: origin=0x0		length=0x100
    MCU0_R5F_TCMA (X)		: origin=0x100		length=0x8000 - 0x100
    MCU0_R5F_TCMB0 (RWIX)	: origin=0x41010000	length=0x8000

    /* MCU0_R5F_1 SoC view */
    MCU0_R5F1_ATCM (RWIX)  	: origin=0x41400000 length=0x8000
    MCU0_R5F1_BTCM (RWIX) 	: origin=0x41410000 length=0x8000

    /* Fully avaialble for apps. Used by SBL to load SYSFW */
    OCMRAM_LOW 	(RWIX) 		: origin=0x41C00200 length=0x40600 - 0x200	     /* ~257KB */

    /* MCU0 memory used for SBL. Avaiable after boot for app starts for dynamic use */
    SBL_RESERVED 	(RWIX) 	: origin=0x41C40600 length=0x60000 - 0x40600	     /* ~126KB */

    /* MCU0 share locations */
    OCMRAM 	(RWIX) 		: origin=0x41C60000 length=0x20000 - 0x2000	     /* ~124KB */

    /* AM65XX M4 locations */
    MCU1_0_MSMC3   (RWIX)              : origin=0x000070001000 length=0x80000 - 0x1000 /* .5 MB - 64K */
    MCU1_1_MSMC3   (RWIX)              : origin=0x000070080000 length=0xF0000 - 0x80000 /* .5 MB - 64K */
    /* Reserved for DMSC */
    MSMC3_DMSC (RWIX)		: origin=0x700F0000 length=0x10000			/* 64K */
    MSMC3_H (RWIX)	 		: origin=0x70100000 length=0xF2000			/* 1MB -56K */
    MSMC3_NOCACHE (RWIX)	: origin=0x701F2000 length=0xE000			/* 56K */
    DDR0    (RWIX)  		: origin=0x80000000 length=0x80000000    	/* 2GB */

/* Additional memory settings	*/

}  /* end of MEMORY */

/*----------------------------------------------------------------------------*/
/* Section Configuration                                                      */

SECTIONS
{
/* 'intvecs' and 'intc_text' sections shall be placed within                  */
/* a range of +\- 16 MB                                                       */
    .intvecs 	: {} palign(8) 		> MCU1_1_VECTORS
    .intc_text 	: {} palign(8) 		> MCU1_1_VECTORS
    .rstvectors 	: {} palign(8) 		> MCU1_1_RESET_VECTORS
    .bootCode    	: {} palign(8) 		> MCU1_1_MSMC3
    .startupCode    : {} palign(8) 		> MCU1_1_MSMC3
    .startupData    : {} palign(8) 		> MCU1_1_MSMC3
    .text    	: {} palign(8) 		> MCU1_1_MSMC3
    .const   	: {} palign(8) 		> MCU1_1_MSMC3
    .cinit   	: {} palign(8) 		> MCU1_1_MSMC3
    .pinit   	: {} palign(8) 		> MCU1_1_MSMC3
    .bss     	: {} align(4)  		> MCU1_1_MSMC3
    .data    	: {} palign(128) 	> MCU1_1_MSMC3
    .boardcfg_data        : {} palign(128)           > MCU1_1_MSMC3
    .sysmem  	: {} 				> MCU1_1_MSMC3

    .stack  	: {} align(4)		> MCU1_1_MSMC3  (HIGH)
    .irqStack  	: {. = . + __IRQ_STACK_SIZE;} align(4)		> MCU1_1_MSMC3  (HIGH)
    RUN_START(__IRQ_STACK_START)
    RUN_END(__IRQ_STACK_END)
    .fiqStack  	: {. = . + __FIQ_STACK_SIZE;} align(4)		> MCU1_1_MSMC3  (HIGH)
    RUN_START(__FIQ_STACK_START)
    RUN_END(__FIQ_STACK_END)
    .abortStack  	: {. = . + __ABORT_STACK_SIZE;} align(4)		> MCU1_1_MSMC3  (HIGH)
    RUN_START(__ABORT_STACK_START)
    RUN_END(__ABORT_STACK_END)
    .undStack  	: {. = . + __UND_STACK_SIZE;} align(4)		> MCU1_1_MSMC3  (HIGH)
    RUN_START(__UND_STACK_START)
    RUN_END(__UND_STACK_END)
    .svcStack  	: {. = . + __SVC_STACK_SIZE;} align(4)		> MCU1_1_MSMC3  (HIGH)
    RUN_START(__SVC_STACK_START)
    RUN_END(__SVC_STACK_END)

/* Additional sections settings 	*/

}  /* end of SECTIONS */

/*----------------------------------------------------------------------------*/
/* Misc linker settings                                                       */


/*-------------------------------- END ---------------------------------------*/

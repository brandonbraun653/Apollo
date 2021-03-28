/*----------------------------------------------------------------------------*/
/* File: linker_mcu1_0.lds                                                  */
/* Description:																  */
/*    Link command file for AM65XX M4 MCU 0 view							  */
/*	  TI ARM Compiler version 18.1.5 LTS or later							  */
/*                                                                            */
/* (c) Texas Instruments 2019, All rights reserved.                           */
/*----------------------------------------------------------------------------*/
/* Linker Settings                                                            */
/* Standard linker options													  */
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
    VECTORS (X)  		: origin=0x41C7F000 length=0x1000
    /* MCU0_R5F_0 local view */
    MCU0_R5F_TCMA (X)		: origin=0x0		length=0x8000
    MCU0_R5F_TCMB0 (RWIX)	: origin=0x41010000	length=0x8000

    /* MCU0_R5F_1 SoC view */
    MCU0_R5F1_ATCM (RWIX)  	: origin=0x41400000 length=0x8000
    MCU0_R5F1_BTCM (RWIX) 	: origin=0x41410000 length=0x8000

    /* Fully avaialble for apps. Used by SBL to load SYSFW */
    OCMRAM_LOW 	(RWIX) 		: origin=0x41C00100 length=0x40600 - 0x100	     /* ~257KB */

    /* MCU0 memory used for SBL. Avaiable after boot for app starts for dynamic use */
    SBL_RESERVED 	(RWIX) 	: origin=0x41C40600 length=0x60000 - 0x40600	     /* ~126KB */

    /* MCU0 share locations */
    OCMRAM 	(RWIX) 		: origin=0x41C60000 length=0x20000 - 0x1000	     /* ~124KB */

    /* AM65XX M4 locations */
    MSMC3_RESERVED	(RWIX)	: origin=0x70000000 length=0x20000		     /* 128K */
    MSMC3	(RWIX)	 	: origin=0x70020000 length=0x10000		     /* 64K */
    /* Reserved for DMSC */
    MSMC3_DMSC (RWIX)		: origin=0x700F0000 length=0x10000		     /* 64K */
    MSMC3_H (RWIX)	 		: origin=0x70100000 length=0xF2000	     /* 1MB -56K */
    MSMC3_NOCACHE (RWIX)	: origin=0x701F2000 length=0xE000		     /* 56K */
    DDR0    (RWIX)  		: origin=0xA0100000 length=0xF00000    	             /* Reserve Memory for R5F */

/* Additional memory settings	*/

}  /* end of MEMORY */

/*----------------------------------------------------------------------------*/
/* Section Configuration                                                      */

SECTIONS
{
/* 'intvecs' and 'intc_text' sections shall be placed within                  */
/* a range of +\- 16 MB                                                       */
    .intvecs 	: {} palign(8) 		> VECTORS
    .intc_text 	: {} palign(8) 		> VECTORS
    .rstvectors 	: {} palign(8) 	> MCU0_R5F_TCMA
    .bootCode      : {} palign(8)      > OCMRAM_LOW
    .startupCode   : {} palign(8)      > OCMRAM_LOW
    .startupData   : {} palign(8)      > OCMRAM_LOW, type = NOINIT
    .text    	: {} palign(8) 		> OCMRAM_LOW
    .const   	: {} palign(8) 		> OCMRAM_LOW
    .resource_table : {} palign(8) 	> OCMRAM_LOW
    .cinit   	: {} palign(8) 		> OCMRAM_LOW
    .pinit   	: {} palign(8) 		> OCMRAM_LOW
    .bss     	: {} align(4)  		> DDR0
    .far     	: {} align(4)  		> DDR0
    .data    	: {} palign(128) 	> DDR0
    .boardcfg_data        : {} palign(128)           > DDR0
    .sysmem  	: {} 				> DDR0

    .stack  	: {} align(4)		> DDR0  
    .irqStack  	: {. = . + __IRQ_STACK_SIZE;} align(4)		> DDR0 (HIGH) 
    RUN_START(__IRQ_STACK_START)
    RUN_END(__IRQ_STACK_END)
    .fiqStack  	: {. = . + __FIQ_STACK_SIZE;} align(4)		> DDR0 (HIGH) 
    RUN_START(__FIQ_STACK_START)
    RUN_END(__FIQ_STACK_END)
    .abortStack  	: {. = . + __ABORT_STACK_SIZE;} align(4)    > DDR0 (HIGH) 
    RUN_START(__ABORT_STACK_START)
    RUN_END(__ABORT_STACK_END)
    .undStack  	: {. = . + __UND_STACK_SIZE;} align(4)		> DDR0 (HIGH) 
    RUN_START(__UND_STACK_START)
    RUN_END(__UND_STACK_END)
    .svcStack  	: {. = . + __SVC_STACK_SIZE;} align(4)		> DDR0 (HIGH) 
    RUN_START(__SVC_STACK_START)
    RUN_END(__SVC_STACK_END)

/* Additional sections settings 	*/

}  /* end of SECTIONS */

/*----------------------------------------------------------------------------*/
/* Misc linker settings                                                       */


/*-------------------------------- END ---------------------------------------*/

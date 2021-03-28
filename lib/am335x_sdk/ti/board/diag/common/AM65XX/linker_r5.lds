/*----------------------------------------------------------------------------*/
/* File: linker_r5.lds                                                        */
/* Description:																  */
/*    Link command file for AM65xx       							          */
/*	  TI ARM Compiler version 15.12.3 LTS or later							  */
/*                                                                            */
/*    Platform: QT                                                            */
/* (c) Texas Instruments 2017, All rights reserved.                           */
/*----------------------------------------------------------------------------*/
/*  History:															      */
/*    Aug 26th, 2016 Original version .......................... Loc Truong   */
/*    Aug 01th, 2017 new TCM mem map  .......................... Loc Truong   */
/*    Nov 07th, 2017 Changes for R5F Init Code.................. Vivek Dhande */
/*    Nov 11th, 2018 Updated for diagnostic tests .............. EVM team     */
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

-stack  0x8000                              /* SOFTWARE STACK SIZE           */
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
	OCMCRAM     : ORIGIN = 0x000041C00000, LENGTH = 0x00080000				/* MCUSS-OCMC RAM - 512KB 					*/
    BOOTVECTOR  : ORIGIN = 0x000070000100, LENGTH = 0x00001000 - 0x100      /* MSMC RAM INIT CODE (4 KB)				*/
    DIAG_FRAMEWORK  : ORIGIN = 0x000070001000, LENGTH = 0x80000 - 0x1000	/* MSMC resrved for diag framework - Don't use for diag tests */
    DIAG_COMMON     : ORIGIN = 0x000070080000, LENGTH = 0x68000				/* MSMC for diag common usage */
    DIAG_STACK      : ORIGIN = 0x0000700E8000, LENGTH = 0x8000				/* MSMC for diag stack */
    DMSC_RSVD       : ORIGIN = 0x0000700F0000, LENGTH = 0x10000				/* MSMC reserved for DMSC - DO NOT use it */
    DIAG_DATA       : ORIGIN = 0x000070100000, LENGTH = 0xF0000				/* MSMC for diag data */
    DDR_0      (RWX) : ORIGIN =  0x80000000, LENGTH = 0x10000000
    DDR_1      (RWX) : ORIGIN =  0x90000000, LENGTH = 0x10000000
    DDR_2      (RWX) : ORIGIN =  0xA0000000, LENGTH = 0x60000000

}  /* end of MEMORY */

/*----------------------------------------------------------------------------*/
/* Section Configuration                                                      */

SECTIONS
{
/* 'intvecs' and 'intc_text' sections shall be placed within                  */
/* a range of +\- 16 MB                                                       */
    .intvecs 	: {} palign(8) 		> BOOTVECTOR
    .intc_text 	: {} palign(8) 		> BOOTVECTOR
    .rstvectors 	: {} palign(8) 		> OCMCRAM
    .startupCode   : {} palign(8)      > DIAG_COMMON
    .bootCode   : {} palign(8)      > DIAG_COMMON
    .startupData   : {} palign(8)      > DIAG_DATA, type = NOINIT
    .text    	: {} palign(8) 		> DIAG_COMMON
    diagData   : {} palign(8)      > DIAG_DATA
    .const   	: {} palign(8) 		> DIAG_DATA
    .cinit   	: {} palign(8) 		> DIAG_DATA
    .pinit   	: {} palign(8) 		> DIAG_DATA
    .bss     	: {} align(4)  		> DIAG_DATA
    .data    	: {} palign(128) 	> DIAG_DATA
	.sysmem  	: {} 				> DIAG_COMMON
    .bss:extMemCache:ramdisk : {} align (32)     > DIAG_COMMON
	.stack  	: {} align(4)		> DIAG_STACK  (HIGH)
	.irqStack  	: {. = . + __IRQ_STACK_SIZE;} align(4)		> DIAG_COMMON  (HIGH)
    usbramdisk   	: {} palign(8) 		> DIAG_DATA
    RUN_START(__IRQ_STACK_START)
    RUN_END(__IRQ_STACK_END)
    .fiqStack  	: {. = . + __FIQ_STACK_SIZE;} align(4)		> DIAG_COMMON  (HIGH)
    RUN_START(__FIQ_STACK_START)
    RUN_END(__FIQ_STACK_END)
    .abortStack  	: {. = . + __ABORT_STACK_SIZE;} align(4)		> DIAG_COMMON  (HIGH)
    RUN_START(__ABORT_STACK_START)
    RUN_END(__ABORT_STACK_END)
    .undStack  	: {. = . + __UND_STACK_SIZE;} align(4)		> DIAG_COMMON  (HIGH)
    RUN_START(__UND_STACK_START)
    RUN_END(__UND_STACK_END)
    .svcStack  	: {. = . + __SVC_STACK_SIZE;} align(4)		> DIAG_COMMON  (HIGH)
    RUN_START(__SVC_STACK_START)
    RUN_END(__SVC_STACK_END)
    /* Keep the DDR sections at the end to make sure
       any of the above stack sections are not getting into
       the DDR memory.
     */
	uartbuffer   	: {} palign(8) 		> DDR_0
    .data_buffer   	: {} palign(8) 		> DDR_0

/* Additional sections settings 	*/

}  /* end of SECTIONS */

/*----------------------------------------------------------------------------*/
/* Misc linker settings                                                       */


/*-------------------------------- END ---------------------------------------*/

/*----------------------------------------------------------------------------*/
/* File: emac_linker_r5.cmd                                                  */
/* Description:																  */
/*    Link command file for AM65XX M4 MCU 0 view							  */
/*	  TI ARM Compiler version 15.12.3 LTS or later							  */
/*                                                                            */
/*    Platform: QT                                                            */
/* (c) Texas Instruments 2017, All rights reserved.                           */
/*----------------------------------------------------------------------------*/
/*  History:															      *'
/*    Aug 26th, 2016 Original version .......................... Loc Truong   */
/*    Aug 01th, 2017 new TCM mem map  .......................... Loc Truong   */
/*    Nov 07th, 2017 Changes for R5F Init Code.................. Vivek Dhande */
/*----------------------------------------------------------------------------*/
/* Linker Settings                                                            */
/* Standard linker options													  */
--entry_point=ti_sysbios_family_arm_v7r_keystone3_Hwi_vectors
--retain="*(.intvecs)"
--retain="*(.intc_text)"
--retain="*(.rstvectors)"
--fill_value=0

/*----------------------------------------------------------------------------*/
/* Memory Map                                                                 */
MEMORY
{
	VECTORS (X)  			: origin=0x41C7F000 length=0x1000
    /*  Reset Vectors base address(RESET_VECTORS) should be 64 bytes aligned  */
	RESET_VECTORS (X)  			: origin=0x41C00000 length=0x100
    /* MCU0_R5F_0 local view 												  */
    MCU0_R5F_TCMA (X)		: origin=0x0			length=0x8000 fill=0xffffffff
    MCU0_R5F_TCMB0 (RWIX)	: origin=0x41010000	length=0x8000

    /* MCU0_R5F_1 SoC view													  */
    MCU0_R5F1_ATCM (RWIX)  	: origin=0x41400000 length=0x8000
    MCU0_R5F1_BTCM (RWIX) 	: origin=0x41410000 length=0x8000

    /* MCU0 share locations													  */
    OCMRAM 	(RWIX) 		: origin=0x41C3e000 length=0x42000 - 0x1000	     /* ~510KB */

    /* AM65XX M4 locations													  */
    MSMC3	(RWIX)	 	: origin=0x70000000 length=0xF0000			/* 1MB-64K */
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
    .intvecs 	: {} palign(8) 		> VECTORS
    .intc_text 	: {} palign(8) 		> VECTORS
    .rstvectors 	: {} palign(8) 		> RESET_VECTORS
    .text    	: {} palign(8) 		> DDR0 
    .const   	: {} palign(8) 		> DDR0
    .cinit   	: {} palign(8) 		> DDR0
    .pinit   	: {} palign(8) 		> DDR0
    .bss     	: {} align(4)  		> DDR0
    .data    	: {} palign(128) 	> DDR0
    .boardcfg_data        : {} palign(128)           > DDR0
	.sysmem  	: {} 				> DDR0
    .startup_text: { -l *sysbios.aer5f*(.text)
                     -l *boot.aer5f*(.text)
                     -l *auto_init.aer5f*(.text)
                    } > MSMC3_H
    .stack  	: {} align(4)		> DDR0

/* Additional sections settings 	*/

}  /* end of SECTIONS */

/*----------------------------------------------------------------------------*/
/* Misc linker settings                                                       */


/*-------------------------------- END ---------------------------------------*/

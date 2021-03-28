/****************************************************************************/
/*  OMAPL137.cmd                                                            */
/*  Copyright (c) 2010 Texas Instruments Incorporated                       */
/*  Author: Rafael de Souza                                                 */
/*                                                                          */
/*    Description: This file is a sample linker command file that can be    */
/*                 used for linking programs built with the C compiler and  */
/*                 running the resulting .out file on an OMAPL137           */
/*                 device.  Use it as a guideline.  You will want to        */
/*                 change the memory layout to match your specific          */
/*                 target system.  You may want to change the allocation    */
/*                 scheme according to the size of your program.            */
/*                                                                          */
/*    Usage:       The map below contains the local memory for each core    */
/*                 Use the linker option --define=DSP_CORE=n                */
/*                 Where n defines the core used: DSP (n=1) or ARM (n=0)    */
/*                                                                          */
/****************************************************************************/

MEMORY
{
#ifdef DSP_CORE      /* DSP exclusive memory regions */

    DSPL2ROM     o = 0x00700000  l = 0x00100000  /* 1MB L2 DSP local ROM */ 
    DSPL2RAM     o = 0x00800000  l = 0x00040000  /* 256kB L2 DSP local RAM */
    DSPL1PRAM    o = 0x00E00000  l = 0x00008000  /* 32kB L1 DSP local Program RAM */
    DSPL1DRAM    o = 0x00F00000  l = 0x00008000  /* 32kB L1 DSP local Data RAM */

#endif

    SHDSPL2ROM   o = 0x11700000  l = 0x00100000  /* 1MB L2 Shared Internal ROM */
    SHDSPL2RAM   o = 0x11800000  l = 0x00040000  /* 256kB L2 Shared Internal RAM */
    SHDSPL1PRAM  o = 0x11E00000  l = 0x00008000  /* 32kB L1 Shared Internal Program RAM */
    SHDSPL1DRAM  o = 0x11F00000  l = 0x00008000  /* 32kB L1 Shared Internal Data RAM */
    EMIFASDRAM   o = 0x40000000  l = 0x08000000  /* 64MB SDRAM Data (CS0) */  
    EMIFACS2     o = 0x60000000  l = 0x02000000  /* 32MB Async Data (CS2) */
    EMIFACS3     o = 0x62000000  l = 0x02000000  /* 32MB Async Data (CS3) */
    EMIFACS4     o = 0x64000000  l = 0x02000000  /* 32MB Async Data (CS4) */
    EMIFACS5     o = 0x66000000  l = 0x02000000  /* 32MB Async Data (CS5) */
    SHRAM        o = 0x80018000  l = 0x00008000  /* 32KB of Shared RAM. Note: 96KB of RAM is used by SBL */
    EMIFBSDRAM   o = 0xC0000000  l = 0x10000000  /* 256MB SDRAM Data */

#ifndef DSP_CORE     /* ARM exclusive memory regions */

    ARMROM       o = 0xFFFD0000  l = 0x00010000  /* 64kB ARM local ROM */
    ARMRAM       o = 0xFFFF0000  l = 0x00002000  /* 8kB ARM local RAM */

#endif
}

SECTIONS
{
    .text          >  EMIFBSDRAM
    .stack         >  EMIFBSDRAM
    .bss           >  SHRAM
    .cio           >  EMIFBSDRAM
    .const         >  SHRAM
    .data          >  SHRAM
    .switch        >  EMIFBSDRAM
    .sysmem        >  EMIFBSDRAM
    .far           >  SHRAM
    .args          >  EMIFBSDRAM
    .ppinfo        >  EMIFBSDRAM
    .ppdata        >  SHRAM
  
    /* TI-ABI or COFF sections */
    .pinit         >  EMIFBSDRAM
    .cinit         >  EMIFBSDRAM
  
    /* EABI sections */
    .binit         >  EMIFBSDRAM
    .init_array    >  EMIFBSDRAM
    .neardata      >  SHRAM
    .fardata       >  SHRAM
    .rodata        >  SHRAM
    .c6xabi.exidx  >  EMIFBSDRAM
    .c6xabi.extab  >  EMIFBSDRAM
}

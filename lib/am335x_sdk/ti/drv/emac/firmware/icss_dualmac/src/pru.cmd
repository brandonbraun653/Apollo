/****************************************************************************/
/*  PRU.cmd                                                                 */
/*  Copyright (c) 2017-2019  Texas Instruments Incorporated                 */
/*  Author: Rafael de Souza                                                 */
/*                                                                          */
/*    Description: This file is a sample linker command file that can be    */
/*                 used for linking programs built with the C compiler and  */
/*                 running the resulting .out file on an PRU CORE device.   */
/*                 Use it as a guideline.  You will want to                 */
/*                 change the memory layout to match your specific          */
/*                 target system.  You may want to change the allocation    */
/*                 scheme according to the size of your program.            */
/*                                                                          */
/****************************************************************************/


MEMORY
{
    PAGE 0:
      PRUIMEM:   o = 0x00000000  l = 0x00002000  /* 8kB PRU0 Instruction RAM */
    PAGE 1:
      PRUDMEM:   o = 0x00000000  l = 0x00002000  /* 8kB PRU Data RAM 0 */
    PAGE 2:
      SHAREDMEM: o = 0x00010000  l = 0x00003000  /* 12kB Shared RAM */
}

SECTIONS
{
    .text:Start	   >  0x00
    .text          >  PRUIMEM, PAGE 0 palign = 16
    .bss           >  PRUDMEM, PAGE 1 palign = 16
    .data          >  PRUDMEM, PAGE 1 palign = 16
    .rodata        >  PRUDMEM, PAGE 1 palign = 16
    .farbss        >  SHAREDMEM, PAGE 2
    .fardata       >  SHAREDMEM, PAGE 2
    .rofardata     >  SHAREDMEM, PAGE 2
    .sysmem        >  PRUDMEM, PAGE 1
    .stack         >  PRUDMEM, PAGE 1
    .init_array    >  PRUDMEM, PAGE 1
    .cinit         >  PRUDMEM, PAGE 1
    .args          >  PRUDMEM, PAGE 1
    .resource_table >  PRUDMEM, PAGE 1 palign = 16
    .version_string >  PRUDMEM, PAGE 1 palign = 16
}



/****************************************************************************/
/*  PRU.cmd                                                                 */
/*  Copyright (c) 2017-2018  Texas Instruments Incorporated                 */
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
#ifndef AM437X_ICSS0
        /* ICSS1 */
        /* 8 kB PRU Instruction RAM */
        PRUIMEM:   o = 0x00000000  l = 0x00002000
#else
        /* ICSS0 */
        /* 4 kB PRU Instruction RAM */
        PRUIMEM:   o = 0x00000000  l = 0x00001000
#endif

    PAGE 1:
#ifndef AM437X_ICSS0    
        /* ICSS1 */
        /* ICSS1, 8 kB PRU Data RAM, local */
        PRUDMEM       : o = 0x00000000  l = 0x00001100
        PRUDMEM_CTXT  : o = 0x00001100  l = 0x00000F00
        /* ICSS1, 8 kB PRU Data RAM, other */
        PRUDMEMO      : o = 0x00002000  l = 0x00002000        
#else        
        /* ICSS0 */
        /* ICSS0, 4 kB PRU Data RAM, local */
        PRUDMEM       : o = 0x00000000  l = 0x00000D00
        PRUDMEM_CTXT  : o = 0x00000D00  l = 0x000000A0
        PRUDMEM_SH    : o = 0x00000DA0  l = 0x00000260
        /* ICSS0, 4 kB PRU Data RAM, other */
        PRUDMEMO      : o = 0x00002000  l = 0x00001000
#endif
      
    PAGE 2:
#ifndef AM437X_ICSS0    
        SHAREDMEM: o = 0x00010000  l = 0x00003000  /* 12kB Shared RAM */
#else        
        SHAREDMEM: o = 0x00050000  l = 0x00003000  /* ICSS1 12kB Shared RAM */
#endif        
}

SECTIONS
{
    .text:I2C_scheduler	    >  0x00
    .text                   >  PRUIMEM, PAGE 0
    .bss                    >  PRUDMEM, PAGE 1
    .data                   >  PRUDMEM, PAGE 1
    .rodata                 >  PRUDMEM, PAGE 1
    .farbss                 >  SHAREDMEM, PAGE 2
    .fardata                >  SHAREDMEM, PAGE 2
    .rofardata              >  SHAREDMEM, PAGE 2
    .sysmem                 >  PRUDMEM, PAGE 1
    .stack                  >  PRUDMEM, PAGE 1
    .init_array             >  PRUDMEM, PAGE 1
    .cinit                  >  PRUDMEM, PAGE 1
    .args                   >  PRUDMEM, PAGE 1
    
    /* I2C context */
    .i2c_ctxt               >  PRUDMEM_CTXT, PAGE 1 
    
    /* Shared info */
    /* shared info located in DMEM0 */
    .pru0_tmp_ctxt          >  0x00000DA0, PAGE 1
    .pru1_tmp_ctxt          >  0x00002DA0, PAGE 1
    /* shared info located in DMEM1 */
    /* 
    .pru0_tmp_ctxt          >  0x00002DA0, PAGE 1
    .pru1_tmp_ctxt          >  0x00000DA0, PAGE 1 
    */
}



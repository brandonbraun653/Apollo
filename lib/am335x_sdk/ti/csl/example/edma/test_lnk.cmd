-c
-heap  0x2000
-stack 0x2000


/* Memory Map 1 - the default */
MEMORY
{
        L1D:     o = 00f00000h   l = 00007FFFh 
        L1P:     o = 00e00000h   l = 00007FFFh 
        MSMC:    o = 0C000000h   l = 001FFFFFh 
        L2SRAM:  o = 10800000h   l = 00080000h
} 

SECTIONS
{
    .csl_vect   >       MSMC
    .text       >       MSMC
    .stack      >       MSMC
    .bss        >       MSMC
    .cinit      >       MSMC
    .cio        >       MSMC
    .const      >       MSMC
    .data       >       MSMC
    .switch     >       MSMC
    .sysmem     >       MSMC
    .far        >       MSMC
    .testMem    >       MSMC  
    .fardata    >       MSMC
    .neardata   >       MSMC
    .rodata     >       MSMC
    
}
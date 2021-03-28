-c
-heap  0x2000
-stack 0x2000


/* Memory Map 1 - the default */
MEMORY
{
        L1D:     o = 00f00000h   l = 00007FFFh 
        L1P:     o = 00e00000h   l = 00007FFFh 
        L2:      o = 00800000h   l = 0007FFFFh 
} 

SECTIONS
{
    .csl_vect   >       L2
    .text       >       L2
    .stack      >       L2
    .bss        >       L2
    .cinit      >       L2
    .cio        >       L2
    .const      >       L2
    .data       >       L2
    .switch     >       L2
    .sysmem     >       L2
    .far        >       L2
    .testMem    >       L2  
     ISRAM1     >       L2 
     ISRAM      >       L2 
    .fardata    >       L2
    .neardata   >       L2
    .rodata     >       L2
}
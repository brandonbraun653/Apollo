SECTIONS
{
    .bss        : load >> L2SRAM
                /* GLOBAL & STATIC VARS              */
    .data       : load >> L2SRAM               /* GLOBAL & STATIC VARS              */
    .sysmem     : load >> L2SRAM               /* DYNAMIC MEMORY ALLOCATION AREA    */
    .stack      : load >> L2SRAM        /* SOFTWARE SYSTEM STACK             */

    .text       : load >> L2SRAM   /* CODE                              */
    .text:_isr  : load >> L2SRAM             /* ISR CODE SPACE                    */
    .cinit      : load >> L2SRAM          /* INITIALIZATION TABLES             */
//#ifdef (__LARGE_DATA_MODEL__)
    .const      : load >> L2SRAM   /* CONSTANT DATA                     */
//#else
//    .const      : {} > FLASH              /* CONSTANT DATA                     */
//#endif
    .cio        : load >> L2SRAM               /* C I/O BUFFER                      */
    .testData: load >> L2SRAM
    .init_array: load >> L2SRAM
}

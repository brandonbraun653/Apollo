/*	File: linker.lds
 *	Purpose: single core A53 C app for Maxwell-M4
 *			 For QT use only (not for EVM or SVB)
*/
ENTRY(_bootcode)

STACKSIZE = 0x40000;
HEAPSIZE  = 0x40000;

MEMORY
{
/*	QT MEMORY MAP FOR MAXWELL */
OCMCRAM		: ORIGIN = 0x000041C00000, LENGTH = 0x00080000
BOOTCODE    : ORIGIN = 0x000070000100, LENGTH = 0x00001000 - 0x100
MSMC_SRAM   : ORIGIN = 0x000070001000, LENGTH = 0x0017F000
DV_DONOTUSE : ORIGIN = 0x000070180000, LENGTH = 0x00080000
SYSDDR0		: ORIGIN = 0x000080000000, LENGTH = 0x80000000
}

SECTIONS
{
	startup   : { *entry.o(.text) *entry.o(.rodata) } > OCMCRAM
	.text : { *(.text) } >SYSDDR0
	.data : { *(.data) } >SYSDDR0
  .init           :
  {
    KEEP (*crti_m.o(.init) )
    KEEP (*(.init) )
    *(.rodata .rodata.* .gnu.linkonce.r.*)
  } > SYSDDR0

 .finit           :
  {
    KEEP (*(.fini))
  } > SYSDDR0

 /* for libc_init_array calling static intialization*/
    . = ALIGN(4);
    .preinit_array :
    {
    __preinit_array_start = .;
    KEEP (*(.preinit_array*))
    __preinit_array_end = .;
    } > SYSDDR0

    . = ALIGN(4);
    .init_array :
    {
    __init_array_start = .;
    KEEP (*(.init_array*))
    __init_array_end = .;
    } > SYSDDR0

    . = ALIGN(4);
    .fini_array :
    {
    __fini_array_start = .;
    KEEP (*(.fini_array*))
    __fini_array_end = .;
    } > SYSDDR0

 /* Uninitialized data */
    . = ALIGN(4);
	.bss   :
	{
		__bss_start   = .;
		__bss_start__ = .;
		_bstart = .;

		*(.bss*)
		__bss_end   = .;
		__bss_end__ = .;
		_bend = .;
	}  > SYSDDR0

	/* C RTS Heap and stack space */
	.heap (NOLOAD):
	{
        . = ALIGN(16);
		__HeapBase = .;
				__end   = .;
        __end__ = .;
        end = __end__;
        *(.heap*)
        . = . + HEAPSIZE;
        __HeapLimit = .;
    } > SYSDDR0

    .stack (NOLOAD):
    {
        . = ALIGN(16);
        __StackLimit = . ;
        *(.stack*)
        . = . + STACKSIZE;
        __StackTop = . ;
        __StackBase = . ;
    } > SYSDDR0

    PROVIDE(__stack = __StackTop);
}
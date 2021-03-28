/*	File: linker_a53.lds
 *  Semihosting supported gcc Linker script for maxwell A53 for QT
 *	Purpose: single core A53 C app
*/
__STACK_SIZE = 0x8000;
__TI_STACK_SIZE = __STACK_SIZE;

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
}

REGION_ALIAS("REGION_TEXT", DIAG_COMMON);
REGION_ALIAS("REGION_BSS", DIAG_DATA);
REGION_ALIAS("REGION_USB_RAMDISK", DIAG_DATA);
REGION_ALIAS("REGION_DIAG_DATA", DIAG_COMMON);
REGION_ALIAS("REGION_DIAG_CODE", DIAG_DATA);
REGION_ALIAS("REGION_DATA", DIAG_DATA);
REGION_ALIAS("REGION_STACK", DIAG_STACK);
REGION_ALIAS("REGION_HEAP", DIAG_DATA);
REGION_ALIAS("REGION_ARM_EXIDX", DIAG_COMMON);
REGION_ALIAS("REGION_ARM_EXTAB", DIAG_COMMON);
REGION_ALIAS("REGION_TEXT_STARTUP", DIAG_COMMON);
REGION_ALIAS("REGION_DISPLAY_BUFFER", DDR_0);
REGION_ALIAS("REGION_DATA_BUFFER", DDR_1);
REGION_ALIAS("REGION_UART_BUFFER", DDR_0);

SECTIONS {

    .vecs : {
        *(.vecs)
    } > BOOTVECTOR AT> BOOTVECTOR

    .text.csl_a53_startup : {
        *(.text.csl_a53_startup)
		*(.Entry)
    } > REGION_TEXT_STARTUP AT> REGION_TEXT_STARTUP

    .text : {
        CREATE_OBJECT_SYMBOLS
        *(.text)
        *(.text.*)
        . = ALIGN(0x8);
        KEEP (*(.ctors))
        . = ALIGN(0x4);
        KEEP (*(.dtors))
        . = ALIGN(0x8);
        __init_array_start = .;
        KEEP (*(.init_array*))
        __init_array_end = .;
        *(.init)
        *(.fini*)
    } > REGION_TEXT AT> REGION_TEXT

    PROVIDE (__etext = .);
    PROVIDE (_etext = .);
    PROVIDE (etext = .);

    .rodata : {
        *(.rodata)
        *(.rodata*)
    } > REGION_TEXT AT> REGION_TEXT

    .data_buffer (NOLOAD) : ALIGN (8) {
        __data_buffer_load__ = LOADADDR (.data_buffer);
        __data_buffer_start__ = .;
        *(.data_buffer)
        *(.data_buffer*)
        . = ALIGN (8);
        __data_buffer_end__ = .;
    } > REGION_DATA_BUFFER AT> REGION_DATA_BUFFER

    .data : ALIGN (8) {
        __data_load__ = LOADADDR (.data);
        __data_start__ = .;
        *(.data)
        *(.data*)
        . = ALIGN (8);
        __data_end__ = .;
    } > REGION_DATA AT> REGION_DATA_BUFFER

    .ARM.exidx : {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > REGION_ARM_EXIDX AT> REGION_ARM_EXIDX

    .ARM.extab : {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > REGION_ARM_EXTAB AT> REGION_ARM_EXTAB

    .bss : {
        __bss_start__ = .;
        *(.shbss)
        *(.bss)
        *(.bss.*)
        . = ALIGN (8);
        __bss_end__ = .;
        . = ALIGN (8);
        __bss_common_start__ = .;
        *(COMMON)
        __bss_common_end__ = .;
    } > REGION_BSS AT> REGION_BSS

    .heap : {
        __heap_start__ = .;
        end = __heap_start__;
        _end = end;
        __end = end;
        KEEP(*(.heap))
        __heap_end__ = .;
        __HeapLimit = __heap_end__;
    } > REGION_HEAP AT> REGION_HEAP

    .stack (NOLOAD) : ALIGN(16) {
        _stack = .;
        __stack = .;
        KEEP(*(.stack))
    } > REGION_STACK AT> REGION_STACK

	__TI_STACK_BASE = __stack;

    usbramdisk :
    {
        . = ALIGN(8);
        *(usbramdisk*)
    } > REGION_USB_RAMDISK

    displaybuffer :
    {
        . = ALIGN(8);
        *(displaybuffer*)
    } > REGION_DISPLAY_BUFFER AT> REGION_DISPLAY_BUFFER

    uartbuffer (NOLOAD):
    {
        . = ALIGN(8);
        *(uartbuffer*)
    } > REGION_UART_BUFFER AT> REGION_UART_BUFFER

    diagData :
    {
        . = ALIGN(8);
        *(diagData*)
    } > REGION_DIAG_DATA AT> REGION_DIAG_DATA

    diagCode : {
        CREATE_OBJECT_SYMBOLS
        *(.text)
        *(.text.*)
        . = ALIGN(0x8);
    } > REGION_DIAG_CODE AT> REGION_DIAG_CODE

    /* Stabs debugging sections.  */
    .stab          0 : { *(.stab) }
    .stabstr       0 : { *(.stabstr) }
    .stab.excl     0 : { *(.stab.excl) }
    .stab.exclstr  0 : { *(.stab.exclstr) }
    .stab.index    0 : { *(.stab.index) }
    .stab.indexstr 0 : { *(.stab.indexstr) }
    .comment       0 : { *(.comment) }
    /*
     * DWARF debug sections.
     * Symbols in the DWARF debugging sections are relative to the beginning
     * of the section so we begin them at 0.
     */
    /* DWARF 1 */
    .debug         0 : { *(.debug) }
    .line          0 : { *(.line) }
    /* GNU DWARF 1 extensions */
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }
    /* DWARF 1.1 and DWARF 2 */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    /* DWARF 2 */
    .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line .debug_line.* .debug_line_end ) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }
    /* SGI/MIPS DWARF 2 extensions */
    .debug_weaknames 0 : { *(.debug_weaknames) }
    .debug_funcnames 0 : { *(.debug_funcnames) }
    .debug_typenames 0 : { *(.debug_typenames) }
    .debug_varnames  0 : { *(.debug_varnames) }
    /* DWARF 3 */
    .debug_pubtypes 0 : { *(.debug_pubtypes) }
    .debug_ranges   0 : { *(.debug_ranges) }
    /* DWARF Extension.  */
    .debug_macro    0 : { *(.debug_macro) }
    .note.gnu.arm.ident 0 : { KEEP (*(.note.gnu.arm.ident)) }
    /DISCARD/ : { *(.note.GNU-stack) *(.gnu_debuglink) *(.gnu.lto_*) }
}

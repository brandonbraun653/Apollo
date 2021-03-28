/*	File: linker_a53.lds
 *  Semihosting supported gcc Linker script for maxwell A53 for QT
 *	Purpose: single core A53 C app
*/
__STACK_SIZE = 0x10000;
__TI_STACK_SIZE = __STACK_SIZE;

MEMORY
{
    OCMCRAM     : ORIGIN = 0x000041C00000, LENGTH = 0x00080000				/* MCUSS-OCMC RAM - 512KB 					*/
    BOOTVECTOR  : ORIGIN = 0x000070000100, LENGTH = 0x00001000 - 0x100      /* MSMC RAM INIT CODE (4 KB)				*/
    DIAG_FRAMEWORK  : ORIGIN = 0x000070001000, LENGTH = 0x6E000             /* MSMC resrved for diag framework - Don't use for diag tests */
    DIAG_FW_STACK   : ORIGIN = 0x00007006F000, LENGTH = 0x10000				/* MSMC for diag framework common usage */
    /* MSMC from 0x000070080000 is allocated for diag and DMSC. Do not use it for diag framework */
    DDR_0      (RWX) : ORIGIN =  0x80000000, LENGTH = 0x10000000
    DDR_1      (RWX) : ORIGIN =  0x90000000, LENGTH = 0x10000000
    DDR_2      (RWX) : ORIGIN =  0xA0000000, LENGTH = 0x60000000
}

REGION_ALIAS("REGION_TEXT", DIAG_FRAMEWORK);
REGION_ALIAS("REGION_BSS", DIAG_FRAMEWORK);
REGION_ALIAS("REGION_DATA", DIAG_FRAMEWORK);
REGION_ALIAS("REGION_STACK", DIAG_FW_STACK);
REGION_ALIAS("REGION_HEAP", DIAG_FRAMEWORK);
REGION_ALIAS("REGION_ARM_EXIDX", DIAG_FRAMEWORK);
REGION_ALIAS("REGION_ARM_EXTAB", DIAG_FRAMEWORK);
REGION_ALIAS("REGION_TEXT_STARTUP", DIAG_FRAMEWORK);

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

    .data : ALIGN (8) {
        __data_load__ = LOADADDR (.data);
        __data_start__ = .;
        *(.data)
        *(.data*)
        . = ALIGN (8);
        __data_end__ = .;
    } > REGION_DATA AT> REGION_TEXT

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
    .note.gnu.build-id (NOLOAD) : { *(.note.*) }
    /DISCARD/ : { *(.note.GNU-stack) *(.gnu_debuglink) *(.gnu.lto_*) }
}

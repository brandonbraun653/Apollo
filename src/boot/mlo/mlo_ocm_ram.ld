OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_startup)

MEMORY
{
   ocm_ram : ORIGIN = 0x402f0400, LENGTH = 0x1B400
}


SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        *(.text.startup);
        *(.text)
    } > ocm_ram

    .data :
    {
        . = ALIGN(4);
        *(.data)
    } > ocm_ram

    .bss :
    {
        . = ALIGN(4);
        PROVIDE_HIDDEN (__bss_start__ = .);
        *(.bss)
        PROVIDE_HIDDEN (__bss_end__ = .);
    } > ocm_ram

    .preinit_array :
    {
        . = ALIGN(4);
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP (*(.preinit_array*))
        PROVIDE_HIDDEN (__preinit_array_end = .);
    } > ocm_ram

    .init_array :
    {
        . = ALIGN(4);
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array*))
        PROVIDE_HIDDEN (__init_array_end = .);
    } > ocm_ram

    .fini_array :
    {
        . = ALIGN(4);
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP (*(SORT(.fini_array.*)))
        KEEP (*(.fini_array*))
        PROVIDE_HIDDEN (__fini_array_end = .);
    } > ocm_ram

    .note.gnu.build-id :
    {
        . = ALIGN(4);
        PROVIDE( _note = .);
        *(.note.gnu.build-id)
        . = ALIGN(4);
        *(.note.gnu.build-id.*);
        . = ALIGN(4);
        PROVIDE( _enote = .);
    }  > ocm_ram

    .heap :
    {
        . = ALIGN(4);
        __end__ = .;
        end = __end__;
        __HeapBase = __end__;
        *(.heap*)
        . = . + 0x800;
        __HeapLimit = .;
    } > ocm_ram

    .stack :
    {
        . = ALIGN(256);
        __StackLimit = . ;
        *(.stack*)
        . = . + 0x800;
        __StackTop = .;
    } > ocm_ram

    _stack = __StackTop;
}
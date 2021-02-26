/********************************************************************************
 *  File Name:
 *    boot_linker_refs.hpp
 *
 *  Description:
 *    Declare critical functions so the linker can't throw them away
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef APOLLO_MLO_LINKER_REFERENCES_HPP
#define APOLLO_MLO_LINKER_REFERENCES_HPP

/* STL Includes */
#include <cstdint>

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------
Constants provided by the linker script
-------------------------------------------------*/
extern void * _stack;
extern void * __data_start__;
extern void * __data_end__;
extern void * __bss_start__;
extern void * __bss_end__;
extern void * __preinit_array_start;
extern void * __preinit_array_end;
extern void * __init_array_start;
extern void * __init_array_end;
extern void * __fini_array_start;
extern void * __fini_array_end;
extern void * _note;
extern void * _enote;
extern void * __HeapBase;
extern void * __HeapLimit;
extern void * __StackLimit;
extern void * __StackTop;

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif  /* !APOLLO_MLO_LINKER_REFERENCES_HPP */

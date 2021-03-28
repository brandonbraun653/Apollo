/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** @mainpage Processor SDK Utilities
 *
 *  @section intro Introduction
 *
 *  This document describes the Processor SDK Utilities used for profiling, and
 *  potentially other tools developed by TI in the future.
 *  - @subpage profCCS
 *  - @subpage profDSS
 *
 */
/** @defgroup pdk_profiling_tool PDK Profiling tools
 *  @{
 */
/** @} */
/** @defgroup pdk_profiling_hooks PDK Instrumentation hooks
 *  @ingroup pdk_profiling_tool
 *  For more information, see:
 *  - @subpage profCCS
 *  - @subpage profDSS
 */
/**
 *  @file    profilingHooks.h
 *
 *  @brief   Declarations for the runtime programming hooks of the Processor SDK Profiling Tool.
 *
 *  For more information, see:
 *  - @subpage profCCS
 *  - @subpage profDSS
 *
 *  ## Usage ##
 *
 *  Applications that are included in a profiling session must  set these
 *  compiler flags for the desired platform:
 *    - ARM: `-finstrument-functions -gdwarf-3 -g`
 *    - DSP: `--entry_parm=address --exit_hook=ti_utils_exit --exit_parm=address --entry_hook=ti_utils_entry -g`
 *    - M4: `--entry_parm=address --exit_hook=ti_utils_exit --exit_parm=address --entry_hook=ti_utils_entry -g`
 *
 *  For best results, ensure that the optimization levels are consistent between
 *  the library and the project (typically -O3, or optimization level 3).
 *
 */
/* Defined for C66, or DSP */
#if defined (_TMS320C6X)

/*!
 *  @brief    TI Toolchain Utils Entry Hook
 *
 *  Instruments the entry point and timestamp of the current function into
 *  memory. Note that this function is automatically referenced at entry of
 *  every function by TI Toolchain.
 *
 *  @param    *func_addr  Function Assembly Address (Hexadecimal)
 */
void ti_utils_entry(void (* func_addr)(void));

/*!
 *  @brief    TI Toolchain Utils Exit Hook
 *
 *  Instruments the exit point and timestamp of the current function into
 *  memory. Note that this function is automatically referenced at end of
 *  every function by TI Toolchain.
 *
 *  @param    *func_addr  Function Assembly Address (Hexadecimal)
 */
void ti_utils_exit(void (* func_addr)(void));

#endif
/* Defined for M4 */
#if defined (__TI_ARM_V7M4__)

/*!
 *  @brief    TI Toolchain Utils Entry Hook
 *
 *  Instruments the entry point and timestamp of the current function into
 *  memory. Note that this function is automatically referenced at entry of
 *  every function by TI Toolchain.
 *
 *  @param    *func_addr  Function Assembly Address (Hexadecimal)
 */
void ti_utils_entry(void (* func_addr)(void));

/*!
 *  @brief    TI Toolchain Utils Exit Hook
 *
 *  Instruments the exit point and timestamp of the current function into
 *  memory. Note that this function is automatically referenced at end of
 *  every function by TI Toolchain.
 *
 *  @param    *func_addr  Function Assembly Address (Hexadecimal)
 */
void ti_utils_exit(void (* func_addr)(void));
/* Defined for ARM that is not M4 */
#elif defined(__arm__)

/*!
 *  @brief    ARMv7 GCC Utils Entry Hook
 *
 *  Instruments the entry point, call site and timestamp of the current function
 *  into memory. Note that this is a standard GCC library prototype function and
 *  is automatically referenced at the entry of every function by GCC.
 *
 *  @param    *this_fn    Function Assembly Address (Hexadecimal)
 *  @param    *call_site  Call Site Assembly Address (Hexadecimal)
 */
void __attribute__((no_instrument_function))__cyg_profile_func_enter(const void *this_fn, const void *call_site);

/*!
 *  @brief    ARMv7 GCC Utils Exit Hook
 *
 *  Instruments the entry point, call site and timestamp of the current function
 *  into memory. Note that this is a standard GCC library prototype function and
 *  is automatically referenced at the entry of every function by GCC.
 *
 *  @param    *this_fn    Function Assembly Address (Hexadecimal)
 *  @param    *call_site  Call Site Assembly Address (Hexadecimal)
 */
void __attribute__((no_instrument_function))__cyg_profile_func_exit(const void *this_fn, void *call_site);

#endif

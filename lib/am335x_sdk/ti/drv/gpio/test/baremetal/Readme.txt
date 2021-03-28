 ******************************************************************************
 * FILE PURPOSE: Readme File for building the baremetal test/example
 ******************************************************************************
 * FILE NAME: Readme.txt
 * Copyright (C) 2015, Texas Instruments, Inc.
 *****************************************************************************

The baremetal test/example makefile is located under ti/drv/gpio/test/<arch>,
where <arch> is "c66" or armv7, the makefile builds both the test and example.

To build baremetal test/example, run the following commands:

cd ti/drv/gpio
gmake -f test/baremetal/<arch>/makefile DEVICE=<DEVICE_NAME>

where <arch> is "c66" or armv7, and <DEVICE_NAME> is "K2H", "K2K", "K2E", "K2L", "C6678", "C6657".

Notes:
1. Currently only K2 C66 baremetal test/example is supported
2. PDK need to be installed properly to include the board/osal libs
3. The following paths need to be set/exported properly to build the test/example:
   * PDK_INSTALL_PATH
   * CGTOOLS
   * TOOLCHAIN_PATH_A15
   * CROSS_TOOL_PRFX

   E.g., in windows, run the following commands before calling the makefile:
         set PDK_INSTALL_PATH="C:/ti/<pdk_###>/packages"
         set CGTOOLS="C:/ti/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3"
         set TOOLCHAIN_PATH_A15="C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3"
         set CROSS_TOOL_PRFX="arm-none-eabi-"
 

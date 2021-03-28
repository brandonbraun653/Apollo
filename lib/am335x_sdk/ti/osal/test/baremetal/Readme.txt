 ******************************************************************************
 * FILE PURPOSE: Readme File for building the baremetal test/example
 ******************************************************************************
 * FILE NAME: Readme.txt
 * Copyright (C) 2016, Texas Instruments, Inc.
 *****************************************************************************

The baremetal test makefile is located under ti/osal/test,

To build baremetal test, run the following commands:

cd ti/osal
gmake -f test/baremetal/makefile MANUAL_CACHE_TEST=YES (Optional for AM572x C66/A15)

The MANUAL_CACHE_TEST=YES option will enable cache test which needs to be run interactively using a CCS.
Please do the following.
1) Connect CCS to A15/C66.
2) Load the program
3) Put a break point at OSAL_cache_test() and do single-step and follow the instructions printed out at the UART at the beginning of the cache test. 

Notes:
1. PDK need to be installed properly to include the board/osal libs
2. The following paths need to be set/exported properly to build the test using pdksetupenv script provided in the pdk:
   * PDK_INSTALL_PATH
   * CGTOOLS
   * TOOLCHAIN_PATH_A15
   * CROSS_TOOL_PRFX

   E.g., in Windows, run the following commands before calling the makefile:
         set PDK_INSTALL_PATH="C:/ti/pdk_am57xx_1_0_2/packages"
         set CGTOOLS="c:/ti/ccsv6/tools/compiler/ti-cgt-c6000_8.1.0"
         set TOOLCHAIN_PATH_A15="C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3"
         set TOOLCHAIN_PATH_A9="C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3"
         set TOOLCHAIN_PATH_A8="C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3"
         set TOOLCHAIN_PATH_M4="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5"
         set CROSS_TOOL_PRFX="arm-none-eabi-"
 

#
# Copyright (c) 2016 - 2019, Texas Instruments Incorporated
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# *  Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
# *  Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# *  Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
# OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
# EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

# File: fatfs_component.mk
#       This file is component include make file of FATFS library.
# List of variables set in this file and their purpose:
# <mod>_RELPATH        - This is the relative path of the module, typically from
#                        top-level directory of the package
# <mod>_PATH           - This is the absolute path of the module. It derives from
#                        absolute path of the top-level directory (set in env.mk)
#                        and relative path set above
# <mod>_INCLUDE        - This is the path that has interface header files of the
#                        module. This can be multiple directories (space separated)
# <mod>_PKG_LIST       - Names of the modules (and sub-modules) that are a part
#                        part of this module, including itself.
# <mod>_BOARD_DEPENDENCY - "yes": means the code for this module depends on
#                             board and the compiled obj/lib has to be kept
#                             under <board> directory
#                             "no" or "" or if this variable is not defined: means
#                             this module has no board dependent code and hence
#                             the obj/libs are not kept under <board> dir.
# <mod>_CORE_DEPENDENCY     - "yes": means the code for this module depends on
#                             core and the compiled obj/lib has to be kept
#                             under <core> directory
#                             "no" or "" or if this variable is not defined: means
#                             this module has no core dependent code and hence
#                             the obj/libs are not kept under <core> dir.
# <mod>_APP_STAGE_FILES     - List of source files that belongs to the module
#                             <mod>, but that needs to be compiled at application
#                             build stage (in the context of the app). This is
#                             primarily for link time configurations or if the
#                             source file is dependent on options/defines that are
#                             application dependent. This can be left blank or
#                             not defined at all, in which case, it means there
#                             no source files in the module <mod> that are required
#                             to be compiled in the application build stage.
#
ifeq ($(fatfs_component_make_include), )

# under other list
drvfatfs_BOARDLIST       = am65xx_evm am65xx_idk j721e_sim j721e_evm j7200_evm
drvfatfs_SOCLIST           = am574x am572x am571x am437x am335x dra72x dra75x dra78x k2g omapl137 omapl138 am65xx j721e j7200
drvfatfs_am574x_CORELIST   = c66x a15_0 ipu1_0
drvfatfs_am572x_CORELIST   = c66x a15_0 ipu1_0
drvfatfs_am571x_CORELIST   = c66x a15_0 ipu1_0
drvfatfs_dra72x_CORELIST   = c66x a15_0 ipu1_0
drvfatfs_dra75x_CORELIST   = c66x a15_0 ipu1_0
drvfatfs_dra78x_CORELIST   = c66x ipu1_0
drvfatfs_am437x_CORELIST   = a9host
drvfatfs_am335x_CORELIST   = a8host
drvfatfs_k2g_CORELIST      = c66x a15_0
drvfatfs_omapl137_CORELIST = arm9_0 c674x
drvfatfs_omapl138_CORELIST = arm9_0 c674x
drvfatfs_am65xx_CORELIST   = mpu1_0 mcu1_0
drvfatfs_j721e_CORELIST   = $(DEFAULT_j721e_CORELIST)
drvfatfs_j7200_CORELIST    = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1
############################
# uart package
# List of components included under uart lib
# The components included here are built and will be part of uart lib
############################
fatfs_LIB_LIST = fatfs_indp fatfs_multi_indp fatfs_profile_indp
drvfatfs_LIB_LIST = $(fatfs_LIB_LIST)
fatfs_EXAMPLE_LIST = 

#
# FATFS Modules
#

# FATFS LIB DEVICE INDEPENDENT
fatfs_indp_COMP_LIST = fatfs_indp
fatfs_indp_RELPATH = ti/fs/fatfs
fatfs_indp_PATH = $(PDK_FATFS_COMP_PATH)
fatfs_indp_LIBNAME = ti.fs.fatfs
export fatfs_indp_LIBNAME
fatfs_indp_LIBPATH = $(fatfs_indp_PATH)/lib
export fatfs_indp_LIBPATH
fatfs_indp_OBJPATH = $(fatfs_indp_RELPATH)/fatfs_indp
export fatfs_indp_OBJPATH
fatfs_indp_MAKEFILE = -f build/makefile_indp.mk
export fatfs_indp_MAKEFILE
fatfs_indp_BOARD_DEPENDENCY = no
fatfs_indp_CORE_DEPENDENCY = no
fatfs_indp_SOC_DEPENDENCY = no
export fatfs_indp_COMP_LIST
export fatfs_indp_BOARD_DEPENDENCY
export fatfs_indp_CORE_DEPENDENCY
export fatfs_indp_SOC_DEPENDENCY
fatfs_indp_PKG_LIST = fatfs_indp
export fatfs_indp_PKG_LIST
fatfs_indp_INCLUDE = $(fatfs_indp_PATH)
fatfs_indp_SOCLIST = $(drvfatfs_SOCLIST)
export fatfs_indp_SOCLIST
fatfs_indp_$(SOC)_CORELIST = $(drvfatfs_$(SOC)_CORELIST)
export fatfs_indp_$(SOC)_CORELIST

# FATFS PROFILING SOC INDEPENDENT LIB
fatfs_profile_indp_COMP_LIST = fatfs_profile_indp
fatfs_profile_indp_RELPATH = ti/fs/fatfs
fatfs_profile_indp_PATH = $(PDK_FATFS_COMP_PATH)
fatfs_profile_indp_LIBNAME = ti.fs.fatfs.profiling
export fatfs_profile_indp_LIBNAME
fatfs_profile_indp_LIBPATH = $(fatfs_profile_indp_PATH)/lib
export fatfs_profile_indp_LIBPATH
fatfs_profile_indp_OBJPATH = $(fatfs_profile_indp_RELPATH)/fatfs_profile_indp
export fatfs_profile_indp_OBJPATH
fatfs_profile_indp_MAKEFILE = -f build/makefile_profile_indp.mk
export fatfs_profile_indp_MAKEFILE
fatfs_profile_indp_BOARD_DEPENDENCY = no
fatfs_profile_indp_CORE_DEPENDENCY = no
fatfs_profile_indp_SOC_DEPENDENCY = no
export fatfs_profile_indp_COMP_LIST
export fatfs_profile_indp_BOARD_DEPENDENCY
export fatfs_profile_indp_CORE_DEPENDENCY
export fatfs_profile_indp_SOC_DEPENDENCY
fatfs_profile_indp_PKG_LIST = fatfs_profile_indp
export fatfs_profile_indp_PKG_LIST
fatfs_profile_indp_INCLUDE = $(fatfs_profile_indp_PATH)
fatfs_profile_indp_SOCLIST = am574x am572x am571x am437x am335x dra72x dra75x dra78x k2g omapl137 omapl138
export fatfs_profile_indp_SOCLIST
fatfs_profile_indp_$(SOC)_CORELIST = $(drvfatfs_$(SOC)_CORELIST)
export fatfs_profile_indp_$(SOC)_CORELIST

# EMMC Readwrite test
FATFS_Console_TestApp_COMP_LIST = FATFS_Console_TestApp
FATFS_Console_TestApp_RELPATH = ti/fs/fatfs/example/console
FATFS_Console_TestApp_PATH = $(PDK_FATFS_COMP_PATH)/example/console
FATFS_Console_TestApp_BOARD_DEPENDENCY = yes
FATFS_Console_TestApp_CORE_DEPENDENCY = no
FATFS_Console_TestApp_XDC_CONFIGURO = yes
export FATFS_Console_TestApp_COMP_LIST
export FATFS_Console_TestApp_BOARD_DEPENDENCY
export FATFS_Console_TestApp_CORE_DEPENDENCY
export FATFS_Console_TestApp_XDC_CONFIGURO
FATFS_Console_TestApp_PKG_LIST = FATFS_Console_TestApp
FATFS_Console_TestApp_INCLUDE = $(FATFS_Console_TestApp_PATH)
FATFS_Console_TestApp_BOARDLIST = $(drvfatfs_BOARDLIST)
export FATFS_Console_TestApp_BOARDLIST
FATFS_Console_TestApp_$(SOC)_CORELIST = $(drvfatfs_$(SOC)_CORELIST)
export FATFS_Console_TestApp_$(SOC)_CORELIST

fatfs_EXAMPLE_LIST += FATFS_Console_TestApp

# EMMC Readwrite test with SMP enabled
FATFS_Console_SMP_TestApp_COMP_LIST = FATFS_Console_SMP_TestApp
FATFS_Console_SMP_TestApp_RELPATH = ti/fs/fatfs/example/console
FATFS_Console_SMP_TestApp_PATH = $(PDK_FATFS_COMP_PATH)/example/console
FATFS_Console_SMP_TestApp_MAKEFILE = -f makefile SMP=enable
FATFS_Console_SMP_TestApp_BOARD_DEPENDENCY = yes
FATFS_Console_SMP_TestApp_CORE_DEPENDENCY = no
FATFS_Console_SMP_TestApp_XDC_CONFIGURO = yes
export FATFS_Console_SMP_TestApp_COMP_LIST
export FATFS_Console_SMP_TestApp_BOARD_DEPENDENCY
export FATFS_Console_SMP_TestApp_CORE_DEPENDENCY
export FATFS_Console_SMP_TestApp_XDC_CONFIGURO
FATFS_Console_SMP_TestApp_PKG_LIST = FATFS_Console_SMP_TestApp
FATFS_Console_SMP_TestApp_INCLUDE = $(FATFS_Console_SMP_TestApp_PATH)
FATFS_Console_SMP_TestApp_BOARDLIST = am65xx_idk
export FATFS_Console_SMP_TestApp_BOARDLIST
FATFS_Console_SMP_TestApp_$(SOC)_CORELIST = mpu1_0
export FATFS_Console_SMP_TestApp_$(SOC)_CORELIST

fatfs_EXAMPLE_LIST += FATFS_Console_SMP_TestApp

export drvfatfs_LIB_LIST
export fatfs_LIB_LIST
export fatfs_EXAMPLE_LIST

drvfatfs_EXAMPLE_LIST = $(fatfs_EXAMPLE_LIST)
export drvfatfs_EXAMPLE_LIST

fatfs_component_make_include := 1
endif

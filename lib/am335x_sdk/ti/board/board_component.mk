#
# Copyright (c) 2017, Texas Instruments Incorporated
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

# File: board_component.mk
#       This file is component include make file of BOARD library.
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
ifeq ($(board_component_make_include), )

board_lib_BOARDLIST       = evmAM335x icev2AM335x iceAMIC110 skAM335x bbbAM335x evmAM437x idkAM437x skAM437x evmAM572x idkAM571x idkAM572x evmK2H evmK2K evmK2E evmK2L evmK2G iceK2G \
                            evmC6678 evmC6657 tda2xx-evm evmDRA75x tda2ex-evm evmDRA72x tda3xx-evm evmDRA78x evmOMAPL137 lcdkOMAPL138 idkAM574x am65xx_evm am65xx_idk j721e_sim j721e_qt j721e_evm j7200_evm \
                            tpr12_evm
board_lib_tda2xx_CORELIST = a15_0 ipu1_0 c66x
board_lib_tda2ex_CORELIST = a15_0 ipu1_0 c66x
board_lib_tda3xx_CORELIST = ipu1_0 c66x
board_lib_dra72x_CORELIST = a15_0 ipu1_0 c66x
board_lib_dra75x_CORELIST = a15_0 ipu1_0 c66x
board_lib_dra78x_CORELIST = ipu1_0 c66x
board_lib_am572x_CORELIST = c66x a15_0 ipu1_0
board_lib_am574x_CORELIST = c66x a15_0 ipu1_0
board_lib_am571x_CORELIST = c66x a15_0 ipu1_0
board_lib_k2h_CORELIST    = c66x a15_0
board_lib_k2k_CORELIST    = c66x a15_0
board_lib_k2l_CORELIST    = c66x a15_0
board_lib_k2e_CORELIST    = c66x a15_0
board_lib_k2g_CORELIST    = c66x a15_0
board_lib_c6678_CORELIST  = c66x
board_lib_c6657_CORELIST  = c66x
board_lib_am437x_CORELIST = a9host
board_lib_am335x_CORELIST = a8host
board_lib_omapl137_CORELIST = arm9_0 c674x
board_lib_omapl138_CORELIST = arm9_0 c674x
board_lib_am65xx_CORELIST = mpu1_0 mcu1_0 mcu1_1
board_lib_j721e_CORELIST = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1 mcu3_0 mcu3_1 c66xdsp_1 c66xdsp_2 c7x_1
board_lib_j7200_CORELIST = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1
board_lib_tpr12_CORELIST = mcu1_0 c66xdsp_1


############################
# board package
# List of components included under board lib
# The components included here are built and will be part of board lib
############################
board_LIB_LIST = board
board_lib_LIB_LIST = $(board_LIB_LIST)

############################
# board examples
# List of examples under board
# All the tests mentioned in list are built when test target is called
# List below all examples for allowed values
############################
board_EXAMPLE_LIST =

#
# BOARD Modules
#

# BOARD LIB
board_COMP_LIST = board
board_RELPATH = ti/board
board_PATH = $(PDK_BOARD_COMP_PATH)
board_LIBNAME = ti.board
export board_LIBNAME
board_LIBPATH = $(board_PATH)/lib
export board_LIBPATH
board_OBJPATH = $(board_RELPATH)/board
export board_OBJPATH
board_MAKEFILE = -f build/makefile.mk
export board_MAKEFILE
board_BOARD_DEPENDENCY = yes
board_CORE_DEPENDENCY = no
board_SOC_DEPENDENCY = yes
export board_COMP_LIST
export board_BOARD_DEPENDENCY
export board_CORE_DEPENDENCY
export board_SOC_DEPENDENCY
board_PKG_LIST = board
export board_PKG_LIST
board_INCLUDE = $(board_PATH)
board_SOCLIST = $(SOC)
export board_SOCLIST
board_$(SOC)_CORELIST = $(board_lib_$(SOC)_CORELIST)
export board_$(SOC)_CORELIST

#
# BOARD Examples
#

# Board DDR thermal monitor test app
board_ddr_thermal_test_app_COMP_LIST = board_ddr_thermal_test_app
board_ddr_thermal_test_app_RELPATH = ti/board/examples/ddr_thermal_test_app
board_ddr_thermal_test_app_PATH = $(PDK_BOARD_COMP_PATH)/examples/ddr_thermal_test_app
board_ddr_thermal_test_app_BOARD_DEPENDENCY = yes
board_ddr_thermal_test_app_CORE_DEPENDENCY = yes
board_ddr_thermal_test_app_MAKEFILE = -f makefile
board_ddr_thermal_test_app_XDC_CONFIGURO = yes
export board_ddr_thermal_test_app_COMP_LIST
export board_ddr_thermal_test_app_BOARD_DEPENDENCY
export board_ddr_thermal_test_app_CORE_DEPENDENCY
export board_ddr_thermal_test_app_MAKEFILE
export board_ddr_thermal_test_app_XDC_CONFIGURO
board_ddr_thermal_test_app_PKG_LIST = board_ddr_thermal_test_app
board_ddr_thermal_test_app_INCLUDE = $(board_ddr_thermal_test_app_PATH)
board_ddr_thermal_test_app_BOARDLIST = j721e_evm
export board_ddr_thermal_test_app_BOARDLIST
board_ddr_thermal_test_app_$(SOC)_CORELIST = mcu1_0
export board_ddr_thermal_test_app_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), j721e))
board_ddr_thermal_test_app_SBL_APPIMAGEGEN = yes
export board_ddr_thermal_test_app_SBL_APPIMAGEGEN

# Packaged for below board_EXAMPLE
board_EXAMPLE_LIST += board_ddr_thermal_test_app

endif

export board_LIB_LIST
export board_EXAMPLE_LIST

board_component_make_include := 1
endif




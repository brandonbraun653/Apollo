#
# Copyright (c) 2016-2018, Texas Instruments Incorporated
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

# File: osal_component.mk
#       This file is component include make file of OSAL library.
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
#                             this module has no baord dependent code and hence
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
ifeq ($(osal_component_make_include), )

libosal_BOARDLIST       = evmAM572x evmAM335x evmAM437x iceK2G idkAM574x idkAM572x idkAM571x idkAM437x am65xx_evm am65xx_idk evmOMAPL137 lcdkOMAPL138 evmK2E evmK2H evmK2K evmK2L j721e_evm j7200_evm tpr12_evm
libosal_SOCLIST         = tda2xx tda2px tda2ex tda3xx dra78x dra72x dra75x am574x am572x am571x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138 am65xx j721e j7200 am64x tpr12
libosal_tda2xx_CORELIST = a15_0 ipu1_0
libosal_tda2px_CORELIST = a15_0 ipu1_0
libosal_tda2ex_CORELIST = a15_0 ipu1_0
libosal_tda3xx_CORELIST = ipu1_0
libosal_dra72x_CORELIST = c66x a15_0 ipu1_0
libosal_dra75x_CORELIST = c66x a15_0 ipu1_0
libosal_dra78x_CORELIST = c66x ipu1_0
libosal_am574x_CORELIST = c66x a15_0 ipu1_0
libosal_am572x_CORELIST = c66x a15_0 ipu1_0
libosal_am571x_CORELIST = c66x a15_0 ipu1_0
libosal_k2h_CORELIST    = c66x a15_0
libosal_k2k_CORELIST    = c66x a15_0
libosal_k2l_CORELIST    = c66x a15_0
libosal_k2e_CORELIST    = c66x a15_0
libosal_k2g_CORELIST    = c66x a15_0
libosal_omapl137_CORELIST    = c674x arm9_0
libosal_omapl138_CORELIST    = c674x arm9_0
libosal_c6678_CORELIST  = c66x
libosal_c6657_CORELIST  = c66x
libosal_am437x_CORELIST = a9host
libosal_am335x_CORELIST = a8host
libosal_am65xx_CORELIST = mpu1_0 mcu1_0
libosal_j721e_CORELIST = $(DEFAULT_j721e_CORELIST) c7x-hostemu
libosal_j7200_CORELIST = $(DEFAULT_j7200_CORELIST)
libosal_am64x_CORELIST = $(DEFAULT_am64x_CORELIST)
libosal_tpr12_CORELIST = $(DEFAULT_tpr12_CORELIST)

############################
# osal package
# List of components included under osal lib
# The components included here are built and will be part of osal lib
############################
osal_LIB_LIST = osal_nonos osal_nonos_indp
ifeq ($(BUILD_OS_TYPE),tirtos)
osal_LIB_LIST += osal_tirtos osal_tirtos_indp
endif
libosal_LIB_LIST = $(osal_LIB_LIST)

############################
# osal examples
# List of examples under osal
# All the tests mentioned in list are built when test target is called
# List below all examples for allowed values
############################
osal_EXAMPLE_LIST =

#
# OSAL Modules
#

# OSAL NONOS LIB
osal_nonos_COMP_LIST = osal_nonos
osal_nonos_RELPATH = ti/osal
osal_nonos_PATH = $(PDK_OSAL_COMP_PATH)
osal_nonos_LIBNAME = ti.osal
export osal_nonos_LIBNAME
osal_nonos_LIBPATH = $(osal_nonos_PATH)/lib/nonos
export osal_nonos_LIBPATH
osal_nonos_OBJPATH = $(osal_nonos_RELPATH)/osal_nonos
export osal_nonos_OBJPATH
osal_nonos_MAKEFILE = -f build/makefile_nonos.mk
export osal_nonos_MAKEFILE
osal_nonos_PLATFORM_DEPENDENCY = no
osal_nonos_CORE_DEPENDENCY = no
osal_nonos_SOC_DEPENDENCY = yes
export osal_nonos_COMP_LIST
export osal_nonos_PLATFORM_DEPENDENCY
export osal_nonos_CORE_DEPENDENCY
export osal_nonos_SOC_DEPENDENCY
osal_nonos_PKG_LIST = osal_nonos
export osal_nonos_PKG_LIST
osal_nonos_INCLUDE = $(osal_nonos_PATH)
osal_nonos_SOCLIST = $(libosal_SOCLIST)
export osal_nonos_SOCLIST
osal_nonos_$(SOC)_CORELIST = $(libosal_$(SOC)_CORELIST)
export osal_nonos_$(SOC)_CORELIST

# OSAL NONOS LIB DEVICE INDEPENDENT
osal_nonos_indp_COMP_LIST = osal_nonos_indp
osal_nonos_indp_RELPATH = ti/osal
osal_nonos_indp_PATH = $(PDK_OSAL_COMP_PATH)
osal_nonos_indp_LIBNAME = ti.osal
export osal_nonos_indp_LIBNAME
osal_nonos_indp_LIBPATH = $(osal_nonos_indp_PATH)/lib/nonos
export osal_nonos_indp_LIBPATH
osal_nonos_indp_OBJPATH = $(osal_nonos_indp_RELPATH)/osal_nonos_indp
export osal_nonos_indp_OBJPATH
osal_nonos_indp_MAKEFILE = -f build/makefile_nonos_indp.mk
export osal_nonos_indp_MAKEFILE
osal_nonos_indp_PLATFORM_DEPENDENCY = no
osal_nonos_indp_CORE_DEPENDENCY = no
osal_nonos_indp_SOC_DEPENDENCY = no
export osal_nonos_indp_COMP_LIST
export osal_nonos_indp_PLATFORM_DEPENDENCY
export osal_nonos_indp_CORE_DEPENDENCY
export osal_nonos_indp_SOC_DEPENDENCY
osal_nonos_indp_PKG_LIST = osal_nonos_indp
export osal_nonos_indp_PKG_LIST
osal_nonos_indp_INCLUDE = $(osal_nonos_indp_PATH)
osal_nonos_indp_SOCLIST = $(libosal_SOCLIST)
export osal_nonos_indp_SOCLIST
osal_nonos_indp_$(SOC)_CORELIST = $(libosal_$(SOC)_CORELIST)
export osal_nonos_indp_$(SOC)_CORELIST

# OSAL TIRTOS LIB
osal_tirtos_COMP_LIST = osal_tirtos
osal_tirtos_RELPATH = ti/osal
osal_tirtos_PATH = $(PDK_OSAL_COMP_PATH)
osal_tirtos_LIBNAME = ti.osal
export osal_tirtos_LIBNAME
osal_tirtos_LIBPATH = $(osal_tirtos_PATH)/lib/tirtos
export osal_tirtos_LIBPATH
osal_tirtos_OBJPATH = $(osal_tirtos_RELPATH)/osal_tirtos
export osal_tirtos_OBJPATH
osal_tirtos_MAKEFILE = -f build/makefile_tirtos.mk
export osal_tirtos_MAKEFILE
osal_tirtos_PLATFORM_DEPENDENCY = no
osal_tirtos_CORE_DEPENDENCY = no
osal_tirtos_SOC_DEPENDENCY = yes
export osal_tirtos_COMP_LIST
export osal_tirtos_PLATFORM_DEPENDENCY
export osal_tirtos_CORE_DEPENDENCY
export osal_tirtos_SOC_DEPENDENCY
osal_tirtos_PKG_LIST = osal_tirtos
export osal_tirtos_PKG_LIST
osal_tirtos_INCLUDE = $(osal_tirtos_PATH)
osal_tirtos_SOCLIST = $(libosal_SOCLIST)
export osal_tirtos_SOCLIST
osal_tirtos_$(SOC)_CORELIST = $(libosal_$(SOC)_CORELIST)
export osal_tirtos_$(SOC)_CORELIST

# OSAL TIRTOS DEVICE INDEPENDENT
osal_tirtos_indp_COMP_LIST = osal_tirtos_indp
osal_tirtos_indp_RELPATH = ti/osal
osal_tirtos_indp_PATH = $(PDK_OSAL_COMP_PATH)
osal_tirtos_indp_LIBNAME = ti.osal
export osal_tirtos_indp_LIBNAME
osal_tirtos_indp_LIBPATH = $(osal_tirtos_indp_PATH)/lib/tirtos
export osal_tirtos_indp_LIBPATH
osal_tirtos_indp_OBJPATH = $(osal_tirtos_indp_RELPATH)/osal_tirtos_indp
export osal_tirtos_indp_OBJPATH
osal_tirtos_indp_MAKEFILE = -f build/makefile_tirtos_indp.mk
export osal_tirtos_indp_MAKEFILE
osal_tirtos_indp_PLATFORM_DEPENDENCY = no
osal_tirtos_indp_CORE_DEPENDENCY = no
osal_tirtos_indp_SOC_DEPENDENCY = no
export osal_tirtos_indp_COMP_LIST
export osal_tirtos_indp_PLATFORM_DEPENDENCY
export osal_tirtos_indp_CORE_DEPENDENCY
export osal_tirtos_indp_SOC_DEPENDENCY
osal_tirtos_indp_PKG_LIST = osal_tirtos_indp
export osal_tirtos_indp_PKG_LIST
osal_tirtos_indp_INCLUDE = $(osal_tirtos_indp_PATH)
osal_tirtos_indp_SOCLIST = $(libosal_SOCLIST)
export osal_tirtos_indp_SOCLIST
osal_tirtos_indp_$(SOC)_CORELIST = $(libosal_$(SOC)_CORELIST)
export osal_tirtos_indp_$(SOC)_CORELIST

#
# OSAL Examples
#
OSAL_Baremetal_TestApp_COMP_LIST = OSAL_Baremetal_TestApp
OSAL_Baremetal_TestApp_RELPATH = ti/osal/test/baremetal
OSAL_Baremetal_TestApp_PATH = $(PDK_OSAL_COMP_PATH)/test/baremetal
OSAL_Baremetal_TestApp_BOARD_DEPENDENCY = yes
OSAL_Baremetal_TestApp_CORE_DEPENDENCY = no
export OSAL_Baremetal_TestApp_COMP_LIST
export OSAL_Baremetal_TestApp_BOARD_DEPENDENCY
export OSAL_Baremetal_TestApp_CORE_DEPENDENCY
OSAL_Baremetal_TestApp_PKG_LIST = OSAL_Baremetal_TestApp
OSAL_Baremetal_TestApp_INCLUDE = $(OSAL_Baremetal_TestApp_PATH)
OSAL_Baremetal_TestApp_BOARDLIST = $(libosal_BOARDLIST)
export OSAL_Baremetal_TestApp_BOARDLIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
OSAL_Baremetal_TestApp_SBL_APPIMAGEGEN = yes
export OSAL_Baremetal_TestApp_SBL_APPIMAGEGEN
endif

# OSAL sysbios unit test app
OSAL_TestApp_COMP_LIST = OSAL_TestApp
OSAL_TestApp_RELPATH = ti/osal/test/sysbios_unit_test
OSAL_TestApp_PATH = $(PDK_OSAL_COMP_PATH)/test/sysbios_unit_test
OSAL_TestApp_BOARD_DEPENDENCY = yes
OSAL_TestApp_CORE_DEPENDENCY = no
OSAL_TestApp_XDC_CONFIGURO = yes
export OSAL_TestApp_COMP_LIST
export OSAL_TestApp_BOARD_DEPENDENCY
export OSAL_TestApp_CORE_DEPENDENCY
export OSAL_TestApp_XDC_CONFIGURO
OSAL_TestApp_PKG_LIST = OSAL_TestApp
OSAL_TestApp_INCLUDE = $(OSAL_TestApp_PATH)
OSAL_TestApp_BOARDLIST = $(libosal_BOARDLIST)
export OSAL_TestApp_BOARDLIST
OSAL_TestApp_$(SOC)_CORELIST = $(osal_$(SOC)_CORELIST)
export OSAL_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
OSAL_TestApp_SBL_APPIMAGEGEN = yes
export OSAL_TestApp_SBL_APPIMAGEGEN
endif

#Default Core List
OSAL_Baremetal_TestApp_$(SOC)_CORELIST = a15_0 c66x

# Overwrite default core list for below SoCs
ifeq ($(BOARD),$(filter $(BOARD), idkAM574x evmAM572x idkAM572x idkAM571x))
OSAL_Baremetal_TestApp_$(SOC)_CORELIST = a15_0 ipu1_0 c66x
endif

ifeq ($(BOARD),$(filter $(BOARD), evmAM335x))
OSAL_Baremetal_TestApp_$(SOC)_CORELIST = a8host
endif


ifeq ($(BOARD),$(filter $(BOARD), evmAM437x idkAM437x))
OSAL_Baremetal_TestApp_$(SOC)_CORELIST = a9host
endif

ifeq ($(BOARD),$(filter $(BOARD), evmOMAPL137))
osal_baremetal_test_$(SOC)_CORELIST = c674x arm9_0
endif

ifeq ($(BOARD),$(filter $(BOARD), lcdkOMAPL138))
osal_baremetal_test_$(SOC)_CORELIST = c674x arm9_0
endif

ifeq ($(BOARD),$(filter $(BOARD), evmK2E))
osal_baremetal_test_$(SOC)_CORELIST = c66x a15_0
endif

ifeq ($(BOARD),$(filter $(BOARD), evmK2H evmK2K))
osal_baremetal_test_$(SOC)_CORELIST = c66x a15_0
endif

ifeq ($(BOARD),$(filter $(BOARD), evmK2L))
osal_baremetal_test_$(SOC)_CORELIST = c66x a15_0
endif

ifeq ($(BOARD),$(filter $(BOARD), evmOMAPL137))
osal_baremetal_test_$(SOC)_CORELIST = c674x arm9_0
endif

ifeq ($(BOARD),$(filter $(BOARD), lcdkOMAPL138))
osal_baremetal_test_$(SOC)_CORELIST = c674x arm9_0
endif

ifeq ($(BOARD),$(filter $(BOARD), evmK2E))
osal_baremetal_test_$(SOC)_CORELIST = c66x a15_0
endif

ifeq ($(BOARD),$(filter $(BOARD), evmK2H evmK2K))
osal_baremetal_test_$(SOC)_CORELIST = c66x a15_0
endif

ifeq ($(BOARD),$(filter $(BOARD), evmK2L))
osal_baremetal_test_$(SOC)_CORELIST = c66x a15_0
endif

ifeq ($(SOC),$(filter $(SOC), dra72x dra75x))
OSAL_Baremetal_TestApp_$(SOC)_CORELIST = a15_0 ipu1_0 c66x
endif

ifeq ($(SOC),$(filter $(SOC), dra78x))
OSAL_Baremetal_TestApp_$(SOC)_CORELIST = ipu1_0 c66x
endif


ifeq ($(SOC),$(filter $(SOC), am65xx))
 OSAL_TestApp_$(SOC)_CORELIST = mpu1_0 mcu1_0
 OSAL_Baremetal_TestApp_$(SOC)_CORELIST = mpu1_0 mcu1_0
endif

ifeq ($(SOC),$(filter $(SOC), j721e))
	OSAL_TestApp_$(SOC)_CORELIST = mpu1_0 mcu1_0 mcu2_0 mcu3_0 c66xdsp_1 c7x_1
 OSAL_Baremetal_TestApp_$(SOC)_CORELIST = mpu1_0 mcu1_0 mcu2_0 mcu3_0
endif

ifeq ($(SOC),$(filter $(SOC), j7200))
 OSAL_TestApp_$(SOC)_CORELIST = mpu1_0 mcu1_0 mcu2_0
 OSAL_Baremetal_TestApp_$(SOC)_CORELIST = mpu1_0 mcu1_0 mcu2_0
endif

ifeq ($(SOC),$(filter $(SOC), tpr12))
 OSAL_TestApp_$(SOC)_CORELIST = mcu1_0 c66xdsp_1
 OSAL_Baremetal_TestApp_$(SOC)_CORELIST = mcu1_0 c66xdsp_1
endif

export OSAL_Baremetal_TestApp_$(SOC)_CORELIST
export OSAL_TestApp_$(SOC)_CORELIST

osal_EXAMPLE_LIST += OSAL_Baremetal_TestApp
osal_EXAMPLE_LIST += OSAL_TestApp

ifeq ($(CPLUSPLUS_BUILD), yes)
#cpptest
cpptest_COMP_LIST = cpptest
cpptest_RELPATH = ti/osal/test/cpptest
cpptest_PATH = $(PDK_OSAL_COMP_PATH)/test/cpptest
cpptest_BOARD_DEPENDENCY = yes
cpptest_CORE_DEPENDENCY = yes
export cpptest_COMP_LIST
export cpptest_BOARD_DEPENDENCY
export cpptest_CORE_DEPENDENCY
cpptest_PKG_LIST = cpptest
cpptest_INCLUDE = $(cpptest_PATH)
cpptest_BOARDLIST = $(libosal_BOARDLIST)
export cpptest_BOARDLIST

#Default Core List
ifeq ($(BOARD),$(filter $(BOARD), evmAM335x))
cpptest_$(SOC)_CORELIST = a8host
endif

ifeq ($(BOARD),$(filter $(BOARD), evmAM437x idkAM437x))
cpptest_$(SOC)_CORELIST = a9host
endif

ifeq ($(BOARD),$(filter $(BOARD), idkAM574x evmAM572x idkAM572x idkAM571x))
cpptest_$(SOC)_CORELIST = a15_0 ipu1_0 c66x
endif

ifeq ($(BOARD),$(filter $(BOARD), evmK2G iceK2G))
cpptest_$(SOC)_CORELIST = c66x a15_0
endif

export cpptest_$(SOC)_CORELIST
osal_EXAMPLE_LIST += cpptest
endif

export osal_LIB_LIST
export libosal_LIB_LIST
export osal_EXAMPLE_LIST

libosal_EXAMPLE_LIST = $(osal_EXAMPLE_LIST)
export libosal_EXAMPLE_LIST

osal_component_make_include := 1
endif

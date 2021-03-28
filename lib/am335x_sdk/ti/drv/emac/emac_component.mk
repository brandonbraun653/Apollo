#
# Copyright (c) 2016-2019, Texas Instruments Incorporated
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

# File: emac_component.mk
#       This file is component include make file of EMAC library.
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
ifeq ($(emac_component_make_include), )

# under other list
drvemac_BOARDLIST       = am65xx_evm am65xx_idk j721e_sim j721e_evm
drvemac_SOCLIST         = am574x am572x am571x am437x am335x k2g dra72x dra75x dra78x omapl137 omapl138 c6657 am65xx j721e
drvemac_am574x_CORELIST = c66x a15_0 ipu1_0
drvemac_am572x_CORELIST = c66x a15_0 ipu1_0
drvemac_am571x_CORELIST = c66x a15_0 ipu1_0
drvemac_am437x_CORELIST = a9host
drvemac_am335x_CORELIST = a8host
drvemac_k2g_CORELIST    = c66x a15_0
drvemac_dra72x_CORELIST = a15_0 ipu1_0
drvemac_dra75x_CORELIST = a15_0 ipu1_0
drvemac_dra78x_CORELIST = ipu1_0
drvemac_omapl137_CORELIST = c674x arm9_0
drvemac_omapl138_CORELIST = c674x arm9_0
drvemac_c6657_CORELIST  = c66x
drvemac_am65xx_CORELIST = mpu1_0 mcu1_0
drvemac_j721e_CORELIST = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1 mcu3_0 mcu3_1

############################
# emac package
# List of components included under emac lib
# The components included here are built and will be part of emac lib
############################
emac_LIB_LIST = emac emac_indp emac_profile emac_profile_indp
drvemac_LIB_LIST = $(emac_LIB_LIST)

############################
# makefile based emac test apps
# List of tests under emac
# All the tests mentioned in list are built when test target is called
# List below all test apps for allowed values
############################
emac_EXAMPLE_LIST = Emac_Icssg_Switch_TestApp Emac_Icssg_TestApp Emac_Cpsw_TestApp Emac_Cpsw_Smp_TestApp Emac_Icssg_WithoutDDR_TestApp Emac_Icssg_Switch_Benchmark_TestApp Emac_Icssg_Switch_LinkStatus_TestApp
drvemac_EXAMPLE_LIST = $(emac_EXAMPLE_LIST)

#
# EMAC Modules
#

# EMAC LIB
emac_COMP_LIST = emac
emac_RELPATH = ti/drv/emac
emac_PATH = $(PDK_EMAC_COMP_PATH)
emac_LIBNAME = ti.drv.emac
export emac_LIBNAME
emac_LIBPATH = $(emac_PATH)/lib
export emac_LIBPATH
emac_OBJPATH = $(emac_RELPATH)/emac
export emac_OBJPATH
emac_MAKEFILE = -f build/makefile.mk
export emac_MAKEFILE
emac_BOARD_DEPENDENCY = no
emac_CORE_DEPENDENCY = no
emac_SOC_DEPENDENCY = yes
export emac_COMP_LIST
export emac_BOARD_DEPENDENCY
export emac_CORE_DEPENDENCY
export emac_SOC_DEPENDENCY
emac_PKG_LIST = emac
export emac_PKG_LIST
emac_INCLUDE = $(emac_PATH)
emac_SOCLIST = $(drvemac_SOCLIST)
export emac_SOCLIST
emac_$(SOC)_CORELIST = $(drvemac_$(SOC)_CORELIST)
export emac_$(SOC)_CORELIST

# EMAC INDEPENDENT LIB
emac_indp_COMP_LIST = emac_indp
emac_indp_RELPATH = ti/drv/emac
emac_indp_PATH = $(PDK_EMAC_COMP_PATH)
emac_indp_LIBNAME = ti.drv.emac
export emac_indp_LIBNAME
emac_indp_LIBPATH = $(emac_indp_PATH)/lib
export emac_indp_LIBPATH
emac_indp_OBJPATH = $(emac_indp_RELPATH)/emac_indp
export emac_indp_OBJPATH
emac_indp_MAKEFILE = -f build/makefile_indp.mk
export emac_indp_MAKEFILE
emac_indp_BOARD_DEPENDENCY = no
emac_indp_CORE_DEPENDENCY = no
emac_indp_SOC_DEPENDENCY = no
export emac_indp_COMP_LIST
export emac_indp_BOARD_DEPENDENCY
export emac_indp_CORE_DEPENDENCY
export emac_indp_SOC_DEPENDENCY
emac_indp_PKG_LIST = emac_indp
export emac_indp_PKG_LIST
emac_indp_INCLUDE = $(emac_indp_PATH)
emac_indp_SOCLIST = $(drvemac_SOCLIST)
export emac_indp_SOCLIST
emac_indp_$(SOC)_CORELIST = $(drvemac_$(SOC)_CORELIST)
export emac_indp_$(SOC)_CORELIST

# EMAC PROFILE LIB
emac_profile_COMP_LIST = emac_profile
emac_profile_RELPATH = ti/drv/emac
emac_profile_PATH = $(PDK_EMAC_COMP_PATH)
emac_profile_LIBNAME = ti.drv.emac.profiling
export emac_profile_LIBNAME
emac_profile_LIBPATH = $(emac_profile_PATH)/lib
export emac_profile_LIBPATH
emac_profile_OBJPATH = $(emac_profile_RELPATH)/emac_profile
export emac_profile_OBJPATH
emac_profile_MAKEFILE = -f build/makefile_profile.mk
export emac_profile_MAKEFILE
emac_profile_BOARD_DEPENDENCY = no
emac_profile_CORE_DEPENDENCY = no
emac_profile_SOC_DEPENDENCY = yes
export emac_profile_COMP_LIST
export emac_profile_BOARD_DEPENDENCY
export emac_profile_CORE_DEPENDENCY
export emac_profile_SOC_DEPENDENCY
emac_profile_PKG_LIST = emac_profile
export emac_profile_PKG_LIST
emac_profile_INCLUDE = $(emac_profile_PATH)
emac_profile_SOCLIST = $(drvemac_SOCLIST)
export emac_profile_SOCLIST
emac_profile_$(SOC)_CORELIST = $(drvemac_$(SOC)_CORELIST)
export emac_profile_$(SOC)_CORELIST

# EMAC PROFILE INDEPENDENT LIB
emac_profile_indp_COMP_LIST = emac_profile_indp
emac_profile_indp_RELPATH = ti/drv/emac
emac_profile_indp_PATH = $(PDK_EMAC_COMP_PATH)
emac_profile_indp_LIBNAME = ti.drv.emac.profiling
export emac_profile_indp_LIBNAME
emac_profile_indp_LIBPATH = $(emac_profile_indp_PATH)/lib
export emac_profile_indp_LIBPATH
emac_profile_indp_OBJPATH = $(emac_profile_indp_RELPATH)/emac_profile_indp
export emac_profile_indp_OBJPATH
emac_profile_indp_MAKEFILE = -f build/makefile_profile_indp.mk
export emac_profile_indp_MAKEFILE
emac_profile_indp_BOARD_DEPENDENCY = no
emac_profile_indp_CORE_DEPENDENCY = no
emac_profile_indp_SOC_DEPENDENCY = no
export emac_profile_indp_COMP_LIST
export emac_profile_indp_BOARD_DEPENDENCY
export emac_profile_indp_CORE_DEPENDENCY
export emac_profile_indp_SOC_DEPENDENCY
emac_profile_indp_PKG_LIST = emac_profile_indp
export emac_profile_indp_PKG_LIST
emac_profile_indp_INCLUDE = $(emac_profile_indp_PATH)
emac_profile_indp_SOCLIST = $(drvemac_SOCLIST)
export emac_profile_indp_SOCLIST
emac_profile_indp_$(SOC)_CORELIST = $(drvemac_$(SOC)_CORELIST)
export emac_profile_indp_$(SOC)_CORELIST

# EMAC unit test app ICSSG
Emac_Icssg_TestApp_COMP_LIST = Emac_Icssg_TestApp
Emac_Icssg_TestApp_RELPATH = ti/drv/emac/test/EmacLoopbackTest
Emac_Icssg_TestApp_PATH = $(PDK_EMAC_COMP_PATH)/test/EmacLoopbackTest
Emac_Icssg_TestApp_BOARD_DEPENDENCY = yes
Emac_Icssg_TestApp_CORE_DEPENDENCY = no
Emac_Icssg_TestApp_XDC_CONFIGURO = yes
Emac_Icssg_TestApp_MAKEFILE = -f am65xx/icssg/makefile_dualmac
export Emac_Icssg_TestApp_MAKEFILE
export Emac_Icssg_TestApp_board_dependency
export Emac_Icssg_TestApp_core_dependency
export Emac_Icssg_TestApp_xdc_configuro
Emac_Icssg_TestApp_PKG_LIST = Emac_Icssg_TestApp
Emac_Icssg_TestApp_INCLUDE = $(Emac_Icssg_TestApp_PATH)
Emac_Icssg_TestApp_BOARDLIST = am65xx_evm am65xx_idk
export Emac_Icssg_TestApp_BOARDLIST
Emac_Icssg_TestApp_$(SOC)_CORELIST = $(drvemac_$(SOC)_CORELIST)
export Emac_Icssg_TestApp_$(SOC)_CORELIST

Emac_Icssg_TestApp_SBL_APPIMAGEGEN = yes
export Emac_Icssg_TestApp_SBL_APPIMAGEGEN

# EMAC unit test app CPSW
Emac_Cpsw_TestApp_COMP_LIST = Emac_Cpsw_TestApp
Emac_Cpsw_TestApp_RELPATH = ti/drv/emac/test/EmacLoopbackTest
Emac_Cpsw_TestApp_PATH = $(PDK_EMAC_COMP_PATH)/test/EmacLoopbackTest
Emac_Cpsw_TestApp_BOARD_DEPENDENCY = yes
Emac_Cpsw_TestApp_CORE_DEPENDENCY = no
Emac_Cpsw_TestApp_XDC_CONFIGURO = yes
Emac_Cpsw_TestApp_MAKEFILE = -f $(SOC)/cpsw/makefile
export Emac_Cpsw_TestApp_board_dependency
export Emac_Cpsw_TestApp_core_dependency
export Emac_Cpsw_TestApp_xdc_configuro
Emac_Cpsw_TestApp_PKG_LIST = Emac_Cpsw_TestApp
Emac_Cpsw_TestApp_INCLUDE = $(Emac_Cpsw_TestApp_PATH)
Emac_Cpsw_TestApp_BOARDLIST = am65xx_evm am65xx_idk j721e_sim j721e_evm
export Emac_Cpsw_TestApp_BOARDLIST
Emac_Cpsw_TestApp_$(SOC)_CORELIST = $(drvemac_$(SOC)_CORELIST)
export Emac_Cpsw_TestApp_$(SOC)_CORELIST

Emac_Cpsw_TestApp_SBL_APPIMAGEGEN = yes
ifeq ($(SOC),$(filter $(SOC), j721e))
Emac_Cpsw_TestApp_SBL_APPIMAGEGEN = no
endif
export Emac_Cpsw_TestApp_SBL_APPIMAGEGEN

# EMAC unit test app CPSW with SMP enabled
Emac_Cpsw_Smp_TestApp_COMP_LIST = Emac_Cpsw_Smp_TestApp
Emac_Cpsw_Smp_TestApp_RELPATH = ti/drv/emac/test/EmacLoopbackTest
Emac_Cpsw_Smp_TestApp_PATH = $(PDK_EMAC_COMP_PATH)/test/EmacLoopbackTest
Emac_Cpsw_Smp_TestApp_BOARD_DEPENDENCY = yes
Emac_Cpsw_Smp_TestApp_CORE_DEPENDENCY = no
Emac_Cpsw_Smp_TestApp_XDC_CONFIGURO = yes
Emac_Cpsw_Smp_TestApp_MAKEFILE = -f $(SOC)/cpsw/makefile SMP=enable
export Emac_Cpsw_Smp_TestApp_board_dependency
export Emac_Cpsw_Smp_TestApp_core_dependency
export Emac_Cpsw_Smp_TestApp_xdc_configuro
Emac_Cpsw_Smp_TestApp_PKG_LIST = Emac_Cpsw_Smp_TestApp
Emac_Cpsw_Smp_TestApp_INCLUDE = $(Emac_Cpsw_Smp_TestApp_PATH)
Emac_Cpsw_Smp_TestApp_BOARDLIST = am65xx_evm am65xx_idk
export Emac_Cpsw_Smp_TestApp_BOARDLIST
Emac_Cpsw_Smp_TestApp_$(SOC)_CORELIST = $(drvemac_$(SOC)_CORELIST)
export Emac_Cpsw_Smp_TestApp_$(SOC)_CORELIST

Emac_Cpsw_Smp_TestApp_SBL_APPIMAGEGEN = yes
export Emac_Cpsw_Smp_TestApp_SBL_APPIMAGEGEN

# EMAC unit test app ICSSG without DDR
Emac_Icssg_WithoutDDR_TestApp_COMP_LIST = Emac_Icssg_WithoutDDR_TestApp
Emac_Icssg_WithoutDDR_TestApp_RELPATH = ti/drv/emac/test/EmacLoopbackTest
Emac_Icssg_WithoutDDR_TestApp_PATH = $(PDK_EMAC_COMP_PATH)/test/EmacLoopbackTest
Emac_Icssg_WithoutDDR_TestApp_BOARD_DEPENDENCY = yes
Emac_Icssg_WithoutDDR_TestApp_CORE_DEPENDENCY = no
Emac_Icssg_WithoutDDR_TestApp_XDC_CONFIGURO = yes
Emac_Icssg_WithoutDDR_TestApp_MAKEFILE = -f am65xx/icssg/makefile_without_ddr
export Emac_Icssg_WithoutDDR_TestApp_MAKEFILE
export Emac_Icssg_WithoutDDR_TestApp_board_dependency
export Emac_Icssg_WithoutDDR_TestApp_core_dependency
export Emac_Icssg_WithoutDDR_TestApp_xdc_configuro
Emac_Icssg_WithoutDDR_TestApp_PKG_LIST = Emac_Icssg_WithoutDDR_TestApp
Emac_Icssg_WithoutDDR_TestApp_INCLUDE = $(Emac_Icssg_WithoutDDR_TestApp_PATH)
Emac_Icssg_WithoutDDR_TestApp_BOARDLIST = am65xx_evm am65xx_idk
export Emac_Icssg_WithoutDDR_TestApp_BOARDLIST
#Emac_Icssg_WithoutDDR_TestApp_$(SOC)_CORELIST = $(drvemac_$(SOC)_CORELIST)
Emac_Icssg_WithoutDDR_TestApp_$(SOC)_CORELIST = mcu1_0
export Emac_Icssg_WithoutDDR_TestApp_$(SOC)_CORELIST

Emac_Icssg_WithoutDDR_TestApp_SBL_APPIMAGEGEN = yes
export Emac_Icssg_WithoutDDR_TestApp_SBL_APPIMAGEGEN

# EMAC SWITCH unit test app ICSSG
Emac_Icssg_Switch_TestApp_COMP_LIST = Emac_Icssg_Switch_TestApp
Emac_Icssg_Switch_TestApp_RELPATH = ti/drv/emac/test/EmacLoopbackTest
Emac_Icssg_Switch_TestApp_PATH = $(PDK_EMAC_COMP_PATH)/test/EmacLoopbackTest
Emac_Icssg_Switch_TestApp_BOARD_DEPENDENCY = yes
Emac_Icssg_Switch_TestApp_CORE_DEPENDENCY = no
Emac_Icssg_Switch_TestApp_XDC_CONFIGURO = yes
Emac_Icssg_Switch_TestApp_MAKEFILE = -f am65xx/icssg/makefile_switch
export Emac_Icssg_Switch_TestApp_MAKEFILE
export Emac_Icssg_Switch_TestApp_board_dependency
export Emac_Icssg_Switch_TestApp_core_dependency
export Emac_Icssg_Switch_TestApp_xdc_configuro
Emac_Icssg_Switch_TestApp_PKG_LIST = Emac_Icssg_Switch_TestApp
Emac_Icssg_Switch_TestApp_INCLUDE = $(Emac_Icssg_Switch_TestApp_PATH)
Emac_Icssg_Switch_TestApp_BOARDLIST = am65xx_idk
export Emac_Icssg_Switch_TestApp_BOARDLIST
Emac_Icssg_Switch_TestApp_$(SOC)_CORELIST = $(drvemac_$(SOC)_CORELIST)
export Emac_Icssg_Switch_TestApp_$(SOC)_CORELIST

Emac_Icssg_Switch_TestApp_SBL_APPIMAGEGEN = yes
export Emac_Icssg_Switch_TestApp_SBL_APPIMAGEGEN

# EMAC SWITCH Benchmark unit test app ICSSG
Emac_Icssg_Switch_Benchmark_TestApp_COMP_LIST = Emac_Icssg_Switch_Benchmark_TestApp
Emac_Icssg_Switch_Benchmark_TestApp_RELPATH = ti/drv/emac/test/EmacLoopbackTest
Emac_Icssg_Switch_Benchmark_TestApp_PATH = $(PDK_EMAC_COMP_PATH)/test/EmacLoopbackTest
Emac_Icssg_Switch_Benchmark_TestApp_BOARD_DEPENDENCY = yes
Emac_Icssg_Switch_Benchmark_TestApp_CORE_DEPENDENCY = no
Emac_Icssg_Switch_Benchmark_TestApp_XDC_CONFIGURO = yes
Emac_Icssg_Switch_Benchmark_TestApp_MAKEFILE = -f am65xx/icssg/makefile_switch_benchmark
export Emac_Icssg_Switch_Benchmark_TestApp_MAKEFILE
export Emac_Icssg_Switch_Benchmark_TestApp_board_dependency
export Emac_Icssg_Switch_Benchmark_TestApp_core_dependency
export Emac_Icssg_Switch_Benchmark_TestApp_xdc_configuro
Emac_Icssg_Switch_Benchmark_TestApp_PKG_LIST = Emac_Icssg_Switch_Benchmark_TestApp
Emac_Icssg_Switch_Benchmark_TestApp_INCLUDE = $(Emac_Icssg_Switch_Benchmark_TestApp_PATH)
Emac_Icssg_Switch_Benchmark_TestApp_BOARDLIST = am65xx_idk
export Emac_Icssg_Switch_Benchmark_TestApp_BOARDLIST
Emac_Icssg_Switch_Benchmark_TestApp_$(SOC)_CORELIST = $(drvemac_$(SOC)_CORELIST)
export Emac_Icssg_Switch_Benchmark_TestApp_$(SOC)_CORELIST

# EMAC SWITCH Link status check unit test app ICSSG
Emac_Icssg_Switch_LinkStatus_TestApp_COMP_LIST = Emac_Icssg_Switch_LinkStatus_TestApp
Emac_Icssg_Switch_LinkStatus_TestApp_RELPATH = ti/drv/emac/test/EmacLoopbackTest
Emac_Icssg_Switch_LinkStatus_TestApp_PATH = $(PDK_EMAC_COMP_PATH)/test/EmacLoopbackTest
Emac_Icssg_Switch_LinkStatus_TestApp_BOARD_DEPENDENCY = yes
Emac_Icssg_Switch_LinkStatus_TestApp_CORE_DEPENDENCY = no
Emac_Icssg_Switch_LinkStatus_TestApp_XDC_CONFIGURO = yes
Emac_Icssg_Switch_LinkStatus_TestApp_MAKEFILE = -f am65xx/icssg/makefile_switch_link_status
export Emac_Icssg_Switch_LinkStatus_TestApp_MAKEFILE
export Emac_Icssg_Switch_LinkStatus_TestApp_board_dependency
export Emac_Icssg_Switch_LinkStatus_TestApp_core_dependency
export Emac_Icssg_Switch_LinkStatus_TestApp_xdc_configuro
Emac_Icssg_Switch_LinkStatus_TestApp_PKG_LIST = Emac_Icssg_Switch_LinkStatus_TestApp
Emac_Icssg_Switch_LinkStatus_TestApp_INCLUDE = $(Emac_Icssg_Switch_LinkStatus_TestApp_PATH)
Emac_Icssg_Switch_LinkStatus_TestApp_BOARDLIST = am65xx_idk
export Emac_Icssg_Switch_LinkStatus_TestApp_BOARDLIST
Emac_Icssg_Switch_LinkStatus_TestApp_$(SOC)_CORELIST = $(drvemac_$(SOC)_CORELIST)
export Emac_Icssg_Switch_LinkStatus_TestApp_$(SOC)_CORELIST

Emac_Icssg_Switch_LinkStatus_TestApp_SBL_APPIMAGEGEN = yes
export Emac_Icssg_Switch_LinkStatus_TestApp_SBL_APPIMAGEGEN
export drvemac_LIB_LIST
export emac_LIB_LIST
export emac_EXAMPLE_LIST
export drvemac_EXAMPLE_LIST

emac_component_make_include := 1
endif

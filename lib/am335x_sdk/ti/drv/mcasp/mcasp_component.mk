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

# File: mcasp_component.mk
#       This file is component include make file of MCASP library.
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
ifeq ($(mcasp_component_make_include), )

# under other list
drvmcasp_BOARDLIST       = am65xx_evm am65xx_idk j721e_evm
drvmcasp_SOCLIST         = am574x am572x am571x k2g am437x am335x dra72x dra75x dra78x omapl137 omapl138 am65xx j721e
drvmcasp_am572x_CORELIST = c66x a15_0 ipu1_0
drvmcasp_am574x_CORELIST = c66x a15_0 ipu1_0
drvmcasp_dra72x_CORELIST = c66x a15_0 ipu1_0
drvmcasp_dra75x_CORELIST = c66x a15_0 ipu1_0
drvmcasp_dra78x_CORELIST = c66x ipu1_0
drvmcasp_am571x_CORELIST = c66x a15_0 ipu1_0
drvmcasp_k2g_CORELIST    = c66x a15_0
drvmcasp_am437x_CORELIST = a9host
drvmcasp_am335x_CORELIST = a8host
drvmcasp_omapl137_CORELIST = c674x arm9_0
drvmcasp_omapl138_CORELIST = c674x arm9_0
drvmcasp_am65xx_CORELIST     = mpu1_0 mcu1_0
drvmcasp_j721e_CORELIST     = mpu1_0 mcu1_0 mcu2_0 c66xdsp_1 c66xdsp_2
############################
# mcasp package
# List of components included under mcasp lib
# The components included here are built and will be part of mcasp lib
############################

mcasp_LIB_LIST = mcasp mcasp_indp mcasp_profile mcasp_profile_indp
drvmcasp_LIB_LIST = $(mcasp_LIB_LIST)

############################
# mcasp examples
# List of examples under mcasp
# All the tests mentioned in list are built when test target is called
# List below all examples for allowed values
############################
mcasp_EXAMPLE_LIST = MCASP_AudioLoopback_TestApp MCASP_DeviceLoopback_SMP_TestApp MCASP_DeviceLoopback_TestApp MCASP_DeviceLoopback_Regression_TestApp MCASP_AudioDCAnalogLoopback_TestApp MCASP_AudioDCDigitalLoopback_TestApp
#
# MCASP Modules
#

# MCASP LIB
mcasp_COMP_LIST = mcasp
mcasp_RELPATH = ti/drv/mcasp
mcasp_PATH = $(PDK_MCASP_COMP_PATH)
mcasp_LIBNAME = ti.drv.mcasp
export mcasp_LIBNAME
mcasp_LIBPATH = $(mcasp_PATH)/lib
export mcasp_LIBPATH
mcasp_OBJPATH = $(mcasp_RELPATH)/mcasp
export mcasp_OBJPATH
mcasp_MAKEFILE = -f build/makefile.mk
export mcasp_MAKEFILE
mcasp_BOARD_DEPENDENCY = no
mcasp_CORE_DEPENDENCY = no
mcasp_SOC_DEPENDENCY = yes
export mcasp_COMP_LIST
export mcasp_BOARD_DEPENDENCY
export mcasp_CORE_DEPENDENCY
export mcasp_SOC_DEPENDENCY
mcasp_PKG_LIST = mcasp
export mcasp_PKG_LIST
mcasp_INCLUDE = $(mcasp_PATH)
mcasp_SOCLIST = $(drvmcasp_SOCLIST)
export mcasp_SOCLIST
mcasp_$(SOC)_CORELIST = $(drvmcasp_$(SOC)_CORELIST)
export mcasp_$(SOC)_CORELIST

# MCASP PROFILE LIB
mcasp_profile_COMP_LIST = mcasp_profile
mcasp_profile_RELPATH = ti/drv/mcasp
mcasp_profile_PATH = $(PDK_MCASP_COMP_PATH)
mcasp_profile_LIBNAME = ti.drv.mcasp.profiling
export mcasp_profile_LIBNAME
mcasp_profile_LIBPATH = $(mcasp_profile_PATH)/lib
export mcasp_profile_LIBPATH
mcasp_profile_OBJPATH = $(mcasp_profile_RELPATH)/mcasp_profile
export mcasp_profile_OBJPATH
mcasp_profile_MAKEFILE = -f build/makefile_profile.mk
export mcasp_profile_MAKEFILE
mcasp_profile_BOARD_DEPENDENCY = no
mcasp_profile_CORE_DEPENDENCY = no
mcasp_profile_SOC_DEPENDENCY = yes
export mcasp_profile_COMP_LIST
export mcasp_profile_BOARD_DEPENDENCY
export mcasp_profile_CORE_DEPENDENCY
export mcasp_profile_SOC_DEPENDENCY
mcasp_profile_PKG_LIST = mcasp_profile
export mcasp_profile_PKG_LIST
mcasp_profile_INCLUDE = $(mcasp_profile_PATH)
mcasp_profile_SOCLIST = am574x am572x am571x k2g am437x am335x dra72x dra75x dra78x omapl137 omapl138 am65xx
export mcasp_profile_SOCLIST
mcasp_profile_$(SOC)_CORELIST = $(drvmcasp_$(SOC)_CORELIST)
export mcasp_profile_$(SOC)_CORELIST

#
# McASP Examples
#

# McASP Audio Loopback example app
MCASP_AudioLoopback_TestApp_COMP_LIST = MCASP_AudioLoopback_TestApp
MCASP_AudioLoopback_TestApp_RELPATH = ti/drv/mcasp/example/MCASP_AudioLoopback_TestApp
MCASP_AudioLoopback_TestApp_PATH = $(PDK_MCASP_COMP_PATH)/example/MCASP_AudioLoopback_TestApp
MCASP_AudioLoopback_TestApp_BOARD_DEPENDENCY = yes
MCASP_AudioLoopback_TestApp_CORE_DEPENDENCY = no
MCASP_AudioLoopback_TestApp_XDC_CONFIGURO = yes
export MCASP_AudioLoopback_TestApp_COMP_LIST
export MCASP_AudioLoopback_TestApp_BOARD_DEPENDENCY
export MCASP_AudioLoopback_TestApp_CORE_DEPENDENCY
export MCASP_AudioLoopback_TestApp_XDC_CONFIGURO
MCASP_AudioLoopback_TestApp_PKG_LIST = MCASP_AudioLoopback_TestApp
MCASP_AudioLoopback_TestApp_INCLUDE = $(MCASP_AudioLoopback_TestApp_PATH)
MCASP_AudioLoopback_TestApp_BOARDLIST = am65xx_evm am65xx_idk j721e_sim j721e_evm j721e_qt
export MCASP_AudioLoopback_TestApp_BOARDLIST
MCASP_AudioLoopback_TestApp_$(SOC)_CORELIST = $(drvmcasp_$(SOC)_CORELIST)
export MCASP_AudioLoopback_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
MCASP_AudioLoopback_TestApp_SBL_APPIMAGEGEN = yes
export MCASP_AudioLoopback_TestApp_SBL_APPIMAGEGEN
endif

# McASP Audio Loopback example app with SMP enabled
MCASP_DeviceLoopback_SMP_TestApp_COMP_LIST = MCASP_DeviceLoopback_SMP_TestApp
MCASP_DeviceLoopback_SMP_TestApp_RELPATH = ti/drv/mcasp/example/MCASP_DeviceLoopback_TestApp
MCASP_DeviceLoopback_SMP_TestApp_PATH = $(PDK_MCASP_COMP_PATH)/example/MCASP_DeviceLoopback_TestApp
MCASP_DeviceLoopback_SMP_TestApp_MAKEFILE = -f makefile SMP=enable
MCASP_DeviceLoopback_SMP_TestApp_BOARD_DEPENDENCY = yes
MCASP_DeviceLoopback_SMP_TestApp_CORE_DEPENDENCY = no
MCASP_DeviceLoopback_SMP_TestApp_XDC_CONFIGURO = yes
export MCASP_DeviceLoopback_SMP_TestApp_COMP_LIST
export MCASP_DeviceLoopback_SMP_TestApp_BOARD_DEPENDENCY
export MCASP_DeviceLoopback_SMP_TestApp_CORE_DEPENDENCY
export MCASP_DeviceLoopback_SMP_TestApp_XDC_CONFIGURO
export MCASP_DeviceLoopback_SMP_TestApp_MAKEFILE
MCASP_DeviceLoopback_SMP_TestApp_PKG_LIST = MCASP_DeviceLoopback_SMP_TestApp
MCASP_DeviceLoopback_SMP_TestApp_INCLUDE = $(MCASP_DeviceLoopback_SMP_TestApp_PATH)
MCASP_DeviceLoopback_SMP_TestApp_BOARDLIST = am65xx_evm am65xx_idk
export MCASP_DeviceLoopback_TestApp_BOARDLIST
MCASP_DeviceLoopback_SMP_TestApp_$(SOC)_CORELIST = mpu1_0
export MCASP_DeviceLoopback_SMP_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
MCASP_DeviceLoopback_SMP_TestApp_SBL_APPIMAGEGEN = yes
export MCASP_DeviceLoopback_SMP_TestApp_SBL_APPIMAGEGEN
endif

# McASP sysbios unit test app
MCASP_DeviceLoopback_TestApp_COMP_LIST = MCASP_DeviceLoopback_TestApp
MCASP_DeviceLoopback_TestApp_RELPATH = ti/drv/mcasp/example/MCASP_DeviceLoopback_TestApp
MCASP_DeviceLoopback_TestApp_PATH = $(PDK_MCASP_COMP_PATH)/example/MCASP_DeviceLoopback_TestApp
MCASP_DeviceLoopback_TestApp_BOARD_DEPENDENCY = yes
MCASP_DeviceLoopback_TestApp_CORE_DEPENDENCY = no
MCASP_DeviceLoopback_TestApp_XDC_CONFIGURO = yes
export MCASP_DeviceLoopback_TestApp_COMP_LIST
export MCASP_DeviceLoopback_TestApp_BOARD_DEPENDENCY
export MCASP_DeviceLoopback_TestApp_CORE_DEPENDENCY
export MCASP_DeviceLoopback_TestApp_XDC_CONFIGURO
MCASP_DeviceLoopback_TestApp_PKG_LIST = MCASP_DeviceLoopback_TestApp
MCASP_DeviceLoopback_TestApp_INCLUDE = $(MCASP_DeviceLoopback_TestApp_PATH)
MCASP_DeviceLoopback_TestApp_BOARDLIST = am65xx_evm am65xx_idk j721e_sim j721e_evm j721e_qt
export MCASP_DeviceLoopback_TestApp_BOARDLIST
MCASP_DeviceLoopback_TestApp_$(SOC)_CORELIST = $(drvmcasp_$(SOC)_CORELIST)
export MCASP_DeviceLoopback_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
MCASP_DeviceLoopback_TestApp_SBL_APPIMAGEGEN = yes
export MCASP_DeviceLoopback_TestApp_SBL_APPIMAGEGEN
endif

# McASP sysbios  regression app
MCASP_DeviceLoopback_Regression_TestApp_COMP_LIST = MCASP_DeviceLoopback_Regression_TestApp
MCASP_DeviceLoopback_Regression_TestApp_RELPATH = ti/drv/mcasp/example/MCASP_DeviceLoopback_Regression_TestApp
MCASP_DeviceLoopback_Regression_TestApp_PATH = $(PDK_MCASP_COMP_PATH)/example/MCASP_DeviceLoopback_Regression_TestApp
MCASP_DeviceLoopback_Regression_TestApp_BOARD_DEPENDENCY = yes
MCASP_DeviceLoopback_Regression_TestApp_CORE_DEPENDENCY = no
MCASP_DeviceLoopback_Regression_TestApp_XDC_CONFIGURO = yes
export MCASP_DeviceLoopback_Regression_TestApp_COMP_LIST
export MCASP_DeviceLoopback_Regression_TestApp_BOARD_DEPENDENCY
export MCASP_DeviceLoopback_Regression_TestApp_CORE_DEPENDENCY
export MCASP_DeviceLoopback_Regression_TestApp_XDC_CONFIGURO
MCASP_DeviceLoopback_Regression_TestApp_PKG_LIST = MCASP_DeviceLoopback_Regression_TestApp
MCASP_DeviceLoopback_Regression_TestApp_INCLUDE = $(MCASP_DeviceLoopback_Regression_TestApp_PATH)
MCASP_DeviceLoopback_Regression_TestApp_BOARDLIST = am65xx_evm am65xx_idk
export MCASP_DeviceLoopback_Regression_TestApp_BOARDLIST
MCASP_DeviceLoopback_Regression_TestApp_$(SOC)_CORELIST = $(drvmcasp_$(SOC)_CORELIST)
export MCASP_DeviceLoopback_Regression_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
MCASP_DeviceLoopback_Regression_TestApp_SBL_APPIMAGEGEN = yes
export MCASP_DeviceLoopback_Regression_TestApp_SBL_APPIMAGEGEN
endif

# McASP Audio DC Analog Loopback example app
MCASP_AudioDCAnalogLoopback_TestApp_COMP_LIST = MCASP_AudioDCAnalogLoopback_TestApp
MCASP_AudioDCAnalogLoopback_TestApp_RELPATH = ti/drv/mcasp/example/MCASP_AudioDCAnalogLoopback_TestApp
MCASP_AudioDCAnalogLoopback_TestApp_PATH = $(PDK_MCASP_COMP_PATH)/example/MCASP_AudioDCAnalogLoopback_TestApp
MCASP_AudioDCAnalogLoopback_TestApp_BOARD_DEPENDENCY = yes
MCASP_AudioDCAnalogLoopback_TestApp_CORE_DEPENDENCY = no
MCASP_AudioDCAnalogLoopback_TestApp_XDC_CONFIGURO = yes
export MCASP_AudioDCAnalogLoopback_TestApp_COMP_LIST
export MCASP_AudioDCAnalogLoopback_TestApp_BOARD_DEPENDENCY
export MCASP_AudioDCAnalogLoopback_TestApp_CORE_DEPENDENCY
export MCASP_AudioDCAnalogLoopback_TestApp_XDC_CONFIGURO
MCASP_AudioDCAnalogLoopback_TestApp_PKG_LIST = MCASP_AudioDCAnalogLoopback_TestApp
MCASP_AudioDCAnalogLoopback_TestApp_INCLUDE = $(MCASP_AudioDCAnalogLoopback_TestApp_PATH)
MCASP_AudioDCAnalogLoopback_TestApp_BOARDLIST = j721e_evm
export MCASP_AudioDCAnalogLoopback_TestApp_BOARDLIST
MCASP_AudioDCAnalogLoopback_TestApp_$(SOC)_CORELIST = $(drvmcasp_$(SOC)_CORELIST)
export MCASP_AudioDCAnalogLoopback_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
MCASP_AudioDCAnalogLoopback_TestApp_SBL_APPIMAGEGEN = yes
export MCASP_AudioDCAnalogLoopback_TestApp_SBL_APPIMAGEGEN
endif

# McASP Digital DC Analog Loopback example app
MCASP_AudioDCDigitalLoopback_TestApp_COMP_LIST = MCASP_AudioDCDigitalLoopback_TestApp
MCASP_AudioDCDigitalLoopback_TestApp_RELPATH = ti/drv/mcasp/example/MCASP_AudioDCDigitalLoopback_TestApp
MCASP_AudioDCDigitalLoopback_TestApp_PATH = $(PDK_MCASP_COMP_PATH)/example/MCASP_AudioDCDigitalLoopback_TestApp
MCASP_AudioDCDigitalLoopback_TestApp_BOARD_DEPENDENCY = yes
MCASP_AudioDCDigitalLoopback_TestApp_CORE_DEPENDENCY = no
MCASP_AudioDCDigitalLoopback_TestApp_XDC_CONFIGURO = yes
export MCASP_AudioDCDigitalLoopback_TestApp_COMP_LIST
export MCASP_AudioDCDigitalLoopback_TestApp_BOARD_DEPENDENCY
export MCASP_AudioDCDigitalLoopback_TestApp_CORE_DEPENDENCY
export MCASP_AudioDCDigitalLoopback_TestApp_XDC_CONFIGURO
MCASP_AudioDCDigitalLoopback_TestApp_PKG_LIST = MCASP_AudioDCDigitalLoopback_TestApp
MCASP_AudioDCDigitalLoopback_TestApp_INCLUDE = $(MCASP_AudioDCDigitalLoopback_TestApp_PATH)
MCASP_AudioDCDigitalLoopback_TestApp_BOARDLIST = j721e_evm
export MCASP_AudioDCDigitalLoopback_TestApp_BOARDLIST
MCASP_AudioDCDigitalLoopback_TestApp_$(SOC)_CORELIST = $(drvmcasp_$(SOC)_CORELIST)
export MCASP_AudioDCDigitalLoopback_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
MCASP_AudioDCDigitalLoopback_TestApp_SBL_APPIMAGEGEN = yes
export MCASP_AudioDCDigitalLoopback_TestApp_SBL_APPIMAGEGEN
endif

export drvmcasp_LIB_LIST
export mcasp_LIB_LIST
export mcasp_EXAMPLE_LIST

drvmcasp_EXAMPLE_LIST = $(mcasp_EXAMPLE_LIST)
export drvmcasp_EXAMPLE_LIST
mcasp_component_make_include := 1
endif

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

# File: icss_emac_component.mk
#       This file is component include make file of ICSS_EMAC library.
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
ifeq ($(icss_emac_component_make_include), )

# under other list
drvicss_emac_BOARDLIST       = 
drvicss_emac_SOCLIST         = am574x am572x am571x am437x am335x k2g am65xx
drvicss_emac_am574x_CORELIST = c66x a15_0 ipu1_0 pru_0 pru_1
drvicss_emac_am572x_CORELIST = c66x a15_0 ipu1_0 pru_0 pru_1
drvicss_emac_am571x_CORELIST = c66x a15_0 ipu1_0 pru_0 pru_1
drvicss_emac_am437x_CORELIST = a9host pru_0 pru_1
drvicss_emac_am335x_CORELIST = a8host pru_0 pru_1
drvicss_emac_k2g_CORELIST    = c66x a15_0 pru_0 pru_1
drvicss_emac_am65xx_CORELIST = mpu1_0 mcu1_0
############################
# icss_emac package
# List of components included under icss_emac lib
# The components included here are built and will be part of icss_emac lib
############################
icss_emac_LIB_LIST = icss_emac icss_emac_indp icss_emac_profile icss_emac_profile_indp
drvicss_emac_LIB_LIST = $(icss_emac_LIB_LIST)

icss_emac_FIRM_LIST = icss_dualemac icss_switch icss_stp_switch
drvicss_emac_FIRM_LIST = $(icss_emac_FIRM_LIST)

icss_emac_EXAMPLE_LIST =
drvicss_emac_EXAMPLE_LIST = $(icss_emac_EXAMPLE_LIST)

#
# ICSS_EMAC Modules
#

# ICSS_EMAC LIB
icss_emac_COMP_LIST = icss_emac
icss_emac_RELPATH = ti/drv/icss_emac
icss_emac_PATH = $(PDK_ICSS_EMAC_COMP_PATH)
icss_emac_LIBNAME = ti.drv.icss_emac
export icss_emac_LIBNAME
icss_emac_LIBPATH = $(icss_emac_PATH)/lib
export icss_emac_LIBPATH
icss_emac_OBJPATH = $(icss_emac_RELPATH)/icss_emac
export icss_emac_OBJPATH
icss_emac_MAKEFILE = -f build/makefile.mk
export icss_emac_MAKEFILE
icss_emac_BOARD_DEPENDENCY = no
icss_emac_CORE_DEPENDENCY = no
icss_emac_SOC_DEPENDENCY = yes
export icss_emac_COMP_LIST
export icss_emac_BOARD_DEPENDENCY
export icss_emac_CORE_DEPENDENCY
export icss_emac_SOC_DEPENDENCY
icss_emac_PKG_LIST = icss_emac
export icss_emac_PKG_LIST
icss_emac_INCLUDE = $(icss_emac_PATH)
icss_emac_SOCLIST = $(drvicss_emac_SOCLIST)
export icss_emac_SOCLIST
icss_emac_$(SOC)_CORELIST = $(drvicss_emac_$(SOC)_CORELIST)
export icss_emac_$(SOC)_CORELIST

# ICSS_EMAC INDEPENDENT LIB
icss_emac_indp_COMP_LIST = icss_emac_indp
icss_emac_indp_RELPATH = ti/drv/icss_emac
icss_emac_indp_PATH = $(PDK_ICSS_EMAC_COMP_PATH)
icss_emac_indp_LIBNAME = ti.drv.icss_emac
export icss_emac_indp_LIBNAME
icss_emac_indp_LIBPATH = $(icss_emac_indp_PATH)/lib
export icss_emac_indp_LIBPATH
icss_emac_indp_OBJPATH = $(icss_emac_indp_RELPATH)/icss_emac_indp
export icss_emac_indp_OBJPATH
icss_emac_indp_MAKEFILE = -f build/makefile_indp.mk
export icss_emac_indp_MAKEFILE
icss_emac_indp_BOARD_DEPENDENCY = no
icss_emac_indp_CORE_DEPENDENCY = no
icss_emac_indp_SOC_DEPENDENCY = no
export icss_emac_indp_COMP_LIST
export icss_emac_indp_BOARD_DEPENDENCY
export icss_emac_indp_CORE_DEPENDENCY
export icss_emac_indp_SOC_DEPENDENCY
icss_emac_indp_PKG_LIST = icss_emac_indp
export icss_emac_indp_PKG_LIST
icss_emac_indp_INCLUDE = $(icss_emac_indp_PATH)
icss_emac_indp_SOCLIST = $(drvicss_emac_SOCLIST)
export icss_emac_indp_SOCLIST
icss_emac_indp_$(SOC)_CORELIST = $(drvicss_emac_$(SOC)_CORELIST)
export icss_emac_indp_$(SOC)_CORELIST

# ICSS_EMAC PROFILE LIB
icss_emac_profile_COMP_LIST = icss_emac_profile
icss_emac_profile_RELPATH = ti/drv/icss_emac
icss_emac_profile_PATH = $(PDK_ICSS_EMAC_COMP_PATH)
icss_emac_profile_LIBNAME = ti.drv.icss_emac.profiling
export icss_emac_profile_LIBNAME
icss_emac_profile_LIBPATH = $(icss_emac_profile_PATH)/lib
export icss_emac_profile_LIBPATH
icss_emac_profile_OBJPATH = $(icss_emac_profile_RELPATH)/icss_emac_profile
export icss_emac_profile_OBJPATH
icss_emac_profile_MAKEFILE = -f build/makefile_profile.mk
export icss_emac_profile_MAKEFILE
icss_emac_profile_BOARD_DEPENDENCY = no
icss_emac_profile_CORE_DEPENDENCY = no
icss_emac_profile_SOC_DEPENDENCY = yes
export icss_emac_profile_COMP_LIST
export icss_emac_profile_BOARD_DEPENDENCY
export icss_emac_profile_CORE_DEPENDENCY
export icss_emac_profile_SOC_DEPENDENCY
icss_emac_profile_PKG_LIST = icss_emac_profile
export icss_emac_profile_PKG_LIST
icss_emac_profile_INCLUDE = $(icss_emac_profile_PATH)
icss_emac_profile_SOCLIST = $(drvicss_emac_SOCLIST)
export icss_emac_profile_SOCLIST
icss_emac_profile_$(SOC)_CORELIST = $(drvicss_emac_$(SOC)_CORELIST)
export icss_emac_profile_$(SOC)_CORELIST

# ICSS_EMAC PROFILE INDEPENDENT LIB
icss_emac_profile_indp_COMP_LIST = icss_emac_profile_indp
icss_emac_profile_indp_RELPATH = ti/drv/icss_emac
icss_emac_profile_indp_PATH = $(PDK_ICSS_EMAC_COMP_PATH)
icss_emac_profile_indp_LIBNAME = ti.drv.icss_emac.profiling
export icss_emac_profile_indp_LIBNAME
icss_emac_profile_indp_LIBPATH = $(icss_emac_profile_indp_PATH)/lib
export icss_emac_profile_indp_LIBPATH
icss_emac_profile_indp_OBJPATH = $(icss_emac_profile_indp_RELPATH)/icss_emac_profile_indp
export icss_emac_profile_indp_OBJPATH
icss_emac_profile_indp_MAKEFILE = -f build/makefile_profile_indp.mk
export icss_emac_profile_indp_MAKEFILE
icss_emac_profile_indp_BOARD_DEPENDENCY = no
icss_emac_profile_indp_CORE_DEPENDENCY = no
icss_emac_profile_indp_SOC_DEPENDENCY = no
export icss_emac_profile_indp_COMP_LIST
export icss_emac_profile_indp_BOARD_DEPENDENCY
export icss_emac_profile_indp_CORE_DEPENDENCY
export icss_emac_profile_indp_SOC_DEPENDENCY
icss_emac_profile_indp_PKG_LIST = icss_emac_profile_indp
export icss_emac_profile_indp_PKG_LIST
icss_emac_profile_indp_INCLUDE = $(icss_emac_profile_indp_PATH)
icss_emac_profile_indp_SOCLIST = $(drvicss_emac_SOCLIST)
export icss_emac_profile_indp_SOCLIST
icss_emac_profile_indp_$(SOC)_CORELIST = $(drvicss_emac_$(SOC)_CORELIST)
export icss_emac_profile_indp_$(SOC)_CORELIST

# ICCS DUAL EMAC FIRMWARE
icss_dualemac_COMP_LIST = icss_dualemac
# temporary fix for nightly build
# icss_dualemac_RELPATH = ti/drv/icss_emac/firmware/icss_dualemac
icss_dualemac_RELPATH = icss_dualemac
icss_dualemac_PATH = $(PDK_ICSS_EMAC_COMP_PATH)/firmware/icss_dualemac
icss_dualemac_HEADERNAME = icss_dualemac
export icss_dualemac_HEADERNAME
icss_dualemac_HEADERPATH = $(icss_dualemac_PATH)/bin
export icss_dualemac_HEADERPATH
icss_dualemac_OBJPATH = $(icss_dualemac_RELPATH)
export icss_dualemac_OBJPATH
icss_dualemac_MAKEFILE = -f ../../build/makefile_icss_dualemac.mk
export icss_dualemac_MAKEFILE
icss_dualemac_BOARD_DEPENDENCY = no
icss_dualemac_CORE_DEPENDENCY = yes
icss_dualemac_SOC_DEPENDENCY = yes
export icss_dualemac_COMP_LIST
export icss_dualemac_BOARD_DEPENDENCY
export icss_dualemac_CORE_DEPENDENCY
export icss_dualemac_SOC_DEPENDENCY
icss_dualemac_PKG_LIST = icss_dualemac
export icss_dualemac_PKG_LIST
icss_dualemac_INCLUDE = $(icss_dualemac_PATH)
icss_dualemac_SOCLIST = am571x am572x am335x am437x k2g am574x
export icss_dualemac_SOCLIST
icss_dualemac_$(SOC)_CORELIST = $(drvicss_emac_$(SOC)_CORELIST)
export icss_dualemac_$(SOC)_CORELIST

# ICCS SWITCH FIRMWARE
icss_switch_COMP_LIST = icss_switch
# temporary fix for nightly build
# icss_switch_RELPATH = ti/drv/icss_emac/firmware/icss_switch
icss_switch_RELPATH = icss_switch
icss_switch_PATH = $(PDK_ICSS_EMAC_COMP_PATH)/firmware/icss_switch
icss_switch_HEADERNAME = icss_switch
export icss_switch_HEADERNAME
icss_switch_HEADERPATH = $(icss_switch_PATH)/bin
export icss_switch_HEADERPATH
icss_switch_OBJPATH = $(icss_switch_RELPATH)
export icss_switch_OBJPATH
icss_switch_MAKEFILE = -f ../../build/makefile_icss_switch.mk
export icss_switch_MAKEFILE
icss_switch_BOARD_DEPENDENCY = no
icss_switch_CORE_DEPENDENCY = yes
icss_switch_SOC_DEPENDENCY = yes
export icss_switch_COMP_LIST
export icss_switch_BOARD_DEPENDENCY
export icss_switch_CORE_DEPENDENCY
export icss_switch_SOC_DEPENDENCY
icss_switch_PKG_LIST = icss_switch
export icss_switch_PKG_LIST
icss_switch_INCLUDE = $(icss_switch_PATH)
icss_switch_SOCLIST = am571x am572x am335x am437x k2g am574x
export icss_switch_SOCLIST
icss_switch_$(SOC)_CORELIST = $(drvicss_emac_$(SOC)_CORELIST)
export icss_switch_$(SOC)_CORELIST

# ICCS FW SWITCH FIRMWARE
icss_switch_COMP_LIST = icss_stp_switch
# temporary fix for nightly build
# icss_stp_switch_RELPATH = ti/drv/icss_emac/firmware/icss_switch
icss_stp_switch_RELPATH = icss_stp_switch
icss_stp_switch_PATH = $(PDK_ICSS_EMAC_COMP_PATH)/firmware/icss_switch
icss_stp_switch_HEADERNAME = icss_stp_switch
export icss_stp_switch_HEADERNAME
icss_stp_switch_HEADERPATH = $(icss_stp_switch_PATH)/bin
export icss_stp_switch_HEADERPATH
icss_stp_switch_OBJPATH = $(icss_stp_switch_RELPATH)
export icss_stp_switch_OBJPATH
icss_stp_switch_MAKEFILE = -f ../../build/makefile_icss_stp_switch.mk
export icss_stp_switch_MAKEFILE
icss_stp_switch_BOARD_DEPENDENCY = no
icss_stp_switch_CORE_DEPENDENCY = yes
icss_stp_switch_SOC_DEPENDENCY = yes
export icss_stp_switch_COMP_LIST
export icss_stp_switch_BOARD_DEPENDENCY
export icss_stp_switch_CORE_DEPENDENCY
export icss_stp_switch_SOC_DEPENDENCY
icss_stp_switch_PKG_LIST = icss_stp_switch
export icss_stp_switch_PKG_LIST
icss_stp_switch_INCLUDE = $(icss_stp_switch_PATH)
icss_stp_switch_SOCLIST = am571x am572x am574x
export icss_stp_switch_SOCLIST
icss_stp_switch_$(SOC)_CORELIST = $(drvicss_emac_$(SOC)_CORELIST)
export icss_stp_switch_$(SOC)_CORELIST


export drvicss_emac_LIB_LIST
export icss_emac_LIB_LIST
export drvicss_emac_FIRM_LIST
export icss_emac_FIRM_LIST
export drvicss_emac_EXAMPLE_LIST
export icss_emac_EXAMPLE_LIST


icss_emac_component_make_include := 1
endif

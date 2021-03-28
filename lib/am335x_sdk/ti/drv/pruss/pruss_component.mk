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

# File: pruss_component.mk
#       This file is component include make file of PRUSS library.
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
ifeq ($(pruss_component_make_include), )

# under other list
drvpruss_BOARDLIST       = icev2AM335x idkAM437x idkAM571x idkAM572x iceK2G idkAM574x
drvpruss_SOCLIST         = am574x am572x am571x am437x am335x k2g am65xx j721e
drvpruss_am574x_CORELIST = c66x a15_0 ipu1_0 pru_0 pru_1
drvpruss_am572x_CORELIST = c66x a15_0 ipu1_0 pru_0 pru_1
drvpruss_k2g_CORELIST    = c66x a15_0 pru_0 pru_1
drvpruss_am571x_CORELIST = c66x a15_0 ipu1_0 pru_0 pru_1
drvpruss_am437x_CORELIST = a9host pru_0 pru_1
drvpruss_am335x_CORELIST = a8host pru_0 pru_1
drvpruss_am65xx_CORELIST = mpu1_0 mcu1_0
drvpruss_j721e_CORELIST  = mcu1_0 mpu1_0

############################
# uart package
# List of components included under uart lib
# The components included here are built and will be part of uart lib
############################
pruss_LIB_LIST = pruss pruss_indp pruss_profile pruss_profile_indp
drvpruss_LIB_LIST = $(pruss_LIB_LIST)

pruss_FIRM_LIST = pruss_sorte_slave pruss_sorte_master
drvpruss_FIRM_LIST = $(pruss_FIRM_LIST)

pruss_EXAMPLE_LIST = pruss_app_sorte_slave pruss_app_sorte_master
drvpruss_EXAMPLE_LIST = $(pruss_EXAMPLE_LIST)


#
# PRUSS Modules
#

# PRUSS LIB
pruss_COMP_LIST = pruss
pruss_RELPATH = ti/drv/pruss
pruss_PATH = $(PDK_PRUSS_COMP_PATH)
pruss_LIBNAME = ti.drv.pruss
export pruss_LIBNAME
pruss_LIBPATH = $(pruss_PATH)/lib
export pruss_LIBPATH
pruss_OBJPATH = $(pruss_RELPATH)/pruss
export pruss_OBJPATH
pruss_MAKEFILE = -f build/makefile.mk
export pruss_MAKEFILE
pruss_BOARD_DEPENDENCY = no
pruss_CORE_DEPENDENCY = no
pruss_SOC_DEPENDENCY = yes
export pruss_COMP_LIST
export pruss_BOARD_DEPENDENCY
export pruss_CORE_DEPENDENCY
export pruss_SOC_DEPENDENCY
pruss_PKG_LIST = pruss
export pruss_PKG_LIST
pruss_INCLUDE = $(pruss_PATH)
pruss_SOCLIST = $(drvpruss_SOCLIST)
export pruss_SOCLIST
pruss_$(SOC)_CORELIST = $(drvpruss_$(SOC)_CORELIST)
export pruss_$(SOC)_CORELIST

# PRUSS INDEPENDENT LIB
pruss_indp_COMP_LIST = pruss_indp
pruss_indp_RELPATH = ti/drv/pruss
pruss_indp_PATH = $(PDK_PRUSS_COMP_PATH)
pruss_indp_LIBNAME = ti.drv.pruss
export pruss_indp_LIBNAME
pruss_indp_LIBPATH = $(pruss_indp_PATH)/lib
export pruss_indp_LIBPATH
pruss_indp_OBJPATH = $(pruss_indp_RELPATH)/pruss_indp
export pruss_indp_OBJPATH
pruss_indp_MAKEFILE = -f build/makefile_indp.mk
export pruss_indp_MAKEFILE
pruss_indp_BOARD_DEPENDENCY = no
pruss_indp_CORE_DEPENDENCY = no
pruss_indp_SOC_DEPENDENCY = no
export pruss_indp_COMP_LIST
export pruss_indp_BOARD_DEPENDENCY
export pruss_indp_CORE_DEPENDENCY
export pruss_indp_SOC_DEPENDENCY
pruss_indp_PKG_LIST = pruss_indp
export pruss_indp_PKG_LIST
pruss_indp_INCLUDE = $(pruss_indp_PATH)
pruss_indp_SOCLIST = $(drvpruss_SOCLIST)
export pruss_indp_SOCLIST
pruss_indp_$(SOC)_CORELIST = $(drvpruss_$(SOC)_CORELIST)
export pruss_indp_$(SOC)_CORELIST

# PRUSS PROFILE LIB
pruss_profile_COMP_LIST = pruss_profile
pruss_profile_RELPATH = ti/drv/pruss
pruss_profile_PATH = $(PDK_PRUSS_COMP_PATH)
pruss_profile_LIBNAME = ti.drv.pruss.profiling
export pruss_profile_LIBNAME
pruss_profile_LIBPATH = $(pruss_profile_PATH)/lib
export pruss_profile_LIBPATH
pruss_profile_OBJPATH = $(pruss_profile_RELPATH)/pruss_profile
export pruss_profile_OBJPATH
pruss_profile_MAKEFILE = -f build/makefile_profile.mk
export pruss_profile_MAKEFILE
pruss_profile_BOARD_DEPENDENCY = no
pruss_profile_CORE_DEPENDENCY = no
pruss_profile_SOC_DEPENDENCY = yes
export pruss_profile_COMP_LIST
export pruss_profile_BOARD_DEPENDENCY
export pruss_profile_CORE_DEPENDENCY
export pruss_profile_SOC_DEPENDENCY
pruss_profile_PKG_LIST = pruss_profile
export pruss_profile_PKG_LIST
pruss_profile_INCLUDE = $(pruss_profile_PATH)
pruss_profile_SOCLIST = $(drvpruss_SOCLIST)
export pruss_profile_SOCLIST
pruss_profile_$(SOC)_CORELIST = $(drvpruss_$(SOC)_CORELIST)
export pruss_profile_$(SOC)_CORELIST

# PRUSS PROFILE INDEPENDENT LIB
pruss_profile_indp_COMP_LIST = pruss_profile_indp
pruss_profile_indp_RELPATH = ti/drv/pruss
pruss_profile_indp_PATH = $(PDK_PRUSS_COMP_PATH)
pruss_profile_indp_LIBNAME = ti.drv.pruss.profiling
export pruss_profile_indp_LIBNAME
pruss_profile_indp_LIBPATH = $(pruss_profile_indp_PATH)/lib
export pruss_profile_indp_LIBPATH
pruss_profile_indp_OBJPATH = $(pruss_profile_indp_RELPATH)/pruss_profile_indp
export pruss_profile_indp_OBJPATH
pruss_profile_indp_MAKEFILE = -f build/makefile_profile_indp.mk
export pruss_profile_indp_MAKEFILE
pruss_profile_indp_BOARD_DEPENDENCY = no
pruss_profile_indp_CORE_DEPENDENCY = no
pruss_profile_indp_SOC_DEPENDENCY = no
export pruss_profile_indp_COMP_LIST
export pruss_profile_indp_BOARD_DEPENDENCY
export pruss_profile_indp_CORE_DEPENDENCY
export pruss_profile_indp_SOC_DEPENDENCY
pruss_profile_indp_PKG_LIST = pruss_profile_indp
export pruss_profile_indp_PKG_LIST
pruss_profile_indp_INCLUDE = $(pruss_profile_indp_PATH)
pruss_profile_indp_SOCLIST = $(drvpruss_SOCLIST)
export pruss_profile_indp_SOCLIST
pruss_profile_indp_$(SOC)_CORELIST = $(drvpruss_$(SOC)_CORELIST)
export pruss_profile_indp_$(SOC)_CORELIST


# PRUSS SORTE FIRMWARE
pruss_sorte_slave_COMP_LIST = pruss_sorte_slave
# temporary fix for nightly build
# pruss_sorte_slave_RELPATH = ti/drv/pruss/example/apps/sorte/firmware/pruss_sorte_slave
pruss_sorte_slave_RELPATH = pruss_sorte_slave
pruss_sorte_slave_PATH = $(PDK_PRUSS_COMP_PATH)/example/apps/sorte/firmware
pruss_sorte_slave_HEADERNAME = sorte_slave
export pruss_sorte_slave_HEADERNAME
pruss_sorte_slave_HEADERPATH = $(pruss_sorte_slave_PATH)/bin
export pruss_sorte_slave_HEADERPATH
pruss_sorte_slave_OBJPATH = $(pruss_sorte_slave_RELPATH)
export pruss_sorte_slave_OBJPATH
pruss_sorte_slave_MAKEFILE = -f ../../../../build/makefile_sorte_slave.mk
export pruss_sorte_slave_MAKEFILE
pruss_sorte_slave_BOARD_DEPENDENCY = no
pruss_sorte_slave_CORE_DEPENDENCY = yes
pruss_sorte_slave_SOC_DEPENDENCY = yes
export pruss_sorte_slave_COMP_LIST
export pruss_sorte_slave_BOARD_DEPENDENCY
export pruss_sorte_slave_CORE_DEPENDENCY
export pruss_sorte_slave_SOC_DEPENDENCY
pruss_sorte_slave_PKG_LIST = pruss_sorte_slave
export pruss_sorte_slave_PKG_LIST
pruss_sorte_slave_INCLUDE = $(pruss_sorte_slave_PATH)
pruss_sorte_slave_SOCLIST = am335x am437x am571x am572x k2g am574x
export pruss_sorte_slave_SOCLIST
pruss_sorte_slave_$(SOC)_CORELIST = $(drvpruss_$(SOC)_CORELIST)
export pruss_sorte_slave_$(SOC)_CORELIST

# PRUSS SORTE FIRMWARE
pruss_sorte_master_COMP_LIST = pruss_sorte_master
# temporary fix for nightly build
# pruss_sorte_master_RELPATH = ti/drv/pruss/example/apps/sorte/firmware/pruss_sorte_master
pruss_sorte_master_RELPATH = pruss_sorte_master
pruss_sorte_master_PATH = $(PDK_PRUSS_COMP_PATH)/example/apps/sorte/firmware
pruss_sorte_master_HEADERNAME = sorte_master
export pruss_sorte_master_HEADERNAME
pruss_sorte_master_HEADERPATH = $(pruss_sorte_master_PATH)/bin
export pruss_sorte_master_HEADERPATH
pruss_sorte_master_OBJPATH = $(pruss_sorte_master_RELPATH)
export pruss_sorte_master_OBJPATH
pruss_sorte_master_MAKEFILE = -f ../../../../build/makefile_sorte_master.mk
export pruss_sorte_master_MAKEFILE
pruss_sorte_master_BOARD_DEPENDENCY = no
pruss_sorte_master_CORE_DEPENDENCY = yes
pruss_sorte_master_SOC_DEPENDENCY = yes
export pruss_sorte_master_COMP_LIST
export pruss_sorte_master_BOARD_DEPENDENCY
export pruss_sorte_master_CORE_DEPENDENCY
export pruss_sorte_master_SOC_DEPENDENCY
pruss_sorte_master_PKG_LIST = pruss_sorte_master
export pruss_sorte_master_PKG_LIST
pruss_sorte_master_INCLUDE = $(pruss_sorte_master_PATH)
pruss_sorte_master_SOCLIST = am335x am437x am571x am572x k2g am574x
export pruss_sorte_master_SOCLIST
pruss_sorte_master_$(SOC)_CORELIST = pru_0
export pruss_sorte_master_$(SOC)_CORELIST

#
# PRUSS Examples
#
# PRUSS SORTE Slave app
pruss_app_sorte_slave_COMP_LIST = pruss_app_sorte_slave
pruss_app_sorte_slave_RELPATH = ti/drv/pruss/example/apps/sorte/slave
pruss_app_sorte_slave_PATH = $(PDK_PRUSS_COMP_PATH)/example/apps/sorte/slave
pruss_app_sorte_slave_BINPATH = $(pruss_app_sorte_slave_PATH)
export pruss_app_sorte_slave_BINPATH
pruss_app_sorte_slave_BOARD_DEPENDENCY = yes
pruss_app_sorte_slave_CORE_DEPENDENCY = no
pruss_app_sorte_slave_XDC_CONFIGURO = yes
export pruss_app_sorte_slave_COMP_LIST
export pruss_app_sorte_slave_BOARD_DEPENDENCY
export pruss_app_sorte_slave_CORE_DEPENDENCY
export pruss_app_sorte_slave_XDC_CONFIGURO
pruss_app_sorte_slave_PKG_LIST = pruss_app_sorte_slave
pruss_app_sorte_slave_INCLUDE = $(pruss_app_sorte_slave_PATH)
pruss_app_sorte_slave_BOARDLIST = icev2AM335x idkAM437x idkAM571x idkAM572x iceK2G idkAM574x
export pruss_app_sorte_slave_BOARDLIST
pruss_app_sorte_slave_SOCLIST = $(SOC)
export pruss_app_sorte_slave_SOCLIST
ifeq ($(BOARD),$(filter $(BOARD), icev2AM335x))
pruss_app_sorte_slave_$(SOC)_CORELIST = a8host 
endif
ifeq ($(BOARD),$(filter $(BOARD), idkAM437x))
pruss_app_sorte_slave_$(SOC)_CORELIST = a9host 
endif

ifeq ($(BOARD),$(filter $(BOARD), idkAM572x idkAM574x))
pruss_app_sorte_slave_$(SOC)_CORELIST = a15_0 
endif

ifeq ($(BOARD),$(filter $(BOARD), idkAM571x))
pruss_app_sorte_slave_$(SOC)_CORELIST = a15_0 
endif

ifeq ($(BOARD),$(filter $(BOARD), iceK2G))
pruss_app_sorte_slave_$(SOC)_CORELIST = a15_0 
endif

export pruss_app_sorte_slave_$(SOC)_CORELIST

# PRUSS SORTE Master app
pruss_app_sorte_master_COMP_LIST = pruss_app_sorte_master
pruss_app_sorte_master_RELPATH = ti/drv/pruss/example/apps/sorte/master
pruss_app_sorte_master_PATH = $(PDK_PRUSS_COMP_PATH)/example/apps/sorte/master
pruss_app_sorte_master_BINPATH = $(pruss_app_sorte_master_PATH)
export pruss_app_sorte_master_BINPATH
pruss_app_sorte_master_BOARD_DEPENDENCY = yes
pruss_app_sorte_master_CORE_DEPENDENCY = no
pruss_app_sorte_master_XDC_CONFIGURO = yes
export pruss_app_sorte_master_COMP_LIST
export pruss_app_sorte_master_BOARD_DEPENDENCY
export pruss_app_sorte_master_CORE_DEPENDENCY
export pruss_app_sorte_master_XDC_CONFIGURO
pruss_app_sorte_master_PKG_LIST = pruss_app_sorte_master
pruss_app_sorte_master_INCLUDE = $(pruss_app_sorte_master_PATH)
pruss_app_sorte_master_BOARDLIST = icev2AM335x idkAM437x idkAM571x idkAM572x iceK2G idkaM574x
export pruss_app_sorte_master_BOARDLIST
pruss_app_sorte_master_SOCLIST = $(SOC)
export pruss_app_sorte_master_SOCLIST

ifeq ($(BOARD),$(filter $(BOARD), icev2AM335x))
pruss_app_sorte_master_$(SOC)_CORELIST = a8host 
endif

ifeq ($(BOARD),$(filter $(BOARD), idkAM437x))
pruss_app_sorte_master_$(SOC)_CORELIST = a9host 
endif

ifeq ($(BOARD),$(filter $(BOARD), idkAM572x idkAM574x))
pruss_app_sorte_master_$(SOC)_CORELIST = a15_0 
endif

ifeq ($(BOARD),$(filter $(BOARD), idkAM571x))
pruss_app_sorte_master_$(SOC)_CORELIST = a15_0 
endif

ifeq ($(BOARD),$(filter $(BOARD), iceK2G))
pruss_app_sorte_master_$(SOC)_CORELIST = a15_0 
endif

export pruss_app_sorte_master_$(SOC)_CORELIST

export drvpruss_LIB_LIST
export pruss_LIB_LIST
export drvpruss_FIRM_LIST
export pruss_FIRM_LIST
export drvpruss_EXAMPLE_LIST
export pruss_EXAMPLE_LIST

pruss_component_make_include := 1
endif

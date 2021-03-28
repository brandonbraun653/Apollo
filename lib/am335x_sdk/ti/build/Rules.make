#
# Copyright (c) 2013-2018, Texas Instruments Incorporated
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

#Default build environment, (Windows_NT / linux)
#if nothing is defined, default to linux as in windows this variable is defined
export OS ?= linux

SDK_INSTALL_PATH ?= $(abspath ../../../../)
TOOLS_INSTALL_PATH ?= $(SDK_INSTALL_PATH)

#Default BUILD_OS_TYPE (tirtos/baremetal/qnx)
export BUILD_OS_TYPE ?= tirtos

include $(PDK_INSTALL_PATH)/ti/build/procsdk_defs.mk

# Default board
# Supported values are printed in "make -s help" option. Below are the list for reference.
#                   evmDRA72x, evmDRA75x, evmDRA78x,
#                   evmAM572x, idkAM571x, idkAM572x idkAM574x
#                   evmK2H, evmK2K, evmK2E, evmK2L, evmK2G, evmC6678, evmC6657,
#                   evmAM335x, icev2AM335x, iceAMIC110, skAM335x, bbbAM335x,
#                   evmAM437x idkAM437x skAM437x evmOMAPL137 lcdkOMAPL138

################################################################################
# Other user configurable variables
################################################################################

#if LIMIT_BOARDS is defined, BOARD from the LIMIT_BOARDS
ifneq ($(LIMIT_BOARDS),)
BOARD ?= $(firstword $(LIMIT_BOARDS))
SOC ?= $(firstword $(LIMIT_SOCS))
CORE ?= $(firstword $(LIMIT_CORES))
else	
#if LIMIT_BOARDS is not defined, default BOARD and SOC to the below
export BOARD ?= j721e_evm
export SOC ?= j721e
endif
# Default to m4 build depending on BOARD selected!!
ifeq ($(BOARD),$(filter $(BOARD), evmAM572x idkAM572x idkAM571x idkAM574x))
  CORE ?= a15_0
endif
ifeq ($(BOARD),$(filter $(BOARD), am65xx_sim am65xx_evm am65xx_idk j721e_sim j721e_vhwazebu j721e_qt j721e_evm j7200_evm j7200_sim am64x_evm))
  CORE ?= mcu1_0
endif
ifeq ($(BOARD),$(filter $(BOARD), j721e_ccqt j721e_loki))
  CORE ?= c7x_1
endif
ifeq ($(BOARD),$(filter $(BOARD), j721e_hostemu j7200_hostemu))
  CORE = c7x-hostemu
endif
ifeq ($(BOARD),$(filter $(BOARD), tpr12_evm))
  CORE ?= mcu1_0
endif
CORE ?= ipu1_0
export CORE

# Default Build Profile
# Supported Values: debug | release
export BUILD_PROFILE ?= release

# Treat compiler warning as error
# Supported Values: yes | no
export TREAT_WARNINGS_AS_ERROR ?= yes

#Various boards support for J7 TDA family of devices
BOARD_LIST_J7_TDA = j721e_sim j721e_hostemu j721e_ccqt j721e_loki j721e_qt j721e_vhwazebu j721e_evm
BOARD_LIST_J7_TDA += j7200_sim j7200_hostemu j7200_evm am64x_evm
BOARD_LIST_J7_TDA += am65xx_evm
export BOARD_LIST_J7_TDA

#Various boards support for TPR12 family of devices
export BOARD_LIST_TPR12 = tpr12_evm

################################################################################
# Other advanced configurable variables
################################################################################

# Set Core Build Profile depending on BUILD_PROFILE value
export BUILD_PROFILE_$(CORE) ?= $(BUILD_PROFILE)

# Default PACKAGE_SELECT build flag
# Supported values: all, vps-hal-only, vps-vip-only, vps-vpe-only, vps-dss-only, vps-vip-dss, vps-vip-vpe
export PACKAGE_SELECT ?= all

# Disable recursive building of example dependencies
export DISABLE_RECURSE_DEPS ?= no

# Default C++ build flag, yes or no
export CPLUSPLUS_BUILD ?= no

include $(PDK_INSTALL_PATH)/ti/build/pdk_tools_path.mk

#use <module>_PATH variable as makefile internally expects PATH variable this way for external component path
export pdk_PATH := $(PDK_INSTALL_PATH)
export bios_PATH := $(BIOS_INSTALL_PATH)
export xdc_PATH := $(XDC_INSTALL_PATH)
export edma3_lld_PATH := $(EDMA3LLD_BIOS6_INSTALLDIR)
export ndk_PATH := $(NDK_INSTALL_PATH)
export ns_PATH := $(NS_INSTALL_PATH)
export radarLink_PATH := $(RADARLINK_INSTALL_PATH)
export ipc_PATH := $(IPC_INSTALL_PATH)
export uia_PATH := $(UIA_INSTALL_PATH)

export ROOTDIR := $(pdk_PATH)
XDCPATH =
ifeq ($(BUILD_OS_TYPE),tirtos)
  XDCPATH = $(bios_PATH)/packages;$(xdc_PATH)/packages;$(edma3_lld_PATH)/packages;$(ndk_PATH)/packages;$(ns_PATH)/;$(pdk_PATH);$(ipc_PATH)/packages;$(uia_PATH)/packages;
endif
export XDCPATH

#Default SECTTI SIZE INFORMATION
export SECTTI_SIZE_INFO ?= no

#Default SECTTI tool
export SECTTI ?= $(CG_XML_BIN_INSTALL_PATH)/sectti

# Build for HS devices if secdev package is found
ifneq ("$(wildcard $(TI_SECURE_DEV_PKG)/scripts/secure-binary-image.sh)","")
  export SECUREMODE ?= yes
endif

# include other dependent files
include $(PDK_INSTALL_PATH)/ti/build/comp_paths.mk
ifeq ($(MAKERULEDIR), )
  #Makerule path not defined, define this and assume relative path from ROOTDIR
  export MAKERULEDIR := $(ROOTDIR)/ti/build/makerules
endif
include $(MAKERULEDIR)/build_config.mk
include $(MAKERULEDIR)/platform.mk
include $(MAKERULEDIR)/env.mk

export PRUCORE_LIST = $(CORE_LIST_PRU)

################################################################################
# Build Tools Configuration
################################################################################

ifeq ($(OS),Windows_NT)
  PATH := $(PATH)
endif

# Compiler Tools:
# PATH := $(C6X_GEN_INSTALL_PATH)/bin;$(PATH)

# XDC Tools location:
PATH := $(XDC_INSTALL_PATH);$(XDC_INSTALL_PATH)/bin;$(XDC_INSTALL_PATH)/packages/xdc/services/io/release;$(PATH)

ifeq ($(OS),Windows_NT)
  PATH := $(subst /,\,$(PATH))
else
  PATH := $(subst ;,:,$(PATH))
endif

export PATH

LIBDIR ?= ./lib
export LIBDIR

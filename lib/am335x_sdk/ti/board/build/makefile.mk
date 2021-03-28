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


include $(PDK_INSTALL_PATH)/ti/build/Rules.make

MODULE_NAME = board

SRCDIR = . src
INCDIR = . src

PACKAGE_SRCS_COMMON =

ifeq ($(BOARD),$(filter $(BOARD),evmAM335x icev2AM335x iceAMIC110 skAM335x bbbAM335x evmAM437x idkAM437x skAM437x evmAM572x idkAM571x idkAM572x evmK2H evmK2K evmK2E evmK2L evmK2G iceK2G evmC6678 evmC6657 evmOMAPL137 lcdkOMAPL138 idkAM574x am65xx_evm am65xx_idk tpr12_evm))
# Common source files across all platforms and cores
SRCS_COMMON += board.c
endif

ifeq ($(BOARD),$(filter $(BOARD),evmAM335x icev2AM335x iceAMIC110 skAM335x bbbAM335x evmAM437x idkAM437x skAM437x evmAM572x idkAM571x idkAM572x evmK2H evmK2K evmK2E evmK2L iceK2G evmC6678 evmC6657 evmOMAPL137 lcdkOMAPL138 idkAM574x evmDRA72x evmDRA75x evmDRA78x evmTDAxx j721e_sim j721e_qt j7200_evm tpr12_evm))
# Board stub function enabled for all the boards except evmK2G
SRCS_COMMON += boardStub.c
endif

ifeq ($(BOARD),$(filter $(BOARD), evmAM335x icev2AM335x iceAMIC110 skAM335x bbbAM335x evmAM437x idkAM437x skAM437x))
include $(PDK_BOARD_COMP_PATH)/src/$(BOARD)/src_files_$(BOARD).mk
include $(PDK_BOARD_COMP_PATH)/src/src_files_starterware.mk
ifeq ($(BOARD),$(filter $(BOARD), icev2AM335x evmAM437x))
include $(PDK_BOARD_COMP_PATH)/src/flash/src_files_flash.mk
endif
endif

ifeq ($(BOARD),$(filter $(BOARD), am65xx_evm am65xx_idk))
include $(PDK_BOARD_COMP_PATH)/src/$(BOARD)/src_files_$(BOARD).mk
include $(PDK_BOARD_COMP_PATH)/src/evmKeystone3/src_files_evmKeystone3.mk
include $(PDK_BOARD_COMP_PATH)/src/flash/src_files_flash.mk
include $(PDK_BOARD_COMP_PATH)/src/devices/src_files_devices.mk
include $(PDK_BOARD_COMP_PATH)/src/src_files_lld.mk
endif

ifeq ($(BOARD),$(filter $(BOARD), j721e_sim j721e_qt))
include $(PDK_BOARD_COMP_PATH)/src/j721e_sim/src_files_j721e_sim.mk
include $(PDK_BOARD_COMP_PATH)/src/flash/src_files_flash.mk
PACKAGE_SRCS_COMMON += src/j721e_sim
endif

ifeq ($(BOARD),$(filter $(BOARD), j721e_evm))
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)
include $(PDK_BOARD_COMP_PATH)/src/$(BOARD)/src_files_$(BOARD).mk
include $(PDK_BOARD_COMP_PATH)/src/flash/src_files_flash.mk
include $(PDK_BOARD_COMP_PATH)/src/devices/src_files_devices.mk
PACKAGE_SRCS_COMMON += src/$(BOARD)
PACKAGE_SRCS_COMMON += src/devices
endif

ifeq ($(BOARD),$(filter $(BOARD), j7200_evm))
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)
include $(PDK_BOARD_COMP_PATH)/src/$(BOARD)/src_files_$(BOARD).mk
include $(PDK_BOARD_COMP_PATH)/src/flash/src_files_flash.mk
include $(PDK_BOARD_COMP_PATH)/src/devices/src_files_devices.mk
PACKAGE_SRCS_COMMON += src/$(BOARD)
PACKAGE_SRCS_COMMON += src/devices
endif

ifeq ($(BOARD),$(filter $(BOARD), tpr12_evm))
include $(PDK_BOARD_COMP_PATH)/src/$(BOARD)/src_files_$(BOARD).mk
PACKAGE_SRCS_COMMON += src/$(BOARD)
endif

ifeq ($(BOARD),$(filter $(BOARD), evmAM572x idkAM571x idkAM572x idkAM574x))
include $(PDK_BOARD_COMP_PATH)/src/$(BOARD)/src_files_$(BOARD).mk
include $(PDK_BOARD_COMP_PATH)/src/src_files_lld.mk
endif

ifeq ($(BOARD),$(filter $(BOARD), evmK2E evmK2L evmK2G iceK2G evmC6678 evmC6657))
include $(PDK_BOARD_COMP_PATH)/src/$(BOARD)/src_files_$(BOARD).mk
include $(PDK_BOARD_COMP_PATH)/src/evmKeystone/src_files_evmKeystone.mk
include $(PDK_BOARD_COMP_PATH)/src/flash/src_files_flash.mk
CFLAGS_LOCAL_$(BOARD) += -D$(BOARD)=$(BOARD)
endif

ifeq ($(BOARD),$(filter $(BOARD), evmK2H evmK2K))
include $(PDK_BOARD_COMP_PATH)/src/evmK2H/src_files_evmK2H.mk
include $(PDK_BOARD_COMP_PATH)/src/evmKeystone/src_files_evmKeystone.mk
include $(PDK_BOARD_COMP_PATH)/src/flash/src_files_flash.mk
CFLAGS_LOCAL_$(BOARD) += -DevmK2H=evmK2H
endif

ifeq ($(BOARD),$(filter $(BOARD), tda2xx-evm tda2ex-evm tda3xx-evm))
SRCDIR += src/evmTDAxx
INCDIR += src/evmTDAxx
SRCS_COMMON += evmTDAxx.c
PACKAGE_SRCS_COMMON += src/evmTDAxx
CFLAGS_LOCAL_$(BOARD) += -D$(BOARD)=$(BOARD)
endif

ifeq ($(BOARD),$(filter $(BOARD), evmDRA72x evmDRA75x evmDRA78x))
include $(PDK_BOARD_COMP_PATH)/src/$(BOARD)/src_files_$(BOARD).mk
SRCDIR += src/$(BOARD) src/evmAM572x/device
INCDIR += src/$(BOARD) src/evmAM572x/device
SRCS_COMMON += $(BOARD).c enet_phy.c
PACKAGE_SRCS_COMMON += src/$(BOARD) src/evmAM572x/device
CFLAGS_LOCAL_$(BOARD) += -D$(BOARD)=$(BOARD)
endif


ifeq ($(BOARD),$(filter $(BOARD), evmOMAPL137))
include $(PDK_BOARD_COMP_PATH)/src/$(BOARD)/src_files_$(BOARD).mk
include $(PDK_BOARD_COMP_PATH)/src/flash/src_files_flash.mk
CFLAGS_LOCAL_$(BOARD) += -D$(BOARD)=$(BOARD)
endif

ifeq ($(BOARD),$(filter $(BOARD), lcdkOMAPL138))
include $(PDK_BOARD_COMP_PATH)/src/$(BOARD)/src_files_$(BOARD).mk
CFLAGS_LOCAL_$(BOARD) += -D$(BOARD)=$(BOARD)
endif

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk edma


# List all the internal submodules whose interface header files
# need to be included for this module
INCLUDE_INTERNAL_INTERFACES = csl

PACKAGE_SRCS_COMMON += makefile board_component.mk board.h \
                       board_cfg.h build/makefile.mk
ifeq ($(BOARD),$(filter $(BOARD), j721e_sim j721e_qt j721e_evm j7200_evm tpr12_evm))
PACKAGE_SRCS_COMMON += src/board.c src/boardStub.c src/Module.xs \
                       src/src_files_lld.mk src/src_files_starterware.mk
else
PACKAGE_SRCS_COMMON += src
endif

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ROOTDIR)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
#     and need not be explicitly specified here

# Nothing beyond this point


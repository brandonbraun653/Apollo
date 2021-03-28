# Filename: Makefile
#
# This file is the makefile for building this module.
#
# Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
#
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
#    Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the
#    distribution.
#
#    Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#******************************************************************************


APP_NAME = dcan_app_loopback

SRCDIR = . ..
SRCDIR += ${PDK_INSTALL_PATH}/ti/starterware/examples/example_utils/
INCDIR = . ..

# Conditional Check to build the StarterWare libraries
# for RTOS environment. RTOS_BUILD flag needs to be enabled
# for this.

ifeq ($(RTOS_BUILD), yes)
.PHONY: all
all: dcanlibs_create app_build

.PHONY: dcanlibs_create
dcanlibs_create:
	cd  $(PDK_INSTALL_PATH)/ti/starterware/; \
	$(MAKE) -s libs_clean PLATFORM=$(PLATFORM) PROFILE=release; \
	$(MAKE) -s example_utils_clean PLATFORM=$(PLATFORM) PROFILE=release; \
	$(MAKE) libs PLATFORM=$(PLATFORM)  PROFILE=release RTOS_BUILD=yes; \
	$(MAKE) example_utils PLATFORM=$(PLATFORM)  PROFILE=release RTOS_BUILD=yes;

.PHONY: app_build
app_build:

include $(PDK_INSTALL_PATH)/ti/build/Rules.make

# List all the directories, whose interface header files
# need to be included for this component

INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/examples/dcan
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/examples/example_utils
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/include/hw
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/include/utils
ifeq ($(PLATFORM), am335x-evm)
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/include/am335x
endif
ifeq ($(PLATFORM), am43xx-evm)
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/include/am43xx
endif
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/include
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/include/am43xx/am437x
INCDIR += ${PDK_INSTALL_PATH}
INCDIR += $(XDC_INSTALL_PATH)/packages/
INCDIR += $(BIOS_INSTALL_PATH)/packages/

LIB_PATH += $(BIOS_INSTALL_PATH)/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/lib/hard

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = example_utils dal soc board utils device bios xdc pdk

# List all the components required by the application
COMP_LIST_COMMON = example_utils board utils soc dal bios xdc

# XDC CFG File
ifeq ($(PLATFORM), am335x-evm)
XDC_CFG_FILE_a8host = rtos/am335x_app_dcan_evmam335x.cfg
endif
ifeq ($(PLATFORM), am43xx-evm)
XDC_CFG_FILE_a9host = rtos/am437x_app_dcan_evmam437x.cfg
endif

# Common source files and CFLAGS across all platforms and cores
SRCS_COMMON = dcan_app.c loopback_app_main.c
SRCS_COMMON += dma_utils.c edma_utils.c
ifeq ($(PLATFORM), am43xx-evm)
CFLAGS_LOCAL_COMMON += -DRTOS_BUILD -DSOC_AM437X -DevmAM437x -DAM43XX_FAMILY_BUILD
endif
ifeq ($(PLATFORM), am335x-evm)
CFLAGS_LOCAL_COMMON += -DRTOS_BUILD -DSOC_AM335X -DevmAM335x -DAM335X_FAMILY_BUILD
endif

# Include common make files
include $(STARTERWARE_ROOTDIR)/ti/build/makerules/common.mk

else

include $(STARTERWARE_ROOTDIR)/build/makerules/platform.mk

# List all the external components/interfaces, whose interface header files
# need to be included for this component

INCLUDE_EXTERNAL_INTERFACES = example_utils dal soc board utils device

# List all the components required by the application
COMP_LIST_COMMON = example_utils board utils soc dal

# Common source files and CFLAGS across all platforms and cores
SRCS_COMMON = dcan_app.c loopback_app_main.c

CFLAGS_LOCAL_COMMON =

LNKCMD_FILE = $(STARTERWARE_ROOTDIR)/examples/$(TOOLCHAIN)/$(SOCFAMILY)_ddr.lds

# Include common make files
include $(STARTERWARE_ROOTDIR)/build/makerules/common.mk

endif

# OBJs and libraries are built by using rule defined in rules_<target>.mk
# and need not be explicitly specified here

# Nothing beyond this point

# Filename: Makefile
#
# This file is the makefile for building this module.
#
# Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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


APP_NAME = lcdc_app_raster

SRCDIR = . ..
INCDIR = . ..

ifeq ($(RTOS_BUILD), yes)
.PHONY: all
all: lcdclibs_create lcdcapp_build

.PHONY: lcdclibs_create
lcdclibs_create:
	cd  $(PDK_INSTALL_PATH)/ti/starterware/; \
	$(MAKE) -s libs_clean PLATFORM=$(PLATFORM) PROFILE=release; \
	$(MAKE) -s example_utils_clean PLATFORM=$(PLATFORM) PROFILE=release; \
	$(MAKE) libs PLATFORM=$(PLATFORM)  PROFILE=release RTOS_BUILD=yes; \
	$(MAKE) example_utils PLATFORM=$(PLATFORM) PROFILE=release RTOS_BUILD=yes;

.PHONY: lcdcapp_build
lcdcapp_build:
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

# List all the directories, whose interface header files
# need to be included for this component
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/examples/lcdc/
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/examples/example_utils
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/device
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/include/hw
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/include/utils
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/include/am335x
INCDIR += ${PDK_INSTALL_PATH}/ti/starterware/include
INCDIR += ${PDK_INSTALL_PATH}
INCDIR += $(XDC_INSTALL_PATH)/packages/
INCDIR += $(BIOS_INSTALL_PATH)/packages/

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = example_utils dal soc board utils device bios xdc pdk

# List all the components required by the application
COMP_LIST_COMMON = example_utils board utils soc dal device bios xdc

# Common source files and CFLAGS across all platforms and cores
SRCS_COMMON = lcdc_app.c raster_app_main.c

# XDC CFG File
XDC_CFG_FILE_a8host = rtos/am335x_app_lcdc_evmam335x.cfg

CFLAGS_LOCAL_COMMON += -DRTOS_BUILD -DLCD_EVM

# Include common make files
include $(STARTERWARE_ROOTDIR)/ti/build/makerules/common.mk

else

include $(STARTERWARE_ROOTDIR)/build/makerules/platform.mk

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = example_utils dal soc board utils device
#INCLUDE_EXTERNAL_INTERFACES = dal soc board utils

# List all the components required by the application
COMP_LIST_COMMON = example_utils board utils soc dal device
#COMP_LIST_COMMON = board utils soc dal

# Common source files and CFLAGS across all platforms and cores
SRCS_COMMON = lcdc_app.c raster_app_main.c

#include the image of the proper resolution based on the lcd board.
ifeq ($(LCDTYPE), lcd-lcd4_dcard)
  CFLAGS_LOCAL_COMMON += -DLCD_LCD4_DCARD
endif # ifeq ($(LCDTYPE), lcd-lcd4_dcard)

ifeq ($(LCDTYPE), lcd-evm)
  CFLAGS_LOCAL_COMMON += -DLCD_EVM
endif # ifeq ($(LCDTYPE), lcd-evm)

ifeq ($(LCDTYPE),)
  CFLAGS_LOCAL_COMMON += -DLCD_EVM
endif # ifeq ($(LCDTYPE),)

LNKCMD_FILE = $(STARTERWARE_ROOTDIR)/examples/$(TOOLCHAIN)/$(SOCFAMILY)_ddr.lds

# Core/SoC/platform specific source files and CFLAGS
# Example:
# SRCS_<core/SoC/platform-name> =
# CFLAGS_LOCAL_<core/SoC/platform-name> =

# Include common make files
include $(STARTERWARE_ROOTDIR)/build/makerules/common.mk

endif
# OBJs and libraries are built by using rule defined in rules_<target>.mk
# and need not be explicitly specified here

# Nothing beyond this point

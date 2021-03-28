# Filename: Rules.make
#
# This file contains:
# 1. Default settings for configuration of the make system
# 2. Path for the toolchain, StarterWare installation and dependencies
#
# Copyright (C) 2013-2017 Texas Instruments Incorporated - http://www.ti.com/
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


ifeq ($(starterware_PATH), )

#Default build environment, windows or linux
ifeq ($(OS), )
  OS := linux
endif

starterware_RELPATH = starterware-src

ifeq ($(OS),Windows_NT)
#Paths for windows machine
  starterware_PATH := $(CURDIR)

  KW_PATH :=
else #Paths for linux machine
  # Directory where all external (imported) software packages are located;
  # typically those that are NOT checked into version controlled repository.
  # In this case, compiler tool chains etc.
  EXTERNAL_SW_ROOT = /opt

  starterware_PATH := $(CURDIR)
  KW_PATH := /apps/klocwork/klocwork/client_9.5.3/bin
endif

STARTERWARE_ROOTDIR := $(starterware_PATH)

# Default toolchain
# Supported values: gcc, ewarm
ifeq ($(TOOLCHAIN), )
  TOOLCHAIN := gcc
endif

# Default platform
# Supported values: am335x-evm, am43xx-evm
ifeq ($(PLATFORM), )
  PLATFORM := am43xx-evm
endif

# Default core
# Supported values: a8host, a9host
# Default to a8host or a9host build depending on platform selected!
ifeq ($(PLATFORM),$(filter $(PLATFORM), am335x-evm amic110-ddrless))
  CORE := a8host
endif

ifeq ($(PLATFORM),am43xx-evm)
  CORE := a9host
endif

# Default profile
# Supported values: debug, release, prod_release
ifeq ($(PROFILE), )
  PROFILE := debug
endif

ifeq ($(PROFILE_$(CORE)), )
  PROFILE_$(CORE) := $(PROFILE)
endif

# Default console build flag
# Supported values: SEMIHOSTING, UART
ifeq ($(CONSOLE), )
  CONSOLE := UART
endif

# Default build configuration
# Supported values: all, boot
ifeq ($(BUILDCFG), )
  BUILDCFG := all
endif

# Default boot mode
# Supported values: mmcsd, uart
# Default boot mode is set to mmcsd if build configuration is boot.
ifeq ($(BOOTMODE), )
  ifeq ($(BUILDCFG), boot)
    BOOTMODE := mmcsd
  endif
endif

# Default klockwork build flag
# Supported values: yes, no
ifeq ($(KW_BUILD), )
  KW_BUILD := no
endif

# Default C++ build flag
# Supported values: yes, no
ifeq ($(CPLUSPLUS_BUILD), )
  CPLUSPLUS_BUILD := no
endif

export OS
export PLATFORM
export CORE
export PROFILE_$(CORE)
export TOOLCHAIN
export FPULIB_VERSION
export starterware_RELPATH
export starterware_PATH
export KW_PATH
export STARTERWARE_ROOTDIR
export CONSOLE
export KW_BUILD
export CPLUSPLUS_BUILD
export BUILDCFG
export BOOTMODE

endif

include $(STARTERWARE_ROOTDIR)/build/makerules/build_config.mk
include $(STARTERWARE_ROOTDIR)/build/makerules/env.mk
include $(STARTERWARE_ROOTDIR)/build/makerules/platform.mk
include $(STARTERWARE_ROOTDIR)/build/makerules/component.mk

# Default SOC - can be set only after SOCFAMILY is set in platform.mk.
# Supported values depend on the SOCFAMILY.
ifeq ($(SOCFAMILY), am335x)
  SOC := am335x
endif #ifeq ($(SOCFAMILY), am335x)
ifeq ($(SOCFAMILY), am43xx)
  SOC := am437x
endif #ifeq ($(SOCFAMILY), am43xx)

export SOC

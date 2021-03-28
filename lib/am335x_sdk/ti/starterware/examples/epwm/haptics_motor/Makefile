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


APP_NAME = epwm_app_haptics_motor

include $(STARTERWARE_ROOTDIR)/build/makerules/platform.mk

SRCDIR = . ..
INCDIR = . ..

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES =  example_utils board utils soc dal

# List all the components required by the application
COMP_LIST_COMMON = example_utils board utils soc dal

# Common source files and CFLAGS across all platforms and cores
SRCS_COMMON = epwm_app.c haptics_motor_app_main.c

CFLAGS_LOCAL_COMMON =

LNKCMD_FILE = $(STARTERWARE_ROOTDIR)/examples/$(TOOLCHAIN)/$(SOCFAMILY)_ddr.lds

# Core/SoC/platform specific source files and CFLAGS
# Example:
# SRCS_<core/SoC/platform-name> =
# CFLAGS_LOCAL_<core/SoC/platform-name> =

# Include common make files
include $(STARTERWARE_ROOTDIR)/build/makerules/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
# and need not be explicitly specified here

# Nothing beyond this point

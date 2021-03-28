#
# Copyright (c) 2016 - 2018, Texas Instruments Incorporated
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

MODULE_NAME = profiling

SRCDIR = . src
INCDIR = . src

# Common source files across all platforms and cores
ifeq ($(CORE),$(filter $(CORE), mpu1_0))
  SRCS_COMMON += profilingHooksArmV8.c
else ifeq ($(CORE),$(filter $(CORE), mcu1_0))
  SRCS_COMMON += profilingHooksR5.c
else ifeq ($(CORE),$(filter $(CORE), a15_0 a9host a8host))
  SRCS_COMMON += profilingHooksArmV7_A.c
  SRCS_ASM_COMMON += profilingHooksArmV7_AAssembly.asm
else ifeq ($(CORE),$(filter $(CORE), c66x))
  SRCS_COMMON += profilingHooksC66.c
else
  SRCS_COMMON += profilingHooksM4.c
endif

ifeq ($(CORE),$(filter $(CORE), mpu1_0 a15_0 a9host a8host))
  CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) -finstrument-functions -gdwarf-3 -g -D_ENABLE_BM
else
  CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) --entry_parm=address --exit_hook=ti_utils_exit --exit_parm=address --entry_hook=ti_utils_entry -g -D_ENABLE_BM
endif

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk edma
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCLUDE_EXTERNAL_INTERFACES += csl
endif

PACKAGE_SRCS_COMMON = makefile profilingHooks.h profiling_component.mk profiling_osal.h \
                      docs/ReleaseNotes_Utils.pdf src build/makefile_profile.mk \

# Including trace modules here, as trace do not have source files and packaging
PACKAGE_SRCS_COMMON += ../trace

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

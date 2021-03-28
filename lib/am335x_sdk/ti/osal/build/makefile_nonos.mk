#
# Copyright (c) 2016, Texas Instruments Incorporated
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
include $(PDK_OSAL_COMP_PATH)/src/src_common_nonos.mk

MODULE_NAME = osal_nonos

MUXINTCP = src/nonos/muxintcp
TIMER    = src/nonos/timer
COUNTER_32K = src/nonos/counter_32k
DELAY    = src/nonos/delay

ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x am571x am572x am574x tda3xx dra78x am437x am335x am65xx j721e j7200))
  SRCDIR += $(TIMER)/v1
  INCDIR += $(TIMER)/v1
  PACKAGE_SRCS_COMMON += $(TIMER)/v1
endif
ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x am571x am572x am574x tda3xx dra78x am437x am335x))
  SRCDIR += $(MUXINTCP)/v1
  INCDIR += $(MUXINTCP)/v1
  PACKAGE_SRCS_COMMON += $(MUXINTCP)/v1
  SRCS_COMMON += MuxIntcP_nonos.c
endif

ifeq ($(SOC),$(filter $(SOC), am571x am572x am574x dra72x dra75x dra78x))
  SRCDIR += $(COUNTER_32K)/v0 $(DELAY)/v2
  INCDIR += $(COUNTER_32K)/v0 $(DELAY)/v2
  SRCS_COMMON += counter_32k.c
  PACKAGE_SRCS_COMMON += $(COUNTER_32K)/v0 $(DELAY)/v2
endif

ifeq ($(SOC),$(filter $(SOC), am335x am437x))
  SRCDIR += $(DELAY)/v1
  INCDIR += $(DELAY)/v1
  PACKAGE_SRCS_COMMON += $(DELAY)/v1
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
  SRCDIR += $(DELAY)/v4
  INCDIR += $(DELAY)/v4
  PACKAGE_SRCS_COMMON += $(DELAY)/v4
endif

ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l k2e k2g c6678 c6657))
  SRCDIR += $(MUXINTCP)/v0 $(TIMER)/v0 $(DELAY)/v0
  INCDIR += $(MUXINTCP)/v0 $(TIMER)/v0 $(DELAY)/v0
  PACKAGE_SRCS_COMMON += $(MUXINTCP)/v0 $(TIMER)/v0 $(DELAY)/v0
  SRCS_COMMON += MuxIntcP_nonos.c
endif
ifeq ($(SOC),$(filter $(SOC), omapl137 omapl138 c6747))
  SRCDIR += $(MUXINTCP)/v1 $(DELAY)/v3 $(TIMER)/v0
  INCDIR += $(MUXINTCP)/v1 $(TIMER)/v0
  PACKAGE_SRCS_COMMON += $(MUXINTCP)/v1 $(DELAY)/v3 $(TIMER)/v0
  SRCS_COMMON += MuxIntcP_nonos.c
endif

ifeq ($(SOC),$(filter $(SOC), tpr12))
  SRCDIR += $(TIMER)/v2 $(DELAY)/v4
  INCDIR += $(TIMER)/v2 $(DELAY)/v4
  PACKAGE_SRCS_COMMON += $(TIMER)/v2 $(DELAY)/v4
endif


ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l k2e k2g c6678 c6657 dra72x dra75x dra78x am571x am572x am574x am437x am335x omapl137 omapl138 c6747 am65xx j721e j7200 tpr12))
SRCS_COMMON += TimerP_nonos.c delay.c
endif


# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk

CFLAGS_LOCAL_COMMON += $(PDK_CFLAGS)

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

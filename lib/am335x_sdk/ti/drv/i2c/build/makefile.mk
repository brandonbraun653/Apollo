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

MODULE_NAME = i2c
ifeq ($(ICSS0_FW), yes)
    MODULE_NAME = i2c_icss0
endif

include $(PDK_I2C_COMP_PATH)/src/src_files_common.mk

ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra72x dra75x tda2ex am571x am572x am574x tda3xx dra78x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138 am65xx j721e j7200))
SRCDIR += soc/$(SOC)
INCDIR += soc
# Common source files across all platforms and cores
SRCS_COMMON += I2C_soc.c
endif

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk

ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra72x dra75x tda2ex am571x am572x am574x tda3xx dra78x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138 j721e j7200))
PACKAGE_SRCS_COMMON += soc/$(SOC) soc/I2C_soc.h
endif

CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

# For all FW supporting devices source files in library and package
ifeq ($(SOC),$(filter $(SOC), am574x am572x am335x am437x))
  SRCDIR += src/v2
  INCDIR += src/v2
  SRCS_COMMON += I2C_v2.c
  PACKAGE_SRCS_COMMON += src/v2 soc/I2C_v2.h
  CFLAGS_LOCAL_COMMON += -DPRU_ICSS_FW
endif

ifeq ($(SOC),$(filter $(SOC), am437x))
  ifeq ($(ICSS0_FW), yes)
    # For ICSS0
    CFLAGS_LOCAL_COMMON += -DAM437X_ICSS0
  endif
endif

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ROOTDIR)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# Nothing beyond this point

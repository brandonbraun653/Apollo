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

MODULE_NAME = nimu
CFLAGS_LOCAL_COMMON = -DNDK_NOUSERAPIS

ifeq ($(SOC),$(filter $(SOC), am571x am572x am574x am437x am335x dra72x dra75x dra78x))
include $(PDK_NIMU_COMP_PATH)/src/v4/src_files_v4.mk
endif

ifeq ($(SOC),$(filter $(SOC), k2h k2k))
include $(PDK_NIMU_COMP_PATH)/src/v2/src_files_v2.mk
endif

ifeq ($(SOC),$(filter $(SOC), k2l k2e))
include $(PDK_NIMU_COMP_PATH)/src/v3/src_files_v3.mk
CFLAGS_LOCAL_COMMON += -DNSS_GEN2 
endif

ifeq ($(SOC),$(filter $(SOC), c6657))
include $(PDK_NIMU_COMP_PATH)/src/v0/src_files_v0.mk
endif

ifeq ($(SOC),$(filter $(SOC), omapl137 omapl138))
include $(PDK_NIMU_COMP_PATH)/src/v6/src_files_v6.mk
endif

ifeq ($(SOC),$(filter $(SOC),c6678))
include $(PDK_NIMU_COMP_PATH)/src/v1/src_files_v1.mk
endif

ifeq ($(SOC),$(filter $(SOC), k2g))
include $(PDK_NIMU_COMP_PATH)/src/v5/src_files_v5.mk
CFLAGS_LOCAL_COMMON += -DNSS_LITE
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j721e))
include $(PDK_NIMU_COMP_PATH)/src/v7/src_files_v7.mk
endif

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk ndk

PACKAGE_SRCS_COMMON += makefile nimu_eth.h nimu_component.mk \
                      src/NIMU_drv_log.h src/nimu_osal.h

CFLAGS_LOCAL_COMMON += $(PDK_CFLAGS)

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ROOTDIR)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# Nothing beyond this point

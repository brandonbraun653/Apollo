#
# Copyright (c) 2017, Texas Instruments Incorporated
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
include $(PDK_MCASP_COMP_PATH)/src/src_files_common.mk

MODULE_NAME = mcasp_profile

ifeq ($(SOC),$(filter $(SOC), am571x am572x am574x dra72x dra75x dra78x k2g am437x omapl137 omapl138 am65xx))
SRCDIR += soc/$(SOC)
INCDIR += soc
# Common source files across all platforms and cores
  SRCS_COMMON += mcasp_soc.c
endif

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk
                      

ifeq ($(SOC),$(filter $(SOC),  am571x am572x am574x dra72x dra72x dra75x dra78x k2g am437x omapl137 omapl138 am65xx))
endif


ifeq ($(BUILDTYPE),$(filter $(BUILDTYPE), profile profiledma))
  ifeq ($(CORE),$(filter $(CORE), a15_0 a9host a8host mpu1_0))
    CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) -finstrument-functions -gdwarf-3 -g -D_ENABLE_BM
  else
    CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) --entry_parm=address --exit_hook=ti_utils_exit --exit_parm=address --entry_hook=ti_utils_entry -g -D_ENABLE_BM
  endif
endif


ifeq ($(SOC),$(filter $(SOC), am571x am572x am574x dra72x dra72x dra75x dra78x k2g am437x am335x omapl137 omapl138))
CFLAGS_LOCAL_COMMON += -DMcasp_LOOPJOB_ENABLED -DMCASP_EDMA_ENABLED
INCLUDE_EXTERNAL_INTERFACES += edma
endif


ifeq ($(SOC),$(filter $(SOC),am65xx))
CFLAGS_LOCAL_COMMON += -DMCASP_UDMA_ENABLED
endif

ifeq ($(CORE),$(filter $(CORE), c66x c674x))
CFLAGS_LOCAL_COMMON += -DBUILD_DSP
endif
# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ROOTDIR)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# Nothing beyond this point

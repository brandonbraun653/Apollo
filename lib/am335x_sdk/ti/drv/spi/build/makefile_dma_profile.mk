#
# Copyright (c) 2017 - 2020, Texas Instruments Incorporated
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
include $(PDK_SPI_COMP_PATH)/src/src_files_common.mk

MODULE_NAME = spi_dma_profile

ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra72x dra75x tda2ex am571x am572x am574x tda3xx dra78x am437x am335x k2h k2k k2l k2e k2g c6678 c6657 omapl137 omapl138 am65xx j721e j7200))
SRCDIR += soc/$(SOC)

ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l k2e k2g c6678 c6657 omapl137 omapl138))
    SRCDIR += soc/dma/v0
else
ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra72x dra75x tda2ex am571x am572x am574x tda3xx dra78x am437x am335x))
    SRCDIR += soc/dma/v1
else
    SRCDIR += soc/dma/v2
endif
endif

INCDIR += soc
SRCS_COMMON += SPI_soc.c SPI_dma.c
ifeq ($(SOC),$(filter $(SOC), am65xx j721e))
SRCS_COMMON += OSPI_dma.c
endif

ifeq ($(SOC),$(filter $(SOC), am571x am572x am574x am437x am335x))
SRCS_COMMON += QSPI_dma.c
endif
endif

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra72x dra75x tda2ex am571x am572x am574x tda3xx dra78x am437x am335x k2h k2k k2l k2e k2g c6678 c6657 omapl137 omapl138))
INCLUDE_EXTERNAL_INTERFACES = pdk edma
else
INCLUDE_EXTERNAL_INTERFACES = pdk
endif

ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra72x dra75x tda2ex am571x am572x am574x tda3xx dra78x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138 am65xx j721e j7200))
PACKAGE_SRCS_COMMON += soc/$(SOC) soc/SPI_soc.h
ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l k2e k2g c6678 c6657 omapl137 omapl138))
    PACKAGE_SRCS_COMMON += soc/dma/v0
else
ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra72x dra75x tda2ex am571x am572x am574x tda3xx dra78x am437x am335x))
    PACKAGE_SRCS_COMMON += soc/dma/v1
else
    PACKAGE_SRCS_COMMON += soc/dma/v2
endif
endif
endif

ifeq ($(CORE),$(filter $(CORE), mpu1_0 a15_0 a9host a8host))
  CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) -finstrument-functions -gdwarf-3 -g -D_ENABLE_BM -DSPI_DMA_ENABLE
else
  CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) --entry_parm=address --exit_hook=ti_utils_exit --exit_parm=address --entry_hook=ti_utils_entry -g -D_ENABLE_BM -DSPI_DMA_ENABLE
endif

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ROOTDIR)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# Nothing beyond this point

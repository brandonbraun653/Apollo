#
# Copyright (c) 2016 - 2020, Texas Instruments Incorporated
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
SOC_INDP_LIB_SOCS=k2h k2k k2l k2e k2g c6657 c6678 omapl137 omapl138 am571x am572x am574x  am335x am437x 
SOC_DEP_LIB_SOCS=tda2xx tda3xx tda2px dra75x tda2ex dra72x dra78x j721e am77x j7200 am65xx

PACKAGE_SRCS_COMMON = makefile SPI.h MCSPI.h spi_component.mk .gitignore \
                      docs/ReleaseNotes_SPI_LLD.pdf \
                      src/SPI_drv.c src/SPI_osal.h src/src_files_common.mk \
                      build/makefile.mk build/makefile_profile.mk \
                      build/makefile_indp.mk build/makefile_profile_indp.mk \
                      build/makefile_dma.mk build/makefile_dma_profile.mk


ifeq ($(SOC),$(filter $(SOC), $(SOC_INDP_LIB_SOCS) ))
  # All src/v1 files
  SRCDIR = . src src/v1
  INCDIR = . src src/v1
  SRCS_COMMON += SPI_drv.c SPI_v1.c QSPI_v1.c
  PACKAGE_SRCS_COMMON += src/v1

  # All src/v0 files
  SRCDIR += src/v0
  INCDIR += src/v0
  SRCS_COMMON += SPI_v0.c OSPI_v0.c QSPI_v0.c
  PACKAGE_SRCS_COMMON += src/v0

  # All src/v2 files
ifeq ($(SOC),$(filter $(SOC), am335x, am437x))
  SRCDIR += src/v2
  INCDIR += src/v2
  SRCS_COMMON += ESPI_v2.c
  PACKAGE_SRCS_COMMON += src/v2  build/makefile_icss_espi.mk
endif

endif


ifeq ($(SOC),$(filter $(SOC),$(SOC_DEP_LIB_SOCS) ))
  # TDA & J7 targets include SPI_V1, QSPI_V1(for Sitara) , OSPI_V1(For J7)
  SRCDIR = . src src/v1
  INCDIR = . src src/v1
  SRCS_COMMON += SPI_drv.c SPI_v1.c
  PACKAGE_SRCS_COMMON += src/v1/SPI_v1.c soc/SPI_v1.h

  ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x tda3xx dra78x))
     SRCS_COMMON += QSPI_v1.c
     PACKAGE_SRCS_COMMON += src/v1/QSPI_v1.c soc/QSPI_v1.h 
  endif

  ifeq ($(SOC),$(filter $(SOC), j721e am77x j7200 am65xx))
    SRCDIR += src/v0
    INCDIR += src/v0
    SRCS_COMMON += OSPI_v0.c
    PACKAGE_SRCS_COMMON += src/v0/OSPI_v0.c src/v0/OSPI_v0.h
  endif
  
endif


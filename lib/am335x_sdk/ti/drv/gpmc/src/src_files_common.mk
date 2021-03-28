#
# This file is the makefile for building GPMC RTOS library.
#
#   Copyright (c) Texas Instruments Incorporated 2016
#

SRCDIR = . src src/V1
INCDIR = . src src/V1
# Common source files across all platforms and cores
  SRCS_COMMON += GPMC_drv.c GPMC_v1.c

PACKAGE_SRCS_COMMON = GPMC.h makefile gpmc_component.mk \
                      docs/ReleaseNotes_GPMC_LLD.pdf \
                      docs/GPMC_LLD_SoftwareManifest.html \
                      src/GPMC_osal.h src/V1/GPMC_v1.h src/src_files_common.mk \
                      build/makefile.mk build/makefile_indp.mk \
                      build/makefile_profile.mk build/makefile_profile_indp.mk



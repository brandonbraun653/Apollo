
SRCDIR = . src
INCDIR = . src

ifeq ($(SOC),$(filter $(SOC),am574x am572x am571x k2g am437x am335x dra72x dra75x dra78x omapl137 omapl138))
  # EDMA
  SRCDIR += src/dma/V0
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j721e))
  # NavSS
  SRCDIR += src/dma/V1
endif

# Common source files across all platforms and cores
SRCS_COMMON += mcasp_drv.c mcasp_ioctl.c mcasp_dma.c

PACKAGE_SRCS_COMMON = makefile mcasp_component.mk \
                      build/makefile.mk build/makefile_profile.mk src/src_files_common.mk \
                      mcasp_osal.h mcasp_drv.h mcasp_types.h include/McaspLocal.h soc/mcasp_soc.h \
                      soc/$(SOC) $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.c)) \
                      docs/ReleaseNotes_MCASP_LLD.pdf


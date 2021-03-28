
ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x am571x am572x am574x tda3xx am335x am437x dra78x am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_mcspi.h csl_mcspi.h src/ip/mcspi/src_files_mcspi.mk src/ip/mcspi/V0
SRCS_COMMON += mcspi.c
SRCDIR += src/ip/mcspi/V0/priv
INCDIR += . src/ip/mcspi/V0
endif

ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l k2e k2g c6657 c6678 omapl137 omapl138 tpr12))
PACKAGE_SRCS_COMMON += cslr_spi.h src/ip/mcspi/src_files_mcspi.mk src/ip/mcspi/V1
SRCS_COMMON += spi.c
SRCDIR += src/ip/mcspi/V1/priv
ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l k2e k2g c6657 c6678 omapl137 omapl138))
  INCDIR += . src/ip/mcspi/V1_0
else
  INCDIR += . src/ip/mcspi/V1_1
endif
endif

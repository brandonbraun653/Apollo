
ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x tda2px))
PACKAGE_SRCS_COMMON += cslr_mcan.h csl_mcan.h src/ip/mcan/mcan.h src/ip/mcan/src_files_mcan.mk src/ip/mcan/V0
SRCDIR += src/ip/mcan/V0
INCDIR += src/ip/mcan/V0
SRCS_COMMON += mcan.c
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
  ifneq ($(CORE),$(filter $(CORE), c7x-hostemu))
    PACKAGE_SRCS_COMMON += cslr_mcan.h csl_mcan.h src/ip/mcan/mcan.h src/ip/mcan/src_files_mcan.mk src/ip/mcan/V1
    SRCDIR += src/ip/mcan/V1
    INCDIR += src/ip/mcan/V1/V1_0
    SRCS_COMMON += mcan.c
  endif
endif

ifeq ($(SOC),$(filter $(SOC), tpr12))
  PACKAGE_SRCS_COMMON += cslr_mcan.h csl_mcan.h src/ip/mcan/mcan.h src/ip/mcan/src_files_mcan.mk src/ip/mcan/V1
  SRCDIR += src/ip/mcan/V1
  INCDIR += src/ip/mcan/V1/V1_1
  SRCS_COMMON += mcan.c
endif

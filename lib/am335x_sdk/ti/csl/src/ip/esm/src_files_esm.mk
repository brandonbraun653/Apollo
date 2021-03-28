
ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x tpr12))
PACKAGE_SRCS_COMMON += cslr_esm.h csl_esm.h src/ip/esm/src_files_esm.mk src/ip/esm/V0
SRCDIR += src/ip/esm/V0/priv
INCDIR += src/ip/esm/V0
ifeq ($(SOC),$(filter $(SOC), tpr12))
  INCDIR += src/ip/esm/V0/V0_1
endif
SRCS_COMMON += esm.c
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e))
PACKAGE_SRCS_COMMON += cslr_esm.h csl_esm.h src/ip/esm/src_files_esm.mk src/ip/esm/V1
SRCDIR += src/ip/esm/V1/priv
INCDIR += src/ip/esm/V1
SRCS_COMMON += csl_esm.c
endif

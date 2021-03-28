
ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l k2e c6657))
PACKAGE_SRCS_COMMON += cslr_vcp2.h  csl_vcp2Aux.h  csl_vcp2.h
endif

ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l k2e))

PACKAGE_SRCS_COMMON += src/ip/vcp2/src_files_vcp2.mk src/ip/vcp2/V0
SRCDIR += src/ip/vcp2/V0
INCDIR += . src/ip/vcp2/V0

ifeq ($(CORE),$(filter $(CORE), c66x))
SRCS_COMMON += csl_vcp2.c
endif

endif

ifeq ($(SOC),$(filter $(SOC), c6657))

PACKAGE_SRCS_COMMON += src/ip/vcp2/src_files_vcp2.mk src/ip/vcp2/V1
SRCDIR += src/ip/vcp2/V1
INCDIR += . src/ip/vcp2/V1

ifeq ($(CORE),$(filter $(CORE), c66x))
SRCS_COMMON += csl_vcp2.c
endif

endif

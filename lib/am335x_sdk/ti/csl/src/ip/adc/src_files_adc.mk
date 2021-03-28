ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x am65xx j7200 j721e))
PACKAGE_SRCS_COMMON += cslr_adc.h csl_adc.h src/ip/adc/src_files_adc.mk src/ip/adc/V0/adc.h src/ip/adc/V0/priv

SRCS_COMMON += adc.c
SRCDIR += src/ip/adc/V0/priv
INCDIR += .
endif

ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x))
PACKAGE_SRCS_COMMON += src/ip/adc/V0/V0_0
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e))
PACKAGE_SRCS_COMMON += src/ip/adc/V0/V0_1
endif


ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x tda3xx dra78x am574x))
PACKAGE_SRCS_COMMON += cslr_emif.h csl_emif.h src/ip/emif/src_files_emif.mk
PACKAGE_SRCS_COMMON += src/ip/emif/V0/emif.h src/ip/emif/V0/priv
SRCDIR += src/ip/emif/V0/priv
INCDIR += src/ip/emif/V0
SRCS_COMMON += emif.c
endif

ifeq ($(SOC),$(filter $(SOC), tda2xx dra75x tda2ex dra72x am574x))
PACKAGE_SRCS_COMMON += src/ip/emif/V0/V0_0
INCDIR += src/ip/emif/V0/V0_0
endif

ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x))
PACKAGE_SRCS_COMMON += src/ip/emif/V0/V0_1
INCDIR += src/ip/emif/V0/V0_1
endif

ifeq ($(SOC),$(filter $(SOC), tda2px))
PACKAGE_SRCS_COMMON += src/ip/emif/V0/V0_2
INCDIR += src/ip/emif/V0/V0_2
endif

ifeq ($(SOC),$(filter $(SOC), am65xx))
PACKAGE_SRCS_COMMON += cslr_emif.h csl_emif.h src/ip/emif/src_files_emif.mk src/ip/emif/V1
SRCDIR += src/ip/emif/V1/priv
INCDIR += src/ip/emif/V1
SRCS_COMMON += csl_emif.c
endif

ifeq ($(SOC),$(filter $(SOC), j721e))
PACKAGE_SRCS_COMMON += cslr_emif.h csl_emif.h src/ip/emif/src_files_emif.mk src/ip/emif/V2
SRCDIR += src/ip/emif/V2/priv
INCDIR += src/ip/emif/V2
SRCS_COMMON += csl_emif.c
endif

ifeq ($(SOC),$(filter $(SOC), j7200))
PACKAGE_SRCS_COMMON += cslr_emif.h csl_emif.h src/ip/emif/src_files_emif.mk src/ip/emif/V3 src/ip/emif/V2
SRCDIR += src/ip/emif/V2/priv
INCDIR += src/ip/emif/V2
SRCS_COMMON += csl_emif.c
endif


ifeq ($(SOC),$(filter $(SOC), am65xx j721e am77x))
PACKAGE_SRCS_COMMON += cslr_dru.h csl_dru.h src/ip/dru/src_files_dru.mk src/ip/dru/V0
SRCDIR += src/ip/dru/V0/priv
INCDIR += src/ip/dru/V0
SRCS_COMMON += csl_dru.c
endif

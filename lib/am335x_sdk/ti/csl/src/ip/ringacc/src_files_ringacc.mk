
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_ringacc.h csl_ringacc.h src/ip/ringacc/src_files_ringacc.mk src/ip/ringacc/V0
SRCDIR += src/ip/ringacc/V0/priv
INCDIR += src/ip/ringacc/V0
SRCS_COMMON += csl_ringacc.c
endif


ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_pbist.h src/ip/pbist/src_files_pbist.mk src/ip/pbist/V0
SRCDIR += src/ip/pbist/V0/priv
INCDIR += src/ip/pbist/V0
endif

ifeq ($(SOC),$(filter $(SOC), j721e))
PACKAGE_SRCS_COMMON += csl_pbist.h
SRCS_COMMON += csl_pbist.c
endif

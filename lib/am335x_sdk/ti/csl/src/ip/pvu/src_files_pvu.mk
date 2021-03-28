
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_pvu.h csl_pvu.h src/ip/pvu/src_files_pvu.mk src/ip/pvu/V0
SRCDIR += src/ip/pvu/V0/priv
INCDIR += src/ip/pvu/V0
SRCS_COMMON += csl_pvu.c
endif

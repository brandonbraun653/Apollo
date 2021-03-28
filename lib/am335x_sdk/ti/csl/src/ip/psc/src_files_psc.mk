
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_psc.h csl_psc.h src/ip/psc/src_files_psc.mk src/ip/psc/V2
SRCDIR += src/ip/psc/V2/priv
INCDIR += src/ip/psc/V2
SRCS_COMMON += csl_psc.c
endif

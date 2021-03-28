
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_clec.h csl_clec.h src/ip/clec/src_files_clec.mk src/ip/clec/V0
SRCDIR += src/ip/clec/V0/priv
INCDIR += src/ip/clec/V0
SRCS_COMMON += csl_clec.c
endif

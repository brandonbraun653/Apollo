
ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x am65xx j7200 j721e am77x tpr12))
PACKAGE_SRCS_COMMON += cslr_dcc.h csl_dcc.h src/ip/dcc/src_files_dcc.mk src/ip/dcc/V0
SRCDIR += src/ip/dcc/V0/priv
INCDIR += src/ip/dcc/V0
SRCS_COMMON += dcc.c
endif

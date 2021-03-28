
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_ecc_aggr.h csl_ecc_aggr.h src/ip/ecc_aggr/src_files_ecc_aggr.mk src/ip/ecc_aggr/V1
SRCDIR += src/ip/ecc_aggr/V1/priv
INCDIR += src/ip/ecc_aggr/V1
SRCS_COMMON += csl_ecc_aggr.c
endif

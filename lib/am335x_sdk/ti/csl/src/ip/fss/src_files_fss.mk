
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x ))
PACKAGE_SRCS_COMMON += cslr_fss.h csl_fss.h src/ip/fss/src_files_fss.mk src/ip/fss/V0
SRCDIR += src/ip/fss/V0/priv
INCDIR += src/ip/fss/V0
SRCS_COMMON += csl_fss.c
endif

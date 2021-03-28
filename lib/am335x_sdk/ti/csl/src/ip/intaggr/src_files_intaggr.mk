
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_intaggr.h csl_intaggr.h src/ip/intaggr/src_files_intaggr.mk src/ip/intaggr/V0
SRCDIR += src/ip/intaggr/V0/priv
INCDIR += src/ip/intaggr/V0
SRCS_COMMON += csl_intaggr.c
endif

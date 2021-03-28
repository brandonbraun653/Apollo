
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_hyperbus.h csl_hyperbus.h src/ip/hyperbus/src_files_hyperbus.mk src/ip/hyperbus/V0
SRCDIR += src/ip/hyperbus/V0/priv
INCDIR += src/ip/hyperbus/V0
SRCS_COMMON += csl_hyperbus.c
endif

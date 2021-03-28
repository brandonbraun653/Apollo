
ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l))

PACKAGE_SRCS_COMMON += cslr_srio.h  csl_serdes_srio.h  csl_srioAux.h  csl_srioAuxPhyLayer.h  csl_srio.h
PACKAGE_SRCS_COMMON += src/ip/srio/src_files_srio.mk src/ip/srio/V0

SRCS_COMMON += cslr_srio_resetread.c

SRCDIR += src/ip/srio/V0
INCDIR += . src/ip/srio/V0
endif


ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l k2e k2g))

PACKAGE_SRCS_COMMON += cslr_usimocp.h
PACKAGE_SRCS_COMMON += src/ip/usim/src_files_usim.mk src/ip/usim/V0
SRCDIR += src/ip/usim/V0
INCDIR += . src/ip/usim/V0
SRCS_COMMON += cslr_usimocp_resetread.c
endif

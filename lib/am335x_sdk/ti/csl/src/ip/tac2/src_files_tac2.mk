ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l))
PACKAGE_SRCS_COMMON += cslr_tac2_cfg.h  cslr_tac2_data.h  cslr_tac2_sgcp_cfg.h  csl_tac2.h
endif

ifeq ($(SOC),$(filter $(SOC), k2h k2k))

PACKAGE_SRCS_COMMON += src/ip/tac2/V0/cslr_tac2_cfg.h src/ip/tac2/V0/cslr_tac2_data.h
PACKAGE_SRCS_COMMON += src/ip/tac2/V0/cslr_tac2_sgcp_cfg.h
PACKAGE_SRCS_COMMON += src/ip/tac2/V0/csl_tac2_regsBEAux.h  src/ip/tac2/V0/csl_tac2_regsFEAux.h
PACKAGE_SRCS_COMMON += src/ip/tac2/V0/csl_tac2_regs.h  src/ip/tac2/V0/csl_tac2_regsSGCPAux.h
PACKAGE_SRCS_COMMON += src/ip/tac2/src_files_tac2.mk src/ip/tac2/V0
SRCS_COMMON += csl_tac2_regsBEAux.c  csl_tac2_regsFEAux.c  csl_tac2_regsSGCPAux.c
SRCDIR += src/ip/tac2/V0
INCDIR += . src/ip/tac2/V0

endif

ifeq ($(SOC),$(filter $(SOC), k2l))

PACKAGE_SRCS_COMMON += src/ip/tac2/V1/cslr_tac2_cfg.h  src/ip/tac2/V1/cslr_tac2_data.h
PACKAGE_SRCS_COMMON += src/ip/tac2/V1/cslr_tac2_sgcp_cfg.h
PACKAGE_SRCS_COMMON += src/ip/tac2/src_files_tac2.mk src/ip/tac2/V1

SRCS_COMMON += csl_tac2_regsBEAux.c  csl_tac2_regsFEAux.c  csl_tac2_regsSGCPAux.c

SRCDIR += src/ip/tac2/V1
INCDIR += . src/ip/tac2/V1

endif
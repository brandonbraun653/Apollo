
ifeq ($(SOC),$(filter $(SOC), am571x am572x k2h k2k k2l k2e k2g c6678 c6657 am574x omapl137 c6747 omapl138 j7200 j721e tpr12))
PACKAGE_SRCS_COMMON += src/ip/tsc/V0 src/ip/tsc/src_files_tsc.mk csl_tsc.h
SRCDIR += src/ip/tsc/V0
INCDIR += src/ip/tsc/V0

ifeq ($(CORE),$(filter $(CORE), c66x c674x c66xdsp_1 c66xdsp_2))
SRCS_ASM_COMMON += csl_tsc.asm
INCDIR += . src/ip/tsc/V0
endif

endif


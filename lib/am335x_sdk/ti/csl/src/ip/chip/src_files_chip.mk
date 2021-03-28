
ifeq ($(SOC),$(filter $(SOC), am571x am572x am574x dra72x dra75x dra78x k2h k2k k2l k2e k2g c6678 c6657 omapl137 omapl138 j7200 j721e am65xx tpr12))
PACKAGE_SRCS_COMMON += src/ip/chip/V0 csl_chip.h cslr_chip.h csl_chipAux.h src/ip/chip/src_files_chip.mk
SRCDIR += src/ip/chip/V0
INCDIR += src/ip/chip/V0

ifeq ($(CORE),$(filter $(CORE), c66x c66xdsp_1 c66xdsp_2 c674x))
SRCS_COMMON += csl_chip.c
INCDIR += . src/ip/chip/V0
endif

endif


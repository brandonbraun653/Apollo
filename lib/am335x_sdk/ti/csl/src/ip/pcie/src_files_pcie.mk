
ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x am571x am572x am574x))
PACKAGE_SRCS_COMMON += cslr_pcie.h csl_pcie.h src/ip/pcie/src_files_pcie.mk src/ip/pcie/V1
SRCDIR += src/ip/pcie/V1/priv
INCDIR += . src/ip/pcie/V1
SRCS_$(SOC) += pcie.c
endif

ifeq ($(SOC),$(filter $(SOC), am65xx))
PACKAGE_SRCS_COMMON += cslr_pcie.h src/ip/pcie/src_files_pcie.mk src/ip/pcie/V2
INCDIR += . src/ip/pcie/V2
endif

ifeq ($(SOC),$(filter $(SOC), j721e am77x))
PACKAGE_SRCS_COMMON += cslr_pcie.h src/ip/pcie/src_files_pcie.mk src/ip/pcie/V3
INCDIR += . src/ip/pcie/V3
endif

ifeq ($(SOC),$(filter $(SOC), j7200))
PACKAGE_SRCS_COMMON += cslr_pcie.h src/ip/pcie/src_files_pcie.mk src/ip/pcie/V4
INCDIR += . src/ip/pcie/V4
endif

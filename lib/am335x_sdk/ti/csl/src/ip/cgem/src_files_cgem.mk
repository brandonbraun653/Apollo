
ifeq ($(SOC),$(filter $(SOC), j7200 j721e))
PACKAGE_SRCS_COMMON += cslr_cgem.h src/ip/cgem/src_files_cgem.mk src/ip/cgem/V1
endif

ifeq ($(SOC),$(filter $(SOC), tpr12))
PACKAGE_SRCS_COMMON += cslr_cgem.h src/ip/cgem/src_files_cgem.mk src/ip/cgem/V0
endif

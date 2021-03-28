
ifeq ($(SOC),$(filter $(SOC), j7200 j721e am77x tpr12))
PACKAGE_SRCS_COMMON += cslr_atl.h src/ip/atl/src_files_atl.mk src/ip/atl/V0
INCDIR += src/ip/atl/V0
endif

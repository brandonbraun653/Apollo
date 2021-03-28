
ifeq ($(SOC),$(filter $(SOC), j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_vpfe.h src/ip/vpfe/src_files_vpfe.mk src/ip/vpfe/V0
INCDIR += src/ip/vpfe/V0
endif

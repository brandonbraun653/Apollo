
ifeq ($(SOC),$(filter $(SOC), j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_vpac.h src/ip/vpac/src_files_vpac.mk src/ip/vpac/V0
INCDIR += src/ip/vpac/V0
endif

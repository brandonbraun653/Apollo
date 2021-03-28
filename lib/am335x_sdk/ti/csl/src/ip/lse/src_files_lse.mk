
ifeq ($(SOC),$(filter $(SOC), j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_lse.h src/ip/lse/src_files_lse.mk src/ip/lse/V0
INCDIR += src/ip/lse/V0
endif

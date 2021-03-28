
ifeq ($(SOC),$(filter $(SOC), j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_ctset2.h src/ip/ctset2/src_files_ctset2.mk src/ip/ctset2/V0
INCDIR += src/ip/ctset2/V0
endif

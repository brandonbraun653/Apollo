
ifeq ($(SOC),$(filter $(SOC), j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_i3c.h src/ip/i3c/src_files_i3c.mk src/ip/i3c/V0
INCDIR += src/ip/i3c/V0
endif

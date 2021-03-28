
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_icss.h src/ip/icss/src_files_icss.mk src/ip/icss/V1 src/ip/icss/V2
endif

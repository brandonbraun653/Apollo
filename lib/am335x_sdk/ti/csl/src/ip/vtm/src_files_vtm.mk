
ifeq ($(SOC),$(filter $(SOC), am65xx))
PACKAGE_SRCS_COMMON += cslr_vtm.h src/ip/vtm/src_files_vtm.mk src/ip/vtm/V0
INCDIR += src/ip/vtm/V0
endif

ifeq ($(SOC),$(filter $(SOC), j7200 j721e))
PACKAGE_SRCS_COMMON += cslr_vtm.h src/ip/vtm/src_files_vtm.mk src/ip/vtm/V1
INCDIR += src/ip/vtm/V1
endif

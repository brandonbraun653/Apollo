
ifeq ($(SOC),$(filter $(SOC), j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_dmpac.h src/ip/dmpac/src_files_dmpac.mk src/ip/dmpac/V0
INCDIR += src/ip/dmpac/V0
endif

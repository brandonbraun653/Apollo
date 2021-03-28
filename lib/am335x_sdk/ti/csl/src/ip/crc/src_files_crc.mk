
ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x am65xx j7200 j721e am77x tpr12))
PACKAGE_SRCS_COMMON += cslr_crc.h csl_crc.h src/ip/crc/src_files_crc.mk src/ip/crc/V0
SRCDIR += src/ip/crc/V0/priv
INCDIR += src/ip/crc/V0
SRCS_COMMON += crc.c
endif


ifeq ($(SOC),$(filter $(SOC), k2g))
PACKAGE_SRCS_COMMON += cslr_emif4f.h csl_emif4f.h csl_emif4fAux.h src/ip/emif4/src_files_emif4f.mk
PACKAGE_SRCS_COMMON += src/ip/emif4/V1/priv
SRCDIR += src/ip/emif4/V1/priv
INCDIR += src/ip/emif4/V1
SRCS_COMMON += emif4f.c
endif

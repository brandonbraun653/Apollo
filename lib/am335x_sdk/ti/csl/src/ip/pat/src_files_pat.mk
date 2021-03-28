
ifeq ($(SOC),$(filter $(SOC), j7200 am77x))
PACKAGE_SRCS_COMMON += cslr_pat.h csl_pat.h src/ip/pat/src_files_pat.mk src/ip/pat/V0
SRCDIR += src/ip/pat/V0/priv
INCDIR += src/ip/pat/V0
SRCS_COMMON += csl_pat.c
endif

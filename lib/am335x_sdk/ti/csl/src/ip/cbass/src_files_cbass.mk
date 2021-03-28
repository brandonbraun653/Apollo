
ifeq ($(SOC),$(filter $(SOC), am65xx))
PACKAGE_SRCS_COMMON += cslr_cbass.h csl_cbass.h src/ip/cbass/src_files_cbass.mk
PACKAGE_SRCS_COMMON += src/ip/cbass/V0/priv/csl_cbass_error.c
PACKAGE_SRCS_COMMON += src/ip/cbass/V0/priv/csl_cbass_qos.c
PACKAGE_SRCS_COMMON += src/ip/cbass/V0/csl_cbass.h
PACKAGE_SRCS_COMMON += src/ip/cbass/V0/csl_cbass_error.h
PACKAGE_SRCS_COMMON += src/ip/cbass/V0/csl_cbass_qos.h
PACKAGE_SRCS_COMMON += src/ip/cbass/V0/cslr_cbass.h

SRCDIR += src/ip/cbass/V0/priv
INCDIR += src/ip/cbass/V0
SRCS_COMMON += csl_cbass_qos.c csl_cbass_error.c
endif

ifeq ($(SOC),$(filter $(SOC), j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_cbass.h csl_cbass.h csl_fw.h src/ip/cbass/src_files_cbass.mk src/ip/cbass/V0/V0_1
PACKAGE_SRCS_COMMON += src/ip/cbass/V0/csl_cbass.h
PACKAGE_SRCS_COMMON += src/ip/cbass/V0/csl_cbass_error.h
PACKAGE_SRCS_COMMON += src/ip/cbass/V0/csl_cbass_qos.h
PACKAGE_SRCS_COMMON += src/ip/cbass/V0/cslr_cbass.h
SRCDIR += src/ip/cbass/V0/V0_1/priv
INCDIR += src/ip/cbass/V0/V0_1
SRCS_COMMON += csl_fw.c
endif

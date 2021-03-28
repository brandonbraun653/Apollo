
ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px am572x am574x dra75x tda2ex dra72x am571x tda3xx dra78x am65xx j7200 j721e))
PACKAGE_SRCS_COMMON += cslr_dss.h csl_dss.h src/ip/dss/src_files_dss.mk
endif

ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px am572x am574x dra75x tda2ex dra72x am571x))
PACKAGE_SRCS_COMMON += src/ip/dss/V1
endif

ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x))
PACKAGE_SRCS_COMMON += src/ip/dss/V2
endif

ifeq ($(SOC),$(filter $(SOC), am65xx))
PACKAGE_SRCS_COMMON += src/ip/dss/V3
PACKAGE_SRCS_COMMON += csl_fvid2_dataTypes.h
SRCDIR += src/ip/dss/V3/priv
INCDIR += src/ip/dss/V3
SRCS_COMMON += csl_dssCommon.c csl_dssVideoPipe.c csl_dssOverlay.c csl_dssVideoPort.c
endif

ifeq ($(SOC),$(filter $(SOC), j7200 j721e))
PACKAGE_SRCS_COMMON += src/ip/dss/V4
PACKAGE_SRCS_COMMON += csl_fvid2_dataTypes.h
SRCDIR += src/ip/dss/V4/priv
INCDIR += src/ip/dss/V4
SRCS_COMMON += csl_dssCommon.c csl_dssVideoPipe.c csl_dssWbPipe.c csl_dssOverlay.c csl_dssVideoPort.c
endif

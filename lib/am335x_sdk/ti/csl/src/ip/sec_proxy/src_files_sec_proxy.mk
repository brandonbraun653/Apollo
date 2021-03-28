
ifeq ($(SOC),$(filter $(SOC), am65xx j721e am77x j7200))
PACKAGE_SRCS_COMMON += cslr_sec_proxy.h csl_sec_proxy.h src/ip/sec_proxy/src_files_sec_proxy.mk src/ip/sec_proxy/V0
SRCDIR += src/ip/sec_proxy/V0/priv
SRCS_COMMON += csl_sec_proxy.c
INCDIR += src/ip/sec_proxy/V0 
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j721e am77x))
PACKAGE_SRCS_COMMON += src/ip/sec_proxy/V0/V0_0
INCDIR += src/ip/sec_proxy/V0/V0_0
endif

ifeq ($(SOC),$(filter $(SOC), j7200))
PACKAGE_SRCS_COMMON += src/ip/sec_proxy/V0/V0_1
INCDIR += src/ip/sec_proxy/V0/V0_1
endif

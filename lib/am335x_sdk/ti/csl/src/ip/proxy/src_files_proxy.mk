
ifeq ($(SOC),$(filter $(SOC), am65xx j721e am77x j7200))
PACKAGE_SRCS_COMMON += cslr_proxy.h csl_proxy.h src/ip/proxy/src_files_proxy.mk src/ip/proxy/V0
SRCDIR += src/ip/proxy/V0/priv
SRCS_COMMON += csl_proxy.c
INCDIR += src/ip/proxy/V0 
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j721e am77x))
PACKAGE_SRCS_COMMON += src/ip/proxy/V0/V0_0
INCDIR += src/ip/proxy/V0/V0_0
endif

ifeq ($(SOC),$(filter $(SOC), j7200 ))
PACKAGE_SRCS_COMMON += src/ip/proxy/V0/V0_1
INCDIR += src/ip/proxy/V0/V0_1
endif

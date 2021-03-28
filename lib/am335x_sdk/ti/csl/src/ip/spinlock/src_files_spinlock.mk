ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x am571x am572x tda3xx dra78x am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_spinlock.h csl_spinlock.h src/ip/spinlock/src_files_spinlock.mk
endif

ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x am571x am572x tda3xx dra78x am574x))
PACKAGE_SRCS_COMMON += src/ip/spinlock/V0
SRCS_COMMON += spinlock.c
SRCDIR += src/ip/spinlock/V0/priv
INCDIR += . src/ip/spinlock/V0
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += src/ip/spinlock/V1
SRCS_COMMON += csl_spinlock.c
SRCDIR += src/ip/spinlock/V1/priv
INCDIR += . src/ip/spinlock/V1
endif


ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x am571x am572x am574x tda3xx am335x am437x dra78x am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_i2c.h csl_i2c.h src/ip/i2c/src_files_i2c.mk src/ip/i2c/V2
SRCDIR += src/ip/i2c/V2/priv
INCDIR += . src/ip/i2c/V2
SRCS_COMMON += i2c.c
endif

ifeq ($(SOC),$(filter $(SOC), k2h k2e k2k k2l k2g c6657 c6678 omapl137 omapl138 tpr12))
PACKAGE_SRCS_COMMON += cslr_i2c.h csl_i2c.h src/ip/i2c/src_files_i2c.mk src/ip/i2c/V0
SRCDIR += src/ip/i2c/V0/priv
ifeq ($(SOC),$(filter $(SOC), tpr12))
  INCDIR += . src/ip/i2c/V0 src/ip/i2c/V0/V0_1
else
  INCDIR += . src/ip/i2c/V0 src/ip/i2c/V0/V0_0
endif
SRCS_COMMON += i2c.c
endif


ifeq ($(SOC),$(filter $(SOC), tda3xx tda2xx tda2px tda2ex am574x am572x am571x k2h k2e k2k k2l k2g dra78x))
PACKAGE_SRCS_COMMON += src/ip/arm_gic/src_files_arm_gic.mk
ifeq ($(ARCH),armv7a)
  SRCDIR += src/ip/arm_gic/V0
  INCDIR += src/ip/arm_gic/V0
  SRCS_ASM_COMMON += csl_a15_intr.asm
endif
endif

ifeq ($(SOC),$(filter $(SOC), am65xx am77x))
PACKAGE_SRCS_COMMON += src/ip/arm_gic/V2 src/ip/arm_gic/src_files_arm_gic.mk
PACKAGE_SRCS_COMMON += cslr_gic500.h csl_gic.h
  ifeq ($(ARCH),armv8a)
    SRCDIR += src/ip/arm_gic/V2
    SRCDIR += src/ip/arm_gic/V2/priv
    INCDIR += src/ip/arm_gic/V2
    SRCS_COMMON += csl_gic.c
  endif
endif

ifeq ($(SOC),$(filter $(SOC), j7200 j721e))
PACKAGE_SRCS_COMMON += src/ip/arm_gic/V2 src/ip/arm_gic/V3 src/ip/arm_gic/src_files_arm_gic.mk
PACKAGE_SRCS_COMMON += cslr_gic500.h csl_gic.h
  ifeq ($(ARCH),armv8a)
    SRCDIR += src/ip/arm_gic/V2
    SRCDIR += src/ip/arm_gic/V2/priv
    INCDIR += src/ip/arm_gic/V3
    SRCS_COMMON += csl_gic.c
  endif
endif

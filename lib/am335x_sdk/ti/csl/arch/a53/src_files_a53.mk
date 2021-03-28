
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e))

  PACKAGE_SRCS_COMMON += arch/a53
  ifeq ($(ARCH),armv8a)
    SRCDIR += ./arch/a53/src
    INCDIR += ./arch/a53
    SRCS_COMMON += csl_a53.c interrupt.c
    SRCS_ASM_COMMON += csl_a53v8cache.asm csl_a53v8func.asm csl_a53v8misc.asm
    #Define 64-bit mode for now. 32-bit requires make infra change
    CFLAGS_LOCAL_COMMON += -DCSL_A53_AARCH64
  endif

endif

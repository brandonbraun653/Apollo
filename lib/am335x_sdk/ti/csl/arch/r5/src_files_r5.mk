
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x tpr12))

  PACKAGE_SRCS_COMMON += arch/r5
  ifeq ($(ARCH),armv7m)
    SRCDIR += ./arch/r5/src
    INCDIR += ./arch/r5
    SRCS_ASM_COMMON += csl_arm_r5.asm
    SRCS_COMMON += interrupt.c csl_cache.c csl_r5.c
  endif

endif

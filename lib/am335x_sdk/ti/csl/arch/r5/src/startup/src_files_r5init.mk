ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x tpr12))

  PACKAGE_SRCS_COMMON += r5/src/startup
  ifeq ($(ARCH),armv7m)
    SRCDIR += r5/src/startup
    INCDIR += r5/src/startup
    INCDIR += r5
    SRCS_ASM_COMMON += boot.asm r5_startup.asm
    SRCS_COMMON += startup.c
  endif

endif

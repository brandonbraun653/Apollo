ifeq ($(SOC),$(filter $(SOC), omapl137 omapl138))

  PACKAGE_SRCS_COMMON += arm9/src/csl_arm9_startup.c arm9/src/exceptionhandler.asm arm9/src/csl_arm9_init.asm arm9/src/src_files_arm9init.mk
  ifeq ($(ARCH),armv5)
    SRCDIR += arm9/src
    INCDIR += arm9/src
    INCDIR += arm9

    SRCS_COMMON += csl_arm9_startup.c
    SRCS_ASM_COMMON += exceptionhandler.asm csl_arm9_init.asm
  endif

endif

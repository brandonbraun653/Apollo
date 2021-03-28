
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x tpr12))

  ifeq ($(ARCH),armv7m)
    SRCDIR += ./arch/r5/src
    INCDIR += ./arch/r5
    SRCS_COMMON += csl_vim.c
  endif

endif

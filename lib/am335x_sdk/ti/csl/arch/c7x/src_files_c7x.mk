ifeq ($(SOC),$(filter $(SOC), j721e j7200 am77x))
  PACKAGE_SRCS_COMMON += arch/c7x
  ifeq ($(ARCH),c71)
    SRCDIR += ./arch/c7x/src
    INCDIR += ./arch/c7x
    SRCS_ASM_COMMON += csl_c7x_asm.asm
    SRCS_ASM_COMMON += csl_c7xmisc.asm
    SRCS_ASM_COMMON += csl_c7xecr.asm
    SRCS_ASM_COMMON += c7vectors.asm
    SRCS_ASM_COMMON += c7vectors_gs.asm
    SRCS_ASM_COMMON += c7vectors_s.asm
    SRCS_ASM_COMMON += csl_c7x_events.asm
    SRCS_ASM_COMMON += int_setup.asm
    SRCS_COMMON += csl_c7x.c
  endif
endif

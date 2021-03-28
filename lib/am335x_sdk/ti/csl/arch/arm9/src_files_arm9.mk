
ifeq ($(SOC),$(filter $(SOC),omapl137 omapl138))

   PACKAGE_SRCS_COMMON += cslr_aintc.h  arch/arm9 src/ip/aintc/V0
  ifeq ($(ARCH),armv5)
    SRCDIR += ./arch/arm9/src ./arch/arm9/V0
    INCDIR += ./arch/arm9 ./arch/arm9/V0

    SRCS_COMMON += interrupt.c
    SRCS_ASM_COMMON += csl_arm9_cpu.asm csl_arm9_cp15.asm
  endif

endif

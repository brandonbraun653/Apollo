
ifeq ($(SOC),$(filter $(SOC), omapl137 omapl138))

PACKAGE_SRCS_COMMON += arch/c67x
ifeq ($(ARCH),c67x)
SRCDIR += ./arch/c67x/src
INCDIR += ./arch/c67x
SRCS_COMMON += interrupt.c
SRCS_ASM_COMMON += intvecs.asm
endif

endif

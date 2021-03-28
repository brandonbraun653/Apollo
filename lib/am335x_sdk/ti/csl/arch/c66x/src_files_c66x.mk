
ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x tda3xx am574x am572x am571x dra78x j721e tpr12))

PACKAGE_SRCS_COMMON += arch/c66x
ifeq ($(ARCH),c66x)
SRCDIR += ./arch/c66x/src
INCDIR += ./arch/c66x
SRCS_COMMON += interrupt.c
ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x tda3xx am574x am572x am571x dra78x j721e))
SRCS_COMMON += dsp_config.c
endif
ifeq ($(SOC),$(filter $(SOC), am571x am572x am574x tda2xx tda2px tda2ex tda3xx))
SRCS_COMMON += dsp_wugen.c
endif
SRCS_ASM_COMMON += intvecs.asm
ifeq ($(SOC),$(filter $(SOC), am571x am572x am574x tda2xx tda2px tda2ex tda3xx j721e tpr12))
SRCS_COMMON += dsp_ecc.c dsp_icfg.c dsp_usrSpvSupport.c
SRCS_ASM_COMMON += swenr.asm
endif
ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px tda2ex tda3xx))
SRCS_COMMON += dsp_xmc.c
endif
endif

endif

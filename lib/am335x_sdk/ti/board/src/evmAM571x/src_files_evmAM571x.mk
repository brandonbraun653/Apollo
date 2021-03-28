
SRCDIR += src/evmAM571x src/evmAM571x/device src/evmAM571x/include
INCDIR += src/evmAM571x src/evmAM571x/device src/evmAM571x/include

# Common source files across all platforms and cores
SRCS_COMMON += evmAM571x.c evmAM571x_lld_init.c evmAM571x_pinmux.c evmAM571x_clock.c evmAM571x_ddr.c evmAM571x_info.c evmAM571x_pll.c enet_phy.c

ifeq ($(CORE),$(filter $(CORE), c66x))
    SRCS_ASM_COMMON += iodelay_stack_C66.asm
endif

PACKAGE_SRCS_COMMON =   src/evmAM571x/src_files_evmAM571x.mk

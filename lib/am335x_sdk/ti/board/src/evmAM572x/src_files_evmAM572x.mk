
SRCDIR += src/evmAM572x src/evmAM572x/device src/evmAM572x/include
INCDIR += src/evmAM572x src/evmAM572x/device src/evmAM572x/include

# Common source files across all platforms and cores
SRCS_COMMON += evmAM572x.c evmAM572x_lld_init.c evmam572x_pinmux.c evmAM572x_clock.c evmAM572x_ddr.c evmAM572x_info.c evmAM572x_pll.c
SRCS_COMMON += pmic_device.c enet_phy.c boardPadDelayDevice.c boardPadDelayInit.c iodelay_config.c

ifeq ($(CORE),$(filter $(CORE), c66x))
    SRCS_ASM_COMMON += iodelay_stack_C66.asm
endif

PACKAGE_SRCS_COMMON =   src/evmAM572x/src_files_evmAM572x.mk

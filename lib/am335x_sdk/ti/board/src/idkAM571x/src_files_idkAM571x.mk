
SRCDIR += src/idkAM571x src/idkAM571x/device src/idkAM571x/include
INCDIR += src/idkAM571x src/idkAM571x/device src/idkAM571x/include

# Common source files across all platforms and cores
SRCS_COMMON += idkAM571x.c idkAM571x_lld_init.c idkAM571x_pinmux.c idkAM571x_clock.c idkAM571x_ddr.c idkAM571x_info.c idkAM571x_pll.c idkAM571x_ethernet_config.c am570x_ddr.c
SRCS_COMMON += pmic_device.c enet_phy.c boardPadDelayDevice.c boardPadDelayInit.c iodelay_config.c qspi_flash.c

ifeq ($(CORE),$(filter $(CORE), c66x))
    SRCS_ASM_COMMON += iodelay_stack_C66.asm
endif

PACKAGE_SRCS_COMMON =   src/idkAM571x/src_files_idkAM571x.mk

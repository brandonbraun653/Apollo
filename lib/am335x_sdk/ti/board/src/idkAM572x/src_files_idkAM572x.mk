
SRCDIR += src/idkAM572x src/idkAM572x/device src/idkAM572x/include
INCDIR += src/idkAM572x src/idkAM572x/device src/idkAM572x/include

# Common source files across all platforms and cores
SRCS_COMMON += idkAM572x.c idkAM572x_lld_init.c idkAM572x_pinmux.c idkAM572x_clock.c idkAM572x_ddr.c idkAM572x_info.c idkAM572x_pll.c idkAM572x_ethernet_config.c
SRCS_COMMON += pmic_device.c enet_phy.c boardPadDelayDevice.c boardPadDelayInit.c iodelay_config.c qspi_flash.c

ifeq ($(CORE),$(filter $(CORE), c66x))
    SRCS_ASM_COMMON += iodelay_stack_C66.asm
endif

PACKAGE_SRCS_COMMON =   src/idkAM572x/src_files_idkAM572x.mk

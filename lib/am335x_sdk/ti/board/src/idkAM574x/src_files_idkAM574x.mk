
SRCDIR += src/idkAM574x src/idkAM574x/device src/idkAM574x/include
INCDIR += src/idkAM574x src/idkAM574x/device src/idkAM574x/include

# Common source files across all platforms and cores
SRCS_COMMON += idkAM574x.c idkAM574x_lld_init.c idkAM574x_pinmux.c idkAM574x_clock.c idkAM574x_ddr.c idkAM574x_info.c idkAM574x_pll.c idkAM574x_ethernet_config.c
SRCS_COMMON += pmic_device.c enet_phy.c boardPadDelayDevice.c boardPadDelayInit.c iodelay_config.c qspi_flash.c

ifeq ($(CORE),$(filter $(CORE), c66x))
    SRCS_ASM_COMMON += iodelay_stack_C66.asm
endif

PACKAGE_SRCS_COMMON =   src/idkAM574x/src_files_idkAM574x.mk

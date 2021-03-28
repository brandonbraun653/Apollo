
SRCDIR += src/$(BOARD) src/evmDRA75x/pinmux src/evmAM572x/device
INCDIR += src/$(BOARD) src/evmDRA75x/pinmux src/$(BOARD)/pinmux src/$(BOARD)/include src/evmAM572x/device

# Common source files across all platforms and cores
SRCS_COMMON += $(BOARD).c evmDRA7xx_mmc.c evmDRA7xx_pinmux.c boardPadDelayDevice.c boardPadDelayInit.c iodelay_config.c
SRCS_COMMON += enet_phy.c 

ifeq ($(CORE),$(filter $(CORE), c66x))
    SRCS_ASM_COMMON += iodelay_stack_C66.asm
else ifeq ($(CORE),$(filter $(CORE), ipu1_0))
    SRCS_ASM_COMMON += iodelay_stack_M4.asm
endif

CFLAGS_LOCAL_$(BOARD) += -D$(BOARD)

PACKAGE_SRCS_COMMON =   src/$(BOARD)/src_files_$(BOARD).mk

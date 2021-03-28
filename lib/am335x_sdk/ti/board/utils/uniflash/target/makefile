# Copyright (C) 2018-2019 Texas Instruments Incorporated - http://www.ti.com/
#
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
#    Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the
#    distribution.
#
#    Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#
# Macro definitions referenced below
#

ifeq ($(RULES_MAKE), )
include $(PDK_INSTALL_PATH)/ti/build/Rules.make
else
include $(RULES_MAKE)
endif

# Soc based on board
ifeq ($(BOARD), idkAM571x)
SOC_NAME = am571x
SOC = AM571x
endif

ifeq ($(BOARD), idkAM572x)
SOC_NAME = am572x
SOC = AM572x
endif

ifeq ($(BOARD), idkAM574x)
SOC_NAME = am574x
SOC = AM574x
endif

ifeq ($(BOARD), $(filter $(BOARD), evmK2G iceK2G))
SOC_NAME = k2g
SOC = K2G
endif

ifeq ($(BOARD), idkAM437x)
SOC_NAME = am437x
SOC = AM437x
endif

ifeq ($(BOARD), $(filter $(BOARD), evmAM335x icev2AM335x iceAMIC110))
SOC_NAME = am335x
SOC = AM335x
endif

ifeq ($(BOARD), $(filter $(BOARD), am65xx_evm am65xx_idk))
SOC_NAME = am65xx
SOC = AM65XX
endif
export SOC

FLASH_SRC_DIR ?= $(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/src
FLASH_PGM_BINDIR = $(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/bin/$(BOARD)
FLASH_PGM_OBJDIR = $(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/obj/$(BOARD)
ARMV7LIBDIR ?= ./lib
BINFLAGS = -O binary

#Cross tools
ifeq ($(SOC), AM65XX)
 CODEGEN_INCLUDE = $(TOOLCHAIN_PATH_R5)/include
 CC = $(TOOLCHAIN_PATH_R5)/bin/armcl
 AR = $(TOOLCHAIN_PATH_R5)/bin/armar
 LNK = $(TOOLCHAIN_PATH_R5)/bin/armlnk
 SIZE = $(TOOLCHAIN_PATH_R5)/bin/armofd
 BIN = $(TOOLCHAIN_PATH_GCC_ARCH64)/bin/aarch64-elf-objcopy
else
# Support backwards compatibility with KeyStone1 approach
 CC = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)gcc
 AC = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)as
 AR = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)ar
 LD = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)gcc
 BIN = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)objcopy
endif

# INCLUDE Directories
CSL_DIR = $(PDK_INSTALL_PATH)/ti/csl
BOARD_DIR = $(PDK_INSTALL_PATH)/ti/board

ifeq ($(SOC), $(filter $(SOC), AM335x AM437x))
STARTERWARE_DIR = $(PDK_INSTALL_PATH)/ti/starterware
else
SBL_SRCDIR = $(PDK_INSTALL_PATH)/ti/boot/sbl
endif

ifeq ($(SOC), AM65XX)
INCDIR := $(CSL_DIR);$(PDK_INSTALL_PATH);$(BOARD_DIR);$(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/soc;$(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/soc/k3;$(FLASH_SRC_DIR)/qspi;$(PDK_INSTALL_PATH)/ti/drv/uart;$(PDK_INSTALL_PATH)/ti/csl/src/ip/qspi/V1;$(FLASH_SRC_DIR)/spi;$(FLASH_SRC_DIR)/ospi;$(FLASH_SRC_DIR)/emmc;$(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/board/$(BOARD)/include;$(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/include;$(PDK_INSTALL_PATH)/ti/board/diag/common/$(SOC);$(CODEGEN_INCLUDE)
else
INCDIR := $(CSL_DIR);$(PDK_INSTALL_PATH);$(BOARD_DIR);$(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/soc;$(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/soc/$(SOC_NAME);$(FLASH_SRC_DIR)/qspi;$(PDK_INSTALL_PATH)/ti/board/src/idkAM572x/device;$(PDK_INSTALL_PATH)/ti/drv/uart;$(PDK_INSTALL_PATH)/ti/csl/src/ip/qspi/V1;$(FLASH_SRC_DIR)/spi;$(FLASH_SRC_DIR)/ospi;$(FLASH_SRC_DIR)/emmc;$(PDK_INSTALL_PATH)/ti/starterware/bootloader/src/am335x;$(PDK_INSTALL_PATH)/ti/starterware/include;$(PDK_INSTALL_PATH)/ti/starterware/include/hw;$(PDK_INSTALL_PATH)/ti/starterware/include/am335x;$(PDK_INSTALL_PATH)/ti/starterware/include/utils;$(PDK_INSTALL_PATH)/ti/starterware/bootloader/include;$(PDK_INSTALL_PATH)/ti/starterware/board;$(STARTERWARE_DIR);$(PDK_INSTALL_PATH)/ti/starterware/dal;$(PDK_INSTALL_PATH)/ti/starterware/utils;$(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/board/$(BOARD)/include;$(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/include;$(PDK_INSTALL_PATH)/ti/board/diag/common/$(SOC)
endif

# Libraries
ifeq ($(SOC), AM65XX)
    WRTR_SOC = $(SOC_NAME)
    WRTR_SOC_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/soc/k3
    WRTR_LINKER = linker.cmd
    CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/r5f/release/ti.csl.aer5f"
    CSL_INIT_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/r5f/release/ti.csl.init.aer5f"
    SCI_LIB = "$(PDK_INSTALL_PATH)/ti/drv/sciclient/lib/$(SOC_NAME)/mcu1_0/release/sciclient.aer5f"
    OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/$(SOC_NAME)/r5f/release/ti.osal.aer5f"
    OSPI_LIB = "$(PDK_INSTALL_PATH)/ti/drv/spi/lib/$(SOC_NAME)/r5f/release/ti.drv.spi.dma.aer5f"
    MMCSD_LIB = "$(PDK_INSTALL_PATH)/ti/drv/mmcsd/lib/$(SOC_NAME)/r5f/release/ti.drv.mmcsd.aer5f"
    GPIO_LIB = "$(PDK_INSTALL_PATH)/ti/drv/gpio/lib/$(SOC_NAME)/r5f/release/ti.drv.gpio.aer5f"
    BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/r5f/release/ti.board.aer5f"
    I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/$(SOC_NAME)/r5f/release/ti.drv.i2c.aer5f"
    UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(SOC_NAME)/r5f/release/ti.drv.uart.aer5f"
    UDMA_LIB = "$(PDK_INSTALL_PATH)/ti/drv/udma/lib/$(SOC_NAME)/mcu1_0/release/udma.aer5f"
    PERIPHERAL_LIB = $(UART_LIB) $(I2C_LIB) $(UDMA_LIB) $(OSPI_LIB) $(CSL_LIB) $(CSL_INIT_LIB) $(OSAL_LIB) $(SCI_LIB) $(BOARD_LIB) $(MMCSD_LIB)

    RTSLIB_PATH = "$(TOOLCHAIN_PATH_R5)/lib/libc.a"
    LNK_LIBS = -l$(PERIPHERAL_LIB) -l$(BOARD_LIB) -l$(OSAL_LIB) $(RTSLIB_PATH)

NUM_PROCS = 1

ifeq ($(OS),Windows_NT)
  NUM_PROCS = $(NUMBER_OF_PROCESSORS)
else
  NUM_PROCS = $(shell grep -c ^processor /proc/cpuinfo)
endif

BUILD_LIB_ONCE = $(TOOLCHAIN_PATH_R5)/lib/$(RTSLIB_NAME)
RTSLIB_NAME = rtsv7R4_T_le_v3D16_eabi.lib
endif

ifeq ($(SOC), K2G)
	WRTR_SOC = k2g
	WRTR_SOC_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/soc/$(SOC_NAME)
	WRTR_LINKER = linker.cmd
	CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/a15/release/ti.csl.aa15fg"
	CSL_INIT_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/a15/release/ti.csl.init.aa15fg"
	OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/$(SOC_NAME)/a15/release/ti.osal.aa15fg"
	QSPI_LIB = "$(PDK_INSTALL_PATH)/ti/drv/spi/lib/$(SOC_NAME)/a15/release/ti.drv.spi.aa15fg"
	MMCSD_LIB = "$(PDK_INSTALL_PATH)/ti/drv/mmcsd/lib/$(SOC_NAME)/a15/release/ti.drv.mmcsd.aa15fg"
	GPIO_LIB = "$(PDK_INSTALL_PATH)/ti/drv/gpio/lib/$(SOC_NAME)/a15/release/ti.drv.gpio.aa15fg"
	BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/a15/release/ti.board.aa15fg"
	I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/a15/release/ti.drv.i2c.aa15fg"
	UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(SOC_NAME)/a15/release/ti.drv.uart.aa15fg"
	PERIPHERAL_LIB = $(UART_LIB) $(I2C_LIB) $(QSPI_LIB) $(CSL_LIB) $(CSL_INIT_LIB) $(OSAL_LIB) $(BOARD_LIB) $(MMCSD_LIB) $(GPIO_LIB)
endif

ifeq ($(SOC), $(filter $(SOC), AM571x AM572x AM574x))
	WRTR_SOC = $(SOC_NAME)
	WRTR_SOC_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/soc/am57xx
	WRTR_LINKER = linker.cmd
	BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/a15/release/ti.board.aa15fg"
	CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/a15/release/ti.csl.aa15fg"
	CSL_INIT_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/a15/release/ti.csl.init.aa15fg"
	OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/$(SOC_NAME)/a15/release/ti.osal.aa15fg"
	QSPI_LIB = "$(PDK_INSTALL_PATH)/ti/drv/spi/lib/$(SOC_NAME)/a15/release/ti.drv.spi.aa15fg"
	I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/$(SOC_NAME)/a15/release/ti.drv.i2c.aa15fg"
	UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(SOC_NAME)/a15/release/ti.drv.uart.aa15fg"
	PERIPHERAL_LIB = $(UART_LIB) $(QSPI_LIB) $(I2C_LIB) $(MMCSD_LIB) $(CSL_LIB) $(CSL_INIT_LIB) $(OSAL_LIB) $(BOARD_LIB)
endif

ifeq ($(SOC), AM437x)
	WRTR_SOC = am437x
	WRTR_SOC_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/soc/$(SOC_NAME)
	WRTR_LINKER = linker.cmd
	BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/a9/release/ti.board.aa9fg"
	CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/a9/release/ti.csl.aa9fg"
	OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/$(SOC_NAME)/a9/release/ti.osal.aa9fg"
	QSPI_LIB = "$(PDK_INSTALL_PATH)/ti/drv/spi/lib/$(SOC_NAME)/a9/release/ti.drv.spi.aa9fg"
	UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(SOC_NAME)/a9/release/ti.drv.uart.aa9fg"
	PERIPHERAL_LIB = $(UART_LIB) $(QSPI_LIB) $(MMCSD_LIB) $(CSL_LIB) $(OSAL_LIB) $(BOARD_LIB)
endif

ifeq ($(SOC), AM335x)
	WRTR_SOC = am335x
	WRTR_SOC_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/soc/$(SOC_NAME)
	WRTR_BOARD_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/board/src
	WRTR_BOARD_DIR += $(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/board/$(BOARD)
	WRTR_LINKER = linker.cmd
	BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/a8/release/ti.board.aa8fg"
	CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/a8/release/ti.csl.aa8fg"
	OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/$(SOC_NAME)/a8/release/ti.osal.aa8fg"
	SPI_LIB = "$(PDK_INSTALL_PATH)/ti/drv/spi/lib/$(SOC_NAME)/a8/release/ti.drv.spi.aa8fg"
	UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(SOC_NAME)/a8/release/ti.drv.uart.aa8fg"
	I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/$(SOC_NAME)/a8/release/ti.drv.i2c.aa8fg"
	PERIPHERAL_LIB = $(UART_LIB) $(SPI_LIB) $(CSL_LIB) $(OSAL_LIB) $(BOARD_LIB) $(I2C_LIB)
endif

LIBDIR :=

ifeq ($(SOC), AM65XX)
INTERNALDEFS = -g -ms -DMAKEFILE_BUILD -c -qq -pdsw225  $(DEBUG_FLAG) -D$(BOARD) -DSOC_$(SOC) --endian=little -mv7R5 --abi=eabi -eo.oer5f --code_state=16 -ea.ser5f --symdebug:dwarf --embed_inline_assembly --float_support=vfpv3d16 -ms -oe -O2 -op0 -os --optimize_with_debug --inline_recursion_limit=20  -DBUILD_MCU1_0 -DBUILD_MCU -DBARE_METAL
ifneq ($(BUILD_HS), yes)
INTERNALDEFS += -DSPI_DMA_ENABLE
endif
# Linker options
INTERNALLINKDEFS = --emit_warnings_as_errors -w -q -u _resetvectors -i "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/r5f/release" -i "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/r5f/release" $(WRTR_SOC_DIR)/$(WRTR_LINKER) -c -mv7R5 --diag_suppress=10063 --opt='--float_support=vfpv3d16 --endian=little -mv7R5 --abi=eabi -qq -pdsw225 -g -ms -DMAKEFILE_BUILD -oe --symdebug:dwarf -ms -op2 -O3 -os --optimize_with_debug --inline_recursion_limit=20 --diag_suppress=23000' --strict_compatibility=on -x --zero_init=on $(LNK_LIBS)

OBJEXT = oer5f
ASMOBJEXT = oer5f
else
# Compiler options
INTERNALDEFS += -g -gdwarf-3 -gstrict-dwarf -Wall $(DEBUG_FLAG) -D__ARMv7 -DSOC_$(SOC) -D$(BOARD) -mtune=cortex-a15 -march=armv7-a -marm -mfloat-abi=hard -mfpu=neon
# Linker options
INTERNALLINKDEFS = -mfloat-abi=hard -Wl,--undefined,__aeabi_uidiv -Wl,--undefined,__aeabi_idiv --entry Entry -nostartfiles -static -Wl,--gc-sections -Wl,-T $(WRTR_SOC_DIR)/$(WRTR_LINKER) -Wl,--start-group -lgcc -lc -lrdimon $(BOARD_LIB) $(PERIPHERAL_LIB) -Wl,--end-group $(LDFLAGS)

OBJEXT = o
ASMOBJEXT = ao
endif

# Executable using device independent library and device object file
EXE=uart_$(BOARD)_flash_programmer.out
BIN_NAME=uart_$(BOARD)_flash_programmer.bin

ifeq ($(OS),Windows_NT)
export TIIMAGE=tiimage.exe
else
export TIIMAGE=tiimage.out
endif

SRCDIR = $(FLASH_SRC_DIR)/

INCS = -I. -I$(strip $(subst ;, -I,$(INCDIR), -I,$(INCDIR)))

VPATH=$(SRCDIR):$(PDK_INSTALL_PATH)/ti/drv/uart/soc/$(WRTR_SOC):$(PDK_INSTALL_PATH)/ti/drv/spi/soc/$(WRTR_SOC):$(WRTR_SOC_DIR):$(WRTR_BOARD_DIR):$(FLASH_SRC_DIR)/qspi:$(FLASH_SRC_DIR)/ospi:$(PDK_INSTALL_PATH)/ti/drv/uart:$(FLASH_SRC_DIR)/spi:$(FLASH_SRC_DIR)/emmc:$(PDK_INSTALL_PATH)/ti/starterware/bootloader/src/am335x:$(PDK_INSTALL_PATH)/ti/starterware/include:$(PDK_INSTALL_PATH)/ti/starterware/include/hw:$(PDK_INSTALL_PATH)/ti/starterware/include/am335x:$(PDK_INSTALL_PATH)/ti/starterware/include/utils:$(PDK_INSTALL_PATH)/ti/starterware/bootloader/include:$(PDK_INSTALL_PATH)/ti/starterware/board:$(STARTERWARE_DIR):$(PDK_INSTALL_PATH)/ti/starterware/bootloader/src:$(PDK_INSTALL_PATH)/ti/starterware/examples/gpio:$(PDK_INSTALL_PATH)/ti/starterware/utils:$(STARTERWARE_DIR)/include:$(STARTERWARE_DIR)/board:$(STARTERWARE_DIR)/soc/am335x:$(STARTERWARE_DIR)/soc/armv7a/gcc:$(PDK_INSTALL_PATH)/ti/board/diag/common/$(SOC)

#List the Source Files
SRC_C = \
	xmodem.c \
	uart_main.c 

ifeq ($(SOC), K2G)
SRC_DRV = a15.c
endif

ifeq ($(BOARD), $(filter $(BOARD), idkAM571x idkAM572x idkAM574x idkAM437x iceK2G evmK2G))
SRC_DRV += qspi.c
endif

ifeq ($(BOARD), $(filter $(BOARD), evmAM335x iceAMIC110 icev2AM335x))
SRC_DRV += spi.c
endif

ifeq ($(BOARD), $(filter $(BOARD), am65xx_evm am65xx_idk))
SRC_DRV += ospi.c
endif

ifeq ($(BOARD), $(filter $(BOARD), am65xx_evm am65xx_idk))
SRC_DRV += emmc.c
endif

SRC_DRV += \
    soc.c

ifeq ($(SOC), AM335x)
SRC_DRV += \
	board.c \
	soc_platform_pll.c
endif

ifeq ($(OS),Windows_NT)
  BIN_CERT_GEN=powershell -executionpolicy unrestricted -command $(ROOTDIR)/ti/build/makerules/x509CertificateGen.ps1
else
  BIN_CERT_GEN=$(ROOTDIR)/ti/build/makerules/x509CertificateGen.sh
endif
BIN_CERT_KEY=$(ROOTDIR)/ti/build/makerules/k3_dev_mpk.pem

#Common entry object
ifeq ($(SOC), $(filter $(SOC), AM335x AM437x))
ENTRY_SRC = sbl_init.S
endif
ifeq ($(SOC), K2G)
ENTRY_SRC = init.S
endif

# FLAGS for the SourceFiles
ifeq ($(SOC), AM65XX)
CFLAGS += -O2
SRC_CFLAGS = -I. $(CFLAGS) -g -eo.$(OBJEXT) -ea.$(ASMOBJEXT)
else
CFLAGS += -Wall -O2
SRC_CFLAGS = -I. $(CFLAGS) -g -gdwarf-3 -gstrict-dwarf -Wall
endif

# Make Rule for the SRC Files
SRC_OBJS = $(patsubst %.c, $(FLASH_PGM_OBJDIR)/%.$(OBJEXT), $(SRC_C))
ifeq ($(SOC), AM65XX)
ENTRY_OBJ = $(patsubst %.asm, $(FLASH_PGM_OBJDIR)/%.$(ASMOBJEXT), $(ENTRY_SRC))
else
ENTRY_OBJ = $(patsubst %.S, $(FLASH_PGM_OBJDIR)/%.$(ASMOBJEXT), $(ENTRY_SRC))
endif

SRC_DRV_OBJS = $(patsubst %.c, $(FLASH_PGM_OBJDIR)/%.$(OBJEXT), $(SRC_DRV))

ifeq ($(SOC), $(filter $(SOC), AM335x AM65XX))
uart_$(BOARD)_flash_programmer:$(FLASH_PGM_BINDIR)/$(BIN_NAME)
else
uart_$(BOARD)_flash_programmer:$(FLASH_PGM_BINDIR)/$(EXE)
endif

ifeq ($(SOC), AM65XX)
$(FLASH_PGM_BINDIR)/$(EXE): $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ) $(FLASH_PGM_BINDIR)/.created $(FLASH_PGM_OBJDIR)/.created $(BUILD_LIB_ONCE)
	@echo linking $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ) into $@ ...
	@$(LNK) $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ) $(INTERNALLINKDEFS) -m"$(FLASH_PGM_BINDIR)/uart_$(BOARD)_flash_programmer.map" -o $@
else
$(FLASH_PGM_BINDIR)/$(EXE): $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ) $(FLASH_PGM_BINDIR)/.created $(FLASH_PGM_OBJDIR)/.created
	@echo linking $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ) into $@ ...
	@$(CC) $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ) $(INTERNALLINKDEFS) -Wl,-Map=$(FLASH_PGM_BINDIR)/uart_$(BOARD)_flash_programmer.map -o $@
endif

ifeq ($(SOC), AM335x)
$(FLASH_PGM_BINDIR)/$(BIN_NAME) : $(FLASH_PGM_BINDIR)/$(EXE)
	$(BIN) $(BINFLAGS) $(FLASH_PGM_BINDIR)/$(EXE) $@

else
$(FLASH_PGM_BINDIR)/$(BIN_NAME) : $(FLASH_PGM_BINDIR)/$(EXE)
ifneq ($(OS),Windows_NT)
	$(CHMOD) a+x $(BIN_CERT_GEN)
endif
	$(BIN) --gap-fill=0xff -O binary $(FLASH_PGM_BINDIR)/$(EXE) $(FLASH_PGM_BINDIR)/$(BIN_NAME)
	$(BIN_CERT_GEN) -b $(FLASH_PGM_BINDIR)/$(BIN_NAME) -o $(FLASH_PGM_BINDIR)/uart_$(BOARD)_flash_programmer.tiimage -c R5 -l 0x41c00100 -k $(BIN_CERT_KEY) -d DEBUG -j DBG_FULL_ENABLE
endif
	
$(FLASH_PGM_OBJDIR)/%.$(OBJEXT): %.c $(FLASH_PGM_OBJDIR)/.created
	@echo compiling $< ...
ifeq ($(SOC), AM65XX)
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS) -fr=$(FLASH_PGM_OBJDIR) -fs=$(FLASH_PGM_OBJDIR) -fc $<
else
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS)  $< -o $@
endif


ifeq ($(SOC), AM65XX)
$(FLASH_PGM_OBJDIR)/%.$(ASMOBJEXT): %.asm $(FLASH_PGM_OBJDIR)/.created
	@echo compiling $< ...
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS)  -fr=$(FLASH_PGM_OBJDIR) -fs=$(FLASH_PGM_OBJDIR) -fa $<
else
$(FLASH_PGM_OBJDIR)/%.$(ASMOBJEXT): %.S $(FLASH_PGM_OBJDIR)/.created
	@echo compiling $< ...
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS)  $< -o $@
endif


$(FLASH_PGM_OBJDIR)/.created:
	@mkdir -p $(FLASH_PGM_OBJDIR)
	@touch $(FLASH_PGM_OBJDIR)/.created

$(FLASH_PGM_BINDIR)/.created:
	@mkdir -p $(FLASH_PGM_BINDIR)
	@touch $(FLASH_PGM_BINDIR)/.created
	
$(STARTERWARE_DIR)/tools/ti_image/$(TIIMAGE):
	gcc -o $(STARTERWARE_DIR)/tools/ti_image/$(TIIMAGE) $(STARTERWARE_DIR)/tools/ti_image/tiimage.c

$(BUILD_LIB_ONCE):
ifeq ($(SOC), AM65XX)
	@echo \# $@ not found, building  $@ ...
	@$(TOOLCHAIN_PATH_R5)/lib/mklib --pattern=$(RTSLIB_NAME) --parallel=$(NUM_PROCS) --compiler_bin_dir=$(TOOLCHAIN_PATH_R5)/bin
endif

clean: uart_$(BOARD)_flash_programmer_clean

uart_$(BOARD)_flash_programmer_clean:
	@rm -f $(FLASH_PGM_BINDIR)/$(EXE) $(FLASH_PGM_BINDIR)/$(BIN_NAME)
	@rm -f $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ)
	@rm -f $(FLASH_PGM_BINDIR)/uart_$(BOARD)_flash_programmer.map

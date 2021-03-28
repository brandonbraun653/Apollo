# Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

ifeq ($(BOARD), $(filter $(BOARD), idkAM572x evmAM572x))
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

ifeq ($(BOARD), $(filter $(BOARD), evmAM437x idkAM437x))
SOC_NAME = am437x
SOC = AM437x
endif

ifeq ($(BOARD), $(filter $(BOARD), evmAM335x icev2AM335x iceAMIC110))
SOC_NAME = am335x
SOC = AM335x
endif

ifeq ($(BOARD), evmOMAPL137)
SOC_NAME = omapl137
SOC = OMAPL137
endif

ifeq ($(BOARD), lcdkOMAPL138)
SOC_NAME = omapl138
SOC = OMAPL138
endif

APPLOADER_SRC_DIR ?= $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/src
ifeq ($(SOC), OMAPL137)
APPLOADER_PGM_BINDIR = $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/bin/$(BOARD)/c674x
APPLOADER_PGM_OBJDIR = $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/obj/$(BOARD)/c674x
else ifeq ($(SOC), OMAPL138)
APPLOADER_PGM_BINDIR = $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/bin/$(BOARD)/armv5
APPLOADER_PGM_OBJDIR = $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/obj/$(BOARD)/armv5
else
APPLOADER_PGM_BINDIR = $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/bin/$(BOARD)/armv7
APPLOADER_PGM_OBJDIR = $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/obj/$(BOARD)/armv7
endif
ARMV7LIBDIR ?= ./lib
# ARMV5 link directory that contain built peripheral libraries
ARMV5LIBDIR ?= ./lib
BINFLAGS = -O binary

#Cross tools
ifeq ($(SOC), OMAPL137)
ifdef C6X_GEN_INSTALL_PATH
#Support backwards compatibility with KeyStone1 approach
CC = $(C6X_GEN_INSTALL_PATH)/bin/cl6x
endif
else ifeq ($(SOC), OMAPL138)
ifdef TOOLCHAIN_PATH_ARM9
TOOLCHAIN_PATH = $(TOOLCHAIN_PATH_ARM9)
else
TOOLCHAIN_PATH = $(TOOLCHAIN_PATH_Arm9)
endif
#Cross tools
CC = $(TOOLCHAIN_PATH)/bin/armcl
AR = $(TOOLCHAIN_PATH)/bin/armar
LNK = $(TOOLCHAIN_PATH)/bin/armlnk
SIZE = $(TOOLCHAIN_PATH)/bin/armofd
else
ifdef TOOLCHAIN_PATH_A15
# Support backwards compatibility with KeyStone1 approach
 CC = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)gcc
 AC = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)as
 AR = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)ar
 LD = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)gcc
 BIN = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)objcopy
endif
endif

# INCLUDE Directories
CSL_DIR = $(PDK_INSTALL_PATH)/ti/csl
BOARD_DIR = $(PDK_INSTALL_PATH)/ti/board

ifeq ($(SOC), $(filter $(SOC), AM335x AM437x))
STARTERWARE_DIR = $(PDK_INSTALL_PATH)/ti/starterware
else
SBL_SRCDIR = $(PDK_INSTALL_PATH)/ti/boot/sbl
SBL_RPRC_DIR = $(SBL_SRCDIR)/src/rprc
SBL_BOARD_DIR = $(SBL_SRCDIR)/board/src
endif

# Libraries
ifeq ($(SOC), OMAPL138)
	APPLOADER_SOC = $(SOC_NAME)
	APPLOADER_SOC_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/soc/$(SOC_NAME)
	APPLOADER_LINKER = linker.cmd
	SBL_SOC_DIR = $(SBL_SRCDIR)/soc/$(SOC_NAME)
	BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/arm9/release/ti.board.ae9"
	UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(SOC_NAME)/arm9/release/ti.drv.uart.ae9"
	I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/$(SOC_NAME)/arm9/release/ti.drv.i2c.ae9"
	SPI_LIB = "$(PDK_INSTALL_PATH)/ti/drv/spi/lib/$(SOC_NAME)/arm9/release/ti.drv.spi.ae9"
	CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/arm9/release/ti.csl.ae9"
	CSL_INIT_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/arm9/release/ti.csl.init.ae9"
	RTSLIB_PATH = "$(TOOLCHAIN_PATH)/lib/libc.a"
	MMCSD_LIB = "$(PDK_INSTALL_PATH)/ti/drv/mmcsd/lib/$(SOC_NAME)/arm9/release/ti.drv.mmcsd.ae9"
	FATFS_LIB = "$(PDK_INSTALL_PATH)/ti/fs/fatfs/lib/arm9/release/ti.fs.fatfs.ae9"
	OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/$(SOC_NAME)/arm9/release/ti.osal.ae9"
	PERIPHERAL_LIB = -l$(BOARD_LIB) -l$(I2C_LIB) -l$(UART_LIB) -l$(OSAL_LIB) -l$(SPI_LIB) -l$(CSL_LIB) -l$(CSL_INIT_LIB) $(RTSLIB_PATH)
endif
ifeq ($(SOC), OMAPL137)
	APPLOADER_SOC = $(SOC_NAME)
	APPLOADER_SOC_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/soc/$(SOC_NAME)
	APPLOADER_LINKER = linker.cmd
	SBL_SOC_DIR = $(SBL_SRCDIR)/soc/$(SOC_NAME)
	BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/c674/release/ti.board.ae674"
	I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/$(SOC_NAME)/c674/release/ti.drv.i2c.ae674"
	UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(SOC_NAME)/c674/release/ti.drv.uart.ae674"
	OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/$(SOC_NAME)/c674/release/ti.osal.ae674"
	SPI_LIB = "$(PDK_INSTALL_PATH)/ti/drv/spi/lib/$(SOC_NAME)/c674/release/ti.drv.spi.ae674"
	MMCSD_LIB = "$(PDK_INSTALL_PATH)/ti/drv/mmcsd/lib/$(SOC_NAME)/c674/release/ti.drv.mmcsd.ae674"
	CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/c674/release/ti.csl.ae674"
	CSL_INTC_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/c674/release/ti.csl.intc.ae674"
	RTSLIB_PATH = "$(C6X_GEN_INSTALL_PATH)/lib/libc.a"
	PERIPHERAL_LIB = -l$(BOARD_LIB) -l$(I2C_LIB) -l$(UART_LIB) -l$(OSAL_LIB) -l$(SPI_LIB) -l$(MMCSD_LIB) -l$(CSL_LIB) -l$(CSL_INTC_LIB)  -l$(RTSLIB_PATH)
endif
ifeq ($(SOC), K2G)
	APPLOADER_SOC = $(SOC_NAME)
	APPLOADER_SOC_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/soc/$(SOC_NAME)
	APPLOADER_LINKER = linker_$(BOARD).cmd
	SOC_INIT_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/soc/$(SOC_NAME)
	SBL_SOC_DIR = $(SBL_SRCDIR)/soc/$(SOC_NAME)
	CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/a15/release/ti.csl.aa15fg"
	CSL_INIT_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/a15/release/ti.csl.init.aa15fg"
	OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/$(SOC_NAME)/a15/release/ti.osal.aa15fg"
	MMCSD_LIB = "$(PDK_INSTALL_PATH)/ti/drv/mmcsd/lib/$(SOC_NAME)/a15/release/ti.drv.mmcsd.aa15fg"
	GPIO_LIB = "$(PDK_INSTALL_PATH)/ti/drv/gpio/lib/$(SOC_NAME)/a15/release/ti.drv.gpio.aa15fg"
	BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/a15/release/ti.board.aa15fg"
	I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/a15/release/ti.drv.i2c.aa15fg"
	UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(SOC_NAME)/a15/release/ti.drv.uart.aa15fg"
	PERIPHERAL_LIB = $(UART_LIB) $(I2C_LIB) $(CSL_LIB) $(CSL_INIT_LIB) $(OSAL_LIB) $(BOARD_LIB) $(MMCSD_LIB) $(GPIO_LIB)
endif
ifeq ($(SOC), $(filter $(SOC), AM571x AM572x AM574x))
	APPLOADER_SOC = $(SOC_NAME)
	APPLOADER_SOC_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/soc/am57xx
ifeq ($(SOC), AM571x)
	APPLOADER_LINKER = linker_AM571x.cmd
else
    APPLOADER_LINKER = linker_AM572x.cmd
endif
	SBL_SOC_DIR = $(SBL_SRCDIR)/soc/am57xx
	BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/a15/release/ti.board.aa15fg"
	CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/a15/release/ti.csl.aa15fg"
	CSL_INIT_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/a15/release/ti.csl.init.aa15fg"
	OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/$(SOC_NAME)/a15/release/ti.osal.aa15fg"
	I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/$(SOC_NAME)/a15/release/ti.drv.i2c.aa15fg"
	UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(SOC_NAME)/a15/release/ti.drv.uart.aa15fg"
	PERIPHERAL_LIB = $(UART_LIB) $(I2C_LIB) $(MMCSD_LIB) $(CSL_LIB) $(CSL_INIT_LIB) $(OSAL_LIB) $(BOARD_LIB)
endif
ifeq ($(SOC), AM437x)
	APPLOADER_SOC = $(SOC_NAME)
	APPLOADER_SOC_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/soc/$(SOC_NAME)
	APPLOADER_LINKER = linker_$(BOARD).cmd
	SOC_INIT_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uniflash/target/soc/$(SOC_NAME)
	BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/a9/release/ti.board.aa9fg"
	CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/a9/release/ti.csl.aa9fg"
	OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/$(SOC_NAME)/a9/release/ti.osal.aa9fg"
	QSPI_LIB = "$(PDK_INSTALL_PATH)/ti/drv/spi/lib/$(SOC_NAME)/a9/release/ti.drv.spi.aa9fg"
	UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(SOC_NAME)/a9/release/ti.drv.uart.aa9fg"
	PERIPHERAL_LIB = $(UART_LIB) $(QSPI_LIB) $(MMCSD_LIB) $(CSL_LIB) $(OSAL_LIB) $(BOARD_LIB)
endif
ifeq ($(SOC), AM335x)
	APPLOADER_SOC = $(SOC_NAME)
	APPLOADER_SOC_DIR = $(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/soc/$(SOC_NAME)
	APPLOADER_LINKER = linker_$(BOARD).cmd
	BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/a8/release/ti.board.aa8fg"
	CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC_NAME)/a8/release/ti.csl.aa8fg"
	OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/$(SOC_NAME)/a8/release/ti.osal.aa8fg"
	SPI_LIB = "$(PDK_INSTALL_PATH)/ti/drv/spi/lib/$(SOC_NAME)/a8/release/ti.drv.spi.aa8fg"
	UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(SOC_NAME)/a8/release/ti.drv.uart.aa8fg"
	I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/$(SOC_NAME)/a8/release/ti.drv.i2c.aa8fg"
	PERIPHERAL_LIB = $(UART_LIB) $(SPI_LIB) $(CSL_LIB) $(OSAL_LIB) $(BOARD_LIB) $(I2C_LIB)
endif

INCDIR := $(CSL_DIR);$(PDK_INSTALL_PATH);$(BOARD_DIR);$(APPLOADER_SRC_DIR);$(SBL_SRCDIR);$(SBL_RPRC_DIR);$(SBL_SOC_DIR);$(SBL_BOARD_DIR);$(PDK_INSTALL_PATH)/ti/drv/uart

LIBDIR :=

ifeq ($(SOC), $(filter $(SOC), OMAPL137 OMAPL138))
ifeq ($(SOC), OMAPL137)
DEFFLAGS = --define=SOC_$(SOC) --define=BUILD_DSP -D$(SOC)_BUILD -mv64+
SOC_FLAGS = -mv64+
else ifeq ($(SOC), OMAPL138)
DEFFLAGS = --define=SOC_$(SOC) -D$(SOC)_BUILD -mv5e --code_state=32 -me -DlcdkOMAPL138
SOC_FLAGS = -mv5e --code_state=32 -me
endif
# Compiler options
INTERNALDEFS = -g $(DEBUG_FLAG) -g $(DEFFLAGS) --diag_wrap=off --diag_warning=225 --display_error_number
# Linker options
INTERNALLINKDEFS = $(SOC_FLAGS) -g $(DEFFLAGS) --diag_wrap=off --diag_warning=225 --display_error_number -z
else

# Compiler options
INTERNALDEFS += -g -gdwarf-3 -gstrict-dwarf -Wall $(DEBUG_FLAG) -D__ARMv7 -DSOC_$(SOC) -D$(BOARD) -D$(SOC)_BUILD -mtune=cortex-a15 -march=armv7-a -marm -mfloat-abi=hard -mfpu=neon

# Linker options
INTERNALLINKDEFS = -mfloat-abi=hard -Wl,--undefined,__aeabi_uidiv -Wl,--undefined,__aeabi_idiv --entry Entry -nostartfiles -static -Wl,--gc-sections -Wl,-T $(APPLOADER_SOC_DIR)/$(APPLOADER_LINKER) -Wl,--start-group -lgcc -lc -lrdimon $(BOARD_LIB) $(PERIPHERAL_LIB) -Wl,--end-group $(LDFLAGS)
endif

# Executable using SOC independent library and SOC object file
ifeq ($(SOC), $(filter $(SOC), AM335x AM437x))
BIN_NAME=apploader_$(BOARD)_mmcsd.bin
APPLOADER_TEST_DIR=$(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/bin/$(BOARD)/sd

#
# Where the application will be loaded to. This is required to generate
# image with Header (Load Address and Size)
#
ifeq ($(BOARD), evmAM335x)
IMG_LOAD_ADDR = 0xBFE00000
else ifeq ($(BOARD), icev2AM335x)
IMG_LOAD_ADDR = 0x8FD00000
else ifeq ($(BOARD), iceAMIC110)
IMG_LOAD_ADDR = 0x9FE00000
endif

ifeq ($(BOARD), evmAM437x)
IMG_LOAD_ADDR = 0xFFE00000
else ifeq ($(BOARD), idkAM437x)
IMG_LOAD_ADDR = 0xBFE00000
endif

endif
ifneq ($(SOC), $(filter $(SOC), AM335x AM437x))
BIN_NAME=apploader_TEST
APPLOADER_TEST_DIR=$(PDK_INSTALL_PATH)/ti/board/utils/uartAppLoader/bin/$(BOARD)/sd
ifeq ($(OS),Windows_NT)
OUT2RPRC_EXE=$(PDK_INSTALL_PATH)/ti/boot/sbl/tools/out2rprc/bin/out2rprc.exe
IMAGEGEN_EXE=$(PDK_INSTALL_PATH)/ti/boot/sbl/tools/multicoreImageGen/bin/MulticoreImageGen.exe
else
OUT2RPRC_EXE=mono $(PDK_INSTALL_PATH)/ti/boot/sbl/tools/out2rprc/bin/out2rprc.exe
IMAGEGEN_EXE=$(PDK_INSTALL_PATH)/ti/boot/sbl/tools/multicoreImageGen/bin/MulticoreImageGen
endif
DSP0_ID=1
MPU_CPU0_ID=0
Dev_ID=55
endif

EXE=apploader_$(BOARD)_mmcsd.out

OBJEXT = o
ASMOBJEXT = ao
SRCDIR = $(APPLOADER_SRC_DIR)/

INCS = -I. -I$(strip $(subst ;, -I,$(INCDIR)))
ifeq ($(SOC), OMAPL137)
INCS += -I$(C6X_GEN_INSTALL_PATH)/include  -I$(C6X_GEN_INSTALL_PATH)/lib
CORE_ID = $(DSP0_ID)
else ifeq ($(SOC), OMAPL138)
INCS += -I$(TOOLCHAIN_PATH)/include -I$(TOOLCHAIN_PATH)/lib
CORE_ID = $(MPU_CPU0_ID)
else
CORE_ID = $(MPU_CPU0_ID)
endif

VPATH=$(PDK_INSTALL_PATH)/ti/csl/src/ip/uart/V1/priv:$(SRCDIR):$(PDK_INSTALL_PATH)/ti/drv/uart/soc/$(APPLOADER_SOC):$(APPLOADER_SOC_DIR):$(SOC_INIT_DIR):$(PDK_INSTALL_PATH)/ti/drv/uart:$(SBL_SRCDIR):$(SBL_SOC_DIR):$(SBL_RPRC_DIR):$(STARTERWARE_DIR)/soc/armv7a/gcc:$(PDK_INSTALL_PATH)/ti/board/diag/common/$(SOC)

#List the Source Files
SRC_C += \
	xmodem.c \
	apploader_main.c

ifeq ($(SOC), K2G)
SRC_DRV += a15.c
endif
ifeq ($(SOC), $(filter $(SOC), K2G OMAPL137 OMAPL138))
SRC_DRV += sbl_slave_boot.c
endif

ifeq ($(SOC), $(filter $(SOC), AM571x AM572x AM574x))
SRC_DRV += sbl_slave_core_boot.c \
	sbl_prcm.c
endif

ifneq ($(SOC), $(filter $(SOC), AM335x AM437x))
SRC_DRV += \
	core_boot.c \
	sbl_rprc.c
else
SRC_DRV += startup.c
endif

SRC_DRV += \
	soc.c

#Common entry object
ifeq ($(SOC), $(filter $(SOC), AM335x AM437x AM571x AM572x AM574x))
ENTRY_SRC = diag_entry.S
endif
ifeq ($(SOC), K2G)
ENTRY_SRC = init.S
endif

ifeq ($(SOC), $(filter $(SOC), AM335x AM437x))
ifeq ($(OS),Windows_NT)
export TIIMAGE=tiimage.exe
else
export TIIMAGE=tiimage
endif
endif

# FLAGS for the SourceFiles
ifeq ($(SOC), $(filter $(SOC), OMAPL137 OMAPL138))
CFLAGS += -ms -oe --inline_recursion_limit=20 -O2
SRC_CFLAGS = -I. $(CFLAGS) -eo.$(OBJEXT) -ea.$(ASMOBJEXT) -g
else
CFLAGS += -Wall -g
SRC_CFLAGS = -I. $(CFLAGS) -g -gdwarf-3 -gstrict-dwarf -Wall
endif

# Make Rule for the SRC Files
SRC_OBJS = $(patsubst %.c, $(APPLOADER_PGM_OBJDIR)/%.$(OBJEXT), $(SRC_C))
ENTRY_OBJ = $(patsubst %.S, $(APPLOADER_PGM_OBJDIR)/%.$(ASMOBJEXT), $(ENTRY_SRC))
SRC_DRV_OBJS = $(patsubst %.c, $(APPLOADER_PGM_OBJDIR)/%.$(OBJEXT), $(SRC_DRV))

ifeq ($(SOC), $(filter $(SOC), AM335x AM437x))
apploader_$(BOARD)_mmcsd:$(APPLOADER_PGM_BINDIR)/$(EXE) $(APPLOADER_PGM_BINDIR)/$(BIN_NAME)
else
apploader_$(BOARD)_mmcsd:$(APPLOADER_PGM_BINDIR)/$(EXE) $(APPLOADER_TEST_DIR)/$(BIN_NAME)
endif
ifeq ($(SOC), $(filter $(SOC), AM335x AM437x))
$(APPLOADER_PGM_BINDIR)/$(BIN_NAME) : $(APPLOADER_PGM_BINDIR)/$(EXE) $(APPLOADER_TEST_DIR)/.created $(STARTERWARE_DIR)/tools/ti_image/$(TIIMAGE)
	$(BIN) $(BINFLAGS) $(APPLOADER_PGM_BINDIR)/$(EXE) $@
	$(STARTERWARE_DIR)/tools/ti_image/$(TIIMAGE) $(IMG_LOAD_ADDR) NONE $(APPLOADER_PGM_BINDIR)/$(BIN_NAME) $(APPLOADER_TEST_DIR)/apploader_TEST

$(STARTERWARE_DIR)/tools/ti_image/$(TIIMAGE):
	gcc -o $(STARTERWARE_DIR)/tools/ti_image/$(TIIMAGE) $(STARTERWARE_DIR)/tools/ti_image/tiimage.c
else
$(APPLOADER_TEST_DIR)/$(BIN_NAME) : $(APPLOADER_PGM_BINDIR)/$(EXE) $(APPLOADER_TEST_DIR)/.created
	$(OUT2RPRC_EXE) $(APPLOADER_PGM_BINDIR)/$(EXE) $(APPLOADER_PGM_BINDIR)/$(EXE).rprc
	$(IMAGEGEN_EXE) LE $(Dev_ID) $@ $(CORE_ID) $(APPLOADER_PGM_BINDIR)/$(EXE).rprc
endif
ifeq ($(SOC), $(filter $(SOC), OMAPL137 OMAPL138))
$(APPLOADER_PGM_BINDIR)/$(EXE): $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ) $(APPLOADER_PGM_BINDIR)/.created $(APPLOADER_PGM_OBJDIR)/.created
	@echo linking $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ) into $@ ...
	@$(CC) $(SRC_OBJS) $(SRC_DRV_OBJS) $(INTERNALLINKDEFS) $(APPLOADER_SOC_DIR)/$(APPLOADER_LINKER) -o $@ -m"$(APPLOADER_PGM_BINDIR)/apploader_$(BOARD)_mmcsd.map" $(PERIPHERAL_LIB) --rom_model

$(APPLOADER_PGM_OBJDIR)/%.$(OBJEXT): %.c $(APPLOADER_PGM_OBJDIR)/.created
	@echo compiling $< ...
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS) -fr=$(APPLOADER_PGM_OBJDIR) -fs=$(APPLOADER_PGM_OBJDIR) -fc $<
else
$(APPLOADER_PGM_BINDIR)/$(EXE): $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ) $(APPLOADER_PGM_BINDIR)/.created $(APPLOADER_PGM_OBJDIR)/.created
	@echo linking $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ) into $@ ...
	@$(CC) $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ) $(INTERNALLINKDEFS) -Wl,-Map=$(APPLOADER_PGM_BINDIR)/apploader_$(BOARD)_mmcsd.map -o $@

$(APPLOADER_PGM_OBJDIR)/%.$(OBJEXT): %.c $(APPLOADER_PGM_OBJDIR)/.created
	@echo compiling $< ...
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS)  $< -o $@

$(APPLOADER_PGM_OBJDIR)/%.$(ASMOBJEXT): %.S $(APPLOADER_PGM_OBJDIR)/.created
	@echo compiling $< ...
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS)  $< -o $@
endif

$(APPLOADER_PGM_OBJDIR)/.created:
	@mkdir -p $(APPLOADER_PGM_OBJDIR)
	@touch $(APPLOADER_PGM_OBJDIR)/.created

$(APPLOADER_PGM_BINDIR)/.created:
	@mkdir -p $(APPLOADER_PGM_BINDIR)
	@touch $(APPLOADER_PGM_BINDIR)/.created

$(APPLOADER_TEST_DIR)/.created:
	@mkdir -p $(APPLOADER_TEST_DIR)
	@touch $(APPLOADER_TEST_DIR)/.created

clean: apploader_$(BOARD)_mmcsd_clean

apploader_$(BOARD)_mmcsd_clean:
	@rm -f $(APPLOADER_PGM_BINDIR)/$(EXE) $(APPLOADER_PGM_BINDIR)/apploader_$(BOARD)_mmcsd.map
	@rm -f $(SRC_OBJS) $(SRC_DRV_OBJS) $(ENTRY_OBJ)
	@rm -f $(APPLOADER_PGM_BINDIR)/$(EXE).rprc
	@rm -f $(APPLOADER_TEST_DIR)/$(BIN_NAME) $(APPLOADER_PGM_BINDIR)/$(BIN_NAME) $(APPLOADER_TEST_DIR)/apploader_TEST

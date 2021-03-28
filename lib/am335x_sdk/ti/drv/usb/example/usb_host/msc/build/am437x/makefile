# Copyright (C) 2015 - 2018 Texas Instruments Incorporated - http://www.ti.com/
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

# Output directories
OBJDIR = .
BINDIR = .


ifeq ($(RULES_MAKE), )
include $(PDK_INSTALL_PATH)/ti/build/Rules.make
else
include $(RULES_MAKE)
endif

ifndef DEVICE
export DEVICE=am437x
endif

export BOARD=evmAM437x

# Cross tools
ifdef TOOLCHAIN_PATH_A9
# Support backwards compatibility with KeyStone1 approach
 CC = $(TOOLCHAIN_PATH_A9)/bin/$(CROSS_TOOL_PRFX)gcc
 AC = $(TOOLCHAIN_PATH_A9)/bin/$(CROSS_TOOL_PRFX)as
 AR = $(TOOLCHAIN_PATH_A9)/bin/$(CROSS_TOOL_PRFX)ar
 LD = $(TOOLCHAIN_PATH_A9)/bin/$(CROSS_TOOL_PRFX)gcc
endif

AVAR=a9
LIBEXT=a$(AVAR)fg
BUILD_PROFILE?=release

# INCLUDE Directories
CSL_DIR = $(PDK_INSTALL_PATH)/ti/csl/
USB_DIR = $(PDK_INSTALL_PATH)/ti/drv/usb
STARTER_DIR = $(PDK_INSTALL_PATH)/ti/starterware

STARTER_INC =  $(STARTER_DIR)/include;
STARTER_INC += $(STARTER_DIR)/include/hw;
STARTER_INC += $(STARTER_DIR)/include/am43xx;
STARTER_INC += $(STARTER_DIR)/include/utils;
STARTER_INC += $(STARTER_DIR)/examples/example_utils
#mmu configuration comes from the example_utils


INCDIR = $(PDK_INSTALL_PATH);
INCDIR += $(USB_DIR);
INCDIR += $(USB_DIR)/src/include;
INCDIR += $(USB_DIR)/src/usb_func/include;
INCDIR += $(USB_DIR)/soc;
INCDIR += $(USB_DIR)/example/shell;
INCDIR += $(STARTER_INC)

STWLIBLOC = lib/am43xx-evm/$(AVAR)/$(BUILD_PROFILE)/gcc
STARTERLIBDIR  = -L$(STARTER_DIR)/binary/soc/$(STWLIBLOC)
STARTERLIBDIR += -L$(STARTER_DIR)/binary/dal/$(STWLIBLOC)
STARTERLIBDIR += -L$(STARTER_DIR)/binary/utils/$(STWLIBLOC)
STARTERLIBDIR += -L$(STARTER_DIR)/binary/board/$(STWLIBLOC)
STARTERLIBDIR += -L$(STARTER_DIR)/binary/examples/example_utils/$(STWLIBLOC)


# Libraries
USB_LIB = "$(PDK_INSTALL_PATH)/ti/drv/usb/lib//$(AVAR)/$(BUILD_PROFILE)/ti.drv.usb.$(LIBEXT)"
USB_SOC_LIB = "$(PDK_INSTALL_PATH)/ti/drv/usb/lib/$(DEVICE)/$(AVAR)/$(BUILD_PROFILE)/ti.drv.usb.$(LIBEXT)"
FATFS_LIB = "$(PDK_INSTALL_PATH)/ti/fs/fatfs/lib/$(AVAR)/$(BUILD_PROFILE)/ti.fs.fatfs.$(LIBEXT)"
OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/$(DEVICE)/$(AVAR)/$(BUILD_PROFILE)/ti.osal.$(LIBEXT)"

UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(AVAR)/$(BUILD_PROFILE)/ti.drv.uart.$(LIBEXT)"
UART_SOC_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/$(DEVICE)/$(AVAR)/$(BUILD_PROFILE)/ti.drv.uart.$(LIBEXT)"

I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/$(AVAR)/$(BUILD_PROFILE)/ti.drv.i2c.$(LIBEXT)"
I2C_SOC_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/$(DEVICE)/$(AVAR)/$(BUILD_PROFILE)/ti.drv.i2c.$(LIBEXT)"

USB_LIBS = $(USB_LIB) $(USB_SOC_LIB)
UART_LIBS = $(UART_LIB) $(UART_SOC_LIB)
I2C_LIBS = $(I2C_LIB) $(I2C_SOC_LIB)

BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/$(AVAR)/$(BUILD_PROFILE)/ti.board.$(LIBEXT)"
CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(DEVICE)/$(AVAR)/$(BUILD_PROFILE)/ti.csl.$(LIBEXT)"
 
#starterware libraries:
#STARTER_LIBS = -lutils -lsoc -lboard -ldal  
#STARTER_LIBS = -lutils -lsoc -lboard -ldal -lexample_utils
STARTER_LIBS = -lsoc -lexample_utils
 

# Compiler options
INTERNALDEFS = -c -g -gstrict-dwarf $(DEBUG_FLAG) -mtune=cortex-$(AVAR) -mcpu=cortex-$(AVAR) -march=armv7-a -marm -mfloat-abi=hard -Dgcc -mfpu=neon -funsigned-char -ffunction-sections -fdata-sections

#linker command file:
LINKER_CMD = $(USB_DIR)/example/$(DEVICE)_linker.lds


# Executable using device independent library and device object file
EXE=usb_h_msc_$(DEVICE).out

# Linker options
INTERNALLINKDEFS = -mfloat-abi=hard -Wl,--undefined, -Wl,--undefined, -Wl,--gc-sections --entry Entry $(STARTERLIBDIR) -Wl,-T $(LINKER_CMD) -Wl,--start-group -l"c" -lrdimon -l"m" $(FATFS_LIB) $(UART_LIBS) $(STARTER_LIBS) $(USB_LIBS) $(OSAL_LIB) $(BOARD_LIB) $(I2C_LIBS) $(CSL_LIB) -Wl,--end-group $(LDFLAGS) -Wl,-Map=$(EXE).map

#INCS = -I. -I$(strip $(subst ;, -I,$(INCDIR)))
INCS = -I. -I$(strip $(subst ; , -I,$(INCDIR)))

#List the Source Files
VPATH = $(USB_DIR)/example/usb_host/msc:$(USB_DIR)/example/shell:$(USB_DIR)/example/common

TEST_SRC = \
    fs_shell_app_utils.c \
    fatfs_port_usbmsc.c \
    usb_main.c \
    usb_osal.c \
    timer.c


#ENTRY_SRC = diag_entry.S


# FLAGS for the SourceFiles
CFLAGS += -Wall -mno-unaligned-access 
SRC_CFLAGS = $(CFLAGS) -DevmAM437x -DSOC_AM335x

# Make Rule for the SRC Files
TEST_SRC_OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(TEST_SRC))
ENTRY_OBJ = $(patsubst %.S, $(OBJDIR)/%.oa, $(ENTRY_SRC))

#VPATH=$(SRC_DIR)

all:$(BINDIR)/$(EXE)

$(BINDIR)/$(EXE): $(TEST_SRC_OBJS)
	@echo linking $(TEST_SRC_OBJS) into $@ ...
	$(CC) $(TEST_SRC_OBJS) $(INTERNALLINKDEFS) -o $@

$(OBJDIR)/%.o: %.c
	@echo compiling $< ... 
	$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS) $< -o $@

$(OBJDIR)/%.$(ASMOBJEXT): %.S $(OBJDIR)/.created
	@echo compiling $< ...
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS)  $< -o $@


clean:
	@rm -f $(BINDIR)/$(EXE)
	@rm -f $(BINDIR)/$(EXE).map
	@rm -f $(TEST_SRC_OBJS) $(ENTRY_OBJ)

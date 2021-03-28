# Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
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
export DEVICE=omapl138
endif


# Cross tools
ifdef TOOLCHAIN_PATH_Arm9
# Support backwards compatibility with KeyStone1 approach
 CC = $(TOOLCHAIN_PATH_Arm9)/bin/armcl
 AR = $(TOOLCHAIN_PATH_Arm9)/bin/armar
 LNK = $(TOOLCHAIN_PATH_Arm9)/bin/armlnk
 SIZE = $(TOOLCHAIN_PATH_Arm9)/bin/armofd
endif

AVAR=arm9
LIBEXT=ae9
BUILD_PROFILE?=release

# INCLUDE Directories
CSL_DIR = $(PDK_INSTALL_PATH)/ti/csl/
USB_DIR = $(PDK_INSTALL_PATH)/ti/drv/usb

INCDIR = $(PDK_INSTALL_PATH);
INCDIR += $(USB_DIR);
INCDIR += $(USB_DIR)/src/include;
INCDIR += $(USB_DIR)/src/usb_func/include;
INCDIR += $(USB_DIR)/soc;
INCDIR += $(TOOLCHAIN_PATH_Arm9)/lib/src;
INCDIR += $(USB_DIR)/example/ramdisk;
INCDIR += $(USB_DIR)/example/shell

SBL_SRC_DIR ?= $(PDK_INSTALL_PATH)/ti/boot/sbl
SBL_SOC_DIR = $(SBL_SRC_DIR)/soc

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

BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/lcdkOMAPL138/$(AVAR)/$(BUILD_PROFILE)/ti.board.$(LIBEXT)"
CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(DEVICE)/$(AVAR)/$(BUILD_PROFILE)/ti.csl.$(LIBEXT)"
CSL_INIT_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/$(DEVICE)/$(AVAR)/$(BUILD_PROFILE)/ti.csl.init.$(LIBEXT)"
RTSLIB_PATH = "$(TOOLCHAIN_PATH_Arm9)/lib/libc.a"
PERIPHERAL_LIB = $(USB_LIBS) $(UART_LIBS) $(BOARD_LIB) $(OSAL_LIB) $(I2C_LIBS) $(FATFS_LIB) $(CSL_LIB) $(CSL_INIT_LIB) $(RTSLIB_PATH)
 
DEFFLAGS = --define=SOC_OMAPL138 --define=BUILD_ARM
# Compiler options
INTERNALDEFS += -g $(DEBUG_FLAG) -mv5e --code_state=32 -me -g $(DEFFLAGS) --diag_wrap=off --diag_warning=225 --display_error_number  -DSOC_OMAPL138 -DlcdkOMAPL138

# Executable using device independent library and device object file
EXE=usb_d_msc_$(DEVICE).out

# Linker options
INTERNALLINKDEFS = -mv5e --code_state=32 -me -g $(DEVFLAGS) --diag_wrap=off --diag_warning=225 --display_error_number -z $(USB_DIR)/example/omapl13x_linker_arm.cmd 

INCS = -I. -I$(strip $(subst ; , -I,$(INCDIR)))

#List the Source Files
VPATH = $(USB_DIR)/example/usb_dev/msc:$(USB_DIR)/example/ramdisk:$(USB_DIR)/example/common

TEST_SRC = \
     usb_msc_structs.c \
	dev_msc.c \
	usbdmscglue.c \
    ramdiskutils.c \
    usb_osal.c \
    timer.c

	
# FLAGS for the SourceFiles
CFLAGS += -g --inline_recursion_limit=20
SRC_CFLAGS = $(CFLAGS) -eo.o -ea.ao -DlcdkOMAPL138

# Make Rule for the SRC Files
TEST_SRC_OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(TEST_SRC))
ENTRY_OBJ = $(patsubst %.S, $(OBJDIR)/%.oa, $(ENTRY_SRC))
COMMONSRCASMOBJS = $(patsubst %.asm, $(OBJDIR)/%.oa, $(COMMONSRCASM))


$(BINDIR)/$(EXE): $(TEST_SRC_OBJS)
	@echo linking $(TEST_SRC_OBJS) into $@ ...
	$(CC) $(TEST_SRC_OBJS) $(INTERNALLINKDEFS) -o $@ $(PERIPHERAL_LIB) 

$(OBJDIR)/%.o: %.c
	@echo compiling $< ... 
	$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS) $< -o

clean:
	@rm -f $(BINDIR)/$(EXE)
	@rm -f $(BINDIR)/$(EXE).map
	@rm -f $(TEST_SRC_OBJS) $(ENTRY_OBJ)

# Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com/
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
DIAGOBJDIR = $(PDK_DIAG_DIR)/obj/$(BOARD)/$(TARGET)
DIAGBINDIR = $(PDK_DIAG_DIR)/bin/$(BOARD)/$(TARGET)
SDDIAGBINDIR = $(PDK_DIAG_DIR)/bin/$(BOARD)/sd

# ARMV7 link directory that contain built peripheral libraries
ARMV7LIBDIR ?= ./lib

# Cross tools
ifdef TOOLCHAIN_PATH_A9
 CC = $(TOOLCHAIN_PATH_A9)/bin/$(CROSS_TOOL_PRFX)gcc
 AC = $(TOOLCHAIN_PATH_A9)/bin/$(CROSS_TOOL_PRFX)as
 AR = $(TOOLCHAIN_PATH_A9)/bin/$(CROSS_TOOL_PRFX)ar
 LD = $(TOOLCHAIN_PATH_A9)/bin/$(CROSS_TOOL_PRFX)gcc
 OBJCOPY = $(TOOLCHAIN_PATH_A9)/bin/$(CROSS_TOOL_PRFX)objcopy
endif

# INCLUDE Directories
CSL_DIR = $(PDK_INSTALL_PATH)/ti/csl/
STARTERWARE_DIR = $(PDK_INSTALL_PATH)/ti/starterware
INCDIR := $(CSL_DIR);$(PDK_INSTALL_PATH);$(PDK_DIAG_DIR);$(PDK_DIAG_DIR)/src/$(BOARD)/include;$(STARTERWARE_DIR)/include;$(STARTERWARE_DIR)/include/hw/;$(STARTERWARE_DIR)/include/armv7a;$(STARTERWARE_DIR)/include/utils;$(STARTERWARE_DIR)/soc/armv7a

# Libraries
BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/a9/release/ti.board.aa9fg"
OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/am437x/a9/release/ti.osal.aa9fg"
UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/am437x/a9/release/ti.drv.uart.aa9fg"
I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/am437x/a9/release/ti.drv.i2c.aa9fg"
CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/am437x/a9/release/ti.csl.aa9fg"
PERIPHERAL_LIB = $(OSAL_LIB) $(UART_LIB) $(I2C_LIB) $(CSL_LIB)

# Compiler options
INTERNALDEFS = -g -gdwarf-3 -gstrict-dwarf -Wall $(DEBUG_FLAG) -D__ARMv7 -D$(BOARD) -DSOC_$(DEVICE) -mtune=cortex-a9 -march=armv7-a -marm -mfloat-abi=hard -mfpu=neon -DDEBUG_PRINT

# Linker options
INTERNALLINKDEFS = -mfloat-abi=hard -Wl,--undefined,__aeabi_uidiv -Wl,--undefined,__aeabi_idiv --entry Entry -nostartfiles -static -Wl,--gc-sections -Wl,-T $(PDK_DIAG_DIR)/diag/common/$(DEVICE)/linker.cmd -Wl,--start-group -l"c" -lrdimon -l"m" -l"nosys" $(BOARD_LIB) $(PERIPHERAL_LIB) -Wl,--end-group $(LDFLAGS)
BINFLAGS=-O binary

# Executable using device independent library and device object file
EXE=uart_diagExample_$(BOARD)_$(TARGET).out
TESTNAME=uart

#
# Where the application will be loaded to. This is required to generate
# image with Header (Load Address and Size)
#
IMG_LOAD_ADDR = 0x80000000

ifeq ($(OS),Windows_NT)
export TIIMAGE=tiimage.exe
else
export TIIMAGE=tiimage
endif

OBJEXT = o
ASMOBJEXT = ao
SRCDIR = $(PDK_DIAG_DIR)/diag/uart/src

INCS = -I. -I$(strip $(subst ;, -I,$(INCDIR)))

VPATH=$(SRCDIR):$(PDK_DIAG_DIR)/diag/common/$(DEVICE):$(PDK_INSTALL_PATH)/ti/drv/uart/soc/am437x:$(STARTERWARE_DIR)/soc:$(STARTERWARE_DIR)/soc/armv7a/gcc

#List the Source Files
TEST_SRC = \
	uart_diag.c
	
TEST_SRC_DEV = \

#Common entry object
ENTRY_SRC = diag_entry.S

#Common diagnostic source objects
DIAG_SRC = gic.c \
           cpu.c \
           diag_common_cfg.c

# FLAGS for the SourceFiles
CFLAGS += -Wall -O2
SRC_CFLAGS = -I. $(CFLAGS) -g -gdwarf-3 -gstrict-dwarf -Wall

# Make Rule for the SRC Files
TEST_SRC_OBJS = $(patsubst %.c, $(DIAGOBJDIR)/%.$(OBJEXT), $(TEST_SRC))
ENTRY_OBJ = $(patsubst %.S, $(DIAGOBJDIR)/%.$(ASMOBJEXT), $(ENTRY_SRC))
TEST_SRC_DEV_OBJS = $(patsubst %.c, $(DIAGOBJDIR)/%.$(OBJEXT), $(TEST_SRC_DEV))
DIAG_SRC_OBJS = $(patsubst %.c, $(DIAGOBJDIR)/%.$(OBJEXT), $(DIAG_SRC))

all:$(DIAGBINDIR)/$(EXE)

$(DIAGBINDIR)/$(EXE): $(TEST_SRC_OBJS) $(TEST_SRC_DEV_OBJS) $(ENTRY_OBJ) $(DIAG_SRC_OBJS) $(DIAGBINDIR)/.created $(DIAGOBJDIR)/.created $(STARTERWARE_DIR)/tools/ti_image/$(TIIMAGE)
	@echo linking $(TEST_SRC_OBJS) $(TEST_SRC_DEV_OBJS) $(ENTRY_OBJ) $(DIAG_SRC_OBJS) into $@ ...
	@$(CC) $(TEST_SRC_OBJS) $(TEST_SRC_DEV_OBJS) $(ENTRY_OBJ) $(DIAG_SRC_OBJS) $(INTERNALLINKDEFS) -Wl,-Map=$(DIAGBINDIR)/mem_$(BOARD).map -o $@
	mkdir -p $(SDDIAGBINDIR)
	$(OBJCOPY) $(BINFLAGS) $(DIAGBINDIR)/$(EXE) $(DIAGBINDIR)/$(TESTNAME).bin
	$(STARTERWARE_DIR)/tools/ti_image/$(TIIMAGE) $(IMG_LOAD_ADDR) NONE $(DIAGBINDIR)/$(TESTNAME).bin $(SDDIAGBINDIR)/$(TESTNAME)_TEST

$(DIAGOBJDIR)/%.$(OBJEXT): %.c $(DIAGOBJDIR)/.created
	@echo compiling $< ...
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS)  $< -o $@

$(DIAGOBJDIR)/%.$(ASMOBJEXT): %.S $(DIAGOBJDIR)/.created
	@echo compiling $< ...
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS)  $< -o $@

$(DIAGOBJDIR)/.created:
	@mkdir -p $(DIAGOBJDIR)
	@touch $(DIAGOBJDIR)/.created

$(DIAGBINDIR)/.created:
	@mkdir -p $(DIAGBINDIR)
	@touch $(DIAGBINDIR)/.created

$(STARTERWARE_DIR)/tools/ti_image/$(TIIMAGE):
	gcc -o $(STARTERWARE_DIR)/tools/ti_image/$(TIIMAGE) $(STARTERWARE_DIR)/tools/ti_image/tiimage.c

clean:
	@rm -f $(DIAGBINDIR)/$(EXE)
	@rm -f $(TEST_SRC_OBJS) $(TEST_SRC_DEV_OBJS) $(ENTRY_OBJ) $(DIAGBINDIR)/.created $(DIAGOBJDIR)/.created

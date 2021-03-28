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

# Output directories
ifeq ($(TESTMODE),STRESS_TEST)
DIAGOBJDIR ?= $(PDK_DIAG_DIR)/obj/$(BOARD)/$(TARGET)/stress
else
ifeq ($(TESTMODE),COMPLIANCE_TEST)
DIAGOBJDIR ?= $(PDK_DIAG_DIR)/obj/$(BOARD)/$(TARGET)/compliance
else
DIAGOBJDIR ?= $(PDK_DIAG_DIR)/obj/$(BOARD)/$(TARGET)/functional
endif
endif
DIAGBINDIR ?= $(PDK_DIAG_DIR)/bin/$(BOARD)/$(TARGET)

# ARMV7 link directory that contain built peripheral libraries
ARMV7LIBDIR ?= ./lib

# Cross tools
# Set compiler/archiver/linker commands and include paths
CODEGEN_INCLUDE = $(TOOLCHAIN_PATH_R5)/include
CC = $(TOOLCHAIN_PATH_R5)/bin/armcl
AR = $(TOOLCHAIN_PATH_R5)/bin/armar
LNK = $(TOOLCHAIN_PATH_R5)/bin/armlnk
SIZE = $(TOOLCHAIN_PATH_R5)/bin/armofd
RTSLIB_NAME = rtsv7R4_T_le_v3D16_eabi.lib

# INCLUDE Directories
CSL_DIR = $(PDK_INSTALL_PATH)/ti/csl/
INCDIR := $(CSL_DIR);$(PDK_INSTALL_PATH);$(PDK_DIAG_DIR);$(PDK_DIAG_DIR)/src/$(BOARD)/include;$(PDK_DIAG_DIR)/diag/common/$(DEVICE);$(CODEGEN_INCLUDE);$(PDK_DIAG_DIR)/src/evmKeystone3/include

# Libraries
BOARD_LIB = "$(PDK_DIAG_DIR)/lib/$(BOARD)/r5f/release/ti.board.aer5f"
UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/am65xx/r5f/release/ti.drv.uart.aer5f"
I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/am65xx/r5f/release/ti.drv.i2c.aer5f"
CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/am65xx/r5f/release/ti.csl.aer5f"
CSL_INIT_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/am65xx/r5f/release/ti.csl.init.aer5f"
OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/am65xx/r5f/release/ti.osal.aer5f"
SCICLIENT_LIB = "$(PDK_INSTALL_PATH)/ti/drv/sciclient/lib/am65xx/mcu1_0/release/sciclient.aer5f"
PERIPHERAL_LIB = $(UART_LIB) $(I2C_LIB) $(CSL_LIB) $(CSL_INIT_LIB) $(SCICLIENT_LIB)

RTSLIB_PATH = "$(TOOLCHAIN_PATH_R5)/lib/libc.a"
LNK_LIBS = -l$(PERIPHERAL_LIB) -l$(BOARD_LIB) -l$(OSAL_LIB) $(RTSLIB_PATH)

# Compiler options
INTERNALDEFS = -g -ms -DMAKEFILE_BUILD -c -qq -pdsw225  $(DEBUG_FLAG) -D$(BOARD) -DSOC_$(DEVICE) --endian=little -mv7R5 --abi=eabi -eo.oer5f --code_state=16 -ea.ser5f --symdebug:dwarf --embed_inline_assembly --float_support=vfpv3d16 -ms -oe -op0 -os --optimize_with_debug --inline_recursion_limit=20  -DBUILD_MCU1_0 -DBUILD_MCU -DBARE_METAL

# Linker options
INTERNALLINKDEFS = --emit_warnings_as_errors -w -q -u _c_int00 $(PDK_DIAG_DIR)/diag/common/$(DEVICE)/linker_r5.lds -c -mv7R5 --diag_suppress=10063 --opt='--float_support=vfpv3d16 --endian=little -mv7R5 --abi=eabi -qq -pdsw225 -g -ms -DMAKEFILE_BUILD -oe --symdebug:dwarf -ms -op2 -os --optimize_with_debug --inline_recursion_limit=20 --diag_suppress=23000' --strict_compatibility=on -x --zero_init=on $(LNK_LIBS)

# Executable using device independent library and device object file
ifeq ($(TESTMODE),STRESS_TEST)
EXE=uartStress_diagExample_$(BOARD)_$(TARGET).xer5f
else
ifeq ($(TESTMODE),COMPLIANCE_TEST)
EXE=uartCompliance_diagExample_$(BOARD)_$(TARGET).out
else
EXE=uart_diagExample_$(BOARD)_$(TARGET).out
endif
endif

OBJEXT = oer5f
ASMOBJEXT = oer5f
SRCDIR = $(PDK_DIAG_DIR)/diag/uart/src

INCS = -I. -I$(strip $(subst ;, -I,$(INCDIR)))

VPATH=$(SRCDIR):$(PDK_DIAG_DIR)/diag/common/$(DEVICE):$(PDK_INSTALL_PATH)/ti/drv/uart/soc/am65xx:$(PDK_INSTALL_PATH)/ti/drv/i2c/soc/am65xx

#List the Source Files
ifeq ($(TESTMODE),STRESS_TEST)
TEST_SRC = uart_stress_test.c
else
TEST_SRC = uart_diag.c
endif

TEST_SRC_DEV = 

#Common entry object
ENTRY_SRC = diag_entry_r5.asm

#Common diagnostic source objects
DIAG_SRC = diag_common_cfg.c

# FLAGS for the SourceFiles
CFLAGS += -O2
SRC_CFLAGS = -I. $(CFLAGS) -g -eo.$(OBJEXT) -ea.$(ASMOBJEXT)

# Make Rule for the SRC Files
TEST_SRC_OBJS = $(patsubst %.c, $(DIAGOBJDIR)/%.$(OBJEXT), $(TEST_SRC))
ENTRY_OBJ = $(patsubst %.asm, $(DIAGOBJDIR)/%.$(ASMOBJEXT), $(ENTRY_SRC))
TEST_SRC_DEV_OBJS = $(patsubst %.c, $(DIAGOBJDIR)/%.$(OBJEXT), $(TEST_SRC_DEV))
DIAG_SRC_OBJS = $(patsubst %.c, $(DIAGOBJDIR)/%.$(OBJEXT), $(DIAG_SRC))

NUM_PROCS = 1

ifeq ($(OS),Windows_NT)
  NUM_PROCS = $(NUMBER_OF_PROCESSORS)
else
  NUM_PROCS = $(shell grep -c ^processor /proc/cpuinfo)
endif

BUILD_LIB_ONCE = $(TOOLCHAIN_PATH_R5)/lib/$(RTSLIB_NAME)

all:$(DIAGBINDIR)/$(EXE)

$(DIAGBINDIR)/$(EXE): $(TEST_SRC_OBJS) $(TEST_SRC_DEV_OBJS) $(ENTRY_OBJ) $(DIAG_SRC_OBJS) $(DIAGBINDIR)/.created $(DIAGOBJDIR)/.created $(BUILD_LIB_ONCE)
	@echo linking $(TEST_SRC_OBJS) $(TEST_SRC_DEV_OBJS) $(ENTRY_OBJ) $(DIAG_SRC_OBJS) into $@ ...
	@$(LNK) $(TEST_SRC_OBJS) $(TEST_SRC_DEV_OBJS) $(ENTRY_OBJ) $(DIAG_SRC_OBJS) $(INTERNALLINKDEFS) -m"$(DIAGBINDIR)/uart_$(BOARD).map" -o $@

$(DIAGOBJDIR)/%.$(OBJEXT): %.c $(DIAGOBJDIR)/.created
	@echo compiling $< ...
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS) -fr=$(DIAGOBJDIR) -fs=$(DIAGOBJDIR) -fc $<

$(DIAGOBJDIR)/%.$(ASMOBJEXT): %.asm $(DIAGOBJDIR)/.created
	@echo compiling $< ...
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS) -fr=$(DIAGOBJDIR) -fs=$(DIAGOBJDIR) -fa $<

$(DIAGOBJDIR)/.created:
	@mkdir -p $(DIAGOBJDIR)
	@touch $(DIAGOBJDIR)/.created

$(DIAGBINDIR)/.created:
	@mkdir -p $(DIAGBINDIR)
	@touch $(DIAGBINDIR)/.created

$(BUILD_LIB_ONCE):
	@echo \# $@ not found, building  $@ ...
	@$(TOOLCHAIN_PATH_R5)/lib/mklib --pattern=$(RTSLIB_NAME) --parallel=$(NUM_PROCS) --compiler_bin_dir=$(TOOLCHAIN_PATH_R5)/bin

clean:
	@rm -f $(DIAGBINDIR)/$(EXE)
	@rm -f $(TEST_SRC_OBJS) $(TEST_SRC_DEV_OBJS) $(ENTRY_OBJ) $(DIAGBINDIR)/.created $(DIAGBINDIR)/*.map $(DIAGOBJDIR)/.created

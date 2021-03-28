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
ARMV8LIBDIR ?= ./lib

# Cross tools
CODEGEN_INCLUDE = $(TOOLCHAIN_PATH_A53)/aarch64-elf/include
CC = $(TOOLCHAIN_PATH_A53)/bin/aarch64-elf-gcc
AR = $(TOOLCHAIN_PATH_A53)/bin/aarch64-elf-ar
LNK = $(TOOLCHAIN_PATH_A53)/bin/aarch64-elf-gcc
SIZE = $(TOOLCHAIN_PATH_A53)/bin/aarch64-elf-size

# INCLUDE Directories
CSL_DIR = $(PDK_INSTALL_PATH)/ti/csl/
INCDIR := $(CSL_DIR);$(PDK_INSTALL_PATH);$(PDK_DIAG_DIR);$(PDK_DIAG_DIR)/src/$(BOARD)/include;$(PDK_DIAG_DIR)/diag/common/$(DEVICE);$(CODEGEN_INCLUDE);$(PDK_DIAG_DIR)/src/evmKeystone3/include;$(PDK_INSTALL_PATH)/ti/drv/emac/firmware/icss_dualmac/config

# Libraries
BOARD_LIB = "$(PDK_DIAG_DIR)/lib/$(BOARD)/a53/release/ti.board.aa53fg"
UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/am65xx/a53/release/ti.drv.uart.aa53fg"
I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/am65xx/a53/release/ti.drv.i2c.aa53fg"
EMAC_LIB = "$(PDK_INSTALL_PATH)/ti/drv/emac/lib/am65xx/a53/release/ti.drv.emac.aa53fg"
PRUSS_LIB = "$(PDK_INSTALL_PATH)/ti/drv/pruss/lib/am65xx/a53/release/ti.drv.pruss.aa53fg"
CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/am65xx/a53/release/ti.csl.aa53fg"
CSL_INIT_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/am65xx/a53/release/ti.csl.init.aa53fg"
OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/am65xx/a53/release/ti.osal.aa53fg"
UDMA_LIB = "$(PDK_INSTALL_PATH)/ti/drv/udma/lib/am65xx/mpu1_0/release/udma.aa53fg"
SCICLIENT_LIB = "$(PDK_INSTALL_PATH)/ti/drv/sciclient/lib/am65xx/mpu1_0/release/sciclient.aa53fg"
PERIPHERAL_LIB = $(UART_LIB) $(I2C_LIB) $(CSL_LIB) $(CSL_INIT_LIB) $(EMAC_LIB) $(PRUSS_LIB) $(UDMA_LIB) $(SCICLIENT_LIB)

# Compiler options
INTERNALDEFS = -Wimplicit -Wall $(DEBUG_FLAG) -D__ARMv8 -D$(BOARD) -DSOC_$(DEVICE) -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections -c -mcpu=cortex-a53+fp+simd -g -mabi=lp64 -mcmodel=large -mstrict-align -mfix-cortex-a53-835769 -mfix-cortex-a53-843419 -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast -Werror

# Linker options
INTERNALLINKDEFS = -Werror -Wl,-static -Wl,--gc-sections -nostartfiles -Wl,-T $(PDK_DIAG_DIR)/diag/icssg_emac/build/am65xx_idk/armv8/linker_a53.lds -Wl,--build-id=none --entry Entry -Wl,--start-group -l"c" -lrdimon -l"m" -l"gcc" -l"stdc++" $(BOARD_LIB) $(PERIPHERAL_LIB) $(OSAL_LIB) -Wl,--end-group $(LDFLAGS)

# Executable using device independent library and device object file
ifeq ($(TESTMODE),STRESS_TEST)
EXE=icssgEmacStress_diagExample_$(BOARD)_$(TARGET).out
else
ifeq ($(TESTMODE),COMPLIANCE_TEST)
EXE=icssgEmacCompliance_diagExample_$(BOARD)_$(TARGET).out
else
EXE=icssgEmac_diagExample_$(BOARD)_$(TARGET).out
endif
endif

OBJEXT = o
ASMOBJEXT = ao
SRCDIR = $(PDK_DIAG_DIR)/diag/icssg_emac/src:$(PDK_DIAG_DIR)/diag/emac/src:$(PDK_INSTALL_PATH)/ti/drv/emac/firmware/icss_dualmac/config

INCS = -I. -I$(strip $(subst ;, -I,$(INCDIR)))

VPATH=$(SRCDIR):$(PDK_DIAG_DIR)/diag/common/$(DEVICE):$(PDK_INSTALL_PATH)/ti/drv/uart/soc/am65xx:$(PDK_INSTALL_PATH)/ti/drv/i2c/soc/am65xx

#List the Source Files
TEST_SRC = \
	icssg_emac_test.c \
	emac_fw_config_dual_mac.c

TEST_SRC_DEV = 

#Common entry object
ENTRY_SRC = diag_entry.S

#Common diagnostic source objects
DIAG_SRC = diag_common_cfg.c

# FLAGS for the SourceFiles
CFLAGS += -DDIAG_$(TESTMODE) -Wall -O2
SRC_CFLAGS = -I. $(CFLAGS) -g -gdwarf-3 -gstrict-dwarf -Wall 

# Make Rule for the SRC Files
TEST_SRC_OBJS = $(patsubst %.c, $(DIAGOBJDIR)/%.$(OBJEXT), $(TEST_SRC))
ENTRY_OBJ = $(patsubst %.S, $(DIAGOBJDIR)/%.$(ASMOBJEXT), $(ENTRY_SRC))
TEST_SRC_DEV_OBJS = $(patsubst %.c, $(DIAGOBJDIR)/%.$(OBJEXT), $(TEST_SRC_DEV))
DIAG_SRC_OBJS = $(patsubst %.c, $(DIAGOBJDIR)/%.$(OBJEXT), $(DIAG_SRC))

all:$(DIAGBINDIR)/$(EXE)

$(DIAGBINDIR)/$(EXE): $(TEST_SRC_OBJS) $(TEST_SRC_DEV_OBJS) $(ENTRY_OBJ) $(DIAG_SRC_OBJS) $(DIAGBINDIR)/.created $(DIAGOBJDIR)/.created
	@echo linking $(TEST_SRC_OBJS) $(TEST_SRC_DEV_OBJS) $(ENTRY_OBJ) $(DIAG_SRC_OBJS) into $@ ...
	@$(CC) $(TEST_SRC_OBJS) $(TEST_SRC_DEV_OBJS) $(ENTRY_OBJ) $(DIAG_SRC_OBJS) $(INTERNALLINKDEFS) -Wl,-Map=$(DIAGBINDIR)/icssgEmac_$(BOARD).map -o $@

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

clean:
	@rm -f $(DIAGBINDIR)/$(EXE)
	@rm -f $(TEST_SRC_OBJS) $(TEST_SRC_DEV_OBJS) $(ENTRY_OBJ) $(DIAGBINDIR)/.created $(DIAGBINDIR)/*.map $(DIAGOBJDIR)/.created

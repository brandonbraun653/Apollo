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

MODULE =uart
#DEVICE_LC = $(shell echo $(DEVICE) | tr A-Z a-z)
lc = $(subst A,a,$(subst B,b,$(subst C,c,$(subst D,d,$(subst E,e,$(subst F,f,$(subst G,g,$(subst H,h,$(subst I,i,$(subst J,j,$(subst K,k,$(subst L,l,$(subst M,m,$(subst N,n,$(subst O,o,$(subst P,p,$(subst Q,q,$(subst R,r,$(subst S,s,$(subst T,t,$(subst U,u,$(subst V,v,$(subst W,w,$(subst X,x,$(subst Y,y,$(subst Z,z,$1))))))))))))))))))))))))))
ifeq ($(DEVICE),K2K)
	DEVICE2 = K2H
else
	DEVICE2 = $(DEVICE)
endif
DEVICE_LC = $(call lc,$(DEVICE))
ifeq ($(DEVICE_LC),k2k)
	DEVICE_LC2 = k2h
else
	DEVICE_LC2 = $(DEVICE_LC)
endif

# Module directories
CSL_DIR = $(PDK_INSTALL_PATH)/ti/csl/
UART_DIR = $(PDK_INSTALL_PATH)/ti/drv/$(MODULE)
OSAL_DIR = $(PDK_INSTALL_PATH)/ti/osal
BOARD_DIR = $(PDK_INSTALL_PATH)/ti/board

# Output directories
TESTOBJDIR = $(UART_DIR)/test/baremetal/c66/$(DEVICE_LC)/obj
TESTBINDIR = $(UART_DIR)/test/baremetal/c66/$(DEVICE_LC)/bin

# LIB Directories
CSL_LIB_DIR = $(CSL_DIR)/lib/$(DEVICE_LC)/c66
UART_LIB_DIR = $(UART_DIR)/lib/$(DEVICE_LC2)/c66
OSAL_LIB_DIR = $(OSAL_DIR)/lib/nonos/$(DEVICE_LC2)/c66
BOARD_LIB_DIR = $(BOARD_DIR)/lib/evm$(DEVICE2)/c66

# INCLUDE Directories
INCDIR := $(CSL_DIR);$(UART_DIR);$(PDK_INSTALL_PATH);$(OSAL_DIR);$(BOARD_DIR)

# Cross tools
ifdef CGTOOLS
# Support backwards compatibility with KeyStone1 approach
 CC = $(CGTOOLS)/bin/cl6x
endif

COPTS= -g -c -mv6600 -ml3 -I $(CGTOOLS)/include
AOPTS= -g -c -mv6600 -eogem.oa

ifeq ($(ENDIAN),big)
ifeq ($(ABI_FORMAT),coffabi)
	COPTS+= -me --abi=coffabi -eo.oe66e
	AOPTS+= -me --abi=coffabi -ea.se66e
else
	COPTS+= -me --abi=eabi -eo.oe66e --strip_coff_underscore
	AOPTS+= -me --abi=eabi -ea.se66e --strip_coff_underscore
	OBJEXT = oe66e
	ASMOBJEXT = se66e
endif
	CSL_LIB= $(CSL_LIB_DIR)/ti.csl.ae66e
	CSL_INTC_LIB= $(CSL_LIB_DIR)/ti.csl.intc.ae66e
	OSAL_LIB= $(OSAL_LIB_DIR)/ti.osal.ae66e
	BOARD_LIB= $(BOARD_LIB_DIR)/ti.board.ae66e
	UART_LIB= $(UART_LIB_DIR)/ti.drv.uart.$(DEVICE_LC2).ae66e
else
ifeq ($(ABI_FORMAT),coffabi)
	COPTS+= --abi=coffabi -eo.oe66
	AOPTS+= --abi=coffabi  -ea.se66
else
	COPTS+= --abi=eabi -eo.oe66 --strip_coff_underscore
	AOPTS+= --abi=eabi -ea.se66 --strip_coff_underscore
endif
	CSL_LIB= $(CSL_LIB_DIR)/ti.csl.ae66
	CSL_INTC_LIB= $(CSL_LIB_DIR)/ti.csl.intc.ae66
	OSAL_LIB= $(OSAL_LIB_DIR)/ti.osal.ae66
	BOARD_LIB= $(BOARD_LIB_DIR)/ti.board.ae66
	UART_LIB= $(UART_LIB_DIR)/ti.drv.uart.$(DEVICE_LC2).ae66
	OBJEXT = oe66
	ASMOBJEXT = se66
endif

# Libraries
LIB= -l$(BOARD_LIB) -l$(UART_LIB) -l$(OSAL_LIB) -l$(CSL_LIB) -l$(CSL_INTC_LIB) -l$(CGTOOLS)/lib/rts6600_elf.lib -l$(CGTOOLS)/lib/libc.a 

# Compiler options
INTERNALDEFS = -DSOC_$(DEVICE) -DEVM_$(DEVICE) -DBARE_METAL

# Linker options
LOPTS = -mv6600 --abi=eabi -z -c

# Executable using device independent library and device object file
EXE1=UART_BasicExample_$(DEVICE)_c66xTestProject
EXE2=UART_BasicExample_$(DEVICE)_c66xExampleProject

TESTDIR = $(UART_DIR)/test/src
EXAMPLEDIR = $(UART_DIR)/example/sample/src

INCS = -I. -I$(strip $(subst ;, -I,$(INCDIR)))

VPATH=$(TESTDIR):$(EXAMPLEDIR)

#List the Source Files
TEST_SRC = \
	main_uart_test.c

TEST_DMA_SRC = \
	main_dma_test.c

EXAMPLE_SRC = \
	main_uart_example.c

# Make Rule for the SRC Files
TEST_SRC_OBJS = $(patsubst %.c, $(TESTOBJDIR)/%.$(OBJEXT), $(TEST_SRC))
TEST_SRC_DMA_OBJS = $(patsubst %.c, $(TESTOBJDIR)/%.$(OBJEXT), $(TEST_DMA_SRC))
EXAMPLE_SRC_OBJS = $(patsubst %.c, $(TESTOBJDIR)/%.$(OBJEXT), $(EXAMPLE_SRC))

all:$(TESTOBJDIR)/.created $(TESTBINDIR)/$(EXE1).out $(TESTBINDIR)/$(EXE2).out

$(TESTBINDIR)/$(EXE1).out: $(TEST_SRC_OBJS) $(TESTBINDIR)/.created $(TESTOBJDIR)/.created
	echo linking $(TEST_SRC_OBJS) into $@ ...
	$(CC) $(LOPTS) $(UART_DIR)/test/$(DEVICE_LC2)/linker.cmd $(TEST_SRC_OBJS) $(LIB) -o $@ -m $(TESTBINDIR)/$(EXE1).map

$(TESTBINDIR)/$(EXE2).out: $(EXAMPLE_SRC_OBJS) $(TESTBINDIR)/.created $(TESTOBJDIR)/.created
	echo linking $(EXAMPLE_SRC_OBJS) into $@ ...
	$(CC) $(LOPTS) $(UART_DIR)/test/$(DEVICE_LC2)/linker.cmd $(EXAMPLE_SRC_OBJS) $(LIB) -o $@ -m $(TESTBINDIR)/$(EXE2).map

$(TESTOBJDIR)/%.$(OBJEXT): %.c $(TESTOBJDIR)/.created
	echo compiling $< ...
	$(CC) -c $(COPTS) $(INTERNALDEFS) $(INCS)  $< -fr $(dir $@) -fo $(notdir $@)

$(TESTOBJDIR)/%.$(ASMOBJEXT): %.S $(TESTOBJDIR)/.created
	@echo compiling $< ...
	@$(CC) -c $(AOPTS) $(INTERNALDEFS) $(INCS)  $< -fr $(dir $@) -fo $(notdir $@)

$(TESTOBJDIR)/.created:
	mkdir -p $(TESTOBJDIR)
	touch $(TESTOBJDIR)/.created

$(TESTBINDIR)/.created:
	mkdir -p $(TESTBINDIR)
	touch $(TESTBINDIR)/.created

clean:
	@rm -f $(TESTBINDIR)/$(EXE1).out $(TESTBINDIR)/$(EXE1).map
	@rm -f $(TESTBINDIR)/$(EXE2).out $(TESTBINDIR)/$(EXE2).map
	@rm -f $(TEST_SRC_OBJS) $(EXAMPLE_SRC_OBJS) $(TESTBINDIR)/.created $(TESTOBJDIR)/.created



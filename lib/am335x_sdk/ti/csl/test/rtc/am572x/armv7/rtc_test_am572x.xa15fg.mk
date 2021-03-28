#*******************************************************************************
#* FILE PURPOSE: Lower level makefile for Creating Component Libraries
#*******************************************************************************
#* FILE NAME: ./test/am572x/armv7/rtc_test_am572x.xa15fg.mk
#*
#* DESCRIPTION: Defines Source Files, Compilers flags and build rules
#*
#*
#*******************************************************************************
#

#
# Macro definitions referenced below
#
empty =
space =$(empty) $(empty)
 CC = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)gcc
 AC = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)as
 AR = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)ar
 LD = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)gcc

# Libraries
BOARD_LIB = "$(PDK_INSTALL_PATH)/ti/board/lib/idkam572x/armv7/ti.board.aa15fg"
UART_LIB = "$(PDK_INSTALL_PATH)/ti/drv/uart/lib/armv7/ti.drv.uart.aa15fg"
I2C_LIB = "$(PDK_INSTALL_PATH)/ti/drv/i2c/lib/armv7/ti.drv.i2c.aa15fg"
CSL_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/am572x/a15/ti.csl.aa15fg"
CSL_INIT_LIB = "$(PDK_INSTALL_PATH)/ti/csl/lib/am572x/a15/ti.csl.init.aa15fg"
OSAL_LIB = "$(PDK_INSTALL_PATH)/ti/osal/lib/nonos/am572x/armv7/ti.osal.aa15fg"
LIB = $(BOARD_LIB) $(UART_LIB) $(I2C_LIB) $(CSL_LIB) $(CSL_INIT_LIB) $(OSAL_LIB)

# INCLUDE Directories
INCDIR := $(PDK_INSTALL_PATH)/ti/csl;$(PDK_INSTALL_PATH);$(PDK_INSTALL_PATH)/ti/csl/test/rtc;$(PDK_INSTALL_PATH)/ti/csl/test/rtc/am572x/armv7

INCS = -I. -I$(TOOLCHAIN_PATH_A15)/include -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(INCDIR))))
OBJEXT = oa15fg
AOBJEXT = sa15fg
CFLAGS_INTERNAL = -mno-unaligned-access -c -mtune=cortex-a15 -marm -DDRA7xx -gstrict-dwarf -Wall -D__ARMv7 -D_LITTLE_ENDIAN=1 -mcpu=cortex-a15 -mfpu=neon -mfloat-abi=hard -mabi=aapcs -g
ASFLAGS_INTERNAL =  -mcpu=cortex-a15 -mfpu=neon -mfloat-abi=hard
ARFLAGS_INTERNAL = cr
LNKFLAGS_INTERNAL = -mfloat-abi=hard -Wl,--undefined,__aeabi_uidiv -Wl,--undefined,__aeabi_idiv --entry Entry -nostartfiles -static -Wl,--gc-sections -Wl,-T $(PDK_INSTALL_PATH)/ti/csl/soc/am572x/src/csl_a15_linker.lds -Wl,--start-group -l"c" -lrdimon -l"m" -l"nosys" $(LIB) -Wl,--end-group $(LDFLAGS)
INTERNALDEFS = -MD -MF $@.dep
INTERNALLINKDEFS = -o $@
OBJDIR =  $(LIBDIR)/am572x//armv7/obj

#List the C Source Files
COMMONSRCC = \
    test/rtc/am572x/armv7/rtc_main.c

# FLAGS for the COMMONSRC Files
COMMONSRCCFLAGS =   -DSOC_AM572x  -I./test/rtc/am572x/armv7 -I. 

# Make Rule for the SRC Files
COMMONSRCCOBJS = $(patsubst %.c, $(OBJDIR)/%.$(OBJEXT), $(COMMONSRCC))

$(COMMONSRCCOBJS): $(OBJDIR)/%.$(OBJEXT): %.c
	-@echo cla15fg $< ...
	if [ ! -d $(@D) ]; then $(MKDIR) $(@D) ; fi;
	$(RM) $@.dep
	$(CC) $(CFLAGS_INTERNAL) $(COMMONSRCCFLAGS) $(INTERNALDEFS) $(INCS) $< -o $@

#Create Empty rule for dependency
$(COMMONSRCCOBJS):.\test\rtc\am572x\armv7\rtc_test_am572x.xa15fg.mk
.\test\rtc\am572x\armv7\rtc_test_am572x.xa15fg.mk:

#Include Depedency for COMMONSRC Files
ifneq (clean,$(MAKECMDGOALS))
 -include $(COMMONSRCCOBJS:%.$(OBJEXT)=%.$(OBJEXT).dep)
endif


$(BINDIR)/am572x/armv7/rtc_test_am572x.xa15fg : $(COMMONSRCCOBJS)
	@echo linking $? into $@ ...
	if [ ! -d $(BINDIR)/am572x/armv7 ]; then $(MKDIR) $(BINDIR)/am572x/armv7 ; fi;
	$(LD) $? $(LNKFLAGS_INTERNAL) $(INTERNALLINKDEFS)

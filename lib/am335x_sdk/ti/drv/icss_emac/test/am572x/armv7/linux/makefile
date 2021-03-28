#
# Macro definitions referenced below
#

empty =
space =$(empty) $(empty)

ARMV7OBJDIR ?= ./obj/$(DEVICE)
ARMV7BINDIR ?= ./bin/$(DEVICE)
ARMV7LIBDIR ?= ./lib

ARMV7OBJDIR := $(ARMV7OBJDIR)/icss_emac/test
ARMV7BINDIR := $(ARMV7BINDIR)/icss_emac/test

#Cross tools
ifdef CROSS_TOOL_INSTALL_PATH
# Support backwards compatibility with KeyStone1 approach
 CC = $(CROSS_TOOL_INSTALL_PATH)/$(CROSS_TOOL_PRFX)gcc
 AC = $(CROSS_TOOL_INSTALL_PATH)/$(CROSS_TOOL_PRFX)as
 AR = $(CROSS_TOOL_INSTALL_PATH)/$(CROSS_TOOL_PRFX)ar
 LD = $(CROSS_TOOL_INSTALL_PATH)/$(CROSS_TOOL_PRFX)gcc
endif

# INCLUDE Directories
ICSS_EMAC_INC_DIR = $(PDK_INSTALL_PATH)/ti/drv/icss_emac
PRUSS_INC_DIR = $(PDK_INSTALL_PATH)/ti/drv/pruss

ICSS_EMAC_SRC_DIR ?= $(PDK_INSTALL_PATH)/ti/drv/icss_emac
ICSS_EMAC_TEST_DIR = $(ICSS_EMAC_SRC_DIR)/test
ICSS_EMAC_ARM_LIN_TEST_DIR = $(ICSS_EMAC_TEST_DIR)/src/armv7/linux
ICSS_EMAC_DEVICE_DIR = $(ICSS_EMAC_SRC_DIR)/soc/$(DEVICE)
ICSS_EMAC_FW_DIR = $(ICSS_EMAC_SRC_DIR)/firmware/icss_dualemac/config

INCDIR := $(PDK_INSTALL_PATH);$(ICSS_EMAC_INC_DIR);$(PRUSS_INC_DIR);$(ICSS_EMAC_TEST_DIR)/../../../..;\
		  $(ICSS_EMAC_ARM_LIN_TEST_DIR)

# Libraries
ICSS_EMAC_LIB = -licss_emac
PRUSS_LIB = -L $(PDK_INSTALL_PATH)/ti/drv/pruss/lib -lpruss
OSAL_LIB = -L $(PDK_INSTALL_PATH)/ti/osal/lib/linux -losal

# Firmware
FW_BIN_PATH = $(PDK_PKG_PATH)/ti/drv/icss_emac/firmware/icss_dualemac/bin/am572x/a15_0
FW_LIB_PRU0 = $(FW_BIN_PATH)/REV2/icss_dualemac_PRU0.bin
FW_LIB_PRU1 = $(FW_BIN_PATH)/REV2/icss_dualemac_PRU1.bin
FW_LIB_PRU0_V1 = $(FW_BIN_PATH)/REV1/icss_dualemac_PRU0.bin
FW_LIB_PRU1_V1 = $(FW_BIN_PATH)/REV1/icss_dualemac_PRU1.bin
FW_LNK_CMD_REV1 = $(PDK_PKG_PATH)/ti/build/pruss/lnk_a8_a9_a15_REV1_linux.cmd
FW_LNK_CMD_REV2 = $(PDK_PKG_PATH)/ti/build/pruss/lnk_a8_a9_a15_REV2_linux.cmd


ifeq ($(USEDYNAMIC_LIB), yes)
#presuming ARM executable would depend on dynamic library dependency
EXE_EXTN = _so
LIBS     = $(OSAL_LIB) $(PRUSS_LIB) $(ICSS_EMAC_LIB)
else
#forcing ARM executable to depend on static LLD libraries
EXE_EXTN =
LIBS     = -Wl,-Bstatic $(OSAL_LIB) $(PRUSS_LIB) $(ICSS_EMAC_LIB) -Wl,-Bdynamic
endif


# Compiler options
INTERNALDEFS = $(DEBUG_FLAG) -D__ARMv7 -D__LINUX_USER_SPACE -D_LITTLE_ENDIAN=1 -DMAKEFILE_BUILD -D_GNU_SOURCE -DidkAM572x -DSOC_AM572x -DUIO_INTERRUPT_ONE_SHOT_MODE

# Linker options
INTERNALLINKDEFS = -Wl,--start-group -L $(ARMV7LIBDIR) $(LIBS) -lrt -Wl,--end-group -pthread $(LDFLAGS)

MAIN_TEST_EXE=icss_emacMainTest$(EXE_EXTN).out

OBJEXT = o

SRCDIR = $(ICSS_EMAC_TEST_DIR)/src:$(ICSS_EMAC_ARM_LIN_TEST_DIR):$(ICSS_EMAC_DEVICE_DIR):$(ICSS_EMAC_FW_DIR):

INCS = -I. -I$(strip $(subst ;, -I,$(INCDIR)))

VPATH=$(SRCDIR)

#List the Source Files
DEVICE_TEST_SRC = \
	icss_emacSoc.c  \
        icss_emacFwConfig.c \

OSAL_TEST_SRC = \
	mmap_helper.c

MAIN_TEST_SRC = \
	main.c	\
	test_common_utils.c

# FLAGS for the SourceFiles
SRC_CFLAGS = -I. $(CFLAGS)

# Make Rule for the SRC Files
DEVICE_TEST_SRC_OBJS = $(patsubst %.c, $(ARMV7OBJDIR)/%.$(OBJEXT), $(DEVICE_TEST_SRC))
OSAL_TEST_SRC_OBJS = $(patsubst %.c, $(ARMV7OBJDIR)/%.$(OBJEXT), $(OSAL_TEST_SRC))
MAIN_TEST_SRC_OBJS = $(patsubst %.c, $(ARMV7OBJDIR)/%.$(OBJEXT), $(MAIN_TEST_SRC))

all:$(ARMV7BINDIR)/$(MAIN_TEST_EXE)

$(ARMV7BINDIR)/$(MAIN_TEST_EXE): $(MAIN_TEST_SRC_OBJS) $(OSAL_TEST_SRC_OBJS) $(DEVICE_TEST_SRC_OBJS) $(ARMV7BINDIR)/.created
	@echo linking $(MAIN_TEST_SRC_OBJS) $(OSAL_TEST_SRC_OBJS) $(DEVICE_TEST_SRC_OBJS) ${FW_LIB_PRU0} ${FW_LIB_PRU1} ${FW_LIB_PRU0_V1} ${FW_LIB_PRU1_V1} ${FW_LNK_CMD_REV1} ${FW_LNK_CMD_REV2} into $@ ...
	@$(CC) $(MAIN_TEST_SRC_OBJS) $(OSAL_TEST_SRC_OBJS) $(DEVICE_TEST_SRC_OBJS) ${FW_LIB_PRU0} ${FW_LIB_PRU1} ${FW_LIB_PRU0_V1} ${FW_LIB_PRU1_V1} ${FW_LNK_CMD_REV1} ${FW_LNK_CMD_REV2} $(INTERNALLINKDEFS) -o $@

$(ARMV7OBJDIR)/%.$(OBJEXT): %.c $(ARMV7OBJDIR)/.created
	@echo compiling $< ...
	@$(CC) -c $(SRC_CFLAGS) $(INTERNALDEFS) $(INCS)  $< -o $@

$(ARMV7OBJDIR)/.created:
	@mkdir -p $(ARMV7OBJDIR)
	@touch $(ARMV7OBJDIR)/.created

$(ARMV7BINDIR)/.created:
	@mkdir -p $(ARMV7BINDIR)
	@touch $(ARMV7BINDIR)/.created

clean:
	@rm -fr $(ARMV7OBJDIR)
	@rm -fr $(ARMV7BINDIR)


#
# Macro definitions referenced below
#

empty =
space =$(empty) $(empty)

ARMV7OBJDIR ?= ./obj
ARMV7BINDIR ?= ./bin
ARMV7LIBDIR ?= ./lib/linux

ARMV7OBJDIR := $(ARMV7OBJDIR)/osal/test
ARMV7BINDIR := $(ARMV7BINDIR)/osal/test

#Cross tools
ifdef CROSS_TOOL_INSTALL_PATH
# Support backwards compatibility with KeyStone1 approach
 CC = $(CROSS_TOOL_INSTALL_PATH)/$(CROSS_TOOL_PRFX)gcc
 AC = $(CROSS_TOOL_INSTALL_PATH)/$(CROSS_TOOL_PRFX)as
 AR = $(CROSS_TOOL_INSTALL_PATH)/$(CROSS_TOOL_PRFX)ar
 LD = $(CROSS_TOOL_INSTALL_PATH)/$(CROSS_TOOL_PRFX)gcc
endif

# INCLUDE Directories
OSAL_INC_DIR = $(PDK_INSTALL_PATH)/ti/osal
OSAL_SRC_DIR ?= $(PDK_INSTALL_PATH)/ti/osal
OSAL_TEST_DIR = $(OSAL_SRC_DIR)/test
OSAL_ARM_LIN_TEST_DIR = $(OSAL_TEST_DIR)/linux

INCDIR := $(PDK_INSTALL_PATH);$(OSAL_INC_DIR)

# Libraries
OSAL_LIB = -losal

ifeq ($(USEDYNAMIC_LIB), yes)
#presuming ARM executable would depend on dynamic library dependency
EXE_EXTN = _so
LIBS     = $(OSAL_LIB)
else
#forcing ARM executable to depend on static LLD libraries
EXE_EXTN =
LIBS     = -Wl,-Bstatic $(OSAL_LIB) -Wl,-Bdynamic
endif


# Compiler options
INTERNALDEFS = $(DEBUG_FLAG) -D__ARMv7 -D__LINUX_USER_SPACE -D_LITTLE_ENDIAN=1 -DMAKEFILE_BUILD -D_GNU_SOURCE

# Linker options
INTERNALLINKDEFS = -Wl,--start-group -L $(ARMV7LIBDIR) $(LIBS) -lrt -Wl,--end-group -pthread $(LDFLAGS)

MAIN_TEST_EXE=osalMainTest$(EXE_EXTN)

OBJEXT = o

SRCDIR = $(OSAL_ARM_LIN_TEST_DIR):

INCS = -I. -I$(strip $(subst ;, -I,$(INCDIR)))

VPATH=$(SRCDIR)

#List the Source Files
MAIN_TEST_SRC = \
	main_osal_test_linux.c

# FLAGS for the SourceFiles
SRC_CFLAGS = -I. $(CFLAGS)

# Make Rule for the SRC Files
MAIN_TEST_SRC_OBJS = $(patsubst %.c, $(ARMV7OBJDIR)/%.$(OBJEXT), $(MAIN_TEST_SRC))

all:$(ARMV7BINDIR)/$(MAIN_TEST_EXE)

$(ARMV7BINDIR)/$(MAIN_TEST_EXE): $(MAIN_TEST_SRC_OBJS) $(ARMV7BINDIR)/.created
	@echo linking $(MAIN_TEST_SRC_OBJS) into $@ ...
	@$(CC) $(MAIN_TEST_SRC_OBJS) $(INTERNALLINKDEFS) -o $@

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


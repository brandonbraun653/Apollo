include $(PDK_INSTALL_PATH)/ti/build/Rules.make

MODULE_NAME = csl_intc

SRCDIR = .
INCDIR = .

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk csl

# List all the internal submodules whose interface header files
# need to be included for this module
INCLUDE_INTERNAL_INTERFACES += csl

# Common source files and CFLAGS across all platforms and cores

#Include src files for only the modules defined under csl_intc_COMP_LIST
SRCS_COMMON =
# Include all common files and also the top level makefiles as CSL is the base module
PACKAGE_SRCS_COMMON += makefile.mk \
                       _csl_intcIntrEnDisRes.asm  _csl_intcIsrDispatch.asm  _csl_intcNmiDummy.asm \
                       csl_intcAsmUtils.c  _csl_intcCombEventDispatcher.c  \
                       csl_intcExcep.c csl_intcHookIsr.c csl_intcInit.c \
                       csl_intcPlugEventHandler.c  csl_intcClose.c  _csl_intcDispatcher.c \
                       csl_intcGetHwStatus.c  csl_intcHwControl.c  csl_intcOpen.c  _csl_intcResource.c

CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

# INTC modules
-include $(PDK_CSL_COMP_PATH)/src/intc/src_files_intc.mk

# Core/SoC/platform specific source files and CFLAGS
# Example:
#   SRCS_<core/SoC/platform-name> =
#   CFLAGS_LOCAL_<core/SoC/platform-name> =

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ROOTDIR)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
#     and need not be explicitly specified here

# Nothing beyond this point

#
# This file is the makefile for building CSL_TRIM library.
#
#   Copyright (c) Texas Instruments Incorporated 2019
#

.PHONY : gensizes

include $(PDK_INSTALL_PATH)/ti/build/Rules.make

MODULE_NAME = csl_trim

SRCDIR = .
INCDIR = .

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk csl_trim

# List all the internal submodules whose interface header files
# need to be included for this module
INCLUDE_INTERNAL_INTERFACES += csl_trim

# Common source files and CFLAGS across all platforms and cores
#Include src files for only the modules defined under csl_COMP_LIST
SRCS_COMMON =
# Include all common files and also the top level makefiles as CSL is the base module
PACKAGE_SRCS_COMMON = makefile makefile_csl_trim.mk csl_component.mk arch/makefile_init.mk src_files_csl_trim.mk \
                      csl_bootcfgAux.h  csl_bootcfg.h cslr_bootcfg.h \
                      csl_mainpage.h   src/ip/uart/V0 \
                      arch/csl_arch.h  arch/cslr64.h test/csl_test_component.mk

CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

#Include src files for only the modules defined under csl_intc_COMP_LIST
SRCS_COMMON =
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

# csl_trim modules
-include $(PDK_CSL_COMP_PATH)/src_files_csl_trim.mk

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

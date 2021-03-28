#
# This file is the makefile for building GPMC RTOS library.
#
#   Copyright (c) Texas Instruments Incorporated 2016
#
include $(PDK_INSTALL_PATH)/ti/build/Rules.make
include $(PDK_GPMC_COMP_PATH)/src/src_files_common.mk

MODULE_NAME = gpmc_profile

SRCDIR += soc/$(SOC)
INCDIR += soc
# Common source files across all platforms and cores
SRCS_COMMON += GPMC_soc.c

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk edma

PACKAGE_SRCS_COMMON += soc/$(SOC)

ifeq ($(CORE),$(filter $(CORE), a15_0 a9host a8host))
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) -finstrument-functions -gdwarf-3 -g -D_ENABLE_BM
else
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) --entry_parm=address --exit_hook=ti_utils_exit --exit_parm=address --entry_hook=ti_utils_entry -g -D_ENABLE_BM
endif

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

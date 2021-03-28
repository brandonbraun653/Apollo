#
# This file is the makefile for building CSL MCAN app.
#
#   Copyright (c) Texas Instruments Incorporated 2016
#
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

APP_NAME = csl_hyperbus_app
BUILD_OS_TYPE=baremetal

SRCDIR = .
INCDIR = .

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk csl_arch board csl

COMP_LIST_COMMON = board csl csl_init osal_nonos uart i2c spi
ifeq ($(SOC), $(filter $(SOC), j721e))
COMP_LIST_COMMON += sciclient
endif

# Common source files and CFLAGS across all platforms and cores
PACKAGE_SRCS_COMMON = .
ifeq ($(SOC),$(filter $(SOC), j721e))
SRCS_COMMON = hyperbus_app_main.c
endif

CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

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

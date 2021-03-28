# Filename: Makefile
#
# This file is the makefile for building the pm rtos example.
#
#   Copyright (C) 2015 - 2017 Texas Instruments Incorporated
#
#******************************************************************************
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

APP_NAME = pm_rtos_app

ifeq ($(SOC),$(filter $(SOC), k2g))
    SRCDIR = src/k2g
else
    SRCDIR = src
endif
INCDIR = . src

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk pm_example_utils pm_rtos bios xdc

# List all the components required by the application
COMP_LIST_COMMON = csl pm_rtos pm_example_utils osal_tirtos bios xdc
ifeq ($(SOC),$(filter $(SOC), am572x am571x am335x am437x k2g))
COMP_LIST_COMMON += uart i2c board
endif

# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_ipu1_0 = $(PDK_PM_COMP_PATH)/examples/pmrtos/pm.cfg
ifeq ($(SOC),$(filter $(SOC), k2g))
XDC_CFG_FILE_a15_0 = $(PDK_PM_COMP_PATH)/examples/pmrtos/k2g/pm_a15.cfg
XDC_CFG_FILE_c66x = $(PDK_PM_COMP_PATH)/examples/pmrtos/k2g/pm_c66.cfg
else
XDC_CFG_FILE_a15_0 = $(PDK_PM_COMP_PATH)/examples/pmrtos/pm_a15.cfg
XDC_CFG_FILE_c66x = $(PDK_PM_COMP_PATH)/examples/pmrtos/pm_c66.cfg
endif
XDC_CFG_FILE_a8host = $(PDK_PM_COMP_PATH)/examples/pmrtos/pm_a8.cfg
XDC_CFG_FILE_a9host = $(PDK_PM_COMP_PATH)/examples/pmrtos/pm_a9.cfg

CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

# Common source files and CFLAGS across all platforms and cores
ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x tda3xx dra78x am335x am437x k2g))
SRCS_COMMON += pm_main.c
endif
PACKAGE_SRCS_COMMON = .

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

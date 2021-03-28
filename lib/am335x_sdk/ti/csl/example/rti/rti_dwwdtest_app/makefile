#
# This file is the makefile for building CSL rti app.
#
#   Copyright (c) Texas Instruments Incorporated 2015-2020
#
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

APP_NAME = csl_rti_dwwd_test_app

BUILD_OS_TYPE=baremetal

SRCDIR = .
INCDIR =

SRCDIR += $(PDK_INSTALL_PATH)/ti/build/unit-test/Unity/src $(PDK_INSTALL_PATH)/ti/build/unit-test/config
INCDIR += $(PDK_INSTALL_PATH)/ti/build/unit-test/Unity/src $(PDK_INSTALL_PATH)/ti/build/unit-test/config

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk csl_arch

# List all the components required by the application
ifeq ($(CSL_BUILD),$(filter $(CSL_BUILD), CSL))
  COMP_LIST_COMMON = csl
else
  COMP_LIST_COMMON = csl2 csl_trim
endif

COMP_LIST_COMMON += csl_utils_common csl_uart_console
ifeq ($(SOC),$(filter $(SOC), am65xx))
  COMP_LIST_COMMON += csl_init osal_nonos board uart sciclient
endif
# Common source files and CFLAGS across all platforms and cores
PACKAGE_SRCS_COMMON = .

ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x))
  SRCS_COMMON = rti_app_dwwd.c
endif

ifeq ($(SOC),$(filter $(SOC), am65xx))
  SRCS_COMMON = rti_app_dwwd_v1.c
endif

CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

ifeq ($(WDT_RESET), enable)
  CFLAGS_LOCAL_COMMON += -DWDT_RESET
ifeq ($(CORE),mcu1_0)
  EXTERNAL_LNKCMD_FILE_LOCAL = $(SOC)/linker_$(CORE).lds
endif
endif

ifeq ($(CORE),ipu1_0)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_m4.cmd
endif
ifeq ($(CORE),c66x)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_dsp.cmd
endif

LNKFLAGS_LOCAL_a15_0 += --entry Entry
LNKFLAGS_LOCAL_mpu1_0 += --entry Entry

ifeq ($(SOC),$(filter $(SOC), am65xx))
SRCS_COMMON += unity.c unity_config.c

CFLAGS_LOCAL_COMMON += -DUNITY_INCLUDE_CONFIG_H
endif

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

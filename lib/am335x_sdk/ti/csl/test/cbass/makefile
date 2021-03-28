#
# This file is the makefile for building CSL CBASS Test App.
#
#   Copyright (c) Texas Instruments Incorporated 2019
#
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

APP_NAME = csl_cbass_baremetal_test_app
BUILD_OS_TYPE=baremetal
SRCDIR = .
INCDIR =

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk

ifeq ($(CSL_BUILD),$(filter $(CSL_BUILD), CSL))
  COMP_LIST_COMMON = csl
else
  COMP_LIST_COMMON = csl2 csl_trim
endif

# List all the components required by the application
ifeq ($(SOC),$(filter $(SOC), am65xx))
ifeq ($(CORE),$(filter $(CORE), mcu1_0 mcu1_1))
  COMP_LIST_COMMON += csl_init osal_nonos sciclient board uart
endif
endif

# Common source files and CFLAGS across all platforms and cores
PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

SRCS_COMMON += cbass_test_main.c cbass_test_qos.c cbass_test_err.c

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

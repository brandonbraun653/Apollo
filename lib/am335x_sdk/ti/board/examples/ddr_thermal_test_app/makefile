#
# This file is the makefile for building ddr test app.
#
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

APP_NAME = board_ddr_thermal_test_app

ifeq ($(IS_BAREMETAL),yes)
BUILD_OS_TYPE = baremetal
else
BUILD_OS_TYPE = tirtos
CFLAGS_OS_DEFINES = -DUSE_BIOS
EXTERNAL_INTERFACES = bios xdc
COMP_LIST_COMMON    = osal_tirtos
ifeq ($(SOC), j721e)
  XDC_CFG_FILE_$(CORE) = $(PDK_INSTALL_PATH)/ti/build/$(SOC)/sysbios_$(ISA).cfg
endif
endif
SRCDIR = src
INCDIR = inc

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk $(EXTERNAL_INTERFACES)
INCLUDE_INTERNAL_INTERFACES =

ifeq ($(CSL_BUILD),$(filter $(CSL_BUILD), CSL))
  COMP_LIST_COMMON = csl
else
  COMP_LIST_COMMON = csl2 csl_trim
endif

# List all the components required by the application
ifeq ($(SOC),$(filter $(SOC), j721e))
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
  COMP_LIST_COMMON += csl_init osal_nonos sciclient board uart i2c
endif
endif

# Common source files and CFLAGS across all platforms and cores
PACKAGE_SRCS_COMMON = .
SRCS_COMMON = main.c

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

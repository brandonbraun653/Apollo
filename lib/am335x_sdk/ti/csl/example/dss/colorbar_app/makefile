#
# This file is the makefile for building DSS Color Bar app.
#
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

APP_NAME = csl_dss_colorbar_app
BUILD_OS_TYPE=baremetal

SRCDIR = .
INCDIR =

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk

# List all the components required by the application
COMP_LIST_COMMON = csl csl_init
ifeq ($(BOARD),$(filter $(BOARD), am65xx_evm))
COMP_LIST_COMMON += i2c osal_nonos uart board sciclient
endif

# Common source files and CFLAGS across all platforms and cores
PACKAGE_SRCS_COMMON = .
SRCS_COMMON = dss_colorbar_app.c

LNKFLAGS_LOCAL_mpu1_0 += --entry Entry
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

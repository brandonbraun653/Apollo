# Makefile for McASP device loopback unit test app
include $(PDK_INSTALL_PATH)/ti/build/Rules.make
export DISABLE_RECURSE_DEPS

#Name of the directory created under packages/ti/binary/
APP_NAME = MCASP_DeviceLoopback_Regression_TestApp
# Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
LOCAL_APP_NAME = MCASP_DeviceLoopback_Regression_$(BOARD)_$(CORE)TestApp

ifeq ($(SOC),$(filter $(SOC), am65xx))
SRCDIR = ../src ../../ ../evmAM65xx/src
INCDIR = ../src ../include ../../ ../evmAM65xx/include
# Common source files across all platforms and cores
SRCS_COMMON += audioSample_io_regression.c audioSample_main.c deviceloopback.c audio_evmInit.c mcasp_cfg.c mcasp_debug.c regression.c

ifeq ($(CORE),$(filter $(CORE), mpu1_0))
# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = ../evmAM65xx/a53/mcaspUnitTest_a53.cfg
endif

ifeq ($(CORE),$(filter $(CORE), mcu1_0))
# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = ../evmAM65xx/r5/mcaspUnitTest_r5.cfg
endif

endif

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = bios xdc pdk

# List all the components required by the application
COMP_LIST_COMMON = csl mcasp osal_tirtos uart board

CFLAGS_MCASP_UT = -DMCASP_MASTER -DDEVICE_LOOPBACK

# Enable below to log various events
# CFLAGS_MCASP_UT += -DMCASP_ENABLE_DEBUG_LOG

ifeq ($(SOC),$(filter $(SOC), am65xx))
COMP_LIST_COMMON += udma sciclient
endif

PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) $(CFLAGS_MCASP_UT)

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

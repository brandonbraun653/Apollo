# Makefile for McASP device loopback unit test app
include $(PDK_INSTALL_PATH)/ti/build/Rules.make
export DISABLE_RECURSE_DEPS

#Name of the directory created under packages/ti/binary/
APP_NAME = MCASP_AudioDCAnalogLoopback_TestApp

SRCDIR = ../src ../../
INCDIR = ../src ../include ../../

SRCS_COMMON = audioSample_io.c audioSample_main.c audio_evmInit.c mcasp_cfg.c mcasp_debug.c

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = bios xdc pdk

COMP_LIST_COMMON = csl mcasp osal_tirtos uart board

CFLAGS_MCASP_UT = -DMCASP_MASTER -DAUDIO_DC_ANALOG_TEST

ifeq ($(SOC), $(filter $(SOC), j721e))
  SRCDIR += ../j721e/src
  INCDIR += ../j721e/include

  COMP_LIST_COMMON += udma sciclient i2c

  # Enable XDC build for application by providing XDC CFG File per core
  XDC_CFG_FILE_$(CORE) = $(PDK_INSTALL_PATH)/ti/build/$(SOC)/sysbios_$(ISA).cfg
  XDC_CFG_UPDATE_$(CORE) = ../j721e/mcasp_extra_config.xs
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


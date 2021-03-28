# Makefile for GPIO LED Blink unit test app
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

ifeq ($(IS_BAREMETAL),yes)
BUILD_OS_TYPE = baremetal
CFLAGS_OS_DEFINES =
LNKFLAGS_LOCAL_mpu1_0  += --entry Entry
COMP_LIST_COMMON =  csl_init osal_nonos
EXTERNAL_INTERFACES =
XDC_CFG_FILE_mpu1_0 =
XDC_CFG_FILE_mcu1_0 =
else
BUILD_OS_TYPE = tirtos
CFLAGS_OS_DEFINES = -DUSE_BIOS
EXTERNAL_INTERFACES = bios xdc
COMP_LIST_COMMON    = osal_tirtos
ifeq ($(SOC),$(filter $(SOC), am65xx))
XDC_CFG_FILE_mpu1_0 = ./am65xx/gpioLedBlinkTest_a53.cfg
XDC_CFG_FILE_mcu1_0 = ./am65xx/gpioLedBlinkTest_r5.cfg
endif
ifeq ($(SOC),$(filter $(SOC), j721e j7200))
XDC_CFG_FILE_$(CORE) = $(PDK_INSTALL_PATH)/ti/build/$(SOC)/sysbios_$(ISA).cfg
endif
endif

ifeq ($(BUILD_OS_TYPE), tirtos)
GPIO_OS_TESTPREFIX=
else
GPIO_OS_TESTPREFIX=_Baremetal
endif

#Name of the directory created under packages/ti/binary/
APP_NAME = GPIO$(GPIO_OS_TESTPREFIX)_LedBlink_TestApp
# Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
LOCAL_APP_NAME =  GPIO$(GPIO_OS_TESTPREFIX)_LedBlink_$(BOARD)_$(CORE)TestApp

SRCDIR = . src
INCDIR = . src

# Common source files across all platforms and cores
SRCS_COMMON += main_led_blink.c GPIO_board.c

ifeq ($(SOC),$(filter $(SOC), am65xx))
SRCDIR += am65xx
endif

ifeq ($(SOC),$(filter $(SOC), j721e))
SRCDIR += j721e
endif

ifeq ($(SOC),$(filter $(SOC), j7200))
SRCDIR += j7200
endif
# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk $(EXTERNAL_INTERFACES)

# List all the components required by the application
#COMP_LIST_COMMON  += gpio_profile uart board csl profiling
COMP_LIST_COMMON  += gpio uart board csl

ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
COMP_LIST_COMMON += sciclient i2c
endif


PACKAGE_SRCS_COMMON = ../../test
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) $(CFLAGS_GPIO_UT) $(CFLAGS_OS_DEFINES)

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

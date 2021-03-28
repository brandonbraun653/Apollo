# Makefile for I2C sample app
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

APP_NAME = drv_i2c_led_blink_test

ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex tda3xx dra78x))
SRCDIR = . src
INCDIR = . src
# Common source files across all platforms and cores
SRCS_COMMON += i2c_led_blink.c
endif

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = bios xdc pdk

# List all the components required by the application
COMP_LIST_COMMON = i2c osal_tirtos csl

# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_ipu1_0 = i2cSample.cfg
XDC_CFG_FILE_c66x = i2cSample.cfg

PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

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

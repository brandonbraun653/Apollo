# Makefile for UART sample app
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

APP_NAME = drv_uart_intr_mode_app

#Name of the directory created under packages/ti/binary/
APP_NAME = UART_BasicExample_Intr_ExampleProject
# Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
LOCAL_APP_NAME =  UART_BasicExample_Intr_$(BOARD)_$(CORE)Example_Project


ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x dra78x tda2ex tda3xx))
SRCDIR = . src
INCDIR = . src
# Common source files across all platforms and cores
SRCS_COMMON += uart_intr_test.c
endif

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = bios xdc pdk

# List all the components required by the application
COMP_LIST_COMMON = uart osal_tirtos csl

ifeq ($(SOC),$(filter $(SOC), am65xx))
COMP_LIST_COMMON += sciclient
endif

# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = uartSample.cfg

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

# Makefile for EMAC sample app
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

#Name of the directory created under packages/ti/binary/
APP_NAME = Emac_Icssg_TestApp

# Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
LOCAL_APP_NAME =  EMAC_Icssg_$(BOARD)_$(CORE)TestApp

SRCDIR += $(PDK_EMAC_COMP_PATH)/firmware/icss_dualmac/config
INCDIR += $(PDK_EMAC_COMP_PATH)/firmware/icss_dualmac/config
ifeq ($(SOC),$(filter $(SOC), j721e))
SRCS_COMMON += main_j721e.c test_utils_k3.c emac_fw_config_dual_mac.c
endif
# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = bios xdc pdk

# List all the components required by the application
COMP_LIST_COMMON = emac uart uart_console osal_tirtos csl pruss board udma sciclient i2c

ifeq ($(CORE),$(filter $(CORE), mpu1_0))
# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = ./j721e/emacUnitTest_a72.cfg
EXTERNAL_LNKCMD_FILE_LOCAL = $(pdk_PATH)/ti/drv/emac/test/EmacLoopbackTest/j721e/emac_linker_a72.lds
endif

ifeq ($(CORE),$(filter $(CORE), mcu1_0))
# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = ./j721e/emacUnitTest_r5.cfg
EXTERNAL_LNKCMD_FILE_LOCAL = $(pdk_PATH)/ti/drv/emac/test/EmacLoopbackTest/j721e/emac_linker_r5.lds
endif

PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) -DEMAC_TEST_APP_ICSSG

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

# Makefile for EMAC sample app
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

ifeq ($(SMP), enable)
    #Name of the directory created under packages/ti/binary/
    APP_NAME = Emac_Cpsw_Smp_TestApp

    # Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
    LOCAL_APP_NAME =  EMAC_Cpsw_$(BOARD)_$(CORE)_Smp_TestApp
else
    #Name of the directory created under packages/ti/binary/
    APP_NAME = Emac_Cpsw_TestApp

    # Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
    LOCAL_APP_NAME =  EMAC_Cpsw_$(BOARD)_$(CORE)TestApp
endif

SRCDIR += $(PDK_INSTALL_PATH)/ti/build/unit-test/Unity/src $(PDK_INSTALL_PATH)/ti/build/unit-test/config
INCDIR += $(PDK_INSTALL_PATH)/ti/build/unit-test/Unity/src $(PDK_INSTALL_PATH)/ti/build/unit-test/config

SRCS_COMMON += main_am65xx.c test_utils_k3.c unity_config.c unity.c

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = bios xdc pdk

# List all the components required by the application
COMP_LIST_COMMON = emac uart uart_console osal_tirtos csl board udma sciclient


ifeq ($(CORE),$(filter $(CORE), mpu1_0))
# Enable XDC build for application by providing XDC CFG File per core
ifeq ($(SMP), enable)
XDC_CFG_FILE_$(CORE) = $(PDK_INSTALL_PATH)/ti/build/am65xx/sysbios_smp_a53.cfg
else
XDC_CFG_FILE_$(CORE) = ./am65xx/emacUnitTest_a53.cfg
endif
EXTERNAL_LNKCMD_FILE_LOCAL = $(pdk_PATH)/ti/drv/emac/test/EmacLoopbackTest/am65xx/emac_linker_a53.lds
endif

ifeq ($(CORE),$(filter $(CORE), mcu1_0))
# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = ./am65xx/emacUnitTest_r5.cfg
EXTERNAL_LNKCMD_FILE_LOCAL = $(pdk_PATH)/ti/drv/emac/test/EmacLoopbackTest/am65xx/emac_linker_r5.lds
SRCS_ASM_COMMON += dlfo_workaround.asm
endif
PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) -DEMAC_TEST_APP_CPSW -DUNITY_INCLUDE_CONFIG_H

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

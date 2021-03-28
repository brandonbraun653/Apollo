# Makefile for EMAC sample app
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

APP_NAME = drv_emac_packet_inspection_app

ifeq ($(BOARD),$(filter $(BOARD), evmDRA72x evmDRA75x evmDRA78x))
SRCDIR = . ..
INCDIR = . ..
# Common source files across all platforms and cores
SRCS_COMMON += main_evmDRA7xx.c test_osal.c
endif

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = bios xdc pdk

# List all the components required by the application
COMP_LIST_COMMON = emac i2c uart osal_tirtos board drv_emac_test_utils csl

# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_ipu1_0 = emac_test_m4.cfg
XDC_CFG_FILE_a15_0 = emac_test_a15.cfg

PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON += $(PDK_CFLAGS) -D$(BOARD)

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

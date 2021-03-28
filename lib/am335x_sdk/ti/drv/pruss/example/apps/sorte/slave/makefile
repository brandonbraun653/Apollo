# Makefile for UART sample app
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

APP_NAME = pruss_app_sorte_slave

SRCDIR = ../src
INCDIR = ../src
# Common source files across all platforms and cores
SRCS_COMMON += main.c

CFLAGS_LOCAL_COMMON = -finstrument-functions -DSORTE_SLAVE
EXTERNAL_LNKCMD_FILE_LOCAL = $(pruss_app_sorte_slave_PATH)/../src/lnk.cmd

LNKFLAGS_LOCAL_COMMON = -g -gdwarf-3 -gstrict-dwarf -Wall -Wl,--defsym,STACKSIZE=0x1C000 -Wl,--defsym,HEAPSIZE=0x400


ifeq ($(BOARD),$(filter $(BOARD), icev2AM335x))
EXTERNAL_LNKCMD_FILE_LOCAL = ${PDK_INSTALL_PATH}/ti/build/pruss/lnk_a8_a9_a15_REV1.cmd
# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = ../src/sorte_icev2am335x_app.cfg
EXT_LIB_$(CORE) = $(pruss_sorte_slave_PATH)/bin/$(SOC)/a8host/REV1/sorte_slave_PRU0.bin
EXT_LIB_$(CORE) += $(pruss_sorte_slave_PATH)/bin/$(SOC)/a8host/REV1/sorte_slave_PRU1.bin
endif

ifeq ($(BOARD),$(filter $(BOARD), idkAM437x))
EXTERNAL_LNKCMD_FILE_LOCAL = ${PDK_INSTALL_PATH}/ti/build/pruss/lnk_a8_a9_a15_REV1.cmd
# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = ../src/sorte_idkAM437x_app.cfg
EXT_LIB_$(CORE) = $(pruss_sorte_slave_PATH)/bin/$(SOC)/a9host/REV1/sorte_slave_PRU0.bin
EXT_LIB_$(CORE) += $(pruss_sorte_slave_PATH)/bin/$(SOC)/a9host/REV1/sorte_slave_PRU1.bin
endif
ifeq ($(BOARD),$(filter $(BOARD), idkAM572x))
EXTERNAL_LNKCMD_FILE_LOCAL = ${PDK_INSTALL_PATH}/ti/build/pruss/lnk_a8_a9_a15_REV2.cmd
# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = ../src/sorte_idkAM572x_app.cfg
EXT_LIB_$(CORE) = $(pruss_sorte_slave_PATH)/bin/$(SOC)/a15_0/REV2/sorte_slave_PRU0.bin
EXT_LIB_$(CORE) += $(pruss_sorte_slave_PATH)/bin/$(SOC)/a15_0/REV2/sorte_slave_PRU1.bin
endif

ifeq ($(BOARD),$(filter $(BOARD), idkAM574x))
EXTERNAL_LNKCMD_FILE_LOCAL = ${PDK_INSTALL_PATH}/ti/build/pruss/lnk_a8_a9_a15_REV2.cmd
# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = ../src/sorte_idkAM574x_app.cfg
EXT_LIB_$(CORE) = $(pruss_sorte_slave_PATH)/bin/$(SOC)/a15_0/REV2/sorte_slave_PRU0.bin
EXT_LIB_$(CORE) += $(pruss_sorte_slave_PATH)/bin/$(SOC)/a15_0/REV2/sorte_slave_PRU1.bin
endif

ifeq ($(BOARD),$(filter $(BOARD), idkAM571x))
EXTERNAL_LNKCMD_FILE_LOCAL = ${PDK_INSTALL_PATH}/ti/build/pruss/lnk_a8_a9_a15_REV2.cmd
# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = ../src/sorte_idkAM571x_app.cfg
EXT_LIB_$(CORE) = $(pruss_sorte_slave_PATH)/bin/$(SOC)/a15_0/REV2/sorte_slave_PRU0.bin
EXT_LIB_$(CORE) += $(pruss_sorte_slave_PATH)/bin/$(SOC)/a15_0/REV2/sorte_slave_PRU1.bin
endif

ifeq ($(BOARD),$(filter $(BOARD), iceK2G))
EXTERNAL_LNKCMD_FILE_LOCAL = ${PDK_INSTALL_PATH}/ti/build/pruss/lnk_a8_a9_a15_REV2.cmd
# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = ../src/sorte_iceK2G_app.cfg
EXT_LIB_$(CORE) = $(pruss_sorte_slave_PATH)/bin/$(SOC)/a15_0/REV2/sorte_slave_PRU0.bin
EXT_LIB_$(CORE) += $(pruss_sorte_slave_PATH)/bin/$(SOC)/a15_0/REV2/sorte_slave_PRU1.bin
endif

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = bios xdc pdk

# List all the components required by the application
COMP_LIST_COMMON = board osal_tirtos pruss icss_emac uart i2c gpio csl

PACKAGE_SRCS_COMMON = .

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


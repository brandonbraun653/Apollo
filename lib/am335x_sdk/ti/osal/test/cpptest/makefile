#
# This file is the makefile for building CPP test application.
#
ifeq ($(RULES_MAKE), )
include $(PDK_INSTALL_PATH)/ti/build/Rules.make
else
include $(RULES_MAKE)
endif

PATH += $(PERL_INSTALL_PATH)

APP_NAME = cpptest

SRCDIR = . 
INCDIR = .

BUILD_OS_TYPE = baremetal

.PHONY: all
all: create_header cpp_build

ifeq ($(SOC),am335x)
STARTERWARE_PLATFORM = am335x-evm
CORE_NAME = a8
else ifeq ($(SOC),am437x)
STARTERWARE_PLATFORM = am43xx-evm
CORE_NAME = a9
endif

.PHONY: create_header
create_header:
ifneq ($(SOC),$(filter $(SOC), am335x am437x))
	@echo "Creating Header File..."
	perl include_header_file.pl $(PDK_INSTALL_PATH)/ti $(SOC)
endif

.PHONY: cpp_build
cpp_build:

SRCDIR = . 

LNKFLAGS_LOCAL_a8host += --entry Entry
LNKFLAGS_LOCAL_a9host += --entry Entry
LNKFLAGS_LOCAL_a15_0  += --entry Entry
#LNKFLAGS_LOCAL_mpu1_0 += --entry Entry

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk csl_arch
ifeq ($(SOC),$(filter $(SOC), am335x am437x))
INCLUDE_EXTERNAL_INTERFACES += starterware
endif

# List all the components required by the application

COMP_LIST_COMMON += board osal_nonos i2c emac gpio gpmc icss_emac mcasp mmcsd pm pruss spi uart profiling fatfs 
COMP_LIST_COMMON += dal soc device utils mmcsd_lib ff9b_lib xmodem_lib qspi_lib nand_lib example_utils 
COMP_LIST_COMMON += csl
COMP_LIST_a15_0   = csl_init
COMP_LIST_c66x = csl_intc
COMP_LIST_mpu1_0  = csl_init
COMP_LIST_mcu1_0  = csl_init
ifeq ($(SOC),$(filter $(SOC), am65xx))
COMP_LIST_COMMON += udma sciclient
endif

BOARD_PATH = $(PDK_INSTALL_PATH)/ti/board
CSL_PATH = $(PDK_INSTALL_PATH)/ti/csl
DRV_PATH = $(PDK_INSTALL_PATH)/ti/drv
FATFS_PATH = $(PDK_INSTALL_PATH)/ti/fs/fatfs
OSAL_PATH = $(PDK_INSTALL_PATH)/ti/osal
UTILS_PATH = $(PDK_INSTALL_PATH)/ti/utils/profiling
STARTERWARE_PATH = $(PDK_INSTALL_PATH)/ti/starterware

ifeq ($(SOC),$(filter $(SOC), am335x am437x))
EXT_LIB_LIST_COMMON += $(STARTERWARE_PATH)/binary/soc/lib/$(STARTERWARE_PLATFORM)/$(CORE_NAME)/release/gcc/libsoc.a
EXT_LIB_LIST_COMMON += $(STARTERWARE_PATH)/binary/board/lib/$(STARTERWARE_PLATFORM)/$(CORE_NAME)/release/gcc/libboard.a
EXT_LIB_LIST_COMMON += $(STARTERWARE_PATH)/binary/device/lib/$(STARTERWARE_PLATFORM)/$(CORE_NAME)/release/gcc/libdevice.a
EXT_LIB_LIST_COMMON += $(STARTERWARE_PATH)/binary/dal/lib/$(STARTERWARE_PLATFORM)/$(CORE_NAME)/release/gcc/libdal.a
EXT_LIB_LIST_COMMON += $(STARTERWARE_PATH)/binary/utils/lib/$(STARTERWARE_PLATFORM)/$(CORE_NAME)/release/gcc/libutils.a
endif

# Common source files and CFLAGS across all platforms and cores
PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

INCDIR += $(BIOS_INSTALL_PATH)/packages
INCDIR += $(XDC_INSTALL_PATH)/packages
INCDIR += $(EDMA3LLD_BIOS6_INSTALLDIR)/packages
INCDIR += $(DRV_PATH)/icss-emac
INCDIR += $(DRV_PATH)/pm
INCDIR += $(DRV_PATH)/usb/src/usb_func/include
INCDIR += $(DRV_PATH)/usb/src/include
INCDIR += $(DRV_PATH)/usb
INCDIR += $(NDK_INSTALL_PATH)/packages

SRCS_COMMON += cpptest.c
ifeq ($(SOC),$(filter $(SOC), am335x am437x))
# Additional Source and Include for AM335x/AM437x for init/entry source files
SRCDIR += $(PDK_INSTALL_PATH)/ti/osal/test/$(SOC)/armv7/nonos

INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include
INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include/hw
INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include/armv7a


SRCS_COMMON += example_utils_mmu.c mmu_arm.c app_startup.c 
SRCS_ASM_COMMON += init.asm exceptionhandler.asm
endif

ifeq ($(SOC),am335x)
INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include/am335x
endif
ifeq ($(SOC),am437x)
INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include/am43xx
endif

CFLAGS_LOCAL_COMMON += -Dgcc 

ifeq ($(SOC),am335x)
LNKCMD_FILE = $(PDK_INSTALL_PATH)/ti/osal/test/$(SOC)/armv7/nonos/am335x_ddr.lds
endif
ifeq ($(SOC),am437x)
LNKCMD_FILE = $(PDK_INSTALL_PATH)/ti/osal/test/$(SOC)/armv7/nonos/am43xx_ddr.lds
endif
ifeq ($(CORE),a15_0)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_a15.cmd
endif
ifeq ($(CORE),ipu1_0)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_m4.cmd
endif
ifeq ($(CORE),c66x)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_dsp.cmd
endif

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ROOTDIR)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# Nothing beyond this point

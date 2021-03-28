# Makefile for USB sample app
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

ifeq ($(BAREMETAL),yes)
BUILD_OS_TYPE=baremetal
OS_FLAGS=-DBAREMETAL
LNKFLAGS_LOCAL_mpu1_0  += --entry Entry
#LNKFLAGS_LOCAL_mcu1_0  += --entry Entry

# List all the components required by the application
COMP_LIST_COMMON = osal_nonos csl csl_init board uart usb sciclient i2c

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk

#using USB local linker file instead of ti/build for customization
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
EXTERNAL_LNKCMD_FILE_LOCAL = $(pdk_PATH)/ti/drv/usb/example/build/$(SOC)/linker_r5.lds
endif

ifeq ($(CORE),$(filter $(CORE), mpu1_0))
EXTERNAL_LNKCMD_FILE_LOCAL = $(pdk_PATH)/ti/drv/usb/example/build/$(SOC)/linker_a53.lds
endif

else
BUILD_OS_TYPE=tirtos
OS_FLAGS=-DTIRTOS

# List all the components required by the application
COMP_LIST_COMMON = osal_tirtos csl board uart usb sciclient i2c

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = bios xdc pdk

#TIRTOS components are indicated in the rtsc cfg file

#using USB local linker file instead of ti/build for customization
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
EXTERNAL_LNKCMD_FILE_LOCAL = $(pdk_PATH)/ti/drv/usb/example/build/$(SOC)/linker_r5_sysbios.lds
endif

ifeq ($(CORE),$(filter $(CORE), mpu1_0))
EXTERNAL_LNKCMD_FILE_LOCAL = $(pdk_PATH)/ti/drv/usb/example/build/$(SOC)/linker_$(ISA).lds
endif

endif

ifeq ($(USB30),yes)
USB3OPT=usb3_
USB3FLG=-DUSB3SS_EN
else
USB3OPT=
USB3FLG=
endif


ifeq ($(BUILD_OS_TYPE), tirtos)
USB_OS_TESTPREFIX=
else
USB_OS_TESTPREFIX=_Baremetal
endif

#Name of the directory created under packages/ti/binary/
APP_NAME = USB$(USB_OS_TESTPREFIX)_DevMsc_TestApp
# Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
LOCAL_APP_NAME = USB$(USB_OS_TESTPREFIX)_DevMsc_$(USB3OPT)$(BOARD)_$(CORE)TestApp

SRCDIR = . 
SRCDIR += $(PDK_INSTALL_PATH)/ti/drv/usb/example/usb_dev/msc
SRCDIR += $(PDK_INSTALL_PATH)/ti/drv/usb/example/ramdisk
SRCDIR += $(PDK_INSTALL_PATH)/ti/drv/usb/example/common

INCDIR = . src
INCDIR += $(PDK_INSTALL_PATH)/ti/drv/usb 
INCDIR += $(PDK_INSTALL_PATH)/ti/drv/usb/example/usb_dev/msc 
INCDIR += $(PDK_INSTALL_PATH)/ti/drv/usb/example/ramdisk
INCDIR += $(PDK_INSTALL_PATH)/ti/drv/usb/src/usb_func/include 
INCDIR += $(PDK_INSTALL_PATH)/ti/drv/usb/src/include  
INCDIR += $(PDK_INSTALL_PATH)/ti/drv/usb/example/common
INCDIR += $(PDK_INSTALL_PATH)/ti/csl  


# Common source files across all platforms and cores
SRCS_COMMON +=  usb_msc_structs.c usbdmscglue.c ramdiskutils.c usb_osal.c intRouter.c timer.c

ifeq ($(BAREMETAL),yes)
SRCS_COMMON += dev_msc.c
XDC_CFG_FILE_$(CORE) =
else
SRCS_COMMON += biosMmu.c dev_msc_main.c 
SRCDIR += $(PDK_INSTALL_PATH)/ti/drv/usb/example/bios 


# Enable XDC build for application by providing XDC CFG File per core
XDC_CFG_FILE_$(CORE) = $(PDK_INSTALL_PATH)/ti/drv/usb/example/bios/$(SOC)/usb_$(SOC)_evm.cfg

endif

PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) $(OS_FLAGS)

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

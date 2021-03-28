#
# This file is the makefile for building CSL timer app.
#
ifeq ($(RULES_MAKE), )
include $(PDK_INSTALL_PATH)/ti/build/Rules.make
else
include $(RULES_MAKE)
endif

#Name of the directory created under packages/ti/binary/
APP_NAME = OSAL_Baremetal_TestApp
# Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
LOCAL_APP_NAME =  OSAL_Baremetal_$(BOARD)_$(CORE)TestApp
BUILD_OS_TYPE = baremetal

SRCDIR = ../src
INCDIR = ../src

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk csl_arch

# List all the components required by the application
ifeq ($(SOC),$(filter $(SOC), tpr12))
  COMP_LIST_COMMON += board osal_nonos
else
  COMP_LIST_COMMON += board uart osal_nonos i2c
endif
COMP_LIST_c66x = csl_intc
COMP_LIST_c66xdsp_1 = csl_intc
COMP_LIST_c66xdsp_2 = csl_intc
COMP_LIST_c674x = csl_intc
COMP_LIST_COMMON += csl
COMP_LIST_a15_0   = csl_init
COMP_LIST_arm9_0 = csl_init
COMP_LIST_mpu1_0  = csl_init
COMP_LIST_mcu1_0  = csl_init
COMP_LIST_mcu1_1  = csl_init
COMP_LIST_mcu2_0  = csl_init
COMP_LIST_mcu2_1  = csl_init
COMP_LIST_mcu3_0  = csl_init
COMP_LIST_mcu3_1  = csl_init

ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
  COMP_LIST_COMMON += sciclient
endif

# Common source files and CFLAGS across all platforms and cores
PACKAGE_SRCS_COMMON = . ../src
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) -DBARE_METAL

ifeq ($(MANUAL_CACHE_TEST),YES)
  CFLAGS_LOCAL_COMMON += -DMANUAL_CACHE_TEST
endif

ifeq ($(SOC),$(filter $(SOC), k2h k2k k2l k2e k2g c6678 c6657 am571x am572x am574x am437x am335x omapl137 omapl138 am65xx j721e j7200 tpr12))
  CFLAGS_LOCAL_COMMON += -DENABLE_TIMER_TEST
endif

SRCS_COMMON += main_osal_test.c
ifeq ($(CORE),a8host)
  # Additional Source and Include for AM335x for init/entry source files
  SRCDIR      += $(PDK_OSAL_COMP_PATH)/test/am335x/armv7/nonos
  INCDIR      += $(PDK_OSAL_COMP_PATH)/test/am335x/armv7/nonos
  INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include
  INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include/hw
  INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include/armv7a
  INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include/am335x
  SRCS_COMMON += example_utils_mmu.c mmu_arm.c app_startup.c
  SRCS_ASM_COMMON += init.asm exceptionhandler.asm
  #Indicate gcc compilation for starterware header files
  CFLAGS_LOCAL_COMMON += -Dgcc
endif

ifeq ($(CORE),a9host)
  # Additional Source and Include for AM437x for init/entry source files
  SRCDIR += $(PDK_OSAL_COMP_PATH)/test/am437x/armv7/nonos
  INCDIR += $(PDK_OSAL_COMP_PATH)/test/am437x/armv7/nonos
  INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include
  INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include/hw
  INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include/armv7a
  INCDIR += $(PDK_INSTALL_PATH)/ti/starterware/include/am43xx
  SRCS_COMMON += example_utils_mmu.c mmu_arm.c app_startup.c
  SRCS_ASM_COMMON += init.asm exceptionhandler.asm
  #Indicate gcc compilation for starterware header files
  CFLAGS_LOCAL_COMMON += -Dgcc
endif


ifeq ($(SOC),$(filter $(SOC), k2g k2e k2h k2k k2l))
  ifeq ($(CORE),a15_0)
   LNKCMD_FILE = $(PDK_OSAL_COMP_PATH)/test/k2g/armv7/nonos/k2g_lnk.cmd
  endif
else
  ifeq ($(CORE),a15_0)
   LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_a15.cmd
  endif
endif

ifeq ($(CORE),ipu1_0)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_m4.cmd
endif
ifeq ($(CORE),c66x)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_dsp.cmd
endif

ifeq ($(CORE),c674x)
   LNKCMD_FILE = $(PDK_OSAL_COMP_PATH)/test/$(SOC)/c674x/nonos/lnk_c674x.cmd
endif

ifeq ($(CORE),a8host)
 LNKCMD_FILE = $(PDK_OSAL_COMP_PATH)/test/am335x/armv7/nonos/am335x_ddr.lds
endif

ifeq ($(CORE),a9host)
 LNKCMD_FILE = $(PDK_OSAL_COMP_PATH)/test/am437x/armv7/nonos/am43xx_ddr.lds
endif

ifeq ($(CORE), arm9_0)
 LNKCMD_FILE = $(PDK_OSAL_COMP_PATH)/test/$(SOC)/arm9/nonos/lnk_arm9.cmd
endif

LNKFLAGS_LOCAL_a15_0  += --entry Entry
LNKFLAGS_LOCAL_a8host += --entry Entry
LNKFLAGS_LOCAL_a9host += --entry Entry
LNKFLAGS_LOCAL_mpu1_0 += --entry Entry

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

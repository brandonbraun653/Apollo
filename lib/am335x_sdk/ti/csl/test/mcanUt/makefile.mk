#
# This file is the makefile for building MCAN unit test application.
#
SRCDIR = testApp testLib
INCDIR = testInput testLib

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk
INCLUDE_INTERNAL_INTERFACES =

# List all the components required by the application
ifeq ($(SOC),$(filter $(SOC), am65xx j721e))
    COMP_LIST_COMMON = csl_init udma sciclient board uart gpio i2c udma_apputils
endif
ifeq ($(SOC),$(filter $(SOC), tda2px tda3xx dra78x))
  COMP_LIST_COMMON = pm_hal pm_lib csl_utils_common csl_uart_console
endif

COMP_LIST_COMMON += csl

ifeq ($(BUILD_OS_TYPE), baremetal)
  SRCS_COMMON = main_baremetal.c
  COMP_LIST_COMMON += csl_arch
  ifeq ($(SOC),$(filter $(SOC), am65xx j721e))
    COMP_LIST_COMMON += osal_nonos fvid2
  endif
  ifeq ($(CORE),ipu1_0)
    LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_m4.cmd
  endif
  ifeq ($(CORE),mpu1_0)
    LNKFLAGS_LOCAL_mpu1_0 += --entry Entry
    EXTERNAL_LNKCMD_FILE_LOCAL = arm_a53.cmd
  endif
else
  INCLUDE_EXTERNAL_INTERFACES += xdc bios
  COMP_LIST_COMMON += osal_tirtos fvid2
  CFLAGS_LOCAL_COMMON = $(FVID2_CFLAGS)
  SRCS_COMMON = main_tirtos.c utils_prf.c
  XDC_CFG_FILE_$(CORE) = $(PDK_INSTALL_PATH)/ti/build/$(SOC)/sysbios_$(ISA).cfg
endif

XDC_CFG_UPDATE_$(CORE) = mcan_ut.cfg

# Common source files and CFLAGS across all platforms and cores
SRCS_COMMON += st_mcanApp.c st_mcanParser.c st_mcanCommon.c st_mcanTxApp.c st_mcanRxApp.c

CFLAGS_LOCAL_COMMON += $(PDK_CFLAGS)
PACKAGE_SRCS_COMMON = . ../csl_test_component.mk

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

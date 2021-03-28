# Makefile for MMCSD DMA unit test app
ifeq ($(RULES_MAKE), )
include $(PDK_INSTALL_PATH)/ti/build/Rules.make
else
include $(RULES_MAKE)
endif

export DISABLE_RECURSE_DEPS
BUILD_OS_TYPE = baremetal
#Name of the directory created under packages/ti/binary/
APP_NAME = MMCSD_Baremetal_Regression_TestApp
# Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
LOCAL_APP_NAME = MMCSD_Baremetal_Regression_$(BOARD)_$(CORE)TestApp

ifeq ($(SOC),$(filter $(SOC), am65xx))
SRCDIR = ../src ../../
INCDIR = ../src ../include ../../
# Common source files across all platforms and cores
SRCS_COMMON += main.c

CFLAGS_MMCSD_UT += -DMMCSD_ADMA_ENABLED -DMMCSD_REGRESSION_TEST -DMMCSD_TEST_FATFS_BENCHMARK_ENABLED


endif

ifeq ($(SOC),$(filter $(SOC), j721e j7200))
SRCDIR = ../src ../../
INCDIR = ../src ../include ../../
# Common source files across all platforms and cores
SRCS_COMMON += main.c  
CFLAGS_MMCSD_UT += -DMMCSD_ADMA_ENABLED -DMMCSD_REGRESSION_TEST -DMMCSD_TEST_FATFS_BENCHMARK_ENABLED
#CFLAGS_MMCSD_UT += -DMMCSD_TEST_DDR_DISABLED 

#CFLAGS_MMCSD_UT += -DSTRESS_PATTERN_RANDOM_SMH_TEST_ENABLE
#SRCS_COMMON += stress_test_pattern.c

#CFLAGS_MMCSD_UT += -DSTRESS_PATTERN_TEST_ENABLE
#SRCS_COMMON += random_test_pattern.c

#CFLAGS_MMCSD_UT += -DSTRESS_TEST_ENABLED

endif

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk csl_arch

# List all the components required by the application
COMP_LIST_COMMON += uart osal_nonos i2c fatfs_indp mmcsd board
COMP_LIST_c66x = csl_intc
COMP_LIST_COMMON += csl
COMP_LIST_a15_0   = csl_init
COMP_LIST_mpu1_0  = csl_init
COMP_LIST_mpu1_1  = csl_init
LNKFLAGS_LOCAL_a15_0  += --entry Entry
LNKFLAGS_LOCAL_a8host += --entry Entry
LNKFLAGS_LOCAL_a9host += --entry Entry
LNKFLAGS_LOCAL_mpu1_0 += --entry Entry


COMP_LIST_mcu1_0  = csl_init
COMP_LIST_mcu1_1  = csl_init

ifeq ($(SOC),$(filter $(SOC), j721e j7200))
COMP_LIST_mcu2_0  = csl_init
COMP_LIST_mcu2_1  = csl_init
ifeq ($(SOC),$(filter $(SOC), j721e))
COMP_LIST_mcu3_0  = csl_init
COMP_LIST_mcu3_1  = csl_init
endif
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
COMP_LIST_COMMON += sciclient
endif

# CFLAGS_MMCSD_UT += -DIO_CONSOLE 
# am65xx build
ifeq ($(BOARD),$(filter $(BOARD), am65xx-sim))
CFLAGS_MMCSD_UT    += -DsimAM6x
endif

# EVM build
ifeq ($(BOARD),$(filter $(BOARD), am65xx-evm))
CFLAGS_MMCSD_UT += -DevmAM65xx
endif


PACKAGE_SRCS_COMMON = ../
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) $(CFLAGS_MMCSD_UT) -DBARE_METAL

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

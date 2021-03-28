# Makefile for SPI unit test app
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

ifeq ($(IS_BAREMETAL),yes)
BUILD_OS_TYPE = baremetal
CFLAGS_OS_DEFINES =
LNKFLAGS_LOCAL_mpu1_0  += --entry Entry
COMP_LIST_COMMON =  csl_init osal_nonos
EXTERNAL_INTERFACES =
XDC_CFG_FILE_mpu1_0 =
XDC_CFG_FILE_mcu1_0 =
else
BUILD_OS_TYPE = tirtos
CFLAGS_OS_DEFINES = -DUSE_BIOS
EXTERNAL_INTERFACES = bios xdc
COMP_LIST_COMMON    = osal_tirtos

ifeq ($(SOC),$(filter $(SOC), am65xx))
XDC_CFG_FILE_mpu1_0 = ./$(SOC)/ospiFlashTest_a53.cfg
XDC_CFG_FILE_mcu1_0 = ./$(SOC)/ospiFlashTest_r5.cfg
else
ifeq ($(SOC),$(filter $(SOC), j721e j7200))
XDC_CFG_FILE_$(CORE) = $(PDK_INSTALL_PATH)/ti/build/$(SOC)/sysbios_$(ISA).cfg
endif
endif

endif

SRCDIR = . src
INCDIR = . src

# Common source files across all platforms and cores
SRCS_COMMON += main_ospi_flash_test.c

ifeq ($(BUILD_OS_TYPE), tirtos)
OSPI_OS_TESTPREFIX=
else
OSPI_OS_TESTPREFIX=_Baremetal
endif



# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk $(EXTERNAL_INTERFACES)

ifeq ($(DMA), enable)
    ifeq ($(SMP), enable)
        #Name of the directory created under packages/ti/binary/
        APP_NAME = OSPI$(OSPI_OS_TESTPREFIX)_Flash_Dma_SMP_TestApp
        # Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
        LOCAL_APP_NAME =  OSPI$(OSPI_OS_TESTPREFIX)_Flash_Dma_$(BOARD)_$(CORE)_SMP_TestApp
    else
        #Name of the directory created under packages/ti/binary/
        APP_NAME = OSPI$(OSPI_OS_TESTPREFIX)_Flash_Dma_TestApp
        # Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
        LOCAL_APP_NAME =  OSPI$(OSPI_OS_TESTPREFIX)_Flash_Dma_$(BOARD)_$(CORE)TestApp
    endif

COMP_LIST_COMMON += spi_dma udma sciclient i2c
#COMP_LIST_COMMON += spi_dma_profile udma
CFLAGS_SPI_DMA    = -DSPI_DMA_ENABLE 
else
    ifeq ($(SMP), enable)
        APP_NAME = OSPI$(OSPI_OS_TESTPREFIX)_Flash_SMP_TestApp
        # Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
        LOCAL_APP_NAME =  OSPI$(OSPI_OS_TESTPREFIX)_Flash_$(BOARD)_$(CORE)_SMP_TestApp
    else
        APP_NAME = OSPI$(OSPI_OS_TESTPREFIX)_Flash_TestApp
        # Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
        LOCAL_APP_NAME =  OSPI$(OSPI_OS_TESTPREFIX)_Flash_$(BOARD)_$(CORE)TestApp
    endif

COMP_LIST_COMMON += spi sciclient i2c
#COMP_LIST_COMMON += spi_profile
CFLAGS_SPI_DMA    =
endif

# List all the components required by the application
COMP_LIST_COMMON  += csl board uart

PACKAGE_SRCS_COMMON = .
PACKAGE_SRCS_COMMON += ../src/SPI_log.h ../src/SPI_log.c
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) $(CFLAGS_SPI_DMA) $(CFLAGS_OS_DEFINES)
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

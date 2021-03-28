# Makefile for UART unit test app
include $(PDK_INSTALL_PATH)/ti/build/Rules.make


ifeq ($(IS_BAREMETAL),yes)
BUILD_OS_TYPE = baremetal
CFLAGS_OS_DEFINES =
LNKFLAGS_LOCAL_mpu1_0  += --entry Entry
COMP_LIST_COMMON =  osal_nonos
ifeq ($(ARCH),c66x)
  COMP_LIST_COMMON += csl_intc
else
  COMP_LIST_COMMON += csl_init
endif
EXTERNAL_INTERFACES =
XDC_CFG_FILE_mpu1_0 =
XDC_CFG_FILE_mcu1_0 =
else
BUILD_OS_TYPE = tirtos
CFLAGS_OS_DEFINES = -DUSE_BIOS
EXTERNAL_INTERFACES = bios xdc
COMP_LIST_COMMON    = osal_tirtos
XDC_CFG_FILE_mpu1_0 = ./$(SOC)/uartUnitTest_$(ISA).cfg
XDC_CFG_FILE_mcu1_0 = ./$(SOC)/uartUnitTest_r5.cfg
ifeq ($(SOC),$(filter $(SOC), j721e j7200))
  XDC_CFG_FILE_$(CORE) = $(PDK_INSTALL_PATH)/ti/build/$(SOC)/sysbios_$(ISA).cfg
endif
endif

SRCDIR = . src
INCDIR = . src
# Common source files across all platforms and cores
SRCS_COMMON += main_uart_test.c

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk $(EXTERNAL_INTERFACES)


ifeq ($(BUILD_OS_TYPE), tirtos)
UART_OS_TYPE=
else
UART_OS_TYPE=_Baremetal
endif

# DMA enabled build
ifeq ($(DMA), enable)
    ifeq ($(SMP), enable)
        #Name of the directory created under packages/ti/binary/
        APP_NAME = UART$(UART_OS_TYPE)_DMA_SMP_TestApp
        # Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
        LOCAL_APP_NAME =  UART$(UART_OS_TYPE)_DMA_$(BOARD)_$(CORE)_SMP_TestApp
	else
        #Name of the directory created under packages/ti/binary/
        APP_NAME = UART$(UART_OS_TYPE)_DMA_TestApp
        # Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
        LOCAL_APP_NAME =  UART$(UART_OS_TYPE)_DMA_$(BOARD)_$(CORE)TestApp
    endif
    COMP_LIST_COMMON   += uart_dma udma sciclient i2c
    #COMP_LIST_COMMON   += uart_dma_profile udma
    CFLAGS_UART_DMA    = -DUART_DMA_ENABLE
else
    ifeq ($(SMP), enable)
        #Name of the directory created under packages/ti/binary/
        APP_NAME = UART$(UART_OS_TYPE)_SMP_TestApp
        # Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
        LOCAL_APP_NAME =  UART$(UART_OS_TYPE)_$(BOARD)_$(CORE)_SMP_TestApp
    else
        #Name of the directory created under packages/ti/binary/
        APP_NAME = UART$(UART_OS_TYPE)_TestApp
        # Name of the binary if different from the default (APP_NAME)_$(BOARD_$(CORE)_<build_profile>
        LOCAL_APP_NAME =  UART$(UART_OS_TYPE)_$(BOARD)_$(CORE)TestApp
    endif
    COMP_LIST_COMMON   += uart

    ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
    COMP_LIST_COMMON += sciclient i2c
    endif

    #COMP_LIST_COMMON   += uart_profile
    CFLAGS_UART_DMA    =
endif
# List all the components required by the application
COMP_LIST_COMMON  += csl board
#COMP_LIST_COMMON  += osal_tirtos csl board profiling

PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) $(CFLAGS_UART_DMA) $(CFLAGS_OS_DEFINES)

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

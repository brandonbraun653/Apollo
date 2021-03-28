#
# This file is the makefile for building CSL crc app.
#
#   Copyright (c) Texas Instruments Incorporated 2017 - 2018
#
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

BUILD_OS_TYPE=baremetal

APP_NAME = csl_ecc_test_app

SRCDIR = .
INCDIR =

ifeq ($(SOC), $(filter $(SOC), k2g k2e k2k k2h k2l c6657 c6678))
SRCDIR += $(PDK_INSTALL_PATH)/ti/csl/arch/$(CORE)/src
INCDIR += $(PDK_INSTALL_PATH)/ti/csl/arch/$(CORE)
INCDIR += $(PDK_INSTALL_PATH)
endif
# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk csl_arch

# List all the components required by the application
ifeq ($(BOARD),$(filter $(BOARD), evmK2G evmK2K evmK2H evmK2L evmK2E evmC6657 evmC6678 evmAM572x idkAM571x idkAM572x idkAM574x am65xx_evm j721e_evm))
  COMP_LIST_COMMON += board i2c uart osal_nonos
ifeq ($(CORE),$(filter $(CORE), c66x))
  COMP_LIST_c66x = csl_intc
endif

ifeq ($(BOARD),$(filter $(BOARD), am65xx_evm j721e_evm))
  COMP_LIST_COMMON += sciclient
endif

endif
ifeq ($(SOC), $(filter $(SOC), k2g k2e k2k k2h k2l c6657 c6678))
COMP_LIST_COMMON += csl csl_uart_console
else
COMP_LIST_COMMON += csl csl_utils_common csl_uart_console
endif
ifeq ($(CORE),$(filter $(CORE), a15_0))
COMP_LIST_COMMON += csl_arch
COMP_LIST_a15_0 = csl_init
endif

ifeq ($(SOC), $(filter $(SOC), am65xx j721e))
COMP_LIST_mpu1_0  = csl_init
endif

ifeq ($(SOC), $(filter $(SOC), j721e))
COMP_LIST_mcu1_0  = csl_init
endif

# Common source files and CFLAGS across all platforms and cores
PACKAGE_SRCS_COMMON = .

CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

ifeq ($(CORE),ipu1_0)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_m4.cmd
 ifeq ($(SOC), $(filter $(SOC), am571x am572x))
  SRCS_COMMON = main_ipu.c ecc_ocmc.c
 else
  SRCS_COMMON = main_ipu.c ecc_emif.c ecc_ocmc.c
 endif
endif
ifeq ($(CORE),c66x)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/ecc/ecc_test_app/lnk_dsp.cmd
 ifeq ($(SOC), $(filter $(SOC), am571x am572x))
  SRCS_COMMON = main_c66x.c  ecc_ocmc.c
 else ifeq ($(SOC), $(filter $(SOC), k2g k2e k2k k2h k2l c6657 c6678))
  SRCS_COMMON = interrupt.c dsp_ecc.c dsp_icfg.c main_c66x.c
  SRCS_ASM_COMMON = intvecs.asm
  ifeq ($(SOC), $(filter $(SOC), k2g))
   SRCS_COMMON += ecc_emif_k2g.c
  endif
 else
  SRCS_COMMON = main_c66x.c  ecc_emif.c ecc_ocmc.c
 endif
endif
ifeq ($(CORE),a15_0)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_a15.cmd
 ifeq ($(SOC), $(filter $(SOC), am571x am572x))
  SRCS_COMMON = main.c ecc_ocmc.c
 else ifeq ($(SOC), $(filter $(SOC), k2g))
  SRCS_COMMON = main.c ecc_emif_k2g.c
 else
  SRCS_COMMON = main.c  ecc_emif.c ecc_ocmc.c
 endif
endif

ifeq ($(CORE),mpu1_0)
  SRCS_COMMON = main_a53.c ecc_msmc.c esm_app.c
endif

ifeq ($(SOC), $(filter $(SOC), j721e))
ifeq ($(CORE),mcu1_0)
 EXTERNAL_LNKCMD_FILE_LOCAL = $(PDK_CSL_COMP_PATH)/example/ecc/ecc_test_app/linker_r5.lds
 SRCS_COMMON = main_r5f.c ecc_ddr.c esm_app_r5.c
endif
endif

LNKFLAGS_LOCAL_a15_0 += --entry Entry
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

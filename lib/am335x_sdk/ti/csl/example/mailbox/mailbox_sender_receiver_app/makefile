#
# This file is the makefile for building CSL mailbox app.
#
include $(PDK_INSTALL_PATH)/ti/build/Rules.make

APP_NAME = csl_mailbox_sender_receiver_app
BUILD_OS_TYPE = baremetal
SRCDIR = .
INCDIR =

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk

# List all the components required by the application
ifeq ($(BOARD),$(filter $(BOARD), idkAM572x evmAM572x idkAM571x idkAM574x))
  COMP_LIST_COMMON += board i2c uart osal_nonos
  COMP_LIST_c66x = csl_intc
endif
COMP_LIST_COMMON += csl csl_utils_common csl_uart_console
COMP_LIST_a15_0 = csl_init
ifeq ($(BOARD),$(filter $(BOARD), am65xx_evm j721e_evm))
  COMP_LIST_COMMON += csl_init osal_nonos board uart sciclient i2c
endif

# Common source files and CFLAGS across all platforms and cores
ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x am571x am572x am574x))
SRCS_a15_0 = mailbox_receiver.c
SRCS_ipu1_0 = mailbox_sender.c
SRCS_c66x = mailbox_sender.c
endif

PACKAGE_SRCS_COMMON = .
SRCS_COMMON =

ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x))
SRCS_ipu1_0 = mailbox_receiver.c
SRCS_c66x = mailbox_sender.c
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j721e))
SRCS_mcu1_0 = mailbox_receiver.c
SRCS_mcu1_1 = mailbox_sender.c
SRCS_mpu1_0 = mailbox_sender.c
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j721e))
EXTERNAL_LNKCMD_FILE_LOCAL = $(SOC)/linker_$(CORE).lds
endif

CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS)

ifeq ($(CORE),a15_0)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_a15.cmd
endif
ifeq ($(CORE),ipu1_0)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_m4.cmd
endif
ifeq ($(CORE),c66x)
 LNKCMD_FILE = $(PDK_CSL_COMP_PATH)/example/lnk_dsp.cmd
endif
ifeq ($(ISA),$(filter $(ISA), a53 a72))
  LNKFLAGS_LOCAL_$(CORE) += --entry Entry
endif
CFLAGS_LOCAL_COMMON += -DBARE_METAL

LNKFLAGS_LOCAL_a15host += --entry Entry

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

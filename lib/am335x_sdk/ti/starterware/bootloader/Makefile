# Filename: Makefile
#
# This file is the makefile for building this module.
#
# Copyright (C) 2013-2019 Texas Instruments Incorporated - http://www.ti.com/
#
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
#    Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the
#    distribution.
#
#    Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#******************************************************************************


APP_NAME = bootloader

include $(STARTERWARE_ROOTDIR)/build/makerules/platform.mk

SRCDIR = ./src ./src/$(SOCFAMILY) ../examples/gpio ../device
INCDIR = ./include ./src/$(SOCFAMILY) ../examples/gpio ../device

# List all the external components/interfaces, whose interface header files
# need to be included for this component

INCLUDE_EXTERNAL_INTERFACES = dal soc board utils

ifeq ($(BOOTMODE),mmcsd)
SRCDIR += ../examples/mmcsd
INCDIR += ../examples/mmcsd
INCLUDE_EXTERNAL_INTERFACES += mmcsd_lib ff9b_lib device
COMP_LIST_COMMON = ff9b_lib mmcsd_lib device
endif

ifeq ($(BOOTMODE),uart)
SRCDIR += ../library/third_party/xmodem
INCDIR += ../library/third_party/xmodem/include
INCLUDE_EXTERNAL_INTERFACES += xmodem_lib device
COMP_LIST_COMMON = xmodem_lib device
endif

ifeq ($(BOOTMODE), qspi)
SRCDIR += .
INCDIR += ../examples/qspi
INCLUDE_EXTERNAL_INTERFACES += qspi_lib device
COMP_LIST_COMMON = qspi_lib device
endif

ifeq ($(BOOTMODE), nand)
SRCDIR += .
INCDIR += ../examples/nand/read_write/
INCLUDE_EXTERNAL_INTERFACES += nand_lib device
COMP_LIST_COMMON = nand_lib device
endif

ifeq ($(BOOTMODE), mcspi)
SRCDIR += .
INCDIR += .
INCLUDE_EXTERNAL_INTERFACES += device
COMP_LIST_COMMON = device
endif

# List all the components required by the application

COMP_LIST_COMMON += board utils soc dal

# Common source files and CFLAGS across all platforms and cores
SRCS_COMMON = sbl_copy.c sbl_main.c
SRCS_COMMON += gpio_app.c

ifeq ($(USE_DDR), no)
SRCS_am335x += sbl_am335x_platform.c sbl_am335x_platform_pll.c
else
SRCS_am335x += sbl_am335x_platform.c sbl_am335x_platform_ddr.c sbl_am335x_platform_pll.c
endif

SRCS_am43xx += sbl_am43xx_platform.c sbl_am43xx_platform_ddr.c sbl_am43xx_platform_pll.c

ifeq ($(BOOTMODE),mmcsd)
SRCS_COMMON += hsmmcsd_app_pol.c sbl_mmcsd.c
endif

ifeq ($(BOOTMODE),uart)
SRCS_COMMON += sbl_uart.c
endif

ifeq ($(BOOTMODE),qspi)
SRCS_COMMON += sbl_qspi.c
endif

ifeq ($(BOOTMODE), nand)
SRCS_COMMON += sbl_nand.c
endif

ifeq ($(BOOTMODE), mcspi)
SRCS_COMMON += sbl_mcspi.c
endif

CFLAGS_LOCAL_COMMON =

ifeq ($(BOOTMODE), qspi)
LNKCMD_FILE = $(STARTERWARE_ROOTDIR)/examples/$(TOOLCHAIN)/$(SOCFAMILY)_boot_xip.lds
CFLAGS_LOCAL_COMMON += -DUSE_XIP -DQDMA_BOOT_QSPI
else

ifeq ($(SECUREMODE),yes)
LNKCMD_FILE = $(STARTERWARE_ROOTDIR)/examples/$(TOOLCHAIN)/$(SOCFAMILY)_boot_hs.lds
else

ifeq ($(USE_DDR), no)
LNKCMD_FILE = $(STARTERWARE_ROOTDIR)/examples/$(TOOLCHAIN)/$(SOCFAMILY)_boot_noddr.lds
else  
LNKCMD_FILE = $(STARTERWARE_ROOTDIR)/examples/$(TOOLCHAIN)/$(SOCFAMILY)_boot.lds
endif #($(USE_DDR), no)

endif  # ifeq ($(SECUREMODE),yes)

ifeq ($(PLATFORM),am335x-evm)
 IMG_LOAD_ADDR = 0x402F0400
endif #($(PLATFORM),am335x-evm)

ifeq ($(PLATFORM),amic110-ddrless)
 IMG_LOAD_ADDR = 0x402F0400
endif #($(PLATFORM),amic110-ddrless)

ifeq ($(PLATFORM),am43xx-evm)
ifeq ($(SECUREMODE),yes)
 IMG_LOAD_ADDR = 0x40300000
else
 IMG_LOAD_ADDR = 0x402F4000
endif
endif #($(PLATFORM),am43xx-evm)

endif #($(BOOTMODE), qspi)

ifeq ($(SECUREMODE),yes)
SRCS_ASM_COMMON += sbl_sec_asm.S
SRCS_COMMON += sbl_sec.c
endif

# Core/SoC/platform specific source files and CFLAGS
# Example:
# SRCS_<core/SoC/platform-name> =
# CFLAGS_LOCAL_<core/SoC/platform-name> =

# Include common make files
include $(STARTERWARE_ROOTDIR)/build/makerules/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
# and need not be explicitly specified here

# Nothing beyond this point

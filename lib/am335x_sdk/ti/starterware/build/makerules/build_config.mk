# File     build_config.mk
#
# This file contains build options that are typically changed during
# the build time.
#
# This file changes when:
#     1. format needs to change (eg: COFF/ELF)
#     2. Endian-ness needs to change (little/big)
#     3. global compiler and linker options need to change (one entry for each
#                                                           core)
#     4. A new custom build configuration is to be added
#     5. A new module is added (needs to be added into the 'all' BUILDCFG.
#
# Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

# Global options

# Endianness : Allowed values = little | big
ENDIAN = little

# Format : Allowed values = COFF | ELF
FORMAT = ELF

STARTERWARE_BUILD_ENV := yes

############################################'
# Configurable parameters
############################################'

# List out the different supported custom build configurations. Build
# configurations enable reduced size builds for StarterWare.

# all: Full build configuration
ifeq ($(BUILDCFG), all)
BUILDCFG_MOD_UART = 1
BUILDCFG_MOD_I2C = 1
BUILDCFG_MOD_MCSPI = 1
BUILDCFG_MOD_GPIO = 1
BUILDCFG_MOD_MMCSD = 1
BUILDCFG_MOD_DMTIMER = 1
BUILDCFG_MOD_EDMA3CC = 1
BUILDCFG_MOD_EDMA3TC = 1
BUILDCFG_MOD_PWMSS = 1
BUILDCFG_MOD_DSS = 1
BUILDCFG_MOD_QSPI = 1
BUILDCFG_MOD_WDT = 1
BUILDCFG_MOD_ADC = 1
BUILDCFG_MOD_RTC = 1
BUILDCFG_MOD_LCDC = 1
BUILDCFG_MOD_DCAN = 1
BUILDCFG_MOD_VPFE = 1
BUILDCFG_MOD_CPSW = 1
BUILDCFG_MOD_GPMC = 1
BUILDCFG_MOD_MDIO = 1
BUILDCFG_MOD_PRU_ETH = 1
endif # ifeq ($(BUILDCFG), all)

# boot: Reduced build configuration for boot-loader
ifeq ($(BUILDCFG), boot)
BUILDCFG_MOD_GPIO = 1
BUILDCFG_MOD_UART = 1
BUILDCFG_MOD_I2C = 1
BUILDCFG_MOD_MCSPI = 1
ifeq ($(BOOTMODE),mmcsd)
BUILDCFG_MOD_MMCSD = 1
endif # ifeq ($(BOOTMODE),mmcsd)
ifeq ($(BOOTMODE), qspi)
BUILDCFG_MOD_QSPI = 1
endif # ifeq ($(BOOTMODE), qspi)
ifeq ($(BOOTMODE), nand)
BUILDCFG_MOD_GPMC = 1
endif # ifeq ($(BOOTMODE), nand)
ifeq ($(BOOTMODE), mcspi)
BUILDCFG_MOD_MCSPI = 1
endif # ifeq ($BOOTMODE),mcspi)

endif # ifeq ($(BUILDCFG), boot)

export STARTERWARE_BUILD_ENV

# Nothing beyond this point

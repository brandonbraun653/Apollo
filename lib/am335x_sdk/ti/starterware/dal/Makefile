# Filename: Makefile
#
# This file is the makefile for building this module.
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


MODULE_NAME = dal

include $(STARTERWARE_ROOTDIR)/build/makerules/platform.mk

SRCDIR = .
INCDIR = .

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = utils

# List all the internal sub-modules whose interface header files
# need to be included for this module
INCLUDE_INTERNAL_INTERFACES = dal

# Common source files and CFLAGS across all platforms and cores

#Include src files for only the modules defined under dal_COMP_LIST
ifeq ($(findstring i2c,$(dal_COMP_LIST)),i2c)
SRCS_COMMON += i2c.c
endif
ifeq ($(findstring uart,$(dal_COMP_LIST)),uart)
SRCS_COMMON += uart.c
endif
ifeq ($(findstring gpio,$(dal_COMP_LIST)),gpio)
SRCS_COMMON += gpio.c
endif
ifeq ($(findstring spinlock,$(dal_COMP_LIST)),spinlock)
SRCS_COMMON += spinlock.c
endif
ifeq ($(findstring mcspi,$(dal_COMP_LIST)),mcspi)
SRCS_COMMON += mcspi.c
endif
ifeq ($(findstring gpmc,$(dal_COMP_LIST)),gpmc)
SRCS_COMMON += gpmc.c elm.c
endif
ifeq ($(findstring qspi,$(dal_COMP_LIST)),qspi)
SRCS_COMMON += qspi.c
endif
ifeq ($(findstring edma,$(dal_COMP_LIST)),edma)
SRCS_COMMON += edma.c
endif
ifeq ($(findstring mmu,$(dal_COMP_LIST)),mmu)
SRCS_COMMON += mmu.c
endif
ifeq ($(findstring mcasp,$(dal_COMP_LIST)),mcasp)
SRCS_COMMON += mcasp.c
endif
ifeq ($(findstring mmcsd,$(dal_COMP_LIST)),mmcsd)
SRCS_COMMON += hs_mmcsd.c
endif
ifeq ($(findstring dmtimer,$(dal_COMP_LIST)),dmtimer)
SRCS_COMMON += dmtimer.c
endif
ifeq ($(findstring epwm,$(dal_COMP_LIST)),epwm)
SRCS_COMMON += epwm.c
endif
ifeq ($(findstring vpfe,$(dal_COMP_LIST)),vpfe)
SRCS_COMMON += vpfe.c
endif
ifeq ($(findstring dss,$(dal_COMP_LIST)),dss)
SRCS_COMMON += dss.c dss_coefficients.c
endif
ifeq ($(findstring wdt,$(dal_COMP_LIST)),wdt)
SRCS_COMMON += wdt.c
endif
ifeq ($(findstring ecap,$(dal_COMP_LIST)),ecap)
SRCS_COMMON += ecap.c
endif
ifeq ($(findstring adc,$(dal_COMP_LIST)),adc)
SRCS_COMMON += tsc_adc_ss.c
endif
ifeq ($(findstring rtc,$(dal_COMP_LIST)),rtc)
SRCS_COMMON += rtc.c dal_misc.c
endif
ifeq ($(findstring lcdc,$(dal_COMP_LIST)),lcdc)
SRCS_am335x += lcdc.c
endif
ifeq ($(findstring dcan,$(dal_COMP_LIST)),dcan)
SRCS_COMMON += dcan.c
endif
ifeq ($(findstring cpsw,$(dal_COMP_LIST)),cpsw)
SRCS_COMMON += cpsw.c
SRCS_COMMON += cpsw_ale.c
endif
ifeq ($(findstring mdio,$(dal_COMP_LIST)),mdio)
SRCS_COMMON += mdio.c
endif
ifeq ($(findstring mailbox,$(dal_COMP_LIST)),mailbox)
SRCS_COMMON += mailbox.c
endif
ifeq ($(findstring pruss,$(dal_COMP_LIST)),pruss)
SRCS_COMMON += pruss.c
endif
PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(STARTERWARE_CFLAGS)

# Core/SoC/platform specific source files and CFLAGS
# Example:
#   SRCS_<core/SoC/platform-name> =
#   CFLAGS_LOCAL_<core/SoC/platform-name> =

# Include common make files
include $(STARTERWARE_ROOTDIR)/build/makerules/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
#     and need not be explicitly specified here

# Nothing beyond this point

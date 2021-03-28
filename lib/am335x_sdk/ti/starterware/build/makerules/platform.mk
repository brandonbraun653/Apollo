# Filename: platform.mk
#
# Platforms make file - Platform/SoC/targets are defined/derived in this file.
# Any configurations that are needed in the Makefile for all modules / examples
# can be defined here.
#
# This file needs to change when:
#     1. a new platform/SoC is added, which also might have its own cores/ISAs
#
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


#
# Derive SOCFAMILY from PLATFORM
#

# am335x EVM
ifeq ($(PLATFORM),am335x-evm)
 SOCFAMILY = am335x
 IMG_LOAD_ADDR = 0x80000000
endif

ifeq ($(PLATFORM),amic110-ddrless)
 SOCFAMILY = am335x
 IMG_LOAD_ADDR = 0x402F0400
 export USE_DDR=no
endif

# am43xx EVM
ifeq ($(PLATFORM),am43xx-evm)
 SOCFAMILY = am43xx
 IMG_LOAD_ADDR = 0x80000000
endif

# am43xx Zebu
ifeq ($(PLATFORM),am43xx-zebu)
 SOCFAMILY = am43xx
 IMG_LOAD_ADDR = 0x40300000
endif


# Derive Target/ISA from CORE

# a8host
ifeq ($(CORE),a8host)
 ISA = a8
 ARCH = armv7a
endif

# a9host
ifeq ($(CORE),a9host)
 ISA = a9
 ARCH = armv7a
endif


#
# Derive ISA specific settings
#
ifeq ($(FORMAT),ELF)
  FORMAT_EXT = e
endif
# If ENDIAN is set to "big", set ENDIAN_EXT to "e", that would be used in
#    in the filename extension of object/library/executable files
ifeq ($(ENDIAN),big)
  ENDIAN_EXT = e
endif
# Define the file extensions
OBJEXT = o
LIBEXT = a
EXEEXT = out
ASMEXT = o
BINEXT = bin

# Nothing beyond this point

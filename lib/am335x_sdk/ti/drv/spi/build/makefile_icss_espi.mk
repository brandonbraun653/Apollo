# Copyright (c) 2016-2018, Texas Instruments Incorporated
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# *  Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
# *  Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# *  Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
# OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
# EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

include $(PDK_INSTALL_PATH)/ti/build/Rules.make

MODULE_NAME = icss_espi

SRCDIR += src/pru_x src/pru_y $(PDK_CSL_COMP_PATH)/  $(PDK_INSTALL_PATH)/
INCDIR += src/pru_x src/pru_y include $(PDK_CSL_COMP_PATH)/  $(PDK_INSTALL_PATH)/ $(PDK_SPI_ROOT_PATH)

ifeq ($(SOC),$(filter $(SOC), am335x ))
# PRU0 is PRU-CC
SRCS_ASM_pru_0 += eSPI_control.asm eSPI_cmd.asm
LNKFLAGS_LOCAL_pru_0 = --entry_point=PRU_Y_START

# PRU1 is PRU-BB
SRCS_ASM_pru_1 += eSPI_global_states.asm eSPI_single_mode.asm eSPI_dual_mode.asm eSPI_quad_mode.asm
LNKFLAGS_LOCAL_pru_1 = --entry_point=PRU_X_START

# Choose correct linker CMD file
ifeq ($(CORE),$(filter $(CORE), pru_0 ))
LNKCMD_FILE = $($(MODULE_NAME)_PATH)/src/pru_y/AM335x_PRU_CC.cmd
else
LNKCMD_FILE = $($(MODULE_NAME)_PATH)/src/pru_x/AM335x_PRU_BB.cmd
endif

else
# PRU0 is PRU-BB
SRCS_ASM_pru_0 += eSPI_global_states.asm eSPI_single_mode.asm eSPI_dual_mode.asm eSPI_quad_mode.asm
LNKFLAGS_LOCAL_pru_0 = --entry_point=PRU_X_START

# PRU1 is PRU-CC
SRCS_ASM_pru_1 += eSPI_control.asm eSPI_cmd.asm
LNKFLAGS_LOCAL_pru_1 = --entry_point=PRU_Y_START

# Choose correct linker CMD file
ifeq ($(CORE),$(filter $(CORE), pru_0 ))
LNKCMD_FILE = $($(MODULE_NAME)_PATH)/src/pru_x/AM335x_PRU_BB.cmd
else
LNKCMD_FILE = $($(MODULE_NAME)_PATH)/src/pru_y/AM335x_PRU_CC.cmd
endif
endif

PACKAGE_SRCS_COMMON += src/ build/makefile_icss_espi.mk

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES =
                      
CFLAGS_LOCAL_COMMON = $(PDK_CFLAGS) -DPRU

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ROOTDIR)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# Nothing beyond this point


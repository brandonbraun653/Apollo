# Filename: filelist.mk
#
# This file provides files to be compiled in SRCS_COMMON, SRCS_ASM_COMMON
# variables
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

ifeq ($(USE_DDR), no)
SRCS_COMMON +=  board_am335x.c \
                dcard_am335x.c \
                am335x_amic110.c            
else
SRCS_COMMON +=  board_am335x.c \
                dcard_am335x.c \
                am335x_gpevm.c \
                am335x_evmsk.c \
                am335x_beaglebone.c \
                am335x_beagleboneblack.c \
                am335x_icev1.c \
                am335x_icev2.c \
                am335x_amic110.c \
                am335x_custom.c
endif

ifeq ($(USE_DDR), no)
SRCS_COMMON +=  am335x_amic11x_pinmux_data.c
else
SRCS_COMMON +=  am335x_gpevm_pinmux_data.c \
                am335x_evmsk_pinmux_data.c \
                am335x_beaglebone_pinmux_data.c \
                am335x_beagleboneblack_pinmux_data.c \
                am335x_icev1_pinmux_data.c \
                am335x_icev2_pinmux_data.c \
                am335x_amic11x_pinmux_data.c
SRCS_COMMON +=  am335x_lcd4_dcard.c 
endif

SRCS_ASM_COMMON +=

# Nothing beyond this point

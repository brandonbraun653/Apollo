#
# Copyright (c) 2016, Texas Instruments Incorporated
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


ifeq ($(BOARD),$(filter $(BOARD), evmAM572x idkAM572x))
SRCDIR +=   $(PDK_INSTALL_PATH)/ti/drv/i2c/soc/am572x \
            $(PDK_INSTALL_PATH)/ti/drv/uart/soc/am572x \
            $(PDK_INSTALL_PATH)/ti/drv/spi/soc/am572x

INCDIR +=   $(PDK_INSTALL_PATH)/ti/drv/i2c/soc/am572x \
            $(PDK_INSTALL_PATH)/ti/drv/uart/soc/am572x \
            $(PDK_INSTALL_PATH)/ti/drv/spi/soc/am572x

# Common source files across all platforms and cores
SRCS_COMMON += I2C_soc.c UART_soc.c SPI_soc.c
CFLAGS_LOCAL_COMMON += -DPRU_ICSS_FW
endif

ifeq ($(BOARD),$(filter $(BOARD), idkAM574x))
SRCDIR +=   $(PDK_INSTALL_PATH)/ti/drv/i2c/soc/am574x \
            $(PDK_INSTALL_PATH)/ti/drv/uart/soc/am574x \
            $(PDK_INSTALL_PATH)/ti/drv/spi/soc/am574x

INCDIR +=   $(PDK_INSTALL_PATH)/ti/drv/i2c/soc/am574x \
            $(PDK_INSTALL_PATH)/ti/drv/uart/soc/am574x \
            $(PDK_INSTALL_PATH)/ti/drv/spi/soc/am574x

# Common source files across all platforms and cores
SRCS_COMMON += I2C_soc.c UART_soc.c SPI_soc.c
CFLAGS_LOCAL_COMMON += -DPRU_ICSS_FW
endif

ifeq ($(BOARD),$(filter $(BOARD), evmAM571x idkAM571x))
SRCDIR +=   $(PDK_INSTALL_PATH)/ti/drv/i2c/soc/am571x \
            $(PDK_INSTALL_PATH)/ti/drv/uart/soc/am571x \
            $(PDK_INSTALL_PATH)/ti/drv/spi/soc/am571x

INCDIR +=   $(PDK_INSTALL_PATH)/ti/drv/i2c/soc/am571x \
            $(PDK_INSTALL_PATH)/ti/drv/uart/soc/am571x \
            $(PDK_INSTALL_PATH)/ti/drv/spi/soc/am571x

# Common source files across all platforms and cores
SRCS_COMMON += I2C_soc.c UART_soc.c SPI_soc.c
endif

ifeq ($(BOARD),$(filter $(BOARD), evmOMAPL137))
SRCDIR +=   $(PDK_INSTALL_PATH)/ti/drv/i2c/soc/omapl137 \
            $(PDK_INSTALL_PATH)/ti/drv/uart/soc/omapl137

INCDIR +=   $(PDK_INSTALL_PATH)/ti/drv/i2c/soc/omapl137 \
            $(PDK_INSTALL_PATH)/ti/drv/uart/soc/omapl137

# Common source files across all platforms and cores
SRCS_COMMON += I2C_soc.c UART_soc.c
endif

PACKAGE_SRCS_COMMON =   src/src_files_lld.mk

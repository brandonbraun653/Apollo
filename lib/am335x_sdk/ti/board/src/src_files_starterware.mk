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


SRCDIR +=   $(PDK_INSTALL_PATH)/ti/starterware/include \
            $(PDK_INSTALL_PATH)/ti/starterware/include/hw \
            $(PDK_INSTALL_PATH)/ti/starterware/board \
            $(PDK_INSTALL_PATH)/ti/starterware/device \
            $(PDK_INSTALL_PATH)/ti/starterware/include/utils \
            $(PDK_INSTALL_PATH)/ti/starterware/utils \
            $(PDK_INSTALL_PATH)/ti/starterware/soc

INCDIR +=   $(PDK_INSTALL_PATH)/ti/starterware/include \
            $(PDK_INSTALL_PATH)/ti/starterware/include/hw \
            $(PDK_INSTALL_PATH)/ti/starterware/board \
            $(PDK_INSTALL_PATH)/ti/starterware/device \
            $(PDK_INSTALL_PATH)/ti/starterware/include/utils \
            $(PDK_INSTALL_PATH)/ti/starterware/utils \
            $(PDK_INSTALL_PATH)/ti/starterware/soc

ifeq ($(BOARD),$(filter $(BOARD), evmAM335x icev2AM335x iceAMIC110 skAM335x bbbAM335x))
    SRCDIR +=   $(PDK_INSTALL_PATH)/ti/starterware/board/am335x \
                $(PDK_INSTALL_PATH)/ti/starterware/soc/am335x \
                $(PDK_INSTALL_PATH)/ti/starterware/include/am335x

    INCDIR +=   $(PDK_INSTALL_PATH)/ti/starterware/board/am335x \
                $(PDK_INSTALL_PATH)/ti/starterware/soc/am335x \
                $(PDK_INSTALL_PATH)/ti/starterware/include/am335x

    CFLAGS_LOCAL_COMMON +=  -DAM335X_FAMILY_BUILD -Dam335x -DBUILDCFG_MOD_UART -DBUILDCFG_MOD_GPIO  -DBUILDCFG_MOD_I2C \
                            -DBUILDCFG_MOD_MCSPI  -DBUILDCFG_MOD_QSPI -DBUILDCFG_MOD_PRU_ETH -DBUILDCFG_MOD_MMCSD -DBUILDCFG_MOD_CPSW \
                            -DBUILDCFG_MOD_PWMSS -DBUILDCFG_MOD_DSS -DBUILDCFG_MOD_USB -DBUILDCFG_MOD_GPMC -DBUILDCFG_MOD_DCAN \
                            -DBUILDCFG_MOD_MCASP -DBUILDCFG_MOD_VPFE -DBUILDCFG_MOD_MDIO -DBUILDCFG_MOD_DMTIMER -DBUILDCFG_MOD_EDMA3CC \
                            -DBUILDCFG_MOD_EDMA3TC -DBUILDCFG_MOD_RTC -DBUILDCFG_MOD_WDT -DBUILDCFG_MOD_ADC -DBUILDCFG_MOD_LCDC -DBUILDCFG_MOD_PRU_ICSS

    # Common source files across all platforms and cores
    SRCS_COMMON += am335x_control.c am335x_chipdb.c am335x_prcm.c hw_am335x_chipdb.c hw_am335x_chipdb_baseaddr.c hw_am335x_chipdb_interrupt.c

    ifeq ($(BOARD),$(filter $(BOARD), evmAM335x))
        SRCS_COMMON += am335x_gpevm_pinmux_data.c
    endif

    ifeq ($(BOARD),$(filter $(BOARD), icev2AM335x))
        SRCS_COMMON += am335x_icev2_pinmux_data.c
    endif

    ifeq ($(BOARD),$(filter $(BOARD), iceAMIC110))
        SRCS_COMMON += am335x_amic11x_pinmux_data.c
    endif

    ifeq ($(BOARD),$(filter $(BOARD), skAM335x))
        SRCS_COMMON += am335x_evmsk_pinmux_data.c
    endif

    ifeq ($(BOARD),$(filter $(BOARD), bbbAM335x))
        SRCS_COMMON += am335x_beagleboneblack_pinmux_data.c
    endif
endif

ifeq ($(BOARD),$(filter $(BOARD), evmAM437x idkAM437x skAM437x))
    SRCDIR +=   $(PDK_INSTALL_PATH)/ti/starterware/board/am43xx \
                $(PDK_INSTALL_PATH)/ti/starterware/soc/am43xx \
                $(PDK_INSTALL_PATH)/ti/starterware/include/am43xx \
                $(PDK_INSTALL_PATH)/ti/starterware/include/am43xx/am437x \
                $(PDK_INSTALL_PATH)/ti/starterware/include/armv7a \
                $(PDK_INSTALL_PATH)/ti/starterware/soc/armv7a \
                $(PDK_INSTALL_PATH)/ti/starterware/soc/am43xx/am437x


    INCDIR +=   $(PDK_INSTALL_PATH)/ti/starterware/board/am43xx \
                $(PDK_INSTALL_PATH)/ti/starterware/soc/am43xx \
                $(PDK_INSTALL_PATH)/ti/starterware/include/am43xx \
                $(PDK_INSTALL_PATH)/ti/starterware/include/am43xx/am437x \
                $(PDK_INSTALL_PATH)/ti/starterware/include/armv7a \
                $(PDK_INSTALL_PATH)/ti/starterware/soc/armv7a \
                $(PDK_INSTALL_PATH)/ti/starterware/soc/am43xx/am437x

    CFLAGS_LOCAL_COMMON +=  -DAM43XX_FAMILY_BUILD -Dam437x -DBUILDCFG_MOD_UART -DBUILDCFG_MOD_GPIO  -DBUILDCFG_MOD_I2C \
                            -DBUILDCFG_MOD_MCSPI -DBUILDCFG_MOD_QSPI -DBUILDCFG_MOD_PRU_ETH -DBUILDCFG_MOD_MMCSD  -DBUILDCFG_MOD_CPSW \
                            -DBUILDCFG_MOD_PWMSS -DBUILDCFG_MOD_DSS -DBUILDCFG_MOD_USB -DBUILDCFG_MOD_GPMC -DBUILDCFG_MOD_DCAN \
                            -DBUILDCFG_MOD_MCASP -DBUILDCFG_MOD_VPFE -DBUILDCFG_MOD_MDIO -DBUILDCFG_MOD_DMTIMER -DBUILDCFG_MOD_EDMA3CC \
                            -DBUILDCFG_MOD_EDMA3TC -DBUILDCFG_MOD_RTC -DBUILDCFG_MOD_WDT -DBUILDCFG_MOD_ADC -DBUILDCFG_MOD_PRU_ICSS

    # Common source files across all platforms and cores
    SRCS_COMMON += am43xx_control.c pl310.c hw_prcm_data.c agraph.c am43xx_chipdb.c am43xx_prcm.c hw_am43xx_chipdb.c hw_am43xx_chipdb_baseaddr.c hw_am43xx_chipdb_interrupt.c
    ifeq ($(BOARD),$(filter $(BOARD), evmAM437x))
        SRCS_COMMON += am43xx_gpevm_pinmux_data.c
    endif

    ifeq ($(BOARD),$(filter $(BOARD), idkAM437x))
        SRCS_COMMON += am43xx_idkevm_pinmux_data.c
    endif

    ifeq ($(BOARD),$(filter $(BOARD), skAM437x))
        SRCS_COMMON += am43xx_evmsk_pinmux_data.c
    endif
endif

PACKAGE_SRCS_COMMON =   src/src_files_starterware.mk

# Filename: component.mk

# This file is component include make file of starterware.
#
# List of variables set in this file and their purpose:
# <mod>_RELPATH        - This is the relative path of the module, typically from
#                        top-level directory of the package
# <mod>_PATH           - This is the absolute path of the module. It derives from
#                        absolute path of the top-level directory (set in env.mk)
#                        and relative path set above
# <mod>_INCLUDE        - This is the path that has interface header files of the
#                        module. This can be multiple directories (space separated)
# <mod>_PKG_LIST       - Names of the modules (and sub-modules) that are a part
#                        part of this module, including itself.
# <mod>_PLATFORM_DEPENDENCY - "yes": means the code for this module depends on
#                             platform and the compiled obj/lib has to be kept
#                             under <platform> directory
#                             "no" or "" or if this variable is not defined: means
#                             this module has no platform dependent code and hence
#                             the obj/libs are not kept under <platform> dir.
# <mod>_CORE_DEPENDENCY     - "yes": means the code for this module depends on
#                             core and the compiled obj/lib has to be kept
#                             under <core> directory
#                             "no" or "" or if this variable is not defined: means
#                             this module has no core dependent code and hence
#                             the obj/libs are not kept under <core> dir.
# <mod>_APP_STAGE_FILES     - List of source files that belongs to the module
#                             <mod>, but that needs to be compiled at application
#                             build stage (in the context of the app). This is
#                             primarily for link time configurations or if the
#                             source file is dependent on options/defines that are
#                             application dependent. This can be left blank or
#                             not defined at all, in which case, it means there
#                             no source files in the module <mod> that are required
#                             to be compiled in the application build stage.
#
#
# Copyright (C) 2013-2017 Texas Instruments Incorporated - http://www.ti.com/
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


############################
# StarterWare package
############################
starterware_PKG_LIST_ALL = dal soc board device utils mmcsd_lib ff9b_lib qspi_lib nand_lib

############################
# StarterWare libraries
############################

# dal
dal_COMP_LIST = uart i2c mcspi gpio mmcsd dmtimer edma epwm qspi vpfe dss wdt ecap adc rtc lcdc dcan gpmc cpsw usb mdio mailbox pruss

# spinlock ocmc gpmc timer edma mcspi qspi mailbox mcasp gpio mmu mmcsd

dal_RELPATH = dal
dal_PATH = $(starterware_PATH)/$(dal_RELPATH)
dal_PLATFORM_DEPENDENCY = yes
export dal_COMP_LIST
export dal_PLATFORM_DEPENDENCY
dal_PKG_LIST = dal
dal_INCLUDE = $(starterware_PATH)/include $(starterware_PATH)/include/hw $(starterware_PATH)/include/$(ARCH) $(starterware_PATH)/include/$(SOCFAMILY) $(starterware_PATH)/include/$(SOC) $(starterware_PATH)/include/$(ARCH)/$(SOC) $(starterware_PATH)/library/third_party/ff9b/src $(starterware_PATH)/library/third_party/ff9b/port

# soc
soc_RELPATH = soc
soc_PATH = $(starterware_PATH)/$(soc_RELPATH)
soc_PLATFORM_DEPENDENCY = yes
export soc_PLATFORM_DEPENDENCY
soc_INCLUDE = $(starterware_PATH)/include $(starterware_PATH)/include/$(SOCFAMILY) $(starterware_PATH)/include/$(SOCFAMILY)/$(SOC)
soc_PKG_LIST = soc

# board
board_RELPATH = board
board_PATH = $(starterware_PATH)/$(board_RELPATH)
board_PLATFORM_DEPENDENCY = yes
export board_PLATFORM_DEPENDENCY
board_INCLUDE = $(board_PATH)
board_PKG_LIST = board

# StarterWare device
device_RELPATH = device
device_PATH = $(starterware_PATH)/$(device_RELPATH)
device_PLATFORM_DEPENDENCY = yes
export device_PLATFORM_DEPENDENCY
device_INCLUDE = $(starterware_PATH)/include $(device_PATH) $(starterware_PATH)/include/$(SOCFAMILY)/$(SOC)  $(starterware_PATH)/include/utils/ $(starterware_PATH)/include/hw/
device_PKG_LIST = device

# utils
utils_COMP_LIST = uart i2c timer graphics display ramdisk

utils_RELPATH = utils
utils_PATH = $(starterware_PATH)/$(utils_RELPATH)
utils_PLATFORM_DEPENDENCY = yes
export utils_COMP_LIST
export utils_PLATFORM_DEPENDENCY
utils_INCLUDE = $(starterware_PATH)/include/utils
utils_PKG_LIST = utils
utils_INCLUDE = $(starterware_PATH)/include $(starterware_PATH)/soc $(starterware_PATH)/include/hw $(starterware_PATH)/include/$(ARCH) $(starterware_PATH)/include/$(ARCH)/$(SOC) $(starterware_PATH)/include/$(SOCFAMILY)  $(starterware_PATH)/include/$(SOCFAMILY)/$(SOC)  $(starterware_PATH)/include/$(SOC) $(starterware_PATH)/include/utils/ $(starterware_PATH)/utils


############################
# Libraries / protocol stacks
############################
# mmcsd lib
mmcsd_lib_RELPATH = library/mmcsd
mmcsd_lib_PATH = $(starterware_PATH)/$(mmcsd_lib_RELPATH)
mmcsd_lib_PLATFORM_DEPENDENCY = yes
export mmcsd_lib_PLATFORM_DEPENDENCY
mmcsd_lib_INCLUDE = $(mmcsd_lib_PATH)/include
mmcsd_lib_PKG_LIST = mmcsd_lib

# Third party library ff9b
ff9b_lib_RELPATH = library/third_party/ff9b
ff9b_lib_PATH = $(starterware_PATH)/$(ff9b_lib_RELPATH)
ff9b_lib_PLATFORM_DEPENDENCY = yes
export ff9b_lib_PLATFORM_DEPENDENCY
ff9b_lib_INCLUDE = $(ff9b_lib_PATH)/src $(ff9b_lib_PATH)/port
ff9b_lib_PKG_LIST = ff9b_lib

# Third party library xmodem
xmodem_lib_RELPATH = library/third_party/xmodem
xmodem_lib_PATH = $(starterware_PATH)/$(xmodem_lib_RELPATH)
xmodem_lib_PLATFORM_DEPENDENCY = yes
export xmodem_lib_PLATFORM_DEPENDENCY
xmodem_lib_INCLUDE = $(xmodem_lib_PATH)/include
xmodem_lib_PKG_LIST = xmodem_lib

# QSPI Library
qspi_lib_RELPATH = library/qspilib
qspi_lib_PATH = $(starterware_PATH)/$(qspi_lib_RELPATH)
qspi_lib_PLATFORM_DEPENDENCY = yes
export qspi_lib_PLATFORM_DEPENDENCY
qspi_lib_PKG_LIST = qspi_lib
qspi_lib_INCLUDE = $(qspi_lib_PATH)/include

# NAND Library
nand_lib_RELPATH = library/nandlib
nand_lib_PATH = $(starterware_PATH)/$(nand_lib_RELPATH)
nand_lib_PLATFORM_DEPENDENCY = yes
export nand_lib_PLATFORM_DEPENDENCY
nand_lib_PKG_LIST = nand_lib
nand_lib_INCLUDE = $(nand_lib_PATH)/include

############################
# Boot loader
############################
bootloader_RELPATH = bootloader
bootloader_PATH = $(starterware_PATH)/$(bootloader_RELPATH)
bootloader_PLATFORM_DEPENDENCY = yes
export bootloader_PLATFORM_DEPENDENCY

############################
# StarterWare examples
############################
starterware_EXAMPLES_LIST = example_utils gpio_app_led_blink dmtimer_app_cdt gpio_app_buzzer cache_mmu_app i2c_app_eeprom_read wdt_app_cpu_reset adc_app_volt_measure rtc_app_clock epwm_app_haptics_motor uart_app_echo dcan_app_frame_tx_rx nand_app_read_write mmcsd_app_fs_shell dcan_app_loopback ddr_app_diag_test rtc_app_only

# StarterWare example_utils
example_utils_COMP_LIST = mmu

example_utils_RELPATH = examples/example_utils
example_utils_PATH = $(starterware_PATH)/$(example_utils_RELPATH)
example_utils_PLATFORM_DEPENDENCY = yes
export example_utils_PLATFORM_DEPENDENCY
example_utils_INCLUDE = $(example_utils_PATH) $(starterware_PATH)/include $(starterware_PATH)/include/hw $(starterware_PATH)/include/$(ARCH) $(starterware_PATH)/include/$(SOCFAMILY) $(starterware_PATH)/include/$(SOC) $(PDK_INSTALL_PATH)
example_utils_PKG_LIST = example_utils

# uart_app_echo example
uart_app_echo_RELPATH = examples/uart/echo
uart_app_echo_PATH = $(starterware_PATH)/$(uart_app_echo_RELPATH)
uart_app_echo_PLATFORM_DEPENDENCY = yes
export uart_app_echo_PLATFORM_DEPENDENCY

# test_app example
test_app_RELPATH = examples/test
test_app_PATH = $(starterware_PATH)/$(test_app_RELPATH)
test_app_PLATFORM_DEPENDENCY = yes
export test_app_PLATFORM_DEPENDENCY

# gpio_app_led_blink example
gpio_app_led_blink_RELPATH = examples/gpio/led_blink
gpio_app_led_blink_PATH = $(starterware_PATH)/$(gpio_app_led_blink_RELPATH)
gpio_app_led_blink_PLATFORM_DEPENDENCY = yes
export gpio_app_led_blink_PLATFORM_DEPENDENCY
gpio_app_led_blink_INCLUDE = examples/gpio

# gpio_app_buzzer example
gpio_app_buzzer_RELPATH = examples/gpio/buzzer
gpio_app_buzzer_PATH = $(starterware_PATH)/$(gpio_app_buzzer_RELPATH)
gpio_app_buzzer_PLATFORM_DEPENDENCY = yes
export gpio_app_buzzer_PLATFORM_DEPENDENCY
gpio_app_buzzer_INCLUDE = examples/gpio

# cache_mmu_app example
cache_mmu_app_RELPATH = examples/cache_mmu
cache_mmu_app_PATH = $(starterware_PATH)/$(cache_mmu_app_RELPATH)
cache_mmu_app_PLATFORM_DEPENDENCY = yes
export cache_mmu_app_PLATFORM_DEPENDENCY

# dmtimer_app_cdt example
dmtimer_app_cdt_RELPATH = examples/dmtimer/countdown_timer
dmtimer_app_cdt_PATH = $(starterware_PATH)/$(dmtimer_app_cdt_RELPATH)
dmtimer_app_cdt_PLATFORM_DEPENDENCY = yes
export dmtimer_app_cdt_PLATFORM_DEPENDENCY
dmtimer_app_cdt_INCLUDE = examples/dmtimer

# i2c_eeprom_read example
i2c_app_eeprom_read_RELPATH = examples/i2c/eeprom_read
i2c_app_eeprom_read_PATH = $(starterware_PATH)/$(i2c_app_eeprom_read_RELPATH)
i2c_app_eeprom_read_PLATFORM_DEPENDENCY = yes
export i2c_app_eeprom_read_PLATFORM_DEPENDENCY
i2c_app_eeprom_read_INCLUDE = examples/i2c

# epwm_app_haptics_motor example
epwm_app_haptics_motor_RELPATH = examples/epwm/haptics_motor
epwm_app_haptics_motor_PATH = $(starterware_PATH)/$(epwm_app_haptics_motor_RELPATH)
epwm_app_haptics_motor_PLATFORM_DEPENDENCY = yes
export epwm_app_haptics_motor_PLATFORM_DEPENDENCY
epwm_app_haptics_motor_INCLUDE = examples/epwm

# qspi_app_read_write example
qspi_app_read_write_RELPATH = examples/qspi/read_write
qspi_app_read_write_PATH = $(starterware_PATH)/$(qspi_app_read_write_RELPATH)
qspi_app_read_write_PLATFORM_DEPENDENCY = yes
export qspi_app_read_write_PLATFORM_DEPENDENCY

# wdt_app_cpu_reset example
wdt_app_cpu_reset_RELPATH = examples/wdt/cpu_reset
wdt_app_cpu_reset_PATH = $(starterware_PATH)/$(wdt_app_cpu_reset_RELPATH)
wdt_app_cpu_reset_PLATFORM_DEPENDENCY = yes
export wdt_app_cpu_reset_PLATFORM_DEPENDENCY
wdt_app_cpu_reset_INCLUDE = examples/wdt

# qspi_app_flash_writer example
qspi_app_flash_writer_RELPATH = examples/qspi/flash_writer
qspi_app_flash_writer_PATH = $(starterware_PATH)/$(qspi_app_flash_writer_RELPATH)
qspi_app_flash_writer_PLATFORM_DEPENDENCY = yes
export qspi_app_flash_writer_PLATFORM_DEPENDENCY

# dss_app_raster example
dss_app_raster_RELPATH = examples/dss/raster
dss_app_raster_PATH = $(starterware_PATH)/$(dss_app_raster_RELPATH)
dss_app_raster_PLATFORM_DEPENDENCY = yes
export dss_app_raster_PLATFORM_DEPENDENCY
dss_app_raster_INCLUDE = examples/dss

# adc_app_volt_measure example
adc_app_volt_measure_RELPATH = examples/adc/volt_measure
adc_app_volt_measure_PATH = $(starterware_PATH)/$(adc_app_volt_measure_RELPATH)
adc_app_volt_measure_PLATFORM_DEPENDENCY = yes
export adc_app_volt_measure_PLATFORM_DEPENDENCY
adc_app_volt_measure_INCLUDE = examples/adc

# rtc_app_clock example
rtc_app_clock_RELPATH = examples/rtc/clock
rtc_app_clock_PATH = $(starterware_PATH)/$(rtc_app_clock_RELPATH)
rtc_app_clock_PLATFORM_DEPENDENCY = yes
export rtc_app_clock_PLATFORM_DEPENDENCY
rtc_app_clock_INCLUDE = examples/rtc

# mcspi_app_flash example
mcspi_app_flash_RELPATH = examples/mcspi/flash
mcspi_app_flash_PATH = $(starterware_PATH)/$(mcspi_app_flash_RELPATH)
mcspi_app_flash_PLATFORM_DEPENDENCY = yes
export mcspi_app_flash_PLATFORM_DEPENDENCY
mcspi_app_flash_INCLUDE = examples/mcspi

# lcdc_app_raster example
lcdc_app_raster_RELPATH = examples/lcdc/raster
lcdc_app_raster_PATH = $(starterware_PATH)/$(lcdc_app_raster_RELPATH)
lcdc_app_raster_PLATFORM_DEPENDENCY = yes
export lcdc_app_raster_PLATFORM_DEPENDENCY
lcdc_app_raster_INCLUDE = examples/lcdc

# dcan_app_frame_tx_rx example
dcan_app_frame_tx_rx_RELPATH = examples/dcan/frame_tx_rx
dcan_app_frame_tx_rx_PATH = $(starterware_PATH)/$(dcan_app_frame_tx_rx_RELPATH)
dcan_app_frame_tx_rx_PLATFORM_DEPENDENCY = yes
export dcan_app_frame_tx_rx_PLATFORM_DEPENDENCY
dcan_app_frame_tx_rx_INCLUDE = examples/dcan

# dcan_app_loopback example
dcan_app_loopback_RELPATH = examples/dcan/loopback
dcan_app_loopback_PATH = $(starterware_PATH)/$(dcan_app_loopback_RELPATH)
dcan_app_loopback_PLATFORM_DEPENDENCY = yes
export dcan_app_loopback_PLATFORM_DEPENDENCY
dcan_app_loopback_INCLUDE = examples/dcan

# cap_tsc_app example
cap_tsc_app_RELPATH = examples/cap_tsc
cap_tsc_app_PATH = $(starterware_PATH)/$(cap_tsc_app_RELPATH)
cap_tsc_app_PLATFORM_DEPENDENCY = yes
export cap_tsc_app_PLATFORM_DEPENDENCY
cap_tsc_app_INCLUDE = 

# vpfe_app_capture_display example
vpfe_app_capture_display_RELPATH = examples/vpfe/capture_display
vpfe_app_capture_display_PATH = $(starterware_PATH)/$(vpfe_app_capture_display_RELPATH)
vpfe_app_capture_display_PLATFORM_DEPENDENCY = yes
export vpfe_app_capture_display_PLATFORM_DEPENDENCY
vpfe_app_capture_display_INCLUDE = examples/vpfe

# nand_app_read_write example
nand_app_read_write_RELPATH = examples/nand/read_write
nand_app_read_write_PATH = $(starterware_PATH)/$(nand_app_read_write_RELPATH)
nand_app_read_write_PLATFORM_DEPENDENCY = yes
export nand_app_read_write_PLATFORM_DEPENDENCY
nand_app_read_write_INCLUDE = examples/nand

# mmcsd_app_fs_shell example
mmcsd_app_fs_shell_RELPATH = examples/mmcsd/fs_shell
mmcsd_app_fs_shell_PATH = $(starterware_PATH)/$(mmcsd_app_fs_shell_RELPATH)
mmcsd_app_fs_shell_PLATFORM_DEPENDENCY = yes
export mmcsd_app_fs_shell_PLATFORM_DEPENDENCY
mmcsd_app_fs_shell_INCLUDE = ff9b_lib

# ddr diagnostics test
ddr_app_diag_test_RELPATH = examples/ddr/diag_test
ddr_app_diag_test_PATH = $(starterware_PATH)/$(ddr_app_diag_test_RELPATH)
ddr_app_diag_test_PLATFORM_DEPENDENCY = yes
export ddr_app_diag_test_PLATFORM_DEPENDENCY
ddr_app_diag_test_INCLUDE =

# rtc_app_only example
rtc_app_only_RELPATH = examples/rtc/rtc_only
rtc_app_only_PATH = $(starterware_PATH)/$(rtc_app_only_RELPATH)
rtc_app_only_PLATFORM_DEPENDENCY = yes
export rtc_app_only_PLATFORM_DEPENDENCY
rtc_app_only_INCLUDE = examples/rtc

# pm_app_demo example
pm_app_demo_RELPATH = examples/pm
pm_app_demo_PATH = $(starterware_PATH)/$(pm_app_demo_RELPATH)
pm_app_demo_PLATFORM_DEPENDENCY = yes
export pm_app_demo_PLATFORM_DEPENDENCY
pm_app_demo_INCLUDE = examples/pm

# Component specific CFLAGS
CFLAGS_COMP_COMMON +=

ifeq ($(BUILDCFG_MOD_UART), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_UART
endif # ifeq ($(BUILDCFG_MOD_UART), 1)

ifeq ($(BUILDCFG_MOD_I2C), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_I2C
endif # ifeq ($(BUILDCFG_MOD_I2C), 1)

ifeq ($(BUILDCFG_MOD_MCSPI), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_MCSPI
endif # ifeq ($(BUILDCFG_MOD_MCSPI), 1)

ifeq ($(BUILDCFG_MOD_ADC), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_ADC
endif # ifeq ($(BUILDCFG_MOD_ADC), 1)

ifeq ($(BUILDCFG_MOD_GPIO), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_GPIO
endif # ifeq ($(BUILDCFG_MOD_GPIO), 1)

ifeq ($(BUILDCFG_MOD_MMCSD), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_MMCSD
endif # ifeq ($(BUILDCFG_MOD_MMCSD), 1)

ifeq ($(BUILDCFG_MOD_DMTIMER), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_DMTIMER
endif # ifeq ($(BUILDCFG_MOD_DMTIMER), 1)

ifeq ($(BUILDCFG_MOD_EDMA3CC), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_EDMA3CC
endif # ifeq ($(BUILDCFG_MOD_EDMA3CC), 1)

ifeq ($(BUILDCFG_MOD_EDMA3TC), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_EDMA3TC
endif # ifeq ($(BUILDCFG_MOD_EDMA3TC), 1)

ifeq ($(BUILDCFG_MOD_PWMSS), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_PWMSS
endif # ifeq ($(BUILDCFG_MOD_PWMSS), 1)

ifeq ($(BUILDCFG_MOD_DSS), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_DSS
endif # ifeq ($(BUILDCFG_MOD_DSS), 1)

ifeq ($(BUILDCFG_MOD_QSPI), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_QSPI
endif # ifeq ($(BUILDCFG_MOD_QSPI), 1)

ifeq ($(BUILDCFG_MOD_WDT), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_WDT
endif # ifeq ($(BUILDCFG_MOD_WDT), 1)

ifeq ($(BUILDCFG_MOD_RTC), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_RTC
endif # ifeq ($(BUILDCFG_MOD_RTC), 1)

ifeq ($(BUILDCFG_MOD_LCDC), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_LCDC
endif # ifeq ($(BUILDCFG_MOD_LCDC), 1)

ifeq ($(BUILDCFG_MOD_DCAN), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_DCAN
endif # ifeq ($(BUILDCFG_MOD_DCAN), 1)

ifeq ($(BUILDCFG_MOD_VPFE), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_VPFE
endif # ifeq ($(BUILDCFG_MOD_VPFE), 1)

ifeq ($(BUILDCFG_MOD_CPSW), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_CPSW
endif # ifeq ($(BUILDCFG_MOD_ENET), 1)

ifeq ($(BUILDCFG_MOD_GPMC), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_GPMC
endif # ifeq ($(BUILDCFG_MOD_GPMC), 1)

ifeq ($(BUILDCFG_MOD_USB), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_USB
endif # ifeq ($(BUILDCFG_MOD_USB), 1)

ifeq ($(BUILDCFG_MOD_MDIO), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_MDIO
endif # ifeq ($(BUILDCFG_MOD_MDIO), 1)

ifeq ($(BUILDCFG_MOD_PRU_ETH), 1)
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_PRU_ETH
endif # ifeq ($(BUILDCFG_MOD_PRU_ETH), 1)

# BOOTMODE specific CFLAGS
ifeq ($(BOOTMODE), mmcsd)
  CFLAGS_COMP_COMMON += -DBOOT_MMCSD
  ifeq ($(SECUREMODE), yes)
     CFLAGS_COMP_COMMON += -DSECURE_BOOT
  endif
endif # ifeq ($(BOOTMODE), mmcsd)

ifeq ($(BOOTMODE), uart)
  CFLAGS_COMP_COMMON += -DBOOT_UART
  ifeq ($(SECUREMODE), yes)
     CFLAGS_COMP_COMMON += -DSECURE_BOOT
  endif
endif # ifeq ($(BOOTMODE), uart)

ifeq ($(BOOTMODE), qspi)
  CFLAGS_COMP_COMMON += -DBOOT_QSPI
endif # ifeq ($(BOOTMODE), qspi)

ifeq ($(BOOTMODE), nand)
  CFLAGS_COMP_COMMON += -DBOOT_NAND
endif # ifeq ($(BOOTMODE), nand)

ifeq ($(BOOTMODE), mcspi)
  CFLAGS_COMP_COMMON += -DBOOT_MCSPI
  
# Superset command line option to enable all features
# Example implementation: BUILD_ICSS_DDRLESS_BOOT
ifeq ($(BUILD_ICSS_DDRLESS_BOOT), yes)
export USE_DDR=no
export ENABLE_PRU=yes
export LOAD_BIN=yes
endif

# Individual command line options to enable additional SBL features
ifeq ($(USE_DDR), no)
  CFLAGS_COMP_COMMON += -DDDRLESS
endif

ifeq ($(ENABLE_PRU), yes)
  CFLAGS_COMP_COMMON += -DPRU_WKUP
  CFLAGS_COMP_COMMON += -DBUILDCFG_MOD_PRU_ICSS
endif

ifeq ($(LOAD_BIN), yes)
  CFLAGS_COMP_COMMON += -DBIN_INSTALL
endif

endif # ifeq ($(BOOTMODE), mcspi)

ifeq ($(CORE),)
else # ifeq ($(CORE),)
# CFLAGS based on example/demo/application properties
ifeq ($(PLATFORM),am335x-evm)
  STARTERWARE_CFLAGS += -DPLATFORM_EVM_SI
endif
ifeq ($(PLATFORM),amic110-ddrless)
  STARTERWARE_CFLAGS += -DPLATFORM_EVM_SI
endif
ifeq ($(PLATFORM),am43xx-evm)
  STARTERWARE_CFLAGS += -DPLATFORM_EVM_SI
endif
ifeq ($(PLATFORM),am43xx-zebu)
  STARTERWARE_CFLAGS += -DPLATFORM_ZEBU
endif

ifeq ($(SOCFAMILY), am335x)
  STARTERWARE_CFLAGS += -DAM335X_FAMILY_BUILD
endif # ifeq ($(SOCFAMILY), am335x)
ifeq ($(SOCFAMILY), am43xx)
  STARTERWARE_CFLAGS += -DAM43XX_FAMILY_BUILD
endif # ifeq ($(SOCFAMILY), am43xx)

ifeq ($(SOC), am335x)
  STARTERWARE_CFLAGS += -DAM335X_BUILD
endif # ifeq ($(SOC), am335x)
ifeq ($(SOC), am437x)
  STARTERWARE_CFLAGS += -DAM437X_BUILD
endif # ifeq ($(SOC), am437x)

ifeq ($(CORE),a8host)
  STARTERWARE_CFLAGS += -DBUILD_A8
endif

ifeq ($(CORE),a9host)
  STARTERWARE_CFLAGS += -DBUILD_A9
endif
endif

#Enable trace only for non-Klocwork build and for all profiles
ifeq ($(KW_BUILD),no)
  STARTERWARE_CFLAGS += -DUSE_STD_ASSERT -DTRACE_ENABLE
endif

# Enable standard asserts for klocwork build
ifeq ($(KW_BUILD),yes)
  STARTERWARE_CFLAGS += -DUSE_STD_ASSERT -DASSERT_ENABLE -DTRACE_ENABLE
endif


ifeq ($(PROFILE_$(CORE)),debug)
  STARTERWARE_CFLAGS += -DDEBUG_BUILD
# Enable asserts for debug build
  STARTERWARE_CFLAGS += -DASSERT_ENABLE
endif

ifeq ($(PROFILE_$(CORE)),release)
  STARTERWARE_CFLAGS += -DRELEASE_BUILD
# Enable asserts for release build
  STARTERWARE_CFLAGS += -DASSERT_ENABLE
endif

ifeq ($(PROFILE_$(CORE)),prod_release)
  STARTERWARE_CFLAGS += -DPROD_RELEASE_BUILD
# Disable asserts for production release
#  STARTERWARE_CFLAGS += -DASSERT_ENABLE
endif


export STARTERWARE_CFLAGS

# Nothing beyond this point

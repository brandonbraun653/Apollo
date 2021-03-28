# Copyright (C) 2015-2019 Texas Instruments Incorporated - http://www.ti.com/
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

# ROOT Directory
ifndef PDK_INSTALL_PATH
export ROOTDIR := ../..
else
export ROOTDIR = $(PDK_INSTALL_PATH)
endif

# PDK Board Library
ifndef PDK_DIAG_DIR
export PDK_DIAG_DIR = $(ROOTDIR)/ti/board
endif

ifeq ($(RULES_MAKE), )
include $(PDK_INSTALL_PATH)/ti/build/Rules.make
else
include $(RULES_MAKE)
endif

# Common Macros used in make
ifndef RM
export RM = rm -f
endif

ifndef CP
export CP = cp -p
endif

export MKDIR = mkdir -p

ifndef RMDIR
export RMDIR = rm -rf
endif

ifndef SED
export SED = sed
endif

ifndef MAKE
export MAKE = make
endif

ifeq ($(OS),Windows_NT)
export SDSCRIPT=create_sd.bat
else
export SDSCRIPT=./create_sd.sh
endif

ifeq ($(OS),Windows_NT)
export SPISCRIPT=create_spi.bat
else
export SPISCRIPT=./create_spi.sh
endif

ALL_BOARDS ?= idkAM571x idkAM572x idkAM574x evmAM572x evmK2G iceK2G evmAM335x evmAM437x idkAM437x skAM437x bbbAM335x icev2AM335x skAM335x evmOMAPL137 iceAMIC110 am65xx_evm am65xx_idk j721e_evm


idkAM571x_DIAG = dcan eeprom emmc framework framework_loader gmac haptics icss_emac lcd_touchscreen led led_industrial mcspi mem mmcsd pmic qspi timer uart
idkAM572x_DIAG = dcan eeprom emmc framework framework_loader gmac haptics icss_emac lcd_touchscreen led led_industrial mcspi mem mmcsd pmic qspi uart
evmAM571x_DIAG = eeprom framework framework_loader led mem pmic temperature uart
evmAM572x_DIAG = eeprom emmc framework framework_loader gmac led mem mmcsd pmic pwm temperature timer uart
idkAM574x_DIAG = dcan eeprom emmc framework framework_loader gmac haptics icss_emac lcd_touchscreen led led_industrial mcspi mem mmcsd pmic qspi uart
evmK2G_DIAG = dcan eeprom emmc framework hdmi lcd led mcasp mem nand norflash pwm qspi temperature uart uart2usb
iceK2G_DIAG = clock_generator current_monitor eeprom emac framework icss_emac led led_industrial mem oled_display qspi rotary_switch uart
am65xx_evm_DIAG = boot_eeprom boost_gpio boot_switch button current_monitor eeprom emac emmc ext_rtc framework icssg_emac lcd led led_industrial mcasp mem mmcsd norflash ospi pcie temperature uart usb_device usb_host
am65xx_idk_DIAG = boot_eeprom boot_switch button current_monitor eeprom emac emmc ext_rtc framework icssg_emac icssg_led led led_industrial mcan mem mmcsd norflash ospi pcie rotary_switch rs485_uart temperature uart usb_device usb_host
evmAM437x_DIAG = buzzer framework framework_loader haptics led mem uart mmcsd accelerometer temperature light_sensor eeprom rtc pmic adc button timer
evmAM335x_DIAG = framework framework_loader mem uart mmcsd buzzer accelerometer temperature light_sensor eeprom rtc pmic pwm adc timer
idkAM437x_DIAG = framework framework_loader led led_industrial qspi mem mmcsd uart eeprom mcspi pwm rtc
skAM437x_DIAG = framework framework_loader eeprom led uart mmcsd mem accelerometer rtc pmic adc button
bbbAM335x_DIAG = framework framework_loader eeprom uart mmcsd mem led rtc pmic
icev2AM335x_DIAG = framework framework_loader eeprom uart mmcsd mem led rtc pmic
skAM335x_DIAG = framework framework_loader eeprom uart mmcsd mem led accelerometer rtc pmic adc button
evmOMAPL137_DIAG = mcasp mcasp_audiodc
iceAMIC110_DIAG = framework framework_loader eeprom uart led mem mcspi ddrless_app
j721e_evm_DIAG = build

BUILD_DIRS = $(foreach a,$($(btests)),$(a)_build)
CLEAN_TARGETS = $(foreach a,$(ALL_BOARDS),$(a)_clean)
CLEAN_DIRS = $(foreach a,$($(ctests)),$(a)_clean)
ALL_SD = $(foreach a,$(ALL_BOARDS),$(a)_sd)
ALL_SPI = $(foreach a,$(ALL_BOARDS),$(a)_spi)

.NOTPARALLEL: 
.PHONY: $(ALL_BOARDS) $(BUILD_DIRS) $(CLEAN_TARGETS) $(CLEAN_DIRS) $(ALL_SD) $(ALL_SPI)

all: $(ALL_BOARDS)

$(ALL_BOARDS):
	$(MAKE) buildtarget bboard=$@ btests=$@_DIAG
 
buildtarget: $(BUILD_DIRS)

$(BUILD_DIRS):
ifeq ($(bboard),evmOMAPL137)
	$(MAKE) -C $(subst _build,,$@) BOARD=$(bboard) TARGET=c674x
	$(MAKE) -C $(subst _build,,$@) BOARD=$(bboard) TARGET=armv5
else ifeq ($(bboard),$(filter $(bboard), am65xx_evm am65xx_idk))
	$(MAKE) -C $(subst _build,,$@) BOARD=$(bboard) TARGET=armv8 BOOTMODE=$(bboot) TESTMODE=STRESS_TEST
	$(MAKE) -C $(subst _build,,$@) BOARD=$(bboard) TARGET=armv8 BOOTMODE=$(bboot) TESTMODE=FUNCTIONAL_TEST
	$(MAKE) -C $(subst _build,,$@) BOARD=$(bboard) TARGET=armv8 BOOTMODE=$(bboot) TESTMODE=COMPLIANCE_TEST
	$(MAKE) -C $(subst _build,,$@) BOARD=$(bboard) TARGET=armv7 BOOTMODE=$(bboot) TESTMODE=STRESS_TEST
	$(MAKE) -C $(subst _build,,$@) BOARD=$(bboard) TARGET=armv7 BOOTMODE=$(bboot) TESTMODE=FUNCTIONAL_TEST
	$(MAKE) -C $(subst _build,,$@) BOARD=$(bboard) TARGET=armv7 BOOTMODE=$(bboot) TESTMODE=COMPLIANCE_TEST
else ifeq ($(bboard),$(filter $(bboard), j721e_evm))
	$(MAKE) -C $(subst _build,,$@) BOARD=$(bboard) CORE=mpu1_0 BUILD_COMP=examples
	$(MAKE) -C $(subst _build,,$@) BOARD=$(bboard) CORE=mcu1_0 BUILD_COMP=examples
else
	$(MAKE) -C $(subst _build,,$@) BOARD=$(bboard) TARGET=armv7 BOOTMODE=$(bboot)
endif

$(ALL_SD):
	$(MAKE) sdtarget sboard=$(subst _sd,,$@) bboot=SD

sdtarget: $(sboard)
ifeq ($(sboard),$(filter $(sboard), am65xx_evm am65xx_idk))
	$(SDSCRIPT) $(sboard) armv8 0
	$(SDSCRIPT) $(sboard) armv7 4
else ifeq ($(sboard),$(filter $(sboard), j721e_evm))
# Nothing to be done for J7. Will be taken care by diag component make
else
	$(SDSCRIPT) $(sboard) armv7 0
endif

$(ALL_SPI):
	$(MAKE) spitarget sboard=$(subst _spi,,$@) bboot=SPI

spitarget: $(sboard)
	$(SPISCRIPT) $(sboard)

clean: $(CLEAN_TARGETS)

$(CLEAN_TARGETS):
	$(MAKE) cleantarget cboard=$(subst _clean,,$@) ctests=$(subst _clean,_DIAG,$@)

cleantarget: $(CLEAN_DIRS)

$(CLEAN_DIRS):
ifeq ($(cboard),evmOMAPL137)
	-$(MAKE) -C $(subst _clean,,$@) BOARD=$(cboard) TARGET=armv5 clean
	-$(MAKE) -C $(subst _clean,,$@) BOARD=$(cboard) TARGET=c674x clean
else ifeq ($(cboard),am65xx_evm)
	-$(MAKE) -C $(subst _clean,,$@) BOARD=$(cboard) TARGET=armv8 clean
else ifeq ($(cboard),am65xx_idk)
	-$(MAKE) -C $(subst _clean,,$@) BOARD=$(cboard) TARGET=armv8 clean
else ifeq ($(cboard),j721e_evm)
	-$(MAKE) -C $(subst _clean,,$@) CORE=mpu1_0 BOARD=$(cboard) BUILD_COMP=examples_clean
	-$(MAKE) -C $(subst _clean,,$@) CORE=mcu1_0 BOARD=$(cboard) BUILD_COMP=examples_clean
else
	-$(MAKE) -C $(subst _clean,,$@) BOARD=$(cboard) TARGET=armv7 clean
endif

#  ============================================================================
#  (C) Copyright 2019 Texas Instruments, Inc.
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
#
#  ============================================================================

# File: board_diag_component.mk
#       This file is component include make file of board diagnostic.
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
# <mod>_BOARD_DEPENDENCY - "yes": means the code for this module depends on
#                             board and the compiled obj/lib has to be kept
#                             under <board> directory
#                             "no" or "" or if this variable is not defined: means
#                             this module has no board dependent code and hence
#                             the obj/libs are not kept under <board> dir.
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
ifeq ($(board_diag_component_make_include), )

board_diag_j721e_BOARDLIST = j721e_evm
board_diag_j721e_CORELIST = mpu1_0 mcu1_0

############################
# Board diagnostic package
# List of diagnostics included under board diagnostic
# The components included here are built and will be part of board diagnostic
############################
board_diag_LIB_LIST =

############################
# board diagnostics
# List of diagnostics under board
# All the tests mentioned in list are built when test target is called
# List below all example for allowed values - note the list is populated in each example
############################
board_diag_EXAMPLE_LIST =

#
# Diagnostic Modules
#

# ARCH is used for diag binary folder name to align with existing platforms
ifeq ($(CORE),mpu1_0)
board_diag_LOCAL_BINPATH = $(PDK_BOARD_DIAG_COMP_PATH)/../bin/$(BOARD)/armv8
else
board_diag_LOCAL_BINPATH = $(PDK_BOARD_DIAG_COMP_PATH)/../bin/$(BOARD)/armv7
endif

board_diag_APPIMAGEGEN_CTRL = yes

# Board Diagnostic
board_diag_COMP_LIST = board_diag

# ADC
adc_board_diag_COMP_LIST = adc_board_diag
adc_board_diag_RELPATH = ti/board/diag/adc/build
adc_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/adc/build
adc_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
adc_board_diag_MAKEFILE = -f makefile
adc_board_diag_BOARD_DEPENDENCY = yes
adc_board_diag_CORE_DEPENDENCY = yes
export adc_board_diag_COMP_LIST
export adc_board_diag_BOARD_DEPENDENCY
export adc_board_diag_CORE_DEPENDENCY
export adc_board_diag_MAKEFILE
adc_board_diag_PKG_LIST = adc_board_diag
adc_board_diag_INCLUDE = $(adc_board_diag_PATH)
adc_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
adc_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export adc_board_diag_$(SOC)_CORELIST
export adc_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += adc_board_diag

# AUTOMATION HEADER
automationHeader_board_diag_COMP_LIST = automationHeader_board_diag
automationHeader_board_diag_RELPATH = ti/board/diag/automation_header/build
automationHeader_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/automation_header/build
automationHeader_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
automationHeader_board_diag_MAKEFILE = -f makefile
automationHeader_board_diag_BOARD_DEPENDENCY = yes
automationHeader_board_diag_CORE_DEPENDENCY = yes
export automationHeader_board_diag_COMP_LIST
export automationHeader_board_diag_BOARD_DEPENDENCY
export automationHeader_board_diag_CORE_DEPENDENCY
export automationHeader_board_diag_MAKEFILE
automationHeader_board_diag_PKG_LIST = automationHeader_board_diag
automationHeader_board_diag_INCLUDE = $(automationHeader_board_diag_PATH)
automationHeader_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
automationHeader_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export automationHeader_board_diag_$(SOC)_CORELIST
export automationHeader_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += automationHeader_board_diag

# BOOT EEPROM
bootEeprom_board_diag_COMP_LIST = bootEeprom_board_diag
bootEeprom_board_diag_RELPATH = ti/board/diag/boot_eeprom/build
bootEeprom_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/boot_eeprom/build
bootEeprom_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
bootEeprom_board_diag_MAKEFILE = -f makefile
bootEeprom_board_diag_BOARD_DEPENDENCY = yes
bootEeprom_board_diag_CORE_DEPENDENCY = yes
export bootEeprom_board_diag_COMP_LIST
export bootEeprom_board_diag_BOARD_DEPENDENCY
export bootEeprom_board_diag_CORE_DEPENDENCY
export bootEeprom_board_diag_MAKEFILE
bootEeprom_board_diag_PKG_LIST = bootEeprom_board_diag
bootEeprom_board_diag_INCLUDE = $(bootEeprom_board_diag_PATH)
bootEeprom_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
bootEeprom_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export bootEeprom_board_diag_$(SOC)_CORELIST
export bootEeprom_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += bootEeprom_board_diag

# BOOT SWITCH
bootSwitch_board_diag_COMP_LIST = bootSwitch_board_diag
bootSwitch_board_diag_RELPATH = ti/board/diag/boot_switch/build
bootSwitch_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/boot_switch/build
bootSwitch_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
bootSwitch_board_diag_MAKEFILE = -f makefile
bootSwitch_board_diag_BOARD_DEPENDENCY = yes
bootSwitch_board_diag_CORE_DEPENDENCY = yes
export bootSwitch_board_diag_COMP_LIST
export bootSwitch_board_diag_BOARD_DEPENDENCY
export bootSwitch_board_diag_CORE_DEPENDENCY
export bootSwitch_board_diag_MAKEFILE
bootSwitch_board_diag_PKG_LIST = bootSwitch_board_diag
bootSwitch_board_diag_INCLUDE = $(bootSwitch_board_diag_PATH)
bootSwitch_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
bootSwitch_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export bootSwitch_board_diag_$(SOC)_CORELIST
export bootSwitch_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += bootSwitch_board_diag

# CLOCK GENERATOR
clockGen_board_diag_COMP_LIST = clockGen_board_diag
clockGen_board_diag_RELPATH = ti/board/diag/clock_generator/build
clockGen_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/clock_generator/build
clockGen_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
clockGen_board_diag_MAKEFILE = -f makefile
clockGen_board_diag_BOARD_DEPENDENCY = yes
clockGen_board_diag_CORE_DEPENDENCY = yes
export clockGen_board_diag_COMP_LIST
export clockGen_board_diag_BOARD_DEPENDENCY
export clockGen_board_diag_CORE_DEPENDENCY
export clockGen_board_diag_MAKEFILE
clockGen_board_diag_PKG_LIST = clockGen_board_diag
clockGen_board_diag_INCLUDE = $(clockGen_board_diag_PATH)
clockGen_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
clockGen_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export clockGen_board_diag_$(SOC)_CORELIST
export clockGen_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += clockGen_board_diag

# CPSW EMAC
cpsw_board_diag_COMP_LIST = cpsw_board_diag
cpsw_board_diag_RELPATH = ti/board/diag/cpsw/build
cpsw_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/cpsw/build
cpsw_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
cpsw_board_diag_MAKEFILE = -f makefile
cpsw_board_diag_BOARD_DEPENDENCY = yes
cpsw_board_diag_CORE_DEPENDENCY = yes
export cpsw_board_diag_COMP_LIST
export cpsw_board_diag_BOARD_DEPENDENCY
export cpsw_board_diag_CORE_DEPENDENCY
export cpsw_board_diag_MAKEFILE
cpsw_board_diag_PKG_LIST = cpsw_board_diag
cpsw_board_diag_INCLUDE = $(cpsw_board_diag_PATH)
cpsw_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
cpsw_board_diag_$(SOC)_CORELIST = mcu2_0
export cpsw_board_diag_$(SOC)_CORELIST
export cpsw_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)

# Add CPSW example only if the CPSW component path exists
ifneq ($(wildcard $(PDK_CPSW_COMP_PATH)),)
board_diag_EXAMPLE_LIST += cpsw_board_diag
endif

# csirx
csirx_board_diag_COMP_LIST = csirx_board_diag
csirx_board_diag_RELPATH = ti/board/diag/csirx/build
csirx_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/csirx/build
csirx_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
csirx_board_diag_MAKEFILE = -f makefile
csirx_board_diag_BOARD_DEPENDENCY = yes
csirx_board_diag_CORE_DEPENDENCY = yes
export csirx_board_diag_COMP_LIST
export csirx_board_diag_BOARD_DEPENDENCY
export csirx_board_diag_CORE_DEPENDENCY
export csirx_board_diag_MAKEFILE
csirx_board_diag_PKG_LIST = csirx_board_diag
csirx_board_diag_INCLUDE = $(csirx_board_diag_PATH)
csirx_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
csirx_board_diag_$(SOC)_CORELIST = mcu2_1
export csirx_board_diag_$(SOC)_CORELIST
export csirx_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)

# Add CSIRX diagnostic test only if the CSIRX component path exists
ifneq ($(wildcard $(PDK_CSIRX_COMP_PATH)),)
board_diag_EXAMPLE_LIST += csirx_board_diag
endif


# CURRENT MONITOR
currentMonitor_board_diag_COMP_LIST = currentMonitor_board_diag
currentMonitor_board_diag_RELPATH = ti/board/diag/current_monitor/build
currentMonitor_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/current_monitor/build
currentMonitor_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
currentMonitor_board_diag_MAKEFILE = -f makefile
currentMonitor_board_diag_BOARD_DEPENDENCY = yes
currentMonitor_board_diag_CORE_DEPENDENCY = yes
export currentMonitor_board_diag_COMP_LIST
export currentMonitor_board_diag_BOARD_DEPENDENCY
export currentMonitor_board_diag_CORE_DEPENDENCY
export currentMonitor_board_diag_MAKEFILE
currentMonitor_board_diag_PKG_LIST = currentMonitor_board_diag
currentMonitor_board_diag_INCLUDE = $(currentMonitor_board_diag_PATH)
currentMonitor_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
currentMonitor_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export currentMonitor_board_diag_$(SOC)_CORELIST
export currentMonitor_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += currentMonitor_board_diag

# DISPLAYPORT
displayPort_board_diag_COMP_LIST = displayPort_board_diag
displayPort_board_diag_RELPATH = ti/board/diag/display_port/build
displayPort_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/display_port/build
displayPort_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
displayPort_board_diag_MAKEFILE = -f makefile
displayPort_board_diag_BOARD_DEPENDENCY = yes
displayPort_board_diag_CORE_DEPENDENCY = yes
export displayPort_board_diag_COMP_LIST
export displayPort_board_diag_BOARD_DEPENDENCY
export displayPort_board_diag_CORE_DEPENDENCY
export displayPort_board_diag_MAKEFILE
displayPort_board_diag_PKG_LIST = displayPort_board_diag
displayPort_board_diag_INCLUDE = $(displayPort_board_diag_PATH)
displayPort_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
displayPort_board_diag_$(SOC)_CORELIST = mcu2_1
export displayPort_board_diag_$(SOC)_CORELIST
export displayPort_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += displayPort_board_diag

# DSI
dsi_board_diag_COMP_LIST = dsi_board_diag
dsi_board_diag_RELPATH = ti/board/diag/dsi/build
dsi_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/dsi/build
dsi_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
dsi_board_diag_MAKEFILE = -f makefile
dsi_board_diag_BOARD_DEPENDENCY = yes
dsi_board_diag_CORE_DEPENDENCY = yes
export dsi_board_diag_COMP_LIST
export dsi_board_diag_BOARD_DEPENDENCY
export dsi_board_diag_CORE_DEPENDENCY
export dsi_board_diag_MAKEFILE
dsi_board_diag_PKG_LIST = dsi_board_diag
dsi_board_diag_INCLUDE = $(dsi_board_diag_PATH)
dsi_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
dsi_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export dsi_board_diag_$(SOC)_CORELIST
export dsi_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += dsi_board_diag

# EEPROM
eeprom_board_diag_COMP_LIST = eeprom_board_diag
eeprom_board_diag_RELPATH = ti/board/diag/eeprom/build
eeprom_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/eeprom/build
eeprom_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
eeprom_board_diag_MAKEFILE = -f makefile
eeprom_board_diag_BOARD_DEPENDENCY = yes
eeprom_board_diag_CORE_DEPENDENCY = yes
export eeprom_board_diag_COMP_LIST
export eeprom_board_diag_BOARD_DEPENDENCY
export eeprom_board_diag_CORE_DEPENDENCY
export eeprom_board_diag_MAKEFILE
eeprom_board_diag_PKG_LIST = eeprom_board_diag
eeprom_board_diag_INCLUDE = $(eeprom_board_diag_PATH)
eeprom_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
eeprom_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export eeprom_board_diag_$(SOC)_CORELIST
export eeprom_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += eeprom_board_diag

# EMAC
emac_board_diag_COMP_LIST = emac_board_diag
emac_board_diag_RELPATH = ti/board/diag/emac/build
emac_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/emac/build
emac_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
emac_board_diag_MAKEFILE = -f makefile
emac_board_diag_BOARD_DEPENDENCY = yes
emac_board_diag_CORE_DEPENDENCY = yes
export emac_board_diag_COMP_LIST
export emac_board_diag_BOARD_DEPENDENCY
export emac_board_diag_CORE_DEPENDENCY
export emac_board_diag_MAKEFILE
emac_board_diag_PKG_LIST = emac_board_diag
emac_board_diag_INCLUDE = $(emac_board_diag_PATH)
emac_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
emac_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export emac_board_diag_$(SOC)_CORELIST
export emac_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
#board_diag_EXAMPLE_LIST += emac_board_diag

# EMMC
emmc_board_diag_COMP_LIST = emmc_board_diag
emmc_board_diag_RELPATH = ti/board/diag/emmc/build
emmc_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/emmc/build
emmc_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
emmc_board_diag_MAKEFILE = -f makefile
emmc_board_diag_BOARD_DEPENDENCY = yes
emmc_board_diag_CORE_DEPENDENCY = yes
export emmc_board_diag_COMP_LIST
export emmc_board_diag_BOARD_DEPENDENCY
export emmc_board_diag_CORE_DEPENDENCY
export emmc_board_diag_MAKEFILE
emmc_board_diag_PKG_LIST = emmc_board_diag
emmc_board_diag_INCLUDE = $(emmc_board_diag_PATH)
emmc_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
emmc_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export emmc_board_diag_$(SOC)_CORELIST
export emmc_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += emmc_board_diag

# EXPANSION HEADER
expHeader_board_diag_COMP_LIST = expHeader_board_diag
expHeader_board_diag_RELPATH = ti/board/diag/exp_header/build
expHeader_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/exp_header/build
expHeader_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
expHeader_board_diag_MAKEFILE = -f makefile
expHeader_board_diag_BOARD_DEPENDENCY = yes
expHeader_board_diag_CORE_DEPENDENCY = yes
export expHeader_board_diag_COMP_LIST
export expHeader_board_diag_BOARD_DEPENDENCY
export expHeader_board_diag_CORE_DEPENDENCY
export expHeader_board_diag_MAKEFILE
expHeader_board_diag_PKG_LIST = expHeader_board_diag
expHeader_board_diag_INCLUDE = $(expHeader_board_diag_PATH)
expHeader_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
expHeader_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export expHeader_board_diag_$(SOC)_CORELIST
export expHeader_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += expHeader_board_diag

# EXTERNAL RTC
extRtc_board_diag_COMP_LIST = extRtc_board_diag
extRtc_board_diag_RELPATH = ti/board/diag/ext_rtc/build
extRtc_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/ext_rtc/build
extRtc_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
extRtc_board_diag_MAKEFILE = -f makefile
extRtc_board_diag_BOARD_DEPENDENCY = yes
extRtc_board_diag_CORE_DEPENDENCY = yes
export extRtc_board_diag_COMP_LIST
export extRtc_board_diag_BOARD_DEPENDENCY
export extRtc_board_diag_CORE_DEPENDENCY
export extRtc_board_diag_MAKEFILE
extRtc_board_diag_PKG_LIST = extRtc_board_diag
extRtc_board_diag_INCLUDE = $(extRtc_board_diag_PATH)
extRtc_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
extRtc_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export extRtc_board_diag_$(SOC)_CORELIST
export extRtc_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += extRtc_board_diag

# FPD LIB
fpdLib_board_diag_COMP_LIST = fpdLib_board_diag
fpdLib_board_diag_RELPATH = ti/board/diag/fpd_lib/build
fpdLib_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/fpd_lib/build
fpdLib_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
fpdLib_board_diag_MAKEFILE = -f makefile
fpdLib_board_diag_BOARD_DEPENDENCY = yes
fpdLib_board_diag_CORE_DEPENDENCY = yes
export fpdLib_board_diag_COMP_LIST
export fpdLib_board_diag_BOARD_DEPENDENCY
export fpdLib_board_diag_CORE_DEPENDENCY
export fpdLib_board_diag_MAKEFILE
fpdLib_board_diag_PKG_LIST = fpdLib_board_diag
fpdLib_board_diag_INCLUDE = $(fpdLib_board_diag_PATH)
fpdLib_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
fpdLib_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export fpdLib_board_diag_$(SOC)_CORELIST
export fpdLib_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += fpdLib_board_diag

# Framework
framework_board_diag_COMP_LIST = framework_board_diag
framework_board_diag_RELPATH = ti/board/diag/framework/build
framework_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/framework/build
framework_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
framework_board_diag_MAKEFILE = -f makefile
framework_board_diag_BOARD_DEPENDENCY = yes
framework_board_diag_CORE_DEPENDENCY = yes
export framework_board_diag_COMP_LIST
export framework_board_diag_BOARD_DEPENDENCY
export framework_board_diag_CORE_DEPENDENCY
export framework_board_diag_MAKEFILE
framework_board_diag_PKG_LIST = framework_board_diag
framework_board_diag_INCLUDE = $(framework_board_diag_PATH)
framework_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
framework_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export framework_board_diag_$(SOC)_CORELIST
export framework_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += framework_board_diag

# HDMI
hdmi_board_diag_COMP_LIST = hdmi_board_diag
hdmi_board_diag_RELPATH = ti/board/diag/hdmi/build
hdmi_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/hdmi/build
hdmi_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
hdmi_board_diag_MAKEFILE = -f makefile
hdmi_board_diag_BOARD_DEPENDENCY = yes
hdmi_board_diag_CORE_DEPENDENCY = yes
export hdmi_board_diag_COMP_LIST
export hdmi_board_diag_BOARD_DEPENDENCY
export hdmi_board_diag_CORE_DEPENDENCY
export hdmi_board_diag_MAKEFILE
hdmi_board_diag_PKG_LIST = hdmi_board_diag
hdmi_board_diag_INCLUDE = $(hdmi_board_diag_PATH)
hdmi_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
hdmi_board_diag_$(SOC)_CORELIST = mcu2_1
export hdmi_board_diag_$(SOC)_CORELIST
export hdmi_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += hdmi_board_diag

# HYPERBUS
hyperbus_board_diag_COMP_LIST = hyperbus_board_diag
hyperbus_board_diag_RELPATH = ti/board/diag/hyperbus/build
hyperbus_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/hyperbus/build
hyperbus_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
hyperbus_board_diag_MAKEFILE = -f makefile
hyperbus_board_diag_BOARD_DEPENDENCY = yes
hyperbus_board_diag_CORE_DEPENDENCY = yes
export hyperbus_board_diag_COMP_LIST
export hyperbus_board_diag_BOARD_DEPENDENCY
export hyperbus_board_diag_CORE_DEPENDENCY
export hyperbus_board_diag_MAKEFILE
hyperbus_board_diag_PKG_LIST = hyperbus_board_diag
hyperbus_board_diag_INCLUDE = $(hyperbus_board_diag_PATH)
hyperbus_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
hyperbus_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export hyperbus_board_diag_$(SOC)_CORELIST
export hyperbus_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += hyperbus_board_diag

# LED
led_board_diag_COMP_LIST = led_board_diag
led_board_diag_RELPATH = ti/board/diag/led/build
led_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/led/build
led_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
led_board_diag_MAKEFILE = -f makefile
led_board_diag_BOARD_DEPENDENCY = yes
led_board_diag_CORE_DEPENDENCY = yes
export led_board_diag_COMP_LIST
export led_board_diag_BOARD_DEPENDENCY
export led_board_diag_CORE_DEPENDENCY
export led_board_diag_MAKEFILE
led_board_diag_PKG_LIST = led_board_diag
led_board_diag_INCLUDE = $(led_board_diag_PATH)
led_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
led_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export led_board_diag_$(SOC)_CORELIST
export led_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += led_board_diag

# LIN
lin_board_diag_COMP_LIST = lin_board_diag
lin_board_diag_RELPATH = ti/board/diag/lin/build
lin_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/lin/build
lin_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
lin_board_diag_MAKEFILE = -f makefile
lin_board_diag_BOARD_DEPENDENCY = yes
lin_board_diag_CORE_DEPENDENCY = yes
export lin_board_diag_COMP_LIST
export lin_board_diag_BOARD_DEPENDENCY
export lin_board_diag_CORE_DEPENDENCY
export lin_board_diag_MAKEFILE
lin_board_diag_PKG_LIST = lin_board_diag
lin_board_diag_INCLUDE = $(lin_board_diag_PATH)
lin_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
lin_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export lin_board_diag_$(SOC)_CORELIST
export lin_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += lin_board_diag

# MCAN
mcan_board_diag_COMP_LIST = mcan_board_diag
mcan_board_diag_RELPATH = ti/board/diag/mcan/build
mcan_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/mcan/build
mcan_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
mcan_board_diag_MAKEFILE = -f makefile
mcan_board_diag_BOARD_DEPENDENCY = yes
mcan_board_diag_CORE_DEPENDENCY = yes
export mcan_board_diag_COMP_LIST
export mcan_board_diag_BOARD_DEPENDENCY
export mcan_board_diag_CORE_DEPENDENCY
export mcan_board_diag_MAKEFILE
mcan_board_diag_PKG_LIST = mcan_board_diag
mcan_board_diag_INCLUDE = $(mcan_board_diag_PATH)
mcan_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
mcan_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export mcan_board_diag_$(SOC)_CORELIST
export mcan_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += mcan_board_diag

# LEO PMIC LIB
leoPmicLib_board_diag_COMP_LIST = leoPmicLib_board_diag
leoPmicLib_board_diag_RELPATH = ti/board/diag/leo_pmic_lib/build
leoPmicLib_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/leo_pmic_lib/build
leoPmicLib_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
leoPmicLib_board_diag_MAKEFILE = -f makefile
leoPmicLib_board_diag_BOARD_DEPENDENCY = yes
leoPmicLib_board_diag_CORE_DEPENDENCY = yes
export leoPmicLib_board_diag_COMP_LIST
export leoPmicLib_board_diag_BOARD_DEPENDENCY
export leoPmicLib_board_diag_CORE_DEPENDENCY
export leoPmicLib_board_diag_MAKEFILE
leoPmicLib_board_diag_PKG_LIST = leoPmicLib_board_diag
leoPmicLib_board_diag_INCLUDE = $(leoPmicLib_board_diag_PATH)
leoPmicLib_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
leoPmicLib_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export leoPmicLib_board_diag_$(SOC)_CORELIST
export leoPmicLib_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += leoPmicLib_board_diag

# MEM
mem_board_diag_COMP_LIST = mem_board_diag
mem_board_diag_RELPATH = ti/board/diag/mem/build
mem_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/mem/build
mem_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
mem_board_diag_MAKEFILE = -f makefile
mem_board_diag_BOARD_DEPENDENCY = yes
mem_board_diag_CORE_DEPENDENCY = yes
export mem_board_diag_COMP_LIST
export mem_board_diag_BOARD_DEPENDENCY
export mem_board_diag_CORE_DEPENDENCY
export mem_board_diag_MAKEFILE
mem_board_diag_PKG_LIST = mem_board_diag
mem_board_diag_INCLUDE = $(mem_board_diag_PATH)
mem_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
mem_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export mem_board_diag_$(SOC)_CORELIST
export mem_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += mem_board_diag

# MMCSD
mmcsd_board_diag_COMP_LIST = mmcsd_board_diag
mmcsd_board_diag_RELPATH = ti/board/diag/mmcsd/build
mmcsd_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/mmcsd/build
mmcsd_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
mmcsd_board_diag_MAKEFILE = -f makefile
mmcsd_board_diag_BOARD_DEPENDENCY = yes
mmcsd_board_diag_CORE_DEPENDENCY = yes
export mmcsd_board_diag_COMP_LIST
export mmcsd_board_diag_BOARD_DEPENDENCY
export mmcsd_board_diag_CORE_DEPENDENCY
export mmcsd_board_diag_MAKEFILE
mmcsd_board_diag_PKG_LIST = mmcsd_board_diag
mmcsd_board_diag_INCLUDE = $(mmcsd_board_diag_PATH)
mmcsd_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
mmcsd_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export mmcsd_board_diag_$(SOC)_CORELIST
export mmcsd_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += mmcsd_board_diag

# NOR FLASH
norflash_board_diag_COMP_LIST = norflash_board_diag
norflash_board_diag_RELPATH = ti/board/diag/norflash/build
norflash_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/norflash/build
norflash_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
norflash_board_diag_MAKEFILE = -f makefile
norflash_board_diag_BOARD_DEPENDENCY = yes
norflash_board_diag_CORE_DEPENDENCY = yes
export norflash_board_diag_COMP_LIST
export norflash_board_diag_BOARD_DEPENDENCY
export norflash_board_diag_CORE_DEPENDENCY
export norflash_board_diag_MAKEFILE
norflash_board_diag_PKG_LIST = norflash_board_diag
norflash_board_diag_INCLUDE = $(norflash_board_diag_PATH)
norflash_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
norflash_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export norflash_board_diag_$(SOC)_CORELIST
export norflash_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += norflash_board_diag

# OSPI
ospi_board_diag_COMP_LIST = ospi_board_diag
ospi_board_diag_RELPATH = ti/board/diag/ospi/build
ospi_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/ospi/build
ospi_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
ospi_board_diag_MAKEFILE = -f makefile
ospi_board_diag_BOARD_DEPENDENCY = yes
ospi_board_diag_CORE_DEPENDENCY = yes
export ospi_board_diag_COMP_LIST
export ospi_board_diag_BOARD_DEPENDENCY
export ospi_board_diag_CORE_DEPENDENCY
export ospi_board_diag_MAKEFILE
ospi_board_diag_PKG_LIST = ospi_board_diag
ospi_board_diag_INCLUDE = $(ospi_board_diag_PATH)
ospi_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
ospi_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export ospi_board_diag_$(SOC)_CORELIST
export ospi_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += ospi_board_diag

# PMIC
pmic_board_diag_COMP_LIST = pmic_board_diag
pmic_board_diag_RELPATH = ti/board/diag/pmic/build
pmic_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/pmic/build
pmic_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
pmic_board_diag_MAKEFILE = -f makefile
pmic_board_diag_BOARD_DEPENDENCY = yes
pmic_board_diag_CORE_DEPENDENCY = yes
export pmic_board_diag_COMP_LIST
export pmic_board_diag_BOARD_DEPENDENCY
export pmic_board_diag_CORE_DEPENDENCY
export pmic_board_diag_MAKEFILE
pmic_board_diag_PKG_LIST = pmic_board_diag
pmic_board_diag_INCLUDE = $(pmic_board_diag_PATH)
pmic_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
pmic_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export pmic_board_diag_$(SOC)_CORELIST
export pmic_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += pmic_board_diag

# RS485 UART
rs485Uart_board_diag_COMP_LIST = rs485Uart_board_diag
rs485Uart_board_diag_RELPATH = ti/board/diag/rs485_uart/build
rs485Uart_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/rs485_uart/build
rs485Uart_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
rs485Uart_board_diag_MAKEFILE = -f makefile
rs485Uart_board_diag_BOARD_DEPENDENCY = yes
rs485Uart_board_diag_CORE_DEPENDENCY = yes
export rs485Uart_board_diag_COMP_LIST
export rs485Uart_board_diag_BOARD_DEPENDENCY
export rs485Uart_board_diag_CORE_DEPENDENCY
export rs485Uart_board_diag_MAKEFILE
rs485Uart_board_diag_PKG_LIST = rs485Uart_board_diag
rs485Uart_board_diag_INCLUDE = $(rs485Uart_board_diag_PATH)
rs485Uart_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
rs485Uart_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export rs485Uart_board_diag_$(SOC)_CORELIST
export rs485Uart_board_diag_SBL_APPIMAGEGEN = yes
#board_diag_EXAMPLE_LIST += rs485Uart_board_diag

# TEMPERATURE
temperature_board_diag_COMP_LIST = temperature_board_diag
temperature_board_diag_RELPATH = ti/board/diag/temperature/build
temperature_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/temperature/build
temperature_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
temperature_board_diag_MAKEFILE = -f makefile
temperature_board_diag_BOARD_DEPENDENCY = yes
temperature_board_diag_CORE_DEPENDENCY = yes
export temperature_board_diag_COMP_LIST
export temperature_board_diag_BOARD_DEPENDENCY
export temperature_board_diag_CORE_DEPENDENCY
export temperature_board_diag_MAKEFILE
temperature_board_diag_PKG_LIST = temperature_board_diag
temperature_board_diag_INCLUDE = $(temperature_board_diag_PATH)
temperature_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
temperature_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export temperature_board_diag_$(SOC)_CORELIST
export temperature_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += temperature_board_diag

# UART
uart_board_diag_COMP_LIST = uart_board_diag
uart_board_diag_RELPATH = ti/board/diag/uart/build
uart_board_diag_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/uart/build
uart_board_diag_CUSTOM_BINPATH = $(board_diag_LOCAL_BINPATH)
uart_board_diag_MAKEFILE = -f makefile
uart_board_diag_BOARD_DEPENDENCY = yes
uart_board_diag_CORE_DEPENDENCY = yes
export uart_board_diag_COMP_LIST
export uart_board_diag_BOARD_DEPENDENCY
export uart_board_diag_CORE_DEPENDENCY
export uart_board_diag_MAKEFILE
uart_board_diag_PKG_LIST = uart_board_diag
uart_board_diag_INCLUDE = $(uart_board_diag_PATH)
uart_board_diag_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
uart_board_diag_$(SOC)_CORELIST = $(board_diag_$(SOC)_CORELIST)
export uart_board_diag_$(SOC)_CORELIST
export uart_board_diag_SBL_APPIMAGEGEN = $(board_diag_APPIMAGEGEN_CTRL)
board_diag_EXAMPLE_LIST += uart_board_diag

# Diagnostic test image creation for SD boot.
# Keep this at the end to get executed after building all the diagnostic tests
board_diag_img_COMP_LIST = board_diag_img
board_diag_img_RELPATH = ti/board/diag/build
board_diag_img_PATH = $(PDK_BOARD_DIAG_COMP_PATH)/build
board_diag_img_MAKEFILE = -f board_diag_img.mk
board_diag_img_BOARD_DEPENDENCY = no
board_diag_img_CORE_DEPENDENCY = no
board_diag_img_PKG_LIST = board_diag_img
export board_diag_img_COMP_LIST
export board_diag_img_BOARD_DEPENDENCY
export board_diag_img_CORE_DEPENDENCY
export board_diag_img_MAKEFILE
board_diag_img_INCLUDE = $(board_diag_img_PATH)
board_diag_img_BOARDLIST = $(board_diag_$(SOC)_BOARDLIST)
board_diag_img_$(SOC)_CORELIST = mpu1_0
export board_diag_img_$(SOC)_CORELIST
board_diag_EXAMPLE_LIST += board_diag_img

export board_diag_EXAMPLE_LIST

# Diagnostic test build flags
ifeq ($(BUILD_PROFILE),debug)
BOARD_DIAG_CFLAGS = -DPDK_RAW_BOOT
PROFILE = debug
export PROFILE
export BOARD_DIAG_CFLAGS
endif

board_diag_component_make_include := 1
endif

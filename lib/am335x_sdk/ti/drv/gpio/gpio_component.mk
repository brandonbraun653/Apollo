#
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

# File: gpio_component.mk
#       This file is component include make file of GPIO rtosrary.
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
#                             core and the compiled obj/rtos has to be kept
#                             under <core> directory
#                             "no" or "" or if this variable is not defined: means
#                             this module has no core dependent code and hence
#                             the obj/rtoss are not kept under <core> dir.
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
ifeq ($(gpio_component_make_include), )

# under other list
drvgpio_BOARDLIST       = am65xx_evm am65xx_idk j721e_sim j721e_evm j7200_evm
drvgpio_SOCLIST         = am574x am572x am571x dra72x dra75x dra78x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138 am65xx j721e j7200
drvgpio_SOCPROFILELIST  = am574x am572x am571x dra72x dra75x dra78x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138
drvgpio_am574x_CORELIST = c66x a15_0 ipu1_0
drvgpio_am572x_CORELIST = c66x a15_0 ipu1_0
drvgpio_am571x_CORELIST = c66x a15_0 ipu1_0
drvgpio_dra72x_CORELIST = c66x a15_0 ipu1_0
drvgpio_dra75x_CORELIST = c66x a15_0 ipu1_0
drvgpio_dra78x_CORELIST = c66x ipu1_0
drvgpio_k2h_CORELIST    = c66x a15_0
drvgpio_k2k_CORELIST    = c66x a15_0
drvgpio_k2l_CORELIST    = c66x a15_0
drvgpio_k2e_CORELIST    = c66x a15_0
drvgpio_k2g_CORELIST    = c66x a15_0
drvgpio_c6678_CORELIST  = c66x
drvgpio_c6657_CORELIST  = c66x
drvgpio_omapl137_CORELIST  = c674x arm9_0
drvgpio_omapl138_CORELIST  = c674x arm9_0
drvgpio_am437x_CORELIST = a9host
drvgpio_am335x_CORELIST = a8host
drvgpio_am65xx_CORELIST   = mpu1_0 mcu1_0
drvgpio_j721e_CORELIST   = $(DEFAULT_j721e_CORELIST)
drvgpio_j721e_CORELISTARM = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1 mcu3_0 mcu3_1
drvgpio_j7200_CORELIST    = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1
drvgpio_j7200_CORELISTARM = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1
############################
# gpio package
# List of components included under gpio rtos
# The components included here are built and will be part of gpio rtos
############################
gpio_LIB_LIST = gpio gpio_indp gpio_profile gpio_profile_indp
drvgpio_LIB_LIST = $(gpio_LIB_LIST)

############################
# gpio examples
# List of examples under gpio
# All the tests mentioned in list are built when test target is called
# List below all examples for allowed values
############################
gpio_EXAMPLE_LIST = GPIO_Baremetal_LedBlink_TestApp GPIO_LedBlink_TestApp
drvgpio_EXAMPLE_LIST = $(gpio_EXAMPLE_LIST)

#
# GPIO Modules
#

# GPIO LIB
gpio_COMP_LIST = gpio
gpio_RELPATH = ti/drv/gpio
gpio_PATH = $(PDK_GPIO_COMP_PATH)
gpio_LIBNAME = ti.drv.gpio
export gpio_LIBNAME
gpio_LIBPATH = $(gpio_PATH)/lib
export gpio_LIBPATH
gpio_OBJPATH = $(gpio_RELPATH)/gpio
export gpio_OBJPATH
gpio_MAKEFILE = -f build/makefile.mk
export gpio_MAKEFILE
gpio_BOARD_DEPENDENCY = no
gpio_CORE_DEPENDENCY = no
gpio_SOC_DEPENDENCY = yes
export gpio_COMP_LIST
export gpio_BOARD_DEPENDENCY
export gpio_CORE_DEPENDENCY
export gpio_SOC_DEPENDENCY
gpio_PKG_LIST = gpio
export gpio_PKG_LIST
gpio_INCLUDE = $(gpio_PATH)
gpio_SOCLIST = $(drvgpio_SOCLIST)
export gpio_SOCLIST
gpio_$(SOC)_CORELIST = $(drvgpio_$(SOC)_CORELIST)
export gpio_$(SOC)_CORELIST

# GPIO INDEPENDENT LIB
gpio_indp_COMP_LIST = gpio_indp
gpio_indp_RELPATH = ti/drv/gpio
gpio_indp_PATH = $(PDK_GPIO_COMP_PATH)
gpio_indp_LIBNAME = ti.drv.gpio
export gpio_indp_LIBNAME
gpio_indp_LIBPATH = $(gpio_indp_PATH)/lib
export gpio_indp_LIBPATH
gpio_indp_OBJPATH = $(gpio_indp_RELPATH)/gpio_indp
export gpio_indp_OBJPATH
gpio_indp_MAKEFILE = -f build/makefile_indp.mk
export gpio_indp_MAKEFILE
gpio_indp_BOARD_DEPENDENCY = no
gpio_indp_CORE_DEPENDENCY = no
gpio_indp_SOC_DEPENDENCY = no
export gpio_indp_COMP_LIST
export gpio_indp_BOARD_DEPENDENCY
export gpio_indp_CORE_DEPENDENCY
export gpio_indp_SOC_DEPENDENCY
gpio_indp_PKG_LIST = gpio_indp
export gpio_indp_PKG_LIST
gpio_indp_INCLUDE = $(gpio_indp_PATH)
gpio_indp_SOCLIST = $(drvgpio_SOCLIST)
export gpio_indp_SOCLIST
gpio_indp_$(SOC)_CORELIST = $(drvgpio_$(SOC)_CORELIST)
export gpio_indp_$(SOC)_CORELIST

# GPIO PROFILE LIB
gpio_profile_COMP_LIST = gpio_profile
gpio_profile_RELPATH = ti/drv/gpio
gpio_profile_PATH = $(PDK_GPIO_COMP_PATH)
gpio_profile_LIBNAME = ti.drv.gpio.profiling
export gpio_profile_LIBNAME
gpio_profile_LIBPATH = $(gpio_profile_PATH)/lib
export gpio_profile_LIBPATH
gpio_profile_OBJPATH = $(gpio_profile_RELPATH)/gpio_profile
export gpio_profile_OBJPATH
gpio_profile_MAKEFILE = -f build/makefile_profile.mk
export gpio_profile_MAKEFILE
gpio_profile_BOARD_DEPENDENCY = no
gpio_profile_CORE_DEPENDENCY = no
gpio_profile_SOC_DEPENDENCY = yes
export gpio_profile_COMP_LIST
export gpio_profile_BOARD_DEPENDENCY
export gpio_profile_CORE_DEPENDENCY
export gpio_profile_SOC_DEPENDENCY
gpio_profile_PKG_LIST = gpio_profile
export gpio_profile_PKG_LIST
gpio_profile_INCLUDE = $(gpio_profile_PATH)
gpio_profile_SOCLIST = $(drvgpio_SOCPROFILELIST)
export gpio_profile_SOCLIST
gpio_profile_$(SOC)_CORELIST = $(drvgpio_$(SOC)_CORELIST)
export gpio_profile_$(SOC)_CORELIST

# GPIO PROFILE INDEPENDENT LIB
gpio_profile_indp_COMP_LIST = gpio_profile_indp
gpio_profile_indp_RELPATH = ti/drv/gpio
gpio_profile_indp_PATH = $(PDK_GPIO_COMP_PATH)
gpio_profile_indp_LIBNAME = ti.drv.gpio.profiling
export gpio_profile_indp_LIBNAME
gpio_profile_indp_LIBPATH = $(gpio_profile_indp_PATH)/lib
export gpio_profile_indp_LIBPATH
gpio_profile_indp_OBJPATH = $(gpio_profile_indp_RELPATH)/gpio_profile_indp
export gpio_profile_indp_OBJPATH
gpio_profile_indp_MAKEFILE = -f build/makefile_profile_indp.mk
export gpio_profile_indp_MAKEFILE
gpio_profile_indp_BOARD_DEPENDENCY = no
gpio_profile_indp_CORE_DEPENDENCY = no
gpio_profile_indp_SOC_DEPENDENCY = no
export gpio_profile_indp_COMP_LIST
export gpio_profile_indp_BOARD_DEPENDENCY
export gpio_profile_indp_CORE_DEPENDENCY
export gpio_profile_indp_SOC_DEPENDENCY
gpio_profile_indp_PKG_LIST = gpio_profile_indp
export gpio_profile_indp_PKG_LIST
gpio_profile_indp_INCLUDE = $(gpio_profile_indp_PATH)
gpio_profile_indp_SOCLIST = $(drvgpio_SOCPROFILELIST)
export gpio_profile_indp_SOCLIST
gpio_profile_indp_$(SOC)_CORELIST = $(drvgpio_$(SOC)_CORELIST)
export gpio_profile_indp_$(SOC)_CORELIST

#
# GPIO Examples
#

# GPIO baremetal Example led blink
GPIO_Baremetal_LedBlink_TestApp_COMP_LIST = GPIO_Baremetal_LedBlink_TestApp
GPIO_Baremetal_LedBlink_TestApp_RELPATH = ti/drv/gpio/test/led_blink
GPIO_Baremetal_LedBlink_TestApp_PATH = $(PDK_GPIO_COMP_PATH)/test/led_blink
GPIO_Baremetal_LedBlink_TestApp_BOARD_DEPENDENCY = yes
GPIO_Baremetal_LedBlink_TestApp_CORE_DEPENDENCY = no
GPIO_Baremetal_LedBlink_TestApp_MAKEFILE = -f makefile IS_BAREMETAL=yes
export GPIO_Baremetal_LedBlink_TestApp_COMP_LIST
export GPIO_Baremetal_LedBlink_TestApp_BOARD_DEPENDENCY
export GPIO_Baremetal_LedBlink_TestApp_CORE_DEPENDENCY
export GPIO_Baremetal_LedBlink_TestApp_MAKEFILE
GPIO_Baremetal_LedBlink_TestApp_PKG_LIST = GPIO_Baremetal_LedBlink_TestApp
GPIO_Baremetal_LedBlink_TestApp_INCLUDE = $(GPIO_Baremetal_LedBlink_TestApp_PATH)
GPIO_Baremetal_LedBlink_TestApp_BOARDLIST = $(drvgpio_BOARDLIST)
export GPIO_Baremetal_LedBlink_TestApp_BOARDLIST
ifeq ($(SOC),$(filter $(SOC), j721e j7200))
GPIO_Baremetal_LedBlink_TestApp_$(SOC)_CORELIST = $(drvgpio_$(SOC)_CORELISTARM)
else
GPIO_Baremetal_LedBlink_TestApp_$(SOC)_CORELIST = $(drvgpio_$(SOC)_CORELIST)
endif
export GPIO_Baremetal_LedBlink_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
GPIO_Baremetal_LedBlink_TestApp_SBL_APPIMAGEGEN = yes
export GPIO_Baremetal_LedBlink_TestApp_SBL_APPIMAGEGEN
endif

# GPIO rtos Example led blink
GPIO_LedBlink_TestApp_COMP_LIST = GPIO_LedBlink_TestApp
GPIO_LedBlink_TestApp_RELPATH = ti/drv/gpio/test/led_blink
GPIO_LedBlink_TestApp_PATH = $(PDK_GPIO_COMP_PATH)/test/led_blink
GPIO_LedBlink_TestApp_BOARD_DEPENDENCY = yes
GPIO_LedBlink_TestApp_CORE_DEPENDENCY = no
GPIO_LedBlink_TestApp_MAKEFILE = -f makefile
GPIO_LedBlink_TestApp_XDC_CONFIGURO = yes
export GPIO_LedBlink_TestApp_COMP_LIST
export GPIO_LedBlink_TestApp_BOARD_DEPENDENCY
export GPIO_LedBlink_TestApp_CORE_DEPENDENCY
export GPIO_LedBlink_TestApp_XDC_CONFIGURO
GPIO_LedBlink_TestApp_PKG_LIST = GPIO_LedBlink_TestApp
GPIO_LedBlink_TestApp_INCLUDE = $(GPIO_LedBlink_TestApp_PATH)
GPIO_LedBlink_TestApp_BOARDLIST = $(drvgpio_BOARDLIST)
export GPIO_LedBlink_TestApp_BOARDLIST
GPIO_LedBlink_TestApp_$(SOC)_CORELIST = $(gpio_$(SOC)_CORELIST)
export GPIO_LedBlink_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
GPIO_LedBlink_TestApp_SBL_APPIMAGEGEN = yes
export GPIO_LedBlink_TestApp_SBL_APPIMAGEGEN
endif

export drvgpio_LIB_LIST
export drvgpio_EXAMPLE_LIST
export gpio_LIB_LIST
export gpio_EXAMPLE_LIST

gpio_component_make_include := 1
endif

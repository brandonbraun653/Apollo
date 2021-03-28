#
# Copyright (c) 2016 - 2018, Texas Instruments Incorporated
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

# File: i2c_component.mk
#       This file is component include make file of I2C library.
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
ifeq ($(i2c_component_make_include), )

drvi2c_BOARDLIST       = am65xx_evm am65xx_idk j721e_sim j721e_evm j7200_evm
drvi2c_BOARDLISTLIM    = am65xx_evm am65xx_idk
drvi2c_SOCLIST         = am574x am572x am571x tda2xx tda2px tda2ex tda3xx dra78x dra72x dra75x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138 am65xx j721e j7200
drvi2c_SOCLISTLIM      = am574x am572x am571x tda2xx tda2px tda2ex tda3xx dra78x dra72x dra75x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138 am65xx
drvi2c_tda2xx_CORELIST = ipu1_0
drvi2c_tda2px_CORELIST = ipu1_0
drvi2c_tda2ex_CORELIST = ipu1_0
drvi2c_tda3xx_CORELIST = ipu1_0
drvi2c_dra72x_CORELIST = c66x a15_0 ipu1_0
drvi2c_dra75x_CORELIST = c66x a15_0 ipu1_0
drvi2c_dra78x_CORELIST = c66x ipu1_0
drvi2c_am574x_CORELIST = c66x a15_0 ipu1_0 pru_0 pru_1
drvi2c_am572x_CORELIST = c66x a15_0 ipu1_0 pru_0 pru_1
drvi2c_am571x_CORELIST = c66x a15_0 ipu1_0 pru_0 pru_1
drvi2c_k2h_CORELIST    = c66x a15_0
drvi2c_k2k_CORELIST    = c66x a15_0
drvi2c_k2l_CORELIST    = c66x a15_0
drvi2c_k2e_CORELIST    = c66x a15_0
drvi2c_k2g_CORELIST    = c66x a15_0 pru_0 pru_1
drvi2c_omapl137_CORELIST    = c674x arm9_0
drvi2c_omapl138_CORELIST    = c674x arm9_0
drvi2c_c6678_CORELIST  = c66x
drvi2c_c6657_CORELIST  = c66x
drvi2c_am437x_CORELIST = a9host pru_0 pru_1
drvi2c_am335x_CORELIST = a8host pru_0 pru_1
drvi2c_am65xx_CORELIST   = mpu1_0 mcu1_0 mcu1_1
drvi2c_j721e_CORELIST   = $(DEFAULT_j721e_CORELIST)
drvi2c_j721e_CORELISTARM = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1 mcu3_0 mcu3_1
drvi2c_j7200_CORELIST    = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1
############################
# i2c package
# List of components included under i2c lib
# The components included here are built and will be part of i2c lib
############################
i2c_LIB_LIST = i2c i2c_indp i2c_profile i2c_profile_indp i2c_icss0
drvi2c_LIB_LIST = $(i2c_LIB_LIST)

############################
# i2c Firmwares
# All the firmware mentioned in list are built when build target is called
# List below all firmware for allowed values
############################
i2c_FIRM_LIST = icss_i2c icss_i2c_icss0
drvi2c_FIRM_LIST = $(i2c_FIRM_LIST)

############################
# i2c examples
# List of examples under i2c
# All the tests mentioned in list are built when test target is called
# List below all examples for allowed values
############################
i2c_EXAMPLE_LIST = drv_i2c_led_blink_test I2C_Baremetal_Eeprom_TestApp I2C_Eeprom_TestApp I2C_Eeprom_SMP_TestApp drv_i2c_utility
drvi2c_EXAMPLE_LIST = $(i2c_EXAMPLE_LIST)

#
# I2C Modules
#

# I2C LIB
i2c_COMP_LIST = i2c
i2c_RELPATH = ti/drv/i2c
i2c_PATH = $(PDK_I2C_COMP_PATH)
i2c_LIBNAME = ti.drv.i2c
export i2c_LIBNAME
i2c_LIBPATH = $(i2c_PATH)/lib
export i2c_LIBPATH
i2c_OBJPATH = $(i2c_RELPATH)/i2c
export i2c_OBJPATH
i2c_MAKEFILE = -f build/makefile.mk
export i2c_MAKEFILE
i2c_BOARD_DEPENDENCY = no
i2c_CORE_DEPENDENCY = no
i2c_SOC_DEPENDENCY = yes
export i2c_COMP_LIST
export i2c_BOARD_DEPENDENCY
export i2c_CORE_DEPENDENCY
export i2c_SOC_DEPENDENCY
i2c_PKG_LIST = i2c
export i2c_PKG_LIST
i2c_INCLUDE = $(i2c_PATH)
i2c_SOCLIST = $(drvi2c_SOCLIST)
export i2c_SOCLIST
i2c_$(SOC)_CORELIST = $(drvi2c_$(SOC)_CORELIST)
ifeq ($(SOC),$(filter $(SOC), j721e))
i2c_$(SOC)_CORELIST += mcu2_1 mcu3_0 muc1_1
endif
export i2c_$(SOC)_CORELIST

# I2C LIB, AM437x ICSS0
i2c_icss0_COMP_LIST = i2c_icss0
i2c_icss0_RELPATH = ti/drv/i2c
i2c_icss0_PATH = $(PDK_I2C_COMP_PATH)
i2c_icss0_LIBNAME = ti.drv.i2c_icss0
export i2c_icss0_LIBNAME
i2c_icss0_LIBPATH = $(i2c_icss0_PATH)/lib
export i2c_icss0_LIBPATH
i2c_icss0_OBJPATH = $(i2c_icss0_RELPATH)/i2c_icss0
export i2c_icss0_OBJPATH
i2c_icss0_MAKEFILE = -f build/makefile.mk ICSS0_FW=yes
export i2c_icss0_MAKEFILE
i2c_icss0_BOARD_DEPENDENCY = no
i2c_icss0_CORE_DEPENDENCY = no
i2c_icss0_SOC_DEPENDENCY = yes
export i2c_icss0_COMP_LIST
export i2c_icss0_BOARD_DEPENDENCY
export i2c_icss0_CORE_DEPENDENCY
export i2c_icss0_SOC_DEPENDENCY
i2c_icss0_PKG_LIST = i2c
export i2c_icss0_PKG_LIST
i2c_icss0_INCLUDE = $(i2c_icss0_PATH)
i2c_icss0_SOCLIST = am437x
export i2c_icss0_SOCLIST
i2c_icss0_$(SOC)_CORELIST = $(drvi2c_$(SOC)_CORELIST)
export i2c_icss0_$(SOC)_CORELIST

# I2C INDEPENDENT LIB
i2c_indp_COMP_LIST = i2c_indp
i2c_indp_RELPATH = ti/drv/i2c
i2c_indp_PATH = $(PDK_I2C_COMP_PATH)
i2c_indp_LIBNAME = ti.drv.i2c
export i2c_indp_LIBNAME
i2c_indp_LIBPATH = $(i2c_indp_PATH)/lib
export i2c_indp_LIBPATH
i2c_indp_OBJPATH = $(i2c_indp_RELPATH)/i2c_indp
export i2c_indp_OBJPATH
i2c_indp_MAKEFILE = -f build/makefile_indp.mk
export i2c_indp_MAKEFILE
i2c_indp_BOARD_DEPENDENCY = no
i2c_indp_CORE_DEPENDENCY = no
i2c_indp_SOC_DEPENDENCY = no
export i2c_indp_COMP_LIST
export i2c_indp_BOARD_DEPENDENCY
export i2c_indp_CORE_DEPENDENCY
export i2c_indp_SOC_DEPENDENCY
i2c_indp_PKG_LIST = i2c_indp
export i2c_indp_PKG_LIST
i2c_indp_INCLUDE = $(i2c_indp_PATH)
i2c_indp_SOCLIST = $(drvi2c_SOCLISTLIM)
export i2c_indp_SOCLIST
i2c_indp_$(SOC)_CORELIST = $(drvi2c_$(SOC)_CORELIST)
export i2c_indp_$(SOC)_CORELIST

# I2C PROFILE LIB
i2c_profile_COMP_LIST = i2c_profile
i2c_profile_RELPATH = ti/drv/i2c
i2c_profile_PATH = $(PDK_I2C_COMP_PATH)
i2c_profile_LIBNAME = ti.drv.i2c.profiling
export i2c_profile_LIBNAME
i2c_profile_LIBPATH = $(i2c_profile_PATH)/lib
export i2c_profile_LIBPATH
i2c_profile_OBJPATH = $(i2c_profile_RELPATH)/i2c_profile
export i2c_profile_OBJPATH
i2c_profile_MAKEFILE = -f build/makefile_profile.mk
export i2c_profile_MAKEFILE
i2c_profile_BOARD_DEPENDENCY = no
i2c_profile_CORE_DEPENDENCY = no
i2c_profile_SOC_DEPENDENCY = yes
export i2c_profile_COMP_LIST
export i2c_profile_BOARD_DEPENDENCY
export i2c_profile_CORE_DEPENDENCY
export i2c_profile_SOC_DEPENDENCY
i2c_profile_PKG_LIST = i2c_profile
export i2c_profile_PKG_LIST
i2c_profile_INCLUDE = $(i2c_profile_PATH)
i2c_profile_SOCLIST = $(drvi2c_SOCLISTLIM)
export i2c_profile_SOCLIST
i2c_profile_$(SOC)_CORELIST = $(drvi2c_$(SOC)_CORELIST)
export i2c_profile_$(SOC)_CORELIST

# I2C PROFILE INDEPENDENT LIB
i2c_profile_indp_COMP_LIST = i2c_profile_indp
i2c_profile_indp_RELPATH = ti/drv/i2c
i2c_profile_indp_PATH = $(PDK_I2C_COMP_PATH)
i2c_profile_indp_LIBNAME = ti.drv.i2c.profiling
export i2c_profile_indp_LIBNAME
i2c_profile_indp_LIBPATH = $(i2c_profile_indp_PATH)/lib
export i2c_profile_indp_LIBPATH
i2c_profile_indp_OBJPATH = $(i2c_profile_indp_RELPATH)/i2c_profile_indp
export i2c_profile_indp_OBJPATH
i2c_profile_indp_MAKEFILE = -f build/makefile_profile_indp.mk
export i2c_profile_indp_MAKEFILE
i2c_profile_indp_BOARD_DEPENDENCY = no
i2c_profile_indp_CORE_DEPENDENCY = no
i2c_profile_indp_SOC_DEPENDENCY = no
export i2c_profile_indp_COMP_LIST
export i2c_profile_indp_BOARD_DEPENDENCY
export i2c_profile_indp_CORE_DEPENDENCY
export i2c_profile_indp_SOC_DEPENDENCY
i2c_profile_indp_PKG_LIST = i2c_profile_indp
export i2c_profile_indp_PKG_LIST
i2c_profile_indp_INCLUDE = $(i2c_profile_indp_PATH)
i2c_profile_indp_SOCLIST = $(drvi2c_SOCLISTLIM)
export i2c_profile_indp_SOCLIST
i2c_profile_indp_$(SOC)_CORELIST = $(drvi2c_$(SOC)_CORELIST)
export i2c_profile_indp_$(SOC)_CORELIST

#
# I2C Firmwares
#
icss_i2c_COMP_LIST = icss_i2c
# temporary fix for nightly build
# icss_i2c_RELPATH = ti/drv/i2c/firmware/icss_i2c
icss_i2c_RELPATH = icss_i2c
icss_i2c_PATH = $(PDK_I2C_COMP_PATH)/firmware/icss_i2c
icss_i2c_HEADERNAME = icss_i2c
export icss_i2c_HEADERNAME
icss_i2c_HEADERPATH = $(icss_i2c_PATH)/bin
export icss_i2c_HEADERPATH
icss_i2c_OBJPATH = $(icss_i2c_RELPATH)
export icss_i2c_OBJPATH
icss_i2c_MAKEFILE = -f ../../build/makefile_icss_i2c.mk
export icss_i2c_MAKEFILE
icss_i2c_BOARD_DEPENDENCY = no
icss_i2c_CORE_DEPENDENCY = yes
icss_i2c_SOC_DEPENDENCY = yes
export icss_i2c_COMP_LIST
export icss_i2c_BOARD_DEPENDENCY
export icss_i2c_CORE_DEPENDENCY
export icss_i2c_SOC_DEPENDENCY
icss_i2c_PKG_LIST = icss_i2c
export icss_i2c_PKG_LIST
icss_i2c_INCLUDE = $(icss_i2c_PATH)
icss_i2c_SOCLIST = am437x am574x am572x am571x am335x k2g
export icss_i2c_SOCLIST
icss_i2c_$(SOC)_CORELIST = $(drvi2c_$(SOC)_CORELIST)
export icss_i2c_$(SOC)_CORELIST

#
# I2C Firmwares, AM437x ICSS0
#
icss_i2c_icss0_COMP_LIST = icss_i2c_icss0
icss_i2c_icss0_RELPATH = icss_i2c_icss0
icss_i2c_icss0_PATH = $(PDK_I2C_COMP_PATH)/firmware/icss_i2c
icss_i2c_icss0_HEADERNAME = icss_i2c_icss0
export icss_i2c_icss0_HEADERNAME
icss_i2c_icss0_HEADERPATH = $(icss_i2c_icss0_PATH)/bin
export icss_i2c_icss0_HEADERPATH
icss_i2c_icss0_OBJPATH = $(icss_i2c_icss0_RELPATH)
export icss_i2c_icss0_OBJPATH
icss_i2c_icss0_MAKEFILE = -f ../../build/makefile_icss_i2c.mk ICSS0_FW=yes
export icss_i2c_icss0_MAKEFILE
icss_i2c_icss0_BOARD_DEPENDENCY = no
icss_i2c_icss0_CORE_DEPENDENCY = yes
icss_i2c_icss0_SOC_DEPENDENCY = yes
export icss_i2c_icss0_COMP_LIST
export icss_i2c_icss0_BOARD_DEPENDENCY
export icss_i2c_icss0_CORE_DEPENDENCY
export icss_i2c_icss0_SOC_DEPENDENCY
icss_i2c_icss0_PKG_LIST = icss_i2c
export icss_i2c_icss0_PKG_LIST
icss_i2c_icss0_INCLUDE = $(icss_i2c_icss0_PATH)
icss_i2c_icss0_SOCLIST = am437x
export icss_i2c_icss0_SOCLIST
icss_i2c_icss0_$(SOC)_CORELIST = $(drvi2c_$(SOC)_CORELIST)
export icss_i2c_icss0_$(SOC)_CORELIST

#
# I2C Examples
#

# I2C Example led blink
drv_i2c_led_blink_test_COMP_LIST = drv_i2c_led_blink_test
drv_i2c_led_blink_test_RELPATH = ti/drv/i2c/example/tdaxx/led_blink
drv_i2c_led_blink_test_PATH = $(PDK_I2C_COMP_PATH)/example/tdaxx/led_blink
drv_i2c_led_blink_test_BOARD_DEPENDENCY = yes
drv_i2c_led_blink_test_CORE_DEPENDENCY = no
drv_i2c_led_blink_test_XDC_CONFIGURO = yes
export drv_i2c_led_blink_test_COMP_LIST
export drv_i2c_led_blink_test_BOARD_DEPENDENCY
export drv_i2c_led_blink_test_CORE_DEPENDENCY
export drv_i2c_led_blink_test_XDC_CONFIGURO
drv_i2c_led_blink_test_PKG_LIST = drv_i2c_led_blink_test
drv_i2c_led_blink_test_INCLUDE = $(drv_i2c_led_blink_test_PATH)
drv_i2c_led_blink_test_BOARDLIST = tda2xx-evm tda2px-evm tda2ex-evm tda3xx-evm evmDRA78x
export drv_i2c_led_blink_test_BOARDLIST
drv_i2c_led_blink_test_$(SOC)_CORELIST = $(i2c_$(SOC)_CORELIST)
export drv_i2c_led_blink_test_$(SOC)_CORELIST

# I2C baremetal EEPROM test
I2C_Baremetal_Eeprom_TestApp_COMP_LIST = I2C_Baremetal_Eeprom_TestApp
I2C_Baremetal_Eeprom_TestApp_RELPATH = ti/drv/i2c/test/eeprom_read
I2C_Baremetal_Eeprom_TestApp_PATH = $(PDK_I2C_COMP_PATH)/test/eeprom_read
I2C_Baremetal_Eeprom_TestApp_BOARD_DEPENDENCY = yes
I2C_Baremetal_Eeprom_TestApp_CORE_DEPENDENCY = no
I2C_Baremetal_Eeprom_TestApp_MAKEFILE = -f makefile IS_BAREMETAL=yes
export I2C_Baremetal_Eeprom_TestApp_COMP_LIST
export I2C_Baremetal_Eeprom_TestApp_BOARD_DEPENDENCY
export I2C_Baremetal_Eeprom_TestApp_CORE_DEPENDENCY
export I2C_Baremetal_Eeprom_TestApp_MAKEFILE
I2C_Baremetal_Eeprom_TestApp_PKG_LIST = I2C_Baremetal_Eeprom_TestApp
I2C_Baremetal_Eeprom_TestApp_INCLUDE = $(I2C_Baremetal_Eeprom_TestApp_PATH)
I2C_Baremetal_Eeprom_TestApp_BOARDLIST = am65xx_evm am65xx_idk j721e_evm j7200_evm
export I2C_Baremetal_Eeprom_TestApp_BOARDLIST
ifeq ($(SOC),$(filter $(SOC), j721e))
I2C_Baremetal_Eeprom_TestApp_$(SOC)_CORELIST = $(drvi2c_j721e_CORELISTARM)
else
I2C_Baremetal_Eeprom_TestApp_$(SOC)_CORELIST = $(drvi2c_$(SOC)_CORELIST)
endif

export I2C_Baremetal_Eeprom_TestApp_$(SOC)_CORELIST

# I2C rtos EEPROM test
I2C_Eeprom_TestApp_COMP_LIST = I2C_Eeprom_TestApp
I2C_Eeprom_TestApp_RELPATH = ti/drv/i2c/test/eeprom_read
I2C_Eeprom_TestApp_PATH = $(PDK_I2C_COMP_PATH)/test/eeprom_read
I2C_Eeprom_TestApp_BOARD_DEPENDENCY = yes
I2C_Eeprom_TestApp_CORE_DEPENDENCY = no
I2C_Eeprom_TestApp_MAKEFILE = -f makefile
I2C_Eeprom_TestApp_XDC_CONFIGURO = yes
export I2C_Eeprom_TestApp_COMP_LIST
export I2C_Eeprom_TestApp_BOARD_DEPENDENCY
export I2C_Eeprom_TestApp_CORE_DEPENDENCY
export I2C_Eeprom_TestApp_XDC_CONFIGURO
export I2C_Eeprom_TestApp_MAKEFILE
I2C_Eeprom_TestApp_PKG_LIST = I2C_Eeprom_TestApp
I2C_Eeprom_TestApp_INCLUDE = $(I2C_Eeprom_TestApp_PATH)
I2C_Eeprom_TestApp_BOARDLIST = $(drvi2c_BOARDLIST)
export I2C_Eeprom_TestApp_BOARDLIST
I2C_Eeprom_TestApp_$(SOC)_CORELIST = $(i2c_$(SOC)_CORELIST)
export I2C_Eeprom_TestApp_$(SOC)_CORELIST

# I2C rtos EEPROM test with SMP enabled
I2C_Eeprom_SMP_TestApp_COMP_LIST = I2C_Eeprom_SMP_TestApp
I2C_Eeprom_SMP_TestApp_RELPATH = ti/drv/i2c/test/eeprom_read
I2C_Eeprom_SMP_TestApp_PATH = $(PDK_I2C_COMP_PATH)/test/eeprom_read
I2C_Eeprom_SMP_TestApp_BOARD_DEPENDENCY = yes
I2C_Eeprom_SMP_TestApp_CORE_DEPENDENCY = no
I2C_Eeprom_SMP_TestApp_MAKEFILE = -f makefile SMP=enable
I2C_Eeprom_SMP_TestApp_XDC_CONFIGURO = yes
export I2C_Eeprom_SMP_TestApp_COMP_LIST
export I2C_Eeprom_SMP_TestApp_BOARD_DEPENDENCY
export I2C_Eeprom_SMP_TestApp_CORE_DEPENDENCY
export I2C_Eeprom_SMP_TestApp_XDC_CONFIGURO
export I2C_Eeprom_SMP_TestApp_MAKEFILE
I2C_Eeprom_SMP_TestApp_PKG_LIST = I2C_Eeprom_SMP_TestApp
I2C_Eeprom_SMP_TestApp_INCLUDE = $(I2C_Eeprom_SMP_TestApp_PATH)
I2C_Eeprom_SMP_TestApp_BOARDLIST = $(drvi2c_BOARDLISTLIM)
export I2C_Eeprom_SMP_TestApp_BOARDLIST
I2C_Eeprom_SMP_TestApp_$(SOC)_CORELIST = mpu1_0
export I2C_Eeprom_SMP_TestApp_$(SOC)_CORELIST

# I2C Utility
drv_i2c_utility_COMP_LIST = drv_i2c_utility
drv_i2c_utility_RELPATH = ti/drv/i2c/example/i2c_utility
drv_i2c_utility_PATH = $(PDK_I2C_COMP_PATH)/example/i2c_utility
drv_i2c_utility_BOARD_DEPENDENCY = yes
drv_i2c_utility_CORE_DEPENDENCY = no
drv_i2c_utility_MAKEFILE = -f makefile
drv_i2c_utility_XDC_CONFIGURO = yes
export drv_i2c_utility_COMP_LIST
export drv_i2c_utility_BOARD_DEPENDENCY
export drv_i2c_utility_CORE_DEPENDENCY
export drv_i2c_utility_XDC_CONFIGURO
export drv_i2c_utility_MAKEFILE
drv_i2c_utility_PKG_LIST = drv_i2c_utility
drv_i2c_utility_INCLUDE = $(drv_i2c_utility_PATH)
drv_i2c_utility_BOARDLIST = j721e_evm j7200_evm
export drv_i2c_utility_BOARDLIST
ifeq ($(SOC),$(filter $(SOC), am65xx))
drv_i2c_utility_$(SOC)_CORELIST = mcu1_0 mpu1_0
endif
ifeq ($(SOC),$(filter $(SOC), j721e am77x))
drv_i2c_utility_$(SOC)_CORELIST = $(drvi2c_j721e_CORELISTARM)
endif
ifeq ($(SOC),$(filter $(SOC), j7200))
drv_i2c_utility_$(SOC)_CORELIST = $(drvi2c_j7200_CORELIST)
endif
export drv_i2c_utility_$(SOC)_CORELIST

export drvi2c_LIB_LIST
export drvi2c_EXAMPLE_LIST
export drvi2c_FIRM_LIST
export i2c_FIRM_LIST
export i2c_LIB_LIST
export i2c_EXAMPLE_LIST

i2c_component_make_include := 1
endif

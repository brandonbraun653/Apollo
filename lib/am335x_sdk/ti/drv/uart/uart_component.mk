#
# Copyright (c) 2017 - 2019, Texas Instruments Incorporated
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

# File: uart_component.mk
#       This file is component include make file of UART library.
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
ifeq ($(uart_component_make_include), )

# under other list
drvuart_BOARDLIST       = am65xx_evm am65xx_idk j721e_sim j721e_evm j7200_evm
drvuart_dma_SOCLIST     = tda2xx tda2px dra72x dra75x tda2ex tda3xx dra78x am574x am572x am571x k2h k2k k2l k2e k2g c6678 c6657 omapl137 omapl138 am437x am65xx j721e j7200
drvuart_SOCLIST         = tda2xx tda2px dra72x dra75x tda2ex tda3xx dra78x am574x am572x am571x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138 am65xx j721e j7200
drvuart_tda2xx_CORELIST = ipu1_0
drvuart_tda2px_CORELIST = ipu1_0
drvuart_tda2ex_CORELIST = ipu1_0
drvuart_tda3xx_CORELIST = ipu1_0
drvuart_dra78x_CORELIST = c66x ipu1_0
drvuart_am574x_CORELIST = c66x a15_0 ipu1_0
drvuart_am572x_CORELIST = c66x a15_0 ipu1_0
drvuart_am571x_CORELIST = c66x a15_0 ipu1_0
drvuart_dra72x_CORELIST = c66x a15_0 ipu1_0
drvuart_dra75x_CORELIST = c66x a15_0 ipu1_0
drvuart_k2h_CORELIST    = c66x a15_0
drvuart_k2k_CORELIST    = c66x a15_0
drvuart_k2l_CORELIST    = c66x a15_0
drvuart_k2e_CORELIST    = c66x a15_0
drvuart_k2g_CORELIST    = c66x a15_0
drvuart_omapl137_CORELIST    = c674x arm9_0
drvuart_omapl138_CORELIST    = c674x arm9_0
drvuart_c6678_CORELIST  = c66x
drvuart_c6657_CORELIST  = c66x
drvuart_am437x_CORELIST = a9host
drvuart_am335x_CORELIST = a8host pru_0 pru_1
drvuart_am65xx_CORELIST = mpu1_0 mcu1_0 mcu1_1
drvuart_j721e_CORELIST = $(DEFAULT_j721e_CORELIST)
drvuart_j721e_CORELISTARM = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1 mcu3_0 mcu3_1
drvuart_j7200_CORELIST = $(DEFAULT_j7200_CORELIST)
drvuart_j7200_CORELISTARM = mpu1_0 mcu1_0 mcu1_1 mcu2_0 mcu2_1

############################
# uart package
# List of components included under uart lib
# The components included here are built and will be part of uart lib
############################
uart_LIB_LIST = uart uart_dma uart_profile uart_dma_profile uart_indp uart_profile_indp uart_console
drvuart_LIB_LIST = $(uart_LIB_LIST)

############################
# uart Firmwares
# All the firmware mentioned in list are built when build target is called
# List below all firmware for allowed values
############################
uart_FIRM_LIST = icss_uart
drvuart_FIRM_LIST = $(uart_FIRM_LIST)

############################
# uart examples
# List of examples under uart
# All the tests mentioned in list are built when test target is called
# List below all examples for allowed values
############################
#uart_EXAMPLE_LIST = drv_uart_unit_test drv_uart_polling_mode_app drv_uart_intr_mode_app
uart_EXAMPLE_LIST = UART_Baremetal_TestApp UART_Baremetal_DMA_TestApp UART_TestApp UART_SMP_TestApp UART_DMA_TestApp UART_DMA_SMP_TestApp
drvuart_EXAMPLE_LIST = $(uart_EXAMPLE_LIST)

#
# UART Modules
#

# UART LIB
uart_COMP_LIST = uart
uart_RELPATH = ti/drv/uart
uart_PATH = $(PDK_UART_COMP_PATH)
uart_LIBNAME = ti.drv.uart
export uart_LIBNAME
uart_LIBPATH = $(uart_PATH)/lib
export uart_LIBPATH
uart_OBJPATH = $(uart_RELPATH)/uart
export uart_OBJPATH
uart_MAKEFILE = -f build/makefile.mk
export uart_MAKEFILE
uart_BOARD_DEPENDENCY = no
uart_CORE_DEPENDENCY = no
uart_SOC_DEPENDENCY = yes
export uart_COMP_LIST
export uart_BOARD_DEPENDENCY
export uart_CORE_DEPENDENCY
export uart_SOC_DEPENDENCY
uart_PKG_LIST = uart
uart_INCLUDE = $(uart_PATH)
uart_SOCLIST = tda2xx tda2px tda2ex tda3xx dra78x am574x am572x am571x dra72x dra75x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138 am65xx j721e j7200
export uart_SOCLIST
uart_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
ifeq ($(SOC),$(filter $(SOC), j721e))
uart_$(SOC)_CORELIST += c7x_1
endif
export uart_$(SOC)_CORELIST

# UART LIB DEVICE INDEPENDENT
uart_indp_COMP_LIST = uart_indp
uart_indp_RELPATH = ti/drv/uart
uart_indp_PATH = $(PDK_UART_COMP_PATH)
uart_indp_LIBNAME = ti.drv.uart
export uart_indp_LIBNAME
uart_indp_LIBPATH = $(uart_indp_PATH)/lib
export uart_indp_LIBPATH
uart_indp_OBJPATH = $(uart_indp_RELPATH)/uart_indp
export uart_indp_OBJPATH
uart_indp_MAKEFILE = -f build/makefile_indp.mk
export uart_indp_MAKEFILE
uart_indp_BOARD_DEPENDENCY = no
uart_indp_CORE_DEPENDENCY = no
uart_indp_SOC_DEPENDENCY = no
export uart_indp_COMP_LIST
export uart_indp_BOARD_DEPENDENCY
export uart_indp_CORE_DEPENDENCY
export uart_indp_SOC_DEPENDENCY
uart_indp_PKG_LIST = uart_indp
uart_indp_INCLUDE = $(uart_indp_PATH)
uart_indp_SOCLIST = tda2xx tda2px tda2ex tda3xx dra78x am574x am572x am571x dra72x dra75x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138 am65xx
export uart_indp_SOCLIST
uart_indp_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
export uart_indp_$(SOC)_CORELIST

# UART DMA SOC LIB
uart_dma_COMP_LIST = uart_dma
uart_dma_RELPATH = ti/drv/uart
uart_dma_PATH = $(PDK_UART_COMP_PATH)
uart_dma_LIBNAME = ti.drv.uart.dma
export uart_dma_LIBNAME
uart_dma_LIBPATH = $(uart_dma_PATH)/lib
export uart_dma_LIBPATH
uart_dma_OBJPATH = $(uart_dma_RELPATH)/uart_dma
export uart_dma_OBJPATH
uart_dma_MAKEFILE = -f build/makefile_dma.mk
export uart_dma_MAKEFILE
uart_dma_BOARD_DEPENDENCY = no
uart_dma_CORE_DEPENDENCY = no
uart_dma_SOC_DEPENDENCY = yes
export uart_dma_COMP_LIST
export uart_dma_BOARD_DEPENDENCY
export uart_dma_CORE_DEPENDENCY
export uart_dma_SOC_DEPENDENCY
uart_dma_PKG_LIST = uart_dma
uart_dma_INCLUDE = $(uart_dma_PATH)
uart_dma_SOCLIST = am574x am572x am571x dra72x dra75x dra78x k2h k2k k2l k2e k2g c6678 c6657 omapl137 omapl138 am437x am65xx j721e j7200 am335x
export uart_dma_SOCLIST
uart_dma_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
export uart_dma_$(SOC)_CORELIST

# UART PROFILING SOC LIB
uart_profile_COMP_LIST = uart_profile
uart_profile_RELPATH = ti/drv/uart
uart_profile_PATH = $(PDK_UART_COMP_PATH)
uart_profile_LIBNAME = ti.drv.uart.profiling
export uart_profile_LIBNAME
uart_profile_LIBPATH = $(uart_profile_PATH)/lib
export uart_profile_LIBPATH
uart_profile_OBJPATH = $(uart_profile_RELPATH)/uart_profile
export uart_profile_OBJPATH
uart_profile_MAKEFILE = -f build/makefile_profile.mk
export uart_profile_MAKEFILE
uart_profile_BOARD_DEPENDENCY = no
uart_profile_CORE_DEPENDENCY = no
uart_profile_SOC_DEPENDENCY = yes
export uart_profile_COMP_LIST
export uart_profile_BOARD_DEPENDENCY
export uart_profile_CORE_DEPENDENCY
export uart_profile_SOC_DEPENDENCY
uart_profile_PKG_LIST = uart_profile
uart_profile_INCLUDE = $(uart_profile_PATH)
uart_profile_SOCLIST = am574x am572x am571x dra72x dra75x dra78x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138 am65xx
export uart_profile_SOCLIST
uart_profile_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
export uart_profile_$(SOC)_CORELIST

# UART PROFILING SOC INDEPENDENT LIB
uart_profile_indp_COMP_LIST = uart_profile_indp
uart_profile_indp_RELPATH = ti/drv/uart
uart_profile_indp_PATH = $(PDK_UART_COMP_PATH)
uart_profile_indp_LIBNAME = ti.drv.uart.profiling
export uart_profile_indp_LIBNAME
uart_profile_indp_LIBPATH = $(uart_profile_indp_PATH)/lib
export uart_profile_indp_LIBPATH
uart_profile_indp_OBJPATH = $(uart_profile_indp_RELPATH)/uart_profile_indp
export uart_profile_indp_OBJPATH
uart_profile_indp_MAKEFILE = -f build/makefile_profile_indp.mk
export uart_profile_indp_MAKEFILE
uart_profile_indp_BOARD_DEPENDENCY = no
uart_profile_indp_CORE_DEPENDENCY = no
uart_profile_indp_SOC_DEPENDENCY = no
export uart_profile_indp_COMP_LIST
export uart_profile_indp_BOARD_DEPENDENCY
export uart_profile_indp_CORE_DEPENDENCY
export uart_profile_indp_SOC_DEPENDENCY
uart_profile_indp_PKG_LIST = uart_profile_indp
uart_profile_indp_INCLUDE = $(uart_profile_indp_PATH)
uart_profile_indp_SOCLIST = am574x am572x am571x dra72x dra75x dra78x k2h k2k k2l k2e k2g c6678 c6657 am437x am335x omapl137 omapl138 am65xx
export uart_profile_indp_SOCLIST
uart_profile_indp_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
export uart_profile_indp_$(SOC)_CORELIST

# UART DMA PROFILING SOC LIB
uart_dma_profile_COMP_LIST = uart_dma_profile
uart_dma_profile_RELPATH = ti/drv/uart
uart_dma_profile_PATH = $(PDK_UART_COMP_PATH)
uart_dma_profile_LIBNAME = ti.drv.uart.profiling.dma
export uart_dma_profile_LIBNAME
uart_dma_profile_LIBPATH = $(uart_dma_profile_PATH)/lib
export uart_dma_profile_LIBPATH
uart_dma_profile_OBJPATH = $(uart_dma_profile_RELPATH)/uart_dma_profile
export uart_dma_profile_OBJPATH
uart_dma_profile_MAKEFILE = -f build/makefile_dma_profile.mk
export uart_dma_profile_MAKEFILE
uart_dma_profile_BOARD_DEPENDENCY = no
uart_dma_profile_CORE_DEPENDENCY = no
uart_dma_profile_SOC_DEPENDENCY = yes
export uart_dma_profile_COMP_LIST
export uart_dma_profile_BOARD_DEPENDENCY
export uart_dma_profile_CORE_DEPENDENCY
export uart_dma_profile_SOC_DEPENDENCY
uart_dma_profile_PKG_LIST = uart_dma_profile
uart_dma_profile_INCLUDE = $(uart_dma_profile_PATH)
uart_dma_profile_SOCLIST = am574x am572x am571x dra72x dra75x dra78x k2h k2k k2l k2e k2g c6678 c6657 am437x am65xx am335x
export uart_dma_profile_SOCLIST
uart_dma_profile_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
export uart_dma_profile_$(SOC)_CORELIST

# UART console LIB
uart_console_COMP_LIST = uart_console
uart_console_RELPATH = ti/drv/uart
uart_console_PATH = $(PDK_UART_COMP_PATH)
uart_console_LIBNAME = ti.drv.uart_console
export uart_console_LIBNAME
uart_console_LIBPATH = $(uart_console_PATH)/lib
export uart_console_LIBPATH
uart_console_OBJPATH = $(uart_console_RELPATH)/uart_console
export uart_console_OBJPATH
uart_console_MAKEFILE = -f build/makefile_console.mk
export uart_console_MAKEFILE
uart_console_BOARD_DEPENDENCY = no
uart_console_CORE_DEPENDENCY = no
uart_console_SOC_DEPENDENCY = yes
export uart_console_COMP_LIST
export uart_console_BOARD_DEPENDENCY
export uart_console_CORE_DEPENDENCY
export uart_console_SOC_DEPENDENCY
uart_console_PKG_LIST = uart_console
uart_console_INCLUDE = $(uart_console_PATH)
uart_console_SOCLIST = tda2xx tda2px tda2ex tda3xx am65xx j721e j7200
export uart_console_SOCLIST
uart_console_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
export uart_console_$(SOC)_CORELIST

#
# UART Firmwares
#
icss_uart_COMP_LIST = icss_uart
# temporary fix for nightly build
# icss_uart_RELPATH = ti/drv/uart/firmware/icss_uart
icss_uart_RELPATH = icss_uart
icss_uart_PATH = $(PDK_UART_COMP_PATH)/firmware/icss_uart
icss_uart_HEADERNAME = icss_uart
export icss_uart_HEADERNAME
icss_uart_HEADERPATH = $(icss_uart_PATH)/bin
export icss_uart_HEADERPATH
icss_uart_OBJPATH = $(icss_uart_RELPATH)
export icss_uart_OBJPATH
icss_uart_MAKEFILE = -f ../../build/makefile_icss_uart.mk
export icss_uart_MAKEFILE
icss_uart_BOARD_DEPENDENCY = no
icss_uart_CORE_DEPENDENCY = yes
icss_uart_SOC_DEPENDENCY = yes
export icss_uart_COMP_LIST
export icss_uart_BOARD_DEPENDENCY
export icss_uart_CORE_DEPENDENCY
export icss_uart_SOC_DEPENDENCY
icss_uart_PKG_LIST = icss_uart
export icss_uart_PKG_LIST
icss_uart_INCLUDE = $(icss_uart_PATH)
#icss_uart_SOCLIST = am437x am574x am572x am571x am335x k2g
icss_uart_SOCLIST = am335x
export icss_uart_SOCLIST
icss_uart_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
export icss_uart_$(SOC)_CORELIST

#
# UART Examples
#

# UART unit test baremetal app
UART_Baremetal_TestApp_COMP_LIST = UART_Baremetal_TestApp
UART_Baremetal_TestApp_RELPATH = ti/drv/uart/test
UART_Baremetal_TestApp_PATH = $(PDK_UART_COMP_PATH)/test
UART_Baremetal_TestApp_BOARD_DEPENDENCY = yes
UART_Baremetal_TestApp_CORE_DEPENDENCY = no
UART_Baremetal_TestApp_MAKEFILE = -f makefile IS_BAREMETAL=yes
export UART_Baremetal_TestApp_COMP_LIST
export UART_Baremetal_TestApp_BOARD_DEPENDENCY
export UART_Baremetal_TestApp_CORE_DEPENDENCY
export UART_Baremetal_TestApp_MAKEFILE
UART_Baremetal_TestApp_PKG_LIST = UART_Baremetal_TestApp
UART_Baremetal_TestApp_INCLUDE = $(UART_Baremetal_TestApp_PATH)
UART_Baremetal_TestApp_BOARDLIST = $(drvuart_BOARDLIST)
export UART_Baremetal_TestApp_BOARDLIST
ifeq ($(SOC),$(filter $(SOC), j721e j7200))
UART_Baremetal_TestApp_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELISTARM)
else
UART_Baremetal_TestApp_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
endif

export UART_Baremetal_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
UART_Baremetal_TestApp_SBL_APPIMAGEGEN = yes
export UART_Baremetal_TestApp_SBL_APPIMAGEGEN
endif

# UART unit test baremetal dma app
UART_Baremetal_DMA_TestApp_COMP_LIST = UART_Baremetal_DMA_TestApp
UART_Baremetal_DMA_TestApp_RELPATH = ti/drv/uart/test
UART_Baremetal_DMA_TestApp_PATH = $(PDK_UART_COMP_PATH)/test
UART_Baremetal_DMA_TestApp_BOARD_DEPENDENCY = yes
UART_Baremetal_DMA_TestApp_CORE_DEPENDENCY = no
UART_Baremetal_DMA_TestApp_MAKEFILE = -f makefile IS_BAREMETAL=yes DMA=enable
export UART_Baremetal_DMA_TestApp_COMP_LIST
export UART_Baremetal_DMA_TestApp_BOARD_DEPENDENCY
export UART_Baremetal_DMA_TestApp_CORE_DEPENDENCY
export UART_Baremetal_DMA_TestApp_MAKEFILE
UART_Baremetal_DMA_TestApp_PKG_LIST = UART_Baremetal_DMA_TestApp
UART_Baremetal_DMA_TestApp_INCLUDE = $(UART_Baremetal_DMA_TestApp_PATH)
UART_Baremetal_DMA_TestApp_BOARDLIST = $(drvuart_BOARDLIST)
export UART_Baremetal_DMA_TestApp_BOARDLIST
ifeq ($(SOC),$(filter $(SOC), j721e j7200))
UART_Baremetal_DMA_TestApp_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELISTARM)
else
UART_Baremetal_DMA_TestApp_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
endif
export UART_Baremetal_DMA_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
UART_Baremetal_DMA_TestApp_SBL_APPIMAGEGEN = yes
export UART_Baremetal_DMA_TestApp_SBL_APPIMAGEGEN
endif

# UART unit test rtos app
UART_TestApp_COMP_LIST = UART_TestApp
UART_TestApp_RELPATH = ti/drv/uart/test
UART_TestApp_PATH = $(PDK_UART_COMP_PATH)/test
UART_TestApp_BOARD_DEPENDENCY = yes
UART_TestApp_CORE_DEPENDENCY = no
UART_TestApp_MAKEFILE = -f makefile
UART_TestApp_XDC_CONFIGURO = yes
export UART_TestApp_COMP_LIST
export UART_TestApp_BOARD_DEPENDENCY
export UART_TestApp_CORE_DEPENDENCY
export UART_TestApp_MAKEFILE
export UART_TestApp_XDC_CONFIGURO
UART_TestApp_PKG_LIST = UART_TestApp
UART_TestApp_INCLUDE = $(UART_TestApp_PATH)
UART_TestApp_BOARDLIST = $(drvuart_BOARDLIST)
export UART_TestApp_BOARDLIST
UART_TestApp_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
export UART_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
UART_TestApp_SBL_APPIMAGEGEN = yes
export UART_TestApp_SBL_APPIMAGEGEN
endif

# UART unit test rtos app with SMP enabled
UART_SMP_TestApp_COMP_LIST = UART_SMP_TestApp
UART_SMP_TestApp_RELPATH = ti/drv/uart/test
UART_SMP_TestApp_PATH = $(PDK_UART_COMP_PATH)/test
UART_SMP_TestApp_BOARD_DEPENDENCY = yes
UART_SMP_TestApp_CORE_DEPENDENCY = no
UART_SMP_TestApp_MAKEFILE = -f makefile SMP=enable
UART_SMP_TestApp_XDC_CONFIGURO = yes
export UART_SMP_TestApp_COMP_LIST
export UART_SMP_TestApp_BOARD_DEPENDENCY
export UART_SMP_TestApp_CORE_DEPENDENCY
export UART_SMP_TestApp_MAKEFILE
export UART_SMP_TestApp_XDC_CONFIGURO
UART_SMP_TestApp_PKG_LIST = UART_SMP_TestApp
UART_SMP_TestApp_INCLUDE = $(UART_SMP_TestApp_PATH)
UART_SMP_TestApp_BOARDLIST = $(drvuart_BOARDLIST)
export UART_SMP_TestApp_BOARDLIST
UART_SMP_TestApp_$(SOC)_CORELIST = mpu1_0
export UART_SMP_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
UART_SMP_TestApp_SBL_APPIMAGEGEN = yes
export UART_SMP_TestApp_SBL_APPIMAGEGEN
endif

# UART unit test rtos dma app
UART_DMA_TestApp_COMP_LIST = UART_DMA_TestApp
UART_DMA_TestApp_RELPATH = ti/drv/uart/test
UART_DMA_TestApp_PATH = $(PDK_UART_COMP_PATH)/test
UART_DMA_TestApp_BOARD_DEPENDENCY = yes
UART_DMA_TestApp_CORE_DEPENDENCY = no
UART_DMA_TestApp_MAKEFILE = -f makefile DMA=enable
UART_DMA_TestApp_XDC_CONFIGURO = yes
export UART_DMA_TestApp_COMP_LIST
export UART_DMA_TestApp_BOARD_DEPENDENCY
export UART_DMA_TestApp_CORE_DEPENDENCY
export UART_DMA_TestApp_MAKEFILE
export UART_DMA_TestApp_XDC_CONFIGURO
UART_DMA_TestApp_PKG_LIST = UART_DMA_TestApp
UART_DMA_TestApp_INCLUDE = $(UART_DMA_TestApp_PATH)
UART_DMA_TestApp_BOARDLIST = $(drvuart_BOARDLIST)
export UART_DMA_TestApp_BOARDLIST
UART_DMA_TestApp_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
export UART_DMA_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
UART_DMA_TestApp_SBL_APPIMAGEGEN = yes
export UART_DMA_TestApp_SBL_APPIMAGEGEN
endif

# UART unit test rtos dma app with SMP enabled
UART_DMA_SMP_TestApp_COMP_LIST = UART_DMA_SMP_TestApp
UART_DMA_SMP_TestApp_RELPATH = ti/drv/uart/test
UART_DMA_SMP_TestApp_PATH = $(PDK_UART_COMP_PATH)/test
UART_DMA_SMP_TestApp_BOARD_DEPENDENCY = yes
UART_DMA_SMP_TestApp_CORE_DEPENDENCY = no
UART_DMA_SMP_TestApp_MAKEFILE = -f makefile DMA=enable SMP=enable
UART_DMA_SMP_TestApp_XDC_CONFIGURO = yes
export UART_DMA_SMP_TestApp_COMP_LIST
export UART_DMA_SMP_TestApp_BOARD_DEPENDENCY
export UART_DMA_SMP_TestApp_CORE_DEPENDENCY
export UART_DMA_SMP_TestApp_MAKEFILE
export UART_DMA_SMP_TestApp_XDC_CONFIGURO
UART_DMA_SMP_TestApp_PKG_LIST = UART_DMA_SMP_TestApp
UART_DMA_SMP_TestApp_INCLUDE = $(UART_DMA_SMP_TestApp_PATH)
UART_DMA_SMP_TestApp_BOARDLIST = $(drvuart_BOARDLIST)
export UART_DMA_SMP_TestApp_BOARDLIST
UART_DMA_SMP_TestApp_$(SOC)_CORELIST = mpu1_0
export UART_DMA_SMP_TestApp_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
UART_DMA_SMP_TestApp_SBL_APPIMAGEGEN = yes
export UART_DMA_SMP_TestApp_SBL_APPIMAGEGEN
endif

# UART Polling mode Test app
UART_BasicExample_Polling_ExampleProject_COMP_LIST = UART_BasicExample_Polling_ExampleProject
UART_BasicExample_Polling_ExampleProject_RELPATH = ti/drv/uart/example/UART_BasicExample_Polling_ExampleProject
UART_BasicExample_Polling_ExampleProject_PATH = $(PDK_UART_COMP_PATH)/example/UART_BasicExample_Polling_ExampleProject
UART_BasicExample_Polling_ExampleProject_BOARD_DEPENDENCY = yes
UART_BasicExample_Polling_ExampleProject_CORE_DEPENDENCY = no
UART_BasicExample_Polling_ExampleProject_XDC_CONFIGURO = yes
export UART_BasicExample_Polling_ExampleProject_COMP_LIST
export UART_BasicExample_Polling_ExampleProject_BOARD_DEPENDENCY
export UART_BasicExample_Polling_ExampleProject_CORE_DEPENDENCY
export UART_BasicExample_Polling_ExampleProject_XDC_CONFIGURO
UART_BasicExample_Polling_ExampleProject_PKG_LIST = UART_BasicExample_Polling_ExampleProject
UART_BasicExample_Polling_ExampleProject_INCLUDE = $(UART_BasicExample_Polling_ExampleProject_PATH)
UART_BasicExample_Polling_ExampleProject_BOARDLIST = tda2xx-evm tda2px-evm tda2ex-evm tda3xx-evm evmDRA75x evmDRA78x
export UART_BasicExample_Polling_ExampleProject_BOARDLIST
UART_BasicExample_Polling_ExampleProject_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
export UART_BasicExample_Polling_ExampleProject_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
UART_BasicExample_Polling_ExampleProject_SBL_APPIMAGEGEN = yes
export UART_BasicExample_Polling_ExampleProject_SBL_APPIMAGEGEN
endif

# UART Interrupt mode Test app
UART_BasicExample_Intr_ExampleProject_COMP_LIST = UART_BasicExample_Intr_ExampleProject
UART_BasicExample_Intr_ExampleProject_RELPATH = ti/drv/uart/example/UART_BasicExample_Intr_ExampleProject
UART_BasicExample_Intr_ExampleProject_PATH = $(PDK_UART_COMP_PATH)/example/UART_BasicExample_Intr_ExampleProject
UART_BasicExample_Intr_ExampleProject_BOARD_DEPENDENCY = yes
UART_BasicExample_Intr_ExampleProject_CORE_DEPENDENCY = no
UART_BasicExample_Intr_ExampleProject_XDC_CONFIGURO = yes
export UART_BasicExample_Intr_ExampleProject_COMP_LIST
export UART_BasicExample_Intr_ExampleProject_BOARD_DEPENDENCY
export UART_BasicExample_Intr_ExampleProject_CORE_DEPENDENCY
export UART_BasicExample_Intr_ExampleProject_XDC_CONFIGURO
UART_BasicExample_Intr_ExampleProject_PKG_LIST = UART_BasicExample_Intr_ExampleProject
UART_BasicExample_Intr_ExampleProject_INCLUDE = $(UART_BasicExample_Intr_ExampleProject_PATH)
UART_BasicExample_Intr_ExampleProject_BOARDLIST = tda2xx-evm tda2px-evm tda2ex-evm tda3xx-evm evmDRA75x evmDRA78x
export UART_BasicExample_Intr_ExampleProject_BOARDLIST
UART_BasicExample_Intr_ExampleProject_$(SOC)_CORELIST = $(drvuart_$(SOC)_CORELIST)
export UART_BasicExample_Intr_ExampleProject_$(SOC)_CORELIST
ifeq ($(SOC),$(filter $(SOC), am65xx j721e j7200))
UART_BasicExample_Intr_ExampleProject_SBL_APPIMAGEGEN = yes
export UART_BasicExample_Intr_ExampleProject_SBL_APPIMAGEGEN
endif

export drvuart_LIB_LIST
export uart_LIB_LIST
export uart_EXAMPLE_LIST
export drvuart_EXAMPLE_LIST
export drvuart_FIRM_LIST
export uart_FIRM_LIST

uart_component_make_include := 1
endif

#*******************************************************************************
#                                                                              *
# Copyright (c) 2013-2017 Texas Instruments Incorporated - http://www.ti.com/  *
#                        ALL RIGHTS RESERVED                                   *
#                                                                              *
#*******************************************************************************

# File: component.mk
#       This file is component include make file of PM library.
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
ifeq ($(pm_component_make_include), )

pmrtos_SOCLIST = am572x dra75x am571x dra78x am335x am437x k2g
pmrtos_BOARDLIST = evmDRA75x evmAM572x idkAM572x idkAM571x evmDRA78x evmAM335x evmAM437x evmK2G iceK2G
pm_SOCLIST = $(pmrtos_SOCLIST) tda2xx tda2ex tda3xx
pm_BOARDLIST = $(pmrtos_BOARDLIST) tda2xx-evm tda2ex-evm tda3xx-evm
pm_tda2xx_CORELIST = a15_0 ipu1_0 c66x
pm_am572x_CORELIST = a15_0 ipu1_0 c66x
pm_dra75x_CORELIST = a15_0 ipu1_0 c66x
pm_tda2ex_CORELIST = a15_0 ipu1_0 c66x
pm_am571x_CORELIST = a15_0 ipu1_0 c66x
pm_tda3xx_CORELIST = ipu1_0 c66x
pm_am335x_CORELIST = a8host
pm_am437x_CORELIST = a9host
pm_dra78x_CORELIST = ipu1_0 c66x
pm_k2g_CORELIST = a15_0 c66x

############################
# pm package
# List of components included under pm lib
# The components included here are built and will be part of pm lib
############################
pm_LIB_LIST = pm_hal pm_lib
ifeq ($(BUILD_OS_TYPE),tirtos)
pm_LIB_LIST += pm_rtos
endif

############################
# pm app lib package
# List of components included under pm app lib
# The components included here are built and will be part of pm app lib
############################
pm_APP_LIB_LIST = pm_example_utils

############################
# pm examples
# List of examples under pm (+= is used at each example definition)
# All the tests mentioned in list are built when test target is called
# List below all examples for allowed values
############################
pm_EXAMPLE_LIST =

#
# PM Modules
#

# PM HAL
pm_hal_COMP_LIST = pm_hal
pm_hal_RELPATH = ti/drv/pm/src/pmhal
pm_hal_PATH = $(PDK_PM_COMP_PATH)/src/pmhal
pm_hal_LIBNAME = pm_hal
pm_hal_LIBPATH = $(PDK_PM_COMP_PATH)/lib
export pm_hal_LIBNAME
export pm_hal_LIBPATH
pm_hal_BOARD_DEPENDENCY = no
pm_hal_CORE_DEPENDENCY = no
export pm_hal_COMP_LIST
export pm_hal_BOARD_DEPENDENCY
export pm_hal_CORE_DEPENDENCY
pm_hal_PKG_LIST = pm_hal
pm_hal_INCLUDE = $(pm_hal_PATH) $(PDK_PM_COMP_PATH)/include
ifeq ($(SOC),$(filter $(SOC), k2g))
pm_hal_INCLUDE += $(PDK_PM_COMP_PATH)/include/pmmc
else
pm_hal_INCLUDE += $(PDK_PM_COMP_PATH)/include/prcm
endif
pm_hal_SOCLIST = $(pm_SOCLIST)
export pm_hal_SOCLIST
ifeq ($(SOC),$(filter $(SOC), tda2xx tda3xx))
pm_hal_$(SOC)_CORELIST = $(pm_$(SOC)_CORELIST) arp32_1
else
pm_hal_$(SOC)_CORELIST = $(pm_$(SOC)_CORELIST)
endif
export pm_hal_$(SOC)_CORELIST

# PM LIB
pm_lib_COMP_LIST = pm_lib
pm_lib_RELPATH = ti/drv/pm/src/pmlib
pm_lib_PATH = $(PDK_PM_COMP_PATH)/src/pmlib
pm_lib_LIBNAME = pm_lib
pm_lib_LIBPATH = $(PDK_PM_COMP_PATH)/lib
export pm_lib_LIBNAME
export pm_lib_LIBPATH
pm_lib_BOARD_DEPENDENCY = no
pm_lib_CORE_DEPENDENCY = no
export pm_lib_COMP_LIST
export pm_lib_BOARD_DEPENDENCY
export pm_lib_CORE_DEPENDENCY
pm_lib_PKG_LIST = pm_lib
pm_lib_INCLUDE = $(pm_lib_PATH) $(PDK_PM_COMP_PATH)/include
pm_lib_SOCLIST = $(pm_SOCLIST)
export pm_lib_SOCLIST
ifeq ($(SOC),$(filter $(SOC), tda2xx tda3xx))
pm_lib_$(SOC)_CORELIST = $(pm_$(SOC)_CORELIST) arp32_1
else
pm_lib_$(SOC)_CORELIST = $(pm_$(SOC)_CORELIST)
endif
export pm_lib_$(SOC)_CORELIST

# PM RTOS
pm_rtos_COMP_LIST = pm_rtos
pm_rtos_RELPATH = ti/drv/pm
pm_rtos_PATH = $(PDK_PM_COMP_PATH)
pm_rtos_LIBNAME = pm_rtos
pm_rtos_LIBPATH = $(PDK_PM_COMP_PATH)/lib
pm_rtos_MAKEFILE = -fmakefile.mk
export pm_rtos_LIBNAME
export pm_rtos_LIBPATH
export pm_rtos_MAKEFILE
pm_rtos_BOARD_DEPENDENCY = no
pm_rtos_CORE_DEPENDENCY = no
export pm_rtos_COMP_LIST
export pm_rtos_BOARD_DEPENDENCY
export pm_rtos_CORE_DEPENDENCY
pm_rtos_PKG_LIST = pm_rtos
pm_rtos_INCLUDE = $(pm_rtos_PATH) $(PDK_PM_COMP_PATH)/include
pm_rtos_SOCLIST = $(pmrtos_SOCLIST)
export pm_rtos_SOCLIST
pm_rtos_$(SOC)_CORELIST = $(pm_$(SOC)_CORELIST)
export pm_rtos_$(SOC)_CORELIST

# PM Example Utils
pm_example_utils_COMP_LIST = pm_example_utils
pm_example_utils_RELPATH = ti/drv/pm/examples/utils
pm_example_utils_PATH = $(PDK_PM_COMP_PATH)/examples/utils
pm_example_utils_LIBNAME = pm_example_utils
pm_example_utils_LIBPATH = $(PDK_PM_COMP_PATH)/lib
export pm_example_utils_LIBNAME
export pm_example_utils_LIBPATH
pm_example_utils_BOARD_DEPENDENCY = no
pm_example_utils_CORE_DEPENDENCY = no
export pm_example_utils_COMP_LIST
export pm_example_utils_BOARD_DEPENDENCY
export pm_example_utils_CORE_DEPENDENCY
pm_example_utils_PKG_LIST = pm_example_utils
pm_example_utils_INCLUDE = $(pm_example_utils_PATH)
pm_example_utils_SOCLIST = tda2xx am572x dra75x tda2ex am571x tda3xx dra78x am335x am437x k2g
export pm_example_utils_SOCLIST
pm_example_utils_$(SOC)_CORELIST = $(pm_$(SOC)_CORELIST)
export pm_example_utils_$(SOC)_CORELIST

#
# PM Examples
#

# PM Systemconfig App
pm_systemconfig_app_COMP_LIST = pm_systemconfig_app
pm_systemconfig_app_RELPATH = ti/drv/pm/examples/systemconfig
pm_systemconfig_app_PATH = $(PDK_PM_COMP_PATH)/examples/systemconfig
pm_systemconfig_app_BOARD_DEPENDENCY = yes
pm_systemconfig_app_CORE_DEPENDENCY = no
pm_systemconfig_app_XDC_CONFIGURO = yes
export pm_systemconfig_app_COMP_LIST
export pm_systemconfig_app_BOARD_DEPENDENCY
export pm_systemconfig_app_CORE_DEPENDENCY
export pm_systemconfig_app_XDC_CONFIGURO
pm_systemconfig_app_PKG_LIST = pm_systemconfig_app
pm_systemconfig_app_INCLUDE =
pm_systemconfig_app_BOARDLIST = tda2xx-evm tda2ex-evm tda3xx-evm evmDRA78x
export pm_systemconfig_app_BOARDLIST
pm_systemconfig_app_$(SOC)_CORELIST = $(pm_$(SOC)_CORELIST)
export pm_systemconfig_app_$(SOC)_CORELIST
pm_EXAMPLE_LIST += pm_systemconfig_app

# PM RTOS App
pm_rtos_app_COMP_LIST = pm_rtos_app
pm_rtos_app_RELPATH = ti/drv/pm/examples/pmrtos
pm_rtos_app_PATH = $(PDK_PM_COMP_PATH)/examples/pmrtos
pm_rtos_app_BOARD_DEPENDENCY = yes
pm_rtos_app_CORE_DEPENDENCY = no
pm_rtos_app_XDC_CONFIGURO = yes
export pm_rtos_app_COMP_LIST
export pm_rtos_app_BOARD_DEPENDENCY
export pm_rtos_app_CORE_DEPENDENCY
export pm_rtos_app_XDC_CONFIGURO
pm_rtos_app_PKG_LIST = pm_rtos_app
pm_rtos_app_INCLUDE = $(pm_rtos_app_PATH) $(PDK_PM_COMP_PATH)/include
pm_rtos_app_BOARDLIST = evmAM572x evmDRA78x evmAM335x evmAM437x evmK2G
export pm_rtos_app_BOARDLIST
pm_rtos_app_$(SOC)_CORELIST = $(pm_$(SOC)_CORELIST)
ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x))
pm_rtos_app_$(SOC)_CORELIST = ipu1_0
endif
export pm_rtos_app_$(SOC)_CORELIST
ifeq ($(BUILD_OS_TYPE),tirtos)
pm_EXAMPLE_LIST += pm_rtos_app
endif


# PM RTOS Thermal App
pm_rtos_thermal_app_COMP_LIST = pm_rtos_thermal_app
pm_rtos_thermal_app_RELPATH = ti/drv/pm/examples/pmrtos_thermal
pm_rtos_thermal_app_PATH = $(PDK_PM_COMP_PATH)/examples/pmrtos_thermal
pm_rtos_thermal_app_BOARD_DEPENDENCY = yes
pm_rtos_thermal_app_CORE_DEPENDENCY = no
pm_rtos_thermal_app_XDC_CONFIGURO = yes
export pm_rtos_thermal_app_COMP_LIST
export pm_rtos_thermal_app_BOARD_DEPENDENCY
export pm_rtos_thermal_app_CORE_DEPENDENCY
export pm_rtos_thermal_app_XDC_CONFIGURO
pm_rtos_thermal_app_PKG_LIST = pm_rtos_thermal_app
pm_rtos_thermal_app_INCLUDE = $(pm_rtos_thermal_app_PATH) $(PDK_PM_COMP_PATH)/include
pm_rtos_thermal_app_BOARDLIST = evmAM572x
export pm_rtos_thermal_app_BOARDLIST
pm_rtos_thermal_app_$(SOC)_CORELIST = $(pm_$(SOC)_CORELIST)

export pm_rtos_thermal_app_$(SOC)_CORELIST
ifeq ($(BUILD_OS_TYPE),tirtos)
pm_EXAMPLE_LIST += pm_rtos_thermal_app
endif

# PM RTOS Measurement App
pm_rtos_measurement_app_COMP_LIST = pm_rtos_measurement_app
pm_rtos_measurement_app_RELPATH = ti/drv/pm/examples/pmrtos_measurement
pm_rtos_measurement_app_PATH = $(PDK_PM_COMP_PATH)/examples/pmrtos_measurement
pm_rtos_measurement_app_BOARD_DEPENDENCY = yes
pm_rtos_measurement_app_CORE_DEPENDENCY = no
pm_rtos_measurement_app_XDC_CONFIGURO = yes
export pm_rtos_measurement_app_COMP_LIST
export pm_rtos_measurement_app_BOARD_DEPENDENCY
export pm_rtos_measurement_app_CORE_DEPENDENCY
export pm_rtos_measurement_app_XDC_CONFIGURO
pm_rtos_measurement_app_PKG_LIST = pm_rtos_measurement_app
pm_rtos_measurement_app_INCLUDE = $(pm_rtos_measurement_app_PATH) $(PDK_PM_COMP_PATH)/include
pm_rtos_measurement_app_BOARDLIST = evmAM335x evmAM437x
export pm_rtos_measurement_app_BOARDLIST
pm_rtos_measurement_app_$(SOC)_CORELIST = $(pm_$(SOC)_CORELIST)
export pm_rtos_measurement_app_$(SOC)_CORELIST
ifeq ($(BUILD_OS_TYPE),tirtos)
# pm_EXAMPLE_LIST += pm_rtos_measurement_app
endif

export pm_LIB_LIST
export pm_EXAMPLE_LIST

pm_component_make_include := 1
endif

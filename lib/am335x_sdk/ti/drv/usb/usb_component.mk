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

# File: usb_component.mk
#       This file is component include make file of USB library.
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
ifeq ($(usb_component_make_include), )

# under other list
drvusb_BOARDLIST       = am65xx_evm am65xx_idk j721e_evm
drvusb_SOCLIST         = am574x am572x am571x am437x am335x dra72x dra75x k2g omapl137 omapl138 am65xx j721e
drvusb_am65xx_CORELIST = mpu1_0 mcu1_0
drvusb_j721e_CORELIST  = mpu1_0 mcu1_0
drvusb_am574x_CORELIST = a15_0
drvusb_am572x_CORELIST = a15_0
drvusb_am571x_CORELIST = a15_0
drvusb_am437x_CORELIST = a9host
drvusb_am335x_CORELIST = a8host
drvusb_dra72x_CORELIST = a15_0 ipu1_0
drvusb_dra75x_CORELIST = a15_0 ipu1_0
drvusb_k2g_CORELIST = a15_0
drvusb_omapl137_CORELIST = arm9_0 c674x
drvusb_omapl138_CORELIST = arm9_0 c674x
############################
# usb package
# List of components included under usb lib
# The components included here are built and will be part of usb lib
############################
usb_LIB_LIST = usb
#usb_profile usb_indp usb_profile_indp
drvusb_LIB_LIST = $(usb_LIB_LIST)

############################
# usb examples
# List of examples under usb
# All the tests mentioned in list are built when test target is called
# List below all examples for allowed values
# The app names in the EXAMPLE_LIST need to match with the APP_NAME in the example makefiles
# in ti/drv/usb/example/build
############################

usb_EXAMPLE_LIST =  USB_HostMsc_TestApp USB_DevMsc_TestApp USB_DevBulk_TestApp

ifeq ($(SOC),$(filter $(SOC), am65xx ))
    usb_EXAMPLE_LIST += USB_Baremetal_HostMsc_TestApp USB_Baremetal_DevMsc_TestApp USB_Baremetal_HostMsc_usb30_TestApp
endif

usb_EXAMPLE_LIST += USB_HostMsc_usb30_TestApp

drvusb_EXAMPLE_LIST = $(usb_EXAMPLE_LIST)

#
# USB Modules
#

# USB LIB
usb_COMP_LIST = usb
usb_RELPATH = ti/drv/usb
usb_PATH = $(PDK_USB_COMP_PATH)
usb_LIBNAME = ti.drv.usb
export usb_LIBNAME
usb_LIBPATH = $(usb_PATH)/lib
export usb_LIBPATH
usb_OBJPATH = $(usb_RELPATH)/usb
export usb_OBJPATH
usb_MAKEFILE = -f build/makefile.mk
export usb_MAKEFILE
usb_BOARD_DEPENDENCY = no
usb_CORE_DEPENDENCY = no
usb_SOC_DEPENDENCY = yes
export usb_COMP_LIST
export usb_BOARD_DEPENDENCY
export usb_CORE_DEPENDENCY
export usb_SOC_DEPENDENCY
usb_PKG_LIST = usb
export usb_PKG_LIST
usb_INCLUDE = $(usb_PATH)
usb_SOCLIST = $(drvusb_SOCLIST)
export usb_SOCLIST
usb_$(SOC)_CORELIST = $(drvusb_$(SOC)_CORELIST)
export usb_$(SOC)_CORELIST

# USB LIB DEVICE INDEPENDENT
usb_indp_COMP_LIST = usb_indp
usb_indp_RELPATH = ti/drv/usb
usb_indp_PATH = $(PDK_USB_COMP_PATH)
usb_indp_LIBNAME = ti.drv.usb
export usb_indp_LIBNAME
usb_indp_LIBPATH = $(usb_indp_PATH)/lib
export usb_indp_LIBPATH
usb_indp_OBJPATH = $(usb_indp_RELPATH)/usb_indp
export usb_indp_OBJPATH
usb_indp_MAKEFILE = -f build/makefile_indp.mk
export usb_indp_MAKEFILE
usb_indp_BOARD_DEPENDENCY = no
usb_indp_CORE_DEPENDENCY = no
usb_indp_SOC_DEPENDENCY = no
export usb_indp_COMP_LIST
export usb_indp_BOARD_DEPENDENCY
export usb_indp_CORE_DEPENDENCY
export usb_indp_SOC_DEPENDENCY
usb_indp_PKG_LIST = usb_indp
export usb_indp_PKG_LIST
usb_indp_INCLUDE = $(usb_indp_PATH)
usb_indp_SOCLIST = $(drvusb_SOCLIST)
export usb_indp_SOCLIST
usb_indp_$(SOC)_CORELIST = $(drvusb_$(SOC)_CORELIST)
export usb_indp_$(SOC)_CORELIST

# USB PROFILING SOC LIB
usb_profile_COMP_LIST = usb_profile
usb_profile_RELPATH = ti/drv/usb
usb_profile_PATH = $(PDK_USB_COMP_PATH)
usb_profile_LIBNAME = ti.drv.usb.profiling
export usb_profile_LIBNAME
usb_profile_LIBPATH = $(usb_profile_PATH)/lib
export usb_profile_LIBPATH
usb_profile_OBJPATH = $(usb_profile_RELPATH)/usb_profile
export usb_profile_OBJPATH
usb_profile_MAKEFILE = -f build/makefile_profile.mk
export usb_profile_MAKEFILE
usb_profile_BOARD_DEPENDENCY = no
usb_profile_CORE_DEPENDENCY = no
usb_profile_SOC_DEPENDENCY = yes
export usb_profile_COMP_LIST
export usb_profile_BOARD_DEPENDENCY
export usb_profile_CORE_DEPENDENCY
export usb_profile_SOC_DEPENDENCY
usb_profile_PKG_LIST = usb_profile
export usb_profile_PKG_LIST
usb_profile_INCLUDE = $(usb_profile_PATH)
usb_profile_SOCLIST = $(drvusb_SOCLIST)
export usb_profile_SOCLIST
usb_profile_$(SOC)_CORELIST = $(drvusb_$(SOC)_CORELIST)
export usb_profile_$(SOC)_CORELIST

# USB PROFILING SOC INDEPENDENT LIB
usb_profile_indp_COMP_LIST = usb_profile_indp
usb_profile_indp_RELPATH = ti/drv/usb
usb_profile_indp_PATH = $(PDK_USB_COMP_PATH)
usb_profile_indp_LIBNAME = ti.drv.usb.profiling
export usb_profile_indp_LIBNAME
usb_profile_indp_LIBPATH = $(usb_profile_indp_PATH)/lib
export usb_profile_indp_LIBPATH
usb_profile_indp_OBJPATH = $(usb_profile_indp_RELPATH)/usb_profile_indp
export usb_profile_indp_OBJPATH
usb_profile_indp_MAKEFILE = -f build/makefile_profile_indp.mk
export usb_profile_indp_MAKEFILE
usb_profile_indp_BOARD_DEPENDENCY = no
usb_profile_indp_CORE_DEPENDENCY = no
usb_profile_indp_SOC_DEPENDENCY = no
export usb_profile_indp_COMP_LIST
export usb_profile_indp_BOARD_DEPENDENCY
export usb_profile_indp_CORE_DEPENDENCY
export usb_profile_indp_SOC_DEPENDENCY
usb_profile_indp_PKG_LIST = usb_profile_indp
export usb_profile_indp_PKG_LIST
usb_profile_indp_INCLUDE = $(usb_profile_indp_PATH)
usb_profile_indp_SOCLIST = $(drvusb_SOCLIST)
export usb_profile_indp_SOCLIST
usb_profile_indp_$(SOC)_CORELIST = $(drvusb_$(SOC)_CORELIST)
export usb_profile_indp_$(SOC)_CORELIST

#USB examples
#USB RTOS host MSC example
USB_HostMsc_TestApp_COMP_LIST = USB_HostMsc_TestApp
USB_HostMsc_TestApp_RELPATH = ti/drv/usb/example/build/usb_host_msc
USB_HostMsc_TestApp_PATH = $(PDK_USB_COMP_PATH)/example/build/usb_host_msc
USB_HostMsc_TestApp_MAKEFILE = -f makefile USB30=no
USB_HostMsc_TestApp_BOARD_DEPENDENCY = yes
USB_HostMsc_TestApp_CORE_DEPENDENCY = no
USB_HostMsc_TestApp_XDC_CONFIGURO = yes
USB_HostMsc_TestApp_PKG_LIST = USB_HostMsc_TestApp
USB_HostMsc_TestApp_INCLUDE = $(USB_HostMsc_TestApp_PATH)
USB_HostMsc_TestApp_BOARDLIST = $(drvusb_BOARDLIST)
USB_HostMsc_TestApp_$(SOC)_CORELIST = $(drvusb_$(SOC)_CORELIST)

export USB_HostMsc_TestApp_COMP_LIST
export USB_HostMsc_TestApp_RELPATH
export USB_HostMsc_TestApp_PATH
export USB_HostMsc_TestApp_BOARD_DEPENDENCY
export USB_HostMsc_TestApp_CORE_DEPENDENCY
export USB_HostMsc_TestApp_XDC_CONFIGURO
export USB_HostMsc_TestApp_PKG_LIST
export USB_HostMsc_TestApp_INCLUDE
export USB_HostMsc_TestApp_BOARDLIST
export USB_HostMsc_TestApp_$(SOC)_CORELIST
export USB_HostMsc_TestApp_MAKEFILE

#USB RTOS host MSC example with SMP enabled
USB_HostMsc_SMP_TestApp_COMP_LIST = USB_HostMsc_TestApp
USB_HostMsc_SMP_TestApp_RELPATH = ti/drv/usb/example/build/usb_host_msc
USB_HostMsc_SMP_TestApp_PATH = $(PDK_USB_COMP_PATH)/example/build/usb_host_msc
USB_HostMsc_SMP_TestApp_MAKEFILE = -f makefile USB30=no SMP=enable
USB_HostMsc_SMP_TestApp_BOARD_DEPENDENCY = yes
USB_HostMsc_SMP_TestApp_CORE_DEPENDENCY = no
USB_HostMsc_SMP_TestApp_XDC_CONFIGURO = yes
USB_HostMsc_SMP_TestApp_PKG_LIST = USB_HostMsc_TestApp
USB_HostMsc_SMP_TestApp_INCLUDE = $(USB_HostMsc_SMP_TestApp_PATH)
USB_HostMsc_SMP_TestApp_BOARDLIST = $(drvusb_BOARDLIST)
USB_HostMsc_SMP_TestApp_$(SOC)_CORELIST = mpu1_0

export USB_HostMsc_SMP_TestApp_COMP_LIST
export USB_HostMsc_SMP_TestApp_RELPATH
export USB_HostMsc_SMP_TestApp_PATH
export USB_HostMsc_SMP_TestApp_BOARD_DEPENDENCY
export USB_HostMsc_SMP_TestApp_CORE_DEPENDENCY
export USB_HostMsc_SMP_TestApp_XDC_CONFIGURO
export USB_HostMsc_SMP_TestApp_PKG_LIST
export USB_HostMsc_SMP_TestApp_INCLUDE
export USB_HostMsc_SMP_TestApp_BOARDLIST
export USB_HostMsc_SMP_TestApp_$(SOC)_CORELIST
export USB_HostMsc_SMP_TestApp_MAKEFILE

#USB RTOS dev MSC example
USB_DevMsc_TestApp_COMP_LIST = USB_DevMsc_TestApp
USB_DevMsc_TestApp_RELPATH = ti/drv/usb/example/build/usb_dev_msc
USB_DevMsc_TestApp_PATH = $(PDK_USB_COMP_PATH)/example/build/usb_dev_msc
USB_DevMsc_TestApp_BOARD_DEPENDENCY = yes
USB_DevMsc_TestApp_CORE_DEPENDENCY = no
USB_DevMsc_TestApp_XDC_CONFIGURO = yes
USB_DevMsc_TestApp_PKG_LIST = USB_DevMsc_TestApp
USB_DevMsc_TestApp_INCLUDE = $(USB_DevMsc_TestApp_PATH)
USB_DevMsc_TestApp_BOARDLIST = $(drvusb_BOARDLIST)
USB_DevMsc_TestApp_$(SOC)_CORELIST = $(drvusb_$(SOC)_CORELIST)

export USB_DevMsc_TestApp_COMP_LIST
export USB_DevMsc_TestApp_RELPATH
export USB_DevMsc_TestApp_PATH
export USB_DevMsc_TestApp_BOARD_DEPENDENCY
export USB_DevMsc_TestApp_CORE_DEPENDENCY
export USB_DevMsc_TestApp_XDC_CONFIGURO
export USB_DevMsc_TestApp_PKG_LIST
export USB_DevMsc_TestApp_INCLUDE
export USB_DevMsc_TestApp_BOARDLIST
export USB_DevMsc_TestApp_$(SOC)_CORELIST

#USB RTOS dev bulk example
USB_DevBulk_TestApp_COMP_LIST = USB_DevBulk_TestApp
USB_DevBulk_TestApp_RELPATH = ti/drv/usb/example/build/usb_dev_bulk
USB_DevBulk_TestApp_PATH = $(PDK_USB_COMP_PATH)/example/build/usb_dev_bulk
USB_DevBulk_TestApp_BOARD_DEPENDENCY = yes
USB_DevBulk_TestApp_CORE_DEPENDENCY = no
USB_DevBulk_TestApp_XDC_CONFIGURO = yes
USB_DevBulk_TestApp_PKG_LIST = USB_DevBulk_TestApp
USB_DevBulk_TestApp_INCLUDE = $(USB_DevBulk_TestApp_PATH)
USB_DevBulk_TestApp_BOARDLIST = $(drvusb_BOARDLIST)
USB_DevBulk_TestApp_$(SOC)_CORELIST = $(drvusb_$(SOC)_CORELIST)

export USB_DevBulk_TestApp_COMP_LIST
export USB_DevBulk_TestApp_RELPATH
export USB_DevBulk_TestApp_PATH
export USB_DevBulk_TestApp_BOARD_DEPENDENCY
export USB_DevBulk_TestApp_CORE_DEPENDENCY
export USB_DevBulk_TestApp_XDC_CONFIGURO
export USB_DevBulk_TestApp_PKG_LIST
export USB_DevBulk_TestApp_INCLUDE
export USB_DevBulk_TestApp_BOARDLIST
export USB_DevBulk_TestApp_$(SOC)_CORELIST

# Baremetal projects
# Bare-metal USB host project
USB_Baremetal_HostMsc_TestApp_COMP_LIST = USB_Baremetal_HostMsc_TestApp
USB_Baremetal_HostMsc_TestApp_RELPATH = ti/drv/usb/example/build/usb_host_msc
USB_Baremetal_HostMsc_TestApp_PATH = $(PDK_USB_COMP_PATH)/example/build/usb_host_msc
USB_Baremetal_HostMsc_TestApp_BOARD_DEPENDENCY = yes
USB_Baremetal_HostMsc_TestApp_CORE_DEPENDENCY = no
USB_Baremetal_HostMsc_TestApp_XDC_CONFIGURO = yes
USB_Baremetal_HostMsc_TestApp_MAKEFILE = -f makefile BAREMETAL=yes
USB_Baremetal_HostMsc_TestApp_PKG_LIST = USB_Baremetal_HostMsc_TestApp
USB_Baremetal_HostMsc_TestApp_INCLUDE = $(USB_Baremetal_HostMsc_TestApp_PATH)
USB_Baremetal_HostMsc_TestApp_BOARDLIST = $(drvusb_BOARDLIST)
USB_Baremetal_HostMsc_TestApp_$(SOC)_CORELIST = $(drvusb_$(SOC)_CORELIST)

export USB_Baremetal_HostMsc_TestApp_COMP_LIST
export USB_Baremetal_HostMsc_TestApp_RELPATH
export USB_Baremetal_HostMsc_TestApp_PATH
export USB_Baremetal_HostMsc_TestApp_BOARD_DEPENDENCY
export USB_Baremetal_HostMsc_TestApp_CORE_DEPENDENCY
export USB_Baremetal_HostMsc_TestApp_XDC_CONFIGURO
export USB_Baremetal_HostMsc_TestApp_PKG_LIST
export USB_Baremetal_HostMsc_TestApp_INCLUDE
export USB_Baremetal_HostMsc_TestApp_BOARDLIST
export USB_Baremetal_HostMsc_TestApp_$(SOC)_CORELIST
export USB_Baremetal_HostMsc_TestApp_MAKEFILE

# Bare metal USB dev MSC example
USB_Baremetal_DevMsc_TestApp_COMP_LIST = USB_Baremetal_DevMsc_TestApp
USB_Baremetal_DevMsc_TestApp_RELPATH = ti/drv/usb/example/build/usb_dev_msc
USB_Baremetal_DevMsc_TestApp_PATH = $(PDK_USB_COMP_PATH)/example/build/usb_dev_msc
USB_Baremetal_DevMsc_TestApp_BOARD_DEPENDENCY = yes
USB_Baremetal_DevMsc_TestApp_CORE_DEPENDENCY = no
USB_Baremetal_DevMsc_TestApp_XDC_CONFIGURO = yes
USB_Baremetal_DevMsc_TestApp_MAKEFILE = -f makefile BAREMETAL=yes
USB_Baremetal_DevMsc_TestApp_PKG_LIST = USB_Baremetal_DevMsc_TestApp
USB_Baremetal_DevMsc_TestApp_INCLUDE = $(USB_Baremetal_DevMsc_TestApp_PATH)
USB_Baremetal_DevMsc_TestApp_BOARDLIST = $(drvusb_BOARDLIST)
USB_Baremetal_DevMsc_TestApp_$(SOC)_CORELIST = $(drvusb_$(SOC)_CORELIST)

export USB_Baremetal_DevMsc_TestApp_COMP_LIST
export USB_Baremetal_DevMsc_TestApp_RELPATH
export USB_Baremetal_DevMsc_TestApp_PATH
export USB_Baremetal_DevMsc_TestApp_BOARD_DEPENDENCY
export USB_Baremetal_DevMsc_TestApp_CORE_DEPENDENCY
export USB_Baremetal_DevMsc_TestApp_XDC_CONFIGURO
export USB_Baremetal_DevMsc_TestApp_PKG_LIST
export USB_Baremetal_DevMsc_TestApp_INCLUDE
export USB_Baremetal_DevMsc_TestApp_BOARDLIST
export USB_Baremetal_DevMsc_TestApp_$(SOC)_CORELIST



# USB3.0 USB host project - RTOS
# only AM65x EVM supports USB3.0 - so limit BOARD here.
# AM5 also has USB3.0 but it has no makefile project ATM.
USB_HostMsc_usb30_TestApp_COMP_LIST = USB_HostMsc_usb30_TestApp
USB_HostMsc_usb30_TestApp_RELPATH = ti/drv/usb/example/build/usb_host_msc
USB_HostMsc_usb30_TestApp_PATH = $(PDK_USB_COMP_PATH)/example/build/usb_host_msc
USB_HostMsc_usb30_TestApp_BOARD_DEPENDENCY = yes
USB_HostMsc_usb30_TestApp_CORE_DEPENDENCY = no
USB_HostMsc_usb30_TestApp_XDC_CONFIGURO = yes
USB_HostMsc_usb30_TestApp_MAKEFILE = -f makefile USB30=yes
USB_HostMsc_usb30_TestApp_PKG_LIST = USB_HostMsc_usb30_TestApp
USB_HostMsc_usb30_TestApp_INCLUDE = $(USB_HostMsc_usb30_TestApp_PATH)
USB_HostMsc_usb30_TestApp_BOARDLIST = am65xx_evm j721e_evm
USB_HostMsc_usb30_TestApp_$(SOC)_CORELIST = $(drvusb_$(SOC)_CORELIST)

export USB_HostMsc_usb30_TestApp_COMP_LIST
export USB_HostMsc_usb30_TestApp_RELPATH
export USB_HostMsc_usb30_TestApp_PATH
export USB_HostMsc_usb30_TestApp_BOARD_DEPENDENCY
export USB_HostMsc_usb30_TestApp_CORE_DEPENDENCY
export USB_HostMsc_usb30_TestApp_XDC_CONFIGURO
export USB_HostMsc_usb30_TestApp_PKG_LIST
export USB_HostMsc_usb30_TestApp_INCLUDE
export USB_HostMsc_usb30_TestApp_BOARDLIST
export USB_HostMsc_usb30_TestApp_$(SOC)_CORELIST
export USB_HostMsc_usb30_TestApp_MAKEFILE


# USB3.0 USB host project - baremetal
# only AM65x EVM supports USB3.0
# AM5 also has USB3.0 but it has no makefile project ATM.
USB_Baremetal_HostMsc_usb30_TestApp_COMP_LIST = USB_Baremetal_HostMsc_usb30_TestApp
USB_Baremetal_HostMsc_usb30_TestApp_RELPATH = ti/drv/usb/example/build/usb_host_msc
USB_Baremetal_HostMsc_usb30_TestApp_PATH = $(PDK_USB_COMP_PATH)/example/build/usb_host_msc
USB_Baremetal_HostMsc_usb30_TestApp_BOARD_DEPENDENCY = yes
USB_Baremetal_HostMsc_usb30_TestApp_CORE_DEPENDENCY = no
USB_Baremetal_HostMsc_usb30_TestApp_XDC_CONFIGURO = yes
USB_Baremetal_HostMsc_usb30_TestApp_MAKEFILE = -f makefile USB30=yes BAREMETAL=yes
USB_Baremetal_HostMsc_usb30_TestApp_PKG_LIST = USB_Baremetal_HostMsc_usb30_TestApp
USB_Baremetal_HostMsc_usb30_TestApp_INCLUDE = $(USB_Baremetal_HostMsc_usb30_TestApp_PATH)
USB_Baremetal_HostMsc_usb30_TestApp_BOARDLIST = am65xx_evm j721e_evm
USB_Baremetal_HostMsc_usb30_TestApp_$(SOC)_CORELIST = $(drvusb_$(SOC)_CORELIST)

export USB_Baremetal_HostMsc_usb30_TestApp_COMP_LIST
export USB_Baremetal_HostMsc_usb30_TestApp_RELPATH
export USB_Baremetal_HostMsc_usb30_TestApp_PATH
export USB_Baremetal_HostMsc_usb30_TestApp_BOARD_DEPENDENCY
export USB_Baremetal_HostMsc_usb30_TestApp_CORE_DEPENDENCY
export USB_Baremetal_HostMsc_usb30_TestApp_XDC_CONFIGURO
export USB_Baremetal_HostMsc_usb30_TestApp_PKG_LIST
export USB_Baremetal_HostMsc_usb30_TestApp_INCLUDE
export USB_Baremetal_HostMsc_usb30_TestApp_BOARDLIST
export USB_Baremetal_HostMsc_usb30_TestApp_$(SOC)_CORELIST
export USB_Baremetal_HostMsc_usb30_TestApp_MAKEFILE





export drvusb_LIB_LIST
export usb_LIB_LIST
export usb_EXAMPLE_LIST
export drvusb_EXAMPLE_LIST

usb_component_make_include := 1
endif

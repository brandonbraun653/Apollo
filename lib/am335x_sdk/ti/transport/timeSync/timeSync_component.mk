#
# Copyright (c) 2018, Texas Instruments Incorporated
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

# File: timeSync_component.mk
#       This file is component include make file of timeSync driver library.
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
ifeq ($(timeSync_component_make_include), )

# under other list
timeSync_default_BOARDLIST       = idkAM572x idkAM571x idkAM437x icev2AM335x
timeSync_default_SOCLIST         = am572x am571x am574x am335x am437x k2g
timeSync_am572x_CORELIST         = c66x a15_0 ipu1_0
timeSync_am574x_CORELIST         = c66x a15_0 ipu1_0
timeSync_am571x_CORELIST         = c66x a15_0 ipu1_0
timeSync_k2g_CORELIST            = c66x a15_0
timeSync_am335x_CORELIST         = a8host
timeSync_am437x_CORELIST         = a9host


############################
# timeSync package
# List of components included under timeSync lib
# The components included here are built and will be part of timeSync lib
############################
timeSync_LIB_LIST = timeSync

############################
# timeSync examples
# List of examples under timeSync (+= is used at each example definition)
# All the tests mentioned in list are built when test target is called
# List below all examples for allowed values
############################
timeSync_EXAMPLE_LIST =

#
# timeSync Modules
#

# timeSync icss LIB DEVICE INDEPENDENT
timeSync_COMP_LIST = timeSync
timeSync_RELPATH = ti/transport/timeSync
timeSync_PATH = $(PDK_TIMESYNC_COMP_PATH)
timeSync_LIBNAME = ti.transport.timeSync
timeSync_LIBPATH = $(timeSync_PATH)/lib
timeSync_MAKEFILE = -fsrc/makefile
export timeSync_MAKEFILE
export timeSync_LIBNAME
timeSync_LIBPATH = $(PDK_TIMESYNC_COMP_PATH)/lib
export timeSync_LIBPATH
timeSync_BOARD_DEPENDENCY = no
timeSync_CORE_DEPENDENCY = no
timeSync_SOC_DEPENDENCY = no
export timeSync_COMP_LIST
export timeSync_BOARD_DEPENDENCY
export timeSync_CORE_DEPENDENCY
export timeSync_SOC_DEPENDENCY
timeSync_PKG_LIST = timeSync
timeSync_INCLUDE = $(timeSync_PATH)
timeSync_SOCLIST = $(timeSync_default_SOCLIST)
timeSync_BOARDLIST = $(timeSync_default_BOARDLIST)
export timeSync_SOCLIST
export timeSync_$(SOC)_CORELIST
export timeSync_BOARDLIST
timeSync_EXAMPLE_LIST =

export timeSync_LIB_LIST
export timeSync_EXAMPLE_LIST

timeSync_component_make_include := 1
endif

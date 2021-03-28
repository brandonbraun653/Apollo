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

# File: board_utils_component.mk
#       This file is component include make file of utils.
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
ifeq ($(board_utils_component_make_include), )

############################
# Board utils package
# List of components included under board utils
# The components included here are built and will be part of board utils
############################
board_utils_LIB_LIST =

############################
# Board utils package
# List of utils examples (apps) supported for below boards
############################
board_utils_j721e_BOARDLIST = j721e_evm
board_utils_j721e_CORELIST = mcu1_0

############################
# Board utils example
# List of example under board utils
# All the tests mentioned in list are built when test target is called
# List below all example for allowed values - note the list is populated in each example
############################
board_utils_EXAMPLE_LIST =

#
# board utils Modules
#

# board utils
board_utils_COMP_LIST = board_utils


# Flash Programmer
board_utils_uart_flash_programmer_COMP_LIST = board_utils_uart_flash_programmer
board_utils_uart_flash_programmer_RELPATH = ti/board/utils/uniflash/target/build
board_utils_uart_flash_programmer_CUSTOM_BINPATH = $(PDK_BOARD_UTILS_COMP_PATH)/uniflash/target/bin/$(BOARD)
board_utils_uart_flash_programmer_PATH = $(PDK_BOARD_UTILS_COMP_PATH)/uniflash/target/build
board_utils_uart_flash_programmer_MAKEFILE = -f uart_make.mk
board_utils_uart_flash_programmer_BOARD_DEPENDENCY = yes
board_utils_uart_flash_programmer_CORE_DEPENDENCY = yes
export board_utils_uart_flash_programmer_COMP_LIST
export board_utils_uart_flash_programmer_BOARD_DEPENDENCY
export board_utils_uart_flash_programmer_CORE_DEPENDENCY
export board_utils_uart_flash_programmer_MAKEFILE
export board_utils_uart_flash_programmer_CUSTOM_BINPATH
board_utils_uart_flash_programmer_PKG_LIST = board_utils_uart_flash_programmer
board_utils_uart_flash_programmer_INCLUDE = $(board_utils_uart_flash_programmer_PATH)
board_utils_uart_flash_programmer_BOARDLIST = $(board_utils_$(SOC)_BOARDLIST)
export board_utils_uart_flash_programmer_BOARDLIST
board_utils_uart_flash_programmer_$(SOC)_CORELIST = $(board_utils_$(SOC)_CORELIST)
export board_utils_uart_flash_programmer_$(SOC)_CORELIST
board_utils_EXAMPLE_LIST += board_utils_uart_flash_programmer
board_utils_uart_flash_programmer_SBL_IMAGEGEN = yes
export board_utils_uart_flash_programmer_SBL_IMAGEGEN

# Uniflash utils is not supported for any profile
# other than release due to memory constraint
ifneq ($(BUILD_PROFILE), release)
board_utils_EXAMPLE_LIST =
endif # ifneq ($(BUILD_PROFILE), release)

export board_utils_EXAMPLE_LIST

board_utils_component_make_include := 1
endif

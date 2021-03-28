#
# Copyright (c) 2016, Texas Instruments Incorporated
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


PACKAGE_SRCS_COMMON = makefile I2C.h i2c_component.mk \
                      docs/I2C_LLD_SDS.pdf docs/I2C_LLD_SoftwareManifest.html \
                      docs/ReleaseNotes_I2C_LLD.pdf \
                      src/I2C_drv.c src/I2C_drv_log.h src/I2C_osal.h \
                      build/makefile.mk build/makefile_indp.mk build/makefile_profile_indp.mk \
                      build/makefile_profile.mk src/src_files_common.mk

# The following v1 files are all that is shipped with TDA devices
  SRCDIR = . src src/v1
  INCDIR = . src src/v1
  SRCS_COMMON += I2C_drv.c I2C_v1.c
  PACKAGE_SRCS_COMMON += src/v1 soc/I2C_v1.h

# For all non-TDA devices, component contains all source files in library and package
ifneq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex tda3xx dra78x j721e j7200 am65xx))
  SRCDIR += src/v0
  INCDIR += src/v0
  SRCS_COMMON += I2C_v0.c
  PACKAGE_SRCS_COMMON += src/v0 soc/I2C_v0.h
endif

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk

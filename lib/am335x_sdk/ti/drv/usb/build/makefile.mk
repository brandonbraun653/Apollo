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

include $(PDK_INSTALL_PATH)/ti/build/Rules.make
include $(PDK_USB_COMP_PATH)/src/src_files_common.mk

MODULE_NAME = usb

ifeq ($(SOC),$(filter $(SOC), am335x am437x))
    include $(PDK_USB_COMP_PATH)/src/src_files_starterware.mk
endif

ifeq ($(SOC),$(filter $(SOC), am335x omapl137 omapl138 c6748))
    SRCDIR += src/musb
    INCDIR += src/musb
    # Common source files across all platforms and cores
    SRCS_COMMON += musb.c usb_musb.c usb_musb_dcd.c usbhenum_musb.c cppi41dma.c
    PACKAGE_SRCS_COMMON += src/musb
endif

ifeq ($(SOC),$(filter $(SOC), am437x am571x am572x am574x k2g am65xx dra72x dra75x))
    SRCDIR += src/dwc src/xhci
    INCDIR += src/dwc src/xhci
    # Common source files across all platforms and cores
    SRCS_COMMON += usb_xhci_hcd.c usb_dwc_dcd.c usb_dwc.c usbhenum_dwc.c
    PACKAGE_SRCS_COMMON += src/dwc src/xhci
endif


ifeq ($(SOC),$(filter $(SOC), j721e))
    SRCDIR += src/cdn/core_driver/host/src  src/cdn/core_driver/device/src src/cdn/core_driver/common/src  src/cdn
    INCDIR += src/cdn/core_driver/host/include src/cdn/core_driver/host/src  src/xhci
    INCDIR += src/cdn/core_driver/device/include  src/cdn/core_driver/device/src 
    INCDIR += src/cdn/core_driver/common/include src/cdn/core_driver/common/src 
    INCDIR += src/cdn 

    SRCS_COMMON += usb_cdn.c usb_cdn_dcd.c usbhenum_dwc.c 
    SRCS_COMMON += cusbd.c  cusbdma.c  cusbdma_obj_if.c  cusbd_obj_if.c cps.c cusbd_sanity.c cusb_ch9_sanity.c cusbdma_sanity.c list_sanity.c
    SRCS_COMMON += cdn_xhci_sanity.c
    PACKAGE_SRCS_COMMON += src/cdn

#ifeq ($(USE_CDN_XHCI),y)
    SRCS_COMMON += cdn_xhci.c cdn_xhci_obj_if.c xhci_mem_alloc.c
    CFLAGS_LOCAL_COMMON += -DUSE_CDN_XHCI

ifeq ($(CORE),$(filter $(CORE), mpu1_0))
    CFLAGS_LOCAL_COMMON += -DPLATFORM_64_BIT 
endif

ifneq ($(findstring mcu,$(CORE)),)
    # allow unalgined access with the R5 core
    #CFLAGS_LOCAL_COMMON += --unaligned_access=off
endif

#else
#    SRCDIR += src/xhci
#    SRCS_COMMON += usb_xhci_hcd.c 
#    PACKAGE_SRCS_COMMON += src/xhci
#endif

    # cdn's driver xhci_mem_alloc needs this flag
    CFLAGS_LOCAL_COMMON += -DUSBSSP_DEMO_TB
endif


SRCDIR += soc soc/$(SOC)
INCDIR += soc soc/$(SOC)
# Common source files across all platforms and cores
SRCS_COMMON += usb_soc.c usb_wrapper.c
PACKAGE_SRCS_COMMON += soc/$(SOC)

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk edma

ifneq ($(SOC),$(filter $(SOC), omapl137 omapl138 c6748))
CFLAGS_LOCAL_COMMON += $(PDK_CFLAGS)
  ifeq ($(CORE),$(filter $(CORE), a8host a9host a15_0))
    CFLAGS_LOCAL_COMMON += -mno-unaligned-access
  else ifeq ($(CORE),$(filter $(CORE), ipu1_0))
    CFLAGS_LOCAL_COMMON += --unaligned_access=off
  endif
endif

ifeq ($(SOC),$(filter $(SOC), am335x omapl137 omapl138 c6748))
#enable DMA by default for AM3 USB. Other platforms already has DMA
CFLAGS_LOCAL_COMMON += -DDMA_MODE
endif

ifeq ($(BUILD_PROFILE),debug)
ifeq ($(SOC),$(filter $(SOC), am65xx))
#CFLAGS_LOCAL_COMMON += -DUSB3_DEBUG                #this flag enable USB3.0 debug
#CFLAGS_LOCAL_COMMON += -DPRINT_COMPLIANCE_STATUS   #this flag makes the code wait for USB port to get to compliance state
endif
ifeq ($(SOC),$(filter $(SOC), j721e))
CFLAGS_LOCAL_COMMON += -DDEBUG
endif
#CFLAGS_LOCAL_COMMON += -DDEBUG_PRINT_EN            #this flag enable debug prints. Used only with UART in poll mode
endif

# this is to disable the dsb instruction in usb/src/include/hw_types.h
#CFLAGS_LOCAL_COMMON += -DMEM_BARRIER_DISABLE

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ROOTDIR)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk
# Nothing beyond this point

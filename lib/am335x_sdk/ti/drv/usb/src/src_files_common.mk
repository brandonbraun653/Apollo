
SRCDIR = . src src/usb_func/common src/usb_func/device src/usb_func/host src/include src/usb_func/include
INCDIR = . src src/usb_func/common src/usb_func/device src/usb_func/host src/include src/usb_func/include src/musb soc/$(SOC)
# Common source files across all platforms and cores
SRCS_COMMON += usb_drv.c usb_desc.c usbdmsc.c usbdcdesc.c usb_dcd_interface.c usb_dev_dman.c usbhmsc.c usbhscsi.c usbtick.c usbdbulk.c usbdcdc.c

ifeq ($(SOC),$(filter $(SOC), am335x omapl137 omapl138 c6748))
SRCS_COMMON += usbdaudio.c
endif

PACKAGE_SRCS_COMMON = makefile usb_drv.h usb_osal.h usbdaudio.h usbdmsc.h usbhmsc.h usbdbulk.h usb_component.mk \
                      docs/ReleaseNotes_USB_LLD.pdf \
                      src src/include src/usb_func/common src/usb_func/device src/usb_func/host src/usb_func/include \
                      src/usb_drv.c src/src_files_common.mk src/src_files_starterware.mk \
                      build/makefile.mk build/makefile_indp.mk build/makefile_profile.mk \
                      build/makefile_profile_indp.mk \
                      example/common example/ramdisk example/mcasp example/shell example/usb_host example/usb_dev \
                      example/bios/biosMmu.c example/bios/dev_bulk_main.c example/bios/dev_msc_main.c \
                      example/bios/dev_msc_mmcsd.c example/bios/host_msc_main.c example/bios/dev_audio_main.c

CFLAGS_LOCAL_COMMON = -Dgcc

ifeq ($(SOC),$(filter $(SOC), j721e am65xx))
PACKAGE_SRCS_COMMON += example/bios/$(SOC) example/build/$(SOC)
endif

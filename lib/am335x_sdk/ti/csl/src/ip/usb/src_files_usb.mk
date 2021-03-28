
ifeq ($(SOC),$(filter $(SOC), am65xx))
PACKAGE_SRCS_COMMON += cslr_usb.h src/ip/usb/src_files_usb.mk src/ip/usb/V4
INCDIR += . src/ip/usb/V4
endif

ifeq ($(SOC),$(filter $(SOC), j721e am77x))
PACKAGE_SRCS_COMMON += cslr_usb.h src/ip/usb/src_files_usb.mk src/ip/usb/V5
INCDIR += . src/ip/usb/V5
endif

ifeq ($(SOC),$(filter $(SOC), j7200 ))
PACKAGE_SRCS_COMMON += cslr_usb.h src/ip/usb/src_files_usb.mk src/ip/usb/V6
INCDIR += . src/ip/usb/V6
endif

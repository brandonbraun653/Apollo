
ifeq ($(SOC),$(filter $(SOC), tpr12))
PACKAGE_SRCS_COMMON += cslr_sci.h src/ip/sci/src_files_sci.mk src/ip/sci/V0
endif

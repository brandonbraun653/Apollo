
ifeq ($(SOC),$(filter $(SOC), tpr12))
PACKAGE_SRCS_COMMON += cslr_cbuff.h src/ip/cbuff/src_files_cbuff.mk src/ip/cbuff/V0
endif

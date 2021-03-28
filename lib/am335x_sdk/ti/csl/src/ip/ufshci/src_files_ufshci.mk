
ifeq ($(SOC),$(filter $(SOC), j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_ufshci.h cslr_ufshciss.h src/ip/ufshci/src_files_ufshci.mk src/ip/ufshci/V0
INCDIR += src/ip/ufshci/V0
endif

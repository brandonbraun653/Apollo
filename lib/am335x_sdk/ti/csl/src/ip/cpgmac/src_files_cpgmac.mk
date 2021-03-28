
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_cpgmac_sl.h src/ip/cpgmac/src_files_cpgmac.mk src/ip/cpgmac/V0
endif

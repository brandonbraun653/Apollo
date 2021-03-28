
ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e))
  PACKAGE_SRCS_COMMON += csl_cpgmac_sl.h src/ip/emac/src_files_emac.mk src/ip/emac/V5
  SRCDIR += src/ip/emac/V5/priv
  INCDIR += . src/ip/emac/V5
  SRCS_COMMON += csl_cpgmac_sl.c
endif


ifeq ($(SOC),$(filter $(SOC), k2h k2k))

PACKAGE_SRCS_COMMON += cslr_xge_cpsw.h  cslr_xge_cpsw_ss_s.h  cslr_xge_cpxmac_sl.h
PACKAGE_SRCS_COMMON += src/ip/xge/V0/cslr_xge_cpsw.h  src/ip/xge/V0/cslr_xge_cpsw_ss_s.h  src/ip/xge/V0/cslr_xge_cpxmac_sl.h
PACKAGE_SRCS_COMMON += src/ip/vcp2/src_files_xge.mk src/ip/xge/V0
SRCDIR += src/ip/xge/V0
INCDIR += . src/ip/xge/V0
SRCS_COMMON += cslr_xge_cpsw_resetread.c  cslr_xge_cpsw_ss_s_resetread.c  cslr_xge_cpxmac_sl_resetread.c
endif

ifeq ($(SOC),$(filter $(SOC), am65xx j7200 j721e am77x))
PACKAGE_SRCS_COMMON += cslr_xge_cpsw.h cslr_xge_cpsw_ss_s.h
PACKAGE_SRCS_COMMON += src/ip/xge/V4
PACKAGE_SRCS_COMMON += src/ip/xge/src_files_xge.mk
endif

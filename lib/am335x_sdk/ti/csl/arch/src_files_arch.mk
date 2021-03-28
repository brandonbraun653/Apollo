PACKAGE_SRCS_COMMON += arch/csl_arch.h arch/cslr64.h arch/src_files_arch.mk

ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x am571x am572x am574x k2h k2k k2l k2e k2g))
-include $(PDK_CSL_COMP_PATH)/arch/a15/src_files_a15.mk
endif

ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x tda3xx am574x am572x am571x dra78x))
-include $(PDK_CSL_COMP_PATH)/arch/m4/src_files_m4.mk
endif

ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px dra75x tda2ex dra72x tda3xx am574x am572x am571x dra78x k2h k2k k2l k2e k2g am77x j721e tpr12))
-include $(PDK_CSL_COMP_PATH)/arch/c66x/src_files_c66x.mk
endif

ifeq ($(SOC),$(filter $(SOC), tda2xx tda2px tda2ex dra75x dra78x tda3xx am572x am574x))
-include $(PDK_CSL_COMP_PATH)/arch/arp32/src_files_arp32.mk
endif

ifeq ($(SOC),$(filter $(SOC), am65xx am77x j7200 j721e tpr12))
-include $(PDK_CSL_COMP_PATH)/arch/r5/src_files_r5.mk
-include $(PDK_CSL_COMP_PATH)/arch/r5/src_files_r5_vim.mk
-include $(PDK_CSL_COMP_PATH)/arch/r5/src_files_r5_ccmr5.mk
-include $(PDK_CSL_COMP_PATH)/arch/r5/src_files_r5_mpu.mk
-include $(PDK_CSL_COMP_PATH)/arch/r5/src_files_r5_pmu.mk
-include $(PDK_CSL_COMP_PATH)/arch/r5/src_files_r5_hard_err_cache.mk
endif

ifeq ($(SOC),$(filter $(SOC), am65xx))
-include $(PDK_CSL_COMP_PATH)/arch/a53/src_files_a53.mk
endif

ifeq ($(SOC),$(filter $(SOC), j7200 j721e am77x))
# src_files_a53.mk included as placeholder for eventual a72 implementation
-include $(PDK_CSL_COMP_PATH)/arch/a53/src_files_a53.mk
endif

ifeq ($(SOC),$(filter $(SOC), j7200 j721e am77x))
-include $(PDK_CSL_COMP_PATH)/arch/c7x/src_files_c7x.mk
endif

ifeq ($(SOC),$(filter $(SOC), omapl137 omapl138))
-include $(PDK_CSL_COMP_PATH)/arch/arm9/src_files_arm9.mk
-include $(PDK_CSL_COMP_PATH)/arch/c67x/src_files_c67x.mk
endif

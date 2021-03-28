# Source files and CFLAGS across all platforms and cores

SRCDIR += prcm src/pmlib/prcm
INCDIR += prcm src/pmlib/prcm

ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x))
SRCDIR += prcm/V0 src/pmlib/prcm/V0
INCDIR += prcm/V0 src/pmlib/prcm/V0
endif
ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x))
SRCDIR += prcm/V2 src/pmlib/prcm/V2
INCDIR += prcm/V2 src/pmlib/prcm/V2
endif
ifeq ($(SOC),$(filter $(SOC), am335x))
SRCDIR += prcm/V3 src/pmlib/prcm/V3
INCDIR += prcm/V3 src/pmlib/prcm/V3
endif
ifeq ($(SOC),$(filter $(SOC), am437x))
SRCDIR += prcm/V4 src/pmlib/prcm/V4
INCDIR += prcm/V4 src/pmlib/prcm/V4
endif

SRCS_COMMON += pmlib_sysconfig.c pmlib_clkrate.c pmlib_boardconfig.c

ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra7xx tda2ex am571x tda3xx))
SRCS_COMMON += pmlib_videopll_data.c pmlib_videopll.c
endif

SRCS_a15_0 += pmlib_cpuidle_a15host.c
SRCS_ipu1_0 += pmlib_cpuidle_m4.c
SRCS_ipu1_1 += pmlib_cpuidle_m4.c
SRCS_c66x += pmlib_cpuidle_c66x.c
SRCS_arp32_1 += pmlib_cpuidle_arp32.c
SRCS_a8host += pmlib_cpuidle_a8host.c
SRCS_a9host += pmlib_cpuidle_a9host.c

ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x))
SRCS_COMMON +=  pmlib_clk_rate_data_tda2xx.c
endif

ifeq ($(SOC),$(filter $(SOC), tda2ex am571x))
SRCS_COMMON +=  pmlib_clk_rate_data_tda2ex.c
endif

ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x))
SRCS_COMMON +=  pmlib_clk_rate_data_tda3xx.c
endif

ifeq ($(SOC),am335x)
SRCS_COMMON +=  pmlib_clk_rate_data_am335x.c
endif

ifeq ($(SOC),am437x)
SRCS_COMMON +=  pmlib_clk_rate_data_am437x.c
endif

SRCS_ASM_a15_0 += pmlib_cpuidle_utils_a15host.asm
SRCS_ASM_ipu1_0 += pmlib_cpuidle_utils_m4.asm
SRCS_ASM_ipu1_1 += pmlib_cpuidle_utils_m4.asm
SRCS_ASM_a8host += pmlib_cpuidle_utils_a8host.asm
SRCS_ASM_a9host += pmlib_cpuidle_utils_a9host.asm

# Nothing beyond this point

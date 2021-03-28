# Source files and CFLAGS across all platforms and cores

SRCDIR += src/pmrtos/prcm src/pmrtos/common
INCDIR += src/pmrtos/prcm src/pmrtos/common

ifeq ($(SOC),$(filter $(SOC), tda2xx am572x dra75x tda2ex am571x))
SRCDIR += src/pmrtos/prcm/V0
INCDIR += src/pmrtos/prcm/V0
endif
ifeq ($(SOC),$(filter $(SOC), tda3xx dra78x))
SRCDIR += src/pmrtos/prcm/V2
INCDIR += src/pmrtos/prcm/V2
endif
ifeq ($(SOC),$(filter $(SOC), am335x))
SRCDIR += src/pmrtos/prcm/V3
INCDIR += src/pmrtos/prcm/V3
endif
ifeq ($(SOC),$(filter $(SOC), am437x))
SRCDIR += src/pmrtos/prcm/V4
INCDIR += src/pmrtos/prcm/V4
endif

SRCS_COMMON += List.c PowerDevice.c PowerDevice_tirtos.c

ifeq ($(SOC),$(filter $(SOC), tda3xx tda2xx am572x dra75x tda2ex am571x dra78x am335x am437x))
SRCS_COMMON += PowerPRCM_deviceInit.c PowerPRCM_dpll.c
endif

# Nothing beyond this point

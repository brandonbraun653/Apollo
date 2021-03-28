# Source files and CFLAGS across all platforms and cores

SRCDIR += src/pmrtos/pmmc src/pmrtos/common
INCDIR += src/pmrtos/pmmc src/pmrtos/common

ifeq ($(SOC),$(filter $(SOC), k2g))
SRCDIR += src/pmrtos/pmmc/V0
INCDIR += src/pmrtos/pmmc/V0
endif

SRCS_COMMON += List.c PowerDevice.c PowerDevice_tirtos.c

ifeq ($(SOC),$(filter $(SOC), k2g))
SRCS_COMMON += PowerPMMC_deviceInit.c
endif

# Nothing beyond this point

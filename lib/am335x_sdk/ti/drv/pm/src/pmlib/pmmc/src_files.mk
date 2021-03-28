# Source files and CFLAGS across all platforms and cores

SRCDIR += pmmc src/pmlib/pmmc
INCDIR += pmmc src/pmlib/pmmc

SRCS_COMMON += pmlib_sysconfig.c pmlib_clkrate.c

SRCS_a15_0 += pmlib_cpuidle_a15host.c
SRCS_c66x += pmlib_cpuidle_c66x.c

SRCS_ASM_a15_0 += pmlib_cpuidle_utils_a15host.asm

# Nothing beyond this point

SRCDIR += src src/v6
INCDIR += src src/v6

INCDIR += $(bios_PATH)/packages/ti/posix/ccs

# Common source files across all platforms and cores
SRCS_COMMON += nimu_eth.c

PACKAGE_SRCS_COMMON += src/v6/ src/v6/nimu_eth.h src/v6/nimu_eth.c

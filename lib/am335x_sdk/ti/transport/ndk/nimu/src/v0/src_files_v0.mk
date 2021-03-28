SRCDIR += src src/v0
INCDIR += src src/v0

ifeq ($(CORE),$(filter $(CORE), c66x))
INCDIR += $(bios_PATH)/packages/ti/posix/ccs
endif 

# Common source files across all platforms and cores
SRCS_COMMON += nimu_eth.c

PACKAGE_SRCS_COMMON += src/v0/ src/v0/nimu_eth.h src/v0/nimu_eth.c

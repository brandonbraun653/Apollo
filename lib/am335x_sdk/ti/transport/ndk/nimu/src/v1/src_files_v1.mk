SRCDIR += src src/v1
INCDIR += src src/v1

ifeq ($(CORE),$(filter $(CORE), c66x))
INCDIR += $(bios_PATH)/packages/ti/posix/ccs
endif 

# Common source files across all platforms and cores
SRCS_COMMON += nimu_eth.c

PACKAGE_SRCS_COMMON += src/v1/ src/v1/nimu_eth.h src/v1/nimu_eth.c src/v1/nimu_internal.h

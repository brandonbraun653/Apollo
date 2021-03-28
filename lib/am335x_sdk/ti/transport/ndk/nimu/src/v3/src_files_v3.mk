SRCDIR += src src/v3
INCDIR += src src/v3
ifeq ($(CORE),$(filter $(CORE), c66x))
INCDIR += $(bios_PATH)/packages/ti/posix/ccs
endif 
# Common source files across all platforms and cores
SRCS_COMMON += nimu_eth.c

PACKAGE_SRCS_COMMON += src/v3/ src/v3/nimu_eth.h src/v3/nimu_eth.c src/v3/nimu_internal.h

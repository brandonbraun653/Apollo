SRCDIR += src src/v2
INCDIR += src src/v2
ifeq ($(CORE),$(filter $(CORE), c66x))
INCDIR += $(bios_PATH)/packages/ti/posix/ccs
endif 
# Common source files across all platforms and cores
SRCS_COMMON += nimu_eth.c

PACKAGE_SRCS_COMMON += src/v2/ src/v2/nimu_eth.h src/v2/nimu_eth.c src/v2/nimu_internal.h

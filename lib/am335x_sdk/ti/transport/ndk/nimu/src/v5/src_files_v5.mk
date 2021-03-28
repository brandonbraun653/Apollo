SRCDIR += src src/v5
INCDIR += src src/v5
ifeq ($(CORE),$(filter $(CORE), c66x))
INCDIR += $(bios_PATH)/packages/ti/posix/ccs
endif 
# Common source files across all platforms and cores
SRCS_COMMON += nimu_eth.c

PACKAGE_SRCS_COMMON += src/v5/ src/v5/nimu_eth.h src/v5/nimu_eth.c src/v5/nimu_internal.h

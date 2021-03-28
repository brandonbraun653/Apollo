SRCDIR += src src/v7
INCDIR += src src/v7


ifeq ($(CORE),$(filter $(CORE), mcu1_0 mcu1_1 mcu2_0 mcu2_1))
INCDIR += $(bios_PATH)/packages/ti/posix/ccs
endif 

INCDIR += $(bios_PATH)/packages

# Common source files across all platforms and cores
SRCS_COMMON += nimu_eth.c

ifeq ($(CORE),$(filter $(CORE), mpu1_0 mpu1_1 mpu2_0 mpu2_1))
CFLAGS_LOCAL_COMMON += -std=c99
endif
PACKAGE_SRCS_COMMON += src/v7/nimu_eth.h \
			src/v7/nimu_eth.c \
			build/makefile.mk \
			build/makefile_profile.mk \
			build/makefile_icssg.mk \
			build/makefile_icssg_profile.mk \
			src/v7/src_files_v7.mk


SRCDIR = . src/tirtos src/common arch/core
INCDIR = . src/tirtos

SRCS_COMMON += Core_utils.c SemaphoreP_tirtos.c HwiP_tirtos.c SwiP_tirtos.c Utils_tirtos.c CacheP_tirtos.c RegisterIntr_tirtos.c EventCombinerP_tirtos.c Queue_tirtos.c EventP_tirtos.c TaskP_tirtos.c

ifeq ($(SOC),$(filter $(SOC), am574x am572x am571x k2g k2l k2e k2h k2k c6678 c6657 am437x am335x omapl137 omapl138 c6747 am65xx j721e j7200))
SRCS_COMMON += TimerP_tirtos.c
endif

ifeq ($(SOC),$(filter $(SOC), tpr12))
  SRCS_COMMON += TimerP_tirtos.c CycleprofilerP_tirtos.c MemoryP_tirtos.c
endif

ifeq ($(ISA),$(filter $(ISA), a53 a72 c7x))
  SRCDIR += soc/$(SOC)
  SRCS_COMMON += bios_mmu.c
endif

PACKAGE_SRCS_COMMON = makefile HwiP.h SwiP.h MuxIntcP.h osal.h osal_component.mk SemaphoreP.h MemoryP.h CycleprofilerP.h \
                      CacheP.h EventCombinerP.h EventP.h Queue.h RegisterIntr.h TaskP.h TimerP.h soc/$(SOC) soc/osal_soc.h \
                      src/tirtos/CacheP_tirtos.c src/tirtos/CycleprofilerP_tirtos.c src/tirtos/EventCombinerP_tirtos.c \
                      src/tirtos/EventP_tirtos.c src/tirtos/HwiP_tirtos.c src/tirtos/SwiP_tirtos.c src/tirtos/MemoryP_tirtos.c \
                      src/tirtos/Queue_tirtos.c src/tirtos/RegisterIntr_tirtos.c src/tirtos/SemaphoreP_tirtos.c src/tirtos/TaskP_tirtos.c \
                      src/tirtos/TimerP_tirtos.c src/tirtos/Utils_tirtos.c src/tirtos/tirtos_config.h src/src_common_tirtos.mk \
                      docs/OSAL_SoftwareManifest.html docs/ReleaseNotes_OSAL.pdf build/makefile_tirtos_indp.mk build/makefile_tirtos.mk


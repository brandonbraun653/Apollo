ifeq ($(BOARD),$(filter $(BOARD), j721e_evm j7200_evm))
SRCDIR += src/devices/audio src/devices/combos src/devices/common src/devices/fpd src/devices/sensors src/devices/pmic
INCDIR += src/devices/audio src/devices/combos src/devices/common src/devices/fpd src/devices/sensors src/devices/pmic

SRCS_COMMON += common.c ds90ub953.c ds90ub960.c imx390.c pcm3168A.c ds90ub924.c ds90ub941.c ds90ub9xx_tlc59108.c tlc59108.c ds90ub925.c ds90ub926.c ds90ub9702.c afe8310.c ds90ub92x_afe8310.c tps65941.c
endif

ifeq ($(BOARD),$(filter $(BOARD), am65xx_evm am65xx_idk))
SRCDIR += src/devices/common src/devices/pmic
INCDIR += src/devices/common src/devices/pmic

SRCS_COMMON += common.c tps62363.c
endif

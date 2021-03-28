# Common source files and CFLAGS across all platforms and cores

SRCDIR += pmmc src/pmhal/pmmc
INCDIR += pmmc src/pmhal/pmmc

ifeq ($(SOC),$(filter $(SOC), k2g))
SRCS_COMMON +=  pmhal_pmmc.c pmhal_msgmgr.c
endif

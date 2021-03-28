
ifeq ($(SOC),$(filter $(SOC), j7200 j721e am77x))
# CSI-TX has compilation errors in host emulation build. This is not required in host emu. Hence disable
ifneq ($(CORE),$(filter $(CORE), c7x-hostemu))
PACKAGE_SRCS_COMMON += cslr_csitx.h csl_csitx.h src/ip/csitx/src_files_csitx.mk src/ip/csitx/V0
SRCDIR += src/ip/csitx/V0/priv
INCDIR += src/ip/csitx/V0 src/ip/csitx/V0/priv
SRCS_COMMON += csitx_sanity.c csitx.c csitx_ss.c
endif
endif

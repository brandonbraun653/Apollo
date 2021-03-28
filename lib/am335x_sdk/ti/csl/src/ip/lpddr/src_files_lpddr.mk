
ifeq ($(SOC),$(filter $(SOC), j7200 j721e))
# lpaddr has compilation errors in host emulation build. This is not required in host emu. Hence disable
  ifneq ($(CORE),$(filter $(CORE), c7x-hostemu))
    PACKAGE_SRCS_COMMON += cslr_lpddr.h csl_lpddr.h src/ip/lpddr/src_files_lpddr.mk src/ip/lpddr/V0
    SRCDIR += src/ip/lpddr/V0/priv
    INCDIR += src/ip/lpddr/V0 src/ip/lpddr/V0/priv
    SRCS_COMMON += lpddr4.c lpddr4_ctl_regs_rw_masks.c lpddr4_obj_if.c
  endif
endif

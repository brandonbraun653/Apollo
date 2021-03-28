# Filename: rules_a9.mk
#
# Make rules for A9 - This file has all the common rules and defines required
#                     for Cortex-A9 ISA
#
# This file needs to change when:
#     1. Code generation tool chain changes (This file uses TMS470)
#     2. Internal switches (which are normally not touched) has to change
#     3. XDC specific switches change
#     4. a rule common for A9 ISA has to be added or modified
# Set compiler/archiver/linker commands and include paths
# Defining the cross compiler tool prefix
#
#
# Copyright (C) 2013-2018 Texas Instruments Incorporated - http://www.ti.com/
#
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
#    Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the
#    distribution.
#
#    Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#******************************************************************************


ifndef PREFIX
PREFIX=arm-none-eabi-
endif

CODEGEN_INCLUDE = $(TOOLCHAIN_PATH_A9)/arm-non-eabi/include $(TOOLCHAIN_PATH_A9)/arm-none-eabi/include/newlib-nano
CC = $(TOOLCHAIN_PATH_A9)/bin/${PREFIX}gcc
AR = $(TOOLCHAIN_PATH_A9)/bin/${PREFIX}ar
LNK = $(TOOLCHAIN_PATH_A9)/bin/${PREFIX}ld
BIN = $(TOOLCHAIN_PATH_A9)/bin/${PREFIX}objcopy

# Derive a part of RTS Library name based on ENDIAN: little/big
ifeq ($(ENDIAN),little)
  RTSLIB_ENDIAN = le
else
  RTSLIB_ENDIAN = be
endif

# Derive compiler switch and part of RTS Library name based on FORMAT: COFF/ELF
ifeq ($(FORMAT),ELF)
  RTSLIB_FORMAT = eabi
endif

# Internal CFLAGS - normally doesn't change
CFLAGS_INTERNAL = -c -mcpu=cortex-a9 -mtune=cortex-a9 -march=armv7-a -mfpu=neon -mfloat-abi=hard -eo.$(OBJEXT) -ea.$(ASMEXT) -mlong-calls -fdata-sections -funsigned-char -ffunction-sections -Wall -Dgcc -Darmv7a -D SUPPORT_UNALIGNED -MD -MF $(DEPFILE).P -D $(CONSOLE)
CFLAGS_DIROPTS =

#
#  rdimon runtime library linker option for semiHosting support
#
ifeq ($(CONSOLE), SEMIHOSTING)
CFLAGS_INTERNAL +=--specs=rdimon.specs -DSEMIHOSTING
endif

# CFLAGS based on profile selected
ifeq ($(PROFILE_$(CORE)), debug)
 LNKFLAGS_INTERNAL_PROFILE =
 CFLAGS_INTERNAL += -D_DEBUG_=1 -g
endif
ifeq ($(PROFILE_$(CORE)), release)
 LNKFLAGS_INTERNAL_PROFILE =
 CFLAGS_INTERNAL += -O2
endif

ifeq ($(RTOS_BUILD), yes)
  CFLAGS_INTERNAL += -DRTOS_BUILD
endif

# Following 'if...' block is for an application; to add a #define for each
#   component in the build. This is required to know - at compile time - which
#   components are on which core.
ifndef MODULE_NAME
  # Derive list of all packages from each of the components needed by the app
  PKG_LIST_A9_LOCAL = $(foreach COMP,$(COMP_LIST_$(CORE)),$($(COMP)_PKG_LIST))

  # Defines for the app and cfg source code to know which components/packages
  # are included in the build for the local CORE...
  CFLAGS_APP_DEFINES = $(foreach PKG,$(PKG_LIST_A9_LOCAL),-D_LOCAL_$(PKG)_)
  CFLAGS_APP_DEFINES += $(foreach PKG,$(PKG_LIST_A9_LOCAL),-D_BUILD_$(PKG)_)

  ifeq ($(CORE),a9host)
    PKG_LIST_REMOTE = $(foreach COMP,$(COMP_LIST_m3video),$($(COMP)_PKG_LIST))
    PKG_LIST_REMOTE += $(foreach COMP,$(COMP_LIST_m3vpss),$($(COMP)_PKG_LIST))
    CFLAGS_APP_DEFINES += -D_LOCAL_CORE_a9host_
  endif

  # Defines for the app and cfg source code to know which components/packages
  # are included in the build for the remote CORE...
  CFLAGS_APP_DEFINES += $(foreach PKG,$(PKG_LIST_REMOTE),-D_REMOTE_$(PKG)_)
  CFLAGS_APP_DEFINES += $(foreach PKG,$(PKG_LIST_REMOTE),-D_BUILD_$(PKG)_)
endif

# Assemble CFLAGS from all other CFLAGS definitions
_CFLAGS = $(CFLAGS_INTERNAL) $(CFLAGS_GLOBAL_$(CORE)) $(CFLAGS_LOCAL_COMMON) $(CFLAGS_LOCAL_$(CORE)) $(CFLAGS_LOCAL_$(PLATFORM)) $(CFLAGS_LOCAL_$(SOCFAMILY)) $(CFLAGS_LOCAL_$(SOC)) $(CFLAGS_APP_DEFINES) $(CFLAGS_COMP_COMMON) $(CFLAGS_GLOBAL_$(PLATFORM)) $(STARTERWARE_CFLAGS)

# Decide the compile mode
COMPILEMODE = -x c
ifeq ($(CPLUSPLUS_BUILD), yes)
  COMPILEMODE = -x c++ -Wno-narrowing -Wno-sign-compare -fpermissive
endif

INCLUDES += -I$(TOOLCHAIN_PATH_A9)/arm-non-eabi/include
INCLUDES += -I$(TOOLCHAIN_PATH_A9)/arm-none-eabi/include/newlib-nano
# Object file creation
# The $(CC) compiles the source to generate object
$(OBJ_PATHS): $(OBJDIR)/%$(LIB_SUFFIX).$(OBJEXT): %.c
	$(ECHO) \# Compiling $(PLATFORM):$(CORE):$(PROFILE_$(CORE)):$(APP_NAME)$(MODULE_NAME): $<
	$(CC) $(_CFLAGS) $(INCLUDES) $(CFLAGS_DIROPTS) $(COMPILEMODE) -o $(OBJDIR)/$(basename $(notdir $<))$(LIB_SUFFIX).$(OBJEXT) $<

# Object file creation for assembly files
$(OBJ_PATHS_ASM): $(OBJDIR)/%$(LIB_SUFFIX).$(ASMEXT): %.S
	$(ECHO) \# Compiling $(PLATFORM):$(CORE):$(PROFILE_$(CORE)):$(APP_NAME)$(MODULE_NAME): $<
	$(CC) $(_CFLAGS) $(INCLUDES) $(CFLAGS_DIROPTS) -o $(OBJDIR)/$(basename $(notdir $<))$(LIB_SUFFIX).$(OBJEXT) $<

$(PACKAGE_PATHS): $(PACKAGEDIR)/%: %
	$(ECHO) \# Copying $(PACKAGE_NAME)/$($(MODULE_NAME)_RELPATH)/$<
	$(MKDIR) -p $(DEST_ROOT)/package/$(PACKAGE_SELECT)/$(PACKAGE_NAME)/$($(MODULE_NAME)_RELPATH)
	$(CP) --parents -rf $< $(DEST_ROOT)/package/$(PACKAGE_SELECT)/$(PACKAGE_NAME)/$($(MODULE_NAME)_RELPATH)

# Archive flags - normally doesn't change
ARFLAGS = -c -r

# Archive/library file creation
$(LIBDIR)/$(addprefix lib,$(MODULE_NAME))$(LIB_SUFFIX).$(LIBEXT) : $(OBJ_PATHS_ASM) $(OBJ_PATHS)
	$(ECHO) \#
	$(ECHO) \# Archiving $(PLATFORM):$(CORE):$(PROFILE_$(CORE)):$(MODULE_NAME)$(LIB_SUFFIX)
	$(ECHO) \#
	$(AR) $(ARFLAGS) $@ $(OBJ_PATHS_ASM) $(OBJ_PATHS)

# Linker options and rules
LNKFLAGS_INTERNAL_COMMON = -e Entry -u Entry -u __aeabi_uidiv -u __aeabi_idiv -Wl,--gc-sections --specs=nano.specs
# Assemble Linker flags from all other LNKFLAGS definitions
_LNKFLAGS = $(LNKFLAGS_INTERNAL_COMMON) $(LNKFLAGS_INTERNAL_PROFILE) $(LNKFLAGS_GLOBAL_$(CORE)) $(LNKFLAGS_LOCAL_COMMON) $(LNKFLAGS_LOCAL_$(CORE))

#LIB_PATHS += $(EXT_LIB_PATH_COMMON)
#LIB_PATHS += $(EXT_LIB_PATH_a9host)
LIB_PATHS += $(TOOLCHAIN_PATH_A9)/arm-none-eabi/lib/hard
LIB_PATHS += $(TOOLCHAIN_PATH_A9)/arm-none-eabi/lib/hard/libc_nano.a $(TOOLCHAIN_PATH_A9)/arm-none-eabi/lib/hard/libm.a  $(TOOLCHAIN_PATH_A9)/arm-none-eabi/lib/hard/librdimon_nano.a $(TOOLCHAIN_PATH_A9)/arm-none-eabi/lib/hard/libg_nano.a

LNK_LIB_PATHS =  $(foreach LIB_PATH,$(LIB_PATHS),$(addprefix -L,$(LIB_PATH)))
LNK_LIBS =  $(foreach LIB,$(LIBS),$(addprefix -l,$(LIB)))

#
#  rdimon runtime library linker option for semiHosting support
#
ifeq ($(CONSOLE), SEMIHOSTING)
LNK_LIBS += -lc -lgcc -lrdimon
endif

LNK_LIBS += -lstdc++ -lgcc -lm -lc -lrdimon

# Linker - to create executable file

ifeq ($(LOCAL_APP_NAME),)
 EXE_NAME = $(BINDIR)/$(APP_NAME)$(EXE_SUFFIX)_$(CORE)_$(PROFILE_$(CORE)).$(EXEEXT)
else
 ifeq ($(PROFILE_$(CORE)),prod_release)
  EXE_NAME = $(BINDIR)/$(LOCAL_APP_NAME)$(EXE_SUFFIX).$(EXEEXT)
 else
  EXE_NAME = $(BINDIR)/$(LOCAL_APP_NAME)$(EXE_SUFFIX)_$(PROFILE_$(CORE)).$(EXEEXT)
 endif
endif

$(EXE_NAME) : $(OBJ_PATHS_ASM) $(OBJ_PATHS) $(LIB_PATHS) $(LNKCMD_FILE)
	$(ECHO) \# Linking into $(EXE_NAME)...
	$(ECHO) \#
	$(CC) -mfloat-abi=hard $(_LNKFLAGS) $(LNK_LIB_PATHS) $(OBJ_PATHS_ASM) $(OBJ_PATHS) -Wl,-T $(LNKCMD_FILE) -o $@  -Wl,--start-group $(LNK_LIBS) -Wl,--end-group -Wl,-Map=$@.map
	$(ECHO) \# $@ created.
	$(ECHO) \#

# Binary - to create binary file

#
# Binary options
#
BINFLAGS_INTERNAL_COMMON =-O binary

# Binary Flags
_BINFLAGS = $(BINFLAGS_INTERNAL_COMMON)

ifeq ($(LOCAL_APP_NAME),)
 BIN_NAME = $(BINDIR)/$(APP_NAME)$(EXE_SUFFIX)_$(CORE)_$(PROFILE_$(CORE)).$(BINEXT)
 ifeq ($(SECUREMODE), yes)
   SIGNED_BIN_NAME = $(BINDIR)/$(APP_NAME)$(EXE_SUFFIX)_$(CORE)_$(PROFILE_$(CORE))_signed.$(BINEXT)
 endif
else
 ifeq ($(PROFILE_$(CORE)),prod_release)
  BIN_NAME = $(BINDIR)/$(LOCAL_APP_NAME)$(EXE_SUFFIX).$(BINEXT)
 else
  BIN_NAME = $(BINDIR)/$(LOCAL_APP_NAME)$(EXE_SUFFIX)_$(PROFILE_$(CORE)).$(BINEXT)

  ifeq ($(SECUREMODE), yes)
    SIGNED_BIN_NAME = $(BINDIR)/$(LOCAL_APP_NAME)$(EXE_SUFFIX)_$(PROFILE_$(CORE))_signed.$(BINEXT)
  endif
 endif
endif

$(BIN_NAME) : $(EXE_NAME)
	$(ECHO) \# Generating $(BIN_NAME)...
	$(BIN) $(_BINFLAGS) $(EXE_NAME) $@
ifeq ($(SECUREMODE), yes)
 ifeq ($(BUILDCFG), boot) 
  ifeq ($(TI_SECURE_DEV_PKG),)
	$(ECHO) "TI_SECURE_DEV_PKG not defined. Please set it to your SECDEV location"
  else
	$(TI_SECURE_DEV_PKG)/scripts/create-boot-image.sh ISSW $(BIN_NAME) $(SIGNED_BIN_NAME) 0x403018e0
  endif
 endif
endif 
	$(ECHO) \# $@ created.
	$(ECHO) \#

# TI Binary - to create binary file

#
# TI Binary options
#
ifneq ($(BOOTMODE),)
 IMG_LOAD_TYPE = $(BOOTMODE)
else # ifneq ($(BOOTMODE),)
 IMG_LOAD_TYPE = NONE
endif # ifneq ($(BOOTMODE),)

ifeq ($(LOCAL_APP_NAME),)
 TIBIN_NAME = $(BINDIR)/$(APP_NAME)$(EXE_SUFFIX)_$(CORE)_$(PROFILE_$(CORE))_ti.$(BINEXT)
else
 ifeq ($(PROFILE_$(CORE)),prod_release)
  TIBIN_NAME = $(BINDIR)/$(LOCAL_APP_NAME)$(EXE_SUFFIX)_ti.$(BINEXT)
 else
  TIBIN_NAME = $(BINDIR)/$(LOCAL_APP_NAME)$(EXE_SUFFIX)_$(PROFILE_$(CORE))_ti.$(BINEXT)
 endif
endif

ifeq ($(OS),Windows_NT)
  TIIMAGE_EXE = tiimage.exe
else
  TIIMAGE_EXE = tiimage.out
endif

$(TIBIN_NAME) : $(BIN_NAME)
	$(ECHO) \# Generating $(TIBIN_NAME)...
ifneq ($(OS),Windows_NT)
	cd $(starterware_PATH)/tools/ti_image/; gcc tiimage.c -o $(TIIMAGE_EXE); cd -
endif
	$(starterware_PATH)/tools/ti_image/$(TIIMAGE_EXE) $(IMG_LOAD_ADDR) $(IMG_LOAD_TYPE) $(BIN_NAME) $(TIBIN_NAME)
	$(ECHO) \# $@ created.
	$(ECHO) \#
ifneq ($(OS),Windows_NT)
	rm -rf $(starterware_PATH)/tools/ti_image/$(TIIMAGE_EXE)
endif

# Include dependency make files that were generated by $(CC)
-include $(SRCS:%.c=$(DEPDIR)/%.P)

# Nothing beyond this point

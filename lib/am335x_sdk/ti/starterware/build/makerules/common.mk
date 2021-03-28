# Filename: common.mk
#
# Common make file - This file has common rules and definitions that are common
#                    across platforms/cores/ISAs/SoCs
#
# This file needs to change when:
#     1. common rule/define has to be added or modified
#
#
# Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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


#
# Include make paths and options for all supported targets/platforms
#

include $(STARTERWARE_ROOTDIR)/build/makerules/build_config.mk
include $(STARTERWARE_ROOTDIR)/build/makerules/env.mk
include $(STARTERWARE_ROOTDIR)/build/makerules/component.mk

#.DEFAULT_GOAL := all

.PHONY : all clean gendirs
all : $(CORE)

# Define directories that are going to be created as a part of build process
ifdef MODULE_NAME
  ifeq ($($(MODULE_NAME)_PLATFORM_DEPENDENCY),yes)
    ifeq ($($(MODULE_NAME)_CORE_DEPENDENCY),yes)
      DEPENDENCY_SUB_PATH = $(PLATFORM)/$(CORE)
    else
      DEPENDENCY_SUB_PATH = $(PLATFORM)/$(ISA)
    endif
  else
    ifeq ($($(MODULE_NAME)_CORE_DEPENDENCY),yes)
      DEPENDENCY_SUB_PATH = $(CORE)
    else
      DEPENDENCY_SUB_PATH = $(ISA)
    endif
  endif
endif

ifeq ($(DEST_ROOT),)
 ifdef MODULE_NAME
  OBJDIR = obj/$(DEPENDENCY_SUB_PATH)/$(PROFILE_$(CORE))/gcc
  LIBDIR = lib/$(DEPENDENCY_SUB_PATH)/$(PROFILE_$(CORE))/gcc
 else
  ifeq ($(BUILDCFG),boot)
   OBJDIR = obj/$(PLATFORM)/$(CORE)/$(PROFILE_$(CORE))/gcc/$(BUILDCFG)_$(BOOTMODE)
  else
   OBJDIR = obj/$(PLATFORM)/$(CORE)/$(PROFILE_$(CORE))/gcc
  endif
  BINDIR = bin/$(PLATFORM)/gcc
 endif
  PACKAGEDIR = package/$(DEPENDENCY_SUB_PATH)/$(PACKAGE_SELECT)/gcc
else
  ifdef MODULE_NAME
   OBJDIR = $(DEST_ROOT)/$($(MODULE_NAME)_RELPATH)/obj/$(DEPENDENCY_SUB_PATH)/$(PROFILE_$(CORE))/gcc
   LIBDIR = $(DEST_ROOT)/$($(MODULE_NAME)_RELPATH)/lib/$(DEPENDENCY_SUB_PATH)/$(PROFILE_$(CORE))/gcc
  else
   ifeq ($(BUILDCFG),boot)
    OBJDIR = $(DEST_ROOT)/$(APP_NAME)/obj/$(PLATFORM)/$(CORE)/$(PROFILE_$(CORE))/gcc/$(BUILDCFG)_$(BOOTMODE)
   else
    OBJDIR = $(DEST_ROOT)/$(APP_NAME)/obj/$(PLATFORM)/$(CORE)/$(PROFILE_$(CORE))/gcc
   endif
   BINDIR = $(DEST_ROOT)/$(APP_NAME)/bin/$(PLATFORM)/gcc
  endif
  PACKAGEDIR = $(DEST_ROOT)/package/$(PACKAGE_SELECT)/gcc
endif
DEPDIR = $(OBJDIR)/.deps
DEPFILE = $(DEPDIR)/$(*F)

# Create directories
$(OBJDIR) :
	$(MKDIR) -p $(OBJDIR)

$(DEPDIR) :
	$(MKDIR) -p $(DEPDIR)

$(LIBDIR) :
	$(MKDIR) -p $(LIBDIR)

$(BINDIR) :
	$(MKDIR) -p $(BINDIR)

$(PACKAGEDIR) :
	$(MKDIR) -p $(PACKAGEDIR)

#
# Common variables
#

# Assemble list of source file names

SRCS = $(SRCS_COMMON) $(SRCS_$(CORE)) $(SRCS_$(SOCFAMILY))
SRCS_ASM = $(SRCS_ASM_COMMON) $(SRCS_ASM_$(CORE)) $(SRCS_ASM_$(SOCFAMILY))

ifneq ($(SOCFAMILY),$(PLATFORM))
SRCS += $(SRCS_$(PLATFORM))
SRCS_ASM += $(SRCS_ASM_$(PLATFORM))
endif #ifneq ($(SOCFAMILY,$(PLATFORM))

ifneq ($(SOC),$(SOCFAMILY))
SRCS += $(SRCS_$(SOC))
SRCS_ASM += $(SRCS_ASM_$(SOC))
endif #ifneq ($(SOC),$(SOCFAMILY))

PACKAGE_SRCS = $(PACKAGE_SRCS_COMMON)

# Define search paths
VPATH = $(SRCDIR)

# Following 'if...' block is for an application.
ifndef MODULE_NAME
  # Derive list of all packages from each of the components needed by the app
  PKG_LIST = $(foreach COMP,$(COMP_LIST_COMMON),$($(COMP)_PKG_LIST))
  PKG_LIST += $(foreach COMP,$(COMP_LIST_$(CORE)),$($(COMP)_PKG_LIST))


  # For each of the packages (or modules), get a list of source files that are
  # marked to be compiled in app stage of the build (or in the context in the app)
  SRCS_APPSTG_FILES = $(foreach PKG, $(PKG_LIST), $($(PKG)_APP_STAGE_FILES))
  # The app has to compile package cfg source files in its context. The name
  # of the file assumed is <MOD>_cfg.c under the top-level directory - i.e.
  # specified by <MOD>_PATH variable
  #SRCS_CFG = $(addsuffix _cfg.c,$(PKG_LIST))
  SRCS += $(SRCS_APPSTG_FILES)
  PKG_PATHS = $(foreach PKG,$(PKG_LIST),$($(PKG)_PATH))
  VPATH += $(PKG_PATHS)

  export PKG_LIST
endif

# Change the extension from C to $(OBJEXT) and also add path
ACT_OBJ_PATHS = $(patsubst %.c, $(OBJDIR)/%.$(OBJEXT), $(SRCS))

# Change the extension from ASM to $(ASMEXT) and also add path
ACT_OBJ_PATHS_ASM = $(patsubst %.S, $(OBJDIR)/%.$(ASMEXT), $(SRCS_ASM))

PACKAGE_PATHS = $(patsubst %, $(PACKAGEDIR)/%, $(PACKAGE_SRCS))

# BUILDCFG specific suffix
ifneq ($(BUILDCFG), all)
    LIB_SUFFIX = _$(BUILDCFG)

    # BOOTMODE specific suffix
    ifeq ($(BOOTMODE), )
        EXE_SUFFIX = _$(BUILDCFG)
    else # ifneq ($(BOOTMODE), )
		ifeq ($(USE_DDR), no)
			EXE_SUFFIX = _$(BUILDCFG)_$(BOOTMODE)_noDDR
		else
			EXE_SUFFIX = _$(BUILDCFG)_$(BOOTMODE)
		endif
    endif # ifneq ($(BOOTMODE), )
endif # ifneq ($(BUILDCFG), all)

# Change the extension from C to $(OBJEXT) and also add path
OBJ_PATHS = $(patsubst %.c, $(OBJDIR)/%$(LIB_SUFFIX).$(OBJEXT), $(SRCS))

# Change the extension from ASM to $(ASMEXT) and also add path
OBJ_PATHS_ASM = $(patsubst %.S, $(OBJDIR)/%$(LIB_SUFFIX).$(ASMEXT), $(SRCS_ASM))

# Assemble include paths here
INCLUDE_EXTERNAL = $(foreach INCL,$(INCLUDE_EXTERNAL_INTERFACES),$($(INCL)_INCLUDE))
INCLUDE_INTERNAL = $(foreach INCL,$(INCLUDE_INTERNAL_INTERFACES),$($(INCL)_INCLUDE))
INCLUDE_ALL = $(CODEGEN_INCLUDE) $(INCDIR) $(INCLUDE_EXTERNAL) $(INCLUDE_INTERNAL)

# Add prefix "-I" to each of the include paths in INCLUDE_ALL
INCLUDES = $(addprefix -I,$(INCLUDE_ALL))

# Create rule to "make" all packages
.PHONY : $(PKG_LIST)
$(PKG_LIST) :
	$(ECHO) \# Making $(PLATFORM):$(CORE):$(PROFILE_$(CORE)):$@...
	$(MAKE) -C $($@_PATH)

# Get libraries for all the packages
# LIBS = $(foreach LIB,$(PKG_LIST),$(LIB).$(LIBEXT))
define GET_COMP_DEPENDENCY_SUB_PATH
  ifeq ($$($(1)_PLATFORM_DEPENDENCY),yes)
    ifeq ($$($(1)_CORE_DEPENDENCY),yes)
      $(1)_DEPSUBPATH = $(PLATFORM)/$(CORE)
    else
      $(1)_DEPSUBPATH = $(PLATFORM)/$(ISA)
    endif
   else
    ifeq ($$($(1)_CORE_DEPENDENCY),yes)
      $(1)_DEPSUBPATH = $(CORE)
    else
      $(1)_DEPSUBPATH = $(ISA)
    endif
  endif
endef

$(foreach LIB,$(PKG_LIST),$(eval $(call GET_COMP_DEPENDENCY_SUB_PATH,$(LIB))))

ifeq ($(DEST_ROOT),)
   LIB_PATHS = $(foreach LIB,$(PKG_LIST),$($(LIB)_PATH)/lib/$($(LIB)_DEPSUBPATH)/$(PROFILE_$(CORE)))
else
   LIB_PATHS = $(foreach LIB,$(PKG_LIST),$(DEST_ROOT)/$($(LIB)_RELPATH)/lib/$($(LIB)_DEPSUBPATH)/$(PROFILE_$(CORE))/gcc)
endif

LIBS = $(foreach LIB,$(PKG_LIST),$(LIB)$(LIB_SUFFIX))

# Include make rules for ISA that is built in this iteration
#   eg: rules_a8host.mk
include $(STARTERWARE_ROOTDIR)/build/makerules/rules_$(ISA).mk
package : $(PACKAGE_PATHS)

ifdef MODULE_NAME
# Rules for module; this iteration is for a module

# Clean Object and Library (archive) directories
clean :
	$(RM) -f $(OBJDIR)/* $(DEPDIR)/* $(LIBDIR)/*

# Create dependencies list to ultimately create module archive library file
$(CORE) : $(OBJDIR) $(DEPDIR) $(LIBDIR) $(LIBDIR)/$(addprefix lib,$(MODULE_NAME))$(LIB_SUFFIX).$(LIBEXT)

else
# Rules for application; this iteration is for an app

# Clean Object, Binary and Configuro generated directories
clean :
	$(RM) -f $(OBJDIR)/* $(DEPDIR)/* $(BINDIR)/*
obj_clean :

	$(RM) -f $(OBJDIR)/* $(DEPDIR)/*

#EXE_NAME = $(BINDIR)/$(APP_NAME)_$(CORE)_$(PROFILE_$(CORE)).$(EXEEXT)

#BIN_NAME = $(BINDIR)/$(APP_NAME)_$(CORE)_$(PROFILE_$(CORE)).$(BINEXT)

# Create dependencies list to ultimately create application executable binary
$(CORE) : $(OBJDIR) $(BINDIR) $(DEPDIR) $(PKG_LIST) $(EXE_NAME) $(BIN_NAME) $(TIBIN_NAME)

endif

# Nothing beyond this point

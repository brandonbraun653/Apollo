ifeq ($(RULES_MAKE), )
include $(PDK_INSTALL_PATH)/ti/build/Rules.make
else
include $(RULES_MAKE)
endif

# Support backwards compatibility with KeyStone1 approach
 CC = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)g++
 AC = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)as
 AR = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)ar
 LD = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)g++
 BIN = $(TOOLCHAIN_PATH_A15)/bin/$(CROSS_TOOL_PRFX)objcopy

UNIFLASH_HOST_BINDIR = bin
UNIFLASH_HOST_SRCDIR = source
CPPFLAG = -static

ifeq ($(OS),Windows_NT)
LOCAL_FLAG = -DWINDOWS
endif

all:  $(UNIFLASH_HOST_BINDIR)/ProcessorSDKSerialFlash

$(UNIFLASH_HOST_BINDIR)/.created:
	@mkdir -p $(UNIFLASH_HOST_BINDIR)
	@touch $(UNIFLASH_HOST_BINDIR)/.created

$(UNIFLASH_HOST_BINDIR)/ProcessorSDKSerialFlash.o: $(UNIFLASH_HOST_SRCDIR)/ProcessorSDKSerialFlash.cpp
	g++ $(LOCAL_FLAG) -o $(UNIFLASH_HOST_BINDIR)/ProcessorSDKSerialFlash.o -c $(UNIFLASH_HOST_SRCDIR)/ProcessorSDKSerialFlash.cpp

$(UNIFLASH_HOST_BINDIR)/main.o : $(UNIFLASH_HOST_SRCDIR)/main.cpp
	g++ $(LOCAL_FLAG) -o $(UNIFLASH_HOST_BINDIR)/main.o -c $(UNIFLASH_HOST_SRCDIR)/main.cpp

$(UNIFLASH_HOST_BINDIR)/ProcessorSDKSerialFlash: $(UNIFLASH_HOST_BINDIR)/.created $(UNIFLASH_HOST_BINDIR)/ProcessorSDKSerialFlash.o $(UNIFLASH_HOST_BINDIR)/main.o
	g++ $(CPPFLAG) -o $(UNIFLASH_HOST_BINDIR)/ProcessorSDKSerialFlash $(UNIFLASH_HOST_BINDIR)/ProcessorSDKSerialFlash.o $(UNIFLASH_HOST_BINDIR)/main.o

clean:
	rm -f $(UNIFLASH_HOST_BINDIR)/ProcessorSDKSerialFlash.o $(UNIFLASH_HOST_BINDIR)/main.o $(UNIFLASH_HOST_BINDIR)/ProcessorSDKSerialFlash



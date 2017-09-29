CC=g++
EMCC=emcc
IDIR =../../src
INCLUDE=-I$(IDIR) -I$(IDIR)/Linuxduinoh
CFLAGS=$(INCLUDE) -Wall
EMFLAGS=$(INCLUDE) --bind
LDFLAGS=-pthread
DIRSOURCES= $(IDIR)/Core.cpp $(IDIR)/Serial.cpp $(IDIR)/WString.cpp $(IDIR)/SPI.cpp $(IDIR)/Wire.cpp
JSLIBRARY=$(IDIR)/library_ioctls.js
# TARGETS  
TARGETS= analogWrite setPwm
WASM_TARGETS=


all: $(TARGETS)
all.js: $(WASM_TARGETS)

# analogWrite
analogWrite:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@

# setPwm
setPwm:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@


.PHONY: clean
clean:
	rm -f $(TARGETS) $(WASM_TARGETS) $(WASM_TARGETS:.js=.wasm)
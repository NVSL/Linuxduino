CC=g++
EMCC=emcc
IDIR =../../src
INCLUDE=-I$(IDIR)
CFLAGS=$(INCLUDE) -Wall
EMFLAGS=$(INCLUDE) --bind
LDFLAGS=-pthread
DIRSOURCES= $(IDIR)/Core.cpp $(IDIR)/Serial.cpp $(IDIR)/WString.cpp $(IDIR)/SPI.cpp $(IDIR)/Wire.cpp
JSLIBRARY=$(IDIR)/library_ioctls.js
# TARGETS  
TARGETS=
WASM_TARGETS= linuxduino.js

all: $(WASM_TARGETS)

# linuxduino
linuxduino.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 -s ENVIRONMENT=node $< -o $@ --js-library $(JSLIBRARY)
	./addCode.sh

.PHONY: clean
clean:
	rm -f $(TARGETS) $(WASM_TARGETS) $(WASM_TARGETS:.js=.wasm)
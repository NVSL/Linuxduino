CC=g++
EMCC=emcc
IDIR =../../src
INCLUDE=-I$(IDIR) -I$(IDIR)/Arduinoh
CFLAGS=$(INCLUDE) -Wall
EMFLAGS=$(INCLUDE) --bind
LDFLAGS=-pthread
DIRSOURCES= $(IDIR)/Arduinoh/main.cpp $(IDIR)/Core.cpp $(IDIR)/Serial.cpp $(IDIR)/WString.cpp $(IDIR)/SPI.cpp $(IDIR)/Wire.cpp
JSLIBRARY=$(IDIR)/library_ioctls.js
# TARGETS  
TARGETS=digitalWrite digitalRead
WASM_TARGETS=digitalWrite.js digitalRead.js

all: $(TARGETS)
all.js: $(WASM_TARGETS)

# digitalWrite
digitalWrite:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
digitalWrite.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# digitalRead
digitalRead:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
digitalRead.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

	
.PHONY: clean
clean:
	rm -f $(TARGETS) $(WASM_TARGETS) $(WASM_TARGETS:.js=.wasm)
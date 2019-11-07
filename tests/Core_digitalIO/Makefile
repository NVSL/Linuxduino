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
TARGETS=digitalWrite digitalRead

all: $(TARGETS)
all.js: $(WASM_TARGETS)

# digitalWrite
digitalWrite:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@

# digitalRead
digitalRead:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@

	
.PHONY: clean
clean:
	rm -f $(TARGETS)
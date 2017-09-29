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
TARGETS= i2c_write i2c_read i2c_getset
WASM_TARGETS= i2c_write.js i2c_read.js i2c_getset.js

all: $(TARGETS)
all.js: $(WASM_TARGETS)

# i2c_write
i2c_write:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
i2c_write.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# i2c_read
i2c_read:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
i2c_read.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# i2c_getset
i2c_getset:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
i2c_getset.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)


.PHONY: clean
clean:
	rm -f $(TARGETS) $(WASM_TARGETS) $(WASM_TARGETS:.js=.wasm)
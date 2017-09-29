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
TARGETS= spi_settings spi_separateSettings spi_transfer spi_getset
WASM_TARGETS= spi_settings.js spi_separateSettings.js spi_transfer.js spi_getset.js


all: $(TARGETS)
all.js: $(WASM_TARGETS)

# spi_settings
spi_settings:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
spi_settings.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# spi_separateSettings
spi_separateSettings:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
spi_separateSettings.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# spi_transfer
spi_transfer:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
spi_transfer.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# spi_getset
spi_getset:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
spi_getset.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)


.PHONY: clean
clean:
	rm -f $(TARGETS) $(WASM_TARGETS) $(WASM_TARGETS:.js=.wasm)
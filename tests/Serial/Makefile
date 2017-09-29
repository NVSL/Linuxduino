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
TARGETS=serial_print serial_wstring serial_parse serial_peek serial_read serial_readBytes serial_readBytesUntil 	\
	serial_write serial_readString serial_readStringUntil serial_readStringCommand serial_flush serial_find			\
	serial_findUntil serial_getset
WASM_TARGETS=serial_print.js serial_wstring.js serial_parse.js serial_peek.js serial_read.js serial_readBytes.js 	\
 serial_readBytesUntil.js serial_write.js serial_readString.js serial_readStringUntil.js 							\
 serial_readStringCommand.js serial_flush.js serial_find.js serial_findUntil.js serial_getset.js


all: $(TARGETS)
all.js: $(WASM_TARGETS)

# serial_print
serial_print:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_print.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_wstring
serial_wstring:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_wstring.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_parse
serial_parse:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_parse.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_peek
serial_peek:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_peek.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_read
serial_read:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_read.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_readBytes
serial_readBytes:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_readBytes.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_readBytesUntil
serial_readBytesUntil:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_readBytesUntil.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_write
serial_write:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_write.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_readString
serial_readString:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_readString.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_readStringUntil
serial_readStringUntil:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_readStringUntil.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_readStringCommand
serial_readStringCommand:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_readStringCommand.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_flush
serial_flush:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_flush.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_find
serial_find:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_find.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_findUntil
serial_findUntil:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_findUntil.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)

# serial_getset
serial_getset:
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIRSOURCES) $@.cpp $< -o $@
serial_getset.js:
	$(EMCC) $(EMFLAGS) $(DIRSOURCES) $(addsuffix .cpp, $(basename $@)) -s WASM=1 $< -o $@ --js-library $(JSLIBRARY)


.PHONY: clean
clean:
	rm -f $(TARGETS) $(WASM_TARGETS) $(WASM_TARGETS:.js=.wasm)
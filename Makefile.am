ACLOCAL_AMFLAGS = -I m4

# Linuxduino Library
lib_LTLIBRARIES = liblinuxduino.la
liblinuxduino_la_SOURCES =  ./src/Core.cpp  ./src/Serial.cpp  ./src/SPI.cpp  ./src/Wire.cpp  ./src/WString.cpp 
include_HEADERS = ./src/Arduinoh/Arduino.h ./src/Linuxduinoh/Linuxduino.h ./src/Core.h ./src/Serial.h ./src/SPI.h ./src/Wire.h ./src/WString.h ./src/Node_ioctl.h ./src/linux_headers/i2c-dev.h ./src/linux_headers/spi/spidev.h
liblinuxduino_la_LDFLAGS = -no-undefined -version-info 1:0:0
liblinuxduino_la_LIBADD = -lpthread -lm
/*
  SPI.cpp - Linuxduino I2C library header

  Copyright (c) 2016 Jorge Garza <jgarzagu@ucsd.edu>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef WireLinux_h
#define WireLinux_h

#include <stdint.h>
#include <stdlib.h>
#include <string>

/////////////////////////////////////////////
//          Set/Get Default (Wire)        //
////////////////////////////////////////////

extern char I2C_DRIVER_NAME[]; 

void setWire(std::string defaultWire);
void setWire(const char * defaultWire);
std::string getWire_std(void);
char * getWire(void);

/////////////////////////////////////////////
//          WireLinux class (I2C)         //
////////////////////////////////////////////

#ifndef BUFFER_LENGTH
  //Linux I2C MAX is 8192. 
  #define BUFFER_LENGTH 512 
#endif


class WireLinux {
	private:
		int fd;
        static uint8_t rxBuffer[];
        static uint16_t rxBufferIndex;
        static uint16_t rxBufferLength;

        static uint8_t txBuffer[];
        static uint16_t txBufferIndex;
        static uint16_t txBufferLength;

        static uint16_t transmitting;

        int i2c_write_bytes(int file, uint8_t *txBuff, size_t numBytes);
        int i2c_read_bytes(int file, uint8_t *rxBuff, size_t numBytes);

	public:
		WireLinux();
		void begin();
    void begin(std::string i2cDeviceName);
		void begin(const char *i2cDeviceName);
		void end();
		uint8_t  requestFrom(uint8_t address, size_t quantity);
		void beginTransmission(uint8_t address);
		uint8_t endTransmission();		
		size_t write(uint8_t data);
    size_t write(std::string data);
		size_t write(const char *data);
		size_t write(void *data, size_t quantity);
    size_t write_js(std::string data, size_t quantity);
		int available(void);
		int read(void);
};

extern WireLinux Wire;


#endif
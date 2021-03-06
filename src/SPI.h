/*
  SPI.cpp - LinuxDuino SPI library header

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

#ifndef SPILinux_h
#define SPILinux_h

#include <stdint.h>
#include <stdlib.h>
#include <string>


/////////////////////////////////////////////
//          Set/Get Default (UART)        //
////////////////////////////////////////////

extern char SPI_DRIVER_NAME[]; 

void setSPI(std::string defaultSPI);
void setSPI(const char * defaultSPI);
std::string getSPI_std(void);
char * getSPI(void);

/////////////////////////////////////////////
//          SPILinux class (SPI)          //
////////////////////////////////////////////

#ifndef LSBFIRST
#define LSBFIRST 1
#endif
#ifndef MSBFIRST
#define MSBFIRST 0
#endif	

// SPI Modes 
#define SPI_MODE0 0	// Same as SPI_MODE_0 in linux/spi/spi.h
#define SPI_MODE1 1	// Same as SPI_MODE_1 in linux/spi/spi.h 
#define SPI_MODE2 2	// Same as SPI_MODE_2 in linux/spi/spi.h
#define SPI_MODE3 3	// Same as SPI_MODE_3 in linux/spi/spi.h


// SPI Speed taking a 16 MHz Arduino clock speed
#define SPI_CLOCK_DIV2 8000000
#define SPI_CLOCK_DIV4 4000000
#define SPI_CLOCK_DIV8 2000000
#define SPI_CLOCK_DIV16 1000000
#define SPI_CLOCK_DIV32 500000
#define SPI_CLOCK_DIV64 250000
#define SPI_CLOCK_DIV128 125000


class SPISettings {
	public:
		uint32_t spiClock;
		uint8_t spiBitOrder;
		uint8_t spiDataMode;

		SPISettings() {
			spiClock = 4000000;
			spiBitOrder = MSBFIRST;
			spiDataMode = SPI_MODE0;
		}

		SPISettings(uint32_t clock, uint8_t bitOrder, uint8_t dataMode) {
			spiClock = clock;
			spiBitOrder = bitOrder;
			spiDataMode = dataMode;
		}

	friend class SPIPi;
};

class SPILinux {
	private:
		int fd;
		int lsbHardwareError;
		void spi_transfer_bytes(int file, uint8_t *tx_data, size_t numBytes);
		uint8_t reverse_byte_order(uint8_t b);
	public:
		SPILinux();
  		void begin();
  		void begin(std::string spiDeviceName);
  		void begin(const char *spiDeviceName);
    	void end();
    	void beginTransaction(SPISettings settings);
    	void endTransaction();
    	void setBitOrder(uint8_t bitOrder);
 		void setClockDivider(uint32_t clockDiv);
		void setDataMode(uint8_t dataMode);
 		uint8_t transfer(uint8_t data);
 		//uint16_t transfer16(uint16_t data);
 		void transfer(void *buf, size_t count);
 		std::string transfer_js(std::string buf, size_t count);
 		//std::string transfer_js(uint8_t data);
 		//std::string transfer_js(std::string data);
};


extern SPILinux SPI;

#endif
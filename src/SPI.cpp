/*
  SPI.cpp - LinuxDuino SPI library

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

#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#ifdef __EMSCRIPTEN__
    #include "linux_headers/spi/spidev.h"
    #include "Node_ioctl.h"
    #include <emscripten/bind.h>
    using namespace emscripten;
#else
    #include <linux/spi/spidev.h>
#endif
#include "SPI.h"

// All functions of unistd.h must be called like this: unistd::the_function()
namespace unistd {
    #include <unistd.h>
};

/////////////////////////////////////////////
//          Set/Get Default (SPI)         //
////////////////////////////////////////////

char SPI_DRIVER_NAME[128] = "";

void setSPI(std::string defaultSPI)
{
    setSPI(defaultSPI.c_str());
}

// Sets Defualt SPI device driver name
void setSPI(const char * defaultSPI)
{
    strncpy(SPI_DRIVER_NAME, defaultSPI, 128);
    SPI_DRIVER_NAME[127] = '\0';
}

// Gets Defualt SPI device driver name
std::string getSPI_std(void)
{
    return SPI_DRIVER_NAME;
}

// Gets Defualt SPI device driver name
char * getSPI(void)
{
    return SPI_DRIVER_NAME;
}

/////////////////////////////////////////////
//          SPILinux class (SPI)          //
////////////////////////////////////////////

////  Private methods ////

// Transfers SPI data, received data is stored back in the data buffer
void SPILinux::spi_transfer_bytes(int file, uint8_t *data, size_t numBytes) 
{
    struct spi_ioc_transfer spi;

    // Reverse tx bytes if hardware LSB hardware is not supported
    if (lsbHardwareError == true) {
        for(size_t i = 0; i < numBytes; i++) {
            data[i] = reverse_byte_order(data[i]);
        }
    }

    // Set spi values
    memset (&spi, 0, sizeof(spi));
    spi.tx_buf        = (unsigned long)data;
    spi.rx_buf        = (unsigned long)data;
    spi.len           = numBytes;

#ifdef __EMSCRIPTEN__
    // Webassembly
    if (node_ioctl (file, SPI_IOC_MESSAGE(1), &spi) < 0) {
        fprintf(stderr, "SPI.%s(): SPI transfer error\n", __func__);
        exit(1);
    }
#else
    //C++
    if (ioctl (file, SPI_IOC_MESSAGE(1), &spi) < 0) {
        fprintf(stderr, "SPI.%s(): SPI transfer error: %s \n", __func__, strerror (errno));
        exit(1);
    }
#endif 

    // Return recieved data
    memcpy(data, (unsigned long *)spi.rx_buf, numBytes);

    // Reverse rx bytes if hardware LSB hardware is not supported
    // rx data can be wrong if LSB hardware is not supported. 
    if (lsbHardwareError == true) {
        for(size_t i = 0; i < numBytes; i++) {
            data[i] = reverse_byte_order(data[i]);
        }
    }
}

// Reverse byte order from MSB to LSB, this is done if
// hardware dosen't support LSB like the Raspberry Pi. 
uint8_t SPILinux::reverse_byte_order(uint8_t b) {
   b = ((b * 0x0802LU & 0x22110LU) | 
    (b * 0x8020LU & 0x88440LU)) * 0x10101LU >> 16;
   return b;
}

////  Public methods ////


SPILinux::SPILinux()
{
    fd = -1;
    lsbHardwareError = false;
}

void SPILinux::begin()
{
    begin(SPI_DRIVER_NAME);
}

void SPILinux::begin(std::string spiDeviceName)
{
    begin(spiDeviceName.c_str());
}

void SPILinux::begin(const char *spiDeviceName)
{
    char spiDeviceNamePath[128];
    uint8_t bitsPerWord = 8;

    // If SPI device name is empty return an error
    if (strcmp(spiDeviceName, "") == 0) {
        fprintf(stderr, "SPI.%s(): specify a SPI device driver to open first "
                "using setSPI(\"device_path\") or SPI.begin(\"device_path\")\n",
                __func__);
        exit(1);
    }

    // Here we change the path from /dev/... to /devices/...
    // see github issue #1 (https://github.com/NVSL/Linuxduino/issues/1)
#ifdef __EMSCRIPTEN__
    // Webassembly
    char devPath[4];
    char restOfPath[124];
    sscanf((char *)spiDeviceName, "%*c%3[^/]%124s", devPath, restOfPath);
    devPath[3] = '\0';
    restOfPath[123] = '\0';
    if (strcmp(devPath, "dev") == 0) {
        // Replace /dev with /devices
        strcpy(spiDeviceNamePath, "/devices");
        strcat(spiDeviceNamePath, restOfPath);
    } else {
        strcpy(spiDeviceNamePath, spiDeviceName);
    }
#else
    // C++
    strcpy(spiDeviceNamePath, spiDeviceName);
#endif

    // Open SPI port
    fd = open(spiDeviceNamePath, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "SPI.%s(): error opening SPI device %s: %s\n",
            __func__, spiDeviceName, strerror (errno));
        exit(1);
    }

    // Set bits per word to 8 always
#ifdef __EMSCRIPTEN__
    // Webassembly
    if (node_ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bitsPerWord) < 0) {
        fprintf(stderr, "SPI.%s(): ioctl error \n", __func__);
        exit(1);
    }
#else 
    // C++
    if (ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bitsPerWord) < 0) {
        fprintf(stderr, "SPI.%s(): ioctl error: %s\n", __func__, strerror (errno));
        exit(1);
    }
#endif

}

void SPILinux::end()
{
    unistd::close(fd);
    fd = -1;
}

void SPILinux::beginTransaction(SPISettings settings)
{

    if (fd < 0) {
        fprintf(stderr, "SPI.%s(): initialize SPI first with SPI.begin() \n", __func__);
        exit(1);
    }

    
#ifdef __EMSCRIPTEN__
    // Webassembly

    // Set SPI mode (0,1,2,3)
    if (node_ioctl(fd, SPI_IOC_WR_MODE, &settings.spiDataMode) < 0) {
        fprintf(stderr, "SPI.%s(): ioctl error\n", __func__);
        exit(1);
    }

    // Set SPI bit order (LSB/MSB)
    if (node_ioctl(fd, SPI_IOC_WR_LSB_FIRST, &settings.spiBitOrder) < 0) {
        // If LSB is not supported (like in RPi) EINVAL may occurr. 
        // If this happens don't exit. Instead try to support it. 
        if (settings.spiBitOrder == LSBFIRST) {
            lsbHardwareError = true;
        } else {
            fprintf(stderr, "SPI.%s(): ioctl error\n", __func__);
            exit(1); 
        }
    }

    // Set max Hz speed
    if (node_ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &settings.spiClock) < 0) {
        fprintf(stderr, "SPI.%s(): ioctl error\n", __func__);
        exit(1);
    }

#else 
    // C++

    // Set SPI mode (0,1,2,3)
    if (ioctl(fd, SPI_IOC_WR_MODE, &settings.spiDataMode) < 0) {
        fprintf(stderr, "SPI.%s(): ioctl error: %s\n", __func__, strerror (errno));
        exit(1);
    }

    // Set SPI bit order (LSB/MSB)
    if (ioctl(fd, SPI_IOC_WR_LSB_FIRST, &settings.spiBitOrder) < 0) {
        // If LSB is not supported (like in RPi) EINVAL may occurr. 
        // If this happens don't exit. Instead try to support it. 
        if (settings.spiBitOrder == LSBFIRST) {
            lsbHardwareError = true;
        } else {
            fprintf(stderr, "SPI.%s(): ioctl error: %s\n", __func__, strerror (errno));
            exit(1);
        }
    }

    // Set max Hz speed
    if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &settings.spiClock) < 0) {
        fprintf(stderr, "SPI.%s(): ioctl error: %s\n", __func__, strerror (errno));
        exit(1);
    }
#endif

}

void SPILinux::endTransaction()
{
    // Do Nothing
}

void SPILinux::setBitOrder(uint8_t bitOrder)
{
    if (fd < 0) {
        fprintf(stderr, "SPI.%s(): initialize SPI first with SPI.begin() \n", __func__);
        exit(1);
    }

// Set SPI bit order (LSB/MSB)
#ifdef __EMSCRIPTEN__
    // Webassembly
    if (node_ioctl(fd, SPI_IOC_WR_LSB_FIRST, &bitOrder) < 0) {
        // If LSB is not supported (like in RPi) EINVAL may occurr. 
        // If this happens don't exit. Instead try to support it. 
        if (bitOrder == LSBFIRST) {
            lsbHardwareError = true;
        } else {
            fprintf(stderr, "SPI.%s(): ioctl error\n", __func__);
            exit(1); 
        }
    }
#else
    // C++
    if (ioctl(fd, SPI_IOC_WR_LSB_FIRST, &bitOrder) < 0) {
        // If LSB is not supported (like in RPi) EINVAL may occurr. 
        // If this happens don't exit. Instead try to support it. 
        if (bitOrder == LSBFIRST) {
            lsbHardwareError = true;
        } else {
            fprintf(stderr, "SPI.%s(): ioctl error: %s\n", __func__, strerror (errno));
            exit(1);
        }
    }
#endif 

}

void SPILinux::setClockDivider(uint32_t clockDiv)
{
    if (fd < 0) {
        fprintf(stderr, "SPI.%s(): initialize SPI first with SPI.begin() \n", __func__);
        exit(1);
    }

    // Set max Hz speed
#ifdef __EMSCRIPTEN__
    // Webassembly
    if (node_ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &clockDiv) < 0) {
        fprintf(stderr, "SPI.%s(): ioctl error\n", __func__);
        exit(1);
    }
#else
    // C++
    if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &clockDiv) < 0) {
        fprintf(stderr, "SPI.%s(): ioctl error: %s\n", __func__, strerror (errno));
        exit(1);
    }
#endif
}

void SPILinux::setDataMode(uint8_t dataMode)
{
    if (fd < 0) {
        fprintf(stderr, "SPI.%s(): initialize SPI first with SPI.begin() \n", __func__);
        exit(1);
    }

    // Set SPI mode (0,1,2,3)
#ifdef __EMSCRIPTEN__
    // Webassembly
    if (node_ioctl(fd, SPI_IOC_WR_MODE, &dataMode) < 0) {
        fprintf(stderr, "SPI.%s(): ioctl error\n", __func__);
        exit(1);
    }
#else
    // C++
    if (ioctl(fd, SPI_IOC_WR_MODE, &dataMode) < 0) {
        fprintf(stderr, "SPI.%s(): ioctl error: %s\n", __func__, strerror (errno));
        exit(1);
    }
#endif
}

uint8_t SPILinux::transfer(uint8_t data)
{
    uint8_t transferData;
    transferData = data;
    spi_transfer_bytes(fd, &transferData, 1);
    return transferData;
}

/*
uint16_t SPILinux::transfer16(uint16_t data)
{
    // TODO
}
*/

void SPILinux::transfer(void *buf, size_t count)
{
    spi_transfer_bytes(fd, (uint8_t *)buf, count);
}

void SPILinux::transfer_js(std::string buf, size_t count)
{
    transfer((uint8_t *)buf.c_str(), count);
}


SPILinux SPI = SPILinux();


/////////////////////////////////////////////
//    Embind SPI functions                //
////////////////////////////////////////////
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_BINDINGS(SPI) {
        constant("LSBFIRST", LSBFIRST);
        constant("MSBFIRST", MSBFIRST);
        constant("SPI_MODE0", SPI_MODE0);
        constant("SPI_MODE1", SPI_MODE1);
        constant("SPI_MODE2", SPI_MODE2);
        constant("SPI_MODE3", SPI_MODE3);
        constant("SPI_CLOCK_DIV2", SPI_CLOCK_DIV2);
        constant("SPI_CLOCK_DIV4", SPI_CLOCK_DIV4);
        constant("SPI_CLOCK_DIV8", SPI_CLOCK_DIV8);
        constant("SPI_CLOCK_DIV16", SPI_CLOCK_DIV16);
        constant("SPI_CLOCK_DIV32", SPI_CLOCK_DIV32);
        constant("SPI_CLOCK_DIV64", SPI_CLOCK_DIV64);
        constant("SPI_CLOCK_DIV128", SPI_CLOCK_DIV128);
        function("setSPI", 
            select_overload<void(std::string)>(&setSPI));
        function("getSPI", &getSPI_std);
        class_<SPISettings>("SPISettings")
            .constructor<>()
            .constructor<uint32_t, uint8_t, uint8_t>()
            ;
        class_<SPILinux>("SPI")
            .constructor<>()  
            .function("begin", select_overload<void()>(&SPILinux::begin))
            .function("begin", select_overload<void(std::string)>(&SPILinux::begin))
            .function("end", &SPILinux::end)
            .function("beginTransaction", &SPILinux::beginTransaction)
            .function("endTransaction", &SPILinux::endTransaction)
            .function("setBitOrder", &SPILinux::setBitOrder)
            .function("setClockDivider", &SPILinux::setClockDivider)
            .function("setDataMode", &SPILinux::setDataMode)
            .function("transfer",  select_overload<uint8_t(uint8_t)>(&SPILinux::transfer))
            .function("transfer",  &SPILinux::transfer_js)
            ;
    }
#endif
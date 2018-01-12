/*
  Wire.cpp - Linuxduino I2C library

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
#include <termios.h> 
#include <sys/ioctl.h>
#include <sys/types.h>
#ifdef __EMSCRIPTEN__
    #include "Node_ioctl.h"
    #include <emscripten/bind.h>
    using namespace emscripten;
#endif
#include "Wire.h"

// All functions of unistd.h must be called like this: unistd::the_function()
namespace unistd {
    #include <unistd.h>
};

/////////////////////////////////////////////
//          Set/Get Default (Wire)        //
////////////////////////////////////////////

char I2C_DRIVER_NAME[128] = "";

void setWire(std::string defaultWire)
{
    setWire(defaultWire.c_str());
}

// Sets Defualt Wire device driver name
void setWire(const char * defaultWire)
{
    strncpy(I2C_DRIVER_NAME, defaultWire, 128);
    I2C_DRIVER_NAME[127] = '\0';
}

// Gets Defualt Wire device driver name
std::string getWire_std(void)
{
    return I2C_DRIVER_NAME;
}

// Gets Defualt Wire device driver name
char * getWire(void)
{
    return I2C_DRIVER_NAME;
}

/////////////////////////////////////////////
//          WireLinux class (I2C)          //
////////////////////////////////////////////
#define I2C_SLAVE 0x0703

//// Private methods ///
uint8_t WireLinux::rxBuffer[BUFFER_LENGTH];
uint16_t WireLinux::rxBufferIndex = 0;
uint16_t WireLinux::rxBufferLength = 0;

uint8_t WireLinux::txBuffer[BUFFER_LENGTH];
uint16_t WireLinux::txBufferIndex = 0;
uint16_t WireLinux::txBufferLength = 0;

uint16_t WireLinux::transmitting = 0;


int WireLinux::i2c_write_bytes(int file, uint8_t *txBuff, size_t numBytes)
{
    int bytes_written = 0;

    if (numBytes == 0) {
        return bytes_written;
    } else {
        bytes_written = unistd::write(file, txBuff, numBytes);
        if ( bytes_written < 0) {
            // errno == 5 (Input/Output error) means I2C cables
            // may not be connected properly.
            // Make noise about everything else except errno == 5. 
            if (errno != 5 ) {
                fprintf(stderr, "Wire.%s(): i2c write error: %s \n",
                    __func__, strerror (errno));
            }
        }
    }

    return bytes_written;
}

int WireLinux::i2c_read_bytes(int file, uint8_t *rxBuff, size_t numBytes)
{
    int bytes_read = 0;

    if (numBytes == 0) {
        return bytes_read;
    } else {
        bytes_read = unistd::read(file, rxBuff, numBytes);
        if ( bytes_read < 0) {
            // errno == 5 (Input/Output error) means I2C cables 
            // may not be connected properly.
            // Make noise about everything else except errno == 5. 
            if (errno != 5 ) {
                fprintf(stderr, "Wire.%s(): i2c read error: %s \n",
                    __func__, strerror (errno));
            }
        }
    }

    return bytes_read;
}

////  Public methods ////

//Constructor
WireLinux::WireLinux()
{
    fd = -1;
}

void WireLinux::begin()
{
    begin(I2C_DRIVER_NAME);
}

void WireLinux::begin(std::string i2cDeviceName)
{
    begin(i2cDeviceName.c_str());
}

// Initialize Wire/I2C
void WireLinux::begin(const char *i2cDeviceName)
{
    char i2cDeviceNamePath[128];

    // If I2C device name is empty return an error
    if (strcmp(i2cDeviceName, "") == 0) {
        fprintf(stderr, "Wire.%s(): specify a I2C device driver to open first "
                "using setWire(\"device_path\") or Wire.begin(\"device_path\")\n",
                __func__);
        exit(1);
    }
    
    // Here we change the path from /dev/... to /devices/...
    // see github issue #1 (https://github.com/NVSL/Linuxduino/issues/1)
#ifdef __EMSCRIPTEN__
    // Webassembly
    char devPath[4];
    char restOfPath[124];
    sscanf((char *)i2cDeviceName, "%*c%3[^/]%124s", devPath, restOfPath);
    devPath[3] = '\0';
    restOfPath[123] = '\0';
    if (strcmp(devPath, "dev") == 0) {
        // Replace /dev with /devices
        strcpy(i2cDeviceNamePath, "/devices");
        strcat(i2cDeviceNamePath, restOfPath);
    } else {
        strcpy(i2cDeviceNamePath, i2cDeviceName);
    }
#else
    // C++
    strcpy(i2cDeviceNamePath, i2cDeviceName);
#endif

    // Open I2C port
    fd = open(i2cDeviceNamePath, O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "Wire.%s(): error openning I2C device %s: %s\n",
            __func__, i2cDeviceName, strerror (errno));
        exit(1);
    }

    rxBufferIndex = 0;
    rxBufferLength = 0;

    txBufferIndex = 0;
    txBufferLength = 0;

}

void WireLinux::end()
{
    unistd::close(fd);
    fd = -1;
}

// Initialize the Wire library with a slave address
/*
void WireLinux::begin(uint8_t address) 
{
    // TODO, Still reading documentation for linux new I2c slave support
}
*/

uint8_t WireLinux::requestFrom(uint8_t address, size_t quantity)
{

    if (fd < 0) {
        fprintf(stderr, 
            "Wire.%s(): initialize I2C first with Wire.begin() \n",
             __func__);
        exit(1);
    }

#ifdef __EMSCRIPTEN__
    // Webassembly
    if (node_ioctl(fd, I2C_SLAVE, address) < 0) {
        fprintf(stderr, "Wire.%s(): ioctl error\n",__func__);
        exit(1);
    }
#else
    //C++
    if (ioctl(fd, I2C_SLAVE, address) < 0) {
        fprintf(stderr, "Wire.%s(): ioctl error: %s\n",
            __func__, strerror (errno));
        exit(1);
    }
#endif

    // clamp to buffer length
    if(quantity > BUFFER_LENGTH){
        quantity = BUFFER_LENGTH;
    }

    // perform blocking read into buffer
    uint8_t read = i2c_read_bytes(fd, rxBuffer, quantity);
    // set rx buffer iterator vars
    rxBufferIndex = 0;
    rxBufferLength = read;

    return read;
}


//Begin a transmission to the I2C slave device with the given address
void WireLinux::beginTransmission(uint8_t address)
{

    if (fd < 0) {
        fprintf(stderr, 
            "Wire.%s(): initialize I2C first with Wire.begin() \n",
             __func__);
        exit(1);
    }

#ifdef __EMSCRIPTEN__
    // Webassembly
    if (node_ioctl(fd, I2C_SLAVE, address) < 0) {
        fprintf(stderr, "Wire.%s(): ioctl error\n",__func__);
        exit(1);
    }
#else
    //C++
    if (ioctl(fd, I2C_SLAVE, address) < 0) {
        fprintf(stderr, "Wire.%s(): ioctl error: %s\n",
            __func__, strerror (errno));
        exit(1);
    }
#endif

    // indicate that we are transmitting
    transmitting = 1;
    // reset tx buffer iterator vars
    txBufferIndex = 0;
    txBufferLength = 0;
}

// Writes data to the I2C, returns bytes written.
size_t WireLinux::write(uint8_t data)
{

    if (transmitting) {
        // in master transmitter mode
        // don't bother if buffer is full
        if (txBufferLength >= BUFFER_LENGTH) {
          return 0;
        }

        // put byte in tx buffer
        txBuffer[txBufferIndex] = data;
        ++txBufferIndex;
        // update amount in buffer   
        txBufferLength = txBufferIndex;
    } else {
        // in slave send mode
        // reply to master
        i2c_write_bytes(fd, &data, 1);
    }

    return 1;

}

size_t WireLinux::write(std::string str)
{
    return write(str.c_str());
}

// Writes data to the I2C in form of string, returns bytes written. 
size_t WireLinux::write(const char *str)
{
    size_t byteswritten = 0;

    for (size_t i = 0; i < strlen(str) ; i++) {
        // If transmitting data >= BUFFER_LENGTH, then break.
        if (write(str[i]) == 0) {
            break;
        }
        byteswritten++;
    }

    return byteswritten;
}


// Writes data to the I2C, returns bytes written. 
size_t WireLinux::write(void *data, size_t quantity)
{

    size_t byteswritten = 0;

    if (transmitting) {
        // in master transmitter mode
        for(size_t i = 0; i < quantity; ++i){
            write(((uint8_t *)data)[i]);
        }
        byteswritten = quantity;
    } else {
        // in slave send mode
        // reply to master
        byteswritten = i2c_write_bytes(fd, (uint8_t *)data, quantity);
    }
    
    return byteswritten;
}


size_t WireLinux::write_js(std::string data, size_t quantity)
{
    return write((uint8_t *)data.c_str(), quantity);
}


int WireLinux::available(void)
{
  return rxBufferLength - rxBufferIndex;
}


int WireLinux::read(void)
{
  int value = -1;
  
  // get each successive byte on each call
  if (rxBufferIndex < rxBufferLength) {
    value = rxBuffer[rxBufferIndex];
    ++rxBufferIndex;
  }

  return value;
}


uint8_t WireLinux::endTransmission()
{
    uint8_t ret;

    if (fd < 0) {
        fprintf(stderr, "Wire.%s(): initialize I2C first with Wire.begin() \n", 
            __func__);
        exit(1);
    }

    // Transmit Data 
    ret = i2c_write_bytes(fd, txBuffer, txBufferLength);

    // reset tx buffer iterator vars
    txBufferIndex = 0;
    txBufferLength = 0;
    // indicate that we are done transmitting
    transmitting = 0;

    return ret;
}


WireLinux Wire = WireLinux();


/////////////////////////////////////////////
//    Embind Wire functions               //
////////////////////////////////////////////
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_BINDINGS(Wire) {
        constant("BUFFER_LENGTH", BUFFER_LENGTH);
        function("setWire", 
            select_overload<void(std::string)>(&setWire));
        function("getWire", &getWire_std);
        class_<WireLinux>("Wire")
            .constructor<>()
            .function("begin", select_overload<void()>(&WireLinux::begin))
            .function("begin", select_overload<void(std::string)>(&WireLinux::begin))
            .function("end", &WireLinux::end)
            .function("requestFrom", &WireLinux::requestFrom)
            .function("beginTransmission", &WireLinux::beginTransmission)
            .function("endTransmission", &WireLinux::endTransmission)
            // Wire.write(uint8_t) :: NO TYPE OVERLOAD WITH EMBIND (Added as write_byte)
            .function("write_byte", select_overload<size_t(uint8_t)>(&WireLinux::write))
            .function("write", select_overload<size_t(std::string)>(&WireLinux::write))
            .function("write", &WireLinux::write_js)
            .function("available", &WireLinux::available)
            .function("read", &WireLinux::read)
            ;
    }
#endif

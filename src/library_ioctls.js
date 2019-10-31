mergeInto(LibraryManager.library, {
  node_ioctl: function(fd, cmd, val) {
    try{
      var ioctl = require('ioctl-napi');
    } catch (e) {
      console.log("library_ioctls.js: Missing npm module\n" +
        "To install the missing npm module run:\n"+
        "npm install ioctl-napi\n");
      throw e;
    }
    var ret = -1;
    // Get stream from the filesystem.
    var stream = FS.streams[fd];

    switch (cmd) {
      case 21505:   // TCGETS

        //struct termios
        // {
        //  tcflag_t c_iflag;   // uint (4 bytes)
        //  tcflag_t c_oflag;   // uint (4 bytes)
        //  tcflag_t c_cflag;   // uint (4 bytes)
        //  tcflag_t c_lflag;   // uint (4 bytes)
        //  cc_t c_line;        // uchar (1 byte)
        //  cc_t c_cc[NCCS];    // uchar (32 bytes)
        //  speed_t __c_ispeed; // uint (4 bytes)
        //  speed_t __c_ospeed; // uint (4 bytes)
        // }; // Total: 57 bytes.

        var termios = Buffer.alloc(57);

        // Call ioctl
        try{
          ret = ioctl(stream.nfd, cmd, termios);
        } catch (e) {
          console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
        }
        
        var c_iflag = Buffer.from(termios.buffer, 0, 4);
        var c_oflag = Buffer.from(termios.buffer, 4, 4);
        var c_cflag = Buffer.from(termios.buffer, 8, 4);
        var c_lflag = Buffer.from(termios.buffer, 12, 4);
        var c_line = Buffer.from(termios.buffer, 16, 1);
        var c_cc = Buffer.from(termios.buffer, 17, 32);
        var c_ispeed = Buffer.from(termios.buffer, 49, 4);
        var c_ospeed = Buffer.from(termios.buffer, 53, 4);

        // Set data from ioctl
        var ptr = getValue(val, '*');
        setValue(ptr, c_iflag, 'i32');
        setValue(ptr+4, c_oflag,  'i32');
        setValue(ptr+8, c_cflag,  'i32');
        setValue(ptr+12, c_lflag, 'i32');
        setValue(ptr+16, c_line, 'i8');
        for (var i =0; i< 32; i++){
          setValue(ptr+17+i, c_cc[i], 'i8');
        }
        setValue(ptr+49, c_ispeed, 'i32');
        setValue(ptr+53, c_ospeed, 'i32');

        break;
  
      case 21506:       // TCSETS

        //struct termios
        // {
        //  tcflag_t c_iflag;   // uint (4 bytes)
        //  tcflag_t c_oflag;   // uint (4 bytes)
        //  tcflag_t c_cflag;   // uint (4 bytes)
        //  tcflag_t c_lflag;   // uint (4 bytes)
        //  cc_t c_line;        // uchar (1 byte)
        //  cc_t c_cc[NCCS];    // uchar (32 bytes)
        //  speed_t __c_ispeed; // uint (4 bytes)
        //  speed_t __c_ospeed; // uint (4 bytes)
        // }; // Total: 57 bytes.

        var c_iflag = Buffer.alloc(4);
        var c_oflag = Buffer.alloc(4);
        var c_cflag = Buffer.alloc(4);
        var c_lflag = Buffer.alloc(4);
        var c_line = Buffer.alloc(1);
        var c_cc = Buffer.alloc(32);
        var c_ispeed = Buffer.alloc(4);
        var c_ospeed = Buffer.alloc(4);

        // Get data from pointer
        var ptr = getValue(val, '*');
        c_iflag.writeUInt32LE(getValue(ptr, 'i32'));
        c_oflag.writeUInt32LE(getValue(ptr+4, 'i32'));
        c_cflag.writeUInt32LE(getValue(ptr+8, 'i32'));
        c_lflag.writeUInt32LE(getValue(ptr+12, 'i32'));
        c_line.writeUInt8(getValue(ptr+16, 'i8'));
        for (var i =0; i< 32; i++){
          c_cc[i] = getValue(ptr+17+i, 'i8'); 
        }
        c_ispeed.writeUInt32LE(getValue(ptr+49, 'i32'));
        c_ospeed.writeUInt32LE(getValue(ptr+53, 'i32'));

        // Create termios buffer
        var termios = Buffer.concat([c_iflag,c_oflag,c_cflag,c_lflag,c_line,c_cc,c_ispeed,c_ospeed]);

        // Call ioctl
        try{
          ret = ioctl(stream.nfd, cmd, termios);
        } catch (e) {
          console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
        }

        break;
  
      case 21531:       // FIONREAD

        // int *nBytes;
        var nBytes = Buffer.alloc(4);  

        // Call ioctl
        try{
          ret = ioctl(stream.nfd, cmd, nBytes);
        } catch (e) {
          console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
        }

        // Return availale bytes in stream
        var ptr = getValue(val, '*');
        setValue(ptr, nBytes.readUInt32LE(), 'i32');
        break;
  
      case 21515:       // TCFLSH

        // int queue_selector;
        var queue_selector = getValue(val, 'i32');
        
        // Call ioctl
        try{
          ret = ioctl(stream.nfd, cmd, queue_selector);
        } catch (e) {
          console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
        }

        break;

      case 1073834755:    // SPI_IOC_WR_BITS_PER_WORD

        // uint8_t *bitsPerWord;
        var ptr = getValue(val, '*');
        var bitsPerWord = Buffer.from([getValue(ptr, 'i8')]);

        // Call ioctl
        try{
          ret = ioctl(stream.nfd, cmd, bitsPerWord);
        } catch (e) {
          console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
        }

        break;

      case 1073834753:    // SPI_IOC_WR_MODE

        // uint8_t *spiDataMode;
        var ptr = getValue(val, '*');
        var spiDataMode = Buffer.from([getValue(ptr, 'i8')]);

        // Call ioctl
        try{
          ret = ioctl(stream.nfd, cmd, spiDataMode);
        } catch (e) {
          console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
        }

        break;

      case 1073834754:    // SPI_IOC_WR_LSB_FIRST

        // uint8_t *spiBitOrder;
        var ptr = getValue(val, '*');
        var spiBitOrder = Buffer.from([getValue(ptr, 'i8')]);

        // Call ioctl
        try{
          ret = ioctl(stream.nfd, cmd, spiBitOrder);
        } catch (e) {
          // Don't print any error, as we may want to continue if an 
          // error happens with this ioclt. (e.g LSB hardware error)
        }

        break;

      case 1074031364:    // SPI_IOC_WR_MAX_SPEED_HZ

        // uint32_t *spiClock;
        var ptr = getValue(val, '*');
        var spiClock = Buffer.alloc(4);
        spiClock.writeUInt32LE(getValue(ptr, 'i32'));

        // Call ioctl
        try{
          ret = ioctl(stream.nfd, cmd, spiClock);
        } catch (e) {
          console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
        }

        break; 

      case 1075866368:    // SPI_IOC_MESSAGE(1)

        // struct spi_ioc_transfer {
        //  unsigned long long  tx_buf;     // 8 bytes // Pointer
        //  unsigned long long  rx_buf;     // 8 bytes // Pointer
        //  unsigned int    len;            // 4 bytes
        //  unsigned int    speed_hz;       // 4 bytes
        //  unsigned short  delay_usecs;    // 2 bytes
        //  unsigned char   bits_per_word;  // 1 byte
        //  unsigned char   cs_change;      // 1 byte
        //  unsigned char   tx_nbits;       // 1 byte
        //  unsigned char   rx_nbits;       // 1 byte
        //  unsigned short  pad;            // 2 bytes
        // }; // Total 32 bytes

        var ptr = getValue(val, '*');
        var ptr_tx = getValue(ptr, '*');
        var ptr_rx = getValue(ptr+8, '*');
        var numBytes = getValue(ptr+16, 'i32');

        var tx =  Buffer.alloc(numBytes);
        var rx =  Buffer.alloc(numBytes);
        for (var i=0; i < numBytes; i++) {
          tx[i] = (0xff & getValue(ptr_tx + i, 'i8'));
          rx[i] = 0x00;
        }

        // Get pointer to tx buffer and set pading if needed
        var tx_buf = Buffer.from(tx.memAddressLE(),'hex');
        var tx_pad = Buffer.alloc(0);
        if (tx_buf.length == 4) {
          // Is 32-bit Architecture so add a padding
          tx_pad = Buffer.alloc(4); 
        }

        // Get pointer to rx buffer and set pading if needed
        var rx_buf = Buffer.from(rx.memAddressLE(),'hex');
        var rx_pad = Buffer.alloc(0);
        if (rx_buf.length == 4) {
          // Is 32-bit Architecture so add a padding
          rx_pad = Buffer.alloc(4); 
        }

        var len = Buffer.alloc(4);
        var speed_hz = Buffer.alloc(4);
        var delay_usecs = Buffer.alloc(2);
        var bits_per_word = Buffer.alloc(1);
        var cs_change = Buffer.alloc(1);
        var tx_nbits = Buffer.alloc(1);
        var rx_nbits = Buffer.alloc(1);
        var pad = Buffer.alloc(2);

        len.writeUInt32LE(numBytes);
        speed_hz.writeUInt32LE(getValue(ptr+20, 'i32'));
        delay_usecs.writeUInt16LE(getValue(ptr+24, 'i16'));
        bits_per_word.writeUInt8(getValue(ptr+26, 'i8'));
        cs_change.writeUInt8(getValue(ptr+27, 'i8'));
        tx_nbits.writeUInt8(getValue(ptr+28, 'i8'));
        rx_nbits.writeUInt8(getValue(ptr+29, 'i8'));
        pad.writeUInt16LE(getValue(ptr+30, 'i16'));

        // Create spi_ioc_transfer struct
        var spi_ioc_transfer = Buffer.concat([tx_buf,tx_pad,rx_buf,rx_pad,
          len,speed_hz,delay_usecs,bits_per_word,cs_change,tx_nbits,rx_nbits,pad]);

        // Call ioctl
        try {       
          ret = ioctl(stream.nfd, cmd, spi_ioc_transfer);
        } catch (e) {
          console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
        };

        // Set rx buffer with received data
        for (var i=0; i < numBytes; i++) {
          setValue(ptr_rx+i, rx[i], 'i8');
        }

        break;

      case 1795:        // I2C_SLAVE

        // uint8_t address; 
        var address = getValue(val, 'i8');

        // Call ioctl
        try{
          ret = ioctl(stream.nfd, cmd, address);
        } catch (e) {
          console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
        }

        break;

      default:        // ERROR
        console.log("library_ioctls.js: node ioctl cmd "+cmd+" not found");
        break;
      }

    return ret;
  }
});
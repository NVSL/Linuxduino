mergeInto(LibraryManager.library, {
	node_ioctl: function(fd, cmd, val) {
		try{
			var ioctl = require('ioctl');
			var ref = require('ref');
			var ArrayType = require('ref-array');
			var StructType = require('ref-struct');
		} catch (e) {
			console.log("library_ioctls.js: Error, an npm module "+ 
				"needs to be installed.\n" +
				"To install all the required npm modules run:\n"+
				"npm install ioctl ref ref-array ref-struct\n");
			throw e;
		}
		var ret = -1;
		// Get stream from the filesystem.
		var stream = FS.streams[fd];

		switch (cmd) {
			case 21505: 	// TCGETS
				//struct termios
				// {
				// 	tcflag_t c_iflag;
				// 	tcflag_t c_oflag;
				// 	tcflag_t c_cflag;
				// 	tcflag_t c_lflag;
				// 	cc_t c_line;
				// 	cc_t c_cc[NCCS];
				// 	speed_t __c_ispeed;
				// 	speed_t __c_ospeed;
				// };
				var termios = new (StructType({
				    c_iflag : ref.types.uint,
				    c_oflag : ref.types.uint,
				    c_cflag : ref.types.uint,
				    c_lflag : ref.types.uint,
				    c_line : ref.types.uchar,
				    c_cc : ArrayType(ref.types.char, 32),
				    c_ispeed: ref.types.int,
				    c_ospeed: ref.types.int
				}));
				// Call ioctl
				try{
					ret = ioctl(stream.nfd, cmd, termios.ref());
				} catch (e) {
					console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
				}
				// Set data from ioctl
				var ptr = getValue(val, '*');
				setValue(ptr, termios.c_iflag, 'i32');
				setValue(ptr+4, termios.c_oflag,  'i32');
				setValue(ptr+8, termios.c_cflag,  'i32');
				setValue(ptr+12, termios.c_lflag, 'i32');
				setValue(ptr+14, termios.c_line, 'i8');
				for (var i =0; i< 32; i++){
					setValue(ptr+17+i, termios.c_cc[i], 'i8');
				}

				break;

			case 21506: 			// TCSETS
				//struct termios
				// {
				// 	tcflag_t c_iflag;
				// 	tcflag_t c_oflag;
				// 	tcflag_t c_cflag;
				// 	tcflag_t c_lflag;
				// 	cc_t c_line;
				// 	cc_t c_cc[NCCS];
				// 	speed_t __c_ispeed;
				// 	speed_t __c_ospeed;
				// };
				var termios = new (StructType({
				    c_iflag : ref.types.uint,
				    c_oflag : ref.types.uint,
				    c_cflag : ref.types.uint,
				    c_lflag : ref.types.uint,
				    c_line : ref.types.uchar,
				    c_cc : ArrayType(ref.types.char, 32),
				    c_ispeed: ref.types.int,
				    c_ospeed: ref.types.int
				}));
				// Get data from pointer
				var ptr = getValue(val, '*');
				termios.c_iflag = getValue(ptr, 'i32');
				termios.c_oflag = getValue(ptr+4, 'i32');
				termios.c_cflag = getValue(ptr+8, 'i32');
				termios.c_lflag = getValue(ptr+12, 'i32');
				termios.c_line  = getValue(ptr+14, 'i8');
				for (var i =0; i< 32; i++){
					termios.c_cc[i] = getValue(ptr+17+i, 'i8');
				}
				// Call ioctl
				try{
					ret = ioctl(stream.nfd, cmd, termios.ref());
				} catch (e) {
					console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
				}
				break;

			case 21531: 			// FIONREAD
				//* int nBytes;
				var nBytes = new Buffer(4);  
				nBytes.type = ref.types.int;
				// Call ioctl
				try{
					ret = ioctl(stream.nfd, cmd, nBytes);
				} catch (e) {
					console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
				}
				// Return availale bytes in stream
				var ptr = getValue(val, '*');
				setValue(ptr, nBytes.deref(), 'i32');
				break;

			case 21515: 			// TCFLSH
				// int queue_selector;
				var queue_selector = getValue(val, 'i32');
				// Call ioctl
				try{
					ret = ioctl(stream.nfd, cmd, nBytes);
				} catch (e) {
					console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
				}
				break;

			case 1073834755: 		// SPI_IOC_WR_BITS_PER_WORD
				// uint8_t *bitsPerWord;
				var ptr = getValue(val, '*');
				var bitsPerWord = ref.alloc('uint8', getValue(ptr, 'i8'));
				//console.log("Spi bits per word = "+ bitsPerWord.deref());
				// Call ioctl
				try{
					ret = ioctl(stream.nfd, cmd, bitsPerWord);
				} catch (e) {
					console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
				}
				break;

			case 1073834753: 		// SPI_IOC_WR_MODE
				// uint8_t *spiDataMode;
				var ptr = getValue(val, '*');
				var spiDataMode = ref.alloc('uint8', getValue(ptr, 'i8'));
				//console.log("Spi data mode = "+ spiDataMode.deref());
				// Call ioctl
				try{
					ret = ioctl(stream.nfd, cmd, spiDataMode);
				} catch (e) {
					console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
				}
				break;

			case 1073834754: 		// SPI_IOC_WR_LSB_FIRST
				// uint8_t *spiBitOrder;
				var ptr = getValue(val, '*');
				var spiBitOrder = ref.alloc('uint8', getValue(ptr, 'i8'));
				//console.log("Spi bit order = "+ spiBitOrder.deref());
				// Call ioctl
				try{
					ret = ioctl(stream.nfd, cmd, spiBitOrder);
				} catch (e) {
					// Don't print any error, as we may want to continue if an 
					// error happens with this ioclt. (e.g LSB hardware error)
				}
				break;

			case 1074031364: 		// SPI_IOC_WR_MAX_SPEED_HZ
				// uint32_t *spiClock;
				var ptr = getValue(val, '*');
				var spiClock = ref.alloc('uint32', getValue(ptr, 'i32'));
				//console.log("Spi clock = "+ spiClock.deref());
				// Call ioctl
				try{
					ret = ioctl(stream.nfd, cmd, spiClock);
				} catch (e) {
					console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
				}
				break; 

			case 1075866368: 		// SPI_IOC_MESSAGE(1)
				// struct spi_ioc_transfer {
				// 	unsigned long long	tx_buf; 		//__u64
				// 	unsigned long long	rx_buf; 		//__u64
				// 	unsigned int		len;			//__u32
				// 	unsigned int		speed_hz;		//__u32
				// 	unsigned short		delay_usecs;	//__u16
				// 	unsigned char		bits_per_word;	//__u8
				// 	unsigned char		cs_change;		//__u8
				// 	unsigned char		tx_nbits;		//__u8
				// 	unsigned char		rx_nbits;		//__u8
				// 	unsigned short		pad;			//__u8
				// };
				var spi_ioc_transfer = new (StructType({
					// pointer to tx_buf and rx_buf was added cuz npm-ioctl 
					// doesn't support &tx_buf and &rx_buf dereferencing.  
					// Padding was also added to complete 8 bytes. 
				    tx_buf : ref.refType('uchar'),
				    pad_tx : ref.types.uint,
				    rx_buf : ref.refType('uchar'),
				    pad_rx : ref.types.uint,
				    len : ref.types.uint,
				    speed_hz : ref.types.uint,
				    delay_usecs : ref.types.ushort,
				    bits_per_word : ref.types.uchar,
				    cs_change: ref.types.uchar,
				    tx_nbits: ref.types.uchar,
				    rx_nbits: ref.types.uchar,
				    pad: ref.types.ushort
				}));

				var ptr = getValue(val, '*');
				var ptr_tx = getValue(ptr, '*');
				var ptr_rx = getValue(ptr+8, '*');
				var numBytes = getValue(ptr+16, 'i32');
				var tx = new Buffer(numBytes);
				var rx = new Buffer(numBytes);
				tx.type = ref.types.uchar;
				rx.type = ref.types.uchar;
				for (var i=0; i < numBytes; i++) {
					tx[i] = (0xff & getValue(ptr_tx + i, 'i8'));
					rx[i] = (0xff & getValue(ptr_rx + i, 'i8'));
				}

				spi_ioc_transfer.tx_buf = tx;
				spi_ioc_transfer.tx_pad = 0;
				spi_ioc_transfer.rx_buf = rx;
				spi_ioc_transfer.rx_pad = 0;
				spi_ioc_transfer.len = numBytes;
				spi_ioc_transfer.speed_hz = getValue(ptr+20, 'i32');
				spi_ioc_transfer.delay_usecs = getValue(ptr+24, 'i16');
				spi_ioc_transfer.bits_per_word = getValue(ptr+26, 'i8');
				spi_ioc_transfer.cs_change = getValue(ptr+27, 'i8');
				spi_ioc_transfer.tx_nbits = getValue(ptr+28, 'i8');
				spi_ioc_transfer.rx_nbits = getValue(ptr+29, 'i8');
				spi_ioc_transfer.pad = getValue(ptr+30, 'i16');

				try {
					// Call ioctl
					ret = ioctl(stream.nfd, cmd, spi_ioc_transfer.ref());
				} catch (e) {
					console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
				}


				for (var i=0; i < numBytes; i++) {
					setValue(ptr_tx+i, tx[i], 'i8');
					setValue(ptr_rx+i, rx[i], 'i8');
				}
				setValue(ptr+16, spi_ioc_transfer.len, 'i32');
				setValue(ptr+20, spi_ioc_transfer.speed_hz, 'i32');
				setValue(ptr+24, spi_ioc_transfer.delay_usecs, 'i16');
				setValue(ptr+26, spi_ioc_transfer.bits_per_word, 'i8');
				setValue(ptr+27, spi_ioc_transfer.cs_change, 'i8');
				setValue(ptr+28, spi_ioc_transfer.tx_nbits, 'i8');
				setValue(ptr+29, spi_ioc_transfer.rx_nbits, 'i8');
				setValue(ptr+30, spi_ioc_transfer.pad, 'i16');
				break;

			case 1795: 				// I2C_SLAVE
				// uint8_t address; 
				var address = getValue(val, 'i8');
				try{
					// Call ioctl
					ret = ioctl(stream.nfd, cmd, address);
				} catch (e) {
					console.log("library_ioctls.js: node ioctl cmd "+cmd+" "+e);
				}
				break;

			default: 				// ERROR
				console.log("library_ioctls.js: node ioctl cmd "+cmd+" not found");
				break;
		}

		return ret;
	}
});
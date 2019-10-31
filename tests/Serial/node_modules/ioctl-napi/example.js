// Get current serial configuration
// Use: sudo node example.js
var fs = require("fs");
var ioctl = require("./ioctl");

try {
	var fd = fs.openSync("/dev/ttyUSB0", fs.constants.O_RDWR);
} catch (e) {
	console.log("Error opening Serial:", e);
	return;
}
console.log("Success opening serial!!");

var TCGETS = 0x5401;
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
// }; // Total = 57 bytes
var termios = Buffer.alloc(57);

try {
	var ret = ioctl(fd, TCGETS, termios);
} catch (e) {
	console.log("ioctl error: ", e);
	return;
}

console.log("termios buffer:", termios);
var c_iflag = Buffer.from(termios.buffer, 0, 4);
var c_oflag = Buffer.from(termios.buffer, 4, 4);
var c_cflag = Buffer.from(termios.buffer, 8, 4);
var c_lflag = Buffer.from(termios.buffer, 12, 4);
var c_line = Buffer.from(termios.buffer, 16, 1);
var c_cc = Buffer.from(termios.buffer, 17, 32);
var c_ispeed = Buffer.from(termios.buffer, 49, 4);
var c_ospeed = Buffer.from(termios.buffer, 53, 4);

console.log("c_iflag:", c_iflag);
console.log("c_oflag:", c_oflag);
console.log("c_cflag:", c_cflag);
console.log("c_lflag:", c_lflag);
console.log("c_line:", c_line);
console.log("c_cc:", c_cc);
console.log("c_ispeed:", c_ispeed);
console.log("c_ospeed:", c_ospeed);
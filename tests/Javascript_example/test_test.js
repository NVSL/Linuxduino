var Linuxduino = require("./test.js");

Linuxduino.onRuntimeInitialized = function() {
    console.log('Initialize');
    Linuxduino.lerp(1.0, 1.0, 1.0);
}
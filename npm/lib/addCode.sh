#!/bin/bash
echo "
module.exports.ready = new Promise(function(resolve, reject) {
  Module.onRuntimeInitialized = () => {
      resolve();
  }
});
" >> ./linuxduino.js
echo "addCode.sh: Extra code added"
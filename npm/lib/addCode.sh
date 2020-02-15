#!/bin/bash

#
# Add promise to use linuxduino as an async function
#
echo "
module.exports.ready = new Promise(function(resolve, reject) {
  Module.onRuntimeInitialized = () => {
      resolve();
  }
});
" >> ./linuxduino.js

#
# Remove linuxduino fetch so it always search WASM file locally
# when require('linuxduino') is in an online file. 
#
# Insert before 
FIND="Prefer streaming instantiation if available."
INSERTBEFORE='\/\*'
sed -i "/${FIND}/i ${INSERTBEFORE}" linuxduino.js

# Insert before 
FIND="no exports yet; we'll fill them in later"
INSERTBEFORE='\*\/ \n  instantiateArrayBuffer(receiveInstantiatedSource);'
sed -i -E "/${FIND}/i ${INSERTBEFORE}" linuxduino.js

#
# Finish 
#
echo "addCode.sh: Extra code added"
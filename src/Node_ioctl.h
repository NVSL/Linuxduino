#ifndef Node_ioctl_h
#define Node_ioctl_h

// Defines the external ioctl function name for Webassembly
// This function calls to the ioctls implemented in javascript
// The javascript ioctls are located in library_ioctls.js
// This library shuld be added in emscripten as follows: 
// emcc [options | files] --js-library library_ioctls.js

extern "C" {
  extern int node_ioctl(int var, int cmd, ...);
}


#endif


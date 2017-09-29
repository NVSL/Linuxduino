#include "Linuxduino.h"
#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif


int EMSCRIPTEN_KEEPALIVE lol(int var) {
    printf("In lol\n");
    return 1;
}
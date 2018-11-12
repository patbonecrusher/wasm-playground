#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <emscripten/emscripten.h>
#include <functional>

extern "C"  void testExternalJSMethod();

std::function<void(int)> gCallback;


// The code inside the main will be executed once the WASM module loads.
int main(int argc, char ** argv) {
    printf("WebAssembly module loaded\n");
    testExternalJSMethod();
}

// Simple C function that returns a number between 1 and 6.
extern "C" void EMSCRIPTEN_KEEPALIVE foo(char* data) {
	printf("cccc %s\n", data);
}

extern "C" int EMSCRIPTEN_KEEPALIVE roll_dice() {
	printf("boo\n");
    srand ( time(NULL) );
    int r = rand() % 6 + 1;
    gCallback(r);
    return  r;
}


extern "C" void EMSCRIPTEN_KEEPALIVE registerCallback(char* a){
	printf("a is %s\n", a);
	int fp = atoi(a);
	printf("fp is %d\n", fp);
	printf("%d\n", __LINE__);
	void (*f)(int) = reinterpret_cast<void (*)(int)>(fp);
	printf("f %08x\n", f);
	printf("%d\n", __LINE__);
	f(7);
	printf("hahaha\n");
    gCallback = f;
}

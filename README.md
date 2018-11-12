
```bash
em++ -std=c++11 dice-roll.cpp -s WASM=1 -O3 -o index.js --js-library myLibrary.js -s RESERVED_FUNCTION_POINTERS=10 -s DISABLE_EXCEPTION_CATCHING=2 --post-js post.js --post-js myLibrary.js -s ASSERTIONS=2 -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap', 'ccall']"
```

## Notes
https://github.com/timhutton/opengl-canvas-wasm.git


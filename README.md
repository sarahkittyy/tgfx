# tgfx

A cross-platform terminal graphics library for linux.

## Building

```bash
git clone https://github.com/sarahkittyy/tgfx
cd tgfx
mkdir build
cd build
cmake \
    -DBUILD_TESTS=on \ # use =off to not build the tests
    -DCMAKE_BUILD_TYPE=Release \ 
    ..
make
```
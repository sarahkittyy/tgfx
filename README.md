# tgfx

A cross-platform terminal graphics library for linux.

Heavily inspired by [SFML.](https://github.com/SFML/SFML)

## Building

```bash
git clone https://github.com/sarahkittyy/tgfx
cd tgfx
mkdir build
cd build
cmake .. # See section "CMake Flags" for more options.
make
```

## Docs

See [the github.io page](https://sarahkittyy.github.io/tgfx) (files located in docs/html).

## CMake Flags

```bash
cmake \
    -DBUILD_TESTS=on|off \ # 'on' to build and run the tests.
    -DCOLOR_MODE=true|256|16 \ # terminal color compatibility. See section "Colors"
    ..
```

## Colors

Most terminals support either 3/4 bit colors, 8 bit colors, or 24 bit (true) colors.

You can specify which color compatibility setting to use in the cmake flags with the variable `COLOR_MODE=(see below)`. The default mode is `true`

|`-DCOLOR_MODE=...`|Mode|
|-|-|
|`true`| Full 24-bit RGB support |
|`256` | 8 bit RGB support (256 colors) |
|`16` | 4 bit color support (16 colors) |

When using a mode other than `true`, rgb colors given to rendering methods will be rounded to the nearest available ansi color.

You can view all ansi colors for the three different modes [here.](https://en.wikipedia.org/wiki/ANSI_escape_code#Colors)
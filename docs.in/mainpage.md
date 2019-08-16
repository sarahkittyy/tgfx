[TOC]

# tgfx {#mainpage}

Welcome to the tgfx docs!

tgfx (terminal gfx) is an attempt at bringing [SFML-](https://github.com/SFML/SFML)like experience to rendering "graphics" on a linux terminal.

## Building

tgfx uses CMake as the primary build system.

```bash
cd tgfx
mkdir build
cd build
cmake \ # CMake flags go here
    ..
make
```

See [**CMake Flags**](#cmake-flags) for build options.

## CMake Flags {#cmake-flags}

```bash
cmake \
    -DBUILD_TESTS=on|off \ # 'on' to build and run the tests.
    -DCOLOR_MODE=true|256|16 \ # terminal color compatibility.
    ..
```

See [**Colors**](#colors) for more info on `-DCOLOR_MODE=...`

## Colors {#colors}

Most terminals support either 3/4 bit colors, 8 bit colors, or 24 bit (true) colors.

You can specify which color compatibility setting to use in the cmake flags with the variable `COLOR_MODE=(see below)`. The default mode is `true`

|`-DCOLOR_MODE=...`|Mode|
|-|-|
|`true`| Full 24-bit RGB support |
|`256` | 8 bit RGB support (256 colors) |
|`16` | 4 bit color support (16 colors) |

When using a mode other than `true`, rgb colors given to rendering methods will be rounded to the nearest available ansi color.

You can view all ansi colors for the three different modes [here.](https://en.wikipedia.org/wiki/ANSI_escape_code#Colors)
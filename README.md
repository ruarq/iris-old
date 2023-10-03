# iris

[![C/C++ CI](https://github.com/ruarq/iris/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/ruarq/iris/actions/workflows/c-cpp.yml)

Iris is a general-purpose multi-paradigm (functional, procedural, structural)
programming language.

# Building

## Dependencies

- libfmt:10.1.0+
- A C++ compiler (clang++:14+)
- make:3.81+

## Instructions

Run

```sh
./premake5 gmake2
make config=release
```

The binaries will be in the `./bin/release` directory.

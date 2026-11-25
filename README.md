# Gedrouble Loader

Gedrouble is a **Geometry Dash mod loader project**. It is not a Geode mod and is not packaged as a `.geode` file.

The project is being built as its own native loader/core. Geode is an intended dependency/integration component; Gedrouble itself must remain the loader/host, not a plugin that Geode loads.

## Current state

- Native C++ loader-core scaffold
- CMake build (shared library)
- No game injection, mod discovery, or runtime loading implemented yet

## Build the core

```sh
cmake -S . -B build
cmake --build build
```

The GitHub Actions workflow compiles the native core on Linux. This is only a core build check; it does **not** mean the loader is already able to load mods into Geometry Dash.

## Planned architecture

1. Loader application/bootstrap
2. Loader core and mod management
3. Geode integration adapter
4. Android/Geometry Dash runtime integration

The next implementation step is to choose and implement the actual runtime entry point for the target platform, then connect the loader core to it.

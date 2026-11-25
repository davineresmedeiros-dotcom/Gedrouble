# Gedrouble Loader

Gedrouble is a **native Geometry Dash mod loader project**. It is not a Geode mod and is not packaged as a `.geode` file.

## Core milestone (v0.1.0)
- Native C++ shared library
- Core lifecycle: initialize, ready, shutdown
- Version API: 0.1.0
- Logging API with replaceable platform log sink
- Basic lifecycle/version test

Game bootstrap/runtime integration and mod discovery/loading are not implemented yet.

## Build and test
```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Architecture
1. Core — lifecycle, logging, versioning (current)
2. Mod Manager — metadata and enabled/disabled mods
3. Runtime adapter — connect to the target Geometry Dash runtime
4. Android bootstrap/launcher — separate component, later

Geode is not the loader itself. Runtime integration will be a separate adapter, not a Geode plugin.

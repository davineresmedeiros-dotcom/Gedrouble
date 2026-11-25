# Gedrouble

Gedrouble is a Geometry Dash mod-loader project that **uses Geode as its host/dependency** for game integration. Gedrouble is its own project and loader; it is not a replacement for Geode or an independent game bootstrap.

## Core milestone (v0.1.0)
- Native C++ core library
- Core lifecycle: initialize, ready, shutdown
- Version API: 0.1.0
- Logging API with replaceable platform log sink
- Basic lifecycle/version test
- Optional Geode-hosted entry point

The current entry point initializes the Gedrouble Core through Geode. It does not yet discover, enable, disable, or load Gedrouble mods.

## Build and test the core
These commands build and test the core without requiring the Geode SDK:
```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Build the Geode integration
Configure with the Geode SDK available to CMake:
```sh
cmake -S . -B build -DGEDROUBLE_BUILD_GEODE_INTEGRATION=ON
cmake --build build
```

The Geode integration is opt-in so ordinary core CI can run without the SDK.

## Roadmap
1. Core lifecycle and logging (current)
2. Geode integration and runtime bridge
3. Mod Manager (metadata, discovery, enabled/disabled state)
4. Actual mod loading through the supported host/runtime APIs

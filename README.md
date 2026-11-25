# Gedrouble

Gedrouble is a Geometry Dash mod-loader project that **uses Geode as its host/dependency** for game integration. Gedrouble is its own loader project; Geode provides the game integration and mod-host environment.

## Core milestone (v0.1.0)
- Native C++ core library
- Core lifecycle: initialize, ready, shutdown
- Version API: 0.1.0
- Logging API with replaceable platform log sink
- Basic lifecycle/version test
- Geode-hosted entry point and lifecycle callbacks

The current entry point initializes and shuts down the Gedrouble Core through Geode. It does not yet discover, enable, disable, or load Gedrouble's own mod entries.

## Build and test the core
These commands build and test the core without requiring the Geode SDK:
```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Build the Geode integration
Install the matching Geode SDK and make sure the `GEODE_SDK` environment variable points to its directory. The Geode SDK's version and target Geometry Dash version must match `mod.json`.
```sh
cmake -S . -B build -DGEDROUBLE_BUILD_GEODE_INTEGRATION=ON
cmake --build build
```

The Geode integration is opt-in so core CI can run without the SDK. The `mod.json` Geode version is a template token; use the exact Geode version of the SDK you install before packaging.

## Roadmap
1. Core lifecycle and logging (current)
2. Geode runtime bridge
3. Gedrouble Mod Manager (metadata, discovery, enabled/disabled state)
4. Actual mod loading through the supported host/runtime APIs

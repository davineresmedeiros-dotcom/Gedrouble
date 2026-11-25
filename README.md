# Gedrouble

Gedrouble is a Geometry Dash mod project built on top of Geode.

## Target

- Geode: `v6.0.0-beta.1`
- Geometry Dash: `2.2091`
- Mod version: `v0.1.0`

## Build

Install the matching Geode SDK and Geode CLI, then build from the project directory:

```sh
geode build
```

The project expects the `GEODE_SDK` environment variable to point to the installed SDK.

## First milestone

The initial mod logs a startup message when Geode loads Gedrouble. After confirming that it builds and loads, we can add the first Gedrouble-specific interface and features.

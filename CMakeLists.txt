cmake_minimum_required(VERSION 3.21)
project(GedroubleLoader VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build the core as static code so it can be bundled into the Geode-hosted
# Gedrouble module, while still being testable without the Geode SDK.
add_library(gedrouble_loader STATIC src/loader.cpp src/log.cpp)
set_target_properties(gedrouble_loader PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(gedrouble_loader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(gedrouble_loader PUBLIC GEDROUBLE_LOADER_BUILD)

# Enable only when the Geode SDK is installed and GEODE_SDK points to it.
option(GEDROUBLE_BUILD_GEODE_INTEGRATION "Build Gedrouble's Geode-hosted integration" OFF)
if(GEDROUBLE_BUILD_GEODE_INTEGRATION)
    if(NOT DEFINED ENV{GEODE_SDK})
        message(FATAL_ERROR "Set GEODE_SDK to the installed Geode SDK directory.")
    endif()
    add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode-sdk)
    add_library(gedrouble_geode SHARED src/geode_entry.cpp)
    target_link_libraries(gedrouble_geode PRIVATE gedrouble_loader)
    setup_geode_mod(gedrouble_geode)
endif()

include(CTest)
if(BUILD_TESTING)
    add_executable(gedrouble_core_test tests/core_test.cpp)
    target_link_libraries(gedrouble_core_test PRIVATE gedrouble_loader)
    add_test(NAME gedrouble_core_test COMMAND gedrouble_core_test)
endif()

cmake_minimum_required(VERSION 3.21)
project(GedroubleLoader VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(gedrouble_loader SHARED src/loader.cpp src/log.cpp)
target_include_directories(gedrouble_loader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(gedrouble_loader PRIVATE GEDROUBLE_LOADER_BUILD)

# Geode integration is opt-in so the standalone core tests can run without
# downloading or configuring the Geode SDK.
option(GEDROUBLE_BUILD_GEODE_INTEGRATION "Build Gedrouble's Geode-hosted integration" OFF)
if(GEDROUBLE_BUILD_GEODE_INTEGRATION)
    find_package(Geode REQUIRED)
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

if(ANDROID)
    set_target_properties(gedrouble_loader PROPERTIES OUTPUT_NAME "gedrouble")
endif()

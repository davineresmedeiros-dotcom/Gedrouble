cmake_minimum_required(VERSION 3.21)

project(GedroubleLoader VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(gedrouble_loader SHARED
    src/loader.cpp
)

target_include_directories(gedrouble_loader
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(gedrouble_loader
    PRIVATE GEDROUBLE_LOADER_BUILD
)

if(ANDROID)
    set_target_properties(gedrouble_loader PROPERTIES
        OUTPUT_NAME "gedrouble"
    )
endif()

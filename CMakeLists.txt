cmake_minimum_required(VERSION 3.23)
project(Adam VERSION 0.1.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 1. Define the target without sources upfront
add_library(Adam)

# 2. Add implementation files as PRIVATE and public headers via FILE_SET
target_sources(Adam
    PRIVATE
        src/scene_manager.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include"
        FILES
            include/adam/scene_manager.h
            include/adam/scene.h
)

target_include_directories(Adam PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# 3. Compiler requirements
#target_compile_features(Adam PUBLIC cxx_std_20)

# 4. Alias target for uniform linking syntax
add_library(Adam::Adam ALIAS Adam)

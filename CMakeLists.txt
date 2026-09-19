cmake_minimum_required(VERSION 4.3.0)
project(adam LANGUAGES CXX)

# Output all binaries to the bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 1. Find your source files
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")

# 2. Create your executable
add_executable(adam ${SRC_FILES})
target_include_directories(adam PRIVATE src)

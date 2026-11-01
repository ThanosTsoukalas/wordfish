# ThanUI/demo/CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(WordFish LANGUAGES CXX)

# Build the demo executable
file(GLOB_RECURSE WORDFISH_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(WordFish ${WORDFISH_SRC})
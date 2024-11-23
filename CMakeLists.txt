cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(sorting_lib LANGUAGES CXX)
# set(CMAKE_VERBOSE_MAKEFILE ON)

add_library(sorting
            SHARED
            src/cppmult.cpp
            )
find_package(pybind11 REQUIRED)  # or add_subdirectory(pybind11)

add_library(example MODULE src/cppmult.cpp)

target_link_libraries(example PRIVATE pybind11::module pybind11::lto pybind11::windows_extras)

pybind11_extension(example)
if(NOT MSVC AND NOT ${CMAKE_BUILD_TYPE} MATCHES Debug|RelWithDebInfo)
    # Strip unnecessary sections of the binary on Linux/macOS
    pybind11_strip(example)
endif()

set_target_properties(example PROPERTIES CXX_VISIBILITY_PRESET "hidden"
                                         CUDA_VISIBILITY_PRESET "hidden")
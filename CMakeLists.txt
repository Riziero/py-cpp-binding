cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(sorting_lib LANGUAGES CXX)

# generate a library from sources
add_library(sort
  STATIC
    ./src/Sorting.h
    ./src/Sorting.cpp
  )

add_executable(run main.cpp)

target_link_libraries(run sort)
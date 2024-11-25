cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(sorting LANGUAGES CXX)
# set(CMAKE_VERBOSE_MAKEFILE ON)

add_library(sorting
            SHARED
            src/cppmult.cpp
            )


find_package(pybind11 REQUIRED)  # or add_subdirectory(pybind11)
add_library(example MODULE src/cppmult.cpp)


# Include python headers
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
target_include_directories(sorting PRIVATE ${Python3_INCLUDE_DIRS})

# Link against Python lib
find_package(PythonLibs REQUIRED)
target_link_libraries(sorting ${PYTHON_LIBRARIES})

target_link_libraries(example PRIVATE pybind11::module pybind11::lto pybind11::windows_extras)

pybind11_extension(example)
if(NOT MSVC AND NOT ${CMAKE_BUILD_TYPE} MATCHES Debug|RelWithDebInfo)
    # Strip unnecessary sections of the binary on Linux/macOS
    pybind11_strip(example)
endif()

set_target_properties(example PROPERTIES CXX_VISIBILITY_PRESET "hidden"
                                         CUDA_VISIBILITY_PRESET "hidden")


# hook and configure dependencies
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(extern/googletest EXCLUDE_FROM_ALL)
enable_testing()

add_executable(testcpp src/test.cpp)
target_include_directories(testcpp PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(testcpp gtest gtest_main ${PROJECT_NAME})
add_test(NAME testcpp COMMAND testcpp)
target_include_directories(testcpp PRIVATE ${Python3_INCLUDE_DIRS})


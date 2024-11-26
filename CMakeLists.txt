cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

# project name and language
project(sorting LANGUAGES CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_library(sorting
    SHARED
    src/sortArray.cpp
)

# Include pybind11 headers folder
target_include_directories(sorting PRIVATE extern/pybind11/include)
# Include python headers
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
target_include_directories(sorting PRIVATE ${Python3_INCLUDE_DIRS})
# Link against Python libs
find_package(PythonLibs REQUIRED)
target_link_libraries(sorting ${PYTHON_LIBRARIES})



# Py module 
add_subdirectory(extern/pybind11)
pybind11_add_module(pysort src/sortArray.cpp)


# Testing target
add_subdirectory(extern/googletest EXCLUDE_FROM_ALL)
enable_testing()

add_executable(testcpp src/test.cpp)
target_include_directories(testcpp PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(testcpp gtest gtest_main ${PROJECT_NAME})
add_test(NAME testcpp COMMAND testcpp)
target_include_directories(testcpp PRIVATE ${Python3_INCLUDE_DIRS})


# Archive the libs (cpp and python)
add_custom_target(create_tar ALL 
    COMMAND     ${CMAKE_COMMAND} 
    -E tar "cfvz" 
    "libs.tgz" "${CMAKE_BINARY_DIR}/lib"
)
add_dependencies(create_tar sorting)

set(pytestingfolder "${CMAKE_CURRENT_SOURCE_DIR}/pytesting")

# Copy the py module in `pytestingfolder`
add_custom_command(
    TARGET pysort POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_BINARY_DIR}/lib/pysort*
    ${pytestingfolder}/pysort.so
)


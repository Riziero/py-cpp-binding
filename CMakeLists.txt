cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(sorting LANGUAGES CXX)
# set(CMAKE_VERBOSE_MAKEFILE ON)

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




add_subdirectory(extern/pybind11)
pybind11_add_module(pysort src/sortArray.cpp)
# find_package(pybind11 REQUIRED)  # add_subdirectory(pybind11)
# add_library(pysort MODULE src/sortArray.cpp)




# target_link_libraries(pysort PRIVATE pybind11::module pybind11::lto pybind11::windows_extras)

# pybind11_extension(pysort)
# if(NOT MSVC AND NOT ${CMAKE_BUILD_TYPE} MATCHES Debug|RelWithDebInfo)
#     # Strip unnecessary sections of the binary on Linux/macOS
#     pybind11_strip(pysort)
# endif()

# set_target_properties(pysort PROPERTIES CXX_VISIBILITY_PRESET "hidden"
#                                          CUDA_VISIBILITY_PRESET "hidden")


# hook and configure dependencies
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(extern/googletest EXCLUDE_FROM_ALL)
enable_testing()

add_executable(testcpp src/test.cpp)
target_include_directories(testcpp PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(testcpp gtest gtest_main ${PROJECT_NAME})
add_test(NAME testcpp COMMAND testcpp)
target_include_directories(testcpp PRIVATE ${Python3_INCLUDE_DIRS})


add_custom_target(create_tar ALL 
    COMMAND     ${CMAKE_COMMAND} 
    -E tar "cfvz" 
    "libs.tgz" "${CMAKE_BINARY_DIR}/lib"
)
add_dependencies(create_tar sorting)

set(pytestingfolder "${CMAKE_CURRENT_SOURCE_DIR}/pytesting")
# add_custom_target(makepydir ALL COMMAND ${CMAKE_COMMAND} -E make_directory ${pytestingfolder})
add_custom_command(
    TARGET pysort POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_BINARY_DIR}/lib/pysort*
    ${pytestingfolder}/pysort.so
)


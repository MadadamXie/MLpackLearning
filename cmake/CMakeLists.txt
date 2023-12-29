# Indicating the minimum required cmake version
cmake_minimum_required(VERSION 2.8)

# Set project name
project(hello C CXX)

# Options 
option(DEBUG "Compile with debugging information" OFF)

if(CMAKE_COMPILER_IS_GNUCC OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
endif(CMAKE_COMPILER_IS_GNUCC OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lstdc++")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -lstdc++")
  set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -lstdc++")
endif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")

# CMAKE_SOURCE_DIR is the root path of the the project;
# CMAKE_MODULE_PATH is the module path of the the project;
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake")

# Find package armadillo which will generate the following variables:
find_package(Armadillo 3.6.0 REQUIRED)

include_directories(${ARMADILLO_INCLUDE_DIRS})
include_directories(${LIBXML2_INCLUDE_DIR})
find_package(Boost 1.49
    COMPONENTS
      program_options
      unit_test_framework
      random
    REQUIRED
)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

# Collect all header files in the library.
file(GLOB_RECURSE INCLUDE_H_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
file(GLOB_RECURSE INCLUDE_HPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
set(INCLUDE_FILES ${INCLUDE_H_FILES} ${INCLUDE_HPP_FILES})


add_subdirectory(hello)
add_executable(hello_bin hello.cpp)
add_dependencies(hello_bin hello1)

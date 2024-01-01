cmake_minimum_required(VERSION 3.0)
project(cli)

set(Boost_ADDITIONAL_VERSIONS
  "1.49.0" "1.50.0" "1.51.0" "1.52.0" "1.53.0" "1.54.0" "1.55.0")
find_package(Boost 1.49
    COMPONENTS
      program_options
      unit_test_framework
      random
    REQUIRED
  )

add_definitions(-DBOOST_TEST_DYN_LINK)

add_executable(cli_main 
  main.cpp
  cli.cpp 
  cli.hpp
  option.hpp
  option.cpp
)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})


target_link_libraries(
  cli_main
  ${Boost_LIBRARIES}
  )

set(SOURCES 
  hello1.cpp
)

set(DIR_SRCS)
foreach(file ${SOURCES})
  set(DIR_SRCS ${DIR_SRCS} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
endforeach()

set(HELLO_SRC ${HELLO_SRC} ${DIR_SRCS} PARENT_SCOPE)

add_library(hello1 hello1.cpp)

target_link_libraries(hello1
  ${ARMADILLO_LIBRARIES}
  ${Boost_LIBRARIES}
  ${LIBXML2_LIBRARIES}
)

set_target_properties(hello1
  PROPERTIES
  VERSION 1.0
  SOVERSION 1
)



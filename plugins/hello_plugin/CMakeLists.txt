file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
add_library(hello_plugin
             hello_plugin.cpp
             ${HEADERS} )

target_link_libraries(hello_plugin appbase)
target_include_directories(hello_plugin PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")

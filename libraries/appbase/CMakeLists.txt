cmake_minimum_required(VERSION 3.8)
project(AppBase)

set(Boost_NO_SYSTEM_PATHS ON)
find_package(Boost REQUIRED COMPONENTS filesystem program_options)

file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(appbase
             application.cpp
             ${HEADERS}
           )

target_link_libraries(appbase  Boost::asio Boost::program_options Boost::filesystem Threads::Threads)

target_include_directories(appbase
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")

set_target_properties(appbase PROPERTIES PUBLIC_HEADER "${HEADERS}")

find_package(Git)
if(EXISTS ${CMAKE_SOURCE_DIR}/.git AND GIT_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/version.cmake @ONLY)
  add_custom_target(appbase_version ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/version.cmake BYPRODUCTS version.cpp)
  add_dependencies(appbase appbase_version)
else()
  set(VERSION_STRING "Unknown")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.cpp.in ${CMAKE_CURRENT_BINARY_DIR}/version.cpp @ONLY ESCAPE_QUOTES)
endif()
target_sources(appbase PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/version.cpp)

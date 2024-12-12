cmake_minimum_required(VERSION 3.30.0)

set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

project(server CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)
set(CXX_STANDARD_REQUIRED ON)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)
set(VERSION_FULL "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

if ("${CMAKE_GENERATOR}" STREQUAL "Ninja")
   add_compile_options(-fdiagnostics-color=always)
endif()

set(BOOST_ROOT $ENV{VCPKG_ROOT})
set(Boost_DIR $ENV{VCPKG_ROOT})
set(Boost_NO_SYSTEM_PATHS ON)
# find_package(Boost 1.86.0 REQUIRED COMPONENTS system)
find_package(Boost REQUIRED COMPONENTS system asio chrono date_time filesystem iostreams)
find_package(fmt REQUIRED)

add_subdirectory(libraries)
add_subdirectory(plugins)
add_subdirectory(programs)

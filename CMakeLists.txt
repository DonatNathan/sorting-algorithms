cmake_minimum_required(VERSION 3.0)

project(sorting-algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

file(GLOB library_sources "src/*.cpp")

add_library(sorting-lib ${library_sources})

target_include_directories(sorting-lib PUBLIC includes)

target_link_libraries(sorting-lib sfml-audio sfml-graphics sfml-window sfml-system)

add_executable(sort src/main.cpp )

target_link_libraries(sort sorting-lib)

target_include_directories(sort PRIVATE includes)
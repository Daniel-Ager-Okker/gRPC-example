cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(grpc-example CXX)
set(CMAKE_CXX_STANDARD 20)

enable_testing()
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/tests)

add_subdirectory(app)
add_subdirectory(lib)
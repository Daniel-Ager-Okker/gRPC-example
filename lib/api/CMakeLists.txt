cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(lib-api)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(grpc-api)
add_subdirectory(test)

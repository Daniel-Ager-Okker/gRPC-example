cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(lib-sqlite-storage)
set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC
    ./SqliteStorageManager.cpp
)
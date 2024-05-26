cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(app)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} 
    ./main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    lib-grpc-api
    lib-storage
)
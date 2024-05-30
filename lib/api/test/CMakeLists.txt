cmake_minimum_required(VERSION 3.23 FATAL_ERROR)
project(test-api)
set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}
    ./main.cpp
    ./TestClient.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    GTest/include
)

# Link gRPC libraries
option(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)
set(_GRPC_GRPCPP gRPC::grpc++)

target_link_libraries(${PROJECT_NAME} PRIVATE
    gtest
    gtest_main
    lib-api

    ${_PROTOBUF_LIBPROTOBUF}
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/tests/${PROJECT_NAME})
set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/${PROJECT_NAME})

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
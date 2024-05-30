cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(lib-api)
set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC
    ./GrpcAPI.cpp
    ./ServerGRPC.cpp
    ./main.grpc.pb.cc
    ./main.pb.cc
)

# Public headers
target_sources(${PROJECT_NAME} PUBLIC
    FILE_SET lib_grpc_api_HEADERS
    TYPE HEADERS
    BASE_DIRS ../include/
    FILES
        ../include/api/GrpcAPI.h
)

# Link libraries
option(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")

find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)
set(_GRPC_GRPCPP gRPC::grpc++)

target_link_libraries(${PROJECT_NAME} PRIVATE
    lib-storage

  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF}
)

# Generate cpp-files due to proto
execute_process(
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/generate.sh
)
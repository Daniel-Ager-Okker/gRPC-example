cmake_minimum_required(VERSION 3.23 FATAL_ERROR)
project(test-grpc-api)
set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}
    ./main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    GTest/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/tests/${PROJECT_NAME})
set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/${PROJECT_NAME})

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
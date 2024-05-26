cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(lib-storage)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(./src/json-manager)
add_subdirectory(./src/sqlite-manager)
add_subdirectory(./src/postgres-manager)

add_library(${PROJECT_NAME} STATIC
    ./src/IStorageManager.cpp
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    lib-json-storage
    lib-postgres-storage
    lib-sqlite-storage
)

# Public headers
target_sources(${PROJECT_NAME} PUBLIC
    FILE_SET lib_storage_HEADERS
    TYPE HEADERS
    BASE_DIRS ./include/
    FILES
        ./include/storage/IStorageManager.h
        ./include/storage/DTOs.h
)
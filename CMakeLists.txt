cmake_minimum_required(VERSION 2.8)
project(Quickstart)

set(QUICKSTART_MAJOR_VERSION 0)
set(QUICKSTART_MINOR_VERSION 1)
set(QUICKSTART_PATCH_VERSION 0)
set(QUICKSTART_VERSION
    ${QUICKSTART_MAJOR_VERSION}.${QUICKSTART_MINOR_VERSION}.${QUICKSTART_PATCH_VERSION})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(libs)

add_executable(quickstart src/main.cpp)

target_include_directories(quickstart PRIVATE ${CMAKE_SOURCE_DIR}/includes)
target_link_libraries(quickstart library)

cmake_minimum_required(VERSION 2.8)
#[[ In-source build check ]]
if("${CMAKE_BINARY_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
    message(FATAL_ERROR "In-source builds are not allowed.")
    message(WARNING "Remove CMakeFiles/ and CMakeCache.txt in the\
            source root before building again.")
else()
    #[[ Set project version ]]
    project(Quickstart)
    set(QUICKSTART_MAJOR_VERSION 0)
    set(QUICKSTART_MINOR_VERSION 1)
    set(QUICKSTART_PATCH_VERSION 0)
    set(QUICKSTART_VERSION
        ${QUICKSTART_MAJOR_VERSION}.
        ${QUICKSTART_MINOR_VERSION}.
        ${QUICKSTART_PATCH_VERSION})


    #[[ CONSTANTS ]]
    # Compiler options
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # for clangd lsp
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    # File paths
    set(SOURCE_MAIN ${CMAKE_SOURCE_DIR}/src/main.cpp)
    set(SOURCE_INTERNAL_LIBS
        ${CMAKE_SOURCE_DIR}/src/obj.cpp)
    #[[ CONSTANTS END ]]

    #[[ Define the output binary ]]
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    add_executable(Quickstart ${SOURCE_MAIN})

    #[[ Link internal libraries ]]
    add_library(internal_libs ${SOURCE_INTERNAL_LIBS})
    target_include_directories(internal_libs
        PUBLIC ${CMAKE_SOURCE_DIR}/includes
        PUBLIC ${CMAKE_SOURCE_DIR}/src)
    target_link_libraries(Quickstart internal_libs)

    #[[ Link external libraries ]]
    add_subdirectory(libs)
    target_link_libraries(Quickstart external_libs)
endif("${CMAKE_BINARY_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")

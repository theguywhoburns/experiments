cmake_minimum_required(VERSION 3.22)
project(experinents
 LANGUAGES C)

# Disable full macro expansion backtraces for Metalang99.

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c" 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES C_STANDARD 23  C_STANDARD_REQUIRED ON)
target_compile_options(${PROJECT_NAME} PRIVATE -pedantic -ftrack-macro-expansion=0)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

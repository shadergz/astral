cmake_minimum_required(VERSION 3.24)
project(astral VERSION 0.0.1)

add_subdirectory(OpenCL-Headers)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED On)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_C_BYTE_ORDER LITTLE_ENDIAN)

add_executable(astral)
target_sources(astral PRIVATE
        src/local_entry.c
        src/heap_objects.c
        src/terminal.c
        src/valtiel.c
        src/user.c)
target_link_libraries(astral PRIVATE OpenCL::Headers)

target_include_directories(astral PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

cmake_minimum_required(VERSION 3.24)
project(astral VERSION 0.0.1)

add_subdirectory(OpenCL-Headers)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED On)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_C_BYTE_ORDER LITTLE_ENDIAN)

add_executable(astral)
target_sources(astral PRIVATE src/local_entry.c)
target_link_libraries(astral PRIVATE OpenCL::Headers)

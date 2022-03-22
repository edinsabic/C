cmake_minimum_required(VERSION 3.13)
project(cgame VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)

cmake_minimum_required(VERSION 3.13)
project(004_ping_pong VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED PATHS ../libs/SDL2)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(src/app)
include_directories(src/domain)

add_executable(004_ping_pong
        src/app/Window.c
        src/app/Window.h
        src/app/Color.h
        src/domain/Board.c
        src/domain/Board.h
        src/main.c)

target_link_libraries(004_ping_pong ${SDL2_LIBRARIES})




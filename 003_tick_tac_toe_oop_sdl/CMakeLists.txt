cmake_minimum_required(VERSION 3.13)
project(003_tick_tac_toe_oop VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED PATHS ../libs/SDL2)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(src/app)
include_directories(src/domain)

add_executable(003_tick_tac_toe_oop_sdl
        # src/app/terminal.c
        # src/app/terminal.h
        # src/domain/Zeton.c
        # src/domain/Zeton.h
        # src/domain/World.c
        # src/domain/World.h
        # src/domain/utils.c
        # src/domain/utils.h
        src/main.c)

target_link_libraries(003_tick_tac_toe_oop_sdl ${SDL2_LIBRARIES})




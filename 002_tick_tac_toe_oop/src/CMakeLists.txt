find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(app)
include_directories(domain)

add_executable(002_tick_tac_toe_oop
        app/terminal.c
        app/terminal.h
        domain/Zeton.c
        domain/Zeton.h
        domain/World.c
        domain/World.h
        domain/utils.c
        domain/utils.h
        main.c)

target_link_libraries(002_tick_tac_toe_oop ${CURSES_LIBRARIES})

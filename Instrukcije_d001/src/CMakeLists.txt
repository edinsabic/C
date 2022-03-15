find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(app)
include_directories(domain)

add_executable(Instrukcije_d001
        app/terminal.c
        app/terminal.h
        domain/Zeton.c
        domain/Zeton.h
        domain/World.c
        domain/World.h
        main.c)

target_link_libraries(Instrukcije_d001 ${CURSES_LIBRARIES})

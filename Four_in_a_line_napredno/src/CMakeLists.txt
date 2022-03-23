find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(app)
include_directories(domain)

add_executable(Four_in_a_line_napredno
        app/terminal.c
        app/terminal.h
        domain/Zeton.c
        domain/Zeton.h
        domain/World.c
        domain/World.h
        main.c
        )

target_link_libraries(Four_in_a_line_napredno ${CURSES_LIBRARIES})

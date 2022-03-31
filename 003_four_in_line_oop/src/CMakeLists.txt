find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(app)
include_directories(domain)

add_executable(003_four_in_line_oop
        app/terminal.c
        app/terminal.h
        app/utils.c
        app/utils.h
        domain/Zeton.c
        domain/Zeton.h
        domain/Plosca.c
        domain/Plosca.h
        main.c)

target_link_libraries(003_four_in_line_oop ${CURSES_LIBRARIES})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(app)
include_directories(domain)

add_executable(cgame
        app/terminal.c
        app/terminal.h
        domain/Enemy.c
        domain/Enemy.h
        domain/Hero.c
        domain/Hero.h
        domain/Laser.c
        domain/Laser.h
        domain/World.c
        domain/World.h
        main.c)

target_link_libraries(cgame ${CURSES_LIBRARIES})

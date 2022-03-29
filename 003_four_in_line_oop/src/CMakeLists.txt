find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(app)
include_directories(domain)

<<<<<<< HEAD:003_four_in_line_oop/src/CMakeLists.txt
add_executable(Four_in_a_line_napredno
=======
add_executable(002_tick_tac_toe_oop
>>>>>>> main:002_tick_tac_toe_oop/src/CMakeLists.txt
        app/terminal.c
        app/terminal.h
        domain/Zeton.c
        domain/Zeton.h
        domain/World.c
        domain/World.h
<<<<<<< HEAD:003_four_in_line_oop/src/CMakeLists.txt
        main.c
        )

target_link_libraries(Four_in_a_line_napredno ${CURSES_LIBRARIES})
=======
        domain/utils.c
        domain/utils.h
        main.c)

target_link_libraries(002_tick_tac_toe_oop ${CURSES_LIBRARIES})
>>>>>>> main:002_tick_tac_toe_oop/src/CMakeLists.txt

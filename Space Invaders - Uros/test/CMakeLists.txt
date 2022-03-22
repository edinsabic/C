find_library(CMOCKA cmocka)

if (CMOCKA)
    add_executable(state state.c)
    add_dependencies(state state)
    add_test(state state)
    target_link_libraries(state ${CMOCKA})
endif()

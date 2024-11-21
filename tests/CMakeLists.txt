set(SRC_DIR "../src")

set(SOURCES
    ${SRC_DIR}/main.c
)

execute_process(
    COMMAND pkg-config --cflags --libs gtk+-3.0 pango cairo glib-2.0 gobject
    OUTPUT_VARIABLE CMAKE_FLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

message(STATUS "CMake Flags: ${CMAKE_FLAGS}")

add_executable(cengine_tests test-cengine-vector.c)

target_include_directories(cengine_tests PRIVATE ${SRC_DIR})

target_link_libraries(cengine_tests PRIVATE ${CMAKE_FLAGS})

add_test(NAME CengineTests COMMAND cengine_tests)

set_tests_properties(CengineTests PROPERTIES TIMEOUT 300)

add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND}
    COMMENT "Running CTests"
)


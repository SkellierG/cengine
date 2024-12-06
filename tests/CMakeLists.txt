#set(SRC_DIR "../src")

#set(SOURCES
    #${SRC_DIR}/cengine-ivec.c
    #${SRC_DIR}/cengine-vec2.c
    #${SRC_DIR}/cengine-vec3.c
    #${SRC_DIR}/cengine-vec4.c
    #${SRC_DIR}/cengine-vector.c
    #test-cengine-vector.c
#)

#execute_process(
    #COMMAND pkg-config --cflags --libs gtk+-3.0 pango cairo glib-2.0 gobject-2.0
    #OUTPUT_VARIABLE CMAKE_FLAGS
    #OUTPUT_STRIP_TRAILING_WHITESPACE
#)

#message(STATUS "CMake Flags: ${CMAKE_FLAGS}")

#add_executable(cengine_tests test-cengine-vector.c)

#target_include_directories(cengine_tests PRIVATE ${SRC_DIR})

#target_link_libraries(cengine_tests PRIVATE ${CMAKE_FLAGS})

#add_test(NAME CengineTests COMMAND cengine_tests)

#set_tests_properties(CengineTests PROPERTIES TIMEOUT 300)

#add_custom_target(run_tests
#    COMMAND ${CMAKE_CTEST_COMMAND}
#    COMMENT "Running CTests"
#)


set(SOURCES
    vectors/cengine-ivec.c
    vectors/cengine-vec2.c
    vectors/cengine-vec3.c
    vectors/cengine-vec4.c
    vectors/cengine-vector.c
    main.c
)

include_directories(
    /usr/include/glib-2.0
    /usr/lib64/glib-2.0/include
)


execute_process(
    COMMAND pkg-config --cflags --libs gtk+-3.0
    OUTPUT_VARIABLE GTK3_FLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
    COMMAND pkg-config --cflags --libs pango
    OUTPUT_VARIABLE PANGO_FLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
    COMMAND pkg-config --cflags --libs cairo
    OUTPUT_VARIABLE CAIRO_FLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
    COMMAND pkg-config --cflags --libs glib-2.0
    OUTPUT_VARIABLE GLIB_FLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND pkg-config --cflags --libs gobject-2.0
    OUTPUT_VARIABLE GOBJECT_FLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

message(STATUS "GTK3 flags: ${GTK3_FLAGS}")
message(STATUS "Pango flags: ${PANGO_FLAGS}")
message(STATUS "Cairo flags: ${CAIRO_FLAGS}")
message(STATUS "GLib flags: ${GLIB_FLAGS}")
message(STATUS "Gobject flags: ${GOBJECT_FLAGS}")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GTK3_FLAGS} ${PANGO_FLAGS} ${CAIRO_FLAGS} ${GLIB_FLAGS} ${GOBJECT_FLAGS}")

message(STATUS "CMake C Flags: ${CMAKE_C_FLAGS}")

add_executable(cengine_linux ${SOURCES})
set_target_properties(cengine_linux PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${LINUX_OUTPUT_DIR}"
)

#add_executable(cengine_windows.exe ${SOURCES})
#set_target_properties(cengine_windows.exe PROPERTIES
#    RUNTIME_OUTPUT_DIRECTORY "${WINDOWS_OUTPUT_DIR}"
#)



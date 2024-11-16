# Archivos fuente
set(SOURCES
    test.c
)

# Ejecuta pkg-config manualmente para obtener flags de compilación y enlace
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

# Mostrar las banderas de pkg-config
message(STATUS "GTK3 flags: ${GTK3_FLAGS}")
message(STATUS "Pango flags: ${PANGO_FLAGS}")
message(STATUS "Cairo flags: ${CAIRO_FLAGS}")
message(STATUS "GLib flags: ${GLIB_FLAGS}")

# Añadir flags de compilación
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GTK3_FLAGS} ${PANGO_FLAGS} ${CAIRO_FLAGS} ${GLIB_FLAGS}")

# Crear ejecutable para Linux
add_executable(cengine_linux ${SOURCES})
set_target_properties(cengine_linux PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${LINUX_OUTPUT_DIR}"
)

# Crear ejecutable para Windows
add_executable(cengine_windows.exe ${SOURCES})
set_target_properties(cengine_windows.exe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${WINDOWS_OUTPUT_DIR}"
)


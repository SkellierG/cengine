cmake_minimum_required(VERSION 3.10)

project(Cengine VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

enable_testing()

set(BUILD_OUTPUT_DIR "${CMAKE_BINARY_DIR}/dist")
set(LINUX_OUTPUT_DIR "${BUILD_OUTPUT_DIR}/linux")
set(WINDOWS_OUTPUT_DIR "${BUILD_OUTPUT_DIR}/windows")

file(MAKE_DIRECTORY ${LINUX_OUTPUT_DIR})
file(MAKE_DIRECTORY ${WINDOWS_OUTPUT_DIR})

add_subdirectory(src)
add_subdirectory(tests)

add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${LINUX_OUTPUT_DIR} ${WINDOWS_OUTPUT_DIR}
    COMMENT "Cleaning all build artifacts for Linux and Windows"
)

add_custom_target(clean_l
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${LINUX_OUTPUT_DIR}/cengine_linux
    COMMENT "Cleaning Linux build artifacts"
)

add_custom_target(clean_w
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${WINDOWS_OUTPUT_DIR}/cengine_windows.exe
    COMMENT "Cleaning Windows build artifacts"
)


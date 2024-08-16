cmake_minimum_required(VERSION 3.20.0)
project(mantis VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-Wall -I/usr/include/c++/11 -I/usr/include/x86_64-linux-gnu/c++/11")

file(GLOB MANTIS_SOURCES 
    "${PROJECT_SOURCE_DIR}/mantis/src/*.cc"
    "${PROJECT_SOURCE_DIR}/mantis/src/server/*.cc"
)

file(GLOB MANTIS_HEADERS_PRIVATE 
    "${PROJECT_SOURCE_DIR}/mantis/src/*.h"
    "${PROJECT_SOURCE_DIR}/mantis/src/server/*.h"
)

# Build Dependencies
# TODO: build trantor. For now we can just link to the compiled library
add_subdirectory(
    "${PROJECT_SOURCE_DIR}/external/trantor"
)
set(TRANTOR_INCLUDE_DIR
    "${PROJECT_SOURCE_DIR}/external/trantor"
)

add_subdirectory(
    "${PROJECT_SOURCE_DIR}/external/QLogger"
)
set(QLOGGER_INCLUDE_DIR
    "${PROJECT_SOURCE_DIR}/external/QLogger/include"
)


# The include path to specify for building the library
set(MANTIS_INCLUDE_DIR
    "${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}"
)

add_library(${PROJECT_NAME} SHARED ${MANTIS_SOURCES} ${MANTIS_HEADERS})
target_include_directories(${PROJECT_NAME}
    PUBLIC
    "${MANTIS_INCLUDE_DIR}"
    "${TRANTOR_INCLUDE_DIR}"
    "${QLOGGER_INCLUDE_DIR}"
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    trantor
    qlogger
)

# Build examples
file(GLOB SIMPLE_SERVER_SOURCES
    "${PROJECT_SOURCE_DIR}/examples/simple_server/src/*.cc"
)
file(GLOB SIMPLE_SERVER_HEADERS
    "${PROJECT_SOURCE_DIR}/examples/simple_server/include/*.h"
)

add_executable(simple_server ${SIMPLE_SERVER_SOURCES} ${SIMPLE_SERVER_HEADERS})
target_include_directories(simple_server
    PRIVATE
    "${PROJECT_SOURCE_DIR}/examples/simple_server/include"
    "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(simple_server PUBLIC ${PROJECT_NAME})

#Generate compiler commands for using clangd LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

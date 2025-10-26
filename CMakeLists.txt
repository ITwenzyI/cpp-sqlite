cmake_minimum_required(VERSION 4.0)
project(cpp_sqlite)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Alle CPP Dateien automatisch finden (modular / GLOB)
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(database_demo
        ${SOURCES}
        sqlite/sqlite3.c
)

target_include_directories(database_demo PRIVATE sqlite)


# Warnungen aktivieren (unter Windows hilfreich)
if (MSVC)
    target_compile_options(database_demo PRIVATE /W4)
else()
    target_compile_options(database_demo PRIVATE -Wall -Wextra -pedantic)
endif()


cmake_minimum_required(VERSION 3.15)
project(cgen VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(cgen
  src/main.c
  src/npaths.c
  src/projectdata.c
  src/cmakefill.c
)

target_include_directories(cgen PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_options(cgen PRIVATE -Wall -Wextra -Wpedantic)

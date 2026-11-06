#include "../include/cmakefill.h"
#include "../include/projectdata.h"
#include <stdio.h>

char *C_CONFIG = "cmake_minimum_required(VERSION 3.15)\nproject(%s VERSION 1.0.0 LANGUAGES C)\nset(CMAKE_C_STANDARD 17)\nset(CMAKE_C_STANDARD_REQUIRED ON)\nset(CMAKE_C_EXTENSIONS OFF)\n\nadd_executable(%s\n  src/main.c\n)\ntarget_include_directories(%s PRIVATE\n    ${CMAKE_CURRENT_SOURCE_DIR}/include\n)\ntarget_compile_options(%s PRIVATE -Wall -Wextra -Wpedantic)\n";


void CMakeCreateConfig(ProjectData *data) {
     FILE *fd;
     //TODO: Add path
     fd = fopen("CMakeLists.txt", "w");
     if (data->type == PTYPE_C) {
          fprintf(fd, C_CONFIG, data->name, data->name, data->name, data->name);
     }     
}

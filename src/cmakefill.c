#include "../include/cmakefill.h"
#include "../include/projectdata.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *C_CONFIG = "cmake_minimum_required(VERSION 3.15)\nproject(%s VERSION 1.0.0 LANGUAGES C)\nset(CMAKE_C_STANDARD 17)\nset(CMAKE_C_STANDARD_REQUIRED ON)\nset(CMAKE_C_EXTENSIONS OFF)\n\nadd_executable(%s\n  src/main.c\n)\ntarget_include_directories(%s PRIVATE\n    ${CMAKE_CURRENT_SOURCE_DIR}/include\n)\ntarget_compile_options(%s PRIVATE -Wall -Wextra -Wpedantic)\n";

char *CXX_CONFIG = "cmake_minimum_required(VERSION 3.30)\nproject(%s CXX)\n\nset(CMAKE_CXX_STANDARD 23)\nset(CMAKE_CXX_STANDARD_REQUIRED ON)\n\nadd_executable(%s)\n\ntarget_sources(%s PRIVATE\n    src/main.cpp\n)\n\ntarget_include_directories(%s \n    PUBLIC \n        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>\n)\n";

int CMakeCreateConfig(ProjectData *data) {
     FILE *fd;
     char pathBuffer[1024];
     size_t pathSize = sizeof(pathBuffer);
     strncpy(pathBuffer, data->pathdata->path, pathSize);
     strncat(pathBuffer, "/CMakeLists.txt", pathSize);
     fd = fopen(pathBuffer, "w");
     if (fd == NULL) return -1;
     if (data->type == PTYPE_C) {
          fprintf(fd, C_CONFIG, data->name, data->name, data->name, data->name);
     }
     else {
          fprintf(fd, CXX_CONFIG, data->name, data->name, data->name, data->name);
     }
     fclose(fd);
     return 0;
}

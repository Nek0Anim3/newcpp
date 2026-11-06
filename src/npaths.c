#include "../include/npaths.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

PathData *pathCreate(char *buffer, size_t bufSize) {
     fgets(buffer, bufSize, stdin);
     if (buffer[0] == '\n') {
          // if not specified
          getcwd(buffer, bufSize);
          printf("Directory not specified..\nUsing current working dir..\n--  %s\n", buffer);
     }
     else {
          printf("Using directory..\n--  %s\n", buffer);
     }
     PathData *data = (PathData*) calloc(1, sizeof(PathData));
     data->path = buffer;
     data->pathSize = strlen(buffer);
     return data;
}

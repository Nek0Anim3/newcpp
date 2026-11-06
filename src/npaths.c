#include "../include/npaths.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

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

int createProjectPath(char *path, mode_t mode, char *name) {
    strcat(path, "/");
    strcat(path, name);
    char temp_path[1024];
    
    size_t len = strlen(path);

    if (len >= sizeof(temp_path)) {
        errno = ENAMETOOLONG;
        return -1;
    }
    
    strncpy(temp_path, path, sizeof(temp_path));

    for (size_t i = 0; i < len; i++) {
        if (temp_path[i] == '/' && i > 0) {
            temp_path[i] = '\0';
            if (mkdir(temp_path, mode) != 0) {
                if (errno != EEXIST) {
                    return -1; 
                }
            }
            temp_path[i] = '/';
        }
    }
 
    if (mkdir(temp_path, mode) != 0 && errno != EEXIST) {
        return -1;
    }

    return 0;
}

#pragma once
#include <stdint.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct {
     char *path;
     size_t pathSize;
} PathData;

/**
 * Awaits for user input, then allocates path data and |returns pointer to PathData struct|.
 */
PathData* pathCreate(char *buffer, size_t bufSize);

void pathFree(PathData* path);
int createProjectPath(char *path, mode_t mode, char *name);
int createDir(char *path, char *dirName);

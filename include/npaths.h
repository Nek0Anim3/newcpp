#include <stdint.h>
#include <stddef.h>

typedef struct {
     char *path;
     size_t pathSize;
} PathData;

/**
 * Awaits for user input, then allocates path data and |returns pointer to PathData struct|.
 */
PathData* pathCreate(char *buffer, size_t bufSize);

void pathFree(PathData* path);

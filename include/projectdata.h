#include "npaths.h"
#include <stdbool.h>

typedef enum {
     PTYPE_C = 0,
     PTYPE_CXX = 1
} ProjectType;

typedef struct {
     char *name;
     PathData *pathdata;
     ProjectType type;
     bool useCmake;
} ProjectData;


int createProject(ProjectData *data);
void setProjectName(ProjectData *data);
void setProjectType(ProjectData *data);
void setProjectPath(ProjectData *data);
void setUseCmake(ProjectData *data);

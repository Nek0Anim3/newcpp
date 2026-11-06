#include "npaths.h"

typedef enum {
     PTYPE_C = 0,
     PTYPE_CXX = 1
} ProjectType;

typedef struct {
     char *name;
     PathData *pathdata;
     ProjectType type;
} ProjectData;


int createProject();
void setProjectName(ProjectData *data);
void setProjectType(ProjectData *data);
void setProjectPath(ProjectData *data);

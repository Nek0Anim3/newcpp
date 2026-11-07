#include <stdio.h>
#include <unistd.h>
#include "../include/projectdata.h"
#include <stdlib.h>
#include "../include/cmakefill.h"
int main() {
     ProjectData *projData = (ProjectData *)calloc(1, sizeof(ProjectData));
     printf("New project creation...\n");
     setProjectName(projData);
     printf("Select language:\n 0 - C Language (default)\n 1 - C++\nInput (0 or 1) > ");
     setProjectType(projData);
     printf("\nSpecify directory for project (enter = current dir)\nInput (absolute) > ");
     setProjectPath(projData);
     printf("\nShould project use CMake tool?\n 0 - No\n 1 - Yes (default)\nInput (0 or 1) > ");
     setUseCmake(projData);
    
     createProject(projData);
     return 0;
    
}

#include "../include/projectdata.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// some colored text woo-hoo
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

void setProjectName(ProjectData *data) {
     char bannedChars[] = "!@#$%^&*()+={}[]:;\"'<>,.?/|\\";
     size_t bufSize = 256;
     char *nameBuff = (char*) calloc(bufSize, sizeof(char));

     while (1) {
          printf("Name a project (enter = untitled) > ");
          fgets(nameBuff, bufSize, stdin);
          if (strpbrk(nameBuff, bannedChars) != NULL) {
               printf("Special characters not allowed!\n");
               continue;
          } else {
               if (nameBuff[0] == '\n') {
                    strncpy(nameBuff, "untitled", bufSize);
               }
               break;
          }
     }
     data->name = nameBuff;
     printf(GREEN "[+] Set Project Name: %s\n" RESET, nameBuff);
}

void setProjectType(ProjectData *data) {
     char buffer[16];
     char typeText[16];
  
     while (1) {
          fgets(buffer, 16, stdin);
          switch (buffer[0]) {
              case '\n':
              case '0':
                   data->type = PTYPE_C;
                   strncpy(typeText, "Plain C", 16);
                   break;
              case '1':
                   data->type = PTYPE_CXX;
                   strncpy(typeText, "C++", 16);
                   break;
              default:
                   printf("Not valid. Type 0 or 1...\n");
                   printf("Input (0 or 1) > ");
                   continue;
          }
          break;
     }
     if (data->type == 0 || data->type == 1) {
          printf(GREEN "[+] Set Project Type: %s\n" RESET, typeText);
     }
}

void setProjectPath(ProjectData *data) {
     char buffer[1024];
     PathData *pathData = pathCreate(&buffer[0], sizeof(buffer));
     data->pathdata = pathData;
     if (pathData->path != NULL) {
          printf(GREEN "[+] Set Project Directory: %s\n" RESET, pathData->path);
     }
}

void setUseCmake(ProjectData *data) {
     char buffer[16];
     char typeText[16];
  
     while (1) {
          fgets(buffer, 16, stdin);
          switch (buffer[0]) {
              case '\n':
              case '1':
                   data->useCmake = true;
                   strncpy(typeText, "Yes", 16);
                   break;
              case '0':
                   data->useCmake = false;
                   strncpy(typeText, "No", 16);
                   break;
              default:
                   printf("Not valid. Type 0 or 1...\n");
                   printf("Input (0 or 1) > ");
                   continue;
          }
          break;
     }
     if (data->useCmake == 0) {
          printf(RED "[-] Use Cmake?: %s\n" RESET, typeText);
     } else {
          printf(GREEN "[+] Use Cmake?: %s\n" RESET, typeText);
     }
}

void printProjectData(ProjectData *data) {
     printf("Project '%s':\n  Language -- %s\n  Path -- %s\n", data->name, "STUB REMOVEPLS", data->pathdata->path);
}

int createProject(ProjectData *data) {
     return 0;
}


#ifndef TASKGENERATOR_H
#define TASKGENERATOR_H

#include "Task.h"

int generatePriority(int id);
int generateCPU(int id);
int generateRAM(int id);
int generateStorage(int id);

Task generateTask(int id);

#endif
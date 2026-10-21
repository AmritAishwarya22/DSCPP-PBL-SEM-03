#ifndef TASK_H
#define TASK_H

typedef struct
{
    int id;
    int priority;
    int cpu;
    int ram;
    int storage;
} Task;

#define MAX_TASKS 100

#endif
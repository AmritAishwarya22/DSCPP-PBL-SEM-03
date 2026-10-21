#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#include "Task.h"

typedef struct Node
{
    Task task;
    struct Node* next;
} Node;

typedef struct
{
    Node* front;
    int count;
    int capacity;
} TaskQueue;

void initializeQueue(TaskQueue* q, int capacity);
int isEmpty(TaskQueue* q);
int isFull(TaskQueue* q);
int queueSize(TaskQueue* q);
int enqueue(TaskQueue* q, Task task);
int dequeue(TaskQueue* q, Task* task);
void displayQueue(TaskQueue* q);
void clearQueue(TaskQueue* q);

#endif
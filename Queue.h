#ifndef QUEUE_H
#define QUEUE_H
#include "Task.h"
#define MAX 100
extern struct Task queue[MAX];
extern int front;
extern int rear;
void enqueue(struct Task task);
void dequeue();
int isEmpty();
void display();
#endif
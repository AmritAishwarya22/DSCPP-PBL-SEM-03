#include <stdio.h>
#include "Queue.h"
void enqueue(struct Task task) 
{
 if ((rear + 1) % MAX == front) 
 {
  printf("Queue is full \n");
 }
  else
 {
  if (front == -1) 
  {
   front = 0;
  }
  rear = (rear + 1) % MAX;
  queue[rear] = task;
  printf("Task added sucessfully \n");
 }
}
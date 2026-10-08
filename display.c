#include <stdio.h>
#include "Queue.h"
void display() 
{
 int i;
 if (front == -1) 
 {
  printf("Queue is empty \n");
 }
 else
 {
  printf("Queue is \n");
  int i = front;
  do
  {
   printf("Task ID = %d \n", queue[i].id);
   printf("Priority = %d\n", queue[i].priority);
   printf("CPU = %d\n", queue[i].cpu);
   printf("RAM = %d\n", queue[i].ram);
   i= (i + 1) % MAX;
  } 
   while (i != (rear + 1) % MAX);
  }
}
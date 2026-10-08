#include <stdio.h>
#include "Queue.h"
void dequeue() 
{
 if (front == -1) 
 {
  printf("Queue is empty \n");
 }
 else 
 {
  printf("Dequeued Task = %d \n", queue[front].id);
  if (front == rear) 
  {
   front = -1;
   rear = -1;
  } 
  else 
  {
    front = (front + 1) % MAX;
   }
 }
}
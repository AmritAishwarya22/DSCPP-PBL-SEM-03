#include <stdio.h>
#include <stdlib.h>
#include "TaskQueue.h"

void initializeQueue(TaskQueue* q, int capacity)
{
    q->front = NULL;
    q->count = 0;
    q->capacity = capacity;
}

int isEmpty(TaskQueue* q)
{
    return q->front == NULL;
}

int isFull(TaskQueue* q)
{
    return q->count >= q->capacity;
}

int queueSize(TaskQueue* q)
{
    return q->count;
}

int enqueue(TaskQueue* q, Task task)
{
    if (isFull(q))
    {
        printf("Queue is full. Task %d rejected.\n", task.id);
        return 0;
    }

    Node* newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    newNode->task = task;
    newNode->next = NULL;

    if (q->front == NULL ||
        task.priority > q->front->task.priority)
    {
        newNode->next = q->front;
        q->front = newNode;
    }
    else
    {
        Node* temp = q->front;

        while (temp->next != NULL &&
               temp->next->task.priority >= task.priority)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    q->count++;
    return 1;
}

int dequeue(TaskQueue* q, Task* task)
{
    if (isEmpty(q))
    {
        return 0;
    }

    Node* temp = q->front;

    *task = temp->task;
    q->front = temp->next;

    free(temp);
    q->count--;

    return 1;
}

void displayQueue(TaskQueue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = q->front;
    int position = 1;

    printf("\n========== PRIORITY QUEUE ==========\n");
    printf("Front -> Highest priority first\n\n");

    while (temp != NULL)
    {
        printf("Position %d | Task ID: %d | Priority: %d"
               " | CPU: %d vCPU | RAM: %d GB"
               " | Storage: %d GB\n",
               position,
               temp->task.id,
               temp->task.priority,
               temp->task.cpu,
               temp->task.ram,
               temp->task.storage);

        temp = temp->next;
        position++;
    }

    printf("\nRear -> Lowest priority last\n");
    printf("Queue size: %d/%d\n", q->count, q->capacity);
}

void clearQueue(TaskQueue* q)
{
    Node* temp;

    while (q->front != NULL)
    {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }

    q->count = 0;
}
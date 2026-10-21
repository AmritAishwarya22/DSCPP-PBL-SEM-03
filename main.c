#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TaskQueue.h"

int randomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
}

Task generateTask(int id)
{
    Task task;

    task.id = id;
    task.priority = randomNumber(1, 5);
    task.cpu = randomNumber(1, 16);
    task.ram = randomNumber(1, 64);
    task.storage = randomNumber(10, 500);

    return task;
}

void displayTask(Task task)
{
    printf("Task %d | Priority: %d | CPU: %d vCPU"
           " | RAM: %d GB | Storage: %d GB\n",
           task.id,
           task.priority,
           task.cpu,
           task.ram,
           task.storage);
}

int main(void)
{
    TaskQueue q;
    Task tasks[MAX_TASKS];
    Task selectedTask;
    int numberOfTasks;
    int i;

    srand((unsigned int)time(NULL));

    printf("====================================\n");
    printf(" CLOUD SERVER TASK QUEUE SIMULATOR\n");
    printf("====================================\n");

    printf("Enter number of tasks (1-%d): ", MAX_TASKS);

    if (scanf("%d", &numberOfTasks) != 1 ||
        numberOfTasks < 1 ||
        numberOfTasks > MAX_TASKS)
    {
        printf("Invalid number of tasks.\n");
        return 1;
    }

    initializeQueue(&q, MAX_TASKS);

    printf("\nGenerating %d tasks automatically...\n",
           numberOfTasks);

    for (i = 0; i < numberOfTasks; i++)
    {
        tasks[i] = generateTask(i + 1);
    }

    printf("\n========== GENERATED TASKS ==========\n");

    for (i = 0; i < numberOfTasks; i++)
    {
        displayTask(tasks[i]);
    }

    printf("\n========== ENQUEUE PROCESS ==========\n");

    for (i = 0; i < numberOfTasks; i++)
    {
        if (enqueue(&q, tasks[i]))
        {
            printf("Task %d inserted into priority queue"
                   " | Priority: %d\n",
                   tasks[i].id,
                   tasks[i].priority);
        }
        else
        {
            clearQueue(&q);
            return 1;
        }
    }

    displayQueue(&q);

    printf("\n========== DEQUEUE PROCESS ==========\n");
    printf("Tasks will now be removed by priority.\n\n");

    while (!isEmpty(&q))
    {
        if (dequeue(&q, &selectedTask))
        {
            printf("Selected Task: %d | Priority: %d"
                   " | CPU: %d vCPU | RAM: %d GB"
                   " | Storage: %d GB | Remaining: %d\n",
                   selectedTask.id,
                   selectedTask.priority,
                   selectedTask.cpu,
                   selectedTask.ram,
                   selectedTask.storage,
                   queueSize(&q));
        }
    }

    printf("\nQueue empty: %s\n",
           isEmpty(&q) ? "Yes" : "No");

    clearQueue(&q);

    printf("All tasks have been displayed and dequeued.\n");

    return 0;
}
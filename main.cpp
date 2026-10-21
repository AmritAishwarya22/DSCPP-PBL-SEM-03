
#include <iostream>
#include "TaskGenerator.h"

using namespace std;

int main()
{
    int numberOfTasks;

    cout << "===== Automatic Task Generator =====" << endl;
    cout << "Enter number of tasks (0-1000): ";
    cin >> numberOfTasks;

    if (cin.fail() || numberOfTasks < 0 ||
        numberOfTasks > 1000)
    {
        cout << "Invalid input! Enter a number from 0 to 1000."
             << endl;
        return 1;
    }

    Task tasks[1000];

    for (int i = 0; i < numberOfTasks; i++)
    {
        tasks[i] = generateTask(i + 1);
    }

    cout << endl;
    cout << "===== Generated Tasks =====" << endl;

    for (int i = 0; i < numberOfTasks; i++)
    {
        cout << "Task ID: " << tasks[i].id << endl;
        cout << "Priority: " << tasks[i].priority << endl;
        cout << "CPU Required: " << tasks[i].cpu << " units" << endl;
        cout << "RAM Required: " << tasks[i].ram << " GB" << endl;
        cout << "Storage Required: "
             << tasks[i].storage << " GB" << endl;

        cout << "--------------------------" << endl;
    }

    cout << "Total tasks generated: "
         << numberOfTasks << endl;

    return 0;
}
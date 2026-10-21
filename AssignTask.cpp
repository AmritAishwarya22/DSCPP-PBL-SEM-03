
#include <iostream>
#include "Server.h"
using namespace std;

void Server::assignTask(int cpu, int ram, int storage)
{
    if (canHandle(cpu, ram, storage))
    {
        usedCPU += cpu;
        usedRAM += ram;
        usedStorage += storage;

        cout << "Task assigned to Server "
             << serverId << endl;
    }
    else
    {
        cout << "Insufficient resources on Server "
             << serverId << endl;
    }
}

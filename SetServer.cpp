#include "Server.h"

void Server::setServer(int id, int cpu, int ram, int storage)
{
    serverId = id;
    totalCPU = cpu;
    totalRAM = ram;
    totalStorage = storage;

    usedCPU = usedRAM = usedStorage = 0;
}
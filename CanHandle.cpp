#include "Server.h"

int Server::canHandle(int cpu, int ram, int storage)
{
    return (cpu <= totalCPU - usedCPU &&
            ram <= totalRAM - usedRAM &&
            storage <= totalStorage - usedStorage);
}
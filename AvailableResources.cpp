#include "Server.h"

int Server::availableResources()
{
    return (totalCPU - usedCPU) +
           (totalRAM - usedRAM) +
           (totalStorage - usedStorage);
}
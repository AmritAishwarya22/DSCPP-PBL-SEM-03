#include "LoadBalancer.h"
double calculateUtilization(Server s)
{
 double cpu = (double)s.usedCPU / s.totalCPU;
 double ram = (double)s.usedRAM / s.totalRAM;
 double storage = (double)s.usedStorage / s.totalStorage;
 double total = (cpu + ram + storage) * 100 / 3;
 return total;
}
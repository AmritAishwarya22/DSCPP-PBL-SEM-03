#include "LoadBalancer.h"
int selectServer(Server s[], int n, Task t)
{
 int best = -1;
 int i;
 int freeCPU, freeRAM, freeStorage , use;
 double cpu , ram , storage;
 double lowest = 101.0;
 for (i = 0; i < n; i++)
 {
  freeCPU = s[i].totalCPU - s[i].usedCPU;
  freeRAM = s[i].totalRAM - s[i].usedRAM;
  freeStorage = s[i].totalStorage - s[i].usedStorage;
  if (freeCPU >= t.cpu &&freeRAM >= t.ram &&freeStorage >= t.storage)
  {
   cpu = (double)s[i].usedCPU / s[i].totalCPU;
   ram = (double)s[i].usedRAM / s[i].totalRAM;
   storage = (double)s[i].usedStorage / s[i].totalStorage;
   use = (cpu + ram + storage) * 100.0 / 3.0;
   if (use < lowest)
   {
    lowest = use;
    best = i;
   }
  }
 }
 return best;
}
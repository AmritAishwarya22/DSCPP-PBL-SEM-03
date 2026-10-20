#include "LoadBalancer.h"
bool checkEligibility(Server s, Task t)
{
 if (s.totalCPU - s.usedCPU >= t.cpu &&s.totalRAM - s.usedRAM >= t.ram &&s.totalStorage - s.usedStorage >= t.storage)
 {
  return true;
 }
 return false;
}
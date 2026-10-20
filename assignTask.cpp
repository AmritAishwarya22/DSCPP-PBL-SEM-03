#include "LoadBalancer.h"
void assignTask(Server &s, Task t)
{
 if (s.totalCPU - s.usedCPU >= t.cpu &&s.totalRAM - s.usedRAM >= t.ram &&s.totalStorage - s.usedStorage >= t.storage)
 {
  s.usedCPU = s.usedCPU + t.cpu;
  s.usedRAM = s.usedRAM + t.ram;
  s.usedStorage = s.usedStorage + t.storage;
 }
}
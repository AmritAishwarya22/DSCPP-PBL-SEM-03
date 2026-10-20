#ifndef LOADBALANCER_H
#define LOADBALANCER_H
struct Server
{
 int id;
 int totalCPU, totalRAM, totalStorage;
 int usedCPU, usedRAM, usedStorage;
};

struct Task
{
 int id;
 int cpu, ram, storage;
};
bool checkEligibility(Server s, Task t);
double calculateUtilization(Server s);
int selectServer(Server s[], int n, Task t);
void assignTask(Server &s, Task t);
#endif
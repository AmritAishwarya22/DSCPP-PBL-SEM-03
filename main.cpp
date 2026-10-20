#include <iostream>
#include "LoadBalancer.h"
using namespace std;
int main()
{
 Server s[10];
 Task t;
 int n;
 cout << "Enter number of servers \n";
 cin >> n;
 if (n < 1 || n > 10)
 {
  cout << "Invalid servers";
  return 0;
 }
 for (int i = 0; i < n; i++)
 {
  s[i].id = i + 1;
  cout << "Enter details of Server \n" << i + 1 << endl;
  cout << "Enter total CPU in cores";
  cin >> s[i].totalCPU;
  cout << "Enter total RAM in GB";
  cin >> s[i].totalRAM;
  cout << "Enter total Storage in GB";
  cin >> s[i].totalStorage;
  if (s[i].totalCPU <= 0 ||s[i].totalRAM <= 0 ||s[i].totalStorage <= 0)
  {
   cout << "Invalid Resource";
   return 0;
  }
  s[i].usedCPU = 0;
  s[i].usedRAM = 0;
  s[i].usedStorage = 0;
 }
 cout << "Enter Task ID \n";
 cin >> t.id;
 cout << "Enter Task CPU in cores \n";
 cin >> t.cpu;
 cout << "Enter Task RAM in GB \n";
 cin >> t.ram;
 cout << "Enter Task Storage in GB \n";
 cin >> t.storage;
 cout << "Servers are\n";
 for (int i = 0; i < n; i++)
 {
  cout << "\nServer " << s[i].id;
  if (checkEligibility(s[i], t))
  {
   cout << " Task can be run \n";
  }
  else
  {
   cout << " Task cannot be run \n";
  }
  cout << "\nUtilization: " << calculateUtilization(s[i]) << "%\n";
 }
 int selected = selectServer(s, n, t);
 if (selected == -1)
 {
  cout << "No suitable server available\n";
 }
 else
 {
  cout << "\nSelected Server: " << s[selected].id;
  assignTask(s[selected], t);
  cout << "Task assigned successfully\n";
 }
 cout << "Final Server Details:\n";
 for (int i = 0; i < n; i++)
 {
  cout << "Server is " << s[i].id;
  cout << "CPU is " << s[i].usedCPU << "/" << s[i].totalCPU;
  cout << "RAM is " << s[i].usedRAM << "/" << s[i].totalRAM;
  cout << "Storage is " << s[i].usedStorage << "/" << s[i].totalStorage;
 }
 return 0;
}   
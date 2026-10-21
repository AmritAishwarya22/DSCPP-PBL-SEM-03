
#include <iostream>
#include "Server.h"
using namespace std;

void Server::displayServer()
{
    cout << "\nServer ID: " << serverId;
    cout << "\nCPU Used: " << usedCPU << "/" << totalCPU;
    cout << "\nRAM Used: " << usedRAM << "/" << totalRAM;
    cout << "\nStorage Used: " << usedStorage
         << "/" << totalStorage << endl;
}

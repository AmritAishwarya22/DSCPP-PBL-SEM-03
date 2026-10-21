
#include <iostream>
#include "Server.h"
using namespace std;

int main()
{
    Server servers[3];

    servers[0].setServer(1, 100, 200, 500);
    servers[1].setServer(2, 150, 300, 600);
    servers[2].setServer(3, 200, 400, 800);

    servers[0].assignTask(20, 50, 100);
    servers[1].assignTask(40, 100, 200);

    for (int i = 0; i < 3; i++)
    {
        servers[i].displayServer();
    }

    return 0;
}

#ifndef SERVER_H
#define SERVER_H

class Server
{
private:
    int serverId;

    int totalCPU, totalRAM, totalStorage;
    int usedCPU, usedRAM, usedStorage;

public:
    Server();

    void setServer(int id, int cpu, int ram, int storage);

    int canHandle(int cpu, int ram, int storage);
    int availableResources();

    void assignTask(int cpu, int ram, int storage);
    void displayServer();
};

#endif

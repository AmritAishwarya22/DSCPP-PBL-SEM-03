
#include "TaskGenerator.h"

Task generateTask(int id)
{
    Task t;

    t.id = id;
    t.priority = generatePriority(id);
    t.cpu = generateCPU(id);
    t.ram = generateRAM(id);
    t.storage = generateStorage(id);

    return t;
}
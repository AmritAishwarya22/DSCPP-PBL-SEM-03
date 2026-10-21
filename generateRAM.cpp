
#include "TaskGenerator.h"

int generateRAM(int id)
{
    return ((id % 8) + 1) * 2;
}
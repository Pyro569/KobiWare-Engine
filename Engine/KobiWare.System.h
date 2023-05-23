#include <KobiWare/KobiWare.Include.h>

void debugLog(char *Message)
{
    std::cout << Message;
}

bool inRange(unsigned low, unsigned high, unsigned x)
{
    return ((x - low) <= (high - low));
}
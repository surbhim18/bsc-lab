#include "Packet.h"
#include<cstring>

Packet:: Packet()
{
    data = new char[maxPacketSize];
}

Packet:: ~Packet()
{
    delete []data;
}

Packet& Packet:: operator=(Packet& P)
{
    char *newData = new char[maxPacketSize];
    strcpy(newData,P.data);

    this->data = newData;
    return (*this);
}

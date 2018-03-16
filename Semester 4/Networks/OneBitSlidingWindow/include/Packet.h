#ifndef PACKET_H
#define PACKET_H

#define maxPacketSize 50

class Packet
{
    public:
        char* data;
        Packet();
        Packet& operator=(Packet&);
        ~Packet();

};

#endif // PACKET_H

#include <iostream>
#include<cstring>
#include "Packet.h"
#include "Frame.h"

using namespace std;

enum eventType {frameArrival,error,unknown};
bool isFrameArrival= false;
bool isError=false;

Frame frameAtPhyLayer;
bool isFrameAtPhyLayer = false;

void from_NL(Packet &p)
{
    cout<<"\nEnter data: ";
    cin.getline(p.data,maxPacketSize);
}

void from_PL(Frame &f)
{
    if(isFrameAtPhyLayer)
    {
      f = frameAtPhyLayer;
      isFrameAtPhyLayer = false;
    }
    else
        cout<<"Frame not at Physical Layer!\n";
}

void to_NL(Packet &p)
{
    cout<<"Data      : ";
    cout<<p.data<<endl;
}

void to_PL(Frame &f)
{
    frameAtPhyLayer = f;
    isFrameAtPhyLayer = true;
}

void wait_for_event(eventType &event)
{
    if(isFrameAtPhyLayer)
    {
        isFrameArrival = true;
        event = frameArrival;
    }
    else
    {
        isError = true;
        event = error;
    }
}

void receiver1();
void sender1()
{
    Frame s;
    Packet buffer;

    from_NL(buffer);
    s.info = buffer;
    to_PL(s);
}

void receiver1()
{
    Frame r;
    eventType event;

    wait_for_event(event);
    from_PL(r);
    to_NL(r.info);
}

/*
void receiver2();
void sender2()
{
    Frame s;
    Packet buffer;
    eventType event;

    from_NL(buffer);
    s.info = buffer;
    to_PL(s);

    wait_for_event(event);
}

void receiver2()
{
    Frame r;
    eventType event;

    wait_for_event(event);
    from_PL(r);
    to_NL(r.info);
}
*/

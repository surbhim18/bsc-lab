#include<iostream>
#include "Frame.h"
#include "Packet.h"

using namespace std;

enum eventType {frameArrival,error,unknown};
bool isFrameArrival= false;
bool isError=false;

Frame frameAtPhyLayer;
bool  isFrameAtPhyLayer = false;

void from_NL(Packet &p)
{
    cout<<"\nEnter data: ";
    cin.getline(p.data,maxPacketSize);
}

void from_PL(Frame &f)
{
    if(isFrameAtPhyLayer)
        f = frameAtPhyLayer;
    else
        cout<<"Frame not at Physical Layer!\n";
}

void to_NL(Packet &p)
{
    cout<<"\nData: ";
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

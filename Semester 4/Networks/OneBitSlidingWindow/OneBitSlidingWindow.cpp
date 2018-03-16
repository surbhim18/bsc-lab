#include <iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include "Packet.h"
#include "Frame.h"

#define MAX_SEQ 1

using namespace std;

enum eventType {frameArrival,chksumError, timeout};

Frame frameAtPhyLayerSys1;
bool isFrameAtPhyLayerSys1 = false;

Frame frameAtPhyLayerSys2;
bool isFrameAtPhyLayerSys2 = false;

bool startSys1 = true;
bool startSys2 = true;

time_t startTimeSys1;
time_t newTimeSys1;

time_t startTimeSys2;
time_t newTimeSys2;

int random(int n)
{
    srand((unsigned)time(NULL));
    return rand()%n;
}

void inc(seq_no &s)
{
    if(s==0)
        s=1;
    else
        s=0;
}

void start_timer_system1(seq_no s)
{
    time(&startTimeSys1);
}

void stop_timer_system1(seq_no s)
{
    startTimeSys1 = 0;
}

void start_timer_system2(seq_no s)
{
    time(&startTimeSys2);
}

void stop_timer_system2(seq_no s)
{
    startTimeSys2 = 0;
}

void from_NL_system1(Packet &p)
{
    cout<<"\nData to be sent from System1: ";
    cin.getline(p.data,maxPacketSize);
}

void to_NL_system1(Packet &p)
{
    cout<<"\nData received at System1    : ";
    cout<<p.data;
}

void from_NL_system2(Packet &p)
{
    cout<<"\nData to be sent from System2: ";
    cin.getline(p.data,maxPacketSize);
}

void to_NL_system2(Packet &p)
{
    cout<<"\nData received at System2    : ";
    cout<<p.data;
}

void to_PL_system1(Frame &f)
{
    frameAtPhyLayerSys1 = f;
    isFrameAtPhyLayerSys1 = true;
}

void to_PL_system2(Frame &f)
{
    frameAtPhyLayerSys2 = f;
    isFrameAtPhyLayerSys2 = true;
}

void from_PL_system1(Frame &f)
{
    if(isFrameAtPhyLayerSys1)
    {
        f = frameAtPhyLayerSys1;
        isFrameAtPhyLayerSys1 = false;
    }
    else
        cout<<"Frame not at Physical Layer of System 1!\n";
}

void from_PL_system2(Frame &f)
{
    if(isFrameAtPhyLayerSys2)
    {
        f = frameAtPhyLayerSys2;
        isFrameAtPhyLayerSys2 = false;
    }
    else
        cout<<"Frame not at Physical Layer of System 2!\n";
}

void wait_for_event_system1(eventType &event)
{
    double diff = difftime(newTimeSys2,startTimeSys2);

    if(diff >= 5)
    {
        event = timeout;
        cout<<"\nTimeout at System 1.";
    }
    else
    {
        int ch=random(10);
        if(ch!=0)
        {
            event = frameArrival;
        }
        else
        {
            event = chksumError;
            cout<<"\nError in receiving piggybacked data frame from System 2.";
        }
    }
}

void wait_for_event_system2(eventType &event)
{
    double diff = difftime(newTimeSys1,startTimeSys1);

    if(diff >= 5)
    {
        event = timeout;
        cout<<"\nTimeout at System 2.";
    }
    else
    {
        int ch=random(10);
        if(ch!=0)
        {
            event = frameArrival;
        }
        else
        {
            event = chksumError;
            cout<<"\nError in receiving piggybacked data frame from System 1.";
        }
    }
}

//communication starts from this system
void system1()
{
    static seq_no next_frame_to_send=0;
    static seq_no frame_expected =0;
    static Packet buffer;

    Frame r,s;
    eventType event;

    if(!startSys1)
        wait_for_event_system1(event);

    if(startSys1==false && event == frameArrival)
    {
        from_PL_system2(r);
        if(r.seqNo == frame_expected)
        {
            cout<<"\nFrame "<<r.seqNo<<" received at System 1 from System 2.";
            to_NL_system1(r.info);
            inc(frame_expected);
        }
        if(r.ackNo == next_frame_to_send)
        {
            stop_timer_system1(r.ackNo);
            cout<<"\nAcknowledgement frame for "<<r.ackNo<<" received at System 1.";
            from_NL_system1(buffer);
            inc(next_frame_to_send);
        }
        time(&newTimeSys1);
    }
    else if(event == chksumError)
    {
        newTimeSys1 = startTimeSys1+5;
    }

    if(startSys1)
    {
        from_NL_system1(buffer);
        startSys1 = false;
    }

    s.info = buffer;
    s.seqNo = next_frame_to_send;
    s.ackNo = 1- frame_expected;

    to_PL_system1(s);
    start_timer_system1(s.seqNo);
    cout<<"\nFrame "<<s.seqNo<<" sent from System 1 to System 2.";
}

void system2()
{
    static seq_no next_frame_to_send=0;
    static seq_no frame_expected =0;
    static Packet buffer;

    Frame r,s;
    eventType event;

    wait_for_event_system2(event);

    if(event == frameArrival)
    {
        from_PL_system1(r);
        if(r.seqNo == frame_expected)
        {
            cout<<"\nFrame "<<r.seqNo<<" received at System 2 from System 1.";
            to_NL_system2(r.info);
            inc(frame_expected);
        }
        if(startSys2== true || r.ackNo == next_frame_to_send)
        {
            if(!startSys2)
            {
                stop_timer_system2(r.ackNo);
                cout<<"\nAcknowledgement frame for "<<r.ackNo<<" received at System 2.";
                inc(next_frame_to_send);
            }
            else
            {
                startSys2 = false;
            }
            from_NL_system2(buffer);
        }
        time(&newTimeSys2);
    }
    else if(event == chksumError)
    {
        newTimeSys2 = startTimeSys2+5;
    }

    s.info = buffer;
    s.seqNo = next_frame_to_send;
    s.ackNo = 1- frame_expected;

    to_PL_system2(s);
    start_timer_system2(s.seqNo);
    cout<<"\nFrame "<<s.seqNo<<" sent from System 2 to System 1.";
}

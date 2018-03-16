#include <iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include "Packet.h"
#include "Frame.h"

#define MAX_SEQ 1

using namespace std;

enum eventType {frameArrival,chksumError, timeout};

Frame frameAtPhyLayer;
bool isFrameAtPhyLayer = false;

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

void from_NL(Packet &p)
{
    cout<<"\nData to be sent : ";
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
    cout<<"\nData received   : ";
    cout<<p.data;
}

void to_PL(Frame &f)
{
    frameAtPhyLayer = f;
    isFrameAtPhyLayer = true;
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
        from_PL(r);
        if(r.seqNo == frame_expected)
        {
            cout<<"\nFrame "<<r.seqNo<<" received at System 1 from System 2.";
            to_NL(r.info);
            inc(frame_expected);
        }
        if(r.ackNo == next_frame_to_send)
        {
            stop_timer_system1(r.ackNo);
            cout<<"\nAcknowledgement frame for "<<r.ackNo<<" received at System 1.";
            from_NL(buffer);
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
        from_NL(buffer);
        startSys1 = false;
    }

    s.info = buffer;
    s.seqNo = next_frame_to_send;
    s.ackNo = 1- frame_expected;

    to_PL(s);
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
        from_PL(r);
        if(r.seqNo == frame_expected)
        {
            cout<<"\nFrame "<<r.seqNo<<" received at System 2 from System 1.";
            to_NL(r.info);
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
            from_NL(buffer);
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

    to_PL(s);
    start_timer_system2(s.seqNo);
    cout<<"\nFrame "<<s.seqNo<<" sent from System 2 to System 1.";
}


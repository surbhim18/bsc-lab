#include <iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include "Packet.h"
#include "Frame.h"

using namespace std;

enum eventType {frameArrival,chksumError, timeout};

Frame frameAtPhyLayer;
bool isFrameAtPhyLayer = false;

bool start = true;
//bool complete = false;

#define inc(s) if(s==0) s=1; else s=0;

//srand((unsigned)time(NULL));
time_t startTime;
time_t newTime;

int random(int n)
{
    srand((unsigned)time(NULL));
    return rand()%n;
}

void start_timer(seq_no s)
{
    time(&startTime);
}

void stop_timer(seq_no s)
{
    startTime = 0;
}

void from_NL(Packet &p)
{
    cout<<"\nEnter data : ";
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
    cout<<"\nData : ";
    cout<<p.data;
}

void to_PL(Frame &f)
{
    frameAtPhyLayer = f;
    isFrameAtPhyLayer = true;
}

void wait_for_event_sender(eventType &event)
{
    //set event as frame arrival or error or timeout
    double diff = difftime(newTime,startTime);

    if(diff >= 5)
    {
        event = timeout;
        cout<<"\nTimeout.";
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
            cout<<"\nError in receiving acknowlegement frame.";
        }
    }
}

void wait_for_event_receiver(eventType &event)
{
    //set event as frame arrival or error
    int ch=random(10);
    if(ch!=0)
    {
        event = frameArrival;
    }
    else
    {
        event = chksumError;
        cout<<"\nError in receiving data frame.";
    }
}

void sender3()
{
    static seq_no next_frame_to_send =0;
    Frame s;
    static Packet buffer;
    eventType event;

    if(!start)
        wait_for_event_sender(event);

    if(start == false && event == frameArrival)
    {
        from_PL(s);
        if(s.ackNo == next_frame_to_send)
        {
            stop_timer(s.ackNo);
            cout<<"\nAcknowledgement frame for "<<s.ackNo<<" received.";
            from_NL(buffer);
            inc(next_frame_to_send);
            //complete = true;
        }
    }

    if(start)
    {
        from_NL(buffer);
        start = false;
    }

    s.info = buffer;
    s.seqNo = next_frame_to_send;
    to_PL(s);
    start_timer(s.seqNo);
    cout<<"\nFrame "<<s.seqNo<<" sent.";
    //complete = false;
}

void receiver3()
{
    static seq_no frame_expected = 0;
    Frame r,s;
    eventType event;

    wait_for_event_receiver(event);
    if(event == frameArrival)
    {
        from_PL(r);
        if(r.seqNo == frame_expected)
        {
            cout<<"\nFrame "<<r.seqNo<<" received.";
            to_NL(r.info);
            inc(frame_expected);
        }
        s.ackNo = 1 - frame_expected;
        to_PL(s);
        time(&newTime);
    }
    else if(event == chksumError)
    {
        newTime = startTime+5;
    }
}

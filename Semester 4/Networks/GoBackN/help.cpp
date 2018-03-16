#include <iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include "Packet.h"
#include "Frame.h"

using namespace std;

enum eventType {frameArrival,chksumError,timeout,network_layer_ready};

Frame frameAtPhyLayer;
bool isFrameAtPhyLayer = false;

bool start = true;

//check if inc is correct
#define inc(s) if(s==MAX_SEQ) s=0; else s = s+1;
#define MAX_SEQ 7

time_t startTime;
time_t newTime;

int random(int n)
{
    srand((unsigned)time(NULL));
    return rand()%n;
}

// handle the event- network layer ready or not
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

//change it
void start_timer(seq_no s)
{
    time(&startTime);
}

//change it
void stop_timer(seq_no s)
{
    startTime = 0;
}

//code here
void enable_network_layer()
{

}

//code here
void disable_network_layer()
{

}

bool between(seq_no a, seq_no b, seq_no c)
{
    if(((a<=b)&&(b<c)) || ((c<a)&&(a<=b)) || ((b<c)&&(c<a)))
        return true;
    else
        return false;
}

void wait_for_event(eventType &event)
{

}

void send_data(seq_no frame_no, seq_no frame_expected, Packet buffer[])
{
    Frame s;
    s.info = buffer[frame_no];
    s.seqNo = frame_no;
    s.ackNo = (frame_expected + MAX_SEQ)%(MAX_SEQ + 1);
    to_PL(s);
    start_timer(frame_no);
}

//change and make a receiver function
void sender4()
{
    seq_no next_frame_to_send;
    seq_no ack_expected;
    seq_no frame_expected;
    Frame r;
    Packet buffer[MAX_SEQ + 1];
    seq_no nbuffered;
    seq_no i;
    eventType event;

    enable_network_layer();
    ack_expected = 0;
    next_frame_to_send = 0;
    frame_expected = 0;
    nbuffered = 0;

    while (true)
    {
        wait_for_event(event);

        switch(event)
        {
        case network_layer_ready:

            from_NL(buffer[next_frame_to_send]);
            nbuffered = nbuffered + 1;
            send_data(next_frame_to_send, frame_expected, buffer);
            inc(next_frame_to_send);
            break;

        case frameArrival:
            from_PL(r);
            if (r.seqNo == frame_expected)
            {
                to_NL(r.info);
                inc(frame_expected);
            }

            while(between(ack_expected, r.ackNo, next_frame_to_send))
            {
                nbuffered = nbuffered − 1;
                stop_timer(ack_expected);
                inc(ack_expected);
            }
            break;

        case chksumError:
            break;

        case timeout:
            next_frame_to_send = ack_expected;
            for (i=1; i<=nbuffered; i++)
            {
                send_data(next_frame_to_send, frame_expected, buffer);
                inc(next_frame_to_send);
            }
        }
        if (nbuffered < MAX_SEQ)
            enable_network_layer();
        else
            disable_network_layer();
    }
}

/*
void receiver4()
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
        //change here as well
        time(&newTime);
    }
    else if(event == chksumError)
    {
        //change the timer
        newTime = startTime+5;
    }
}
*/
////////////////////////////////////////////////////////////////////////////

/*
void start_timer(seq_no s)
{
    time(&startTime);
}

void stop_timer(seq_no s)
{
    startTime = 0;
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
    Packet buffer;
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
*/

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


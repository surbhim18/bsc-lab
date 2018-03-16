#include <iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include "Packet.h"
#include "Frame.h"
#define MAX_SEQ 7

using namespace std;

enum eventType {frameArrival,chksumError,timeout,network_layer_ready};

Frame frameAtPhyLayerSys1;
bool isFrameAtPhyLayerSys1 = false;
Frame frameAtPhyLayerSys2;
bool isFrameAtPhyLayerSys2 = false;

bool startSys1 = true;

bool NL_enabled_sys1 = false;
bool NL_enabled_sys2 = false;

time_t startTimeSys1[MAX_SEQ];
time_t newTimeSys1[MAX_SEQ];

time_t startTimeSys2[MAX_SEQ];
time_t newTimeSys2[MAX_SEQ];

void initialize()
{
    for(int i=0; i<MAX_SEQ; i++)
    {
        startTimeSys1[i]=0;
        newTimeSys2[i]=0;
        startTimeSys2[i]=0;
        newTimeSys2[i]=0;
    }
}

int random(int n)
{
    srand((unsigned)time(NULL));
    return rand()%n;
}

void inc(seq_no &s)
{
    s = (s+1)%(MAX_SEQ);
}

void from_NL_system1(Packet &p)
{
    cout<<"\nData to be sent from System1: ";
    cin.getline(p.data,maxPacketSize);
}

void from_PL_system1(Frame &f)
{
    if(isFrameAtPhyLayerSys1)
    {
        f = frameAtPhyLayerSys1;
        isFrameAtPhyLayerSys1 = false;
    }
    else
        cout<<"Frame not at Physical Layer of System1!\n";
}

void to_NL_system1(Packet &p)
{
    cout<<"\nData received at System1    : ";
    cout<<p.data;
}

void to_PL_system1(Frame &f)
{
    frameAtPhyLayerSys1 = f;
    isFrameAtPhyLayerSys1 = true;
}

void from_NL_system2(Packet &p)
{
    cout<<"\nData to be sent from System2: ";
    cin.getline(p.data,maxPacketSize);
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

void to_NL_system2(Packet &p)
{
    cout<<"\nData received at System2    : ";
    cout<<p.data;
}

void to_PL_system2(Frame &f)
{
    frameAtPhyLayerSys2 = f;
    isFrameAtPhyLayerSys2 = true;
}

void start_timer_system1(seq_no s)
{
    time(&startTimeSys1[s]);
}

void stop_timer_system1(seq_no s)
{
    startTimeSys1[s] = 0;
}

void start_timer_system2(seq_no s)
{
    time(&startTimeSys2[s]);
}

void stop_timer_system2(seq_no s)
{
    startTimeSys2[s] = 0;
}

void enable_network_layer_system1()
{
    NL_enabled_sys1 = true;
}

void disable_network_layer_system1()
{
    NL_enabled_sys1 = false;
    cout<<"\nNetwork layer of System 1 disabled.";
}

void enable_network_layer_system2()
{
    NL_enabled_sys2 = true;
}

void disable_network_layer_system2()
{
    NL_enabled_sys2 = false;
    cout<<"\nNetwork layer of System 2 disabled.";
}

bool between(seq_no a, seq_no b, seq_no c)
{
    if(b==-1)                               //no acknowledgement has been set
        return false;

    if(((a<=b)&&(b<c)) || ((c<a)&&(a<=b)) || ((b<c)&&(c<a)))
        return true;
    else
        return false;
}

void wait_for_event_system1(eventType &event)
{
    static short int counter =0;
    int i;

    if(NL_enabled_sys1) //events can be all 4
    {
        if(counter%3==0) //every third time, check for timeout
        {
            for(i=0; i<MAX_SEQ; i++)
            {
                double diff = difftime(newTimeSys2[i],startTimeSys2[i]);
                if(diff >= 5)
                {
                    event = timeout;
                    cout<<"\nTimeout at System 1.";
                    return;
                }
            }
        }

        int num = random(10);
        if(num>= 8)
        {
            event = chksumError;
            cout<<"\nError in receiving piggybacked data frame from System 2.";
        }
        else if(num>=4)
        {
            event = frameArrival;
        }
        else
        {
            event = network_layer_ready;
        }
    }
    else                //network layer ready event not possible
    {
        if(counter%3==0) //every third time, check for timeout
        {
            for(i=0; i<MAX_SEQ; i++)
            {
                double diff = difftime(newTimeSys2[i],startTimeSys2[i]);
                if(diff >= 5)
                {
                    event = timeout;
                    cout<<"\nTimeout at System 1.";
                    return;
                }
            }
        }

        int num = random(6);
        if(num>= 4)
        {
            event = chksumError;
            cout<<"\nError in receiving piggybacked data frame from System 2.";
        }
        else
        {
            event = frameArrival;
        }
    }

    counter=(counter+1)%3;
}

void wait_for_event_system2(eventType &event)
{
    static short int counter =0;
    int i;

    if(NL_enabled_sys2) //events can be all 4
    {
        if(counter%3==0) //every third time, check for timeout
        {
            for(i=0; i<MAX_SEQ; i++)
            {
                double diff = difftime(newTimeSys1[i],startTimeSys1[i]);
                if(diff >= 5)
                {
                    event = timeout;
                    cout<<"\nTimeout at System 2.";
                    return;
                }
            }
        }

        int num = random(10);
        if(num>= 8)
        {
            event = chksumError;
            cout<<"\nError in receiving piggybacked data frame from System 1.";
        }
        else if(num>=4)
        {
            event = frameArrival;
        }
        else
        {
            event = network_layer_ready;
        }
    }
    else                //network layer ready event not possible
    {
        if(counter%3==0) //every third time, check for timeout
        {
            for(i=0; i<MAX_SEQ; i++)
            {
                double diff = difftime(newTimeSys1[i],startTimeSys1[i]);
                if(diff >= 5)
                {
                    event = timeout;
                    return;
                }
            }
        }

        int num = random(6);
        if(num>= 4)
        {
            event = chksumError;
            cout<<"\nError in receiving piggybacked data frame from System 1.";
        }
        else
        {
            event = frameArrival;
        }
    }

    counter = (counter+1)%3;
}

void send_data_system1(seq_no frame_no, seq_no frame_expected, Packet buffer[])
{
    Frame s;
    s.info = buffer[frame_no];
    s.seqNo = frame_no;
    s.ackNo = (frame_expected + MAX_SEQ)%(MAX_SEQ + 1);
    to_PL_system1(s);
    start_timer_system1(frame_no);
    cout<<"\nFrame "<<s.seqNo<<" sent from System 1 to System 2.";
}

void system1()
{
    static seq_no next_frame_to_send=0;
    static seq_no ack_expected=0;
    static seq_no frame_expected=0;
    static seq_no nbuffered=0;
    static Packet buffer[MAX_SEQ + 1];

    Frame r;
    seq_no i;
    eventType event;

    if(startSys1)
        enable_network_layer_system1();
    else
        wait_for_event_system1(event);

    if(startSys1==true || event == network_layer_ready)
    {
        from_NL_system1(buffer[next_frame_to_send]);
        nbuffered = nbuffered + 1;
        send_data_system1(next_frame_to_send, frame_expected, buffer);
        inc(next_frame_to_send);

        if(startSys1)
            startSys1 = false;
    }
    else if(event == frameArrival)
    {
        from_PL_system2(r);
        if (r.seqNo == frame_expected)
        {
            time(&newTimeSys1[frame_expected]);
            cout<<"\nFrame "<<r.seqNo<<" received at System 1 from System 2.";
            to_NL_system1(r.info);
            inc(frame_expected);
        }

        while(between(ack_expected, r.ackNo, next_frame_to_send))
        {
            nbuffered = nbuffered-1;
            stop_timer_system1(ack_expected);
            inc(ack_expected);
        }
        cout<<"\nAcknowledgement for frames till "<<r.ackNo<<" received at System 1.";
    }
    else if(event == chksumError)
    {
        newTimeSys1[frame_expected] = startTimeSys1[frame_expected]+5;
    }
    else if (event == timeout)
    {
        next_frame_to_send = ack_expected;
        for (i=1; i<=nbuffered; i++)
        {
            send_data_system1(next_frame_to_send, frame_expected, buffer);
            inc(next_frame_to_send);
        }
    }

    if (nbuffered < MAX_SEQ)
        enable_network_layer_system1();
    else
        disable_network_layer_system1();
}


void send_data_system2(seq_no frame_no, seq_no frame_expected, Packet buffer[])
{
    Frame s;
    s.info = buffer[frame_no];
    s.seqNo = frame_no;
    s.ackNo = (frame_expected + MAX_SEQ)%(MAX_SEQ + 1);
    to_PL_system2(s);
    start_timer_system2(frame_no);
    cout<<"\nFrame "<<s.seqNo<<" sent from System 2 to System 1.";
}

void system2()
{
    static seq_no next_frame_to_send=0;
    static seq_no ack_expected=0;
    static seq_no frame_expected=0;
    static seq_no nbuffered=0;
    static Packet buffer[MAX_SEQ + 1];

    Frame r;
    seq_no i;
    eventType event;

    enable_network_layer_system2();

    wait_for_event_system2(event);

    if(event == network_layer_ready)
    {
        from_NL_system2(buffer[next_frame_to_send]);
        nbuffered = nbuffered + 1;
        send_data_system2(next_frame_to_send, frame_expected, buffer);
        inc(next_frame_to_send);
    }
    else if(event == frameArrival)
    {
        from_PL_system1(r);
        if (r.seqNo == frame_expected)
        {
            time(&newTimeSys2[frame_expected]);
            cout<<"\nFrame "<<r.seqNo<<" received at System 2 from System 1.";
            to_NL_system2(r.info);
            inc(frame_expected);
        }

        while(between(ack_expected, r.ackNo, next_frame_to_send))
        {
            nbuffered = nbuffered-1;
            stop_timer_system2(ack_expected);
            inc(ack_expected);
        }
        cout<<"\nAcknowledgement for frames till "<<r.ackNo<<" received at System 2.";
    }
    else if(event == chksumError)
    {
        newTimeSys2[frame_expected] = startTimeSys2[frame_expected]+5;
    }
    else if(event == timeout)
    {
        next_frame_to_send = ack_expected;
        for (i=1; i<=nbuffered; i++)
        {
            send_data_system2(next_frame_to_send, frame_expected, buffer);
            inc(next_frame_to_send);
        }
    }

    if (nbuffered < MAX_SEQ)
        enable_network_layer_system2();
    else
        disable_network_layer_system2();
}


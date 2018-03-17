#include "Process.h"
#include<iostream>

using namespace std;

Process::Process()
{
    priority=0;
    startTime=0;
    finishTime=0;
}

int Process:: retPid()
{
    return pid;
}

int Process:: retBurstTime()
{
    return burstTime;
}

int Process:: retArrvTime()
{
    return arrvTime;
}

int Process:: retPriority()
{
    return priority;
}

int Process:: retStartTime()
{
    return startTime;
}

int Process:: retFinishTime()
{
    return finishTime;
}

void Process:: setStartTime(int time)
{
    startTime = time;
}

void Process:: setFinishTime(int time)
{
    finishTime = time;
}

void Process:: enter()
{
    cout<<"\nProcess     : ";
    cin>>pid;
    cout<<"Burst Time  : ";
    cin>>burstTime;
    cout<<"Arrival Time: ";
    cin>>arrvTime;
    cout<<"Priority    : ";
    cin>>priority;
}

void Process:: display()
{
    cout<<pid<<"\t\t"<<burstTime<<"\t\t"<<arrvTime<<"\t\t"<<priority<<"\t\t"<<startTime<<"\t\t"<<finishTime<<endl;
}

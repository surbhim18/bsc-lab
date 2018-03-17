#include "Process.h"
#include<iostream>

using namespace std;

Process::Process()
{
    startTime=0;
    finishTime=0;
    priority=0;
}

int Process:: retPid()
{
    return pid;
}

int Process:: retBurstTime()
{
    return burstTime;
}

int Process:: retPriority()
{
    return priority;
}

int Process:: retArrvTime()
{
    return arrvTime;
}

int Process:: retStartTime()
{
    return startTime;
}

int Process:: retFinishTime()
{
    return finishTime;
}

int Process:: retRemainingTime()
{
    return remainingTime;
}

void Process:: setStartTime(int time)
{
    startTime = time;
}

void Process:: setFinishTime(int time)
{
    finishTime = time;
}

void Process:: setRemainingTime(int time)
{
    remainingTime = time;
}

void Process:: enter()
{
    cout<<"\nProcess     : ";
    cin>>pid;
    cout<<"Burst Time  : ";
    cin>>burstTime;
     cout<<"Priority    : ";
    cin>>priority;
    cout<<"Arrival Time: ";
    cin>>arrvTime;

    remainingTime=burstTime;
}

void Process:: display()
{
    cout<<pid<<"\t\t"<<burstTime<<"\t\t"<<priority<<"\t\t"<<arrvTime<<"\t\t"<<startTime<<"\t\t"<<finishTime<<"\t\t"<<(finishTime-arrvTime-burstTime)<<endl;
}

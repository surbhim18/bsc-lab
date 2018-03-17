#include <iostream>
#include<cstdlib>
#include "Process.h"
#include "CirQueue.h"

using namespace std;

void enterProcesses(Process *p, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        p[i].enter();
    }
}

void sortProcessesOnArrvTime(Process *p, int n)
{
    int i,j;
    for(i=1; i<n; i++)
    {
        j = i-1;
        Process temp = p[i];

        while(p[j].retArrvTime() > temp.retArrvTime() && j>=0)
        {
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = temp;
    }
}

int findProcessIndex(Process *p, Process x, int n)
{
    for(int k=0; k<n; k++)
    {
        if(x.retPid() == p[k].retPid())
        {
            return k;
        }
    }
    return -1;
}

bool isComplete(Process p)
{
    if(p.retRemainingTime()==0)
        return true;
    else
        return false;
}

bool hasNotStarted(Process p)
{
    if(p.retRemainingTime()==p.retBurstTime())
        return true;
    else
        return false;
}

void scheduleProcesses(Process *p, int n, int quant)
{
    sortProcessesOnArrvTime(p,n);

    int clockTime = p[0].retArrvTime();

    CirQueue *que = new CirQueue(n);

    int i=0;
    int pInQue=0;

    while(clockTime == p[i].retArrvTime() && i<n)
    {
        que->enqueue(p[i]);
        pInQue++;
        i++;
    }

    Process processToBeScheduled;
    while(!que->isEmpty())
    {
        processToBeScheduled = que->dequeue();
        int index = findProcessIndex(p,processToBeScheduled,n);

        int executionTime;
        int remainingTime = p[index].retRemainingTime();
        if(remainingTime >= quant)
            executionTime = quant;
        else
            executionTime = remainingTime;

        if(hasNotStarted(p[index]))
            p[index].setStartTime(clockTime);

        p[index].setRemainingTime(remainingTime - executionTime);

        clockTime = clockTime + executionTime;

        if(isComplete(p[index]))
            p[index].setFinishTime(clockTime);
        else
            que->enqueue(p[index]);

        int j= pInQue;
        while(j<n && clockTime >= p[j].retArrvTime())
        {
            que->enqueue(p[j]);
            pInQue++;
            j++;
        }

        if(que->isEmpty() && pInQue!=n)
        {
            clockTime = p[j].retArrvTime();
            while(clockTime >= p[j].retArrvTime() && j<n)
            {
                que->enqueue(p[j]);
                pInQue++;
                j++;
            }
        }
    }

    delete que;
}


float avgWaitingTime(Process *p, int n)
{
    int i,sum=0;
    int waitingTime;
    float average;

    for(i=0; i<n; i++)
    {
        waitingTime = p[i].retFinishTime() - p[i].retArrvTime() - p[i].retBurstTime();
        sum += waitingTime;
    }

    average = (float)sum/n;
    return average;
}


float avgTAtime(Process *p, int n)
{
    int i,TAtime,sum=0;
    float average;

    for(i=0; i<n; i++)
    {
        TAtime = p[i].retFinishTime() - p[i].retArrvTime();
        sum += TAtime;
    }

    average = (float)sum/n;
    return average;
}


void display_RR_Schedule(Process *p, int n)
{
    cout<<"Process\tBurst Time\tArrival Time\tStarting Time\tFinishing Time\tWaiting Time\n";

    int i;
    for(i=0; i<n; i++)
    {
        p[i].display();
    }

    cout<<"\nAverage turnaround time: "<<avgTAtime(p,n);
    cout<<"\nAverage waiting time   : "<<avgWaitingTime(p,n);
}


int main()
{
    Process *p;
    int n,quant;

    cout<<"\nEnter the number of processes: ";
    cin>>n;
    cout<<"Enter time quant             : ";
    cin>>quant;

    p = new Process[n];

    cout<<"\nEnter processes:\n";
    enterProcesses(p,n);
    cout<<endl;

    try
    {
        scheduleProcesses(p,n,quant);
    }
    catch(char* msg)
    {
        cout<<msg;
        exit(0);
    }
    cout<<endl;

    display_RR_Schedule(p,n);
    cout<<endl;

    return 0;
}

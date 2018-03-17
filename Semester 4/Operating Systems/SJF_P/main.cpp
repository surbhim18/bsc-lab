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

void scheduleProcesses(Process *p, int n)
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

    //cout<<"\npoint 1\n";
    Process shortestProcess;
    while(pInQue!=n)
    {
        shortestProcess = que->dequeue();
        int index = findProcessIndex(p,shortestProcess,n);
        //cout<<"\nPoint 2\n";
        //cout<<"\nIndex: "<<index<<endl;
        int executionTime = p[pInQue].retArrvTime() - clockTime;

        if(hasNotStarted(p[index]))
            p[index].setStartTime(clockTime);

        p[index].setRemainingTime(p[index].retRemainingTime()- executionTime);

        clockTime = clockTime + executionTime;

        if(isComplete(p[index]))
            p[index].setFinishTime(clockTime);
        else
            que->enqueue(p[index]);

        //cout<<"\nPoint 3\n";

        int j= pInQue;
        while(j<n && clockTime >= p[j].retArrvTime())
        {
            que->enqueue(p[j]);
            pInQue++;
            j++;
        }
        //cout<<"\nPoint 4\n";

        if(que->isEmpty() && pInQue!=n)
        {
            clockTime = p[j].retArrvTime();
            while(clockTime >= p[j].retArrvTime() && j<n)
            {
                que->enqueue(p[j]);
                pInQue++;
                j++;
            }
            //cout<<"\nPoint 5\n";
        }
    }

    while(!que->isEmpty())
    {
        //cout<<"\nPoint 6\n";
        shortestProcess = que->dequeue();
        int index = findProcessIndex(p,shortestProcess,n);
        //cout<<"\nINDEX: "<<index<<endl;

        if(hasNotStarted(p[index]))
            p[index].setStartTime(clockTime);

        int ftime = clockTime + p[index].retRemainingTime();
        p[index].setFinishTime(ftime);

        p[index].setRemainingTime(0);

        clockTime = p[index].retFinishTime();
        //cout<<"\nPoint 7\n";
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


void display_SJF_P_Schedule(Process *p, int n)
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
    int n;

    cout<<"\nEnter the number of processes: ";
    cin>>n;

    p = new Process[n];

    cout<<"\nEnter processes:\n";
    enterProcesses(p,n);
    cout<<endl;

    try
    {
        scheduleProcesses(p,n);
    }
    catch(char* msg)
    {
        cout<<msg;
        exit(0);
    }
    cout<<endl;

    display_SJF_P_Schedule(p,n);
    cout<<endl;

    return 0;
}

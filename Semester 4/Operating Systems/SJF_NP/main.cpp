#include <iostream>
#include<cstdlib>
#include "Process.h"
#include "Queue.h"

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


void scheduleProcesses(Process *p, int n)
{
    sortProcessesOnArrvTime(p,n);

    int clockTime = p[0].retArrvTime();

    Queue *que = new Queue(n);

    int i=0;
    int pInQue=0;
    while(clockTime == p[i].retArrvTime() && i<n)
    {
        que->enqueue(p[i]);
        pInQue++;
        i++;
    }

    Process shortestProcess;
    while(!que->isEmpty())
    {
        shortestProcess = que->dequeue();

        int index = findProcessIndex(p,shortestProcess,n);

        p[index].setStartTime(clockTime);
        int ftime = p[index].retStartTime() + p[index].retBurstTime();
        p[index].setFinishTime(ftime);

        clockTime = p[index].retFinishTime();

        int j= pInQue;
        while(clockTime >= p[j].retArrvTime() && j<n)
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
    int i,waitingTime,sum=0;
    float average;

    for(i=0; i<n; i++)
    {
        waitingTime = p[i].retStartTime() - p[i].retArrvTime();
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


void display_SJF_NP_Schedule(Process *p, int n)
{
    cout<<"Process\tBurst Time\tArrival Time\tStarting Time\tFinishing Time\n";

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


    display_SJF_NP_Schedule(p,n);
    cout<<endl;

    return 0;
}

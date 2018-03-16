/*
Process id should be unique.
*/

#include<iostream>

using namespace std;

struct Process
{
    int pid;
    int burstTime;
    int arrvTime;
    int startTime;
    int finishTime;
};

void enterProcesses(Process *p, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        cout<<"\nProcess     : ";
        cin>>p[i].pid;
        cout<<"Burst Time  : ";
        cin>>p[i].burstTime;
        cout<<"Arrival Time: ";
        cin>>p[i].arrvTime;

        p[i].startTime=0;
        p[i].finishTime=0;
    }
}

void sortProcesses(Process *p, int n)
{
    int i,j;

    for(i=1; i<n; i++)
    {
        j = i-1;
        Process temp = p[i];

        while(p[j].arrvTime > temp.arrvTime && j>=0)
        {
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = temp;
    }
}

void scheduleProcesses(Process *p, int n)
{
    sortProcesses(p,n);

    int clockTime = p[0].arrvTime;
    int finsihTime;

    int i=0;
    while(i!=n)
    {
        if(clockTime > p[i].arrvTime)
            p[i].startTime = clockTime;
        else
            p[i].startTime = p[i].arrvTime;

        p[i].finishTime = p[i].startTime + p[i].burstTime;

        clockTime = p[i].finishTime;
        i++;
    }
}

float avgWaitingTime(Process *p, int n)
{
    int i,waitingTime,sum=0;
    float average;

    for(i=0; i<n; i++)
    {
        waitingTime = p[i].startTime - p[i].arrvTime;
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
        TAtime = p[i].finishTime - p[i].arrvTime;
        sum += TAtime;
    }

    average = (float)sum/n;
    return average;
}

void FCFS_schedule(Process *p, int n)
{
    cout<<"Process\tBurst Time\tArrival Time\tStarting Time\tFinishing Time\n";

    int i;
    for(i=0; i<n; i++)
    {
        cout<<p[i].pid<<"\t\t"<<p[i].burstTime<<"\t\t"<<p[i].arrvTime<<"\t\t"<<p[i].startTime<<"\t\t"<<p[i].finishTime<<endl;
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
    scheduleProcesses(p,n);
    cout<<endl;
    FCFS_schedule(p,n);
    cout<<endl;

    return 0;
}

#include "Queue.h"
#include<iostream>

using namespace std;

Queue:: Queue(int n)
{
    maxSize = n;
    front = rear = -1;
    que = new Process[maxSize];
}

Queue::~Queue()
{
    delete []que;
}

bool Queue:: isEmpty()
{
    if(front==-1 && rear==-1)
        return true;
    else
        return false;
}
void Queue:: enqueue(Process p)
{
    if(rear == maxSize-1)
    {
        throw "\nMaximum size exceeded!";
    }
    else if(rear == -1)
    {
        rear = front = 0;
        que[rear] =  p;
    }
    else
    {
        int j=rear;
        while(j>=front && que[j].retBurstTime() > p.retBurstTime())
        {
            que[j+1] = que[j];
            j--;
        }
        que[j+1] = p;
        rear++;
    }
}

Process Queue:: dequeue()
{
    Process temp;
    if(front == -1)
    {
        throw "\nQueue is empty!\n";

    }
    else if(rear == front)
    {
        temp = que[front];
        front = rear = -1;
    }
    else
    {
        temp = que[front];
        front++;
    }

    return temp;
}

void Queue:: display()
{
    int i;

    for(i=front; i<=rear; i++)
        que[i].display();
}

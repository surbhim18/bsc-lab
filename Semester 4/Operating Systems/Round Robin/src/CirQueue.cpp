#include "CirQueue.h"
#include<iostream>

using namespace std;

CirQueue:: CirQueue(int n)
{
    maxSize = n;
    front = rear = -1;
    que = new Process[maxSize];
}

CirQueue::~CirQueue()
{
    delete []que;
}

bool CirQueue:: isEmpty()
{
    if(front==-1 && rear==-1)
        return true;
    else
        return false;
}
void CirQueue:: enqueue(Process p)
{
    if((front==0 && rear == maxSize-1) || front == rear+1)
    {
        throw "\nMaximum size exceeded!\n";
    }
    else if(rear == -1)
    {
        rear = front = 0;
        que[rear] =  p;
    }
    else
    {
        rear = (rear+1)%maxSize;
        que[rear] = p;
    }
}

Process CirQueue:: dequeue()
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
        front = (front+1)%maxSize;
    }

    return temp;
}

void CirQueue:: display()
{
    int i;
    if(front<=rear)
    {
        for(i=front; i<=rear; i++)
            que[i].display();
    }
    else
    {
        for(i=front; i<maxSize; i++)
            que[i].display();

        for(i=0; i<=rear; i++)
            que[i].display();
    }
}

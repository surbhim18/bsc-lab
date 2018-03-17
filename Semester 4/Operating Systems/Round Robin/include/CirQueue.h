#include "Process.h"
#ifndef CIRQUEUE_H
#define CIRQUEUE_H


class CirQueue
{
     Process *que;
    int front;
    int rear;
    int maxSize;

    public:
    CirQueue(int n);
    void enqueue(Process p);
    Process dequeue();
    void display();
    bool isEmpty();
    ~CirQueue();
};

#endif // CIRQUEUE_H

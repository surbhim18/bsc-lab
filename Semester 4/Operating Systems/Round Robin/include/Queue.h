#ifndef QUEUE_H
#define QUEUE_H

#include "Process.h"

class Queue
{
    Process *que;
    int front;
    int rear;
    int maxSize;

    public:
    Queue(int n);
    void enqueue(Process p);
    Process dequeue();
    void display();
    bool isEmpty();
    ~Queue();
};

#endif // QUEUE_H

#include "Node.h"
#ifndef QUEUESLL_H
#define QUEUESLL_H


class QueueSLL
{
    private:
        Node* frontt;
        Node* rear;

    public:
        QueueSLL();
        bool isEmpty() const;
        void display() const;
        void enqueue(int);
        int dequeue();
        ~QueueSLL();

};


#endif // QUEUESLL_H

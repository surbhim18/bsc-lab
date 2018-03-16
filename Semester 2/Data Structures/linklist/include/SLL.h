#ifndef SLL_H
#define SLL_H

#include "Node.h"

class SLL
{
    private:
        Node* head;
        Node* tail;

    public:
        SLL();
        bool isEmpty() const;
        void display() const;
        void addToHead(int);
        void addToTail(int);
        int deleteFromHead();
        int deleteFromTail();
        bool isInList(int) const;
        bool delet(int);
        bool addBefore(int,int);
        bool addAfter(int,int);
        bool deleteBefore(int);
        bool deleteAfter(int);
        void reverseSLL();
        void printReverse();
        void printReverse(Node*);
        ~SLL();

};

#endif // SLL_H

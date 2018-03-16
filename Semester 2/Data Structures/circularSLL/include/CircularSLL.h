#include "Node.h"

#ifndef CIRCULARSLL_H
#define CIRCULARSLL_H


class CircularSLL
{
    private:
        Node* head;
        Node* tail;

    public:
        CircularSLL();
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
        void reverseCSLL();
        ~CircularSLL();

};

#endif // CIRCULARSLL_H

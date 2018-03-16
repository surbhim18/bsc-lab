#include "Node.h"

#ifndef DLL_H
#define DLL_H


class DLL
{
    private:
        Node* head;
        Node* tail;

    public:
        DLL();
        bool isEmpty() const;
        void display() const;
        void printDLL() const;
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
        int deleteAtPos(int);
        void reverseDLL();
        ~DLL();

};

#endif // DLL_H
